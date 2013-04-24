/*
 * wrapper_filesystem.h
 *
 *  Created on: 2013-04-16
 *      Author: akshayk
 */

#ifndef WRAPPER_FILESYSTEM_H_
#define WRAPPER_FILESYSTEM_H_

/******************************************
 * TYPE WRAPPERS
 */


TYPE_WRAPPER(struct address_space_operations, {
        pre {
            D(kern_printk("    address_space_operations\n");)

            WRAP_FUNC(arg.writepage);
            WRAP_FUNC(arg.readpage);
            WRAP_FUNC(arg.writepages);
            WRAP_FUNC(arg.set_page_dirty);
            WRAP_FUNC(arg.readpages);
            WRAP_FUNC(arg.write_begin);
            WRAP_FUNC(arg.write_end);
            WRAP_FUNC(arg.bmap);
            WRAP_FUNC(arg.invalidatepage);
            WRAP_FUNC(arg.releasepage);
            WRAP_FUNC(arg.direct_IO);
            WRAP_FUNC(arg.get_xip_mem);
            WRAP_FUNC(arg.migratepage);
            WRAP_FUNC(arg.launder_page);
            WRAP_FUNC(arg.is_partially_uptodate);
            WRAP_FUNC(arg.error_remove_page);
        }
        no_post
})

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

#define LOOP_COUNT 5

TYPE_WRAPPER(struct super_block, {
        pre {
            D(kern_printk("    super_block\n");)

            WRAP_RECURSIVE_KERNEL(arg.s_type);
            WRAP_RECURSIVE_KERNEL(arg.s_op);
            WRAP_RECURSIVE_KERNEL(arg.s_export_op);
            WRAP_RECURSIVE_KERNEL(arg.dq_op);
            WRAP_RECURSIVE_KERNEL(arg.s_qcop);
            WRAP_RECURSIVE(arg.s_bdev);

            if(0 != arg.s_xattr) {
                D( kern_printk("inside super_block 1 : %lx\n", arg.s_xattr); )
                    struct xattr_handler *handler = (struct xattr_handler*)*arg.s_xattr;
                for(int i=0; i < LOOP_COUNT ; i++) {
                    D(kern_printk("inside super block 2 : %lx\n", handler);)
                        WRAP_RECURSIVE_KERNEL(handler);
                    ++handler;
                }
            }
        }
        no_post
})

TYPE_WRAPPER(struct address_space, {
        pre {
            D( kern_printk("    address_space\n");)
                WRAP_RECURSIVE_KERNEL(arg.a_ops);
        }
        no_post
})

TYPE_WRAPPER(struct block_device , {
        pre {
            D( kern_printk("     block_device\n"); )

            WRAP_RECURSIVE_KERNEL(arg.bd_inode);
            WRAP_RECURSIVE_KERNEL(arg.bd_super);
        }
        no_post
})

TYPE_WRAPPER(struct file_system_type, {
        pre {
            D( kern_printk("    file_system_type\n"); )
            WRAP_FUNC(arg.mount);
            WRAP_FUNC(arg.kill_sb);
        }
        no_post
})

/*TYPE_WRAPPER(get_block_t, {
        pre {
            D( kern_printk("    get_block_t\n"); )
                WRAP_FUNC(arg);
        }
        no_post
})*/

/***********************************************
 * FUNCTION WRAPPER
 */

FUNC_WRAPPER(register_filesystem, (struct file_system_type * fs), {
        WRAP_FUNC(fs->mount);
        WRAP_FUNC(fs->kill_sb);
        return register_filesystem(fs);
})

FUNC_WRAPPER(iget_locked, (struct super_block *sb, unsigned long ino), {
        struct super_operations *arg_sop = (struct super_operations*)sb->s_op;
        kern_printk("super_operation access : %lx", sb->s_op);
        //WRAP_FUNC(TO_UNWATCHED_ADDRESS(arg_sop)->alloc_inode);
        //WRAP_FUNC(TO_UNWATCHED_ADDRESS(arg_sop)->destroy_inode);
        //WRAP_FUNC(TO_UNWATCHED_ADDRESS(arg_sop)->dirty_inode);
        //WRAP_FUNC(TO_UNWATCHED_ADDRESS(arg_sop)->write_inode);
        WRAP_RECURSIVE_KERNEL(arg_sop);
        return iget_locked(sb, ino);
})
#if 1
FUNC_WRAPPER(security_inode_init_security, ( struct inode * inode , struct inode * dir ,
        const struct qstr * qstr , initxattrs initxattrs , void * fs_data ), {
      //  struct inode *temp_inode = inode;
        int ret;
        //REMOVE_WATCHPOINT(temp_inode);
        //WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        //WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        //WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //inode = temp_inode;
        ret = security_inode_init_security(inode, dir, qstr, initxattrs, fs_data);
        return ret;
})
#endif
FUNC_WRAPPER(__bread, ( struct block_device * bdev , sector_t block , unsigned size ), {
        struct buffer_head *ret = __bread(bdev, block, size);
        return ret;
})

