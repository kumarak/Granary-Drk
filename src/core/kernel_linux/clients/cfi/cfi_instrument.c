/*
 * cfi_instrument.c
 *
 *  Created on: 2012-04-08
 *      Author: akshayk
 */


#include <stddef.h>

#define CC(...)

#include "cfi_defines.h"
#include <linux/slab.h>
#include "cfi_module.h"
#include "cfi_wrapper.h"
#include "cfi_address_logger.h"
#include "cfi_debug_log.h"
#include "cfi_memory_leak.h"
#include "cfi_insert_call.h"
#include "cfi_instrumentation.h"
#include "cfi_hotpatch.h"
#include <linux/stop_machine.h>
#include "kernel_linux/clients/dcontext_extend.h"
#include <linux/fs.h>

#if defined(CFI_SEQUENTIALIZE_MODULE) && CFI_SEQUENTIALIZE_MODULE
#   include "cfi_sequence.h"
#endif

#define GRANARY_MEM_INSTRUMENTATION

extern struct task_struct *sweep_task;



struct alias_meta {

    uint64_t base_address;
    uint64_t limit;

} __attribute__((packed));


struct hlist_head per_thread_metainfo[GC_TABLE_SIZE];

//struct cfi_mcontext_t thread_mcontext;

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
extern int cfi_is_granary_code(void *);

void cfi_hotpatch_kernel(void *drcontext);


extern uint64_t cfi_watch_write8(void *, uint8_t);
//extern uint64_t cfi_watch_write16(void *, uint16_t);
//extern uint64_t cfi_watch_write32(void *, uint32_t);
//extern uint64_t cfi_watch_write64(void *, uint64_t);

//extern uint64_t cfi_watch_read(void *);
//extern uint64_t cfi_watch_read16(void *);
//extern uint64_t cfi_watch_read32(void *);
//extern uint64_t cfi_watch_read64(void *);

//extern uint64_t cfi_unalias_addr(void *);

void drinit_dcontext(unsigned int thread_id) {
    dr_init_client_extension(cfi_init_dcontext, DR_EXTENSION(cfi));
    dr_register_kernel_wrapper(cfi_get_kernel_wrapper);
    dr_register_direct_call_exit((void*)cfi_exit_direct_call);
    dr_register_address_untracker(cfi_get_untracked_address);
    dr_register_address_return_exit(cfi_exit_return_to_kernel);
    dr_register_return_path_address(cfi_return_to_module_from_kernel);
    dr_register_is_granary_code(cfi_is_granary_code);
    dr_register_get_symbol_name(cfi_print_symbol_name);
    dr_register_hotpatch_callback(cfi_hotpatch_kernel);
    //dr_register_exit_module_context(cfi_seq_release_module);
}
#if 0
/* ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * Access / Modify operands.
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 */

/// apply a callback function to all operands of an instruction. This will apply the
/// functions to destination operands first.
typedef void (opnd_callback_t)(instr_t *, opnd_t *, bool is_source,  void *state);
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

struct opnd_callback_t {
    void *state;
    opnd_callback_t *callback;
    bool is_source_check;
};

void operand_callback(instr_t *in, opnd_t *opnd, bool is_source, struct opnd_callback_t *cb) {
    if(is_source == cb->is_source_check) {
        cb->callback(in, opnd, is_source, cb->state);
    }
}

void for_each_source_operand(instr_t *in, void *state, opnd_callback_t *callback) {
    struct opnd_callback_t new_state;
    new_state.state = state;
    new_state.callback = callback;
    new_state.is_source_check = true;
    for_each_operand(in, &new_state, operand_callback);
}

void for_each_dest_operand(instr_t *in, void *state, opnd_callback_t *callback) {
    struct opnd_callback_t new_state;
    new_state.state = state;
    new_state.callback = callback;
    new_state.is_source_check = false;
    for_each_operand(in, &new_state, operand_callback);
}

