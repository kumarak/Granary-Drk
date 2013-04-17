/*
 * cfi_instrument.c
 *
 *  Created on: 2012-04-08
 *      Author: akshayk
 */


#include <stddef.h>

#include "cfi_module.h"
#include "cfi_wrapper.h"
#include "cfi_address_logger.h"

#include "kernel_linux/clients/dcontext_extend.h"

#if CFI_SEQUENTIALIZE_MODULE
#   include "cfi_sequence.h"
#endif

#define GRANARY_MEM_INSTRUMENTATION

/**
 * Initialize the CFI extension structure to the dcontext.
 */
static void cfi_init_dcontext(void *extension) {
	struct cfi_client_extension *cfi = (struct cfi_client_extension *) extension;

	memset(cfi, 0, sizeof *cfi);
	cfi->iret_handler = dr_app_start_after_iret;
}

struct dcontext;
extern void cfi_exit_direct_call(void);
extern void *cfi_get_untracked_address(void *);
extern void cfi_return_to_module_from_kernel(void);
extern void cfi_exit_return_to_kernel(void);

void drinit_dcontext(unsigned int thread_id) {
	dr_init_client_extension(cfi_init_dcontext, DR_EXTENSION(cfi));
	dr_register_kernel_wrapper(cfi_get_kernel_wrapper);
	dr_register_direct_call_exit((void*)cfi_exit_direct_call);
	dr_register_address_untracker(cfi_get_untracked_address);
	dr_register_address_return_exit(cfi_exit_return_to_kernel);
	dr_register_return_path_address(cfi_return_to_module_from_kernel);
	//dr_register_exit_module_context(cfi_seq_release_module);
}

#define DISPLAY_STRING(msg) dr_printf("%s\n", msg);
#define NULL_TERMINATE(buf) buf[(sizeof(buf)/sizeof(buf[0])) - 1] = '\0'

#define MAX_INSTR_REGISTER 8

#define SHADOW_OFFSET 0x400000000000

typedef struct _mem_ref_t{
	bool write;
	void *addr;
	size_t size;
}mem_ref_t;

#define READABLE_TRACE
#define MAX_NUM_MEM_REFS 8192
#define MEM_BUF_SIZE (sizeof(mem_ref_t) * MAX_NUM_MEM_REFS)

/* thread private log file and counter */
typedef struct {
	char   *buf_ptr;
	char   *buf_base;	/* buf_end holds the negative value of real address of buffer end. */
	ptr_int_t buf_end;
	void   *cache;
	file_t  log;
	uint64  num_refs;
} per_thread_t;

static client_id_t client_id;

static void
at_direct_call(app_pc instr_addr, app_pc target_addr)
{
	printk("    direct call address : %lx\n",(unsigned long)target_addr );
	//    dr_app_give_control();
}

static void
at_indirect_call(app_pc instr_addr, app_pc target_addr)
{
	printk("    indirect call address : %lx\n",(unsigned long)target_addr );

}

static void handle_mem_write()
{

}

static reg_id_t get_next_free_reg(unsigned long *bit_array)
{
	unsigned pos = 0;
	for(; pos < 32; ++pos) {
		unsigned long mask = (1 << pos);
		if(!(mask & *bit_array)) {
			*bit_array |= mask;
			return (reg_id_t) pos;
		}
	}
	return DR_REG_NULL;
}

static void free_reg(unsigned long *bit_array, reg_id_t reg) {
	*bit_array &= ~(1 << reg);
}

static void collect_reg(unsigned long *regs, reg_id_t reg) {
	// map the registers onto the 64-bit registers
	if(reg < DR_REG_SPL) {
		while(reg >= DR_REG_EAX) {
			reg -= (DR_REG_EAX - 1);
		}
		//printk("used reg : %d\n", reg);
		*regs |= (1 << reg);
	}
}

