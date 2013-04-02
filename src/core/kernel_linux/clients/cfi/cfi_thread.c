/*
 * cfi_thread.c
 *
 *  Created on: 2013-01-30
 *      Author: akshayk
 */

#include "cfi_defines.h"
#include "cfi_thread.h"
#include "cfi_atomic_list.h"
#include "cfi_hashtable.h"
#include "dr_kernel_utils.h"

#include <linux/kthread.h>
#include <linux/fs.h>
#include <asm/thread_info.h>
#include <linux/param.h>
#include <linux/sched.h>

extern struct hashtable_t *module_watchpoint_map;
extern struct hashtable_t *kernel_variable_hash;

#define KERNEL_ADDRESS_OFFSET       0xffff000000000000
#define USER_ADDRESS_OFFSET         0x00007fffffffffff

#define KERNEL_ADDRESS_OFFSET       0xffff000000000000
#define WATCHPOINT_ADDRESS_MASK     0x8000c00000000000
#define WATCHPOINT               0x800000000000

enum {
    ALIAS_ADDRESS_NOT_ENABLED               = 0x8000000000000000ULL,
    ALIAS_ADDRESS_ENABLED                   = ~ALIAS_ADDRESS_NOT_ENABLED, // high-order bit not set

    ALIAS_ADDRESS_INDEX_MASK                = 0xffff000000000000ULL,
    ALIAS_ADDRESS_INDEX_OFFSET              = (12 * 4),
    ALIAS_ADDRESS_DISPLACEMENT_MASK         = 0x0000ffffffffffffULL
};

#define HEAP_START  0x0000880000000000
#define HEAP_END    0x0000c0ffffffffff

struct alias_meta {

    uint64_t base_address;
    uint64_t limit;

} __attribute__((packed));


extern void *get_watchpoint_meta(void *addr);

inline bool is_watchpoint(uint64_t addr){
    if((addr & WATCHPOINT_ADDRESS_MASK) == WATCHPOINT)
        return true;//(reg_t)((uint64_t)addr | KERNEL_ADDRESS_OFFSET);
    else
        return false;
}


static int pp_block(char* dest, size_t size, const void* n)
{
    return snprintf(dest, size, "block_%s", *(const int*)n ? "in" : "out");
}

static void granary_trace_block(int n)
{
    granary_trace(pp_block, &n, sizeof(n));
}

extern struct hashtable_t *kernel_pointer_hash;
extern struct cfi_list_head module_alloc_list[2];
extern struct cfi_list_head module_global_list;
extern struct cfi_list_head module_gc_free_list;
extern struct cfi_list_head list_collected_watchpoint;
extern struct cfi_list_head return_collected_watchpoint;

typedef unsigned int (*scan_callback)(void *addr);

extern struct cfi_list_head atomic_sweep_list;
extern uint64_t flag_memory_snapshot;

void look_stack(uint64_t addr) {

}


static __inline__ void cfi_list_update_base(struct cfi_list_head *list_head)
{
    struct list_item *ptr;
    uint64_t index_part;
    uint64_t displacement_part;
    uint64_t value;
    struct alias_meta *meta_info;

    spin_lock(&(list_head->list_lock));
    ptr = list_head->head;
    while(ptr != NULL){
        meta_info = (struct alias_meta *)get_watchpoint_meta((void*)ptr->node);
        value = meta_info->base_address;
        displacement_part = (ALIAS_ADDRESS_DISPLACEMENT_MASK & ((uint64_t) value));
        index_part = (ALIAS_ADDRESS_INDEX_MASK & ((uint64_t)ptr->node));
        ptr->node = ((index_part | displacement_part) & ALIAS_ADDRESS_ENABLED);
        ptr = ptr->next;
    }
    spin_unlock(&(list_head->list_lock));
}

uint64_t cfi_item_update_base(void *ptr){
    struct alias_meta *meta_info;
#ifdef CFI_NO_WATCHPOINT
    hashmap_get(module_watchpoint_map, (void*)ptr, (void**)&meta_info);
    if(meta_info != NULL)
    	return meta_info->base_address;
    else
    	return ptr;
#else
    uint64_t index_part;
    uint64_t displacement_part;
    uint64_t value;
    meta_info = (struct alias_meta *)get_watchpoint_meta((void*)ptr);
    if(meta_info != NULL) {
        value = meta_info->base_address;
        displacement_part = (ALIAS_ADDRESS_DISPLACEMENT_MASK & ((uint64_t) value));
        index_part = (ALIAS_ADDRESS_INDEX_MASK & ((uint64_t)ptr));
        return (uint64_t)((index_part | displacement_part) & ALIAS_ADDRESS_ENABLED);
    }else {
        printk("%s : %lx, %lx\n", __FUNCTION__, ptr, meta_info);
        return ptr;
    }
#endif
}


