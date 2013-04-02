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

#define MAX_WPOINT_COUNT 0x7FFF



extern "C" {
    __attribute__((noinline)) void debug_watchpoint(uint64_t index, uint64_t displacement, uint64_t index_part) {
        kern_printk("index : %lx, displacement : %lx, index_part : %lx\n", index, displacement, index_part);
        (void) index;
        (void) displacement;
        (void) index_part;
    }
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
    static void on(alias_meta *, T *) { }
};

/// default version of a memory write watchpoint
template <typename T, typename F>
struct watch_write {
public:
    template <typename V>
    static void on(alias_meta *, T *, V) { }
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

struct heap_meta {
    uint64_t base_address;
    uint64_t limmit;
} __attribute__((packed));


typedef struct alias_entry alias_entry;
/// represents an alias entry
struct alias_entry : alias_meta {
public:

    static atomic_region_allocator<alias_meta> entries;

    template <typename T>
    static alias_meta *allocate(T *address, unsigned long size) {
        alias_meta *entry(entries.allocate());
        entry->base_address = (uint64_t)address;
        entry->limit = (uint64_t)address + size;
        return entry;
    }
};

/// static initialize the alias entries
atomic_region_allocator<alias_meta> alias_entry::entries(
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
        alias_meta *entry(alias_entry::allocate<T>(ptr, 0));
        const uint64_t index(alias_entry::entries.offset_of(entry));
        const uint64_t displacement_part(ALIAS_ADDRESS_DISPLACEMENT_MASK & ((uint64_t) ptr));
        const uint64_t index_part(index << ALIAS_ADDRESS_INDEX_OFFSET);
       // DWP(entry, index_part, displacement_part);
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
        alias_meta *entry(alias_entry::allocate<T>(ptr, size));
        const uint64_t index(alias_entry::entries.offset_of(entry));
        const uint64_t displacement_part(ALIAS_ADDRESS_DISPLACEMENT_MASK & ((uint64_t) ptr));
        const uint64_t index_part(index << ALIAS_ADDRESS_INDEX_OFFSET);
      //  kern_printk(" base : %lx, limit : %lx, size : %lx", entry->base_address, entry->limit, size);
      //  DWP((uint64_t)entry, index_part, displacement_part);
        return (T *) ((index_part | displacement_part) & ALIAS_ADDRESS_ENABLED);
    }
}

/// get the meta information of a watchpoint; note: this assumes the address passed
/// in is indeed a watchpoint
template <typename T>
alias_meta *WATCHPOINT_META(T *ptr) throw() {
    unsigned index(0);
    uint64_t displacement(0);
    if(likely(ptr && decode_alias_address((uint64_t) ptr, index, displacement))) {
        return  alias_entry::entries[index];
    }
    return 0;
}

template <typename T>
void ADD_TYPELESS_WATCHPOINT(T *&ptr) throw() {
 /*   if(!ptr) {
        return ptr;
    }
*/
    ptr = (T*)((uint64_t)ptr /*& ALIAS_ADDRESS_ENABLED*/);
/*
    if(likely(is_alias_address((uint64_t) ptr))) {
        return ptr;
    } else {
        alias_meta *entry(alias_entry::allocate<T>(ptr, size));
        const uint64_t index(alias_entry::entries.offset_of(entry));
        const uint64_t displacement_part(ALIAS_ADDRESS_DISPLACEMENT_MASK & ((uint64_t) ptr));
        const uint64_t index_part(index << ALIAS_ADDRESS_INDEX_OFFSET);
        DWP((uint64_t)entry, index_part, displacement_part);
        return (T *) ((index_part | displacement_part) & ALIAS_ADDRESS_ENABLED);
    }
    ptr = to_alias_heap_address(ptr);*/
}

template <typename T>
void ADD_WATCHPOINT(T *&ptr) throw() {
    ptr = to_alias_address(ptr);
}

template <typename T>
void ADD_WATCHPOINT(T *&ptr, unsigned long size) throw() {
    ptr = to_alias_heap_address(ptr, size);
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
        static void on(alias_meta *meta, type *addr__) throw() { \
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
        static void on(alias_meta *meta, type *addr__, V) throw() { \
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
    void *get_watchpoint_meta(void *addr){

        return (void*)WATCHPOINT_META(addr);
    }
}


#endif /* DRK_CFI_ALIAS_HPP_ */

