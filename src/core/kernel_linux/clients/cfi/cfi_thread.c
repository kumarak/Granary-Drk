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
#include <linux/stop_machine.h>
#include "cfi_notifier.h"


#define KERNEL_ADDRESS_OFFSET       0xffff000000000000
#define USER_ADDRESS_OFFSET         0x00007fffffffffff

#define KERNEL_ADDRESS_OFFSET       0xffff000000000000
#define WATCHPOINT_ADDRESS_MASK     0x8000800000000000
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

struct watchpoint_descriptor {

    uint64_t base_address;
    uint64_t limit;
    uint64_t state;
    struct watchpoint_descriptor *next;

} __attribute__((packed));


extern void *get_watchpoint_meta(void *addr);
extern void wrapper_collect_watchpoint(void *addr);
extern void wrapper_collect_descriptor(uint64_t index);
extern uint64_t get_descriptors_count(void);
extern void *get_descriptor_at_index(uint64_t index);




extern struct hashtable_t *kernel_pointer_hash;
extern struct cfi_list_head module_alloc_list[2];
extern struct cfi_list_head module_global_list;
extern struct cfi_list_head watchpoint_scan_list;
extern struct cfi_list_head list_collected_watchpoint;
extern struct cfi_list_head list_collected_watchpoint_kernel;
extern struct cfi_list_head kernel_leaked_watchpoints;

extern struct kernel_module *list_loaded_modules;

typedef unsigned int (*scan_callback)(void *addr);

extern struct cfi_list_head atomic_sweep_list;
extern uint64_t flag_memory_snapshot;


void cfi_dump_stack(){
    struct thread_info *thread = current_thread_info();
    //printk("return address : %lx\n", thread->client_data.return_address_stack[thread->client_data.return_stack_size -1]);

    //dump_stack();
}

#if 0
static __inline__ void cfi_list_update_base(struct cfi_list_head *list_head)
{
    struct list_item *ptr;
    uint64_t index_part;
    uint64_t displacement_part;
    uint64_t value;
    struct watchpoint_descriptor *meta_info;

    spin_lock(&(list_head->list_lock));
    ptr = list_head->head;
    while(ptr != NULL){
        meta_info = (struct watchpoint_descriptor *)get_watchpoint_meta((void*)ptr->node);
        value = meta_info->base_address;
        displacement_part = (ALIAS_ADDRESS_DISPLACEMENT_MASK & ((uint64_t) value));
        index_part = (ALIAS_ADDRESS_INDEX_MASK & ((uint64_t)ptr->node));
        ptr->node = ((index_part | displacement_part) & ALIAS_ADDRESS_ENABLED);
        ptr = ptr->next;
    }
    spin_unlock(&(list_head->list_lock));
}
#endif

static inline uint64_t
cfi_item_update_base(void *ptr){
    struct watchpoint_descriptor *meta_info;
    uint64_t index_part;
    uint64_t displacement_part;
    uint64_t value;
    meta_info = (struct watchpoint_descriptor *)get_watchpoint_meta((void*)ptr);
    if((meta_info != NULL) && (meta_info >= MODULE_SHADOW_END ) && (meta_info < MODULE_SHADOW_END_EXTENDED)) {
        value = meta_info->base_address;
        displacement_part = (ALIAS_ADDRESS_DISPLACEMENT_MASK & ((uint64_t) value));
        index_part = (ALIAS_ADDRESS_INDEX_MASK & ((uint64_t)ptr));
        return (uint64_t)((index_part | displacement_part) & ALIAS_ADDRESS_ENABLED);
    }else {
        printk("%s : %lx, %lx\n", __FUNCTION__, ptr, meta_info);
        return NULL;
    }
}

static inline uint64_t
cfi_update_descriptor_state(void *ptr, uint64_t state){
    uint64_t index_part;
    uint64_t displacement_part;
    uint64_t value;
    struct watchpoint_descriptor *meta_info = (struct watchpoint_descriptor *)get_watchpoint_meta((void*)ptr);
    if((meta_info != NULL)
            && (meta_info >= MODULE_SHADOW_END )
            && (meta_info < MODULE_SHADOW_END_EXTENDED)
            && (meta_info->state & WP_MEMORY_ALLOCATED)) {

        uint64_t newval = 0x0ULL;
        uint64_t oldval = 0x0ULL;
        do {
            oldval = meta_info->state;
            newval = (meta_info->state | state/*| WP_MEMORY_FREED*/);
        }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
        //meta_info->state = meta_info->state | state;

        value = meta_info->base_address;
        displacement_part = (ALIAS_ADDRESS_DISPLACEMENT_MASK & ((uint64_t) value));
        index_part = (ALIAS_ADDRESS_INDEX_MASK & ((uint64_t)ptr));
        return (uint64_t)((index_part | displacement_part) & ALIAS_ADDRESS_ENABLED);
    }else {
        printk("%s : %lx, %lx\n", __FUNCTION__, ptr, meta_info);
        return NULL;
    }
}

