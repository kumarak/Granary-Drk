/*
 * cfi_instrumentation.h
 *
 *  Created on: 2013-02-01
 *      Author: akshayk
 */

#ifndef CFI_INSTRUMENTATION_H_
#define CFI_INSTRUMENTATION_H_

#include "cfi_defines.h"
#include "cfi_module.h"


#define MAX_INSTR_REGISTER 8

#define SHADOW_OFFSET 0x400000000000

#define TESTALL(mask, var) (((mask) & (var)) == (mask))
#define TESTANY(mask, var) (((mask) & (var)) != 0)

#define INVALID_MEM_ADDR -1
#define REG_SPILL_START DR_REG_XAX
#define REG_SPILL_STOP DR_REG_R15

#define USE_NON_CANNONICAL_ADDR

#ifdef USE_NON_CANNONICAL_ADDR
#define KERNEL_ADDRESS_OFFSET       0xffff000000000000
#define KERNEL_MEMORY_START         0xffff880000000000
#define KERNEL_MEMORY_HOLE_START    0xffffc80000000000
#define KERNEL_MEMORY_HOLE_END      0xffffc8ffffffffff
#define USER_ADDRESS_OFFSET         0x00007fffffffffff
#else
#define KERNEL_MEMORY_HOLE_START    0xffffc80000000000
#define KERNEL_MEMORY_HOLE_END      0xffffc8ffffffffff
#define ADDRESS_OFFSET              0x0000800000000000
#define KERNEL_MEMORY_START_ADDR    0xffff890000000000
#endif


enum {
    WATCHPOINT_INDEX_MASK   = 0xffff800000000000ULL,
    SHADOW_START_ADDR       = 0xffffffffe0000000ULL,
    SHADOW_END_ADDR         = 0xffffffffff000000ULL,
    SHIFT_BIT_COUNT         = 0x30
};

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



struct register_manager {
    uint32_t live;
    uint32_t undead;
} __attribute__((packed));


struct watchpoint_state {

    // getting zombie registers
    struct register_manager *regs;
    struct register_manager *spill_regs;

    // for tracking memory operands
    struct memory_operand_modifier *ops;

    // are the flags dead?
    bool flags_are_dead;

    // policy information
    bool watch_read;
    bool watch_write;
};


struct spill_reg_t {
    reg_id_t reg;
    bool was_spilled;
};

static uint32_t FORCE_LIVE_REGS = (0U
        |   (1U << DR_REG_NULL)
        |   (1U << DR_REG_RSP)
        |   (1U << DR_REG_RBP)
);



/// apply a callback function to all operands of an instruction. This will apply the
/// functions to destination operands first.
typedef void (opnd_callback_t)(instr_t *, opnd_t *, bool is_source,  void *state);

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

static
void for_each_dsts_operand(instr_t *in, void *state, opnd_callback_t *callback) {
    int i = 0, max = in->num_dsts;
    for(; i < max; ++i) {
        callback(in, &(in->dsts[i]), false, state);
    }
}

static
void for_each_src_operand(instr_t *in, void *state, opnd_callback_t *callback) {
    int i = 0, max = in->num_srcs - 1;
    if(in->num_srcs) {
        callback(in, &(in->src0), true, state);
        for(i = 0; i < max; ++i) {
            callback(in, &(in->srcs[i]), true, state);
        }
    }
}

struct opnd_callback_t {
    void *state;
    opnd_callback_t *callback;
    bool is_source_check;
};

static void
operand_callback(instr_t *in, opnd_t *opnd, bool is_source, struct opnd_callback_t *cb) {
    if(is_source == cb->is_source_check) {
        cb->callback(in, opnd, is_source, cb->state);
    }
}

static void
for_each_source_operand(instr_t *in, void *state, opnd_callback_t *callback) {
    struct opnd_callback_t new_state;
    new_state.state = state;
    new_state.callback = callback;
    new_state.is_source_check = true;
    for_each_operand(in, &new_state, operand_callback);
}

