/*
 * cfi_hotpatch.h
 *
 *  Created on: 2013-03-14
 *      Author: akshayk
 */

#ifndef CFI_HOTPATCH_H_
#define CFI_HOTPATCH_H_

#include "cfi_module.h"

#define CLIENT_CACHE_SIZE PAGE_SIZE

typedef struct {
    uint64 used_size;
    byte* cache_start;
    byte* cache_ptr;
    byte* cache_end;
} client_cache_info_t;


byte*
hijack_kernel_function(void *drcontext, client_cache_info_t *client,
                            byte *pc, app_pc src_addr, app_pc target_addr);

#endif /* CFI_HOTPATCH_H_ */
