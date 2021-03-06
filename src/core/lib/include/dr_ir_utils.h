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

#ifndef _DR_IR_UTILS_H_
#define _DR_IR_UTILS_H_ 1

#ifdef X64


/**
 * The decode and encode routines use a per-thread persistent flag that
 * indicates whether to treat code as 32-bit (x86) or 64-bit (x64).  This
 * routine sets that flag to the indicated value and returns the old value.  Be
 * sure to restore the old value prior to any further application execution to
 * avoid problems in mis-interpreting application code.
 *
 * \note For 64-bit DR builds only.
 */
bool
set_x86_mode(void *drcontext, bool x86);

/**
 * The decode and encode routines use a per-thread persistent flag that
 * indicates whether to treat code as 32-bit (x86) or 64-bit (x64).  This
 * routine returns the value of that flag.
 *
 * \note For 64-bit DR builds only.
 */
bool
get_x86_mode(void *drcontext);
#endif


/**************************************************
 * CODE TRANSFORMATION UTILITIES
 */
/**
 * @file dr_ir_utils.h
 * @brief Code transformation utilities.
 */

/**
 * An enum of spill slots to use with dr_save_reg(), dr_restore_reg(),
 * dr_save_arith_flags(), dr_restore_arith_flags() and
 * dr_insert_mbr_instrumentation().  Values stored in spill slots remain
 * valid only until the next non-meta (i.e. application) instruction.  Spill slots
 * can be accessed/modifed during clean calls and restore_state_events (see
 * dr_register_restore_state_event()) with dr_read_saved_reg() and
 * dr_write_saved_reg().
 *
 * Spill slots <= dr_max_opnd_accessible_spill_slot() can be directly accessed
 * from client inserted instructions with dr_reg_spill_slot_opnd().
 *
 * \note Some spill slots may be faster to access than others.  Currently spill
 * slots 1-3 are significantly faster to access than the others when running
 * without -thread_private.  When running with -thread_private all spill slots
 * are expected to have similar performance.  This is subject to change in future
 * releases, but clients may assume that smaller numbered spill slots are faster
 * or the same cost to access as larger numbered spill slots.
 *
 * \note The number of spill slots may change in future releases.
 */
typedef enum {
    SPILL_SLOT_1  =  0,  /** spill slot for register save/restore routines */
    SPILL_SLOT_2  =  1,  /** spill slot for register save/restore routines */
    SPILL_SLOT_3  =  2,  /** spill slot for register save/restore routines */
    SPILL_SLOT_4  =  3,  /** spill slot for register save/restore routines */
    SPILL_SLOT_5  =  4,  /** spill slot for register save/restore routines */
    SPILL_SLOT_6  =  5,  /** spill slot for register save/restore routines */
    SPILL_SLOT_7  =  6,  /** spill slot for register save/restore routines */
    SPILL_SLOT_8  =  7,  /** spill slot for register save/restore routines */
    SPILL_SLOT_9  =  8,  /** spill slot for register save/restore routines */
#ifdef X64
    SPILL_SLOT_10 =  9,  /** spill slot for register save/restore routines
                          * \note x64 only */
    SPILL_SLOT_11 = 10,  /** spill slot for register save/restore routines
                          * \note x64 only */
    SPILL_SLOT_12 = 11,  /** spill slot for register save/restore routines
                          * \note x64 only */
    SPILL_SLOT_13 = 12,  /** spill slot for register save/restore routines
                          * \note x64 only */
    SPILL_SLOT_14 = 13,  /** spill slot for register save/restore routines
                          * \note x64 only */
    SPILL_SLOT_15 = 14,  /** spill slot for register save/restore routines
                          * \note x64 only */
    SPILL_SLOT_16 = 15,  /** spill slot for register save/restore routines
                          * \note x64 only */
    SPILL_SLOT_17 = 16,  /** spill slot for register save/restore routines
                          * \note x64 only */
    SPILL_SLOT_MAX = SPILL_SLOT_17 /** Enum value of the last register save/restore
                                    *  spill slot. */
#else
    SPILL_SLOT_MAX = SPILL_SLOT_9 /** Enum value of the last register save/restore
                                   *  spill slot. */
#endif
} dr_spill_slot_t;