static void
for_each_dest_operand(instr_t *in, void *state, opnd_callback_t *callback) {
    struct opnd_callback_t new_state;
    new_state.state = state;
    new_state.callback = callback;
    new_state.is_source_check = false;
    for_each_operand(in, &new_state, operand_callback);
}

typedef void (reg_callback_t)(opnd_t *, reg_id_t *, void *state);


static void
for_each_reg(opnd_t *op, void *state, reg_callback_t *callback) {
    reg_id_t local_copy;
    switch(op->kind) {
    case REG_kind:
        callback(op, &(op->value.reg), state);
        break;
    case BASE_DISP_kind:
        local_copy = op->value.base_disp.base_reg;
        callback(op, &local_copy, state);
        op->value.base_disp.base_reg = local_copy;

        local_copy = op->value.base_disp.index_reg;
        callback(op, &local_copy, state);
        op->value.base_disp.index_reg = local_copy;
        break;
    default:
        break;
    }
}

static inline reg_id_t reg_to_reg64(reg_id_t reg) {
    if(reg < DR_REG_SPL) {
        while(reg >= DR_REG_EAX) {
            reg -= (DR_REG_EAX - 1);
        }
        return reg;
    }
    return DR_REG_NULL;
}



static void
memory_operand_finder(instr_t *in, opnd_t *opnd, bool is_source, struct memory_operand_modifier *mod) {
    if(!mod->has_memory_operand && BASE_DISP_kind == opnd->kind && !opnd->seg.segment) {
        if(opnd->value.base_disp.base_reg && !reg_to_reg64(opnd->value.base_disp.base_reg)) {
            return;
        }
        if(opnd->value.base_disp.index_reg && !reg_to_reg64(opnd->value.base_disp.index_reg)) {
            return;
        }

        if(is_source) {
            mod->has_source_memory_operand = true;
        } else {
            mod->has_dest_memory_operand = true;
        }
        mod->has_memory_operand = true;
        mod->found_operand = *opnd;
    }

    (void) in;
}

static void
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

static void
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


static void
kill_all_regs(struct register_manager *regs) {
    regs->live = FORCE_LIVE_REGS;
    regs->undead = 0;
}

static void
revive_all_regs(struct register_manager *regs) {
    regs->live = ~0;
    regs->undead = 0;
}


static bool
reg_is_used(struct register_manager *regs, reg_id_t reg) {
    uint32_t mask;
    reg = reg_to_reg64(reg);
    if(reg) {
        mask = 1UL << reg;
        return !!((regs->live | regs->undead) & mask);
    }
    return false;
}

static bool
reg_is_live(struct register_manager *regs, reg_id_t reg) {
    uint32_t mask;
    reg = reg_to_reg64(reg);
    if(reg) {
        mask = 1UL << reg;
        return !!(regs->live & mask);
    }
    return false;
}

static bool
reg_is_dead(struct register_manager *regs, reg_id_t reg) {
    uint32_t mask;
    reg = reg_to_reg64(reg);
    if(reg) {
        mask = 1UL << reg;
        return !!(~regs->live & mask);
    }
    return false;
}

static void
revive_reg(struct register_manager *regs, reg_id_t reg);

static void
kill_reg(struct register_manager *regs, reg_id_t reg_) {
    reg_id_t reg = reg_to_reg64(reg_);
    if(reg) {
        if(reg == reg_) {
            uint32_t mask = 1UL << reg;
            regs->undead &= ~mask;
            regs->live &= ~mask;
            regs->live |= FORCE_LIVE_REGS;

        } else if(!reg_is_dead(regs, reg)) {
            revive_reg(regs, reg);
        }
    }
}

static void
revive_reg(struct register_manager *regs, reg_id_t reg) {
    reg = reg_to_reg64(reg);
    if(reg) {
        uint32_t mask = 1UL << reg;
        regs->undead &= ~mask;
        regs->live |= mask;
    }
}

static void kill_opnd_reg(opnd_t *op, reg_id_t *reg, struct register_manager *regs) {
    kill_reg(regs, *reg);
}

static void revive_opnd_reg(opnd_t *op, reg_id_t *reg, struct register_manager *regs) {
    revive_reg(regs, *reg);
}