typedef void (reg_callback_t)(opnd_t *, reg_id_t *, void *state);
void for_each_reg(opnd_t *op, void *state, reg_callback_t *callback) {
    reg_id_t local_copy;
    switch(op->kind) {
    case REG_kind:
        local_copy = op->value.reg;
        callback(op, &local_copy, state);
        op->value.reg = local_copy;
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

/* ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * Updating memory operands in place; used in the implementation of watchpoints.
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 */

struct memory_operand_modifier {
    bool has_memory_operand;
    bool has_source_memory_operand;
    bool has_dest_memory_operand;
    opnd_t found_operand;
    opnd_t replacement_operand;
};

void memory_operand_finder(instr_t *in, opnd_t *opnd, bool is_source, struct memory_operand_modifier *mod) {
    if(!mod->has_memory_operand && BASE_DISP_kind == opnd->kind) {
        if(DR_REG_NULL == reg_to_reg64(opnd->value.base_disp.base_reg)) {
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

void memory_operand_replacer(instr_t *in, opnd_t *opnd, bool is_source, struct memory_operand_modifier *mod) {
    if(BASE_DISP_kind == opnd->kind) {
        const int orig_size = opnd_get_size(*opnd);
        *opnd = mod->replacement_operand;
        opnd_set_size(opnd, orig_size);
        instr_set_raw_bits_valid(in, false);
    }

    (void) is_source;
}


/* ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * Track live/dead registers.
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 */

struct register_manager {
    uint32_t live;
    uint32_t undead;
} __attribute__((packed));

static uint32_t FORCE_LIVE_REGS = (0U
        |   (1U << DR_REG_NULL)
        |   (1U << DR_REG_RSP)
        |   (1U << DR_REG_RBP)
);

void kill_all_regs(struct register_manager *regs) {
    regs->live = FORCE_LIVE_REGS;
    regs->undead = 0;
}

void revive_all_regs(struct register_manager *regs) {
    regs->live = ~0;
    regs->undead = 0;
}


bool reg_is_used(struct register_manager *regs, reg_id_t reg) {
    uint32_t mask;
    if(reg < DR_REG_SPL) {
        reg = reg_to_reg64(reg);
        mask = 1UL << reg;
        return !!((regs->live | regs->undead) & mask);
    }
    return false;
}

bool reg_is_live(struct register_manager *regs, reg_id_t reg) {
    uint32_t mask;
    if(reg < DR_REG_SPL) {
        reg = reg_to_reg64(reg);
        mask = 1UL << reg;
        return !!(regs->live & mask);
    }
    return false;
}

bool reg_is_dead(struct register_manager *regs, reg_id_t reg) {
    uint32_t mask;
    if(reg < DR_REG_SPL) {
        reg = reg_to_reg64(reg);
        mask = 1UL << reg;
        return !!(~regs->live & mask);
    }
    return false;
}

void kill_reg(struct register_manager *regs, reg_id_t reg) {
    uint32_t mask;
    if(reg < DR_REG_SPL) {
        reg = reg_to_reg64(reg);
        mask = 1UL << reg;
        if(regs->undead & mask) {
            regs->undead &= ~mask;
        }

        regs->live &= ~mask;
        regs->live |= FORCE_LIVE_REGS;
    }
}

void revive_reg(struct register_manager *regs, reg_id_t reg) {
    uint32_t mask;
    if(reg < DR_REG_SPL) {
        reg = reg_to_reg64(reg);
        mask = 1UL << reg;
        if(regs->undead & mask) {
            regs->undead &= ~mask;
        }

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
    } else if(BASE_DISP_kind == op->kind) {
        for_each_reg(op, regs, (reg_callback_t *) revive_opnd_reg);
    } else {
        for_each_reg(op, regs, (reg_callback_t *) kill_opnd_reg);
    }
}

inline void kill_used_regs_in_instr(struct register_manager *regs, instr_t *in) {
    for_each_operand(in, regs, (opnd_callback_t *) kill_opnd_regs);
}

inline void revive_used_regs_in_instr(struct register_manager *regs, instr_t *in) {
    for_each_operand(in, regs, (opnd_callback_t *) revive_opnd_regs);
}

inline void find_dead_regs(struct register_manager *regs, instr_t *in) {
    for_each_operand(in, regs, (opnd_callback_t *) find_dead_reg);
    regs->undead = 0;
}

/// Returns the next 64-bit "free" dead register.
reg_id_t get_zombie(struct register_manager *regs) {
    uint64_t zombies = (regs->live | regs->undead);
    unsigned pos = 0;
    for(; pos < 32; ++pos) {
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
reg_id_t get_scaled_zombie(struct register_manager *regs, reg_id_t scale) {
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

//typedef void (opnd_callback_t)(instr_t *, opnd_t *, bool is_source,  void *state)

void
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

/* ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * Instrument.
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 */

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

static void add_watchpoint_light(void *drcontext,
        instrlist_t *bb,
        instr_t *instr,
        app_pc pc,
        struct watchpoint_state *state);


static void add_watchpoint_heavy(void *drcontext,
        instrlist_t *bb,
        instr_t *instr,
        app_pc pc,
        struct watchpoint_state *state);

static dr_emit_flags_t
bb_event(void *drcontext, void *tag, instrlist_t *bb, bool for_trace, bool translating)
{
    instr_t *instr, *prev_instr;
    opnd_t op;
    uint opcode;
    int i;
    int instrumented = 0;
    app_pc first_instr = NULL;

    struct memory_operand_modifier ops = {0};
    struct register_manager regs = {0};
    struct register_manager spill_regs = {0};
    struct register_manager rewatch_tracker = {0};
    struct watchpoint_state state = {0};
    state.watch_read = true;
    state.watch_write = true;
    state.ops = &ops;
    state.regs = &regs;
    state.spill_regs = &spill_regs;
    revive_all_regs(&regs);
    revive_all_regs(&rewatch_tracker);

    bool prev_instr_modifies_flags = false;

    for(instr = instrlist_last(bb); instr != NULL; instr = prev_instr) {
        app_pc pc = instr_get_app_pc(instr);
        bool lea_dest_was_live = false;
        prev_instr = instr_get_prev(instr);

        // update flag information for this and next instruction processed.
        state.flags_are_dead = prev_instr_modifies_flags;
        if(instr_get_opcode_eflags(instr->opcode)) {
            prev_instr_modifies_flags = true;
        }

        // update the dead regs
        find_dead_regs(&regs, instr);

        // don't want to instrument non-native code.
        if(!pc) {
            continue;
        }

        if(OP_lea == instr->opcode) {
            reg_id_t dest_reg = instr->dsts[0].value.reg;
            lea_dest_was_live = reg_is_live(&rewatch_tracker, dest_reg);
        }

        // update the rewatch tracker
        find_merge_check_reg(&rewatch_tracker, instr);

        // lock prefix
        if(instr_get_prefixes(instr) & 0xf0 == 0xf0) {
            get_zombie(&rewatch_tracker);
            continue;
        }

        // ignore certain instructions (e.g. that modify the stack)
        switch(instr->opcode) {
        case OP_pushf:  case OP_popf:
        case OP_push:   case OP_pop:
        case OP_call:   case OP_call_far:
        case OP_ret:    case OP_ret_far:
            get_zombie(&rewatch_tracker);
            continue;
        default:
            if(instr_is_sse_or_sse2(instr)) {
                get_zombie(&rewatch_tracker);
                continue;
            }
            break;
        }

        // go find our memory operands, if any
        memset(&ops, 0, sizeof ops);
        for_each_operand(instr, &ops, (opnd_callback_t *) memory_operand_finder);

        // no memory operands, so nothing to watch.
        if(!ops.has_memory_operand) {
            get_zombie(&rewatch_tracker);
            continue;
        }

        if(OP_lea == instr->opcode) {
            get_zombie(&rewatch_tracker);
            if(lea_dest_was_live) {
                reg_id_t dest_reg = instr->dsts[0].value.reg;
                revive_reg(&rewatch_tracker, dest_reg);
            }
            continue;
        }

        // policy based checks
        if(ops.has_source_memory_operand && !state.watch_read) {
            get_zombie(&rewatch_tracker);
            continue;
        }

        if(ops.has_dest_memory_operand && !state.watch_write) {
            get_zombie(&rewatch_tracker);
            continue;
        }

        // this is a likely local variable; don't instrument
        switch(ops.found_operand.value.base_disp.base_reg) {
        case DR_REG_RSP: case DR_REG_ESP: case DR_REG_SP:
        case DR_REG_RBP: case DR_REG_EBP: case DR_REG_BP:
            get_zombie(&rewatch_tracker);
            continue;
        default:
            break;
        }

        // convenient iff we need to spill registers later on
        kill_all_regs(&spill_regs);
        revive_used_regs_in_instr(&spill_regs, instr);

        // add watchpoint instrumentation.
        if(instr_writes_memory(instr) || instr_reads_memory(instr)) {
            if (opnd_is_rel_addr(state.ops->found_operand) || opnd_is_abs_addr(state.ops->found_operand)) {

            }else if (opnd_is_base_disp(state.ops->found_operand)) {
                add_watchpoint_heavy(drcontext, bb, instr, pc, &state);
            }
        }
        // } else {
        //    add_watchpoint_light(drcontext, bb, instr, pc, &state);
        //}

    }

    return DR_EMIT_DEFAULT;
}


/* ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * Add in instrumentation for a watchpoint.
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 */

noinline void break_fault()
{

}

#define ADDI(...) { \
        instr_t *next_cursor = (__VA_ARGS__); \
        instrlist_meta_postinsert(bb, cursor, next_cursor); \
        if(next_cursor != instr_get_next(cursor)) break_fault(); \
        cursor = instr_get_next(cursor); }

#define PRE(...) instrlist_meta_preinsert(bb, cursor, (__VA_ARGS__))
#define POST(...) instrlist_meta_postinsert(bb, cursor, (__VA_ARGS__))

struct spill_reg_t {
    reg_id_t reg;
    bool was_spilled;
};

/// Get a register. This will either find a dead register, or if none exist,
/// spill a register, and then allow us to use the spilled register.
static instr_t *save_register(
        void *drcontext,
        instrlist_t *bb,
        instr_t *cursor,
        struct watchpoint_state *state,
        struct spill_reg_t *r
) {
    //  r->reg = get_zombie(state->regs);
    //  r->was_spilled = false;

    //  if(DR_REG_NULL == r->reg) {
    //      r->reg = get_zombie(state->spill_regs);
    //     r->was_spilled = true;
    ADDI(INSTR_CREATE_push(drcontext, opnd_create_reg(r->reg)));
    // }
    return cursor;
}


/// Restore a previously used register. If the register was dead then no
/// restoration is needed; otherwise we must restore it from the stack.
static instr_t *restore_register(
        void *drcontext,
        instrlist_t *bb,
        instr_t *cursor,
        struct spill_reg_t *r
) {
    //if(r->was_spilled) {
    ADDI(INSTR_CREATE_pop(drcontext, opnd_create_reg(r->reg)));
    //  }
    // return cursor;
}

enum {
    WATCHPOINT_INDEX_MASK   = 0xffff000000000000ULL
};


#define INSTR_RAW_BITS_VALID    0x00080000
#define INSTR_RAW_BITS_ALLOCATED    0x00100000


// heavy instrumentation for an instruction
// check for a watch-point address
//          save registers
//          check for watch-point address
//          add a clean call
//          emulate the original instruction
//          restore registers
static void add_watchpoint_heavy(
        void *drcontext,
        instrlist_t *bb,
        instr_t *instr,
        app_pc pc,
        struct watchpoint_state *state
) {
    bool spilled_unwatched_addr = false;
    struct spill_reg_t watched_addr;
    struct spill_reg_t unwatched_addr;

    instr_t *addr_is_a_watchpoint = INSTR_CREATE_label(drcontext);
    instr_t *addr_is_not_a_watchpoint = INSTR_CREATE_label(drcontext);
    instr_t *begin_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *done_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *nop = INSTR_CREATE_nop(drcontext);
    instr_t *emulated;
    instr_t *cursor = instr;
    instr_t *prev_instr;

    PRE(begin_instrumenting);

    prev_instr = instr_get_prev(begin_instrumenting);
    cursor = begin_instrumenting;

    if(!state->flags_are_dead) {
        ADDI(INSTR_CREATE_pushf(drcontext));
    }

    cursor = save_register(drcontext, bb, cursor, state, &watched_addr);
    cursor = save_register(drcontext, bb, cursor, state, &unwatched_addr);

    // calculate and store the address that is about to be read or written
    opnd_t watched_addr_reg = opnd_create_reg(watched_addr.reg);
    opnd_t watched_addr_opnd = state->ops->found_operand;
    watched_addr_opnd.size = OPSZ_lea;
    ADDI(INSTR_CREATE_lea(drcontext,
            watched_addr_reg,
            watched_addr_opnd));

    // store the kernel hole base address
    //opnd_t kernel_hole_reg = );
    opnd_t unwatched_addr_reg = opnd_create_reg(unwatched_addr.reg);
    ADDI(INSTR_CREATE_mov_imm(drcontext, unwatched_addr_reg,
            OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));

    // mask it with the computed address; if the masked and unmasked are the
    // same then we found a watchpoint, otherwise we didn't.
    ADDI(INSTR_CREATE_or(drcontext, watched_addr_reg, unwatched_addr_reg));
    ADDI(INSTR_CREATE_cmp(drcontext, watched_addr_reg, watched_addr_reg));
    ADDI(INSTR_CREATE_jcc(drcontext, OP_je,
            opnd_create_instr(addr_is_not_a_watchpoint)));

    ADDI(addr_is_a_watchpoint);

    // replace the memory operands
    emulated = instr_clone(drcontext, instr);
    emulated->translation = 0;
    state->ops->replacement_operand = opnd_create_base_disp(
            watched_addr.reg, DR_REG_NULL, 1, 0, state->ops->found_operand.size);
    for_each_operand(emulated, state->ops,
            (opnd_callback_t *) memory_operand_replacer);

    // execute the emulated instruction
    ADDI(emulated);

    // restore saved state.
    cursor = restore_register(drcontext, bb, cursor, &unwatched_addr);
    cursor = restore_register(drcontext, bb, cursor, &watched_addr);
    if(!state->flags_are_dead) {
        ADDI(INSTR_CREATE_popf(drcontext));
    }

    ADDI(INSTR_CREATE_jmp_short(drcontext,
            opnd_create_instr(done_instrumenting)));

    // fall-through
    ADDI(addr_is_not_a_watchpoint);

    // restore saved state.
    cursor = restore_register(drcontext, bb, cursor, &unwatched_addr);
    cursor = restore_register(drcontext, bb, cursor, &watched_addr);
    if(!state->flags_are_dead) {
        ADDI(INSTR_CREATE_popf(drcontext));
    }

    /*** original instruction here ***/
    instr->translation = 0; // hack!
    instr_being_modified(instr, false);
    instr_set_ok_to_mangle(instr, false);

    cursor = instr;

    POST(done_instrumenting);
    nop->translation = pc; // hack!
    POST(nop);
}


// light instrumentation for an instruction
// basic assumption : every memory operation is happening on watched address
//          save registers
//          emulate the original instruction
//          restore registers
static void add_watchpoint_light(
        void *drcontext,
        instrlist_t *bb,
        instr_t *instr,
        app_pc pc,
        struct watchpoint_state *state
) {
    bool spilled_unwatched_addr = false;
    struct spill_reg_t watched_addr;
    struct spill_reg_t unwatched_addr;

    instr_t *begin_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *nop = INSTR_CREATE_nop(drcontext);
    instr_t *cursor = instr;

    PRE(begin_instrumenting);

    cursor = begin_instrumenting;
    cursor = save_register(drcontext, bb, cursor, state, &watched_addr);
    cursor = save_register(drcontext, bb, cursor, state, &unwatched_addr);
    if(!state->flags_are_dead) {
        ADDI(INSTR_CREATE_pushf(drcontext));
    }


    // calculate and store the address that is about to be read or written
    opnd_t watched_addr_reg = opnd_create_reg(watched_addr.reg);
    opnd_t watched_addr_opnd = state->ops->found_operand;
    watched_addr_opnd.size = OPSZ_lea;

    ADDI(INSTR_CREATE_lea(drcontext,
            watched_addr_reg,
            watched_addr_opnd));

    // store the kernel hole base address
    opnd_t unwatched_addr_reg = opnd_create_reg(unwatched_addr.reg);

    ADDI(INSTR_CREATE_mov_imm(drcontext, unwatched_addr_reg,
            OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));

    // mask it with the computed address, thus converting it into an
    // unwatched address
    ADDI(INSTR_CREATE_or(drcontext, unwatched_addr_reg, watched_addr_reg));

    // replace the memory operands in place
    state->ops->replacement_operand = opnd_create_base_disp(
            unwatched_addr.reg, DR_REG_NULL, 1, 0, state->ops->found_operand.size);
    for_each_operand(instr, state->ops,
            (opnd_callback_t *) memory_operand_replacer);

    instr->translation = 0; // hack!
    instr_being_modified(instr, false);
    instr_set_ok_to_mangle(instr, false);

    // restore saved state.
    cursor = instr;
    if(!state->flags_are_dead) {
        ADDI(INSTR_CREATE_popf(drcontext));
    }
    cursor = restore_register(drcontext, bb, cursor, &unwatched_addr);
    cursor = restore_register(drcontext, bb, cursor, &watched_addr);

    nop->translation = pc; // hack!
    ADDI(nop);
}
#endif



void cfi_watch_write(void *addr) {
    //print_file(STDERR,"%s : %lx\n",__FUNCTION__, addr);
    //printk("%s : %lx\n",__FUNCTION__, addr);
}

void cfi_watch_read(void *addr) {
    //printk("%s : %lx\n",__FUNCTION__, addr);
    //	alias_meta *meta(WATCHPOINT_META(addr));
}



typedef struct _mem_ref_t{
    bool write;
    void *addr;
    size_t size;
}mem_ref_t;

#define READABLE_TRACE
#define MAX_NUM_MEM_REFS 8192
#define MEM_BUF_SIZE (sizeof(mem_ref_t) * MAX_NUM_MEM_REFS)


#define REG_SPILL_START DR_REG_XAX
#define REG_SPILL_STOP DR_REG_R15

#define NUM_SPILL_REGS  (REG_SPILL_STOP - REG_SPILL_START + 1)

typedef struct _reg_status_t {
    reg_id_t reg;    	/* register id */
    bool used;       	/* if used for mem addresing */
    bool dead;       	/* if a dead reg in app  */
    bool steal;      	/* if steal by umbra      */
    bool restore_now;	/* if need instrument for restore value */
    bool save_now;   	/* if need instrument for save    value */
    int  count;      	/* usage count in a bb */
} reg_status_t;




/* thread private log file and counter */
typedef struct {
    char   *buf_ptr;
    char   *buf_base;	/* buf_end holds the negative value of real address of buffer end. */
    ptr_int_t buf_end;
    void   *cache;
    file_t  log;
    uint64  num_refs;
} per_thread_t;

typedef struct _basic_block_t {
    int    			id;
    app_pc 			tag;
    unsigned int   	flags;
    int    			length;
    void  			*bytes;
    int    			edge_in;
    int    			edge_out;
    int    			count;
    int    			num_refs;
    int    			num_app_instrs;
}basic_block_t;

/* ilist info */
typedef struct _ilist_info_t {
    basic_block_t 	*bb;
    int  			num_mems;
    int  			num_instrs;
    int  			num_steals;
    bool 			translate; 	/* if insert translation code */
    reg_id_t 		reg_addr;
    reg_status_t 	aflags;
    reg_status_t 	eax;
    reg_status_t 	regs[NUM_SPILL_REGS];
} ilist_info_t;


//static client_id_t client_id;



static inline void handle_mem_write(void)
{

}



noinline int break_at_add(void *addr, instr_t* instr) {
    int dsts = instr_num_dsts(instr);
    int srcs = instr_num_srcs(instr);
    instr_get_app_pc(instr);
    return dsts+srcs;
}



static inline void
replace_instr(void* drcontext, instrlist_t *ilist, instr_t **old, instr_t *new)
{
    //instr_set_translation(new, instr_get_translation(*old));
    instrlist_replace(ilist, *old, new);
    instr_destroy(drcontext, *old);
    *old = new;
}


static inline const char *op_name(int opcode) {
    static const char *op_names[] = {
#		define OP_MACRO(o) #o ,
#		include "opcodes.h"
#		undef OP_MACRO
            "" // sentinel
    };
    return op_names[opcode];
}



static inline void break_on_multiple_dests(int num_dests, int num_sources, void *pc) {
    (void) num_dests;
    (void)num_sources;
    (void)pc;
}


#define LOG_FILE "address_log.txt"
static inline void
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

bool
instr_reads_from_aflags(instr_t *instr)
{
    uint aflags;

    aflags = instr_get_arith_flags(instr);
    if (TESTANY(EFLAGS_READ_6, aflags))
        return true;
    return false;
}


void break_on_dsts_2(app_pc *pc, instr_t *instr) {
    int num = instr_num_dsts(instr);
    (void)num;
}

void break_on_dsts_test(app_pc *pc, instr_t *instr) {
    int num = instr_num_dsts(instr);
    int src = instr_num_srcs(instr);
    (void)num;
    (void)src;
}

//#define USE_NON_CANNONICAL_ADDR

/* check if instr update the whol register */
static bool
instr_writes_to_whole_reg(instr_t *instr, reg_id_t reg)
{
    if (instr_writes_to_exact_reg(instr, reg))
        return true;

    reg = reg_64_to_32(reg);
    if (instr_writes_to_exact_reg(instr, reg))
        return true;

    return false;
}

/* check if this instr set an register to immed value */
static bool
reg_set_immed(instr_t *instr, reg_id_t reg)
{
    int opcode = instr_get_opcode(instr);

    // for case of r1 = r1 - r1, or r1 = r1 xor r1
    if((opcode == OP_sub || opcode == OP_xor) &&
            (opnd_same(instr_get_src(instr, 0),
                    instr_get_src(instr, 1))))
        return true;

    if(opcode == OP_mov_ld          &&
            opnd_is_immed(instr_get_src(instr, 0)))
        return true;
    if (opcode == OP_mov_imm)
        return true;

    return false;
}

/* check if register is dead before this instr */
bool
register_is_dead(instr_t *instr, reg_id_t reg)
{
    int  opcode;

    // when at interupt, register never die
    if(instr_is_syscall(instr) || instr_is_interrupt(instr))
        return false;

    opcode = instr_get_opcode(instr);
    // dead reg must be exact dst being written
    if (!instr_writes_to_whole_reg(instr, reg))
        return false;

    // reg is set to be immed
    // r1 = r1 - r1 || r1 = r1 xor r1 || r1 = immed
    if(reg_set_immed(instr, reg))
        return true;

    // dead reg cannot be used
    if(instr_reg_in_src(instr, reg))
        return false;

    // must be a dead reg now
    return true;
}


static inline reg_id_t
get_dead_registers (instrlist_t *bb, instr_t *instr) {
    reg_id_t reg;
    reg_id_t dead_reg = DR_REG_NULL;
    for (reg = REG_SPILL_START; reg <= REG_SPILL_STOP; reg++)
    {
        if (register_is_dead(instr, reg)) {
            for (;;) {
                instr_t *prev = instr_get_prev(instr);
                if (prev == NULL || instr_reads_from_reg(prev, reg)) {
                    dead_reg = reg;
                    break;
                }
                instr = prev;
            }
        }
    }

    return dead_reg;
}


#define TEST_VALUE  0x1

#if 0
static instr_t*
instrument_read_mem_3src(void *drcontext, instrlist_t *ilist, instr_t *instr)
{
    unsigned long used_registers = 0;
    unsigned int i;
    reg_id_t reg;
    reg_id_t dead_reg = DR_REG_R10;
    bool instrument_flag = 0;

    instr_t* next;

    instr_t *execute_native_instr = INSTR_CREATE_label(drcontext);
    instr_t *done_emulation = INSTR_CREATE_label(drcontext);
    instr_t *next_nop = INSTR_CREATE_label(drcontext);
    instr_t *label_src1 = INSTR_CREATE_label(drcontext);
    instr_t *label_src2 = INSTR_CREATE_label(drcontext);
    instr_t *label_src3 = INSTR_CREATE_label(drcontext);
    instr_t* instr_cloned;

    if(instr_reads_from_reg(instr, DR_REG_RSP)
            || instr_reads_from_reg(instr, DR_REG_RBP)
            || instr_reads_from_aflags(instr)
            || instr_is_sse_or_sse2(instr)){
        return instr;
    }

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );

    reg_id_t reg_mem_addr[3];
    opnd_t opnd_mem_addr[3];
    reg_mem_addr[0] = get_next_free_reg(&used_registers);
    opnd_mem_addr[0] = opnd_create_reg(reg_mem_addr[0]);

    reg_mem_addr[1] = get_next_free_reg(&used_registers);
    opnd_mem_addr[1] = opnd_create_reg(reg_mem_addr[1]);

    reg_mem_addr[2] = get_next_free_reg(&used_registers);
    opnd_mem_addr[2] = opnd_create_reg(reg_mem_addr[2]);

    reg_id_t reg_kernel_hole = get_next_free_reg(&used_registers);
    opnd_t opnd_kernel_hole = opnd_create_reg(reg_kernel_hole);

    opnd_t opnd_src0 = instr_get_src(instr, 0);
    opnd_t opnd_src1 = instr_get_src(instr, 1);
    opnd_t opnd_src2 = instr_get_src(instr, 2);

    instr_t* clone_instr = instr_clone(drcontext, instr);
    instr_set_app_pc(clone_instr, NULL);
    opnd_t opnd_src_clone[3];
    opnd_src_clone[0] = instr_get_src(clone_instr, 0);
    opnd_src_clone[1] = instr_get_src(clone_instr, 1);
    opnd_src_clone[2] = instr_get_src(clone_instr, 2);

    instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_push(drcontext, opnd_mem_addr[0]));
    instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_push(drcontext, opnd_mem_addr[1]));
    instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_push(drcontext, opnd_mem_addr[2]));
    instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_push(drcontext, opnd_kernel_hole));
    //instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(KERNEL_MEMORY_START)));
    instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pushf(drcontext));


    if (opnd_is_rel_addr(opnd_src0) || opnd_is_abs_addr(opnd_src0)) {

    }else if (opnd_is_base_disp(opnd_src0)) {
        reg_id_t src_reg = opnd_get_base(opnd_src0);

        switch (src_reg) {
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

        instrument_flag = 1;

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_lea(drcontext,
                        opnd_mem_addr[0],
                        opnd_create_base_disp(src_reg, opnd_get_index(opnd_src0), opnd_get_scale(opnd_src0), opnd_get_disp(opnd_src0), OPSZ_lea)));

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_test(drcontext, opnd_mem_addr[0], opnd_mem_addr[0]));

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(label_src1)));

        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(KERNEL_ADDRESS_OFFSET)));
        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_or(drcontext, opnd_mem_addr[0], opnd_kernel_hole));

        opnd_set_disp(&opnd_src_clone[0], 0);
        opnd_set_base(&opnd_src_clone[0], opnd_get_reg(opnd_mem_addr[0]));
        opnd_set_index(&opnd_src_clone[0], DR_REG_NULL);
        opnd_set_scale(&opnd_src_clone[0], 0);
    }
    else {

    }

    instrlist_meta_preinsert(ilist, instr, label_src1);

    if (opnd_is_rel_addr(opnd_src1) || opnd_is_abs_addr(opnd_src1)) {

    }else if (opnd_is_base_disp(opnd_src1)) {
        reg_id_t src_reg = opnd_get_base(opnd_src1);

        switch (src_reg) {
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

        instrument_flag = 1;

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_lea(drcontext,
                        opnd_mem_addr[1],
                        opnd_create_base_disp(src_reg, opnd_get_index(opnd_src1), opnd_get_scale(opnd_src1), opnd_get_disp(opnd_src1), OPSZ_lea)));

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_test(drcontext, opnd_mem_addr[1], opnd_mem_addr[1]));

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(label_src2)));

        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(KERNEL_ADDRESS_OFFSET)));
        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_or(drcontext, opnd_mem_addr[1], opnd_kernel_hole));

        opnd_set_disp(&opnd_src_clone[1], 0);
        opnd_set_base(&opnd_src_clone[1], opnd_get_reg(opnd_mem_addr[1]));
        opnd_set_index(&opnd_src_clone[1], DR_REG_NULL);
        opnd_set_scale(&opnd_src_clone[1], 0);
    }
    else {

    }

    instrlist_meta_preinsert(ilist, instr, label_src2);

    if (opnd_is_rel_addr(opnd_src2) || opnd_is_abs_addr(opnd_src2)) {

    }else if (opnd_is_base_disp(opnd_src2)) {
        reg_id_t src_reg = opnd_get_base(opnd_src2);

        switch (src_reg) {
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

        instrument_flag = 1;

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_lea(drcontext,
                        opnd_mem_addr[1],
                        opnd_create_base_disp(src_reg, opnd_get_index(opnd_src2), opnd_get_scale(opnd_src2), opnd_get_disp(opnd_src2), OPSZ_lea)));

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_test(drcontext, opnd_mem_addr[2], opnd_mem_addr[2]));

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(label_src3)));

        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(KERNEL_ADDRESS_OFFSET)));
        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_or(drcontext, opnd_mem_addr[2], opnd_kernel_hole));

        opnd_set_disp(&opnd_src_clone[2], 0);
        opnd_set_base(&opnd_src_clone[2], opnd_get_reg(opnd_mem_addr[2]));
        opnd_set_index(&opnd_src_clone[2], DR_REG_NULL);
        opnd_set_scale(&opnd_src_clone[2], 0);
    }
    else {

    }

    instrlist_meta_preinsert(ilist, instr, label_src3);

    instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_popf(drcontext));
    instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_kernel_hole));


    if(instrument_flag == 1)
    {
        instr_set_src(clone_instr, 0, opnd_src_clone[0]);
        instr_set_src(clone_instr, 1, opnd_src_clone[1]);
        instr_set_src(clone_instr, 1, opnd_src_clone[2]);
        instrlist_meta_preinsert(ilist, instr, clone_instr);
        instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_pop(drcontext, opnd_mem_addr[2]));
        instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_pop(drcontext, opnd_mem_addr[1]));
        instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_pop(drcontext, opnd_mem_addr[0]));
        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_jmp(drcontext, opnd_create_instr(done_emulation)));
    }

    instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_pop(drcontext, opnd_mem_addr[2]));
    instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_pop(drcontext, opnd_mem_addr[1]));
    instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_pop(drcontext, opnd_mem_addr[0]));

    instrlist_meta_postinsert(ilist, instr, next_nop);
    instr_t *dummy_op = INSTR_CREATE_nop(drcontext);
    instr_set_app_pc(dummy_op, instr_get_app_pc(instr));
    instrlist_meta_postinsert(ilist, instr, dummy_op);

    instrlist_meta_postinsert(ilist, instr, done_emulation);

    instrlist_meta_postinsert(
            ilist,
            instr,
            INSTR_CREATE_jmp(drcontext, opnd_create_instr(next_nop)));

    //	return instr;

}