/**
 * Inserts into \p ilist prior to \p where meta-instruction(s) to save the
 * register \p reg in the spill slot \p slot.  See dr_restore_reg(). Use
 * dr_read_saved_reg() and dr_write_saved_reg() to access spill slots from clean
 * calls and restore_state_events (see dr_register_restore_state_event()).
 * \note The stored value remains available only until the next non-meta (i.e.
 * application) instruction. Use dr_insert_write_tls_field() and
 * dr_insert_read_tls_field() for a persistent (but more costly to access)
 * thread-local-storage location.  See also dr_raw_tls_calloc().
 */
void
dr_save_reg(void *drcontext, instrlist_t *ilist, instr_t *where, reg_id_t reg,
            dr_spill_slot_t slot);

/**
 * Inserts into \p ilist prior to \p where meta-instruction(s) to restore the
 * register \p reg from the spill slot \p slot.  See dr_save_reg() for notes on
 * lifetime and alternative access to spill slots.
 */
void
dr_restore_reg(void *drcontext, instrlist_t *ilist, instr_t *where, reg_id_t reg,
               dr_spill_slot_t slot);

/**
 * Returns the largest dr_spill_slot_t that can be accessed with an opnd_t from
 * dr_reg_spill_slot_opnd().
 */
dr_spill_slot_t
dr_max_opnd_accessible_spill_slot(void);

/**
 * Returns an opnd_t that directly accesses the spill slot \p slot. Only slots
 * <= dr_max_opnd_accessible_spill_slot() can be used with this routine.
 * \note \p slot must be <= dr_max_opnd_accessible_spill_slot()
 */
opnd_t
dr_reg_spill_slot_opnd(void *drcontext, dr_spill_slot_t slot);

/**
 * Can be used from a clean call or a restore_state_event (see
 * dr_register_restore_state_event()) to see the value saved in spill slot
 * \p slot by dr_save_reg().
 */
reg_t
dr_read_saved_reg(void *drcontext, dr_spill_slot_t slot);

/**
 * Can be used from a clean call to modify the value saved in the spill slot
 * \p slot by dr_save_reg() such that a later dr_restore_reg() will see the
 * new value.
 *
 * \note This routine should only be used during a clean call out of the
 * cache.  Use at any other time could corrupt application or \DynamoRIO
 * state.
 */
void
dr_write_saved_reg(void *drcontext, dr_spill_slot_t slot, reg_t value);

/**
 * Inserts into \p ilist prior to \p where meta-instruction(s) to save the 6
 * arithmetic flags into xax after first saving xax to the spill slot \p slot.
 * This is equivalent to dr_save_reg() of xax to \p slot followed by lahf and
 * seto al instructions.  See dr_restore_arith_flags().
 *
 * \note At completion of the inserted instructions the saved flags are in the
 * xax register.  The xax register should not be modified after using this
 * routine unless it is first saved (and later restored prior to
 * using dr_restore_arith_flags()).
 */
void
dr_save_arith_flags(void *drcontext, instrlist_t *ilist, instr_t *where,
                    dr_spill_slot_t slot);

/**
 * Inserts into \p ilist prior to \p where meta-instruction(s) to restore the 6
 * arithmetic flags, assuming they were saved using dr_save_arith_flags() with
 * slot \p slot and that xax holds the same value it did after the save.
 */
void
dr_restore_arith_flags(void *drcontext, instrlist_t *ilist, instr_t *where,
                       dr_spill_slot_t slot);

/** Emulates the effects of
 *  add 7f, al
 *  sahf
 * on eflags to restore eflags from xax. Does not modify xax.
 */
void
dr_emulate_restore_arith_flags(dr_mcontext_t *mcontext);

/**
 * Inserts into \p ilist prior to \p where meta-instruction(s) to read into the
 * general-purpose full-size register \p reg from the user-controlled drcontext
 * field for this thread.  Reads from the same field as dr_get_tls_field().
 */
void
dr_insert_read_tls_field(void *drcontext, instrlist_t *ilist, instr_t *where,
                         reg_id_t reg);

/**
 * Inserts into \p ilist prior to \p where meta-instruction(s) to write the
 * general-purpose full-size register \p reg to the user-controlled drcontext field
 * for this thread.  Writes to the same field as dr_set_tls_field().
 */
