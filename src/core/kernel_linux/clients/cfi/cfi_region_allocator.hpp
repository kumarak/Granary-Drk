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
        void *start_address = module_page_alloc(2*PAGE_SIZE);
        void *end_address = start_address + 2*PAGE_SIZE;
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

#if 0
    static uint64_t get_max_active_index(void){
        return max_active_index;
    }
#if 1
    static unsigned long get_next_free_index(){
        uint64_t *base_ptr = 0x0ULL;
        uint64_t next_index = 0x0ULL;
        base_ptr = collected_watchpoints;
        uint64_t counter = 0;
        unsigned pos = 0;
        uint64_t mask = 0x0ULL;
        uint64_t base = 0x0ULL;
        uint64_t newval, oldval;

        base = (uint64_t)(*base_ptr);
        kern_printk("get_next_free_watchpoints : %llx\n", base);

        while((base & ALL_ONE_MASK) == ALL_ONE_MASK){
            counter += 64;
            base_ptr++;
            base = (uint64_t)*base_ptr;
        }

        for(; pos < 64; pos++) {
            mask = (0x1ULL << pos);
            if(!(mask & (uint64_t)base)) {
                oldval = base;
                newval = (base | mask);
                do {
                    oldval = base;
                }while(!__sync_bool_compare_and_swap(base_ptr, oldval, newval));
                break;
            }
        }

        //kern_printk("baseval : %llx, mask : %llx, newval : %llx, oldval : %llx\n", base, mask, newval, oldval);
        next_index = counter+pos;
        if(max_active_index < next_index) {
            max_active_index = next_index;
        }
        return next_index;

    }
#endif
#if 0
    static bool is_active_index(unsigned long index){
        uint64_t *base = (uint64_t*)collected_watchpoints;
        unsigned long offset = index/64;
        base = base+offset;
        unsigned pos = index%64;
        unsigned long mask = (0x1U << pos);
        if ((*(base) & mask) == mask){
            return 1;
        }

        return 0;
    }
#else
    static bool is_active_index(unsigned long index){
        watchpoint_descriptor *descriptor(entries.get_index(index));
        if(descriptor->state & WP_DESCRIPTOR_ACTIVE)
            return 1;
        else
            return 0;
    }
#endif
#if 0
    static bool collect_free_index(unsigned long index){
        uint64_t *base_ptr =  0x0ULL;
        base_ptr =  collected_watchpoints;
        unsigned long offset = index/64;
        base_ptr = base_ptr+offset;
        unsigned pos = index%64;
        uint64_t mask = (0x1ULL << pos);
        mask = ~mask;
        uint64_t base = *(base_ptr);
        uint64_t oldval = base;
        uint64_t newval = (oldval & mask);
        //kern_printk("index : %lx, base : %lx, newval : %lx, oldval : %lx\n", index, base, newval, oldval);
        do {
            oldval = base;
        }while(!__sync_bool_compare_and_swap(base_ptr, oldval, newval));

        return 1;
    }
#endif

    static watchpoint_descriptor * get_next_free_descriptor(void){
        watchpoint_descriptor *descriptor = NULL;
        volatile struct watchpoint_descriptor *oldval = NULL;
        volatile struct watchpoint_descriptor *newval = NULL;
        if(NULL != table_info.free_head){
            descriptor = (watchpoint_descriptor*)table_info.free_head;

            do {
                oldval = table_info.free_head;
                newval = table_info.free_head->next;
            } while(!__sync_bool_compare_and_swap(&(table_info.free_head), oldval, newval));

            descriptor->next = NULL;
        }
        return descriptor;

    }
    static bool collect_free_descriptor(unsigned long index){
        watchpoint_descriptor *entry(entries.get_index(index));
        uint64_t oldval = 0x0ULL;
        uint64_t newval = 0x0ULL;
        entry->index = index;
        entry->next = NULL;
        do {
            oldval = entry->state;
            newval = entry->state & (~WP_DESCRIPTOR_ACTIVE);
        } while(!__sync_bool_compare_and_swap(&(entry->state), oldval, newval));

        entry->state &= ~WP_DESCRIPTOR_ACTIVE;
        add_to_free_list(entry);
#ifdef CFI_DEBUG
        kern_printk("collected index : %lx\n", index);
#endif
        return 1;
    }

    static bool add_to_allocated_list(watchpoint_descriptor *descriptor){
        volatile struct watchpoint_descriptor *oldval = NULL;
        struct watchpoint_descriptor *newval = NULL;
        descriptor->next = table_info.allocated_head;

        do {
            oldval = table_info.allocated_head;
            newval = descriptor;
        } while(!__sync_bool_compare_and_swap(&(table_info.allocated_head), oldval, newval));

        return 0;
    }

    static bool add_to_free_list(watchpoint_descriptor *descriptor){
        volatile struct watchpoint_descriptor *oldval = NULL;
        struct watchpoint_descriptor *newval = NULL;
        descriptor->next = table_info.free_head;

        do {
            oldval = table_info.free_head;
            newval = descriptor;
        } while(!__sync_bool_compare_and_swap(&(table_info.free_head), oldval, newval));

        return 0;
    }

    template <typename T>
    static watchpoint_descriptor *allocate(T *address, unsigned long size) {
#if 1
        watchpoint_descriptor *descriptor = get_next_free_descriptor();
        if(descriptor == NULL){
            descriptor = entries.get_index(max_active_index);
            max_active_index++;
        }
        if(descriptor != NULL){
            descriptor->base_address = (uint64_t)address;
            descriptor->limit = (uint64_t)address + size;
            descriptor->next = NULL;
            descriptor->state |= WP_DESCRIPTOR_ACTIVE;
        }
        return descriptor;
#else
        unsigned long index = get_next_free_index();
        kern_printk("watchpoint number : %lx size : %lu\n", index, sizeof(watchpoint_descriptor));
       // watchpoint_descriptor *entry(entries.allocate());
        watchpoint_descriptor *entry(entries.allocate_index(index));
        kern_printk("meta_info address : %lx\n", entry);
        entry->base_address = (uint64_t)address;
        entry->limit = (uint64_t)address + size;
        entry->next = NULL;
        entry->state = 0x0ULL;
        entry->state |= WP_DESCRIPTOR_ACTIVE;
        return entry;
#endif
    }
#endif
};

atomic_region_allocator<shadow_region> shadow_allocator::shadow_module(
    (void *) 0,
    (void *) 0
);


#endif /* cfi_CFI_REGION_ALLOCATOR_HPP_ */
