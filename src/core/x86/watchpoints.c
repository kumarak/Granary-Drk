/*
 * watchpoints.c
 *
 *  Created on: 2013-05-15
 *      Author: akshayk
 */


#include "../globals.h"
#include "instr.h"
#include "instr_create.h"
#include "decode.h"
#include "decode_fast.h"
#include "instrument.h"
#include "watchpoints.h"

#define PRE     instrlist_meta_preinsert
#define POST    instrlist_meta_postinsert
#define APP     instrlist_append


enum {
    WATCHPOINT_INDEX_MASK   = 0xffff800000000000ULL,
    WATCHPOINT_BASE         = 0x0000880000000000ULL,
    SHADOW_START_ADDR       = 0xffffffffe0000000ULL,
    SHADOW_END_ADDR         = 0xffffffffff000000ULL,
    WATCHPOINT_ADDRESS_MASK = 0x8000800000000000ULL,
    WATCHPOINT              = 0x0000800000000000ULL,
    SHIFT_BIT_COUNT         = 0x30
};

typedef void (opnd_callback_t)(instr_t *, opnd_t *, bool is_source,  void *state);


struct memory_operand_modifier {
    bool has_memory_operand;
    bool has_source_memory_operand;
    bool has_dest_memory_operand;
    bool has_src_seg;
    bool has_dsts_seg;
    uint32_t src_size;
    uint32_t dsts_size;
    opnd_t found_operand;
    opnd_t replacement_operand;
};


static inline reg_id_t reg_to_reg64(reg_id_t reg) {
    if(reg < DR_REG_SPL) {
        while(reg >= DR_REG_EAX) {
            reg -= (DR_REG_EAX - 1);
        }
        return reg;
    }
    return DR_REG_NULL;
}


static inline void
memory_src_operand_finder(instr_t *in, opnd_t *opnd, bool is_source, struct memory_operand_modifier *mod) {
    if(BASE_DISP_kind == opnd->kind){
        if(opnd->value.base_disp.base_reg && !reg_to_reg64(opnd->value.base_disp.base_reg)) {
            return;
        }
        if(opnd->value.base_disp.index_reg && !reg_to_reg64(opnd->value.base_disp.index_reg)) {
            return;
        }
        mod->has_source_memory_operand = true;
        mod->has_memory_operand = true;
        mod->found_operand = *opnd;
    }
    if(!opnd->seg.segment) {

        mod->has_src_seg = 1;
    }

    mod->src_size = opnd->size;
    (void) in;
}

static inline void
memory_dsts_operand_finder(instr_t *in, opnd_t *opnd, bool is_source, struct memory_operand_modifier *mod) {
    if(BASE_DISP_kind == opnd->kind){
        if(opnd->value.base_disp.base_reg && !reg_to_reg64(opnd->value.base_disp.base_reg)) {
            return;
        }
        if(opnd->value.base_disp.index_reg && !reg_to_reg64(opnd->value.base_disp.index_reg)) {
            return;
        }
        mod->has_dest_memory_operand = true;
        mod->has_memory_operand = true;
        mod->found_operand = *opnd;
    }
    if(!opnd->seg.segment) {
        mod->has_dsts_seg = 1;
    }

    mod->dsts_size = opnd->size;
    (void) in;
}

static void
memory_operand_replacer(instr_t *in, opnd_t *opnd, bool is_source, struct memory_operand_modifier *mod) {
    if(BASE_DISP_kind == opnd->kind) {
        const int orig_size = opnd_get_size(*opnd);
        *opnd = mod->replacement_operand;
        opnd_set_size(opnd, orig_size);
        instr_set_raw_bits_valid(in, false);
    }

    (void) is_source;
}


static
void for_each_operand(instr_t *in, void *state, opnd_callback_t *callback) {
    int i = 0, max = in->num_dsts;
    for(; i < max; ++i) {
        callback(in, &(in->dsts[i]), false, state);
    }

    if(in->num_srcs) {
        callback(in, &(in->src0), true, state);
        for(i = 0, max = in->num_srcs - 1; i < max; ++i) {
            callback(in, &(in->srcs[i]), true, state);
        }
    }
}

