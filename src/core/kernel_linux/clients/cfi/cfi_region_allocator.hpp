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

    extern void *module_page_alloc(unsigned long size);
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

    void init(void* begin, void* end){
        this->begin = (T*) begin;
        this->end = (T*) end;
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
        if((void*)this < (void*)4095){
            granary_fault();
            return false;
        }
        return begin <= addr && addr < end /*&& 0 == (((uint64_t) addr) % SIZE)*/;
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


#define PAGE_SHIFT      12
#define PAGE_SIZE       (1UL << PAGE_SHIFT)

struct shadow_region {
    union {
        char data[16];
        struct {
            uint64_t instr;
            uint64_t slot;
        };
    };
}__attribute__((packed));

struct shadow_allocator {
public:

    static atomic_region_allocator<shadow_region> shadow_module;

    static void init(){
        void *start_address = module_page_alloc(16*PAGE_SIZE);
        void *end_address = start_address + 16*PAGE_SIZE;
        kern_printk("shadow_allocator : %llx - %llx\n", start_address, end_address);
        shadow_module.init((void*)start_address, (void*)end_address);
    }

    static shadow_region *allocate(void) {
        shadow_region *entry(shadow_module.allocate());
        entry->instr = 0x0ULL;
        entry->slot = 0x0ULL;
        return entry;
    }

    static bool is_shadow_allocate(void *addr) {
        bool ret = shadow_module.is_allocated((shadow_region*)addr);
        return ret;
    }

};

atomic_region_allocator<shadow_region> shadow_allocator::shadow_module(
    (void *) 0,
    (void *) 0
);



#endif /* cfi_CFI_REGION_ALLOCATOR_HPP_ */
