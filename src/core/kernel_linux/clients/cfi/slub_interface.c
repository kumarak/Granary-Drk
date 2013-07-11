/*
 * slub_interface.c
 *
 *  Created on: 2013-06-06
 *      Author: akshayk
 */

#include <linux/types.h>
#include <linux/slab.h>
#include "slub_interface.h"

mem_allocator_t slub_allocator;

void *
cfi_kmem_cache_alloc_trace(struct kmem_cache *s, gfp_t gfpflags, size_t size)
{
        return slub_allocator.kmem_cache_alloc(s, gfpflags);
}

void *cfi_kmalloc(size_t size, gfp_t flags)
{
    if(slub_allocator.__kmalloc != NULL) {
        if (__builtin_constant_p(size)) {
            if (size > SLUB_MAX_SIZE)
                return kmalloc_large(size, flags);

            if (!(flags & SLUB_DMA)) {
                struct kmem_cache *s = kmalloc_slab(size);

                if (!s)
                    return ZERO_SIZE_PTR;

                return cfi_kmem_cache_alloc_trace(s, flags, size);
            }
        }
        return slub_allocator.__kmalloc(size, flags);
    } else {
        kmalloc(size, flags);
    }

}



void cfi_kfree(const void *x)
{
    if(slub_allocator.kfree != NULL) {
        slub_allocator.kfree(x);
    } else {
        kfree(x);
    }
}

void *cfi_kmem_cache_alloc(struct kmem_cache *s, gfp_t flags){
    if(slub_allocator.kmem_cache_alloc != NULL) {
        return slub_allocator.kmem_cache_alloc(s, flags);
    } else {
        return kmem_cache_alloc(s, flags);
    }
}

__always_inline
void cfi_kmem_cache_free(struct kmem_cache *s, void *x)
{
    if(slub_allocator.kmem_cache_free != NULL) {
        slub_allocator.kmem_cache_free(s, x);
    } else {
        kmem_cache_free(s, x);
    }
}
