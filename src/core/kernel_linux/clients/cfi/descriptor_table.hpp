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
    extern void *cfi_kfree(void *ptr);
    extern struct descriptor *descriptors_cache_alloc(void);
    extern void descriptors_cache_free(void *ptr);

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
    WP_ADDRESS_BASE                      = 0x0000800000000000ULL,
    WP_ADDRESS_MASK                      = 0x8000800000000000ULL,
};

#include "cfi_region_allocator.hpp"

#define MAX_COUNTER_INDEX 0x7FFFU
#define MAX_PARTIAL_INDEX 0xFFU

#define MAX_WATCHPOINTS 0x7F7F01ULL

struct leak_check_descriptor;

struct descriptor {
    uint64_t base_address;
    uint64_t limit;
    struct {
        uint32_t state;
        uint32_t index;
    };
    leak_check_descriptor *next;

} __attribute__((packed));

struct leak_check_descriptor {
    union {
        descriptor *leak_descriptor;
        volatile leak_check_descriptor *next;
    };
};

static descriptor* allocate(void) throw(){
    return descriptors_cache_alloc();
}

/// Free a watchpoint descriptor.
static void free(descriptor *ds) throw(){
    descriptors_cache_free((void*)ds);
}


struct destriptor_table_info{
    volatile struct leak_check_descriptor *allocated_head;
    volatile struct leak_check_descriptor *free_head[MAX_PARTIAL_INDEX];
    uint64_t max_counter_index[MAX_PARTIAL_INDEX];
    uint64_t count;
};

#define TABLE_SIZE 0x10000U*PAGE_SIZE


struct descriptor_table : leak_check_descriptor {
public:

    static atomic_region_allocator<leak_check_descriptor> entries;
    static destriptor_table_info table_info;

    static uint64_t max_active_index;

    static void init(){
        void *start_address = module_descriptor_table_alloc(TABLE_SIZE);
        void *end_address = (void*)((uint64_t)start_address + TABLE_SIZE);
        max_active_index = 0;
        table_info.count = 0;
        entries.init((void *) start_address, (void *) end_address);
        kern_printk("descriptor_table start : %llx : end %llx\n", start_address, end_address);
    }

    static uint64_t get_max_active_index(void){
        return max_active_index;
    }

    static leak_check_descriptor *get_allocated_head(void){
        return (leak_check_descriptor*)table_info.allocated_head;
    }

    static bool is_active_index(unsigned long index){
        leak_check_descriptor *descriptors(entries.get_index(index));
        if(descriptors->leak_descriptor != NULL) {
            if(descriptors->leak_descriptor->state & WP_DESCRIPTOR_ACTIVE)
                return 1;
        }
    }

    template<typename T>
    static leak_check_descriptor *get_next_free_descriptor(T *addr){
        leak_check_descriptor *descriptors = NULL;
        uint64_t p_index = ((uint64_t)addr & 0xFF00000ULL);
        p_index >>= 20;
        volatile struct leak_check_descriptor *oldval = NULL;
        volatile struct leak_check_descriptor *newval = NULL;
        if(NULL != table_info.free_head[p_index]){
            do {
                descriptors = (leak_check_descriptor*)table_info.free_head[p_index];
                oldval = table_info.free_head[p_index];
                newval = descriptors;
            }while(!__sync_bool_compare_and_swap(&(table_info.free_head[p_index]), oldval, newval));
        }
        return descriptors;
    }

    static bool collect_free_descriptor(unsigned long index){
        leak_check_descriptor *entry(entries.get_index(index));
        uint64_t oldval = 0x0ULL;
        uint64_t newval = 0x0ULL;
        free(entry->leak_descriptor);
        entry->leak_descriptor = NULL;
        add_to_free_list(entry, index);
        return 1;
    }

    static bool add_to_allocated_list(leak_check_descriptor *descriptors){
        volatile struct leak_check_descriptor *oldval = NULL;
        struct leak_check_descriptor *newval = NULL;
        newval = descriptors;

        do {
            oldval = table_info.allocated_head;
            descriptors->leak_descriptor->next = (leak_check_descriptor*)table_info.allocated_head;
        } while(!__sync_bool_compare_and_swap(&(table_info.allocated_head), oldval, newval));

        return 0;
    }


    static bool add_to_free_list(leak_check_descriptor *descriptors, unsigned int index){
        volatile struct leak_check_descriptor *oldval = NULL;
        struct leak_check_descriptor *newval = NULL;
        unsigned int p_index = (index & 0xFF);

        do {
            descriptors = (leak_check_descriptor*)table_info.free_head[p_index];
            oldval = table_info.free_head[p_index];
            newval = descriptors;
        } while(!__sync_bool_compare_and_swap(&(table_info.free_head[p_index]), oldval, newval));

        return 0;
    }


