/*
 * cfi_alias.hpp
 *
 *  Created on: 2012-09-30
 *      Author: pag
 *     Version: $Id$
 */

#ifndef DRK_CFI_ALIAS_HPP_
#define DRK_CFI_ALIAS_HPP_

#define CATCH_ALL(...)

#ifdef __GNUC__
#   define likely(x)       __builtin_expect((x),1)
#   define unlikely(x)     __builtin_expect((x),0)
#else
#   define likely(x)       (x)
#   define unlikely(x)     (x)
#endif

#define MAX_DESCRIPTOR_INDEX 0x7FFF



extern "C" {
    __attribute__((noinline)) void debug_watchpoint(uint64_t index, uint64_t displacement, uint64_t index_part) {
        kern_printk("index : %lx, displacement : %lx, index_part : %lx\n", index, displacement, index_part);
        (void) index;
        (void) displacement;
        (void) index_part;
    }
    extern void *cfi_get_free_pages(unsigned long count);

}

#define DWP(w, m, a) debug_watchpoint((w), (m), (a));

/// see http://www.mjmwired.net/kernel/Documentation/x86/x86_64/mm.txt
///
/// aliased addresses are placed in the 40-bit guard hole:
///        ffffc10000000000 - ffffc1ffffffffff (=40 bits) hole
enum {
    ALIAS_ADDRESS_NOT_ENABLED               = 0x8000000000000000ULL,
    ALIAS_ADDRESS_ENABLED                   = ~ALIAS_ADDRESS_NOT_ENABLED, // high-order bit not set

    ALIAS_ADDRESS_INDEX_MASK                = 0xffff000000000000ULL,
    ALIAS_ADDRESS_INDEX_OFFSET              = (12 * 4),
    ALIAS_ADDRESS_DISPLACEMENT_MASK         = 0x0000ffffffffffffULL
};

#include "cfi_region_allocator.hpp"
#include "aliases/meta.hpp"

/// forward declaration of the aliasing dispatcher (dispatches based on second
/// template argument)
template <bool, typename>
struct alias_dispatch;

/// default version of a memory read watchpoint
template <typename T, typename F>
struct watch_read {
public:
    static void on(watchpoint_descriptor *, T *) { }
};

/// default version of a memory write watchpoint
template <typename T, typename F>
struct watch_write {
public:
    template <typename V>
    static void on(watchpoint_descriptor *, T *, V) { }
};

struct alias_entry;

/// vtable of type-specific operations
struct memory_operations {
public:
    void (*watch_write8)(alias_entry *entry, uint64_t disp, uint8_t new_value);
    CATCH_ALL(void (*watch_write16)(alias_entry *entry, uint64_t disp, uint16_t new_value);)
    CATCH_ALL(void (*watch_write32)(alias_entry *entry, uint64_t disp, uint32_t new_value);)
    CATCH_ALL(void (*watch_write64)(alias_entry *entry, uint64_t disp, uint64_t new_value);)

    void (*watch_read8)(alias_entry *entry, uint64_t disp);
    CATCH_ALL(void (*watch_read16)(alias_entry *entry, uint64_t disp);)
    CATCH_ALL(void (*watch_read32)(alias_entry *entry, uint64_t disp);)
    CATCH_ALL(void (*watch_read64)(alias_entry *entry, uint64_t disp);)
};


/// default entries for that vtable
void dummy_watch_write8(alias_entry *, uint64_t, uint8_t) { }
CATCH_ALL(void dummy_watch_write16(alias_entry *, uint64_t, uint16_t) { })
CATCH_ALL(void dummy_watch_write32(alias_entry *, uint64_t, uint32_t) { })
CATCH_ALL(void dummy_watch_write64(alias_entry *, uint64_t, uint64_t) { })

