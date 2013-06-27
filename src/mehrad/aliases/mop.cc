
#include <string.h>
#include <cstdio>
#include <cstddef>
#include <stdint.h>
#include <type_traits>


typedef bool K_Bool;
typedef unsigned long __kernel_ulong_t;
typedef long __kernel_long_t;
typedef size_t __kernel_size_t;

#   define __fswab32(...) __VA_ARGS__
#   define __fswab64(...) __VA_ARGS__
#   define __fswab16(...) __VA_ARGS__

extern "C" {
#   define volatile 
#   define const
#   define __attribute__(...)
#   include "kernel_types_latest.hpp"
#   undef __attribute__
#   undef const
#   undef volatile
}


enum {
    NUM_BITS = 8
};

struct bit_range {
    unsigned begin;
    unsigned end;

    void update(unsigned byte_off, unsigned bit_off) {
        bit_off += byte_off * NUM_BITS;

        if(bit_off < begin) {
            begin = bit_off;
        }

        if(bit_off > end) {
            end = bit_off;
        }
    }
};

bit_range get_bit_range(unsigned char *bytes, unsigned num_bytes) {
    bit_range r = {num_bytes * NUM_BITS, 0};
    for(unsigned byte_off(0U); byte_off < num_bytes; ++byte_off) {
        for(unsigned bit_off(0U); bit_off < NUM_BITS; ++bit_off) {
            unsigned char mask = 1U << bit_off;
            if(bytes[byte_off] & mask) {
                r.update(byte_off, bit_off);
            }
        }
    }
    return r;
}

template <typename T>
struct placement_type {
    union {
        T val;
        unsigned char data[sizeof(T)];
    } u;
};

/// size of an array
template <typename T, const size_t LENGTH>
constexpr size_t array_size(T (&)[LENGTH]) throw() {
    return sizeof(T) * LENGTH;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// first inclusion, set up some templates
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define CAT__(x, y) x ## y
#define CAT_(x, y) CAT__(x, y)
#define CAT(x,y) CAT_(x, y)



#define DEF_FIELD(struct_type,field,id,is_first) \
    template <typename, bool=false, bool=false> struct set ## id; \
    template <typename T> \
    struct set ## id<T, true, false> { \
        static void set(T &dest, const T &source) { \
            memcpy(&(dest.field[0]), &(source.field[0]), array_size(dest.field)); \
        } \
    }; \
    template <typename T> \
    struct set ## id<T, false, true> { \
        static void set(T &dest, const T &source) { } \
    }; \
    template <typename T> \
    struct set ## id<T, false, false> { \
        static void set(T &dest, const T &source) { \
            dest.field = source.field; \
        } \
    };

#define DEF_TYPE(type, ID)
#define END_TYPE
#define BEGIN_MOP
#define END_MOP

#include "get_bit_ranges.cc"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// second inclusion, write the program
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#undef DEF_FIELD
#undef DEF_TYPE
#undef END_TYPE
#undef BEGIN_MOP
#undef END_MOP

template <typename T>
struct is_zero_sized_array {
    enum {
        value = false
    };
};

template <typename T>
struct is_zero_sized_array<T[0]> {
    enum {
        value = true
    };
};

static const char *python_bool[] = {
    "False",
    "True"
};

#define DEF_FIELD(struct_type, field, id, is_first) \
    { \
        placement_type<struct_type> data; \
        placement_type<struct_type> data_full; \
        typedef decltype(data.u.val.field) field_type; \
        typedef std::remove_all_extents<field_type>::type base_type; \
        enum { \
            IS_ARRAY = !!std::is_array<field_type>::value, \
            IS_ZERO_ARRAY = is_zero_sized_array<field_type>::value, \
            IS_VOLATILE = 0, \
            IS_POINTER = std::is_pointer<field_type>::value, \
            CAN_SPLIT = IS_VOLATILE || IS_POINTER \
        }; \
        memset(data.u.data, 0, sizeof data); \
        memset(data_full.u.data, ~0, sizeof data); \
        set ## id<struct_type, IS_ARRAY, IS_ZERO_ARRAY>::set(data.u.val, data_full.u.val); \
        bit_range r(get_bit_range(data.u.data, sizeof data)); \
        if(!IS_ZERO_ARRAY) { \
            printf("(\"%s\",%u,%u,%s,%u),", #field, r.begin, r.end, python_bool[CAN_SPLIT], id); \
        }\
    }

#define DEF_TYPE(type, id) \
    { \
        printf("    mop_type(\"%s\",%lu, %u,[", #type, sizeof(type), id);

#define END_TYPE \
        printf("])\n"); \
    }

#define BEGIN_MOP \
    int main(void) { \
        printf( \
            "from mop import *\n" \
            "def describe_types():\n" \
        );

#define END_MOP \
        printf(\
            "if \"__main__\" == __name__:\n" \
            "    mop_header()\n" \
            "    describe_types()\n" \
            "    mop_footer()\n" \
        ); \
        return 0; \
    }

#include "get_bit_ranges.cc"
