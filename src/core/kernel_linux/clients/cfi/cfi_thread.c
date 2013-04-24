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

static inline uint64_t
cfi_item_update_base(void *ptr){
    struct alias_meta *meta_info;
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
}

bool func_module_alloclist(void *addr, void *data){
    printk("%lx\t", addr);
    return 0;
}

static inline
bool is_watchpoint(uint64_t value){
    if(!(value & ALIAS_ADDRESS_NOT_ENABLED) &&
            ((uint64_t)value > USER_ADDRESS_OFFSET)){
        uint64_t temp_value = (value & (~KERNEL_ADDRESS_OFFSET));
        if((temp_value > HEAP_START) && (temp_value < HEAP_END)){
            return true;
        }
    }
    return false;
}

static inline bool move_object_to_graylist(void *value){
   /* if(cfi_list_item_exist(&module_alloc_list[CFI_ALLOC_WHITE_LIST], value)){
        cfi_list_item_delete(&module_alloc_list[CFI_ALLOC_WHITE_LIST], value);
    }
*/
 /*   if(!cfi_list_item_exist(&module_alloc_list[CFI_ALLOC_GRAY_LIST], value)){
        cfi_list_append(&module_alloc_list[CFI_ALLOC_GRAY_LIST], value);
    }
*/
    return true;
}

static inline void
cfi_update_item_list(void){
    dr_printf("white list : ");
    cfi_list_item_print(&module_alloc_list[CFI_ALLOC_WHITE_LIST]);
    dr_printf("gray list : ");
    cfi_list_item_print(&module_alloc_list[CFI_ALLOC_GREY_LIST]);
}

void
cfi_scan_rootsets(void){
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

    global_list = module_global_list.head;
    spin_lock(&(module_global_list.list_lock));
    while(global_list != NULL){
        value = (uint64_t)(*(uint64_t*)(global_list->node));
        if(is_watchpoint(value)){
            cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], (void*)cfi_item_update_base(value));
        }
        global_list = global_list->next;
    }
    spin_unlock(&(module_global_list.list_lock));


    return_list = return_collected_watchpoint.head;
    spin_lock(&(return_collected_watchpoint.list_lock));
    while(return_list != NULL){
        value = (uint64_t)((uint64_t*)(return_list->node));
        if(is_watchpoint(value)){
            cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], (void*)cfi_item_update_base(value));
        }
        return_list = return_list->next;
    }
    spin_unlock(&(return_collected_watchpoint.list_lock));

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
                if(is_watchpoint(value)){
                    cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], (void*)cfi_item_update_base(value));
                }
                ptr++;
            }

            for(idx = 0; idx < 16; idx++){
                value = thread_private_slot->regs[idx];
                if(is_watchpoint(value)){
                    cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], (void*)cfi_item_update_base(value));
                }
            }
        }
        sweep_list = sweep_list->next;
    }
    spin_unlock(&(atomic_sweep_list.list_lock));



    alloc_scan_list = module_alloc_list[CFI_ALLOC_WHITE_LIST].head;
    spin_lock(&(module_alloc_list[CFI_ALLOC_WHITE_LIST].list_lock));
    while(alloc_scan_list != NULL){
        struct alias_meta *temp_meta;
        meta_info = (struct alias_meta *)get_watchpoint_meta((void*)alloc_scan_list->node);
        if(meta_info != NULL){
            ptr = (uint64_t*)meta_info->base_address;
            while(ptr <= meta_info->limit ){
                value = (uint64_t)(*(ptr));
                if(is_watchpoint(value)){
                    cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], (void*)cfi_item_update_base(value));
                }
                ptr++;
            }
        }
        alloc_scan_list = alloc_scan_list->next;
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
    while (!kthread_should_stop()){
        dr_printf("*******************************************************inside sweep_thread_init\n");
        preempt_disable();
        raw_local_irq_save(flags);
        do {
            local_flag = flag_memory_snapshot;
        }while(!__sync_bool_compare_and_swap(&flag_memory_snapshot, local_flag, 0x0));

        printk("white list count : %lx\n", cfi_get_list_count(&module_alloc_list[CFI_ALLOC_WHITE_LIST]));
        cfi_for_each_item(&module_alloc_list[CFI_ALLOC_WHITE_LIST], &func_module_alloclist, NULL);
        printk("\n");

        cfi_scan_rootsets();

        printk("grey list count : %lx\n", cfi_get_list_count(&module_alloc_list[CFI_ALLOC_GREY_LIST]));
        cfi_for_each_item(&module_alloc_list[CFI_ALLOC_GREY_LIST], &func_module_alloclist, NULL);
        printk("\n");
        cfi_list_delete_all(&module_alloc_list[CFI_ALLOC_GREY_LIST]);
        printk("\nkernel objects hashtable count : %lx\n", hashmap_get_item_count(kernel_pointer_hash));
        do {
            local_flag = flag_memory_snapshot;
        }while(!__sync_bool_compare_and_swap(&flag_memory_snapshot, local_flag, 0x1));
        raw_local_irq_restore(flags);
        preempt_enable();

        set_current_state(TASK_INTERRUPTIBLE);
        schedule_timeout(100*HZ/*00*/);
    }
    set_current_state(TASK_RUNNING);

    return 0;
}


void cfi_return_to_kernel(void *ptr){
    uint64_t value = (uint64_t)(ptr);
    struct alias_meta *meta_info;
    if((!((uint64_t)value & ALIAS_ADDRESS_NOT_ENABLED)) && ((uint64_t)value > USER_ADDRESS_OFFSET)){
        uint64_t temp_value = (value & (~KERNEL_ADDRESS_OFFSET));
        if((temp_value > HEAP_START) && (temp_value < HEAP_END)){
            cfi_list_append(&return_collected_watchpoint, (void*)cfi_item_update_base(value));
        }
    }
}

