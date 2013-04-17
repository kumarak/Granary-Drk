/*
 * cfi_instrument.c
 *
 *  Created on: 2012-04-08
 *      Author: akshayk
 */


#include <stddef.h>

#include "cfi_module.h"
#include "cfi_wrapper.h"
#include "kernel_linux/clients/dcontext_extend.h"

extern int DRK_IS_RUNNING;

#define GRANARY_MEM_INSTRUMENTATION

/**
 * Called when the instrumented module returns to the kernel function that called
 * it.
 */
static void handle_module_exit_function_return(void *drcontext) {
    (void) drcontext;
}

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
extern void cfi_release_module(void);
extern void cfi_exit_return_to_kernel(void);

void drinit_dcontext(unsigned int thread_id) {
    dr_init_client_extension(cfi_init_dcontext, DR_EXTENSION(cfi));
    dr_register_kernel_wrapper(cfi_get_kernel_wrapper);
    dr_register_direct_call_exit((void*)cfi_exit_direct_call);
    dr_register_address_untracker(cfi_get_untracked_address);
    dr_register_address_return_exit(cfi_exit_return_to_kernel);
    dr_register_return_path_address(cfi_return_to_module_from_kernel);
    dr_register_exit_module_context(cfi_release_module);
}

#ifdef GRANARY_MEM_INSTRUMENTATION

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
static reg_id_t change_reg_class(reg_id_t reg, reg_id_t reg_class) {
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

static void break_always_base_disp()
{

}

static void break_always_mem_ref()
{

}

static void break_always_on_default()
{

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

/*bool ref_is_local_var(op)
{
	int i;
	if(!opnd_is_base_disp(opnd))
	return true;
}
*/
static void
replace_instr(void* drcontext, instrlist_t *ilist, instr_t **old, instr_t *new)
{
	//instr_set_translation(new, instr_get_translation(*old));
	instrlist_replace(ilist, *old, new);
	instr_destroy(drcontext, *old);
	*old = new;
}



/*
bool
is_instr_local_var_write(instr_t instr)
{

	if(ref_is_stack_mem(opnd) &&)
}

*/

static const char *op_name(int opcode) {
	static const char *op_names[] = {
#		define OP_MACRO(o) #o ,
#		include "opcodes.h"
#		undef OP_MACRO
		"" // sentinel
	};
	return op_names[opcode];
}

void (*null_function)(void);

static void break_at_reg(reg_id_t reg, app_pc pc) {

}


#define INVALID_MEM_ADDR -1
#define REG_SPILL_START DR_REG_XAX
#define REG_SPILL_STOP DR_REG_R15


static void
instrument_write_mem(void *drcontext, instrlist_t *ilist, instr_t *instr, bool write)
{
	int i;
	instr_t *meta_instr;
    opnd_t dest_ref, opnd_src, opnd_dest, opnd1;
    instrlist_t* ilist_pre = instrlist_create(drcontext);
    instrlist_t* ilist_post = instrlist_create(drcontext);
    ptr_int_t pt_addr;
    int num_src, num_dest;
    unsigned long registers = 0;
    reg_id_t spill_reg_2;

    printk("--%s--", __FUNCTION__);
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

    /* get the spill reg*/
    opnd_t spill_reg;
    reg_id_t spill_reg_id = get_next_free_reg(&registers);
   	if(DR_REG_NULL < spill_reg_id
   	&& DR_REG_R15 >= spill_reg_id
   	&& DR_REG_RSP != spill_reg_id
   	&& DR_REG_RBP != spill_reg_id) {
   		spill_reg = opnd_create_reg(spill_reg_id);
    }
   	else {
   		break_at_reg(spill_reg_id, instr_get_app_pc(instr));
   		return;
   		//DR_ASSERT_MSG(false, "what is this\n");
   	}

    for(i=0; i < instr_num_dsts(instr); i++)
    {
        reg_id_t spill_reg_id = get_next_free_reg(&registers);
        opnd_t spill_reg = opnd_create_reg(spill_reg_id);

    	dest_ref = instr_get_dst(instr, i);

    	if(DR_REG_NULL == spill_reg_id || DR_REG_R15 < spill_reg_id) {
    		break_on_weird_reg(spill_reg_id);
    	}

    	if(opnd_is_rel_addr(dest_ref) || opnd_is_abs_addr(dest_ref)) {

    		if(instr_get_rel_addr_dst_idx(instr) == INVALID_MEM_ADDR)
    		{

    			get the target address in the destination
    			pt_addr = opnd_get_addr(dest_ref);
    			pt_addr |= 0x0;

    			opnd_dest = OPND_CREATE_INT64(opnd_get_addr(dest_ref));

    			//instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_nop(drcontext));
    			//instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_nop(drcontext));

    			//instr_set_dst(instr, i, opnd_dest);
    			break_always_mem_ref();
    		}

		} else if (opnd_is_base_disp(dest_ref)) {
			reg_id_t dest_reg = opnd_get_base(dest_ref);

			// ignore likely local variables
			switch(dest_reg) {
			case DR_REG_RSP: case DR_REG_ESP:  case DR_REG_SP:
			case DR_REG_RBP: case DR_REG_EBP: case DR_REG_BP:
				return;
				//continue;
				//free_reg(&registers, spill_reg_id);
				//goto pop_register;
			default: break;
			}

			instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_push(drcontext, spill_reg));
			meta_instr = INSTR_CREATE_lea(drcontext,
							spill_reg,
							opnd_create_base_disp(dest_reg, opnd_get_index(dest_ref), opnd_get_scale(dest_ref), opnd_get_disp(dest_ref), OPSZ_lea));
			instrlist_meta_preinsert(ilist, instr, meta_instr);
			instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, spill_reg, OPND_CREATE_INT64(0x0)));
			instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, spill_reg));

			//instrlist_postinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, spill_reg, OPND_CREATE_INT64(0x0)));
			meta_instr = INSTR_CREATE_lea(drcontext,
					spill_reg,
					opnd_create_base_disp(dest_reg, opnd_get_index(dest_ref), opnd_get_scale(dest_ref), opnd_get_disp(dest_ref), OPSZ_lea));
			instrlist_postinsert(ilist, instr, meta_instr);
		//	instrlist_postinsert(ilist, instr, INSTR_CREATE_pop(drcontext, spill_reg));
			instrlist_postinsert(ilist, instr, INSTR_CREATE_popf(drcontext));


			if(instr_get_opcode(instr) == OP_mov_ld || instr_get_opcode(instr) == OP_mov_st  )
			{
				//instrlist_preinsert(ilist, instr, INSTR_CREATE_push(drcontext, spill_reg));
				//instrlist_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, spill_reg, OPND_CREATE_INT64(0x0)));

				if(!opnd_is_reg(dest_ref))
				{
					meta_instr = INSTR_CREATE_lea(drcontext,
							spill_reg,
							opnd_create_base_disp(dest_reg, opnd_get_index(dest_ref), opnd_get_scale(dest_ref), opnd_get_disp(dest_ref), OPSZ_lea));

					instrlist_preinsert(ilist, instr, meta_instr);

					spill_reg_2 = get_next_free_reg(&registers);
					instrlist_preinsert(ilist, instr, INSTR_CREATE_push(drcontext, opnd_create_reg(spill_reg_2)));
					instrlist_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_create_reg(spill_reg_2), OPND_CREATE_INT64(0x0)));
					instrlist_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_create_reg(spill_reg_2)));
				}

				//instrlist_postinsert(ilist, instr, INSTR_CREATE_pop(drcontext, spill_reg));
				//instrlist_preinsert(ilist, instr, INSTR_CREATE_popf(drcontext));
				break_always_base_disp();
			}





			if(opnd_is_reg(dest_ref))
			{
				spill_reg_2 = get_next_free_reg(&registers);
				instrlist_preinsert(ilist, instr, INSTR_CREATE_push(drcontext, opnd_create_reg(spill_reg_2)));
				instrlist_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_create_reg(spill_reg_2), OPND_CREATE_INT64(0x0)));

				instrlist_preinsert(ilist, instr, INSTR_CREATE_pushf(drcontext));
				//meta_instr =  INSTR_CREATE_or(drcontext, spill_reg, opnd_create_reg(spill_reg_2));
				//instrlist_preinsert(ilist, instr, meta_instr);
				instrlist_preinsert(ilist, instr, INSTR_CREATE_popf(drcontext));

				instrlist_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_create_reg(spill_reg_2)));
				instr_set_dst(instr, i, opnd_create_base_disp(
										change_reg_class(spill_reg_id, dest_reg),
										DR_REG_NULL, 0, 0,
										opnd_get_size(dest_ref)));
				break_always_base_disp();
			}

		//	meta_instr = INSTR_CREATE_pop(drcontext, spill_reg);
		//	instr_set_translation(meta_instr, instr_get_app_pc(instr));
		//	instrlist_preinsert(ilist, instr, meta_instr);

		//	instrlist_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, spill_reg));
	    } else {
	    	break_always_on_default();
	    	//DR_ASSERT_MSG(false, "Unhandled instructions");
	    }
    }

   // dr_save_reg(drcontext, ilist, instr, spill_reg_id, SPILL_SLOT_1);
   // dr_restore_reg(drcontext, ilist, instr, spill_reg_id, SPILL_SLOT_1);

    //instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_push(drcontext, spill_reg));
    //instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, spill_reg));
    //instrlist_meta_postinsert(ilist, instr, INSTR_CREATE_nop(drcontext));
    //instrlist_meta_postinsert(ilist, instr, INSTR_CREATE_nop(drcontext));
    //printk("\n");
}

static dr_emit_flags_t
bb_event(void *drcontext, void *tag, instrlist_t *bb, bool for_trace, bool translating)
{
	instr_t *instr,*next_instr, *last_instr;
    opnd_t op;
    uint opcode;
    int i;

    for(instr= instrlist_first(bb); instr != NULL; instr = instr_get_next(instr))
    {
    	if(instr_get_app_pc(instr) == NULL)
    		continue;

    	if(!instr_opcode_valid(instr))
    		continue;

    	if (instr_writes_memory(instr))
    	{
    		instrument_write_mem(drcontext, bb, instr, true);
    	}
    }

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

#endif
/**
 * Initialize the CFI extension.
 */
void
drinit(client_id_t id)
{
    printk("drinit cfi %d\n", id);
//    dr_init_client_extension(cfi_init_dcontext, DR_EXTENSION(cfi));
    dr_register_module_exit(handle_module_exit_function_return, MODULE_EXIT_RETURN);

#ifdef GRANARY_MEM_INSTRUMENTATION
    dr_register_bb_event(bb_event);
    dr_register_thread_init_event(event_thread_init);
    dr_register_thread_exit_event(event_thread_exit);
#endif
}
