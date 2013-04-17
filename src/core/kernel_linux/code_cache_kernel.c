/*
 * code_cache_kernel.c
 *
 *  Created on: 2013-04-14
 *      Author: akshayk
 */

#include "code_cache_kernel.h"
#include "instrlist.h"
#include "arch.h"
#include "instr.h"
#include "instrument.h"
#include "instr_create.h"
#include "decode.h"
#include "decode_fast.h"
#include "disassemble.h"
#include "../hashtable.h"


static generic_table_t  *hash_table_kernel;

static byte *code_cache_kernel_start;
static byte *code_cache_cur_pc;

#define KERNEL_CACHE_SIZE 4*1024

#define INIT_HTABLE_SIZE_KERNEL 128


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

#define PRE     instrlist_meta_preinsert
#define POST    instrlist_meta_postinsert
#define APP     instrlist_append

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

static inline
void for_each_dsts_operand(instr_t *in, void *state, opnd_callback_t *callback) {
    int i = 0, max = in->num_dsts;
    for(; i < max; ++i) {
        callback(in, &(in->dsts[i]), false, state);
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

static inline void
for_each_source_operand(instr_t *in, void *state, opnd_callback_t *callback) {
    struct opnd_callback_t new_state;
    new_state.state = state;
    new_state.callback = callback;
    new_state.is_source_check = true;
    for_each_operand(in, &new_state, (opnd_callback_t*)operand_callback);
}

static inline void
for_each_dest_operand(instr_t *in, void *state, opnd_callback_t *callback) {
    struct opnd_callback_t new_state;
    new_state.state = state;
    new_state.callback = callback;
    new_state.is_source_check = false;
    for_each_operand(in, &new_state, (opnd_callback_t*)operand_callback);
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



static inline void
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



static inline void
memory_operand_replacer(instr_t *in, opnd_t *opnd, bool is_source, struct memory_operand_modifier *mod) {
    if(BASE_DISP_kind == opnd->kind) {
        const int orig_size = opnd_get_size(*opnd);
        *opnd = mod->replacement_operand;
        opnd_set_size(opnd, orig_size);
        instr_set_raw_bits_valid(in, false);
    }

    (void) is_source;
}


static inline void
kill_all_regs(struct register_manager *regs) {
    regs->live = FORCE_LIVE_REGS;
    regs->undead = 0;
}

static inline void
revive_all_regs(struct register_manager *regs) {
    regs->live = ~0;
    regs->undead = 0;
}


static inline bool
reg_is_used(struct register_manager *regs, reg_id_t reg) {
    uint32_t mask;
    reg = reg_to_reg64(reg);
    if(reg) {
        mask = 1UL << reg;
        return !!((regs->live | regs->undead) & mask);
    }
    return false;
}

static inline bool
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
static inline reg_id_t
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

static inline void
find_merge_check_reg(struct register_manager *regs, instr_t* instr)
{
    for_each_operand(instr, regs, (opnd_callback_t*)do_merge_check);
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

static inline void free_reg(unsigned long *bit_array, reg_id_t reg) {
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

/// lower a register to be in the same class (64, 32, 16 bit) as
/// another register
static inline reg_id_t change_reg_class(reg_id_t reg) {
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


static inline reg_id_t change_reg_64bit_class(reg_id_t reg) {
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


void
code_cache_kernel_init(void){
    hash_table_kernel = generic_hash_create(GLOBAL_DCONTEXT,
            INIT_HTABLE_SIZE_KERNEL, 80,
            HASHTABLE_SHARED | HASHTABLE_PERSISTENT,
            NULL
            _IF_DEBUG("code_cache_kernel table"));

    code_cache_kernel_start = heap_alloc(GLOBAL_DCONTEXT, KERNEL_CACHE_SIZE HEAPACCT(ACCT_CLIENT) );
    code_cache_cur_pc = code_cache_kernel_start;
}

static void
instrument_memory_write(void *drcontext, instrlist_t *ilist, instr_t *instr, app_pc pc, struct memory_operand_modifier *ops)
{
    unsigned long used_registers = 0;
    reg_id_t reg_watched_addr;
    reg_id_t reg_unwatched_addr;
    opnd_t opnd_watched_addr;
    opnd_t opnd_unwatched_addr;
    opnd_t watched_addr_opnd;

    instr_t *addr_is_a_watchpoint = INSTR_CREATE_label(drcontext);
    instr_t *addr_is_not_a_watchpoint = INSTR_CREATE_label(drcontext);
    instr_t *begin_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *done_instrumenting = INSTR_CREATE_label(drcontext);

    instr_t *nop = INSTR_CREATE_nop(drcontext);
    instr_t *emulated;

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );

    reg_watched_addr = get_next_free_reg(&used_registers);
    opnd_watched_addr = opnd_create_reg(reg_watched_addr);

    reg_unwatched_addr = get_next_free_reg(&used_registers);
    opnd_unwatched_addr = opnd_create_reg(reg_unwatched_addr);

    watched_addr_opnd = ops->found_operand;

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



static void
instrument_memory_read(void *drcontext, instrlist_t *ilist, instr_t *instr, app_pc pc, struct memory_operand_modifier *ops)
{
    unsigned long used_registers = 0;
    reg_id_t reg_watched_addr;
    reg_id_t reg_unwatched_addr;
    instr_t *addr_is_a_watchpoint = INSTR_CREATE_label(drcontext);
    instr_t *addr_is_not_a_watchpoint = INSTR_CREATE_label(drcontext);
    instr_t *begin_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *done_instrumenting = INSTR_CREATE_label(drcontext);

    instr_t *nop = INSTR_CREATE_nop(drcontext);
    instr_t *emulated;

    opnd_t opnd_watched_addr;
    opnd_t opnd_unwatched_addr;
    opnd_t watched_addr_opnd;

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );

    reg_watched_addr = get_next_free_reg(&used_registers);
    opnd_watched_addr = opnd_create_reg(reg_watched_addr);

    reg_unwatched_addr = get_next_free_reg(&used_registers);
    opnd_unwatched_addr = opnd_create_reg(reg_unwatched_addr);

    watched_addr_opnd = ops->found_operand;

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

void
instrument_mem_instr_xadd(void *drcontext, instrlist_t *ilist,
        instr_t *instr, app_pc pc, bool flag)
{
    unsigned long used_registers = 0;
    reg_id_t instr_reg;
    opnd_t instr_opnd;
    opnd_t opnd_reg;

    instr_t *emulated;
    reg_id_t reg_mask;
    opnd_t opnd_reg_mask;

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

    reg_mask = get_next_free_reg(&used_registers);
    opnd_reg_mask = opnd_create_reg(reg_mask);

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
        if((instr->prefixes & 0xf0) == 0xf0)
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
instrument_memory_operations(void *drcontext, instrlist_t *ilist, instr_t *instr, app_pc pc, bool is_write)
{
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

     if (opnd_is_rel_addr(ops.found_operand) || opnd_is_abs_addr(ops.found_operand)) {

     }else if (opnd_is_base_disp(ops.found_operand)) {
         if(opnd_is_near_base_disp(ops.found_operand)){
             if(instr->opcode == OP_xadd) {
                 if(is_write){
                     instrument_mem_instr_xadd(drcontext, ilist, instr, pc, true);
                 } else {
                     instrument_mem_instr_xadd(drcontext, ilist, instr, pc, false);
                 }

             } else {
                 if(is_write){
                     instrument_memory_write(drcontext, ilist, instr, pc, &ops);
                 } else {
                     instrument_memory_read(drcontext, ilist, instr, pc, &ops);
                 }
             }
         }else if(opnd_is_far_base_disp(ops.found_operand)) {

             if(instr->opcode == OP_rep_stos || instr->opcode == OP_rep_movs){
                 //instrument_write_rep_stos(drcontext, ilist, instr, pc, &ops, is_write);
             } else if (instr->opcode == OP_dec ||
                     instr->opcode == OP_inc||
                     instr->opcode == OP_xadd ||
                     instr->opcode == OP_cmpxchg ||
                     instr->opcode == OP_btr){
                 if(instr_writes_memory(instr)){
                    // instrument_mem_instr(drcontext, ilist, instr, pc, true);
                 } else if(instr_reads_memory(instr)){
                     //instrument_mem_instr(drcontext, ilist, instr, pc, false);
                 }
             }
         }
     }
}


void
basic_block_instrumentation(dcontext_t *drcontext, instrlist_t *ilist){
    instr_t *instr, *next_instr, *first_instr;
    app_pc pc;

    first_instr = instrlist_first(ilist);

    for(instr = instrlist_first(ilist); instr != NULL; instr = next_instr){
        next_instr = instr_get_next(instr);
        pc = instr_get_app_pc(instr);

        if(pc == NULL)
            continue;

        if(!instr_opcode_valid(instr))
            continue;

        if(instr_is_cti(instr)){
            continue;
        }

        if(instr_writes_memory(instr)) {
            instrument_memory_operations(drcontext, ilist, instr, pc, true);

        } else if(instr_reads_memory(instr)) {
            instrument_memory_operations(drcontext, ilist, instr, pc, false);
        }
    }

}

void
process_ubr(dcontext_t *dcontext, instrlist_t *ilist, instr_t *instr){
   // app_pc tgt = (byte *) opnd_get_pc(instr_get_target(instr));
}

byte *
get_target_address(dcontext_t *dcontext, byte *pc)
{
    byte *start_pc, *cur_pc, *instr_start;
    instrlist_t *ilist = instrlist_create(GLOBAL_DCONTEXT);
    instr_t *instr = NULL;
    app_pc tgt;

    build_basic_block_kernel(dcontext, pc, 0, true, true, 0, 0);

    start_pc = pc;
    cur_pc = start_pc;

    do {
        instr = instr_create(GLOBAL_DCONTEXT);
        instr_start = cur_pc;
        cur_pc = decode(GLOBAL_DCONTEXT, cur_pc, instr);
        instr_set_translation(instr, instr_start);
        instrlist_append(ilist, instr);

    }while(!instr_is_cti(instr));

    if (instr_is_cti(instr)) {
        tgt = (app_pc)instr->translation;
        //instr->translation = 0; // hack!
        instr_being_modified(instr, false);
        instr_set_ok_to_mangle(instr, false);
        process_ubr(dcontext, ilist, instr);
    }

    instrlist_remove(ilist, instr);
    APP(ilist, INSTR_CREATE_jmp(GLOBAL_DCONTEXT, opnd_create_pc(tgt)));

    basic_block_instrumentation(GLOBAL_DCONTEXT, ilist);

    code_cache_kernel_start = code_cache_cur_pc;
    code_cache_cur_pc = instrlist_encode(GLOBAL_DCONTEXT, ilist, code_cache_kernel_start, true);

    return code_cache_kernel_start;
}


