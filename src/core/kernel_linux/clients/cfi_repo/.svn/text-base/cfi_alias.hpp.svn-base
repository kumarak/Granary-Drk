/*
 * cfi_alias.hpp
 *
 *  Created on: 2012-09-30
 *      Author: pag
 *     Version: $Id$
 */

#ifndef DRK_CFI_ALIAS_HPP_
#define DRK_CFI_ALIAS_HPP_

#ifdef __GNUC__
#   define likely(x)       __builtin_expect((x),1)
#   define unlikely(x)     __builtin_expect((x),0)
#else
#   define likely(x)       (x)
#   define unlikely(x)     (x)
#endif

/// see http://www.mjmwired.net/kernel/Documentation/x86/x86_64/mm.txt
///
/// aliased addresses are placed in the 40-bit guard hole:
///         ffff800000000000 - ffff80ffffffffff (=40 bits) guard hole

enum {
    ALIAS_ADDRESS_SPACE_BEGIN               = 0xffff800000000000ULL,
    ALIAS_ADDRESS_SPACE_END                 = 0xffff80ffffffffffULL,
    ALIAS_ADDRESS_INDEX_MASK                = 0x000000ffff000000ULL,
    ALIAS_ADDRESS_INDEX_OFFSET              = (6 * 4),
    ALIAS_ADDRESS_DISPLACEMENT_MASK         = 0x0000000000ffffffULL
};

#include "cfi_region_allocator.hpp"

class read_tag { };
class write_tag { };

/// forward declaration
struct alias_entry_extension;

/// include the alias extension
#include "cfi_alias_extend.hpp"

/// basic types for different sized memory
typedef uint8_t     mem8_t;
typedef uint16_t    mem16_t;
typedef uint32_t    mem32_t;
typedef uint64_t    mem64_t;

union value {
    mem8_t val8;
    mem16_t val16;
    mem32_t val32;
    mem64_t val64;
};

enum value_size {
    SIZE_8 = 8U,
    SIZE_16 = 16U,
    SIZE_32 = 32U,
    SIZE_64 = 64U
};

/// generic memory selector for the correct type of different sized memory
/// based on the number of bits in that memory
template <unsigned num_bits>
struct mem_selectector_t;

template <> struct mem_selectector_t<8> { mem8_t val; };
template <> struct mem_selectector_t<16> { mem16_t val; };
template <> struct mem_selectector_t<32> { mem32_t val; };
template <> struct mem_selectector_t<64> { mem64_t val; };

/// forward declaration
template <typename T> struct alias_operations;

/// vtable of type-specific operations
struct memory_operations {
public:
    mem8_t  (*emulate_write8) (void *base, unsigned disp, mem8_t new_value);
    mem16_t (*emulate_write16)(void *base, unsigned disp, mem16_t new_value);
    mem32_t (*emulate_write32)(void *base, unsigned disp, mem32_t new_value);
    mem64_t (*emulate_write64)(void *base, unsigned disp, mem64_t new_value);

    mem8_t  (*emulate_read8) (void *base, unsigned disp);
    mem16_t (*emulate_read16)(void *base, unsigned disp);
    mem32_t (*emulate_read32)(void *base, unsigned disp);
    mem64_t (*emulate_read64)(void *base, unsigned disp);
};

/// basic emulation of a write to memory of some number of bits;
/// made to fit for any of the write operations of the memory_operations struct
template <unsigned num_bits>
DECLTYPE(mem_selectector_t<num_bits>().val)
emulate_write(
    void *base,
    unsigned disp,
    mem_selectector_t<num_bits> new_value
) throw() {
    mem8_t *ptr(&(((mem8_t *) base)[disp]));
    typedef DECLTYPE(new_value.val) value_t;
    const value_t old_val(new_value.val);
    *((value_t *) ptr) = new_value.val;
    return old_val;
}

/// basic emulation of a read from memory of some number of bits
/// made to fit for any of the read operations of the memory_operations struct
template <unsigned num_bits>
DECLTYPE(mem_selectector_t<num_bits>().val)
emulate_read(void *base, unsigned disp) throw() {
    mem8_t *ptr(&(((mem8_t *) base)[disp]));
    return ((mem_selectector_t<num_bits> *) ptr)->val;
}


/// represents an alias entry
///
///
struct alias_entry : public alias_entry_extension {
public:

    /// base address of a data structure
    void *base_address;

    /// vtable of operations on a specific type
    memory_operations *operations;

    /// reference counter for alias entries
    //volatile long long ref_count;

    static atomic_region_allocator<alias_entry> entries;

/*
    FORCE_INLINE void inc_ref(void) throw() {
        cfi_atomic_change((volatile mem_t *) &(this->ref_count), add_one);
    }

    FORCE_INLINE void dec_ref(void) throw() {
        cfi_atomic_change((volatile mem_t *) &(this->ref_count), subtract_one);
    }

    FORCE_INLINE void leaked(void) throw() {
        this->ref_count = 0xffffffffULL;
    }
*/
};

/// static initialize the alias antries
atomic_region_allocator<alias_entry> alias_entry::entries(/* TODO */);

/// decode an aliased address into its components
/// Returns false iff the address is not an aliased address.
FORCE_INLINE static bool decode_alias_address(
    uint64_t addr,
    unsigned &entry_index,
    unsigned &displacement
) {
    if(ALIAS_ADDRESS_SPACE_BEGIN <= addr && addr < ALIAS_ADDRESS_SPACE_END) {
        entry_index = (addr & ALIAS_ADDRESS_INDEX_MASK) >> ALIAS_ADDRESS_INDEX_OFFSET;
        displacement = (addr & ALIAS_ADDRESS_DISPLACEMENT_MASK);
        return true;
    } else {
        return false;
    }
}

/// convert a raw address to an alias address
template <typename T, typename... MetaArgs>
FORCE_INLINE T *to_alias_address(T *ptr, MetaArgs&&... meta_args) throw() {
    unsigned index(0);
    unsigned displacement(0);

    // already an aliased address
    if(likely(decode_alias_address((uint64_t) ptr, index, displacement))) {
        alias_entry *entry(alias_entry::entries[index]);
        //entry->inc_ref();
        return ptr;
    } else {
        alias_entry *entry(alias_entry::entries.allocate());
        entry->base_address = ptr;
        entry->type = id<T, alias_entry>::get();
    }
}

/// convert an aliased address into an unaliased address
/// if the se
template <typename T>
FORCE_INLINE T *to_unaliased_address(T *ptr /*, bool leaked=false */) throw() {
    unsigned index(0);
    unsigned displacement(0);

    // it's an alias entry
    if(likely(decode_alias_address((uint64_t) ptr, index, displacement))) {
        alias_entry *entry(alias_entry::entries[index]);

        /*if(likely(!leaked)) {
            entry->dec_ref();
        } else {
            entry->leaked();
        }*/

        const uint64_t addr((uint64_t) entry->base_address);
        return (T *) (addr + displacement);

    // not an aliased address
    } else {
        return ptr;
    }
}


#endif /* DRK_CFI_ALIAS_HPP_ */