void
dr_insert_write_tls_field(void *drcontext, instrlist_t *ilist, instr_t *where,
                          reg_id_t reg);

/** Inserts \p instr as a non-application instruction into \p ilist prior to \p where. */
void
instrlist_meta_preinsert(instrlist_t *ilist, instr_t *where, instr_t *instr);

/** Inserts \p instr as a non-application instruction into \p ilist after \p where. */
void
instrlist_meta_postinsert(instrlist_t *ilist, instr_t *where, instr_t *instr);

/** Inserts \p instr as a non-application instruction onto the end of \p ilist */
void
instrlist_meta_append(instrlist_t *ilist, instr_t *instr);

/**
 * Inserts \p instr as a non-application instruction that can fault (see
 * instr_set_meta_may_fault()) into \p ilist prior to \p where.
 */
void
instrlist_meta_fault_preinsert(instrlist_t *ilist, instr_t *where, instr_t *instr);

/**
 * Inserts \p instr as a non-application instruction that can fault (see
 * instr_set_meta_may_fault()) into \p ilist after \p where.
 */
void
instrlist_meta_fault_postinsert(instrlist_t *ilist, instr_t *where, instr_t *instr);

/**
 * Inserts \p instr as a non-application instruction that can fault (see
 * instr_set_meta_may_fault()) onto the end of \p ilist.
 */
void
instrlist_meta_fault_append(instrlist_t *ilist, instr_t *instr);

/**
 * Inserts into \p ilist prior to \p where meta-instruction(s) to save state
 * for a call, switch to this thread's DR stack, set up the passed-in
 * parameters, make a call to \p callee, clean up the parameters, and
 * then restore the saved state.
 *
 * The callee must use the standard C calling convention that matches the
 * underlying 32-bit or 64-bit binary interface convention ("cdecl"). Other
 * calling conventions, such as "fastcall" and "stdcall", are not supported.
 *
 * Stores the application state information on the DR stack, where it can
 * be accessed from \c callee using dr_get_mcontext() and modified using
 * dr_set_mcontext().
 *
 * If \p save_fpstate is true, preserves the fp/mmx/sse state on the DR stack.
 * Note that it is relatively expensive to save this state (on the
 * order of 200 cycles) and that it typically takes 512 bytes to store
 * it (see proc_fpstate_save_size()).
 *
 * DR does support translating a fault in an argument (e.g., an
 * argument that references application memory); such a fault will be
 * treated as an application exception.
 *
 * \note The stack used to save state and call \p callee is limited to
 * 20KB by default; this can be changed with the -stack_size DR runtime
 * parameter.  This stack cannot be used to store state that persists
 * beyond \c callee's return point.
 *
 * \note This routine only supports passing arguments that are
 * integers or pointers of a size equal to the register size: i.e., no
 * floating-point, multimedia, or aggregate data types.
 * The routine also supports immediate integers that are smaller than
 * the register size, and for 64-bit mode registers or memory references that
 * are OPSZ_4.
 *
 * \note For 64-bit mode, passing arguments that use calling
 * convention registers (for Windows, RCX, RDX, R8, R9; for Linux,
 * RDI, RSI, RDX, RCX, R8 and R9) are supported but may incur
 * additional stack usage.
 *
 * \note For 64-bit mode, if a 32-bit immediate integer is specified as an
 * argument and it has its top bit set, we assume it is intended to be
 * sign-extended to 64-bits; otherwise we zero-extend it.
 *
 * \note For 64-bit mode, variable-sized argument operands may not work
 * properly.
 *
 * \note Arguments that reference sub-register portions of REG_XSP are
 * not supported (full REG_XSP is supported).
 */
void
dr_insert_clean_call(void *drcontext, instrlist_t *ilist, instr_t *where,
                     void *callee, bool save_fpstate, uint num_args, ...);

