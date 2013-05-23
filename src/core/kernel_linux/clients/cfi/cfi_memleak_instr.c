/*
 * cfi_leak_instrumentation.c
 *
 *  Created on: 2013-02-01
 *      Author: akshayk
 */

#include "cfi_instrumentation.h"
#include "cfi_insert_call.h"
#include "cfi_hashtable.h"


#define PRE     instrlist_meta_preinsert
#define POST    instrlist_meta_postinsert
#define APP  	instrlist_append

extern struct hashtable_t *alloc_pointer_hash;

static void
 dump_watch_write(void *src, void *dest){
    uint64_t value;
    int ret = -1;
    ret = hashmap_get(alloc_pointer_hash, src, &value);

    if(ret == 0)
        dr_printf("FOUND!!!!!!!!!   thread id  src %lx, dest : %lx\n", src, dest);
    else
        dr_printf("thread id  src %lx, dest : %lx\n", src, dest);
}

static bool
instr_is_reg_save(instr_t *instr)
{
    opnd_t opnd;

    if (instr_get_opcode(instr) != OP_mov_st)
        return false;
    opnd = instr_get_src(instr, 0);
    if (!opnd_is_reg(opnd))
        return false;

    return true;
}

void cfi_debug_call(void *addr) {
    //print_file(STDERR,"%s : %lx\n",__FUNCTION__, addr);
    dr_printf("%s : %lx\n",__FUNCTION__, addr);
}

#if 0

static instr_t*
instrument_reg_save(void *drcontext, instrlist_t *ilist, instr_t *instr, app_pc pc, opnd_t src_opnd, struct memory_operand_modifier *ops)
{
    unsigned long used_registers = 0;
    bool flag_unwatched_addr = false;
    reg_id_t reg_watched_addr;
    reg_id_t reg_unwatched_addr;
    struct spill_reg_t watched_addr;
    struct spill_reg_t unwatched_addr;
    struct spill_reg_t spill_reg[16];

    instr_t *addr_is_a_watchpoint = INSTR_CREATE_label(drcontext);
    instr_t *addr_is_not_a_watchpoint = INSTR_CREATE_label(drcontext);
    instr_t *begin_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *done_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *not_null = INSTR_CREATE_label(drcontext);

    instr_t *done_check = INSTR_CREATE_label(drcontext);
    instr_t *nop = INSTR_CREATE_nop(drcontext);
    instr_t *do_callback = INSTR_CREATE_label(drcontext);
    instr_t *next_nop = INSTR_CREATE_label(drcontext);
    instr_t *emulated;
    instr_t *cursor = instr;

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );

    reg_watched_addr = get_next_free_reg(&used_registers);
    opnd_t opnd_watched_addr = opnd_create_reg(reg_watched_addr);

    reg_unwatched_addr = get_next_free_reg(&used_registers);
    opnd_t opnd_unwatched_addr = opnd_create_reg(reg_unwatched_addr);

    opnd_t watched_addr_opnd = ops->found_operand;
    //watched_addr_opnd.size = OPSZ_lea;

    PRE(ilist, instr, begin_instrumenting);
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_watched_addr));
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_unwatched_addr));
    PRE(ilist, instr, INSTR_CREATE_pushf(drcontext));


    PRE(ilist, instr, INSTR_CREATE_lea(drcontext, opnd_watched_addr, opnd_create_base_disp(opnd_get_base(ops->found_operand),
                                                opnd_get_index(ops->found_operand), opnd_get_scale(ops->found_operand),
                                                opnd_get_disp(ops->found_operand), OPSZ_lea)));

    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_unwatched_addr, OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));

    PRE(ilist, instr, INSTR_CREATE_or(drcontext, opnd_unwatched_addr, opnd_watched_addr));
    PRE(ilist, instr, INSTR_CREATE_cmp(drcontext, opnd_unwatched_addr, opnd_watched_addr));

    PRE(ilist, instr, INSTR_CREATE_jcc(drcontext, OP_je, opnd_create_instr(addr_is_not_a_watchpoint)));

    PRE(ilist, instr, addr_is_a_watchpoint);

    emulated = instr_clone(drcontext, instr);
    emulated->translation = 0;

    ops->replacement_operand = opnd_create_base_disp(
            reg_unwatched_addr, DR_REG_NULL,1, 0 , ops->found_operand.size);

    for_each_operand(emulated, ops,
            (opnd_callback_t *) memory_operand_replacer);
    PRE(ilist, instr, INSTR_CREATE_popf(drcontext));
    PRE(ilist, instr, emulated);
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_unwatched_addr));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_watched_addr));

    PRE(ilist, instr, INSTR_CREATE_jmp_short(drcontext,
            opnd_create_instr(done_instrumenting)));

    PRE(ilist, instr, addr_is_not_a_watchpoint);
    PRE(ilist, instr, INSTR_CREATE_popf(drcontext));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_unwatched_addr));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_watched_addr));
    /*** original instruction here ***/
    instr->translation = 0; // hack!
    instr_being_modified(instr, false);
    instr_set_ok_to_mangle(instr, false);

    nop->translation = pc + instr->length;
    POST(ilist, instr, nop);
    POST(ilist, instr, done_instrumenting);
}

