/* **********************************************************
 * Copyright (c) 2001-2009 VMware, Inc.  All rights reserved.
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

/* Copyright (c) 2003-2007 Determina Corp. */
/* Copyright (c) 2001-2003 Massachusetts Institute of Technology */
/* Copyright (c) 2001 Hewlett-Packard Company */

/*
 * interp.c - interpreter used for native trace selection
 */

#include "../globals.h"
#include "../link.h"
#include "../fragment.h"
#include "../emit.h"
#include "../dispatch.h"
#include "../instrlist.h"
#include "../fcache.h"
#include "../monitor.h" /* for trace_abort and monitor_data_t */
#include "arch.h"
#include "instr.h"
#include "instr_create.h"
#include "decode.h"
#include "decode_fast.h"
#include "disassemble.h"
#include "string_wrapper.h" /* for memcpy */
#include "instrument.h"
#include "../hotpatch.h"
#ifdef RETURN_AFTER_CALL
# include "../rct.h"
#endif
#ifdef WINDOWS
# include "ntdll.h" /* for EXCEPTION_REGISTRATION */
# include "../nudge.h" /* for generic_nudge_target() address */
#endif
#include "../perscache.h"

#ifdef CHECK_RETURNS_SSE2
#include <setjmp.h> /* for warning when see libc setjmp */
#endif

#ifdef VMX86_SERVER
# include "vmkuw.h" /* VMKUW_SYSCALL_GATEWAY */
#endif

enum { DIRECT_XFER_LENGTH = 5 };

/* forward declarations */
static void process_nops_for_trace(dcontext_t *dcontext, instrlist_t *ilist, uint flags
                                   _IF_DEBUG(bool recreating));
static int fixup_last_cti(dcontext_t *dcontext, instrlist_t *trace,
                          app_pc next_tag, uint next_flags, uint trace_flags,
                          fragment_t *prev_f, linkstub_t *prev_l,
                          bool record_translation, uint *num_exits_deleted/*OUT*/,
                          /* If non-NULL, only looks inside trace between these two */
                          instr_t *start_instr, instr_t *end_instr);
static bool can_use_mangle_trace(void);
bool mangle_trace(dcontext_t *dcontext, instrlist_t *ilist, monitor_data_t *md);

/* we use a branch limit of 1 to make it easier for the trace
 * creation mechanism to stitch basic blocks together
 */
#define BRANCH_LIMIT 1

/* we limit total bb size to handle cases like infinite loop or sequence
 * of calls.
 * also, we have a limit on fragment body sizes, which should be impossible
 * to break since x86 instrs are max 17 bytes and we only modify ctis.
 * Although...selfmod mangling does really expand fragments!
 * -selfmod_max_writes helps for selfmod bbs (case 7893/7909).
 * System call mangling is also large, for degenerate cases like tests/linux/infinite.
 * PR 215217: also client additions: we document and assert.
 * FIXME: need better way to know how big will get, b/c we can construct
 * cases that will trigger the size assertion!
 */
/* define replaced by -max_bb_instrs option */

/* exported so micro routines can assert whether held */
DECLARE_CXTSWPROT_VAR(mutex_t bb_building_lock, INIT_LOCK_FREE(bb_building_lock));

#ifdef INTERNAL
file_t bbdump_file = INVALID_FILE;
#endif

/* initialization */
void
interp_init(void)
{
#ifdef INTERNAL
    if (INTERNAL_OPTION(bbdump_tags)) {
        bbdump_file = open_log_file("bbs", NULL, 0);
        ASSERT(bbdump_file != INVALID_FILE);
    }
#endif
}

#ifdef CUSTOM_TRACES_RET_REMOVAL
# ifdef DEBUG
/* don't bother with adding lock */
static int num_rets_removed;
# endif
#endif

/* cleanup */
void
interp_exit(void)
{
#ifdef INTERNAL
    if (INTERNAL_OPTION(bbdump_tags)) {
        os_close(bbdump_file);
    }
#endif
    DELETE_LOCK(bb_building_lock);

    LOG(GLOBAL, LOG_INTERP|LOG_STATS, 1, "Total application code seen: %d KB\n",
        GLOBAL_STAT(app_code_seen)/1024);
#ifdef CUSTOM_TRACES_RET_REMOVAL
# ifdef DEBUG
    LOG(GLOBAL, LOG_INTERP|LOG_STATS, 1, "Total rets removed: %d\n",
        num_rets_removed);
# endif
#endif
}

/****************************************************************************
 ****************************************************************************
 *
 * B A S I C   B L O C K   B U I L D I N G
 */

/* we have a lot of data to pass around so we package it in this struct
 * so we can have separate routines for readability
 */
typedef struct {
    /* in */
    app_pc start_pc;
    bool app_interp;         /* building bb to interp app, as opposed to for pc
                              * translation or figuring out what pages a bb touches? */
    bool for_cache;          /* should vmareas be updated? */
    bool mangle_ilist;       /* should bb ilist be mangled? */
    bool record_translation; /* store translation info for each instr_t? */
    bool has_bb_building_lock; /* usually ==for_cache; used for aborting bb building */
    file_t outf;               /* send disassembly and notes to a file? 
                              * we use this mainly for dumping trace origins */
#ifdef CLIENT_INTERFACE
    bool pass_to_client;     /* pass to client, if a bb hook exists;
                              * we store this up front to avoid race conditions
                              * between full_decode setting and hook calling time.
                              */
    bool post_client;        /* has the client already processed the bb? */
    bool for_trace;          /* PR 299808: we tell client if building a trace */
#endif

    /* in and out */
    overlap_info_t *overlap_info; /* if non-null, records overlap information here;
                                   * caller must initialize region_start and region_end */

    /* out */
    instrlist_t *ilist;
    uint flags;
    void *vmlist;
    app_pc end_pc;
    bool native_exec;        /* replace cur ilist with a native_exec version */
#ifdef CLIENT_INTERFACE
    instrlist_t **unmangled_ilist; /* PR 299808: clone ilist pre-mangling */
#endif

    /* internal usage only */
    bool full_decode;        /* decode every instruction into a separate instr_t? */
    bool follow_direct;      /* elide unconditional branches? */
    bool check_vm_area;      /* whether to call check_thread_vm_area() */
    uint num_elide_jmp;
    uint num_elide_call;
    app_pc last_page;
    app_pc cur_pc;
    app_pc instr_start;
    app_pc checked_end;       /* end of current vmarea checked */
    cache_pc exit_target;     /* fall-through target of final instr */
    uint exit_type;           /* indirect branch type  */
#ifdef LINUX
    bool invalid_instr_hack;
#endif
    instr_t *instr;             /* the current instr */
    int eflags;
    DEBUG_DECLARE(bool initialized;)
} build_bb_t;

/* forward decl */
static inline bool
bb_process_syscall(dcontext_t *dcontext, build_bb_t *bb);

static void
init_build_bb(build_bb_t *bb, app_pc start_pc, bool app_interp, bool for_cache,
              bool mangle_ilist, bool record_translation, file_t outf, uint known_flags,
              overlap_info_t *overlap_info)
{
    memset(bb, 0, sizeof(*bb));
    bb->check_vm_area = true;
    bb->start_pc = start_pc;
    bb->app_interp = app_interp;
    bb->for_cache = for_cache;
    bb->mangle_ilist = mangle_ilist;
    bb->record_translation = record_translation;
    bb->outf = outf;
    bb->overlap_info = overlap_info;
    bb->follow_direct = !TEST(FRAG_SELFMOD_SANDBOXED, known_flags);
    bb->flags = known_flags;
    DODEBUG(bb->initialized = true;);
}

static void
reset_overlap_info(dcontext_t *dcontext, build_bb_t *bb)
{
    bb->overlap_info->start_pc = bb->start_pc;
    bb->overlap_info->min_pc = bb->start_pc;
    bb->overlap_info->max_pc = bb->start_pc;
    bb->overlap_info->contiguous = true;
    bb->overlap_info->overlap = false;
}

static void
update_overlap_info(dcontext_t *dcontext, build_bb_t *bb, app_pc new_pc, bool jmp)
{
    if (new_pc < bb->overlap_info->min_pc)
        bb->overlap_info->min_pc = new_pc;
    if (new_pc > bb->overlap_info->max_pc)
        bb->overlap_info->max_pc = new_pc;
    /* we get called at end of all contiguous intervals, so ignore jmps */
    LOG(THREAD, LOG_ALL, 5, "\t    app_bb_overlaps "PFX".."PFX" %s\n",
        bb->last_page, new_pc, jmp?"jmp":"");
    if (!bb->overlap_info->overlap && !jmp) {
        /* contiguous interval: prev_pc..new_pc (open-ended) */
        if (bb->last_page < bb->overlap_info->region_end &&
            new_pc > bb->overlap_info->region_start) {
            LOG(THREAD_GET, LOG_ALL, 5, "\t    it overlaps!\n");
            bb->overlap_info->overlap = true;
        }
    }
    if (bb->overlap_info->contiguous && jmp)
        bb->overlap_info->contiguous = false;
}

#ifdef DEBUG
# define BBPRINT(bb, level, ...) do {                     \
    LOG(THREAD, LOG_INTERP, level, __VA_ARGS__);          \
    if (bb->outf != INVALID_FILE && bb->outf != (THREAD)) \
        print_file(bb->outf, __VA_ARGS__);                \
} while (0);
#else
# ifdef INTERNAL
#  define BBPRINT(bb, level, ...) do {                     \
     if (bb->outf != INVALID_FILE)                         \
         print_file(bb->outf, __VA_ARGS__);                \
   } while (0);
# else
#  define BBPRINT(bb, level, ...) /* nothing */
# endif
#endif

#ifdef WINDOWS
extern void intercept_load_dll(void);
extern void intercept_unload_dll(void);
# ifdef INTERNAL
extern void DllMainThreadAttach(void);
# endif
#endif

/* forward declarations */
static bool
mangle_bb_ilist(dcontext_t *dcontext, build_bb_t *bb);

static void
build_native_exec_bb(dcontext_t *dcontext, build_bb_t *bb);

static bool
at_native_exec_gateway(dcontext_t *dcontext, app_pc start
                       _IF_DEBUG(bool xfer_target));

#ifdef DEBUG
static void
report_native_module(dcontext_t *dcontext, app_pc modpc);
#endif

/* return true if pc is a call target that should NOT be inlined */
#if defined(DEBUG) || !defined(WINDOWS)
/* cl.exe non-debug won't let other modules use it if inlined */
inline
#endif 
bool
must_not_be_inlined(app_pc pc)
{
    return (
#ifdef INTERNAL
            !dynamo_options.inline_calls
#else
            0
#endif
#ifdef WINDOWS
            || pc == (app_pc)intercept_load_dll
            || pc == (app_pc)intercept_unload_dll
            /* we're guaranteed to have direct calls to the next routine since our
             * own DllMain calls it! */
# ifdef INTERNAL
            || pc == (app_pc) DllMainThreadAttach
# endif
            /* check for nudge handling escape from cache */
            || (pc == (app_pc)generic_nudge_handler)
#else
            /* PR 200203: long-term we want to control loading of client
             * libs, but for now we have to let the loader call _fini()
             * in the client, which may end up calling __wrap_free().
             * It's simpler to let those be interpreted and make a native
             * call to the real heap routine here as this is a direct
             * call whereas we'd need native_exec for the others:
             */
            || pc == (app_pc)global_heap_free
#endif
        );
}

/* return true if pc is a direct jmp target that should NOT be elided and followed */
static inline bool
must_not_be_elided(app_pc pc)
{
#ifdef WINDOWS
    /* Allow only the return jump in the landing pad to be elided, as we
     * interpret the return path from trampolines.  The forward jump leads to
     * the trampoline and shouldn't be elided. */
    if (vmvector_overlap(landing_pad_areas, pc, pc + 1)) {
        /* Ok, is it the return jump, which is always 32-bit rel and the target
         * is not in the interception buffer?  If so, elide. */
        if (*pc == JMP_REL32_OPCODE &&
            !is_in_interception_buffer(PC_RELATIVE_TARGET(pc + 1))) {
            return false;
        } else {
            return true;
        }
    }
#endif
    return (0
#ifdef WINDOWS
            /* we insert trampolines by adding direct jmps to our interception code buffer
             * we don't want to interpret the code in that buffer, as it may swap to the
             * dstack and mess up a return-from-fcache.
             * N.B.: if use this routine anywhere else, pay attention to the
             * hack for is_syscall_trampoline() in the use here!
             */
            || (is_in_interception_buffer(pc))
#else /* LINUX */
#endif
            );
}

#ifdef DR_APP_EXPORTS
/* This function allows automatically injected dynamo to ignore
 * dynamo API routines that would really mess things up
 */
static inline bool
must_escape_from(app_pc pc)
{
    /* if ever find ourselves at top of one of these, immediately issue
     * a ret instruction...haven't set up frame yet so stack fine, only
     * problem is return value, go ahead and overwrite xax, it's caller-saved
     * FIXME: is this ok?
     */
    /* Note that we can't just look for direct calls to these functions
     * because of stubs, etc. that end up doing indirect jumps to them!
     */
    bool res = false
#ifdef DR_APP_EXPORTS
        || (automatic_startup &&
            (pc == (app_pc)dynamorio_app_init ||
             pc == (app_pc)dr_app_start ||
             pc == (app_pc)dynamo_thread_init ||
             pc == (app_pc)dynamorio_app_exit ||
             /* dr_app_stop is a nop already */
             pc == (app_pc)dynamo_thread_exit))
#endif
        ;
#ifdef DEBUG
    if (res) {
# ifdef DR_APP_EXPORTS
        LOG(THREAD_GET, LOG_INTERP, 3, "must_escape_from: found ");
        if (pc == (app_pc)dynamorio_app_init)
            LOG(THREAD_GET, LOG_INTERP, 3, "dynamorio_app_init\n");
        else if (pc == (app_pc)dr_app_start)
            LOG(THREAD_GET, LOG_INTERP, 3, "dr_app_start\n");
        /* FIXME: are dynamo_thread_* still needed hered? */
        else if (pc == (app_pc)dynamo_thread_init)
            LOG(THREAD_GET, LOG_INTERP, 3, "dynamo_thread_init\n");
        else if (pc ==  (app_pc)dynamorio_app_exit)
            LOG(THREAD_GET, LOG_INTERP, 3, "dynamorio_app_exit\n");
        else if (pc ==  (app_pc)dynamo_thread_exit)
            LOG(THREAD_GET, LOG_INTERP, 3, "dynamo_thread_exit\n");
# endif
    }
#endif

    return res;
}
#endif /* DR_APP_EXPORTS */

/* Perform checks such as looking for dynamo stopping points and bad places
 * to be.  We assume we only have to check after control transfer instructions,
 * i.e., we assume that all of these conditions are procedures that are only
 * entered by calling or jumping, never falling through.
 */
static inline bool
check_for_stopping_point(dcontext_t *dcontext, build_bb_t *bb)
{
#ifdef DR_APP_EXPORTS
    if (must_escape_from(bb->cur_pc)) {
        BBPRINT(bb, 3, "interp: emergency exit from "PFX"\n", bb->cur_pc);
        /* if ever find ourselves at top of one of these, immediately issue
         * a ret instruction...haven't set up frame yet so stack fine, only
         * problem is return value, go ahead and overwrite xax, it's
         * caller-saved.
         * FIXME: is this ok?
         */
        /* move 0 into xax -- our functions return 0 to indicate success */
        instrlist_append(bb->ilist, /* x64 will zero-extend to rax */
                         INSTR_CREATE_mov_imm(dcontext, opnd_create_reg(REG_EAX),
                                              OPND_CREATE_INT32(0)));
        /* insert a ret instruction */
        instrlist_append(bb->ilist, INSTR_CREATE_ret(dcontext));
        /* should this be treated as a real return? */
        bb->exit_type |= LINK_INDIRECT | LINK_RETURN;
        ASSERT_NOT_IMPLEMENTED(false);
        bb->exit_target = get_ibl_routine(dcontext, IBL_LINKED, DEFAULT_IBL_BB(), IBL_RETURN);
        return true;
    }
#endif /* DR_APP_EXPORTS */

#ifdef CHECK_RETURNS_SSE2
    if (bb->cur_pc == (app_pc)longjmp) {
        SYSLOG_INTERNAL_WARNING("encountered longjmp, which will cause ret mismatch!");
    }
#endif

    return is_stopping_point(dcontext, bb->cur_pc);
}

/* Arithmetic eflags analysis to see if sequence of instrs reads an
 * arithmetic flag prior to writing it.
 * Usage: first initialize status to 0 and eflags_6 to 0.
 * Then call this routine for each instr in sequence, assigning result to status.
 * eflags_6 holds flags written and read so far.
 * Uses these flags, defined in instr.h, as status values:
 *   EFLAGS_WRITE_6   = writes all 6 flags before reading any
 *   EFLAGS_WRITE_OF  = writes OF before reading it
 *   EFLAGS_READ_6    = reads some of 6 before writing
 *   EFLAGS_READ_OF   = reads OF before writing OF
 *   0                = no information yet
 */
static inline int
eflags_analysis(instr_t *instr, int status, uint *eflags_6)
{
    uint e6 = *eflags_6; /* local copy */
    uint e6_w2r = EFLAGS_WRITE_TO_READ(e6);
    uint instr_eflags = instr_get_arith_flags(instr);

    /* Keep going until result is non-zero, also keep going if
     * result is writes to OF to see if later writes to rest of flags
     * before reading any, and keep going if reads one of the 6 to see
     * if later writes to OF before reading it.
     */
    if (instr_eflags == 0 || status == EFLAGS_READ_OF || status == EFLAGS_WRITE_6)
        return status;
    /* we ignore interrupts */
    if ((instr_eflags & EFLAGS_READ_6) != 0 &&
        (!instr_opcode_valid(instr) || !instr_is_interrupt(instr))) {
        /* store the flags we're reading */
        e6 |= (instr_eflags & EFLAGS_READ_6);
        *eflags_6 = e6;
        if ((e6_w2r | (instr_eflags & EFLAGS_READ_6)) != e6_w2r) {
            /* we're reading a flag that has not been written yet */
            status = EFLAGS_READ_6; /* some read before all written */
            LOG(THREAD_GET, LOG_INTERP, 4, "\treads flag before writing it!\n");
            if ((instr_eflags & EFLAGS_READ_OF) != 0 && (e6 & EFLAGS_WRITE_OF) == 0) {
                status = EFLAGS_READ_OF; /* reads OF before writing! */
                LOG(THREAD_GET, LOG_INTERP, 4, "\t  reads OF prior to writing it!\n");
            }
        }
    } else if ((instr_eflags & EFLAGS_WRITE_6) != 0) {
        /* store the flags we're writing */
        e6 |= (instr_eflags & EFLAGS_WRITE_6);
        *eflags_6 = e6;
        /* check if all written but none read yet */
        if ((e6 & EFLAGS_WRITE_6) == EFLAGS_WRITE_6 && (e6 & EFLAGS_READ_6) == 0) {
            status = EFLAGS_WRITE_6; /* all written before read */
            LOG(THREAD_GET, LOG_INTERP, 4, "\twrote all 6 flags now!\n");
        }
        /* check if at least OF was written but not read */
        else if ((e6 & EFLAGS_WRITE_OF) != 0 && (e6 & EFLAGS_READ_OF) == 0) {
            status = EFLAGS_WRITE_OF; /* OF written before read */
            LOG(THREAD_GET, LOG_INTERP, 4, "\twrote overflow flag before reading it!\n");
        }
    }
    return status;
}


/* check origins of code for several purposes:
 * 1) we need list of areas where this thread's fragments come
 *    from, for faster flushing on munmaps
 * 2) also for faster flushing, each vmarea has a list of fragments
 * 3) we need to mark as read-only any writable region that
 *    has a fragment come from it, to handle self-modifying code
 * 4) for PROGRAM_SHEPHERDING restricted code origins for security
 * 5) for restricted execution environments: not letting bb cross regions
 */

/*
  FIXME CASE 7380:
  since report security violation before execute off bad page, can be
  false positive due to:
  - a faulting instruction in middle of bb would have prevented
    getting there
  - ignorable syscall in middle
  - self-mod code would have ended bb sooner than bad page

  One solution is to have check_thread_vm_area() return false and have
  bb building stop at checked_end if a violation will occur when we
  get there.  Then we only raise the violation once building a bb
  starting there.
 */

static inline void
check_new_page_start(dcontext_t *dcontext, build_bb_t *bb)
{
    DEBUG_DECLARE(bool ok;)
    if (!bb->check_vm_area)
        return;
    DEBUG_DECLARE(ok =) check_thread_vm_area(dcontext, bb->start_pc, bb->start_pc,
                                             (bb->for_cache ? &bb->vmlist : NULL),
                                             &bb->flags, &bb->checked_end,
                                             false/*!xfer*/);
    ASSERT(ok); /* cannot return false on non-xfer */
    bb->last_page = bb->start_pc;
    if (bb->overlap_info != NULL)
        reset_overlap_info(dcontext, bb);
}

/* Walk forward in straight line from prev_pc to new_pc.  
 * FIXME: with checked_end we don't need to call this on every contig end
 * while bb building like we used to.  Should revisit the overlap info and
 * walk_app_bb reasons for keeping those contig() calls and see if we can
 * optimize them away for bb building at least.
 */
static inline void
check_new_page_contig(dcontext_t *dcontext, build_bb_t *bb, app_pc new_pc)
{
    if (!bb->check_vm_area)
        return;
    if (bb->overlap_info != NULL)
        update_overlap_info(dcontext, bb, new_pc, false/*not jmp*/);
    if (bb->checked_end == NULL) {
        ASSERT(new_pc == bb->start_pc);
    } else if (new_pc > bb->checked_end) {
        DEBUG_DECLARE(bool ok =)
            check_thread_vm_area(dcontext, new_pc, bb->start_pc,
                                 (bb->for_cache ? &bb->vmlist : NULL),
                                 &bb->flags, &bb->checked_end,
                                 false/*!xfer*/);
        ASSERT(ok); /* cannot return false on non-xfer */
    }
    DOLOG(4, LOG_INTERP, {
        if (PAGE_START(bb->last_page) != PAGE_START(new_pc))
            LOG(THREAD, LOG_INTERP, 4, "page boundary crossed\n");
    });
    bb->last_page = new_pc; /* update even if not new page, for walk_app_bb */
}

/* Direct cti from prev_pc to new_pc */
static bool
check_new_page_jmp(dcontext_t *dcontext, build_bb_t *bb, app_pc new_pc)
{
    /* cur sandboxing doesn't handle direct cti
     * not good enough to only check this at top of interp -- could walk contig
     * from non-selfmod to selfmod page, and then do a direct cti, which
     * check_thread_vm_area would allow (no flag changes on direct cti)!
     * also not good enough to put this check in check_thread_vm_area, as that
     * only checks across pages.
     */
    if ((bb->flags & FRAG_SELFMOD_SANDBOXED) != 0)
        return false;         
    if (PAGE_START(bb->last_page) != PAGE_START(new_pc))
        LOG(THREAD, LOG_INTERP, 4, "page boundary crossed\n");
    /* do not walk into a native exec dll (we assume not currently there,
     * though could happen if bypass a gateway -- even then this is a feature
     * to allow getting back to native ASAP)
     * FIXME: we could assume that such direct calls only
     * occur from DGC, and rely on check_thread_vm_area to disallow,
     * as an (unsafe) optimization
     */
    if (DYNAMO_OPTION(native_exec) &&
        DYNAMO_OPTION(native_exec_dircalls) &&
        !vmvector_empty(native_exec_areas) &&
        vmvector_overlap(native_exec_areas, new_pc, new_pc+1))
        return false;
    if (!bb->check_vm_area)
        return true;
    /* need to check this even if an intra-page jmp b/c we allow sub-page vm regions */
    if (!check_thread_vm_area(dcontext, new_pc, bb->start_pc,
                              (bb->for_cache ? &bb->vmlist : NULL),
                              &bb->flags, &bb->checked_end, true/*xfer*/))
        return false;
    if (bb->overlap_info != NULL)
        update_overlap_info(dcontext, bb, new_pc, true/*jmp*/);
    bb->flags |= FRAG_HAS_DIRECT_CTI;
    bb->last_page = new_pc; /* update even if not new page, for walk_app_bb */
    return true;
}

static inline void
bb_process_invalid_instr(dcontext_t *dcontext, build_bb_t *bb)
{
    
    /* invalid instr: end bb BEFORE the instr, we'll throw exception if we
     * reach the instr itself
     */
    LOG(THREAD, LOG_INTERP, 2, "interp: invalid instr at "PFX"\n", bb->instr_start);
    /* This routine is called by more than just bb builder, also used
     * for recreating state, so check bb->app_interp parameter to find out
     * if building a real app bb to be executed
     */
    if (bb->app_interp && bb->instr_start == bb->start_pc) {
        /* This is first instr in bb so it will be executed for sure and
         * we need to generate an invalid instruction exception.
         * A benefit of being first instr is that the state is easy
         * to translate.
         */
#ifdef WINDOWS
        /* Copying the invalid bytes and having the processor generate
         * the exception would be cleaner in every way except our fear
         * of a new processor making those bytes valid and us inadvertently
         * executing the unexamined instructions afterward, since we do not
         * know the proper amount of bytes to copy.  Copying is cleaner
         * since Windows splits invalid instructions into different cases,
         * an invalid lock prefix and maybe some other distinctions
         * (it's all interrupt 6 to the processor), and it is hard to
         * duplicate Windows' behavior in our forged exception.
         */
        /* FIXME case 10672: provide a runtime option to specify new
         * instruction formats to avoid this app exception */
        ASSERT(dcontext->bb_build_info == bb);
        bb_build_abort(dcontext, true/*clean vm area*/);
        /* FIXME : we use illegal instruction here, even though we 
         * know windows uses different exception codes for different
         * types of invalid instructions (for ex. STATUS_INVALID_LOCK
         * _SEQUENCE for lock prefix on a jmp instruction)
         */
        if (TEST(DUMPCORE_FORGE_ILLEGAL_INST, DYNAMO_OPTION(dumpcore_mask)))
            os_dump_core("Warning: Encountered Illegal Instruction");
        os_forge_exception(bb->instr_start, ILLEGAL_INSTRUCTION_EXCEPTION);
        ASSERT_NOT_REACHED();
#else
        /* FIXME: Linux hack until we have a real os_forge_exception implementation:
         * copy the bytes and have the process generate the exception.
         * Once remove this, also disable check at top of insert_selfmod_sandbox
         * FIXME PR 307880: we now have a preliminary
         * os_forge_exception impl, but I'm leaving this hack until
         * we're more comfortable w/ our forging.
         */
        uint sz;
        instrlist_append(bb->ilist, bb->instr);
        /* pretend raw bits valid to get it encoded
         * For now we just do 17 bytes, being wary of unreadable pages.
         * FIXME: better solution is to have decoder guess at length (if
         * ok opcode just bad lock prefix or something know length, if
         * bad opcode just bytes up until know it's bad).
         */
        if (!is_readable_without_exception(bb->instr_start, MAX_INSTR_LENGTH)) {
            app_pc nxt_page = (app_pc) ALIGN_FORWARD(bb->instr_start, PAGE_SIZE);
            sz = nxt_page - bb->instr_start;
        } else {
            sz = MAX_INSTR_LENGTH;
        }
        bb->cur_pc += sz; /* just in case, should have a non-self target */
        ASSERT(bb->cur_pc > bb->instr_start); /* else still a self target */
        instr_set_raw_bits(bb->instr, bb->instr_start, sz);
        bb->invalid_instr_hack = true;
#endif
    } else {
        instr_destroy(dcontext, bb->instr);
        bb->instr = NULL;
    }
}

/* returns true to indicate "elide and continue" and false to indicate "end bb now"
 * should be used both for converted indirect jumps and 
 * FIXME: for direct jumps by bb_process_ubr
 */
static inline bool
follow_direct_jump(dcontext_t *dcontext, build_bb_t *bb, 
                   app_pc target)
{
    if (bb->follow_direct &&
        bb->num_elide_jmp < DYNAMO_OPTION(max_elide_jmp) &&
        (DYNAMO_OPTION(elide_back_jmps) || bb->cur_pc <= target)) {
        check_new_page_contig(dcontext, bb, bb->cur_pc-1);
        if (check_new_page_jmp(dcontext, bb, target)) {
            /* Elide unconditional branch and follow target */
            bb->num_elide_jmp++;
            STATS_INC(total_elided_jmps);
            STATS_TRACK_MAX(max_elided_jmps, bb->num_elide_jmp);
            bb->cur_pc = target;
            BBPRINT(bb, 4, "        continuing at target "PFX"\n", bb->cur_pc);

            return true;        /* keep bb going */
        } else {
            BBPRINT(bb, 3, "        NOT following jmp from "PFX" to "PFX"\n",
                    bb->instr_start, target);
        }
    } else {
        BBPRINT(bb, 3, "   NOT attempting to follow jump from "PFX" to "PFX"\n",
                bb->instr_start, target);
    }
    return false;               /* stop bb */
}

/* returns true to indicate "elide and continue" and false to indicate "end bb now" */
static inline bool
bb_process_ubr(dcontext_t *dcontext, build_bb_t *bb)
{
    app_pc tgt = (byte *) opnd_get_pc(instr_get_target(bb->instr));
    BBPRINT(bb, 4, "interp: direct jump at "PFX"\n", bb->instr_start);
    if (must_not_be_elided(tgt)) {
#ifdef WINDOWS
        if (is_syscall_trampoline(tgt)) {
            /* HACK to avoid entering the syscall trampoline that is meant
             * only for native syscalls -- we replace the jmp with the
             * original app mov immed that it replaced
             */
            BBPRINT(bb, 3,
                    "interp: replacing syscall trampoline @"PFX" w/ orig mov @"PFX"\n",
                    bb->instr_start, tgt);
            instr_reset(dcontext, bb->instr);

            /* leave bb->cur_pc unchanged */
            decode(dcontext, tgt, bb->instr);
            /* ASSUMPTION: syscall trampoline puts hooked instruction
             * (usually mov_imm but can be lea if hooked_deeper) here */
            ASSERT(instr_get_opcode(bb->instr) == OP_mov_imm ||
                   (instr_get_opcode(bb->instr) == OP_lea &&
                    DYNAMO_OPTION(native_exec_hook_conflict) == 
                    HOOKED_TRAMPOLINE_HOOK_DEEPER));
            instrlist_append(bb->ilist, bb->instr);
            /* translation should point to the trampoline at the
             * original application address
             */
            if (bb->record_translation)
                instr_set_translation(bb->instr, bb->instr_start);
            if (instr_get_opcode(bb->instr) == OP_lea) {
                app_pc translation = bb->instr_start + 
                    instr_length(dcontext, bb->instr);
                ASSERT_CURIOSITY(instr_length(dcontext, bb->instr) == 4);
                /* we hooked deep need to add the int 2e instruction */
                /* can't use create_syscall_instr because of case 5217 hack */
                ASSERT(get_syscall_method() == SYSCALL_METHOD_INT);
                bb->instr = INSTR_CREATE_int(dcontext,
                                             opnd_create_immed_int((char)0x2e,
                                                                   OPSZ_1));
                if (bb->record_translation)
                    instr_set_translation(bb->instr, translation);
                ASSERT(instr_is_syscall(bb->instr) &&
                       instr_get_opcode(bb->instr) == OP_int);
                instrlist_append(bb->ilist, bb->instr);
                return bb_process_syscall(dcontext, bb);
            }
            return true; /* keep bb going */
        }
#endif 
        BBPRINT(bb, 3, "interp: NOT following jmp to "PFX"\n", tgt);
        /* add instruction to instruction list */
        instrlist_append(bb->ilist, bb->instr);
        /* indicate that relative target must be
         * re-encoded, and that it is not an exit cti
         */
        instr_set_ok_to_mangle(bb->instr, false);
        instr_set_raw_bits_valid(bb->instr, false);
        /* Case 8711: coarse-grain can't handle non-exit cti */
        bb->flags &= ~FRAG_COARSE_GRAIN;
        STATS_INC(coarse_prevent_cti);
        return false; /* end bb now */
    } else {
        if (bb->follow_direct &&
            bb->num_elide_jmp < DYNAMO_OPTION(max_elide_jmp) &&
            (DYNAMO_OPTION(elide_back_jmps) || bb->cur_pc <= tgt)) {
            check_new_page_contig(dcontext, bb, bb->cur_pc-1);
            if (check_new_page_jmp(dcontext, bb, tgt)) {
                /* Elide unconditional branch and follow target */
                bb->num_elide_jmp++;
                STATS_INC(total_elided_jmps);
                STATS_TRACK_MAX(max_elided_jmps, bb->num_elide_jmp);
                bb->cur_pc = tgt;
                BBPRINT(bb, 4, "        continuing at target "PFX"\n", bb->cur_pc);
                /* pretend never saw this ubr: delete instr, then continue */
                instr_destroy(dcontext, bb->instr);
                bb->instr = NULL;
                return true; /* keep bb going */
            } else {
                BBPRINT(bb, 3, "        NOT following direct jmp from "PFX" to "PFX"\n",
                        bb->instr_start, tgt);
            }
        }
        /* End this bb now */
        bb->exit_target = opnd_get_pc(instr_get_target(bb->instr));
        instrlist_append(bb->ilist, bb->instr);
        return false; /* end bb */
    }
    return true; /* keep bb going */
}


/* returns true if call is elided,
 * and false if not following due to hitting a limit or other reason */
static bool
follow_direct_call(dcontext_t *dcontext, build_bb_t *bb, app_pc callee)
{
    /* FIXME: This code should be reused in bb_process_convertible_indcall()
     * and in bb_process_call_direct()
     */
    if (bb->follow_direct &&
        bb->num_elide_call < DYNAMO_OPTION(max_elide_call) &&
        (DYNAMO_OPTION(elide_back_calls) || bb->cur_pc <= callee)) {
        check_new_page_contig(dcontext, bb, bb->cur_pc-1);
        if (check_new_page_jmp(dcontext, bb, callee)) {
            bb->num_elide_call++;
            STATS_INC(total_elided_calls);
            STATS_TRACK_MAX(max_elided_calls, bb->num_elide_call);
            bb->cur_pc = callee;

            BBPRINT(bb, 4, "   continuing in callee at "PFX"\n", bb->cur_pc);
            return true;        /* keep bb going in callee */
        } else {
            BBPRINT(bb, 3,
                    "   NOT following direct (or converted) call from "PFX" to "PFX"\n",
                    bb->instr_start, callee);
        }
    }
    else {
        BBPRINT(bb, 3, "   NOT attempting to follow call from "PFX" to "PFX"\n",
                bb->instr_start, callee);
    }    
    return false; /* stop bb */
}

static inline void
bb_stop_prior_to_instr(dcontext_t *dcontext, build_bb_t *bb, bool appended)
{
    if (appended)
        instrlist_remove(bb->ilist, bb->instr);
    instr_destroy(dcontext, bb->instr);
    bb->instr = NULL;
    bb->cur_pc = bb->instr_start;
}

/* returns true to indicate "elide and continue" and false to indicate "end bb now" */
static inline bool
bb_process_call_direct(dcontext_t *dcontext, build_bb_t *bb)
{
    byte *callee = (byte *)opnd_get_pc(instr_get_target(bb->instr));
# ifdef CUSTOM_TRACES_RET_REMOVAL
    if (callee == bb->instr_start + 5) {
        LOG(THREAD, LOG_INTERP, 4, "found call to next instruction\n");
    } else
        dcontext->num_calls++;
# endif
    STATS_INC(num_all_calls);
    BBPRINT(bb, 4, "interp: direct call at "PFX"\n", bb->instr_start);
    if (must_not_be_inlined(callee)) {
        BBPRINT(bb, 3, "interp: NOT inlining call to "PFX"\n", callee);
        /* Case 8711: coarse-grain can't handle non-exit cti.
         * If we allow this fragment to be coarse we must kill the freeze
         * nudge thread!
         */
        bb->flags &= ~FRAG_COARSE_GRAIN;
        STATS_INC(coarse_prevent_cti);
        return true; /* keep bb going, w/o inlining call */
    } else {
        if (DYNAMO_OPTION(coarse_split_calls) && DYNAMO_OPTION(coarse_units) && 
            TEST(FRAG_COARSE_GRAIN, bb->flags)) {
            if (instrlist_first(bb->ilist) != bb->instr) {
                /* have call be in its own bb */
                bb_stop_prior_to_instr(dcontext, bb, true/*appended already*/);
                return false; /* stop bb */
            } else {
                /* single-call fine-grained bb */
                bb->flags &= ~FRAG_COARSE_GRAIN;
                STATS_INC(coarse_prevent_cti);
            }
        }
        /* FIXME: use follow_direct_call() */
        if (bb->follow_direct &&
            bb->num_elide_call < DYNAMO_OPTION(max_elide_call) &&
            (DYNAMO_OPTION(elide_back_calls) || bb->cur_pc <= callee)) {
            check_new_page_contig(dcontext, bb, bb->cur_pc-1);
            if (check_new_page_jmp(dcontext, bb, callee)) {
                bb->num_elide_call++;
                STATS_INC(total_elided_calls);
                STATS_TRACK_MAX(max_elided_calls, bb->num_elide_call);
                bb->cur_pc = callee;
                BBPRINT(bb, 4, "      continuing in callee at "PFX"\n", bb->cur_pc);
                return true; /* keep bb going */
            } else {
                BBPRINT(bb, 3, "        NOT following direct call from "PFX" to "PFX"\n",
                        bb->instr_start, callee);
            }
        }
        /* End this bb now */
        bb->exit_target = callee;
        return false; /* end bb now */
    }
    return true; /* keep bb going */
}

#ifdef WINDOWS
/* Walk up from the bb->instr and verify that the preceding instructions
 * match the pattern that we expect to precede a sysenter. */
