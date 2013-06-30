/*
 * slub_interface.h
 *
 *  Created on: 2013-06-06
 *      Author: akshayk
 */

#ifndef SLUB_INTERFACE_H_
#define SLUB_INTERFACE_H_

#include "cfi_defines.h"

enum {
    INTERFACE_KFREE = 0x0ULL,
    INTERFACE___KMALLOC,
    INTERFACE_FREE_PERCPU,
    INTERFACE___ALLOC_PERCPU,
    INTERFACE_KMEM_CACHE_ALLOC,
    INTERFACE_KMEM_CACHE_FREE,
    INTERFACE___KMALLOC_NODE,
    INTERFACE___KMALLOC_TRACK_CALLER,
    INTERFACE___KMALLOC_NODE_TRACK_CALLER,
    INTERFACE_KMEM_CACHE_ALLOC_NODE,
    INTERFACE___GET_FREE_PAGES,
    INTERFACE___FREE_PAGES
};


void *cfi_kmalloc(size_t size, gfp_t flags);

void cfi_kfree(const void *x);

void *cfi_kmem_cache_alloc(struct kmem_cache *s, gfp_t flags);

void cfi_kmem_cache_free(struct kmem_cache *s, void *x);

#endif /* SLUB_INTERFACE_H_ */
