/* **********************************************************
 * Copyright (c) 2002-2009 VMware, Inc.  All rights reserved.
 * **********************************************************/

/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * 
 * * Neither the name of VMware, Inc. nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without
 *   specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL VMWARE, INC. OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

#ifndef _DR_IR_INSTR_H_
#define _DR_IR_INSTR_H_ 1

/****************************************************************************
 * INSTR ROUTINES
 */
/**
 * @file dr_ir_instr.h
 * @brief Functions to create and manipulate instructions.
 */



/**
 * Returns an initialized instr_t allocated on the thread-local heap.
 * Sets the x86/x64 mode of the returned instr_t to the mode of dcontext.
 */
instr_t*
instr_create(void *drcontext);

/** Initializes \p instr.
 * Sets the x86/x64 mode of \p instr to the mode of dcontext.
 */
void
instr_init(void *drcontext, instr_t *instr);

/**
 * Deallocates all memory that was allocated by \p instr.  This
 * includes raw bytes allocated by instr_allocate_raw_bits() and
 * operands allocated by instr_set_num_opnds().  Does not deallocate
 * the storage for \p instr itself.
 */
void
instr_free(void *drcontext, instr_t *instr);

/**
 * Performs both instr_free() and instr_init().
 * \p instr must have been initialized.
 */
void
instr_reset(void *drcontext, instr_t *instr);

/**
 * Frees all dynamically allocated storage that was allocated by \p instr,
 * except for allocated bits.
 * Also zeroes out \p instr's fields, except for raw bit fields,
 * whether \p instr is instr_ok_to_mangle(), and the x86 mode of \p instr.
 * \p instr must have been initialized.
 */
void
instr_reuse(void *drcontext, instr_t *instr);

/**
 * Performs instr_free() and then deallocates the thread-local heap
 * storage for \p instr.
 */
void
instr_destroy(void *drcontext, instr_t *instr);

/**
 * Returns the next instr_t in the instrlist_t that contains \p instr.
 * \note The next pointer for an instr_t is inside the instr_t data
 * structure itself, making it impossible to have on instr_t in
 * two different InstrLists (but removing the need for an extra data
 * structure for each element of the instrlist_t).
 */
instr_t*
instr_get_next(instr_t *instr);

/** Returns the previous instr_t in the instrlist_t that contains \p instr. */
instr_t*
instr_get_prev(instr_t *instr);

/** Sets the next field of \p instr to point to \p next. */
void
instr_set_next(instr_t *instr, instr_t *next);

/** Sets the prev field of \p instr to point to \p prev. */
void
instr_set_prev(instr_t *instr, instr_t *prev);

/**
 * Gets the value of the user-controlled note field in \p instr.
 * \note Important: is also used when emitting for targets that are other
 * instructions, so make sure to clear or set appropriately the note field
 * prior to emitting.
 */
void *
instr_get_note(instr_t *instr);

/** Sets the user-controlled note field in \p instr to \p value. */
void
instr_set_note(instr_t *instr, void *value);

/** Return the taken target pc of the (direct branch) instruction. */
app_pc
instr_get_branch_target_pc(instr_t *cti_instr);

/** Set the taken target pc of the (direct branch) instruction. */
void
instr_set_branch_target_pc(instr_t *cti_instr, app_pc pc);

/**
 * Returns true iff \p instr is a conditional branch, unconditional branch,
 * or indirect branch with a program address target (NOT an instr_t address target)
 * and \p instr is ok to mangle.
 */
bool
instr_is_exit_cti(instr_t *instr);

/** Return true iff \p instr's opcode is OP_int, OP_into, or OP_int3. */
bool
instr_is_interrupt(instr_t *instr);

/**
 * Return true iff \p instr is not a meta-instruction
 * (see instr_set_ok_to_mangle() for more information).
 */
bool
instr_ok_to_mangle(instr_t *instr);

/**
 * Sets \p instr to "ok to mangle" if \p val is true and "not ok to
 * mangle" if \p val is false.  An instruction that is "not ok to
 * mangle" is treated by DR as a "meta-instruction", distinct from
 * normal application instructions, and is not mangled in any way.
 * This is necessary to have DR not create an exit stub for a direct
 * jump.  All non-meta instructions that are added to basic blocks or
 * traces should have their translation fields set (via
 * #instr_set_translation(), or the convenience routine
 * #instr_set_meta_no_translation()) when recreating state at a fault;
 * meta instructions should not fault and are not considered
 * application instructions but rather added instrumentation code (see
 * #dr_register_bb_event() for further information on recreating).
 *
 * \note For meta-instructions that can fault but only when accessing
 * client memory and that never access application memory, the
 * "meta-instruction that can fault" property can be set via
 * #instr_set_meta_may_fault to avoid incurring the cost of added
 * sandboxing checks that look for changes to application code.
 */
void
instr_set_ok_to_mangle(instr_t *instr, bool val);

/**
 * A convenience routine that calls both
 * #instr_set_ok_to_mangle (instr, false) and
 * #instr_set_translation (instr, NULL).
 */
void
instr_set_meta_no_translation(instr_t *instr);

/** Return true iff \p instr is to be emitted into the cache. */
bool
instr_ok_to_emit(instr_t *instr);

/**
 * Set \p instr to "ok to emit" if \p val is true and "not ok to emit"
 * if \p val is false.  An instruction that should not be emitted is
 * treated normally by DR for purposes of exits but is not placed into
 * the cache.  It is used for final jumps that are to be elided.
 */
void
instr_set_ok_to_emit(instr_t *instr, bool val);

/**
 * Returns the length of \p instr.
 * As a side effect, if instr_ok_to_mangle(instr) and \p instr's raw bits
 * are invalid, encodes \p instr into bytes allocated with
 * instr_allocate_raw_bits(), after which instr is marked as having
 * valid raw bits.
 */
int
instr_length(void *drcontext, instr_t *instr);

