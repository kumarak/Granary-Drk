/*
 * cfi_notifier.c
 *
 *  Created on: 2012-04-08
 *      Author: akshayk
 */


#include <linux/string.h>
#include "cfi_module.h"
#include "cfi_wrapper.h"
#include "cfi_memory_leak.h"
#include "cfi_utils.h"
#include "cfi_atomic_list.h"
#include "cfi_hashtable.h"
#include "cfi_kernel_addresses.h"

#define MODULE_NAME "cfi"

extern struct pv_info pv_info ;

static DEFINE_MUTEX(load_mutex);
extern struct hashtable_t *local_symbol_table;

#ifndef SHF_MERGE
#define SHF_MERGE        (1 << 4)
#endif

unsigned long long module_text_start = 0;
struct module *target_module;
struct hlist_head lc_objects[LC_TABLE_SIZE];

extern struct cfi_list_head atomic_sweep_list;
extern struct cfi_list_head module_global_list;
extern struct cfi_list_head list_loaded_module;

typedef int (*mod_init_func_ptr)(void);

#if 0
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
#endif
static void set_page_attributes(
    int (*set_memory_)(unsigned long, int),
    void *begin,
    void *end
) {
    const uint64_t begin_pfn = PFN_DOWN(((uint64_t) begin));
    const uint64_t end_pfn = PFN_DOWN(((uint64_t) end));

    if(begin == end) {
        return;
    }

    if(end_pfn > begin_pfn) {
        set_memory_(begin_pfn << PAGE_SHIFT, end_pfn - begin_pfn);

    } else if(end_pfn == begin_pfn) {
        set_memory_(begin_pfn << PAGE_SHIFT, 1);
    }
}

void
on_module_load(struct module *vmod){
    set_page_attributes(
            set_memory_nx,
            vmod->module_core,
            vmod->module_core + vmod->core_text_size);

    set_page_attributes(
            set_memory_rw,
            vmod->module_core + vmod->core_text_size,
            vmod->module_core + vmod->core_text_size + (vmod->core_ro_size - vmod->core_text_size));

    set_page_attributes(
            set_memory_rw,
            vmod->module_init + vmod->init_text_size,
            vmod->module_init + vmod->init_text_size + (vmod->init_ro_size - vmod->init_text_size));

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

    switch(mod_state) {
    case MODULE_STATE_COMING:
        printk("module start address : %p\n", vmod);
        printk("module text start address : %p\n", mod->module_core);

        target_module = mod;
        mod->init = (mod_init_func_ptr) cfi_to_shadow_address(
            (cfi_type_erased_func_ptr) mod->init
        );

        for(i = 0; i < mod->core_num_syms; ++i) {
            if(SHF_ALLOC == mod->core_symtab[i].st_shndx) {
                mod->core_symtab[i].st_value = (long int) cfi_to_shadow_address(
                    (cfi_type_erased_func_ptr) mod->core_symtab[i].st_value
                );
            }else if((SHF_MERGE | SHF_WRITE) == mod->core_symtab[i].st_shndx ){
                cfi_list_append(&module_global_list, (void*)mod->core_symtab[i].st_value);
            }
        }

        /*doesn't record the cfi module*/
        cfi_list_append(&list_loaded_module, mod);

#if 0
        for(i=0; i < mod->num_symtab; i++){
        	dr_printf("module symbol : %lx; name : %s\n",mod->symtab[i].st_value, (mod->strtab + mod->symtab[i].st_name));
        }

        set_module_text_ro(mod);
#endif
        break;

    case MODULE_STATE_LIVE:
        if(!count) {
            // this module is granary
            granary_start = mod->module_core;
            granary_end = ((char *) mod->module_core) + mod->core_text_size;
        }
        ++count;


        if(strcmp(module_name(mod), MODULE_NAME)) {
        	printk("\nmodule name : %s\n", module_name(mod));
        	on_module_load(mod);
        }
        printk("module is loaded now\n");
        break;

    case MODULE_STATE_GOING:
        printk("module is getting unloaded\n");
        break;
    }
	return 0;
}