FUNC_WRAPPER(jbd2_journal_blocks_per_page, (struct inode *inode), {
        struct inode *temp_inode = inode;
        int ret;
        REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //inode = temp_inode;
        ret = jbd2_journal_blocks_per_page(inode);
        return ret;
})

FUNC_WRAPPER(generic_block_fiemap, (struct inode *inode, struct fiemap_extent_info *fieinfo, u64 start, u64 len, get_block_t get_block), {
        struct inode *temp_inode = inode;
        int ret;
        REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //inode = temp_inode;
        WRAP_FUNC(get_block);
        ret = generic_block_fiemap(inode, fieinfo, start, len, get_block);
        return ret;
})


FUNC_WRAPPER_VOID(dquot_initialize, (struct inode *inode), {
        struct inode *temp_inode = inode;
        REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //inode = temp_inode;
        dquot_initialize(inode);
})

FUNC_WRAPPER(inode_permission, (struct inode *inode, int mask), {
        struct inode *temp_inode = inode;
        int ret;
        REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //inode = temp_inode;
        ret = inode_permission(inode, mask);
        return ret;
})

FUNC_WRAPPER(vfs_link, (struct dentry *old_dentry, struct inode *dir, struct dentry *new_dentry), {
        struct inode *temp_inode = dir;
        int ret;
        REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //dir = temp_inode;
        ret = vfs_link(old_dentry, dir, new_dentry);
        return ret;
})

FUNC_WRAPPER_VOID(make_bad_inode, (struct inode *inode), {
        struct inode *temp_inode = inode;
        int ret;
        REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //inode = temp_inode;
        make_bad_inode(inode);
})

FUNC_WRAPPER_VOID(jbd2_journal_init_jbd_inode, (struct jbd2_inode *jinode, struct inode *inode), {
        struct inode *temp_inode = inode;
        int ret;
        REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //inode = temp_inode;
        jbd2_journal_init_jbd_inode(jinode, inode);
})


FUNC_WRAPPER_VOID(iget_failed, (struct inode *inode), {
        struct inode *temp_inode = inode;
        int ret;
        REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //inode = temp_inode;
        iget_failed(inode);
})

FUNC_WRAPPER(vfs_unlink, (struct inode *dir, struct dentry *dentry), {
        struct inode *temp_inode = dir;
        int ret;
        REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //dir = temp_inode;
        ret = vfs_unlink(dir, dentry);
        return ret;
})

FUNC_WRAPPER_VOID(unlock_new_inode, (struct inode *inode), {
        int ret;
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_fop);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(TO_UNWATCHED_ADDRESS(inode)->i_mapping)->a_ops);
        unlock_new_inode(inode);
})

FUNC_WRAPPER(d_splice_alias, (struct inode *inode, struct dentry *dentry), {
        struct inode *temp_inode = inode;
        //REMOVE_WATCHPOINT(inode);
        struct dentry *ret = d_splice_alias(inode, dentry);
       // inode = temp_inode;
        return ret;
})

FUNC_WRAPPER(d_obtain_alias, (struct inode *inode), {
    //REMOVE_WATCHPOINT(inode);
    struct dentry *ret = d_obtain_alias(inode);
    //RETURN_WRAP(ret);
    return ret;
})


FUNC_WRAPPER_VOID(__breadahead, ( struct block_device * bdev , sector_t block , unsigned size ), {
        //REMOVE_WATCHPOINT(bdev);
        __breadahead(bdev, block, size);
})

FUNC_WRAPPER(mpage_writepages, (struct address_space *mapping, struct writeback_control *wbc, get_block_t get_block), {
   // PRE_WRAP(mapping);
   // PRE_WRAP(wbc);
    WRAP_FUNC(get_block);
    int ret = mpage_writepages(mapping, wbc, get_block);
  //  RETURN_WRAP(ret);
    return ret;
})
FUNC_WRAPPER_VOID(inode_needs_sync, (struct inode *inode), {
        int ret;
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_fop);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(TO_UNWATCHED_ADDRESS(inode)->i_mapping)->a_ops);
        ret = inode_needs_sync(inode);
        return ret;
})

