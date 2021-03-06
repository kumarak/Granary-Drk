/*
 * granary_notifier.c
 *
 *  Created on: 2013-01-15
 *      Author: akshayk
 */



#include "granary_module.h"
#include "granary_wrapper.h"

#define MODULE_NAME "cfi"

unsigned long long module_text_start = 0;

typedef int (*mod_init_func_ptr)(void);

void set_page_attributes(void *start, void *end/*, int (*set)(unsigned long start, int num_pages)*/)
{
    unsigned long begin_pfn = PFN_DOWN((unsigned long)start);
    unsigned long end_pfn = PFN_DOWN((unsigned long)end);
    printk("--%s--\n", __FUNCTION__);

    if(end_pfn > begin_pfn)
    {
        printk("making the page execute protected\n");
        set_memory_nx(begin_pfn << PAGE_SHIFT, end_pfn - begin_pfn);

    } else if(end_pfn == begin_pfn)
    {
        set_memory_nx(begin_pfn << PAGE_SHIFT, 1);
    }
}

void set_module_text_ro(struct module *mod)
{
    if( (mod->module_core) && (mod->core_text_size))
    {
        set_page_attributes(mod->module_core, mod->module_core+mod->core_text_size/*, set_memory_nx*/);
    }
    if((mod->module_init) && (mod->init_text_size) )
    {
        set_page_attributes(mod->module_init, mod->module_init+mod->init_text_size/*, set_memory_nx*/);
    }
}

void *granary_start = 0, *granary_end = 0;
int cfi_is_granary_code(void *addr) {
    return granary_start <= addr && addr < granary_end;
}

int module_load_notifier(
    struct notifier_block *nb,
    unsigned long mod_state,
    void *vmod
) {
    int i = 0;
    static int count = 0;
    struct module *mod = (struct module *) vmod;

    printk("target name of the module : %s\n",module_name(mod));
    printk("module start address : %p\n", mod);
    printk("module text start address : %p\n", mod->module_core);

    module_text_start = mod->module_core;

    if(!strcmp(module_name(mod), "dynamorio_controller") || !strcmp(module_name(mod), "dr_kernel_utils") || !strcmp(module_name(mod), "cfi")) {
        printk("loading module is dynamorio_controller\n");
        return 0;
    }

    switch(mod_state) {
    case MODULE_STATE_COMING:
        printk("module start address : %p\n", vmod);
        printk("module text start address : %p\n", mod->module_core);
#if 1
        mod->init = (mod_init_func_ptr) cfi_to_shadow_address(
            (cfi_type_erased_func_ptr) mod->init
        );

        for(i = 0; i < mod->core_num_syms; ++i) {
            if(SHF_ALLOC == mod->core_symtab[i].st_shndx) {
                mod->core_symtab[i].st_value = (long int) cfi_to_shadow_address(
                    (cfi_type_erased_func_ptr) mod->core_symtab[i].st_value
                );
            }
        }
#endif
      //  set_module_text_ro(mod);
        break;

    case MODULE_STATE_LIVE:
        if(!count) {
            // this module is granary
            granary_start = mod->module_core;
            granary_end = ((char *) mod->module_core) + mod->core_text_size;
        }
        ++count;
        printk("module is loaded now\n");
        break;

    case MODULE_STATE_GOING:
        printk("module is getting unloaded\n");
        break;
    }
    return 0;
}


