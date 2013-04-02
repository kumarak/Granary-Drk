/*
 * wrapper_rcu.hpp
 *
 *  Created on: 2013-01-03
 *      Author: akshayk, pag
 */

#ifndef WRAPPER_RCU_HPP_
#define WRAPPER_RCU_HPP_

volatile mem_t next_tid = 0;

void increment_thread_generation(void);
void set_thread_id(unsigned long tid) {
    current_thread_info()->spill_slot[0] = tid;
}

/// return the current thread's id: between 0 and NUM_THREADS - 1
uint64_t get_thread_id(void) {
    uint64_t &tid(current_thread_info()->spill_slot[0]);
    if(!tid) {
        tid = (unsigned long) cfi_atomic_change(&next_tid, add_one);

        // initialize the first generation number to be 1
        set_thread_id(next_tid-1);
        increment_thread_generation();
    }
    return tid - 1U; // so it's zero-indexed
}

/// return the current thread's generation number. When rcu_read_lock
/// is called, the thread's generation number is incremented by 1.
/// When rcu_read_unlock is called, the thread generation number is
/// incremented by 1. This allows us to distingish between reads before/after
/// the read-critical section by looking at the even/oddness of the thread's
/// current generation number.
uint64_t get_thread_generation(void) {
    return current_thread_info()->spill_slot[1];
}

void increment_thread_generation(void) {
    current_thread_info()->spill_slot[1]++;
}

uint64_t decrement_read_lock_count(void) {
    return --(current_thread_info()->spill_slot[2]);
}

void increment_read_lock_count(void) {
    ++(current_thread_info()->spill_slot[2]);
}

void reset_read_lock_count(void) {
    current_thread_info()->spill_slot[2] = 1;
}

#define DM(w, m, a) {if(!(m)) debug_watchpoint_meta((w), (a)); }

extern "C" {
    __attribute__((noinline)) void debug_watchpoint_meta(int where, void *addr) {
        (void) where;
        (void) addr;
    }
}


/// report only the first RCU-related error; this is also a convenient breakpoint for
/// discovering other RCU-related errors.
void rcu_error(const char *err, const char *loc) throw() {
    static bool report_error = true;
    if(report_error) {
        kern_printk("%s: %s\n", loc, err);
        report_error = false;
    }
}


#define RCU_TRACKED_TYPE struct rcu_torture


FUNC_WRAPPER(rcu_watch_assign_pointer, ( RCU_TRACKED_TYPE **dest, RCU_TRACKED_TYPE *addr, const char *loc), {

    if(!addr) {
        return *dest = addr;
    }
    if(!IS_WATCHPOINT(addr)) {
        rcu_error("RCU ERROR: RCU pointer assignment without adding watchpoint (1).", loc);
        return *dest = addr;
    }

    alias_meta *meta(WATCHPOINT_META(addr));

    DM(1, meta, addr)

    if(meta->is_dead()) {
        rcu_error("RCU ERROR: RCU pointer is dead and cannot be assigned (2).", loc);
        return *dest = addr;
    }

    if(!meta->is_source()) {
        rcu_error("RCU ERROR: Publishing a de-referenced RCU pointer (3).", loc);
        return *dest = addr;
    }

    const uint64_t thread_id(get_thread_id());
    const uint64_t thread_gen_num(get_thread_generation());

    if(!(thread_gen_num & 1)) {
        rcu_error("RCU ERROR: Can't publish a pointer while in a read-critical section (4).", loc);
        return *dest = addr;
    }

    if(!meta->can_write(thread_id)) {
        rcu_error("RCU ERROR: Publishing a non-writable RCU-protected data structure (5).", loc);
        return *dest = addr;
    }

    // TODO: check that global refcount of RCU read locks is 0

    meta->publish();

    return *dest = addr;
})


FUNC_WRAPPER_VOID(call_rcu, ( struct rcu_head * head , rcu_func func ), {
    if(!head) {
        kern_printk("RCU ERROR: call_rcu with NULL head.\n");
        return;
    }
    if(!IS_WATCHPOINT(head)) {
        kern_printk("RCU ERROR: call_rcu RCU protected data not watched.\n");
        call_rcu (head, func);
        return;
    }
    alias_meta *meta(WATCHPOINT_META(head));

    meta->kill();

    REMOVE_WATCHPOINT(head);
    get_thread_id();
    call_rcu (to_unaliased_address(head) , func);

    //ADD_WATCHPOINT(head);
})