bool func_module_alloclist(void *addr, void *data){
    printk("%lx\t", addr);
    return 0;
}

bool func_module_collectlist(void *addr, void *data){
    printk("%lx\t", addr);
    if(!cfi_list_item_exist(&module_alloc_list[CFI_ALLOC_GREY_LIST], addr)){
        wrapper_collect_watchpoint(addr);
    }
    return 0;
}

bool func_module_print_greylist(void *addr, void *data){
/*    struct watchpoint_descriptor *descriptor = (struct watchpoint_descriptor*)get_watchpoint_meta(addr);

    if(descriptor->state & WP_MEMORY_ALLOCATED){
        printk("%llx(alloclist)\t", addr);
    } else {
        printk("%llx \t", addr);
    }*/

    if(cfi_list_item_exist(&module_alloc_list[CFI_LOST_REFERENCE], ((void*)((uint64_t)addr /*| ALIAS_ADDRESS_INDEX_MASK*/)))){
        printk("%lx(this is lost watchpoint)\t", addr);
    } else if(!cfi_list_item_exist(&module_alloc_list[CFI_ALLOC_WHITE_LIST], ((void*)((uint64_t)addr /*| ALIAS_ADDRESS_INDEX_MASK*/)))) {
        printk("%lx(not in alloclist)\t", addr);
    } else {
        printk("%lx \t", addr);
    }
    return 0;
}

static inline
bool is_watchpoint(uint64_t value){
#if 0
    if((value & WATCHPOINT_ADDRESS_MASK) == WATCHPOINT){
        return true;
    }
#endif
#if 1
    if(!(value & ALIAS_ADDRESS_NOT_ENABLED) &&
            ((uint64_t)value > USER_ADDRESS_OFFSET)){
        uint64_t temp_value = (value & (~KERNEL_ADDRESS_OFFSET));
        if((temp_value > HEAP_START) && (temp_value < HEAP_END)){
            return true;
        }
    }
#endif
    return false;
}

void
cfi_collect_watcpoint(const void *src, const void *ptr){
    void* base_ptr = NULL;
    if(is_watchpoint((uint64_t)ptr)){
        base_ptr = cfi_update_descriptor_state(ptr, WP_MEMORY_REACHABLE);
        if (NULL != base_ptr) {
            printk("src (%lx) \t dest(%lx)\n", src, base_ptr);
            cfi_list_append(&kernel_leaked_watchpoints, base_ptr);
            cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], base_ptr);
        }
     }
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
    struct watchpoint_descriptor *meta_info;
    struct kernel_module *module_ptr;

    uint64_t stack_bottom;
    uint64_t *ptr = NULL;
    uint64_t *stack_ptr;
    uint64_t value;

    printk("scanning globals\n");
    module_ptr = list_loaded_modules;

    while(module_ptr != NULL){
        uint64_t *scan_ptr;
        printk("scanning data section\n");
        scan_ptr = module_ptr->data_begin;
        if(scan_ptr) {
            while(scan_ptr <= module_ptr->data_end){
                value = (uint64_t)(*scan_ptr);
                if(is_watchpoint(value)){
                    void *base = cfi_update_descriptor_state(value, WP_MEMORY_REACHABLE);
                    if(NULL != base){
                        printk("scanning data section src(%lx) : dest(%lx)\n", scan_ptr, base);
                        cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], base);
                    }
#if 0
                void *base_ptr = cfi_item_update_base(value);
                if(NULL != base_ptr) {
                    printk("scanning data section src(%lx) : dest(%lx)\n", scan_ptr, base_ptr);
                    cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], base_ptr);
                }
