/*
 * cfi_memtrace.h
 *
 *  Created on: 2012-09-20
 *      Author: akshayk
 */

#ifndef CFI_MEMTRACE_H_
#define CFI_MEMTRACE_H_


#include <string.h> /* for memset */
#include <stddef.h> /* for offsetof */
#include "dr_api.h"
#include "drmgr.h"
#include "drutil.h"

#define DISPLAY_STRING(msg) dr_printf("%s\n", msg);

#define NULL_TERMINATE(buf) buf[(sizeof(buf)/sizeof(buf[0])) - 1] = '\0'


typedef struct _mem_ref_t{
	bool write;
	void *addr;
	size_t size;
}mem_ref_t;

#define READABLE_TRACE

#define MAX_NUM_MEM_REFS 8192

#define MEM_BUF_SIZE (sizeof(mem_ref_t) * MAX_NUM_MEM_REFS)

/* thread private log file and counter */
typedef struct {
    char   *buf_ptr;
    char   *buf_base;
    /* buf_end holds the negative value of real address of buffer end. */
    ptr_int_t buf_end;
    void   *cache;
    file_t  log;
    uint64  num_refs;
} per_thread_t;


static client_id_t client_id;
static app_pc code_cache;
static void  *mutex;    /* for multithread support */
static uint64 num_refs; /* keep a global memory reference count */
static int tls_index;

static void event_exit(void);
static void event_thread_init(void *drcontext);
static void event_thread_exit(void *drcontext);
static dr_emit_flags_t event_bb_app2app(void *drcontext, void *tag, instrlist_t *bb,
                                        bool for_trace, bool translating);

static dr_emit_flags_t event_bb_analysis(void *drcontext, void *tag, instrlist_t *bb,
                                         bool for_trace, bool translating,
                                         OUT void **user_data);

static dr_emit_flags_t event_bb_insert(void *drcontext, void *tag, instrlist_t *bb,
                                       instr_t *instr, bool for_trace, bool translating,
                                       void *user_data);

static void clean_call(void);
static void memtrace(void *drcontext);
static void code_cache_init(void);
static void code_cache_exit(void);
static void instrument_mem(void        *drcontext,
                           instrlist_t *ilist,
                           instr_t     *where,
                           int          pos,
                           bool         write);

#endif /* CFI_MEMTRACE_H_ */
