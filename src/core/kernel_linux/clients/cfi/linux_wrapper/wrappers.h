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
#define FUNCTION_WRAPPER FUNC_WRAPPER
#define RETURN_IN_WRAP(x)
#define FUNCTION_WRAPPER_VOID FUNC_WRAPPER_VOID
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

typedef bool _Bool;

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
        if((uint64_t)ptr < WP_ADDRESS_BASE) {   \
            return; \
            }   \
            while(i < size){    \
                uint64_t value = (uint64_t)(*ptr);  \
                if(is_alias_address(value)) {   \
                    cfi_collect_watcpoint(ptr, (void*)value);   \
                }   \
                ptr++;  \
                i = i + sizeof(void*);  \
            }


#define PRE_WRAPPER_KERNEL(x) \
    if((uint64_t)x < 4096)  \
    {   return; }

#define KERNEL_ADDRESS_MASK 0xffff800000000000ULL

#define IS_VALID_ADDRESS(arg)  \
    uint64_t value = (uint64_t)(&arg) & KERNEL_ADDRESS_MASK;    \
    if(value != KERNEL_ADDRESS_MASK){  \
        return; \
    }

#include "wrapper_scanner.h"
#include "kernel_scanners.h"
#include "wrapper_filesystem.h"
#include "wrapper_allocators.h"

//#define PRE_WRAPPER_KERNEL(x)
#define WRAPPER_FOR_struct_callback_head
#define WRAPPER_FOR_struct_mutex



#define APP_WRAPPER_FOR_mount_bdev
#define APP_WRAPPER_FOR___free_pages
#define APP_WRAPPER_FOR_radix_tree_gang_lookup
#define APP_WRAPPER_FOR_vfree
#define APP_WRAPPER_FOR__copy_to_user
#define APP_WRAPPER_FOR___kmalloc
#define APP_WRAPPER_FOR___alloc_percpu
#define APP_WRAPPER_FOR_free_percpu
#define APP_WRAPPER_FOR_kmem_cache_alloc
#define APP_WRAPPER_FOR_kmem_cache_free
#define APP_WRAPPER_FOR_clocksource_mmio_init
#define APP_WRAPPER_FOR_flush_work
#define APP_WRAPPER_FOR_block_write_begin
#define APP_WRAPPER_FOR_generic_block_fiemap
#define APP_WRAPPER_FOR__raw_spin_lock
#define APP_WRAPPER_FOR_sb_set_blocksize
#define APP_WRAPPER_FOR_kthread_create_on_node
#define APP_WRAPPER_FOR_jbd2_journal_blocks_per_page
#define APP_WRAPPER_FOR___breadahead
#define APP_WRAPPER_FOR_d_obtain_alias
#define APP_WRAPPER_FOR_iget_failed
#define APP_WRAPPER_FOR_radix_tree_tag_set
#define APP_WRAPPER_FOR_flush_delayed_work
#define APP_WRAPPER_FOR_kmem_cache_alloc_node
#define APP_WRAPPER_FOR_delayed_work_timer_fn
#define APP_WRAPPER_FOR___mark_inode_dirty
#define APP_WRAPPER_FOR_vmalloc_node
#define APP_WRAPPER_FOR___bread
#define APP_WRAPPER_FOR_kfree
#define APP_WRAPPER_FOR___alloc_workqueue_key
#define APP_WRAPPER_FOR_submit_bh
#define APP_WRAPPER_FOR_posix_acl_alloc
#define APP_WRAPPER_FOR_iget_locked
#define APP_WRAPPER_FOR___get_free_pages
#define APP_WRAPPER_FOR_krealloc
#define APP_WRAPPER_FOR_unlock_new_inode
#define APP_WRAPPER_FOR_vm_map_ram
#define APP_WRAPPER_FOR_jbd2_journal_init_jbd_inode
#define APP_WRAPPER_FOR_mpage_readpage
#define APP_WRAPPER_FOR___block_write_begin
#define APP_WRAPPER_FOR___kmalloc_track_caller
#define APP_WRAPPER_FOR_cancel_work_sync
#define APP_WRAPPER_FOR_kmem_cache_create
#define APP_WRAPPER_FOR_register_filesystem
#define APP_WRAPPER_FOR_register_shrinker
#define APP_WRAPPER_FOR_call_rcu_sched
#define APP_WRAPPER_FOR_vmalloc
#define APP_WRAPPER_FOR___kmalloc_node_track_caller
#define APP_WRAPPER_FOR_d_splice_alias
#define APP_WRAPPER_FOR___dev_remove_pack
#define APP_WRAPPER_FOR_mpage_readpages
#define APP_WRAPPER_FOR_bio_add_page
#define APP_WRAPPER_FOR_make_bad_inode
#define APP_WRAPPER_FOR__copy_from_user
#define APP_WRAPPER_FOR_unlock_page
#define APP_WRAPPER_FOR_destroy_workqueue
#define APP_WRAPPER_FOR_kmem_cache_destroy
#define APP_WRAPPER_FOR_mpage_writepages
#define APP_WRAPPER_FOR_queue_work
#define APP_WRAPPER_FOR_dquot_initialize
#define APP_WRAPPER_FOR___kmalloc_node
#define APP_WRAPPER_FOR_inode_permission
#define APP_WRAPPER_FOR_unregister_shrinker
#define APP_WRAPPER_FOR_vfs_unlink
#define APP_WRAPPER_FOR___krealloc
#define APP_WRAPPER_FOR_inode_init_once
#define APP_WRAPPER_FOR_queue_delayed_work
#define APP_WRAPPER_FOR_rb_first
#define APP_WRAPPER_FOR_mb_cache_create



#include "kernel_wrappers.h"

#define PRE_WRAPPER_FUNC(...)   \
        set_section_state(KERNEL_WRAPPER_SET);

#define POST_WRAPPER_FUNC(...)  \
        unset_section_state(KERNEL_WRAPPER_SET);

#include "function_wrapper.h"
#include "dynamic_wrappers.h"


#endif /* WRAPPERS_H_ */