static void collect_regs(
		unsigned long *regs,
		instr_t *instr,
		int (*num_ops)(instr_t *),
		opnd_t (*get_op)(instr_t *, uint)
) {
	int i;
	opnd_t opnd;
	reg_id_t reg1;

	// make sure these regs are always seen as "used"
	*regs |= (1 << DR_REG_NULL);

	for(i=0; i < num_ops(instr); i++) {
		opnd = get_op(instr, i);
		if(opnd_is_reg(opnd)) {
			collect_reg(regs, opnd_get_reg(opnd));
		} else if(opnd_is_base_disp(opnd)) {
			collect_reg(regs, opnd_get_base(opnd));
			collect_reg(regs, opnd_get_index(opnd));
		}
	}

	collect_reg(regs, DR_REG_RSP);
	collect_reg(regs, DR_REG_RBP);
	collect_reg(regs, DR_REG_RAX);
	collect_reg(regs, DR_REG_RDX);
}

/// lower a register to be in the same class (64, 32, 16 bit) as
/// another register
static reg_id_t change_reg_class(reg_id_t reg) {
	if(reg < DR_REG_SPL) {
		int offset = 0;
		while(reg >= DR_REG_EAX) {
			reg -= (DR_REG_EAX - 1);
			offset += (DR_REG_EAX - 1);
		}
		if(offset) {
			return reg + offset;
		}
	}
	return reg;
}

static reg_id_t change_reg_64bit_class(reg_id_t reg) {
	if(reg < DR_REG_SPL) {
		if(reg >= DR_REG_AL) {
			return reg - (DR_REG_AL-1);
		} else if(reg >= DR_REG_AX) {
			return reg - (DR_REG_AX -1);
		} else if (reg >= DR_REG_EAX) {
			return reg - (DR_REG_EAX -1);
		} else
			return reg;
	}
	return reg;
}


bool ref_is_stack_mem(opnd_t opnd)
{
	if(!opnd_is_base_disp(opnd))
		return false;

	if(opnd_get_base(opnd) == DR_REG_RSP)
		return true;

	return false;
}

#define TESTALL(mask, var) (((mask) & (var)) == (mask))
#define TESTANY(mask, var) (((mask) & (var)) != 0)

bool
instr_writes_to_any_aflags(instr_t *instr)
{
	uint aflags;

	aflags = instr_get_arith_flags(instr);
	if (TESTANY(EFLAGS_WRITE_6, aflags))
		return true;

	return false;
}


static void
replace_instr(void* drcontext, instrlist_t *ilist, instr_t **old, instr_t *new)
{
	//instr_set_translation(new, instr_get_translation(*old));
	instrlist_replace(ilist, *old, new);
	instr_destroy(drcontext, *old);
	*old = new;
}


static const char *op_name(int opcode) {
	static const char *op_names[] = {
#		define OP_MACRO(o) #o ,
#		include "opcodes.h"
#		undef OP_MACRO
			"" // sentinel
	};
	return op_names[opcode];
}


#define INVALID_MEM_ADDR -1
#define REG_SPILL_START DR_REG_XAX
#define REG_SPILL_STOP DR_REG_R15
#define KERNEL_MEMORY_HOLE_START	0xffffc10000000000
#define KERNEL_MEMORY_HOLE_END		0xffffc1ffffffffff