/** Returns true iff \p instr can be encoding as a valid IA-32 instruction. */
bool
instr_is_encoding_possible(instr_t *instr);

/**
 * Encodes \p instr into the memory at \p pc.
 * Uses the x86/x64 mode stored in instr, not the mode of the current thread.
 * Returns the pc after the encoded instr, or NULL if the encoding failed.
 * If instr is a cti with an instr_t target, the note fields of instr and
 * of the target must be set with the respective offsets of each instr_t!
 * (instrlist_encode does this automatically, if the target is in the list).
 */
byte *
instr_encode(void *drcontext, instr_t *instr, byte *pc);

void
dr_takeover_idtr(void);

void
dr_set_native_idtr(void);

void
dr_app_take_over(void);

void
dr_app_stop(void);

void
dr_app_start(void);

void
get_return_address(void);

void
return_to_module_from_interrupt(void);

void
mecontext_snapshot_native(void);

void
dr_app_start_after_iret(void);

void
dr_app_start_on_return(void);

void*
dr_get_wrapper_target(app_pc kernel_addr);

void
dr_register_direct_call_exit(void *addr);

void
dr_register_kernel_wrapper(void *addr);

void*
dr_is_granary_code(void *addr);

void
dr_register_is_granary_code(int (*func)(void *));

void*
dr_is_instrumented_module_code(void *addr);

void
dr_register_is_instrumented_module_code(int (*func)(void *));

int
dr_get_symbol_name(void *addr);

void
dr_register_get_symbol_name(int (*func)(void *));

void
dr_register_exit_module_context(void* addr);

void
dr_register_address_untracker(void *(*addr)(void *));

void
dr_register_address_return_exit(void (*addr)(void));

int
is_drk_running(void);

/** Returns number of bytes of heap used by \p instr. */
int
instr_mem_usage(instr_t *instr);

/**
 * Returns a copy of \p orig with separately allocated memory for
 * operands and raw bytes if they were present in \p orig.
 */
instr_t *
instr_clone(void *drcontext, instr_t *orig);

/**
 * Convenience routine: calls
 * - instr_create(dcontext)
 * - instr_set_opcode(opcode)
 * - instr_set_num_opnds(dcontext, instr, num_dsts, num_srcs)
 *
 * and returns the resulting instr_t.
 */
instr_t *
instr_build(void *drcontext, int opcode, int num_dsts, int num_srcs);

/**
 * Convenience routine: calls 
 * - instr_create(dcontext)
 * - instr_set_opcode(instr, opcode)
 * - instr_allocate_raw_bits(dcontext, instr, num_bytes)
 *
 * and returns the resulting instr_t.
 */
instr_t *
instr_build_bits(void *drcontext, int opcode, uint num_bytes);

/**
 * Returns true iff \p instr's opcode is NOT OP_INVALID.
 * Not to be confused with an invalid opcode, which can be OP_INVALID or
 * OP_UNDECODED.  OP_INVALID means an instruction with no valid fields:
 * raw bits (may exist but do not correspond to a valid instr), opcode,
 * eflags, or operands.  It could be an uninitialized
 * instruction or the result of decoding an invalid sequence of bytes.
 */
bool 
instr_valid(instr_t *instr);

/** Get the original application PC of \p instr if it exists. */
app_pc
instr_get_app_pc(instr_t *instr);

/* Get the original application PC of the instruction if it exists. */
void
instr_set_app_pc(instr_t *instr, app_pc pc);

/** Returns \p instr's opcode (an OP_ constant). */
int 
instr_get_opcode(instr_t *instr);

/** Assumes \p opcode is an OP_ constant and sets it to be instr's opcode. */
void 
instr_set_opcode(instr_t *instr, int opcode);

/**
 * Returns the number of source operands of \p instr.
 *
 * \note Addressing registers used in destination memory references
 * (i.e., base, index, or segment registers) are not separately listed
 * as source operands.
 */
int 
instr_num_srcs(instr_t *instr);

/**
 * Returns the number of destination operands of \p instr.
 */
int 
instr_num_dsts(instr_t *instr);

/**
 * Assumes that \p instr has been initialized but does not have any
 * operands yet.  Allocates storage for \p num_srcs source operands
 * and \p num_dsts destination operands.
 */
void 
instr_set_num_opnds(void *drcontext, instr_t *instr, int num_dsts, int num_srcs);

/**
 * Returns \p instr's source operand at position \p pos (0-based).
 */
opnd_t 
instr_get_src(instr_t *instr, uint pos);

/**
 * Returns \p instr's destination operand at position \p pos (0-based).
 */
opnd_t 
instr_get_dst(instr_t *instr, uint pos);

/**
 * Sets \p instr's source operand at position \p pos to be \p opnd.
 * Also calls instr_set_raw_bits_valid(\p instr, false) and
 * instr_set_operands_valid(\p instr, true).
 */
void 
instr_set_src(instr_t *instr, uint pos, opnd_t opnd);

/**
 * Sets \p instr's destination operand at position \p pos to be \p opnd.
 * Also calls instr_set_raw_bits_valid(\p instr, false) and
 * instr_set_operands_valid(\p instr, true).
 */
void 
instr_set_dst(instr_t *instr, uint pos, opnd_t opnd);

void
instr_being_modified(instr_t *instr, bool raw_bits_valid);

/**
 * Assumes that \p cti_instr is a control transfer instruction
 * Returns the first source operand of \p cti_instr (its target).
 */
opnd_t 
instr_get_target(instr_t *cti_instr);

/**
 * Assumes that \p cti_instr is a control transfer instruction.
 * Sets the first source operand of \p cti_instr to be \p target.
 * Also calls instr_set_raw_bits_valid(\p instr, false) and
 * instr_set_operands_valid(\p instr, true).
 */
void 
instr_set_target(instr_t *cti_instr, opnd_t target);