static instr_t*
instrument_read_mem_2src(void *drcontext, instrlist_t *ilist, instr_t *instr)
{
    unsigned long used_registers = 0;
    unsigned int i;
    reg_id_t reg;
    reg_id_t dead_reg = DR_REG_R10;
    bool instrument_flag = 0;

    instr_t* next;

    instr_t *execute_native_instr = INSTR_CREATE_label(drcontext);
    instr_t *done_emulation = INSTR_CREATE_label(drcontext);
    instr_t *next_nop = INSTR_CREATE_label(drcontext);
    instr_t *label_src1 = INSTR_CREATE_label(drcontext);
    instr_t *label_src2 = INSTR_CREATE_label(drcontext);
    instr_t* instr_cloned;

    if(instr_reads_from_reg(instr, DR_REG_RSP)
            || instr_reads_from_reg(instr, DR_REG_RBP)
            || instr_reads_from_aflags(instr)
            || instr_is_sse_or_sse2(instr)){
        return instr;
    }

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );

#if 0
    for (reg = REG_SPILL_START; reg <= REG_SPILL_STOP; reg++) {
        if (register_is_dead(instr, reg)) {
            for (;;) {
                instr_t *prev = instr_get_prev(instr);
                if (prev == NULL || instr_reads_from_reg(prev, reg)) {
                    dead_reg = reg;
                    break;
                }
                instr = prev;
            }
        }
    }
