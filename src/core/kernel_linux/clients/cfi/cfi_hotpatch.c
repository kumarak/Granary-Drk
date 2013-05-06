/*
 * cfi_hotpatch.c
 *
 *  Created on: 2013-03-14
 *      Author: akshayk
 */

#include <linux/stop_machine.h>
#include "cfi_hotpatch.h"
#include "cfi_hashtable.h"

#define POST instrlist_meta_postinsert
#define PRE  instrlist_meta_preinsert
#define APP  instrlist_append

client_cache_info_t *cpu_client_cache;
extern struct hashtable_t *kernel_pointer_hash;

struct hotpatch_data {
    void *addr;
    unsigned long long oldval;
    unsigned long long newval;
};

noinline void break_kernel_object(void *addr){

}

void cfi_kfree(void *addr){
    void *value;
    //if(hashmap_get(kernel_pointer_hash, (void*)addr, &value)){
      //  break_kernel_object(addr);
    //}
}

void cfi_vfree(void *addr){
    void *value;
   // if(hashmap_get(kernel_pointer_hash, (void*)addr, &value)){
     //   break_kernel_object(addr);
   // }
}

void cfi_kmem_cache_free(struct kmem_cache *s, void *ptr){
    void *value;
    //if(hashmap_get(kernel_pointer_hash, (void*)ptr, &value)){
      //  break_kernel_object(ptr);
    //}
}

//void cfi_hotpatch_kernel(void *data){
 //   printk("%s\n", __FUNCTION__);
//}

byte*
emit_hotpatch_code(void *drcontext, client_cache_info_t *client, byte *pc, app_pc *addr)
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