#endif

void
instrument_memory_write(void *drcontext, instrlist_t *ilist,
        instr_t *instr, app_pc pc, struct memory_operand_modifier *ops){

    unsigned long used_registers = 0;
    bool flag_unwatched_addr = false;
    reg_id_t reg_watched_addr;
    reg_id_t reg_unwatched_addr;
    struct spill_reg_t watched_addr;
    struct spill_reg_t unwatched_addr;
    reg_id_t spill_reg[16];
    opnd_t spill_reg_opnd[16];

    instr_t *addr_is_a_watchpoint = INSTR_CREATE_label(drcontext);
    instr_t *addr_is_not_a_watchpoint = INSTR_CREATE_label(drcontext);
    instr_t *begin_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *done_instrumenting = INSTR_CREATE_label(drcontext);

    instr_t *done_check = INSTR_CREATE_label(drcontext);
    instr_t *nop = INSTR_CREATE_nop(drcontext);
    instr_t *do_callback = INSTR_CREATE_label(drcontext);
    instr_t *next_nop = INSTR_CREATE_label(drcontext);
    instr_t *emulated;
    instr_t *cursor = instr;

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );

    reg_watched_addr = get_next_free_reg(&used_registers);
    opnd_t opnd_watched_addr = opnd_create_reg(reg_watched_addr);

    reg_unwatched_addr = get_next_free_reg(&used_registers);
    opnd_t opnd_unwatched_addr = opnd_create_reg(reg_unwatched_addr);

    opnd_t watched_addr_opnd = ops->found_operand;

    PRE(ilist, instr, begin_instrumenting);
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_watched_addr));
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_unwatched_addr));
    PRE(ilist, instr, INSTR_CREATE_pushf(drcontext));


    PRE(ilist, instr, INSTR_CREATE_lea(drcontext, opnd_watched_addr, opnd_create_base_disp(opnd_get_base(ops->found_operand),
                                                opnd_get_index(ops->found_operand), opnd_get_scale(ops->found_operand),
                                                opnd_get_disp(ops->found_operand), OPSZ_lea)));
#if 0
    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_unwatched_addr,
                                            OPND_CREATE_INT64(WATCHPOINT_BASE)));
    PRE(ilist, instr, INSTR_CREATE_cmp(drcontext, opnd_watched_addr, opnd_unwatched_addr));
    PRE(ilist, instr, INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(addr_is_not_a_watchpoint)));

#else
    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_unwatched_addr,
                                            OPND_CREATE_INT64(WATCHPOINT_ADDRESS_MASK)));
    PRE(ilist, instr, INSTR_CREATE_and(drcontext, opnd_unwatched_addr, opnd_watched_addr));

    spill_reg[0] = get_next_free_reg(&used_registers);
    spill_reg_opnd[0] = opnd_create_reg(spill_reg[0]);
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, spill_reg_opnd[0]));

    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, spill_reg_opnd[0],
            OPND_CREATE_INT64(WATCHPOINT)));

    PRE(ilist, instr, INSTR_CREATE_cmp(drcontext, opnd_unwatched_addr, spill_reg_opnd[0]));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, spill_reg_opnd[0]));
    PRE(ilist, instr, INSTR_CREATE_jcc(drcontext, OP_jne, opnd_create_instr(addr_is_not_a_watchpoint)));
