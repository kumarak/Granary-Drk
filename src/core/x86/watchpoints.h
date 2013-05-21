/*
 * watchpoints.h
 *
 *  Created on: 2013-05-15
 *      Author: akshayk
 */

#ifndef WATCHPOINTS_H_
#define WATCHPOINTS_H_

void
watchpoint_indirect_call_event(dcontext_t *dcontext, instrlist_t *ilist, instr_t *instr,
                     instr_t *next_instr, bool mangle_calls, uint flags);


#endif /* WATCHPOINTS_H_ */
