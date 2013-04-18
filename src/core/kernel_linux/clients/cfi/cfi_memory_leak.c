/*
 * cfi_memory_leak.c
 *
 *  Created on: 2013-01-19
 *      Author: akshayk
 */

#include <linux/module.h>

#include "cfi_defines.h"
#include "cfi_utils.h"
#include "cfi_memory_leak.h"
#include "cfi_module.h"
#include "cfi_atomic_list.h"

extern struct hlist_head lc_objects[LC_TABLE_SIZE];
extern struct cfi_list_head atomic_sweep_list;

extern struct cfi_list_head module_alloc_list[2];


void
granary_lc_print_alloc_info(struct granary_lc_output *output, struct granary_lc_resource_info *info)
{
    static const char* fmt_common = "Address: 0x%p, size: %zu; stack trace of the allocation:";
    static const char* fmt_unknown = "Address: 0x%p, size: unknown; stack trace of the allocation:";

    char *buf = NULL;
    int len;

    BUG_ON(info == NULL);

    if (info->size != 0) {
        len = snprintf(NULL, 0, fmt_common, info->addr, info->size);
    }
    else {
        len = snprintf(NULL, 0, fmt_unknown, info->addr);
    }

    buf = kmalloc(len + 1, GFP_KERNEL);

    if (buf == NULL) {
        pr_warning("granary_lc_print_alloc_info(): not enough memory to prepare a message of size %d\n", len);
    }

    if (info->size != 0) {
        snprintf(buf, len + 1, fmt_common, info->addr, info->size);
    }
    else {
        snprintf(buf, len + 1, fmt_unknown, info->addr);
    }

    printk("%s\n", buf);
   // granary_print_string(output, GRANARY_UNFREED_ALLOC, buf);
    kfree(buf);

   // granary_print_stack_trace(output, GRANARY_UNFREED_ALLOC, &(info->stack_entries[0]), info->num_entries);

   /* if (similar_allocs != 0) {
        granary_print_u64(output, GRANARY_UNFREED_ALLOC, similar_allocs, "+%llu more allocation(s) with the same call stack.");
    }*/

   //granary_print_string(output, GRANARY_UNFREED_ALLOC, sep); /* separator */
}


static void
granary_print_allocs_stat(struct granary_leak_detect *lc)
{
    struct granary_lc_resource_info *ri_info = NULL;
    struct hlist_head *head = NULL;
    unsigned int i;

    if ( lc->total_leaks != 0)
        pr_warning("LeakCheck has detected possible memory leaks: \n");


    for (i = 0; i < GRANARY_RI_TABLE_SIZE; ++i) {
        head = &lc->allocs[i];
        if (!hlist_empty(head)) {
            ri_info = hlist_entry(head->first, struct granary_lc_resource_info, hlist);
            granary_lc_print_alloc_info(lc->output, ri_info);
        }
    }
}


struct granary_leak_detect *granary_leak_object_create(struct module *target){
    struct granary_leak_detect *lc_obj = NULL;

    lc_obj = kzalloc(sizeof(struct granary_leak_detect), GFP_KERNEL);
    if(lc_obj == NULL) {
    	printk("lc_obj is NULL : %s",__FUNCTION__);
    	//granary_debug_null_pointer();
        return NULL;
    }

    INIT_HLIST_NODE(&lc_obj->hlist);
    lc_obj->target = target;
    lc_obj->name = kstrdup(module_name(target), GFP_KERNEL);

    granary_print_module_info(lc_obj->output, target);
    return lc_obj;
}

struct granary_leak_detect *cfi_leak_object_init(struct module *target) {

    return NULL;
}

#if 0
struct granary_leak_detect *granary_lc_object_lookup(struct module *target)
{
    unsigned long irq_flags;
    struct granary_leak_detect *lc = NULL;
    struct granary_leak_detect *obj = NULL;
    struct hlist_head *head = NULL;
    struct hlist_node *node = NULL;
    unsigned long hash_index = 0;

    if (target == NULL)
        return NULL;

    spin_lock_irqsave(&lc_objects_lock, irq_flags);
    hash_index = get_hash_index((uint64_t)target, LC_HASH_BITS);
    head = &lc_objects[hash_index];

    hlist_for_each_entry(obj, node, head, hlist) {
        if (obj->target == target) {
            lc = obj;
            break;
        }
    }
    spin_unlock_irqrestore(&lc_objects_lock, irq_flags);
    //printk("inside  granary_lc_object_lookup: %lx, %lx,\n",  head, lc);
    //printk("lc_objects : %lx granary_lc_object_lookup : %lx, %lx\n", lc_objects, head, hash_index);
    return lc;
}
#endif
static struct granary_lc_resource_info *
resource_info_create(const void *addr, size_t size,
        const void *caller_address)
{
        struct granary_lc_resource_info *info;
        info = kzalloc(sizeof(*info), GFP_ATOMIC);
        if (info != NULL) {
                info->addr = addr;
                info->size  = size;
            /*    kedr_save_stack_trace(&(info->stack_entries[0]),
                        stack_depth,
                        &info->num_entries,
                        (unsigned long)caller_address);*/
                INIT_HLIST_NODE(&info->hlist);
        }
        return info;
}