#endif
reg_id_t reg_mem_addr[2];
opnd_t opnd_mem_addr[2];
reg_mem_addr[0] = get_next_free_reg(&used_registers);
opnd_mem_addr[0] = opnd_create_reg(reg_mem_addr[0]);

reg_mem_addr[1] = get_next_free_reg(&used_registers);
opnd_mem_addr[1] = opnd_create_reg(reg_mem_addr[1]);

reg_id_t reg_kernel_hole = get_next_free_reg(&used_registers);
opnd_t opnd_kernel_hole = opnd_create_reg(reg_kernel_hole);

opnd_t opnd_src0 = instr_get_src(instr, 0);
opnd_t opnd_src1 = instr_get_src(instr, 1);

instr_t* clone_instr = instr_clone(drcontext, instr);
instr_set_app_pc(clone_instr, NULL);
opnd_t opnd_src_clone[2];
opnd_src_clone[0] = instr_get_src(clone_instr, 0);
opnd_src_clone[1] = instr_get_src(clone_instr, 1);

instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_push(drcontext, opnd_mem_addr[0]));
instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_push(drcontext, opnd_mem_addr[1]));
instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_push(drcontext, opnd_kernel_hole));
//instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(KERNEL_MEMORY_START)));
instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pushf(drcontext));


if (opnd_is_rel_addr(opnd_src0) || opnd_is_abs_addr(opnd_src0)) {

}else if (opnd_is_base_disp(opnd_src0)) {
    reg_id_t src_reg = opnd_get_base(opnd_src0);

    switch (src_reg) {
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

    instrument_flag = 1;

    instrlist_meta_preinsert(
            ilist,
            instr,
            INSTR_CREATE_lea(drcontext,
                    opnd_mem_addr[0],
                    opnd_create_base_disp(src_reg, opnd_get_index(opnd_src0), opnd_get_scale(opnd_src0), opnd_get_disp(opnd_src0), OPSZ_lea)));

    instrlist_meta_preinsert(
            ilist,
            instr,
            INSTR_CREATE_test(drcontext, opnd_mem_addr[0], opnd_mem_addr[0]));

    instrlist_meta_preinsert(
            ilist,
            instr,
            INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(label_src1)));

    instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(KERNEL_ADDRESS_OFFSET)));
    instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_or(drcontext, opnd_mem_addr[0], opnd_kernel_hole));

    opnd_set_disp(&opnd_src_clone[0], 0);
    opnd_set_base(&opnd_src_clone[0], opnd_get_reg(opnd_mem_addr[0]));
    opnd_set_index(&opnd_src_clone[0], DR_REG_NULL);
    opnd_set_scale(&opnd_src_clone[0], 0);
}
else {

}

instrlist_meta_preinsert(ilist, instr, label_src1);

if (opnd_is_rel_addr(opnd_src1) || opnd_is_abs_addr(opnd_src1)) {

}else if (opnd_is_base_disp(opnd_src1)) {
    reg_id_t src_reg = opnd_get_base(opnd_src1);

    switch (src_reg) {
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

    instrument_flag = 1;

    instrlist_meta_preinsert(
            ilist,
            instr,
            INSTR_CREATE_lea(drcontext,
                    opnd_mem_addr[1],
                    opnd_create_base_disp(src_reg, opnd_get_index(opnd_src1), opnd_get_scale(opnd_src1), opnd_get_disp(opnd_src1), OPSZ_lea)));

    instrlist_meta_preinsert(
            ilist,
            instr,
            INSTR_CREATE_test(drcontext, opnd_mem_addr[1], opnd_mem_addr[1]));

    instrlist_meta_preinsert(
            ilist,
            instr,
            INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(label_src2)));

    instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(KERNEL_ADDRESS_OFFSET)));
    instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_or(drcontext, opnd_mem_addr[1], opnd_kernel_hole));

    opnd_set_disp(&opnd_src_clone[1], 0);
    opnd_set_base(&opnd_src_clone[1], opnd_get_reg(opnd_mem_addr[1]));
    opnd_set_index(&opnd_src_clone[1], DR_REG_NULL);
    opnd_set_scale(&opnd_src_clone[1], 0);
}
else {

}

instrlist_meta_preinsert(ilist, instr, label_src2);
instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_popf(drcontext));
instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_kernel_hole));


if(instrument_flag == 1)
{
    instr_set_src(clone_instr, 0, opnd_src_clone[0]);
    instr_set_src(clone_instr, 1, opnd_src_clone[1]);
    instrlist_meta_preinsert(ilist, instr, clone_instr);
    instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_pop(drcontext, opnd_mem_addr[1]));
    instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_pop(drcontext, opnd_mem_addr[0]));
    instrlist_meta_preinsert(
            ilist,
            instr,
            INSTR_CREATE_jmp(drcontext, opnd_create_instr(done_emulation)));
}

instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_pop(drcontext, opnd_mem_addr[1]));
instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_pop(drcontext, opnd_mem_addr[0]));

instrlist_meta_postinsert(ilist, instr, next_nop);
instr_t *dummy_op = INSTR_CREATE_nop(drcontext);
instr_set_app_pc(dummy_op, instr_get_app_pc(instr));
instrlist_meta_postinsert(ilist, instr, dummy_op);

instrlist_meta_postinsert(ilist, instr, done_emulation);

instrlist_meta_postinsert(
        ilist,
        instr,
        INSTR_CREATE_jmp(drcontext, opnd_create_instr(next_nop)));

//	return instr;

}

static instr_t*
instrument_read_mem_1src(void *drcontext, instrlist_t *ilist, instr_t *instr)
{
    unsigned long used_registers = 0;
    unsigned int i;
    reg_id_t reg;
    reg_id_t dead_reg = DR_REG_R10;

    instr_t* next;

    instr_t *execute_native_instr = INSTR_CREATE_label(drcontext);
    instr_t *done_emulation = INSTR_CREATE_label(drcontext);
    instr_t *next_nop = INSTR_CREATE_label(drcontext);
    instr_t* instr_cloned;

    if(instr_reads_from_reg(instr, DR_REG_RSP)
            || instr_reads_from_reg(instr, DR_REG_RBP)
            || instr_reads_from_aflags(instr)
            || instr_is_sse_or_sse2(instr)){
        return instr;
    }

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );

    if(instr_get_opcode(instr) == OP_add) {
        //	break_at_add(instr_get_app_pc(instr), instr);
    }

    reg_id_t reg_mem_addr = get_next_free_reg(&used_registers);
    opnd_t opnd_mem_addr = opnd_create_reg(reg_mem_addr);

    reg_id_t reg_kernel_hole = get_next_free_reg(&used_registers);
    opnd_t opnd_kernel_hole = opnd_create_reg(reg_kernel_hole);

    opnd_t opnd_src0 = instr_get_src(instr, 0);


    if((instr_num_srcs(instr) == 1))
    {

        if (opnd_is_rel_addr(opnd_src0) || opnd_is_abs_addr(opnd_src0)) {

        }else if (opnd_is_base_disp(opnd_src0)) {
            reg_id_t src_reg = opnd_get_base(opnd_src0);

            switch (src_reg) {
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

            instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_push(drcontext, opnd_mem_addr));
            instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_push(drcontext, opnd_kernel_hole));

            /*	instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_RAX)));
			instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_ld(drcontext, opnd_create_reg(DR_REG_RAX), opnd_create_reg(DR_REG_RSP)));
			instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(0xffffffffffffc000)));
			instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_and(drcontext, opnd_create_reg(DR_REG_RAX), opnd_kernel_hole));

			instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_st(drcontext, opnd_create_base_disp(DR_REG_RAX, DR_REG_NULL, 0, 0, OPSZ_PTR), opnd_mem_addr));
			instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_RAX)));
			//instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_push(drcontext, opnd_kernel_hole));
             */		//instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(KERNEL_MEMORY_START)));

            instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pushf(drcontext));

            instrlist_meta_preinsert(
                    ilist,
                    instr,
                    INSTR_CREATE_lea(drcontext,
                            opnd_mem_addr,
                            opnd_create_base_disp(src_reg, opnd_get_index(opnd_src0), opnd_get_scale(opnd_src0), opnd_get_disp(opnd_src0), OPSZ_lea)));

            instrlist_meta_preinsert(
                    ilist,
                    instr,
                    INSTR_CREATE_test(drcontext, opnd_mem_addr, opnd_mem_addr));

            instrlist_meta_preinsert(
                    ilist,
                    instr,
                    INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(execute_native_instr)));

            CC(dr_insert_clean_call(drcontext, ilist, instr, (void *)cfi_watch_read, false, 1, opnd_mem_addr);)

            instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(KERNEL_ADDRESS_OFFSET)));
            instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_or(drcontext, opnd_mem_addr, opnd_kernel_hole));

            instr_t* clone_instr = instr_clone(drcontext, instr);
            instr_set_app_pc(clone_instr, NULL);
            opnd_t opnd_src1 = instr_get_src(clone_instr, 0);
            opnd_set_disp(&opnd_src1, 0);
            opnd_set_base(&opnd_src1, opnd_get_reg(opnd_mem_addr));
            opnd_set_index(&opnd_src1, DR_REG_NULL);
            opnd_set_scale(&opnd_src1, 0);
            instr_set_src(clone_instr, 0, opnd_src1);


            instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_popf(drcontext));
            instrlist_meta_preinsert(ilist, instr, clone_instr);
            instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_kernel_hole));
            instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_mem_addr));
            instrlist_meta_preinsert(
                    ilist,
                    instr,
                    INSTR_CREATE_jmp(drcontext, opnd_create_instr(done_emulation)));


            instrlist_meta_preinsert(ilist, instr, execute_native_instr);
            instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_popf(drcontext));
            instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_kernel_hole));
            instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_mem_addr));

            instrlist_meta_postinsert(ilist, instr, next_nop);
            instr_t *dummy_op = INSTR_CREATE_nop(drcontext);
            instr_set_app_pc(dummy_op, instr_get_app_pc(instr));
            instrlist_meta_postinsert(ilist, instr, dummy_op);

            instrlist_meta_postinsert(ilist, instr, done_emulation);

            instrlist_meta_postinsert(
                    ilist,
                    instr,
                    INSTR_CREATE_jmp(drcontext, opnd_create_instr(next_nop)));


            /*		instrlist_meta_postinsert(ilist, instr, INSTR_CREATE_push(drcontext, opnd_kernel_hole));
			instr = instr_get_next(instr);
			instrlist_meta_postinsert(ilist, instr, INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_RAX)));
			instr = instr_get_next(instr);
			instrlist_meta_postinsert(ilist, instr, INSTR_CREATE_mov_ld(drcontext, opnd_create_reg(DR_REG_RAX), opnd_create_reg(DR_REG_RSP)));
			instr = instr_get_next(instr);
			instrlist_meta_postinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(0xffffffffffffc000)));
			instr = instr_get_next(instr);
			instrlist_meta_postinsert(ilist, instr, INSTR_CREATE_and(drcontext, opnd_create_reg(DR_REG_RAX), opnd_kernel_hole));
			instr = instr_get_next(instr);
			instrlist_meta_postinsert(ilist, instr, INSTR_CREATE_mov_ld(drcontext, opnd_mem_addr, opnd_create_base_disp(DR_REG_RAX, DR_REG_NULL, 0, 0, OPSZ_PTR)));
			instr = instr_get_next(instr);
			instrlist_meta_postinsert(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_RAX)));
			instr = instr_get_next(instr);
			instrlist_meta_postinsert(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_kernel_hole));
			instr = instr_get_next(instr);

             */
        } else {

        }
    }
}





static instr_t*
instrument_write_mem_1dsts(void *drcontext, instrlist_t *ilist, instr_t *instr)
{
    unsigned long used_registers = 0;
    unsigned int i;

    instr_t* next;

    instr_t *execute_native_instr = INSTR_CREATE_label(drcontext);
    instr_t *done_emulation = INSTR_CREATE_label(drcontext);
    instr_t *next_nop = INSTR_CREATE_label(drcontext);
    instr_t* instr_cloned;

    if(instr_writes_to_reg(instr, DR_REG_RSP)
            || instr_writes_to_reg(instr, DR_REG_RBP)
            || instr_is_call(instr)
            /*|| instr_writes_to_any_aflags(instr)*/
            || instr_is_sse_or_sse2(instr)){
        return instr;
    }

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );

    reg_id_t reg_mem_addr = get_next_free_reg(&used_registers);
    opnd_t opnd_mem_addr = opnd_create_reg(reg_mem_addr);

    if(instr_get_opcode(instr) == OP_add) {
        //break_at_add(instr_get_app_pc(instr), instr);
    }

    reg_id_t reg_kernel_hole = get_next_free_reg(&used_registers);
    opnd_t opnd_kernel_hole = opnd_create_reg(reg_kernel_hole);

    opnd_t opnd_dst0 = instr_get_dst(instr, 0);

    if (opnd_is_rel_addr(opnd_dst0) || opnd_is_abs_addr(opnd_dst0)) {

    }else if (opnd_is_base_disp(opnd_dst0)) {
        reg_id_t dst_reg = opnd_get_base(opnd_dst0);

        switch (dst_reg) {
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

        //dr_insert_clean_call(drcontext, ilist, instr, (void *)cfi_watch_write, false, 1, opnd_mem_addr);

        instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_push(drcontext, opnd_mem_addr));
        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_push(drcontext, opnd_kernel_hole));
        //instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(KERNEL_MEMORY_START)));
        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pushf(drcontext));

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_lea(drcontext,
                        opnd_mem_addr,
                        opnd_create_base_disp(dst_reg, opnd_get_index(opnd_dst0), opnd_get_scale(opnd_dst0), opnd_get_disp(opnd_dst0), OPSZ_lea)));

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_test(drcontext, opnd_mem_addr, opnd_mem_addr));

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(execute_native_instr)));

        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(KERNEL_ADDRESS_OFFSET)));
        //dr_insert_clean_call(drcontext, ilist, instr, (void *)cfi_watch_write8, false, 1, opnd_mem_addr);
        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_or(drcontext, opnd_mem_addr, opnd_kernel_hole));



        instr_t* clone_instr = instr_clone(drcontext, instr);
        instr_set_app_pc(clone_instr, NULL);
        opnd_t opnd_dst1 = instr_get_dst(clone_instr, 0);

        instr_change_dsts_base_disp_opnd(clone_instr, 0, 0, opnd_get_reg(opnd_mem_addr), DR_REG_NULL, 0);


        if((instr_get_opcode(instr) == OP_add))
        {
            break_at_add(instr_get_app_pc(instr), instr);
            instr_change_srcs_base_disp_opnd(clone_instr, 1, 0, opnd_get_reg(opnd_mem_addr), DR_REG_NULL, 0);

        }

        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_popf(drcontext));
        instrlist_meta_preinsert(ilist, instr, clone_instr);
        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_kernel_hole));
        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_mem_addr));
        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_jmp(drcontext, opnd_create_instr(done_emulation)));


        instrlist_meta_preinsert(ilist, instr, execute_native_instr);
        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_popf(drcontext));
        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_kernel_hole));
        instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_pop(drcontext, opnd_mem_addr));


        instrlist_meta_postinsert(ilist, instr, next_nop);
        instr_t *dummy_op = INSTR_CREATE_nop(drcontext);
        instr_set_app_pc(dummy_op, instr_get_app_pc(instr));
        instrlist_meta_postinsert(ilist, instr, dummy_op);

        instrlist_meta_postinsert(ilist, instr, done_emulation);

        instrlist_meta_postinsert(
                ilist,
                instr,
                INSTR_CREATE_jmp(drcontext, opnd_create_instr(next_nop)));

    } else {

    }
}