void func_traverse_listitem(void *addr){
    uint64_t idx = 1;
    unsigned int flag = 0;

    struct list_item *list;
    uint64_t *stack_ptr;
    uint64_t value;
    struct thread_private_info *thread_private_slot = (struct thread_private_info*)addr;
    thread_private_slot->stack_start_address = (void*)((uint64_t)thread_private_slot->current_stack & 0xffffffffffffc000);
    uint64_t *stack_bottom = thread_private_slot->stack_start_address + 4*PAGE_SIZE-1;
    uint64_t *ptr = thread_private_slot->current_stack;

    list = module_alloc_list[CFI_ALLOC_WHITE_LIST].head;

    //spin_lock(&(module_alloc_list.list_lock));
    if(thread_private_slot != NULL) {
        while(list != NULL){
            flag = 0;
            while((ptr <= stack_bottom)) {
                value = (uint64_t)(*ptr);
                if((((uint64_t)value | KERNEL_ADDRESS_OFFSET) != value) && ((uint64_t)value > USER_ADDRESS_OFFSET)){
                    if(value == list->node){
                        flag = 1;
                        break;
                    }
                   // if(is_watchpoint(value)) {
                     //   look_stack(value);
                       // dr_printf("watchpoint address  list: stack : %lx  value %lx bottom : %lx\n", ptr, value, stack_bottom);
                    //}
                }
                ptr++;
            }
            for(idx = 0; idx < 16; idx++){
                value = thread_private_slot->regs[idx];
                if((((uint64_t)value | KERNEL_ADDRESS_OFFSET) != value) && ((uint64_t)value > USER_ADDRESS_OFFSET)){
                    if(value == list->node){
                        flag = 1;
                        break;
                    }
                   // if(is_watchpoint(value)) {
                       // look_stack(value);
                      //  dr_printf("watchpoint address  list: stack : %lx  value %lx bottom : %lx\n", ptr, value, stack_bottom);
                    //}
                }
            }

            //if(flag == 0){

            //}
            list = list->next;
        }
    }
    //spin_unlock(&(module_alloc_list.list_lock));

}

void func_module_alloclist(void *addr, void *data){
    printk(" %s : %lx\n", __FUNCTION__, addr);

}