/** Returns true iff \p instr's operands are up to date. */
bool 
instr_operands_valid(instr_t *instr);

/** Sets \p instr's operands to be valid if \p valid is true, invalid otherwise. */
void 
instr_set_operands_valid(instr_t *instr, bool valid);

/**
 * Returns true iff \p instr's opcode is valid.
 * If the opcode is ever set to other than OP_INVALID or OP_UNDECODED it is assumed
 * to be valid.  However, calling instr_get_opcode() will attempt to
 * decode a valid opcode, hence the purpose of this routine.
 */
bool 
instr_opcode_valid(instr_t *instr);

/** Returns \p instr's eflags use as EFLAGS_ constants or'ed together. */
uint 
instr_get_eflags(instr_t *instr);

/** Returns the eflags usage of instructions with opcode \p opcode,
 * as EFLAGS_ constants or'ed together.
 */
uint 
instr_get_opcode_eflags(int opcode);

/**
 * Returns \p instr's arithmetic flags (bottom 6 eflags) use 
 * as EFLAGS_ constants or'ed together.
 * If \p instr's eflags behavior has not been calculated yet or is
 * invalid, the entire eflags use is calculated and returned (not
 * just the arithmetic flags).
 */
uint 
instr_get_arith_flags(instr_t *instr);

/**
 * Assumes that \p instr does not currently have any raw bits allocated.
 * Sets \p instr's raw bits to be \p length bytes starting at \p addr.
 * Does not set the operands invalid.
 */
void 
instr_set_raw_bits(instr_t *instr, byte * addr, uint length);

/** Sets \p instr's raw bits to be valid if \p valid is true, invalid otherwise. */
void 
instr_set_raw_bits_valid(instr_t *instr, bool valid);

/** Returns true iff \p instr's raw bits are a valid encoding of instr. */
bool 
instr_raw_bits_valid(instr_t *instr);

/** Returns true iff \p instr has its own allocated memory for raw bits. */
bool 
instr_has_allocated_bits(instr_t *instr);

/** Returns true iff \p instr's raw bits are not a valid encoding of \p instr. */
bool 
instr_needs_encoding(instr_t *instr);

/**
 * Return true iff \p instr is not a meta-instruction that can fault
 * (see instr_set_meta_may_fault() for more information).
 */
bool
instr_is_meta_may_fault(instr_t *instr);

/**
 * Sets \p instr as a "meta-instruction that can fault" if \p val is
 * true and clears that property if \p val is false.  This property is
 * only meaningful for instructions that are marked as "ok to mangle"
 * (see instr_set_ok_to_mangle()).  Normally such instructions are
 * treated as application instructions (i.e., not as
 * meta-instructions).  The "meta-instruction that can fault" property
 * indicates that an instruction should be treated as an application
 * instruction for purposes of fault translation, but not for purposes
 * of mangling.  The property should only be set for instructions that
 * do not access application memory and therefore do not need
 * sandboxing to ensure they do not change application code, yet do
 * access client memory and may deliberately fault (usually to move a
 * rare case out of the code path and to a fault-based path).
 */
void
instr_set_meta_may_fault(instr_t *instr, bool val);

/**
 * Allocates \p num_bytes of memory for \p instr's raw bits.
 * If \p instr currently points to raw bits, the allocated memory is
 * initialized with the bytes pointed to.
 * \p instr is then set to point to the allocated memory.
 */
void 
instr_allocate_raw_bits(void *drcontext, instr_t *instr, uint num_bytes);

/**
 * Sets the translation pointer for \p instr, used to recreate the
 * application address corresponding to this instruction.  When adding
 * or modifying instructions that are to be considered application
 * instructions (i.e., non meta-instructions: see
 * #instr_ok_to_mangle), the translation should always be set.  Pick
 * the application address that if executed will be equivalent to
 * restarting \p instr.
 * Returns the supplied \p instr (for easy chaining).  Use
 * #instr_get_app_pc to see the current value of the translation.
 */
instr_t * 
instr_set_translation(instr_t *instr, app_pc addr);

/**
 * Calling this function with \p instr makes it safe to keep the
 * instruction around indefinitely when its raw bits point into the
 * cache.  The function allocates memory local to \p instr to hold a
 * copy of the raw bits. If this was not done, the original raw bits
 * could be deleted at some point.  Making an instruction persistent
 * is necessary if you want to keep it beyond returning from the call
 * that produced the instruction.
 */
void
instr_make_persistent(void *drcontext, instr_t *instr);

/**
 * Assumes that \p instr's raw bits are valid.
 * Returns a pointer to \p instr's raw bits.
 * \note A freshly-decoded instruction has valid raw bits that point to the
 * address from which it was decoded.
 */
byte *
instr_get_raw_bits(instr_t *instr);

/** If \p instr has raw bits allocated, frees them. */
void
instr_free_raw_bits(void *drcontext, instr_t *instr);

/**
 * Assumes that \p instr's raw bits are valid and have > \p pos bytes.
 * Returns a pointer to \p instr's raw byte at position \p pos (beginning with 0).
 */
byte 
instr_get_raw_byte(instr_t *instr, uint pos);

/**
 * Assumes that \p instr's raw bits are valid and allocated by \p instr
 * and have > \p pos bytes.
 * Sets instr's raw byte at position \p pos (beginning with 0) to the value \p byte.
 */
void 
instr_set_raw_byte(instr_t *instr, uint pos, byte byte);

/**
 * Assumes that \p instr's raw bits are valid and allocated by \p instr
 * and have >= num_bytes bytes.
 * Copies the \p num_bytes beginning at start to \p instr's raw bits.
 */
void 
instr_set_raw_bytes(instr_t *instr, byte *start, uint num_bytes);

/**
 * Assumes that \p instr's raw bits are valid and allocated by \p instr
 * and have > pos+3 bytes.
 * Sets the 4 bytes beginning at position \p pos (0-based) to the value word.
 */