/**
 * Inserts into \p ilist prior to \p where meta-instruction(s) to set
 * up the passed-in parameters, make a call to \p callee, and clean up
 * the parameters.
 *
 * The callee must use the standard C calling convention that matches the
 * underlying 32-bit or 64-bit binary interface convention ("cdecl"). Other
 * calling conventions, such as "fastcall" and "stdcall", are not supported.
 *
 * This routine uses the existing stack.  In 64-bit mode, this routine assumes
 * that the stack pointer is currently 16-byte aligned.
 *
 * The application state is NOT saved or restored (use dr_prepare_for_call()
 * and dr_cleanup_after_call(), or replace this routine with dr_insert_clean_call()).
 * The parameter set-up may write to registers if the calling convention so
 * dictates.  The registers are NOT saved beforehand (to do so, use
 * dr_insert_clean_call()).
 *
 * It is up to the caller of this routine to preserve caller-saved registers.
 *
 * DR does not support translating a fault in an argument.  For fault
 * transparency, the client must perform the translation (see
 * #dr_register_restore_state_event()), or use
 * #dr_insert_clean_call().
 *
 * \note This routine only supports passing arguments that are
 * integers or pointers of a size equal to the register size: i.e., no
 * floating-point, multimedia, or aggregate data types.
 * The routine also supports immediate integers that are smaller than
 * the register size, and for 64-bit mode registers or memory references that
 * are OPSZ_4.
 *
 * \note For 64-bit mode, passing arguments that use calling
 * convention registers (for Windows, RCX, RDX, R8, R9; for Linux,
 * RDI, RSI, RDX, RCX, R8 and R9) are supported but may incur
 * additional stack usage.
 *
 * \note For 64-bit mode, if a 32-bit immediate integer is specified as an
 * argument and it has its top bit set, we assume it is intended to be
 * sign-extended to 64-bits; otherwise we zero-extend it.
 *
 * \note For 64-bit mode, variable-sized argument operands may not work
 * properly.
 *
 * \note Arguments that reference REG_XSP are not supported in 64-bit mode.
 */
void
dr_insert_call(void *drcontext, instrlist_t *ilist, instr_t *where,
               void *callee, uint num_args, ...);

/**
 * Inserts into \p ilist prior to \p where meta-instruction(s) to save state for a call.
 * Stores the application state information on the DR stack.
 * Returns the size of the data stored on the DR stack (in case the caller
 * needs to align the stack pointer).
 *
 * \warning This routine does NOT save the fp/mmx/sse state: to do that the
 * instrumentation routine should call proc_save_fpstate() to save and
 * then proc_restore_fpstate() to restore (or use dr_insert_clean_call()).
 *
 * \note The preparation modifies the REG_XSP and REG_XAX registers
 * (after saving them).  Use dr_insert_clean_call() instead if an
 * argument to the subsequent call that references REG_XAX is
 * desired.
 *
 * \note The stack used to save the state is limited to
 * 20KB by default; this can be changed with the -stack_size DR runtime
 * parameter.  This stack cannot be used to store state that persists
 * beyond a single clean call, code cache execution, or probe callback
 * function execution.
 */
uint
dr_prepare_for_call(void *drcontext, instrlist_t *ilist, instr_t *instr);

/**
 * Inserts into \p ilist prior to \p where meta-instruction(s) to restore state
 * after a call.
 */
void
dr_cleanup_after_call(void *drcontext, instrlist_t *ilist, instr_t *where,
                      uint sizeof_param_area);

/**
 * Inserts into \p ilist prior to \p where meta-instruction(s) to save the current
 * esp and switch to this thread's DR stack.
 * \note The DR stack is limited to 20KB by default; this can be changed with
 * the -stack_size DR runtime parameter.  This stack cannot be used to store
 * state that persists beyond a single clean call, code cache execution,
 * or probe callback function execution.
 */
void
dr_swap_to_clean_stack(void *drcontext, instrlist_t *ilist, instr_t *where);

/**
 * Inserts into \p ilist prior to \p where meta-instruction(s) to restore into
 * esp the value saved by dr_swap_to_dr_stack().
 */
void
dr_restore_app_stack(void *drcontext, instrlist_t *ilist, instr_t *where);

/**
 * Assumes that \p instr is a near call.
 * Inserts into \p ilist prior to \p instr instruction(s) to call callee passing
 * two arguments:
 * -# address of call instruction (caller)
 * -# target address of call (callee)
 */
void
dr_insert_call_instrumentation(void *drcontext, instrlist_t *ilist,
                               instr_t *instr, void *callee);