void
function_scan_alloclist(void)
{
    uint64_t idx = 1;
    unsigned int flag = 0;

    struct list_item *alloc_list;
    struct list_item *sweep_list;
    struct list_item *global_list;
    struct list_item *return_list;
    struct list_item *alloc_scan_list;
    struct alias_meta *meta_info;

    uint64_t *stack_bottom;
    uint64_t *ptr;
    uint64_t *stack_ptr;
    uint64_t value;

    sweep_list = atomic_sweep_list.head;
    spin_lock(&(atomic_sweep_list.list_lock));
    while(sweep_list != NULL){
        struct thread_private_info *thread_private_slot = (struct thread_private_info*)(sweep_list->node);
        thread_private_slot->stack_start_address = (void*)((uint64_t)thread_private_slot->current_stack & 0xffffffffffffc000);
        stack_bottom = thread_private_slot->stack_start_address + 4*PAGE_SIZE-1;
        ptr = thread_private_slot->current_stack;

        if(thread_private_slot != NULL){
            while((ptr <= stack_bottom)) {
                value = (uint64_t)(*ptr);
#ifdef CFI_NO_WATCHPOINT
                if(hashmap_get(module_watchpoint_map, (void*)value, (void**)&meta_info)){
                	cfi_list_append(&list_collected_watchpoint, (void*)value);
                }
#else
                if((!((uint64_t)value & ALIAS_ADDRESS_NOT_ENABLED)) && ((uint64_t)value > USER_ADDRESS_OFFSET)){
                    uint64_t temp_value = (value & (~KERNEL_ADDRESS_OFFSET));
                    if((temp_value > HEAP_START) && (temp_value < HEAP_END)){
                        dr_printf("stack scan found : %lx\n", value);
                        cfi_list_append(&list_collected_watchpoint, (void*)cfi_item_update_base(value));
                    }
                }
#endif
                ptr++;
            }

            for(idx = 0; idx < 16; idx++){
                value = thread_private_slot->regs[idx];

#ifdef CFI_NO_WATCHPOINT
                if(hashmap_get(module_watchpoint_map, (void*)value, (void**)&meta_info)){
                	cfi_list_append(&list_collected_watchpoint, (void*)value);
                }
#else
                if((!((uint64_t)value & ALIAS_ADDRESS_NOT_ENABLED)) && ((uint64_t)value > USER_ADDRESS_OFFSET)){
                    uint64_t temp_value = (value & (~KERNEL_ADDRESS_OFFSET));
                    if((temp_value > HEAP_START) && (temp_value < HEAP_END)){
                        dr_printf("regs scan found : %lx\n", value);
                        cfi_list_append(&list_collected_watchpoint, (void*)cfi_item_update_base(value));
                    }
                }
#endif
            }
        }
        sweep_list = sweep_list->next;
    }
    spin_unlock(&(atomic_sweep_list.list_lock));

    global_list = module_global_list.head;

    spin_lock(&(module_global_list.list_lock));
    while(global_list != NULL){
        value = (uint64_t)(*(uint64_t*)(global_list->node));
        //if((((uint64_t)value | KERNEL_ADDRESS_OFFSET) != value) && ((uint64_t)value > USER_ADDRESS_OFFSET)){
#ifdef CFI_NO_WATCHPOINT
        if(hashmap_get(module_watchpoint_map, (void*)value, (void**)&meta_info)){
        	cfi_list_append(&list_collected_watchpoint, (void*)value);
        }
#else
        if((!((uint64_t)value & ALIAS_ADDRESS_NOT_ENABLED)) && ((uint64_t)value > USER_ADDRESS_OFFSET)){
            uint64_t temp_value = (value & (~KERNEL_ADDRESS_OFFSET));
            if((temp_value > HEAP_START) && (temp_value < HEAP_END)){
                dr_printf("global list found : %lx\n", value);
                cfi_list_append(&list_collected_watchpoint, (void*)cfi_item_update_base(value));
            }
        }
#endif
        global_list = global_list->next;
    }
    spin_unlock(&(module_global_list.list_lock));

    return_list = return_collected_watchpoint.head;

    spin_lock(&(return_collected_watchpoint.list_lock));
    while(return_list != NULL){
        value = (uint64_t)((uint64_t*)(return_list->node));
        //if((((uint64_t)value | KERNEL_ADDRESS_OFFSET) != value) && ((uint64_t)value > USER_ADDRESS_OFFSET)){
#ifdef CFI_NO_WATCHPOINT
        if(hashmap_get(module_watchpoint_map, (void*)value, (void**)&meta_info)){
        	cfi_list_append(&list_collected_watchpoint, (void*)value);
        }
#else
        if((!((uint64_t)value & ALIAS_ADDRESS_NOT_ENABLED)) && ((uint64_t)value > USER_ADDRESS_OFFSET)){
            uint64_t temp_value = (value & (~KERNEL_ADDRESS_OFFSET));
            if((temp_value > HEAP_START) && (temp_value < HEAP_END)){
                dr_printf("return collected found : %lx\n", value);
                cfi_list_append(&list_collected_watchpoint, (void*)value);
            }
        }
#endif
        return_list = return_list->next;
    }
    spin_unlock(&(return_collected_watchpoint.list_lock));


    alloc_scan_list = module_alloc_list[CFI_ALLOC_WHITE_LIST].head;

    spin_lock(&(module_alloc_list[CFI_ALLOC_WHITE_LIST].list_lock));
    while(alloc_scan_list != NULL){
    	struct alias_meta *temp_meta;
#ifdef CFI_NO_WATCHPOINT
    	hashmap_get(module_watchpoint_map, (void*)alloc_scan_list->node, (void**)&meta_info);
#else
    	meta_info = (struct alias_meta *)get_watchpoint_meta((void*)alloc_scan_list->node);
#endif
    	if(meta_info != NULL){
    		ptr = (uint64_t*)meta_info->base_address;
    		while(ptr <= meta_info->limit ){
    			value = (uint64_t)(*(ptr));
#ifdef CFI_NO_WATCHPOINT
    			if(hashmap_get(module_watchpoint_map, (void*)value, (void**)&temp_meta)){
    				cfi_list_append(&list_collected_watchpoint, (void*)cfi_item_update_base(value));
    			}
#else
    			//if((((uint64_t)value | KERNEL_ADDRESS_OFFSET) != value) && ((uint64_t)value > USER_ADDRESS_OFFSET)){
    			if((!((uint64_t)value & ALIAS_ADDRESS_NOT_ENABLED)) && ((uint64_t)value > USER_ADDRESS_OFFSET)){
    				uint64_t temp_value = (value & (~KERNEL_ADDRESS_OFFSET));
    				if((temp_value > HEAP_START) && (temp_value < HEAP_END)){
    				    dr_printf("module alloc list found : %lx\n", value);
    					cfi_list_append(&list_collected_watchpoint, (void*)cfi_item_update_base(value));
    				}
    			}
#endif
    			ptr++;
            }
        }
        alloc_scan_list = alloc_scan_list->next;
    }
    spin_unlock(&(module_alloc_list[CFI_ALLOC_WHITE_LIST].list_lock));

   // cfi_list_update_base(&list_collected_watchpoint);
   // cfi_list_item_print(&list_collected_watchpoint);
    //cfi_list_item_print(&module_alloc_list[CFI_ALLOC_WHITE_LIST]);

    spin_lock(&(module_alloc_list[CFI_ALLOC_WHITE_LIST].list_lock));
    alloc_list = module_alloc_list[CFI_ALLOC_WHITE_LIST].head;
    while(alloc_list != NULL)
    {
        if(!cfi_list_item_exist(&list_collected_watchpoint, alloc_list->node)){
            dr_printf("lost watchpoint addr : %lx, ", alloc_list->node);
        }
        alloc_list = alloc_list->next;
    }

    spin_unlock(&(module_alloc_list[CFI_ALLOC_WHITE_LIST].list_lock));
}