static void
granary_handle_alloc_event(struct granary_leak_detect *lc, const void *addr, size_t size,
        const void *caller_address)
{
        struct granary_lc_resource_info *ri_info;
        struct hlist_head *head;
        struct hlist_head *ri_table = &lc->allocs[0];

        ri_info = resource_info_create(addr, size, caller_address);
        if (ri_info == NULL) {
                return;
        }

    	head = &ri_table[hash_ptr((void *)(ri_info->addr), GRANARY_RI_HASH_BITS)];
    	hlist_add_head(&ri_info->hlist, head);
    	++lc->total_allocs;
    	++lc->total_leaks;
}

static void
resource_info_destroy(struct granary_lc_resource_info *info)
{
	kfree(info);
}

static struct granary_lc_resource_info *
ri_find_and_remove(const void *addr, struct hlist_head *ri_table)
{
	struct hlist_head *head;
	struct granary_lc_resource_info *ri_info = NULL;
	struct granary_lc_resource_info *found = NULL;
	struct hlist_node *node = NULL;
	struct hlist_node *tmp = NULL;

	head = &ri_table[hash_ptr((void *)addr, GRANARY_RI_HASH_BITS)];
	hlist_for_each_entry_safe(ri_info, node, tmp, head, hlist) {
		if (ri_info->addr == addr) {
			hlist_del(&ri_info->hlist);
			found = ri_info;
			break;
		}
	}
	return found;
}

static int
find_and_remove_alloc(const void *addr, struct granary_leak_detect *lc)
{
	int ret = 0;
	struct granary_lc_resource_info *ri = NULL;

	WARN_ON(addr == NULL);

	ri = ri_find_and_remove(addr, &lc->allocs[0]);
	if (ri) {
		ret = 1;
		resource_info_destroy(ri);
		--lc->total_leaks;
	}
	return ret;
}

static void
granary_handle_free_event(struct granary_leak_detect *lc, const void *addr, size_t size,
        const void *caller_address)
{
        struct granary_lc_resource_info *ri_info;
        struct hlist_head *head;
        struct hlist_head *ri_table = &lc->allocs[0];

        ri_info = resource_info_create(addr, size, caller_address);

        if (ri_info == NULL) {
                return;
        }

    	if (!find_and_remove_alloc(ri_info->addr, lc)) {
    		++lc->total_bad_frees;
    	}
    	else {
    		resource_info_destroy(ri_info);
    	}
}

void
granary_lc_handle_alloc(struct module *mod, const void *addr, size_t size,
        const void *caller_address)
{

    unsigned long irq_flags;
    struct granary_leak_detect *lc = NULL;

    cfi_list_append(&module_alloc_list[CFI_ALLOC_WHITE_LIST], addr);
/*
    lc = granary_lc_object_lookup(mod);
	if (lc == NULL) {
		return;
	}

	spin_lock_irqsave(&top_half_lock, irq_flags);
	granary_handle_alloc_event(lc, addr, size, caller_address);
	spin_unlock_irqrestore(&top_half_lock, irq_flags);*/
}

void
granary_lc_handle_free(struct module *mod, const void *addr,
        const void *caller_address)
{
        unsigned long irq_flags;
        struct granary_leak_detect *lc;

        cfi_list_del_item(&module_alloc_list[CFI_ALLOC_WHITE_LIST], addr);

   //     lc = granary_lc_object_lookup(mod);
       // printk("-----%s----- : %lx\n",__FUNCTION__, lc);
        if (lc == NULL) {
                return;
        }

       // spin_lock_irqsave(&top_half_lock, irq_flags);
       // granary_handle_free_event(lc, addr, (size_t)(-1), caller_address);
       // spin_unlock_irqrestore(&top_half_lock, irq_flags);
}


void
granary_print_ld_stat(struct module *mod)
{
    printk("granary_print_ld_stat : %lx\n", mod);
    unsigned long irq_flags;
    struct granary_leak_detect *lc = NULL;

   // lc = granary_lc_object_lookup(mod);
    printk("-------------- : %lx\n", lc);
    if (lc == NULL) {
        return;
    }

   // spin_lock_irqsave(&top_half_lock, irq_flags);
   // granary_print_allocs_stat(lc);
   // spin_unlock_irqrestore(&top_half_lock, irq_flags);
}