#endif


    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_unwatched_addr,
                                        OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));

    PRE(ilist, instr, INSTR_CREATE_or(drcontext, opnd_unwatched_addr, opnd_watched_addr));
    PRE(ilist, instr, INSTR_CREATE_cmp(drcontext, opnd_unwatched_addr, opnd_watched_addr));

    PRE(ilist, instr, INSTR_CREATE_jcc(drcontext, OP_je, opnd_create_instr(addr_is_not_a_watchpoint)));

    PRE(ilist, instr, addr_is_a_watchpoint);

    emulated = instr_clone(drcontext, instr);
    emulated->translation = 0;

    ops->replacement_operand = opnd_create_base_disp(
            reg_unwatched_addr, DR_REG_NULL,1, 0 , ops->found_operand.size);

    for_each_operand(emulated, ops,
            (opnd_callback_t *) memory_operand_replacer);
    PRE(ilist, instr, INSTR_CREATE_popf(drcontext));
    PRE(ilist, instr, emulated);
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_unwatched_addr));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_watched_addr));

    PRE(ilist, instr, INSTR_CREATE_jmp_short(drcontext,
            opnd_create_instr(done_instrumenting)));

    PRE(ilist, instr, addr_is_not_a_watchpoint);
    PRE(ilist, instr, INSTR_CREATE_popf(drcontext));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_unwatched_addr));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_watched_addr));

    /*** original instruction here ***/
    instr->translation = 0; // hack!
    instr_being_modified(instr, false);
    instr_set_ok_to_mangle(instr, false);

    nop->translation = pc + instr->length;
    POST(ilist, instr, nop);
    POST(ilist, instr, done_instrumenting);
}



void
instrument_memory_read(void *drcontext, instrlist_t *ilist,
        instr_t *instr, app_pc pc, struct memory_operand_modifier *ops){

    unsigned long used_registers = 0;
    bool flag_unwatched_addr = false;
    reg_id_t reg_watched_addr;
    reg_id_t reg_unwatched_addr;
    struct spill_reg_t watched_addr;
    struct spill_reg_t unwatched_addr;
    reg_id_t spill_reg[16];
    opnd_t spill_reg_opnd[16];

    instr_t *addr_is_a_watchpoint = INSTR_CREATE_label(drcontext);
    instr_t *addr_is_not_a_watchpoint = INSTR_CREATE_label(drcontext);
    instr_t *begin_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *done_instrumenting = INSTR_CREATE_label(drcontext);

    instr_t *done_check = INSTR_CREATE_label(drcontext);
    instr_t *nop = INSTR_CREATE_nop(drcontext);
    instr_t *do_callback = INSTR_CREATE_label(drcontext);
    instr_t *next_nop = INSTR_CREATE_label(drcontext);
    instr_t *not_null = INSTR_CREATE_label(drcontext);
    instr_t *emulated;
    instr_t *cursor = instr;

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );

    reg_watched_addr = get_next_free_reg(&used_registers);
    opnd_t opnd_watched_addr = opnd_create_reg(reg_watched_addr);

    reg_unwatched_addr = get_next_free_reg(&used_registers);
    opnd_t opnd_unwatched_addr = opnd_create_reg(reg_unwatched_addr);

    opnd_t watched_addr_opnd = ops->found_operand;


    PRE(ilist, instr, begin_instrumenting);
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_watched_addr));
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_unwatched_addr));
    PRE(ilist, instr, INSTR_CREATE_pushf(drcontext));


    PRE(ilist, instr, INSTR_CREATE_lea(drcontext, opnd_watched_addr, opnd_create_base_disp(opnd_get_base(ops->found_operand),
                                                opnd_get_index(ops->found_operand), opnd_get_scale(ops->found_operand),
                                                opnd_get_disp(ops->found_operand), OPSZ_lea)));

#if 0
    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_unwatched_addr,
                                            OPND_CREATE_INT64(WATCHPOINT_BASE)));
    PRE(ilist, instr, INSTR_CREATE_cmp(drcontext, opnd_watched_addr, opnd_unwatched_addr));
    PRE(ilist, instr, INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(addr_is_not_a_watchpoint)));

#else
    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_unwatched_addr,
                                            OPND_CREATE_INT64(WATCHPOINT_ADDRESS_MASK)));
    PRE(ilist, instr, INSTR_CREATE_and(drcontext, opnd_unwatched_addr, opnd_watched_addr));

    spill_reg[0] = get_next_free_reg(&used_registers);
    spill_reg_opnd[0] = opnd_create_reg(spill_reg[0]);
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, spill_reg_opnd[0]));

    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, spill_reg_opnd[0],
            OPND_CREATE_INT64(WATCHPOINT)));

    PRE(ilist, instr, INSTR_CREATE_cmp(drcontext, opnd_unwatched_addr, spill_reg_opnd[0]));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, spill_reg_opnd[0]));
    PRE(ilist, instr, INSTR_CREATE_jcc(drcontext, OP_jne, opnd_create_instr(addr_is_not_a_watchpoint)));