/**
 * Assumes that \p instr is an indirect branch.
 * Inserts into \p ilist prior to \p instr instruction(s) to call callee passing
 * two arguments:
 * -# address of branch instruction
 * -# target address of branch
 * \note Only the address portion of a far indirect branch is considered.
 * \note \p scratch_slot must be <= dr_max_opnd_accessible_spill_slot(). \p scratch_slot
 * is used internally to this routine and will be clobbered.
 */
void
dr_insert_mbr_instrumentation(void *drcontext, instrlist_t *ilist,
                              instr_t *instr, void *callee, dr_spill_slot_t scratch_slot);

/**
 * Assumes that \p instr is a conditional branch
 * Inserts into \p ilist prior to \p instr instruction(s) to call callee passing
 * three arguments:
 * -# address of branch instruction
 * -# target address of branch
 * -# 0 if the branch is not taken, 1 if it is taken
 */
void
dr_insert_cbr_instrumentation(void *drcontext, instrlist_t *ilist,
                              instr_t *instr, void *callee);

/**
 * Assumes that \p instr is a direct, near, unconditional branch.
 * Inserts into \p ilist prior to \p instr instruction(s) to call callee passing
 * two arguments:
 * -# address of branch instruction
 * -# target address of branch
 *
 * \warning Basic block eliding is controlled by -max_elide_jmp.  If that
 * option is set to non-zero, ubrs may never be seen.
 */
void
dr_insert_ubr_instrumentation(void *drcontext, instrlist_t *ilist,
                              instr_t *instr, void *callee);

/**
 * Returns true if the xmm0 through xmm5 for Windows, or xmm0 through
 * xmm15 for Linux, fields in dr_mcontext_t are valid for this process
 * (i.e., whether this process is 64-bit or WOW64, and the processor
 * supports SSE).
 */
bool
dr_mcontext_xmm_fields_valid(void);

/**
 * Copies the current application machine context to \p context.
 * This routine may only be called from:
 * - A clean call invoked by dr_insert_clean_call() or dr_prepare_for_call()
 * - A pre- or post-syscall event (dr_register_pre_syscall_event(),
 *   dr_register_post_syscall_event())
 * - Basic block or trace creation events (dr_register_bb_event(),
 *   dr_register_trace_event()), but for basic block creation only when the
 *   basic block callback parameters \p for_trace and \p translating are
 *   false, and for trace creation only when \p translating is false.
 * - A nudge callback (dr_register_nudge_event()) on Linux.
 *   (On Windows nudges happen in separate dedicated threads.)
 * - A thread or process exit event (dr_register_thread_exit_event(),
 *   dr_register_exit_event())
 * - A thread init event (dr_register_thread_init_event()) for all but
 *   the initial thread.
 *
 * Does NOT copy the pc field.  If \p app_errno is non-NULL copies the
 * saved application error code (value of GetLastError() on Windows; ignored
 * on Linux) to \p app_errno.
 *
 * Returns false if called from the init event or the initial thread's
 * init event; returns true otherwise (cannot distinguish whether the
 * caller is in a clean call so it is up to the caller to ensure it is
 * used properly).
 *
 * \note NUM_XMM_SLOTS in the dr_mcontext_t.xmm array are filled in, but
 * only if dr_mcontext_fields_valid() returns true.
 * \note The context is the context saved at the dr_insert_clean_call() or
 * dr_prepare_for_call() points.  It does not correct for any registers saved
 * with dr_save_reg().  To access registers saved with dr_save_reg() from a
 * clean call use dr_read_saved_reg().
 */
bool
dr_get_mcontext(void *drcontext, dr_mcontext_t *context, int *app_errno);