FUNC_WRAPPER_VOID(rcu_watch_read_lock, (const char *loc), {

    // initialise thread id if not already initialised
    get_thread_id();

    const uint64_t thread_gen_num(get_thread_generation());
    if(!(thread_gen_num & 0x1)) {
        //rcu_error("RCU ERROR: Already in read critical section, recursive call of rcu_watch_read_lock (6).", loc);
        //return;
        increment_read_lock_count();
    } else {
        increment_thread_generation();
        reset_read_lock_count();
    }

    // TODO: increment global refcount of RCU read locks
})


FUNC_WRAPPER_VOID(rcu_watch_read_unlock, (const char *loc), {

    const uint64_t thread_gen_num(get_thread_generation());
    if((thread_gen_num & 0x1)) {
        rcu_error("RCU ERROR: not in read critical section, call of rcu_watch_read_unlock is not allowed (7).", loc);
        return;
    }

    if(!decrement_read_lock_count()) {
        increment_thread_generation();
    }
    // TODO: decrement global refcount of RCU read locks
})


FUNC_WRAPPER_VOID(rcu_watch_read_lock_bh, (const char *loc), {
    // TODO
})


FUNC_WRAPPER_VOID(rcu_watch_read_unlock_bh, (const char *loc), {
    // TODO
    (void) loc;
})


FUNC_WRAPPER_VOID(rcu_watch_read_lock_sched, (const char *loc), {
    // TODO
    (void) loc;
})

FUNC_WRAPPER_VOID(rcu_watch_read_unlock_sched, (const char *loc), {
    // TODO
    (void) loc;
})


/// Called when we do p = rcu_dereference(q)
FUNC_WRAPPER(rcu_watch_dereference, (RCU_TRACKED_TYPE *addr, const char *loc), {

    if(!addr) {
        return addr;
    }

    if(!IS_WATCHPOINT(addr)) {
        rcu_error("RCU ERROR: De-referencing non-RCU tracked pointer (9).", loc);
        return addr;
    }

    const uint64_t thread_id(get_thread_id());
    const uint64_t thread_gen_num(get_thread_generation());

    if((thread_gen_num & 0x1)) { // odd generation number; not in RCS
        rcu_error("RCU ERROR: Must call rcu_dereference within a read critical section (8).", loc);
        return addr;
    }

    alias_meta *meta_source(WATCHPOINT_META(addr));

    DM(2, meta_source, addr)

    if(meta_source->is_dead()) {
        rcu_error("RCU ERROR: De-referencing a dead RCU object (10).", loc);
        return addr;
    }

    if(!meta_source->is_source()) {
        rcu_error("RCU ERROR: De-referencing a de-referenced pointer (11).", loc);
        return addr;
    }

    // create a new watchpoint that references the old watchpoint. this captures
    // the requirement that `p` be readable, but not `q` in:
    // `p = rcu_dereference(q)`
    REMOVE_WATCHPOINT(addr);
    ADD_WATCHPOINT(addr);

    alias_meta *meta_alias = WATCHPOINT_META(addr);

    DM(3, meta_alias, addr)

    meta_alias->aliases(meta_source);

    if(meta_alias->can_read(thread_id, thread_gen_num)) {
        rcu_error("RCU ERROR: Double de-reference within same thread (12).", loc);
        return addr;
    }

    meta_source->allow_read(thread_id, thread_gen_num);

    return addr;
})


FUNC_WRAPPER(rcu_watch_alloc_, (RCU_TRACKED_TYPE *addr, const char *loc), {


    if(!addr) {
        return addr;
    }

    // remove the watchpoint if there; make sure it's dead.
    if(IS_WATCHPOINT(addr)) {
        alias_meta *old_meta(WATCHPOINT_META(addr));

        DM(4, old_meta, addr)

        if(!old_meta->is_dead()) {
            rcu_error("RCU CURIOSITY: Re-allocating non-dead RCU tracked data (13).", loc);
        }

        old_meta->kill();
        REMOVE_WATCHPOINT(addr);
    }

    ADD_WATCHPOINT(addr);
    alias_meta *meta(WATCHPOINT_META(addr));
    DM(5, meta, addr)

    if(meta){
        meta->make_source(); // allocates thread info
    }

    meta->allow_write(get_thread_id());

    return addr;
})


FUNC_WRAPPER(rcu_watch_free_, (RCU_TRACKED_TYPE *addr, const char *loc), {
    if(!addr) {
        return addr;
    }

    if(!IS_WATCHPOINT(addr)) {
        rcu_error("RCU ERROR: Freeing non-RCU protected data (14).", loc);
        return addr;
    }

    alias_meta *meta(WATCHPOINT_META(addr));
    DM(6, meta, addr)
    if(meta->is_dead()) {
        rcu_error("RCU ERROR: Double free of RCU protected data (15).", loc);
        return addr;
    }

    meta->kill();
    REMOVE_WATCHPOINT(addr);

    return addr;
})


#endif /* WRAPPER_RCU_HPP_ */
