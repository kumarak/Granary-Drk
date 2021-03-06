/*
 * cfi_insert_call.c
 *
 *  Created on: 2013-01-29
 *      Author: akshayk
 */

#include "cfi_utils.h"
#include "cfi_module.h"
#include "cfi_insert_call.h"

#define POST instrlist_meta_postinsert
#define PRE  instrlist_meta_preinsert

extern uint64_t *flag_memory_snapshot;

unsigned int
cfi_prepare_for_native_call(void *drcontext, instrlist_t *ilist, instr_t *where)
{
	unsigned int eflags_offs, dstack_offs = 0;
    instr_t *in = (where == NULL) ? instrlist_last(ilist) : instr_get_prev(where);

    CFI_ASSERT(drcontext != NULL, "cfi_prepare_for_native_call: drcontext cannot be NULL");

    //PRE(ilist, where, INSTR_CREATE_push_imm(dcontext, OPND_CREATE_INT32(0)));
    //dstack_offs += XSP_SZ;

    PRE(ilist, where, INSTR_CREATE_pushf(drcontext));
    PRE(ilist, where, INSTR_CREATE_push(drcontext,
                          opnd_create_base_disp(REG_XSP, REG_NULL, 0, 0, OPSZ_STACK)));
    PRE(ilist, where, INSTR_CREATE_and(drcontext,
                         opnd_create_base_disp(REG_XSP, REG_NULL, 0, 0,
                                               OPSZ_STACK),
                         OPND_CREATE_INT32(~(EFLAGS_NON_SYSTEM | EFLAGS_IF))));

    PRE(ilist, where, INSTR_CREATE_popf(drcontext));

  /*  dstack_offs += XSP_SZ;
    eflags_offs = dstack_offs;

    PRE(ilist, where, INSTR_CREATE_lea(drcontext, opnd_create_reg(REG_XSP),
    		OPND_CREATE_MEM_lea(REG_XSP, REG_NULL, 0, - XMM_SLOTS_SIZE)));

    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_R15)));
    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_R14)));
    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_R13)));
    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_R12)));
    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_R11)));
    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_R10)));
    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_R9)));
    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_R8)));
    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_RAX)));
    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_RCX)));
    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_RDX)));
    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_RBX)));*/
    /* we do NOT match pusha xsp value *//*
    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_RSP)));
    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_RBP)));
    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_RSI)));
    PRE(ilist, where, INSTR_CREATE_push(drcontext, opnd_create_reg(REG_RDI)));
    dstack_offs += 16*XSP_SZ + XMM_SLOTS_SIZE;

    PRE(ilist, where, INSTR_CREATE_push(drcontext,
                          opnd_create_base_disp(REG_XSP, REG_NULL, 0,
                          dstack_offs - eflags_offs, OPSZ_STACK)));

    PRE(ilist, where, INSTR_CREATE_and(drcontext,
                         opnd_create_base_disp(REG_XSP, REG_NULL, 0, 0,
                                               OPSZ_STACK),
                         OPND_CREATE_INT32(~(EFLAGS_NON_SYSTEM | EFLAGS_IF))));

    PRE(ilist, where, INSTR_CREATE_popf(drcontext));*/

    /* now go through and mark inserted instrs as meta */
    if (in == NULL)
        in = instrlist_first(ilist);
    else
        in = instr_get_next(in);

    while (in != where) {
        instr_set_ok_to_mangle(in, false);
        in = instr_get_next(in);
    }

    return dstack_offs;
}

void
cfi_cleanup_after_native_call(void *drcontext, instrlist_t *ilist, instr_t *where)
{
	instr_t *in = (where == NULL) ? instrlist_last(ilist) : instr_get_prev(where);

	CFI_ASSERT(drcontext != NULL, "dr_cleanup_after_call: drcontext cannot be NULL");
/*
    PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_RDI)));
    PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_RSI)));
    PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_RBP)));*/
    /* skip xsp by popping into dead rbx */
  /*  PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_RBX)));
    PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_RBX)));
    PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_RDX)));
    PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_RCX)));
    PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_RAX)));
    PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_R8)));
    PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_R9)));
    PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_R10)));
    PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_R11)));
    PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_R12)));
    PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_R13)));
    PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_R14)));
    PRE(ilist, where, INSTR_CREATE_pop(drcontext, opnd_create_reg(REG_R15)));

    PRE(ilist, where, INSTR_CREATE_lea
        (drcontext, opnd_create_reg(REG_XSP),
         OPND_CREATE_MEM_lea(REG_XSP, REG_NULL, 0, XMM_SLOTS_SIZE)));

*/
    PRE(ilist, where, INSTR_CREATE_popf(drcontext));

    /* now go through and mark inserted instrs as meta */
    if (in == NULL)
        in = instrlist_first(ilist);
    else
        in = instr_get_next(in);

    while (in != where) {
        instr_set_ok_to_mangle(in, false);
        in = instr_get_next(in);
    }
}

