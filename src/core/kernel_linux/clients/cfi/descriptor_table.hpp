/*
 * descriptor_table.hpp
 *
 *  Created on: 2013-05-17
 *      Author: akshayk
 */

#ifndef DESCRIPTOR_TABLE_HPP_
#define DESCRIPTOR_TABLE_HPP_


#define CATCH_ALL(...)

#ifdef __GNUC__
#   define likely(x)       __builtin_expect((x),1)
#   define unlikely(x)     __builtin_expect((x),0)
#else
#   define likely(x)       (x)
#   define unlikely(x)     (x)
#endif

typedef unsigned char byte;

#define ALL_ONE_MASK 0xffffffffffffffffULL
#define MAX_DESCRIPTOR_INDEX 0x7FFF



extern "C" {
    extern void *cfi_get_free_pages(unsigned long count);
    extern void *module_descriptor_table_alloc(unsigned long size);
    extern void *cfi_kmalloc(size_t size, gfp_t flags);

    extern function_t *wrapped_functions[];

}

/// see http://www.mjmwired.net/kernel/Documentation/x86/x86_64/mm.txt
///
/// non canonical addresses are used as watch points:

enum {
    WP_ADDRESS_NOT_ENABLED               = 0x8000000000000000ULL,
    WP_ADDRESS_ENABLED                   = ~WP_ADDRESS_NOT_ENABLED, // high-order bit not set

    WP_ADDRESS_INDEX_MASK                = 0xffff000000000000ULL,
    WP_ADDRESS_INDEX_OFFSET              = (12 * 4),
    WP_ADDRESS_DISPLACEMENT_MASK         = 0x0000ffffffffffffULL,
    WP_ADDRESS_BASE                      = 0x00007fffffffffffULL
};


#define GFP_ATOMIC 0x20U

#include "cfi_region_allocator.hpp"

#ifndef CONFIG_TRACER
struct descriptor {
    union {
        uint64_t base_address;
        uint64_t index;
    };
    uint64_t limit;
    uint64_t state;
    volatile struct descriptor *next;

} __attribute__((packed));
#else
struct descriptor {
    union {
        uint64_t base_address;
        uint64_t index;
    };
    uint64_t limit;
    uint64_t type_id;
    uint64_t state;
    uint64_t read_shadow;
    uint64_t write_shadow;
    uint64_t shadow_size;
    volatile struct descriptor *next;

} __attribute__((packed));
#endif

struct destriptor_table_info{
    volatile struct descriptor *allocated_head;
    volatile struct descriptor *free_head;
    uint64_t count;
};

#define COUNTER_INDEX 256

#define TABLE_SIZE 2048*PAGE_SIZE


struct descriptor_table : descriptor {
public:

    static atomic_region_allocator<descriptor> entries;
    static destriptor_table_info table_info;

    static uint64_t* collected_watchpoints;
    static uint64_t max_active_index;

    static void init(){
        collected_watchpoints = (uint64_t*)cfi_get_free_pages(2);
        void *start_address = module_descriptor_table_alloc(TABLE_SIZE);
        void *end_address = (void*)((uint64_t)start_address + TABLE_SIZE);
        max_active_index = 0;
        table_info.allocated_head = NULL;
        table_info.free_head = NULL;
        table_info.count = 0;
        entries.init((void *) start_address, (void *) end_address);
       // kern_printk("collected watchpoints : %lx\n", collected_watchpoints);
        kern_printk("descriptor_table start : %llx : end %llx\n", start_address, end_address);
    }

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
        descriptor *descriptors(entries.get_index(index));
        if(descriptors->state & WP_DESCRIPTOR_ACTIVE)
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

    static descriptor * get_next_free_descriptor(void){
        descriptor *descriptors = NULL;
        volatile struct descriptor *oldval = NULL;
        volatile struct descriptor *newval = NULL;
        if(NULL != table_info.free_head){
            descriptors = (descriptor*)table_info.free_head;

            do {
                oldval = table_info.free_head;
                newval = table_info.free_head->next;
            } while(!__sync_bool_compare_and_swap(&(table_info.free_head), oldval, newval));

            descriptors->next = NULL;
        }
        return descriptors;

    }
    static bool collect_free_descriptor(unsigned long index){
        descriptor *entry(entries.get_index(index));
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

        return 1;
    }

    static bool add_to_allocated_list(descriptor *descriptors){
        volatile struct descriptor *oldval = NULL;
        struct descriptor *newval = NULL;
        descriptors->next = table_info.allocated_head;

        do {
            oldval = table_info.allocated_head;
            newval = descriptors;
        } while(!__sync_bool_compare_and_swap(&(table_info.allocated_head), oldval, newval));

        return 0;
    }