#endif

    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_unwatched_addr, OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));
    PRE(ilist, instr, INSTR_CREATE_or(drcontext, opnd_unwatched_addr, opnd_watched_addr));
    PRE(ilist, instr, INSTR_CREATE_cmp(drcontext, opnd_unwatched_addr, opnd_watched_addr));

    PRE(ilist, instr, INSTR_CREATE_jcc(drcontext, OP_je, opnd_create_instr(addr_is_not_a_watchpoint)));

    PRE(ilist, instr, addr_is_a_watchpoint);

    emulated = instr_clone(drcontext, instr);
    emulated->translation = 0;

    ops->replacement_operand = opnd_create_base_disp(
            reg_unwatched_addr, DR_REG_NULL,1, 0 , ops->found_operand.size);

    for_each_operand(emulated, ops,
            (opnd_callback_t *) memory_operand_replacer);
    PRE(ilist, instr, INSTR_CREATE_popf(drcontext));
    PRE(ilist, instr, emulated);
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_unwatched_addr));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_watched_addr));

    PRE(ilist, instr, INSTR_CREATE_jmp_short(drcontext,
            opnd_create_instr(done_instrumenting)));

    PRE(ilist, instr, addr_is_not_a_watchpoint);
    PRE(ilist, instr, INSTR_CREATE_popf(drcontext));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_unwatched_addr));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_watched_addr));
    /*** original instruction here ***/
    instr->translation = 0; // hack!
    instr_being_modified(instr, false);
    instr_set_ok_to_mangle(instr, false);

    nop->translation = pc + instr->length;
    POST(ilist, instr, nop);
    POST(ilist, instr, done_instrumenting);

}

static void
instrument_write_rep_stos(void *drcontext, instrlist_t *ilist,
        instr_t *instr, app_pc pc, struct memory_operand_modifier *ops, bool is_write){

    unsigned long used_registers = 0;
    reg_id_t instr_reg;
    opnd_t instr_opnd;
    opnd_t opnd_instr_reg;
    instr_t *emulated;

    instr_t *begin_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *done_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *nop = INSTR_CREATE_nop(drcontext);

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );
    collect_reg(&used_registers, DR_REG_RCX);

    reg_id_t reg_mask = get_next_free_reg(&used_registers);
    opnd_t opnd_reg_mask = opnd_create_reg(reg_mask);

    if(is_write) {
        instr_opnd = instr_get_dst(instr, 0);
    }else {
        instr_opnd = instr_get_src(instr, 0);
    }

    instr_reg = opnd_get_base(instr_opnd);
    opnd_instr_reg = opnd_create_reg(instr_reg);

    PRE(ilist, instr, begin_instrumenting);
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_instr_reg));
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_reg_mask));
    PRE(ilist, instr, INSTR_CREATE_pushf(drcontext));
    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_reg_mask, OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));

    PRE(ilist, instr, INSTR_CREATE_or(drcontext, opnd_instr_reg, opnd_reg_mask));

    emulated = instr_clone(drcontext, instr);
    emulated->translation = 0;
    PRE(ilist, instr, INSTR_CREATE_popf(drcontext));
    PRE(ilist, instr, emulated);
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_reg_mask));
    //PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_instr_reg_src));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_instr_reg));
    PRE(ilist, instr, INSTR_CREATE_jmp_short(drcontext,
            opnd_create_instr(done_instrumenting)));

    instr->translation = 0; // hack!
    instr_being_modified(instr, false);
    instr_set_ok_to_mangle(instr, false);

    nop->translation = pc + instr->length + done_instrumenting->length;
    POST(ilist, instr, nop);
    POST(ilist, instr, done_instrumenting);
}