void dummy_watch_read8(alias_entry *, uint64_t) { }
CATCH_ALL(void dummy_watch_read16(alias_entry *, uint64_t) { })
CATCH_ALL(void dummy_watch_read32(alias_entry *, uint64_t) { })
CATCH_ALL(void dummy_watch_read64(alias_entry *, uint64_t) { })

template <typename T>
struct type_operations {
    static const struct memory_operations operations;
};

template <typename T>
const struct memory_operations type_operations<T>::operations = {
    dummy_watch_write8,
    CATCH_ALL(dummy_watch_write16,)
    CATCH_ALL(dummy_watch_write32,)
    CATCH_ALL(dummy_watch_write64,)
    dummy_watch_read8,
    CATCH_ALL(dummy_watch_read16,)
    CATCH_ALL(dummy_watch_read32,)
    CATCH_ALL(dummy_watch_read64)
};


typedef unsigned char byte;
typedef struct alias_entry alias_entry;

#define ALL_ONE_MASK 0xffffffffffffffffULL

struct destriptor_table_info{
    volatile struct watchpoint_descriptor *allocated_head;
    volatile struct watchpoint_descriptor *free_head;
    uint64_t count;
};

#define COUNTER_INDEX 256
/// represents an alias entry
struct alias_entry : watchpoint_descriptor {
public:

    static atomic_region_allocator<watchpoint_descriptor> entries;
#ifdef USING_COUNTER_INDEX
    static destriptor_table_info table_info[COUNTER_INDEX];
    static uint64_t max_active_index[COUNTER_INDEX];
#else
    static destriptor_table_info table_info;

    static uint64_t* collected_watchpoints;
    static uint64_t max_active_index;
#endif
#ifdef USING_COUNTER_INDEX
    static void init(){
        unsigned int i = 0;
        while(i < COUNTER_INDEX){
            max_active_index[i] = 0;
            table_info[i].allocated_head = NULL;
            table_info[i].free_head = NULL;
            table_info[i].count = 0;
            i++;
        }

        entries.init();
    }
#else
    static void init(){
        collected_watchpoints = (uint64_t*)cfi_get_free_pages(2);
        max_active_index = 0;
        table_info.allocated_head = NULL;
        table_info.free_head = NULL;
        table_info.count = 0;
        entries.init();
        kern_printk("collected watchpoints : %lx\n", collected_watchpoints);
    }
#endif
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
};


uint64_t alias_entry::max_active_index = 0;
uint64_t *alias_entry::collected_watchpoints = NULL;
destriptor_table_info alias_entry::table_info = {NULL, NULL, 0};
/// static initialize the alias entries
atomic_region_allocator<watchpoint_descriptor> alias_entry::entries(
    (void *) MODULE_SHADOW_END,
    (void *) MODULE_SHADOW_END_EXTENDED
);

inline static bool is_alias_address(uint64_t addr) {
    if(addr != 0)
        return !(addr & ALIAS_ADDRESS_NOT_ENABLED);
    else
        return false;
}


/// decode an aliased address into its components
/// Returns false iff the address is not an aliased address.
inline static bool decode_alias_address(
        uint64_t addr,
        unsigned &entry_index,
        uint64_t &displacement
) {
    if(is_alias_address(addr)) {
        entry_index = (addr & ALIAS_ADDRESS_INDEX_MASK) >> ALIAS_ADDRESS_INDEX_OFFSET;
        displacement = (addr & ALIAS_ADDRESS_DISPLACEMENT_MASK) | ALIAS_ADDRESS_INDEX_MASK; // convert back into a raw address
        return true;
    } else {
        return false;
    }
}