    static leak_check_descriptor *allocate(void *address, unsigned long size) {
        leak_check_descriptor *descriptors = get_next_free_descriptor(address);
        if(descriptors == NULL){
            uint64_t p_index = ((uint64_t)address & 0xFF00000ULL);
            p_index >>= 20;
            uint64_t index = table_info.max_counter_index[p_index];
            index <<= 0x8;
            index += p_index;
            descriptors = entries.get_index(index);
            table_info.max_counter_index[p_index]++;
            if(table_info.max_counter_index[p_index] > max_active_index){
                max_active_index = table_info.max_counter_index[p_index];
            }
        }
        if(entries.is_allocated(descriptors)){
            descriptors->leak_descriptor = ::allocate();
            descriptors->leak_descriptor->base_address = (uint64_t)address;
            descriptors->leak_descriptor->limit = (uint64_t)address + size;
            descriptors->leak_descriptor->state |= WP_DESCRIPTOR_ACTIVE;
            descriptors->leak_descriptor->index = entries.offset_of(descriptors);
            descriptors->leak_descriptor->next = NULL;
            add_to_allocated_list(descriptors);
            return descriptors;
        }else {
            kern_printk("descriptor is null\n");
            return NULL;
        }
    }
};


uint64_t descriptor_table::max_active_index = 0;
destriptor_table_info descriptor_table::table_info = {NULL, NULL, 0};
/// static initialize the alias entries
atomic_region_allocator<leak_check_descriptor> descriptor_table::entries(
    (void *) 0,
    (void *) 0
);

inline static bool is_watchpoint_address(uint64_t addr) {
    if((addr & WP_ADDRESS_MASK) == WP_ADDRESS_BASE)
        return !(addr & WP_ADDRESS_NOT_ENABLED);
    else
        return false;
}

inline static bool is_alias_address(uint64_t addr) {
    if((addr & WP_ADDRESS_MASK) == WP_ADDRESS_BASE)
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
    unsigned p_index, c_index;
    if(is_watchpoint_address(addr)) {
        c_index = (addr & WP_ADDRESS_INDEX_MASK) >> WP_ADDRESS_INDEX_OFFSET;
        p_index = (addr & 0xFF00000ULL) >> 20;
        entry_index = (c_index << 0x8) | p_index;
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
        leak_check_descriptor *entry(descriptor_table::allocate((void*)ptr, 0));
        uint64_t index(descriptor_table::entries.offset_of(entry));
        index = index >> 0x8;
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
        leak_check_descriptor *entry(descriptor_table::allocate((void*)ptr, size));
        if(entry != NULL) {
            uint64_t index(descriptor_table::entries.offset_of(entry));
            index = index >> 0x8;
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
                leak_check_descriptor *ds = descriptor_table::entries.get_index(index);
                return ds->leak_descriptor;
            }
        }
    }
    return 0;
}

leak_check_descriptor *DESCRIPTOR_HEAD(void) throw() {
    return  descriptor_table::get_allocated_head();
}

template <typename T>
bool COLLECT_WATCHPOINT(T *ptr) throw() {
    unsigned index(0);
    uint64_t displacement(0);
    if(likely(ptr && decode_watchpoint_address((uint64_t) ptr, index, displacement))) {
        if(descriptor_table::is_active_index(index)) {
            leak_check_descriptor *ds = descriptor_table::entries.get_index(index);
            descriptor *meta_info = ds->leak_descriptor;
            meta_info->base_address = 0;
            meta_info->limit = 0;
            descriptor_table::collect_free_descriptor(index);
        }
    }
    return 1;
}

bool COLLECT_DESCRIPTOR(uint64_t index) throw() {
    if(descriptor_table::is_active_index(index)) {
        leak_check_descriptor *meta_info = descriptor_table::entries.get_index(index);
        descriptor_table::collect_free_descriptor(index);
    }
    return 1;
}

template <typename T>
unsigned int GET_DESCRIPTOR_INDEX(T *ptr) throw() {
    unsigned index(0);
    uint64_t displacement(0);
    if(likely(ptr && decode_watchpoint_address((uint64_t) ptr, index, displacement))) {
        if(descriptor_table::is_active_index(index)) {
            return index;
        }
    }
    return 0;
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
inline T *to_watched_percpu_address(T *ptr, unsigned long size) throw() {
    if(!ptr) {
        return ptr;
    }

 /*   if(likely(is_watchpoint_address((uint64_t) ptr))) {
        return ptr;
    } else*/ {
        leak_check_descriptor *entry(descriptor_table::allocate((void*)ptr, size));
        if(entry != NULL) {
            const uint64_t index(descriptor_table::entries.offset_of(entry));
            const uint64_t displacement_part(WP_ADDRESS_DISPLACEMENT_MASK & ((uint64_t) ptr));
            uint64_t index_part(index << WP_ADDRESS_INDEX_OFFSET);
            index_part++;
            return (T *) ((index_part | displacement_part) & WP_ADDRESS_ENABLED);
        } else {
            return ptr;
        }
    }
}

template <typename T>
void ADD_PERCPU_WATCHPOINT(T *&ptr, unsigned long size) throw() {
    if(descriptor_table::max_active_index < MAX_DESCRIPTOR_INDEX) {
        ptr = to_watched_percpu_address(ptr, size);
    }
}

template <typename T>
void REMOVE_PERCPU_WATCHPOINT(T *&ptr) throw() {
    if(descriptor_table::max_active_index < MAX_DESCRIPTOR_INDEX) {
        ptr = (T*)(0xffffffffffffULL & ((uint64_t) ptr));
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
        }else {
            kern_printk("index is not active\n");
        }
    }

    //return (T*)(WP_ADDRESS_INDEX_MASK | ((uint64_t) ptr));
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

    void *get_descriptor_head(uint64_t index){
        return (void*)DESCRIPTOR_HEAD();
    }

}


#endif /* DESCRIPTOR_TABLE_HPP_ */