static void
instrument_write_rep_movs(void *drcontext, instrlist_t *ilist, instr_t *instr,
        app_pc pc, struct memory_operand_modifier *ops, bool is_write)
{
    unsigned long used_registers = 0;
    reg_id_t instr_reg;
    opnd_t instr_opnd_src;
    opnd_t instr_opnd_dsts;
    opnd_t opnd_instr_reg;
    instr_t *emulated;

    instr_t *begin_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *done_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *no_dsts_mask = INSTR_CREATE_label(drcontext);
    instr_t *no_src_mask = INSTR_CREATE_label(drcontext);
    instr_t *nop = INSTR_CREATE_nop(drcontext);

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );
    collect_reg(&used_registers, DR_REG_RCX);

    reg_id_t reg_mask = get_next_free_reg(&used_registers);
    opnd_t opnd_reg_mask = opnd_create_reg(reg_mask);

    instr_opnd_dsts = instr_get_dst(instr, 0);
    instr_opnd_src = instr_get_src(instr, 0);

    reg_id_t instr_reg_dsts = opnd_get_base(instr_opnd_dsts);
    opnd_t opnd_instr_reg_dsts = opnd_create_reg(instr_reg_dsts);

    reg_id_t instr_reg_src = opnd_get_base(instr_opnd_src);
    opnd_t opnd_instr_reg_src = opnd_create_reg(instr_reg_src);

    PRE(ilist, instr, begin_instrumenting);
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_instr_reg_dsts));
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_instr_reg_src));
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_reg_mask));
    PRE(ilist, instr, INSTR_CREATE_pushf(drcontext));
    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_reg_mask,
                                            OPND_CREATE_INT64(WATCHPOINT_BASE)));

    PRE(ilist, instr, INSTR_CREATE_cmp(drcontext, opnd_instr_reg_dsts, opnd_reg_mask));
    PRE(ilist, instr, INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(no_dsts_mask)));

    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_reg_mask, OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));
    PRE(ilist, instr, INSTR_CREATE_or(drcontext, opnd_instr_reg_dsts, opnd_reg_mask));

    PRE(ilist, instr, no_dsts_mask);
    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_reg_mask,
                                            OPND_CREATE_INT64(WATCHPOINT_BASE)));

    PRE(ilist, instr, INSTR_CREATE_cmp(drcontext, opnd_instr_reg_src, opnd_reg_mask));
    PRE(ilist, instr, INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(no_src_mask)));

    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_reg_mask, OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));
    PRE(ilist, instr, INSTR_CREATE_or(drcontext, opnd_instr_reg_src, opnd_reg_mask));

    PRE(ilist, instr, no_src_mask);

    emulated = instr_clone(drcontext, instr);
    emulated->translation = 0;
    PRE(ilist, instr, INSTR_CREATE_popf(drcontext));
    PRE(ilist, instr, emulated);
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_reg_mask));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_instr_reg_src));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_instr_reg_dsts));
    PRE(ilist, instr, INSTR_CREATE_jmp_short(drcontext,
            opnd_create_instr(done_instrumenting)));

    instr->translation = 0; // hack!
    instr_being_modified(instr, false);
    instr_set_ok_to_mangle(instr, false);

    nop->translation = pc + instr->length + done_instrumenting->length;
    POST(ilist, instr, nop);
    POST(ilist, instr, done_instrumenting);
}


static void
instrument_write_rep_cmps(void *drcontext, instrlist_t *ilist, instr_t *instr,
        app_pc pc, struct memory_operand_modifier *ops, bool is_write)
{
    unsigned long used_registers = 0;
    reg_id_t instr_reg;
    opnd_t instr_opnd_src0;
    opnd_t instr_opnd_src1;
    opnd_t opnd_instr_reg;
    instr_t *emulated;

    instr_t *begin_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *done_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *no_dsts_mask = INSTR_CREATE_label(drcontext);
    instr_t *no_src_mask = INSTR_CREATE_label(drcontext);
    instr_t *nop = INSTR_CREATE_nop(drcontext);

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );
    collect_reg(&used_registers, DR_REG_RCX);

    reg_id_t reg_mask = get_next_free_reg(&used_registers);
    opnd_t opnd_reg_mask = opnd_create_reg(reg_mask);

    instr_opnd_src0 = instr_get_src(instr, 0);
    instr_opnd_src1 = instr_get_src(instr, 1);

    reg_id_t instr_reg_src0 = opnd_get_base(instr_opnd_src0);
    opnd_t opnd_instr_reg_src0 = opnd_create_reg(instr_reg_src0);

    reg_id_t instr_reg_src1 = opnd_get_base(instr_opnd_src1);
    opnd_t opnd_instr_reg_src1 = opnd_create_reg(instr_reg_src1);

    PRE(ilist, instr, begin_instrumenting);
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_instr_reg_src0));
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_instr_reg_src1));
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_reg_mask));
    PRE(ilist, instr, INSTR_CREATE_pushf(drcontext));
    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_reg_mask,
                                            OPND_CREATE_INT64(WATCHPOINT_BASE)));

    PRE(ilist, instr, INSTR_CREATE_cmp(drcontext, opnd_instr_reg_src0, opnd_reg_mask));
    PRE(ilist, instr, INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(no_dsts_mask)));

    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_reg_mask, OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));
    PRE(ilist, instr, INSTR_CREATE_or(drcontext, opnd_instr_reg_src0, opnd_reg_mask));

    PRE(ilist, instr, no_dsts_mask);
    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_reg_mask,
                                            OPND_CREATE_INT64(WATCHPOINT_BASE)));

    PRE(ilist, instr, INSTR_CREATE_cmp(drcontext, opnd_instr_reg_src1, opnd_reg_mask));
    PRE(ilist, instr, INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(no_src_mask)));

    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_reg_mask, OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));
    PRE(ilist, instr, INSTR_CREATE_or(drcontext, opnd_instr_reg_src1, opnd_reg_mask));

    PRE(ilist, instr, no_src_mask);

    emulated = instr_clone(drcontext, instr);
    emulated->translation = 0;
    PRE(ilist, instr, INSTR_CREATE_popf(drcontext));
    PRE(ilist, instr, emulated);
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_reg_mask));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_instr_reg_src1));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_instr_reg_src0));
    PRE(ilist, instr, INSTR_CREATE_jmp_short(drcontext,
            opnd_create_instr(done_instrumenting)));

    instr->translation = 0; // hack!
    instr_being_modified(instr, false);
    instr_set_ok_to_mangle(instr, false);

    nop->translation = pc + instr->length + done_instrumenting->length;
    POST(ilist, instr, nop);
    POST(ilist, instr, done_instrumenting);
}


