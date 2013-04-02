/*
 * accessor.hpp
 *
 *  Created on: 2012-10-04
 *      Author: pag
 *     Version: $Id$
 */

#ifndef DRK_ACCESSOR_HPP_
#define DRK_ACCESSOR_HPP_

#if 0
#include <stdint.h>

extern "C" {
#   include "../types/kernel_types.hpp"
}

template <unsigned> struct uint_size;

#define MAKE_UINT_SIZE(size) \
    template <> \
    struct uint_size<size> { \
    public: \
        uint ## size ## _t val; \
    };

MAKE_UINT_SIZE(8)
MAKE_UINT_SIZE(16)
MAKE_UINT_SIZE(32)
MAKE_UINT_SIZE(64)

#ifndef FORCE_INLINE
#   if defined(__GNUC__) && ((__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 2)))
#      define FORCE_INLINE __attribute__((always_inline))
#   else
#     define FORCE_INLINE inline
#   endif
#endif


template <typename C, typename T, unsigned size, unsigned offset, unsigned bit_start, unsigned bit_end>
struct field_accessor {
public:
    C *container__;
    uint_size<size> raw_data__;
    /*
    T operator=(const T &&new_val__) throw() {

    }

    operator T(void) const throw() {

    }*/
};

template <unsigned, typename T, unsigned BitOpSize, unsigned ByteOffset>
struct generic_accessor;

template <typename OverlayedType, unsigned op_size>
struct generic_accessor_base {
public:

    typedef decltype(uint_size<op_size>().val) rd_type__;
    typedef OverlayedType o_type__;
    typedef field_accessor<OverlayedType, void *, op_size, 0, 0, 0> unsafe_accessor;

    FORCE_INLINE generic_accessor_base(rd_type__ raw_data_, o_type__* original_) {
        unsafe_accessor *self((unsafe_accessor *) this);
        self->container__ = original_;
        self->raw_data__.val = raw_data_;
    }

    FORCE_INLINE OverlayedType *operator->(void) {
        unsafe_accessor *self((unsafe_accessor *) this);
        return self->container__;
    }
};

#endif

#endif /* DRK_ACCESSOR_HPP_ */
