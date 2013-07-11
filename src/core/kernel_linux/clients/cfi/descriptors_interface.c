/*
 * descriptors_interface.c
 *
 *  Created on: 2013-06-24
 *      Author: akshayk
 */
#include "cfi_module.h"
#include "slub_interface.h"

static struct kmem_cache *descriptors_cachep;

int init_descriptors_cache(void){

    descriptors_cachep = kmem_cache_create("descriptors_cache",
                         sizeof(struct descriptor),
                         0, (SLAB_RECLAIM_ACCOUNT | SLAB_MEM_SPREAD),
                         NULL);
    printk("descriptors_cachep : %llx\n", descriptors_cachep);
    if (descriptors_cachep == NULL)
        return -ENOMEM;

    return 0;
}

int descriptors_init(){

    return 0;
}


struct descriptor
*descriptors_cache_alloc(void){
    struct descriptor *ds;

    ds = cfi_kmem_cache_alloc(descriptors_cachep, GFP_NOFS | GFP_NOIO);
    if (!ds)
        return NULL;
    return ds;
}


void
descriptors_cache_free(void *ptr){
    struct descriptor *ds = (struct descriptor*)(ptr);
    cfi_kmem_cache_free(descriptors_cachep, ds);
}