static void
instrument_instr_dec(void *drcontext, instrlist_t *ilist, instr_t *instr, app_pc pc, struct memory_operand_modifier *ops, bool flag)
{
    unsigned long used_registers = 0;
    reg_id_t dsts_reg;
    opnd_t opnd_dsts;
    opnd_t opnd_dsts_reg;
    instr_t *emulated;

    instr_t *begin_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *done_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *nop = INSTR_CREATE_nop(drcontext);

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );
    reg_id_t reg_mask = get_next_free_reg(&used_registers);
    opnd_t opnd_reg_mask = opnd_create_reg(reg_mask);

    if(flag == true){
        opnd_dsts = instr_get_dst(instr, 0);
    } else {
        opnd_dsts = instr_get_src(instr, 0);
    }

    dsts_reg = opnd_get_base(opnd_dsts);
    opnd_dsts_reg = opnd_create_reg(dsts_reg);

    PRE(ilist, instr, begin_instrumenting);
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_dsts_reg));
    PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_reg_mask));
    PRE(ilist, instr, INSTR_CREATE_pushf(drcontext));
    PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_reg_mask, OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));

    PRE(ilist, instr, INSTR_CREATE_or(drcontext, opnd_dsts_reg, opnd_reg_mask));
    emulated = instr_clone(drcontext, instr);
    emulated->translation = 0;

    PRE(ilist, instr, INSTR_CREATE_popf(drcontext));
    PRE(ilist, instr, emulated);
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_reg_mask));
    PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_dsts_reg));
    PRE(ilist, instr, INSTR_CREATE_jmp_short(drcontext,
            opnd_create_instr(done_instrumenting)));

    instr->translation = 0; // hack!
    instr_being_modified(instr, false);
    instr_set_ok_to_mangle(instr, false);

    nop->translation = pc + instr->length + done_instrumenting->length;
    POST(ilist, instr, nop);
    POST(ilist, instr, done_instrumenting);
}


static void
instrument_mem_instr(void *drcontext, instrlist_t *ilist,
        instr_t *instr, app_pc pc, bool flag)
{
    unsigned long used_registers = 0;
    reg_id_t instr_reg;
    opnd_t instr_opnd;
    opnd_t opnd_reg;

    instr_t *emulated;

    instr_t *begin_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *done_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *nop = INSTR_CREATE_nop(drcontext);

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );

    reg_id_t reg_mask = get_next_free_reg(&used_registers);
    opnd_t opnd_reg_mask = opnd_create_reg(reg_mask);

    if(flag == true){
        instr_opnd = instr_get_dst(instr, 0);
    } else {
        instr_opnd = instr_get_src(instr, 0);
    }

    if (opnd_is_rel_addr(instr_opnd) || opnd_is_abs_addr(instr_opnd)) {

    }else if (opnd_is_base_disp(instr_opnd)) {
        instr_reg = opnd_get_base(instr_opnd);
        opnd_reg = opnd_create_reg(instr_reg);

        PRE(ilist, instr, begin_instrumenting);
        PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_reg));
        PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_reg_mask));
        PRE(ilist, instr, INSTR_CREATE_pushf(drcontext));
        PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_reg_mask, OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));

        PRE(ilist, instr, INSTR_CREATE_or(drcontext, opnd_reg, opnd_reg_mask));
        emulated = instr_clone(drcontext, instr);
        emulated->translation = 0;

        PRE(ilist, instr, INSTR_CREATE_popf(drcontext));
        if(instr->prefixes & 0xf0 == 0xf0)
        {
            emulated->prefixes = instr->prefixes;
        }
        PRE(ilist, instr, emulated);
        PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_reg_mask));
        PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_reg));
        PRE(ilist, instr, INSTR_CREATE_jmp_short(drcontext,
                opnd_create_instr(done_instrumenting)));

        instr->translation = 0; // hack!
        instr_being_modified(instr, false);
        instr_set_ok_to_mangle(instr, false);

        nop->translation = pc + instr->length + done_instrumenting->length;
        POST(ilist, instr, nop);
        POST(ilist, instr, done_instrumenting);
    }
}