/**
 * Sets the application machine context to \p context.
 * This routine may only be called from:
 * - A clean call invoked by dr_insert_clean_call() or dr_prepare_for_call()
 * - A pre- or post-syscall event (dr_register_pre_syscall_event(),
 *   dr_register_post_syscall_event())
 *   dr_register_thread_exit_event())
 * - Basic block or trace creation events (dr_register_bb_event(),
 *   dr_register_trace_event()), but for basic block creation only when the
 *   basic block callback parameters \p for_trace and \p translating are
 *   false, and for trace creation only when \p translating is false.
 *
 * Ignores the pc field.  If \p app_errno is non-NULL sets the
 * application error code (value of GetLastError() on Windows; ignored
 * on Linux) to be restored as well.
 *
 * \note The xmm0 through xmm5 fields are only set for 64-bit or WOW64
 * processes where the underlying processor supports SSE.  For
 * dr_insert_clean_call() that requested \p save_fpstate, the xmm0
 * through xmm5 values set here override that saved state.
 * Use dr_mcontext_xmm_fields_valid() to determine whether the fields are valid.
 */
void
dr_set_mcontext(void *drcontext, dr_mcontext_t *context, const int *app_errno);

/**
 * Immediately resumes application execution from a clean call out of the cache (see
 * dr_insert_clean_call() or dr_prepare_for_call()) or an exception event with the
 * state specified in \p mcontext (including pc, and including the xmm0 through xmm5
 * values if dr_mcontext_xmm_fields_valid() returns true) and the application error
 * code (value of GetLastError() on Windows; ignored on Linux) specified by \p app_errno.
 *
 * \note dr_get_mcontext() can be used to get the register state (except pc) and the
 * \p app_errno value saved in dr_insert_clean_call() or dr_prepare_for_call()
 * \note If floating point state was saved by dr_prepare_for_call() or
 * dr_insert_clean_call() it is not restored (other than xmm0 through xmm5, if
 * dr_mcontext_xmm_fields_valid()).  The caller should instead manually save and
 * restore the floating point state with proc_save_fpstate() and proc_restore_fpstate()
 * if necessary.
 * \note If the caller wishes to set any other state (such as xmm registers that are
 * not part of the mcontext) they may do so by just setting that state in the current
 * thread before making this call.
 * \note This routine may only be called from a clean call from the cache. It can not be
 * called from any registered event callback.
 * \note This routine doesn't return.
 */
void
dr_redirect_execution(dr_mcontext_t *mcontext, int app_errno);

/***************************************************************************
 * DECODE / DISASSEMBLY ROUTINES
 */


/**
 * Calculates the size, in bytes, of the memory read or write of
 * the instr at \p pc.  If the instruction is a repeating string instruction,
 * considers only one iteration.
 * Returns the pc of the following instruction.
 * If the instruction at \p pc does not reference memory, or is invalid,
 * returns NULL.
 */
app_pc
decode_memory_reference_size(void *drcontext, app_pc pc, uint *size_in_bytes);

/**
 * Decodes only enough of the instruction at address \p pc to determine
 * its eflags usage, which is returned in \p usage as EFLAGS_ constants
 * or'ed together.
 * Returns the address of the next byte after the decoded instruction.
 * Returns NULL on decoding an invalid instruction.
 */
byte *
decode_eflags_usage(void *drcontext, byte *pc, uint *usage);

/**
 * Decodes the instruction at address \p pc into \p instr, filling in the
 * instruction's opcode, eflags usage, prefixes, and operands.
 * The instruction's raw bits are set to valid and pointed at \p pc
 * (xref instr_get_raw_bits()).
 * Assumes that \p instr is already initialized, but uses the x86/x64 mode
 * for the thread \p dcontext rather than that set in instr.
 * If caller is re-using same instr_t struct over multiple decodings,
 * caller should call instr_reset() or instr_reuse().
 * Returns the address of the next byte after the decoded instruction.
 * Returns NULL on decoding an invalid instr and sets opcode to OP_INVALID.
 */
byte *
decode(void *drcontext, byte *pc, instr_t *instr);

/**
 * Decodes the instruction at address \p copy_pc into \p instr as though
 * it were located at address \p orig_pc.  Any pc-relative operands have
 * their values calculated as though the instruction were actually at
 * \p orig_pc, though that address is never de-referenced.
 * The instruction's raw bits are not valid, but its translation field
 * (see instr_get_translation()) is set to \p orig_pc.
 * The instruction's opcode, eflags usage, prefixes, and operands are
 * all filled in.
 * Assumes that \p instr is already initialized, but uses the x86/x64 mode
 * for the thread \p dcontext rather than that set in instr.
 * If caller is re-using same instr_t struct over multiple decodings,
 * caller should call instr_reset() or instr_reuse().
 * Returns the address of the next byte after the decoded instruction
 * copy at \p copy_pc.
 * Returns NULL on decoding an invalid instr and sets opcode to OP_INVALID.
 */