void
on_granary_target_load(struct module *mod)
{
    struct granary_leak_detect *lc = NULL;
    unsigned int irq_flags;
    struct hlist_head *head = NULL;
    unsigned long hash_index = 0;

    BUG_ON(mod == NULL);

	if (mutex_lock_killable(&load_mutex) != 0) {
		pr_warning("on_granary_target_load(): failed to lock mutex\n");
		return;
	}

    lc = granary_leak_object_create(mod);
	if (lc == NULL) {
		pr_warning("on_granary_target_load(): failed to create LeakCheck object for \"%s\"\n",
			module_name(mod));
		goto out;
	}

   // printk("lc object created : %lx\n", lc);

    spin_lock_irqsave(&lc_objects_lock, irq_flags);
    hash_index = hash_ptr(mod, LC_HASH_BITS);
    head = &lc_objects[hash_ptr(mod, LC_HASH_BITS)];
    hlist_add_head(&lc->hlist, head);
    spin_unlock_irqrestore(&lc_objects_lock, irq_flags);

out:
	mutex_unlock(&load_mutex);
	printk("lc_objects : %lx on_granary_target_load : %lx, %lx\n", lc_objects, head, hash_index);
	return;
}

void
on_granary_target_unload(struct module *mod)
{

}


void cfi_thread_slot_module_enrty(void)
{
    struct thread_private_info *thread_spill_slot;

    struct thread_info *thread = current_thread_info();
    register unsigned long current_stack_pointer asm("rsp");

    if(thread->spill_slot[0] == NULL){
        thread_spill_slot = kmalloc(sizeof(struct thread_private_info), GFP_ATOMIC);
        thread_spill_slot->stack = NULL;
        thread_spill_slot->is_running_module = 1;
        thread_spill_slot->section_count = 1;
        thread_spill_slot->stack = kmalloc(4*PAGE_SIZE, GFP_ATOMIC);
        thread_spill_slot->stack_start_address = thread;
        thread_spill_slot->copy_stack = 0;
        thread_spill_slot->current_stack = current_stack_pointer;
        thread->spill_slot[0] = thread_spill_slot;

        cfi_list_prepend(&atomic_sweep_list, thread_spill_slot);
    } else {
        thread_spill_slot = thread->spill_slot[0];
        thread_spill_slot->is_running_module = 1;
        thread_spill_slot->section_count++;
        thread_spill_slot->copy_stack = 0;
        thread_spill_slot->current_stack = current_stack_pointer;
    }

}

#define MODULE_SHADOW_OFFSET 0x20000000

static int
find_symbol_callback(struct kernsym *sym, const char *name,
                        struct module *mod, unsigned long addr) {

    if(sym->addr && (sym->addr == addr)){
        sym->name = name;
        sym->found = true;
        return 1;
    }

    return 0;
}

// find this symbol

#define SYM_NAME_LEN 128

bool is_kernel_code(void *addr){
    return (((uint64_t)addr >=  KERNEL_START_ADDR) && ((uint64_t)addr < KERNEL_END_ADDR));
}

static inline int in_module_init(unsigned long addr, struct module *mod)
{
    return (unsigned long)mod->module_init <= addr && addr < (unsigned long)mod->module_init + mod->init_size;
}

static inline int in_module_core(unsigned long addr, struct module *mod)
{
    return (unsigned long)mod->module_core <= addr && addr < (unsigned long)mod->module_core + mod->core_size;
}


int
print_module_symbol(void *mod, void*data){
    struct module *vmod = (struct module*)mod;
    unsigned int i = 0;

    if((in_module_init((uint64_t)data, mod)) || (in_module_core((uint64_t)data, mod))){
       // printk("module name : %s\n", module_name(mod));
        for(i=0; i < vmod->num_symtab; i++){
            if((vmod->symtab[i].st_value == (uint64_t)data) ||
                    (vmod->symtab[i].st_value == ((uint64_t)data +MODULE_SHADOW_OFFSET))){
               // printk("symbol address : %lx; name : %s\n",data, (vmod->strtab + vmod->symtab[i].st_name));
            }
        }
        return 1;
    }
    //printk("address not in module\n");
    return 0;
}

int
cfi_print_symbol_name(void *symbol_addr) {

    int ret;
    struct kernsym sym;
    void* value = NULL;
    char name[SYM_NAME_LEN];


    if(is_kernel_code(symbol_addr)){
        sym.addr = symbol_addr;
        ret = kallsyms_on_each_symbol((void *)find_symbol_callback, &sym);

        if(sym.found){
            //printk("kernel symbol : %lx , name : %s\n", sym.addr, sym.name);
        }
    } else {
        cfi_for_each_item(&list_loaded_module, print_module_symbol, (void*)symbol_addr);
    }
    return 0;
}