static instr_t*
instrument_write_mem_2dsts(void *drcontext, instrlist_t *ilist, instr_t *instr)
{
    unsigned long used_registers = 0;
    unsigned int i;
    reg_id_t reg;
    reg_id_t dead_reg = DR_REG_R10;
    bool instrument_flag = 0;

    instr_t* next;

    instr_t *execute_native_instr = INSTR_CREATE_label(drcontext);
    instr_t *done_emulation = INSTR_CREATE_label(drcontext);
    instr_t *next_nop = INSTR_CREATE_label(drcontext);
    instr_t *label_dsts1 = INSTR_CREATE_label(drcontext);
    instr_t *label_dsts2 = INSTR_CREATE_label(drcontext);
    instr_t* instr_cloned;

    if(instr_writes_to_reg(instr, DR_REG_RSP)
            || instr_writes_to_reg(instr, DR_REG_RBP)
            || instr_is_call(instr)
            || instr_writes_to_any_aflags(instr)
            || instr_is_sse_or_sse2(instr)){
        return instr;
    }

    collect_regs(&used_registers, instr, instr_num_srcs, instr_get_src );
    collect_regs(&used_registers, instr, instr_num_dsts, instr_get_dst );

    if(instr_get_opcode(instr) == OP_add) {
        //break_at_add(instr_get_app_pc(instr), instr);
    }


    reg_id_t reg_mem_addr[2];
    opnd_t opnd_mem_addr[2];
    reg_mem_addr[0] = get_next_free_reg(&used_registers);
    opnd_mem_addr[0] = opnd_create_reg(reg_mem_addr[0]);

    reg_mem_addr[1] = get_next_free_reg(&used_registers);
    opnd_mem_addr[1] = opnd_create_reg(reg_mem_addr[1]);

    reg_id_t reg_kernel_hole = get_next_free_reg(&used_registers);
    opnd_t opnd_kernel_hole = opnd_create_reg(reg_kernel_hole);

    opnd_t opnd_dsts0 = instr_get_dst(instr, 0);
    opnd_t opnd_dsts1 = instr_get_dst(instr, 1);

    instr_t* clone_instr = instr_clone(drcontext, instr);

    instr_set_app_pc(clone_instr, NULL);
    opnd_t opnd_dsts_clone[2];
    opnd_dsts_clone[0] = instr_get_dst(clone_instr, 0);
    opnd_dsts_clone[1] = instr_get_dst(clone_instr, 1);

    instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_push(drcontext, opnd_mem_addr[0]));
    instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_push(drcontext, opnd_mem_addr[1]));
    instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_push(drcontext, opnd_kernel_hole));
    //instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(KERNEL_MEMORY_START)));
    instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pushf(drcontext));


    if (opnd_is_rel_addr(opnd_dsts0) || opnd_is_abs_addr(opnd_dsts0)) {

    }else if (opnd_is_base_disp(opnd_dsts0)) {
        reg_id_t dsts_reg = opnd_get_base(opnd_dsts0);

        switch (dsts_reg) {
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

        instrument_flag = 1;

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_lea(drcontext,
                        opnd_mem_addr[0],
                        opnd_create_base_disp(dsts_reg, opnd_get_index(opnd_dsts0), opnd_get_scale(opnd_dsts0), opnd_get_disp(opnd_dsts0), OPSZ_lea)));

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_test(drcontext, opnd_mem_addr[0], opnd_mem_addr[0]));

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(label_dsts1)));

        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(KERNEL_ADDRESS_OFFSET)));
        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_or(drcontext, opnd_mem_addr[0], opnd_kernel_hole));

        opnd_set_disp(&opnd_dsts_clone[0], 0);
        opnd_set_base(&opnd_dsts_clone[0], opnd_get_reg(opnd_mem_addr[0]));
        opnd_set_index(&opnd_dsts_clone[0], DR_REG_NULL);
        opnd_set_scale(&opnd_dsts_clone[0], 0);
    }
    else {

    }

    instrlist_meta_preinsert(ilist, instr, label_dsts1);

    if (opnd_is_rel_addr(opnd_dsts1) || opnd_is_abs_addr(opnd_dsts1)) {

    }else if (opnd_is_base_disp(opnd_dsts1)) {
        reg_id_t dsts_reg = opnd_get_base(opnd_dsts1);

        switch (dsts_reg) {
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

        instrument_flag = 1;

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_lea(drcontext,
                        opnd_mem_addr[1],
                        opnd_create_base_disp(dsts_reg, opnd_get_index(opnd_dsts1), opnd_get_scale(opnd_dsts1), opnd_get_disp(opnd_dsts1), OPSZ_lea)));

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_test(drcontext, opnd_mem_addr[1], opnd_mem_addr[1]));

        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(label_dsts2)));

        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_mov_imm(drcontext, opnd_kernel_hole, OPND_CREATE_INT64(KERNEL_ADDRESS_OFFSET)));
        instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_or(drcontext, opnd_mem_addr[1], opnd_kernel_hole));

        opnd_set_disp(&opnd_dsts_clone[1], 0);
        opnd_set_base(&opnd_dsts_clone[1], opnd_get_reg(opnd_mem_addr[1]));
        opnd_set_index(&opnd_dsts_clone[1], DR_REG_NULL);
        opnd_set_scale(&opnd_dsts_clone[1], 0);
    }
    else {

    }

    instrlist_meta_preinsert(ilist, instr, label_dsts2);
    instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_popf(drcontext));
    instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, opnd_kernel_hole));


    if(instrument_flag == 1)
    {
        instr_set_dst(clone_instr, 0, opnd_dsts_clone[0]);
        instr_set_dst(clone_instr, 1, opnd_dsts_clone[1]);
        instrlist_meta_preinsert(ilist, instr, clone_instr);
        instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_pop(drcontext, opnd_mem_addr[1]));
        instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_pop(drcontext, opnd_mem_addr[0]));
        instrlist_meta_preinsert(
                ilist,
                instr,
                INSTR_CREATE_jmp(drcontext, opnd_create_instr(done_emulation)));
    }

    instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_pop(drcontext, opnd_mem_addr[1]));
    instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_pop(drcontext, opnd_mem_addr[0]));

    instrlist_meta_postinsert(ilist, instr, next_nop);
    instr_t *dummy_op = INSTR_CREATE_nop(drcontext);
    instr_set_app_pc(dummy_op, instr_get_app_pc(instr));
    instrlist_meta_postinsert(ilist, instr, dummy_op);

    instrlist_meta_postinsert(ilist, instr, done_emulation);

    instrlist_meta_postinsert(
            ilist,
            instr,
            INSTR_CREATE_jmp(drcontext, opnd_create_instr(next_nop)));


}