void 
instr_set_raw_word(instr_t *instr, uint pos, uint word);

/**
 * Assumes that \p instr's raw bits are valid and have > \p pos + 3 bytes.
 * Returns the 4 bytes beginning at position \p pos (0-based).
 */
uint 
instr_get_raw_word(instr_t *instr, uint pos);

/**
 * Assumes that \p prefix is a PREFIX_ constant.
 * Ors \p instr's prefixes with \p prefix.
 * Returns the supplied instr (for easy chaining).
 */
instr_t *
instr_set_prefix_flag(instr_t *instr, uint prefix);

/**
 * Assumes that \p prefix is a PREFIX_ constant.
 * Returns true if \p instr's prefixes contain the flag \p prefix.
 */
bool 
instr_get_prefix_flag(instr_t *instr, uint prefix);

uint 
instr_get_prefixes(instr_t *instr);
#ifdef X64


/**
 * Each instruction stores whether it should be interpreted in 32-bit
 * (x86) or 64-bit (x64) mode.  This routine sets the mode for \p instr.
 *
 * \note For 64-bit DR builds only.
 */
void
instr_set_x86_mode(instr_t *instr, bool x86);

/**
 * Returns true if \p instr is an x86 instruction (32-bit) and false
 * if \p instr is an x64 instruction (64-bit).
 *
 * \note For 64-bit DR builds only.
 */
bool 
instr_get_x86_mode(instr_t *instr);
#endif


/**
 * Shrinks all registers not used as addresses, and all immed integer and
 * address sizes, to 16 bits.
 * Does not shrink DR_REG_ESI or DR_REG_EDI used in string instructions.
 */
void 
instr_shrink_to_16_bits(instr_t *instr);
#ifdef X64


/**
 * Shrinks all registers, including addresses, and all immed integer and
 * address sizes, to 32 bits.
 *
 * \note For 64-bit DR builds only.
 */
void 
instr_shrink_to_32_bits(instr_t *instr);
#endif


/**
 * Assumes that \p reg is a DR_REG_ constant.
 * Returns true iff at least one of \p instr's operands references a
 * register that overlaps \p reg.
 */
bool 
instr_uses_reg(instr_t *instr, reg_id_t reg);

/**
 * Returns true iff at least one of \p instr's operands references a floating
 * point register.
 */
bool 
instr_uses_fp_reg(instr_t *instr);

/**
 * Assumes that \p reg is a DR_REG_ constant.
 * Returns true iff at least one of \p instr's source operands references \p reg.
 *
 * \note Use instr_reads_from_reg() to also consider addressing
 * registers in destination operands.
 */
bool 
instr_reg_in_src(instr_t *instr, reg_id_t reg);

/**
 * Assumes that \p reg is a DR_REG_ constant.
 * Returns true iff at least one of \p instr's destination operands references \p reg.
 */
bool 
instr_reg_in_dst(instr_t *instr, reg_id_t reg);

/**
 * Assumes that \p reg is a DR_REG_ constant.
 * Returns true iff at least one of \p instr's destination operands is
 * a register operand for a register that overlaps \p reg.
 */
bool 
instr_writes_to_reg(instr_t *instr, reg_id_t reg);

/**
 * Assumes that reg is a DR_REG_ constant.
 * Returns true iff at least one of instr's operands reads
 * from a register that overlaps reg (checks both source operands
 * and addressing registers used in destination operands).
 */
bool 
instr_reads_from_reg(instr_t *instr, reg_id_t reg);

/**
 * Assumes that \p reg is a DR_REG_ constant.
 * Returns true iff at least one of \p instr's destination operands is
 * the same register (not enough to just overlap) as \p reg.
 */
bool
instr_writes_to_exact_reg(instr_t *instr, reg_id_t reg);

/**
 * Replaces all instances of \p old_opnd in \p instr's source operands with
 * \p new_opnd (uses opnd_same() to detect sameness).
 */
bool 
instr_replace_src_opnd(instr_t *instr, opnd_t old_opnd, opnd_t new_opnd);

/**
 * Returns true iff \p instr1 and \p instr2 have the same opcode, prefixes,
 * and source and destination operands (uses opnd_same() to compare the operands).
 */
bool 
instr_same(instr_t *instr1, instr_t *instr2);

/** Returns true iff any of \p instr's source operands is a memory reference. */
bool 
instr_reads_memory(instr_t *instr);

/** Returns true iff any of \p instr's destination operands is a memory reference. */
bool 
instr_writes_memory(instr_t *instr);
#ifdef X64


/**
 * Returns true iff any of \p instr's operands is a rip-relative memory reference. 
 *
 * \note For 64-bit DR builds only.
 */
bool 
instr_has_rel_addr_reference(instr_t *instr);

/**
 * If any of \p instr's operands is a rip-relative memory reference, returns the
 * address that reference targets.  Else returns false.
 *
 * \note For 64-bit DR builds only.
 */
bool
instr_get_rel_addr_target(instr_t *instr, /*OUT*/ app_pc *target);

/**
 * If any of \p instr's destination operands is a rip-relative memory
 * reference, returns the operand position.  If there is no such
 * destination operand, returns -1.
 *
 * \note For 64-bit DR builds only.
 */
int
instr_get_rel_addr_dst_idx(instr_t *instr);

/**
 * If any of \p instr's source operands is a rip-relative memory
 * reference, returns the operand position.  If there is no such
 * source operand, returns -1.
 *
 * \note For 64-bit DR builds only.
 */
int
instr_get_rel_addr_src_idx(instr_t *instr);
#endif /* X64 */


/**
 * Returns NULL if none of \p instr's operands is a memory reference.
 * Otherwise, returns the effective address of the first memory operand
 * when the operands are considered in this order: destinations and then
 * sources.  The address is computed using the passed-in registers.
 */