static void kill_opnd_regs(instr_t *in, opnd_t *op, bool is_source, struct register_manager *regs) {
    for_each_reg(op, regs, (reg_callback_t *) kill_opnd_reg);
}


static void revive_opnd_regs(instr_t *in, opnd_t *op, bool is_source, struct register_manager *regs) {
    for_each_reg(op, regs, (reg_callback_t *) revive_opnd_reg);
}

static void find_dead_reg(instr_t *in, opnd_t *op, bool is_source, struct register_manager *regs) {
    if(is_source) {
        for_each_reg(op, regs, (reg_callback_t *) revive_opnd_reg);
    } else if(REG_kind == op->kind){
        for_each_reg(op, regs, (reg_callback_t *) kill_opnd_reg);
    } else {
        for_each_reg(op, regs, (reg_callback_t *) revive_opnd_reg);
    }
}

static inline void kill_used_regs_in_instr(struct register_manager *regs, instr_t *in) {
    for_each_operand(in, regs, (opnd_callback_t *) kill_opnd_regs);
}

static inline void revive_used_regs_in_instr(struct register_manager *regs, instr_t *in) {
    for_each_operand(in, regs, (opnd_callback_t *) revive_opnd_regs);
}

static inline void find_dead_regs(struct register_manager *regs, instr_t *in) {
    for_each_operand(in, regs, (opnd_callback_t *) find_dead_reg);
    regs->undead = 0;
}

/// Returns the next 64-bit "free" dead register.
static reg_id_t
get_zombie(struct register_manager *regs) {
    uint64_t zombies = (regs->live | regs->undead);
    unsigned pos = 1; // ignore DR_REG_NULL
    for(; pos < DR_REG_EAX; ++pos) {
        uint32_t mask = (1 << pos);
        if(!(mask & zombies)) {
            regs->undead |= mask;
            return (reg_id_t) pos;
        }
    }
    return DR_REG_NULL;
}


/// Returns the next "free" dead register that is at the same scale as
/// another register/operand.
static reg_id_t
get_scaled_zombie(struct register_manager *regs, reg_id_t scale) {
    reg_id_t zombie = get_zombie(regs);

    if(DR_REG_RAX <= scale && scale <= DR_REG_R15) {
        return zombie;
    }

    if(DR_REG_EAX <= scale && scale <= DR_REG_R15D) {
        return zombie + (DR_REG_EAX - 1);
    }

    if(DR_REG_AX <= scale && scale <= DR_REG_R15W) {
        return zombie + (DR_REG_AX - 1);
    }

    if(DR_REG_AL <= scale && scale <= DR_REG_R15L) {
        return zombie + (DR_REG_AL - 1);
    }

    return zombie;
}


static void
do_merge_check(instr_t* in, opnd_t* op, bool is_source, struct register_manager *regs)
{
    if(!is_source && (REG_kind == op->kind)){
        revive_reg(regs, op->value.reg);
    }
    else if(BASE_DISP_kind == op->kind){
        if(reg_is_used(regs, op->value.base_disp.base_reg)){
            kill_reg(regs, op->value.base_disp.base_reg);
        }
    }
}

static void
find_merge_check_reg(struct register_manager *regs, instr_t* instr)
{
    for_each_operand(instr, regs, (opnd_callback_t*)do_merge_check);
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


static bool ref_is_stack_mem(opnd_t opnd)
{
    if(!opnd_is_base_disp(opnd))
        return false;

    if(opnd_get_base(opnd) == DR_REG_RSP)
        return true;

    return false;
}



static bool
instr_writes_to_any_aflags(instr_t *instr)
{
    uint aflags;

    aflags = instr_get_arith_flags(instr);
    if (TESTANY(EFLAGS_WRITE_6, aflags))
        return true;

    return false;
}




dr_emit_flags_t
memleak_bb_event(void *drcontext, void *tag, instrlist_t *bb, bool for_trace, bool translating);

dr_emit_flags_t
buffer_overflow_bb_event(void *drcontext, void *tag, instrlist_t *bb, bool for_trace, bool translating);

#endif /* CFI_INSTRUMENTATION_H_ */