int htable_callback(void *data, const char *key, void *value){
    scan_callback fn= (scan_callback)value;
    //printk("key : %lx, value : %lx\n", key, value);
    if(fn != NULL)
    	fn(key);
    return 0;
}

unsigned int
sweep_thread_init(void *arg)
{
    int ret;
    unsigned long flags;
    unsigned long local_flag;
    printk("inside sweep_thread_init\n");
    while (!kthread_should_stop())
    {

        dr_printf("*******************************************************inside sweep_thread_init\n");
        preempt_disable();
        raw_local_irq_save(flags);
        do {
            local_flag = flag_memory_snapshot;
        }while(!__sync_bool_compare_and_swap(&flag_memory_snapshot, local_flag, 0x0));
        cfi_for_each_item(&module_alloc_list[CFI_ALLOC_WHITE_LIST], &func_module_alloclist, NULL);
        function_scan_alloclist();
       // cfi_for_each_item(&atomic_sweep_list, &func_traverse_listitem);
        //cfi_for_each_item(&module_alloc_list, &func_module_alloclist);
        //printk("---------\n");
        hashmap_iter(kernel_variable_hash, htable_callback, NULL);

        do {
            local_flag = flag_memory_snapshot;
        }while(!__sync_bool_compare_and_swap(&flag_memory_snapshot, local_flag, 0x1));
        raw_local_irq_restore(flags);
        preempt_enable();

        set_current_state(TASK_INTERRUPTIBLE);
        schedule_timeout(10*HZ/*00*/);
    }
    set_current_state(TASK_RUNNING);

    return 0;
}


void cfi_return_to_kernel(void *ptr){
    uint64_t value = (uint64_t)(ptr);
    struct alias_meta *meta_info;
#ifdef CFI_NO_WATCHPOINT
    if(hashmap_get(module_watchpoint_map, (void*)value, (void**)&meta_info)){
    	cfi_list_append(&return_collected_watchpoint, (void*)cfi_item_update_base(value));
    }
#else
    if((!((uint64_t)value & ALIAS_ADDRESS_NOT_ENABLED)) && ((uint64_t)value > USER_ADDRESS_OFFSET)){
        uint64_t temp_value = (value & (~KERNEL_ADDRESS_OFFSET));
        if((temp_value > HEAP_START) && (temp_value < HEAP_END)){
            cfi_list_append(&return_collected_watchpoint, (void*)cfi_item_update_base(value));
           // ptr = (void*)((uint64_t)ptr | ALIAS_ADDRESS_INDEX_MASK);
          //  REMOVE_WATCHPOINT(ptr);
            //printk("return watchpoint : %lx\n", value);
        }
    }
#endif
}