static void break_on_multiple_dests(int num_dests, int num_sources, void *pc) {
	(void) num_dests, num_sources, pc;
}
#if 0
static instr_t *
instrument_write_mem(void *drcontext, instrlist_t *ilist, instr_t *instr, bool write)
{
	int i;
	int emulated_instruction = 0;
	//instr_t *meta_instr;
	//opnd_t dest_ref, opnd_src, opnd_dest, opnd1;
	instrlist_t* ilist_pre = instrlist_create(drcontext);
	instrlist_init(ilist_pre);
	instr_t *emulate_write_op = INSTR_CREATE_label(drcontext);
	instr_t *done_emulation = INSTR_CREATE_label(drcontext);
	instr_t *cloned_op = NULL;
	instr_t* instr_cloned;

	ptr_int_t pt_addr;
	int num_src, num_dest;
	unsigned long registers = 0;
	reg_id_t spill_reg_2;

	if(!write
			|| instr_writes_to_reg(instr, DR_REG_RSP)
			|| instr_writes_to_reg(instr, DR_REG_RBP)
			|| instr_is_call(instr)
			|| instr_writes_to_any_aflags(instr)
			|| instr_is_sse_or_sse2(instr)){
		return;
	}

	switch(instr_get_opcode(instr)) {
	case OP_push: case OP_pop:
	case OP_pusha: case OP_popa:
	case OP_pushf: case OP_popf:
	case OP_push_imm:
		return;
	default:
		break;
	}

	/* collect the unused registers*/
	collect_regs(&registers, instr, instr_num_srcs, instr_get_src );
	collect_regs(&registers, instr, instr_num_dsts, instr_get_dst );

	/* spill register to store the kernel memory hole */
	reg_id_t kernel_hole_reg_id = get_next_free_reg(&registers);
	opnd_t kernel_hole_reg = opnd_create_reg(kernel_hole_reg_id);

	if(instr_num_dsts(instr) > 1) {
		break_on_multiple_dests(instr_num_dsts(instr), instr_num_srcs(instr), instr_get_app_pc(instr));
	}

	/* push spill reg onto stack*/
	instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pushf(drcontext));
	instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_push(drcontext, kernel_hole_reg));

	/* move HOLE_START_MEMORY into spill reg*/
	instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, kernel_hole_reg, OPND_CREATE_INT64(KERNEL_MEMORY_HOLE_START)));

	if (instr_num_dsts(instr) == 1) {
		for (i = 0; i < instr_num_dsts(instr); i++) {
			reg_id_t mem_addr_id = get_next_free_reg(&registers);
			opnd_t reg_mem_addr = opnd_create_reg(mem_addr_id);
			opnd_t dest_ref = instr_get_dst(instr, i);
			opnd_t src_ref = instr_get_src(instr, i);
			opnd_t mem_ref = dest_ref;
			//		opnd_is_memory_reference(src_ref) ? src_ref : dest_ref;

			/* if the address is absolute*/
			if (opnd_is_rel_addr(dest_ref) || opnd_is_abs_addr(dest_ref)) {
				/*first_instr
				 pt_addr = opnd_get_addr(dest_ref);
				 pt_addr |= 0x0;
				 opnd_dest = OPND_CREATE_INT64(opnd_get_addr(dest_ref));
				 */
				// TODO: absolute address, emit the correct emulation of this operation
			} else if (opnd_is_base_disp(dest_ref)) {

				reg_id_t dest_reg = opnd_get_base(dest_ref);

				// ignore likely local variables
				switch (dest_reg) {
				case DR_REG_RSP:
				case DR_REG_ESP:
				case DR_REG_SP:
				case DR_REG_RBP:
				case DR_REG_EBP:
				case DR_REG_BP:
					goto clear_stack;
				default:
					break;
				}

				// spill a register so that we can store the source/destination address of this memory operation
				//instrlist_meta_preinsert(ilist, instr,
				//		INSTR_CREATE_push(drcontext, reg_mem_addr));

				if (instr_get_opcode(instr) == OP_mov_st) {
					emulated_instruction = 1;

					// load the source/dest afirst_instrddress into the reg_mem_addr spill register
					/*	instrlist_meta_preinsert(
							ilist,
							instr,
							INSTR_CREATE_lea(drcontext,
									reg_mem_addr,
									opnd_create_base_disp(dest_reg, opnd_get_index(mem_ref), opnd_get_scale(mem_ref), opnd_get_disp(mem_ref), OPSZ_lea)));
					 */
					// compare with the base address of the kernel hole
					/*				instrlist_meta_preinsert(
							ilist,
							instr,
							INSTR_CREATE_cmp(drcontext, reg_mem_addr, kernel_hole_reg));
					 */
					// if the memory address is < kernel hole base, then it's not an aliased address, so we will emulate
					// the operation with the reg_mem_addr
					/*					instrlist_meta_preinsert(
							ilist,
							instr,
							INSTR_CREATE_jcc(drcontext, OP_jl, opnd_create_instr(emulate_write_op)));
					 */
					// compare with the limit address of the kernel hole
					/*					instrlist_meta_preinsert(
							ilist,
							in
							str,
							INSTR_CREATE_mov_imm(drcontext, kernel_hole_reg, OPND_CREATE_INT64(KERNEL_MEMORY_HOLE_END)));
					instrlist_meta_preinsert(
							ilist,
							instr,
							INSTR_CREATE_cmp(drcontext, reg_mem_addr, kernel_hole_reg));
					 */
					// if the memory address is >= kernel hole limit, then it's not an aliased address, so we will emulate
					// the operation with the reg_mem_addr
					/*					instrlist_meta_preinsert(
							ilist,
							instr,
							INSTR_CREATE_jcc(drcontext, OP_jge, opnd_create_instr(emulate_write_op)));
					 */
					// TODO: call into aliasing system

					// done emulating the op,
					/*					instrlist_meta_preinsert(
							ilist,
							instr,
							INSTR_CREATE_jmp(drcontext, opnd_create_instr(done_emulation)));
					 */
					// emulate the write operation
					//				instrlist_meta_preinsert(ilist, instr, emulate_write_op);

					cloned_op = instr_clone(drcontext, instr);
					instr_set_app_pc(cloned_op, NULL);
					instrlist_meta_preinsert(ilist, instr, cloned_op);

					/*	if(OP_mov_ld == instr_get_opcode(instr)) {
					 instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_ld(drcontext, dest_ref, src_ref));
					 } else {
					 instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_st(drcontext, dest_ref, src_ref));
					 }
					 */
					//			instrlist_meta_preinsert(ilist, instr, done_emulation);

				}
				// restore spilled reg
				//instrlist_meta_preinsert(ilist, instr,
				//		INSTR_CREATE_pop(drcontext, reg_mem_addr));
			} else {

			}

		}
	}
	/*remove_original:
	// replace the original instruction, and ensure that the app pcs agree

	//instr_set_app_pc(dummy_op, instr_get_app_pc(instr));
	instrlist_replace(ilist, instr, dummy_op);*/

	clear_stack:

	instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, kernel_hole_reg));
	instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_popf(drcontext));

	if(emulated_instruction) {

		instr_t *dummy_op = INSTR_CREATE_nop(drcontext);
		instr_set_app_pc(dummy_op, instr_get_app_pc(instr));
		//instr_set_translation(dummy_op, instr_get_translation(instr));
		instrlist_meta_preinsert(ilist, instr, dummy_op);

		instrlist_remove(ilist, instr);
		instr = dummy_op;

		//instr_set_opcode(instr, OP_nop);
	}




	//return instr;
}
#endif