#endif
                }
                scan_ptr++;
            }
        }

        printk("scanning bss section\n");
        scan_ptr = module_ptr->bss_begin;
        if(scan_ptr){
            while(scan_ptr <= module_ptr->bss_end){
                value = (uint64_t)(*scan_ptr);
                if(is_watchpoint(value)){
                    void *base = cfi_update_descriptor_state(value, WP_MEMORY_REACHABLE);
                    if(NULL != base){
                        printk("scanning bss section src(%lx) : dest(%lx)\n", scan_ptr, base);
                        cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], base);
                    }
#if 0
                void *base_ptr = cfi_item_update_base(value);
                if(NULL != base_ptr) {
                    printk("scanning bss section src(%lx) : dest(%lx)\n", scan_ptr, base_ptr);
                    cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], base_ptr);
                };
#endif
                }
                scan_ptr++;
            }
        }

        module_ptr = module_ptr->next;
    }

    global_list = module_global_list.head;
    spin_lock(&(module_global_list.list_lock));
    while(global_list != NULL){
        value = (uint64_t)(*(uint64_t*)(global_list->node));
        if(is_watchpoint(value)){
            void *base = cfi_update_descriptor_state(value, WP_MEMORY_REACHABLE);
            if(NULL != base){
                printk("scanning global objects : %lx\n", base);
                cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], base);
            }
#if 0
            void *base_ptr = cfi_item_update_base(value);
            if(NULL != base_ptr) {
                printk("scanning global objects : %lx\n", base_ptr);
                cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], base_ptr);
            }
#endif
        }
        global_list = global_list->next;
    }
    spin_unlock(&(module_global_list.list_lock));

    sweep_list = atomic_sweep_list.head;
    spin_lock(&(atomic_sweep_list.list_lock));
    while(sweep_list != NULL){
        struct thread_private_info *thread_private_slot = (struct thread_private_info*)(sweep_list->node);
        thread_private_slot->stack_start_address = (void*)((uint64_t)thread_private_slot->current_stack & 0xffffffffffffc000);
        stack_bottom = (uint64_t)(thread_private_slot->stack_start_address + THREAD_SIZE-1);
        ptr = thread_private_slot->current_stack;

        if(thread_private_slot != NULL){

            if(ptr) {
                printk("current stack pointer : %lx\n", ptr);
                while(((uint64_t)ptr <= stack_bottom)) {
                    value = (uint64_t)(*ptr);
                    if(is_watchpoint(value)){
                        void *base = cfi_update_descriptor_state(value, WP_MEMORY_REACHABLE);
                        if(NULL != base){
                            printk("stack : src (%lx) \t dest(%lx)\n", ptr, base);
                            cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], base);
                        }
#if 0
                        void *base_ptr = cfi_item_update_base(value);
                        if(NULL != base_ptr) {
                            printk("stack : src (%lx) \t dest(%lx)\n", ptr, base_ptr);
                            cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], base_ptr);
                        }
#endif
                     }
                    ptr++;
                }
            }
#if 0
            for(idx = 0; idx < 16; idx++){
                value = thread_private_slot->regs[idx];
                if(is_watchpoint(value)){
                    void *base_ptr = cfi_item_update_base(value);
                    if(NULL != base_ptr) {
                        printk("stack : reg (%lu) \t dest(%lx)\n", idx, base_ptr);
                        cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], base_ptr);
                    }

                    //cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], (void*)cfi_item_update_base(value));
                    //cfi_list_append(&list_collected_watchpoint, (void*)cfi_item_update_base(value));
                }
            }
#endif
        }
        sweep_list = sweep_list->next;
    }
    spin_unlock(&(atomic_sweep_list.list_lock));

    /* objects leaking to the kernel*/
    return_list = kernel_leaked_watchpoints.head;
    spin_lock(&(kernel_leaked_watchpoints.list_lock));

    while(return_list != NULL){
        value = (uint64_t)((uint64_t*)(return_list->node));
        if(is_watchpoint(value)){
            void *base = cfi_update_descriptor_state(value, WP_MEMORY_REACHABLE);
            if(NULL != base){
                printk("object passed to the kernel : dest(%llx)\n", base);
                cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], base);
            }
#if 0
            void *base_ptr = cfi_item_update_base(value);
            if(NULL != base_ptr){
                printk("object passed to the kernel : dest(%lx)\n", base_ptr);
                cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], base_ptr);
            }
#endif
        }
        return_list = return_list->next;
    }
    spin_unlock(&(kernel_leaked_watchpoints.list_lock));
