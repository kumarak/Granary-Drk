/*
 * cfi_memory_leak.h
 *
 *  Created on: 2013-01-19
 *      Author: akshayk
 */

#ifndef CFI_MEMORY_LEAK_H_
#define CFI_MEMORY_LEAK_H_

#include <linux/list.h>
#include <linux/spinlock.h>
#include <linux/hash.h>


#define HASH_BITS 5
#define LC_TABLE_SIZE (1 << HASH_BITS)
#define STACK_MAX_FRAMES 16


#define GRANARY_RI_HASH_BITS   10
#define GRANARY_RI_TABLE_SIZE  (1 << GRANARY_RI_HASH_BITS)


//static DEFINE_SPINLOCK(lc_objects_lock);
//static DEFINE_SPINLOCK(top_half_lock);

struct granary_leak_detect {
    struct hlist_node hlist;
    struct module *target;
    char *name;
    struct granary_ld_output *output;

	/* The storage of resource info structures corresponding
	 * to the memory allocation events.
	 * Order of elements: last in - first found. */
	struct hlist_head allocs[GRANARY_RI_TABLE_SIZE];

    uint64_t total_allocs;
    uint64_t total_leaks;
    uint64_t total_bad_frees;
};


struct granary_lc_resource_info
{
        struct hlist_node hlist;

        /* The address of a resource in memory and the size of that
         *  resource. 'size' is (size_t)(-1) if the resource was freed
         * rather than allocated. */
        const void *addr;
        size_t size;

        /* Call stack */
        unsigned int num_entries;
        unsigned long stack_entries[STACK_MAX_FRAMES];
};


struct granary_leak_detect *granary_leak_object_create(struct module *target);
void granary_print_ld_stat(struct module *mod);


#endif /* CFI_MEMORY_LEAK_H_ */
