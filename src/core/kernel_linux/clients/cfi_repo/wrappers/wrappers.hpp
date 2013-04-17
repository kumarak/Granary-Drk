/*
 * wrapper.hpp
 *
 *  Created on: 2012-04-17
 *      Author: akshayk
 */

#ifndef CFI_WRAPPERS_HPP_
#define CFI_WRAPPERS_HPP_

#include <stdarg.h>

extern "C" {
    #include "kernel_types.h"
}

// up here to avoid specialization after instantiation
ADD_TAINT_TRACKER(struct inode);
SET_TAINT_TRACKER(struct pci_error_handlers, error_detected);
SET_TAINT_TRACKER(struct work_struct, func);
SET_TAINT_TRACKER(struct mii_bus, read);
SET_TAINT_TRACKER(struct device_driver, probe);
SET_TAINT_TRACKER(struct device, release);
SET_TAINT_TRACKER(struct file_operations, llseek);
SET_TAINT_TRACKER(struct file_system_type, get_sb);
SET_TAINT_TRACKER(struct super_operations, alloc_inode);

FORCE_INLINE bool is_kernel_virtual_address_space(void *pc)
{
    unsigned long p = (unsigned long) pc;
    /* Taken from Documentation/x86/x86_64/mm.txt */
    return (p > 0x00007fffffffffff );
}

#define WRAP_RECURSIVE_KERNEL(arg)  \
    if(is_kernel_virtual_address_space((void*)arg)) \
    {   WRAP_RECURSIVE(arg);    }


#if 0 && CFI_SEQUENTIALIZE_MODULE

extern "C" {
#   include "kernel_linux/clients/cfi/cfi_sequence.h"
}

FUNC_WRAPPER(mutex_lock, (struct mutex *lock), {
    cfi_seq_open_context((mem_t *) lock);
    return mutex_lock(lock);
})

FUNC_WRAPPER(mutex_unlock, (struct mutex *lock), {
    cfi_seq_close_context((mem_t *) lock);
    return mutex_unlock(lock);
})

#if 0
    FUNC_WRAPPER(mutex_lock, (struct mutex *lock), {
        cfi_seq_log("%p mutex_lock(%p) at %llu (%05llx) count=%llu\n",
            (unsigned long long) lock,
            cfi_seq_get_instr_count(),
            cfi_seq_get_rel_pc(),
            (unsigned long long) lock->count.counter);

        return mutex_lock(lock);
    })

    FUNC_WRAPPER(mutex_unlock, (struct mutex *lock), {
        cfi_seq_log("%p mutex_unlock(%p) at %llu (%05llx) count=%llu\n",
            (unsigned long long) lock,
            cfi_seq_get_instr_count(),
            cfi_seq_get_rel_pc(),
            (unsigned long long) lock->count.counter);

        return mutex_unlock(lock);
    })

    FUNC_WRAPPER(wake_up_process, ( struct task_struct *p), {
        cfi_seq_defer1(wake_up_process, p);
        return 1;
    })

    FUNC_WRAPPER(kthread_create, ( threadfn thread_fun, void *data , const char namefmt[], ... ), {
        struct kthread_create_info *create(0);
        char format_buff[sizeof(create->result->comm)];
        va_list args;
        va_start(args, namefmt);
        kern_vsnprintf(&(format_buff[0]), sizeof(format_buff), namefmt, args);
        va_end(args);
        WRAP_FUNC(thread_fun);

        struct cfi_seq_thread_data *data = cfi_seq_thread_data(thread_fun, data);

        struct task_struct *task = kthread_create(
            cfi_seq_thread,
            data,
            format_buff);

        data->task = task;
        return task;
    })

    FUNC_WRAPPER(schedule, (void), {
        typedef long st_func(long);
        st_func *kern_schedule_timeout = (st_func *) KERN_ADDR_schedule_timeout;
        cfi_seq_release_module();
        kern_schedule_timeout(10000);
    })
#endif

#else

#endif

FUNC_WRAPPER(kthread_create, ( threadfn thread_fun, void *data , const char namefmt[], ... ), {
    struct kthread_create_info *create(0);
    char format_buff[sizeof(create->result->comm)];
    va_list args;
    va_start(args, namefmt);
    kern_vsnprintf(&(format_buff[0]), sizeof(format_buff), namefmt, args);
    va_end(args);
    WRAP_FUNC(thread_fun);
    D( kern_printk(" kthread_create wrapped !!!!!!!!!!!!!!!!!!  : %lx",thread_fun); )
    return kthread_create(thread_fun, data, format_buff);
})