#if 1
    alloc_scan_list = module_alloc_list[CFI_ALLOC_GREY_LIST].head;
    while(alloc_scan_list != NULL){
        struct watchpoint_descriptor *temp_meta;
        meta_info = (struct watchpoint_descriptor *)get_watchpoint_meta((void*)alloc_scan_list->node);
        if((meta_info != NULL)){
            ptr = (uint64_t*)meta_info->base_address;
            if(ptr != NULL) {
            	while(ptr <= meta_info->limit ){
                	value = (uint64_t)(*(ptr));
                	if(is_watchpoint(value)){
                        void *base = cfi_update_descriptor_state(value, WP_MEMORY_REACHABLE);
                        if(NULL != base){
                            if(base != alloc_scan_list->node) {
                                printk("scanning greylist object : src( %lx) \t dest( %lx)\n", (void*)alloc_scan_list->node, base);
                                cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], base);
                            }
                        }
#if 0
                    	void *base_ptr = cfi_item_update_base(value);
                    	if(NULL != base_pt            && !(meta_info->state & WP_MEMORY_ALLOCATED)) {
r) {
                        	if(base_ptr != alloc_scan_list->node) {
                            	printk("scanning greylist object : src( %lx) \t dest( %lx)\n", (void*)alloc_scan_list->node, base_ptr);
                            	cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], base_ptr);
                        	}
                    	}
#endif
                 	}
                ptr++;
            	}
	   }else {
		printk("CHECK WATCHPOINT!!!!!!!!!!!!!!  : %lx", meta_info);
	   }
        }
        alloc_scan_list = alloc_scan_list->next;
    }
#endif
#if 0
    alloc_scan_list = watchpoint_scan_list.head;
    while(alloc_scan_list != NULL){
        struct watchpoint_descriptor *temp_meta;
        meta_info = (struct watchpoint_descriptor *)get_watchpoint_meta((void*)alloc_scan_list->node);
        if(meta_info != NULL){
            ptr = (uint64_t*)meta_info->base_address;
            while(ptr <= meta_info->limit ){
                value = (uint64_t)(*(ptr));
                if(is_watchpoint(value)){
                    if(alloc_scan_list->node != (void*)cfi_item_update_base(value)) {
                        printk("objects passed to the kernel: src( %lx) \t dest( %lx)\n", (void*)alloc_scan_list->node, (void*)cfi_item_update_base(value));
                        cfi_list_append(&list_collected_watchpoint_kernel, (void*)cfi_item_update_base(value));
                    }
                //    cfi_list_append(&module_alloc_list[CFI_ALLOC_GREY_LIST], (void*)cfi_item_update_base(value));
                }
                ptr++;
            }
        }
        alloc_scan_list = alloc_scan_list->next;
    }
    //spin_unlock(&(module_alloc_list[CFI_ALLOC_WHITE_LIST].list_lock));

#endif
}

int htable_callback(void *data, const char *key, void *value){
    scan_callback fn= (scan_callback)value;
    printk("hash item : key(%lx) value(%lx)\n ", key, value);
    if(fn != NULL)
    	fn(key);
    return 0;
}

bool module_tasklist(void *addr, void *data){
    struct thread_private_info *info = (struct thread_private_info*)addr;
    struct task_struct *tsk = (struct thread_struct*)info->tsk;
    memcpy(info->stack, info->tsk->stack, THREAD_SIZE);
    info->current_stack = info->tsk->thread.sp;
    info->stack_start_address = info->tsk->stack;
    return 0;
}

void copy_stack_callback(void){
    cfi_for_each_item(&atomic_sweep_list, &module_tasklist, NULL);
}

#define DEBUG