app_pc
instr_compute_address(instr_t *instr, dr_mcontext_t *mc);

/**
 * Performs address calculation in the same manner as
 * instr_compute_address() but handles multiple memory operands.  The
 * \p index parameter should be initially set to 0 and then
 * incremented with each successive call until this routine returns
 * false, which indicates that there are no more memory operands.  The
 * address of each is computed in the same manner as
 * instr_compute_address() and returned in \p addr; whether it is a
 * write is returned in \p is_write.  Either or both OUT variables can
 * be NULL.
 */
bool
instr_compute_address_ex(instr_t *instr, dr_mcontext_t *mc, uint index,
                         OUT app_pc *addr, OUT bool *write);

/**
 * Calculates the size, in bytes, of the memory read or write of \p instr.
 * If \p instr does not reference memory, or is invalid, returns 0.
 * If \p instr is a repeated string instruction, considers only one iteration.
 */
uint
instr_memory_reference_size(instr_t *instr);

/**
 * Returns true iff \p instr is an IA-32 "mov" instruction: either OP_mov_st,
 * OP_mov_ld, OP_mov_imm, OP_mov_seg, or OP_mov_priv.
 */
bool 
instr_is_mov(instr_t *instr);

/**
 * Returns true iff \p instr's opcode is OP_call, OP_call_far, OP_call_ind,
 * or OP_call_far_ind.
 */
bool 
instr_is_call(instr_t *instr);

/** Returns true iff \p instr's opcode is OP_call or OP_call_far. */
bool 
instr_is_call_direct(instr_t *instr);

/** Returns true iff \p instr's opcode is OP_call_ind or OP_call_far_ind. */
bool 
instr_is_call_indirect(instr_t *instr);

/** Returns true iff \p instr's opcode is OP_ret, OP_ret_far, or OP_iret. */
bool 
instr_is_return(instr_t *instr);

/** Returns true iff \p instr's opcode is OP_iret, OP_sysret, or OP_sysexit. Only meaningful
 * when running in the kernel (see LINUX_KERNEL builds). 
 */
bool
instr_may_return_to_user(instr_t *instr);

/**
 * Returns true iff \p instr is a control transfer instruction of any kind
 * This includes OP_jcc, OP_jcc_short, OP_loop*, OP_jecxz, OP_call*, and OP_jmp*.
 */
bool 
instr_is_cti(instr_t *instr);

/**
 * Returns true iff \p instr is a control transfer instruction that takes an
 * 8-bit offset: OP_loop*, OP_jecxz, OP_jmp_short, or OP_jcc_short
 */
bool 
instr_is_cti_short(instr_t *instr);

/** Returns true iff \p instr is one of OP_loop* or OP_jecxz. */
bool 
instr_is_cti_loop(instr_t *instr);

/**
 * Returns true iff \p instr's opcode is OP_loop* or OP_jecxz and instr has
 * been transformed to a sequence of instruction that will allow a 32-bit
 * offset.
 * If \p pc != NULL, \p pc is expected to point the the beginning of the encoding of
 * \p instr, and the following instructions are assumed to be encoded in sequence
 * after \p instr.
 * Otherwise, the encoding is expected to be found in \p instr's allocated bits.
 */
bool 
instr_is_cti_short_rewrite(instr_t *instr, byte *pc);

/**
 * Returns true iff \p instr is a conditional branch: OP_jcc, OP_jcc_short,
 * OP_loop*, or OP_jecxz.
 */
bool 
instr_is_cbr(instr_t *instr);

/**
 * Returns true iff \p instr is a multi-way (indirect) branch: OP_jmp_ind,
 * OP_call_ind, OP_ret, OP_jmp_far_ind, OP_call_far_ind, OP_ret_far, or
 * OP_iret.
 */
bool 
instr_is_mbr(instr_t *instr);

/**
 * Returns true iff \p instr is an unconditional direct branch: OP_jmp,
 * OP_jmp_short, or OP_jmp_far.
 */
bool 
instr_is_ubr(instr_t *instr);

/**
 * Returns true iff \p instr is a far control transfer instruction: OP_jmp_far,
 * OP_call_far, OP_jmp_far_ind, OP_call_far_ind, OP_ret_far, or OP_iret.
 */
bool 
instr_is_far_cti(instr_t *instr);

/** Returns true if \p instr is an absolute call or jmp that is far. */
bool 
instr_is_far_abs_cti(instr_t *instr);

/**
 * Returns true iff \p instr is used to implement system calls: OP_int with a
 * source operand of 0x80 on linux or 0x2e on windows, or OP_sysenter,
 * or OP_syscall, or #instr_is_wow64_syscall() for WOW64.
 */
bool 
instr_is_syscall(instr_t *instr);
#ifdef WINDOWS 


/**
 * Returns true iff \p instr is the indirect transfer from the 32-bit
 * ntdll.dll to the wow64 system call emulation layer.  This
 * instruction will also return true for instr_is_syscall, as well as
 * appear as an indirect call, so clients modifying indirect calls may
 * want to avoid modifying this type.
 *
 * \note Windows-only
 */
bool
instr_is_wow64_syscall(instr_t *instr);
#endif


/**
 * Returns true iff \p instr is a prefetch instruction: OP_prefetchnta,
 * OP_prefetchnt0, OP_prefetchnt1, OP_prefetchnt2, OP_prefetch, or
 * OP_prefetchw.
 */
bool 
instr_is_prefetch(instr_t *instr);

/**
 * Tries to identify common cases of moving a constant into either a
 * register or a memory address.
 * Returns true and sets \p *value to the constant being moved for the following
 * cases: mov_imm, mov_st, and xor where the source equals the destination.
 */
bool 
instr_is_mov_constant(instr_t *instr, ptr_int_t *value);

/** Returns true iff \p instr is a floating point instruction. */
bool 
instr_is_floating(instr_t *instr);