static instr_t *
instrument_write_mem_dummy(void *drcontext, instrlist_t *ilist, instr_t *instr)
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

    if(instr_writes_to_reg(instr, DR_REG_RSP)
            || instr_writes_to_reg(instr, DR_REG_RBP)
            || instr_is_call(instr)
            || instr_writes_to_any_aflags(instr)
            || instr_is_sse_or_sse2(instr)
            /*|| 1 != instr_num_dsts(instr)*/
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

    if(instr_num_dsts(instr) == 1) {

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

            //if(instr_get_opcode(instr) == OP_mov_st || instr_get_opcode(instr) == OP_add || instr_get_opcode(instr) == OP_sub) {

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

            //instrlist_meta_preinsert(ilist, instr,	INSTR_CREATE_push(drcontext, src_val_reg));

            /*
				cloned_op = instr_clone(drcontext, instr);
				instr_set_app_pc(cloned_op, NULL);
				instr_set_dst(cloned_op, 0, src_val_reg);
				instrlist_meta_preinsert(ilist, instr, cloned_op);
             */
            /*	break_on_src_opnd(instr_app_pc);
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
             */

            //dr_insert_clean_call(drcontext, ilist, instr, (void *)cfi_watch_write, false, 1, reg_mem_addr);


            instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_pop(drcontext, reg_mem_addr));
            instrlist_meta_preinsert(ilist, instr, INSTR_CREATE_popf(drcontext));
            //}

        } else {

        }
    } else {
        break_on_src_opnd(instr_get_app_pc(instr));

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
#endif
#if 1

/* ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * Access / Modify operands.
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 */


/* ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * Updating memory operands in place; used in the implementation of watchpoints.
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 */






/* ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * Track live/dead registers.
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 */




/* ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * Instrument.
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 */

static void add_watchpoint_heavy(void *drcontext,
        instrlist_t *bb,
        instr_t *instr,
        app_pc pc,
        struct watchpoint_state *state);

//static instr_t*
//instrument_mem_operation(void *drcontext, instrlist_t *ilist, instr_t *instr, app_pc pc, struct watchpoint_state *state);

static inline dr_emit_flags_t
bb_event(void *drcontext, void *tag, instrlist_t *bb, bool for_trace, bool translating)
{
    instr_t *instr, *prev_instr;
    //opnd_t op;
    //uint opcode;
  //  int i;
 //   int instrumented = 0;
 //   app_pc first_instr = NULL;

    struct memory_operand_modifier ops = {0};
    struct register_manager regs = {0};
    struct register_manager spill_regs = {0};
    struct register_manager rewatch_tracker = {0};
    struct watchpoint_state state = {0};
    state.watch_read = true;
    state.watch_write = true;
    state.ops = &ops;
    state.regs = &regs;
    state.spill_regs = &spill_regs;
    state.flags_are_dead = false;
    revive_all_regs(&regs);
    revive_all_regs(&rewatch_tracker);

    for(instr = instrlist_last(bb); instr != NULL; instr = prev_instr) {
        bool lea_dest_was_live = false;
        app_pc pc = instr_get_app_pc(instr);
        prev_instr = instr_get_prev(instr);

        if(instr_get_opcode_eflags(instr->opcode)) {
            //state.flags_are_dead = true;
        }

        // don't want to instrument non-native code.
        if(!pc) {
            revive_all_regs(&regs);
            //find_dead_regs(&regs, instr);
            continue;
        }

       // if(instr_is_interrupt(instr)){
       //     revive_all_regs(&regs);
        //    continue;
      //  }

        if(OP_lea == instr->opcode) {
            reg_id_t dest_reg = instr->dsts[0].value.reg;
            lea_dest_was_live = reg_is_live(&rewatch_tracker, dest_reg);
        }

        // update the rewatch tracker
        find_merge_check_reg(&rewatch_tracker, instr);

        // lock prefix
        if((instr_get_prefixes(instr) & 0xf0) == 0xf0) {
            //find_dead_regs(&regs, instr);
            revive_all_regs(&regs);
            get_zombie(&rewatch_tracker);
            continue;
        }

        // ignore certain instructions (e.g. that modify the stack)
        switch(instr->opcode) {
        case OP_pushf:  case OP_popf:
        case OP_push:   case OP_pop:
        case OP_call:   case OP_call_far:
        case OP_ret:    case OP_ret_far:
            find_dead_regs(&regs, instr);
            // fall-through
        case OP_nop:    case OP_nop_modrm:
            get_zombie(&rewatch_tracker);
            continue;
        default:
            if(instr_is_sse_or_sse2(instr)) {
                find_dead_regs(&regs, instr);
                get_zombie(&rewatch_tracker);
                continue;
            }
            break;
        }

        // go find our memory operands, if any
        memset(&ops, 0, sizeof ops);
        for_each_operand(instr, &ops, (opnd_callback_t *) memory_operand_finder);

        // no memory operands, so nothing to watch.
        if(!ops.has_memory_operand) {
            find_dead_regs(&regs, instr);
            get_zombie(&rewatch_tracker);
            continue;
        }

        if(OP_lea == instr->opcode) {
            find_dead_regs(&regs, instr);
            get_zombie(&rewatch_tracker);
            if(lea_dest_was_live) {
                reg_id_t dest_reg = instr->dsts[0].value.reg;
                revive_reg(&rewatch_tracker, dest_reg);
            }
            continue;
        }

        // policy based checks
        if(ops.has_source_memory_operand && !state.watch_read) {
            find_dead_regs(&regs, instr);
            get_zombie(&rewatch_tracker);
            continue;
        }

        if(ops.has_dest_memory_operand && !state.watch_write) {
            find_dead_regs(&regs, instr);
            get_zombie(&rewatch_tracker);
            continue;
        }

        // this is a likely local variable; don't instrument
        switch(ops.found_operand.value.base_disp.base_reg) {
        case DR_REG_RSP: case DR_REG_ESP: case DR_REG_SP:
        case DR_REG_RBP: case DR_REG_EBP: case DR_REG_BP:
            find_dead_regs(&regs, instr);
            get_zombie(&rewatch_tracker);
            continue;
        default:
            break;
        }

        // convenient iff we need to spill registers later on
        kill_all_regs(&spill_regs);
        revive_used_regs_in_instr(&spill_regs, instr);

      /*  if(instr_writes_memory(instr) || instr_reads_memory(instr)) {

            if (opnd_is_rel_addr(state.ops->found_operand) || opnd_is_abs_addr(state.ops->found_operand)) {

            }else if (opnd_is_base_disp(state.ops->found_operand)) {
                instrument_mem_operation(drcontext, bb, instr, pc, &state);
            }
        }
       */
        add_watchpoint_heavy(drcontext, bb, instr, pc, &state);
        // find dead regs for the next (i.e. prev) instruction
        find_dead_regs(&regs, instr);



    }
    return DR_EMIT_DEFAULT;

}

/* ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 * Add in instrumentation for a watchpoint.
 * ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 */

#define ADDI(...) { \
        instr_t *next_cursor = (__VA_ARGS__); \
        instrlist_meta_postinsert(bb, cursor, next_cursor); \
        cursor = instr_get_next(cursor); }

#define SPILL_REG(...) { \
        opnd_t opnd_reg = opnd_create_reg(__VA_ARGS__);\
        ADDI(INSTR_CREATE_push(drcontext, opnd_reg)); }

#define RESTORE_REG(...) { \
        opnd_t opnd_reg = opnd_create_reg(__VA_ARGS__);\
        ADDI(INSTR_CREATE_pop(drcontext, opnd_reg)); }

#define SAVE_MCONTEXT(...)   \
        SPILL_REG(DR_REG_RAX)   \
        SPILL_REG(DR_REG_RCX)   \
        SPILL_REG(DR_REG_RDX)   \
        SPILL_REG(DR_REG_RBX)   \
        SPILL_REG(DR_REG_RSP)   \
        SPILL_REG(DR_REG_RBP)   \
        SPILL_REG(DR_REG_RSI)   \
        SPILL_REG(DR_REG_RDI)   \
        SPILL_REG(DR_REG_R8)    \
        SPILL_REG(DR_REG_R9)    \
        SPILL_REG(DR_REG_R10)   \
        SPILL_REG(DR_REG_R11)   \
        SPILL_REG(DR_REG_R12)   \
        SPILL_REG(DR_REG_R13)   \
        SPILL_REG(DR_REG_R14)   \
        SPILL_REG(DR_REG_R15)

#define RESTORE_MCONTEXT(...)   \
        RESTORE_REG(DR_REG_R15) \
        RESTORE_REG(DR_REG_R14) \
        RESTORE_REG(DR_REG_R13) \
        RESTORE_REG(DR_REG_R12) \
        RESTORE_REG(DR_REG_R11) \
        RESTORE_REG(DR_REG_R10) \
        RESTORE_REG(DR_REG_R9)  \
        RESTORE_REG(DR_REG_R8)  \
        RESTORE_REG(DR_REG_RDI) \
        RESTORE_REG(DR_REG_RSI) \
        RESTORE_REG(DR_REG_RBP) \
        RESTORE_REG(DR_REG_RSP) \
        RESTORE_REG(DR_REG_RBX) \
        RESTORE_REG(DR_REG_RDX) \
        RESTORE_REG(DR_REG_RCX) \
        RESTORE_REG(DR_REG_RAX)


#define PRE(...) instrlist_meta_preinsert(bb, cursor, (__VA_ARGS__))
#define POST(...) instrlist_meta_postinsert(bb, cursor, (__VA_ARGS__))



noinline void break_on_save_register(struct spill_reg_t *r) {
    (void)r;
}
/// Get a register. This will either find a dead register, or if none exist,
/// spill a register, and then allow us to use the spilled register.
static instr_t *save_register(
        void *drcontext,
        instrlist_t *bb,
        instr_t *cursor,
        struct watchpoint_state *state,
        struct spill_reg_t *r
) {
    r->reg = get_zombie(state->regs);
    r->was_spilled = false;

    if(1 || !r->reg) {
        r->reg = get_zombie(state->spill_regs);
        r->was_spilled = true;
        ADDI(INSTR_CREATE_push(drcontext, opnd_create_reg(r->reg)));
    } else {
        break_on_save_register(r);
    }
    return cursor;
}


/// Restore a previously used register. If the register was dead then no
/// restoration is needed; otherwise we must restore it from the stack.
static instr_t *restore_register(
        void *drcontext,
        instrlist_t *bb,
        instr_t *cursor,
        struct spill_reg_t *r
) {
    if(r->was_spilled) {
        ADDI(INSTR_CREATE_pop(drcontext, opnd_create_reg(r->reg)));
    }
    return cursor;
}




#define INSTR_RAW_BITS_VALID    0x00080000
#define INSTR_RAW_BITS_ALLOCATED    0x00100000


static void add_watchpoint_heavy(void *drcontext,
        instrlist_t *bb,
        instr_t *instr,
        app_pc pc,
        struct watchpoint_state *state)
{
  //  bool spilled_unwatched_addr = false;
   // unsigned long used_registers = 0;
    struct spill_reg_t watched_addr;
    struct spill_reg_t unwatched_addr;
    struct spill_reg_t spill_reg[16];
    opnd_t watched_addr_reg;
    opnd_t watched_addr_opnd;
    opnd_t spill_addr_reg;
    opnd_t unwatched_addr_reg;

    instr_t *addr_is_a_watchpoint = INSTR_CREATE_label(drcontext);
    instr_t *addr_is_not_a_watchpoint = INSTR_CREATE_label(drcontext);
    instr_t *begin_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *done_instrumenting = INSTR_CREATE_label(drcontext);
    instr_t *done_check = INSTR_CREATE_label(drcontext);
    instr_t *nop = INSTR_CREATE_nop(drcontext);
    instr_t *do_callback = INSTR_CREATE_label(drcontext);
    //instr_t *next_nop = INSTR_CREATE_label(drcontext);
    instr_t *emulated;
    instr_t *cursor = instr;

    PRE(begin_instrumenting);

    cursor = begin_instrumenting;

    cursor = save_register(drcontext, bb, cursor, state, &watched_addr);
    cursor = save_register(drcontext, bb, cursor, state, &unwatched_addr);

#if 1
    if(!state->flags_are_dead) {
        ADDI(INSTR_CREATE_pushf(drcontext));
    }
#endif
    // calculate and store the address that is about to be read or written
    watched_addr_reg = opnd_create_reg(watched_addr.reg);
    watched_addr_opnd = state->ops->found_operand;
    //opnd_t instr_base_reg = opnd_create_reg(opnd_get_base(state->ops->found_operand));



    watched_addr_opnd.size = OPSZ_lea;
    ADDI(INSTR_CREATE_lea(drcontext,
            watched_addr_reg,
            watched_addr_opnd));


