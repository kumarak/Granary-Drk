/*
 * hotpatch_kernel.c
 *
 *  Created on: 2013-03-14
 *      Author: akshayk
 */


#include "globals.h"
#include "fragment.h"
#include "arch.h"
#include "instr.h"
#include "instr_create.h"
#include "decode.h"
#include "instrument.h"
#include "hotpatch_kernel.h"

#define POST instrlist_meta_postinsert
#define PRE  instrlist_meta_preinsert
#define APP  instrlist_append

void
dr_register_hotpatch_event(dr_emit_flags_t (*func)
        (void *drcontext, void *tag, instrlist_t *bb,
         bool for_trace, bool translating)){
	dcontext_t *dcontext = get_thread_private_dcontext();

}

dr_hotpatch_address(app_pc hotp_pc){
	dcontext_t *dcontext = get_thread_private_dcontext();
	instr_t *instr, *hotpatch_instr;
	cache_pc pc;
	instrlist_t* ilist = instrlist_create(dcontext);
	instr = instr_create(dcontext);
	decode(dcontext, pc, instr);
	instr_set_translation(instr, pc);

	hotpatch_instr = instr_create(dcontext);

	instr_t* hotp_target = INSTR_CREATE_label(dcontext);

	APP(ilist, INSTR_CREATE_jmp(dcontext, opnd_create_instr(hotp_target)));
	APP(ilist, hotp_target);
	APP(ilist, INSTR_CREATE_jmp(dcontext, opnd_create_pc(pc+instr->length)));

    pc = instrlist_encode(dcontext, ilist, pc, false);
    instrlist_clear_and_destroy(dcontext, ilist);


}