TYPE_WRAPPER(struct super_operations, {
    pre {
        D( kern_printk("    super_operations\n"); )

        WRAP_FUNC(arg.alloc_inode);
        WRAP_FUNC(arg.destroy_inode);
        WRAP_FUNC(arg.dirty_inode);
        WRAP_FUNC(arg.write_inode);
        WRAP_FUNC(arg.drop_inode);
        WRAP_FUNC(arg.delete_inode);
        WRAP_FUNC(arg.put_super);
        WRAP_FUNC(arg.write_super);
        WRAP_FUNC(arg.sync_fs);
        WRAP_FUNC(arg.freeze_fs);
        WRAP_FUNC(arg.unfreeze_fs);
        WRAP_FUNC(arg.statfs);
        WRAP_FUNC(arg.remount_fs);
        WRAP_FUNC(arg.clear_inode);
        WRAP_FUNC(arg.umount_begin);
        WRAP_FUNC(arg.show_options);
        WRAP_FUNC(arg.show_stats);
        WRAP_FUNC(arg.quota_read);
        WRAP_FUNC(arg.quota_write);
        WRAP_FUNC(arg.bdev_try_to_free_page);
    }
    no_post
})

SET_TAINT_TRACKER(struct dquot_operations, initialize);
TYPE_WRAPPER(struct dquot_operations, {
    pre {
        D( kern_printk("    dquot_operations\n"); )

        WRAP_FUNC(arg.initialize);
        WRAP_FUNC(arg.drop);
        WRAP_FUNC(arg.alloc_space);
        WRAP_FUNC(arg.alloc_inode);
        WRAP_FUNC(arg.free_space);
        WRAP_FUNC(arg.free_inode);
        WRAP_FUNC(arg.transfer);
        WRAP_FUNC(arg.write_dquot);
        WRAP_FUNC(arg.alloc_dquot);
        WRAP_FUNC(arg.destroy_dquot);
        WRAP_FUNC(arg.acquire_dquot);
        WRAP_FUNC(arg.release_dquot);
        WRAP_FUNC(arg.mark_dirty);
        WRAP_FUNC(arg.write_info);
        WRAP_FUNC(arg.reserve_space);
        WRAP_FUNC(arg.claim_space);
        WRAP_FUNC(arg.release_rsv);
        WRAP_FUNC(arg.get_reserved_space);
    }
    no_post
})

SET_TAINT_TRACKER(struct quotactl_ops, quota_on);
TYPE_WRAPPER(struct quotactl_ops, {
    pre {
        D( kern_printk("    quotactl_ops\n"); )

        WRAP_FUNC(arg.quota_on);
        WRAP_FUNC(arg.quota_off);
        WRAP_FUNC(arg.quota_sync);
        WRAP_FUNC(arg.get_info);
        WRAP_FUNC(arg.set_info);
        WRAP_FUNC(arg.get_dqblk);
        WRAP_FUNC(arg.set_dqblk);
        WRAP_FUNC(arg.get_xstate);
        WRAP_FUNC(arg.get_xquota);
        WRAP_FUNC(arg.set_xquota);
    }
    no_post
})

SET_TAINT_TRACKER(struct inode_operations, create);
TYPE_WRAPPER(struct inode_operations, {
    pre {
        D( kern_printk("    inode_operations\n"); )

        WRAP_FUNC(arg.create);
        WRAP_FUNC(arg.lookup);
        WRAP_FUNC(arg.link);
        WRAP_FUNC(arg.unlink);
        WRAP_FUNC(arg.symlink);
        WRAP_FUNC(arg.mkdir);
        WRAP_FUNC(arg.rmdir);
        WRAP_FUNC(arg.mknod);
        WRAP_FUNC(arg.rename);
        WRAP_FUNC(arg.readlink);
        WRAP_FUNC(arg.follow_link);
        WRAP_FUNC(arg.put_link);
        WRAP_FUNC(arg.truncate);
        WRAP_FUNC(arg.permission);
        WRAP_FUNC(arg.check_acl);
        WRAP_FUNC(arg.setattr);
        WRAP_FUNC(arg.getattr);
        WRAP_FUNC(arg.setxattr);
        WRAP_FUNC(arg.getxattr);
        WRAP_FUNC(arg.listxattr);
        WRAP_FUNC(arg.removexattr);
        WRAP_FUNC(arg.truncate_range);
        WRAP_FUNC(arg.fallocate);
        WRAP_FUNC(arg.fiemap);
    }
    no_post
})