//extern void __percpu_counter_add ( struct percpu_counter * fbc , s64 amount , s32 batch ) ;
FUNC_WRAPPER_VOID(__percpu_counter_add, ( struct percpu_counter * fbc , s64 amount , s32 batch ), {
        //REMOVE_WATCHPOINT(fbc);
        __percpu_counter_add(fbc, amount, batch);
        //return ret;
})


FUNC_WRAPPER(mount_bdev,( struct file_system_type * fs_type , int flags , const char * dev_name , void * data ,
        int ( * fill_super ) ( struct super_block * , void * , int ) ), {
        WRAP_FUNC(fill_super);
        return mount_bdev(fs_type, flags, dev_name, data, fill_super);
})


FUNC_WRAPPER(sb_set_blocksize, ( struct super_block *sb , int i ),{
        return sb_set_blocksize(sb, i);
})

FUNC_WRAPPER(sb_min_blocksize, ( struct super_block *sb , int i ), {
        return sb_min_blocksize(sb, i);
})

FUNC_WRAPPER_VOID(get_random_bytes, ( void * buf , int nbytes ), {
        kern_printk("get_random_bytes wrapper : %lx", buf);
        //REMOVE_WATCHPOINT(buf);
        get_random_bytes(buf, nbytes);
        //buf = temp_ptr;
})


extern int bio_add_page(struct bio *, struct page *, unsigned int,unsigned int);

FUNC_WRAPPER(bio_add_page, (struct bio *bio, struct page *page, unsigned int data1,unsigned int data2), {
        return bio_add_page(bio, page, data1, data2);
})

FUNC_WRAPPER_VOID(_raw_spin_lock, ( raw_spinlock_t * lock ), {
        _raw_spin_lock(lock);
})

//extern void __mark_inode_dirty ( struct inode * , int ) ;
FUNC_WRAPPER_VOID(__mark_inode_dirty, (struct inode *inode, int data), {
        int ret;
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_fop);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(TO_UNWATCHED_ADDRESS(inode)->i_mapping)->a_ops);
        __mark_inode_dirty(inode, data);
})

#if 0
FUNC_WRAPPER_VOID(clear_inode, (struct inode *inode), {
        struct inode *temp_inode = inode;
        int ret;
        REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //inode = temp_inode;
        clear_inode(inode);
})
#endif
//int block_truncate_page(struct address_space *, loff_t, get_block_t *);

FUNC_WRAPPER(block_truncate_page, (struct address_space *mapping, loff_t from, get_block_t *get_block), {
        WRAP_FUNC(get_block);
        return block_truncate_page(mapping, from, get_block);
})

FUNC_WRAPPER(block_write_begin,( struct file * file , struct address_space * mapping , loff_t pos , unsigned len , unsigned flags , struct page * * pagep , void * * fsdata , get_block_t  get_block ) , {
        WRAP_FUNC(get_block);
        return block_write_begin(file, mapping, pos, len, flags, pagep, fsdata, get_block);
})

FUNC_WRAPPER(generic_block_bmap, ( struct address_space * mapping , sector_t block , get_block_t  get_block ) , {
        WRAP_FUNC(get_block);
        return generic_block_bmap(mapping, block, get_block);
})

FUNC_WRAPPER(mpage_readpage, ( struct page * page , get_block_t get_block ) , {
        WRAP_FUNC(get_block);
        return mpage_readpage(page,  get_block);
})

FUNC_WRAPPER(mpage_readpages, ( struct address_space * mapping , struct list_head * pages , unsigned nr_pages , get_block_t get_block ) , {
        WRAP_FUNC(get_block);
        return mpage_readpages(mapping, pages, nr_pages, get_block);
})

FUNC_WRAPPER(submit_bh, ( int rw , struct buffer_head * bh ), {
        if(0 != bh)
            WRAP_FUNC(bh->b_end_io);
        return submit_bh(rw, bh);
})

FUNC_WRAPPER(__block_write_begin, ( struct page * page , loff_t pos ,
                                unsigned len , get_block_t * get_block ), {
        WRAP_FUNC(get_block);
        return __block_write_begin(page, pos, len, get_block);
})