#define LOG_FILE "address_log.txt"
static void
clean_call(void *arg1, void *arg2)
{
	//FILE *fp = fopen(LOG_FILE, "w");
	//printk("%lx\t%lx\n", arg1, arg2);
	//fclose(fp);
}

void break_on_src_opnd(app_pc arg)
{
	(void)arg;
}

static instr_t *
instrument_write_mem_dummy(void *drcontext, instrlist_t *ilist, instr_t *instr, bool write)
{
	int i;
	int emulated_instruction = 0;
	instrlist_t* ilist_pre = instrlist_create(drcontext);
	instrlist_init(ilist_pre);
	instr_t *emulate_write_op = INSTR_CREATE_label(drcontext);
	instr_t *done_emulation = INSTR_CREATE_label(drcontext);
	instr_t *cloned_op = NULL;
	instr_t* instr_cloned;
	app_pc instr_app_pc;

	ptr_int_t pt_addr;
	int num_src, num_dest;
	unsigned long registers = 0;
	reg_id_t spill_reg_2;

	if(!write
	|| instr_writes_to_reg(instr, DR_REG_RSP)
	|| instr_writes_to_reg(instr, DR_REG_RBP)
	|| instr_is_call(instr)
	|| instr_writes_to_any_aflags(instr)
	|| instr_is_sse_or_sse2(instr)
	|| 1 != instr_num_dsts(instr)
	|| 1 != instr_num_srcs(instr)){
		return instr;
	}

	switch(instr_get_opcode(instr)) {
	case OP_push: case OP_pop:
	case OP_pusha: case OP_popa:
	case OP_pushf: case OP_popf:
	case OP_push_imm:
		return instr;
	default:
		break;
	}

	collect_regs(&registers, instr, instr_num_srcs, instr_get_src );
	collect_regs(&registers, instr, instr_num_dsts, instr_get_dst );

	reg_id_t mem_addr_id = get_next_free_reg(&registers);
	reg_id_t src_val_reg_id = get_next_free_reg(&registers);
	opnd_t reg_mem_addr = opnd_create_reg(mem_addr_id);
	opnd_t src_val_reg = opnd_create_reg(src_val_reg_id);

	opnd_t dest_ref = instr_get_dst(instr, 0);

	if (opnd_is_rel_addr(dest_ref) || opnd_is_abs_addr(dest_ref)) {

	}else if (opnd_is_base_disp(dest_ref)) {
		reg_id_t dest_reg = opnd_get_base(dest_ref);

		// ignore likely local variables
		switch (dest_reg) {
		case DR_REG_RSP:
		case DR_REG_ESP:
		case DR_REG_SP:
		case DR_REG_RBP:
		case DR_REG_EBP:
		case DR_REG_BP:
			return instr;
		default:
			break;
		}

		if(instr_get_opcode(instr) == OP_mov_st) {

			instr_app_pc = instr_get_app_pc(instr);

			instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pushf(drcontext));

			// spill a register so that we can store the source/destination address of this memory operation
			instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_push(drcontext, reg_mem_addr));

			instrlist_meta_preinsert(
					ilist,
					instr,
					INSTR_CREATE_lea(drcontext,
							reg_mem_addr,
							opnd_create_base_disp(dest_reg, opnd_get_index(dest_ref), opnd_get_scale(dest_ref), opnd_get_disp(dest_ref), OPSZ_lea)));

			instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_push(drcontext, src_val_reg));

				/*
				cloned_op = instr_clone(drcontext, instr);
				instr_set_app_pc(cloned_op, NULL);
				instr_set_dst(cloned_op, 0, src_val_reg);
				instrlist_meta_preinsert(ilist, instr, cloned_op);
				 */
			break_on_src_opnd(instr_app_pc);
			opnd_t src_opnd = instr_get_src(instr, 0);

			reg_id_t src_reg_id = opnd_get_reg(src_opnd);
			if(src_reg_id < DR_REG_AL)
			{
				reg_id_t new_reg_id = change_reg_64bit_class(src_reg_id);
				printk("new reg id : %d\n", new_reg_id);

				if(new_reg_id < DR_REG_EAX && new_reg_id > DR_REG_NULL )
				{
					instrlist_meta_preinsert(
							ilist,
							instr,
							INSTR_CREATE_mov_st(drcontext, src_val_reg, opnd_create_reg(new_reg_id)));
				}
			}


			dr_insert_clean_call(drcontext, ilist, instr, (void *)clean_call, false, 2, reg_mem_addr, src_val_reg);

			instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, src_val_reg));
			instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, reg_mem_addr));
			instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_popf(drcontext));
		}

	} else {

	}
}