SET_TAINT_TRACKER(struct export_operations, encode_fh);
TYPE_WRAPPER(struct export_operations, {
    pre {
        D( kern_printk("    export_operations\n"); )

        WRAP_FUNC(arg.encode_fh);
        WRAP_FUNC(arg.fh_to_dentry);
        WRAP_FUNC(arg.fh_to_parent);
        WRAP_FUNC(arg.get_name);
        WRAP_FUNC(arg.get_parent);
    }
    no_post
})

SET_TAINT_TRACKER(struct xattr_handler, list);
TYPE_WRAPPER(struct xattr_handler, {
    pre {
        D( kern_printk("    xattr_handler!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"); )
        WRAP_FUNC(arg.list);
        WRAP_FUNC(arg.get);
        WRAP_FUNC(arg.set);
    }
    no_post
})


TYPE_WRAPPER(struct file_operations, {
    pre {
        D( kern_printk("    file_operations\n"); )

          WRAP_FUNC(arg.llseek);
          WRAP_FUNC(arg.read);
          WRAP_FUNC(arg.write);
          WRAP_FUNC(arg.aio_read);
          WRAP_FUNC(arg.aio_write);
          WRAP_FUNC(arg.readdir);
          WRAP_FUNC(arg.poll);
          WRAP_FUNC(arg.ioctl);
          WRAP_FUNC(arg.unlocked_ioctl);
          WRAP_FUNC(arg.compat_ioctl);
          WRAP_FUNC(arg.mmap);
          WRAP_FUNC(arg.open);
          WRAP_FUNC(arg.flush);
          WRAP_FUNC(arg.release);
          WRAP_FUNC(arg.fsync);
          WRAP_FUNC(arg.aio_fsync);
          WRAP_FUNC(arg.fasync);
          WRAP_FUNC(arg.lock);
          WRAP_FUNC(arg.sendpage);
          WRAP_FUNC(arg.get_unmapped_area);
          WRAP_FUNC(arg.check_flags);
          WRAP_FUNC(arg.flock);
          WRAP_FUNC(arg.splice_write);
          WRAP_FUNC(arg.splice_read);
          WRAP_FUNC(arg.setlease);
    }
    no_post
})

