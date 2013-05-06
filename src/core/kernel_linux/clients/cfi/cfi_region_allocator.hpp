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

extern "C" {
#	include "cfi_atomic.h"
}

/// atomic, sliding allocator for some region of memory
template <typename T>
class atomic_region_allocator {
private:

    typedef atomic_region_allocator<T> self_type;

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

        mem_t allocated_addr((mem_t)__sync_fetch_and_add(&(this->next), SIZE));

        return (T *) allocated_addr;
    }

public:

    void init(){
        this->begin = (T*) MODULE_SHADOW_END;
        this->end = (T*)MODULE_SHADOW_END_EXTENDED;
        this->next = this->begin;
    }

    /// initialize the bump pointer allocator;
    atomic_region_allocator(void *begin_, void *end_) throw()
        : begin((T *) begin_)
        , end((T *) end_)
        , next(begin)
    { }

    atomic_region_allocator(void *begin_, void *end_, void (*init)(self_type *)) throw()
        : begin((T *) begin_)
        , end((T *) end_)
        , next(begin)
    {
        init(this);
    }

    T *allocate(void) throw() {
        return (T *) memset(slide(), 0, SIZE);
    }

    T *allocate_index(unsigned long index) throw() {
        T* meta = this->begin + index;
        return (T *) memset(meta, 0, SIZE);
    }

    T *get_index(unsigned long index) throw() {
        T* meta = this->begin + index;
        return (T *) meta;
    }

    inline bool is_allocated(const T *addr) const throw() {
        return begin <= addr && addr < next /*&& 0 == (((uint64_t) addr) % SIZE)*/;
    }

    T *operator[](unsigned i) {
        T *entry = begin + i;
        if(!is_allocated(entry)) {
            return 0;
        }

        return entry;
    }

    FORCE_INLINE unsigned offset_of(const T *addr) const throw() {
        return (unsigned) (addr - begin);
    }
};

#endif /* cfi_CFI_REGION_ALLOCATOR_HPP_ */
