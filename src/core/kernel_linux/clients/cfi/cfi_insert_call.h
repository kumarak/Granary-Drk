/*
 * cfi_insert_call.h
 *
 *  Created on: 2013-01-29
 *      Author: akshayk
 */

#ifndef CFI_INSERT_CALL_H_
#define CFI_INSERT_CALL_H_

unsigned int
cfi_prepare_for_native_call(void *drcontext, instrlist_t *ilist, instr_t *where);

void
cfi_cleanup_after_native_call(void *drcontext, instrlist_t *ilist, instr_t *where);

void
cfi_insert_native_call(void *dcontext, instrlist_t *ilist, instr_t *where, void *callee);

void
cfi_insert_meta_native_call_vargs(void *dcontext, instrlist_t *bb, instr_t *cursor,
                        bool clean_call, void *callee);

void
cfi_call_instrumentation_snapahot(void *dcontext, instrlist_t *ilist,
                        instr_t *where, void *callee);


#endif /* CFI_INSERT_CALL_H_ */