byte *
decode_from_copy(void *drcontext, byte *copy_pc, byte *orig_pc, instr_t *instr);

/**
 * Client routine to decode instructions at an arbitrary app address,
 * following all the rules that DynamoRIO follows internally for
 * terminating basic blocks.  Note that DynamoRIO does not validate
 * that \p start_pc is actually the first instruction of a basic block.
 * \note Caller is reponsible for freeing the list and its instrs!
 */
instrlist_t *
decode_as_bb(void *drcontext, byte *start_pc);

/**
 * Decodes the trace with tag \p tag, and returns an instrlist_t of
 * the instructions comprising that fragment.  If \p tag is not a
 * valid tag for an existing trace, the routine returns NULL.  Clients
 * can use dr_trace_exists_at() to determine whether the trace exists.
 * \note Unlike the instruction list presented by the trace event, the
 * list here does not include any existing client modifications.  If
 * client-modified instructions are needed, it is the responsibility
 * of the client to record or recreate that list itself.
 * \note This routine does not support decoding thread-private traces
 * created by other than the calling thread.
 */
instrlist_t *
decode_trace(void *drcontext, void *tag);

/**
 * Given an OP_ constant, returns the first byte of its opcode when
 * encoded as an IA-32 instruction.
 */
byte 
decode_first_opcode_byte(int opcode);

/** Given an OP_ constant, returns the string name of its opcode. */
const char *
decode_opcode_name(int opcode);

/** 
 * Decodes only enough of the instruction at address \p pc to determine its size.
 * Returns that size.
 * If \p num_prefixes is non-NULL, returns the number of prefix bytes.
 * If \p rip_rel_pos is non-NULL, returns the offset into the instruction
 * of a rip-relative addressing displacement (for data only: ignores
 * control-transfer relative addressing), or 0 if none.
 * May return 0 size for certain invalid instructions.
 */
int 
decode_sizeof(void *drcontext, byte *pc, int *num_prefixes
              _IF_X64(uint *rip_rel_pos));

/** 
 * Decodes only enough of the instruction at address \p pc to determine its size.
 * Returns the address of the byte following the instruction.
 * Returns NULL on decoding an invalid instruction.
 */
byte *
decode_next_pc(void *drcontext, byte *pc);


/** 
 * Decodes and then prints the instruction at address \p pc to file \p outfile.
 * The default is to use AT&T-style syntax, unless the \ref op_syntax_intel
 * "-syntax_intel" runtime option is specified.
 * Returns the address of the subsequent instruction, or NULL if the instruction
 * at \p pc is invalid.
 */
byte *
disassemble(void *drcontext, byte *pc, file_t outfile);

/**
 * Decodes and then prints the instruction at address \p pc to file \p outfile.
 * Prior to the instruction the address is printed if \p show_pc and the raw
 * bytes are printed if \p show_bytes.
 * The default is to use AT&T-style syntax, unless the \ref op_syntax_intel
 * "-syntax_intel" runtime option is specified.
 * Returns the address of the subsequent instruction, or NULL if the instruction
 * at \p pc is invalid.
 */
byte *
disassemble_with_info(void *drcontext, byte *pc, file_t outfile,
                      bool show_pc, bool show_bytes);

/**
 * Decodes the instruction at address \p copy_pc as though
 * it were located at address \p orig_pc, and then prints the
 * instruction to file \p outfile.
 * Prior to the instruction the address \p orig_pc is printed if \p show_pc and the raw
 * bytes are printed if \p show_bytes.
 * The default is to use AT&T-style syntax, unless the \ref op_syntax_intel
 * "-syntax_intel" runtime option is specified.
 * Returns the address of the subsequent instruction after the copy at
 * \p copy_pc, or NULL if the instruction at \p copy_pc is invalid.
 */
byte *
disassemble_from_copy(void *drcontext, byte *copy_pc, byte *orig_pc,
                      file_t outfile, bool show_pc, bool show_bytes);

#endif /* _DR_IR_UTILS_H_ */
