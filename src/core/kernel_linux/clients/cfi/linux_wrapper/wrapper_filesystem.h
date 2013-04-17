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


#endif /* WRAPPER_FILESYSTEM_H_ */