static instr_t *
bb_verify_sysenter_pattern(dcontext_t *dcontext, build_bb_t *bb)
{
    /* Walk back up 2 instructions and verify that there's a
     * "call (%xdx); mov %xsp -> %xdx" or "call %xdx; mov %xsp -> %xdx"
     * just prior to the sysenter.
     * We use "xsp" and "xdx" to be ready for x64 sysenter though we don't
     * expect to see it.
     */
    instr_t *instr = instr_get_prev_expanded(dcontext, bb->ilist, bb->instr);

    /* FIXME Relax the pattern matching on the "mov; call" pair so that small
     * changes in the register dataflow and call construct are tolerated. */

    /* Did we find a "mov %xsp -> %xdx"? */
    if (!(instr != NULL && instr_get_opcode(instr) == OP_mov_ld &&
          instr_num_srcs(instr) == 1 && instr_num_dsts(instr) == 1 &&
          opnd_is_reg(instr_get_dst(instr, 0)) &&
          opnd_get_reg(instr_get_dst(instr, 0)) == REG_XDX &&
          opnd_is_reg(instr_get_src(instr, 0)) &&
          opnd_get_reg(instr_get_src(instr, 0)) == REG_XSP)) {
        BBPRINT(bb, 3, "bb_verify_sysenter_pattern -- mov didn't match\n");
        return NULL;
    }
    instr = instr_get_prev_expanded(dcontext, bb->ilist, instr);

    /* Did we find a "call (%xdx) or "call %xdx" that's already marked
     * for ind->direct call conversion? */
    if (!(instr != NULL && TEST(INSTR_IND_CALL_DIRECT, instr->flags) &&
          instr_is_call_indirect(instr) &&
          /* The 2nd src operand should always be %xsp. */
          opnd_is_reg(instr_get_src(instr, 1)) &&
          opnd_get_reg(instr_get_src(instr, 1)) == REG_XSP &&
          /* Match 'call (%xdx)' for post-SP2. */
          ((opnd_is_near_base_disp(instr_get_src(instr, 0)) &&
            opnd_get_base(instr_get_src(instr, 0)) == REG_XDX &&
            opnd_get_disp(instr_get_src(instr, 0)) == 0) ||
           /* Match 'call %xdx' for pre-SP2. */
           (opnd_is_reg(instr_get_src(instr, 0)) &&
            opnd_get_reg(instr_get_src(instr, 0)) == REG_XDX)))) {
        BBPRINT(bb, 3, "bb_verify_sysenter_pattern -- call didn't match\n");
        return NULL;
    }

    return instr;
}

/* Only used for the Borland SEH exemption. */
/* FIXME - we can't really tell a push from a pop since both are typically a
 * mov to fs:[0], but double processing doesn't hurt. */
/* NOTE we don't see dynamic SEH frame pushes, we only see the first SEH push
 * per mov -> fs:[0] instruction in the app.  So we don't see modified in place
 * handler addresses (see at_Borland_SEH_rct_exemption()) or handler addresses
 * that are passed into a shared routine that sets up the frame (not yet seen,
 * note that MS dlls that have a _SEH_prolog hardcode the handler address in
 * the _SEH_prolog routine, only the data is passed in).
 */
static void
bb_process_SEH_push(dcontext_t *dcontext, build_bb_t *bb, void *value)
{
    if (value == NULL || value == (void *)PTR_UINT_MINUS_1) {
        /* could be popping off the last frame (leaving -1) of the SEH stack */
        STATS_INC(num_endlist_SEH_write);
        ASSERT_CURIOSITY(value != NULL);
        return;
    }
    LOG(THREAD, LOG_INTERP, 3, "App moving "PFX" to fs:[0]\n", value);
# ifdef RETURN_AFTER_CALL
    if (DYNAMO_OPTION(borland_SEH_rct)) {
        /* xref case 5752, the Borland compiler SEH implementation uses a push
         * imm ret motif for fall through to the finally of a try finally block
         * (very similar to what the Microsoft NT at_SEH_rct_exception() is
         * doing). The layout will always look like this :
         *     push e:  (imm32)  (e should be in the .E/.F table)
         *  a:
         *     ...
         *  b: ret
         *  c: jmp rel32         (c should be in the .E/.F table)
         *  d: jmp a:  (rel8/32)
         *     ... (usually nothing)
         *  e:
         * (where ret at b is targeting e, or a valid after call).  The 
         * exception dispatcher calls c (the SEH frame has c as the handler)
         * which jmps to the exception handler which, in turn, calls d to
         * execute the finally block.  Fall through is as shown above. So,
         * we see a .E violation for the handlers call to d and a .C violation
         * for the fall trough case of the ret @ b targeting e.  We may also
         * see a .E violation for a call to a as sometimes the handler computes
         * the target of the jmp @ d an passes that to a different exception
         * handler.
         *
         * For try-except we see the following layout :
         *           I've only seen jmp ind in the case that led to needing
         *           at_Borland_SEH_rct_exemption() to be added, not that
         *           it makes any difference.
         *    [ jmp z:  (rel8/32) || (rarely) ret || (very rarely) jmp ind]
         * x: jmp rel32          (x should be in the .E/.F table)  
         * y:
         *    ...
         *    call rel32
         * [z: ... || ret ]
         * Though there may be other optimized layouts (the ret instead of the
         * jmp z: is one such) so we may not want to rely on anything other
         * then x y.  The exception dispatcher calls x (the SEH frame has x as
         * the handler) which jmps to the exception handler which, in turn,
         * jmps to y to execute the except block.  We see a .F violation from
         * the handler's jmp to y.  at_Borland_SEH_rct_exemption() covers a
         * case where the address of x (and thus y) in an existing SEH frame
         * is changed in place instead of popping and pushing a new frame.
         *
         * All addresses (rel and otherwise) should be in the same module.  So
         * we need to recognize the patter and add d:/y: to the .E/.F table
         * as well as a: (sometimes the handler calculates the target of d and
         * passes that up to a higher level routine, though I don't see the
         * point) and add e: to the .C table.
         *
         * It would be preferable to handle these exemptions reactively at
         * the violation point, but unfortunately, by the time we get to the
         * violation the SEH frame information has been popped off the stack
         * and is lost, so we have to do it pre-emptively here (pattern
         * matching at violation time has proven to difficult in the face of
         * certain compiler optimizations). See at_Borland_SEH_rct_exemption()
         * in callback.c, that could handle all ind branches to y and ind calls
         * to d (see below) at an acceptable level of security if we desired.
         * Handling the ret @ b to e reactively would require the ability to
         * recreate the exact src cti (so we can use the addr of the ret to
         * pattern match) at the violation point (something that can't always
         * currently be done, reset flushing etc.).  Handling the ind call to
         * a (which I've never acutally seen, though I've seen the address
         * computed and it looks like it could likely be hit) reactively is
         * more tricky. Prob. the only way to handle that is to allow .E/.F
         * transistions to any address after a push imm32 of an address in the
         * same module, but that might be too permissive.  FIXME - should still
         * revisit doing the exemptions reactively at some point, esp. once we
         * can reliably get the src cti.
         */

        extern bool seen_Borland_SEH; /* set for callback.c */
        /* First read in the SEH frame, this is the observed structure and
         * the first two fields (which are all that we use) are constrained by
         * ntdll exception dispatcher (see EXCEPTION_REGISTRATION decleration
         * in ntdll.h). */
        /* FIXME - could just use EXCEPTION_REGISTRATION period since all we
         * need is the handler address and it would allow simpler curiosity
         * [see 8181] below.  If, as is expected, other options make use of
         * this routine we'll probably have one shared get of the SEH frame
         * anyways. */
        typedef struct _borland_seh_frame_t {
            EXCEPTION_REGISTRATION reg;
            reg_t xbp; /* not used by us */
        } borland_seh_frame_t;
        borland_seh_frame_t frame;
        /* will hold [b,e] or [x-1,y] */
        byte target_buf[RET_0_LENGTH + 2 * JMP_LONG_LENGTH];
        app_pc handler_jmp_target = NULL;

        if (!safe_read(value, sizeof(frame), &frame)) {
            /* We already checked for NULL and -1 above so this should be
             * a valid SEH frame. Xref 8181, borland_seh_frame_t struct is
             * bigger then EXCEPTION_REGISTRATION (which is all that is 
             * required) so verify smaller size is readable. */
            ASSERT_CURIOSITY(sizeof(EXCEPTION_REGISTRATION) < sizeof(frame) &&
                             safe_read(value, sizeof(EXCEPTION_REGISTRATION),
                                       &frame));
            goto post_borland;
        }
        /* frame.reg.handler is c or y, read extra prior bytes to look for b */
        if (!safe_read((app_pc)frame.reg.handler - RET_0_LENGTH,
                       sizeof(target_buf), target_buf)) {
            goto post_borland;
        }
        if (is_jmp_rel32(&target_buf[RET_0_LENGTH], (app_pc)frame.reg.handler,
                         &handler_jmp_target)) {
            /* we have a possible match, now do the more expensive checking */
            app_pc base;
            LOG(THREAD, LOG_INTERP, 3,
                "Read possible borland SEH frame @"PFX"\n\t"
                "next="PFX" handler="PFX" xbp="PFX"\n\t",
                value, frame.reg.prev, frame.reg.handler, frame.xbp);
            DOLOG(3, LOG_INTERP, {
                dump_buffer_as_bytes(THREAD, target_buf, sizeof(target_buf), 0);
            });
            /* optimize check if we've already processed this frame once */
            if ((DYNAMO_OPTION(rct_ind_jump) != OPTION_DISABLED ||
                 DYNAMO_OPTION(rct_ind_call) != OPTION_DISABLED) &&
                rct_ind_branch_target_lookup(dcontext,
                                             (app_pc)frame.reg.handler +
                                             JMP_LONG_LENGTH)) {
                /* we already processed this SEH frame once, this is prob. a
                 * frame pop, no need to continue */
                STATS_INC(num_borland_SEH_dup_frame);
                LOG(THREAD, LOG_INTERP, 3,
                    "Processing duplicate Borland SEH frame\n");
                goto post_borland;
            }
            base = get_module_base((app_pc)frame.reg.handler);
            STATS_INC(num_borland_SEH_initial_match);
            /* Perf opt, we use the cheaper get_allocation_base() below instead
             * of get_module_base().  We are checking the result against a
             * known module base (base) so no need to duplicate the is module
             * check.  FIXME - the checks prob. aren't even necessary given the
             * later is_in_code_section checks. Xref case 8171. */
            /* FIXME - (perf) we could cache the region from the first
             * is_in_code_section() call and check against that before falling
             * back on is_in_code_section in case of multiple code sections. */
            if (base != NULL &&
                get_allocation_base(handler_jmp_target) == base &&
                get_allocation_base(bb->instr_start) == base &&
                /* FIXME - with -rct_analyze_at_load we should be able to
                 * verify that frame->handler (x: c:) is on the .E/.F
                 * table already. We could also try to match known pre x:
                 * post y: patterns. */
                is_in_code_section(base, bb->instr_start, NULL, NULL) &&
                is_in_code_section(base, handler_jmp_target, NULL, NULL) &&
                is_range_in_code_section(base, (app_pc)frame.reg.handler,
                                         (app_pc)frame.reg.handler+JMP_LONG_LENGTH+1,
                                         NULL, NULL)) {
                app_pc finally_target;
                byte push_imm_buf[PUSH_IMM32_LENGTH];
                DEBUG_DECLARE(bool ok;)
                /* we have a match, add handler+JMP_LONG_LENGTH (y: d:)
                 * to .E/.F table */
                STATS_INC(num_borland_SEH_try_match);
                LOG(THREAD, LOG_INTERP, 2,
                    "Found Borland SEH frame adding "PFX" to .E/.F table\n",
                    (app_pc)frame.reg.handler+JMP_LONG_LENGTH);
                if ((DYNAMO_OPTION(rct_ind_jump) != OPTION_DISABLED ||
                     DYNAMO_OPTION(rct_ind_call) != OPTION_DISABLED)) {
                    mutex_lock(&rct_module_lock);
                    rct_add_valid_ind_branch_target(dcontext,
                                                    (app_pc)frame.reg.handler +
                                                    JMP_LONG_LENGTH);
                    mutex_unlock(&rct_module_lock);
                }
                /* we set this as an enabler for another exemption in 
                 * callback .C, see notes there */
                if (!seen_Borland_SEH) {
                    SELF_UNPROTECT_DATASEC(DATASEC_RARELY_PROT);
                    seen_Borland_SEH = true;
                    SELF_PROTECT_DATASEC(DATASEC_RARELY_PROT);
                }
                /* case 8648: used to decide which RCT entries to persist */
                DEBUG_DECLARE(ok =) os_module_set_flag(base, MODULE_HAS_BORLAND_SEH);
                ASSERT(ok);
                /* look for .C addresses for try finally */
                if (target_buf[0] == RAW_OPCODE_ret &&
                    (is_jmp_rel32(&target_buf[RET_0_LENGTH+JMP_LONG_LENGTH],
                                  (app_pc)frame.reg.handler+JMP_LONG_LENGTH,
                                  &finally_target) ||
                     is_jmp_rel8(&target_buf[RET_0_LENGTH+JMP_LONG_LENGTH],
                                 (app_pc)frame.reg.handler+JMP_LONG_LENGTH,
                                 &finally_target)) &&
                    safe_read(finally_target - sizeof(push_imm_buf), 
                              sizeof(push_imm_buf), push_imm_buf) &&
                    push_imm_buf[0] == RAW_OPCODE_push_imm32) {
                    app_pc push_val = *(app_pc *)&push_imm_buf[1];
                    /* do a few more, expensive, sanity checks */
                    /* FIXME - (perf) see earlier note on get_allocation_base()
                     * and is_in_code_section() usage. */
                    if (get_allocation_base(finally_target) == base &&
                        is_in_code_section(base, finally_target, NULL, NULL) &&
                        get_allocation_base(push_val) == base &&
                        /* FIXME - could also check that push_val is in
                         * .E/.F table, at least for -rct_analyze_at_load */
                        is_in_code_section(base, push_val, NULL, NULL)) {
                        /* Full match, add push_val (e:) to the .C table
                         * and finally_target (a:) to the .E/.F table */
                        STATS_INC(num_borland_SEH_finally_match);
                        LOG(THREAD, LOG_INTERP, 2,
                            "Found Borland SEH finally frame adding "PFX" to"
                            " .C table and "PFX" to .E/.F table\n",
                            push_val, finally_target);
                        if ((DYNAMO_OPTION(rct_ind_jump) != OPTION_DISABLED ||
                             DYNAMO_OPTION(rct_ind_call) != OPTION_DISABLED)) {
                            mutex_lock(&rct_module_lock);
                            rct_add_valid_ind_branch_target(dcontext,
                                                            finally_target);
                            mutex_unlock(&rct_module_lock);
                        }
                        if (DYNAMO_OPTION(ret_after_call)) {
                            fragment_add_after_call(dcontext, push_val);
                        }
                    } else {
                        ASSERT_CURIOSITY(false &&
                                         "partial borland seh finally match");
                    }
                }
            }
        }
    }
 post_borland:
# endif /* RETURN_AFTER_CALL */
    return;
}

/* helper routine for bb_process_fs_ref
 * return true if bb should be continued, false if it shouldn't  */
static bool
bb_process_fs_ref_opnd(dcontext_t *dcontext, build_bb_t *bb, opnd_t dst,
                       bool *is_to_fs0)
{
    ASSERT(is_to_fs0 != NULL);
    *is_to_fs0 = false;
    if (opnd_is_far_base_disp(dst) && /* FIXME - check size? */
        opnd_get_segment(dst) == SEG_FS) {
        /* is a write to fs:[*] */
        if (bb->instr_start != bb->start_pc) {
            /* Not first instruction in the bb, end bb before this
             * instruction, so we can see it as the first instruction of a
             * new bb where we can use the register state. */
            /* As is, always ending the bb here has a mixed effect on mem usage
             * with default options.  We do end up with slightly more bb's
             * (and associated bookeeping costs), but frequently with MS dlls
             * we reduce code cache dupliaction from jmp/call ellision 
             * (_SEH_[Pro,Epi]log otherwise ends up frequently duplicated for
             * instance). */
            /* FIXME - we must stop the bb here even if there's already
             * a bb built for the next instruction, as we have to have
             * reproducible bb building for recreate app state.  We should
             * only get here through code duplication (typically jmp/call
             * inlining, though can also be through multiple entry points into
             * the same block of non cti instructions). */ 
            bb_stop_prior_to_instr(dcontext, bb, false/*not appended yet*/);
            return false; /* stop bb */
        }
        /* Only process the push if building a new bb for cache, can't check
         * this any earlier since have to preserve bb building/ending behavior
         * even when not for cache (for recreation etc.). */
        if (bb->app_interp) {
            /* check is write to fs:[0] */
            if (opnd_compute_address(dst, get_mcontext(dcontext)) == NULL) {
                /* we have new mov to fs:[0] */
                *is_to_fs0 = true;
            }
        }
    }
    return true;
}

/* While currently only used for Borland SEH exemptions, this analysis could
 * also be helpful for other SEH tasks (xref case 5824). */
static bool
bb_process_fs_ref(dcontext_t *dcontext, build_bb_t *bb)
{
    ASSERT(DYNAMO_OPTION(process_SEH_push) &&
           instr_get_prefix_flag(bb->instr, PREFIX_SEG_FS));

    /* If this is the first instruction of a bb for the cache we
     * want to fully decode it, check if it's pushing an SEH frame
     * and, if so, pass it to the SEH checking routines (currently
     * just used for the Borland SEH rct handling).  If this is not
     * the first instruction of the bb then we want to stop the bb
     * just before this instruction so that when we do process this
     * instruction it will be the first in the bb (allowing us to
     * use the register state). */
    if (!bb->full_decode) {
        instr_decode(dcontext, bb->instr);
        /* is possible this is an invalid instr that made it through the fast
         * decode, FIXME is there a better way to handle this? */
        if (!instr_valid(bb->instr)) {
            ASSERT_NOT_TESTED();
            if (bb->cur_pc == NULL)
                bb->cur_pc = bb->instr_start;
            bb_process_invalid_instr(dcontext, bb);
            return false; /* stop bb */
        }
        ASSERT(instr_get_prefix_flag(bb->instr, PREFIX_SEG_FS));
    }
    /* expect to see only simple mov's to fs:[0] for new SEH frames
     * FIXME - might we see other types we'd want to intercept? 
     * do we want to proccess pop instructions (usually just for removing
     * a frame)? */
    if (instr_get_opcode(bb->instr) == OP_mov_st) {
        bool is_to_fs0;
        opnd_t dst = instr_get_dst(bb->instr, 0);
        if (!bb_process_fs_ref_opnd(dcontext, bb, dst, &is_to_fs0))
            return false; /* end bb */
        /* Only process the push if building a new bb for cache, can't check
         * this any earlier since have to preserve bb building/ending behavior
         * even when not for cache (for recreation etc.). */
        if (bb->app_interp) {
            if (is_to_fs0) {
                ptr_int_t value = 0;
                opnd_t src = instr_get_src(bb->instr, 0);
                if (opnd_is_immed_int(src)) {
                    value = opnd_get_immed_int(src);
                } else if (opnd_is_reg(src)) {
                    value = reg_get_value(opnd_get_reg(src), get_mcontext(dcontext));
                } else {
                    ASSERT_NOT_REACHED();
                }
                STATS_INC(num_SEH_pushes_processed);
                LOG(THREAD, LOG_INTERP, 3, "found mov to fs:[0] @ "PFX"\n",
                    bb->instr_start);
                bb_process_SEH_push(dcontext, bb, (void *)value);
            } else {
                STATS_INC(num_fs_movs_not_SEH);
            }
        }
    }
# if defined(DEBUG) && defined(INTERNAL)
    else if (INTERNAL_OPTION(check_for_SEH_push)) {
        /* Debug build Sanity check that we aren't missing SEH frame pushes */
        int i;
        int num_dsts = instr_num_dsts(bb->instr);
        for (i = 0; i < num_dsts; i++) {
            bool is_to_fs0;
            opnd_t dst = instr_get_dst(bb->instr, i);
            if (!bb_process_fs_ref_opnd(dcontext, bb, dst, &is_to_fs0)) {
                STATS_INC(num_process_SEH_bb_early_terminate_debug);
                return false; /* end bb */
            }
            /* common case is pop instructions to fs:[0] when popping an
             * SEH frame stored on tos */
            if (is_to_fs0) {
                if (instr_get_opcode(bb->instr) == OP_pop) {
                    LOG(THREAD, LOG_INTERP, 4,
                        "found pop to fs:[0] @ "PFX"\n", bb->instr_start);
                    STATS_INC(num_process_SEH_pop_fs0);
                } else {
                    /* an unexpected SEH frame push */
                    LOG(THREAD, LOG_INTERP, 1,
                        "found unexpected write to fs:[0] @"PFX"\n",
                        bb->instr_start);
                    DOLOG(1, LOG_INTERP, {
                        loginst(dcontext, 1, bb->instr, "");
                    }); 
                    ASSERT_CURIOSITY(!is_to_fs0);
                }
            }
        }
    }
# endif
    return true; /* continue bb */
}
#endif /* win32 */

#ifndef LINUX_KERNEL
/* Returns true to indicate that ignorable syscall processing is completed
 * with *continue_bb indicating if the bb should be continued or not.
 * When returning false, continue_bb isn't pertinent.
 */
static bool
bb_process_ignorable_syscall(dcontext_t *dcontext, build_bb_t *bb,
                             int sysnum, bool *continue_bb)
{
    STATS_INC(ignorable_syscalls);
    BBPRINT(bb, 3, "found ignorable system call 0x%04x\n", sysnum);
#ifdef WINDOWS
    if (get_syscall_method() != SYSCALL_METHOD_SYSENTER) {
        DODEBUG({
            if (get_syscall_method() == SYSCALL_METHOD_WOW64)
                ASSERT_NOT_TESTED();
        });
        if (continue_bb != NULL)
            *continue_bb = true;
        return true;
    }
    else {
        /* Can we continue interp after the sysenter at the instruction
         * after the call to sysenter? */
        instr_t *call = bb_verify_sysenter_pattern(dcontext, bb);

        if (call != NULL) {
            /* If we're continuing code discovery at the after-call address,
             * change the cur_pc to continue at the after-call addr. This is
             * safe since the preceding call is in the fragment and
             * %xsp/(%xsp) hasn't changed since the call. Obviously, we assume
             * that the sysenter breaks control flow in fashion such any
             * instruction that follows it isn't reached by DR.
             */
            if (DYNAMO_OPTION(ignore_syscalls_follow_sysenter)) {
                bb->cur_pc =
                    instr_get_raw_bits(call) + instr_length(dcontext, call);
                if (continue_bb != NULL)
                    *continue_bb = true;
                return true;
            }
            else {
                /* End this bb now. We set the exit target so that control
                 * skips the vsyscall 'ret' that's executed natively after the
                 * syscall and ends up at the correct place.
                 */
                /* FIXME Assigning exit_target causes the fragment to end 
                 * with a direct exit stub to the after-call address, which
                 * is fine. If bb->exit_target < bb->start_pc, the future
                 * fragment for exit_target is marked as a trace head which
                 * isn't intended. A potentially undesirable side effect
                 * is that exit_target's fragment can't be included in
                 * trace for start_pc.
                 */
                bb->exit_target =
                    instr_get_raw_bits(call) + instr_length(dcontext, call);
                if (continue_bb != NULL)
                    *continue_bb = false;
                return true;
            }
        }
        STATS_INC(ignorable_syscalls_failed_sysenter_pattern);
        /* Pattern match failed but the syscall is ignorable so maybe we
         * can try shared syscall? */
        /* Decrement the stat to prevent double counting. We rarely expect to hit
         * this case. */
        STATS_DEC(ignorable_syscalls);
        return false;
    }
#else
    if (continue_bb != NULL)
        *continue_bb = true;
    return true;
#endif
}
#endif

#ifdef WINDOWS
/* Process a syscall that is executed via shared syscall. */
static void
bb_process_shared_syscall(dcontext_t *dcontext, build_bb_t *bb, int sysnum)
{
    ASSERT(DYNAMO_OPTION(shared_syscalls));
    DODEBUG({
        if (ignorable_system_call(sysnum))
            STATS_INC(ignorable_syscalls);
        else
            STATS_INC(optimizable_syscalls);
    });
    BBPRINT(bb, 3, "found %soptimizable system call 0x%04x\n",
            INTERNAL_OPTION(shared_eq_ignore) ? "ignorable-" : "",
            sysnum);

    LOG(THREAD, LOG_INTERP, 3,
        "ending bb at syscall & NOT removing the interrupt itself\n");

    /* Mark the instruction as pointing to shared syscall */
    bb->instr->flags |= INSTR_SHARED_SYSCALL;
    /* this block must be the last one in a trace */
    bb->flags |= FRAG_MUST_END_TRACE;
    /* we redirect all optimizable syscalls to a single shared piece of code.
     * Once a fragment reaches the shared syscall code, it can be safely
     * deleted, for example, if the thread is interrupted for a callback and
     * DR needs to delete fragments for cache management.
     *
     * Note that w/shared syscall, syscalls can be executed from TWO
     * places -- shared_syscall and do_syscall.
     */
    bb->exit_target = shared_syscall_routine(dcontext);
    /* make sure translation for ending jmp ends up right, mangle will
     * remove this instruction, so set to NULL so translation does the
     * right thing */
    bb->instr = NULL;
}
#endif

#ifndef LINUX_KERNEL
static bool
bb_process_non_ignorable_syscall(dcontext_t *dcontext, build_bb_t *bb,
                                 int sysnum)
{
    BBPRINT(bb, 3, "found non-ignorable system call 0x%04x\n", sysnum);
    STATS_INC(non_ignorable_syscalls);
    bb->exit_type |= LINK_NI_SYSCALL;
    /* destroy the interrupt instruction */
    LOG(THREAD, LOG_INTERP, 3,
        "ending bb at syscall & removing the interrupt itself\n");
    /* Indicate that this is a non-ignorable syscall so mangle will remove */
#ifdef LINUX
    if (instr_get_opcode(bb->instr) == OP_int) {
        bb->exit_type |= LINK_NI_SYSCALL_INT;
        bb->instr->flags |= INSTR_NI_SYSCALL_INT;
    } else
#endif
        bb->instr->flags |= INSTR_NI_SYSCALL;
    /* Set instr to NULL in order to get translation of exit cti correct. */
    bb->instr = NULL;
    /* this block must be the last one in a trace */
    bb->flags |= FRAG_MUST_END_TRACE;
    return false; /* end bb now */
}
#endif

/* returns true to indicate "continue bb" and false to indicate "end bb now" */
static inline bool
bb_process_syscall(dcontext_t *dcontext, build_bb_t *bb)
{
#ifdef LINUX_KERNEL
    ASSERT_MESSAGE("There should not be system calls in the kernel.", false);
    return true;
#else
    int sysnum;
#ifdef CLIENT_INTERFACE
    /* PR 307284: for simplicity do syscall/int processing post-client.
     * We give up on inlining but we can still use ignorable/shared syscalls
     * and trace continuation.
     */
    if (bb->pass_to_client && !bb->post_client)
        return false;
#endif
#ifdef DGC_DIAGNOSTICS
    if (TEST(FRAG_DYNGEN, bb->flags) && !is_dyngen_vsyscall(bb->instr_start)) {
        LOG(THREAD, LOG_INTERP, 1, "WARNING: syscall @ "PFX" in dyngen code!\n",
            bb->instr_start);
    }
#endif
    BBPRINT(bb, 4, "interp: syscall @ "PFX"\n", bb->instr_start);
    check_syscall_method(dcontext, bb->instr);
    bb->flags |= FRAG_HAS_SYSCALL;
    /* if we can identify syscall number and it is an ignorable syscall,
     * we let bb keep going, else we end bb and flag it
     */
    sysnum = find_syscall_num(dcontext, bb->ilist, bb->instr);
#ifdef VMX86_SERVER
    DOSTATS({
        if (instr_get_opcode(bb->instr) == OP_int &&
            instr_get_interrupt_number(bb->instr) == VMKUW_SYSCALL_GATEWAY) {
            STATS_INC(vmkuw_syscall_sites);
            LOG(THREAD, LOG_SYSCALLS, 2, "vmkuw system call site: #=%d\n", sysnum);
        }
    });
#endif
    BBPRINT(bb, 3, "syscall # is %d\n", sysnum);
#ifdef CLIENT_INTERFACE 
    if (sysnum > -1 && instrument_filter_syscall(dcontext, sysnum)) {
        BBPRINT(bb, 3, "client asking to intercept => pretending syscall # %d is -1\n",
                sysnum);
        sysnum = -1;
    }
#endif
    if (sysnum > -1 &&
        DYNAMO_OPTION(ignore_syscalls) && 
        ignorable_system_call(sysnum)
        /* PR 288101: On Linux we do not yet support inlined sysenter instrs as we
         * do not have in-cache support for the post-sysenter continuation: we rely
         * for now on very simple sysenter handling where dispatch uses asynch_target
         * to know where to go next.
         */
        IF_LINUX(&& instr_get_opcode(bb->instr) != OP_sysenter)) {

        bool continue_bb;

#ifndef LINUX_KERNEL
        if (bb_process_ignorable_syscall(dcontext, bb, sysnum, &continue_bb)) {
            if (!DYNAMO_OPTION(inline_ignored_syscalls))
                continue_bb = false;
            return continue_bb;
        }
#endif
    }
#ifdef WINDOWS
    if (sysnum > -1 && DYNAMO_OPTION(shared_syscalls) &&
        optimizable_system_call(sysnum)) {
        bb_process_shared_syscall(dcontext, bb, sysnum);
        return false;
    }
#endif
    
    /* Fall thru and handle as a non-ignorable syscall. */
    return bb_process_non_ignorable_syscall(dcontext, bb, sysnum);
#endif
}

/* Case 3922: for wow64 we treat "call *fs:0xc0" as a system call.
 * Only sets continue_bb if it returns true.
 */
static bool
bb_process_indcall_syscall(dcontext_t *dcontext, build_bb_t *bb,
                           bool *continue_bb)
{
    ASSERT(continue_bb != NULL);
#ifdef WINDOWS
    if (instr_is_wow64_syscall(bb->instr)) {
        /* we could check the preceding instrs but we don't bother */
        *continue_bb = bb_process_syscall(dcontext, bb);
        return true;
    }
#endif
    return false;
}

/* returns true to indicate "continue bb" and false to indicate "end bb now" */
static inline bool
bb_process_interrupt(dcontext_t *dcontext, build_bb_t *bb)
{
#if defined(DEBUG) || defined(INTERNAL) || defined(WINDOWS)
    int num = instr_get_interrupt_number(bb->instr);
#endif
#ifdef CLIENT_INTERFACE
    /* PR 307284: for simplicity do syscall/int processing post-client.
     * We give up on inlining but we can still use ignorable/shared syscalls
     * and trace continuation.
     * PR 550752: we cannot end at int 0x2d: we live w/ client consequences
     */
    if (bb->pass_to_client && !bb->post_client IF_WINDOWS(&& num != 0x2d))
        return false;
#endif
    BBPRINT(bb, 3, "int 0x%x @ "PFX"\n", num, bb->instr_start);
#ifdef WINDOWS
    if (num == 0x2b) {
        /* interrupt 0x2B signals return from callback */
        /* end block here and come back to dynamo to perform interrupt */
        bb->exit_type |= LINK_CALLBACK_RETURN;
        BBPRINT(bb, 3, "ending bb at cb ret & removing the interrupt itself\n");
        /* Set instr to NULL in order to get translation of exit cti
         * correct.  mangle will destroy the instruction */
        bb->instr = NULL;
        bb->flags |= FRAG_MUST_END_TRACE;
        STATS_INC(num_int2b);
        return false;
    } else {
        SYSLOG_INTERNAL_INFO_ONCE("non-syscall, non-int2b 0x%x @ "PFX" from "PFX,
                                  num, bb->instr_start, bb->start_pc);
    }
#endif /* WINDOWS */
    return true;
}

/* If the current instr in the BB is an indirect call that can be converted into a
 * direct call, process it and return true, else, return false.
 * FIXME PR 288327: put in linux call* to vsyscall page
 */
static bool
bb_process_convertible_indcall(dcontext_t *dcontext, build_bb_t *bb)
{
    /* We perform several levels of checking, each increasingly more stringent
     * and expensive, with a false return should any fail.
     */
    instr_t *instr;
    opnd_t src0;
    instr_t *call_instr;
    int call_src_reg;
    app_pc callee;
    bool vsyscall = false;

    /* Check if this BB can be extended and the instr is a (near) indirect call */
    if (instr_get_opcode(bb->instr) != OP_call_ind)
        return false;

    /* Check if we have a "mov <imm> -> %reg; call %reg" or a
     * "mov <imm> -> %reg; call (%reg)" pair. First check for the call.
     */
    /* The 'if' conditions are broken up to make the code more readable
     * while #ifdef-ing the WINDOWS case. It's still ugly though.
     */
    instr = bb->instr;
    if (!(
#ifdef WINDOWS
          /* Match 'call (%xdx)' for a post-SP2 indirect call to sysenter. */
          (opnd_is_near_base_disp(instr_get_src(instr, 0)) &&
           opnd_get_base(instr_get_src(instr, 0)) == REG_XDX &&
           opnd_get_disp(instr_get_src(instr, 0)) == 0) ||
#endif
          /* Match 'call %reg'. */
          opnd_is_reg(instr_get_src(instr, 0))))
        return false;

    /* If there's no CTI in the BB, we can check if there are 5+ preceding
     * bytes and if they could hold a "mov" instruction.
     */
    if (!TEST(FRAG_HAS_DIRECT_CTI, bb->flags) &&
        bb->instr_start - 5 >= bb->start_pc) {

        byte opcode = *((byte *) bb->instr_start - 5);

        /* Check the opcode. Do we see a "mov ... -> %reg"?  Valid opcodes are in
         * the 0xb8-0xbf range (Intel IA-32 ISA ref, v.2) and specify the
         * destination register, i.e., 0xb8 means that %xax is the destination.
         */
        if (opcode < 0xb8 || opcode > 0xbf)
            return false;
    }

    /* Check the previous instruction -- is it really a "mov"? */
    src0 = instr_get_src(instr, 0);
    call_instr = instr;
    instr = instr_get_prev_expanded(dcontext, bb->ilist, bb->instr);
    call_src_reg = opnd_is_near_base_disp(src0) ? opnd_get_base(src0) :
        opnd_get_reg(src0);
    if (instr == NULL || instr_get_opcode(instr) != OP_mov_imm ||
        opnd_get_reg(instr_get_dst(instr, 0)) != call_src_reg)
        return false;

    /* For the general case, we don't try to optimize a call
     * thru memory -- just check that the call uses a register.
     */
    callee = NULL;
    if (opnd_is_reg(src0)) {
        /* Extract the target address. */
        callee = (app_pc) opnd_get_immed_int(instr_get_src(instr, 0));
#ifdef WINDOWS
# ifdef PROGRAM_SHEPHERDING
        /* FIXME - is checking for on vsyscall page better or is checking == to 
         * VSYSCALL_BOOTSTRAP_ADDR? Both are hacky. */
        if (is_dyngen_vsyscall((app_pc)opnd_get_immed_int(instr_get_src(instr, 0)))) {
            LOG(THREAD, LOG_INTERP, 4, "Pre-SP2 style indirect call "
                "to sysenter found at "PFX"\n", bb->instr_start);
            STATS_INC(num_sysenter_indcalls);
            vsyscall = true;
            ASSERT(opnd_get_immed_int(instr_get_src(instr, 0)) ==
                   (ptr_int_t)VSYSCALL_BOOTSTRAP_ADDR);
            ASSERT(!use_ki_syscall_routines()); /* double check our determination */
        }
        else
# endif
#endif
            STATS_INC(num_convertible_indcalls);
    }
#ifdef WINDOWS
    /* Match the "call (%xdx)" to sysenter case for SP2-patched os's. Memory at
     * address VSYSCALL_BOOTSTRAP_ADDR (0x7ffe0300) holds the address of
     * KiFastSystemCall or (FIXME - not handled) on older platforms KiIntSystemCall.
     * FIXME It's unsavory to hard-code 0x7ffe0300, but the constant has little
     * context in an SP2 os. It's a hold-over from pre-SP2.
     */
    else if (get_syscall_method() == SYSCALL_METHOD_SYSENTER
             && call_src_reg == REG_XDX
             && opnd_get_immed_int(instr_get_src(instr, 0)) == 
             (ptr_int_t)VSYSCALL_BOOTSTRAP_ADDR) {
        /* Extract the target address. We expect that the memory read using the
         * value in the immediate field is ok as it's the vsyscall page
         * which 1) cannot be made unreadable and 2) cannot be made writable so
         * the stored value will not change. Of course, it's possible that the
         * os could change the page contents.
         */
        callee = (app_pc)
            *((ptr_uint_t *) opnd_get_immed_int(instr_get_src(instr, 0)));
        if (get_app_sysenter_addr() == NULL) {
            /* For the first call* we've yet to decode an app syscall, yet we
             * cannot have later recreations have differing behavior, so we must
             * handle that case (even though it doesn't matter performance-wise
             * as the first call* is usually in runtime init code that's
             * executed once).  So we do a raw byte compare to:
             *   ntdll!KiFastSystemCall:
             *   7c82ed50 8bd4             mov     xdx,xsp
             *   7c82ed52 0f34             sysenter
             */
            uint raw;
            if (!safe_read(callee, sizeof(raw), &raw) || raw != 0x340fd48b)
                callee = NULL;
        } else {
            /* The callee should be a 2 byte "mov %xsp -> %xdx" followed by the
             * sysenter -- check the sysenter's address as 2 bytes past the callee.
             */
            if (callee + 2 != get_app_sysenter_addr())
                callee = NULL;
        }
        vsyscall = (callee != NULL);
        ASSERT(use_ki_syscall_routines()); /* double check our determination */
        DODEBUG({
            if (callee == NULL)
                ASSERT_CURIOSITY(false && "call* to vsyscall unexpected mismatch");
            else {
                LOG(THREAD, LOG_INTERP, 4, "Post-SP2 style indirect call "
                    "to sysenter found at "PFX"\n", bb->instr_start);
                STATS_INC(num_sysenter_indcalls);
            }
        });
    }
#endif

    /* Check if register dataflow matched and we were able to extract
     * the callee address.
     */
    if (callee == NULL)
        return false;

    if (vsyscall) {
        /* Case 8917: abandon coarse-grainness in favor of performance */
        bb->flags &= ~FRAG_COARSE_GRAIN;
        STATS_INC(coarse_prevent_indcall);
    }

    LOG(THREAD, LOG_INTERP, 4, "interp: possible convertible"
        " indirect call from "PFX" to "PFX"\n",
        bb->instr_start, callee);

    if (must_not_be_inlined(callee)) {
        BBPRINT(bb, 3, "   NOT inlining indirect call to "PFX"\n", callee);
        /* Case 8711: coarse-grain can't handle non-exit cti */
        bb->flags &= ~FRAG_COARSE_GRAIN;
        STATS_INC(coarse_prevent_cti);
        ASSERT_CURIOSITY_ONCE(!vsyscall && "leaving call* to vsyscall");
        return true; /* keep bb going, w/o inlining call */
    }

    if (bb->follow_direct &&
        bb->num_elide_call < DYNAMO_OPTION(max_elide_call) &&
        (DYNAMO_OPTION(elide_back_calls) || bb->cur_pc <= callee)) {
        check_new_page_contig(dcontext, bb, bb->cur_pc-1);
        /* FIXME This is identical to the code for evaluating a
         * direct call's callee. If such code appears in another
         * (3rd) place, we should outline it.
         * FIXME: use follow_direct_call()
         */
        if (vsyscall) {
            /* As a flag to allow our xfer from now-non-coarse to coarse
             * (for vsyscall-in-ntdll) we pre-emptively mark as has-syscall.
             */
            ASSERT(!TEST(FRAG_HAS_SYSCALL, bb->flags));
            bb->flags |= FRAG_HAS_SYSCALL;
        }
        if (check_new_page_jmp(dcontext, bb, callee)) {
            if (vsyscall) /* Restore */
                bb->flags &= ~FRAG_HAS_SYSCALL;
            bb->num_elide_call++;
            STATS_INC(total_elided_calls);
            STATS_TRACK_MAX(max_elided_calls, bb->num_elide_call);
            bb->cur_pc = callee;
            /* FIXME: when using follow_direct_call don't forget to set this */
            call_instr->flags |= INSTR_IND_CALL_DIRECT;
            BBPRINT(bb, 4, "   continuing in callee at "PFX"\n", bb->cur_pc);
            return true; /* keep bb going */
        }
        if (vsyscall) {
            /* Case 8917: Restore, just in case, though we certainly expect to have
             * this flag set as soon as we decode a few more instrs and hit the
             * syscall itself -- but for pre-sp2 we currently could be elsewhere on
             * the same page, so let's be safe here.
             */
            bb->flags &= ~FRAG_HAS_SYSCALL;
        }
    }
    /* FIXME: we're also not converting to a direct call - was this intended? */
    BBPRINT(bb, 3, "   NOT following indirect call from "PFX" to "PFX"\n",
            bb->instr_start, callee);
    DODEBUG({
        if (vsyscall) {
            DO_ONCE({
                /* Case 9095: don't complain so loudly if user asked for no elision */
                if (DYNAMO_OPTION(max_elide_call) <= 2)
                    SYSLOG_INTERNAL_WARNING("leaving call* to vsyscall");
                else
                    ASSERT_CURIOSITY(false && "leaving call* to vsyscall");
            });
        }
    });;
    return false; /* stop bb */
}

