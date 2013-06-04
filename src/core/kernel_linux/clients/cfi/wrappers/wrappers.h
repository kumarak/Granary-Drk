/*
 * wrappers.h
 *
 *  Created on: 2013-04-16
 *      Author: akshayk
 */

#ifndef WRAPPERS_H_
#define WRAPPERS_H_

#define PRE_WRAP pre
#define POST_WRAP post
#define ABORT_IF_FUNCTION_IS_WRAPPED(x)
#define NO_PRE
#define NO_POST no_post
#define NO_RETURN no_return

#define WRAP_FUNCTION WRAP_FUNC
#define PRE_OUT_WRAP(x) WRAP_RECURSIVE(x)
#define POST_OUT_WRAP(x) WRAP_RECURSIVE(x)
/*
TYPE_WRAPPER(struct inode, {
        pre {
            D( kern_printk("    inode\n"); )

            WRAP_RECURSIVE_KERNEL(arg.i_sb);
            WRAP_RECURSIVE_KERNEL(arg.i_op);
            WRAP_RECURSIVE_KERNEL(arg.i_fop);
            WRAP_RECURSIVE_KERNEL(arg.i_mapping);
        }
        no_post
})
*/

#define WRAP_RECURSIVE_KERNEL(arg) \
    if(is_kernel_virtual_address_space((void*)arg)) { \
        if(IS_WATCHPOINT(arg)){ \
            REMOVE_WATCHPOINT(arg);  \
        }   \
        WRAP_RECURSIVE(arg);    \
      }

enum trace_reg {
         TRACE_REG_REGISTER,
         TRACE_REG_UNREGISTER,
#ifdef CONFIG_PERF_EVENTS
         TRACE_REG_PERF_REGISTER,
         TRACE_REG_PERF_UNREGISTER,
         TRACE_REG_PERF_OPEN,
         TRACE_REG_PERF_CLOSE,
         TRACE_REG_PERF_ADD,
         TRACE_REG_PERF_DEL,
#endif
};

#define pgoff_t unsigned long

extern __u32 half_md4_transform(__u32 buf[4], __u32 const in[8]);
extern int trace_event_raw_init(struct ftrace_event_call *call);

extern struct posix_acl *posix_acl_from_xattr(struct user_namespace *user_ns,
                                        const void *value, size_t size);
extern int posix_acl_to_xattr(struct user_namespace *user_ns,
                       const struct posix_acl *acl, void *buffer, size_t size);

extern void list_sort(void *priv, struct list_head *head,
        int (*cmp)(void *priv, struct list_head *a,
                           struct list_head *b));

extern void perf_tp_event(u64 addr, u64 count, void *record,
                           int entry_size, struct pt_regs *regs,
                           struct hlist_head *head, int rctx,
                           struct task_struct *task);
extern void perf_bp_event(struct perf_event *event, void *data);

extern int filter_current_check_discard(struct ring_buffer *buffer,
                                         struct ftrace_event_call *call,
                                         void *rec,
                                         struct ring_buffer_event *event);

void __stack_chk_fail(void);
void *ring_buffer_event_data(struct ring_buffer_event *event);

void trace_buffer_unlock_commit(struct ring_buffer *buffer,
                                struct ring_buffer_event *event,
                                unsigned long flags, int pc);

int trace_seq_printf(struct trace_seq *s, const char *fmt, ...);

extern void *perf_trace_buf_prepare(int size, unsigned short type,
                                     struct pt_regs *regs, int *rctxp);
extern void module_layout(struct module *mod,
                            struct modversion_info *ver,
                            struct kernel_param *kp,
                            struct kernel_symbol *ks,
                            struct tracepoint * const *tp);

extern int trace_define_field(struct ftrace_event_call *call, const char *type,
                               const char *name, int offset, int size,
                               int is_signed, int filter_type);

struct ring_buffer_event *
trace_current_buffer_lock_reserve(struct ring_buffer **current_buffer,
                                   int type, unsigned long len,
                                   unsigned long flags, int pc);

extern int ftrace_event_reg(struct ftrace_event_call *event,
                             enum trace_reg type, void *data);

extern bool __refrigerator(bool check_kthr_stop);
extern struct file *fget_light(unsigned int fd, int *fput_needed);

void sort(void *base, size_t num, size_t size,
          int (*cmp)(const void *, const void *),
          void (*swap)(void *, void *, int));
void __pagevec_release(struct pagevec *pvec);
extern bool freezing_slow_path(struct task_struct *p);
extern int get_unused_fd_flags(unsigned flags);
extern void fd_install(unsigned int fd, struct file *file);
extern void put_unused_fd(unsigned int fd);
extern void fput(struct file *);
extern bool set_freezable(void);

unsigned pagevec_lookup(struct pagevec *pvec, struct address_space *mapping,
                 pgoff_t start, unsigned nr_pages);

#define SCAN_OBJECT(x)    \
        unsigned long size = type_class<ArgT__>::get_size();    \
        unsigned long i = 0;    \
        uint64_t *ptr = (uint64_t*)(&x);  \
        if(NULL != ptr) {   \
            while(i < size){    \
                uint64_t value = (uint64_t)(*ptr);  \
                if(is_alias_address(value)) {   \
                    cfi_collect_watcpoint(ptr, (void*)value);   \
                }   \
                ptr++;  \
                i = i + sizeof(void*);  \
            }   \
        }


#include "kernel_scanners.h"
#include "wrapper_filesystem.h"
#include "wrapper_allocators.h"
#include "kernel_wrappers.h"
#include "dynamic_wrappers.h"


#endif /* WRAPPERS_H_ */
