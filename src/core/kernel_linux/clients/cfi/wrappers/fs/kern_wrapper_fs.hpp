/*
 * kern_wrapper_fs.h
 *
 *  Created on: 2013-04-01
 *      Author: akshayk
 */

#ifndef KERN_WRAPPER_FS_HPP_
#define KERN_WRAPPER_FS_HPP_



FUNC_WRAPPER(register_filesystem, (struct file_system_type * fs), {
		WRAP_FUNC(fs->mount);
		WRAP_FUNC(fs->kill_sb);
        return register_filesystem(fs);
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

#if 0
FUNC_WRAPPER(d_alloc_root, (struct inode *inode), {
        struct inode *temp_inode = inode;
        REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //inode = temp_inode;
        struct dentry *ret = d_alloc_root(inode);
        return ret;
})
#endif


FUNC_WRAPPER(dquot_initialize, (struct inode *inode, int type), {
        struct inode *temp_inode = inode;
        int ret;
        REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //inode = temp_inode;
        ret = dquot_initialize(inode, type);
        return ret;
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

/*
FUNC_WRAPPER(vfs_dq_transfer, (struct inode *inode, struct iattr *iattr), {
        struct inode *temp_inode = inode;
        REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //inode = temp_inode;
        int ret = vfs_dq_transfer(inode, iattr);
        return ret;
})
*/

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
/*
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
*/
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
        //struct inode *temp_inode = TO_UNWATCHED_ADDRESS(inode);
        int ret;
        //REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_fop);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(TO_UNWATCHED_ADDRESS(inode)->i_mapping)->a_ops);
        unlock_new_inode(inode);
        //inode = temp_inode;
})
/*
FUNC_WRAPPER_VOID(vfs_dq_drop, (struct inode *inode), {
        struct inode *temp_inode = inode;
        int ret;
        REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        vfs_dq_drop(inode);
})
*/
FUNC_WRAPPER(d_splice_alias, (struct inode *inode, struct dentry *dentry), {
        struct inode *temp_inode = inode;
        REMOVE_WATCHPOINT(inode);
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
        struct inode *temp_inode = inode;
        int ret;
        //REMOVE_WATCHPOINT(inode);
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
        void *temp_ptr = buf;
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

#endif /* KERN_WRAPPER_FS_H_ */