/** Returns true iff \p instr is part of Intel's MMX instructions. */
bool 
instr_is_mmx(instr_t *instr);

/** Returns true iff \p instr is part of Intel's SSE or SSE2 instructions. */
bool 
instr_is_sse_or_sse2(instr_t *instr);

/** Returns true iff \p instr is a "mov $imm -> (%esp)". */
bool 
instr_is_mov_imm_to_tos(instr_t *instr);

/** Returns true iff \p instr is a label meta-instruction. */
bool 
instr_is_label(instr_t *instr);

/** Returns true iff \p instr is an "undefined" instruction (ud2) */
bool 
instr_is_undefined(instr_t *instr);

bool
instr_is_stringop_loop(instr_t *instr);

bool
instr_is_stringop(instr_t *instr);

/**
 * Assumes that \p instr's opcode is OP_int and that either \p instr's
 * operands or its raw bits are valid.
 * Returns the first source operand if \p instr's operands are valid,
 * else if \p instr's raw bits are valid returns the first raw byte.
 */
int 
instr_get_interrupt_number(instr_t *instr);

/**
 * Assumes that \p instr is a conditional branch instruction
 * Reverses the logic of \p instr's conditional
 * e.g., changes OP_jb to OP_jnb.
 * Works on cti_short_rewrite as well.
 */
void 
instr_invert_cbr(instr_t *instr);

/**
 * Assumes that instr is a meta instruction (!instr_ok_to_mangle())
 * and an instr_is_cti_short() (8-bit reach).  Converts instr's opcode
 * to a long form (32-bit reach).  If instr's opcode is OP_loop* or
 * OP_jecxz, converts it to a sequence of multiple instructions (which
 * is different from instr_is_cti_short_rewrite()).  Each added instruction
 * is marked !instr_ok_to_mangle().
 * Returns the long form of the instruction, which is identical to \p instr
 * unless \p instr is OP_loop* or OP_jecxz, in which case the return value
 * is the final instruction in the sequence, the one that has long reach.
 * \note DR automatically converts non-meta short ctis to long form.
 */
instr_t *
instr_convert_short_meta_jmp_to_long(void *drcontext, instrlist_t *ilist,
                                     instr_t *instr);

/** 
 * Given \p eflags, returns whether or not the conditional branch, \p
 * instr, would be taken.
 */
bool
instr_jcc_taken(instr_t *instr, reg_t eflags);

/**
 * Converts a cmovcc opcode \p cmovcc_opcode to the OP_jcc opcode that
 * tests the same bits in eflags.
 */
int
instr_cmovcc_to_jcc(int cmovcc_opcode);

/**
 * Given \p eflags, returns whether or not the conditional move
 * instruction \p instr would execute the move.  The conditional move
 * can be an OP_cmovcc or an OP_fcmovcc instruction.
 */
bool
instr_cmovcc_triggered(instr_t *instr, reg_t eflags);

/**
 * Returns true if \p instr is one of a class of common nops.
 * currently checks:
 * - xchg reg, reg
 * - mov reg, reg
 * - lea reg, (reg)
 */
bool 
instr_is_nop(instr_t *instr);

/**
 * Convenience routine that returns an initialized instr_t allocated on the
 * thread-local heap with opcode \p opcode and no sources or destinations.
 */
instr_t *
instr_create_0dst_0src(void *drcontext, int opcode);

/**
 * Convenience routine that returns an initialized instr_t allocated on the
 * thread-local heap with opcode \p opcode and a single source (\p src).
 */
instr_t *
instr_create_0dst_1src(void *drcontext, int opcode,
                       opnd_t src);

/**
 * Convenience routine that returns an initialized instr_t allocated on the
 * thread-local heap with opcode \p opcode and two sources (\p src1, \p src2).
 */
instr_t *
instr_create_0dst_2src(void *drcontext, int opcode,
                       opnd_t src1, opnd_t src2);

/**
 * Convenience routine that returns an initialized instr_t allocated
 * on the thread-local heap with opcode \p opcode and three sources
 * (\p src1, \p src2, \p src3).
 */
instr_t * 
instr_create_0dst_3src(void *drcontext, int opcode,
                       opnd_t src1, opnd_t src2, opnd_t src3);

/**
 * Convenience routine that returns an initialized instr_t allocated on the
 * thread-local heap with opcode \p opcode and one destination (\p dst).
 */
instr_t *
instr_create_1dst_0src(void *drcontext, int opcode,
                       opnd_t dst);

/**
 * Convenience routine that returns an initialized instr_t allocated on the
 * thread-local heap with opcode \p opcode, one destination(\p dst),
 * and one source (\p src).
 */
instr_t *
instr_create_1dst_1src(void *drcontext, int opcode,
                       opnd_t dst, opnd_t src);

/**
 * Convenience routine that returns an initialized instr_t allocated on the
 * thread-local heap with opcode \p opcode, one destination (\p dst),
 * and two sources (\p src1, \p src2).
 */
instr_t *
instr_create_1dst_2src(void *drcontext, int opcode,
                       opnd_t dst, opnd_t src1, opnd_t src2);

/**
 * Convenience routine that returns an initialized instr_t allocated on the
 * thread-local heap with opcode \p opcode, one destination (\p dst),
 * and three sources (\p src1, \p src2, \p src3).
 */
instr_t *
instr_create_1dst_3src(void *drcontext, int opcode,
                       opnd_t dst, opnd_t src1, opnd_t src2, opnd_t src3);

/**
 * Convenience routine that returns an initialized instr_t allocated on the
 * thread-local heap with opcode \p opcode, one destination (\p dst),
 * and five sources (\p src1, \p src2, \p src3, \p src4, \p src5).
 */
instr_t * 
instr_create_1dst_5src(void *drcontext, int opcode,
                       opnd_t dst, opnd_t src1, opnd_t src2, opnd_t src3,
                       opnd_t src4, opnd_t src5);

