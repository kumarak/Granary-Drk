/*
 * meta.hpp
 *
 *  Created on: 2012-12-10
 *      Author: pag
 */

#ifndef ALIAS_META_HPP_
#define ALIAS_META_HPP_

#define MAX_WPOINT_COUNT 0x7FFF

#define DTI(w) {debug_thread_info((uint64_t)(w)); }

extern "C" {
    __attribute__((noinline)) void debug_thread_info(uint64_t threadinfo) {
        (void) threadinfo;
    }
}


enum {

    /// Maximum number of threads used by the RCU module.
    NUM_THREADS = 16,
};

/// used for kernel memory allocation
typedef void* vmalloc_type(unsigned long, int, unsigned long long);
typedef void vfree_type(unsigned long);
static vmalloc_type *kern___vmalloc = (vmalloc_type *) KERN_ADDR___vmalloc;
//static vfree_type *kern_vfree = (vfree_type *)KERN_ADDR_vfree;

/// Thread-specific watchpoint meta information.
struct alias_meta_thread {

    // spin lock and free list for allocating RCU thread meta info.
    static volatile mem_t LOCK;
    static alias_meta_thread *FREE_LIST;

    // for linking in the free list.
    alias_meta_thread *next;

    // writer thread_id + 1 iff this RCU-protected structure is being
    // written to; otherwise 0. An RCU-protected structure is writable from
    // the time of allocation up until it is published using rcu_assign_pointer.
    //
    // TODO:
    uint64_t writer_thread_id;

    // The "generation" number of the thread
    uint64_t gen_nums[NUM_THREADS];

    enum {
        MAX_SPIN = 100
    };

    /// Allocate some thread-specific meta information.
    static alias_meta_thread *allocate(void) throw() {
        alias_meta_thread *meta(0);
        mem_t flags;
        unsigned num_spins(0);
       // meta = (alias_meta_thread *) kern___vmalloc(
         //       sizeof(alias_meta_thread), 1 /* GFP_KERNEL */, 0 /* PAGE_RW */);
        //memset(meta, 0, sizeof *meta);
        //return meta;

        if(!FREE_LIST) {
            goto allocate_manually;
        }
        //cfi_debug_outside_lock();
        cfi_atomic_disable_interrupts(&flags);
        for(; cfi_atomic_change(&LOCK, to_one); ++num_spins) {
            cfi_debug_spinlock();
            if(num_spins > MAX_SPIN) {
                cfi_atomic_enable_interrupts(&flags);
                goto allocate_manually; // give up
            }
        }
        meta = FREE_LIST;

        // there's something on the free list.
        if(meta) {
            FREE_LIST = meta->next;
            LOCK = 0; // release the lock
            cfi_atomic_enable_interrupts(&flags);

            // we need to manually allocate.
        } else {
            LOCK = 0; // release the lock
            cfi_atomic_enable_interrupts(&flags);

        allocate_manually:
            meta = (alias_meta_thread *) kern___vmalloc(
                    sizeof(alias_meta_thread), 0x20 /* GFP_ATOMIC */, 0 /* PAGE_RW */);
        }

        memset(meta, 0, sizeof *meta);
        return meta;
    }

    /// Put one of the thread meta infos onto the free list.
    static void free(alias_meta_thread *meta) throw() {
        if(!meta) {
            return;
        }

        mem_t flags;
        cfi_atomic_disable_interrupts(&flags);
        while(cfi_atomic_change(&LOCK, to_one)) { /* spin */ }
        meta->next = FREE_LIST;
        FREE_LIST = meta;
        LOCK = 0; // release
        cfi_atomic_enable_interrupts(&flags);
    }
};

// static initializers
volatile mem_t alias_meta_thread::LOCK = 0;
alias_meta_thread *alias_meta_thread::FREE_LIST = 0;


/// Watchpoint meta information. An RCU watchpoint is
/// either a source (with thread-specific meta-information)
/// or is an alias of a source (i.e. alias = rcu_dereference(source)).
/// 
/// Sources are not allowed to be accessed, only aliases. This
/// enforces that every read/write must be on a RCU-dereferenced
/// pointer. However, sources maintain the thread generation
/// numbers needed to determine whether a read/write on an alias
/// is valid.
struct alias_meta {

    uint64_t base_address;
    uint64_t limit;

} __attribute__((packed));


#endif /* META_HPP_ */