    // store the kernel hole base address
    //opnd_t kernel_hole_reg = );
    unwatched_addr_reg = opnd_create_reg(unwatched_addr.reg);
    ADDI(INSTR_CREATE_mov_imm(drcontext, unwatched_addr_reg,
            OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));
    // mask it with the computed address; if the masked and unmasked are the
    // same then we found a watchpoint, otherwise we didn't.
    ADDI(INSTR_CREATE_or(drcontext, unwatched_addr_reg, watched_addr_reg));
    ADDI(INSTR_CREATE_cmp(drcontext, unwatched_addr_reg, watched_addr_reg));
    ADDI(INSTR_CREATE_jcc(drcontext, OP_je,
            opnd_create_instr(addr_is_not_a_watchpoint)));
ADDI(addr_is_a_watchpoint);
    if(state->ops->has_dest_memory_operand) {
        cursor = save_register(drcontext, bb, cursor, state, &spill_reg[0]);
        spill_addr_reg = opnd_create_reg(spill_reg[0].reg);
        ADDI(INSTR_CREATE_mov_imm(drcontext, spill_addr_reg,
                OPND_CREATE_INT64(WATCHPOINT_INDEX_MASK)));
        ADDI(INSTR_CREATE_and(drcontext, spill_addr_reg, watched_addr_reg));
        ADDI(INSTR_CREATE_shl(drcontext, spill_addr_reg,  OPND_CREATE_INT8(SHIFT_BIT_COUNT)))
        cursor = save_register(drcontext, bb, cursor, state, &spill_reg[1]);
        spill_addr_reg = opnd_create_reg(spill_reg[1].reg);
        ADDI(INSTR_CREATE_mov_imm(drcontext, spill_addr_reg,
                OPND_CREATE_INT64(SHADOW_START_ADDR)));
        // cursor = save_register(drcontext, bb, cursor, state, &spill_reg[2]);
        // spill_addr_reg = opnd_create_reg(spill_reg[2].reg);

        ADDI(INSTR_CREATE_cmp(drcontext, unwatched_addr_reg,
                opnd_create_base_disp(spill_reg[1].reg, spill_reg[0].reg,
                        sizeof(struct alias_meta), 0, OPSZ_PTR)));
        ADDI(INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(do_callback)));

        // ADDI(INSTR_CREATE_mov_ld(drcontext, spill_addr_reg,
        //       opnd_create_base_disp(spill_reg[1].reg, spill_reg[0].reg,
        //            sizeof(struct alias_meta), 0, OPSZ_PTR)));

        // cursor = save_register(drcontext, bb, cursor, state, &spill_reg[3]);
        // spill_addr_reg = opnd_create_reg(spill_reg[3].reg);
        // ADDI(INSTR_CREATE_mov_ld(drcontext, spill_addr_reg,
        //       opnd_create_base_disp(spill_reg[1].reg, spill_reg[0].reg,
       //             sizeof(struct alias_meta), 8*sizeof(byte), OPSZ_PTR)));
        ADDI(INSTR_CREATE_cmp(drcontext, unwatched_addr_reg, opnd_create_base_disp(spill_reg[1].reg, spill_reg[0].reg,
                sizeof(struct alias_meta), 8*sizeof(byte), OPSZ_PTR)));
        ADDI(INSTR_CREATE_jcc(drcontext, OP_jle, opnd_create_instr(done_check)));
        ADDI(INSTR_CREATE_nop(drcontext));
        ADDI(do_callback);
        SAVE_MCONTEXT();
        dr_insert_call(drcontext, bb, cursor, cfi_watch_write, 1,unwatched_addr_reg);
        RESTORE_MCONTEXT();
        ADDI(done_check);
        //  cursor = restore_register(drcontext, bb, cursor, &spill_reg[3]);
        //  cursor = restore_register(drcontext, bb, cursor, &spill_reg[2]);
        cursor = restore_register(drcontext, bb, cursor, &spill_reg[1]);
        cursor = restore_register(drcontext, bb, cursor, &spill_reg[0]);

        //  SAVE_MCONTEXT();
        //   if(state->ops->has_dest_memory_operand) {
        //       dr_insert_call(drcontext, bb, cursor, cfi_watch_write, 1,unwatched_addr_reg);
        //   }else if(state->ops->has_source_memory_operand){
       // dr_insert_call(drcontext, bb, cursor, cfi_watch_read, 1,unwatched_addr_reg);
        //  }
        //  RESTORE_MCONTEXT();
        // replace the memory operands
    }
    emulated = instr_clone(drcontext, instr);
    emulated->translation = 0;

    state->ops->replacement_operand = opnd_create_base_disp(
            unwatched_addr.reg, /*opnd_get_index(state->ops->found_operand)*/DR_REG_NULL,
            /*opnd_get_scale(state->ops->found_operand)*/1, /*opnd_get_disp(state->ops->found_operand)*/0 , state->ops->found_operand.size);

    for_each_operand(emulated, state->ops,
            (opnd_callback_t *) memory_operand_replacer);

    // restore flags before the operand, just in case it depends on them.
    if(!state->flags_are_dead) {
        ADDI(INSTR_CREATE_popf(drcontext));
    }

    // execute the emulated instruction
    ADDI(emulated);

    // restore saved state.
    cursor = restore_register(drcontext, bb, cursor, &unwatched_addr);
    cursor = restore_register(drcontext, bb, cursor, &watched_addr);

    ADDI(INSTR_CREATE_jmp_short(drcontext,
            opnd_create_instr(done_instrumenting)));

    // fall-through
ADDI(addr_is_not_a_watchpoint);

    // restore saved state.
    if(!state->flags_are_dead) {
        ADDI(INSTR_CREATE_popf(drcontext));
    }

    cursor = restore_register(drcontext, bb, cursor, &unwatched_addr);
    cursor = restore_register(drcontext, bb, cursor, &watched_addr);

    /*** original instruction here ***/
    instr->translation = 0; // hack!
    instr_being_modified(instr, false);
    instr_set_ok_to_mangle(instr, false);

    cursor = instr;
   // ADDI(INSTR_CREATE_jmp(drcontext, opnd_create_instr(next_nop)));
ADDI(done_instrumenting);
    nop->translation = pc; // hack!
    ADDI(nop);
   // ADDI(next_nop)
}

#endif

extern struct file* logfile;



static void
 snapshot_mcontext(void *addr){
    dr_printf("thread id : %s\n",__FUNCTION__);
}

static inline instr_t*
granary_save_mcontext(void *drcontext, instrlist_t *bb, instr_t *instr)
{
	instr_t *cursor = instr;
    instr_t *save_mcontext = INSTR_CREATE_label(drcontext);
//    opnd_t opnd_reg_rax = opnd_create_reg(DR_REG_RAX);
//    opnd_t opnd_reg_rbx = opnd_create_reg(DR_REG_RBX);

    PRE(save_mcontext);
    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_RAX)));
    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_RBX)));
    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_RCX)));
    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_RDX)));
    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_RDI)));
    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_RSI)));
    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_RBP)));
    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_RSP)));

    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_R8)));
    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_R9)));
    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_R10)));
    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_R11)));
    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_R12)));
    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_R13)));
    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_R14)));
    PRE(INSTR_CREATE_push(drcontext, opnd_create_reg(DR_REG_R15)));
    PRE(INSTR_CREATE_pushf(drcontext));
    PRE(INSTR_CREATE_mov_ld(drcontext, opnd_create_reg(DR_REG_RAX), opnd_create_reg(DR_REG_RSP)));

    dr_insert_call(drcontext, bb, instr, snapshot_mcontext, false, 0/*, opnd_create_reg(DR_REG_RAX)*/);

    PRE(INSTR_CREATE_popf(drcontext));
    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_R15)));
    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_R14)));
    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_R13)));
    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_R12)));
    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_R11)));
    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_R10)));
    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_R9)));
    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_R8)));

    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_RSP)));
    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_RBP)));
    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_RSI)));
    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_RDI)));
    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_RDX)));
    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_RCX)));
    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_RBX)));
    PRE(INSTR_CREATE_pop(drcontext, opnd_create_reg(DR_REG_RAX)));

    return instr;
}


void cfi_update_thread_metainfo(struct task_struct *ptr)
{


}

static inline void
at_direct_call(app_pc instr_addr, app_pc target_addr)
{
    //cfi_update_thread_metainfo(current);
    //wake_up_process(sweep_task);
    //cfi_fprintf(logfile, "DIRECT @ %lx to %lx\n", instr_addr, target_addr);
   // granary_print_ld_stat(target_module);
}

static inline void
at_indirect_call(app_pc instr_addr, app_pc target_addr)
{
    wake_up_process(sweep_task);
   // cfi_fprintf(logfile, "INDIRECT @ %lx to %lx\n", instr_addr, target_addr);
  //  granary_print_ld_stat(target_module);
}

static inline void
at_return(app_pc instr_addr, app_pc target_addr)
{
    wake_up_process(sweep_task);
  //  cfi_fprintf(logfile, "RETURN @ %lx to %lx\n", instr_addr, target_addr);
   // granary_print_ld_stat(target_module);
}

extern client_cache_info_t *cpu_client_cache;

uint64_t flag = 0x0;
static DEFINE_MUTEX(hotpatch_lock);

void cfi_hotpatch_kernel(void *drcontext){
    client_cache_info_t * client = (client_cache_info_t*) dr_thread_alloc(drcontext, sizeof(client_cache_info_t));
    cpu_client_cache = client;
    printk("%s\n", __FUNCTION__);
    client->cache_start = dr_thread_alloc(drcontext, CLIENT_CACHE_SIZE);
    client->cache_ptr = emit_hotpatch_code(drcontext, client, client->cache_start, (void*)kfree);
    client->cache_ptr = emit_hotpatch_code(drcontext, client, client->cache_ptr, (void*)vfree);
    client->cache_ptr = emit_hotpatch_code(drcontext, client, client->cache_ptr, (void*)kmem_cache_free);

}

static void event_thread_init(void *drcontext)
{


    uint64_t local_flag;
    mutex_lock(&hotpatch_lock);
    if( flag == 0){
        dr_printf("************************************%s***********************************",__FUNCTION__);
        do {
            local_flag = flag;
        }while(!__sync_bool_compare_and_swap(&flag, local_flag, 0x1));
    }
    mutex_unlock(&hotpatch_lock);


}
static void event_thread_exit(void *drcontext)
{
    dr_printf("************************************%s***********************************",__FUNCTION__);

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
      //  dr_register_bb_event(bb_event);
#ifdef CLIENT_MEMORY_LEAK
    	dr_register_bb_event(memleak_bb_event);
#endif
#ifdef CLIENT_BUFFER_OVERFLOW
    	dr_register_bb_event(buffer_overflow_bb_event);
#endif
    	dr_register_thread_init_event(event_thread_init);
    	dr_register_thread_exit_event(event_thread_exit);
    	//cfi_fprintf(logfile, "dr_init \n");
    	//printk("dr_init : %lx\n", logfile);
#endif
}