instr_t *
alias_instr(void *drcontext, instrlist_t *ilist, instr_t *instr) {
	instr_t *cloned_op = NULL;
	instr_t *nulled_op = NULL;

	// clone the operation, but make sure the cloned operation is seen
	// as not having an app pc
	cloned_op = instr_clone(drcontext, instr);
	instr_set_app_pc(cloned_op, NULL);
	instrlist_meta_preinsert(ilist, instr, cloned_op);

	// add in a NOP in place of the original instruction, such that the
	// NOP maps to the original instruction's app pc.
	nulled_op = INSTR_CREATE_nop(drcontext);
	instr_set_app_pc(nulled_op, instr_get_app_pc(instr));
	instrlist_meta_preinsert(ilist, instr, nulled_op);

	instrlist_remove(ilist, instr);

	return nulled_op;
}


/*
 load the HOLE_END_MEMORY in the spill reg
instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, kernel_hole_reg, OPND_CREATE_INT64(KERNEL_MEMORY_HOLE_END)));

//load the source/dest into reg_mem_addr
instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_lea(drcontext,
						reg_mem_addr,
						opnd_create_base_disp(dest_reg, opnd_get_index(mem_ref), opnd_get_scale(mem_ref), opnd_get_disp(mem_ref), OPSZ_lea)));

instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_jcc(drcontext, OP_jg, opnd_create_instr(emulate_write_op)));
 */