/* if we make the IAT sections unreadable we will need to map to proper location */
static inline app_pc
read_from_IAT(app_pc iat_reference)
{
    /* FIXME: we should have looked up where the real IAT should be at
     * the time of checking whether is_in_IAT
     */
    return *(app_pc*) iat_reference;
}

/* returns whether target is an IAT of a module that we convert.  Note
 * users still have to check the referred to value to verify targeting
 * a native module.
 */
static bool
is_targeting_convertible_IAT(dcontext_t *dcontext, instr_t *instr,
                             app_pc *iat_reference /* OUT */)
{
    /* FIXME: we could give up on optimizing a particular module,
     * if too many writes to its IAT are found,
     * even 1 may be too much to handle!
     */
    
    /* We only allow constant address, 
     * any registers used for effective address calculation 
     * can not be guaranteed to be constant dynamically.
     */
    /* FIXME: yet a 'call %reg' if that value is an export would be a
     * good sign that we should go backwards and look for a possible
     * mov IAT[func] -> %reg and then optimize that as well - case 1948
     */

    app_pc memory_reference = NULL;
    opnd_t opnd = instr_get_target(instr);

    LOG(THREAD, LOG_INTERP, 4, "is_targeting_convertible_IAT: ");

    /* A typical example of a proper call
     * ff 15 8810807c     call    dword ptr [kernel32+0x1088 (7c801088)]
     * where
     * [7c801088] =  7c90f04c ntdll!RtlAnsiStringToUnicodeString
     *
     * The ModR/M byte for a displacement only with no SIB should be
     * 15 for CALL, 25 for JMP, (no far versions for IAT)
     */
    if (opnd_is_near_base_disp(opnd)) {
        /* FIXME PR 253930: pattern-match x64 IAT calls */
        IF_X64(ASSERT_NOT_IMPLEMENTED(false));
        memory_reference = (app_pc)(ptr_uint_t)opnd_get_disp(opnd);

        /* now should check all other fields */
        if (opnd_get_base(opnd) != REG_NULL || 
            opnd_get_index(opnd) != REG_NULL) {
            /* this is not a pure memory reference, can't be IAT */
            return false;
        }
        ASSERT(opnd_get_scale(opnd) == 0);
    } else {
        return false;
    }

    LOG(THREAD, LOG_INTERP, 3, "is_targeting_convertible_IAT: memory_reference "PFX"\n",
        memory_reference);

    /* FIXME: if we'd need some more additional structures those can
     * be looked up in a separate hashtable based on the IAT base, or
     * we'd have to extend the vmareas with custom fields
     */
    ASSERT(DYNAMO_OPTION(IAT_convert));
    if (vmvector_overlap(IAT_areas, memory_reference, memory_reference+1)) {
        /* IAT has to be in the same module as current instruction,
         * but even in the unlikely reference by address from another
         * module there is really no problem, so not worth checking
         */
        ASSERT_CURIOSITY(get_module_base(instr->bytes) == get_module_base(memory_reference));

        /* FIXME: now that we know it is in IAT/GOT,
         * we have to READ the contents and return that 
         * safely to the caller so they can convert accordingly
         */

        /* FIXME: we would want to add the IAT section to the vmareas
         * of a region that has a converted block.  Then on a write to
         * IAT we can flush efficiently only blocks affected by a
         * particular module, for a first hack though flushing
         * everything on a hooker will do.
         */
        *iat_reference = memory_reference;
        return true;
    } else {
        /* plain global function
         * e.g. ntdll!RtlUnicodeStringToAnsiString+0x4c:
         * ff15c009917c call dword ptr [ntdll!RtlAllocateStringRoutine (7c9109c0)]
         */
        return false;
    }
}

/* If the current instr in the BB is an indirect call through IAT that
 * can be converted into a direct call, process it and return true,
 * else, return false.
 */
static bool
bb_process_IAT_convertible_indjmp(dcontext_t *dcontext, build_bb_t *bb,
                                  bool *elide_continue)
{
    app_pc iat_reference;
    app_pc target;
    ASSERT(DYNAMO_OPTION(IAT_convert));

    /* Check if the instr is a (near) indirect jump */
    if (instr_get_opcode(bb->instr) != OP_jmp_ind) {
        ASSERT_CURIOSITY(false && "far ind jump");
        return false;           /* not matching, stop bb */
    }

    if (!is_targeting_convertible_IAT(dcontext, bb->instr, 
                                      &iat_reference)) {
        DOSTATS({
            if (TEST(INSTR_IND_JMP_PLT_EXIT, bb->exit_type)) {
                /* see how often we mark as likely a PLT a JMP which in
                 * fact is not going through IAT 
                 */
                STATS_INC(num_indirect_jumps_PLT_not_IAT);
                LOG(THREAD, LOG_INTERP, 3,
                    "bb_process_IAT_convertible_indjmp: indirect jmp not PLT instr="
                    PFX"\n", bb->instr->bytes);
            }
        });
        
        return false;           /* not matching, stop bb */
    }

    target = read_from_IAT(iat_reference);

    DOLOG(4, LOG_INTERP, {
        char name[MAXIMUM_SYMBOL_LENGTH];
        print_symbolic_address(target, name, sizeof(name), false);
        LOG(THREAD, LOG_INTERP, 4, 
            "bb_process_IAT_convertible_indjmp: target="PFX" %s\n", target, name);
    });

    STATS_INC(num_indirect_jumps_IAT);
    DOSTATS({
        if (!TEST(INSTR_IND_JMP_PLT_EXIT, bb->exit_type)) {
            /* count any other known uses for an indirect jump to go
             * through the IAT other than PLT uses, although a block
             * reaching max_elide_call would prevent the above
             * match */
            STATS_INC(num_indirect_jumps_IAT_not_PLT);
            /* FIXME: case 6459 for further inquiry */
            LOG(THREAD, LOG_INTERP, 4, 
                "bb_process_IAT_convertible_indjmp: indirect jmp not PLT target="PFX"\n", 
                target);
        }
    });

    if (must_not_be_elided(target)) {
        ASSERT_NOT_TESTED();
        BBPRINT(bb, 3,
                "   NOT inlining indirect jmp to must_not_be_elided "PFX"\n", target);
        return false; /* do not convert indirect jump, will stop bb */
    }

    /* Verify not targeting native exec DLLs, note that the IATs of
     * any module may have imported a native DLL.  Note it may be
     * possible to optimize with a range check on IAT subregions, but
     * this check isn't much slower.
     */

    /* IAT_elide should definitely not touch native_exec modules.
     * 
     * FIXME: we also prevent IAT_convert from optimizing imports in
     * native_exec_list DLLs, although we could let that convert to a
     * direct jump and require native_exec_dircalls to be always on to
     * intercept those jmps.
     */
    if (DYNAMO_OPTION(native_exec) &&
        vmvector_overlap(native_exec_areas, target, target+1)) {
        BBPRINT(bb, 3,
                "   NOT inlining indirect jump to native exec module "PFX"\n", target);
        STATS_INC(num_indirect_jumps_IAT_native);
        return false;           /* do not convert indirect jump, stop bb */
    }

    /* mangle mostly as such as direct jumps would be mangled in
     * bb_process_ubr(dcontext, bb) but note bb->instr has already
     * been appended so has to reverse some of its actions
     */
    
    /* pretend never saw an indirect JMP, we'll either add a new
       direct JMP or we'll just continue in target */
    instrlist_remove(bb->ilist, bb->instr);    /* bb->instr has been appended already */
    instr_destroy(dcontext, bb->instr);
    bb->instr = NULL;

    if (DYNAMO_OPTION(IAT_elide)) {
        /* try to elide just as a direct jmp would have been elided */

        /* We could have used follow_direct_call instead since
         * commonly this really is a disguised CALL*. Yet for PLT use
         * of the form of CALL PLT[foo]; JMP* IAT[foo] we would have
         * already counted the CALL.  If we have tail call elimination
         * that converts a CALL* into a JMP* it is also OK to treat as
         * a JMP instead of a CALL just as if sharing tails.
         */
        if (follow_direct_jump(dcontext, bb, target)) {
            LOG(THREAD, LOG_INTERP, 4, 
                "bb_process_IAT_convertible_indjmp: eliding jmp* target="PFX"\n", 
                target);

            STATS_INC(num_indirect_jumps_IAT_elided);
            *elide_continue = true; /* do not stop bb */
            return true;        /* converted indirect to direct */
        }
    }
    /* otherwise convert to direct jump without eliding */

    /* we set bb->instr to NULL so unlike bb_process_ubr
     * we get the final exit_target added by build_bb_ilist
     * FIXME: case 85: which will work only when we're using bb->mangle_ilist
     * FIXME: what are callers supposed to see when we do NOT mangle?
     */

    LOG(THREAD, LOG_INTERP, 4, 
        "bb_process_IAT_convertible_indjmp: converting jmp* target="PFX"\n", 
        target);

    STATS_INC(num_indirect_jumps_IAT_converted);
    /* end basic block with a direct JMP to target */
    bb->exit_target = target;   
    *elide_continue = false;    /* matching, but should stop bb */
    return true;               /* matching */
}

/* Returns true if the current instr in the BB is an indirect call
 * through IAT that can be converted into a direct call, process it
 * and sets elide_continue.  Otherwise function return false.
 * OUT elide_continue is set when bb building should continue in target,
 * and not set when bb building should be stopped.
 */
static bool
bb_process_IAT_convertible_indcall(dcontext_t *dcontext, build_bb_t *bb,
                                   bool *elide_continue)
{
    app_pc iat_reference;
    app_pc target;
    ASSERT(DYNAMO_OPTION(IAT_convert));

    /* FIXME: the code structure is the same as
     * bb_process_IAT_convertible_indjmp, could fuse the two
     */

    /* We perform several levels of checking, each increasingly more stringent
     * and expensive, with a false return should any fail.
     */

    /* Check if the instr is a (near) indirect call */
    if (instr_get_opcode(bb->instr) != OP_call_ind) {
        ASSERT_CURIOSITY(false && "far call");
        return false;           /* not matching, stop bb */
    }

    if (!is_targeting_convertible_IAT(dcontext, bb->instr,
                                      &iat_reference)) {
        return false;           /* not matching, stop bb */
    }
    target = read_from_IAT(iat_reference);
    DOLOG(4, LOG_INTERP, {
        char name[MAXIMUM_SYMBOL_LENGTH];
        print_symbolic_address(target, name, sizeof(name), false);
        LOG(THREAD, LOG_INTERP, 4, 
            "bb_process_IAT_convertible_indcall: target="PFX" %s\n", target, name);
    });
    STATS_INC(num_indirect_calls_IAT);
    
    /* mangle mostly as such as direct calls are mangled with
     * bb_process_call_direct(dcontext, bb)
     */

    if (must_not_be_inlined(target)) {
        ASSERT_NOT_TESTED();
        BBPRINT(bb, 3,
                "   NOT inlining indirect call to must_not_be_inlined "PFX"\n", target);
        return false; /* do not convert indirect call, stop bb */
    }

    /* Verify not targeting native exec DLLs, note that the IATs of
     * any module may have imported a native DLL.  Note it may be
     * possible to optimize with a range check on IAT subregions, but
     * this check isn't much slower.
     */
    if (DYNAMO_OPTION(native_exec) &&
        vmvector_overlap(native_exec_areas, target, target+1)) {
        BBPRINT(bb, 3,
                "   NOT inlining indirect call to native exec module "PFX"\n", target);
        STATS_INC(num_indirect_calls_IAT_native);
        return false;           /* do not convert indirect call, stop bb */
    }

    /* mangle_indirect_call and calculate return address as of
     * bb->instr and will remove bb->instr 
     * FIXME: it would have been
     * better to replace in instrlist with a direct call and have
     * mangle_{in,}direct_call use other than the raw bytes, but this for now does the job.
     */
    bb->instr->flags |= INSTR_IND_CALL_DIRECT;

    if (DYNAMO_OPTION(IAT_elide)) {
        /* try to elide just as a direct call would have been elided */
        if (follow_direct_call(dcontext, bb, target)) {
            LOG(THREAD, LOG_INTERP, 4, 
                "bb_process_IAT_convertible_indcall: eliding call* flags=0x%08x target="
                PFX"\n", bb->instr->flags, target);

            STATS_INC(num_indirect_calls_IAT_elided);
            *elide_continue = true; /* do not stop bb */
            return true;        /* converted indirect to direct */
        }
    }
    /* otherwise convert to direct call without eliding */

    LOG(THREAD, LOG_INTERP, 4, 
        "bb_process_IAT_convertible_indcall: converting call* flags=0x%08x target="PFX
        "\n", bb->instr->flags, target);

    STATS_INC(num_indirect_calls_IAT_converted);
    /* bb->instr has been appended already, and will get removed by
     * mangle_indirect_call.  We don't need to set to NULL, since this
     * instr is a CTI and the final jump's translation target should
     * still be the original indirect call.
     */
    bb->exit_target = target;
    /* end basic block with a direct CALL to target.  With default
     * options it should get mangled to a PUSH; JMP
     */
    *elide_continue = false;    /* matching, but should stop bb */
    return true;                /* converted indirect to direct */
}

static bool
instr_will_be_exit_cti(instr_t *inst)
{
    /* can't use instr_is_exit_cti() on pre-mangled instrs */
    return (instr_ok_to_mangle(inst) &&
            instr_is_cti(inst) &&
            (!instr_is_call_direct(inst) ||
             !must_not_be_inlined(instr_get_branch_target_pc(inst)))
            /* PR 239470: ignore wow64 syscall, which is an ind call */
            IF_WINDOWS(&& !instr_is_wow64_syscall(inst)));
}

#ifdef CLIENT_INTERFACE
# ifndef LINUX_KERNEL
/* PR 215217: check syscall restrictions */
static bool
client_check_syscall(instrlist_t *ilist, instr_t *inst,
                     bool *found_syscall, bool *found_int)
{
    /* We do consider the wow64 call* a syscall here (it is both
     * a syscall and a call*: PR 240258).
     */
    if (instr_is_syscall(inst) || instr_get_opcode(inst) == OP_int) {
        if (instr_is_syscall(inst) && found_syscall != NULL)
            *found_syscall = true;
        /* Xref PR 313869 - we should be ignoring int 3 here. */
        if (instr_get_opcode(inst) == OP_int && found_int != NULL)
            *found_int = true;
        /* For linux an ignorable syscall is not a problem.  Our
         * pre-syscall-exit jmp is added post client mangling so should
         * be robust.
         * FIXME: now that we have -no_inline_ignored_syscalls should
         * we assert on ignorable also?  Probably we'd have to have
         * an exception for the middle of a trace?
         */
        if (IF_LINUX(TEST(INSTR_NI_SYSCALL, inst->flags))
            /* PR 243391: only block-ending interrupt 2b matters */
            IF_WINDOWS(instr_is_syscall(inst) ||
                       ((instr_get_opcode(inst) == OP_int &&
                         instr_get_interrupt_number(inst) == 0x2b)))) {
            /* This check means we shouldn't hit the exit_type flags
             * check below but we leave it in place in case we add
             * other flags in future
             */
            if (inst != instrlist_last(ilist)) {
                CLIENT_ASSERT(false, "a syscall or interrupt must terminate the block");
                return false;
            }
            /* should we forcibly delete the subsequent instrs?
             * or the client has to deal w/ bad behavior in release build?
             */
        }
    }
    return true;
}
# endif /* LINUX_KERNEL */

/* Pass bb to client, and afterward check for criteria we require and rescan for
 * eflags and other flags that might have changed.
 */
static void
client_process_bb(dcontext_t *dcontext, build_bb_t *bb,
                  ibl_branch_type_t *ibl_branch_type)
{
    dr_emit_flags_t emitflags = DR_EMIT_DEFAULT;
    instr_t *inst;
    bool found_exit_cti = false;
    bool found_syscall = false;
    bool found_int = false;
    instr_t *last_app_instr = NULL;

    /* This routine is called by more than just bb builder, also used
     * for recreating state, so only call if caller requested it
     * (usually that coincides w/ bb->app_interp being set, but not
     * when recreating state on a fault (PR 214962)).
     * FIXME: hot patches shouldn't be injected during state recreations;
     *        does predicating on bb->app_interp take care of this issue?
     */
    if (!bb->pass_to_client)
        return;

    /* Call the bb creation callback(s) */
    if (!instrument_basic_block(dcontext, (app_pc) bb->start_pc, bb->ilist,
                                bb->for_trace, !bb->app_interp, &emitflags)) {
        /* although no callback was called we must process syscalls/ints (PR 307284) */
    }

    bb->post_client = true;

    /* FIXME: instrumentor may totally mess us up -- our flags
     * or syscall info might be wrong.  xref PR 215217
     */

    /* PR 215217, PR 240265:
     * We need to check for client changes that require a new exit
     * target.  We can't practically analyze the instrlist to decipher
     * the exit, so we'll search backwards and require that the last 
     * cti is the exit cti.  Typically, the last instruction in the 
     * block should be the exit.  Post-mbr and post-syscall positions
     * are particularly fragile, as our mangling code sets state up for
     * the exit that could be messed up by instrs inserted after the
     * mbr/syscall.  We thus disallow such instrs (except for
     * dr_insert_mbr_instrumentation()).  xref cases 10503, 10782, 10784
     *
     * Here's what we support:
     * - more than one exit cti; all but the last must be a ubr
     * - an exit cbr or call must be the final instr in the block
     * - only one mbr; must be the final instr in the block and the exit target
     * - clients can't change the exit of blocks ending in a syscall
     *   (or int), and the syscall must be the final instr in the block;
     *   client can, however, remove the syscall and then add a different exit
     * - client can't add a translation target that's outside of the original
     *   source code bounds, or else our cache consistency breaks down
     *   (the one exception to this is that a jump can translate to its target)
     */

    /* we set to NULL to have a default of fall-through */
    bb->exit_target = NULL;
    bb->exit_type = 0;

    /* N.B.: we're walking backward */
    for (inst = instrlist_last(bb->ilist); inst != NULL; inst = instr_get_prev(inst)) {

        if (!instr_opcode_valid(inst))
            continue;

        if (instr_is_cti(inst) && inst != instrlist_last(bb->ilist)) {
            /* PR 213005: coarse_units can't handle added ctis (meta or not)
             * since decode_fragment(), used for state recreation, can't
             * distinguish from exit cti.
             */
            bb->flags &= ~FRAG_COARSE_GRAIN;
            STATS_INC(coarse_prevent_client);
        }

        if (!instr_ok_to_mangle(inst))
            continue;

        /* in case bb was truncated, find last non-meta fall-through */
        if (last_app_instr == NULL)
            last_app_instr = inst;
    
        /* PR 215217: client should not add new source code regions, else our
         * cache consistency (both page prot and selfmod) will fail
         */
        CLIENT_ASSERT(DYNAMO_OPTION(opt_speed) || (
                      (instr_get_translation(inst) >= bb->start_pc &&
                       instr_get_translation(inst) < bb->cur_pc) ||
                      (instr_is_ubr(inst) && opnd_is_pc(instr_get_target(inst)) &&
                       instr_get_translation(inst) == opnd_get_pc(instr_get_target(inst))))
                      /* the displaced code and jmp return from intercept buffer
                       * has translation fields set to hooked app routine */
                      IF_WINDOWS(|| dr_fragment_app_pc(bb->start_pc) != bb->start_pc),
                      "block's app sources (instr_set_translation() targets) "
                      "must remain within original bounds");

        /* PR 307284: we didn't process syscalls and ints pre-client
         * so do so now to get bb->flags and bb->exit_type set
         */
        if (instr_is_syscall(inst) || instr_get_opcode(inst) == OP_int) {
            instr_t *tmp = bb->instr;
            bb->instr = inst;
            if (instr_is_syscall(bb->instr))
                bb_process_syscall(dcontext, bb);
            else if (instr_get_opcode(bb->instr) == OP_int) /* non-syscall int */
                bb_process_interrupt(dcontext, bb);
            if (inst != instrlist_last(bb->ilist))
                bb->instr = tmp;
        }

#ifndef LINUX_KERNEL
        /* ensure syscall/int2b terminates block */
        client_check_syscall(bb->ilist, inst, &found_syscall, &found_int);
#endif

        if (instr_will_be_exit_cti(inst)) {

            if (!found_exit_cti) {
                /* We're about to clobber the exit_type and could lose any
                 * special flags set above, even if the client doesn't change
                 * the exit target.  We undo such flags after this ilist walk
                 * to support client removal of syscalls/ints.
                 * INSTR_IND_JMP_PLT_EXIT is used for indcall2direct, which
                 * is off by default for CI; it's also used for native_exec,
                 * but we're not sure if we want to support that with CI.
                 * xref case 10846
                 */
                CLIENT_ASSERT(!TEST(~(LINK_DIRECT | LINK_INDIRECT | LINK_CALL |
                                      LINK_RETURN | LINK_JMP
                                      IF_NOT_LINUX_KERNEL(| LINK_NI_SYSCALL_ALL)
                                      IF_WINDOWS(| LINK_CALLBACK_RETURN)),
                                    bb->exit_type),
                              "client unsupported block exit type internal error");

                found_exit_cti = true;
                bb->instr = inst;

                if (instr_is_ubr(inst) || instr_is_call_direct(inst)) {
                    CLIENT_ASSERT(instr_is_ubr(inst) ||
                                  inst == instrlist_last(bb->ilist),
                                  "an exit call must terminate the block");
                    /* a ubr need not be the final instr */
                    if (inst == last_app_instr) {
                        bb->exit_target = instr_get_branch_target_pc(inst);
                        bb->exit_type = instr_branch_type(inst);
                    }
                }
                else if (instr_is_cbr(inst)) {
                    CLIENT_ASSERT(inst == instrlist_last(bb->ilist),
                                  "an exit cbr must terminate the block");
                    /* A null exit target specifies a cbr (see below). */
                    bb->exit_target = NULL;
                    bb->exit_type = 0;
                    instr_exit_branch_set_type(bb->instr,
                                               instr_branch_type(inst));
                }
#ifdef LINUX_KERNEL
                else if (instr_may_return_to_user(inst)) {
                    bb->exit_target = (app_pc) fake_user_return_exit_target;
                    bb->exit_type = instr_branch_type(inst);
                    bb->flags |= FRAG_MUST_END_TRACE; 
                }
#endif
                else {
                    ASSERT(instr_is_mbr(inst));
                    CLIENT_ASSERT(inst == instrlist_last(bb->ilist),
                                  "an exit mbr must terminate the block");
                    bb->exit_target = get_ibl_routine(dcontext, IBL_LINKED,
                                                      DEFAULT_IBL_BB(), 
                                                      get_ibl_branch_type(inst));
                    bb->exit_type = instr_branch_type(inst);
                    *ibl_branch_type = get_ibl_branch_type(inst);
                }

                /* since we're walking backward, at the first exit cti
                 * we can check for post-cti code
                 */
                if (inst != instrlist_last(bb->ilist)) {
                    if (TEST(FRAG_COARSE_GRAIN, bb->flags)) {
                        /* PR 213005: coarse can't handle code beyond ctis */
                        bb->flags &= ~FRAG_COARSE_GRAIN;
                        STATS_INC(coarse_prevent_client);
                    }
                    /* decode_fragment can't handle code beyond ctis */
                    bb->flags |= FRAG_CANNOT_BE_TRACE;
                }

            }

            /* Case 10784: Clients can confound trace building when they
             * introduce more than one exit cti; we'll just disable traces
             * for these fragments.
             * PR 215179: we're currently later marking them no-trace for pad_jmps
             * reasons as well.
             */
            else {
                CLIENT_ASSERT(DYNAMO_OPTION(opt_speed) ||
                              instr_is_ubr(inst),
                              "a second exit cti must be a ubr");
                bb->flags |= FRAG_CANNOT_BE_TRACE;
                /* our cti check above should have already turned off coarse */
                ASSERT(!TEST(FRAG_COARSE_GRAIN, bb->flags));
            }
        }
    }

    /* To handle the client modifying syscall numbers we cannot inline
     * syscalls in the middle of a bb.
     */
    ASSERT(!DYNAMO_OPTION(inline_ignored_syscalls));

    ASSERT((TEST(FRAG_HAS_SYSCALL, bb->flags) && found_syscall) ||
           (!TEST(FRAG_HAS_SYSCALL, bb->flags) && !found_syscall));
    IF_WINDOWS(ASSERT(!TEST(LINK_CALLBACK_RETURN, bb->exit_type) || found_int));

    /* Note that we do NOT remove, or set, FRAG_HAS_DIRECT_CTI based on
     * client modifications: setting it for a selfmod fragment could
     * result in an infinite loop, and it is mainly used for elision, which we
     * are not doing for client ctis.  Clients are not supposed add new
     * app source regions (PR 215217).
     */

    /* Client might have truncated: re-set fall-through. */
    if (last_app_instr != NULL) {
        /* We do not take instr_length of what the client put in, but rather
         * the length of the translation target
         */
        app_pc last_app_pc = instr_get_translation(last_app_instr);
        bb->cur_pc = decode_next_pc(dcontext, last_app_pc);
        LOG(THREAD, LOG_INTERP, 3,
            "setting cur_pc (for fall-through) to" PFX"\n", bb->cur_pc);
        /* don't set bb->instr if last instr is still syscall/int.
         * FIXME: I'm not 100% convinced the logic here covers everything
         * build_bb_ilist does.
         * FIXME: what about if last instr was invalid, or if client adds
         * some invalid instrs: xref bb_process_invalid_instr()
         */
        if (bb->instr != NULL || (!found_int && !found_syscall))
            bb->instr = last_app_instr;
    } else
        bb->instr = NULL; /* no app instrs left */

    /* PR 215217: re-scan for accurate eflags.
     * FIXME: should we not do eflags tracking while decoding, then, and always
     * do it afterward?
     */
    bb->eflags = forward_eflags_analysis(dcontext, bb->ilist, instrlist_first(bb->ilist));

    if (TEST(DR_EMIT_STORE_TRANSLATIONS, emitflags)) {
        /* PR 214962: let client request storage instead of recreation */
        bb->flags |= FRAG_HAS_TRANSLATION_INFO;
        /* if we didn't have record on from start, can't store translation info */
        ASSERT(bb->record_translation && bb->full_decode);
    }
}
#endif /* CLIENT_INTERFACE */

/* Interprets the application's instructions until the end of a basic
 * block is found, and prepares the resulting instrlist for creation of
 * a fragment, but does not create the fragment, just returns the instrlist.
 * Caller is responsible for freeing the list and its instrs!
 *
 * Input parameters in bb control aspects of creation:
 *   If app_interp is true, this is considered real app code.
 *   If pass_to_client is true,
 *     calls instrument routine on bb->ilist before mangling
 *   If mangle_ilist is true, mangles the ilist, else leaves it in app form
 *   If for_cache is true, updates the vmareas data structures
 *     Caller must set and later clear dcontext->bb_build_info.
 *     For !for_cache, build_bb_ilist() sets and clears it, making the
 *     assumption that the caller is doing no other reading from the region.
 *   If record_translation is true, records translation for inserted instrs
 *   If outf != NULL, does full disassembly with comments to outf
 *   If overlap_info != NULL, records overlap information for the block in
 *     the overlap_info (caller must fill in region_start and region_end).
 *
 * FIXME: now that we have better control over following direct ctis,
 * should we have adaptive mechanism to decided whether to follow direct
 * ctis, since some bmarks are better doing so (gap, vortex, wupwise)
 * and others are worse (apsi, perlbmk)?
 */