static inline
void for_each_src_operand(instr_t *in, void *state, opnd_callback_t *callback) {
    int i = 0, max = in->num_srcs - 1;
    if(in->num_srcs) {
        callback(in, &(in->src0), true, state);
        for(i = 0; i < max; ++i) {
            callback(in, &(in->srcs[i]), true, state);
        }
    }
}

static inline void collect_reg(unsigned long *regs, reg_id_t reg) {
    // map the registers onto the 64-bit registers
    if(reg < DR_REG_SPL) {
        while(reg >= DR_REG_EAX) {
            reg -= (DR_REG_EAX - 1);
        }
        *regs |= (1 << reg);
    }
}

static inline void collect_regs(
        unsigned long *regs,
        instr_t *instr,
        int (*num_ops)(instr_t *),
        opnd_t (*get_op)(instr_t *, uint)
) {
    int i;
    opnd_t opnd;

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

static inline reg_id_t get_next_free_reg(unsigned long *bit_array)
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

void
watchpoint_indirect_call_event(dcontext_t *drcontext, instrlist_t *ilist, instr_t *instr,
                     instr_t *next_instr, bool mangle_calls, uint flags)
{
    opnd_t instr_opnd;
    reg_id_t base_reg;
    unsigned long used_registers = 0;
    app_pc pc;
    struct memory_operand_modifier ops = {0};

    instr_t *begin_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *done_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *nop = INSTR_CREATE_nop(drcontext);
    instr_t *emulated;


    memset(&ops, 0, sizeof(struct memory_operand_modifier));

    if(instr_reads_memory(instr)) {
        instr_opnd = instr_get_src(instr, 0);
        if (opnd_is_rel_addr(instr_opnd) || opnd_is_abs_addr(instr_opnd)) {

        }else if (opnd_is_base_disp(instr_opnd)) {

            for_each_src_operand(instr, &ops, (opnd_callback_t *) memory_src_operand_finder);
           // base_reg = opnd_get_reg(instr_opnd);

            switch(ops.found_operand.value.base_disp.base_reg) {
                case DR_REG_RSP: case DR_REG_ESP: case DR_REG_SP:
                case DR_REG_RBP: case DR_REG_EBP: case DR_REG_BP:
                    return;
                default:
                  break;
            }

            collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
            collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );

            reg_id_t reg_watched_addr = get_next_free_reg(&used_registers);
            opnd_t opnd_watched_addr = opnd_create_reg(reg_watched_addr);

            reg_id_t reg_unwatched_addr = get_next_free_reg(&used_registers);
            opnd_t opnd_unwatched_addr = opnd_create_reg(reg_unwatched_addr);

            PRE(ilist, instr, begin_instrumenting);
            PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_watched_addr));
            PRE(ilist, instr, INSTR_CREATE_push(drcontext, opnd_unwatched_addr));
            PRE(ilist, instr, INSTR_CREATE_pushf(drcontext));
            PRE(ilist, instr, INSTR_CREATE_lea(drcontext, opnd_watched_addr, opnd_create_base_disp(opnd_get_base(ops.found_operand),
                                                        opnd_get_index(ops.found_operand), opnd_get_scale(ops.found_operand),
                                                        opnd_get_disp(ops.found_operand), OPSZ_lea)));

            PRE(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_unwatched_addr,
                                            OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));
            PRE(ilist, instr, INSTR_CREATE_or(drcontext, opnd_unwatched_addr, opnd_watched_addr));

            emulated = instr_clone(drcontext, instr);
            emulated->translation = 0;

            ops.replacement_operand = opnd_create_base_disp(
                    reg_unwatched_addr, DR_REG_NULL,1, 0 , ops.found_operand.size);

            for_each_operand(emulated, &ops, (opnd_callback_t *) memory_operand_replacer);

            PRE(ilist, instr, INSTR_CREATE_popf(drcontext));
            PRE(ilist, instr, emulated);
            PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_unwatched_addr));
            PRE(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_watched_addr));

            PRE(ilist, instr, INSTR_CREATE_jmp_short(drcontext,
                    opnd_create_instr(done_instrumenting)));

            pc = instr->translation;
            instr->translation = 0; // hack!
            instr_being_modified(instr, false);
            instr_set_ok_to_mangle(instr, false);

            if(NULL != pc){
                nop->translation = pc + instr->length;
            }
            POST(ilist, instr, nop);
            POST(ilist, instr, done_instrumenting);

        }
    }
}