    static bool add_to_free_list(descriptor *descriptors){
        volatile struct descriptor *oldval = NULL;
        struct descriptor *newval = NULL;
        descriptors->next = table_info.free_head;

        do {
            oldval = table_info.free_head;
            newval = descriptors;
        } while(!__sync_bool_compare_and_swap(&(table_info.free_head), oldval, newval));

        return 0;
    }

    template <typename T>
    static descriptor *allocate(T *address, unsigned long size) {
        descriptor *descriptors = get_next_free_descriptor();
        if(descriptors == NULL){
            descriptors = entries.get_index(max_active_index);
            max_active_index++;
        }
        if(entries.is_allocated(descriptors)){
            descriptors->base_address = (uint64_t)address;
            descriptors->limit = (uint64_t)address + size;
            descriptors->next = NULL;
            descriptors->state |= WP_DESCRIPTOR_ACTIVE;
            descriptors->type_id = 0;
            descriptors->shadow_size = (size/8)+1;
            descriptors->write_shadow = (uint64_t)cfi_kmalloc(descriptors->shadow_size, GFP_ATOMIC);
            memset((void*)descriptors->write_shadow, 0x0, descriptors->shadow_size);

            descriptors->read_shadow = (uint64_t)cfi_kmalloc(descriptors->shadow_size, GFP_ATOMIC);
            memset((void*)descriptors->read_shadow, 0x0, descriptors->shadow_size);

            return descriptors;
        }else {
            return NULL;
        }
    }
};


uint64_t descriptor_table::max_active_index = 0;
uint64_t *descriptor_table::collected_watchpoints = NULL;
destriptor_table_info descriptor_table::table_info = {NULL, NULL, 0};
/// static initialize the alias entries
atomic_region_allocator<descriptor> descriptor_table::entries(
    (void *) 0,
    (void *) 0
);

inline static bool is_watchpoint_address(uint64_t addr) {
    if(addr > WP_ADDRESS_BASE)
        return !(addr & WP_ADDRESS_NOT_ENABLED);
    else
        return false;
}

inline static bool is_alias_address(uint64_t addr) {
    if(addr > WP_ADDRESS_BASE)
        return !(addr & WP_ADDRESS_NOT_ENABLED);
    else
        return false;
}


/// decode an aliased address into its components
/// Returns false iff the address is not an aliased address.
inline static bool decode_watchpoint_address(
        uint64_t addr,
        unsigned &entry_index,
        uint64_t &displacement
) {
    if(is_watchpoint_address(addr)) {
        entry_index = (addr & WP_ADDRESS_INDEX_MASK) >> WP_ADDRESS_INDEX_OFFSET;
        displacement = (addr & WP_ADDRESS_DISPLACEMENT_MASK) | WP_ADDRESS_INDEX_MASK; // convert back into a raw address
        return true;
    } else {
        return false;
    }
}

/// convert a raw address to an alias address; note: this assumes that the address being
/// aliased points to the beginning of some data structure.
template <typename T>
inline T *to_watched_address(T *ptr) throw() {
    if(!ptr) {
        return ptr;
    }

    if(likely(is_watchpoint_address((uint64_t) ptr))) {
        return ptr;
    } else {
        descriptor *entry(descriptor_table::allocate<T>(ptr, 0));
        const uint64_t index(descriptor_table::entries.offset_of(entry));
        const uint64_t displacement_part(WP_ADDRESS_DISPLACEMENT_MASK & ((uint64_t) ptr));
        const uint64_t index_part(index << WP_ADDRESS_INDEX_OFFSET);
        return (T *) ((index_part | displacement_part) & WP_ADDRESS_ENABLED);
    }
}


template <typename T>
inline T *to_watched_heap_address(T *ptr, unsigned long size) throw() {
    if((uint64_t)ptr < WP_ADDRESS_BASE) {
        return ptr;
    }

    if(likely(is_watchpoint_address((uint64_t) ptr))) {
        return ptr;
    } else {
        descriptor *entry(descriptor_table::allocate<T>(ptr, size));
        if(entry != NULL) {
            const uint64_t index(descriptor_table::entries.offset_of(entry));
            const uint64_t displacement_part(WP_ADDRESS_DISPLACEMENT_MASK & ((uint64_t) ptr));
            const uint64_t index_part(index << WP_ADDRESS_INDEX_OFFSET);
            return (T *) ((index_part | displacement_part) & WP_ADDRESS_ENABLED);
        } else {
            return ptr;
        }
    }
}
#if 1//def CONFIG_USING_WATCHPOINT

template <typename T>
descriptor *WATCHPOINT_META(T *ptr) throw() {
    unsigned index(0);
    uint64_t displacement(0);
    if(!is_watchpoint_address((uint64_t)ptr)){
        return NULL;
    } else {
        if(likely(ptr && decode_watchpoint_address((uint64_t) ptr, index, displacement))) {
            if(descriptor_table::is_active_index(index)) {
                return  descriptor_table::entries.get_index(index);
            }
        }
    }
    return 0;
}

