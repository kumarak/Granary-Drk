/*
 * cfi_atomic.h
 *
 *  Created on: 2012-09-25
 *      Author: pag
 *     Version: $Id$
 */

#ifndef DRK_CFI_ATOMIC_H_
#define DRK_CFI_ATOMIC_H_

typedef unsigned long long mem_t;

/// atomically change the location
mem_t cfi_atomic_change(
    register volatile mem_t *addr,
    register mem_t (*next_value_func)(mem_t curr_value)
);

mem_t add_one(mem_t val);
mem_t subtract_one(mem_t val);
mem_t to_zero(mem_t val);
mem_t to_one(mem_t val);

#endif /* DRK_CFI_ATOMIC_H_ */