static void
build_bb_ilist(dcontext_t *dcontext, build_bb_t *bb)
{
    /* Design decision: we will not try to identify branches that target
     * instructions in this basic block, when we take those branches we will
     * just make a new basic block and duplicate part of this one
     */
    int total_branches = 0;
    uint total_instrs = 0;
    uint total_writes = 0; /* only used for selfmod */
    instr_t *non_cti;              /* used if !full_decode */
    byte *non_cti_start_pc; /* used if !full_decode */
    uint eflags_6 = 0; /* holds arith eflags written so far (in read slots) */
    /* indirect branch type as an IBL selector */
    ibl_branch_type_t ibl_branch_type = IBL_GENERIC; /* initialization only */
#ifdef HOT_PATCHING_INTERFACE
    bool hotp_should_inject = false, hotp_injected = false;
#endif
    app_pc page_start_pc = (app_pc) NULL;
    bool bb_build_nested = false;
    /* Caller will free objects allocated here so we must use the passed-in
     * dcontext for allocation; we need separate var for non-global dcontext.
     */
    dcontext_t *my_dcontext = get_thread_private_dcontext();
    DEBUG_DECLARE(bool regenerated = false;)

    ASSERT(bb->initialized);
    /* note that it's ok for bb->start_pc to be NULL as our check_new_page_start
     * will catch it
     */
    /* vmlist must start out empty (or N/A) */
    ASSERT(bb->vmlist == NULL || !bb->for_cache);

#ifdef CUSTOM_TRACES_RET_REMOVAL
    my_dcontext->num_calls = 0;
    my_dcontext->num_rets = 0;
#endif

    /* Support bb abort on decode fault */
    if (my_dcontext != NULL) {
        if (bb->for_cache) {
            /* Caller should have set! */
            ASSERT(bb == (build_bb_t *) my_dcontext->bb_build_info);
        } else if (my_dcontext->bb_build_info == NULL) {
            my_dcontext->bb_build_info = (void *) bb;
        } else {
            /* For nested we leave the original, which should be the only vmlist,
             * and we give up on freeing dangling instr_t and instrlist_t from this decode.
             * We need the original's for_cache so we know to free the bb_building_lock.
             * FIXME: use TRY to handle decode exceptions locally?  Shouldn't have
             * violation remediations on a !for_cache build.
             */
            ASSERT(bb->vmlist == NULL && !bb->for_cache &&
                   ((build_bb_t *)my_dcontext->bb_build_info)->for_cache);
            /* FIXME: add nested as a field so we can have stat on nested faults */
            bb_build_nested = true;
        }
    } else
        ASSERT(dynamo_exited);
    
    if (bb->record_translation || !bb->for_cache ||
        IF_CLIENT_INTERFACE_ELSE(INTERNAL_OPTION(full_decode), false))
        bb->full_decode = true;
    else {
#if defined(STEAL_REGISTER) || defined(CHECK_RETURNS_SSE2)
        bb->full_decode = true;
#endif
    }

    LOG(THREAD, LOG_INTERP, 3, "\ninterp: ");
    BBPRINT(bb, 3, "start_pc = "PFX"\n", bb->start_pc);

    DOSTATS({
        if (bb->app_interp) {
            if (fragment_lookup_deleted(dcontext, bb->start_pc)) {
                /* this will look up private 1st, so yes we will get
                 * dup stats if multiple threads have regnerated the
                 * same private tag, or if a shared tag is deleted and
                 * multiple privates created
                 */
                regenerated = true;
                STATS_INC(num_fragments_deja_vu);
            }
        }
    });

    /* start converting instructions into IR */
    check_new_page_start(dcontext, bb);
    bb->cur_pc = bb->start_pc;
    
    /* for translation in case we break out of loop before decoding any
     * instructions, (i.e. check_for_stopping_point()) */
    bb->instr_start = bb->cur_pc;

    /* create instrlist after check_new_page_start to avoid memory leak
     * on unreadable memory -- though we now properly clean up and won't leak
     * on unreadable on any check_thread_vm_area call
     */
    bb->ilist = instrlist_create(dcontext);
    bb->instr = NULL;

    /* avoid discrepancy in finding invalid instructions between fast decode
     * and the full decode of sandboxing by doing full decode up front
     */
    if (TEST(FRAG_SELFMOD_SANDBOXED, bb->flags))
        bb->full_decode = true;
    if (TEST(FRAG_HAS_TRANSLATION_INFO, bb->flags)) {
        bb->full_decode = true;
        bb->record_translation = true;
    }

    KSTART(bb_decoding);
    while (true) {
        if (check_for_stopping_point(dcontext, bb)) {
            BBPRINT(bb, 3, "interp: found DynamoRIO stopping point at "PFX"\n",
                    bb->cur_pc);
            break;
        }

        /* fill in a new instr structure and update bb->cur_pc */
        bb->instr = instr_create(dcontext);
        /* if !full_decode:
         * All we need to decode are control-transfer instructions
         * For efficiency, put all non-cti into a single instr_t structure
         */
        non_cti_start_pc = bb->cur_pc;
        do {
            /* If the thread's vmareas aren't being added to, indicate the
             * page that's being decoded. */
            if (!bb->for_cache
                && page_start_pc != (app_pc) PAGE_START(bb->cur_pc)) {
                page_start_pc = (app_pc) PAGE_START(bb->cur_pc);
                set_thread_decode_page_start(my_dcontext == NULL ?
                                             dcontext : my_dcontext, page_start_pc);
            }

            bb->instr_start = bb->cur_pc;
            if (bb->full_decode) {
                /* only going through this do loop once! */
                bb->cur_pc = decode(dcontext, bb->cur_pc, bb->instr);
                if (bb->record_translation)
                    instr_set_translation(bb->instr, bb->instr_start);
            } else {
                /* must reset, may go through loop multiple times */
                instr_reset(dcontext, bb->instr);
                bb->cur_pc = decode_cti(dcontext, bb->cur_pc, bb->instr);
            }

            ASSERT(!bb->check_vm_area || bb->checked_end != NULL);
            if (bb->check_vm_area &&
                bb->cur_pc != NULL && bb->cur_pc-1 > bb->checked_end) {
                /* We're beyond the vmarea allowed -- so check again.
                 * Ideally we'd want to check BEFORE we decode from the
                 * subsequent page, as it could be inaccessible, but not worth
                 * the time estimating the size from a variable number of bytes
                 * before the page boundary.  Instead we rely on other
                 * mechanisms to handle faults while decoding, which we need
                 * anyway to handle racy unmaps by the app.
                 */
                check_new_page_contig(dcontext, bb, bb->cur_pc-1);
            }

            total_instrs++;
            DOELOG(3, LOG_INTERP, {
                disassemble_with_bytes(dcontext, bb->instr_start, THREAD);
            });

#ifdef LINUX_KERNEL            
            ASSERT(instr_get_opcode(bb->instr) != OP_int);
            ASSERT(instr_get_opcode(bb->instr) != OP_sysexit);
            ASSERT(instr_get_opcode(bb->instr) != OP_jmp_far);
            ASSERT(instr_get_opcode(bb->instr) != OP_jmp_far_ind);
            ASSERT(instr_get_opcode(bb->instr) != OP_call_far);
            ASSERT(instr_get_opcode(bb->instr) != OP_call_far_ind);
            ASSERT(instr_get_opcode(bb->instr) != OP_int3);
            /* TODO(peter): We can't check for all gs writes because
             * load_gs_index needs to write to gs. We should whitelist it. */
# if 0
            DODEBUG({
                uint i;
                for (i = 0; i < instr_num_dsts(bb->instr); i++) {
                    opnd_t dst = instr_get_dst(bb->instr, i);
                    if (opnd_is_reg(dst) && opnd_get_reg(dst) == SEG_TLS) {
                        ASSERT_MESSAGE("We rely on the Linux Kernel's per-CPU "
                                       "storage. Instructions that modify gs "
                                       "are not supported.", false);
                    }
                }
            });
# endif
#endif

#if defined(INTERNAL) || defined(CLIENT_INTERFACE)
            if (bb->outf != INVALID_FILE)
                disassemble_with_bytes(dcontext, bb->instr_start, bb->outf);
#endif /* INTERNAL || CLIENT_INTERFACE */

            if (!instr_valid(bb->instr))
                break; /* before eflags analysis! */

            /* Eflags analysis:
             * We do this even if -unsafe_ignore_eflags_prefix b/c it doesn't cost that
             * much and we can use the analysis to detect any bb that reads a flag
             * prior to writing it.
             */
            if (bb->eflags != EFLAGS_WRITE_6 && bb->eflags != EFLAGS_READ_OF)
                bb->eflags = eflags_analysis(bb->instr, bb->eflags, &eflags_6);

            /* stop decoding at an invalid instr (tested above) or a cti
             *(== opcode valid) or a possible SEH frame push (if
             * -process_SEH_push). */
#ifdef WINDOWS
            if (DYNAMO_OPTION(process_SEH_push) &&
                instr_get_prefix_flag(bb->instr, PREFIX_SEG_FS)) {
                STATS_INC(num_bb_build_fs);
                break;
            }
#endif

#ifdef X64
            if (instr_has_rel_addr_reference(bb->instr)) {
                /* PR 215397: we need to split these out for re-relativization */
                break;
            }
#endif
        } while (!instr_opcode_valid(bb->instr) &&
                 total_instrs <= DYNAMO_OPTION(max_bb_instrs));

        if (bb->cur_pc == NULL) {
            /* invalid instr: reset bb->cur_pc, will end bb after updating stats */
            bb->cur_pc = bb->instr_start;
        }

        /* We need the translation when mangling calls and jecxz/loop*.
         * May as well set it for all cti's since there's
         * really no extra overhead in doing so.  Note that we go
         * through the above loop only once for cti's, so it's safe
         * to set the translation here.
         */
        if (instr_opcode_valid(bb->instr) && instr_is_cti(bb->instr))
            instr_set_translation(bb->instr, bb->instr_start);

#ifdef HOT_PATCHING_INTERFACE
        /* If this lookup succeeds then the current bb needs to be patched.
         * In hotp_inject(), address lookup will be done for each instruction 
         * pc in this bb and patching will be done if an exact match is found.
         *
         * Hot patching should be done only for app interp and recreating
         * pc, not for reproducing app code.  Hence we use mangle_ilist.
         * See case 5981.
         *
         * FIXME: this lookup can further be reduced by determining whether or
         *        not the current bb's module needs patching via check_new_page*
         */
        if (DYNAMO_OPTION(hot_patching) && bb->mangle_ilist &&
            !hotp_should_inject) {
            /* case 8780: we may hold the lock; FIXME: figure out if this can
             * be avoided - messy to hold hotp_vul_table lock like this for
             * unnecessary operations. */
            bool owns_hotp_lock = self_owns_write_lock(hotp_get_lock());
            if (hotp_does_region_need_patch(non_cti_start_pc, bb->cur_pc,
                                            owns_hotp_lock)) {
                BBPRINT(bb, 2, "hotpatch match in "PFX": "PFX"-"PFX"\n",
                        bb->start_pc, non_cti_start_pc, bb->cur_pc);
                hotp_should_inject = true;
                /* Don't elide if we are going to hot patch this bb because
                 * the patch point can be a direct cti; eliding would result
                 * in the patch not being applied.  See case 5901.
                 * FIXME: we could make this more efficient by only turning 
                 * off follow_direct if the instr is direct cti.
                 */
                bb->follow_direct = false;
                DOSTATS({
                    if TEST(FRAG_HAS_DIRECT_CTI, bb->flags)
                        STATS_INC(hotp_num_frag_direct_cti);
                });
            }
        }
#endif

        if (bb->full_decode) {
            if (TEST(FRAG_SELFMOD_SANDBOXED, bb->flags) &&
                instr_valid(bb->instr) && instr_writes_memory(bb->instr)) {
                /* to allow tailing non-writes, end prior to the write beyond the max */
                total_writes++;
                if (total_writes > DYNAMO_OPTION(selfmod_max_writes)) {
                    BBPRINT(bb, 3, "reached selfmod write limit %d, stopping\n",
                            DYNAMO_OPTION(selfmod_max_writes));
                    STATS_INC(num_max_selfmod_writes_enforced);
                    bb_stop_prior_to_instr(dcontext, bb, false/*not added to bb->ilist*/);
                    break;
                }
            }
        } else if (bb->instr_start != non_cti_start_pc) {
            /* instr now holds the cti, so create an instr_t for the non-cti */
            non_cti = instr_create(dcontext);
            IF_X64(ASSERT(CHECK_TRUNCATE_TYPE_uint(bb->instr_start - non_cti_start_pc)));
            instr_set_raw_bits(non_cti, non_cti_start_pc,
                               (uint)(bb->instr_start - non_cti_start_pc));
            /* add non-cti instructions to instruction list */
            instrlist_append(bb->ilist, non_cti);
        }

        DOSTATS({
            /* This routine is also called for recreating state, we only want
             * to count app code when we build new bbs, which is indicated by
             * the bb->app_interp parameter
             */
            if (bb->app_interp && !regenerated) {
                /* avoid double-counting for adaptive working set */
                /* FIXME - ubr ellision leads to double couting.  We also
                 * double count when we have multiple entry points into the
                 * same block of cti free instructinos. */
                STATS_ADD(app_code_seen, (bb->cur_pc - non_cti_start_pc));
                LOG(THREAD, LOG_INTERP, 5, "adding %d bytes to total app code seen\n",
                    bb->cur_pc - non_cti_start_pc);
            }
        });

        if (!instr_valid(bb->instr)) {
            bb_process_invalid_instr(dcontext, bb);
            break;
        }

#ifdef WINDOWS
        if (DYNAMO_OPTION(process_SEH_push) &&
            instr_get_prefix_flag(bb->instr, PREFIX_SEG_FS)) {
            DEBUG_DECLARE(ssize_t dbl_count = bb->cur_pc - bb->instr_start); 
            if (!bb_process_fs_ref(dcontext, bb)) {
                DOSTATS({
                    if (bb->app_interp) {
                        LOG(THREAD, LOG_INTERP, 3,
                            "stopping bb at fs-using instr @ "PFX"\n",
                            bb->instr_start);
                        STATS_INC(num_process_SEH_bb_early_terminate);
                        /* don't double count the fs instruction itself
                         * since we removed it from this bb */
                        if (!regenerated)
                            STATS_ADD(app_code_seen, -dbl_count);
                    }
                });
                break;
            }
        }
#else
#  ifndef LINUX_KERNEL
        if (instr_get_prefix_flag(bb->instr,
                                  (SEG_TLS == SEG_GS) ? PREFIX_SEG_GS : PREFIX_SEG_FS)
            /* __errno_location is interpreted when global, though it's hidden in TOT */
            IF_LINUX(&& !is_in_dynamo_dll(bb->instr_start))) {
            /* On linux we use a segment register and do not yet
             * support the application using the same register!
             */
            CLIENT_ASSERT(false, "no support yet for application using non-NPTL segment");
            ASSERT_BUG_NUM(205276, false);
        }
#  endif
#endif

        if (instr_is_ubr(bb->instr)) {
            if (bb_process_ubr(dcontext, bb))
                continue;
            else
                break;
        } else
            instrlist_append(bb->ilist, bb->instr);

#ifdef RETURN_AFTER_CALL
        if (bb->app_interp && dynamo_options.ret_after_call) {
            if (instr_is_call(bb->instr)) {
                /* add after call instruction to valid return targets */
                add_return_target(dcontext, bb->instr_start, bb->instr);
            }
        }
#endif /* RETURN_AFTER_CALL */

#ifdef LINUX_KERNEL
        if (instr_may_return_to_user(bb->instr)) {
            /* TODO(peter): Not sure if it is necessary to set
             * FRAG_MUST_END_TRACE. My intent is to ensure that we return to the
             * dispatcher when we encounter these instructions.
             */
            bb->flags |= FRAG_MUST_END_TRACE; 
            bb->exit_type = instr_branch_type(bb->instr);
            /* TODO(peter): Handle sysexit. */
            ASSERT(TESTANY(LINK_SYSRET | LINK_IRET, bb->exit_type));
            LOG(THREAD, LOG_INTERP, 2, "Block has %s @ pc %p\n",
                TEST(LINK_IRET, bb->exit_type) ?
                    "iret" : "sysret", bb->instr->bytes);
            bb->exit_target = (app_pc) fake_user_return_exit_target;
            break;
        }
#endif
        if (instr_is_call_direct(bb->instr)) {
            if (!bb_process_call_direct(dcontext, bb)) {
                if (bb->instr != NULL)
                    bb->exit_type |= instr_branch_type(bb->instr);
                break;
            }
        }
        else if (instr_is_mbr(bb->instr)) { /* including indirect calls */

            /* Manage the case where we don't need to perform 'normal'
             * indirect branch processing.
             */
            bool normal_indirect_processing = true;
            bool elide_and_continue_if_converted = true;

            if (instr_is_return(bb->instr)) {
                ibl_branch_type = IBL_RETURN;
                STATS_INC(num_returns);
            } else if (instr_is_call_indirect(bb->instr)) {
                STATS_INC(num_all_calls);
                STATS_INC(num_indirect_calls);

                if (DYNAMO_OPTION(coarse_split_calls) && DYNAMO_OPTION(coarse_units) && 
                    TEST(FRAG_COARSE_GRAIN, bb->flags)) {
                    if (instrlist_first(bb->ilist) != bb->instr) {
                        /* have call be in its own bb */
                        bb_stop_prior_to_instr(dcontext, bb, true/*appended already*/);
                        break; /* stop bb */
                    } else {
                        /* single-call fine-grained bb */
                        bb->flags &= ~FRAG_COARSE_GRAIN;
                        STATS_INC(coarse_prevent_cti);
                    }
                }

                /* If the indirect call can be converted into a direct one,
                 * bypass normal indirect call processing.
                 */
                if (DYNAMO_OPTION(indcall2direct)
                    && bb_process_convertible_indcall(dcontext, bb)) {
                    normal_indirect_processing = false;
                    elide_and_continue_if_converted = true;
                } else if (DYNAMO_OPTION(IAT_convert)
                           && bb_process_IAT_convertible_indcall(dcontext, bb, 
                                                                 &elide_and_continue_if_converted)) {
                    normal_indirect_processing = false;
                }
                else if (bb_process_indcall_syscall(dcontext, bb,
                                                    &elide_and_continue_if_converted)) {
                    normal_indirect_processing = false;
                }
                else
                    ibl_branch_type = IBL_INDCALL;
            } else {
                /* indirect jump */
                /* was prev instr a direct call? if so, this is a PLT-style ind call */
                instr_t *prev = instr_get_prev(bb->instr);
                if (prev != NULL && instr_opcode_valid(prev) && instr_is_call_direct(prev)) {
                    bb->exit_type |= INSTR_IND_JMP_PLT_EXIT;
                    /* just because we have a CALL to JMP* makes it
                       only a _likely_ PLT call, we still have to make
                       sure it goes through IAT - see case 4269
                    */
                    STATS_INC(num_indirect_jumps_likely_PLT);
                }

                elide_and_continue_if_converted = true;
                        
                if (DYNAMO_OPTION(IAT_convert) 
                    && bb_process_IAT_convertible_indjmp(dcontext, bb, 
                                                         &elide_and_continue_if_converted)) {
                    /* Clear the IND_JMP_PLT_EXIT flag since we've converted
                     * the PLT to a direct transition (and possibly elided).
                     * Xref case 7867 for why leaving this flag in the eliding
                     * case can cause later failures. */
                    bb->exit_type &= ~INSTR_IND_JMP_PLT_EXIT;
                    normal_indirect_processing = false;
                } else          /* FIXME: this can always be set */
                    ibl_branch_type = IBL_INDJMP;
                STATS_INC(num_indirect_jumps);
            }
#ifdef CUSTOM_TRACES_RET_REMOVAL
            if (instr_is_return(bb->instr))
                my_dcontext->num_rets++;
            else if (instr_is_call_indirect(bb->instr))
                my_dcontext->num_calls++;
#endif
            /* set exit type since this instruction will get mangled */
            if (normal_indirect_processing) {
                bb->exit_type |= instr_branch_type(bb->instr);
                bb->exit_target = get_ibl_routine(dcontext, IBL_LINKED, DEFAULT_IBL_BB(),
                                                  ibl_branch_type);
                break;
            } else {
                /* decide whether to stop bb here */
                if (!elide_and_continue_if_converted)
                    break;
                /* fall through for -max_bb_instrs check */
            }
        }
        else if (instr_is_cti(bb->instr) && !instr_is_call(bb->instr)) {
            total_branches++;
            if (total_branches >= BRANCH_LIMIT) {
                /* set type of 1st exit cti for cbr (bb->exit_type is for fall-through) */
                instr_exit_branch_set_type(bb->instr, instr_branch_type(bb->instr));
                break;
            }
        }
        else if (instr_is_syscall(bb->instr)) {
#ifdef LINUX_KERNEL
        	CLIENT_ASSERT(false, "System call made within in the kernel.");
#endif
            if (!bb_process_syscall(dcontext, bb))
                break;
        } /* end syscall */
        else if (instr_get_opcode(bb->instr) == OP_int) { /* non-syscall int */
            if (!bb_process_interrupt(dcontext, bb))
                break;
        }
#ifdef CHECK_RETURNS_SSE2
        else if (instr_is_sse_or_sse2(bb->instr)) {
            FATAL_USAGE_ERROR(CHECK_RETURNS_SSE2_XMM_USED, 2, 
                              get_application_name(), get_application_pid());
        }
#endif

        if (total_instrs > DYNAMO_OPTION(max_bb_instrs)) {
            /* this could be an enormous basic block, or it could
             * be some degenerate infinite-loop case like a call
             * to a function that calls exit() and then calls itself,
             * so just end it here, we'll pick up where we left off
             * if it's legit
             */
            BBPRINT(bb, 3, "reached -max_bb_instrs, stopping\n");
            STATS_INC(num_max_bb_instrs_enforced);
            break;
        }

    } /* end of while (true) */
    KSTOP(bb_decoding);

#ifdef DEBUG_MEMORY
    /* make sure anyone who destroyed also set to NULL */
    ASSERT(bb->instr == NULL ||
           (bb->instr->bytes != (byte *) HEAP_UNALLOCATED_PTR_UINT &&
            bb->instr->bytes != (byte *) HEAP_ALLOCATED_PTR_UINT &&
            bb->instr->bytes != (byte *) HEAP_PAD_PTR_UINT));
#endif

    check_new_page_contig(dcontext, bb, bb->cur_pc-1);
    bb->end_pc = bb->cur_pc;
    BBPRINT(bb, 3, "end_pc = "PFX"\n\n", bb->end_pc);

    /* We could put this in check_new_page_jmp where it already checks
     * for native_exec overlap, but selfmod ubrs don't even call that routine
     */
    if (DYNAMO_OPTION(native_exec) &&
        DYNAMO_OPTION(native_exec_callcall) &&        
        !vmvector_empty(native_exec_areas) &&
        bb->app_interp && bb->instr != NULL && 
        (instr_is_ubr(bb->instr) || instr_is_call_direct(bb->instr)) &&
        instrlist_first(bb->ilist) == instrlist_last(bb->ilist)) {
        /* Case 4564/3558: handle .NET COM method table where a call* targets
         * a call to a native_exec dll -- we need to put the gateway at the
         * call* to avoid retaddr mangling of the method table call.
         * As a side effect we can also handle call*, jmp.
         * We don't actually verify or care that it was specifically a call*,
         * whatever at_native_exec_gateway() requires to assure itself that we're
         * at a return-address-clobberable point.
         */
        app_pc tgt = opnd_get_pc(instr_get_target(bb->instr));
        if (vmvector_overlap(native_exec_areas, tgt, tgt+1) &&
            at_native_exec_gateway(dcontext, tgt _IF_DEBUG(true/*xfer tgt*/))) {
            /* replace this ilist w/ a native exec one */
            LOG(THREAD, LOG_INTERP, 2,
                "direct xfer @gateway @"PFX" to native_exec module "PFX"\n",
                bb->start_pc, tgt);
            bb->native_exec = true;
            /* add this ubr/call to the native_exec_list, both as an optimization
             * for future entrances and b/c .NET changes its method table call
             * from targeting a native_exec image to instead target DGC directly,
             * thwarting our gateway!
             * FIXME: if heap region de-allocated, we'll remove, but what if re-used
             * w/o going through syscalls?  Just written over w/ something else?
             * We'll keep it on native_exec_list...
             */
            ASSERT(bb->end_pc == bb->start_pc + DIRECT_XFER_LENGTH);
            vmvector_add(native_exec_areas, bb->start_pc, bb->end_pc, NULL);
            DODEBUG({ report_native_module(dcontext, tgt); });
            STATS_INC(num_native_module_entrances_callcall);
            return;
        }
    }

    STATS_TRACK_MAX(max_instrs_in_a_bb, total_instrs);

#ifdef LINUX
    if (bb->invalid_instr_hack) {
        /* turn off selfmod -- we assume bb will hit exception right away */
        if (TEST(FRAG_SELFMOD_SANDBOXED, bb->flags))
            bb->flags &= ~FRAG_SELFMOD_SANDBOXED;
        /* decode_fragment() can't handle invalid instrs, so store translations */
        bb->flags |= FRAG_HAS_TRANSLATION_INFO;
    }
#endif

    if (TEST(FRAG_SELFMOD_SANDBOXED, bb->flags) &&
        (TEST(FRAG_HAS_DIRECT_CTI, bb->flags) || !bb->full_decode)) {
        /* Sandbox requires that bb have no direct cti followings, and
         * had full decode from the start for -selfmod_max_writes!
         * check_thread_vm_area should have ensured this for us, except
         * there is a pathological case where a direct cti occurs, and
         * then we walk over a page boundary onto a selfmod page -- no
         * choice but to back out, which for now we do by rebuilding.
         * FIXME: find better way
         */
        /* FIXME: a better assert is needed because this can trigger if 
         * hot patching turns off follow_direct, the current bb was elided 
         * earlier and is marked as selfmod.  hotp_num_frag_direct_cti will 
         * track this for now.
         */
        ASSERT(bb->follow_direct == true); /* else, infinite loop possible */
        BBPRINT(bb, 2,
                "*** must rebuild bb to avoid following direct cti for selfmod ***\n");
        STATS_INC(num_bb_end_early);
        instrlist_clear_and_destroy(dcontext, bb->ilist);
        if (bb->vmlist != NULL) {
            vm_area_destroy_list(dcontext, bb->vmlist);
            bb->vmlist = NULL;
        }
        bb->flags = FRAG_SELFMOD_SANDBOXED; /* lose all other flags */
        bb->full_decode = true; /* full decode -- see comment at top of routine */
        bb->follow_direct = false; 
        /* overlap info will be reset by check_new_page_start */
        build_bb_ilist(dcontext, bb);
        return;
    }

#ifdef HOT_PATCHING_INTERFACE
    /* CAUTION: This can't be moved below client interface as the basic block
     *          can be changed by the client.  This will mess up hot patching.
     *          The same is true for mangling.
     */
    if (hotp_should_inject) {
        ASSERT(DYNAMO_OPTION(hot_patching));
        hotp_injected = hotp_inject(dcontext, bb->ilist);

        /* Fix for 5272.  Hot patch injection uses dr clean call api which 
         * accesses dcontext fields directly, so the injected bbs can't be
         * shared until that is changed or the clean call mechanism is replaced
         * with bb termination to execute hot patchces.
         * Case 9995 assumes that hotp fragments are fine-grained, which we
         * achieve today by being private; if we make shared we must explicitly
         * prevent from being coarse-grained.
         */
        if (hotp_injected) {
            bb->flags &= ~FRAG_SHARED;
            bb->flags |= FRAG_CANNOT_BE_TRACE;
        }
    }
#endif

#ifdef CLIENT_INTERFACE
    client_process_bb(dcontext, bb, &ibl_branch_type);
    if (bb->unmangled_ilist != NULL)
        *bb->unmangled_ilist = instrlist_clone(dcontext, bb->ilist);
#endif

    /* create a final instruction that will jump to the exit stub
     * corresponding to the fall-through of the conditional branch or
     * the target of the final indirect branch (the indirect branch itself
     * will get mangled into a non-cti)
     */
    if (bb->exit_target == NULL) { /* not set by ind branch, etc. */
        bb->exit_target = (cache_pc) bb->cur_pc; /* fall-through pc */
        if (bb->instr != NULL && instr_opcode_valid(bb->instr) &&
            instr_is_cbr(bb->instr) &&
            (int) (bb->exit_target - bb->start_pc) <= SHRT_MAX &&
            (int) (bb->exit_target - bb->start_pc) >= SHRT_MIN &&
            /* rule out jecxz, etc. */
            !instr_is_cti_loop(bb->instr))
            bb->flags |= FRAG_CBR_FALLTHROUGH_SHORT;
    }
    /* we share all basic blocks except selfmod (since want no-synch quick deletion)
     * or syscall-containing ones (to bound delay on threads exiting shared cache,
     * for cache management, both consistency and capacity)
     * bbs injected with hot patches are also not shared (see case 5272).
     */
    if (DYNAMO_OPTION(shared_bbs) && !TEST(FRAG_SELFMOD_SANDBOXED, bb->flags) &&
        !TEST(FRAG_TEMP_PRIVATE, bb->flags)
#ifdef HOT_PATCHING_INTERFACE
        && !hotp_injected
#endif
       ) {
#ifndef LINUX_KERNEL
        /* If the fragment doesn't have a syscalls or contains a
         * non-ignorable one -- meaning that the frag will exit the cache
         * to execute the syscall -- it can be shared.
         * We don't support ignorable syscalls in shared fragments, as they
         * don't set at_syscall and so are incompatible w/ -syscalls_synch_flush.
         */
        if (!TEST(FRAG_HAS_SYSCALL, bb->flags) ||
            TESTANY(LINK_NI_SYSCALL_ALL, bb->exit_type))
            bb->flags |= FRAG_SHARED;
#endif
#ifdef WINDOWS
        /* A fragment can be shared if it contains a syscall that will be
         * executed via the version of shared syscall that can be targetted by
         * shared frags.
         */
        else if (TEST(FRAG_HAS_SYSCALL, bb->flags) &&
                 DYNAMO_OPTION(shared_fragment_shared_syscalls) &&
                 bb->exit_target == shared_syscall_routine(dcontext))
            bb->flags |= FRAG_SHARED;
        else {
            ASSERT((TEST(FRAG_HAS_SYSCALL, bb->flags) &&
                    (DYNAMO_OPTION(ignore_syscalls) ||
                     (!DYNAMO_OPTION(shared_fragment_shared_syscalls) &&
                      bb->exit_target == shared_syscall_routine(dcontext)))) &&
                   "BB not shared for unknown reason");
        }
#endif
    }

    if (TEST(FRAG_COARSE_GRAIN, bb->flags) &&
        (!TEST(FRAG_SHARED, bb->flags) ||
         /* Ignorable syscalls on linux are mangled w/ intra-fragment jmps, which
          * decode_fragment() cannot handle -- and on win32 this overlaps w/
          * FRAG_MUST_END_TRACE and LINK_NI_SYSCALL
          */
         TEST(FRAG_HAS_SYSCALL, bb->flags) ||
         TEST(FRAG_CANNOT_BE_TRACE, bb->flags) ||
         TEST(FRAG_SELFMOD_SANDBOXED, bb->flags) ||
         /* PR 214142: coarse units does not support storing translations */
         TEST(FRAG_HAS_TRANSLATION_INFO, bb->flags) ||
         /* FRAG_HAS_DIRECT_CTI: we never elide (assert is below);
          * not-inlined call/jmp: we turn off FRAG_COARSE_GRAIN up above
          */
#ifdef WINDOWS
         TEST(LINK_CALLBACK_RETURN, bb->exit_type) ||
#endif
#ifndef LINUX_KERNEL
        TESTANY(LINK_NI_SYSCALL_ALL, bb->exit_type) ||
#endif
         TEST(FRAG_MUST_END_TRACE, bb->flags))) {
        /* Currently not supported in a coarse unit */
        STATS_INC(num_fine_in_coarse);
        DOSTATS({
            if (!TEST(FRAG_SHARED, bb->flags))
                STATS_INC(coarse_prevent_private); 
            else if (TEST(FRAG_HAS_SYSCALL, bb->flags))
                STATS_INC(coarse_prevent_syscall); 
            else if (TEST(FRAG_MUST_END_TRACE, bb->flags))
                STATS_INC(coarse_prevent_end_trace); 
            else if (TEST(FRAG_CANNOT_BE_TRACE, bb->flags))
                STATS_INC(coarse_prevent_no_trace); 
            else if (TEST(FRAG_SELFMOD_SANDBOXED, bb->flags))
                STATS_INC(coarse_prevent_selfmod); 
            else if (TEST(FRAG_HAS_TRANSLATION_INFO, bb->flags))
                STATS_INC(coarse_prevent_translation); 
            else if (IF_WINDOWS_ELSE_0(TEST(LINK_CALLBACK_RETURN, bb->exit_type)))
                STATS_INC(coarse_prevent_cbret); 
#ifndef LINUX_KERNEL
            else if (TESTANY(LINK_NI_SYSCALL_ALL, bb->exit_type))
                STATS_INC(coarse_prevent_syscall); 
#endif
            else
                ASSERT_NOT_REACHED();
        });
        bb->flags &= ~FRAG_COARSE_GRAIN;
    }
    ASSERT(!TEST(FRAG_COARSE_GRAIN, bb->flags) || !TEST(FRAG_HAS_DIRECT_CTI, bb->flags));

    /* now that we know whether shared, ensure we have the right ibl routine */
    if (!TEST(FRAG_SHARED, bb->flags) && TEST(LINK_INDIRECT, bb->exit_type)) {
        ASSERT(bb->exit_target == get_ibl_routine(dcontext, IBL_LINKED, DEFAULT_IBL_BB(),
                                                  ibl_branch_type));
        bb->exit_target = get_ibl_routine(dcontext, IBL_LINKED, IBL_BB_PRIVATE,
                                          ibl_branch_type);
    }

    if (bb->mangle_ilist &&
        (bb->instr == NULL || !instr_opcode_valid(bb->instr) ||
         !instr_is_ubr(bb->instr) || !instr_ok_to_mangle(bb->instr))) {
        instr_t *exit_instr = INSTR_CREATE_jmp(dcontext, opnd_create_pc(bb->exit_target));
        if (bb->record_translation) {
            app_pc translation = NULL;
            if (bb->instr == NULL) {
                /* we removed (or mangle will remove) the last instruction
                 * for special handling (invalid/syscall/int 2b) or there were
                 * no instructions added (i.e. check_stopping_point in which 
                 * case instr_start == cur_pc), use last instruction's start 
                 * address for the translation */
                translation = bb->instr_start;
            } else if (instr_is_cti(bb->instr)) {
                /* last instruction is a cti, consider the exit jmp part of 
                 * the mangling of the cti (since we might not know the target 
                 * if, for ex., its indirect) */
                translation = instr_get_translation(bb->instr);
            } else {
                /* target is the instr after the last instr in the list */
                translation = bb->cur_pc;
                ASSERT(bb->cur_pc == bb->exit_target);
            }
            ASSERT(translation != NULL);
            instr_set_translation(exit_instr, translation);
        }
        /* PR 214962: we need this jmp to be marked as "our mangling" so that
         * we won't relocate a thread there and re-do a ret pop or call push
         */
        instr_set_our_mangling(exit_instr, true);
        /* here we need to set exit_type */
        LOG(THREAD, LOG_EMIT, 3, "exit_branch_type=0x%x bb->exit_target="PFX"\n",
            bb->exit_type, bb->exit_target);
        instr_exit_branch_set_type(exit_instr, bb->exit_type);

        instrlist_append(bb->ilist, exit_instr);
    }

    /* set flags */
#ifdef DGC_DIAGNOSTICS
    /* no traces in dyngen code, that would mess up our exit tracking */
    if (TEST(FRAG_DYNGEN, bb->flags))
        bb->flags |= FRAG_CANNOT_BE_TRACE;
#endif
    if (!INTERNAL_OPTION(unsafe_ignore_eflags_prefix)
        IF_X64(|| !INTERNAL_OPTION(unsafe_ignore_eflags_trace))) {
        bb->flags |= instr_eflags_to_fragment_eflags(bb->eflags);
        if (TEST(FRAG_WRITES_EFLAGS_OF, bb->flags)) {
            LOG(THREAD, LOG_INTERP, 4, "fragment writes OF prior to reading it!\n");
            STATS_INC(bbs_eflags_writes_of);
        } else if (TEST(FRAG_WRITES_EFLAGS_6, bb->flags)) {
            ASSERT(TEST(FRAG_WRITES_EFLAGS_OF, bb->flags));
            LOG(THREAD, LOG_INTERP, 4,
                "fragment writes all 6 flags prior to reading any\n");
            STATS_INC(bbs_eflags_writes_6);
        } else {
            DOSTATS({
                if (bb->eflags == EFLAGS_READ_6) {
                    /* Reads a flag before writing any.  Won't get here if
                     * reads one flag and later writes OF, or writes OF and
                     * later reads one flag before writing that flag.
                     */
                    STATS_INC(bbs_eflags_reads);
                } else {
                    STATS_INC(bbs_eflags_writes_none);
                    if (TEST(LINK_INDIRECT, bb->exit_type))
                        STATS_INC(bbs_eflags_writes_none_ind);
                }
            });
        }
    }
#ifdef RETURN_STACK
    if (bb->exit_target == return_lookup_routine(dcontext))
        bb->flags |= FRAG_ENDS_WITH_RETURN;
#endif

    /* can only have proactive translation info if flag was set from the beginning */
    if (TEST(FRAG_HAS_TRANSLATION_INFO, bb->flags) &&
        (!bb->record_translation || !bb->full_decode))
        bb->flags &= ~FRAG_HAS_TRANSLATION_INFO;

    /* if for_cache, caller must clear once done emitting (emitting can deref
     * app memory so we wait until all done)
     */
    if (!bb_build_nested && !bb->for_cache && my_dcontext != NULL) {
        ASSERT(my_dcontext->bb_build_info == (void *) bb);
        my_dcontext->bb_build_info = NULL;
    }
    bb->instr = NULL;

    /* mangle the instruction list */

    if (!bb->mangle_ilist) {
        /* do not mangle!
         * caller must use full_decode to find invalid instrs and avoid
         * a discrepancy w/ for_cache case that aborts b/c of selfmod sandbox
         * returning false (in code below)
         */
        return;
    }

    if (!mangle_bb_ilist(dcontext, bb)) {
        /* have to rebuild bb w/ new bb flags set by mangle_bb_ilist */
        build_bb_ilist(dcontext, bb);
        return;
    }
}

/* Call when about to throw exception or other drastic action in the
 * middle of bb building, in order to free resources
 */
void
bb_build_abort(dcontext_t *dcontext, bool clean_vmarea)
{
    ASSERT(dcontext->bb_build_info != NULL); /* caller should check */
    if (dcontext->bb_build_info != NULL) {
        build_bb_t *bb = (build_bb_t *) dcontext->bb_build_info;
        /* free instr memory */
        if (bb->instr != NULL && bb->ilist != NULL &&
            instrlist_last(bb->ilist) != bb->instr)
            instr_destroy(dcontext, bb->instr); /* not added to bb->ilist yet */
        DODEBUG({ bb->instr = NULL; });
        if (bb->ilist != NULL) {
            instrlist_clear_and_destroy(dcontext, bb->ilist);
            DODEBUG({ bb->ilist = NULL; });
        }
        if (clean_vmarea) {
            /* Free the vmlist and any locks held (we could have been in
             * the middle of check_thread_vm_area and had a decode fault
             * during code origins checking!)
             */
            check_thread_vm_area_abort(dcontext, &bb->vmlist, bb->flags);
        } /* else we were presumably called from vmarea so caller does cleanup */
        /* Assumption: bb building lock is held iff bb->for_cache,
         * and on a nested app bb build where !bb->for_cache we do keep the
         * original bb info in dcontext (see build_bb_ilist()).
         */
        if (bb->has_bb_building_lock) {
            ASSERT_OWN_MUTEX(USE_BB_BUILDING_LOCK(), &bb_building_lock);
            SHARED_BB_MUTEX(unlock);
            KSTOP_REWIND(bb_building);
        } else
            ASSERT_DO_NOT_OWN_MUTEX(USE_BB_BUILDING_LOCK(), &bb_building_lock);
        dcontext->bb_build_info = NULL;
    }
}

/* returns false if need to rebuild bb: in that case this routine will
 * set the bb flags needed to ensure successful mangling 2nd time around
 */
static bool
mangle_bb_ilist(dcontext_t *dcontext, build_bb_t *bb)
{
    if (TEST(FRAG_SELFMOD_SANDBOXED, bb->flags)) {
        /* sandbox requires that bb have no direct cti followings!
         * check_thread_vm_area should have ensured this for us
         */
        ASSERT(!TEST(FRAG_HAS_DIRECT_CTI, bb->flags));
        LOG(THREAD, LOG_INTERP, 2,
            "fragment overlaps selfmod area, inserting sandboxing\n");
        /* only reason can't be trace is don't have mechanism set up
         * to store app code for each trace bb and update sandbox code
         * to point there
         */
        bb->flags |= FRAG_CANNOT_BE_TRACE;
        if (!insert_selfmod_sandbox(dcontext, bb->ilist, bb->flags, bb->start_pc,
                                    bb->cur_pc, bb->record_translation,
                                    bb->for_cache)) {
            /* have to rebuild bb using full decode -- it has invalid instrs
             * in middle, which we don't want to deal w/ for sandboxing!
             */
            ASSERT(!bb->full_decode); /* else, how did we get here??? */
            LOG(THREAD, LOG_INTERP, 2,
                "*** must rebuild bb to avoid invalid instr in middle ***\n");
            STATS_INC(num_bb_end_early);
            instrlist_clear_and_destroy(dcontext, bb->ilist);
            if (bb->vmlist != NULL) {
                vm_area_destroy_list(dcontext, bb->vmlist);
                bb->vmlist = NULL;
            }
            bb->flags = FRAG_SELFMOD_SANDBOXED; /* lose all other flags */
            bb->full_decode = true; /* full decode this time! */
            bb->follow_direct = false; 
            /* overlap info will be reset by check_new_page_start */
            return false;
        }
        STATS_INC(num_sandboxed_fragments);
    }

    DOLOG(4, LOG_INTERP, {
        LOG(THREAD, LOG_INTERP, 4, "bb ilist before mangling:\n");
        instrlist_disassemble(dcontext, bb->start_pc, bb->ilist, THREAD);
    });
    mangle(dcontext, bb->ilist, bb->flags, true, bb->record_translation);
    DOLOG(4, LOG_INTERP, {
        LOG(THREAD, LOG_INTERP, 4, "bb ilist after mangling:\n");
        instrlist_disassemble(dcontext, bb->start_pc, bb->ilist, THREAD);
    });
    return true;
}

/* Interprets the application's instructions until the end of a basic
 * block is found, following all the rules that build_bb_ilist follows
 * with regard to terminating the block.  Does no mangling or anything of
 * the app code, though -- this routine is intended only for building the
 * original code!
 * Caller is responsible for freeing the list and its instrs!
 * If outf != INVALID_FILE, does full disassembly with comments to outf.
 */
instrlist_t *
build_app_bb_ilist(dcontext_t *dcontext, byte *start_pc, file_t outf)
{
    build_bb_t bb;
    init_build_bb(&bb, start_pc, false/*not interp*/, false/*not for cache*/,
                  false/*do not mangle*/, false/*no translation*/, outf,
                  0/*no pre flags*/, NULL/*no overlap*/);
    build_bb_ilist(dcontext, &bb);
    return bb.ilist;
}

#ifdef CLIENT_INTERFACE
/* Client routine to decode instructions at an arbitrary app address,
 * following all the rules that DynamoRIO follows internally for
 * terminating basic blocks.  Note that DynamoRIO does not validate
 * that start_pc is actually the first instruction of a basic block.
 * \note Caller is reponsible for freeing the list and its instrs!
 */