unsigned int
sweep_thread_init(void *arg)
{
    int ret;
    unsigned long flags;
    unsigned long local_flag;
    uint64_t i = 0;
    uint64_t max_index = 0;
    struct watchpoint_descriptor *descriptor = NULL;
    uint64_t count = 0;

    while (!kthread_should_stop()){
        dr_printf("*******************************************************inside sweep_thread_init\n");
#if 1
        stop_machine(copy_stack_callback, 0, 0);

        preempt_disable();
        raw_local_irq_save(flags);
        do {
            local_flag = flag_memory_snapshot;
        }while(!__sync_bool_compare_and_swap(&flag_memory_snapshot, local_flag, 0x0));

        printk("\nkernel objects hashtable count : %lu\n", hashmap_get_item_count(kernel_pointer_hash));
        hashmap_iter(kernel_pointer_hash, htable_callback, NULL);
        cfi_scan_rootsets();

        count  = get_descriptors_count();
        printk("descriptors count : %lu\n", count);
        for(i = 0; i <= count; i++){
            descriptor = get_descriptor_at_index(i);
            if(NULL != descriptor){
#ifdef DEBUG
                if((descriptor->state & WP_MEMORY_ALLOCATED) /*&& !(descriptor->state & WP_MEMORY_FREED)*/){
                    printk("%llx(%lx)\t", descriptor->base_address, i);
                    //cfi_list_append(&module_alloc_list[CFI_ALLOC_WHITE_LIST], descriptor->base_address);
                }
#endif
                if((descriptor->state & WP_MEMORY_ALLOCATED)
                        /*&& !(descriptor->state & WP_MEMORY_FREED)*/
                        && !(descriptor->state & WP_MEMORY_REACHABLE)){
                      cfi_list_append(&module_alloc_list[CFI_LOST_REFERENCE], descriptor->base_address);
                  }

                if(!(descriptor->state & WP_MEMORY_ALLOCATED) && !(descriptor->state & WP_MEMORY_REACHABLE)){
                    wrapper_collect_descriptor(i);
#ifdef DEBUG
                    //cfi_list_append(&module_alloc_list[CFI_COLLECT_LIST], i);
#endif
                }

                uint64_t newval = 0x0ULL;
                uint64_t oldval = 0x0ULL;
                do {
                    oldval = descriptor->state;
                    newval = (descriptor->state & (~WP_MEMORY_REACHABLE));
                }while(!__sync_bool_compare_and_swap(&(descriptor->state), oldval, newval));
                //meta_info->state = meta_info->state | state;

                //descriptor->state &= ~WP_MEMORY_REACHABLE;
            }
        }

#ifdef DEBUG
        printk("white list count : %lu\n", cfi_get_list_count(&module_alloc_list[CFI_ALLOC_WHITE_LIST]));
        cfi_for_each_item(&module_alloc_list[CFI_ALLOC_WHITE_LIST], &func_module_alloclist, NULL);
        //cfi_list_delete_all(&module_alloc_list[CFI_ALLOC_WHITE_LIST]);
        printk("\n");

        printk("grey list count : %lu\n", cfi_get_list_count(&module_alloc_list[CFI_ALLOC_GREY_LIST]));
        cfi_for_each_item(&module_alloc_list[CFI_ALLOC_GREY_LIST], &func_module_print_greylist, NULL);
        printk("\n");
        cfi_list_delete_all(&module_alloc_list[CFI_ALLOC_GREY_LIST]);
#endif
        printk("lost watchpoints: %lu\n", cfi_get_list_count(&module_alloc_list[CFI_LOST_REFERENCE]));
        cfi_for_each_item(&module_alloc_list[CFI_LOST_REFERENCE], &func_module_alloclist, NULL);
        printk("\n");
#ifdef DEBUG
        printk("watchpoints passed to kernel : %lu\n", cfi_get_list_count(&kernel_leaked_watchpoints));
        cfi_for_each_item(&kernel_leaked_watchpoints, &func_module_alloclist, NULL);
        printk("\n");

        //printk("collect watchpoints: %lu\n", cfi_get_list_count(&module_alloc_list[CFI_COLLECT_LIST]));
        //cfi_for_each_item(&module_alloc_list[CFI_COLLECT_LIST], &func_module_collectlist, NULL);
        //printk("\n");

      //  cfi_list_delete_all(&list_collected_watchpoint);
        cfi_list_delete_all(&kernel_leaked_watchpoints);
        cfi_list_delete_all(&module_alloc_list[CFI_COLLECT_LIST]);
#endif
        do {
            local_flag = flag_memory_snapshot;
        }while(!__sync_bool_compare_and_swap(&flag_memory_snapshot, local_flag, 0x1));
        raw_local_irq_restore(flags);
        preempt_enable();
#endif
        set_current_state(TASK_INTERRUPTIBLE);
        schedule_timeout(100*HZ/*00*/);
    }
    set_current_state(TASK_RUNNING);

    return 0;
}


void cfi_return_to_kernel(void *ptr){
    uint64_t value = (uint64_t)(ptr);
    struct watchpoint_descriptor *meta_info;
    if((!((uint64_t)value & ALIAS_ADDRESS_NOT_ENABLED)) && ((uint64_t)value > USER_ADDRESS_OFFSET)){
        uint64_t temp_value = (value & (~KERNEL_ADDRESS_OFFSET));
        if((temp_value > HEAP_START) && (temp_value < HEAP_END)){
            cfi_list_append(&kernel_leaked_watchpoints, (void*)cfi_item_update_base(value));
        }
    }
}

void *cfi_get_free_pages(unsigned long count){
    return __get_free_pages(GFP_KERNEL | __GFP_ZERO, count);
}

