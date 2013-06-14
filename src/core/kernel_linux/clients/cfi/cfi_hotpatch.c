/*
 * cfi_hotpatch.c
 *
 *  Created on: 2013-03-14
 *      Author: akshayk
 */

#include <linux/stop_machine.h>
#include "cfi_hotpatch.h"
#include "cfi_hashtable.h"
#include "cfi_defines.h"
#include "cfi_wrapper.h"
#include "slub_interface.h"

client_cache_info_t *cpu_client_cache;

extern mem_allocator_t slub_allocator;

#define FUNCTION_WRAPPER(fn_name, ret_type, args, body) \
    typedef ret_type (fn_name ##_type) args;    \
    ret_type wrapper_ ##fn_name args    \
    body



byte*
emit_hotpatch_code(void *drcontext, byte *cache_pc, function_t *func);

#define WRAP_FUNCTION(fn_name, ret_type, nargs, ...) \
    static function_t fn_name ## _wrapper =\
        { .name = #fn_name,\
          .replace_func = NULL,\
          .wrapper_func = NULL,\
          .pre_wrapper = NULL,\
          .post_wrapper = NULL};

#include "slubx.h"
#undef WRAP_FUNCTION

#define WRAP_FUNCTION(fn_name, ret_type, nargs, ...) \
    &fn_name ## _wrapper,

function_t *wrapped_functions[] =  {
#include "slubx.h"
        NULL,
};
#undef WRAP_FUNCTION

#define NUM_WRAPPED_FUNCTIONS (sizeof(wrapped_functions) / sizeof(wrapped_functions[0]))


static bool
cfi_get_function_bounds(function_t *func)
{
    return dr_kernel_find_symbol(func->name, &func->start, &func->size);
}

void update_function_bounds(void){
    int i;
    unsigned int count = NUM_WRAPPED_FUNCTIONS;
    printk("!!!!!!!!!!!!!%s!!!!!!!!!!!!!!! : %d\n", __FUNCTION__, count);
    for (i = 0; i < NUM_WRAPPED_FUNCTIONS; i++) {
        if(wrapped_functions[i] == NULL){
            break;
        }
        if (!cfi_get_function_bounds(wrapped_functions[i])) {
            printk("cfi_get_function_bounds failed for %s\n",
                   wrapped_functions[i]->name);
            return -EINVAL;
        }
        wrapped_functions[i]->wrapper_func = cfi_get_hotpatch_wrapper(wrapped_functions[i]->start);
        printk("function name : %s, size : %lx\n", wrapped_functions[i]->name, wrapped_functions[i]->size);
    }
}

void update_slub_interface(void){
    unsigned int count = NUM_WRAPPED_FUNCTIONS;
    slub_allocator.kfree = wrapped_functions[INTERFACE_KFREE]->replace_func;
    slub_allocator.__kmalloc = wrapped_functions[INTERFACE___KMALLOC]->replace_func;
    slub_allocator.free_percpu = wrapped_functions[INTERFACE_FREE_PERCPU]->replace_func;
    slub_allocator.__alloc_percpu = wrapped_functions[INTERFACE___ALLOC_PERCPU]->replace_func;
    slub_allocator.kmem_cache_alloc = wrapped_functions[INTERFACE_KMEM_CACHE_ALLOC]->replace_func;
    slub_allocator.kmem_cache_free = wrapped_functions[INTERFACE_KMEM_CACHE_FREE]->replace_func;
    slub_allocator.__kmalloc_node =  wrapped_functions[INTERFACE___KMALLOC_NODE]->replace_func;
    slub_allocator.__kmalloc_track_caller =  wrapped_functions[INTERFACE___KMALLOC_TRACK_CALLER]->replace_func;
    slub_allocator.__kmalloc_node_track_caller =  wrapped_functions[INTERFACE___KMALLOC_NODE_TRACK_CALLER]->replace_func;
    slub_allocator.__kmalloc_track_caller =  wrapped_functions[INTERFACE___KMALLOC_TRACK_CALLER]->replace_func;
    slub_allocator.kmem_cache_alloc_node = wrapped_functions[INTERFACE_KMEM_CACHE_ALLOC_NODE]->replace_func;
    slub_allocator.__get_free_pages = wrapped_functions[INTERFACE___GET_FREE_PAGES]->replace_func;
    slub_allocator.__free_pages = wrapped_functions[INTERFACE___FREE_PAGES]->replace_func;
}


void cfi_hotpatch_init(void *drcontext){
    client_cache_info_t * client = (client_cache_info_t*) dr_thread_alloc(drcontext, sizeof(client_cache_info_t));
    cpu_client_cache = client;
    int i;
    printk("%s : %llx\n", __FUNCTION__, client);
    update_function_bounds();

    client->cache_start = dr_thread_alloc(drcontext, CLIENT_CACHE_SIZE);
    client->cache_ptr = client->cache_start;

    for (i = 0; i < NUM_WRAPPED_FUNCTIONS; i++) {
        if(wrapped_functions[i] == NULL){
            break;
        }
        client->cache_ptr = emit_hotpatch_code(drcontext, client->cache_ptr, wrapped_functions[i]);
    }

    update_slub_interface();
}

#define POST instrlist_meta_postinsert
#define PRE  instrlist_meta_preinsert
#define APP  instrlist_append


extern struct hashtable_t *kernel_pointer_hash;

struct hotpatch_data {
    void *addr;
    unsigned long long oldval;
    unsigned long long newval;
};


byte*
emit_hotpatch_code(void *drcontext, byte *cache_pc, function_t *func)
{
    unsigned long long hotpatch_instr = 0ULL;
    unsigned long long temp = 0ULL;
    uint64_t *addr, oldval, newval;
    app_pc wrapper_pc;
    instr_t *instr = NULL;
    int64_t offset_val = 0;
    uint64_t orig_pc = (uint64_t)func->start;

    addr = (uint64_t*)func->start;

    unsigned long hotpatch_instruction[] = {
        0xe9, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00
    };

    app_pc pc = dr_emit_hotpatch_code(func->start, func->size, NULL);

    func->replace_func = (void*)pc;

    if(func->wrapper_func != NULL) {
        wrapper_pc = (app_pc)func->wrapper_func;
    } else {
        wrapper_pc = (app_pc)func->replace_func;
    }

    offset_val = ((uint64_t)wrapper_pc - (orig_pc+5));

    hotpatch_instruction[1] = ((offset_val >> 0)     & 0xff);
    hotpatch_instruction[2] = ((offset_val >> 8)     & 0xff);
    hotpatch_instruction[3] = ((offset_val >> 16)    & 0xff);
    hotpatch_instruction[4] = ((offset_val >> 24)    & 0xff);

    hotpatch_instr = (uint64_t){(hotpatch_instruction[0])
                                + (hotpatch_instruction[1] << 8)
                                + (hotpatch_instruction[2] << 16)
                                + (hotpatch_instruction[3] << 24)
                                + (hotpatch_instruction[4] << 32)};

    newval = hotpatch_instr;

    do {
            oldval = *(addr);
    }while(!__sync_bool_compare_and_swap(addr, oldval, newval));

    return pc;

    /*
    instrlist_t *ilist_hpsrc = instrlist_create(drcontext);
    instrlist_t *ilist_hpdsts = instrlist_create(drcontext);
    instr_t *hpsrc_instr, *orig_instr, *hp_instr, *instr;
    byte *pc_start_t, *pc_end_t, *pc_end;
    instr_t *where;
    uint i =0;
    uint64_t *newaddr, oldval, newval;
    uint size = 0, len=0;
    app_pc src_pc = addr;
    uint64_t target_pc = (uint64_t)addr;
    uint64_t orig_pc = (uint64_t)addr;
    unsigned long begin_pfn = PFN_DOWN((unsigned long)addr);
    uint64_t hotpatch_target;
    int64_t offset_val;

    unsigned long long hotpatch_instr = 0ULL;
    unsigned long long temp = 0ULL;

    unsigned long hotpatch_instruction[] = {
        0xe9, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00
    };

    instrlist_init(ilist_hpsrc);
    instrlist_init(ilist_hpdsts);

    instr_t *hotp_target = INSTR_CREATE_label(drcontext);

    hp_instr = INSTR_CREATE_jmp(drcontext, opnd_create_pc(cfi_kfree));
    len = instr_length(drcontext, hp_instr);
    pc_start_t = dr_thread_alloc(drcontext, len);


    while(size <= 8){
        orig_instr = instr_create(drcontext);
        decode(drcontext, src_pc, orig_instr);
        APP(ilist_hpdsts, orig_instr);
        size = size + orig_instr->length;
        src_pc = src_pc + orig_instr->length;
    }

    target_pc = target_pc + size;
    instr = INSTR_CREATE_jmp(drcontext, opnd_create_pc(target_pc));

    APP(ilist_hpdsts, instr);

    if(addr == (void*)kfree){
        dr_insert_clean_call(drcontext, ilist_hpdsts, instr, (void *)cfi_kfree, false, 1, opnd_create_reg(DR_REG_RDI));
    } else if(addr == (void*)vfree){
        dr_insert_clean_call(drcontext, ilist_hpdsts, instr, (void *)cfi_vfree, false, 1, opnd_create_reg(DR_REG_RDI));
    } else if(addr == (void*)kmem_cache_free){
        dr_insert_clean_call(drcontext, ilist_hpdsts, instr, (void *)cfi_kmem_cache_free, false, 2, opnd_create_reg(DR_REG_RDI), opnd_create_reg(DR_REG_RSI));
    } else if(addr == (void*)delayed_work_timer_fn){
        dr_insert_clean_call(drcontext, ilist_hpdsts, instr, (void *)cfi_delayed_work_timer_fn, false, 2, opnd_create_reg(DR_REG_RDI), opnd_create_reg(DR_REG_RSI));
    }


    pc_end = instrlist_encode(drcontext, ilist_hpdsts, pc, true);

    offset_val = ((uint64_t)pc - (orig_pc+5));


    hotpatch_instruction[1] = ((offset_val >> 0)     & 0xff);
    hotpatch_instruction[2] = ((offset_val >> 8)     & 0xff);
    hotpatch_instruction[3] = ((offset_val >> 16)    & 0xff);
    hotpatch_instruction[4] = ((offset_val >> 24)    & 0xff);

    hotpatch_instr = (uint64_t){(hotpatch_instruction[0])
                                + (hotpatch_instruction[1] << 8)
                                + (hotpatch_instruction[2] << 16)
                                + (hotpatch_instruction[3] << 24)
                                + (hotpatch_instruction[4] << 32)};

    newval = hotpatch_instr;
*/
  /*  while(i < len){
        temp = (uint64_t)(hotpatch_instruction[i]);
        hotpatch_instr = (hotpatch_instr|(temp << 8*i));
        i++;
    }
*/
  //  uint64_t pc_start_i = (uint64_t)pc_start_t;
  //  memset(addr, newval, 0x8);
/*
    do {
        oldval = *(addr);
    }while(!__sync_bool_compare_and_swap(addr, oldval, newval));
*/
    /*make a call to instrumentation function*/

}

#if 0

byte*
emit_hotpatch_code_(void *drcontext, client_cache_info_t *client, byte *pc, app_pc *addr)
{
    instrlist_t *ilist_hpsrc = instrlist_create(drcontext);
    instrlist_t *ilist_hpdsts = instrlist_create(drcontext);
    instr_t *hpsrc_instr, *orig_instr, *hp_instr, *instr;
    byte *pc_start_t, *pc_end_t, *pc_end;
    instr_t *where;
    uint i =0;
    uint64_t *newaddr, oldval, newval;
    uint size = 0, len=0;
    app_pc src_pc = addr;
    uint64_t target_pc = (uint64_t)addr;
    uint64_t orig_pc = (uint64_t)addr;
    unsigned long begin_pfn = PFN_DOWN((unsigned long)addr);
    uint64_t hotpatch_target;
    int64_t offset_val;

    unsigned long long hotpatch_instr = 0ULL;
    unsigned long long temp = 0ULL;

    unsigned long hotpatch_instruction[] = {
        0xe9, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00
    };

    instrlist_init(ilist_hpsrc);
    instrlist_init(ilist_hpdsts);

    instr_t *hotp_target = INSTR_CREATE_label(drcontext);

    hp_instr = INSTR_CREATE_jmp(drcontext, opnd_create_pc(cfi_kfree));
    len = instr_length(drcontext, hp_instr);
    pc_start_t = dr_thread_alloc(drcontext, len);


    while(size <= 8){
        orig_instr = instr_create(drcontext);
        decode(drcontext, src_pc, orig_instr);
        APP(ilist_hpdsts, orig_instr);
        size = size + orig_instr->length;
        src_pc = src_pc + orig_instr->length;
    }

    target_pc = target_pc + size;
    instr = INSTR_CREATE_jmp(drcontext, opnd_create_pc(target_pc));

    APP(ilist_hpdsts, instr);

    if(addr == (void*)kfree){
        dr_insert_clean_call(drcontext, ilist_hpdsts, instr, (void *)cfi_kfree, false, 1, opnd_create_reg(DR_REG_RDI));
    } else if(addr == (void*)vfree){
        dr_insert_clean_call(drcontext, ilist_hpdsts, instr, (void *)cfi_vfree, false, 1, opnd_create_reg(DR_REG_RDI));
    } else if(addr == (void*)kmem_cache_free){
        dr_insert_clean_call(drcontext, ilist_hpdsts, instr, (void *)cfi_kmem_cache_free, false, 2, opnd_create_reg(DR_REG_RDI), opnd_create_reg(DR_REG_RSI));
    } else if(addr == (void*)delayed_work_timer_fn){
        dr_insert_clean_call(drcontext, ilist_hpdsts, instr, (void *)cfi_delayed_work_timer_fn, false, 2, opnd_create_reg(DR_REG_RDI), opnd_create_reg(DR_REG_RSI));
    }


    pc_end = instrlist_encode(drcontext, ilist_hpdsts, pc, true);

    offset_val = ((uint64_t)pc - (orig_pc+5));


    hotpatch_instruction[1] = ((offset_val >> 0)     & 0xff);
    hotpatch_instruction[2] = ((offset_val >> 8)     & 0xff);
    hotpatch_instruction[3] = ((offset_val >> 16)    & 0xff);
    hotpatch_instruction[4] = ((offset_val >> 24)    & 0xff);

    hotpatch_instr = (uint64_t){(hotpatch_instruction[0])
                                + (hotpatch_instruction[1] << 8)
                                + (hotpatch_instruction[2] << 16)
                                + (hotpatch_instruction[3] << 24)
                                + (hotpatch_instruction[4] << 32)};

    newval = hotpatch_instr;

  /*  while(i < len){
        temp = (uint64_t)(hotpatch_instruction[i]);
        hotpatch_instr = (hotpatch_instr|(temp << 8*i));
        i++;
    }
*/
  //  uint64_t pc_start_i = (uint64_t)pc_start_t;
  //  memset(addr, newval, 0x8);

    do {
        oldval = *(addr);
    }while(!__sync_bool_compare_and_swap(addr, oldval, newval));

    /*make a call to instrumentation function*/
    return pc_end;
}
#endif

byte*
hijack_kernel_function(void *drcontext, client_cache_info_t *client,
                          byte *pc, app_pc src_addr, app_pc target_addr){

    unsigned long long hotpatch_instr = 0ULL;
    uint64_t newval, oldval;

    unsigned long hotpatch_instruction[] = {
        0xe9, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00
    };

    uint64_t offset_val = ((uint64_t)(target_addr - src_addr));

    hotpatch_instruction[1] = ((offset_val >> 0)     & 0xff);
    hotpatch_instruction[2] = ((offset_val >> 8)     & 0xff);
    hotpatch_instruction[3] = ((offset_val >> 16)    & 0xff);
    hotpatch_instruction[4] = ((offset_val >> 24)    & 0xff);

    hotpatch_instr = (uint64_t){(hotpatch_instruction[0])
                                + (hotpatch_instruction[1] << 8)
                                + (hotpatch_instruction[2] << 16)
                                + (hotpatch_instruction[3] << 24)
                                + (hotpatch_instruction[4] << 32)};

    newval = hotpatch_instr;

    do {
        oldval = *((uint64_t*)src_addr);
    }while(!__sync_bool_compare_and_swap(src_addr, oldval, newval));

    /*make a call to instrumentation function*/
    return pc;
}