/**
 * Convenience routine that returns an initialized instr_t allocated on the
 * thread-local heap with opcode \p opcode, two destinations (\p dst1, \p dst2)
 * and no sources.
 */
instr_t *
instr_create_2dst_0src(void *drcontext, int opcode,
                       opnd_t dst1, opnd_t dst2);

/**
 * Convenience routine that returns an initialized instr_t allocated on the
 * thread-local heap with opcode \p opcode, two destinations (\p dst1, \p dst2)
 * and one source (\p src).
 */
instr_t *
instr_create_2dst_1src(void *drcontext, int opcode,
                       opnd_t dst1, opnd_t dst2, opnd_t src);

/**
 * Convenience routine that returns an initialized instr_t allocated on the
 * thread-local heap with opcode \p opcode, two destinations (\p dst1, \p dst2)
 * and two sources (\p src1, \p src2).
 */
instr_t *
instr_create_2dst_2src(void *drcontext, int opcode,
                       opnd_t dst1, opnd_t dst2, opnd_t src1, opnd_t src2);

/**
 * Convenience routine that returns an initialized instr_t allocated on the
 * thread-local heap with opcode \p opcode, two destinations (\p dst1, \p dst2)
 * and three sources (\p src1, \p src2, \p src3).
 */
instr_t *
instr_create_2dst_3src(void *drcontext, int opcode,
                       opnd_t dst1, opnd_t dst2,
                       opnd_t src1, opnd_t src2, opnd_t src3);

/**
 * Convenience routine that returns an initialized instr_t allocated on the
 * thread-local heap with opcode \p opcode, two destinations (\p dst1, \p dst2)
 * and four sources (\p src1, \p src2, \p src3, \p src4).
 */
instr_t *
instr_create_2dst_4src(void *drcontext, int opcode,
                       opnd_t dst1, opnd_t dst2,
                       opnd_t src1, opnd_t src2, opnd_t src3, opnd_t src4);

/**
 * Convenience routine that returns an initialized instr_t allocated
 * on the thread-local heap with opcode \p opcode, three destinations
 * (\p dst1, \p dst2, \p dst3) and no sources.
 */
instr_t *
instr_create_3dst_0src(void *drcontext, int opcode,
                       opnd_t dst1, opnd_t dst2, opnd_t dst3);

/**
 * Convenience routine that returns an initialized instr_t allocated
 * on the thread-local heap with opcode \p opcode, three destinations
 * (\p dst1, \p dst2, \p dst3) and three sources 
 * (\p src1, \p src2, \p src3).
 */
instr_t *
instr_create_3dst_3src(void *drcontext, int opcode,
                       opnd_t dst1, opnd_t dst2, opnd_t dst3,
                       opnd_t src1, opnd_t src2, opnd_t src3);

/**
 * Convenience routine that returns an initialized instr_t allocated
 * on the thread-local heap with opcode \p opcode, three destinations
 * (\p dst1, \p dst2, \p dst3) and four sources 
 * (\p src1, \p src2, \p src3, \p src4).
 */
instr_t *
instr_create_3dst_4src(void *drcontext, int opcode,
                       opnd_t dst1, opnd_t dst2, opnd_t dst3,
                       opnd_t src1, opnd_t src2, opnd_t src3, opnd_t src4);

/**
 * Convenience routine that returns an initialized instr_t allocated
 * on the thread-local heap with opcode \p opcode, three destinations
 * (\p dst1, \p dst2, \p dst3) and five sources
 * (\p src1, \p src2, \p src3, \p src4, \p src5).
 */
instr_t *
instr_create_3dst_5src(void *drcontext, int opcode,
                       opnd_t dst1, opnd_t dst2, opnd_t dst3,
                       opnd_t src1, opnd_t src2, opnd_t src3,
                       opnd_t src4, opnd_t src5);

/**
 * Convenience routine that returns an initialized instr_t allocated
 * on the thread-local heap with opcode \p opcode, four destinations
 * (\p dst1, \p dst2, \p dst3, \p dst4) and 1 source (\p src).
 */
instr_t *
instr_create_4dst_1src(void *drcontext, int opcode,
                       opnd_t dst1, opnd_t dst2, opnd_t dst3, opnd_t dst4,
                       opnd_t src);

/**
 * Convenience routine that returns an initialized instr_t allocated
 * on the thread-local heap with opcode \p opcode, four destinations
 * (\p dst1, \p dst2, \p dst3, \p dst4) and four sources
 * (\p src1, \p src2, \p src3, \p src4).
 */
instr_t *
instr_create_4dst_4src(void *drcontext, int opcode,
                       opnd_t dst1, opnd_t dst2, opnd_t dst3, opnd_t dst4,
                       opnd_t src1, opnd_t src2, opnd_t src3, opnd_t src4);

/** Convenience routine that returns an initialized instr_t for OP_popa. */
instr_t *
instr_create_popa(void *drcontext);

/** Convenience routine that returns an initialized instr_t for OP_pusha. */
instr_t *
instr_create_pusha(void *drcontext);


/****************************************************************************
 * EFLAGS
 */
/* we only care about these 11 flags, and mostly only about the first 6
 * we consider an undefined effect on a flag to be a write
 */
