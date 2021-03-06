/*
 * cfi_atomic.c
 *
 *  Created on: 2012-09-25
 *      Author: pag
 *     Version: $Id$
 */

#include "cfi_atomic.h"

void cfi_atomic_disable_interrupts(register mem_t *flags) {
    __asm__ __volatile__ (
        "pushf;"
        "cli;"
        "pop %%rax;"
        "movq %%rax, (%0);"
        : "=r"(flags)
    );
}

void cfi_atomic_enable_interrupts(register mem_t *flags) {
    __asm__ __volatile__ (
        "pushq (%0);"
        "popf;"
        :
        : "r"(flags)
    );
}

/// atomically change the location
mem_t cfi_atomic_change(
    register volatile mem_t *addr,
    register mem_t (*next_value_func)(mem_t curr_value)
) {
    register mem_t prev_value;
    __asm__ __volatile__ (
        "push %%rax;"
        "push %%r10;"

        "mov (%1), %%rax;"
    "1:"
        "mov %%rax, %%rdi;"
        "push %%rax;"               // save our picture of the current value

        "call *%2;"                 // compute the next value
        "mov %%rax, %%r10;"

        "pop %%rax;"                // restore current value

        "lock;"
        "cmpxchg %%r10, (%1);"
        "jnz 1b;"

        "mov %%rax, %0;"            // store the prev value

        "pop %%r10;"
        "pop %%rax;"

        : "=r"(prev_value)
        : "r"(addr), "r"(next_value_func)
        : "rax", "r10", "rdi"
    );

    return prev_value;
}

void cfi_debug_spinlock(void)
{

}
void cfi_debug_outside_lock(void)
{

}

mem_t add_one(mem_t val) { return val + 1; }
mem_t subtract_one(mem_t val) { return val + 1; }
mem_t to_zero(mem_t val) { return 0; }
mem_t to_one(mem_t val) { return 1; }


