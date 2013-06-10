
/*
 * cfi_module.c
 *
 *  Created on: 2012-04-02
 *      Author: akshayk
 */


#include <linux/kthread.h>
#include <linux/fs.h>
#include <asm/thread_info.h>

#include "cfi_defines.h"
#include "cfi_module.h"
#include "symbols/symbol_get_addr.h"
#include "cfi_debug_log.h"
#include "cfi_thread.h"
#include "cfi_hashtable.h"
#include "dr_kernel_utils.h"
#include "cfi_atomic_list.h"
#include "kernel_globals.h"
#include "cfi_hotpatch.h"



extern unsigned long long shadow_module_start;
extern unsigned long long shadow_module_end;

unsigned long long descriptor_table_start;

/*Memleak declaration*/

#define DEFAULT_HASHTABLE_SIZE 0

struct cfi_list_head module_alloc_list[3] =     {{.head = NULL, .count = 0 },
                                                 {.head = NULL, .count = 0 },
                                                 {.head = NULL, .count = 0}};


struct hashtable_t  *module_alloc_hash[3];

DEFINE_HASHTABLE(alloc_pointer_hash);

DEFINE_HASHTABLE(kernel_pointer_hash);
DEFINE_HASHTABLE(kernel_variable_hash);
DEFINE_HASHTABLE(hash_percpu_pointers);

DEFINE_HASHTABLE(dynamic_wrapper_table);

CFI_LIST_DECLARE(module_global_list);
CFI_LIST_DECLARE(atomic_sweep_list);
CFI_LIST_DECLARE(watchpoint_scan_list);
CFI_LIST_DECLARE(list_collected_watchpoint);
CFI_LIST_DECLARE(kernel_leaked_watchpoints);

CFI_LIST_DECLARE(list_loaded_module);

//DEFINE_HASHTABLE(*kernel_pointer_hash);

struct file* logfile = NULL;

MODULE_LICENSE("Dual BSD/GPL");

void *shadow_pointer_init = NULL;
struct task_struct *sweep_task;

uint64_t flag_memory_snapshot = 0x1;

extern client_cache_info_t *cpu_client_cache;

extern void init_wrapper(void);


struct notifier_block module_load_nb = {
    .notifier_call = module_load_notifier,
    .next = NULL,
    .priority = -1,
};

void granary_fault(void)
{

}


int DRK_IS_RUNNING = 0;

#define _ 0x00

/// emulates a call to a CFI function (module_drk_interface). Unfortunately, we can't
/// call to a 64-bit address, and we don't want to clobber a register; so we call to the
/// next instruction (setting up the return address for module_drk_interface to calculate
/// the module address from), then push on the address of module_drk_interface, effectively
/// faking a new return address, then returning to that address; thus bringing us to
/// module_drk_interface as if we had called it directly.
const unsigned long SHADOW_CALL_SIZE = 11UL;
char SHADOW_CALL[] = {
    0xe8, 0x00, 0x00, 0x00, 0x00,       // call NEXT;
                                        // NEXT:
    0x68, _, _, _, _,                   // push module_drk_interface
    0xc3                                // retq
};

#undef _


typedef void *(vmalloc_area_type)(struct vm_struct *, gfp_t gfp_mask, pgprot_t prot);

typedef void *(vmalloc_node_range_type)(unsigned long size, unsigned long align,
										unsigned long start, unsigned long end, gfp_t gfp_mask,
										pgprot_t prot, int node, void *caller);
#if 0
void *shadow_page_alloc(unsigned long size, unsigned long va_start, unsigned long va_end) {
#ifdef LINUX_V2_6_32
    struct vm_struct *area;
    vmalloc_area_type *vmalloc_area = (vmalloc_area_type *) VMALLOC_AREA_ADDR;
#else
    vmalloc_node_range_type *vmalloc_node_range = (vmalloc_node_range_type *) VMALLOC_NODE_RANGE;
#endif
    if (!size)
        return NULL;
    size = PAGE_ALIGN(size);
    if (size > va_end - va_start)
        return NULL;

#ifdef LINUX_V2_6_32
    area = __get_vm_area(size, VM_ALLOC, va_start, va_end);
    if (!area)
        return NULL;

    return vmalloc_area(area, GFP_KERNEL | __GFP_HIGHMEM, PAGE_KERNEL_EXEC);
#else
    return vmalloc_node_range(size, /*VM_ALLOC*/1, va_start, va_end,
    								GFP_KERNEL | __GFP_HIGHMEM, PAGE_KERNEL_EXEC,
    								-1, __builtin_return_address(0));
#endif
}
#endif