instrlist_t *
decode_as_bb(void *drcontext, byte *start_pc)
{
    build_bb_t bb;

    /* Case 10009: When we hook ntdll functions, we hide the jump to
     * the interception buffer from the client BB callback.  If the
     * client asks to decode that address here, we need to decode the
     * instructions in the interception buffer instead so that we
     * again hide our hooking.
     * We will have the jmp from the buffer back to after the hooked
     * app code visible to the client (just like it is for the
     * real bb built there, so at least we're consistent).
     */
# ifdef WINDOWS
    byte *real_pc;
    if (is_intercepted_app_pc((app_pc)start_pc, &real_pc))
        start_pc = real_pc;
# endif

    init_build_bb(&bb, start_pc, false /*not interp*/, 
                  false /*not for cache*/, false /*do not mangle*/,
                  true /* translation; xref case 10070 where this
                        * currently turns on full decode; today we
                        * provide no way to turn that off, as IR
                        * expansion routines are not exported (PR 200409). */,
                  INVALID_FILE, 0 /*no pre flags*/, NULL /*no overlap*/);
    build_bb_ilist((dcontext_t *)drcontext, &bb);
    return bb.ilist;
}

/* Client routine to decode a trace.  We return the instructions in
 * the original app code, i.e., no client modifications.
 */
instrlist_t *
decode_trace(void *drcontext, void *tag)
{
    dcontext_t *dcontext = (dcontext_t *)drcontext;
    fragment_t *frag = fragment_lookup(dcontext, tag);
    /* We don't support asking about other threads, for synch purposes
     * (see recreate_fragment_ilist() synch notes)
     */
    if (get_thread_private_dcontext() != dcontext)
        return NULL;

    if (frag != NULL && TEST(FRAG_IS_TRACE, frag->flags)) {
        instrlist_t *ilist;
        bool alloc_res;
        /* Support being called from bb/trace hook (couldbelinking) or
         * from cache clean call (nolinking).  We disallow asking about
         * another thread's private traces.
         */
        if (!is_couldbelinking(dcontext))
            mutex_lock(&thread_initexit_lock);
        ilist = recreate_fragment_ilist(dcontext, NULL, &frag, &alloc_res,
                                        false/*no mangling*/
                                        _IF_CLIENT(false/*do not re-call client*/));
        ASSERT(!alloc_res);
        if (!is_couldbelinking(dcontext))
            mutex_unlock(&thread_initexit_lock);
        
        return ilist;
    }

    return NULL;
}
#endif

app_pc
find_app_bb_end(dcontext_t *dcontext, byte *start_pc, uint flags)
{
    build_bb_t bb;
    init_build_bb(&bb, start_pc, false/*not interp*/, false/*not for cache*/,
                  false/*do not mangle*/, false/*no translation*/, INVALID_FILE,
                  flags, NULL/*no overlap*/);
    build_bb_ilist(dcontext, &bb);
    instrlist_clear_and_destroy(dcontext, bb.ilist);
    return bb.end_pc;
}

bool
app_bb_overlaps(dcontext_t *dcontext, byte *start_pc, uint flags,
                byte *region_start, byte *region_end, overlap_info_t *info_res)
{
    build_bb_t bb;
    overlap_info_t info;
    info.region_start = region_start;
    info.region_end = region_end;
    init_build_bb(&bb, start_pc, false/*not interp*/, false/*not for cache*/,
                  false/*do not mangle*/, false/*no translation*/, INVALID_FILE,
                  flags, &info);
    build_bb_ilist(dcontext, &bb);
    instrlist_clear_and_destroy(dcontext, bb.ilist);
    info.bb_end = bb.end_pc;
    if (info_res != NULL)
        *info_res = info;
    return info.overlap;
}

/* pass in name if you already have it, else this routine looks it up from modbase */
bool
on_native_exec_list(app_pc modbase, const char *name)
{
    const char *modname;
    bool modlock = false;
    bool onlist = false;

    if (!DYNAMO_OPTION(native_exec))
        return false;

    if (name == NULL) {
        /* acquire name, safely */
        if (modbase == NULL)
            return false;
        os_get_module_info_lock();
        modlock = true;
        os_get_module_name(modbase, &modname);
        if (modname == NULL) {
            os_get_module_info_unlock();
            return false;
        }
    } else
        modname = name;

    if (!IS_STRING_OPTION_EMPTY(native_exec_default_list)) {
        string_option_read_lock();
        LOG(THREAD_GET, LOG_INTERP|LOG_VMAREAS, 4,
            "on_native_exec_list: module %s vs default list %s\n",
            modname==NULL?"null":modname, dynamo_options.native_exec_default_list);
        onlist = check_filter(dynamo_options.native_exec_default_list, modname);
        string_option_read_unlock();
    }
    if (!onlist &&
        !IS_STRING_OPTION_EMPTY(native_exec_list)) {
        string_option_read_lock();
        LOG(THREAD_GET, LOG_INTERP|LOG_VMAREAS, 4,
            "on_native_exec_list: module %s vs append list %s\n",
            modname==NULL?"null":modname, dynamo_options.native_exec_list);
        onlist = check_filter(dynamo_options.native_exec_list, modname);
        string_option_read_unlock();
    }
    if (modlock)
        os_get_module_info_unlock();
    return onlist;
}

#ifdef DEBUG
static void
report_native_module(dcontext_t *dcontext, app_pc modpc)
{
    char name[MAX_MODNAME_INTERNAL];
    const char *modname = name;
    if (os_get_module_name_buf(modpc, name, BUFFER_SIZE_ELEMENTS(name)) == 0) {
        /* for native_exec_callcall we do end up putting DGC on native_exec_list */
        ASSERT(DYNAMO_OPTION(native_exec_callcall));
        modname = "<DGC>";
    }
    LOG(THREAD, LOG_INTERP|LOG_VMAREAS, 2,
        "module %s is on native list, executing natively\n", modname);
    STATS_INC(num_native_module_entrances);
    SYSLOG_INTERNAL_WARNING_ONCE("module %s set up for native execution", modname);
}
#endif

/* WARNING: breaks all kinds of rules, like ret addr transparency and
 * assuming app stack and not doing calls out of the cache and not having
 * control during dll loads, etc...
 */
static void
build_native_exec_bb(dcontext_t *dcontext, build_bb_t *bb)
{
    instr_t *in;
#ifdef X64
    bool reachable;
#endif
    DEBUG_DECLARE(bool ok;)
    /* if we ever protect from simultaneous thread attacks then this will
     * be a hole -- for now should work, all protected while native until
     * another thread goes into DR
     */
    /* Create a bb that changes the return address on the app stack such that we
     * will take control when coming back, and then goes native.  
     * N.B.: we ASSUME we reached this moduled via a call --
     * build_basic_block_fragment needs to make sure, since we can't verify here
     * w/o trying to decode backward from retaddr, and if we're wrong we'll
     * clobber the stack and never regain control!
     * We also assume this bb is never reached later through a non-call.
     */
    ASSERT(bb->initialized);
    ASSERT(bb->app_interp);
    ASSERT(!bb->record_translation);
    ASSERT(bb->start_pc != NULL);
    /* vmlist must start out empty (or N/A) */
    ASSERT(bb->vmlist == NULL);
    if (TEST(FRAG_HAS_TRANSLATION_INFO, bb->flags))
        bb->flags &= ~FRAG_HAS_TRANSLATION_INFO;
    bb->native_exec = true;

    BBPRINT(bb, IF_DGCDIAG_ELSE(1, 2), "build_native_exec_bb @"PFX"\n", bb->start_pc);
    DOLOG(2, LOG_INTERP, {
        dump_mcontext(get_mcontext(dcontext), THREAD, DUMP_NOT_XML); });
    check_new_page_start(dcontext, bb);
    /* create instrlist after check_new_page_start to avoid memory leak
     * on unreadable memory
     * WARNING: do not add any app instructions to this ilist!
     * If you do you must enable selfmod below.
     */
    bb->ilist = instrlist_create(dcontext);
    /* FIXME PR 303413: we won't properly translate a fault in our app
     * stack references here.  We mark as our own mangling so we'll at
     * least return failure from our translate routine.
     */
    instrlist_set_our_mangling(bb->ilist, true);
    /* To regain control we put our interception routine as the retaddr,
     * assuming of course no transparency problems like longjmp or retaddr examination.
     * We need to know where to go when we return -- but this can be stdcall,
     * where it's tough to just push our retaddr after real one as earlier args will be
     * "cleaned up" and beyond TOS and we don't know how many args there were!
     * We use two special fields to store the original return address as well as its
     * stack location.  We assume that we do not re-takeover on exceptions or
     * APCs (callbacks will be ok) -- if we ever decide to we'll have to either
     * use the dcontext stack just like for callbacks or stack
     * native_exec_ret{val,loc} in some other manner.
     */
    append_shared_get_dcontext(dcontext, bb->ilist, true/*save xdi*/);
    instrlist_append(bb->ilist, instr_create_save_to_dc_via_reg
                     (dcontext, REG_NULL/*default*/, REG_XAX, XAX_OFFSET));
    instrlist_append(bb->ilist, INSTR_CREATE_mov_ld(dcontext, opnd_create_reg(REG_XAX),
                                                    OPND_CREATE_MEMPTR(REG_XSP, 0)));
    instrlist_append(bb->ilist, instr_create_save_to_dc_via_reg
                     (dcontext, REG_NULL/*default*/, REG_XAX,
                      NATIVE_EXEC_RETVAL_OFFSET));
    /* we don't count on mcontext being preserved (native syscalls will clobber it),
     * and when we re-takeover we need the new app state anyway, so we have to use
     * a special field to store where we clobbered the app retaddr in order to restore
     * it on a detach
     */
    instrlist_append(bb->ilist, instr_create_save_to_dc_via_reg
                     (dcontext, REG_NULL/*default*/, REG_XSP,
                      NATIVE_EXEC_RETLOC_OFFSET));
#ifdef X64
    /* must go through a register */
    instrlist_append(bb->ilist, INSTR_CREATE_mov_imm
                     (dcontext, opnd_create_reg(REG_XAX),
                      OPND_CREATE_INTPTR((ptr_int_t)back_from_native)));
    instrlist_append(bb->ilist, INSTR_CREATE_mov_st
                     (dcontext, OPND_CREATE_MEMPTR(REG_XSP, 0),
                      opnd_create_reg(REG_XAX)));
    reachable = rel32_reachable_from_heap(bb->start_pc);
    if (!reachable) {
        /* best to store the target at the end of the bb, to keep it readonly,
         * but that requires a post-pass to patch its value: since native_exec
         * is already hacky we just go through TLS and ignore multi-thread selfmod.
         */
        instrlist_append(bb->ilist, INSTR_CREATE_mov_imm
                         (dcontext, opnd_create_reg(REG_XAX),
                          OPND_CREATE_INTPTR((ptr_int_t)bb->start_pc)));
        instrlist_append(bb->ilist, INSTR_CREATE_mov_st
                         (dcontext, opnd_create_tls_slot(os_tls_offset
                                                         (MANGLE_XCX_SPILL_SLOT)),
                          opnd_create_reg(REG_XAX)));
    }
#else
    instrlist_append(bb->ilist, INSTR_CREATE_mov_st
                     (dcontext, OPND_CREATE_MEM32(REG_XSP, 0),
                      OPND_CREATE_INTPTR((ptr_int_t)back_from_native)));
#endif
    instrlist_append(bb->ilist, instr_create_restore_from_dc_via_reg
                     (dcontext, REG_NULL/*default*/, REG_XAX, XAX_OFFSET));
    append_shared_restore_dcontext_reg(dcontext, bb->ilist);
    /* need some cleanup prior to native: turn off asynch, clobber trace, etc. */
    /* FIXME: mark call as do-not-mangle */
    dr_insert_clean_call(dcontext, bb->ilist, NULL, (void *) entering_native,
                         false/*!fp*/, 0);
    /* this is the jump to native code */
#ifdef X64
    if (reachable) {
        instrlist_append(bb->ilist,
                         INSTR_CREATE_jmp(dcontext, opnd_create_pc(bb->start_pc)));
    } else {
        instrlist_append(bb->ilist, INSTR_CREATE_jmp_ind
                         (dcontext, opnd_create_tls_slot(os_tls_offset
                                                         (MANGLE_XCX_SPILL_SLOT))));
    }
#else
    instrlist_append(bb->ilist, INSTR_CREATE_jmp(dcontext, opnd_create_pc(bb->start_pc)));
#endif

    /* mark all as do-not-mangle, so selfmod, etc. will leave alone (in absence
     * of selfmod only really needed for the jmp to native code)
     */
    for (in = instrlist_first(bb->ilist); in != NULL; in = instr_get_next(in))
        instr_set_ok_to_mangle(in, false);

    /* this is a jump for a dummy exit cti */
    instrlist_append(bb->ilist, INSTR_CREATE_jmp(dcontext, opnd_create_pc(bb->start_pc)));

    if (DYNAMO_OPTION(shared_bbs))
        bb->flags |= FRAG_SHARED;

    /* Can't be coarse-grain since has non-exit cti */
    bb->flags &= ~FRAG_COARSE_GRAIN;
    STATS_INC(coarse_prevent_native_exec); 

    /* trace barrier */
    bb->flags |= FRAG_MUST_END_TRACE;

    /* We support mangling here, though currently we don't need it as we don't
     * include any app code (although we mark this bb as belonging to the start
     * pc, so we'll get flushed if this region does), and even if target is
     * selfmod we're running it natively no matter how it modifies itself.  We
     * only care that transition to target is via a call or call* so we can
     * clobber the retaddr and regain control, and that no retaddr mangling
     * happens while native before coming back out.  While the former does not
     * depend on the target at all, unfortunately we cannot verify the latter.
     */
    if (TEST(FRAG_SELFMOD_SANDBOXED, bb->flags))
        bb->flags &= ~FRAG_SELFMOD_SANDBOXED;
    DEBUG_DECLARE(ok = ) mangle_bb_ilist(dcontext, bb);
    ASSERT(ok);
}

static bool
at_native_exec_gateway(dcontext_t *dcontext, app_pc start
                       _IF_DEBUG(bool xfer_target))
{
    /* ASSUMPTION: transfer to another module will always be by indirect call
     * or non-inlined direct call from a fragment that will not be flushed.
     * For now we will only go native if last_exit was
     * a call, a true call*, or a PLT-style call,jmp* (and we detect the latter only
     * if the call is inlined, so if the jmp* table is in a DGC-marked region
     * or if -no_inline_calls we will miss these: FIXME).
     * FIXME: what if have PLT-style but no GOT indirection: call,jmp ?!?
     *
     * We try to identify funky call* constructions (like
     * call*,...,jmp* in case 4269) by examining TOS to see whether it's a
     * retaddr -- we do this if last_exit is a jmp* or is unknown (for the
     * target_delete ibl path).
     *
     * FIXME: we will fail to identify a delay-loaded indirect xfer!
     * Need to know dynamic link patchup code to look for.
     *
     * FIXME: we will fail to take over w/ non-call entrances to a dll, like
     * NtContinue or direct jmp from DGC.
     * we could try to take the top-of-stack value and see if it's a retaddr by
     * decoding the prev instr to see if it's a call.  decode backwards may have
     * issues, and if really want everything will have to do this on every bb,
     * not just if lastexit is ind xfer.
     *
     * We count up easy-to-identify cases we've missed in the DOSTATS below.
     */ 
    bool native_exec_bb = false;
    if (DYNAMO_OPTION(native_exec) &&
        !vmvector_empty(native_exec_areas)) {
        /* do we KNOW that we came from an indirect call? */
        if (TESTANY(LINK_CALL|LINK_IND_JMP_PLT, dcontext->last_exit->flags) &&
            /* only check direct calls if native_exec_dircalls is on */
            (DYNAMO_OPTION(native_exec_dircalls) ||
             LINKSTUB_INDIRECT(dcontext->last_exit->flags))) {
            STATS_INC(num_native_entrance_checks);
            /* we do the overlap check last since it's more costly */
            if (vmvector_overlap(native_exec_areas, start, start+1)) {
                native_exec_bb = true;
                DOSTATS({
                    if (TEST(LINK_CALL, dcontext->last_exit->flags)) {
                        if (LINKSTUB_INDIRECT(dcontext->last_exit->flags))
                            STATS_INC(num_native_module_entrances_indcall);
                        else
                            STATS_INC(num_native_module_entrances_call);
                    } else
                        STATS_INC(num_native_module_entrances_plt);
                    
                });
            }
        } 
        /* can we GUESS that we came from an indirect call? */
        else if (DYNAMO_OPTION(native_exec_guess_calls) &&
                 (/* FIXME: require jmp* be in separate module? */
                  (LINKSTUB_INDIRECT(dcontext->last_exit->flags) &&
                   TEST(LINK_JMP, dcontext->last_exit->flags)) ||
                  LINKSTUB_FAKE(dcontext->last_exit))) {
            /* if unknown last exit, or last exit was jmp*, examine TOS and guess
             * whether it's a retaddr
             */
            app_pc *tos = (app_pc *) get_mcontext(dcontext)->xsp;
            STATS_INC(num_native_entrance_TOS_checks);
            /* vector check cheaper than is_readable syscall, etc. so do it before them,
             * but after last_exit checks above since overlap is more costly
             */
            if (vmvector_overlap(native_exec_areas, start, start+1) &&
                is_readable_without_exception((app_pc)tos, 4)) {
                enum { MAX_CALL_CONSIDER = 6 /* ignore prefixes */ };
                app_pc retaddr = *tos;
                LOG(THREAD, LOG_INTERP|LOG_VMAREAS, 2,
                    "at native_exec target: checking TOS "PFX" => "PFX" for retaddr\n",
                    tos, retaddr);
#ifdef RETURN_AFTER_CALL
                if (DYNAMO_OPTION(ret_after_call)) {
                    native_exec_bb = is_observed_call_site(dcontext, retaddr);
                    LOG(THREAD, LOG_INTERP|LOG_VMAREAS, 2,
                        "native_exec: *TOS is %sa call site in ret-after-call table\n",
                        native_exec_bb ? "" : "NOT ");
                } else {
#endif
                    /* try to decode backward -- make sure readable for decoding */
                    if (is_readable_without_exception(retaddr - MAX_CALL_CONSIDER,
                                                      MAX_CALL_CONSIDER +
                                                      MAX_INSTR_LENGTH)) {
                        /* ind calls have variable length and form so we decode
                         * each byte rather than searching for ff and guessing length
                         */
                        app_pc pc, next_pc;
                        instr_t instr;
                        instr_init(dcontext, &instr);
                        for (pc = retaddr - MAX_CALL_CONSIDER; pc < retaddr; pc++) {
                            LOG(THREAD, LOG_INTERP|LOG_VMAREAS, 3,
                                "native_exec: decoding @"PFX" looking for call\n", pc);
                            instr_reset(dcontext, &instr);
                            next_pc = decode_cti(dcontext, pc, &instr);
                            STATS_INC(num_native_entrance_TOS_decodes);
                            if (next_pc == retaddr && instr_is_call(&instr)) {
                                native_exec_bb = true;
                                LOG(THREAD, LOG_INTERP|LOG_VMAREAS, 2,
                                    "native_exec: found call @ pre-*TOS "PFX"\n", pc);
                                break;
                            }
                        }
                        instr_free(dcontext, &instr);
                    }
#ifdef RETURN_AFTER_CALL
                }
#endif
                DOSTATS({
                    if (native_exec_bb) {
                        if (LINKSTUB_FAKE(dcontext->last_exit))
                            STATS_INC(num_native_module_entrances_TOS_unknown);
                        else
                            STATS_INC(num_native_module_entrances_TOS_jmp);
                    }
                });
            }
        }
        DOSTATS({
            /* did we reach a native dll w/o going through an ind call caught above? */
            if (!xfer_target /* else we'll re-check at the target itself */ &&
                !native_exec_bb && vmvector_overlap(native_exec_areas, start, start+1)) {
                LOG(THREAD, LOG_INTERP|LOG_VMAREAS, 2,
                    "WARNING: pc "PFX" is on native list but reached bypassing gateway!\n",
                    start);
                STATS_INC(num_native_entrance_miss);
                /* do-once since once get into dll past gateway may xfer
                 * through a bunch of lastexit-null or indjmp to same dll
                 */
                ASSERT_CURIOSITY_ONCE(false && "inside native_exec dll");
            }
        });
    }

    return native_exec_bb;
}

/* Use when calling build_bb_ilist with for_cache = true.
 * Must hold bb_building_lock.
 */
static inline void
init_interp_build_bb(dcontext_t *dcontext, build_bb_t *bb, app_pc start,
                     uint initial_flags
                     _IF_CLIENT(bool for_trace)
                     _IF_CLIENT(instrlist_t **unmangled_ilist))
{
    ASSERT_OWN_MUTEX(USE_BB_BUILDING_LOCK() && !TEST(FRAG_TEMP_PRIVATE, initial_flags),
                     &bb_building_lock);
    /* We need to set up for abort prior to native exec and other checks
     * that can crash */
    ASSERT(dcontext->bb_build_info == NULL);
    /* This won't make us be nested b/c for bb.for_cache caller is supposed
     * to set this up */
    dcontext->bb_build_info = (void *) bb;

    init_build_bb(bb, start, true/*real interp*/, true/*for cache*/, true/*mangle*/, 
                  false /* translation: set below for clients */,
                  INVALID_FILE, initial_flags |
                  (INTERNAL_OPTION(store_translations) ?
                   FRAG_HAS_TRANSLATION_INFO : 0), NULL/*no overlap*/);
    if (!TEST(FRAG_TEMP_PRIVATE, initial_flags))
        bb->has_bb_building_lock = true;
#ifdef CLIENT_INTERFACE
    /* We avoid races where there is no hook when we start building a
     * bb (and hence we don't record translation or do full decode) yet
     * a hook when we're ready to call one by storing whether there is a
     * hook at translation/decode decision time: now.
     */
    /* PR 299808: even if no bb hook, for a trace hook we need to
     * record translation and do full decode.  It's racy to check
     * dr_trace_hook_exists() here so we rely on trace building having
     * set unmangled_ilist.
     */
    if (dr_bb_hook_exists() || unmangled_ilist != NULL) {
        bb->pass_to_client = true;
        /* case 10009/214444: For client interface builds, store the translation.
         * by default.  This ensures clients can get the correct app address
         * of any instruction.  We also rely on this for allowing the client
         * to return DR_EMIT_STORE_TRANSLATIONS and setting the
         * FRAG_HAS_TRANSLATION_INFO flag after decoding the app code.
         *
         * FIXME: xref case 10070/214505.  Currently this means that all
         * instructions are fully decoded for client interface builds.
         */
        bb->record_translation = true;
        /* PR 200409: If a bb hook exists, we always do a full decode.
         * Note that we currently do this anyway to get
         * translation fields, but once we fix case 10070 it
         * won't be that way.
         * We do not let the client turn this off (the runtime
         * option is not dynamic, and off by default anyway), as we
         * do not export level-handling instr_t routines like *_expand
         * for walking instrlists and instr_decode().
         */
        bb->full_decode = true;
        /* PR 299808: we give client chance to re-add instrumentation */
        bb->for_trace = for_trace;
    }
    /* we need to clone the ilist pre-mangling */
    bb->unmangled_ilist = unmangled_ilist;
#endif
}

static inline void
exit_interp_build_bb(dcontext_t *dcontext, build_bb_t *bb)
{
    ASSERT(dcontext->bb_build_info == (void *) bb);
    /* Caller's responsibility to clean up since bb.for_cache */
    dcontext->bb_build_info = NULL;

    /* free the instrlist_t elements */
    instrlist_clear_and_destroy(dcontext, bb->ilist);
}

/* Interprets the application's instructions until the end of a basic
 * block is found, and then creates a fragment for the basic block.
 * DOES NOT look in the hashtable to see if such a fragment already exists!
 */
fragment_t *
build_basic_block_fragment(dcontext_t *dcontext, app_pc start, uint initial_flags,
                           bool link, bool visible _IF_CLIENT(bool for_trace)
                           _IF_CLIENT(instrlist_t **unmangled_ilist))
{
    fragment_t *f;
    build_bb_t bb;
    where_am_i_t wherewasi = dcontext->whereami;
#ifdef WINDOWS
    bool image_entry;
#endif
    KSTART(bb_building);
    dcontext->whereami = WHERE_INTERP;

    /* Neither thin_client nor hotp_only should be building any bbs. */
    ASSERT(!RUNNING_WITHOUT_CODE_CACHE());

#ifdef WINDOWS
    /* ASSUMPTION: image entry is reached via indirect transfer and
     * so will be the start of a bb
     * FIXME: ensure compiler inlines this so we don't make the call
     * if we've already reached the entry point
     */
    image_entry = check_for_image_entry(start);
#endif

    init_interp_build_bb(dcontext, &bb, start, initial_flags
                         _IF_CLIENT(for_trace) _IF_CLIENT(unmangled_ilist));
    if (at_native_exec_gateway(dcontext, start _IF_DEBUG(false/*not xfer tgt*/))) {
        DODEBUG({ report_native_module(dcontext, bb.start_pc); });
#ifdef CLIENT_INTERFACE
        /* PR 232617 - build_native_exec_bb doesn't support setting translation
         * info, but it also doesn't pass the built bb to the client (it
         * contains no app code) so we don't need it. */
        bb.record_translation = false;
#endif
        build_native_exec_bb(dcontext, &bb);
    } else {
        build_bb_ilist(dcontext, &bb);
        if (bb.native_exec) {
            /* change bb to be a native_exec gateway */
            LOG(THREAD, LOG_INTERP, 2, "replacing built bb with native_exec bb\n");
            instrlist_clear_and_destroy(dcontext, bb.ilist);
            vm_area_destroy_list(dcontext, bb.vmlist);
            dcontext->bb_build_info = NULL;
            init_interp_build_bb(dcontext, &bb, start, initial_flags
                                 _IF_CLIENT(for_trace) _IF_CLIENT(unmangled_ilist));
#ifdef CLIENT_INTERFACE
            /* PR 232617 - build_native_exec_bb doesn't support setting
             * translation info, but it also doesn't pass the built bb to the
             * client (it contains no app code) so we don't need it. */
            bb.record_translation = false;
#endif
            build_native_exec_bb(dcontext, &bb);
        }
    }
#ifdef WINDOWS
    /* case 9652: we do not want to persist the image entry point, so we keep
     * it fine-grained
     */
    if (image_entry)
        bb.flags &= ~FRAG_COARSE_GRAIN;
#endif

    /* emit fragment into fcache */
    KSTART(bb_emit);
    f = emit_fragment_ex(dcontext, start, bb.ilist, bb.flags, bb.vmlist, link, visible);
    KSTOP(bb_emit);

#ifdef CUSTOM_TRACES_RET_REMOVAL
    f->num_calls = dcontext->num_calls;
    f->num_rets = dcontext->num_rets;
#endif

#ifdef DGC_DIAGNOSTICS
    if ((f->flags & FRAG_DYNGEN)) {
        LOG(THREAD, LOG_INTERP, 1, "new bb is DGC:\n");
        DOLOG(1, LOG_INTERP, { disassemble_app_bb(dcontext, start, THREAD); });
        DOLOG(3, LOG_INTERP, { disassemble_fragment(dcontext, f, false); });
    }
#endif
    DOLOG(2, LOG_INTERP, { disassemble_fragment(dcontext, f, stats->loglevel <= 3); });
    DOLOG(4, LOG_INTERP, {
        if (TEST(FRAG_SELFMOD_SANDBOXED, f->flags)) {
            LOG(THREAD, LOG_INTERP, 4,
                "\nXXXX sandboxed fragment!  original code:\n");
            disassemble_app_bb(dcontext, f->tag, THREAD);
            LOG(THREAD, LOG_INTERP, 4, "code cache code:\n");
            disassemble_fragment(dcontext, f, false);
        }
    });
#ifdef INTERNAL
    if (INTERNAL_OPTION(bbdump_tags)) {
        disassemble_fragment_header(dcontext, f, bbdump_file);
    }
#endif

#ifdef INTERNAL
    DODEBUG({
        if (INTERNAL_OPTION(stress_recreate_pc)) {
            /* verify recreation */
            stress_test_recreate(dcontext, f, bb.ilist);
        }
    });
#endif

    exit_interp_build_bb(dcontext, &bb);

    dcontext->whereami = wherewasi;
    KSTOP(bb_building);
    return f;
}

/* Builds an instrlist_t as though building a bb from pc.
 * Use recreate_fragment_ilist() for building an instrlist_t for a fragment.
 * If check_vm_area is false, Does NOT call check_thread_vm_area()!
 *   Make sure you know it will terminate at the right spot.  It does
 *   check selfmod and native_exec for elision, but otherwise will
 *   follow ubrs to the limit.  Currently used for
 *   record_translation_info() (case 3559).
 */
instrlist_t *
recreate_bb_ilist(dcontext_t *dcontext, byte *pc, uint flags, uint *res_flags,
                  uint *res_exit_type, bool check_vm_area, bool mangle
                  _IF_CLIENT(bool call_client) _IF_CLIENT(bool for_trace))
{
    build_bb_t bb;

    if (!is_readable_without_exception(pc, 4/* don't know full range -- just do simple check now */)) {
        LOG(THREAD, LOG_INTERP, 3,
            "recreate_bb_ilist: cannot read memory at "PFX"\n", pc);
        return NULL;
    }

    LOG(THREAD, LOG_INTERP, 3, "\nbuilding bb instrlist now *********************\n");
    init_build_bb(&bb, pc, false/*not interp*/, false/*not for cache*/,
                  mangle, true/*translation*/, INVALID_FILE,
                  flags, NULL/*no overlap*/);
    bb.check_vm_area = check_vm_area;
#ifdef CLIENT_INTERFACE
    /* PR 214962: we call bb hook again, unless the client told us
     * DR_EMIT_STORE_TRANSLATIONS, in which case we shouldn't come here,
     * except for traces (see below):
     */
    bb.pass_to_client = DYNAMO_OPTION(code_api) && call_client;
    /* PR 299808: we call bb hook again when translating a trace that
     * didn't have DR_EMIT_STORE_TRANSLATIONS on itself (or on any
     * for_trace bb if there was no trace hook).
     */
    bb.for_trace = for_trace;
    /* instrument_basic_block, called by build_bb_ilist, verifies that all
     * non-meta instrs have translation fields */
#endif

    build_bb_ilist(dcontext, &bb);

    LOG(THREAD, LOG_INTERP, 3, "\ndone building bb instrlist *********************\n\n");
    if (res_flags != NULL)
        *res_flags = bb.flags;
    if (res_exit_type != NULL)
        *res_exit_type = bb.exit_type;
    return bb.ilist;
}

/* Re-creates an ilist of the fragment that currently contains the
 * passed-in code cache pc, also returns the fragment.
 *
 * Exactly one of pc and (f_res or *f_res) must be NULL:
 * If pc==NULL, assumes that *f_res is the fragment to use;
 * else, looks up the fragment, allocating it if necessary.
 *   If f_res!=NULL, the fragment is returned and whether it was allocated
 *   is returned in the alloc_res param.
 *   If f_res==NULL, if the fragment was allocated it is freed here.
 * 
 * NOTE : does not add prefix instructions to the created ilist, if we change
 * this to add them be sure to check recreate_app_* for compatibility (for ex.
 * adding them and setting their translation to pc would break current
 * implementation, also setting translation to NULL would trigger an assert)
 *
 * Returns NULL if unable to recreate the fragment ilist (fragment not found
 * or fragment is pending deletion and app memory might have changed).
 * In that case f_res is still pointed at the fragment if it was found, and
 * alloc is valid.
 *
 * For proper synchronization : 
 * If caller is the dcontext's owner then needs to be couldbelinking, otherwise
 * the dcontext's owner should be suspended and the callers should own the
 * thread_initexit_lock
 */
instrlist_t *
recreate_fragment_ilist(dcontext_t *dcontext, byte *pc,
                        /*IN/OUT*/fragment_t **f_res, /*OUT*/bool *alloc_res,
                        bool mangle _IF_CLIENT(bool call_client))
{
    fragment_t *f;
    uint flags = 0;
    instrlist_t *ilist;
    bool alloc = false;
    monitor_data_t md = {0,};
    IF_X64(bool old_mode = true;)
    /* check synchronization, we need to make sure no one flushes the 
     * fragment we just looked up while we are recreating it, if it's the
     * caller's dcontext then just need to be couldbelinking, otherwise need
     * the thread_initexit_lock since then we are looking up in someone else's 
     * table (the dcontext's owning thread would also need to be suspended)
     */
    ASSERT((dcontext != GLOBAL_DCONTEXT &&
            get_thread_id() == dcontext->owning_thread && 
            is_couldbelinking(dcontext)) ||
           (ASSERT_OWN_MUTEX(true, &thread_initexit_lock), true));
    STATS_INC(num_recreated_fragments);
    if (pc == NULL) {
        ASSERT(f_res != NULL && *f_res != NULL);
        f = *f_res;
    } else {
        /* Ensure callers don't give us both valid f and valid pc */
        ASSERT(f_res == NULL || *f_res == NULL);
        LOG(THREAD, LOG_INTERP, 3, "recreate_fragment_ilist: looking up pc "PFX"\n", pc);
        f = fragment_pclookup_with_linkstubs(dcontext, pc, &alloc);
        LOG(THREAD, LOG_INTERP, 3, "\tfound F%d\n", f == NULL? -1 : f->id);
        if (f_res != NULL)
            *f_res = f;
        /* ref case 3559, others, we won't be able to reliably recreate if 
         * target is pending flush, original memory might no longer be there or
         * the memory might have changed.  caller should use the stored
         * translation info instead.
         */
        if (f == NULL || TEST(FRAG_WAS_DELETED, f->flags)) {
            ASSERT(f != NULL || !alloc); /* alloc shouldn't be set if no f */
            ilist = NULL;
            goto recreate_fragment_done;
        }
    }

    /* Recreate in same mode as original fragment */
    IF_X64(old_mode = set_x86_mode(dcontext, FRAG_IS_32(f->flags)));

    if ((f->flags & FRAG_IS_TRACE) == 0) {
        /* easy case: just a bb */
        ilist = recreate_bb_ilist(dcontext, (byte *) f->tag,
                                  0/*no pre flags*/, &flags, NULL,
                                  true/*check vm area*/, mangle
                                  _IF_CLIENT(call_client)
                                  _IF_CLIENT(false/*not for_trace*/));
        ASSERT(ilist != NULL);
        if (ilist == NULL) /* a race */
            goto recreate_fragment_done;
        if (PAD_FRAGMENT_JMPS(f->flags))
            nop_pad_ilist(dcontext, f, ilist, false /* set translation */);
        goto recreate_fragment_done;
    } else {
        /* build trace up one bb at a time */
        instrlist_t *bb;
        byte *apc;
        trace_only_t *t = TRACE_FIELDS(f);
        uint i;
        instr_t *last;
        bool mangle_at_end = can_use_mangle_trace();

        if (mangle_at_end) {
            /* we need an md for mangle_trace */
            md.trace_tag = f->tag;
            /* be sure we ask for translation fields */
            md.trace_flags = f->flags | FRAG_HAS_TRANSLATION_INFO;
            md.num_blks = t->num_bbs;
            md.blk_info = (trace_bb_build_t *)
                HEAP_ARRAY_ALLOC(dcontext, trace_bb_build_t, md.num_blks, ACCT_TRACE,
                                 true);
        }

        ilist = instrlist_create(dcontext);
        STATS_INC(num_recreated_traces);
        ASSERT(t->bbs != NULL);
        for (i=0; i<t->num_bbs; i++) {
            apc = (byte *) t->bbs[i].tag;
            bb = recreate_bb_ilist(dcontext, apc, 0/*no pre flags*/,
                                   &flags, &md.final_exit_flags,
                                   true/*check vm area*/, !mangle_at_end
                                   _IF_CLIENT(call_client)
                                   _IF_CLIENT(true/*for_trace*/));
            ASSERT(bb != NULL);
            if (bb == NULL) {
                instrlist_clear_and_destroy(dcontext, ilist);
                ilist = NULL;
                goto recreate_fragment_done;
            }
            if (mangle_at_end)
                md.blk_info[i].info = t->bbs[i];
            last = instrlist_last(bb);
            ASSERT(last != NULL);
#ifdef CLIENT_INTERFACE
            if (mangle_at_end) {
                md.blk_info[i].bounds.end_pc =
                    instr_get_translation(last) + instr_length(dcontext, last);
            }
#endif

            /* PR 299808: we need to duplicate what we did when we built the trace.
             * While if there's no client trace hook we could mangle and fixup as we
             * go, for simplicity we mangle at the end either way (in either case our
             * code here is not exactly what we did when we made it anyway)
             * PR 333597: we can't use mangle_trace if we have elision on.
             */
            if (mangle && !mangle_at_end) {
                /* To duplicate the trace-building logic:
                 * - call fixup_last_cti()
                 * - retarget the ibl routine just like extend_trace() does 
                 */
                app_pc target = (last != NULL) ? opnd_get_pc(instr_get_target(last))
                    : NULL; /* FIXME: is it always safe */
                /* convert a basic block IBL, and retarget it to IBL_TRACE* */
                if (target != NULL &&
                    is_indirect_branch_lookup_routine(dcontext, target)) {
                    target = get_alternate_ibl_routine(dcontext, target, f->flags);
                    ASSERT(target != NULL);
                    LOG(THREAD, LOG_MONITOR, 3,
                        "recreate_fragment_ilist: replacing ibl_routine to target="
                        PFX"\n", target);
                    instr_set_target(last, opnd_create_pc(target));
                }
                if (DYNAMO_OPTION(pad_jmps) && 
                    !INTERNAL_OPTION(pad_jmps_shift_bb)) {
                    /* FIXME - hack, but pad_jmps_shift_bb will be on by 
                     * default. Synchronize changes here with recreate_fragment_ilist.
                     * This hack is protected by asserts in nop_pad_ilist() (that
                     * we never add nops to a bb if -pad_jmps_shift_bb) and in
                     * extend_trace_pad_bytes (that we only add bbs to traces). */
                    /* FIXME - on linux the signal fence exit can trigger the
                     * protective assert in nop_pad_ilist() */
                    remove_nops_from_ilist(dcontext, bb _IF_DEBUG(true));
                }
                if (instrlist_last(ilist) != NULL) {
                    fixup_last_cti(dcontext, ilist, (app_pc) apc, flags, f->flags, NULL,
                                   NULL, true/* record translation */, NULL,
                                   NULL, NULL);
                }
            }

            instrlist_append(ilist, instrlist_first(bb));
            instrlist_init(bb); /* to clear fields to make destroy happy */
            instrlist_destroy(dcontext, bb);
        }

#ifdef CLIENT_INTERFACE
        /* PR 214962: re-apply client changes, this time storing translation
         * info for modified instrs
         */
        if (call_client) /* else it's decode_trace() who is not really recreating */
            instrument_trace(dcontext, f->tag, ilist, true);
        /* instrument_trace checks that all non-meta instrs have translation fields */
#endif

        if (mangle) {
            if (mangle_at_end) {
                if (!mangle_trace(dcontext, ilist, &md)) {
                    instrlist_clear_and_destroy(dcontext, ilist);
                    ilist = NULL;
                    goto recreate_fragment_done;
                }
            } /* else we mangled one bb at a time up above */

#ifdef INTERNAL
            /* we only optimize traces */
            if (dynamo_options.optimize) {
                /* re-apply all optimizations to ilist
                 * assumption: all optimizations are deterministic and stateless,
                 * so we can exactly replicate their results
                 */
                LOG(THREAD_GET, LOG_INTERP, 2, 
                    "\tre-applying optimizations to F%d\n", f->id);
# ifdef SIDELINE
                if (dynamo_options.sideline) {
                    if (!TEST(FRAG_DO_NOT_SIDELINE, f->flags))
                        optimize_trace(dcontext, f->tag, ilist);
                    /* else, never optimized */
                } else
# endif
                    optimize_trace(dcontext, f->tag, ilist);
            }
#endif

            /* FIXME: case 4718 append_trace_speculate_last_ibl(true)
             * should be called as well 
             */
            if (PAD_FRAGMENT_JMPS(f->flags))
                nop_pad_ilist(dcontext, f, ilist, false /* set translation */);
        }
    }

 recreate_fragment_done:
    if (md.blk_info != NULL) {
        HEAP_ARRAY_FREE(dcontext, md.blk_info, trace_bb_build_t, md.num_blks,
                        ACCT_TRACE, true);
    }
    if (alloc_res != NULL)
        *alloc_res = alloc;
    if (f_res == NULL && alloc)
        fragment_free(dcontext, f);
    IF_X64(set_x86_mode(dcontext, old_mode));
    return ilist;
}


