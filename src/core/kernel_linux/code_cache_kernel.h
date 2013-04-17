/*
 * code_cache_kernel.h
 *
 *  Created on: 2013-04-14
 *      Author: akshayk
 */

#ifndef CODE_CACHE_KERNEL_H_
#define CODE_CACHE_KERNEL_H_

#include "../globals.h"
#include "../hashtable.h"


byte *
get_target_address(dcontext_t *dcontext, byte *pc);

void
code_cache_kernel_init(void);



#endif /* CODE_CACHE_KERNEL_H_ */
