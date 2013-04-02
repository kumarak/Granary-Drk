
/*
 * cfi_module.c
 *
 *  Created on: 2012-04-02
 *      Author: akshayk
 */


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


#include <linux/kthread.h>
#include <linux/fs.h>
#include <asm/thread_info.h>

/*Memleak declaration*/

struct cfi_list_head module_alloc_list[2] = {{ .head = NULL, .count = 0 }, {.head = NULL, .count = 0 }};


DEFINE_HASHTABLE(*alloc_pointer_hash);

DEFINE_HASHTABLE(*kernel_pointer_hash);
DEFINE_HASHTABLE(*module_watchpoint_map);
DEFINE_HASHTABLE(*local_symbol_table);
DEFINE_HASHTABLE(*kernel_variable_hash);

CFI_LIST_DECLARE(module_global_list);
CFI_LIST_DECLARE(atomic_sweep_list);
CFI_LIST_DECLARE(module_gc_free_list);
CFI_LIST_DECLARE(list_collected_watchpoint);
CFI_LIST_DECLARE(return_collected_watchpoint);

CFI_LIST_DECLARE(list_loaded_module);

//DEFINE_HASHTABLE(*kernel_pointer_hash);

struct file* logfile = NULL;

MODULE_LICENSE("Dual BSD/GPL");

void *shadow_pointer_init = NULL;
struct task_struct *sweep_task;

uint64_t flag_memory_snapshot = 0x1;

extern client_cache_info_t *cpu_client_cache;

extern void init_wrapper(void);

void granary_debug_null_pointer()
{

}

struct notifier_block module_load_nb = {
    .notifier_call = module_load_notifier,
    .next = NULL,
    .priority = -1,
};


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

void *shadow_page_alloc(unsigned long size, unsigned long va_start, unsigned long va_end) {
    struct vm_struct *area;
#ifdef LINUX_V2.6.32
    vmalloc_area_type *vmalloc_area = (vmalloc_area_type *) VMALLOC_AREA_ADDR;
#else
    vmalloc_node_range_type *vmalloc_node_range = (vmalloc_node_range_type *) VMALLOC_NODE_RANGE;
#endif
    if (!size)
        return NULL;
    size = PAGE_ALIGN(size);
    if (size > va_end - va_start)
        return NULL;

#ifdef LINUX_V2.6.32
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





static int __init
cfi_module_init(void) {
    unsigned long drk_interface_addr = (unsigned long) cfi_enter_module_from_shadow;

    shadow_pointer_init = shadow_page_alloc(MODULE_SHADOW_END_EXTENDED - MODULE_SHADOW_START - 4096, MODULE_SHADOW_START, MODULE_SHADOW_END_EXTENDED);

	if(shadow_pointer_init == NULL) {
	    printk("shadow alloc failed\n");
    }

    SHADOW_CALL[6] = ((drk_interface_addr >> 0)     & 0xff);
    SHADOW_CALL[7] = ((drk_interface_addr >> 8)     & 0xff);
    SHADOW_CALL[8] = ((drk_interface_addr >> 16)    & 0xff);
    SHADOW_CALL[9] = ((drk_interface_addr >> 24)    & 0xff);

	/*unsigned long shadow_pages = 0;
	shadow_pages = (MODULE_SHADOW_END - MODULE_SHADOW_START)/(4*1024);*/
   	register_module_notifier(&module_load_nb);
   	logfile = cfi_file_open("logfile.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU|S_IRWXG|S_IRWXO);
   	cfi_fprintf(logfile, "logfile \n");
   	printk("logfile : %lx", logfile);

   	//cpu_client_cache = kzalloc(/*dr_cpu_count() **/ sizeof(client_cache_info_t*), GFP_KERNEL);

   	/* list of allocated pointers by the module*/
   	cfi_list_init(&module_alloc_list[CFI_ALLOC_WHITE_LIST]);
   	cfi_list_init(&module_alloc_list[CFI_ALLOC_GRAY_LIST]);

    cfi_list_init(&module_global_list);
   	cfi_list_init(&atomic_sweep_list);
   	cfi_list_init(&module_gc_free_list);
   	cfi_list_init(&list_collected_watchpoint);
   	cfi_list_init(&return_collected_watchpoint);
   	cfi_list_init(&list_loaded_module);

   //	hashmap_init(128, &alloc_pointer_hash);
   	hashmap_init(128, &kernel_pointer_hash);
   	hashmap_init(1024, &module_watchpoint_map);
   	hashmap_init(1024, &local_symbol_table);
   	init_wrapper();
  // 	flag_memory_snapshot = kmalloc(sizeof(unsigned int), GFP_ATOMIC);

   	//*flag_memory_snapshot = 0x1;


/*    sweep_task = kthread_create(sweep_thread_init, NULL, "sweep-thread");
    if (!IS_ERR(sweep_task))
        wake_up_process(sweep_task);
    else
        WARN_ON(1);
*/
    granary_tracer_init();
	/*register_page_fault_notifier(&page_fault_nb);*/
    return 0;
}

static void __exit
cfi_module_exit(void)
{
    unregister_module_notifier(&module_load_nb);
    kfree(flag_memory_snapshot);
    vfree(shadow_pointer_init);
    /*unregister_page_fault_notifier(&page_fault_nb);*/
}

module_init(cfi_module_init);
module_exit(cfi_module_exit);