/*** TRACE BUILDING ROUTINES *****************************************************/

static void
process_nops_for_trace(dcontext_t *dcontext, instrlist_t *ilist, uint flags
                       _IF_DEBUG(bool recreating))
{
    if (PAD_FRAGMENT_JMPS(flags) && !INTERNAL_OPTION(pad_jmps_shift_bb)) {
        /* FIXME - hack, but pad_jmps_shift_bb will be on by 
         * default. Synchronize changes here with recreate_fragment_ilist.
         * This hack is protected by asserts in nop_pad_ilist() (that
         * we never add nops to a bb if -pad_jmps_shift_bb) and in
         * extend_trace_pad_bytes (that we only add bbs to traces). */
        /* FIXME - on linux the signal fence exit can trigger the
         * protective assert in nop_pad_ilist() */
        remove_nops_from_ilist(dcontext, ilist _IF_DEBUG(recreating));
    }
}

#ifdef CUSTOM_EXIT_STUBS
/*
 * Builds custom exit stub instrlist for exit_cti, whose stub is l
 * Assumes that intra-fragment cti's in the custom stub only target other
 * instructions in the same stub, never in the body of the fragment or
 * in other stubs.  FIXME: is this too restrictive?  If change this,
 * change the comment in instr_set_exit_stub_code's declaration.
 */
static void
regenerate_custom_exit_stub(dcontext_t *dcontext, instr_t *exit_cti, linkstub_t *l,
                            fragment_t *f)
{
    /* need to decode and restore custom stub instrlist */
    byte *cspc = EXIT_STUB_PC(dcontext, f, l);
    byte *stop = EXIT_FIXED_STUB_PC(dcontext, f, l);
    instr_t *in, *cti;
    instrlist_t intra_ctis;
    instrlist_t *cil = instrlist_create(dcontext);
    cache_pc start_pc = FCACHE_ENTRY_PC(f);
    ASSERT(DYNAMO_OPTION(indirect_stubs));

    if (l->fixed_stub_offset == 0)
        return; /* has no custom exit stub */

    LOG(THREAD, LOG_INTERP, 3, "in regenerate_custom_exit_stub\n");

    instrlist_init(&intra_ctis);
    while (cspc < stop) {
        in = instr_create(dcontext);
        cspc = decode(dcontext, cspc, in);
        ASSERT(cspc != NULL); /* our own code! */
        if (instr_is_cti(in)) {
            if (!instr_is_return(in) &&
                opnd_is_near_pc(instr_get_target(in)) &&
                (opnd_get_pc(instr_get_target(in)) < start_pc ||
                 opnd_get_pc(instr_get_target(in)) > start_pc+f->size)) {
                loginst(dcontext, 3, in, "\tcti has off-fragment target");
                /* indicate that relative target must be
                 * re-encoded, and that it is not an exit cti
                 */
                instr_set_ok_to_mangle(in, false);
                instr_set_raw_bits_valid(in, false);
            } else if (opnd_is_near_pc(instr_get_target(in))) {
                /* intra-fragment target: we'll change its target operand
                 * from pc to instr_t in second pass, so remember it here
                 */
                instr_t *clone = instr_clone(dcontext, in);
                /* HACK: use note field! */
                instr_set_note(clone, (void *) in);
                instrlist_append(&intra_ctis, clone);
            }
        }
        instrlist_append(cil, in);
    }

    /* must fix up intra-ilist cti's to have instr_t targets
     * assumption: they only target other instrs in custom stub
     * FIXME: allow targeting other instrs?
     */
    for (in = instrlist_first(cil); in != NULL; in = instr_get_next(in)) {
        for (cti = instrlist_first(&intra_ctis); cti != NULL;
             cti = instr_get_next(cti)) {
            if (opnd_get_pc(instr_get_target(cti)) == instr_get_raw_bits(in)) {
                /* cti targets this instr */
                instr_t *real_cti = (instr_t *) instr_get_note(cti);
                /* Do not preserve raw bits just in case instrlist changes
                 * and the instr target moves (xref PR 333691)
                 */
                instr_set_target(real_cti, opnd_create_instr(in));
                loginst(dcontext, 3, real_cti, "\tthis cti: ");
                loginst(dcontext, 3, in, "\t  targets intra-stub instr");
                break;
            }
        }
    }
    instrlist_clear(dcontext,&intra_ctis);

    instr_set_exit_stub_code(exit_cti, cil);
}
#endif

/* Combines instrlist_preinsert to ilist and the size calculation of the addition */
static inline int
tracelist_add(dcontext_t *dcontext, instrlist_t *ilist, instr_t *where, instr_t *inst)
{
    /* when we emit the trace we're going to call instr_length() on all instrs
     * anyway, and we'll re-use any memory allocated here for an encoding
     */
    int size = instr_length(dcontext, inst);
    instrlist_preinsert(ilist, where, inst);
    return size;
}

/* Combines instrlist_postinsert to ilist and the size calculation of the addition */
static inline int
tracelist_add_after(dcontext_t *dcontext, instrlist_t *ilist, instr_t *where, instr_t *inst)
{
    /* when we emit the trace we're going to call instr_length() on all instrs
     * anyway, and we'll re-use any memory allocated here for an encoding
     */
    int size = instr_length(dcontext, inst);
    instrlist_postinsert(ilist, where, inst);
    return size;
}

#ifdef HASHTABLE_STATISTICS
/* increments a given counter - assuming XCX is dead */
int
insert_increment_stat_counter(dcontext_t *dcontext, instrlist_t *trace, instr_t *next,                 
                              uint *counter_address)
{
    int added_size = 0;
    /* incrementing a branch-type specific thread private counter */
    opnd_t private_branchtype_counter = 
        OPND_CREATE_ABSMEM(counter_address, OPSZ_4);

    /* using LEA to avoid clobbering eflags in a simple load-increment-store */
    /*>>>    movl    counter, %ecx */
    /*>>>    lea     1(%ecx), %ecx    */
    /*>>>    movl    %ecx, counter */
    /* x64: the counter is still 32 bits */
    added_size += tracelist_add(dcontext, trace, next,
                                INSTR_CREATE_mov_ld(dcontext, opnd_create_reg(REG_ECX),
                                                    private_branchtype_counter)
                                );
    added_size += tracelist_add(dcontext, trace, next,
                                INSTR_CREATE_lea(dcontext, opnd_create_reg(REG_ECX),
                                                 opnd_create_base_disp(REG_ECX, 
                                                                       REG_NULL, 0, 1, OPSZ_lea)));
    added_size += tracelist_add(dcontext, trace, next,
                                INSTR_CREATE_mov_st(dcontext, 
                                                    private_branchtype_counter,
                                                    opnd_create_reg(REG_ECX)));
    return added_size;
}
#endif /* HASHTABLE_STATISTICS */

/* inserts proper instruction(s) to restore XCX spilled on indirect branch mangling
 *    assumes target instrlist is a trace!
 * returns size to be added to trace 
 */
static inline int
insert_restore_spilled_xcx(dcontext_t *dcontext, instrlist_t *trace, instr_t *next)
{    
    int added_size = 0;

    if (DYNAMO_OPTION(private_ib_in_tls)) {
        added_size += tracelist_add(dcontext, trace, next, 
            INSTR_CREATE_mov_ld(dcontext,
                                opnd_create_reg(REG_XCX),
                                opnd_create_tls_slot(os_tls_offset(MANGLE_XCX_SPILL_SLOT))));
    } else {
        /* We need to restore XCX from TLS for shared fragments, but from
         * mcontext for private fragments, and all traces are private
         */
        added_size += tracelist_add(dcontext, trace, next,
                                    instr_create_restore_from_dcontext
                                    (dcontext, REG_XCX, XCX_OFFSET));
    }

    return added_size;
}

/* 32-bit only: inserts a comparison to speculative_tag with no side effect and
 * if value is matched continue target is assumed to be immediately
 * after targeter (which must be < 127 bytes away).
 * returns size to be added to trace 
 */
static int
insert_transparent_comparison(dcontext_t *dcontext, instrlist_t *trace,
                              instr_t *targeter, /* exit CTI */
                              app_pc speculative_tag)
{
    int added_size = 0;
    instr_t *jecxz;
    instr_t *continue_label = INSTR_CREATE_label(dcontext);
    /* instead of:
     *   cmp ecx,const
     * we use:
     *   lea -const(ecx) -> ecx
     *   jecxz continue
     *   lea const(ecx) -> ecx
     *   jmp exit   # usual targeter for stay on trace comparison
     * continue:    # if match, we target post-targeter
     *
     * we have to use the landing pad b/c we don't know whether the
     * stub will be <128 away
     */
    /* lea requires OPSZ_lea operand */
    added_size += tracelist_add
        (dcontext, trace, targeter,
         INSTR_CREATE_lea
         (dcontext, opnd_create_reg(REG_ECX),
          opnd_create_base_disp(REG_ECX, REG_NULL, 0,
                                -((int)(ptr_int_t)speculative_tag), OPSZ_lea)));
    jecxz = INSTR_CREATE_jecxz(dcontext, opnd_create_instr(continue_label));
    /* do not treat jecxz as exit cti! */
    instr_set_ok_to_mangle(jecxz, false);
    added_size += tracelist_add(dcontext, trace, targeter, jecxz);
    /* need to recover address in ecx */
    IF_X64(ASSERT_NOT_IMPLEMENTED(false));
    added_size += tracelist_add
        (dcontext, trace, targeter,
         INSTR_CREATE_lea
         (dcontext, opnd_create_reg(REG_ECX),
          opnd_create_base_disp(REG_ECX, REG_NULL, 0,
                                ((int)(ptr_int_t)speculative_tag), OPSZ_lea)));
    added_size += tracelist_add_after(dcontext, trace, targeter, continue_label);
    return added_size;
}

/* Mangles an indirect branch in a trace where a basic block with tag "tag"
 * is being added as the next block beyond the indirect branch.
 * Returns the size of instructions added to trace.
 */
static int
mangle_indirect_branch_in_trace(dcontext_t *dcontext, instrlist_t *trace,
                                instr_t *targeter, app_pc next_tag, uint next_flags,
                                instr_t **delete_after/*OUT*/, instr_t *end_instr)
{
    int added_size = 0;
    instr_t *next = instr_get_next(targeter);
    /* all indirect branches should be ubrs */
    ASSERT(instr_is_ubr(targeter));
    /* expecting basic blocks only */
    ASSERT((end_instr != NULL && targeter == end_instr) ||
           targeter == instrlist_last(trace));

    ASSERT(delete_after != NULL);
    *delete_after = (next == NULL || (end_instr != NULL && targeter == end_instr)) ?
        NULL : instr_get_prev(next);

    STATS_INC(trace_ib_cmp);

    /* Change jump to indirect_branch_lookup to a conditional jump
     * based on indirect target not equaling next block in trace
     *
     * the bb has already done:
     *   spill xcx to xcx-tls-spill-slot
     *   mov curtarget, xcx
     *   <any other side effects of ind branch, like ret xsp adjust>
     *
     * and we now want to accomplish:
     *       cmp ecx,const
     *
     * on 32-bit we use:
     *       lea -const(ecx) -> ecx
     *       jecxz continue
     *       lea const(ecx) -> ecx
     *       jmp exit   # usual targeter for stay on trace comparison
     *     continue:    # if match, we target post-targeter
     *       restore ecx
     * we have to use the landing pad b/c we don't know whether the
     * stub will be <128 away
     *
     * on 64-bit we use (PR 245832):
     *       mov xax, xax-tls-spill-slot
     *       mov $staytarget, xax
     *       if !INTERNAL_OPTION(unsafe_ignore_eflags_{trace,ibl})
     *         mov xax, xbx-tls-spill-slot
     *         lahf
     *         seto al
     *         cmp xcx, xbx-tls-spill-slot
     *       else
     *         cmp xcx, xax
     *       jne exit
     *       if xcx live:
     *         mov xcx-tls-spill-slot, xcx
     *       if flags live && unsafe options not on:
     *         add 7f, al
     *         sahf
     *       if xax live:
     *         mov xax-tls-spill-slot, xax
     */

#ifdef CUSTOM_TRACES_RET_REMOVAL
    IF_X64(ASSERT_NOT_IMPLEMENTED(false));
    /* try to remove ret
     * FIXME: also handle ret imm => prev instr is add
     */
    inst = instr_get_prev(targeter);
    if (dcontext->call_depth >= 0 && instr_raw_bits_valid(inst)) {
        byte *b = inst->bytes + inst->length - 1;
        /*
  0x40538115   89 0d ec 68 06 40    mov    %ecx -> 0x400668ec
  0x4053811b   59                   pop    %esp (%esp) -> %ecx %esp
  0x4053811c   83 c4 04             add    $0x04 %esp -> %esp
        */
        LOG(THREAD, LOG_MONITOR, 4,
            "ret removal: *b=0x%x, prev="PFX", dcontext="PFX", 0x%x\n",
            *b, *((int *)(b-4)), dcontext, XCX_OFFSET);
        if ((*b == 0x59 && *((int *)(b-4)) == ((uint)dcontext)+XCX_OFFSET) ||
            (*(b-3)==0x59 && *((int *)(b-7)) == ((uint)dcontext)+XCX_OFFSET &&
             *(b-2)==0x83 && *(b-1)==0xc4)) {
            uint esp_add;
            /* already added calls & rets to call depth
             * if not negative, the call for this ret is earlier in this trace!
             */
            LOG(THREAD, LOG_MONITOR, 4, "fixup_last_cti: removing ret!\n");
            /* delete save ecx and pop */
            if (*b == 0x59) {
                instr_set_raw_bits(inst, inst->bytes, inst->length - 7);
                esp_add = 4;
            } else { /* delete add too */
                instr_set_raw_bits(inst, inst->bytes, inst->length - 10);
                esp_add = 4 + (uint)(*b);
                LOG(THREAD, LOG_MONITOR, 4, "*b=0x%x, esp_add=%d\n", *b, esp_add);
            }
# ifdef DEBUG
            num_rets_removed++;
# endif
            removed_ret = true;
            added_size += tracelist_add
                (dcontext, trace, targeter,
                 INSTR_CREATE_lea(dcontext, opnd_create_reg(REG_ESP),
                                  opnd_create_base_disp(REG_ESP, REG_NULL, 0,
                                                        esp_add, OPSZ_lea)));
        }
    }
    if (removed_ret) {
        *delete_after = instr_get_prev(targeter);
        return added_size;
    }
#endif /* CUSTOM_TRACES_RET_REMOVAL */

#ifdef NATIVE_RETURN
    IF_X64(ASSERT_NOT_IMPLEMENTED(false));
    if (
# ifdef NATIVE_RETURN_RET_IN_TRACES
        /* disable inlining ret: keep it as ret, actually gets better
         * performance, most noticeably on eon, vortex
         */
        false && 
# endif
        prev_l != NULL && prev_l->ret_pc != 0) {
        /* we came here through a ret
         * it was like this:
         *     ret
         *     save ecx
         *     pop ecx
         *     <add 4,esp>
         *     jmp ibl
         * we turn it into:
         *     save ecx
         *     pop ecx
         *     <add 4,esp>
         *     cmp ecx, code_cache_retaddr
         *     jne ibl
         *     restore ecx
         * with custom stub code for jne ibl:
         *     push ecx
         *     restore ecx
         *     ret <with NO IMMED>
         * we get code_cache_retaddr by saving it in dispatch each time
         * that we have to translate a next_tag from cache to app.
         */
        instrlist_t *stub_code = instrlist_create(dcontext);
        /* remove ret (will be added to custom exit stub code) */
        instr_t *ret = targeter;
        LOG(THREAD, LOG_MONITOR, 4, "\tprev_l was a ret with last addr "PFX"\n",
            dcontext->last_retaddr);
        while (ret != NULL) {
            ret = instr_get_prev(ret);
            if (instr_opcode_valid(ret) && instr_is_return(ret))
                break;
        }
        ASSERT(ret != NULL);
        instrlist_remove(trace, ret);
        instr_destroy(dcontext, ret);
        /* can this ret go away, assuming the calling convention? */
        if (dcontext->num_calls_in_trace > 0) {
            /* BIG ASSUMPTION: this ret can go away, the corresponding
             * call is earlier in this trace!
             * Just need to pop retaddr off stack by adding 4 to esp.
             */
            ret = instr_get_prev(targeter);
            ASSERT(ret != NULL);
            instrlist_remove(trace, ret);
            instr_destroy(dcontext, ret);
            added_size += tracelist_add
                (dcontext, trace, targeter,
                 INSTR_CREATE_lea(dcontext, opnd_create_reg(REG_ESP),
                                  opnd_create_base_disp(REG_ESP, REG_NULL, 0,
                                                        (int)4, OPSZ_lea)));
            instrlist_remove(trace, targeter);
            instr_destroy(dcontext, targeter);
            LOG(THREAD, LOG_MONITOR, 4, "\tjust removed ret (#calls %d)\n",
                dcontext->num_calls_in_trace);
            dcontext->num_calls_in_trace--;
            goto fixup_last_cti_finished;
        }
        /* add cmp to cache addr */
        added_size += tracelist_add
            (dcontext, trace, targeter,
             INSTR_CREATE_cmp(dcontext, opnd_create_reg(REG_ECX),
                              OPND_CREATE_INT32((int)dcontext->last_retaddr)));
        /* change jmp into jne indirect_branch_lookup */
        instr_set_opcode(targeter, OP_jnz);
        /* add custom exit stub code */
        added_size += tracelist_add(dcontext, stub_code, NULL,
                                    INSTR_CREATE_push(dcontext, opnd_create_reg(REG_ECX)));
        /* FIXME: When using -unsafe_ignore_eflags, does jmp after call go to
         * ib prefix of target? need to fix up eflags issues w/ mangle.c */
        ASSERT_NOT_IMPLEMENTED(!INTERNAL_OPTION(unsafe_ignore_eflags));
        added_size += tracelist_add
            (dcontext, stub_code, NULL,
             instr_create_restore_from_dcontext(dcontext, REG_ECX, XCX_OFFSET));
        /* can't re-use ret instr, b/c need a ret w/ NO IMMED */
        added_size += tracelist_add(dcontext, stub_code, NULL,
                                    INSTR_CREATE_ret(dcontext));
        instr_set_exit_stub_code(targeter, stub_code);
            
        /* now let normal restore-if-on-trace code get added */
    } else {
#endif /* NATIVE_RETURN */

#ifdef X64
        added_size += tracelist_add
            (dcontext, trace, targeter, INSTR_CREATE_mov_st
             (dcontext, opnd_create_tls_slot(os_tls_offset(PREFIX_XAX_SPILL_SLOT)),
              opnd_create_reg(REG_XAX)));
        added_size += tracelist_add
            (dcontext, trace, targeter, INSTR_CREATE_mov_imm
             (dcontext, opnd_create_reg(REG_XAX),
              OPND_CREATE_INTPTR((ptr_int_t)next_tag)));
        /* saving in the trace and restoring in ibl means that
         * -unsafe_ignore_eflags_{trace,ibl} must be equivalent
         */
        if (!DYNAMO_OPTION(unsafe_ignore_eflags_trace)) {
            added_size += tracelist_add
                (dcontext, trace, targeter, INSTR_CREATE_mov_st
                 (dcontext, opnd_create_tls_slot(os_tls_offset(INDIRECT_STUB_SPILL_SLOT)),
                  opnd_create_reg(REG_XAX)));
            /* FIXME: share w/ insert_save_eflags() */
            added_size += tracelist_add
                (dcontext, trace, targeter, INSTR_CREATE_lahf(dcontext));
            if (!INTERNAL_OPTION(unsafe_ignore_overflow)) { /* OF needs saving */
                /* Move OF flags into the OF flag spill slot. */
                added_size += tracelist_add
                    (dcontext, trace, targeter,
                     INSTR_CREATE_setcc(dcontext, OP_seto, opnd_create_reg(REG_AL)));
            }
            added_size += tracelist_add
                (dcontext, trace, targeter,
                 INSTR_CREATE_cmp(dcontext, opnd_create_reg(REG_XCX),
                                  opnd_create_tls_slot(os_tls_offset
                                                       (INDIRECT_STUB_SPILL_SLOT))));
        } else {
            added_size += tracelist_add
                (dcontext, trace, targeter,
                 INSTR_CREATE_cmp(dcontext, opnd_create_reg(REG_XCX),
                                  opnd_create_reg(REG_XAX)));
        }
        /* change jmp into jne to trace cmp entry of ibl routine (special entry
         * that is after the eflags save) */
        instr_set_opcode(targeter, OP_jnz);
        added_size++; /* jcc is 6 bytes, jmp is 5 bytes */
        ASSERT(opnd_is_pc(instr_get_target(targeter)));
        instr_set_target(targeter, opnd_create_pc
                         (get_trace_cmp_entry(dcontext, opnd_get_pc
                                              (instr_get_target(targeter)))));
        /* since the target gets lost we need to OR in this flag */
        instr_exit_branch_set_type(targeter, instr_exit_branch_type(targeter) |
                                   INSTR_TRACE_CMP_EXIT);
#else
        if (!INTERNAL_OPTION(unsafe_ignore_eflags_trace)) {
            /* if equal follow to the next instruction after the exit CTI */
            added_size +=
                insert_transparent_comparison(dcontext, trace, targeter, next_tag);
            /* leave jmp as it is, a jmp to exit stub (thence to ind br
             * lookup) */
        }
        else {
            /* assume eflags don't need to be saved across ind branches,
             * so go ahead and use cmp, jne
             */
            /* FIXME: no way to cmp w/ 64-bit immed */
            IF_X64(ASSERT_NOT_IMPLEMENTED(false));
            added_size += tracelist_add
                (dcontext, trace, targeter,
                 INSTR_CREATE_cmp(dcontext, opnd_create_reg(REG_ECX),
                                  OPND_CREATE_INT32((int)(ptr_int_t)next_tag)));

            /* Change jmp into jne indirect_branch_lookup */
            /* CHECK: is that also going to exit stub */
            instr_set_opcode(targeter, OP_jnz);
            added_size++; /* jcc is 6 bytes, jmp is 5 bytes */
        }
#endif /* X64 */
        /* PR 214962: our spill restoration needs this whole sequence marked mangle */
        instr_set_our_mangling(targeter, true);

        LOG(THREAD, LOG_MONITOR, 3,
            "fixup_last_cti: added cmp vs. "PFX" for ind br\n", next_tag);

#ifdef NATIVE_RETURN
    }
#endif

#ifdef HASHTABLE_STATISTICS
    /* If we do stay on the trace, increment a counter using dead XCX */
    if (INTERNAL_OPTION(stay_on_trace_stats)) {
        ibl_type_t ibl_type;
        /* FIXME: see if can test the instr flags instead */
        DEBUG_DECLARE(bool ok =)
            get_ibl_routine_type(dcontext, opnd_get_pc(instr_get_target(targeter)),
                                 &ibl_type);
        ASSERT(ok);
        added_size += insert_increment_stat_counter
            (dcontext, trace, next, 
             &get_ibl_per_type_statistics(dcontext, ibl_type.branch_type)->
             ib_stay_on_trace_stat);
    }
#endif /* HASHTABLE_STATISTICS */

    /* If we do stay on the trace, must restore xcx
     * TODO optimization: check if xcx is live or not in next bb */
    added_size += insert_restore_spilled_xcx(dcontext, trace, next);

#ifdef X64
    LOG(THREAD, LOG_INTERP, 4, "next_flags for post-ibl-cmp: 0x%x\n",
        next_flags);
    if (!TEST(FRAG_WRITES_EFLAGS_6, next_flags) &&
        !DYNAMO_OPTION(unsafe_ignore_eflags_trace)) {
        if (!TEST(FRAG_WRITES_EFLAGS_OF, next_flags) &&  /* OF was saved */
            !INTERNAL_OPTION(unsafe_ignore_overflow)) { 
            /* restore OF using add that overflows if OF was on when we did seto */
            added_size += tracelist_add
                (dcontext, trace, next, INSTR_CREATE_add
                 (dcontext, opnd_create_reg(REG_AL), OPND_CREATE_INT8(0x7f)));
        }
        added_size += tracelist_add
            (dcontext, trace, next, INSTR_CREATE_sahf(dcontext));
    } else
        STATS_INC(trace_ib_no_flag_restore);
    /* TODO optimization: check if xax is live or not in next bb */
    added_size += tracelist_add
        (dcontext, trace, next, INSTR_CREATE_mov_ld
         (dcontext, opnd_create_reg(REG_XAX),
          opnd_create_tls_slot(os_tls_offset(PREFIX_XAX_SPILL_SLOT))));
#endif

#ifdef RETURN_STACK
    if (instr_is_return) {
        /* if we stay on the trace, still need to clear pair from
         * return stack
         */
        opnd_t top = opnd_create_dcontext_field(dcontext,
                                                TOP_OF_RSTACK_OFFSET);
        /* insert prior to restoring flags (add clobbers them)! */
        added_size += tracelist_add(dcontext, trace, next,
                                    INSTR_CREATE_add(dcontext, top, OPND_CREATE_INT8(8)));
        
        /* FIXME: we need to execute a ret instruction in order to
         * clear the hardware's return stack!  And if we do that there
         * is no way to avoid a ret misprediction...
         */
        ASSERT_NOT_IMPLEMENTED(false);
    }
#endif
    return added_size;
}

/* This routine handles the mangling of the cti at the end of the
 * previous block when adding a new block (f) to the trace fragment.
 * If prev_l is not NULL, matches the ordinal of prev_l to the nth
 * exit cti in the trace instrlist_t.
 *
 * If prev_l is NULL: WARNING: this routine assumes that the previous
 * block can only have a single indirect branch -- otherwise there is
 * no way to determine which indirect exit targeted the new block!  No
 * assumptions are made about direct exits -- we can walk through them
 * all to find the one that targeted the new block.
 *
 * Returns an upper bound on the size added to the trace with inserted
 * instructions.
 * If we change this to add a substantial # of instrs, should update
 * TRACE_CTI_MANGLE_SIZE_UPPER_BOUND (assert at bottom should notify us)
 *
 * If you want to re-add the ability to add the front end of a trace,
 * revive the now-removed CUSTOM_TRACES_ADD_TRACE define from the attic.
 */
static int
fixup_last_cti(dcontext_t *dcontext, instrlist_t *trace,
               app_pc next_tag, uint next_flags, uint trace_flags,
               fragment_t *prev_f, linkstub_t *prev_l,
               bool record_translation, uint *num_exits_deleted/*OUT*/,
               /* If non-NULL, only looks inside trace between these two */
               instr_t *start_instr, instr_t *end_instr)
{
    app_pc target_tag;
    instr_t *inst, *targeter = NULL;
    /* at end of routine we will delete all instrs after this one: */
    instr_t *delete_after = NULL;
    bool is_indirect = false;
#ifdef RETURN_STACK
    bool instr_is_return;
#endif
    /* Added size for transformations done here.
     * Use tracelist_add to automate adding inserted instr sizes.
     */
    int added_size = 0;
    uint exits_deleted = 0;

    /* count exit stubs to get the ordinal of the exit that targeted us
     * start at prev_l, and count up extraneous exits and blks until end
     */
    uint nth_exit = 0, cur_exit;
#ifdef CUSTOM_TRACES_RET_REMOVAL
    bool removed_ret = false;
#endif
    bool have_ordinal = false;
    if (prev_l != NULL && prev_l == get_deleted_linkstub(dcontext)) {
        int last_ordinal = get_last_linkstub_ordinal(dcontext);
        if (last_ordinal != -1) {
            nth_exit = last_ordinal;
            have_ordinal = true;
        }
    }
    if (!have_ordinal && prev_l != NULL && !LINKSTUB_FAKE(prev_l)) {
        linkstub_t *stub = FRAGMENT_EXIT_STUBS(prev_f);
        while (stub != prev_l)
            stub = LINKSTUB_NEXT_EXIT(stub);
        /* if prev_l is cbr followed by ubr, we'll get 1 for ubr,
         * but we want 0, so we count prev_l itself, then decrement
         */
        stub = LINKSTUB_NEXT_EXIT(stub);
        while (stub != NULL) {
            nth_exit++;
            stub = LINKSTUB_NEXT_EXIT(stub);
        }
    } /* else, we assume it's the final exit */

    LOG(THREAD, LOG_MONITOR, 4,
        "fixup_last_cti: looking for %d-th exit cti from bottom\n", nth_exit);

    if (start_instr != NULL) {
        ASSERT(end_instr != NULL);
    } else {
        start_instr = instrlist_first(trace);
        end_instr = instrlist_last(trace);
    }
    start_instr = instr_get_prev(start_instr); /* get open-ended bound */

    cur_exit = nth_exit;
    /* now match the ordinal to the instrs.
     * we don't have any way to find boundary with previous-previous block
     * to make sure we didn't go backwards too far -- does it matter?
     */
    for (inst = end_instr; inst != NULL && inst != start_instr;
         inst = instr_get_prev(inst)) {
        if (instr_is_exit_cti(inst)) {
            if (cur_exit == 0) {
                ibl_type_t ibl_type;
                /* exit cti is guaranteed to have pc target */
                target_tag = opnd_get_pc(instr_get_target(inst));

                is_indirect = get_ibl_routine_type(dcontext, target_tag, &ibl_type);

                if (is_indirect) {
                    /* this should be a trace exit stub therefore it cannot be IBL_BB* */
                    ASSERT(IS_IBL_TRACE(ibl_type.source_fragment_type));
#ifdef RETURN_STACK
                    instr_is_return = ibl_type.branch_type == IBL_RETURN;
#endif
                    targeter = inst;
                    break;
                } else {
                    if (prev_l != NULL) {
                        /* direct jmp, better point to us */
                        ASSERT(target_tag == next_tag);
                        targeter = inst;
                        break;
                    } else {
                        /* need to search for targeting jmp */
                        if (target_tag == next_tag) {
                            targeter = inst;
                            break;
                        }
                    }
                }
            } else if (prev_l != NULL) {
                LOG(THREAD, LOG_MONITOR, 4,
                    "counting backwards: %d == target_tag = "PFX"\n",
                    cur_exit, opnd_get_pc(instr_get_target(inst)));
                cur_exit--;
            }
        } /* is exit cti */
    }
    ASSERT(targeter != NULL);
    if (record_translation)
        instrlist_set_translation_target(trace, instr_get_translation(targeter));
    instrlist_set_our_mangling(trace, true); /* PR 267260 */
    DOLOG(4, LOG_MONITOR, {
        loginst(dcontext, 4, targeter, "\ttargeter");
    });
    if (is_indirect) {
        added_size += mangle_indirect_branch_in_trace(dcontext, trace, targeter,
                                                      next_tag, next_flags,
                                                      &delete_after, end_instr);
    } else {
        /* direct jump or conditional branch */
        instr_t *next = targeter->next;
        if (instr_is_cbr(targeter)) {
            LOG(THREAD, LOG_MONITOR, 4, "fixup_last_cti: inverted logic of cbr\n");
            if (next != NULL && instr_is_ubr(next)) {
                /* cbr followed by ubr: if cbr got us here, reverse cbr and
                 * remove ubr
                 */
                instr_invert_cbr(targeter);
                instr_set_target(targeter, instr_get_target(next));
                ASSERT(next == end_instr);
                delete_after = targeter;
                LOG(THREAD, LOG_MONITOR, 4, "\tremoved ubr following cbr\n");
            } else {
                ASSERT_NOT_REACHED();
            }
        } else if (instr_is_ubr(targeter)) {
#ifndef CUSTOM_TRACES
            ASSERT(targeter == end_instr);
#endif
            /* remove unnecessary ubr at end of block */
            delete_after = instr_get_prev(targeter);
            if (delete_after != NULL) {
                LOG(THREAD, LOG_MONITOR, 4,     "fixup_last_cti: removed ubr\n");
            }
        } else
            ASSERT_NOT_REACHED();
    }
    /* remove all instrs after this cti -- but what if internal
     * control flow jumps ahead and then comes back?
     * too expensive to check for such all the time.
     * FIXME: what to do?
     *
     * ifdef CUSTOM_TRACES:
     * FIXME: rather than adding entire trace on and then chopping off where
     * we exited, why not add after we know where to stop?
     */
    if (delete_after != NULL) {
        ASSERT(delete_after != end_instr);
        delete_after = instr_get_next(delete_after);
        while (delete_after != NULL) {
            inst = delete_after;
            if (delete_after == end_instr)
                delete_after = NULL;
            else
                delete_after = instr_get_next(delete_after);
            if (instr_is_exit_cti(inst)) {
                /* assumption: passing in cache target to exit_stub_size works
                 * just as well as linkstub_t target, since only cares whether
                 * targeting ibl
                 */
                app_pc target = opnd_get_pc(instr_get_target(inst));
                /* we already added all the stub size differences to the trace,
                 * so we subtract the trace size of the stub here
                 */
                added_size -= local_exit_stub_size(dcontext, target, trace_flags);
                exits_deleted++;
            } else if (instr_opcode_valid(inst) && instr_is_cti(inst)) {
                LOG(THREAD, LOG_MONITOR, 3,
                    "WARNING: deleting non-exit cti in unused tail of frag added to trace\n");
            }
            loginst(dcontext, 4, inst, "\tdeleting");
            instrlist_remove(trace, inst);
            added_size -= instr_length(dcontext, inst);
            instr_destroy(dcontext, inst);
        }
    }

    if (num_exits_deleted != NULL)
        *num_exits_deleted = exits_deleted;

#ifdef NATIVE_RETURN
 fixup_last_cti_finished:
#endif
    if (record_translation)
        instrlist_set_translation_target(trace, NULL);
    instrlist_set_our_mangling(trace, false); /* PR 267260 */
    ASSERT(added_size < TRACE_CTI_MANGLE_SIZE_UPPER_BOUND);
    return added_size;
}

/* Add a speculative counter on last IBL exit
 * Returns additional size to add to trace estimate.
 */