static void
instrument_mem_instr_xadd(void *drcontext, instrlist_t *ilist,
        instr_t *instr, app_pc pc, bool flag)
{
    unsigned long used_registers = 0;
    reg_id_t instr_reg;
    opnd_t instr_opnd;
    opnd_t opnd_reg;

    instr_t *emulated;

    instr_t *begin_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *done_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *nop = INSTR_CREATE_nop(drcontext);

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );
    collect_reg(&used_registers, DR_REG_RAX);
    collect_reg(&used_registers, DR_REG_RBX);
    collect_reg(&used_registers, DR_REG_RCX);
    collect_reg(&used_registers, DR_REG_RDX);
    collect_reg(&used_registers, DR_REG_RSI);
    collect_reg(&used_registers, DR_REG_RDI);

    reg_id_t reg_mask = get_next_free_reg(&used_registers);
    opnd_t opnd_reg_mask = opnd_create_reg(reg_mask);

    if(flag == true){
        instr_opnd = instr_get_dst(instr, 0);
    } else {
        instr_opnd = instr_get_src(instr, 0);
    }

    if (opnd_is_rel_addr(instr_opnd) || opnd_is_abs_addr(instr_opnd)) {

    }else if (opnd_is_base_disp(instr_opnd)) {
        instr_reg = opnd_get_base(instr_opnd);
        opnd_reg = opnd_create_reg(instr_reg);

        PRE(ilist, instr, begin_instrumenting);
        PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_reg));
        PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_reg_mask));
        PRE(ilist, instr, INSTR_CREATE_pushf(drcontext));
        PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_reg_mask, OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));

        PRE(ilist, instr, INSTR_CREATE_or(drcontext, opnd_reg, opnd_reg_mask));
        emulated = instr_clone(drcontext, instr);
        emulated->translation = 0;

        PRE(ilist, instr, INSTR_CREATE_popf(drcontext));
        if(instr->prefixes & 0xf0 == 0xf0)
        {
            emulated->prefixes = instr->prefixes;
        }
        PRE(ilist, instr, emulated);
        PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_reg_mask));
        PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_reg));
        PRE(ilist, instr, INSTR_CREATE_jmp_short(drcontext,
                opnd_create_instr(done_instrumenting)));

        instr->translation = 0; // hack!
        instr_being_modified(instr, false);
        instr_set_ok_to_mangle(instr, false);

        nop->translation = pc + instr->length + done_instrumenting->length;
        POST(ilist, instr, nop);
        POST(ilist, instr, done_instrumenting);
    }
}

static bool inline is_kernel_text(app_pc pc){
	return (pc >= (app_pc) KERNEL_START_ADDR) && (pc < (app_pc) KERNEL_END_ADDR);
}