/// convert a raw address to an alias address; note: this assumes that the address being
/// aliased points to the beginning of some data structure.
template <typename T>
inline T *to_alias_address(T *ptr) throw() {
    if(!ptr) {
        return ptr;
    }

    if(likely(is_alias_address((uint64_t) ptr))) {
        return ptr;
    } else {
        watchpoint_descriptor *entry(alias_entry::allocate<T>(ptr, 0));
        const uint64_t index(alias_entry::entries.offset_of(entry));
        const uint64_t displacement_part(ALIAS_ADDRESS_DISPLACEMENT_MASK & ((uint64_t) ptr));
        const uint64_t index_part(index << ALIAS_ADDRESS_INDEX_OFFSET);
        return (T *) ((index_part | displacement_part) & ALIAS_ADDRESS_ENABLED);
    }
}

/// convert a raw address to an alias address; note: this assumes that the address being
/// aliased points to the beginning of some data structure.
template <typename T>
inline T *to_alias_heap_address(T *ptr, unsigned long size) throw() {
    if(!ptr) {
        return ptr;
    }

    if(likely(is_alias_address((uint64_t) ptr))) {
        return ptr;
    } else {
        watchpoint_descriptor *entry(alias_entry::allocate<T>(ptr, size));
        const uint64_t index(alias_entry::entries.offset_of(entry));
        const uint64_t displacement_part(ALIAS_ADDRESS_DISPLACEMENT_MASK & ((uint64_t) ptr));
        const uint64_t index_part(index << ALIAS_ADDRESS_INDEX_OFFSET);
        return (T *) ((index_part | displacement_part) & ALIAS_ADDRESS_ENABLED);
    }
}

/// get the meta information of a watchpoint; note: this assumes the address passed
/// in is indeed a watchpoint
template <typename T>
watchpoint_descriptor *WATCHPOINT_META(T *ptr) throw() {
    unsigned index(0);
    uint64_t displacement(0);
    if(likely(ptr && decode_alias_address((uint64_t) ptr, index, displacement))) {
        if(alias_entry::is_active_index(index)) {
            return  alias_entry::entries.get_index(index);
        }
    }
    return 0;
}

template <typename T>
bool COLLECT_WATCHPOINT(T *ptr) throw() {
    unsigned index(0);
    uint64_t displacement(0);
    if(likely(ptr && decode_alias_address((uint64_t) ptr, index, displacement))) {
        if(alias_entry::is_active_index(index)) {
            watchpoint_descriptor *meta_info = alias_entry::entries.get_index(index);
            meta_info->base_address = 0;
            meta_info->limit = 0;
            alias_entry::collect_free_descriptor(index);
        }
    }
    return 1;
}

bool COLLECT_DESCRIPTOR(uint64_t index) throw() {
    if(alias_entry::is_active_index(index)) {
        watchpoint_descriptor *meta_info = alias_entry::entries.get_index(index);
        meta_info->base_address = 0;
        meta_info->limit = 0;
        alias_entry::collect_free_descriptor(index);
    }
    return 1;
}


uint64_t DESCRIPTORS_COUNT(void) throw() {
    return alias_entry::max_active_index;
}

template <typename T>
void* DESCRIPTOR_AT_INDEX(T index) throw() {
    if(alias_entry::is_active_index(index)) {
        return  alias_entry::entries.get_index(index);
    }
}

template <typename T>
void ADD_TYPELESS_WATCHPOINT(T *&ptr) throw() {
    (void)ptr;
}

template <typename T>
void ADD_WATCHPOINT(T *&ptr) throw() {
    if(alias_entry::max_active_index < MAX_DESCRIPTOR_INDEX) {
        ptr = to_alias_address(ptr);
    }
}

template <typename T>
void ADD_WATCHPOINT(T *&ptr, unsigned long size) throw() {
    if(alias_entry::max_active_index < MAX_DESCRIPTOR_INDEX) {
        ptr = to_alias_heap_address(ptr, size);
    }
}


/// convert an aliased address into an unaliased address
template <typename T>
inline T *to_unaliased_address(T *ptr) throw() {
    if(!ptr) {
        return ptr;
    }
    return (T*)(ALIAS_ADDRESS_INDEX_MASK | ((uint64_t) ptr));
}


