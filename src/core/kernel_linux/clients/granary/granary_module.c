
/*
 * cfi_module.c
 *
 *  Created on: 2012-04-02
 *      Author: akshayk
 */


#include "granary_module.h"
#include "../cfi/symbols/symbol_get_addr.h"

#include <asm/thread_info.h>

MODULE_LICENSE("Dual BSD/GPL");

void *shadow_pointer_init = NULL;

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

void *shadow_page_alloc(unsigned long size, unsigned long va_start, unsigned long va_end) {
    struct vm_struct *area;
    vmalloc_area_type *vmalloc_area = (vmalloc_area_type *) VMALLOC_AREA_ADDR;

    if (!size)
        return NULL;
    size = PAGE_ALIGN(size);
    if (size > va_end - va_start)
        return NULL;

    area = __get_vm_area(size, VM_ALLOC, va_start, va_end);
    if (!area)
        return NULL;

    return vmalloc_area(area, GFP_KERNEL | __GFP_HIGHMEM, PAGE_KERNEL_EXEC);
}


bool
granary_module_init(void) {
   // unsigned long drk_interface_addr = (unsigned long) cfi_enter_module_from_shadow;

    shadow_pointer_init = shadow_page_alloc(MODULE_SHADOW_END_EXTENDED - MODULE_SHADOW_START - 4096, MODULE_SHADOW_START, MODULE_SHADOW_END_EXTENDED);

	if(shadow_pointer_init == NULL) {
	    printk("shadow alloc failed\n");
    }

  //  SHADOW_CALL[6] = ((drk_interface_addr >> 0)     & 0xff);
  //  SHADOW_CALL[7] = ((drk_interface_addr >> 8)     & 0xff);
 //   SHADOW_CALL[8] = ((drk_interface_addr >> 16)    & 0xff);
  //  SHADOW_CALL[9] = ((drk_interface_addr >> 24)    & 0xff);

	/*unsigned long shadow_pages = 0;
	shadow_pages = (MODULE_SHADOW_END - MODULE_SHADOW_START)/(4*1024);*/
//   	register_module_notifier(&module_load_nb);
	/*register_page_fault_notifier(&page_fault_nb);*/
    return 0;
}

bool
granary_module_exit(void)
{
  //  unregister_module_notifier(&module_load_nb);
    vfree(shadow_pointer_init);
    /*unregister_page_fault_notifier(&page_fault_nb);*/
}

//module_init(cfi_module_init);
//module_exit(cfi_module_exit);