static dr_emit_flags_t
bb_event(void *drcontext, void *tag, instrlist_t *bb, bool for_trace, bool translating)
{
	instr_t *instr,*next_instr, *last_instr;
	opnd_t op;
	uint opcode;
	int i;
	int instrumented = 0;
	app_pc first_instr = NULL;

	for(instr = instrlist_first(bb); instr != NULL; instr = instr_get_next(instr))
	{
		if(NULL == instr_get_app_pc(instr)) {
			continue;
		}

		/*if(NULL == first_instr) {
			first_instr = instr_get_app_pc(instr);
		}
		 */
		if(!instr_opcode_valid(instr)) {
			continue;
		}

		if(instr_writes_memory(instr)) {
			instrument_write_mem_dummy(drcontext, bb, instr, true);
		} else if(instr_reads_memory(instr)) {
			//instrument_read_mem_dummy(instr);
		}

		/*
		instr = alias_instr(drcontext, bb, instr);
		instrumented = 1;*/
	}
	/*
	if(instrumented) {
		extern unsigned long long module_text_start;
		log_address((uint64) first_instr - module_text_start);
	}
	 */
	return DR_EMIT_DEFAULT;

#if 0

	if(instr_is_cti(instr) && instr_num_srcs(instr))
	{
		op = instr_get_target(instr);
		event_bb
		if(instr_is_call_direct(instr))
		{
			//address_opnd = opnd_get_pc(op);

			dr_insert_call_instrumentation(drcontext, bb, instr, (app_pc)at_direct_call);
			//  bb->translation_target = dr_app_stop;

		}else if(instr_is_call_indirect(instr))
		{
			if(opnd_is_near_pc(op))
			{
				dr_insert_call_instrumentation(drcontext, bb, instr, (app_pc)at_indirect_call);
			}
			else if(instr_is_mbr(instr)){
				dr_insert_mbr_instrumentation(drcontext, bb, instr, (app_pc)at_indirect_call, SPILL_SLOT_1);
			}

		}
	}
#endif
}

static void
event_thread_init(void *drcontext)
{
	char logname[MAXIMUM_PATH];
	char *dirsep;
	int len;
	printk("event log : %s\n", __FUNCTION__);

	per_thread_t *data;

	/* allocate thread private data */
	/*    data = dr_thread_alloc(drcontext, sizeof(per_thread_t));
	 */


}

static void
event_thread_exit(void *drcontext)
{
	//printk("event log : %s\n", __FUNCTION__);
}


/**
 * Initialize the CFI extension.
 */
void
drinit(client_id_t id)
{
	printk("drinit cfi %d\n", id);

#if 0 && CFI_SEQUENTIALIZE_MODULE

	// register the callback to add in the sequencing and isntruction
	// counting instrumentation to basic blocks
	dr_register_bb_event(cfi_seq_bb_event);

#endif


#ifdef GRANARY_MEM_INSTRUMENTATION
	dr_register_bb_event(bb_event);
	dr_register_thread_init_event(event_thread_init);
	dr_register_thread_exit_event(event_thread_exit);
#endif
}