void
cfi_insert_meta_native_call_vargs(void *dcontext, instrlist_t *bb, instr_t *cursor,
                       bool clean_call, void *callee)
{
    instr_t *in = (cursor == NULL) ? instrlist_last(bb) : instr_get_prev(cursor);

   // PRE(ilist, instr, INSTR_CREATE_mov_ld(dcontext, opnd_create_reg(REG_RDI), opnd_create_reg(REG_RSP)));

    PRE(bb, cursor, INSTR_CREATE_call(dcontext, opnd_create_pc(callee)));

    /* mark it all meta */
    if (in == NULL)
        in = instrlist_first(bb);
    else
        in = instr_get_next(in);
    while (in != cursor) {
        instr_set_ok_to_mangle(in, false);
        in = instr_get_next(in);
    }
}

void
cfi_insert_native_call(void *dcontext, instrlist_t *ilist, instr_t *where, void *callee)
{
	uint dstack_offs = 0, pad = 0;
	size_t buf_sz = 0;

	/* check for dcontext as NULL*/
	CFI_ASSERT(dcontext != NULL, "cfi_insert_native_call: dcontext cannot be NULL");

	dstack_offs = cfi_prepare_for_native_call(dcontext, ilist, where);

     instrlist_set_our_mangling(ilist, true);
     cfi_insert_meta_native_call_vargs(dcontext, ilist, where, true/*clean*/, callee);
     instrlist_set_our_mangling(ilist, false);

     cfi_cleanup_after_native_call(dcontext, ilist, where);
}

void
cfi_call_instrumentation_snapahot(void *dcontext, instrlist_t *ilist, instr_t *where, void *callee)
{
    uint dstack_offs = 0, pad = 0;

    unsigned int eflags_offs;

    CFI_ASSERT(dcontext != NULL, "cfi_call_instrumentation_snapahot: dcontext cannot be NULL");

    instr_t *next_snapshot = INSTR_CREATE_label(dcontext);
    PRE(ilist, where, INSTR_CREATE_pushf(dcontext));
    dstack_offs += XSP_SZ;
    eflags_offs = dstack_offs;

    PRE(ilist, where, INSTR_CREATE_push(dcontext, opnd_create_reg(DR_REG_RDI)));
    dstack_offs += XSP_SZ;

    PRE(ilist, where, INSTR_CREATE_mov_imm(dcontext, opnd_create_reg(DR_REG_RDI), OPND_CREATE_INT64(&flag_memory_snapshot)));
    PRE(ilist, where, INSTR_CREATE_mov_ld(dcontext, opnd_create_reg(DR_REG_RDI), opnd_create_base_disp(DR_REG_RDI, DR_REG_NULL, 0, 0, OPSZ_PTR)));
    PRE(ilist, where, INSTR_CREATE_cmp(dcontext, opnd_create_reg(DR_REG_RDI), OPND_CREATE_INT8(0x0)));
    PRE(ilist, where, INSTR_CREATE_jcc(dcontext, OP_je, opnd_create_instr(next_snapshot)));

    PRE(ilist, where, INSTR_CREATE_push(dcontext,
                          opnd_create_base_disp(DR_REG_RSP, DR_REG_NULL, 0,
                          dstack_offs - eflags_offs, OPSZ_STACK)));

    PRE(ilist, where, INSTR_CREATE_and(dcontext,
                         opnd_create_base_disp(DR_REG_RSP, DR_REG_NULL, 0, 0,
                                               OPSZ_STACK),
                         OPND_CREATE_INT32(~(EFLAGS_NON_SYSTEM | EFLAGS_IF))));

    PRE(ilist, where, INSTR_CREATE_popf(dcontext));

    instrlist_set_our_mangling(ilist, true);
    cfi_insert_meta_native_call_vargs(dcontext, ilist, where, true/*clean*/, callee);
    instrlist_set_our_mangling(ilist, false);

    cfi_insert_native_call(dcontext, ilist, where, callee /*, opnd_create_reg(DR_REG_RAX)*/);

    PRE(ilist, where, next_snapshot);
    PRE(ilist, where, INSTR_CREATE_pop(dcontext, opnd_create_reg(DR_REG_RDI)));
    PRE(ilist, where, INSTR_CREATE_popf(dcontext));



   /* dstack_offs = cfi_prepare_for_native_call(dcontext, ilist, where);

     instrlist_set_our_mangling(ilist, true);
     cfi_insert_meta_native_call_vargs(dcontext, ilist, where, true*//*clean*//*, callee);
     instrlist_set_our_mangling(ilist, false);

     cfi_cleanup_after_native_call(dcontext, ilist, where);*/
}