int
append_trace_speculate_last_ibl(dcontext_t *dcontext, instrlist_t *trace,
                                app_pc speculate_next_tag,
                                bool record_translation)
{
    /* unlike fixup_last_cti() here we are about to go directly to the IBL routine */
    /* spill XCX in a scratch slot - note always using TLS */
    int added_size = 0;
    ibl_type_t ibl_type;

    instr_t *inst = instrlist_last(trace); /* currently only relevant to last CTI */
    instr_t *where = inst;         /* preinsert before last CTI */

    instr_t *next = instr_get_next(inst);
    DEBUG_DECLARE(bool ok;)

    ASSERT(speculate_next_tag != NULL);
    ASSERT(inst != NULL);
    ASSERT(instr_is_exit_cti(inst));

    /* FIXME: see if can test the instr flags instead */
    DEBUG_DECLARE(ok = )
        get_ibl_routine_type(dcontext, opnd_get_pc(instr_get_target(inst)), &ibl_type);
    ASSERT(ok);
                
    if (record_translation)
        instrlist_set_translation_target(trace, instr_get_translation(inst));
    instrlist_set_our_mangling(trace, true); /* PR 267260 */

    STATS_INC(num_traces_end_at_ibl_speculative_link);

#ifdef HASHTABLE_STATISTICS
    DOSTATS({
        if (INTERNAL_OPTION(speculate_last_exit_stats)) {
            int tls_stat_scratch_slot = os_tls_offset(HTABLE_STATS_SPILL_SLOT);

            added_size += 
                tracelist_add(dcontext, trace, where, 
                              INSTR_CREATE_mov_st(dcontext,
                                                  opnd_create_tls_slot(tls_stat_scratch_slot),
                                                  opnd_create_reg(REG_XCX)));
            added_size += 
                insert_increment_stat_counter(dcontext, trace, where, 
                                              &get_ibl_per_type_statistics(dcontext, 
                                                                           ibl_type.branch_type)
                                              ->ib_trace_last_ibl_exit);
            added_size += 
                tracelist_add(dcontext, trace, where, 
                              INSTR_CREATE_mov_ld(dcontext,
                                                  opnd_create_reg(REG_XCX),
                                                  opnd_create_tls_slot(tls_stat_scratch_slot)));
        }
    });
#endif
    /* preinsert comparison before exit CTI, but increment of success statistics after it */

    /* we need to compare to speculate_next_tag now */
    /* XCX holds value to match */

    /* should use similar eflags-clobbering scheme to inline cmp */
    IF_X64(ASSERT_NOT_IMPLEMENTED(false));
    /* 
     *    8d 89 76 9b bf ff    lea    -tag(%ecx) -> %ecx 
     *    e3 0b                jecxz  continue
     *    8d 89 8a 64 40 00    lea    tag(%ecx) -> %ecx 
     *    e9 17 00 00 00       jmp    <exit stub 1: IBL>
     *
     * continue:
     *                        <increment stats>
     *                        <restore app ecx>  # see FIXME whether to go to prefix or do here
     *    e9 cc aa dd 00       jmp speculate_next_tag
     *
     */

    /* leave jmp as it is, a jmp to exit stub (thence to ind br lookup) */
    added_size += 
        insert_transparent_comparison(dcontext, trace, where, speculate_next_tag);

#ifdef HASHTABLE_STATISTICS
    DOSTATS({
        if (INTERNAL_OPTION(speculate_last_exit_stats)) {
            int tls_stat_scratch_slot = os_tls_offset(HTABLE_STATS_SPILL_SLOT);
            /* XCX already saved */

            added_size += 
                insert_increment_stat_counter(dcontext, trace, next, 
                                              &get_ibl_per_type_statistics(dcontext, 
                                                                           ibl_type.branch_type)
                                              ->ib_trace_last_ibl_speculate_success);
            /* restore XCX to app IB target*/
            added_size += 
                tracelist_add(dcontext, trace, next, 
                              INSTR_CREATE_mov_ld(dcontext,
                                                  opnd_create_reg(REG_XCX),
                                                  opnd_create_tls_slot(tls_stat_scratch_slot)));
        }
    });        
#endif
    /* adding a new CTI for speculative target that is a pseudo
     * direct exit.  Although we could have used the indirect stub
     * to be the unlinked path, with a new CTI way we can unlink a
     * speculated fragment without affecting any other targets
     * reached by the IBL.  Also in general we could decide to add
     * multiple speculative comparisons and to chain them we'd
     * need new CTIs for them.
     */

    /* Ensure all register state is properly preserved on both linked
     * and unlinked paths - currently only XCX is in use.
     * 
     *
     * Preferably we should be targeting prefix of target to
     * save some space for recovering XCX from hot path.  We'd
     * restore XCX in the exit stub when unlinked.
     * So it would act like a direct CTI when linked and like indirect
     * when unlinked.  It could just be an unlinked indirect stub, if
     * we haven't modified any other registers or flags.
     *
     * For simplicity, we currently restore XCX here and use a plain
     * direct exit stub that goes to target start_pc instead of
     * prefixes.  
     *
     * FIXME: (case 5085) the problem with the current scheme is that
     * when we exit unlinked the source will be marked as a DIRECT
     * exit - therefore no security policies will be enforced.
     *
     * FIXME: (case 4718) should add speculated target to current list
     * in case of RCT policy that needs to be invalidated if target is
     * flushed
     */

    /* must restore xcx to app value, FIXME: see above for doing this in prefix+stub */
    added_size += insert_restore_spilled_xcx(dcontext, trace, next);

    /* add a new direct exit stub */
    added_size += tracelist_add(dcontext, trace, next, 
                                INSTR_CREATE_jmp(dcontext, opnd_create_pc(speculate_next_tag)));
    LOG(THREAD, LOG_INTERP, 3,
        "append_trace_speculate_last_ibl: added cmp vs. "PFX" for ind br\n",
        speculate_next_tag);

    if (record_translation)
        instrlist_set_translation_target(trace, NULL);
    instrlist_set_our_mangling(trace, false); /* PR 267260 */

    return added_size;
}

#ifdef HASHTABLE_STATISTICS
/* Add a counter on last IBL exit
 * if speculate_next_tag is not NULL then check case 4817's possible success
 */
/* FIXME: remove this routine once append_trace_speculate_last_ibl()
 * currently useful only to see statistics without side effects of
 * adding exit stub
 */
int
append_ib_trace_last_ibl_exit_stat(dcontext_t *dcontext, instrlist_t *trace,
                                   app_pc speculate_next_tag)
{
    /* unlike fixup_last_cti() here we are about to go directly to the IBL routine */
    /* spill XCX in a scratch slot - note always using TLS */
    int tls_stat_scratch_slot = os_tls_offset(HTABLE_STATS_SPILL_SLOT);
    int added_size = 0;
    ibl_type_t ibl_type;

    instr_t *inst = instrlist_last(trace); /* currently only relevant to last CTI */
    instr_t *where = inst;         /* preinsert before exit CTI */

    DEBUG_DECLARE(bool ok;)

    /* should use similar eflags-clobbering scheme to inline cmp */
    IF_X64(ASSERT_NOT_IMPLEMENTED(false));

    ASSERT(inst != NULL);
    ASSERT(instr_is_exit_cti(inst));

    /* FIXME: see if can test the instr flags instead */
    ok = get_ibl_routine_type(dcontext, opnd_get_pc(instr_get_target(inst)), &ibl_type);
                
    ASSERT(ok);
    added_size += tracelist_add(dcontext, trace, where, 
                                INSTR_CREATE_mov_st(dcontext,
                                                    opnd_create_tls_slot(tls_stat_scratch_slot),
                                                    opnd_create_reg(REG_XCX)));
    added_size += 
        insert_increment_stat_counter(dcontext, trace, where, 
                                      &get_ibl_per_type_statistics(dcontext, ibl_type.branch_type)
                                      ->ib_trace_last_ibl_exit);
    added_size += tracelist_add(dcontext, trace, where, 
                                INSTR_CREATE_mov_ld(dcontext,
                                                    opnd_create_reg(REG_XCX),
                                                    opnd_create_tls_slot(tls_stat_scratch_slot)));

    if (speculate_next_tag != NULL) {
        instr_t *next = instr_get_next(inst);
        /* preinsert comparison before exit CTI, but increment goes after it */

        /* we need to compare to speculate_next_tag now - just like fixup_last_cti() would do later */
        /* ECX holds value to match here */
        
        /* leave jmp as it is, a jmp to exit stub (thence to ind br lookup) */

        /* continue:
         *    increment success counter 
         *    jmp targeter
         *
         *   FIXME: now the last instruction is no longer the exit_cti - see if that breaks any assumptions,
         *   using a short jump to see if anyone erroneously uses this
         */
        added_size += 
            insert_transparent_comparison(dcontext, trace, where, speculate_next_tag);

        /* we'll kill again although ECX restored unnecessarily by comparison routine,   */
        added_size += 
            insert_increment_stat_counter(dcontext, trace, next, 
                                          &get_ibl_per_type_statistics(dcontext, ibl_type.branch_type)
                                          ->ib_trace_last_ibl_speculate_success);
        /* restore ECX */
        added_size += tracelist_add(dcontext, trace, next, 
                                INSTR_CREATE_mov_ld(dcontext,
                                                    opnd_create_reg(REG_ECX),
                                                    opnd_create_tls_slot(tls_stat_scratch_slot)));
        /* jmp where */
        added_size += tracelist_add(dcontext, trace, next, 
                                    INSTR_CREATE_jmp_short(dcontext, opnd_create_instr(where)));
    }

    return added_size;
}
#endif /* HASHTABLE_STATISTICS */

/* Add the fragment f to the end of the trace instrlist_t kept in dcontext
 *
 * Note that recreate_fragment_ilist() is making assumptions about its operation
 * synchronize changes 
 *
 * Returns the size change in the trace from mangling the previous block
 * (assumes the caller has already calculated the size from adding the new block)
 */
uint
extend_trace(dcontext_t *dcontext, fragment_t *f, linkstub_t *prev_l)
{
    monitor_data_t *md = (monitor_data_t *) dcontext->monitor_field;
    fragment_t *prev_f = NULL;
    instrlist_t *trace = &(md->trace);
    instrlist_t *ilist;
    uint size;
    uint prev_mangle_size = 0;
    uint num_exits_deleted = 0;
    uint new_exits_dir = 0, new_exits_indir = 0;

    STATS_INC(num_traces_extended);

    /* if you want to re-add the ability to add traces, revive
     * CUSTOM_TRACES_ADD_TRACE from the attic
     */
    ASSERT(!TEST(FRAG_IS_TRACE, f->flags)); /* expecting block fragments */

    if (prev_l != NULL) {
        ASSERT(!LINKSTUB_FAKE(prev_l) ||
               /* we track the ordinal of the del linkstub so it's ok */
               prev_l == get_deleted_linkstub(dcontext));
        prev_f = linkstub_fragment(dcontext, prev_l);
        LOG(THREAD, LOG_MONITOR, 4, "prev_l = owned by F%d, branch pc "PFX"\n",
            prev_f->id, EXIT_CTI_PC(prev_f, prev_l));
    } else {
        LOG(THREAD, LOG_MONITOR, 4, "prev_l is NULL\n");
    }

    /* insert code to optimize last branch based on new fragment */
    if (instrlist_last(trace) != NULL) {
        prev_mangle_size = fixup_last_cti(dcontext, trace, f->tag, f->flags,
                                          md->trace_flags, prev_f, prev_l, false,
                                          &num_exits_deleted, NULL, NULL);
    }
    
#ifdef CUSTOM_TRACES_RET_REMOVAL
    /* add now, want fixup to operate on depth before adding new blk */
    dcontext->call_depth += f->num_calls;
    dcontext->call_depth -= f->num_rets;
#endif

    LOG(THREAD, LOG_MONITOR, 4,
        "\tadding block %d == "PFX"\n", md->num_blks, f->tag);

    size = md->trace_buf_size - md->trace_buf_top;
    LOG(THREAD, LOG_MONITOR, 4, "decoding F%d into trace buf @"PFX" + 0x%x = "PFX"\n",
        f->id, md->trace_buf, md->trace_buf_top, md->trace_buf + md->trace_buf_top);
    /* FIXME: PR 307388: if md->pass_to_client, much of this is a waste of time as
     * we're going to re-mangle and re-fixup after passing our unmangled list to the
     * client.  We do want to keep the size estimate, which requires having the last
     * cti at least, so for now we keep all the work.  Of course the size estimate is
     * less valuable when the client may add a ton of instrumentation.
     */
    /* decode_fragment will convert f's ibl routines into those appropriate for
     * our trace, whether f and the trace are shared or private
     */
    ilist = decode_fragment(dcontext, f, md->trace_buf + md->trace_buf_top, &size,
                            md->trace_flags, &new_exits_dir, &new_exits_indir);

    md->blk_info[md->num_blks].info.tag = f->tag;
#if defined(RETURN_AFTER_CALL) || defined(RCT_IND_BRANCH)
    if (md->num_blks > 0)
        md->blk_info[md->num_blks - 1].info.num_exits -= num_exits_deleted;
    md->blk_info[md->num_blks].info.num_exits = new_exits_dir + new_exits_indir;
#endif
    md->num_blks++;
    
    /* We need to remove any nops we added for -pad_jmps (we don't expect there
     * to be any in a bb if -pad_jmps_shift_bb) to avoid screwing up 
     * fixup_last_cti etc. */
    process_nops_for_trace(dcontext, ilist, f->flags _IF_DEBUG(false/*!recreating*/));

    DOLOG(5, LOG_MONITOR, {
        LOG(THREAD, LOG_MONITOR, 5, "post-trace-ibl-fixup, ilist is:\n");
        instrlist_disassemble(dcontext, f->tag, ilist, THREAD);
    });

    ASSERT(!instrlist_get_our_mangling(ilist));
    instrlist_append(trace, instrlist_first(ilist));
    instrlist_init(ilist); /* clear fields so destroy won't kill instrs now on trace list */
    instrlist_destroy(dcontext, ilist);

    md->trace_buf_top += size;
    ASSERT(md->trace_buf_top < md->trace_buf_size);
    LOG(THREAD, LOG_MONITOR, 4, "post-extend_trace, trace buf + 0x%x => "PFX"\n",
        md->trace_buf_top, md->trace_buf);

    DOLOG(4, LOG_MONITOR, {
        LOG(THREAD, LOG_MONITOR, 4, "\nafter extending trace:\n");
        instrlist_disassemble(dcontext, md->trace_tag, trace, THREAD);
    });
    return prev_mangle_size;
}

/* If branch_type is 0, sets it to the type of a ubr */
static instr_t *
create_exit_jmp(dcontext_t *dcontext, app_pc target, app_pc translation,
                uint branch_type)
{
    instr_t *jmp = INSTR_CREATE_jmp(dcontext, opnd_create_pc(target));
    instr_set_translation(jmp, translation);
    if (branch_type == 0)
        instr_exit_branch_set_type(jmp, instr_branch_type(jmp));
    else
        instr_exit_branch_set_type(jmp, branch_type);
    instr_set_our_mangling(jmp, true);
    return jmp;
}

static bool
can_use_mangle_trace(void)
{
    /* elision messes up our bb boundary identification */
    bool ok = (DYNAMO_OPTION(max_elide_jmp) == 0 &&
               DYNAMO_OPTION(max_elide_call) == 0 &&
               !DYNAMO_OPTION(indcall2direct));
#ifdef CLIENT_INTERFACE
    /* must be able to use it if client has hooks */
    ASSERT(ok || (!dr_bb_hook_exists() && !dr_trace_hook_exists()));
#endif
    return ok;
}

/* Given an ilist with no mangling or stitching together, this routine does those
 * things.  This is used both for CLIENT_INTERFACE and for recreating traces
 * for state translation.
 * It assumes the ilist abides by client rules: single-mbr bbs, no
 * changes in source app code, no elision.  Else, it returns false.
 *
 * Reads the following fields from md:
 * - trace_tag
 * - trace_flags
 * - num_blks
 * - blk_info
 * - final_exit_flags
 */
bool
mangle_trace(dcontext_t *dcontext, instrlist_t *ilist, monitor_data_t *md)
{
    instr_t *inst, *next_inst, *start_instr, *jmp;
    uint blk, num_exits_deleted;
    app_pc fallthrough = NULL;
    bool found_syscall = false, found_int = false;
    int i;

    ASSERT(can_use_mangle_trace());

    LOG(THREAD, LOG_MONITOR, 2, "mangle_trace "PFX"\n", md->trace_tag);
    DOLOG(4, LOG_INTERP, {
        LOG(THREAD, LOG_INTERP, 4, "ilist passed to mangle_trace:\n");
        instrlist_disassemble(dcontext, md->trace_tag, ilist, THREAD);
    });

    /* We make 3 passes.
     * 1st walk: find bb boundaries
     */
    blk = 0;
    for (inst = instrlist_first(ilist); inst != NULL; inst = next_inst) {
        LOG_DECLARE(instr_t *prev = instr_get_prev(inst);)
        next_inst = instr_get_next(inst);

        if (!instr_ok_to_mangle(inst))
            continue;

        DOLOG(5, LOG_INTERP, {
            LOG(THREAD, LOG_MONITOR, 4, "transl "PFX" ", instr_get_translation(inst));
            loginst(dcontext, 4, inst, "considering non-meta");
        }); 

        /* Check for bb end with no exit cti.  We don't worry about whether a ubr w/
         * a translation set to its target is part of this or next bb: all that's
         * important is blk++ to ensure we find later transitions.  We assume a block
         * w/ nothing but ubrs must have the final one target the subsequent block
         * (which will hit our exit cti check below), so we'll always see an instr in
         * the next block's translation range.
         */
        /* PR 366232: we handle empty bbs by looping here */
        for (i = 1; blk+i < md->num_blks; i++) {
            /* Since we can have tail-duplication among bbs, make sure to first
             * check whether we're still in the cur block: b/c this translation
             * can be both in this block and in next block.  In such a case we
             * assume a (backward) cti separates them. */
            if (!(instr_get_translation(inst) >= md->blk_info[blk].info.tag &&
                  instr_get_translation(inst) < md->blk_info[blk].bounds.end_pc) &&
                instr_get_translation(inst) >= md->blk_info[blk+i].info.tag &&
                instr_get_translation(inst) < md->blk_info[blk+i].bounds.end_pc) {
                /* counting down but adding jmps in forward order */
                for (; i >= 1; i--) {
                    DOLOG(4, LOG_INTERP, { /* use prev to avoid added jmp */
                        loginst(dcontext, 4, prev, "fallthrough end of bb");
                    }); 
                    jmp = create_exit_jmp(dcontext, md->blk_info[blk+1].info.tag,
                                          md->blk_info[blk+1].info.tag, 0);
                    instrlist_preinsert(ilist, inst, jmp);
                    md->blk_info[blk].bounds.end_instr = jmp;
                    blk++;
#if defined(RETURN_AFTER_CALL) || defined(RCT_IND_BRANCH)
                    /* we'll decrement if jmp gets elided (as it should) */
                    md->blk_info[blk].info.num_exits++;
#endif
                    LOG(THREAD, LOG_MONITOR, 4, "starting next bb "PFX"\n",
                        md->blk_info[blk].info.tag);
                }
                break;
            }
        }

#ifdef CLIENT_INTERFACE
        /* Ensure non-ignorable syscall/int2b terminates trace */
#ifndef LINUX_KERNEL
        if (md->pass_to_client &&
            !client_check_syscall(ilist, inst, &found_syscall, &found_int))
            return false;
#endif

        /* Clients should not add new source code regions, which would mess us up
         * here, as well as mess up our cache consistency (both page prot and
         * selfmod).
         */
        if (md->pass_to_client &&
            !((instr_get_translation(inst) >= md->blk_info[blk].info.tag &&
               instr_get_translation(inst) < md->blk_info[blk].bounds.end_pc) ||
              (instr_is_ubr(inst) && opnd_is_pc(instr_get_target(inst)) &&
               instr_get_translation(inst) == opnd_get_pc(instr_get_target(inst))))) {
            LOG(THREAD, LOG_MONITOR, 2,
                "trace error: out-of-bounds transl "PFX" vs start "PFX" end "PFX"\n",
                instr_get_translation(inst),
                md->blk_info[blk].info.tag, md->blk_info[blk].bounds.end_pc);
            CLIENT_ASSERT(false,
                          "trace's app sources (instr_set_translation() targets) "
                          "must remain within original bounds");
            return false;
        }
#endif

        /* in case no exit ctis in last block, find last non-meta fall-through */
        if (blk == md->num_blks - 1)
            fallthrough = instr_get_translation(inst) + instr_length(dcontext, inst);

        /* PR 299808: identify bb boundaries.  We can't go by translations alone, as
         * ubrs can point at their targets and theoretically the entire trace could
         * be ubrs: so we have to go by exits, and limit what the client can do.  We
         * can assume that each bb should not violate the bb callback rules (PR
         * 215217): if has cbr, call, or mbr, that must end bb.  We also want to
         * impose the can't-be-trace rules (PR 215219), which are not documented for
         * bbs: if more than one exit cti or if code beyond last exit cti then can't
         * be in a trace.  We can soften a little and allow extra ubrs if they do not
         * target the subsequent block.  FIXME: we could have stricter translation
         * reqts for ubrs: make them point at corresponding app ubr (but what if
         * really correspond to app cbr?): then can handle code past exit ubr.
         */
        if (instr_will_be_exit_cti(inst) &&
            (!instr_is_ubr(inst) ||
             (inst == instrlist_last(ilist) ||
              (blk+1 < md->num_blks &&
               /* client is disallowed from changing bb exits and sequencing in trace
                * hook; if they change in bb for_trace, will be reflected here.
                */
               opnd_get_pc(instr_get_target(inst)) == md->blk_info[blk+1].info.tag)))) {

            DOLOG(4, LOG_INTERP, {
                loginst(dcontext, 4, inst, "end of bb");
            }); 

            /* Add jump that fixup_last_cti expects */
            if (!instr_is_ubr(inst)) {
                app_pc target;
                if (instr_is_mbr(inst)) {
                    target = get_ibl_routine(dcontext, IBL_LINKED, DEFAULT_IBL_TRACE(), 
                                             get_ibl_branch_type(inst));
                } else if (instr_is_cbr(inst)) {
                    target = instr_get_translation(inst) + instr_length(dcontext, inst);
                } else {
                    target = opnd_get_pc(instr_get_target(inst));
                }
                ASSERT(target != NULL);
                jmp = create_exit_jmp(dcontext, target, instr_get_translation(inst),
                                      instr_branch_type(inst));
                instrlist_postinsert(ilist, inst, jmp);
                /* we're now done w/ end_pc: replace w/ end instr.
                 * mangle() shouldn't remove the exit cti.
                 */
                md->blk_info[blk].bounds.end_instr = jmp;
            } else
                md->blk_info[blk].bounds.end_instr = inst;

            blk++;
            DOLOG(4, LOG_INTERP, {
                if (blk < md->num_blks) {
                    LOG(THREAD, LOG_MONITOR, 4, "starting next bb "PFX"\n",
                        md->blk_info[blk].info.tag);
                }
            });
            if (blk >= md->num_blks && next_inst != NULL) {
                CLIENT_ASSERT(false, "unsupported trace modification: too many exits");
                return false;
            }
        }
#if defined(RETURN_AFTER_CALL) || defined(RCT_IND_BRANCH)
        /* PR 306761: we need to re-calculate md->blk_info[blk].info.num_exits,
         * and then adjust after fixup_last_cti.
         */
        if (instr_will_be_exit_cti(inst))
            md->blk_info[blk].info.num_exits++;
#endif

    }
    if (blk < md->num_blks) {
        ASSERT(!instr_is_ubr(instrlist_last(ilist)));
        if (blk + 1 < md->num_blks) {
            CLIENT_ASSERT(false, "unsupported trace modification: too few exits");
            return false;
        }
        /* must have been no final exit cti: add final fall-through jmp */
        jmp = create_exit_jmp(dcontext, fallthrough, fallthrough, 0);
        /* FIXME PR 307284: support client modifying, replacing, or adding
         * syscalls and ints: need to re-analyze.  Then we wouldn't
         * need the md->final_exit_flags field anymore.
         * For now we disallow.
         */
        if (found_syscall || found_int) {
            instr_exit_branch_set_type(jmp, md->final_exit_flags);
#ifdef WINDOWS
            /* For INSTR_SHARED_SYSCALL, we set it pre-mangling, and it
             * survives to here if the instr is not clobbered,
             * and does not come from md->final_exit_flags
             */
            if (TEST(INSTR_SHARED_SYSCALL, instrlist_last(ilist)->flags)) {
                instr_set_target(jmp, opnd_create_pc(shared_syscall_routine(dcontext)));
                instr_set_our_mangling(jmp, true); /* undone by target set */
            }
            /* FIXME: test for linux too, but allowing ignorable syscalls */
            if (!TESTANY(LINK_NI_SYSCALL_ALL IF_WINDOWS(| LINK_CALLBACK_RETURN),
                         md->final_exit_flags) &&
                !TEST(INSTR_SHARED_SYSCALL, instrlist_last(ilist)->flags)) {
                CLIENT_ASSERT(false,
                              "client modified or added a syscall or int: unsupported");
                return false;
            }
#endif
        }
        instrlist_append(ilist, jmp);
        md->blk_info[blk].bounds.end_instr = jmp;
    } else {
        CLIENT_ASSERT((!found_syscall && !found_int)
                      /* On linux we allow ignorable syscalls in middle.
                       * FIXME PR 307284: see notes above. */
                      IF_NOT_LINUX_KERNEL(IF_LINUX(|| !TEST(LINK_NI_SYSCALL, md->final_exit_flags))),
                      "client changed exit target where unsupported\n"
                      "check if trace ends in a syscall or int");
    }
    ASSERT(instr_is_ubr(instrlist_last(ilist)));
    if (found_syscall)
        md->trace_flags |= FRAG_HAS_SYSCALL;
    else
        md->trace_flags &= ~FRAG_HAS_SYSCALL;

    /* 2nd walk: mangle */
    DOLOG(4, LOG_INTERP, {
        LOG(THREAD, LOG_INTERP, 4, "trace ilist before mangling:\n");
        instrlist_disassemble(dcontext, md->trace_tag, ilist, THREAD);
    });
    /* We do not need to remove nops since we never emitted */
    mangle(dcontext, ilist, md->trace_flags, true/*mangle calls*/,
           /* we're post-client so we don't need translations unless storing */
           TEST(FRAG_HAS_TRANSLATION_INFO, md->trace_flags));
    DOLOG(4, LOG_INTERP, {
        LOG(THREAD, LOG_INTERP, 4, "trace ilist after mangling:\n");
        instrlist_disassemble(dcontext, md->trace_tag, ilist, THREAD);
    });

    /* 3rd walk: stitch together delineated bbs */
    blk = 0;
    start_instr = instrlist_first(ilist);
    for (inst = instrlist_first(ilist); inst != NULL; inst = next_inst) {
        next_inst = instr_get_next(inst);
        
        if (inst == md->blk_info[blk].bounds.end_instr) {
            /* Chain exit to point to next bb */
            if (blk + 1 < md->num_blks) {
                /* We must do proper analysis so that state translation matches
                 * created traces in whether eflags are restored post-cmp
                 */
                uint next_flags = forward_eflags_analysis(dcontext, ilist,
                                                          instr_get_next(inst));
                next_flags = instr_eflags_to_fragment_eflags(next_flags);
                LOG(THREAD, LOG_INTERP, 4, "next_flags for fixup_last_cti: 0x%x\n",
                    next_flags);
                fixup_last_cti(dcontext, ilist, md->blk_info[blk+1].info.tag,
                               next_flags,
                               md->trace_flags, NULL, NULL,
                               TEST(FRAG_HAS_TRANSLATION_INFO, md->trace_flags),
                               &num_exits_deleted,
                               /* Only walk ilist between these instrs */
                               start_instr, inst);
#if defined(RETURN_AFTER_CALL) || defined(RCT_IND_BRANCH)
                md->blk_info[blk].info.num_exits -= num_exits_deleted;
#endif
            }
            blk++;
            if (blk >= md->num_blks && next_inst != NULL) {
                CLIENT_ASSERT(false, "unsupported trace modification: exits modified");
                return false;
            }
            start_instr = next_inst;
        }
    }
    if (blk < md->num_blks) {
        CLIENT_ASSERT(false, "unsupported trace modification: cannot find all exits");
        return false;
    }
    return true;
}

/****************************************************************************
 * UTILITIES
 */

/* Converts instr_t EFLAGS_ flags to corresponding fragment_t FRAG_ flags,
 * assuming that the instr_t flags correspond to the start of the fragment_t
 */
uint
instr_eflags_to_fragment_eflags(uint instr_eflags)
{
    uint frag_eflags = 0;
    if (instr_eflags == EFLAGS_WRITE_OF) {
        /* this fragment writes OF before reading it 
         * May still read other flags before writing them.
         */
        frag_eflags |= FRAG_WRITES_EFLAGS_OF;
    } else if (instr_eflags == EFLAGS_WRITE_6) {
        /* fragment writes all 6 prior to reading */
        frag_eflags |= FRAG_WRITES_EFLAGS_6;
        frag_eflags |= FRAG_WRITES_EFLAGS_OF;
    }
    return frag_eflags;
}

/* Returns one of these flags, defined in instr.h:
 *   EFLAGS_WRITE_6   = writes all 6 flags before reading any
 *   EFLAGS_WRITE_OF  = writes OF before reading it
 *   EFLAGS_READ_6    = reads some of 6 before writing
 *   EFLAGS_READ_OF   = reads OF before writing OF
 *   0                = no information before 1st cti
 */
uint
forward_eflags_analysis(dcontext_t *dcontext, instrlist_t *ilist, instr_t *instr)
{
    instr_t *in;
    uint eflags_6 = 0; /* holds flags written so far (in read slots) */
    int eflags_result = 0;
    for (in = instr; in != NULL; in = instr_get_next_expanded(dcontext, ilist, in)) {
        if (!instr_valid(in) || instr_is_cti(in)) {
            /* give up */
            break;
        }
        if (eflags_result != EFLAGS_WRITE_6 && eflags_result != EFLAGS_READ_OF)
            eflags_result = eflags_analysis(in, eflags_result, &eflags_6);
        DOLOG(4, LOG_INTERP, {
            loginst(dcontext, 4, in, "forward_eflags_analysis");
            LOG(THREAD, LOG_INTERP, 4, "\tinstr %x => %x\n",
                instr_get_eflags(in), eflags_result);
        });
    }
    return eflags_result;
}

/* This translates f's code into an instrlist_t and returns it.
 * If buf is NULL:
 *   The Instrs returned point into f's raw bits, so encode them 
 *   before you delete f!
 * Else, f's raw bits are copied into buf, and *bufsz is modified to
 *   contain the total bytes copied
 *   FIXME: should have release build checks and not just asserts where
 *   we rely on caller to have big-enough buffer?
 * If target_flags differ from f->flags in sharing and/or in trace-ness,
 *   converts ibl and tls usage in f to match the desired target_flags.  
 *   FIXME: converting from private to shared tls is not yet
 *   implemented: we rely on -private_ib_in_tls for adding normal
 *   private bbs to shared traces, and disallow any extensive mangling
 *   (native_exec, selfmod) from becoming shared traces.
 * The caller is responsible for destroying the instrlist and its instrs.
 * If the fragment ends in an elided jmp, a new jmp instr is created, though
 *   its bits field is NULL, allowing the caller to set it to do-not-emit if
 *   trying to exactly duplicate or calculate the size, though most callers
 *   will want to emit that jmp.  See decode_fragment_exact().
 */

/* We want to avoid low-loglevel disassembly when we're in the middle of disassembly */
#define DF_LOGLEVEL(dc) \
    (((dc) != GLOBAL_DCONTEXT && (dc)->in_opnd_disassemble) ? 6U : 4U)