template <typename T>
inline static bool IS_WATCHPOINT(T &val) {
    return is_alias_address((uint64_t) &val);
}

template <typename T>
bool IS_WATCHPOINT(T *&ptr) throw() {
    return is_alias_address((uint64_t) ptr);
}

template <typename T>
T* TO_UNWATCHED_ADDRESS(T *&ptr){
    return to_unaliased_address(ptr);
}

template <typename T>
void REMOVE_WATCHPOINT(T *&ptr) throw() {
    ptr = to_unaliased_address(ptr);
}

template <typename T>
void REMOVE_TYPELESS_WATCHPOINT(T *&ptr) throw() {
    ptr = to_unaliased_address(ptr);
}

void WRAPPER_INIT(){
   // byte* alias_entry::collected_watchpoints = NULL;
    alias_entry::init();
}

#define WATCH(type) \
    template <> \
    const struct memory_operations type_operations<type>::operations = { \
        alias_dispatch<true, type>::write8, \
        CATCH_ALL(alias_dispatch<true, type>::write16,) \
        CATCH_ALL(alias_dispatch<true, type>::write32,) \
        CATCH_ALL(alias_dispatch<true, type>::write64,) \
        alias_dispatch<true, type>::read8, \
        CATCH_ALL(alias_dispatch<true, type>::read16,) \
        CATCH_ALL(alias_dispatch<true, type>::read32,) \
        CATCH_ALL(alias_dispatch<true, type>::read64,) \
    };

#define WATCH_READ(type, field, code) \
    struct FIELD_ ## field; \
    template <> \
    struct watch_read<type, FIELD_ ## field > { \
    public: \
        static void on(watchpoint_descriptor *meta, type *addr__) throw() { \
            DECLTYPE(((type *) 0)->field) &field((addr__)->field); \
            code ; \
            (void) field; \
        } \
    };

#define WATCH_WRITE(type, field, code) \
    struct FIELD_ ## field; \
    template <> \
    struct watch_write<type, FIELD_ ## field > { \
    public: \
        template <typename V> \
        static void on(watchpoint_descriptor *meta, type *addr__, V) throw() { \
            DECLTYPE(((type *) 0)->field) &field((addr__)->field); \
            code ; \
            (void) field; \
        } \
    };

#define DEFINE_WRITE_EMULATOR(size) \
    void cfi_watch_write ## size (void *address, int ## size ## _t val) { \
        unsigned index(0); \
        uint64_t displacement(0); \
        if(likely(decode_alias_address((uint64_t) address, index, displacement))) { \
            alias_entry *entry(alias_entry::entries[index]); \
            return entry->operations->watch_write ## size(\
                entry, \
                displacement, \
                val \
            ); \
        } \
    }

#define DEFINE_READ_EMULATOR(size) \
    void cfi_watch_read ## size (void *address) { \
        unsigned index(0); \
        uint64_t displacement(0); \
        if(likely(decode_alias_address((uint64_t) address, index, displacement))) { \
            alias_entry *entry(alias_entry::entries[index]); \
            entry->operations->watch_read ## size(\
                entry, \
                displacement \
            ); \
        } \
    }

extern "C" {

    CATCH_ALL(DEFINE_WRITE_EMULATOR(8))
    CATCH_ALL(DEFINE_WRITE_EMULATOR(16))
    CATCH_ALL(DEFINE_WRITE_EMULATOR(32))
    CATCH_ALL(DEFINE_WRITE_EMULATOR(64))

    CATCH_ALL(DEFINE_READ_EMULATOR(8))
    CATCH_ALL(DEFINE_READ_EMULATOR(16))
    CATCH_ALL(DEFINE_READ_EMULATOR(32))
    CATCH_ALL(DEFINE_READ_EMULATOR(64))

}

extern "C" {

    extern void *cfi_get_free_pages(unsigned long count);

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


#endif /* DRK_CFI_ALIAS_HPP_ */