template <typename T>
bool COLLECT_WATCHPOINT(T *ptr) throw() {
    unsigned index(0);
    uint64_t displacement(0);
    if(likely(ptr && decode_watchpoint_address((uint64_t) ptr, index, displacement))) {
        if(descriptor_table::is_active_index(index)) {
            descriptor *meta_info = descriptor_table::entries.get_index(index);
            meta_info->base_address = 0;
            meta_info->limit = 0;
            descriptor_table::collect_free_descriptor(index);
        }
    }
    return 1;
}

bool COLLECT_DESCRIPTOR(uint64_t index) throw() {
    if(descriptor_table::is_active_index(index)) {
        descriptor *meta_info = descriptor_table::entries.get_index(index);
        meta_info->base_address = 0;
        meta_info->limit = 0;
        descriptor_table::collect_free_descriptor(index);
    }
    return 1;
}


uint64_t DESCRIPTORS_COUNT(void) throw() {
    return descriptor_table::max_active_index;
}

template <typename T>
void* DESCRIPTOR_AT_INDEX(T index) throw() {
    if(descriptor_table::is_active_index(index)) {
        return  descriptor_table::entries.get_index(index);
    }
    return NULL;
}

template <typename T>
void ADD_TYPELESS_WATCHPOINT(T *&ptr) throw() {
    (void)ptr;
}

template <typename T>
void ADD_WATCHPOINT(T *&ptr) throw() {
    if(descriptor_table::max_active_index < MAX_DESCRIPTOR_INDEX) {
        ptr = to_watched_address(ptr);
    }
}

template <typename T>
void ADD_WATCHPOINT(T *&ptr, unsigned long size) throw() {
    if(descriptor_table::max_active_index < MAX_DESCRIPTOR_INDEX) {
        ptr = to_watched_heap_address(ptr, size);
    }
}

template <typename T>
inline T *get_unwatched_address(T *ptr) throw() {
    unsigned index(0);
    uint64_t displacement(0);
    if((uint64_t)ptr < WP_ADDRESS_BASE) {
        return ptr;
    }
    if(likely(ptr && decode_watchpoint_address((uint64_t) ptr, index, displacement))) {
        if(descriptor_table::is_active_index(index)) {
            return (T*)(WP_ADDRESS_INDEX_MASK | ((uint64_t) ptr));
        }
    }

  //  return (T*)(WP_ADDRESS_INDEX_MASK | ((uint64_t) ptr));
    return ptr;
}


template <typename T>
inline static bool IS_WATCHPOINT(T &val) {
    return is_watchpoint_address((uint64_t) &val);
}

# if 0
template <typename T>
bool IS_WATCHPOINT(T *&ptr) throw() {
    return is_watched_address((uint64_t) ptr);
}
#endif

template <typename T>
T* TO_UNWATCHED_ADDRESS(T *&ptr){
    return get_unwatched_address(ptr);
}

template <typename T>
void REMOVE_WATCHPOINT(T *&ptr) throw() {
    ptr = get_unwatched_address(ptr);
}

template <typename T>
void REMOVE_TYPELESS_WATCHPOINT(T *&ptr) throw() {
    ptr = get_unwatched_address(ptr);
}
#else

#define WATCHPOINT_META(x) 0
#define COLLECT_WATCHPOINT(x)
#define DESCRIPTOR_AT_INDEX(x) 0
#define ADD_WATCHPOINT(x)
#define ADD_WATCHPOINT(x, size)
#define IS_WATCHPOINT(x) false
#define TO_UNWATCHED_ADDRESS(x) x
#define REMOVE_WATCHPOINT(x)
#define REMOVE_TYPELESS_WATCHPOINT(x)
#endif

void WRAPPER_INIT(){
    descriptor_table::init();
    shadow_allocator::init();
}

extern "C" {

    extern void *cfi_get_free_pages(unsigned long count);
    extern void *module_page_alloc(unsigned long size);

    void *get_watchpoint_meta(void *addr){

        return (void*)WATCHPOINT_META(addr);
    }

    void init_wrapper(void) {
        WRAPPER_INIT();
    }

    void wrapper_collect_watchpoint(void *addr){
        COLLECT_WATCHPOINT(addr);
    }

    void wrapper_collect_descriptor(uint64_t index){
        COLLECT_DESCRIPTOR(index);
    }

    uint64_t get_descriptors_count(void){
        return DESCRIPTORS_COUNT();
    }

    void *get_descriptor_at_index(uint64_t index){
        return DESCRIPTOR_AT_INDEX(index);
    }

}


#endif /* DESCRIPTOR_TABLE_HPP_ */