instrlist_t *
decode_fragment(dcontext_t *dcontext, fragment_t *f, byte *buf, /*IN/OUT*/uint *bufsz,
                uint target_flags, /*OUT*/uint *dir_exits, /*OUT*/uint *indir_exits)
{
    linkstub_t  *l;
    cache_pc start_pc, stop_pc, pc, prev_pc = NULL, raw_start_pc;
    instr_t *instr, *cti = NULL, *raw_instr;
    instrlist_t *ilist = instrlist_create(dcontext);
    byte *top_buf = NULL, *cur_buf = NULL;
    app_pc target_tag;
    uint num_bytes, offset;
    uint num_dir = 0, num_indir = 0;
    bool tls_to_dc;
    bool shared_to_private =
        TEST(FRAG_SHARED, f->flags) && !TEST(FRAG_SHARED, target_flags);
#ifdef WINDOWS
    /* The fragment could contain an ignorable sysenter instruction if
     * the following conditions are satisfied. */
    bool possible_ignorable_sysenter = DYNAMO_OPTION(ignore_syscalls) &&
        (get_syscall_method() == SYSCALL_METHOD_SYSENTER) &&
        /* FIXME Traces don't have FRAG_HAS_SYSCALL set so we can't filter on
         * that flag for all fragments. We should propagate this flag from
         * a BB to a trace. */
        (TEST(FRAG_HAS_SYSCALL, f->flags) || TEST(FRAG_IS_TRACE, f->flags));
#endif
    instrlist_t intra_ctis;
    coarse_info_t *info = NULL;
    bool coarse_elided_ubrs = false;
#ifdef X64
    bool old_mode = get_x86_mode(dcontext);
    /* for decoding and get_ibl routines we need the dcontext mode set */
    set_x86_mode(dcontext, TEST(FRAG_32_BIT, f->flags));
#endif

    instrlist_init(&intra_ctis);

    /* Now we need to go through f and make cti's for each of its exit cti's and
     * non-exit cti's with off-fragment targets that need to be re-pc-relativized.
     * The rest of the instructions can be lumped into raw instructions.
     */
    start_pc = FCACHE_ENTRY_PC(f);
    pc = start_pc;
    raw_start_pc = start_pc;
    if (buf != NULL) {
        cur_buf = buf;
        top_buf = cur_buf;
        ASSERT(bufsz != NULL);
    }
    /* Handle code after last exit but before stubs by allowing l to be NULL.
     * Handle coarse-grain fake fragment_t by discovering exits as we go, with
     * l being NULL the whole time.
     */
    if (TEST(FRAG_FAKE, f->flags)) {
        ASSERT(TEST(FRAG_COARSE_GRAIN, f->flags));
        info = get_fragment_coarse_info(f);
        ASSERT(info != NULL);
        coarse_elided_ubrs =
            (info->persisted && TEST(PERSCACHE_ELIDED_UBR, info->flags))
            || (!info->persisted && DYNAMO_OPTION(coarse_freeze_elide_ubr));
        /* Assumption: coarse-grain fragments have no ctis w/ off-fragment targets
         * that are not exit ctis
         */
        l = NULL;
    } else
        l = FRAGMENT_EXIT_STUBS(f);
    while (true) {
        uint l_flags;
        cti = NULL;
        if (l != NULL) {
            stop_pc = EXIT_CTI_PC(f, l);
        } else if (TEST(FRAG_FAKE, f->flags)) {
            /* we don't know the size of f */
            stop_pc = (cache_pc) UNIVERSAL_REGION_END;
        } else {
            /* fake fragment_t, or code between last exit but before stubs or padding */
            stop_pc = fragment_body_end_pc(dcontext, f);
            if (PAD_FRAGMENT_JMPS(f->flags) && stop_pc != raw_start_pc) {
                /* We need to adjust stop_pc to account for any padding, only
                 * way any code could get here is via client interface,
                 * and there really is no nice way to distinguish it
                 * from any padding we added.
                 * PR 213005: we do not support decode_fragment() for bbs
                 * that have code added beyond the last exit cti (we turn
                 * off FRAG_COARSE_GRAIN and set FRAG_CANNOT_BE_TRACE).
                 * Sanity check, make sure it at least looks like there is no
                 * code here */
                ASSERT(IS_SET_TO_DEBUG(raw_start_pc, stop_pc - raw_start_pc)); 
                stop_pc = raw_start_pc;
            }
        }
        IF_X64(ASSERT(TEST(FRAG_FAKE, f->flags) /* no copy made */ ||
                      CHECK_TRUNCATE_TYPE_uint((stop_pc - raw_start_pc))));
        num_bytes = (uint) (stop_pc - raw_start_pc);
        LOG(THREAD, LOG_MONITOR, DF_LOGLEVEL(dcontext),
            "decoding fragment from "PFX" to "PFX"\n", raw_start_pc, stop_pc);
        if (num_bytes > 0) {
            if (buf != NULL) {
                if (TEST(FRAG_FAKE, f->flags)) {
                    /* we don't know the size of f, so we copy later, though
                     * we do point instrs into buf before we copy!
                     */
                } else {
                    /* first copy entire sequence up to exit cti into buf
                     * so we don't have to copy it in pieces if we find cti's, if we don't
                     * find any we want one giant piece anyway
                     */
                    ASSERT(cur_buf + num_bytes < buf + *bufsz);
                    memcpy(cur_buf, raw_start_pc, num_bytes);
                    top_buf = cur_buf + num_bytes;
                    LOG(THREAD, LOG_MONITOR, DF_LOGLEVEL(dcontext),
                        "decode_fragment: copied "PFX"-"PFX" to "PFX"-"PFX"\n",
                        raw_start_pc, raw_start_pc + num_bytes, cur_buf,
                        cur_buf + num_bytes);
                    /* cur_buf is incremented later -- it always points to start
                     * of raw bytes for next-to-add-to-ilist instr, while
                     * top_buf points to top of copied-to-buf data
                     */
                }
            } else {
                /* point at bits in code cache */
                cur_buf = raw_start_pc;
            }
            /* now, we can't make a single raw instr for all that, there may
             * be calls with off-fragment targets in there that need to be
             * re-pc-relativized (instrumentation, etc. insert calls), or
             * we may not even know where the exit ctis are (coarse-grain fragments),
             * so walk through (original bytes!) and decode, looking for cti's
             */
            instr = instr_create(dcontext);
            pc = raw_start_pc;
            /* do we have to translate the store of xcx from tls to dcontext? 
             * be careful -- there can be private bbs w/ indirect branches, so
             * must see if this is a shared fragment we're adding
             */
            tls_to_dc = (shared_to_private && !DYNAMO_OPTION(private_ib_in_tls) &&
                         /* if l==NULL (coarse src) we'll check for xcx every time */
                         (l == NULL || LINKSTUB_INDIRECT(l->flags)));
            do {
#ifdef WINDOWS
                cache_pc prev_decode_pc = prev_pc; /* store the address of the
                                                    * previous decode, the instr
                                                    * before the one 'pc'
                                                    * currently points to *before*
                                                    * the call to decode() just
                                                    * below */
#endif
                /* For frozen coarse fragments, ubr eliding forces us to check
                 * every instr for a potential next fragment start.  This is
                 * expensive so users are advised to decode from app code if
                 * possible (case 9325 -- need exact re-mangle + re-instrument),
                 * though -coarse_pclookup_table helps.
                 */
                if (info != NULL && info->frozen &&
                    coarse_elided_ubrs && pc != start_pc) {
                    /* case 6532: check for ib stubs as we elide the jmp there too */
                    bool stop = false;
                    if (coarse_is_indirect_stub(pc)) {
                        stop = true;
                        LOG(THREAD, LOG_MONITOR, DF_LOGLEVEL(dcontext)-1,
                            "\thit ib stub @"PFX"\n", pc);
                    } else {
                        app_pc tag = fragment_coarse_entry_pclookup(dcontext, info, pc);
                        if (tag != NULL) {
                            stop = true;
                            LOG(THREAD, LOG_MONITOR, DF_LOGLEVEL(dcontext)-1,
                                "\thit frozen tgt: "PFX"."PFX"\n", tag, pc);
                        }
                    }
                    if (stop) {
                        /* Add the ubr ourselves */
                        ASSERT(cti == NULL);
                        cti = INSTR_CREATE_jmp(dcontext, opnd_create_pc(pc));
                        /* It's up to the caller to decide whether to mark this
                         * as do-not-emit or not */
                        /* Process as an exit cti */
                        stop_pc = pc;
                        pc = stop_pc;
                        break;
                    }
                }
                instr_reset(dcontext, instr);
                prev_pc = pc;
                pc = decode_cti(dcontext, pc, instr);
#ifdef WINDOWS
                /* Perform fixups for ignorable syscalls on XP & 2003. */
                if (possible_ignorable_sysenter
                    && instr_opcode_valid(instr)
                    && instr_is_syscall(instr)) {

                    /* We want to find the instr preceding the sysenter and have
                     * it point to the post-sysenter instr in the trace, rather than
                     * remain pointing to the post-sysenter instr in the BB.
                     */
                    instr_t *sysenter_prev;
                    instr_t *sysenter_post;

                    ASSERT(prev_decode_pc != NULL);
                    LOG(THREAD, LOG_MONITOR, DF_LOGLEVEL(dcontext),
                        "decode_fragment: sysenter found @"PFX"\n",
                        instr_get_raw_bits(instr));

                    /* create single raw instr for instructions up to the
                     * sysenter EXCEPT for the immediately preceding instruction
                     */
                    offset = (int)(prev_decode_pc - raw_start_pc);
                    ASSERT(offset > 0);
                    raw_instr = instr_create(dcontext);
                    /* point to buffer bits */
                    instr_set_raw_bits(raw_instr, cur_buf, offset);
                    instrlist_append(ilist, raw_instr);
                    cur_buf += offset;

                    /* Get the "mov" instr just before the sysenter. We know that
                     * it's there because mangle put it there, so we can safely
                     * decode at prev_decode_pc.
                     */
                    sysenter_prev = instr_create(dcontext);
                    decode(dcontext, prev_decode_pc, sysenter_prev);
                    ASSERT(instr_valid(instr) &&
                           instr_is_mov_imm_to_tos(sysenter_prev));
                    instrlist_append(ilist, sysenter_prev);
                    cur_buf += instr_length(dcontext, sysenter_prev);

                    /* Append the sysenter. */
                    instr_set_raw_bits(instr, cur_buf, (int)(pc - prev_pc));
                    instrlist_append(ilist, instr);
                    instr_set_ok_to_mangle(instr, false);

                    /* skip current instr -- the sysenter */
                    cur_buf += (int)(pc - prev_pc);

                    /* Decode the next instr -- the one after the sysenter. */
                    sysenter_post = instr_create(dcontext);
                    prev_decode_pc = pc;
                    prev_pc = pc;
                    pc = decode(dcontext, pc, sysenter_post);
                    if (DYNAMO_OPTION(ignore_syscalls_follow_sysenter))
                        ASSERT(!instr_is_cti(sysenter_post));
                    raw_start_pc = pc;

                    /* skip the post-sysenter instr */
                    cur_buf += (int)(pc - prev_pc);

                    instrlist_append(ilist, sysenter_post);
                    /* Point the pre-sysenter mov to the post-sysenter instr. */
                    instr_set_src(sysenter_prev, 0,
                                  opnd_create_instr(sysenter_post));
                    instr_set_ok_to_mangle(sysenter_prev, false);
                    instr_set_ok_to_mangle(sysenter_post, false);

                    DOLOG(DF_LOGLEVEL(dcontext), LOG_INTERP, {
                        LOG(THREAD, LOG_INTERP, DF_LOGLEVEL(dcontext),
                            "Post-sysenter -- F%d ("PFX") into:\n", f->id, f->tag);
                        instrlist_disassemble(dcontext, f->tag, ilist, THREAD);
                    });

                    /* Set all local state so that we can fall-thru and correctly
                     * process the post-sysenter instruction. Point instr to the
                     * already decoded instruction, sysenter_post. At this point,
                     * pc and raw_start_pc point to just after sysenter_post,
                     * prev_pc points to sysenter_post, prev_decode_pc points to
                     * the sysenter itself, and cur_buf points to post_sysenter.
                     */
                    instr = sysenter_post;
                }
#endif
                /* look for a cti with an off-fragment target */
                if (instr_opcode_valid(instr) && instr_is_cti(instr)) {
                    bool separate_cti = false;
                    bool re_relativize = false;
                    DOLOG(DF_LOGLEVEL(dcontext), LOG_MONITOR, {
                        loginst(dcontext, 4, instr, "decode_fragment: found non-exit cti");
                    });
                    if (TEST(FRAG_FAKE, f->flags)) {
                        /* Case 8711: we don't know the size so we can't even
                         * distinguish off-fragment from intra-fragment targets.
                         * Thus we have to assume that any cti is an exit cti, and
                         * make all fragments for which that is not true into
                         * fine-grained.
                         */
                        /* Process this cti as an exit cti.  FIXME: we will then
                         * re-copy the raw bytes from this cti to the end of the
                         * fragment at the top of the next loop iter, but for
                         * coarse-grain bbs that should be just one instr for cbr bbs
                         * or none for others, so not worth doing anything about.
                         */
                        stop_pc = prev_pc;
                        pc = stop_pc;
                        break;
                    }
                    if (instr_is_return(instr) ||
                        !opnd_is_near_pc(instr_get_target(instr))) {
                        /* just leave it undecoded */
#ifdef NATIVE_RETURN
                        /* need to be able to find ret for fixup_last_cti */
                        if (instr_is_return(instr))
                            separate_cti = true;
#endif
                    } else if (instr_is_cti_short_rewrite(instr, prev_pc)) {
                        /* Cti-short should only occur as exit ctis, which are
                         * separated out unless we're decoding a fake fragment.  We
                         * include this case for future use, as otherwise we'll
                         * decode just the short cti and think it is an
                         * intra-fragment cti.
                         */
                        ASSERT_NOT_REACHED();
                        separate_cti = true;
                        re_relativize = true;
                    } else if (opnd_get_pc(instr_get_target(instr)) < start_pc ||
                               opnd_get_pc(instr_get_target(instr)) > start_pc+f->size) {
                        separate_cti = true;
                        re_relativize = true;
                        DOLOG(DF_LOGLEVEL(dcontext), LOG_MONITOR, {
                            loginst(dcontext, 4, instr, "\tcti has off-fragment target");
                        });
                    } else {
                        /* intra-fragment target: we'll change its target operand
                         * from pc to instr_t in second pass, so remember it here
                         */
                        instr_t *clone = instr_clone(dcontext, instr);
                        /* HACK: use note field! */
                        instr_set_note(clone, (void *) instr);
                        /* we leave the clone pointing at valid original raw bits */
                        instrlist_append(&intra_ctis, clone);
                        /* intra-fragment target */
                        DOLOG(DF_LOGLEVEL(dcontext), LOG_MONITOR, {
                            loginst(dcontext, 4, instr, "\tcti has intra-fragment target");
                        });
#ifdef NATIVE_RETURN
                        if (instr_is_call(instr)) {
                            /* assume it's an application call! */
                            dcontext->num_calls_in_trace++;
                        }
#endif
                        /* since the resulting instrlist could be manipulated,
                         * we need to change the target operand from pc to instr_t.
                         * that requires having this instr separated out now so
                         * our clone-in-note-field hack above works.
                         */
                        separate_cti = true;
                        re_relativize = false;
                    }
                    if (separate_cti) {
                        /* create single raw instr for instructions up to the cti */
                        offset = (int)(prev_pc - raw_start_pc);
                        if (offset > 0) {
                            raw_instr = instr_create(dcontext);
                            /* point to buffer bits */
                            instr_set_raw_bits(raw_instr, cur_buf, offset);
                            instrlist_append(ilist, raw_instr);
                            cur_buf += offset;
                            raw_start_pc = prev_pc;
                        }
                        /* now append cti, indicating that relative target must be
                         * re-encoded, and that it is not an exit cti
                         */
                        instr_set_ok_to_mangle(instr, false);
                        if (re_relativize)
                            instr_set_raw_bits_valid(instr, false);
                        else
                            instr_set_raw_bits(instr, cur_buf, (int)(pc - prev_pc));
                        instrlist_append(ilist, instr);
                        /* include buf for off-fragment cti, to simplify assert below */
                        cur_buf += (int)(pc - prev_pc);
                        raw_start_pc = pc;
                        /* create new instr for future fast decodes */
                        instr = instr_create(dcontext);
                    }
                } /* is cti */
                /* instr_is_tls_xcx_spill won't upgrade from level 1 */
                else if (tls_to_dc && instr_is_tls_xcx_spill(instr)) {
                    /* shouldn't get here for x64, where everything uses tls */
                    IF_X64(ASSERT_NOT_IMPLEMENTED(false));
                    LOG(THREAD, LOG_MONITOR, DF_LOGLEVEL(dcontext),
                        "mangling xcx save from tls to dcontext\n");
                    /* create single raw instr for instructions up to the xcx save */
                    offset = (int)(prev_pc - raw_start_pc);
                    if (offset > 0) {
                        raw_instr = instr_create(dcontext);
                        /* point to buffer bits */
                        instr_set_raw_bits(raw_instr, cur_buf, offset);
                        instrlist_append(ilist, raw_instr);
                        cur_buf += offset;
                        raw_start_pc = prev_pc;
                    }
                    /* now append our new xcx save */
                    instrlist_append(ilist,
                                     instr_create_save_to_dcontext
                                     (dcontext, REG_XCX, XCX_OFFSET));
                    /* make sure skip current instr */
                    cur_buf += (int)(pc - prev_pc);
                    raw_start_pc = pc;
                }
#ifdef X64
                else if (instr_has_rel_addr_reference(instr)) {
                    /* We need to re-relativize, which is done automatically only for
                     * level 1 instrs (PR 251479), and only when raw bits point to
                     * their original location.  We assume that all the if statements
                     * above end up creating a high-level instr, so a cti w/ a
                     * rip-rel operand is already covered.
                     */
                    /* create single raw instr for instructions up to this one */
                    offset = (int)(prev_pc - raw_start_pc);
                    if (offset > 0) {
                        raw_instr = instr_create(dcontext);
                        /* point to buffer bits */
                        instr_set_raw_bits(raw_instr, cur_buf, offset);
                        instrlist_append(ilist, raw_instr);
                        cur_buf += offset;
                        raw_start_pc = prev_pc;
                    }
                    /* should be valid right now since pointing at original bits */
                    ASSERT(instr_rip_rel_valid(instr));
                    if (buf != NULL) {
                        /* re-relativize into the new buffer */
                        DEBUG_DECLARE(byte *nxt =)
                            instr_encode(dcontext, instr, cur_buf);
                        instr_set_raw_bits(instr, cur_buf, (int)(pc - prev_pc));
                        instr_set_rip_rel_valid(instr, true);
                        ASSERT(nxt != NULL);
                    }
                    instrlist_append(ilist, instr);
                    cur_buf += (int)(pc - prev_pc);
                    raw_start_pc = pc;
                    /* create new instr for future fast decodes */
                    instr = instr_create(dcontext);
                }
#endif
            } while (pc < stop_pc);
            DODEBUG({
                if (pc != stop_pc) {
                    LOG(THREAD, LOG_MONITOR, DF_LOGLEVEL(dcontext),
                        "PC "PFX", stop_pc "PFX"\n", pc, stop_pc);
                }
            });
            ASSERT(pc == stop_pc);

            /* create single raw instr for rest of instructions up to exit cti */
            if (pc > raw_start_pc) {
                instr_reset(dcontext, instr);
                /* point to buffer bits */
                offset = (int)(pc - raw_start_pc);
                if (offset > 0) {
                    instr_set_raw_bits(instr, cur_buf, offset);
                    instrlist_append(ilist, instr);
                    cur_buf += offset;
                }
                if (buf != NULL && TEST(FRAG_FAKE, f->flags)) {
                    /* Now that we know the size we can copy into buf.
                     * We have been incrementing cur_buf all along, though
                     * we didn't have contents there.
                     */
                    ASSERT(top_buf < cur_buf);
                    IF_X64(ASSERT(CHECK_TRUNCATE_TYPE_uint((cur_buf - top_buf))));
                    num_bytes = (uint) (cur_buf - top_buf);
                    ASSERT(cur_buf + num_bytes < buf + *bufsz);
                    memcpy(cur_buf, raw_start_pc, num_bytes);
                    top_buf = cur_buf + num_bytes;
                    LOG(THREAD, LOG_MONITOR, DF_LOGLEVEL(dcontext),
                        "decode_fragment: copied "PFX"-"PFX" to "PFX"-"PFX"\n",
                        raw_start_pc, raw_start_pc + num_bytes, cur_buf,
                        cur_buf + num_bytes);
                }
                ASSERT(buf == NULL || cur_buf == top_buf);
            } else {
                /* will reach here if had a processed instr (off-fragment target, etc.)
                 * immediately prior to exit cti, so now don't need instr -- an
                 * example (in absence of clients) is trampoline to interception code
                 */
                instr_destroy(dcontext, instr);
            }
        }

        if (l == NULL && !TEST(FRAG_FAKE, f->flags))
            break;

        /* decode the exit branch */
        if (cti != NULL) {
            /* already created */
            instr = cti;
            ASSERT(info != NULL && info->frozen && instr_is_ubr(instr));
            raw_start_pc = pc;
        } else {
            instr = instr_create(dcontext);
            raw_start_pc = decode(dcontext, stop_pc, instr);
            ASSERT(raw_start_pc != NULL); /* our own code! */
            /* pc now points into fragment! */
        }
        ASSERT(instr_is_ubr(instr) || instr_is_cbr(instr));
        /* replace fcache target with target_tag and add to fragment */
        if (l == NULL) {
            app_pc instr_tgt;
            /* Ensure we get proper target for short cti sequence */
            if (instr_is_cti_short_rewrite(instr, stop_pc))
                remangle_short_rewrite(dcontext, instr, stop_pc, 0/*same target*/);
            instr_tgt = opnd_get_pc(instr_get_target(instr));
            ASSERT(TEST(FRAG_COARSE_GRAIN, f->flags));
            if (cti == NULL && coarse_is_entrance_stub(instr_tgt)) {
                target_tag = entrance_stub_target_tag(instr_tgt);
                l_flags = LINK_DIRECT;
                /* FIXME; try to get LINK_JMP vs LINK_CALL vs fall-through? */
                LOG(THREAD, LOG_MONITOR, DF_LOGLEVEL(dcontext)-1,
                    "\tstub tgt: "PFX" => "PFX"\n", instr_tgt, target_tag);
            } else if (instr_tgt == raw_start_pc /*target next instr*/
                       /* could optimize by not checking for stub if
                        * coarse_elided_ubrs but we need to know whether ALL
                        * ubrs were elided, which we don't know as normally
                        * entire-bb-ubrs are not elided (case 9677).
                        * plus now that we elide jmp-to-ib-stub we must check.
                        */
                       && coarse_is_indirect_stub(instr_tgt)) {
                ibl_type_t ibl_type;
                DEBUG_DECLARE(bool is_ibl;)
                target_tag = coarse_indirect_stub_jmp_target(instr_tgt);
                l_flags = LINK_INDIRECT;
                DEBUG_DECLARE(is_ibl = )
                    get_ibl_routine_type_ex(dcontext, target_tag, &ibl_type
                                            _IF_X64(NULL));
                ASSERT(is_ibl);
                l_flags |= ibltype_to_linktype(ibl_type.branch_type);
                LOG(THREAD, LOG_MONITOR, DF_LOGLEVEL(dcontext)-1,
                    "\tind stub tgt: "PFX" => "PFX"\n", instr_tgt, target_tag);
            } else {
                target_tag = fragment_coarse_entry_pclookup(dcontext, info, instr_tgt);
                /* Only frozen units don't jump through stubs */
                ASSERT(info != NULL && info->frozen);
                ASSERT(target_tag != NULL);
                l_flags = LINK_DIRECT;
                LOG(THREAD, LOG_MONITOR, DF_LOGLEVEL(dcontext)-1,
                    "\tfrozen tgt: "PFX"."PFX"\n", target_tag, instr_tgt);
            }
        } else {
            target_tag = EXIT_TARGET_TAG(dcontext, f, l);
            l_flags = l->flags;
        }
        if (LINKSTUB_DIRECT(l_flags))
            num_dir++;
        else
            num_indir++;
        ASSERT(target_tag != NULL);
        if (instr_is_cti_short_rewrite(instr, stop_pc)) {
            raw_start_pc = remangle_short_rewrite(dcontext, instr, stop_pc, target_tag);
        } else {
            app_pc new_target = target_tag;
            /* don't point to fcache bits */
            instr_set_raw_bits_valid(instr, false);
            LOG(THREAD, LOG_MONITOR, DF_LOGLEVEL(dcontext)-1,
                "decode_fragment exit_cti: pc="PFX" l->target_tag="PFX" l->flags=0x%x\n",
                stop_pc, target_tag, l_flags);

            /* need to propagate exit branch type flags, 
             * instr_t flag copied from old fragment linkstub
             * TODO: when ibl targets are different this won't be necessary 
             */
            instr_exit_branch_set_type(instr, linkstub_propagatable_flags(l_flags));

            /* convert to proper ibl */
            if (is_indirect_branch_lookup_routine(dcontext, target_tag)) {
                DEBUG_DECLARE(app_pc old_target = new_target;)
                new_target = get_alternate_ibl_routine(dcontext, target_tag,
                                                       target_flags);
                ASSERT(new_target != NULL);

                /* for stats on traces, we assume if target_flags contains
                 * FRAG_IS_TRACE then we are extending a trace
                 */
                DODEBUG({
                    LOG(THREAD, LOG_MONITOR, DF_LOGLEVEL(dcontext)-1,
                        "%s: %s ibl_routine "PFX" with %s_target="PFX"\n",
                        TEST(FRAG_IS_TRACE, target_flags) ? 
                        "extend_trace" : "decode_fragment",
                        new_target == old_target ? "maintaining" : "replacing",
                        old_target, new_target == old_target ? "old" : "new", new_target);
                    STATS_INC(num_traces_ibl_extended);
                });
#ifdef WINDOWS
                DOSTATS({
                    if (TEST(FRAG_IS_TRACE, target_flags) &&
                        old_target == shared_syscall_routine(dcontext))
                        STATS_INC(num_traces_shared_syscall_extended);
                });
#endif
            }     

            instr_set_target(instr, opnd_create_pc(new_target));

            if (instr_is_cti_short(instr)) {
                /* make sure non-mangled short ctis, which are generated by
                 * us and never left there from apps, are not marked as exit ctis
                 */
                instr_set_ok_to_mangle(instr, false);
            }
        }
        instrlist_append(ilist, instr);
#ifdef CUSTOM_EXIT_STUBS
        if (l != NULL && l->fixed_stub_offset > 0)
            regenerate_custom_exit_stub(dcontext, instr, l, f);
#endif

        if (TEST(FRAG_FAKE, f->flags)) {
            /* Assumption: coarse-grain bbs have 1 ind exit or 2 direct,
             * and no code beyond the last exit!  Of course frozen bbs
             * can have their final jmp elided, which we handle above.
             */
            if (instr_is_ubr(instr)) {
                break;
            }
        }
        if (l != NULL) /* if NULL keep going: discovering exits as we go */
            l = LINKSTUB_NEXT_EXIT(l);
    } /* end while(true) loop through exit stubs */

    /* now fix up intra-trace cti targets */
    if (instrlist_first(&intra_ctis) != NULL) {
        /* We have to undo all of our level 0 blocks by expanding.
         * Any instrs that need re-relativization should already be
         * separate, so this should not affect rip-rel instrs.           
         */
        int offs = 0;
        for (instr = instrlist_first_expanded(dcontext, ilist); instr != NULL;
             instr = instr_get_next_expanded(dcontext, ilist, instr)) {
            for (cti = instrlist_first(&intra_ctis); cti != NULL;
                 cti = instr_get_next(cti)) {
                /* The clone we put in intra_ctis has raw bits equal to the
                 * original bits, so its target will be in original fragment body.
                 * We can't rely on the raw bits of the new instrs (since the
                 * non-level-0 ones may have allocated raw bits) so we
                 * calculate a running offset as we go.
                 */
                if (opnd_get_pc(instr_get_target(cti)) - start_pc == offs) {
                    /* cti targets this instr */
                    instr_t *real_cti = (instr_t *) instr_get_note(cti);
                    /* PR 333691: do not preserve raw bits of real_cti, since
                     * instrlist may change (e.g., inserted nops).  Must re-encode
                     * once instrlist is finalized.
                     */
                    instr_set_target(real_cti, opnd_create_instr(instr));
                    DOLOG(DF_LOGLEVEL(dcontext), LOG_MONITOR, {
                        loginst(dcontext, 4, real_cti, "\tre-set intra-fragment target");
                    });
                    break;
                }
            }
            offs += instr_length(dcontext, instr);
        }
    }

    instrlist_clear(dcontext,&intra_ctis);
    DOLOG(DF_LOGLEVEL(dcontext), LOG_INTERP, {
        LOG(THREAD, LOG_INTERP, DF_LOGLEVEL(dcontext),
            "Decoded F%d ("PFX"."PFX") into:\n",
            f->id, f->tag, FCACHE_ENTRY_PC(f));
        instrlist_disassemble(dcontext, f->tag, ilist, THREAD);
    });

#ifdef X64
    set_x86_mode(dcontext, old_mode);
#endif

    if (dir_exits != NULL)
        *dir_exits = num_dir;
    if (indir_exits != NULL)
        *indir_exits = num_indir;
    if (buf != NULL) {
        IF_X64(ASSERT(CHECK_TRUNCATE_TYPE_uint((top_buf - buf))));
        *bufsz = (uint) (top_buf - buf);
    }
    return ilist;
}
#undef DF_LOGLEVEL

/* Just like decode_fragment() but marks any instrs missing in the cache
 * as do-not-emit
 */
instrlist_t *
decode_fragment_exact(dcontext_t *dcontext, fragment_t *f, byte *buf,
                      /*IN/OUT*/uint *bufsz, uint target_flags,
                      /*OUT*/uint *dir_exits, /*OUT*/uint *indir_exits)
{
    instrlist_t *ilist =
        decode_fragment(dcontext, f, buf, bufsz, target_flags, dir_exits, indir_exits);
    /* If the final jmp was elided we do NOT want to count it in the size! */
    if (instr_get_raw_bits(instrlist_last(ilist)) == NULL) {
        instr_set_ok_to_emit(instrlist_last(ilist), false);
    }
    return ilist;
}

/* Makes a new copy of fragment f
 * If replace is true,
 *   removes f from the fcache and adds the new copy in its place
 * Else
 *   creates f as an invisible fragment (caller is responsible for linking
 *   the new fragment!)
 */
fragment_t *
copy_fragment(dcontext_t *dcontext, fragment_t *f, bool replace)
{
    instrlist_t *trace = instrlist_create(dcontext);
    instr_t     *instr;
    uint    *trace_buf;
    int       trace_buf_top; /* index of next free location in trace_buf */
    linkstub_t  *l;
    byte *p;
    cache_pc  start_pc;
    int       num_bytes;
    fragment_t  *new_f;
    void      *vmlist = NULL;
    app_pc    target_tag;
    DEBUG_DECLARE(bool ok;)

    trace_buf = heap_alloc(dcontext, f->size*2 HEAPACCT(ACCT_FRAGMENT));

    start_pc = FCACHE_ENTRY_PC(f);
    trace_buf_top = 0;
    p = ((byte *)trace_buf) + trace_buf_top;

    IF_X64(ASSERT_NOT_IMPLEMENTED(false)); /* must re-relativize when copying! */

    for (l = FRAGMENT_EXIT_STUBS(f); l; l = LINKSTUB_NEXT_EXIT(l)) {
        /* Copy the instruction bytes up to (but not including) the first
         * control-transfer instruction.  ***WARNING*** This code assumes
         * that the first link stub corresponds to the first exit branch
         * in the body. */
        IF_X64(ASSERT(CHECK_TRUNCATE_TYPE_uint((EXIT_CTI_PC(f, l) - start_pc))));
        num_bytes = (uint) (EXIT_CTI_PC(f, l) - start_pc);
        if (num_bytes > 0) {
            memcpy(p, (byte *)start_pc, num_bytes);
            trace_buf_top += num_bytes;
            start_pc += num_bytes;

            /* build a mongo instruction corresponding to the copied instructions */
            instr = instr_create(dcontext);
            instr_set_raw_bits(instr, p, num_bytes);
            instrlist_append(trace, instr);
        }

        /* decode the exit branch */
        instr = instr_create(dcontext);
        p = decode(dcontext, (byte *)EXIT_CTI_PC(f, l), instr);
        ASSERT(p != NULL); /* our own code! */
        /* p now points into fragment! */
        ASSERT(instr_is_ubr(instr) || instr_is_cbr(instr));
        /* Replace cache_pc target with target_tag and add to trace.  For
         * an indirect branch, the target_tag is zero. */
        target_tag = EXIT_TARGET_TAG(dcontext, f, l);
        ASSERT(target_tag);
        if (instr_is_cti_short_rewrite(instr, EXIT_CTI_PC(f, l))) {
            p = remangle_short_rewrite(dcontext, instr,
                                       EXIT_CTI_PC(f, l),
                                       target_tag);
        } else {
            /* no short ctis that aren't mangled should be exit ctis */
            ASSERT(!instr_is_cti_short(instr));
            instr_set_target(instr, opnd_create_pc(target_tag));
        }
        instrlist_append(trace, instr);
        start_pc += (p - (byte *)EXIT_CTI_PC(f, l));
    }

    /* emit as invisible fragment */
    /* We don't support shared fragments, where vm_area_add_to_list can fail */
    ASSERT_NOT_IMPLEMENTED(!TEST(FRAG_SHARED, f->flags));
    DEBUG_DECLARE(ok =)
        vm_area_add_to_list(dcontext, f->tag, &vmlist, f->flags, f, false/*no locks*/);
    ASSERT(ok); /* should never fail for private fragments */
    new_f = emit_invisible_fragment(dcontext, f->tag, trace, f->flags, vmlist);
    if (replace) {
        /* link and replace old fragment */
        shift_links_to_new_fragment(dcontext, f, new_f);
        fragment_replace(dcontext, f, new_f);
    } else {
        /* caller is responsible for linking new fragment */
    }

    ASSERT(new_f->flags == f->flags);

    fragment_copy_data_fields(dcontext, f, new_f);

#ifdef DEBUG
    if (stats->loglevel > 1) {
        LOG(THREAD, LOG_ALL, 2, "Copying F%d to F%d\n", f->id, new_f->id);
        disassemble_fragment(dcontext, f, stats->loglevel < 3);
        disassemble_fragment(dcontext, new_f, stats->loglevel < 3);
    }
#endif /* DEBUG */

    heap_free(dcontext, trace_buf, f->size*2 HEAPACCT(ACCT_FRAGMENT));
    /* free the instrlist_t elements */
    instrlist_clear_and_destroy(dcontext, trace);
    if (replace) {
        fragment_delete(dcontext, f, FRAGDEL_NO_OUTPUT | FRAGDEL_NO_UNLINK |
                        FRAGDEL_NO_HTABLE);
        STATS_INC(num_fragments_deleted_copy_and_replace);
    }
    return new_f;
}

/* Used when the code cache is enlarged by copying to a larger space,
 * and all of the relative ctis that target outside the cache need
 * to be shifted. Additionally, sysenter-related patching for ignore-syscalls
 * on XP/2003 is performed here, as the absolute code cache address pushed
 * onto the stack must be updated.
 * Assumption: old code cache has been copied to TOP of new cache, so to
 * detect for ctis targeting outside of old cache can look at new cache
 * start plus old cache size.
 */
void
shift_ctis_in_fragment(dcontext_t *dcontext, fragment_t *f, ssize_t shift,
                       cache_pc fcache_start, cache_pc fcache_end,
                       size_t old_size)
{
    cache_pc pc, prev_pc = NULL;
    cache_pc start_pc = FCACHE_ENTRY_PC(f);
    cache_pc stop_pc = fragment_stubs_end_pc(f);
    /* get what would have been end of cache if just shifted not resized */
    cache_pc fcache_old_end = fcache_start + old_size;
#ifdef WINDOWS
    /* The fragment could contain an ignorable sysenter instruction if
     * the following conditions are satisfied. */
    bool possible_ignorable_sysenter = DYNAMO_OPTION(ignore_syscalls) &&
        (get_syscall_method() == SYSCALL_METHOD_SYSENTER) &&
        /* FIXME Traces don't have FRAG_HAS_SYSCALL set so we can't filter on
         * that flag for all fragments. */
        (TEST(FRAG_HAS_SYSCALL, f->flags) || TEST(FRAG_IS_TRACE, f->flags));
#endif
    instr_t instr;
    instr_init(dcontext, &instr);

    pc = start_pc;
    while (pc < stop_pc) {
#ifdef WINDOWS
        cache_pc prev_decode_pc = prev_pc; /* store the address of the
                                            * previous decode, the instr
                                            * before the one 'pc'
                                            * currently points to *before*
                                            * the call to decode_cti() just
                                            * below */
#endif
        prev_pc = pc;
        instr_reset(dcontext, &instr);
        pc = (cache_pc) decode_cti(dcontext, (byte*)pc, &instr);
#ifdef WINDOWS
        /* Perform fixups for sysenter instrs when ignorable syscalls is used on
         * XP & 2003. These are not cache-external fixups, but it's convenient &
         * efficient to perform them here since decode_cti() is called on every
         * instruction, allowing identification of sysenters without additional
         * decoding.
         */
        if (possible_ignorable_sysenter
            && instr_opcode_valid(&instr)
            && instr_is_syscall(&instr)) {

            cache_pc next_pc;
            app_pc target;
            DEBUG_DECLARE(app_pc old_target;)
            DEBUG_DECLARE(cache_pc encode_nxt;)

            /* Peek up to find the "mov $post-sysenter -> (%xsp)" */
            instr_reset(dcontext, &instr);
            next_pc = decode(dcontext, prev_decode_pc, &instr);
            ASSERT(next_pc == prev_pc);
            LOG(THREAD, LOG_MONITOR, 4,
                "shift_ctis_in_fragment: pre-sysenter mov found @"PFX"\n",
                instr_get_raw_bits(&instr));
            ASSERT(instr_is_mov_imm_to_tos(&instr));
            target = instr_get_raw_bits(&instr) + instr_length(dcontext, &instr)
                + (pc - prev_pc);
            DODEBUG(old_target = (app_pc) opnd_get_immed_int(instr_get_src(&instr, 0)););
            /* PR 253943: we don't support sysenter in x64 */
            IF_X64(ASSERT_NOT_IMPLEMENTED(false)); /* can't have 8-byte imm-to-mem */
            instr_set_src(&instr, 0, opnd_create_immed_int((ptr_int_t)target, OPSZ_4));
            ASSERT(old_target + shift == target);
            LOG(THREAD, LOG_MONITOR, 4,
                "shift_ctis_in_fragment: pre-sysenter mov now pts to @"PFX"\n",
                target);
            DEBUG_DECLARE(encode_nxt = ) instr_encode(dcontext, &instr, prev_decode_pc);
            /* must not change size! */
            ASSERT(encode_nxt != NULL && encode_nxt == next_pc);
        }
        /* The following 'if' won't get executed since a sysenter isn't
         * a CTI instr, so we don't need an else. We do need to take care
         * that any 'else' clauses are added after the 'if' won't trigger
         * on a sysenter either.
         */
#endif
        /* look for a pc-relative cti (including exit ctis) w/ out-of-cache
         * target (anything in-cache is fine, the whole cache was moved)
         */
        if (instr_is_cti(&instr) &&
            /* only ret, ret_far, and iret don't have targets, and
             * we really shouldn't see them, except possibly if they
             * are inserted through instrumentation, so go ahead and
             * check num srcs
             */
            instr_num_srcs(&instr) > 0 &&
            opnd_is_near_pc(instr_get_target(&instr))) {
            app_pc target = opnd_get_pc(instr_get_target(&instr));
            if (target < fcache_start || target > fcache_old_end) {
                DEBUG_DECLARE(byte *nxt_pc;)
                /* re-encode instr w/ new pc-relative target */
                instr_set_raw_bits_valid(&instr, false);
                instr_set_target(&instr, opnd_create_pc(target - shift));
                DEBUG_DECLARE(nxt_pc = ) instr_encode(dcontext, &instr, prev_pc);
                /* must not change size! */
                ASSERT(nxt_pc != NULL && nxt_pc == pc);
#ifdef DEBUG
                if ((stats->logmask & LOG_CACHE) != 0) {
                    loginst(dcontext, 5, &instr,
                            "shift_ctis_in_fragment: found cti w/ out-of-cache target");
                }
#endif
            }
        }
    }
    instr_free(dcontext, &instr);
}

#ifdef PROFILE_RDTSC
/* Add profile call to front of the trace in dc
 * Must call finalize_profile_call and pass it the fragment_t*
 * once the trace is turned into a fragment to fix up a few profile
 * call instructions.
 */
void
add_profile_call(dcontext_t *dcontext)
{
    monitor_data_t *md = (monitor_data_t *) dcontext->monitor_field;
    instrlist_t *trace = &(md->trace);
    byte *p = ((byte *)md->trace_buf) + md->trace_buf_top;
    instr_t *instr;
    uint num_bytes = profile_call_size();
    ASSERT(num_bytes + md->trace_buf_top < md->trace_buf_size);

    insert_profile_call((cache_pc)p);

    /* use one giant BINARY instruction to hold everything,
     * to keep dynamo from interpreting the cti instructions as real ones
     */
    instr = instr_create(dcontext);
    instr_set_raw_bits(instr, p, num_bytes);
    instrlist_prepend(trace, instr);

    md->trace_buf_top += num_bytes;
}
#endif

/* emulates the effects of the instruction at pc with the state in mcontext
 * limited right now to only mov instructions
 * returns NULL if failed or not yet implemented, else returns the pc of the next instr.
 */
app_pc
emulate(dcontext_t *dcontext, app_pc pc, dr_mcontext_t *mc)
{
    instr_t instr;
    app_pc next_pc = NULL;
    uint opc;
    instr_init(dcontext, &instr);
    next_pc = decode(dcontext, pc, &instr);
    if (!instr_valid(&instr)) {
        next_pc = NULL;
        goto emulate_failure;
    }
    DOLOG(2, LOG_INTERP, { loginst(dcontext, 2, &instr, "emulating"); });
    opc = instr_get_opcode(&instr);
    if (opc == OP_mov_st) {
        opnd_t src = instr_get_src(&instr, 0);
        opnd_t dst = instr_get_dst(&instr, 0);
        reg_t *target;
        reg_t val;
        uint sz = opnd_size_in_bytes(opnd_get_size(dst));
        ASSERT(opnd_is_memory_reference(dst));
        if (sz != 4 IF_X64(&& sz != 8)) {
            next_pc = NULL;
            goto emulate_failure;
        }
        target = (reg_t *) opnd_compute_address(dst, mc);
        if (opnd_is_reg(src)) {
            val = reg_get_value(opnd_get_reg(src), mc);
        } else if (opnd_is_immed_int(src)) {
            val = (reg_t) opnd_get_immed_int(src);
        } else {
            next_pc = NULL;
            goto emulate_failure;
        }
        DODEBUG({
            uint prot;
            ASSERT(get_memory_info((app_pc)target, NULL, NULL, &prot));
            ASSERT(TEST(MEMPROT_WRITE, prot));
        });
        LOG(THREAD, LOG_INTERP, 2, "\temulating store by writing "PFX" to "PFX"\n",
            val, target);
        if (sz == 4)
            *((int*)target) = (int) val;
#ifdef X64
        else if (sz == 8)
            *target = val;
#endif
    } else if (opc == OP_inc || opc == OP_dec) {
        opnd_t src = instr_get_src(&instr, 0);
        reg_t *target;
        uint sz = opnd_size_in_bytes(opnd_get_size(src));
        if (sz != 4 IF_X64(&& sz != 8)) {
            next_pc = NULL;
            goto emulate_failure;
        }
        /* FIXME: handle changing register value */
        ASSERT(opnd_is_memory_reference(src));
        /* FIXME: change these to take in dr_mcontext_t* ? */
        target = (reg_t *) opnd_compute_address(src, mc);
        DODEBUG({
            uint prot;
            ASSERT(get_memory_info((app_pc)target, NULL, NULL, &prot));
            ASSERT(TEST(MEMPROT_WRITE, prot));
        });
        LOG(THREAD, LOG_INTERP, 2, "\temulating %s to "PFX"\n",
            opc == OP_inc ? "inc" : "dec", target);
        if (sz == 4) {
            if (opc == OP_inc)
                (*((int*)target))++;
            else
                (*((int*)target))--;
        }
#ifdef X64
        else if (sz == 8) {
            if (opc == OP_inc)
                (*target)++;
            else
                (*target)--;
        }
#endif
    }
 emulate_failure:
    instr_free(dcontext, &instr);
    return next_pc;
}
