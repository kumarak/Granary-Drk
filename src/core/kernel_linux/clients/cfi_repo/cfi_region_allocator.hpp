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

#include "cfi_atomic.h"

/// atomic, sliding allocator for some region of memory
template <typename T>
class atomic_region_allocator {
private:
    enum {
        SIZE = sizeof(T)
    };

    T *begin;
    T *end;
    volatile T *next;

    /// add the size of the type T to the current value of next pointer
    static mem_t add_sizeof_T(mem_t current_value) throw() {
        return current_value + SIZE;
    }

    /// allocate and return space for some new gencode
    T *slide(void) throw() {

        mem_t allocated_addr(cfi_atomic_change(
            (volatile mem_t *) &(this->next),
            add_sizeof_T));

        return (T *) allocated_addr;
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

    T *operator[](unsigned i) {
        T *entry = begin + i;
        if(!is_allocated(entry)) {
            return 0;
        }

        return entry;
    }
};

#endif /* cfi_CFI_REGION_ALLOCATOR_HPP_ */