SET_TAINT_TRACKER(struct address_space_operations, writepage);
TYPE_WRAPPER(struct address_space_operations, {
    pre {
        D(kern_printk("    address_space_operations\n");)

        WRAP_FUNC(arg.writepage);
        WRAP_FUNC(arg.readpage);
        WRAP_FUNC(arg.sync_page);
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


#define LOOP_COUNT 5

TYPE_WRAPPER(struct super_block, {
    pre {
        D(kern_printk("    super_block\n");)

        WRAP_RECURSIVE_KERNEL(arg.s_type);
        WRAP_RECURSIVE_KERNEL(arg.s_op);
        WRAP_RECURSIVE_KERNEL(arg.s_export_op);
      //  WRAP_RECURSIVE_KERNEL(arg.dq_op);
       // WRAP_RECURSIVE_KERNEL(arg.s_qcop);
       // WRAP_RECURSIVE(arg.s_bdev);

        if(0 != arg.s_xattr) {
            D( kern_printk("inside super_block 1 : %lx\n", arg.s_xattr); )
            struct xattr_handler *handler = *arg.s_xattr;
            for(int i=0; i < LOOP_COUNT ; i++) {
                D(kern_printk("inside super block 2 : %lx\n", handler);)
                WRAP_RECURSIVE_KERNEL(handler);
                ++handler;
            }
        }
    }
    no_post
})

/// set inodes to be structure tainted
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

/*SET_TAINT_TRACKER(struct buffer_head, b_end_io);
TYPE_WRAPPER(struct buffer_head, {
    pre {
        D( kern_printk("     buffer_head\n"); )

        WRAP_FUNC(arg.b_end_io);
        WRAP_RECURSIVE_KERNEL(arg.b_assoc_map);
    }
    no_post
})
*/

/*
FUNC_WRAPPER(bmap, ( struct inode * inode , sector_t block ), {
	if(is_kernel_virtual_address_space(inode))
	{
		if(is_kernel_virtual_address_space(inode->i_mapping))
		{
			//WRAP_FUNC(inode->i_mapping->a_ops->bmap);
		}
	}
    return bmap(inode, block);
})

*/


FUNC_WRAPPER(generic_block_fiemap,( struct inode * inode , struct fiemap_extent_info * fieinfo , u64 start , u64 len , get_block_t  get_block ) , {
	WRAP_FUNC(get_block);
    return generic_block_fiemap(inode, fieinfo, start, len, get_block);
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
	if(bh != NULL)
		WRAP_FUNC(bh->b_end_io);
    return submit_bh(rw, bh);
})
/*
TYPE_WRAPPER(struct journal_s , {
    pre {
        D( kern_printk("     journal_s\n"); )

        WRAP_RECURSIVE_KERNEL(arg.j_sb_buffer);
        WRAP_RECURSIVE_KERNEL(arg.j_dev);
        WRAP_RECURSIVE_KERNEL(arg.j_inode);
    }
    no_post
})
*/

// set kmem_cache structs to be function-pointer based taint-tracked
SET_TAINT_TRACKER(struct kmem_cache, ctor);
TYPE_WRAPPER(struct kmem_cache , {
    pre {
        D( kern_printk("     kmem_cache\n"); )

        if(sizeof(struct inode) == arg.size) {
            TAINT_EXTEND_SIZE(arg.size);
        }
        WRAP_FUNC(arg.ctor);
    }
    no_post
})

/*SET_TAINT_TRACKER(struct task_struct, notifier);
TYPE_WRAPPER(struct task_struct , {
    pre {
        D( kern_printk("     task_struct\n"); )

        WRAP_FUNC(arg.notifier);
    }
    no_post
})
*/


TYPE_WRAPPER(struct page , {
    pre {
        D( kern_printk("     page\n"); )

        WRAP_RECURSIVE_KERNEL(arg.mapping);
    }
    no_post
})

SET_TAINT_TRACKER(struct mb_cache_op, free);
TYPE_WRAPPER(struct mb_cache_op , {
    pre {
        D( kern_printk("     mb_cache_op\n"); )

        WRAP_FUNC(arg.free);
    }
    no_post
})


TYPE_WRAPPER(struct file_system_type, {
    pre {
        D( kern_printk("    file_system_type\n"); )
        WRAP_FUNC(arg.get_sb);
        WRAP_FUNC(arg.kill_sb);
    }
    no_post
})

SET_TAINT_TRACKER(struct __wait_queue, func);
TYPE_WRAPPER(struct __wait_queue, {
    pre {
        D( kern_printk("    __wait_queue\n"); )
        WRAP_FUNC(arg.func);
    }
    no_post
})

TYPE_WRAPPER(ctor, {
    pre {
        D( kern_printk("    ctor\n"); )
        WRAP_FUNC(arg);
    }
    no_post
})



TYPE_WRAPPER(get_inode, {
    pre {
        D( kern_printk("    get_inode\n"); )
        WRAP_FUNC(arg);
    }
    no_post
})

TYPE_WRAPPER(fill_super, {
    pre {
        D( kern_printk("    fill_super\n"); )
        WRAP_FUNC(arg);
    }
    no_post
})

TYPE_WRAPPER(read_actor_t, {
    pre {
        D( kern_printk("    read_actor_t\n"); )
        WRAP_FUNC(arg);
    }
    no_post
})

TYPE_WRAPPER(wait_queue_func_t, {
    pre {
        D( kern_printk("    wait_queue_func_t\n"); )
        WRAP_FUNC(arg);
    }
    no_post
})

TYPE_WRAPPER(get_block_t, {
    pre {
        D( kern_printk("    get_block_t\n"); )
        WRAP_FUNC(arg);
    }
    no_post
})

TYPE_WRAPPER(dio_iodone_t, {
    pre {
        D( kern_printk("    dio_iodone_t\n"); )
        WRAP_FUNC(arg);
    }
    no_post
})

TYPE_WRAPPER(bh_end_io_t, {
    pre {
        D( kern_printk("    bh_end_io_t\n"); )
        WRAP_FUNC(arg);
    }
    no_post
})

/*TYPE_WRAPPER(threadfn, {
    pre {
        D( kern_printk("    notifier\n"); )
        WRAP_FUNC(arg);
    }
    no_post
})
*/
TYPE_WRAPPER(fn_scan, {
    pre {
        D( kern_printk("    fn_scan\n"); )
        WRAP_FUNC(arg);
    }
    no_post
})


FUNC_WRAPPER(iget_locked, (struct super_block *sb, unsigned long ino), {
    struct super_operations *arg_sop = (struct super_operations*)sb->s_op;
    WRAP_RECURSIVE_KERNEL(arg_sop);
    return iget_locked(sb, ino);
})

FUNC_WRAPPER(register_filesystem, (struct file_system_type * fs), {
    WRAP_FUNC(fs->get_sb);
    WRAP_FUNC(fs->kill_sb);
    return register_filesystem(fs);
})

FUNC_WRAPPER(get_sb_bdev, (struct file_system_type *fs_type, int flags, const char *dev_name, void *data, fill_super fill_super_data, struct vfsmount *mnt), {
    WRAP_FUNC(fs_type->get_sb);
    WRAP_FUNC(fs_type->kill_sb);
    WRAP_FUNC(fill_super_data);
    return get_sb_bdev(fs_type, flags, dev_name, data, fill_super_data, mnt);
})


#if 0
FUNC_WRAPPER(skb_dma_map, (struct device *dev, struct sk_buff *skb, enum dma_data_direction dir), {
    return skb_dma_map(dev, skb, dir);
})
#endif
TYPE_WRAPPER(struct sk_buff, {
    no_pre
    no_post
})

TYPE_WRAPPER(notifier, {
    pre {
        D( kern_printk("    notifier\n"); )
        WRAP_FUNC(arg);
    }
    no_post
})

SET_TAINT_TRACKER(struct net_device_ops, ndo_init);
TYPE_WRAPPER(struct net_device_ops, {
    pre {
        D( kern_printk("    net_device_ops\n"); )
        WRAP_FUNC(arg.ndo_init);
        WRAP_FUNC(arg.ndo_uninit);
        WRAP_FUNC(arg.ndo_open);
        WRAP_FUNC(arg.ndo_stop);
  //      WRAP_FUNC(arg.ndo_start_xmit);
  //      WRAP_FUNC(arg.ndo_select_queue);
        WRAP_FUNC(arg.ndo_change_rx_flags);
        WRAP_FUNC(arg.ndo_set_rx_mode);
        WRAP_FUNC(arg.ndo_set_multicast_list);
        WRAP_FUNC(arg.ndo_set_mac_address);
        WRAP_FUNC(arg.ndo_validate_addr);
        WRAP_FUNC(arg.ndo_do_ioctl);
        WRAP_FUNC(arg.ndo_set_config);
        WRAP_FUNC(arg.ndo_change_mtu);
        WRAP_FUNC(arg.ndo_neigh_setup);
        WRAP_FUNC(arg.ndo_tx_timeout);
        WRAP_FUNC(arg.ndo_get_stats);
        WRAP_FUNC(arg.ndo_vlan_rx_register);
        WRAP_FUNC(arg.ndo_vlan_rx_add_vid);
        WRAP_FUNC(arg.ndo_vlan_rx_kill_vid);
        WRAP_FUNC(arg.ndo_poll_controller);
        WRAP_FUNC(arg.ndo_fcoe_enable);
        WRAP_FUNC(arg.ndo_fcoe_disable);
        WRAP_FUNC(arg.ndo_fcoe_ddp_setup);
        WRAP_FUNC(arg.ndo_fcoe_ddp_done);
    }
    no_post
})

SET_TAINT_TRACKER(struct ethtool_ops, get_settings);
TYPE_WRAPPER(struct ethtool_ops, {
    pre {
        D( kern_printk("    ethtool_ops\n"); )
        WRAP_FUNC(arg.get_settings);
        WRAP_FUNC(arg.set_settings);
        WRAP_FUNC(arg.get_drvinfo);
        WRAP_FUNC(arg.get_regs_len);
        WRAP_FUNC(arg.get_regs);
        WRAP_FUNC(arg.get_wol);
        WRAP_FUNC(arg.set_wol);
        WRAP_FUNC(arg.get_msglevel);
        WRAP_FUNC(arg.set_msglevel);
        WRAP_FUNC(arg.nway_reset);
        WRAP_FUNC(arg.get_link);
        WRAP_FUNC(arg.get_eeprom_len);
        WRAP_FUNC(arg.get_eeprom);
        WRAP_FUNC(arg.set_eeprom);
        WRAP_FUNC(arg.get_coalesce);
        WRAP_FUNC(arg.set_coalesce);
        WRAP_FUNC(arg.get_ringparam);
        WRAP_FUNC(arg.set_ringparam);
        WRAP_FUNC(arg.get_pauseparam);
        WRAP_FUNC(arg.set_pauseparam);
        WRAP_FUNC(arg.get_rx_csum);
        WRAP_FUNC(arg.set_rx_csum);
        WRAP_FUNC(arg.get_tx_csum);
        WRAP_FUNC(arg.set_tx_csum);
        WRAP_FUNC(arg.set_sg);
        WRAP_FUNC(arg.get_sg);
        WRAP_FUNC(arg.set_tso);
        WRAP_FUNC(arg.get_tso);
        WRAP_FUNC(arg.self_test);
        WRAP_FUNC(arg.get_strings);
        WRAP_FUNC(arg.phys_id);
        WRAP_FUNC(arg.get_ethtool_stats);
        WRAP_FUNC(arg.begin);
        WRAP_FUNC(arg.complete);
        WRAP_FUNC(arg.get_ufo);
        WRAP_FUNC(arg.set_ufo);
        WRAP_FUNC(arg.get_flags);
        WRAP_FUNC(arg.set_flags);
        WRAP_FUNC(arg.get_priv_flags);
        WRAP_FUNC(arg.set_priv_flags);
        WRAP_FUNC(arg.get_sset_count);
        WRAP_FUNC(arg.self_test_count);
        WRAP_FUNC(arg.get_stats_count);
        WRAP_FUNC(arg.get_rxnfc);
        WRAP_FUNC(arg.set_rxnfc);
        WRAP_FUNC(arg.flash_device);
        WRAP_FUNC(arg.reset);
    }
    no_post
})

//SET_TAINT_TRACKER(struct timer_list, function); // watch out! lots of timers!
TYPE_WRAPPER(struct timer_list, {
    pre {
        D( kern_printk("    timer_list \n"); )
        WRAP_FUNC(arg.function);
    }
    no_post
})

//SET_TAINT_TRACKER(struct net_device, destructor); // not required unless recursively wrapping
TYPE_WRAPPER(struct net_device, {
    pre {
        D( kern_printk("    net_device \n"); )
        WRAP_FUNC(arg.destructor);

   //     WRAP_RECURSIVE_KERNEL(arg.netdev_ops);
     //   WRAP_RECURSIVE_KERNEL(arg.ethtool_ops);
    }
    no_post
})


FUNC_WRAPPER( __netdev_alloc_skb, (struct net_device *dev,  unsigned int length, gfp_t gfp_mask), {
        return __netdev_alloc_skb(dev, length, gfp_mask );
})

FUNC_WRAPPER( skb_put,(struct sk_buff *skb, unsigned int len), {
        return skb_put(skb, len);
})

FUNC_WRAPPER( register_netdev, ( struct net_device *dev ), {
		struct net_device_ops *netdev = (struct net_device_ops*)dev->netdev_ops;
		struct ethtool_ops *ethdev = (struct ethtool_ops*)dev->ethtool_ops;
		if(0 != netdev) {
			WRAP_FUNC(netdev->ndo_init);
			WRAP_FUNC(netdev->ndo_uninit);
			WRAP_FUNC(netdev->ndo_open);
			WRAP_FUNC(netdev->ndo_stop);
			WRAP_FUNC(netdev->ndo_start_xmit);
			WRAP_FUNC(netdev->ndo_select_queue);
			WRAP_FUNC(netdev->ndo_change_rx_flags);
			WRAP_FUNC(netdev->ndo_set_rx_mode);
			WRAP_FUNC(netdev->ndo_set_multicast_list);
			WRAP_FUNC(netdev->ndo_set_mac_address);
			WRAP_FUNC(netdev->ndo_validate_addr);
			WRAP_FUNC(netdev->ndo_do_ioctl);
			WRAP_FUNC(netdev->ndo_set_config);
			WRAP_FUNC(netdev->ndo_change_mtu);
			WRAP_FUNC(netdev->ndo_neigh_setup);
			WRAP_FUNC(netdev->ndo_tx_timeout);
			WRAP_FUNC(netdev->ndo_get_stats);
			WRAP_FUNC(netdev->ndo_vlan_rx_register);
			WRAP_FUNC(netdev->ndo_vlan_rx_add_vid);
			WRAP_FUNC(netdev->ndo_vlan_rx_kill_vid);
			WRAP_FUNC(netdev->ndo_poll_controller);
			WRAP_FUNC(netdev->ndo_fcoe_enable);
			WRAP_FUNC(netdev->ndo_fcoe_disable);
			WRAP_FUNC(netdev->ndo_fcoe_ddp_setup);
			WRAP_FUNC(netdev->ndo_fcoe_ddp_done);
			WRAP_FUNC(dev->destructor);
		}
      //  WRAP_RECURSIVE_KERNEL(netdev);
        WRAP_RECURSIVE_KERNEL(ethdev);
        return register_netdev(dev);
})


TYPE_WRAPPER(struct delayed_work, {
    pre {
        D( kern_printk("    delayed_work\n"); )

        WRAP_RECURSIVE(arg.work);
        WRAP_RECURSIVE(arg.timer);
    }
    no_post
})




TYPE_WRAPPER(struct work_struct, {
    pre {
        D( kern_printk("    work_struct\n"); )
        WRAP_FUNC(arg.func);
    }
    no_post
})

SET_TAINT_TRACKER(struct phy_device, adjust_link);
TYPE_WRAPPER(struct phy_device, {
    pre {
        D( kern_printk("    phy_device\n"); )

		WRAP_FUNC(arg.adjust_link);
        WRAP_FUNC(arg.adjust_state);

        WRAP_RECURSIVE_KERNEL(arg.bus);
        WRAP_RECURSIVE(arg.phy_queue);
        WRAP_RECURSIVE(arg.state_queue);
        WRAP_RECURSIVE_KERNEL(arg.attached_dev);
    }
    no_post
})


SET_TAINT_TRACKER(struct pci_driver, probe);
TYPE_WRAPPER(struct pci_driver, {
    pre {
        D( kern_printk("    pci_driver\n"); )
        WRAP_FUNC(arg.probe);
        WRAP_FUNC(arg.remove);
        WRAP_FUNC(arg.suspend);
        WRAP_FUNC(arg.suspend_late);
        WRAP_FUNC(arg.resume_early);
        WRAP_FUNC(arg.resume);
        WRAP_FUNC(arg.shutdown);

        WRAP_RECURSIVE(arg.driver);
        WRAP_RECURSIVE_KERNEL(arg.err_handler);
    }
    no_post
})


TYPE_WRAPPER(struct mii_bus, {
    pre {
        D( kern_printk("    mii_bus\n"); )
        WRAP_FUNC(arg.read);
        WRAP_FUNC(arg.write);
        WRAP_FUNC(arg.reset);

        WRAP_RECURSIVE(arg.dev);

        struct phy_device *handler = arg.phy_map[0];
            for(int i=0; i < 32 ; i++) {
                D(kern_printk("inside super block 2 : %lx\n", handler);)
                WRAP_RECURSIVE_KERNEL(handler);
                ++handler;
            }
    }
    no_post
})



TYPE_WRAPPER(struct dev_pm_info, {
    pre {
        D( kern_printk("    dev_pm_info\n"); )

        WRAP_RECURSIVE(arg.suspend_timer);
        WRAP_RECURSIVE(arg.work);
    }
    no_post
})


TYPE_WRAPPER(struct device, {
    pre {
        D( kern_printk("    device\n"); )
        WRAP_FUNC(arg.release);

        WRAP_RECURSIVE(arg.power);
        WRAP_RECURSIVE_KERNEL(arg.driver);
    }
    no_post
})


SET_TAINT_TRACKER(struct phy_driver, config_init);
TYPE_WRAPPER(struct phy_driver, {
    pre {
        D( kern_printk("    phy_driver\n"); )
        WRAP_FUNC(arg.config_init);
        WRAP_FUNC(arg.probe);
        WRAP_FUNC(arg.suspend);
        WRAP_FUNC(arg.resume);
        WRAP_FUNC(arg.config_aneg);
        WRAP_FUNC(arg.read_status);
        WRAP_FUNC(arg.ack_interrupt);
        WRAP_FUNC(arg.config_intr);
        WRAP_FUNC(arg.did_interrupt);
        WRAP_FUNC(arg.remove)

        WRAP_RECURSIVE(arg.driver);
    }
    no_post
})

TYPE_WRAPPER(struct pci_dev, {
    pre {
        D( kern_printk("    pci_dev\n"); )

		WRAP_RECURSIVE_KERNEL(arg.driver);
    }
    no_post
})


FUNC_WRAPPER( napi_gro_receive, ( struct napi_struct * napi , struct sk_buff * skb ), {
		WRAP_FUNC(napi->poll);
        return napi_gro_receive(napi, skb);
})

#if 0
FUNC_WRAPPER( skb_dma_unmap, (struct device *dev, struct sk_buff *skb, enum dma_data_direction dir), {
        return skb_dma_unmap(dev, skb, dir);
})
#endif
/*
FUNC_WRAPPER( vlan_gro_receive, (struct napi_struct *napi, struct vlan_group *grp, unsigned int vlan_tci, struct sk_buff *skb), {
        return vlan_gro_receive(napi, grp, vlan_tci, skb);
})
*/
FUNC_WRAPPER( pskb_expand_head, (struct sk_buff *skb, int nhead, int ntail, gfp_t gfp_mask), {
        return pskb_expand_head(skb, nhead, ntail, gfp_mask);
})
FUNC_WRAPPER( eth_type_trans, (struct sk_buff *skb, struct net_device *dev), {
        return eth_type_trans(skb, dev);
})

FUNC_WRAPPER( consume_skb, (struct sk_buff *skb), {
        return consume_skb( skb);
})

FUNC_WRAPPER( skb_copy, (const struct sk_buff *skb, gfp_t priority), {
        return skb_copy(skb, priority);
})

FUNC_WRAPPER( skb_gso_segment, (struct sk_buff *skb, int features), {
        return skb_gso_segment(skb,features);
})


FUNC_WRAPPER( __napi_schedule, (struct napi_struct *n), {
		WRAP_FUNC(n->poll);
        return __napi_schedule(n);
})


SET_TAINT_TRACKER(struct napi_struct, poll);
TYPE_WRAPPER(struct napi_struct, {
    pre {
        D( kern_printk("    napi_struct\n"); )
        WRAP_FUNC(arg.poll);

        WRAP_RECURSIVE_KERNEL(arg.dev);

    }
    no_post
})


TYPE_WRAPPER(struct device_driver, {
    pre {
        D( kern_printk("    device_driver\n"); )
        WRAP_FUNC(arg.probe);
        WRAP_FUNC(arg.remove);
        WRAP_FUNC(arg.shutdown);
        WRAP_FUNC(arg.suspend);
        WRAP_FUNC(arg.resume);
    }
    no_post
})

TYPE_WRAPPER(struct dev_pm_ops, {
    no_pre
    no_post
})


TYPE_WRAPPER(struct pci_error_handlers, {
    pre {
        D( kern_printk("    pci_error_handlers\n"); )
        WRAP_FUNC(arg.error_detected);
        WRAP_FUNC(arg.mmio_enabled);
        WRAP_FUNC(arg.link_reset);
        WRAP_FUNC(arg.slot_reset);
        WRAP_FUNC(arg.resume);
    }
    no_post
})

typedef int (each_kallsym_callback)(void *, const char *, struct module *, unsigned long);

TYPE_WRAPPER(each_kallsym_callback *, {
    pre {
        D( kern_printk("    each_kallsym_callback\n"); )
        WRAP_FUNC(arg);
    }
    no_post
})



TYPE_WRAPPER(poll, {
    pre {
        D( kern_printk("    poll\n"); )
        WRAP_FUNC(arg);
    }
    no_post
})

TYPE_WRAPPER(irq_handler_t, {
    pre {
        D( kern_printk("    irq_handler_t\n"); )
        WRAP_FUNC(arg);
    }
    no_post
})

TYPE_WRAPPER(handler, {
    pre {
        D( kern_printk("    handler\n"); )
        WRAP_FUNC(arg);
    }
    no_post
})

#endif /* CFI_WRAPPERS_HPP_ */
