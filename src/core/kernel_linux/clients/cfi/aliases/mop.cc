
#include <cstring>
#include <cstdio>
#include <type_traits>

extern "C" {
#   include "types/kernel_types.hpp"
}

enum {
    NUM_BITS = 8
};

struct range {
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

range get_bit_range(unsigned char *bytes, unsigned num_bytes) {
    range r = {num_bytes * NUM_BITS, 0};
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

#define CAT_(x, y) x ## y
#define CAT(x,y) CAT_(x, y)

template <typename T>
struct transitive_is_volatile {
public:
    enum {
        value = false
    };
};

template <typename T>
struct transitive_is_volatile<volatile T> {
public:
    enum {
        value = true
    };
};

// non-first fields
#define DEF_FIELD_0(struct_type,field,field_id)

// first fields; try to propagate volatile-ness
#define DEF_FIELD_1(struct_type,field,field_id) \
    template <> \
    struct transitive_is_volatile<struct_type> { \
    public: \
        enum { \
            value = transitive_is_volatile<decltype(placement_type<struct_type>().u.val.field)>::value \
        }; \
    };


#define DEF_FIELD(struct_type,field,id,is_first) \
    CAT(DEF_FIELD_, is_first)(struct_type,field,id) \
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

#define DEF_TYPE(type)
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
            IS_VOLATILE = transitive_is_volatile<base_type>::value, \
            IS_POINTER = std::is_pointer<field_type>::value, \
            CAN_SPLIT = IS_VOLATILE || IS_POINTER \
        }; \
        memset(data.u.data, 0, sizeof data); \
        memset(data_full.u.data, ~0, sizeof data); \
        set ## id<struct_type, IS_ARRAY, IS_ZERO_ARRAY>::set(data.u.val, data_full.u.val); \
        range r(get_bit_range(data.u.data, sizeof data)); \
        if(!IS_ZERO_ARRAY) { \
            printf("(\"%s\",%u,%u,%s,%u),", #field, r.begin, r.end, python_bool[CAN_SPLIT], id); \
        }\
    }

#define DEF_TYPE(type) \
    { \
        printf("    mop_type(\"%s\",%lu,[", #type, sizeof(type));

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
