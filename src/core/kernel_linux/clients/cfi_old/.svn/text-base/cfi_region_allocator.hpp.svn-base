/*
 * cfi_gencode.hpp
 *
 *  Created on: Aug 28, 2012
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef cfi_CFI_REGION_ALLOCATOR_HPP_
#define cfi_CFI_REGION_ALLOCATOR_HPP_

#include <stdint.h>
#include <string.h>

/// atomic, sliding allocator for some region of memory
template <typename T>
class atomic_region_allocator {
private:
    enum {
        SIZE = sizeof(T)
    };

    T *begin;
    T *end;
    T *next;

    /// allocate and return space for some new gencode
    T *slide(void) throw() {
        T *allocated_addr(0);

        __asm__ __volatile__ (
            "push %%rax;"
            "push %%rdx;"
            "mov %1, %%rax;"            // %rax = next
        "1:"
            "mov %%rax, %0;"            // mine = next

            "mov %%rax, %%rdx;"         // %rdx = next + 1
            "add $%c2, %%rdx;"          // sizeof(payload)

            "lock;"                     // make the CAS atomic
            "cmpxchg %%rdx, %1;"        // if %0 == %rax
                                        //    then %1 = %rdx, ZF = 1
                                        //    else %rax = %0, ZF = 0
            "jnz 1b;"    // if ZF == 0 then goto find_next_tracked;

            "pop %%rdx;"
            "pop %%rax;"

            : "=r"(allocated_addr)
            : "m"(this->next)
            , "N"(SIZE)
            // clobbered
            : "rax", "rdx"
        );

        return allocated_addr;
    }

public:

    atomic_region_allocator(void *begin_, void *end_) throw()
        : begin((T *) begin_)
        , end((T *) end_)
        , next(begin)
    { }

    T *allocate(void) throw() {
        return (T *) memset(slide(), 0, SIZE);
    }

    inline bool is_allocated(const T *addr) const throw() {
        return begin <= addr && addr < next && 0 == (((uint64_t) addr) % SIZE);
    }
};

#endif /* cfi_CFI_REGION_ALLOCATOR_HPP_ */