typedef void* (vmodule_alloc)(unsigned long);

void *module_page_alloc(unsigned long size) {
    vmodule_alloc *module_alloc = (vmodule_alloc *) MODULE_ALLOC;
    void *start_address = NULL;
    size = PAGE_ALIGN(size);
    start_address = module_alloc(size);
    if(!start_address){
        granary_fault();
        return NULL;
    }
    shadow_module_start = (unsigned long long)start_address;
    shadow_module_end = (unsigned long long)start_address + size;
    return start_address;
}

void *module_descriptor_table_alloc(unsigned long size) {
    void *start_address;
    vmodule_alloc *module_alloc = (vmodule_alloc *) MODULE_ALLOC;
    size = PAGE_ALIGN(size);
    start_address = module_alloc(size);
    descriptor_table_start = (unsigned long long)start_address;
    return start_address;
}



static int __init
cfi_module_init(void) {
    unsigned int ret;
#if 0//def CONFIG_USING_WATCHPOINT
    unsigned long drk_interface_addr = (unsigned long) cfi_enter_module_from_shadow;

    shadow_pointer_init = shadow_page_alloc(MODULE_SHADOW_END_EXTENDED - MODULE_SHADOW_START - 4096, MODULE_SHADOW_START, MODULE_SHADOW_END_EXTENDED);

	if(shadow_pointer_init == NULL) {
	    printk("shadow alloc failed\n");
    }
#endif
#if 0
    SHADOW_CALL[6] = ((drk_interface_addr >> 0)     & 0xff);
    SHADOW_CALL[7] = ((drk_interface_addr >> 8)     & 0xff);
    SHADOW_CALL[8] = ((drk_interface_addr >> 16)    & 0xff);
    SHADOW_CALL[9] = ((drk_interface_addr >> 24)    & 0xff);
#endif
   	register_module_notifier(&module_load_nb);

   	ret = hashmap_init(DEFAULT_HASHTABLE_SIZE, &dynamic_wrapper_table);
   	if(ret != 0) {
   	    printk("dynamic wrapper is not initialized\n");
   	    return -1;
   	}

   	ret = hashmap_init(/*2*DEFAULT_HASHTABLE_SIZE*/128, &kernel_pointer_hash);
   	if(ret != 0) {
        printk("kernel objects hash is not initialized\n");
   	}

    ret = hashmap_init(DEFAULT_HASHTABLE_SIZE, &hash_percpu_pointers);
    if(ret != 0) {
        printk("kernel objects hash is not initialized\n");
    }


   	/* list of allocated pointers by the module*/
   	cfi_list_init(&module_alloc_list[CFI_ALLOC_WHITE_LIST]);
   	cfi_list_init(&module_alloc_list[CFI_ALLOC_GREY_LIST]);
   	cfi_list_init(&module_alloc_list[CFI_LOST_REFERENCE]);
   	cfi_list_init(&module_alloc_list[CFI_COLLECT_LIST]);

    cfi_list_init(&module_global_list);
   	cfi_list_init(&atomic_sweep_list);
   	cfi_list_init(&watchpoint_scan_list);
   	cfi_list_init(&list_collected_watchpoint);
   	cfi_list_init(&kernel_leaked_watchpoints);
   	cfi_list_init(&list_loaded_module);

   	init_wrapper();

#ifdef CLIENT_MEMORY_LEAK
   	/*sweep thread : it scans the rootset and finds the leaked memory*/
   	sweep_task = kthread_create(sweep_thread_init, NULL, "sweep-thread");
    if (!IS_ERR(sweep_task))
        wake_up_process(sweep_task);
    else
        WARN_ON(1);
#endif
    return 0;
}

static void __exit
cfi_module_exit(void)
{
    unregister_module_notifier(&module_load_nb);
    kfree((void*)flag_memory_snapshot);
    vfree(shadow_pointer_init);
}

module_init(cfi_module_init);
module_exit(cfi_module_exit);