static void
instrument_memory_operations(void *drcontext, void* tag, instrlist_t *ilist, instr_t *instr, app_pc pc, bool is_write)
{
    opnd_t instr_opnd;
    struct memory_operand_modifier ops = {0};

    memset(&ops, 0, sizeof(struct memory_operand_modifier));

    if(is_write){
    	for_each_dsts_operand(instr, &ops, (opnd_callback_t *) memory_dsts_operand_finder);
    } else {
    	for_each_src_operand(instr, &ops, (opnd_callback_t *) memory_src_operand_finder);
    }

	 switch(ops.found_operand.value.base_disp.base_reg) {
	 	 case DR_REG_RSP: case DR_REG_ESP: case DR_REG_SP:
	 	 case DR_REG_RBP: case DR_REG_EBP: case DR_REG_BP:
	 		 return;
	 	 default:
	 		 break;
	 }

	 if(instr->opcode == OP_rep_stos){
	     instrument_write_rep_stos(drcontext, ilist, instr, pc, &ops, is_write);
	     return;
	 }

	 if(instr->opcode == OP_rep_movs) {
	     instrument_write_rep_movs(drcontext, ilist, instr, pc, &ops, is_write);
	     return;
	 }

	    if(instr->opcode == OP_rep_cmps
	             || instr->opcode == OP_repne_cmps) {
	         instrument_write_rep_cmps(drcontext, ilist, instr, pc, &ops, is_write);
	         return;
	     }

	 if(opnd_is_far_base_disp(ops.found_operand)){
	     if (instr->opcode == OP_dec ||
	             instr->opcode == OP_inc||
	             instr->opcode == OP_cmpxchg ||
	             instr->opcode == OP_btr ||
	             instr->opcode == OP_bts ||
	             instr->opcode == OP_or ||
	             instr->opcode == OP_sub ||
	             instr->opcode == OP_add){
	         if(instr_writes_memory(instr)){
	             instrument_mem_instr(drcontext, ilist, instr, pc, true);
	         } else if(instr_reads_memory(instr)){
	             instrument_mem_instr(drcontext, ilist, instr, pc, false);
	         }
	         return;
	     }
	 }

	 if(instr->opcode == OP_xadd){
	     if(instr_writes_memory(instr)){
	         instrument_mem_instr_xadd(drcontext, ilist, instr, pc, true);
	     } else if(instr_reads_memory(instr)){
	         instrument_mem_instr_xadd(drcontext, ilist, instr, pc, false);
	     }
	 }

	 if (opnd_is_rel_addr(ops.found_operand) || opnd_is_abs_addr(ops.found_operand)) {

	 }else if (opnd_is_base_disp(ops.found_operand)) {
		 if(opnd_is_near_base_disp(ops.found_operand)){
			 if(is_write){
				 instrument_memory_write(drcontext, ilist, instr, pc, &ops);
			 } else {
				 instrument_memory_read(drcontext, ilist, instr, pc, &ops);
			 }
		 }else if(opnd_is_far_base_disp(ops.found_operand)) {

			 if(instr->opcode == OP_rep_stos || instr->opcode == OP_rep_movs){
				 instrument_write_rep_stos(drcontext, ilist, instr, pc, &ops, is_write);
			 } else if (instr->opcode == OP_dec ||
					 instr->opcode == OP_inc||
					 instr->opcode == OP_xadd ||
					 instr->opcode == OP_cmpxchg ||
					 instr->opcode == OP_btr ||
					 instr->opcode == OP_bts ||
					 instr->opcode == OP_and){
				 if(instr_writes_memory(instr)){
					 instrument_mem_instr(drcontext, ilist, instr, pc, true);
				 } else if(instr_reads_memory(instr)){
					 instrument_mem_instr(drcontext, ilist, instr, pc, false);
				 }
			 }
		 }
	 }

	(void)tag;
}

#define CALL_INDIRECT_SIZE 3

dr_emit_flags_t
memleak_bb_event(void *drcontext, void *tag, instrlist_t *bb, bool for_trace, bool translating)
{
    instr_t *instr,*prev_instr, *last_instr, *first_instr;
    app_pc pc;
    instr_t *cursor;
    opnd_t op;
    uint opcode;
    int i;
    struct memory_operand_modifier ops = {0};

    first_instr = instrlist_first(bb);

    for(instr = instrlist_last(bb); instr != NULL; instr = prev_instr)
    {
    	prev_instr = instr_get_prev(instr);
    	pc = instr_get_app_pc(instr);

    	if(pc == NULL)
    		continue;

    	if(!instr_opcode_valid(instr))
    		continue;

    	if(instr_is_cti(instr) && instr_num_srcs(instr)){
    		if(is_kernel_text(pc)){
    		   if(instr_is_call_indirect(instr)) {
    		        //app_pc return_target = (app_pc)((uint64_t)instr->translation + CALL_INDIRECT_SIZE);

    		    } else {
    		        app_pc target = instr->translation;
    		        instr_t *jmp_instr = INSTR_CREATE_jmp(drcontext, opnd_create_pc(target));
    		        instr_set_ok_to_mangle(jmp_instr, false);
    		        PRE(bb, instr, jmp_instr);
    		    }
    		} else {
    		    /*TODO : there is no need to have a callback function at the end of each basic block;
    		     * the only need of this is for initialise the each thread spill slot and that can be
    		     * elsewhere inside dispatch; removing this gives a performance boost up by 2x */
    		    //cfi_call_instrumentation_snapahot(drcontext, bb, instr, mecontext_snapshot_native);
    		}

    		continue;
    	}

    	if(instr_writes_memory(instr)) {
    		instrument_memory_operations(drcontext, tag, bb, instr, pc, true);

    	} else if(instr_reads_memory(instr)) {
    		instrument_memory_operations(drcontext, tag, bb, instr, pc, false);
    	}

    }

    return DR_EMIT_DEFAULT;
}