#define EFLAGS_READ_CF   0x00000001 /**< Reads CF (Carry Flag). */             
#define EFLAGS_READ_PF   0x00000002 /**< Reads PF (Parity Flag). */            
#define EFLAGS_READ_AF   0x00000004 /**< Reads AF (Auxiliary Carry Flag). */   
#define EFLAGS_READ_ZF   0x00000008 /**< Reads ZF (Zero Flag). */              
#define EFLAGS_READ_SF   0x00000010 /**< Reads SF (Sign Flag). */              
#define EFLAGS_READ_TF   0x00000020 /**< Reads TF (Trap Flag). */              
#define EFLAGS_READ_IF   0x00000040 /**< Reads IF (Interrupt Enable Flag). */  
#define EFLAGS_READ_DF   0x00000080 /**< Reads DF (Direction Flag). */         
#define EFLAGS_READ_OF   0x00000100 /**< Reads OF (Overflow Flag). */          
#define EFLAGS_READ_NT   0x00000200 /**< Reads NT (Nested Task). */            
#define EFLAGS_READ_RF   0x00000400 /**< Reads RF (Resume Flag). */            
#define EFLAGS_WRITE_CF  0x00000800 /**< Writes CF (Carry Flag). */             
#define EFLAGS_WRITE_PF  0x00001000 /**< Writes PF (Parity Flag). */            
#define EFLAGS_WRITE_AF  0x00002000 /**< Writes AF (Auxiliary Carry Flag). */   
#define EFLAGS_WRITE_ZF  0x00004000 /**< Writes ZF (Zero Flag). */              
#define EFLAGS_WRITE_SF  0x00008000 /**< Writes SF (Sign Flag). */              
#define EFLAGS_WRITE_TF  0x00010000 /**< Writes TF (Trap Flag). */              
#define EFLAGS_WRITE_IF  0x00020000 /**< Writes IF (Interrupt Enable Flag). */  
#define EFLAGS_WRITE_DF  0x00040000 /**< Writes DF (Direction Flag). */         
#define EFLAGS_WRITE_OF  0x00080000 /**< Writes OF (Overflow Flag). */          
#define EFLAGS_WRITE_NT  0x00100000 /**< Writes NT (Nested Task). */            
#define EFLAGS_WRITE_RF  0x00200000 /**< Writes RF (Resume Flag). */            

#define EFLAGS_READ_ALL  0x000007ff /**< Reads all flags. */    
#define EFLAGS_WRITE_ALL 0x003ff800 /**< Writes all flags. */   
/* 6 most common flags ("arithmetic flags"): CF, PF, AF, ZF, SF, OF */
/** Reads all 6 arithmetic flags (CF, PF, AF, ZF, SF, OF). */ 
#define EFLAGS_READ_6    0x0000011f
/** Writes all 6 arithmetic flags (CF, PF, AF, ZF, SF, OF). */ 
#define EFLAGS_WRITE_6   0x0008f800

/** Converts an EFLAGS_WRITE_* value to the corresponding EFLAGS_READ_* value. */
#define EFLAGS_WRITE_TO_READ(x) ((x) >> 11)
/** Converts an EFLAGS_READ_* value to the corresponding EFLAGS_WRITE_* value. */
#define EFLAGS_READ_TO_WRITE(x) ((x) << 11)

/**
 * The actual bits in the eflags register that we care about:\n<pre>
 *   11 10  9  8  7  6  5  4  3  2  1  0
 *   OF DF IF    SF ZF    AF    PF    CF  </pre>
 */
enum {
    EFLAGS_CF = 0x00000001, /**< The bit in the eflags register of CF (Carry Flag). */
    EFLAGS_PF = 0x00000004, /**< The bit in the eflags register of PF (Parity Flag). */
    EFLAGS_AF = 0x00000010, /**< The bit in the eflags register of AF (Aux Carry Flag). */
    EFLAGS_ZF = 0x00000040, /**< The bit in the eflags register of ZF (Zero Flag). */
    EFLAGS_SF = 0x00000080, /**< The bit in the eflags register of SF (Sign Flag). */
    EFLAGS_IF = 0x00000200, /**< The bit in the eflags register of IF (Interrupt Enable Flag). */
    EFLAGS_DF = 0x00000400, /**< The bit in the eflags register of DF (Direction Flag). */
    EFLAGS_OF = 0x00000800, /**< The bit in the eflags register of OF (Overflow Flag). */
    EFLAGS_NT = 0x00004000, /**< The bit in the eflags register of NT (Nested Task Flag). */
    EFLAGS_NON_SYSTEM = EFLAGS_CF | EFLAGS_PF | EFLAGS_AF | EFLAGS_ZF |
                        EFLAGS_SF | EFLAGS_DF | EFLAGS_OF,
    /**< The bit positions of the non-system flags: CF, PF, AF, ZF, SF, DF, and
     * OF. */
    EFLAGS_SYSTEM = ~EFLAGS_NON_SYSTEM,
    /**< The bit positions of the system flags: ID, VIP, VIF, AC, VM, RF, NT,
     * IOPL, IF, and TF. */
     EFLAGS_AHF = EFLAGS_SF | EFLAGS_ZF | EFLAGS_AF | EFLAGS_PF | EFLAGS_CF,
    /**< The bit positions of the flags used by sahf and lahf: CF, PF, AF, ZF,
     * and SF  . */
};



/****************************************************************************
 * instr_t prefixes
 *
 * Note that prefixes that change the data or address size, or that
 * specify a different base segment, are not specified on a
 * whole-instruction level, but rather on individual operands (of
 * course with multiple operands they must all match).
 * The rep and repne prefixes are encoded directly into the opcodes.
 * 
 */
#define PREFIX_LOCK           0x1 /**< Makes the instruction's memory accesses atomic. */
#define PREFIX_JCC_NOT_TAKEN  0x2 /**< Branch hint: conditional branch is taken. */
#define PREFIX_JCC_TAKEN      0x4 /**< Branch hint: conditional branch is not taken. */



/**
 * Prints the instruction \p instr to file \p outfile. 
 * Does not print address-size or data-size prefixes for other than
 * just-decoded instrs, and does not check that the instruction has a
 * valid encoding.  Prints each operand with leading zeros indicating
 * the size.
 * The default is to use AT&T-style syntax, unless the \ref op_syntax_intel
 * "-syntax_intel" runtime option is specified.
 */
void 
instr_disassemble(void *drcontext, instr_t *instr, file_t outfile);

#endif /* _DR_IR_INSTR_H_ */