//void * radix_tree_tag_set ( struct radix_tree_root * root , unsigned long index , unsigned int tag ) ;
FUNC_WRAPPER(radix_tree_tag_set, ( struct radix_tree_root * root , unsigned long index , unsigned int tag ), {
    REMOVE_WATCHPOINT(root);
    return radix_tree_tag_set(root, index, tag);
})

//void * radix_tree_tag_clear ( struct radix_tree_root * root , unsigned long index , unsigned int tag ) ;
FUNC_WRAPPER(radix_tree_tag_clear, ( struct radix_tree_root * root , unsigned long index , unsigned int tag ), {
        REMOVE_WATCHPOINT(root);
        return radix_tree_tag_clear(root, index, tag);
})

extern int __ticket_spin_is_locked(arch_spinlock_t *lock);

FUNC_WRAPPER(__ticket_spin_is_locked, (arch_spinlock_t *lock), {
        REMOVE_WATCHPOINT(lock);
        return __ticket_spin_is_locked(lock);
})

//void delayed_work_timer_fn ( unsigned long __data ) ;
FUNC_WRAPPER_VOID(delayed_work_timer_fn, (unsigned long __data),{
    delayed_work_timer_fn(__data);
})


FUNC_WRAPPER(queue_work,( struct workqueue_struct * wq , struct work_struct * work ), {
    return queue_work(wq , work);
})

FUNC_WRAPPER(queue_delayed_work,( struct workqueue_struct * wq , struct delayed_work * work , unsigned long delay ), {
    return queue_delayed_work(wq , work, delay);
})

FUNC_WRAPPER_VOID(inode_init_once, ( struct inode *inode ) ,{
        inode_init_once(inode);
})

//extern struct rb_node *rb_first(const struct rb_root *);
FUNC_WRAPPER(rb_first, (const struct rb_root *rb),{
    REMOVE_WATCHPOINT(rb);
    return rb_first(rb);
})

FUNC_WRAPPER(_copy_to_user, (void *to, void *from, unsigned len), {
        REMOVE_WATCHPOINT(from);
        return _copy_to_user(to, from, len);
})

FUNC_WRAPPER(_copy_from_user, (void *to, void *from, unsigned len), {
        REMOVE_WATCHPOINT(to);
        return _copy_from_user(to, from, len);
})

/*
FUNC_WRAPPER(kthread_create_on_node, ( threadfn thread_fun, void *data , int node, const char namefmt[], ... ), {
        struct kthread_create_info *create(0);
        char format_buff[sizeof(create->result->comm)];
        va_list args;
        va_start(args, namefmt);
        kern_vsnprintf(&(format_buff[0]), sizeof(format_buff), namefmt, args);
        va_end(args);
        WRAP_FUNC(thread_fun);
        D( kern_printk(" kthread_create wrapped !!!!!!!!!!!!!!!!!!  : %lx",thread_fun); )
        return kthread_create_on_node(thread_fun, data, node, format_buff);
})

*/
//#if defined(CAN_WRAP_kthread_create_on_node) && CAN_WRAP_kthread_create_on_node
#   define WRAPPER_FOR_kthread_create_on_node 1
    FUNC_WRAPPER(kthread_create_on_node, (
        int (*threadfn)(void *),
        void *data,
        int node,
        const char namefmt[],
        ...
    ), {
        va_list args__;
        va_start(args__, namefmt);

        WRAP_FUNC(threadfn);
        char name_buff[sizeof(task_struct().comm)];
        vsnprintf(&(name_buff[0]), sizeof(name_buff), namefmt, args__);
        struct task_struct *ret = kthread_create_on_node(threadfn, data, node, name_buff);
        va_end(args__);
        return ret;
    })
//#endif

#if defined(CAN_WRAP_kthread_create) && CAN_WRAP_kthread_create
#   define WRAPPER_FOR_kthread_create 1
    FUNC_WRAPPER(kthread_create, (
        int (*threadfn)(void *),
        void *data,
        const char namefmt[],
        ...
    ), {
        va_list args__;
        va_start(args__, namefmt);

        WRAP_FUNC(threadfn);
        char name_buff[sizeof(task_struct().comm)];
        vsnprintf(&(name_buff[0]), sizeof(name_buff), namefmt, args__);
        struct task_struct *ret = kthread_create(threadfn, data, name_buff);
        va_end(args__);
        return ret;
    })
#endif

#endif /* WRAPPER_FILESYSTEM_H_ */
