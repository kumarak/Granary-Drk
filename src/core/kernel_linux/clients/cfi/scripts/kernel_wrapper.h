/* Auto-generated wrappers. */
FUNCTION_WRAPPER_VOID(posix_cpu_timers_exit_group, (struct task_struct *tsk), {
    PRE_WRAP(tsk);
    posix_cpu_timers_exit_group(tsk);
})

TYPE_WRAPPER(struct list_head, {
    PRE {
        PRE_WRAP(arg.next);
        PRE_WRAP(arg.prev);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct file_system_type, {
    PRE {
        WRAP_FUNCTION(arg.get_sb);
        WRAP_FUNCTION(arg.kill_sb);
        PRE_WRAP(arg.owner);
        PRE_WRAP(arg.next);
        PRE_WRAP(arg.fs_supers);
        PRE_WRAP(arg.s_lock_key);
        PRE_WRAP(arg.s_umount_key);
        PRE_WRAP(arg.i_lock_key);
        PRE_WRAP(arg.i_mutex_key);
        PRE_WRAP(arg.i_mutex_dir_key);
        PRE_WRAP(arg.i_alloc_sem_key);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(spinlock_t, {
    PRE {
        PRE_WRAP(arg.raw_lock);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct kmem_cache_node, {
    PRE {
        PRE_WRAP(arg.list_lock);
        PRE_WRAP(arg.partial);
        PRE_WRAP(arg.nr_slabs);
        PRE_WRAP(arg.total_objects);
        PRE_WRAP(arg.full);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct kref, {
    PRE {
        PRE_WRAP(arg.refcount);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct kobject, {
    PRE {
        PRE_WRAP(arg.entry);
        PRE_WRAP(arg.parent);
        PRE_WRAP(arg.kset);
        PRE_WRAP(arg.ktype);
        PRE_WRAP(arg.sd);
        PRE_WRAP(arg.kref);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct kmem_cache, {
    PRE {
        PRE_WRAP(arg.oo);
        PRE_WRAP(arg.local_node);
        PRE_WRAP(arg.max);
        PRE_WRAP(arg.min);
        WRAP_FUNCTION(arg.ctor);
        PRE_WRAP(arg.list);
        PRE_WRAP(arg.kobj);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct page, {
    PRE {
        PRE_WRAP(arg._count);
        PRE_WRAP(arg.lru);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct super_operations, {
    PRE {
        WRAP_FUNCTION(arg.alloc_inode);
        WRAP_FUNCTION(arg.destroy_inode);
        WRAP_FUNCTION(arg.dirty_inode);
        WRAP_FUNCTION(arg.write_inode);
        WRAP_FUNCTION(arg.drop_inode);
        WRAP_FUNCTION(arg.delete_inode);
        WRAP_FUNCTION(arg.put_super);
        WRAP_FUNCTION(arg.write_super);
        WRAP_FUNCTION(arg.sync_fs);
        WRAP_FUNCTION(arg.freeze_fs);
        WRAP_FUNCTION(arg.unfreeze_fs);
        WRAP_FUNCTION(arg.statfs);
        WRAP_FUNCTION(arg.remount_fs);
        WRAP_FUNCTION(arg.clear_inode);
        WRAP_FUNCTION(arg.umount_begin);
        WRAP_FUNCTION(arg.show_options);
        WRAP_FUNCTION(arg.show_stats);
        WRAP_FUNCTION(arg.quota_read);
        WRAP_FUNCTION(arg.quota_write);
        WRAP_FUNCTION(arg.bdev_try_to_free_page);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct dquot_operations, {
    PRE {
        WRAP_FUNCTION(arg.initialize);
        WRAP_FUNCTION(arg.drop);
        WRAP_FUNCTION(arg.alloc_space);
        WRAP_FUNCTION(arg.alloc_inode);
        WRAP_FUNCTION(arg.free_space);
        WRAP_FUNCTION(arg.free_inode);
        WRAP_FUNCTION(arg.transfer);
        WRAP_FUNCTION(arg.write_dquot);
        WRAP_FUNCTION(arg.alloc_dquot);
        WRAP_FUNCTION(arg.destroy_dquot);
        WRAP_FUNCTION(arg.acquire_dquot);
        WRAP_FUNCTION(arg.release_dquot);
        WRAP_FUNCTION(arg.mark_dirty);
        WRAP_FUNCTION(arg.write_info);
        WRAP_FUNCTION(arg.reserve_space);
        WRAP_FUNCTION(arg.claim_space);
        WRAP_FUNCTION(arg.release_rsv);
        WRAP_FUNCTION(arg.get_reserved_space);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct quotactl_ops, {
    PRE {
        WRAP_FUNCTION(arg.quota_on);
        WRAP_FUNCTION(arg.quota_off);
        WRAP_FUNCTION(arg.quota_sync);
        WRAP_FUNCTION(arg.get_info);
        WRAP_FUNCTION(arg.set_info);
        WRAP_FUNCTION(arg.get_dqblk);
        WRAP_FUNCTION(arg.set_dqblk);
        WRAP_FUNCTION(arg.get_xstate);
        WRAP_FUNCTION(arg.set_xstate);
        WRAP_FUNCTION(arg.get_xquota);
        WRAP_FUNCTION(arg.set_xquota);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct export_operations, {
    PRE {
        WRAP_FUNCTION(arg.encode_fh);
        WRAP_FUNCTION(arg.fh_to_dentry);
        WRAP_FUNCTION(arg.fh_to_parent);
        WRAP_FUNCTION(arg.get_name);
        WRAP_FUNCTION(arg.get_parent);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct hlist_node, {
    PRE {
        PRE_WRAP(arg.next);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct rcu_head, {
    PRE {
        PRE_WRAP(arg.next);
        WRAP_FUNCTION(arg.func);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct dentry, {
    PRE {
        PRE_WRAP(arg.d_count);
        PRE_WRAP(arg.d_lock);
        PRE_WRAP(arg.d_inode);
        PRE_WRAP(arg.d_hash);
        PRE_WRAP(arg.d_parent);
        PRE_WRAP(arg.d_name);
        PRE_WRAP(arg.d_lru);
        PRE_WRAP(arg.d_subdirs);
        PRE_WRAP(arg.d_alias);
        PRE_WRAP(arg.d_op);
        PRE_WRAP(arg.d_sb);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct rw_semaphore, {
    PRE {
        PRE_WRAP(arg.wait_lock);
        PRE_WRAP(arg.wait_list);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct mutex, {
    PRE {
        PRE_WRAP(arg.count);
        PRE_WRAP(arg.wait_lock);
        PRE_WRAP(arg.wait_list);
        PRE_WRAP(arg.owner);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct xattr_handler, {
    PRE {
        WRAP_FUNCTION(arg.list);
        WRAP_FUNCTION(arg.get);
        WRAP_FUNCTION(arg.set);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct hlist_head, {
    PRE {
        PRE_WRAP(arg.first);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct mem_dqinfo, {
    PRE {
        PRE_WRAP(arg.dqi_format);
        PRE_WRAP(arg.dqi_dirty_list);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct quota_info, {
    PRE {
        PRE_WRAP(arg.dqio_mutex);
        PRE_WRAP(arg.dqonoff_mutex);
        PRE_WRAP(arg.dqptr_sem);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct __wait_queue_head, {
    PRE {
        PRE_WRAP(arg.lock);
        PRE_WRAP(arg.task_list);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct super_block, {
    PRE {
        PRE_WRAP(arg.s_list);
        PRE_WRAP(arg.s_type);
        PRE_WRAP(arg.s_op);
        PRE_WRAP(arg.dq_op);
        PRE_WRAP(arg.s_qcop);
        PRE_WRAP(arg.s_export_op);
        PRE_WRAP(arg.s_root);
        PRE_WRAP(arg.s_umount);
        PRE_WRAP(arg.s_lock);
        PRE_WRAP(arg.s_active);
        PRE_WRAP(arg.s_inodes);
        PRE_WRAP(arg.s_anon);
        PRE_WRAP(arg.s_files);
        PRE_WRAP(arg.s_dentry_lru);
        PRE_WRAP(arg.s_bdev);
        PRE_WRAP(arg.s_bdi);
        PRE_WRAP(arg.s_mtd);
        PRE_WRAP(arg.s_instances);
        PRE_WRAP(arg.s_dquot);
        PRE_WRAP(arg.s_wait_unfrozen);
        PRE_WRAP(arg.s_vfs_rename_mutex);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER(dquot_scan_active, (struct super_block *sb, fn_scan fn, unsigned long priv), {
    PRE_WRAP(sb);
    WRAP_FUNCTION(fn);
    int ret = dquot_scan_active(sb, fn, priv);
    RETURN_WRAP(ret);
    return ret;
})

TYPE_WRAPPER(struct inode_operations, {
    PRE {
        WRAP_FUNCTION(arg.create);
        WRAP_FUNCTION(arg.lookup);
        WRAP_FUNCTION(arg.link);
        WRAP_FUNCTION(arg.unlink);
        WRAP_FUNCTION(arg.symlink);
        WRAP_FUNCTION(arg.mkdir);
        WRAP_FUNCTION(arg.rmdir);
        WRAP_FUNCTION(arg.mknod);
        WRAP_FUNCTION(arg.rename);
        WRAP_FUNCTION(arg.readlink);
        WRAP_FUNCTION(arg.follow_link);
        WRAP_FUNCTION(arg.put_link);
        WRAP_FUNCTION(arg.truncate);
        WRAP_FUNCTION(arg.permission);
        WRAP_FUNCTION(arg.check_acl);
        WRAP_FUNCTION(arg.setattr);
        WRAP_FUNCTION(arg.getattr);
        WRAP_FUNCTION(arg.setxattr);
        WRAP_FUNCTION(arg.getxattr);
        WRAP_FUNCTION(arg.listxattr);
        WRAP_FUNCTION(arg.removexattr);
        WRAP_FUNCTION(arg.truncate_range);
        WRAP_FUNCTION(arg.fallocate);
        WRAP_FUNCTION(arg.fiemap);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct file_operations, {
    PRE {
        PRE_WRAP(arg.owner);
        WRAP_FUNCTION(arg.llseek);
        WRAP_FUNCTION(arg.read);
        WRAP_FUNCTION(arg.write);
        WRAP_FUNCTION(arg.aio_read);
        WRAP_FUNCTION(arg.aio_write);
        WRAP_FUNCTION(arg.readdir);
        WRAP_FUNCTION(arg.poll);
        WRAP_FUNCTION(arg.ioctl);
        WRAP_FUNCTION(arg.unlocked_ioctl);
        WRAP_FUNCTION(arg.compat_ioctl);
        WRAP_FUNCTION(arg.mmap);
        WRAP_FUNCTION(arg.open);
        WRAP_FUNCTION(arg.flush);
        WRAP_FUNCTION(arg.release);
        WRAP_FUNCTION(arg.fsync);
        WRAP_FUNCTION(arg.aio_fsync);
        WRAP_FUNCTION(arg.fasync);
        WRAP_FUNCTION(arg.lock);
        WRAP_FUNCTION(arg.sendpage);
        WRAP_FUNCTION(arg.get_unmapped_area);
        WRAP_FUNCTION(arg.check_flags);
        WRAP_FUNCTION(arg.flock);
        WRAP_FUNCTION(arg.splice_write);
        WRAP_FUNCTION(arg.splice_read);
        WRAP_FUNCTION(arg.setlease);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct radix_tree_root, {
    PRE {
        PRE_WRAP(arg.rnode);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct prio_tree_root, {
    PRE {
        PRE_WRAP(arg.prio_tree_node);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct address_space_operations, {
    PRE {
        WRAP_FUNCTION(arg.writepage);
        WRAP_FUNCTION(arg.readpage);
        WRAP_FUNCTION(arg.sync_page);
        WRAP_FUNCTION(arg.writepages);
        WRAP_FUNCTION(arg.set_page_dirty);
        WRAP_FUNCTION(arg.readpages);
        WRAP_FUNCTION(arg.write_begin);
        WRAP_FUNCTION(arg.write_end);
        WRAP_FUNCTION(arg.bmap);
        WRAP_FUNCTION(arg.invalidatepage);
        WRAP_FUNCTION(arg.releasepage);
        WRAP_FUNCTION(arg.direct_IO);
        WRAP_FUNCTION(arg.get_xip_mem);
        WRAP_FUNCTION(arg.migratepage);
        WRAP_FUNCTION(arg.launder_page);
        WRAP_FUNCTION(arg.is_partially_uptodate);
        WRAP_FUNCTION(arg.error_remove_page);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct address_space, {
    PRE {
        PRE_WRAP(arg.host);
        PRE_WRAP(arg.page_tree);
        PRE_WRAP(arg.tree_lock);
        PRE_WRAP(arg.i_mmap);
        PRE_WRAP(arg.i_mmap_nonlinear);
        PRE_WRAP(arg.i_mmap_lock);
        PRE_WRAP(arg.a_ops);
        PRE_WRAP(arg.backing_dev_info);
        PRE_WRAP(arg.private_lock);
        PRE_WRAP(arg.private_list);
        PRE_WRAP(arg.assoc_mapping);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct inode, {
    PRE {
        PRE_WRAP(arg.i_hash);
        PRE_WRAP(arg.i_list);
        PRE_WRAP(arg.i_sb_list);
        PRE_WRAP(arg.i_dentry);
        PRE_WRAP(arg.i_count);
        PRE_WRAP(arg.i_atime);
        PRE_WRAP(arg.i_mtime);
        PRE_WRAP(arg.i_ctime);
        PRE_WRAP(arg.i_lock);
        PRE_WRAP(arg.i_mutex);
        PRE_WRAP(arg.i_alloc_sem);
        PRE_WRAP(arg.i_op);
        PRE_WRAP(arg.i_fop);
        PRE_WRAP(arg.i_sb);
        PRE_WRAP(arg.i_flock);
        PRE_WRAP(arg.i_mapping);
        PRE_WRAP(arg.i_data);
        PRE_WRAP(arg.i_devices);
        PRE_WRAP(arg.i_fsnotify_mark_entries);
        PRE_WRAP(arg.inotify_watches);
        PRE_WRAP(arg.inotify_mutex);
        PRE_WRAP(arg.i_writecount);
        PRE_WRAP(arg.i_acl);
        PRE_WRAP(arg.i_default_acl);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct block_device, {
    PRE {
        PRE_WRAP(arg.bd_inode);
        PRE_WRAP(arg.bd_super);
        PRE_WRAP(arg.bd_mutex);
        PRE_WRAP(arg.bd_inodes);
        PRE_WRAP(arg.bd_holder_list);
        PRE_WRAP(arg.bd_contains);
        PRE_WRAP(arg.bd_part);
        PRE_WRAP(arg.bd_disk);
        PRE_WRAP(arg.bd_list);
        PRE_WRAP(arg.bd_fsfreeze_mutex);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER(mb_cache_entry_get, (struct mb_cache *cache, struct block_device *bdev, sector_t block), {
    PRE_WRAP(cache);
    PRE_WRAP(bdev);
    struct mb_cache_entry *ret = mb_cache_entry_get(cache, bdev, block);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(dbg_pnp_show_resources, (struct pnp_dev *dev, char *desc), {
    PRE_WRAP(dev);
    dbg_pnp_show_resources(dev, desc);
})

TYPE_WRAPPER(struct posix_acl, {
    PRE {
        PRE_WRAP(arg.a_refcount);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER(posix_acl_chmod_masq, (struct posix_acl *acl, mode_t mode), {
    PRE_WRAP(acl);
    int ret = posix_acl_chmod_masq(acl, mode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_auto_config_dev, (struct pnp_dev *dev), {
    PRE_WRAP(dev);
    int ret = pnp_auto_config_dev(dev);
    RETURN_WRAP(ret);
    return ret;
})

TYPE_WRAPPER(rwlock_t, {
    PRE {
        PRE_WRAP(arg.raw_lock);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER(_read_lock_irqsave, (rwlock_t *lock), {
    PRE_WRAP(lock);
    long ret = _read_lock_irqsave(lock);
    RETURN_WRAP(ret);
    return ret;
})

TYPE_WRAPPER(struct journal_superblock_s, {
    PRE {
        PRE_WRAP(arg.s_header);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct timer_list, {
    PRE {
        PRE_WRAP(arg.entry);
        WRAP_FUNCTION(arg.function);
        PRE_WRAP(arg.base);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct journal_s, {
    PRE {
        PRE_WRAP(arg.j_sb_buffer);
        PRE_WRAP(arg.j_superblock);
        PRE_WRAP(arg.j_state_lock);
        PRE_WRAP(arg.j_barrier);
        PRE_WRAP(arg.j_running_transaction);
        PRE_WRAP(arg.j_committing_transaction);
        PRE_WRAP(arg.j_checkpoint_transactions);
        PRE_WRAP(arg.j_wait_transaction_locked);
        PRE_WRAP(arg.j_wait_logspace);
        PRE_WRAP(arg.j_wait_done_commit);
        PRE_WRAP(arg.j_wait_checkpoint);
        PRE_WRAP(arg.j_wait_commit);
        PRE_WRAP(arg.j_wait_updates);
        PRE_WRAP(arg.j_checkpoint_mutex);
        PRE_WRAP(arg.j_dev);
        PRE_WRAP(arg.j_fs_dev);
        PRE_WRAP(arg.j_list_lock);
        PRE_WRAP(arg.j_inode);
        PRE_WRAP(arg.j_task);
        PRE_WRAP(arg.j_commit_timer);
        PRE_WRAP(arg.j_revoke_lock);
        PRE_WRAP(arg.j_revoke);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER(journal_test_revoke, (journal_t *journal, unsigned int blocknr, tid_t sequence), {
    PRE_WRAP(journal);
    int ret = journal_test_revoke(journal, blocknr, sequence);
    RETURN_WRAP(ret);
    return ret;
})

TYPE_WRAPPER(struct sk_buff, {
    PRE {
        PRE_WRAP(arg.next);
        PRE_WRAP(arg.prev);
        PRE_WRAP(arg.sk);
        PRE_WRAP(arg.dev);
        WRAP_FUNCTION(arg.destructor);
        PRE_WRAP(arg.users);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct net_device_ops, {
    PRE {
        WRAP_FUNCTION(arg.ndo_init);
        WRAP_FUNCTION(arg.ndo_uninit);
        WRAP_FUNCTION(arg.ndo_open);
        WRAP_FUNCTION(arg.ndo_stop);
        WRAP_FUNCTION(arg.ndo_start_xmit);
        WRAP_FUNCTION(arg.ndo_select_queue);
        WRAP_FUNCTION(arg.ndo_change_rx_flags);
        WRAP_FUNCTION(arg.ndo_set_rx_mode);
        WRAP_FUNCTION(arg.ndo_set_multicast_list);
        WRAP_FUNCTION(arg.ndo_set_mac_address);
        WRAP_FUNCTION(arg.ndo_validate_addr);
        WRAP_FUNCTION(arg.ndo_do_ioctl);
        WRAP_FUNCTION(arg.ndo_set_config);
        WRAP_FUNCTION(arg.ndo_change_mtu);
        WRAP_FUNCTION(arg.ndo_neigh_setup);
        WRAP_FUNCTION(arg.ndo_tx_timeout);
        WRAP_FUNCTION(arg.ndo_get_stats);
        WRAP_FUNCTION(arg.ndo_vlan_rx_register);
        WRAP_FUNCTION(arg.ndo_vlan_rx_add_vid);
        WRAP_FUNCTION(arg.ndo_vlan_rx_kill_vid);
        WRAP_FUNCTION(arg.ndo_poll_controller);
        WRAP_FUNCTION(arg.ndo_fcoe_enable);
        WRAP_FUNCTION(arg.ndo_fcoe_disable);
        WRAP_FUNCTION(arg.ndo_fcoe_ddp_setup);
        WRAP_FUNCTION(arg.ndo_fcoe_ddp_done);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct ethtool_ops, {
    PRE {
        WRAP_FUNCTION(arg.get_settings);
        WRAP_FUNCTION(arg.set_settings);
        WRAP_FUNCTION(arg.get_drvinfo);
        WRAP_FUNCTION(arg.get_regs_len);
        WRAP_FUNCTION(arg.get_regs);
        WRAP_FUNCTION(arg.get_wol);
        WRAP_FUNCTION(arg.set_wol);
        WRAP_FUNCTION(arg.get_msglevel);
        WRAP_FUNCTION(arg.set_msglevel);
        WRAP_FUNCTION(arg.nway_reset);
        WRAP_FUNCTION(arg.get_link);
        WRAP_FUNCTION(arg.get_eeprom_len);
        WRAP_FUNCTION(arg.get_eeprom);
        WRAP_FUNCTION(arg.set_eeprom);
        WRAP_FUNCTION(arg.get_coalesce);
        WRAP_FUNCTION(arg.set_coalesce);
        WRAP_FUNCTION(arg.get_ringparam);
        WRAP_FUNCTION(arg.set_ringparam);
        WRAP_FUNCTION(arg.get_pauseparam);
        WRAP_FUNCTION(arg.set_pauseparam);
        WRAP_FUNCTION(arg.get_rx_csum);
        WRAP_FUNCTION(arg.set_rx_csum);
        WRAP_FUNCTION(arg.get_tx_csum);
        WRAP_FUNCTION(arg.set_tx_csum);
        WRAP_FUNCTION(arg.get_sg);
        WRAP_FUNCTION(arg.set_sg);
        WRAP_FUNCTION(arg.get_tso);
        WRAP_FUNCTION(arg.set_tso);
        WRAP_FUNCTION(arg.self_test);
        WRAP_FUNCTION(arg.get_strings);
        WRAP_FUNCTION(arg.phys_id);
        WRAP_FUNCTION(arg.get_ethtool_stats);
        WRAP_FUNCTION(arg.begin);
        WRAP_FUNCTION(arg.complete);
        WRAP_FUNCTION(arg.get_ufo);
        WRAP_FUNCTION(arg.set_ufo);
        WRAP_FUNCTION(arg.get_flags);
        WRAP_FUNCTION(arg.set_flags);
        WRAP_FUNCTION(arg.get_priv_flags);
        WRAP_FUNCTION(arg.set_priv_flags);
        WRAP_FUNCTION(arg.get_sset_count);
        WRAP_FUNCTION(arg.self_test_count);
        WRAP_FUNCTION(arg.get_stats_count);
        WRAP_FUNCTION(arg.get_rxnfc);
        WRAP_FUNCTION(arg.set_rxnfc);
        WRAP_FUNCTION(arg.flash_device);
        WRAP_FUNCTION(arg.reset);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct netdev_hw_addr_list, {
    PRE {
        PRE_WRAP(arg.list);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct netdev_queue, {
    PRE {
        PRE_WRAP(arg.dev);
        PRE_WRAP(arg.qdisc);
        PRE_WRAP(arg.qdisc_sleeping);
        PRE_WRAP(arg._xmit_lock);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct semaphore, {
    PRE {
        PRE_WRAP(arg.lock);
        PRE_WRAP(arg.wait_list);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct work_struct, {
    PRE {
        PRE_WRAP(arg.data);
        PRE_WRAP(arg.entry);
        WRAP_FUNCTION(arg.func);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct dev_pm_info, {
    PRE {
        PRE_WRAP(arg.power_state);
        PRE_WRAP(arg.entry);
        PRE_WRAP(arg.suspend_timer);
        PRE_WRAP(arg.work);
        PRE_WRAP(arg.wait_queue);
        PRE_WRAP(arg.lock);
        PRE_WRAP(arg.usage_count);
        PRE_WRAP(arg.child_count);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct dev_archdata, {
    PRE {
        PRE_WRAP(arg.dma_ops);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct klist_node, {
    PRE {
        PRE_WRAP(arg.n_node);
        PRE_WRAP(arg.n_ref);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct device, {
    PRE {
        PRE_WRAP(arg.parent);
        PRE_WRAP(arg.p);
        PRE_WRAP(arg.kobj);
        PRE_WRAP(arg.type);
        PRE_WRAP(arg.sem);
        PRE_WRAP(arg.bus);
        PRE_WRAP(arg.driver);
        PRE_WRAP(arg.power);
        PRE_WRAP(arg.dma_parms);
        PRE_WRAP(arg.dma_pools);
        PRE_WRAP(arg.dma_mem);
        PRE_WRAP(arg.archdata);
        PRE_WRAP(arg.devres_lock);
        PRE_WRAP(arg.devres_head);
        PRE_WRAP(arg.knode_class);
        PRE_WRAP(arg.class1);
        WRAP_FUNCTION(arg.release);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct net_device, {
    PRE {
        PRE_WRAP(arg.name_hlist);
        PRE_WRAP(arg.dev_list);
        PRE_WRAP(arg.napi_list);
        PRE_WRAP(arg.stats);
        PRE_WRAP(arg.wireless_handlers);
        PRE_WRAP(arg.wireless_data);
        PRE_WRAP(arg.netdev_ops);
        PRE_WRAP(arg.ethtool_ops);
        PRE_WRAP(arg.header_ops);
        PRE_WRAP(arg.master);
        PRE_WRAP(arg.uc);
        PRE_WRAP(arg.addr_list_lock);
        PRE_WRAP(arg.mc_list);
        PRE_WRAP(arg.ieee80211_ptr);
        PRE_WRAP(arg.dev_addrs);
        PRE_WRAP(arg.rx_queue);
        PRE_WRAP(arg._tx);
        PRE_WRAP(arg.qdisc);
        PRE_WRAP(arg.tx_global_lock);
        PRE_WRAP(arg.watchdog_timer);
        PRE_WRAP(arg.refcnt);
        PRE_WRAP(arg.todo_list);
        PRE_WRAP(arg.index_hlist);
        PRE_WRAP(arg.link_watch_next);
        WRAP_FUNCTION(arg.destructor);
        PRE_WRAP(arg.npinfo);
        PRE_WRAP(arg.br_port);
        PRE_WRAP(arg.macvlan_port);
        PRE_WRAP(arg.garp_port);
        PRE_WRAP(arg.dev);
        PRE_WRAP(arg.rtnl_link_ops);
        PRE_WRAP(arg.dcbnl_ops);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER(alloc_netdev_mq, (int sizeof_priv, const char *name, void (*setup)(struct net_device *), unsigned int queue_count), {
    WRAP_FUNCTION(setup);
    struct net_device *ret = alloc_netdev_mq(sizeof_priv, name, setup, queue_count);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(proc_sched_set_task, (struct task_struct *p), {
    PRE_WRAP(p);
    proc_sched_set_task(p);
})

FUNCTION_WRAPPER(param_set_uint, (const char *val, struct kernel_param *kp), {
    PRE_WRAP(kp);
    int ret = param_set_uint(val, kp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_file_splice_write, (struct pipe_inode_info *pipe, struct file *out, loff_t *ppos, size_t len, unsigned int flags), {
    PRE_WRAP(pipe);
    PRE_WRAP(out);
    ssize_t ret = generic_file_splice_write(pipe, out, ppos, len, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(eth_type_trans, (struct sk_buff *skb, struct net_device *dev), {
    PRE_WRAP(skb);
    PRE_WRAP(dev);
    u16 ret = eth_type_trans(skb, dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dquot_alloc_space, (struct inode *inode, qsize_t number, int warn), {
    PRE_WRAP(inode);
    int ret = dquot_alloc_space(inode, number, warn);
    RETURN_WRAP(ret);
    return ret;
})

TYPE_WRAPPER(struct resource, {
    PRE {
        PRE_WRAP(arg.parent);
        PRE_WRAP(arg.sibling);
        PRE_WRAP(arg.child);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct pci_bus, {
    PRE {
        PRE_WRAP(arg.node);
        PRE_WRAP(arg.parent);
        PRE_WRAP(arg.children);
        PRE_WRAP(arg.devices);
        PRE_WRAP(arg.self);
        PRE_WRAP(arg.slots);
        PRE_WRAP(arg.ops);
        PRE_WRAP(arg.procdir);
        PRE_WRAP(arg.bridge);
        PRE_WRAP(arg.dev);
        PRE_WRAP(arg.legacy_io);
        PRE_WRAP(arg.legacy_mem);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER(pci_scan_bus_parented, (struct device *parent, int bus, struct pci_ops *ops, void *sysdata), {
    PRE_WRAP(parent);
    PRE_WRAP(ops);
    struct pci_bus *ret = pci_scan_bus_parented(parent, bus, ops, sysdata);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(add_timer, (struct timer_list *timer), {
    PRE_WRAP(timer);
    add_timer(timer);
})

FUNCTION_WRAPPER(jbd2_journal_blocks_per_page, (struct inode *inode), {
    PRE_WRAP(inode);
    int ret = jbd2_journal_blocks_per_page(inode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pskb_expand_head, (struct sk_buff *skb, int nhead, int ntail, gfp_t gfp_mask), {
    PRE_WRAP(skb);
    int ret = pskb_expand_head(skb, nhead, ntail, gfp_mask);
    RETURN_WRAP(ret);
    return ret;
})

TYPE_WRAPPER(struct rb_node, {
    PRE {
        PRE_WRAP(arg.rb_right);
        PRE_WRAP(arg.rb_left);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct sched_entity, {
    PRE {
        PRE_WRAP(arg.load);
        PRE_WRAP(arg.run_node);
        PRE_WRAP(arg.group_node);
        PRE_WRAP(arg.parent);
        PRE_WRAP(arg.cfs_rq);
        PRE_WRAP(arg.my_q);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct sched_rt_entity, {
    PRE {
        PRE_WRAP(arg.run_list);
        PRE_WRAP(arg.back);
        PRE_WRAP(arg.parent);
        PRE_WRAP(arg.rt_rq);
        PRE_WRAP(arg.my_q);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct plist_head, {
    PRE {
        PRE_WRAP(arg.prio_list);
        PRE_WRAP(arg.node_list);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct plist_node, {
    PRE {
        PRE_WRAP(arg.plist);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct pid_link, {
    PRE {
        PRE_WRAP(arg.node);
        PRE_WRAP(arg.pid);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct completion, {
    PRE {
        PRE_WRAP(arg.wait);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct sysv_sem, {
    PRE {
        PRE_WRAP(arg.undo_list);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct thread_struct, {
    PRE {
        PRE_WRAP(arg.ds_ctx);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct sigpending, {
    PRE {
        PRE_WRAP(arg.list);
        PRE_WRAP(arg.signal);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct prop_local_single, {
    PRE {
        PRE_WRAP(arg.lock);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct task_struct, {
    PRE {
        PRE_WRAP(arg.usage);
        PRE_WRAP(arg.sched_class);
        PRE_WRAP(arg.se);
        PRE_WRAP(arg.rt);
        PRE_WRAP(arg.preempt_notifiers);
        PRE_WRAP(arg.cpus_allowed);
        PRE_WRAP(arg.sched_info);
        PRE_WRAP(arg.tasks);
        PRE_WRAP(arg.pushable_tasks);
        PRE_WRAP(arg.mm);
        PRE_WRAP(arg.active_mm);
        PRE_WRAP(arg.real_parent);
        PRE_WRAP(arg.parent);
        PRE_WRAP(arg.children);
        PRE_WRAP(arg.sibling);
        PRE_WRAP(arg.group_leader);
        PRE_WRAP(arg.ptraced);
        PRE_WRAP(arg.ptrace_entry);
        PRE_WRAP(arg.bts);
        PRE_WRAP(arg.thread_group);
        PRE_WRAP(arg.vfork_done);
        PRE_WRAP(arg.start_time);
        PRE_WRAP(arg.real_start_time);
        PRE_WRAP(arg.cputime_expires);
        PRE_WRAP(arg.real_cred);
        PRE_WRAP(arg.cred);
        PRE_WRAP(arg.cred_guard_mutex);
        PRE_WRAP(arg.replacement_session_keyring);
        PRE_WRAP(arg.sysvsem);
        PRE_WRAP(arg.thread);
        PRE_WRAP(arg.fs);
        PRE_WRAP(arg.files);
        PRE_WRAP(arg.nsproxy);
        PRE_WRAP(arg.signal);
        PRE_WRAP(arg.sighand);
        PRE_WRAP(arg.blocked);
        PRE_WRAP(arg.real_blocked);
        PRE_WRAP(arg.saved_sigmask);
        PRE_WRAP(arg.pending);
        WRAP_FUNCTION(arg.notifier);
        PRE_WRAP(arg.notifier_mask);
        PRE_WRAP(arg.audit_context);
        PRE_WRAP(arg.seccomp);
        PRE_WRAP(arg.alloc_lock);
        PRE_WRAP(arg.irqaction);
        PRE_WRAP(arg.pi_lock);
        PRE_WRAP(arg.pi_waiters);
        PRE_WRAP(arg.pi_blocked_on);
        PRE_WRAP(arg.bio_list);
        PRE_WRAP(arg.reclaim_state);
        PRE_WRAP(arg.backing_dev_info);
        PRE_WRAP(arg.io_context);
        PRE_WRAP(arg.last_siginfo);
        PRE_WRAP(arg.ioac);
        PRE_WRAP(arg.mems_allowed);
        PRE_WRAP(arg.cgroups);
        PRE_WRAP(arg.cg_list);
        PRE_WRAP(arg.robust_list);
        PRE_WRAP(arg.compat_robust_list);
        PRE_WRAP(arg.pi_state_list);
        PRE_WRAP(arg.pi_state_cache);
        PRE_WRAP(arg.perf_event_ctxp);
        PRE_WRAP(arg.perf_event_mutex);
        PRE_WRAP(arg.perf_event_list);
        PRE_WRAP(arg.mempolicy);
        PRE_WRAP(arg.fs_excl);
        PRE_WRAP(arg.rcu);
        PRE_WRAP(arg.splice_pipe);
        PRE_WRAP(arg.dirties);
        PRE_WRAP(arg.scm_work_list);
        PRE_WRAP(arg.ret_stack);
        PRE_WRAP(arg.trace_overrun);
        PRE_WRAP(arg.tracing_graph_pause);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER(generic_ptrace_pokedata, (struct task_struct *tsk, long addr, long data), {
    PRE_WRAP(tsk);
    int ret = generic_ptrace_pokedata(tsk, addr, data);
    RETURN_WRAP(ret);
    return ret;
})

TYPE_WRAPPER(struct buffer_head, {
    PRE {
        PRE_WRAP(arg.b_this_page);
        PRE_WRAP(arg.b_page);
        PRE_WRAP(arg.b_bdev);
        WRAP_FUNCTION(arg.b_end_io);
        PRE_WRAP(arg.b_assoc_buffers);
        PRE_WRAP(arg.b_assoc_map);
        PRE_WRAP(arg.b_count);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER_VOID(end_buffer_write_sync, (struct buffer_head *bh, int uptodate), {
    PRE_WRAP(bh);
    end_buffer_write_sync(bh, uptodate);
})

FUNCTION_WRAPPER_VOID(jbd2_journal_switch_revoke_table, (journal_t *journal), {
    PRE_WRAP(journal);
    jbd2_journal_switch_revoke_table(journal);
})

TYPE_WRAPPER(struct pci_dev, {
    PRE {
        PRE_WRAP(arg.bus_list);
        PRE_WRAP(arg.bus);
        PRE_WRAP(arg.subordinate);
        PRE_WRAP(arg.procent);
        PRE_WRAP(arg.slot);
        PRE_WRAP(arg.driver);
        PRE_WRAP(arg.dma_parms);
        PRE_WRAP(arg.dev);
        PRE_WRAP(arg.enable_cnt);
        PRE_WRAP(arg.saved_cap_space);
        PRE_WRAP(arg.rom_attr);
        PRE_WRAP(arg.msi_list);
        PRE_WRAP(arg.vpd);
        PRE_WRAP(arg.ats);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER(ata_pci_sff_prepare_host, (struct pci_dev *pdev, const struct ata_port_info ** const ppi, struct ata_host **r_host), {
    PRE_WRAP(pdev);
    int ret = ata_pci_sff_prepare_host(pdev, ppi, r_host);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sata_link_resume, (struct ata_link *link, unsigned const long *params, unsigned long deadline), {
    PRE_WRAP(link);
    int ret = sata_link_resume(link, params, deadline);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(get_seconds, (), {
    long ret = get_seconds();
    RETURN_WRAP(ret);
    return ret;
})

TYPE_WRAPPER(struct mii_bus, {
    PRE {
        WRAP_FUNCTION(arg.read);
        WRAP_FUNCTION(arg.write);
        WRAP_FUNCTION(arg.reset);
        PRE_WRAP(arg.mdio_lock);
        PRE_WRAP(arg.parent);
        PRE_WRAP(arg.dev);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER_VOID(mdiobus_free, (struct mii_bus *bus), {
    PRE_WRAP(bus);
    mdiobus_free(bus);
})

FUNCTION_WRAPPER_VOID(proc_tty_register_driver, (struct tty_driver *driver), {
    PRE_WRAP(driver);
    proc_tty_register_driver(driver);
})

FUNCTION_WRAPPER(generic_block_fiemap, (struct inode *inode, struct fiemap_extent_info *fieinfo, u64 start, u64 len, get_block_t get_block), {
    PRE_WRAP(inode);
    PRE_WRAP(fieinfo);
    WRAP_FUNCTION(get_block);
    int ret = generic_block_fiemap(inode, fieinfo, start, len, get_block);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_write, (struct xenbus_transaction t, const char *dir, const char *node, const char *string), {
    PRE_WRAP(t);
    int ret = xenbus_write(t, dir, node, string);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(block_invalidatepage, (struct page *page, unsigned long offset), {
    PRE_WRAP(page);
    block_invalidatepage(page, offset);
})

FUNCTION_WRAPPER(sock_no_sendmsg, (struct kiocb *iocb, struct socket *sock, struct msghdr *m, size_t len), {
    PRE_WRAP(iocb);
    PRE_WRAP(sock);
    PRE_WRAP(m);
    int ret = sock_no_sendmsg(iocb, sock, m, len);
    RETURN_WRAP(ret);
    return ret;
})

TYPE_WRAPPER(struct xenbus_watch, {
    PRE {
        PRE_WRAP(arg.list);
        WRAP_FUNCTION(arg.callback);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct xenbus_device, {
    PRE {
        PRE_WRAP(arg.otherend_watch);
        PRE_WRAP(arg.dev);
        PRE_WRAP(arg.down);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct dev_pm_ops, {
    PRE {
        WRAP_FUNCTION(arg.prepare);
        WRAP_FUNCTION(arg.complete);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.resume);
        WRAP_FUNCTION(arg.freeze);
        WRAP_FUNCTION(arg.thaw);
        WRAP_FUNCTION(arg.poweroff);
        WRAP_FUNCTION(arg.restore);
        WRAP_FUNCTION(arg.suspend_noirq);
        WRAP_FUNCTION(arg.resume_noirq);
        WRAP_FUNCTION(arg.freeze_noirq);
        WRAP_FUNCTION(arg.thaw_noirq);
        WRAP_FUNCTION(arg.poweroff_noirq);
        WRAP_FUNCTION(arg.restore_noirq);
        WRAP_FUNCTION(arg.runtime_suspend);
        WRAP_FUNCTION(arg.runtime_resume);
        WRAP_FUNCTION(arg.runtime_idle);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct device_driver, {
    PRE {
        PRE_WRAP(arg.bus);
        PRE_WRAP(arg.owner);
        WRAP_FUNCTION(arg.probe);
        WRAP_FUNCTION(arg.remove);
        WRAP_FUNCTION(arg.shutdown);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.resume);
        PRE_WRAP(arg.pm);
        PRE_WRAP(arg.p);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct xenbus_driver, {
    PRE {
        PRE_WRAP(arg.owner);
        PRE_WRAP(arg.ids);
        WRAP_FUNCTION(arg.probe);
        WRAP_FUNCTION(arg.otherend_changed);
        WRAP_FUNCTION(arg.remove);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.resume);
        WRAP_FUNCTION(arg.uevent);
        PRE_WRAP(arg.driver);
        WRAP_FUNCTION(arg.read_otherend_details);
        WRAP_FUNCTION(arg.is_ready);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER_VOID(xenbus_unregister_driver, (struct xenbus_driver *drv), {
    PRE_WRAP(drv);
    xenbus_unregister_driver(drv);
})

FUNCTION_WRAPPER(vfs_cancel_lock, (struct file *filp, struct file_lock *fl), {
    PRE_WRAP(filp);
    PRE_WRAP(fl);
    int ret = vfs_cancel_lock(filp, fl);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(alloc_buffer_head, (gfp_t gfp_flags), {
    struct buffer_head *ret = alloc_buffer_head(gfp_flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(journal_remove_journal_head, (struct buffer_head *bh), {
    PRE_WRAP(bh);
    journal_remove_journal_head(bh);
})

TYPE_WRAPPER(struct phy_driver, {
    PRE {
        WRAP_FUNCTION(arg.config_init);
        WRAP_FUNCTION(arg.probe);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.resume);
        WRAP_FUNCTION(arg.config_aneg);
        WRAP_FUNCTION(arg.read_status);
        WRAP_FUNCTION(arg.ack_interrupt);
        WRAP_FUNCTION(arg.config_intr);
        WRAP_FUNCTION(arg.did_interrupt);
        WRAP_FUNCTION(arg.remove);
        PRE_WRAP(arg.driver);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct delayed_work, {
    PRE {
        PRE_WRAP(arg.work);
        PRE_WRAP(arg.timer);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct phy_device, {
    PRE {
        PRE_WRAP(arg.drv);
        PRE_WRAP(arg.bus);
        PRE_WRAP(arg.dev);
        PRE_WRAP(arg.phy_queue);
        PRE_WRAP(arg.state_queue);
        PRE_WRAP(arg.irq_disable);
        PRE_WRAP(arg.lock);
        PRE_WRAP(arg.attached_dev);
        WRAP_FUNCTION(arg.adjust_link);
        WRAP_FUNCTION(arg.adjust_state);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER(phy_ethtool_sset, (struct phy_device *phydev, struct ethtool_cmd *cmd), {
    PRE_WRAP(phydev);
    PRE_WRAP(cmd);
    int ret = phy_ethtool_sset(phydev, cmd);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dmi_match, (enum dmi_field f, const char *str), {
    bool ret = dmi_match(f, str);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(d_alloc_root, (struct inode *root_inode), {
    PRE_WRAP(root_inode);
    struct dentry *ret = d_alloc_root(root_inode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(kmem_cache_destroy, (struct kmem_cache *s), {
    PRE_WRAP(s);
    kmem_cache_destroy(s);
})

TYPE_WRAPPER(struct napi_struct, {
    PRE {
        PRE_WRAP(arg.poll_list);
        WRAP_FUNCTION(arg.poll);
        PRE_WRAP(arg.poll_lock);
        PRE_WRAP(arg.dev);
        PRE_WRAP(arg.dev_list);
        PRE_WRAP(arg.gro_list);
        PRE_WRAP(arg.skb);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER(vlan_gro_receive, (struct napi_struct *napi, struct vlan_group *grp, unsigned int vlan_tci, struct sk_buff *skb), {
    PRE_WRAP(napi);
    PRE_WRAP(grp);
    PRE_WRAP(skb);
    int ret = vlan_gro_receive(napi, grp, vlan_tci, skb);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(sata_pmp_error_handler, (struct ata_port *ap), {
    PRE_WRAP(ap);
    sata_pmp_error_handler(ap);
})

FUNCTION_WRAPPER(pci_set_dma_mask, (struct pci_dev *dev, unsigned long mask), {
    PRE_WRAP(dev);
    int ret = pci_set_dma_mask(dev, mask);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pm_qos_add_requirement, (int pm_qos_class, char *name, s32 value), {
    int ret = pm_qos_add_requirement(pm_qos_class, name, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(ll_rw_block, (int rw, int nr, struct buffer_head * bhs[]), {
    ll_rw_block(rw, nr, bhs);
})

FUNCTION_WRAPPER(journal_release, (struct reiserfs_transaction_handle *th, struct super_block *sb), {
    PRE_WRAP(th);
    PRE_WRAP(sb);
    int ret = journal_release(th, sb);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_uevent, (struct device *dev, struct kobj_uevent_env *env), {
    PRE_WRAP(dev);
    PRE_WRAP(env);
    int ret = pci_uevent(dev, env);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(finish_wait, (wait_queue_head_t *q, wait_queue_t *wait), {
    PRE_WRAP(q);
    PRE_WRAP(wait);
    finish_wait(q, wait);
})

FUNCTION_WRAPPER_VOID(pci_msi_off, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_msi_off(dev);
})

FUNCTION_WRAPPER(phy_connect, (struct net_device *dev, const char *bus_id, void (*handler)(struct net_device *), u32 flags, phy_interface_t interface), {
    PRE_WRAP(dev);
    WRAP_FUNCTION(handler);
    struct phy_device *ret = phy_connect(dev, bus_id, handler, flags, interface);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(device_create, (struct class_decl *class_ele, struct device *parent, dev_t devt, void *drvdata, const char *fmt, ...), {
    // TODO: variadic arguments
    PRE_WRAP(class_ele);
    PRE_WRAP(parent);
    struct device *ret = device_create(class_ele, parent, devt, drvdata, fmt);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(security_inode_init_security, (struct inode *inode, struct inode *dir, char **name, void **value, size_t *len), {
    PRE_WRAP(inode);
    PRE_WRAP(dir);
    int ret = security_inode_init_security(inode, dir, name, value, len);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_init, (struct super_block *sb, const char *j_dev_name, int old_format, unsigned int commit_max_age), {
    PRE_WRAP(sb);
    int ret = journal_init(sb, j_dev_name, old_format, commit_max_age);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(free_netdev, (struct net_device *dev), {
    PRE_WRAP(dev);
    free_netdev(dev);
})

FUNCTION_WRAPPER(mb_cache_entry_insert, (struct mb_cache_entry *ce, struct block_device *bdev, sector_t block, unsigned int keys[]), {
    PRE_WRAP(ce);
    PRE_WRAP(bdev);
    int ret = mb_cache_entry_insert(ce, bdev, block, keys);
    RETURN_WRAP(ret);
    return ret;
})

TYPE_WRAPPER(struct journal_head, {
    PRE {
        PRE_WRAP(arg.b_bh);
        PRE_WRAP(arg.b_transaction);
        PRE_WRAP(arg.b_next_transaction);
        PRE_WRAP(arg.b_tnext);
        PRE_WRAP(arg.b_tprev);
        PRE_WRAP(arg.b_cp_transaction);
        PRE_WRAP(arg.b_cpnext);
        PRE_WRAP(arg.b_cpprev);
        PRE_WRAP(arg.b_triggers);
        PRE_WRAP(arg.b_frozen_triggers);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER_VOID(journal_unfile_buffer, (journal_t *journal, struct journal_head *jh), {
    PRE_WRAP(journal);
    PRE_WRAP(jh);
    journal_unfile_buffer(journal, jh);
})

FUNCTION_WRAPPER_VOID(prepare_to_wait, (wait_queue_head_t *q, wait_queue_t *wait, int state), {
    PRE_WRAP(q);
    PRE_WRAP(wait);
    prepare_to_wait(q, wait, state);
})

FUNCTION_WRAPPER_VOID(generic_shutdown_super, (struct super_block *sb), {
    PRE_WRAP(sb);
    generic_shutdown_super(sb);
})

FUNCTION_WRAPPER(bh_submit_read, (struct buffer_head *bh), {
    PRE_WRAP(bh);
    int ret = bh_submit_read(bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(schedule_hrtimeout, (ktime_t *expires, const enum hrtimer_mode mode), {
    int ret = schedule_hrtimeout(expires, mode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_destroy_slot, (struct pci_slot *slot), {
    PRE_WRAP(slot);
    pci_destroy_slot(slot);
})

FUNCTION_WRAPPER(vfs_set_dqinfo, (struct super_block *sb, int type, struct if_dqinfo *ii), {
    PRE_WRAP(sb);
    PRE_WRAP(ii);
    int ret = vfs_set_dqinfo(sb, type, ii);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(napi_complete, (struct napi_struct *n), {
    PRE_WRAP(n);
    napi_complete(n);
})

FUNCTION_WRAPPER(pci_find_capability, (struct pci_dev *dev, int cap), {
    PRE_WRAP(dev);
    int ret = pci_find_capability(dev, cap);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(phy_prepare_link, (struct phy_device *phydev, void (*handler)(struct net_device *)), {
    PRE_WRAP(phydev);
    WRAP_FUNCTION(handler);
    phy_prepare_link(phydev, handler);
})

FUNCTION_WRAPPER(napi_gro_frags, (struct napi_struct *napi), {
    PRE_WRAP(napi);
    gro_result_t ret = napi_gro_frags(napi);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_pm_init, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_pm_init(dev);
})

FUNCTION_WRAPPER(jbd2_log_do_checkpoint, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = jbd2_log_do_checkpoint(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_alloc, (long size), {
    void *ret = pnp_alloc(size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_rescan_bus, (struct pci_bus *bus), {
    PRE_WRAP(bus);
    int ret = pci_rescan_bus(bus);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_unblock_lock, (struct file *filp, struct file_lock *waiter), {
    PRE_WRAP(filp);
    PRE_WRAP(waiter);
    int ret = posix_unblock_lock(filp, waiter);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_find_parent_resource, (const struct pci_dev *dev, struct resource *res), {
    PRE_WRAP(dev);
    PRE_WRAP(res);
    struct resource *ret = pci_find_parent_resource(dev, res);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(buffer_migrate_page, (struct address_space *mapping, struct page *newpage, struct page *page), {
    PRE_WRAP(mapping);
    PRE_WRAP(newpage);
    PRE_WRAP(page);
    int ret = buffer_migrate_page(mapping, newpage, page);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_update_resource, (struct pci_dev *dev, int resno), {
    PRE_WRAP(dev);
    pci_update_resource(dev, resno);
})

FUNCTION_WRAPPER(jbd2_journal_init_revoke_caches, (), {
    int ret = jbd2_journal_init_revoke_caches();
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_write_metadata_buffer, (transaction_t *transaction, struct journal_head *jh_in, struct journal_head **jh_out, unsigned int blocknr), {
    PRE_WRAP(transaction);
    PRE_WRAP(jh_in);
    int ret = journal_write_metadata_buffer(transaction, jh_in, jh_out, blocknr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(kallsyms_on_each_symbol, (int (*fn)(void *, const char *, struct module *, unsigned long), void *data), {
    WRAP_FUNCTION(fn);
    int ret = kallsyms_on_each_symbol(fn, data);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(mod_timer, (struct timer_list *timer, unsigned long expires), {
    PRE_WRAP(timer);
    int ret = mod_timer(timer, expires);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(register_filesystem, (struct file_system_type *fs), {
    PRE_WRAP(fs);
    int ret = register_filesystem(fs);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_no_connect, (struct socket *sock, struct sockaddr *saddr, int len, int flags), {
    PRE_WRAP(sock);
    PRE_WRAP(saddr);
    int ret = sock_no_connect(sock, saddr, len, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_create_data, (const char *name, mode_t mode, struct proc_dir_entry *parent, const struct file_operations *proc_fops, void *data), {
    PRE_WRAP(parent);
    PRE_WRAP(proc_fops);
    struct proc_dir_entry *ret = proc_create_data(name, mode, parent, proc_fops, data);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_resource_type_name, (struct resource *res), {
    PRE_WRAP(res);
    char *ret = pnp_resource_type_name(res);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_no_getname, (struct socket *sock, struct sockaddr *saddr, int *len, int peer), {
    PRE_WRAP(sock);
    PRE_WRAP(saddr);
    int ret = sock_no_getname(sock, saddr, len, peer);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_no_listen, (struct socket *sock, int backlog), {
    PRE_WRAP(sock);
    int ret = sock_no_listen(sock, backlog);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_wipe, (journal_t *journal, int write), {
    PRE_WRAP(journal);
    int ret = journal_wipe(journal, write);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(mark_buffer_dirty, (struct buffer_head *bh), {
    PRE_WRAP(bh);
    mark_buffer_dirty(bh);
})

FUNCTION_WRAPPER(pci_iov_init, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_iov_init(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(init_buffer, (struct buffer_head *_arg1, bh_end_io_t *_arg2, void *_arg3), {
    PRE_WRAP(_arg1);
    init_buffer(_arg1, _arg2, _arg3);
})

FUNCTION_WRAPPER(ata_pci_bmdma_init, (struct ata_host *host), {
    PRE_WRAP(host);
    int ret = ata_pci_bmdma_init(host);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_getsockopt, (struct socket *sock, int level, int optname, char *optval, int *optlen), {
    PRE_WRAP(sock);
    int ret = sock_getsockopt(sock, level, optname, optval, optlen);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(sock_enable_timestamp, (struct sock *sk, int flag), {
    PRE_WRAP(sk);
    sock_enable_timestamp(sk, flag);
})

FUNCTION_WRAPPER(dquot_initialize, (struct inode *inode, int type), {
    PRE_WRAP(inode);
    int ret = dquot_initialize(inode, type);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_user_read_config_word, (struct pci_dev *dev, int pos, u16 *val), {
    PRE_WRAP(dev);
    int ret = pci_user_read_config_word(dev, pos, val);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_iov_release, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_iov_release(dev);
})

FUNCTION_WRAPPER(inode_permission, (struct inode *inode, int mask), {
    PRE_WRAP(inode);
    int ret = inode_permission(inode, mask);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_file_llseek_unlocked, (struct file *file, loff_t offset, int origin), {
    PRE_WRAP(file);
    loff_t ret = generic_file_llseek_unlocked(file, offset, origin);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_find_next_capability, (struct pci_dev *dev, u8 pos, int cap), {
    PRE_WRAP(dev);
    int ret = pci_find_next_capability(dev, pos, cap);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(consume_skb, (struct sk_buff *skb), {
    PRE_WRAP(skb);
    consume_skb(skb);
})

FUNCTION_WRAPPER(bdevname, (struct block_device *bdev, char *buf), {
    PRE_WRAP(bdev);
    const char *ret = bdevname(bdev, buf);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(napi_gro_flush, (struct napi_struct *napi), {
    PRE_WRAP(napi);
    napi_gro_flush(napi);
})

FUNCTION_WRAPPER_VOID(mb_cache_shrink, (struct block_device *bdev), {
    PRE_WRAP(bdev);
    mb_cache_shrink(bdev);
})

FUNCTION_WRAPPER(pcix_set_mmrbc, (struct pci_dev *dev, int mmrbc), {
    PRE_WRAP(dev);
    int ret = pcix_set_mmrbc(dev, mmrbc);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_acl_equiv_mode, (const struct posix_acl *acl, mode_t *mode_p), {
    PRE_WRAP(acl);
    int ret = posix_acl_equiv_mode(acl, mode_p);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(device_create_vargs, (struct class_decl *class_data, struct device *parent, dev_t devt, void *drvdata, const char *fmt, va_list args), {
    PRE_WRAP(class_data);
    PRE_WRAP(parent);
    struct device *ret = device_create_vargs(class_data, parent, devt, drvdata, fmt, args);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(generic_make_request, (struct bio *bio), {
    PRE_WRAP(bio);
    generic_make_request(bio);
})

FUNCTION_WRAPPER(vfs_quota_disable, (struct super_block *sb, int type, unsigned int flags), {
    PRE_WRAP(sb);
    int ret = vfs_quota_disable(sb, type, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(journal_destroy_revoke, (journal_t *journal), {
    PRE_WRAP(journal);
    journal_destroy_revoke(journal);
})

FUNCTION_WRAPPER(generic_listxattr, (struct dentry *dentry, char *buffer, size_t buffer_size), {
    PRE_WRAP(dentry);
    ssize_t ret = generic_listxattr(dentry, buffer, buffer_size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_get_inode, (struct super_block *sb, unsigned int ino, struct proc_dir_entry *de), {
    PRE_WRAP(sb);
    PRE_WRAP(de);
    struct inode *ret = proc_get_inode(sb, ino, de);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_renumber_slot, (struct pci_slot *slot, int slot_nr), {
    PRE_WRAP(slot);
    pci_renumber_slot(slot, slot_nr);
})

FUNCTION_WRAPPER_VOID(journal_destroy_revoke_caches, (), {
    journal_destroy_revoke_caches();
})

FUNCTION_WRAPPER(debugfs_create_file, (const char *name, mode_t mode, struct dentry *parent, void *data, const struct file_operations *fops), {
    PRE_WRAP(parent);
    PRE_WRAP(fops);
    struct dentry *ret = debugfs_create_file(name, mode, parent, data, fops);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_msi_init_pci_dev, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_msi_init_pci_dev(dev);
})

FUNCTION_WRAPPER(do_sync_read, (struct file *filp, char *buf, size_t len, loff_t *ppos), {
    PRE_WRAP(filp);
    ssize_t ret = do_sync_read(filp, buf, len, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(phy_driver_unregister, (struct phy_driver *drv), {
    PRE_WRAP(drv);
    phy_driver_unregister(drv);
})

FUNCTION_WRAPPER_VOID(pci_bus_size_bridges, (struct pci_bus *bus), {
    PRE_WRAP(bus);
    pci_bus_size_bridges(bus);
})

FUNCTION_WRAPPER(input_register_handle, (struct input_handle *handle), {
    PRE_WRAP(handle);
    int ret = input_register_handle(handle);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_cleanup_aer_uncorrect_error_status, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_cleanup_aer_uncorrect_error_status(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(block_read_full_page, (struct page *page, get_block_t get_block), {
    PRE_WRAP(page);
    WRAP_FUNCTION(get_block);
    int ret = block_read_full_page(page, get_block);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_disable_ats, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_disable_ats(dev);
})

FUNCTION_WRAPPER(ethtool_op_get_tso, (struct net_device *dev), {
    PRE_WRAP(dev);
    u32 ret = ethtool_op_get_tso(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_link, (struct dentry *old_dentry, struct inode *dir, struct dentry *new_dentry), {
    PRE_WRAP(old_dentry);
    PRE_WRAP(dir);
    PRE_WRAP(new_dentry);
    int ret = vfs_link(old_dentry, dir, new_dentry);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_user_write_config_byte, (struct pci_dev *dev, int pos, u8 val), {
    PRE_WRAP(dev);
    int ret = pci_user_write_config_byte(dev, pos, val);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_enable_device_mem, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_enable_device_mem(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_errno, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_errno(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(submit_bh, (int rw, struct buffer_head *bh), {
    PRE_WRAP(bh);
    int ret = submit_bh(rw, bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_do_scan_bus, (struct pci_bus *bus), {
    PRE_WRAP(bus);
    int ret = pci_do_scan_bus(bus);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_dq_quota_on_remount, (struct super_block *sb), {
    PRE_WRAP(sb);
    int ret = vfs_dq_quota_on_remount(sb);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_bus_read_config_word, (struct pci_bus *bus, unsigned int devfn, int pos, u16 *value), {
    PRE_WRAP(bus);
    int ret = pci_bus_read_config_word(bus, devfn, pos, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_iomap, (struct pci_dev *dev, int bar, unsigned long maxlen), {
    PRE_WRAP(dev);
    void *ret = pci_iomap(dev, bar, maxlen);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(genphy_restart_aneg, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = genphy_restart_aneg(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(make_bad_inode, (struct inode *inode), {
    PRE_WRAP(inode);
    make_bad_inode(inode);
})

FUNCTION_WRAPPER(input_ff_upload, (struct input_dev *dev, struct ff_effect *effect, struct file *file), {
    PRE_WRAP(dev);
    PRE_WRAP(effect);
    PRE_WRAP(file);
    int ret = input_ff_upload(dev, effect, file);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(add_timer_on, (struct timer_list *timer, int cpu), {
    PRE_WRAP(timer);
    add_timer_on(timer, cpu);
})

FUNCTION_WRAPPER(pci_user_write_config_dword, (struct pci_dev *dev, int pos, u32 val), {
    PRE_WRAP(dev);
    int ret = pci_user_write_config_dword(dev, pos, val);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(rcu_watch_read_lock_bh, (const char *loc), {
    rcu_watch_read_lock_bh(loc);
})

FUNCTION_WRAPPER_VOID(jbd2_journal_release_jbd_inode, (journal_t *journal, struct jbd2_inode *jinode), {
    PRE_WRAP(journal);
    PRE_WRAP(jinode);
    jbd2_journal_release_jbd_inode(journal, jinode);
})

FUNCTION_WRAPPER_VOID(pci_pme_active, (struct pci_dev *dev, bool enable), {
    PRE_WRAP(dev);
    pci_pme_active(dev, enable);
})

FUNCTION_WRAPPER(phy_attach_direct, (struct net_device *dev, struct phy_device *phydev, u32 flags, phy_interface_t interface), {
    PRE_WRAP(dev);
    PRE_WRAP(phydev);
    int ret = phy_attach_direct(dev, phydev, flags, interface);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(rb_replace_node, (struct rb_node *victim, struct rb_node *new_data, struct rb_root *root), {
    PRE_WRAP(victim);
    PRE_WRAP(new_data);
    PRE_WRAP(root);
    rb_replace_node(victim, new_data, root);
})

FUNCTION_WRAPPER_VOID(_write_unlock_irqrestore, (rwlock_t *lock, unsigned long flags), {
    PRE_WRAP(lock);
    _write_unlock_irqrestore(lock, flags);
})

FUNCTION_WRAPPER(jbd2_journal_grab_journal_head, (struct buffer_head *bh), {
    PRE_WRAP(bh);
    struct journal_head *ret = jbd2_journal_grab_journal_head(bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_init_jbd_inode, (struct jbd2_inode *jinode, struct inode *inode), {
    PRE_WRAP(jinode);
    PRE_WRAP(inode);
    jbd2_journal_init_jbd_inode(jinode, inode);
})

FUNCTION_WRAPPER(simple_strtoll, (const char *cp, char **endp, unsigned int base), {
    long long ret = simple_strtoll(cp, endp, base);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_quota_on_path, (struct super_block *sb, int type, int format_id, struct path *path), {
    PRE_WRAP(sb);
    PRE_WRAP(path);
    int ret = vfs_quota_on_path(sb, type, format_id, path);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(mdiobus_scan, (struct mii_bus *bus, int addr), {
    PRE_WRAP(bus);
    struct phy_device *ret = mdiobus_scan(bus, addr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(find_or_create_page, (struct address_space *mapping, unsigned long index, gfp_t gfp_mask), {
    PRE_WRAP(mapping);
    struct page *ret = find_or_create_page(mapping, index, gfp_mask);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_find_device, (unsigned int vendor, unsigned int device, struct pci_dev *from), {
    PRE_WRAP(from);
    struct pci_dev *ret = pci_find_device(vendor, device, from);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_kern_mount, (struct file_system_type *type, int flags, const char *name, void *data), {
    PRE_WRAP(type);
    struct vfsmount *ret = vfs_kern_mount(type, flags, name, data);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_release_buffer, (handle_t *handle, struct buffer_head *bh), {
    PRE_WRAP(handle);
    PRE_WRAP(bh);
    jbd2_journal_release_buffer(handle, bh);
})

FUNCTION_WRAPPER(ethtool_op_set_sg, (struct net_device *dev, u32 data), {
    PRE_WRAP(dev);
    int ret = ethtool_op_set_sg(dev, data);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(unregister_netdev, (struct net_device *dev), {
    PRE_WRAP(dev);
    unregister_netdev(dev);
})

FUNCTION_WRAPPER(posix_cpu_timer_del, (struct k_itimer *timer), {
    PRE_WRAP(timer);
    int ret = posix_cpu_timer_del(timer);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(input_close_device, (struct input_handle *handle), {
    PRE_WRAP(handle);
    input_close_device(handle);
})

FUNCTION_WRAPPER(pnp_stop_dev, (struct pnp_dev *dev), {
    PRE_WRAP(dev);
    int ret = pnp_stop_dev(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(round_jiffies_up, (unsigned long j), {
    long ret = round_jiffies_up(j);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(eth_mac_addr, (struct net_device *dev, void *p), {
    PRE_WRAP(dev);
    int ret = eth_mac_addr(dev, p);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_alloc_send_pskb, (struct sock *sk, unsigned long header_len, unsigned long data_len, int noblock, int *errcode), {
    PRE_WRAP(sk);
    struct sk_buff *ret = sock_alloc_send_pskb(sk, header_len, data_len, noblock, errcode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_proc_attach_device, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_proc_attach_device(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(device_initialize, (struct device *dev), {
    PRE_WRAP(dev);
    device_initialize(dev);
})

FUNCTION_WRAPPER(vfs_quota_sync, (struct super_block *sb, int type), {
    PRE_WRAP(sb);
    int ret = vfs_quota_sync(sb, type);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(input_inject_event, (struct input_handle *handle, unsigned int type, unsigned int code, int value), {
    PRE_WRAP(handle);
    input_inject_event(handle, type, code, value);
})

FUNCTION_WRAPPER(pci_enable_rom, (struct pci_dev *pdev), {
    PRE_WRAP(pdev);
    int ret = pci_enable_rom(pdev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(phy_stop_interrupts, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = phy_stop_interrupts(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(input_ff_erase, (struct input_dev *dev, int effect_id, struct file *file), {
    PRE_WRAP(dev);
    PRE_WRAP(file);
    int ret = input_ff_erase(dev, effect_id, file);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pnp_free_resource, (struct pnp_resource *pnp_res), {
    PRE_WRAP(pnp_res);
    pnp_free_resource(pnp_res);
})

FUNCTION_WRAPPER(phy_driver_register, (struct phy_driver *new_driver), {
    PRE_WRAP(new_driver);
    int ret = phy_driver_register(new_driver);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_set_dma_max_seg_size, (struct pci_dev *dev, unsigned int size), {
    PRE_WRAP(dev);
    int ret = pci_set_dma_max_seg_size(dev, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_target_state, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_power_t ret = pci_target_state(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(block_is_partially_uptodate, (struct page *page, read_descriptor_t *desc, unsigned long from), {
    PRE_WRAP(page);
    PRE_WRAP(desc);
    int ret = block_is_partially_uptodate(page, desc, from);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pcie_get_readrq, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pcie_get_readrq(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_dq_transfer, (struct inode *inode, struct iattr *iattr), {
    PRE_WRAP(inode);
    PRE_WRAP(iattr);
    int ret = vfs_dq_transfer(inode, iattr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_errno, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = journal_errno(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_file_inode, (handle_t *handle, struct jbd2_inode *jinode), {
    PRE_WRAP(handle);
    PRE_WRAP(jinode);
    int ret = jbd2_journal_file_inode(handle, jinode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(eth_header_parse, (const struct sk_buff *skb, unsigned char *haddr), {
    PRE_WRAP(skb);
    int ret = eth_header_parse(skb, haddr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_splice_sendpage, (struct pipe_inode_info *pipe, struct file *out, loff_t *ppos, size_t len, unsigned int flags), {
    PRE_WRAP(pipe);
    PRE_WRAP(out);
    ssize_t ret = generic_splice_sendpage(pipe, out, ppos, len, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(enable_irq, (unsigned int irq), {
    enable_irq(irq);
})

FUNCTION_WRAPPER(device_schedule_callback_owner, (struct device *dev, void (*func)(struct device *), struct module *owner), {
    PRE_WRAP(dev);
    WRAP_FUNCTION(func);
    PRE_WRAP(owner);
    int ret = device_schedule_callback_owner(dev, func, owner);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(iget_failed, (struct inode *inode), {
    PRE_WRAP(inode);
    iget_failed(inode);
})

FUNCTION_WRAPPER(sock_tx_timestamp, (struct msghdr *msg, struct sock *sk, union skb_shared_tx *shtx), {
    PRE_WRAP(msg);
    PRE_WRAP(sk);
    int ret = sock_tx_timestamp(msg, sk, shtx);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(clear_inode, (struct inode *inode), {
    PRE_WRAP(inode);
    clear_inode(inode);
})

FUNCTION_WRAPPER_VOID(dev_set_drvdata, (struct device *dev, void *data), {
    PRE_WRAP(dev);
    dev_set_drvdata(dev, data);
})

FUNCTION_WRAPPER_VOID(pci_release_region, (struct pci_dev *pdev, int bar), {
    PRE_WRAP(pdev);
    pci_release_region(pdev, bar);
})

FUNCTION_WRAPPER(jbd2_journal_init_dev, (struct block_device *bdev, struct block_device *fs_dev, unsigned long long start, int len, int blocksize), {
    PRE_WRAP(bdev);
    PRE_WRAP(fs_dev);
    journal_t *ret = jbd2_journal_init_dev(bdev, fs_dev, start, len, blocksize);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_bus_set_ops, (struct pci_bus *bus, struct pci_ops *ops), {
    PRE_WRAP(bus);
    PRE_WRAP(ops);
    struct pci_ops *ret = pci_bus_set_ops(bus, ops);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(input_ff_create, (struct input_dev *dev, int max_effects), {
    PRE_WRAP(dev);
    int ret = input_ff_create(dev, max_effects);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_quota_on_mount, (struct super_block *sb, char *qf_name, int format_id, int type), {
    PRE_WRAP(sb);
    int ret = vfs_quota_on_mount(sb, qf_name, format_id, type);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(journal_invalidatepage, (journal_t *journal, struct page *page, unsigned long offset), {
    PRE_WRAP(journal);
    PRE_WRAP(page);
    journal_invalidatepage(journal, page, offset);
})

FUNCTION_WRAPPER(generic_file_aio_read, (struct kiocb *iocb, const struct iovec *iov, unsigned long nr_segs, loff_t pos), {
    PRE_WRAP(iocb);
    PRE_WRAP(iov);
    ssize_t ret = generic_file_aio_read(iocb, iov, nr_segs, pos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(print_hex_dump_bytes, (const char *prefix_str, int prefix_type, const void *buf, size_t len), {
    print_hex_dump_bytes(prefix_str, prefix_type, buf, len);
})

FUNCTION_WRAPPER(dmi_find_device, (int type, const char *name, const struct dmi_device *from), {
    PRE_WRAP(from);
    const struct dmi_device *ret = dmi_find_device(type, name, from);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_create, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = journal_create(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(netif_carrier_off, (struct net_device *dev), {
    PRE_WRAP(dev);
    netif_carrier_off(dev);
})

TYPE_WRAPPER(struct ctl_table, {
    PRE {
        PRE_WRAP(arg.child);
        PRE_WRAP(arg.parent);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER(proc_dosoftlockup_thresh, (struct ctl_table *table, int write, void *buffer, size_t *lenp, loff_t *ppos), {
    PRE_WRAP(table);
    int ret = proc_dosoftlockup_thresh(table, write, buffer, lenp, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_stat, (char *name, struct kstat *stat), {
    PRE_WRAP(stat);
    int ret = vfs_stat(name, stat);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_get_timestamp, (struct sock *sk, struct timeval *userstamp), {
    PRE_WRAP(sk);
    PRE_WRAP(userstamp);
    int ret = sock_get_timestamp(sk, userstamp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(input_release_device, (struct input_handle *handle), {
    PRE_WRAP(handle);
    input_release_device(handle);
})

FUNCTION_WRAPPER(jbd2_journal_get_descriptor_buffer, (journal_t *journal), {
    PRE_WRAP(journal);
    struct journal_head *ret = jbd2_journal_get_descriptor_buffer(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(phy_detach, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    phy_detach(phydev);
})

FUNCTION_WRAPPER_VOID(pci_remove_bus, (struct pci_bus *pci_bus), {
    PRE_WRAP(pci_bus);
    pci_remove_bus(pci_bus);
})

FUNCTION_WRAPPER_VOID(journal_clear_revoke, (journal_t *journal), {
    PRE_WRAP(journal);
    journal_clear_revoke(journal);
})

FUNCTION_WRAPPER(pci_read_vpd, (struct pci_dev *dev, loff_t pos, size_t count, void *buf), {
    PRE_WRAP(dev);
    ssize_t ret = pci_read_vpd(dev, pos, count, buf);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_log_start_commit, (journal_t *journal, tid_t tid), {
    PRE_WRAP(journal);
    int ret = jbd2_log_start_commit(journal, tid);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(proc_sched_show_task, (struct task_struct *p, struct seq_file *m), {
    PRE_WRAP(p);
    PRE_WRAP(m);
    proc_sched_show_task(p, m);
})

FUNCTION_WRAPPER_VOID(posix_test_lock, (struct file *filp, struct file_lock *fl), {
    PRE_WRAP(filp);
    PRE_WRAP(fl);
    posix_test_lock(filp, fl);
})

FUNCTION_WRAPPER_VOID(input_event, (struct input_dev *dev, unsigned int type, unsigned int code, int value), {
    PRE_WRAP(dev);
    input_event(dev, type, code, value);
})

FUNCTION_WRAPPER(get_phy_device, (struct mii_bus *bus, int addr), {
    PRE_WRAP(bus);
    struct phy_device *ret = get_phy_device(bus, addr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_alloc_evtchn, (struct xenbus_device *dev, int *port), {
    PRE_WRAP(dev);
    int ret = xenbus_alloc_evtchn(dev, port);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_grab_journal_head, (struct buffer_head *bh), {
    PRE_WRAP(bh);
    struct journal_head *ret = journal_grab_journal_head(bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_invalidatepage, (journal_t *journal, struct page *page, unsigned long offset), {
    PRE_WRAP(journal);
    PRE_WRAP(page);
    jbd2_journal_invalidatepage(journal, page, offset);
})

FUNCTION_WRAPPER(sata_async_notification, (struct ata_port *ap), {
    PRE_WRAP(ap);
    int ret = sata_async_notification(ap);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_writev, (struct file *file, const struct iovec *vec, unsigned long vlen, loff_t *pos), {
    PRE_WRAP(file);
    PRE_WRAP(vec);
    ssize_t ret = vfs_writev(file, vec, vlen, pos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_put_journal_head, (struct journal_head *jh), {
    PRE_WRAP(jh);
    jbd2_journal_put_journal_head(jh);
})

FUNCTION_WRAPPER(register_netdevice_notifier, (struct notifier_block *nb), {
    PRE_WRAP(nb);
    int ret = register_netdevice_notifier(nb);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_next_log_block, (journal_t *journal, unsigned long long *retp), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_next_log_block(journal, retp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(mpage_readpages, (struct address_space *mapping, struct list_head *pages, unsigned int nr_pages, get_block_t get_block), {
    PRE_WRAP(mapping);
    PRE_WRAP(pages);
    WRAP_FUNCTION(get_block);
    int ret = mpage_readpages(mapping, pages, nr_pages, get_block);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_cleanup_rom, (struct pci_dev *pdev), {
    PRE_WRAP(pdev);
    pci_cleanup_rom(pdev);
})

FUNCTION_WRAPPER_VOID(_read_unlock_irqrestore, (rwlock_t *lock, unsigned long flags), {
    PRE_WRAP(lock);
    _read_unlock_irqrestore(lock, flags);
})

FUNCTION_WRAPPER(simple_fill_super, (struct super_block *s, unsigned long magic, struct tree_descr *files), {
    PRE_WRAP(s);
    PRE_WRAP(files);
    int ret = simple_fill_super(s, magic, files);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(ethtool_op_get_sg, (struct net_device *dev), {
    PRE_WRAP(dev);
    u32 ret = ethtool_op_get_sg(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(nobh_write_end, (struct file *file, struct address_space *mapping, loff_t pos, unsigned int len, unsigned int copied, struct page *page, void *fsdata), {
    PRE_WRAP(file);
    PRE_WRAP(mapping);
    PRE_WRAP(page);
    int ret = nobh_write_end(file, mapping, pos, len, copied, page, fsdata);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_request_region_exclusive, (struct pci_dev *pdev, int bar, const char *res_name), {
    PRE_WRAP(pdev);
    int ret = pci_request_region_exclusive(pdev, bar, res_name);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sdio_set_block_size, (struct sdio_func *func, unsigned int blksz), {
    PRE_WRAP(func);
    int ret = sdio_set_block_size(func, blksz);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_bus_add_device, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_bus_add_device(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(device_attach, (struct device *dev), {
    PRE_WRAP(dev);
    int ret = device_attach(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_request_selected_regions_exclusive, (struct pci_dev *pdev, int bars, const char *res_name), {
    PRE_WRAP(pdev);
    int ret = pci_request_selected_regions_exclusive(pdev, bars, res_name);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_vpd_truncate, (struct pci_dev *dev, size_t size), {
    PRE_WRAP(dev);
    int ret = pci_vpd_truncate(dev, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_swizzle_interrupt_pin, (struct pci_dev *dev, u8 pin), {
    PRE_WRAP(dev);
    u8 ret = pci_swizzle_interrupt_pin(dev, pin);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_try_set_mwi, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_try_set_mwi(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(ata_pci_bmdma_clear_simplex, (struct pci_dev *pdev), {
    PRE_WRAP(pdev);
    int ret = ata_pci_bmdma_clear_simplex(pdev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(ioremap_nocache, (resource_size_t phys_addr, unsigned long size), {
    void *ret = ioremap_nocache(phys_addr, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_get_undo_access, (handle_t *handle, struct buffer_head *bh), {
    PRE_WRAP(handle);
    PRE_WRAP(bh);
    int ret = journal_get_undo_access(handle, bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(rcu_watch_dereference, (void *addr, const char *loc), {
    void *ret = rcu_watch_dereference(addr, loc);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_set_features, (journal_t *journal, unsigned long compat, unsigned long ro, unsigned long incompat), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_set_features(journal, compat, ro, incompat);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_readdir, (struct file *file, filldir_t filler, void *buf), {
    PRE_WRAP(file);
    WRAP_FUNCTION(filler);
    int ret = vfs_readdir(file, filler, buf);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(mdiobus_register, (struct mii_bus *bus), {
    PRE_WRAP(bus);
    int ret = mdiobus_register(bus);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_bus_write_config_byte, (struct pci_bus *bus, unsigned int devfn, int pos, u8 value), {
    PRE_WRAP(bus);
    int ret = pci_bus_write_config_byte(bus, devfn, pos, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_create_slot, (struct pci_bus *parent, int slot_nr, const char *name, struct hotplug_slot *hotplug), {
    PRE_WRAP(parent);
    PRE_WRAP(hotplug);
    struct pci_slot *ret = pci_create_slot(parent, slot_nr, name, hotplug);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(rb_next, (const struct rb_node *node), {
    PRE_WRAP(node);
    struct rb_node *ret = rb_next(node);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(journal_unlock_updates, (journal_t *journal), {
    PRE_WRAP(journal);
    journal_unlock_updates(journal);
})

FUNCTION_WRAPPER(sock_no_ioctl, (struct socket *sock, unsigned int cmd, unsigned long arg), {
    PRE_WRAP(sock);
    int ret = sock_no_ioctl(sock, cmd, arg);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(filemap_flush, (struct address_space *mapping), {
    PRE_WRAP(mapping);
    int ret = filemap_flush(mapping);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_path_lookup, (struct dentry *dentry, struct vfsmount *mnt, const char *name, unsigned int flags, struct nameidata *nd), {
    PRE_WRAP(dentry);
    PRE_WRAP(mnt);
    PRE_WRAP(nd);
    int ret = vfs_path_lookup(dentry, mnt, name, flags, nd);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(generic_pipe_buf_unmap, (struct pipe_inode_info *pipe, struct pipe_buffer *buf, void *map_data), {
    PRE_WRAP(pipe);
    PRE_WRAP(buf);
    generic_pipe_buf_unmap(pipe, buf, map_data);
})

FUNCTION_WRAPPER_VOID(pci_enable_bridges, (struct pci_bus *bus), {
    PRE_WRAP(bus);
    pci_enable_bridges(bus);
})

FUNCTION_WRAPPER_VOID(netdev_rx_csum_fault, (struct net_device *dev), {
    PRE_WRAP(dev);
    netdev_rx_csum_fault(dev);
})

FUNCTION_WRAPPER(vfs_unlink, (struct inode *dir, struct dentry *dentry), {
    PRE_WRAP(dir);
    PRE_WRAP(dentry);
    int ret = vfs_unlink(dir, dentry);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(debugfs_create_u16, (const char *name, mode_t mode, struct dentry *parent, u16 *value), {
    PRE_WRAP(parent);
    struct dentry *ret = debugfs_create_u16(name, mode, parent, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(page_put_link, (struct dentry *dentry, struct nameidata *nd, void *cookie), {
    PRE_WRAP(dentry);
    PRE_WRAP(nd);
    page_put_link(dentry, nd, cookie);
})

FUNCTION_WRAPPER_VOID(init_special_inode, (struct inode *inode, umode_t mode, dev_t rdev), {
    PRE_WRAP(inode);
    init_special_inode(inode, mode, rdev);
})

FUNCTION_WRAPPER(xenbus_watch_pathfmt, (struct xenbus_device *dev, struct xenbus_watch *watch, void (*callback)(struct xenbus_watch *, const char **, unsigned int), const char *pathfmt, ...), {
    // TODO: variadic arguments
    PRE_WRAP(dev);
    PRE_WRAP(watch);
    WRAP_FUNCTION(callback);
    int ret = xenbus_watch_pathfmt(dev, watch, callback, pathfmt);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_unfile_buffer, (journal_t *journal, struct journal_head *jh), {
    PRE_WRAP(journal);
    PRE_WRAP(jh);
    jbd2_journal_unfile_buffer(journal, jh);
})

FUNCTION_WRAPPER(pci_get_bus_and_slot, (unsigned int bus, unsigned int devfn), {
    struct pci_dev *ret = pci_get_bus_and_slot(bus, devfn);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_access_phys, (struct vm_area_struct *vma, unsigned long addr, void *buf, int len, int write), {
    PRE_WRAP(vma);
    int ret = generic_access_phys(vma, addr, buf, len, write);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_rename, (struct inode *old_dir, struct dentry *old_dentry, struct inode *new_dir, struct dentry *new_dentry), {
    PRE_WRAP(old_dir);
    PRE_WRAP(old_dentry);
    PRE_WRAP(new_dir);
    PRE_WRAP(new_dentry);
    int ret = vfs_rename(old_dir, old_dentry, new_dir, new_dentry);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_transaction_start, (struct xenbus_transaction *t), {
    PRE_WRAP(t);
    int ret = xenbus_transaction_start(t);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(device_rename, (struct device *dev, char *new_name), {
    PRE_WRAP(dev);
    int ret = device_rename(dev, new_name);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(netdev_class_remove_file, (struct class_attribute *class_attr), {
    PRE_WRAP(class_attr);
    netdev_class_remove_file(class_attr);
})

FUNCTION_WRAPPER(blkdev_put, (struct block_device *bdev, fmode_t mode), {
    PRE_WRAP(bdev);
    int ret = blkdev_put(bdev, mode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_writepages, (struct address_space *mapping, struct writeback_control *wbc), {
    PRE_WRAP(mapping);
    PRE_WRAP(wbc);
    int ret = generic_writepages(mapping, wbc);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_mmap_fits, (struct pci_dev *pdev, int resno, struct vm_area_struct *vma), {
    PRE_WRAP(pdev);
    PRE_WRAP(vma);
    int ret = pci_mmap_fits(pdev, resno, vma);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(ata_pci_sff_init_one, (struct pci_dev *pdev, const struct ata_port_info ** const ppi, struct scsi_host_template *sht, void *host_priv), {
    PRE_WRAP(pdev);
    PRE_WRAP(sht);
    int ret = ata_pci_sff_init_one(pdev, ppi, sht, host_priv);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_cpu_timer_create, (struct k_itimer *new_timer), {
    PRE_WRAP(new_timer);
    int ret = posix_cpu_timer_create(new_timer);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pcie_set_readrq, (struct pci_dev *dev, int rq), {
    PRE_WRAP(dev);
    int ret = pcie_set_readrq(dev, rq);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(dquot_release_reserved_space, (struct inode *inode, qsize_t number), {
    PRE_WRAP(inode);
    dquot_release_reserved_space(inode, number);
})

FUNCTION_WRAPPER(jbd2_journal_test_revoke, (journal_t *journal, unsigned long long blocknr, tid_t sequence), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_test_revoke(journal, blocknr, sequence);
    RETURN_WRAP(ret);
    return ret;
})

TYPE_WRAPPER(struct pci_dynids, {
    PRE {
        PRE_WRAP(arg.lock);
        PRE_WRAP(arg.list);
    }
    NO_POST
    NO_RETURN
})

TYPE_WRAPPER(struct pci_driver, {
    PRE {
        PRE_WRAP(arg.node);
        PRE_WRAP(arg.id_table);
        WRAP_FUNCTION(arg.probe);
        WRAP_FUNCTION(arg.remove);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.suspend_late);
        WRAP_FUNCTION(arg.resume_early);
        WRAP_FUNCTION(arg.resume);
        WRAP_FUNCTION(arg.shutdown);
        PRE_WRAP(arg.err_handler);
        PRE_WRAP(arg.driver);
        PRE_WRAP(arg.dynids);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER(pci_dev_driver, (const struct pci_dev *dev), {
    PRE_WRAP(dev);
    struct pci_driver *ret = pci_dev_driver(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(current_thread_info, (), {
    struct thread_info *ret = current_thread_info();
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_start_commit, (journal_t *journal, tid_t *ptid), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_start_commit(journal, ptid);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(create_proc_entry, (const char *name, mode_t mode, struct proc_dir_entry *parent), {
    PRE_WRAP(parent);
    struct proc_dir_entry *ret = create_proc_entry(name, mode, parent);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_set_pcie_reset_state, (struct pci_dev *dev, enum pcie_reset_state state), {
    PRE_WRAP(dev);
    int ret = pci_set_pcie_reset_state(dev, state);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(sk_reset_timer, (struct sock *sk, struct timer_list *timer, unsigned long expires), {
    PRE_WRAP(sk);
    PRE_WRAP(timer);
    sk_reset_timer(sk, timer, expires);
})

FUNCTION_WRAPPER(d_splice_alias, (struct inode *inode, struct dentry *dentry), {
    PRE_WRAP(inode);
    PRE_WRAP(dentry);
    struct dentry *ret = d_splice_alias(inode, dentry);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(journal_put_journal_head, (struct journal_head *jh), {
    PRE_WRAP(jh);
    journal_put_journal_head(jh);
})

FUNCTION_WRAPPER(vfs_fstat, (unsigned int fd, struct kstat *stat), {
    PRE_WRAP(stat);
    int ret = vfs_fstat(fd, stat);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(kmem_cache_free, (struct kmem_cache *s, void *x), {
    PRE_WRAP(s);
    kmem_cache_free(s, x);
})

FUNCTION_WRAPPER_VOID(proc_flush_task, (struct task_struct *task), {
    PRE_WRAP(task);
    proc_flush_task(task);
})

FUNCTION_WRAPPER(block_page_mkwrite, (struct vm_area_struct *vma, struct vm_fault *vmf, get_block_t get_block), {
    PRE_WRAP(vma);
    PRE_WRAP(vmf);
    WRAP_FUNCTION(get_block);
    int ret = block_page_mkwrite(vma, vmf, get_block);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(unlock_kernel, (), {
    unlock_kernel();
})

FUNCTION_WRAPPER_VOID(generic_pipe_buf_release, (struct pipe_inode_info *pipe, struct pipe_buffer *buf), {
    PRE_WRAP(pipe);
    PRE_WRAP(buf);
    generic_pipe_buf_release(pipe, buf);
})

FUNCTION_WRAPPER(dquot_release, (struct dquot *dquot), {
    PRE_WRAP(dquot);
    int ret = dquot_release(dquot);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(sock_init_data, (struct socket *sock, struct sock *sk), {
    PRE_WRAP(sock);
    PRE_WRAP(sk);
    sock_init_data(sock, sk);
})

FUNCTION_WRAPPER_VOID(unregister_netdevice, (struct net_device *dev), {
    PRE_WRAP(dev);
    unregister_netdevice(dev);
})

FUNCTION_WRAPPER(hrtimer_start, (struct hrtimer *timer, ktime_t tim, const enum hrtimer_mode mode), {
    PRE_WRAP(timer);
    int ret = hrtimer_start(timer, tim, mode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(match_strdup, (substring_t *s), {
    PRE_WRAP(s);
    char *ret = match_strdup(s);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(block_commit_write, (struct page *page, unsigned int from, unsigned int to), {
    PRE_WRAP(page);
    int ret = block_commit_write(page, from, to);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_scan_bus_with_sysdata, (int busno), {
    struct pci_bus *ret = pci_scan_bus_with_sysdata(busno);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_lookup_de, (struct proc_dir_entry *de, struct inode *dir, struct dentry *dentry), {
    PRE_WRAP(de);
    PRE_WRAP(dir);
    PRE_WRAP(dentry);
    struct dentry *ret = proc_lookup_de(de, dir, dentry);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(device_reprobe, (struct device *dev), {
    PRE_WRAP(dev);
    int ret = device_reprobe(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_clear_master, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_clear_master(dev);
})

FUNCTION_WRAPPER_VOID(pci_restore_msi_state, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_restore_msi_state(dev);
})

FUNCTION_WRAPPER_VOID(phy_start, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    phy_start(phydev);
})

FUNCTION_WRAPPER_VOID(down_write, (struct rw_semaphore *sem), {
    PRE_WRAP(sem);
    down_write(sem);
})

FUNCTION_WRAPPER(netif_receive_skb, (struct sk_buff *skb), {
    PRE_WRAP(skb);
    int ret = netif_receive_skb(skb);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_abort, (journal_t *journal, int errno), {
    PRE_WRAP(journal);
    jbd2_journal_abort(journal, errno);
})

FUNCTION_WRAPPER(sata_scr_valid, (struct ata_link *link), {
    PRE_WRAP(link);
    int ret = sata_scr_valid(link);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_fh_to_dentry, (struct super_block *sb, struct fid *fid, int fh_len, int fh_type, get_inode get_node_data), {
    PRE_WRAP(sb);
    PRE_WRAP(fid);
    WRAP_FUNCTION(get_node_data);
    struct dentry *ret = generic_fh_to_dentry(sb, fid, fh_len, fh_type, get_node_data);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(phy_scan_fixups, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = phy_scan_fixups(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_stop, (handle_t *handle), {
    PRE_WRAP(handle);
    int ret = journal_stop(handle);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_lock_file_wait, (struct file *filp, struct file_lock *fl), {
    PRE_WRAP(filp);
    PRE_WRAP(fl);
    int ret = posix_lock_file_wait(filp, fl);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(_spin_lock_irqsave, (spinlock_t *lock), {
    PRE_WRAP(lock);
    long ret = _spin_lock_irqsave(lock);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(hrtimer_try_to_cancel, (struct hrtimer *timer), {
    PRE_WRAP(timer);
    int ret = hrtimer_try_to_cancel(timer);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_check_port, (struct pnp_dev *dev, struct resource *res), {
    PRE_WRAP(dev);
    PRE_WRAP(res);
    int ret = pnp_check_port(dev, res);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_enable_pcie_error_reporting, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_enable_pcie_error_reporting(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_fsync, (struct file *file, struct dentry *dentry, int datasync), {
    PRE_WRAP(file);
    PRE_WRAP(dentry);
    int ret = vfs_fsync(file, dentry, datasync);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_transaction_should_end, (struct reiserfs_transaction_handle *th, int new_alloc), {
    PRE_WRAP(th);
    int ret = journal_transaction_should_end(th, new_alloc);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(input_event_to_user, (char *buffer, const struct input_event *event), {
    PRE_WRAP(event);
    int ret = input_event_to_user(buffer, event);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(iput, (struct inode *inode), {
    PRE_WRAP(inode);
    iput(inode);
})

FUNCTION_WRAPPER(xenbus_probe_devices, (struct xen_bus_type *bus), {
    PRE_WRAP(bus);
    int ret = xenbus_probe_devices(bus);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_register_card_driver, (struct pnp_card_driver *drv), {
    PRE_WRAP(drv);
    int ret = pnp_register_card_driver(drv);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_ack_err, (journal_t *journal), {
    PRE_WRAP(journal);
    jbd2_journal_ack_err(journal);
})

FUNCTION_WRAPPER(generic_cont_expand_simple, (struct inode *inode, loff_t size), {
    PRE_WRAP(inode);
    int ret = generic_cont_expand_simple(inode, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(rcu_watch_read_lock, (const char *loc), {
    rcu_watch_read_lock(loc);
})

FUNCTION_WRAPPER(proc_fill_super, (struct super_block *s), {
    PRE_WRAP(s);
    int ret = proc_fill_super(s);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_set_consistent_dma_mask, (struct pci_dev *dev, u64 mask), {
    PRE_WRAP(dev);
    int ret = pci_set_consistent_dma_mask(dev, mask);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(input_unregister_handler, (struct input_handler *handler), {
    PRE_WRAP(handler);
    input_unregister_handler(handler);
})

FUNCTION_WRAPPER(posix_acl_create_masq, (struct posix_acl *acl, mode_t *mode_p), {
    PRE_WRAP(acl);
    int ret = posix_acl_create_masq(acl, mode_p);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(simple_set_mnt, (struct vfsmount *mnt, struct super_block *sb), {
    PRE_WRAP(mnt);
    PRE_WRAP(sb);
    simple_set_mnt(mnt, sb);
})

FUNCTION_WRAPPER(rb_prev, (const struct rb_node *node), {
    PRE_WRAP(node);
    struct rb_node *ret = rb_prev(node);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_wake_from_d3, (struct pci_dev *dev, bool enable), {
    PRE_WRAP(dev);
    int ret = pci_wake_from_d3(dev, enable);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(mnt_drop_write, (struct vfsmount *mnt), {
    PRE_WRAP(mnt);
    mnt_drop_write(mnt);
})

FUNCTION_WRAPPER(generic_write_end, (struct file *file, struct address_space *mapping, loff_t pos, unsigned int len, unsigned int copied, struct page *page, void *fsdata), {
    PRE_WRAP(file);
    PRE_WRAP(mapping);
    PRE_WRAP(page);
    int ret = generic_write_end(file, mapping, pos, len, copied, page, fsdata);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(sk_stop_timer, (struct sock *sk, struct timer_list *timer), {
    PRE_WRAP(sk);
    PRE_WRAP(timer);
    sk_stop_timer(sk, timer);
})

FUNCTION_WRAPPER_VOID(xenbus_dev_changed, (const char *node, struct xen_bus_type *bus), {
    PRE_WRAP(bus);
    xenbus_dev_changed(node, bus);
})

FUNCTION_WRAPPER(_spin_trylock_bh, (spinlock_t *lock), {
    PRE_WRAP(lock);
    int ret = _spin_trylock_bh(lock);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(generic_smp_call_function_single_interrupt, (), {
    generic_smp_call_function_single_interrupt();
})

FUNCTION_WRAPPER(jbd2_journal_wipe, (journal_t *journal, int write), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_wipe(journal, write);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_user_read_config_byte, (struct pci_dev *dev, int pos, u8 *val), {
    PRE_WRAP(dev);
    int ret = pci_user_read_config_byte(dev, pos, val);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(rcu_watch_assign_pointer, (void **dest, void *src, const char *loc), {
    void *ret = rcu_watch_assign_pointer(dest, src, loc);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(eth_change_mtu, (struct net_device *dev, int new_mtu), {
    PRE_WRAP(dev);
    int ret = eth_change_mtu(dev, new_mtu);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_get_timestampns, (struct sock *sk, struct timespec *userstamp), {
    PRE_WRAP(sk);
    PRE_WRAP(userstamp);
    int ret = sock_get_timestampns(sk, userstamp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_map_ring, (struct xenbus_device *dev, int gnt_ref, grant_handle_t *handle, void *vaddr), {
    PRE_WRAP(dev);
    int ret = xenbus_map_ring(dev, gnt_ref, handle, vaddr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(redirty_page_for_writepage, (struct writeback_control *wbc, struct page *page), {
    PRE_WRAP(wbc);
    PRE_WRAP(page);
    int ret = redirty_page_for_writepage(wbc, page);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(request_threaded_irq, (unsigned int irq, irq_handler_t handler, irq_handler_t thread_fn, unsigned long irqflags, const char *devname, void *dev_id), {
    WRAP_FUNCTION(handler);
    WRAP_FUNCTION(thread_fn);
    int ret = request_threaded_irq(irq, handler, thread_fn, irqflags, devname, dev_id);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sata_scr_write_flush, (struct ata_link *link, int reg, u32 val), {
    PRE_WRAP(link);
    int ret = sata_scr_write_flush(link, reg, val);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(unlock_super, (struct super_block *sb), {
    PRE_WRAP(sb);
    unlock_super(sb);
})

FUNCTION_WRAPPER(request_firmware, (const struct firmware **fw, const char *name, struct device *device), {
    PRE_WRAP(device);
    int ret = request_firmware(fw, name, device);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dmi_name_in_serial, (const char *str), {
    int ret = dmi_name_in_serial(str);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(schedule_work, (struct work_struct *work), {
    PRE_WRAP(work);
    int ret = schedule_work(work);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(genphy_config_aneg, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = genphy_config_aneg(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_get_undo_access, (handle_t *handle, struct buffer_head *bh), {
    PRE_WRAP(handle);
    PRE_WRAP(bh);
    int ret = jbd2_journal_get_undo_access(handle, bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pm_qos_remove_requirement, (int pm_qos_class, char *name), {
    pm_qos_remove_requirement(pm_qos_class, name);
})

FUNCTION_WRAPPER(sata_scr_write, (struct ata_link *link, int reg, u32 val), {
    PRE_WRAP(link);
    int ret = sata_scr_write(link, reg, val);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(mb_cache_entry_find_next, (struct mb_cache_entry *prev, int index, struct block_device *bdev, unsigned int key), {
    PRE_WRAP(prev);
    PRE_WRAP(bdev);
    struct mb_cache_entry *ret = mb_cache_entry_find_next(prev, index, bdev, key);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(i2c_smbus_read_i2c_block_data, (struct i2c_client *client, u8 command, u8 length, u8 *values), {
    PRE_WRAP(client);
    s32 ret = i2c_smbus_read_i2c_block_data(client, command, length, values);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_skip_recovery, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = journal_skip_recovery(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_mkdir, (struct xenbus_transaction t, const char *dir, const char *node), {
    PRE_WRAP(t);
    int ret = xenbus_mkdir(t, dir, node);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pnp_unregister_card_driver, (struct pnp_card_driver *drv), {
    PRE_WRAP(drv);
    pnp_unregister_card_driver(drv);
})

FUNCTION_WRAPPER_VOID(page_cache_sync_readahead, (struct address_space *mapping, struct file_ra_state *ra, struct file *filp, unsigned long offset, unsigned long req_size), {
    PRE_WRAP(mapping);
    PRE_WRAP(ra);
    PRE_WRAP(filp);
    page_cache_sync_readahead(mapping, ra, filp, offset, req_size);
})

FUNCTION_WRAPPER_VOID(pnp_fixup_device, (struct pnp_dev *dev), {
    PRE_WRAP(dev);
    pnp_fixup_device(dev);
})

FUNCTION_WRAPPER(pci_test_config_bits, (struct pci_dev *pdev, const struct pci_bits *bits), {
    PRE_WRAP(pdev);
    PRE_WRAP(bits);
    int ret = pci_test_config_bits(pdev, bits);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(try_to_free_buffers, (struct page *page), {
    PRE_WRAP(page);
    int ret = try_to_free_buffers(page);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_unlink, (struct inode *dir, struct dentry *dentry), {
    PRE_WRAP(dir);
    PRE_WRAP(dentry);
    int ret = simple_unlink(dir, dentry);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_get_create_access, (handle_t *handle, struct buffer_head *bh), {
    PRE_WRAP(handle);
    PRE_WRAP(bh);
    int ret = jbd2_journal_get_create_access(handle, bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(vfree, (void *addr), {
    vfree(addr);
})

FUNCTION_WRAPPER(pnp_register_port_resource, (struct pnp_dev *dev, unsigned int option_flags, resource_size_t min, resource_size_t max, resource_size_t align, resource_size_t size, unsigned char flags), {
    PRE_WRAP(dev);
    int ret = pnp_register_port_resource(dev, option_flags, min, max, align, size, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(eth_validate_addr, (struct net_device *dev), {
    PRE_WRAP(dev);
    int ret = eth_validate_addr(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(iounmap, (void *addr), {
    iounmap(addr);
})

FUNCTION_WRAPPER(dquot_drop, (struct inode *inode), {
    PRE_WRAP(inode);
    int ret = dquot_drop(inode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(new_inode, (struct super_block *sb), {
    PRE_WRAP(sb);
    struct inode *ret = new_inode(sb);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(mdiobus_read, (struct mii_bus *bus, int addr, u16 regnum), {
    PRE_WRAP(bus);
    int ret = mdiobus_read(bus, addr, regnum);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(netif_napi_add, (struct net_device *dev, struct napi_struct *napi, poll p1, int weight), {
    PRE_WRAP(dev);
    PRE_WRAP(napi);
    WRAP_FUNCTION(p1);
    netif_napi_add(dev, napi, p1, weight);
})

FUNCTION_WRAPPER(phy_register_fixup_for_id, (const char *bus_id, int (*run)(struct phy_device *)), {
    WRAP_FUNCTION(run);
    int ret = phy_register_fixup_for_id(bus_id, run);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_init_revoke, (journal_t *journal, int hash_size), {
    PRE_WRAP(journal);
    int ret = journal_init_revoke(journal, hash_size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_configure_slot, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_configure_slot(dev);
})

FUNCTION_WRAPPER(pnp_register_protocol, (struct pnp_protocol *protocol), {
    PRE_WRAP(protocol);
    int ret = pnp_register_protocol(protocol);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(i2c_smbus_read_block_data, (struct i2c_client *client, u8 command, u8 *values), {
    PRE_WRAP(client);
    s32 ret = i2c_smbus_read_block_data(client, command, values);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(block_write_full_page, (struct page *page, get_block_t get_block, struct writeback_control *wbc), {
    PRE_WRAP(page);
    WRAP_FUNCTION(get_block);
    PRE_WRAP(wbc);
    int ret = block_write_full_page(page, get_block, wbc);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dquot_acquire, (struct dquot *dquot), {
    PRE_WRAP(dquot);
    int ret = dquot_acquire(dquot);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(inetdev_by_index, (struct net *net, int ifindex), {
    PRE_WRAP(net);
    struct in_device *ret = inetdev_by_index(net, ifindex);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(nobh_writepage, (struct page *page, get_block_t get_block, struct writeback_control *wbc), {
    PRE_WRAP(page);
    WRAP_FUNCTION(get_block);
    PRE_WRAP(wbc);
    int ret = nobh_writepage(page, get_block, wbc);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_acl_default_exists, (struct inode *inode), {
    PRE_WRAP(inode);
    int ret = posix_acl_default_exists(inode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_register_dma_resource, (struct pnp_dev *dev, unsigned int option_flags, unsigned char map, unsigned char flags), {
    PRE_WRAP(dev);
    int ret = pnp_register_dma_resource(dev, option_flags, map, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(journal_commit_transaction, (journal_t *journal), {
    PRE_WRAP(journal);
    journal_commit_transaction(journal);
})

FUNCTION_WRAPPER(dquot_alloc_inode, (const struct inode *inode, qsize_t number), {
    PRE_WRAP(inode);
    int ret = dquot_alloc_inode(inode, number);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(phy_config_interrupt, (struct phy_device *phydev, u32 interrupts), {
    PRE_WRAP(phydev);
    int ret = phy_config_interrupt(phydev, interrupts);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_get_subsys, (unsigned int vendor, unsigned int device, unsigned int ss_vendor, unsigned int ss_device, struct pci_dev *from), {
    PRE_WRAP(from);
    struct pci_dev *ret = pci_get_subsys(vendor, device, ss_vendor, ss_device, from);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_get_class, (unsigned int class_ele, struct pci_dev *from), {
    PRE_WRAP(from);
    struct pci_dev *ret = pci_get_class(class_ele, from);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_get_dqinfo, (struct super_block *sb, int type, struct if_dqinfo *ii), {
    PRE_WRAP(sb);
    PRE_WRAP(ii);
    int ret = vfs_get_dqinfo(sb, type, ii);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_set_master, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_set_master(dev);
})

FUNCTION_WRAPPER(open_by_devnum, (dev_t dev, fmode_t mode), {
    struct block_device *ret = open_by_devnum(dev, mode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_acl_from_mode, (mode_t mode, gfp_t flags), {
    struct posix_acl *ret = posix_acl_from_mode(mode, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_set_dma_seg_boundary, (struct pci_dev *dev, unsigned long mask), {
    PRE_WRAP(dev);
    int ret = pci_set_dma_seg_boundary(dev, mask);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_flush, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = journal_flush(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_find_ext_capability, (struct pci_dev *dev, int cap), {
    PRE_WRAP(dev);
    int ret = pci_find_ext_capability(dev, cap);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(phy_stop_machine, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    phy_stop_machine(phydev);
})

FUNCTION_WRAPPER(generic_read_dir, (struct file *filp, char *buf, size_t siz, loff_t *ppos), {
    PRE_WRAP(filp);
    ssize_t ret = generic_read_dir(filp, buf, siz, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(bh_uptodate_or_lock, (struct buffer_head *bh), {
    PRE_WRAP(bh);
    int ret = bh_uptodate_or_lock(bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_sync_file, (struct file *file, struct dentry *dentry, int datasync), {
    PRE_WRAP(file);
    PRE_WRAP(dentry);
    int ret = simple_sync_file(file, dentry, datasync);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_vpd_pci22_init, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_vpd_pci22_init(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(journal_refile_buffer, (journal_t *journal, struct journal_head *jh), {
    PRE_WRAP(journal);
    PRE_WRAP(jh);
    journal_refile_buffer(journal, jh);
})

FUNCTION_WRAPPER(skb_copy, (const struct sk_buff *skb, gfp_t priority), {
    PRE_WRAP(skb);
    struct sk_buff *ret = skb_copy(skb, priority);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_pin_fs, (struct file_system_type *type, struct vfsmount **mount, int *count), {
    PRE_WRAP(type);
    int ret = simple_pin_fs(type, mount, count);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_iounmap, (struct pci_dev *dev, void *addr), {
    PRE_WRAP(dev);
    pci_iounmap(dev, addr);
})

FUNCTION_WRAPPER_VOID(device_remove_file, (struct device *dev, struct device_attribute *attr), {
    PRE_WRAP(dev);
    PRE_WRAP(attr);
    device_remove_file(dev, attr);
})

FUNCTION_WRAPPER(pci_sriov_migration, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    irqreturn_t ret = pci_sriov_migration(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dev_open, (struct net_device *dev), {
    PRE_WRAP(dev);
    int ret = dev_open(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sata_sff_hardreset, (struct ata_link *link, unsigned int *class_ele, unsigned long deadline), {
    PRE_WRAP(link);
    int ret = sata_sff_hardreset(link, class_ele, deadline);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_msix_shutdown, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_msix_shutdown(dev);
})

FUNCTION_WRAPPER_VOID(sock_prot_inuse_add, (struct net *net, struct proto *prot, int val), {
    PRE_WRAP(net);
    PRE_WRAP(prot);
    sock_prot_inuse_add(net, prot, val);
})

FUNCTION_WRAPPER(journal_start_commit, (journal_t *journal, tid_t *ptid), {
    PRE_WRAP(journal);
    int ret = journal_start_commit(journal, ptid);
    RETURN_WRAP(ret);
    return ret;
})

TYPE_WRAPPER(struct mb_cache_op, {
    PRE {
        WRAP_FUNCTION(arg.free);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER(mb_cache_create, (const char *name, struct mb_cache_op *cache_op, size_t entry_size, int indexes_count, int bucket_bits), {
    PRE_WRAP(cache_op);
    struct mb_cache *ret = mb_cache_create(name, cache_op, entry_size, indexes_count, bucket_bits);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_buffer_commit_trigger, (struct journal_head *jh, void *mapped_data, struct jbd2_buffer_trigger_type *triggers), {
    PRE_WRAP(jh);
    PRE_WRAP(triggers);
    jbd2_buffer_commit_trigger(jh, mapped_data, triggers);
})

FUNCTION_WRAPPER(vfs_rmdir, (struct inode *dir, struct dentry *dentry), {
    PRE_WRAP(dir);
    PRE_WRAP(dentry);
    int ret = vfs_rmdir(dir, dentry);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_readpage, (struct file *file, struct page *page), {
    PRE_WRAP(file);
    PRE_WRAP(page);
    int ret = simple_readpage(file, page);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(_cond_resched, (), {
    int ret = _cond_resched();
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(hrtimer_forward, (struct hrtimer *timer, ktime_t now, ktime_t interval), {
    PRE_WRAP(timer);
    u64 ret = hrtimer_forward(timer, now, interval);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(device_add, (struct device *dev), {
    PRE_WRAP(dev);
    int ret = device_add(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_update_superblock, (journal_t *journal, int wait), {
    PRE_WRAP(journal);
    jbd2_journal_update_superblock(journal, wait);
})

FUNCTION_WRAPPER(phy_disable_interrupts, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = phy_disable_interrupts(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_get_dqblk, (struct super_block *sb, int type, qid_t id, struct if_dqblk *di), {
    PRE_WRAP(sb);
    PRE_WRAP(di);
    int ret = vfs_get_dqblk(sb, type, id, di);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(device_register, (struct device *dev), {
    PRE_WRAP(dev);
    int ret = device_register(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_bus_max_busnr, (struct pci_bus *bus), {
    PRE_WRAP(bus);
    char ret = pci_bus_max_busnr(bus);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_bus_read_config_dword, (struct pci_bus *bus, unsigned int devfn, int pos, u32 *value), {
    PRE_WRAP(bus);
    int ret = pci_bus_read_config_dword(bus, devfn, pos, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_stop_bus_device, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_stop_bus_device(dev);
})

FUNCTION_WRAPPER_VOID(proc_exec_connector, (struct task_struct *task), {
    PRE_WRAP(task);
    proc_exec_connector(task);
})

FUNCTION_WRAPPER(csum_ipv6_magic, (const struct in6_addr *saddr, const struct in6_addr *daddr, __u32 len, unsigned short proto, __wsum sum), {
    PRE_WRAP(saddr);
    PRE_WRAP(daddr);
    u16 ret = csum_ipv6_magic(saddr, daddr, len, proto, sum);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(register_posix_clock, (const clockid_t clock_id, struct k_clock *new_clock), {
    PRE_WRAP(new_clock);
    register_posix_clock(clock_id, new_clock);
})

FUNCTION_WRAPPER_VOID(phy_disconnect, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    phy_disconnect(phydev);
})

FUNCTION_WRAPPER(debugfs_create_u32, (const char *name, mode_t mode, struct dentry *parent, u32 *value), {
    PRE_WRAP(parent);
    struct dentry *ret = debugfs_create_u32(name, mode, parent, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(phy_attach, (struct net_device *dev, const char *bus_id, u32 flags, phy_interface_t interface), {
    PRE_WRAP(dev);
    struct phy_device *ret = phy_attach(dev, bus_id, flags, interface);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(journal_file_buffer, (struct journal_head *jh, transaction_t *transaction, int jlist), {
    PRE_WRAP(jh);
    PRE_WRAP(transaction);
    journal_file_buffer(jh, transaction, jlist);
})

FUNCTION_WRAPPER(jbd2_journal_destroy, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_destroy(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(skb_trim, (struct sk_buff *skb, unsigned int len), {
    PRE_WRAP(skb);
    skb_trim(skb, len);
})

FUNCTION_WRAPPER(input_open_device, (struct input_handle *handle), {
    PRE_WRAP(handle);
    int ret = input_open_device(handle);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(kern_path, (const char *name, unsigned int flags, struct path *path), {
    PRE_WRAP(path);
    int ret = kern_path(name, flags, path);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(unregister_filesystem, (struct file_system_type *fs), {
    PRE_WRAP(fs);
    int ret = unregister_filesystem(fs);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_dirty_data, (handle_t *handle, struct buffer_head *bh), {
    PRE_WRAP(handle);
    PRE_WRAP(bh);
    int ret = journal_dirty_data(handle, bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(generic_drop_inode, (struct inode *inode), {
    PRE_WRAP(inode);
    generic_drop_inode(inode);
})

FUNCTION_WRAPPER(vfs_setlease, (struct file *filp, long arg, struct file_lock **lease), {
    PRE_WRAP(filp);
    int ret = vfs_setlease(filp, arg, lease);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_find_next_ht_capability, (struct pci_dev *dev, int pos, int ht_cap), {
    PRE_WRAP(dev);
    int ret = pci_find_next_ht_capability(dev, pos, ht_cap);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(input_unfilter_device, (struct input_handle *handle), {
    PRE_WRAP(handle);
    input_unfilter_device(handle);
})

FUNCTION_WRAPPER(block_write_begin, (struct file *file, struct address_space *mapping, loff_t pos, unsigned int len, unsigned int flags, struct page **pagep, void **fsdata, get_block_t get_block), {
    PRE_WRAP(file);
    PRE_WRAP(mapping);
    WRAP_FUNCTION(get_block);
    int ret = block_write_begin(file, mapping, pos, len, flags, pagep, fsdata, get_block);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pcix_get_mmrbc, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pcix_get_mmrbc(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_mark_dirty, (struct reiserfs_transaction_handle *th, struct super_block *sb, struct buffer_head *bh), {
    PRE_WRAP(th);
    PRE_WRAP(sb);
    PRE_WRAP(bh);
    int ret = journal_mark_dirty(th, sb, bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(_spin_lock, (spinlock_t *lock), {
    PRE_WRAP(lock);
    _spin_lock(lock);
})

FUNCTION_WRAPPER(input_register_device, (struct input_dev *dev), {
    PRE_WRAP(dev);
    int ret = input_register_device(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(phy_start_machine, (struct phy_device *phydev, void (*handler)(struct net_device *)), {
    PRE_WRAP(phydev);
    WRAP_FUNCTION(handler);
    phy_start_machine(phydev, handler);
})

FUNCTION_WRAPPER(posix_acl_access_exists, (struct inode *inode), {
    PRE_WRAP(inode);
    int ret = posix_acl_access_exists(inode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(phy_device_register, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = phy_device_register(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(input_filter_device, (struct input_handle *handle), {
    PRE_WRAP(handle);
    int ret = input_filter_device(handle);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(genphy_setup_forced, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = genphy_setup_forced(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_dointvec, (struct ctl_table *table, int write, void *buffer, size_t *lenp, loff_t *ppos), {
    PRE_WRAP(table);
    int ret = proc_dointvec(table, write, buffer, lenp, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_back_from_sleep, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_back_from_sleep(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_enable_ats, (struct pci_dev *dev, int ps), {
    PRE_WRAP(dev);
    int ret = pci_enable_ats(dev, ps);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(block_fsync, (struct file *filp, struct dentry *dentry, int datasync), {
    PRE_WRAP(filp);
    PRE_WRAP(dentry);
    int ret = block_fsync(filp, dentry, datasync);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(rb_first, (const struct rb_root *root), {
    PRE_WRAP(root);
    struct rb_node *ret = rb_first(root);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_extend, (handle_t *handle, int nblocks), {
    PRE_WRAP(handle);
    int ret = jbd2_journal_extend(handle, nblocks);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_iov_bus_range, (struct pci_bus *bus), {
    PRE_WRAP(bus);
    int ret = pci_iov_bus_range(bus);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_request_regions, (struct pci_dev *pdev, const char *res_name), {
    PRE_WRAP(pdev);
    int ret = pci_request_regions(pdev, res_name);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_lost_interrupt, (struct pci_dev *pdev), {
    PRE_WRAP(pdev);
    enum pci_lost_interrupt_reason ret = pci_lost_interrupt(pdev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(netif_carrier_on, (struct net_device *dev), {
    PRE_WRAP(dev);
    netif_carrier_on(dev);
})

FUNCTION_WRAPPER(vfs_quota_enable, (struct inode *inode, int type, int format_id, unsigned int flags), {
    PRE_WRAP(inode);
    int ret = vfs_quota_enable(inode, type, format_id, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_attr_write, (struct file *file, const char *buf, size_t len, loff_t *ppos), {
    PRE_WRAP(file);
    ssize_t ret = simple_attr_write(file, buf, len, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_mark_freed, (struct reiserfs_transaction_handle *th, struct super_block *sb, b_blocknr_t blocknr), {
    PRE_WRAP(th);
    PRE_WRAP(sb);
    int ret = journal_mark_freed(th, sb, blocknr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_dev_to_name, (dev_t device), {
    const char *ret = jbd2_dev_to_name(device);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_i_ino, (struct sock *sk), {
    PRE_WRAP(sk);
    long ret = sock_i_ino(sk);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(module_layout, (struct module *mod, struct modversion_info *ver, struct kernel_param *kp, struct kernel_symbol *ks, struct tracepoint *tp), {
    PRE_WRAP(mod);
    PRE_WRAP(ver);
    PRE_WRAP(kp);
    PRE_WRAP(ks);
    PRE_WRAP(tp);
    module_layout(mod, ver, kp, ks, tp);
})

FUNCTION_WRAPPER(vfs_mknod, (struct inode *dir, struct dentry *dentry, int mode, dev_t dev), {
    PRE_WRAP(dir);
    PRE_WRAP(dentry);
    int ret = vfs_mknod(dir, dentry, mode, dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(netif_rx, (struct sk_buff *skb), {
    PRE_WRAP(skb);
    int ret = netif_rx(skb);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_fstatat, (int dfd, char *filename, struct kstat *stat, int flag), {
    PRE_WRAP(stat);
    int ret = vfs_fstatat(dfd, filename, stat, flag);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_hp_change_slot_info, (struct hotplug_slot *hotplug, struct hotplug_slot_info *info), {
    PRE_WRAP(hotplug);
    PRE_WRAP(info);
    int ret = pci_hp_change_slot_info(hotplug, info);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(yield, (), {
    yield();
})

FUNCTION_WRAPPER_VOID(pnp_device_detach, (struct pnp_dev *pnp_dev), {
    PRE_WRAP(pnp_dev);
    pnp_device_detach(pnp_dev);
})

FUNCTION_WRAPPER_VOID(input_free_device, (struct input_dev *dev), {
    PRE_WRAP(dev);
    input_free_device(dev);
})

FUNCTION_WRAPPER_VOID(netif_napi_del, (struct napi_struct *napi), {
    PRE_WRAP(napi);
    netif_napi_del(napi);
})

FUNCTION_WRAPPER(xenbus_rm, (struct xenbus_transaction t, const char *dir, const char *node), {
    PRE_WRAP(t);
    int ret = xenbus_rm(t, dir, node);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_file_splice_read, (struct file *in, loff_t *ppos, struct pipe_inode_info *pipe, size_t len, unsigned int flags), {
    PRE_WRAP(in);
    PRE_WRAP(pipe);
    ssize_t ret = generic_file_splice_read(in, ppos, pipe, len, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_disable_dev, (struct pnp_dev *dev), {
    PRE_WRAP(dev);
    int ret = pnp_disable_dev(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(ata_pci_device_do_suspend, (struct pci_dev *pdev, pm_message_t mesg), {
    PRE_WRAP(pdev);
    PRE_WRAP(mesg);
    ata_pci_device_do_suspend(pdev, mesg);
})

FUNCTION_WRAPPER(generic_pipe_buf_confirm, (struct pipe_inode_info *info, struct pipe_buffer *buf), {
    PRE_WRAP(info);
    PRE_WRAP(buf);
    int ret = generic_pipe_buf_confirm(info, buf);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_probe_node, (struct xen_bus_type *bus, const char *type, const char *nodename), {
    PRE_WRAP(bus);
    int ret = xenbus_probe_node(bus, type, nodename);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_net_fops_create, (struct net *net, const char *name, mode_t mode, const struct file_operations *fops), {
    PRE_WRAP(net);
    PRE_WRAP(fops);
    struct proc_dir_entry *ret = proc_net_fops_create(net, name, mode, fops);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_unmap_rom, (struct pci_dev *pdev, void *rom), {
    PRE_WRAP(pdev);
    pci_unmap_rom(pdev, rom);
})

FUNCTION_WRAPPER_VOID(jbd2_journal_clear_revoke, (journal_t *journal), {
    PRE_WRAP(journal);
    jbd2_journal_clear_revoke(journal);
})

FUNCTION_WRAPPER(sock_no_socketpair, (struct socket *sock1, struct socket *sock2), {
    PRE_WRAP(sock1);
    PRE_WRAP(sock2);
    int ret = sock_no_socketpair(sock1, sock2);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(posix_cpu_timers_exit, (struct task_struct *tsk), {
    PRE_WRAP(tsk);
    posix_cpu_timers_exit(tsk);
})

FUNCTION_WRAPPER(proc_doulongvec_minmax, (struct ctl_table *table, int write, void *buffer, size_t *lenp, loff_t *ppos), {
    PRE_WRAP(table);
    int ret = proc_doulongvec_minmax(table, write, buffer, lenp, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_prepare_write, (struct file *file, struct page *page, unsigned int from, unsigned int to), {
    PRE_WRAP(file);
    PRE_WRAP(page);
    int ret = simple_prepare_write(file, page, from, to);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_rename, (struct inode *old_dir, struct dentry *old_dentry, struct inode *new_dir, struct dentry *new_dentry), {
    PRE_WRAP(old_dir);
    PRE_WRAP(old_dentry);
    PRE_WRAP(new_dir);
    PRE_WRAP(new_dentry);
    int ret = simple_rename(old_dir, old_dentry, new_dir, new_dentry);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_no_recvmsg, (struct kiocb *iocb, struct socket *sock, struct msghdr *m, size_t len, int flags), {
    PRE_WRAP(iocb);
    PRE_WRAP(sock);
    PRE_WRAP(m);
    int ret = sock_no_recvmsg(iocb, sock, m, len, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_hp_remove_module_link, (struct pci_slot *pci_slot), {
    PRE_WRAP(pci_slot);
    pci_hp_remove_module_link(pci_slot);
})

FUNCTION_WRAPPER(jbd2_journal_load, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_load(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(capable, (int cap), {
    int ret = capable(cap);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(phy_register_fixup_for_uid, (u32 phy_uid, u32 phy_uid_mask, int (*run)(struct phy_device *)), {
    WRAP_FUNCTION(run);
    int ret = phy_register_fixup_for_uid(phy_uid, phy_uid_mask, run);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_acl_to_xattr, (struct posix_acl *acl, void *buffer, size_t size), {
    PRE_WRAP(acl);
    int ret = posix_acl_to_xattr(acl, buffer, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_disable_device, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_disable_device(dev);
})

FUNCTION_WRAPPER(generic_file_readonly_mmap, (struct file *file, struct vm_area_struct *vma), {
    PRE_WRAP(file);
    PRE_WRAP(vma);
    int ret = generic_file_readonly_mmap(file, vma);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(half_md4_transform, (__u32 buf[4], const __u32 in[8]), {
    __u32 ret = half_md4_transform(buf, in);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pnp_unregister_protocol, (struct pnp_protocol *protocol), {
    PRE_WRAP(protocol);
    pnp_unregister_protocol(protocol);
})

FUNCTION_WRAPPER_VOID(block_all_signals, (notifier notifier_var, void *priv, sigset_t *mask), {
    WRAP_FUNCTION(notifier_var);
    PRE_WRAP(mask);
    block_all_signals(notifier_var, priv, mask);
})

FUNCTION_WRAPPER_VOID(pnp_free_resources, (struct pnp_dev *dev), {
    PRE_WRAP(dev);
    pnp_free_resources(dev);
})

FUNCTION_WRAPPER(get_phy_id, (struct mii_bus *bus, int addr, u32 *phy_id), {
    PRE_WRAP(bus);
    int ret = get_phy_id(bus, addr, phy_id);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(debugfs_initialized, (), {
    bool ret = debugfs_initialized();
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(invalidate_bdev, (struct block_device *bdev), {
    PRE_WRAP(bdev);
    invalidate_bdev(bdev);
})

FUNCTION_WRAPPER(sock_no_mmap, (struct file *file, struct socket *sock, struct vm_area_struct *vma), {
    PRE_WRAP(file);
    PRE_WRAP(sock);
    PRE_WRAP(vma);
    int ret = sock_no_mmap(file, sock, vma);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pdev_sort_resources, (struct pci_dev *dev, struct resource_list *head), {
    PRE_WRAP(dev);
    PRE_WRAP(head);
    pdev_sort_resources(dev, head);
})

FUNCTION_WRAPPER(generic_removexattr, (struct dentry *dentry, char *name), {
    PRE_WRAP(dentry);
    int ret = generic_removexattr(dentry, name);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_symlink, (struct inode *dir, struct dentry *dentry, const char *oldname), {
    PRE_WRAP(dir);
    PRE_WRAP(dentry);
    int ret = vfs_symlink(dir, dentry, oldname);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(proc_fork_connector, (struct task_struct *task), {
    PRE_WRAP(task);
    proc_fork_connector(task);
})

FUNCTION_WRAPPER(pci_bus_write_config_word, (struct pci_bus *bus, unsigned int devfn, int pos, u16 value), {
    PRE_WRAP(bus);
    int ret = pci_bus_write_config_word(bus, devfn, pos, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_destroy_revoke, (journal_t *journal), {
    PRE_WRAP(journal);
    jbd2_journal_destroy_revoke(journal);
})

FUNCTION_WRAPPER(pcix_get_max_mmrbc, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pcix_get_max_mmrbc(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(dquot_destroy, (struct dquot *dquot), {
    PRE_WRAP(dquot);
    dquot_destroy(dquot);
})

FUNCTION_WRAPPER(device_private_init, (struct device *dev), {
    PRE_WRAP(dev);
    int ret = device_private_init(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_acl_clone, (const struct posix_acl *acl, gfp_t flags), {
    PRE_WRAP(acl);
    struct posix_acl *ret = posix_acl_clone(acl, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(match_token, (char *s, const match_table_t table, substring_t args[]), {
    int ret = match_token(s, table, args);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_queue_rcv_skb, (struct sock *sk, struct sk_buff *skb), {
    PRE_WRAP(sk);
    PRE_WRAP(skb);
    int ret = sock_queue_rcv_skb(sk, skb);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(kthread_create, (threadfn thread_fun, void *data, char namefmt[]), {
    WRAP_FUNCTION(thread_fun);
    struct task_struct *ret = kthread_create(thread_fun, data, namefmt);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_file_mmap, (struct file *file, struct vm_area_struct *vma), {
    PRE_WRAP(file);
    PRE_WRAP(vma);
    int ret = generic_file_mmap(file, vma);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_msi_enabled, (), {
    int ret = pci_msi_enabled();
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(rcu_watch_free_, (void *addr, const char *loc), {
    void *ret = rcu_watch_free_(addr, loc);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(dev_kfree_skb_any, (struct sk_buff *skb), {
    PRE_WRAP(skb);
    dev_kfree_skb_any(skb);
})

FUNCTION_WRAPPER_VOID(generic_processor_info, (int apicid, int version), {
    generic_processor_info(apicid, version);
})

FUNCTION_WRAPPER(journal_get_write_access, (handle_t *handle, struct buffer_head *bh), {
    PRE_WRAP(handle);
    PRE_WRAP(bh);
    int ret = journal_get_write_access(handle, bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(rb_insert_color, (struct rb_node *node, struct rb_root *root), {
    PRE_WRAP(node);
    PRE_WRAP(root);
    rb_insert_color(node, root);
})

FUNCTION_WRAPPER(pcibios_add_platform_entries, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pcibios_add_platform_entries(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sata_set_spd, (struct ata_link *link), {
    PRE_WRAP(link);
    int ret = sata_set_spd(link);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_acl_chmod, (struct inode *inode, struct generic_acl_operations *ops), {
    PRE_WRAP(inode);
    PRE_WRAP(ops);
    int ret = generic_acl_chmod(inode, ops);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_removexattr, (struct dentry *dentry, const char *name), {
    PRE_WRAP(dentry);
    int ret = vfs_removexattr(dentry, name);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_read_from_buffer, (void *to, size_t count, loff_t *ppos, const void *from, size_t available), {
    ssize_t ret = simple_read_from_buffer(to, count, ppos, from, available);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(netdev_increment_features, (unsigned long all, unsigned long one, unsigned long mask), {
    long ret = netdev_increment_features(all, one, mask);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_bus_add_devices, (const struct pci_bus *bus), {
    PRE_WRAP(bus);
    pci_bus_add_devices(bus);
})

FUNCTION_WRAPPER_VOID(run_posix_cpu_timers, (struct task_struct *tsk), {
    PRE_WRAP(tsk);
    run_posix_cpu_timers(tsk);
})

FUNCTION_WRAPPER(pci_bus_add_child, (struct pci_bus *bus), {
    PRE_WRAP(bus);
    int ret = pci_bus_add_child(bus);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(warn_slowpath_null, (const char *file, int line), {
    warn_slowpath_null(file, line);
})

FUNCTION_WRAPPER(debugfs_create_dir, (const char *name, struct dentry *parent), {
    PRE_WRAP(parent);
    struct dentry *ret = debugfs_create_dir(name, parent);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_add_journal_head, (struct buffer_head *bh), {
    PRE_WRAP(bh);
    struct journal_head *ret = journal_add_journal_head(bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_check_mem, (struct pnp_dev *dev, struct resource *res), {
    PRE_WRAP(dev);
    PRE_WRAP(res);
    int ret = pnp_check_mem(dev, res);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_no_setsockopt, (struct socket *sock, int level, int optname, char *optval, unsigned int optlen), {
    PRE_WRAP(sock);
    int ret = sock_no_setsockopt(sock, level, optname, optval, optlen);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(percpu_counter_destroy, (struct percpu_counter *fbc), {
    PRE_WRAP(fbc);
    percpu_counter_destroy(fbc);
})

FUNCTION_WRAPPER(pnp_add_io_resource, (struct pnp_dev *dev, resource_size_t start, resource_size_t end, int flags), {
    PRE_WRAP(dev);
    struct pnp_resource *ret = pnp_add_io_resource(dev, start, end, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_lstat, (char *name, struct kstat *stat), {
    PRE_WRAP(stat);
    int ret = vfs_lstat(name, stat);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dquot_transfer, (struct inode *inode, struct iattr *iattr), {
    PRE_WRAP(inode);
    PRE_WRAP(iattr);
    int ret = dquot_transfer(inode, iattr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_write_begin, (struct file *file, struct address_space *mapping, loff_t pos, unsigned int len, unsigned int flags, struct page **pagep, void **fsdata), {
    PRE_WRAP(file);
    PRE_WRAP(mapping);
    int ret = simple_write_begin(file, mapping, pos, len, flags, pagep, fsdata);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(mb_cache_entry_free, (struct mb_cache_entry *ce), {
    PRE_WRAP(ce);
    mb_cache_entry_free(ce);
})

FUNCTION_WRAPPER_VOID(unregister_timer_hook, (int (*hook)(struct pt_regs *)), {
    WRAP_FUNCTION(hook);
    unregister_timer_hook(hook);
})

FUNCTION_WRAPPER(vmalloc, (unsigned long size), {
    void *ret = vmalloc(size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_getxattr, (struct dentry *dentry, char *name, void *buffer, size_t size), {
    PRE_WRAP(dentry);
    ssize_t ret = generic_getxattr(dentry, name, buffer, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(generic_smp_call_function_interrupt, (), {
    generic_smp_call_function_interrupt();
})

FUNCTION_WRAPPER(generic_block_bmap, (struct address_space *mapping, sector_t block, get_block_t get_block), {
    PRE_WRAP(mapping);
    WRAP_FUNCTION(get_block);
    sector_t ret = generic_block_bmap(mapping, block, get_block);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(device_for_each_child, (struct device *parent, void *data, int (*fn)(struct device *, void *)), {
    PRE_WRAP(parent);
    WRAP_FUNCTION(fn);
    int ret = device_for_each_child(parent, data, fn);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(init_dummy_netdev, (struct net_device *dev), {
    PRE_WRAP(dev);
    int ret = init_dummy_netdev(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_ext_cfg_avail, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_ext_cfg_avail(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_unregister_driver, (struct pci_driver *drv), {
    PRE_WRAP(drv);
    pci_unregister_driver(drv);
})

FUNCTION_WRAPPER(nobh_truncate_page, (struct address_space *mapping, loff_t from, get_block_t get_block), {
    PRE_WRAP(mapping);
    WRAP_FUNCTION(get_block);
    int ret = nobh_truncate_page(mapping, from, get_block);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_dev_remove, (struct device *_dev), {
    PRE_WRAP(_dev);
    int ret = xenbus_dev_remove(_dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_msix_table_size, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_msix_table_size(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_msi_shutdown, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_msi_shutdown(dev);
})

FUNCTION_WRAPPER_VOID(sock_rfree, (struct sk_buff *skb), {
    PRE_WRAP(skb);
    sock_rfree(skb);
})

FUNCTION_WRAPPER(find_next_zero_bit, (unsigned const long *addr, unsigned long size, unsigned long offset), {
    long ret = find_next_zero_bit(addr, size, offset);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_proc_detach_device, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_proc_detach_device(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(proc_tty_unregister_driver, (struct tty_driver *driver), {
    PRE_WRAP(driver);
    proc_tty_unregister_driver(driver);
})

FUNCTION_WRAPPER(round_jiffies, (unsigned long j), {
    long ret = round_jiffies(j);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_extend, (handle_t *handle, int nblocks), {
    PRE_WRAP(handle);
    int ret = journal_extend(handle, nblocks);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(remove_proc_entry, (const char *name, struct proc_dir_entry *parent), {
    PRE_WRAP(parent);
    remove_proc_entry(name, parent);
})

FUNCTION_WRAPPER(bit_waitqueue, (void *word, int bit), {
    wait_queue_head_t *ret = bit_waitqueue(word, bit);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_disable_sriov, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_disable_sriov(dev);
})

FUNCTION_WRAPPER(sock_no_shutdown, (struct socket *sock, int how), {
    PRE_WRAP(sock);
    int ret = sock_no_shutdown(sock, how);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_add_id, (struct pnp_dev *dev, char *id), {
    PRE_WRAP(dev);
    struct pnp_id *ret = pnp_add_id(dev, id);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pcim_pin_device, (struct pci_dev *pdev), {
    PRE_WRAP(pdev);
    pcim_pin_device(pdev);
})

FUNCTION_WRAPPER_VOID(d_instantiate, (struct dentry *entry, struct inode *inode), {
    PRE_WRAP(entry);
    PRE_WRAP(inode);
    d_instantiate(entry, inode);
})

FUNCTION_WRAPPER(sock_common_recvmsg, (struct kiocb *iocb, struct socket *sock, struct msghdr *msg, size_t size, int flags), {
    PRE_WRAP(iocb);
    PRE_WRAP(sock);
    PRE_WRAP(msg);
    int ret = sock_common_recvmsg(iocb, sock, msg, size, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(posix_cpu_timer_schedule, (struct k_itimer *timer), {
    PRE_WRAP(timer);
    posix_cpu_timer_schedule(timer);
})

FUNCTION_WRAPPER_VOID(bd_release_from_disk, (struct block_device *bdev, struct gendisk *disk), {
    PRE_WRAP(bdev);
    PRE_WRAP(disk);
    bd_release_from_disk(bdev, disk);
})

FUNCTION_WRAPPER(log_start_commit, (journal_t *journal, tid_t tid), {
    PRE_WRAP(journal);
    int ret = log_start_commit(journal, tid);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(device_unregister, (struct device *dev), {
    PRE_WRAP(dev);
    device_unregister(dev);
})

FUNCTION_WRAPPER(sock_rmalloc, (struct sock *sk, unsigned long size, int force, gfp_t priority), {
    PRE_WRAP(sk);
    struct sk_buff *ret = sock_rmalloc(sk, size, force, priority);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_bind_evtchn, (struct xenbus_device *dev, int remote_port, int *port), {
    PRE_WRAP(dev);
    int ret = xenbus_bind_evtchn(dev, remote_port, port);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(hrtimer_init_sleeper, (struct hrtimer_sleeper *sl, struct task_struct *task), {
    PRE_WRAP(sl);
    PRE_WRAP(task);
    hrtimer_init_sleeper(sl, task);
})

FUNCTION_WRAPPER(param_set_int, (const char *val, struct kernel_param *kp), {
    PRE_WRAP(kp);
    int ret = param_set_int(val, kp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(_spin_unlock_bh, (spinlock_t *lock), {
    PRE_WRAP(lock);
    _spin_unlock_bh(lock);
})

FUNCTION_WRAPPER_VOID(pci_walk_bus, (struct pci_bus *top, int (*cb)(struct pci_dev *, void *), void *userdata), {
    PRE_WRAP(top);
    WRAP_FUNCTION(cb);
    pci_walk_bus(top, cb, userdata);
})

FUNCTION_WRAPPER_VOID(proc_clear_tty, (struct task_struct *p), {
    PRE_WRAP(p);
    proc_clear_tty(p);
})

FUNCTION_WRAPPER_VOID(pci_setup_cardbus, (struct pci_bus *bus), {
    PRE_WRAP(bus);
    pci_setup_cardbus(bus);
})

FUNCTION_WRAPPER(sb_min_blocksize, (struct super_block *sb, int size), {
    PRE_WRAP(sb);
    int ret = sb_min_blocksize(sb, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_init_revoke, (journal_t *journal, int hash_size), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_init_revoke(journal, hash_size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sync_dirty_buffer, (struct buffer_head *bh), {
    PRE_WRAP(bh);
    int ret = sync_dirty_buffer(bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(debugfs_create_x8, (const char *name, mode_t mode, struct dentry *parent, u8 *value), {
    PRE_WRAP(parent);
    struct dentry *ret = debugfs_create_x8(name, mode, parent, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(input_allocate_device, (), {
    struct input_dev *ret = input_allocate_device();
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_show_options, (struct seq_file *m, struct vfsmount *mnt), {
    PRE_WRAP(m);
    PRE_WRAP(mnt);
    int ret = generic_show_options(m, mnt);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_no_aer, (), {
    pci_no_aer();
})

FUNCTION_WRAPPER(journal_check_used_features, (journal_t *journal, unsigned long compat, unsigned long ro, unsigned long incompat), {
    PRE_WRAP(journal);
    int ret = journal_check_used_features(journal, compat, ro, incompat);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(put_page, (struct page *page), {
    PRE_WRAP(page);
    put_page(page);
})

FUNCTION_WRAPPER(block_write_full_page_endio, (struct page *page, get_block_t get_block, struct writeback_control *wbc, bh_end_io_t handler), {
    PRE_WRAP(page);
    WRAP_FUNCTION(get_block);
    PRE_WRAP(wbc);
    WRAP_FUNCTION(handler);
    int ret = block_write_full_page_endio(page, get_block, wbc, handler);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_no_bind, (struct socket *sock, struct sockaddr *saddr, int len), {
    PRE_WRAP(sock);
    PRE_WRAP(saddr);
    int ret = sock_no_bind(sock, saddr, len);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_device_find, (const char *nodename, struct bus_type *bus), {
    PRE_WRAP(bus);
    struct xenbus_device *ret = xenbus_device_find(nodename, bus);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(disable_irq, (unsigned int irq), {
    disable_irq(irq);
})

FUNCTION_WRAPPER_VOID(journal_write_revoke_records, (journal_t *journal, transaction_t *transaction, int write_op), {
    PRE_WRAP(journal);
    PRE_WRAP(transaction);
    journal_write_revoke_records(journal, transaction, write_op);
})

FUNCTION_WRAPPER_VOID(unlock_new_inode, (struct inode *inode), {
    PRE_WRAP(inode);
    unlock_new_inode(inode);
})

FUNCTION_WRAPPER(pnp_add_irq_resource, (struct pnp_dev *dev, int irq, int flags), {
    PRE_WRAP(dev);
    struct pnp_resource *ret = pnp_add_irq_resource(dev, irq, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_map_rom, (struct pci_dev *pdev, size_t *size), {
    PRE_WRAP(pdev);
    void *ret = pci_map_rom(pdev, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_create, (int family, int type, int protocol, struct socket **res), {
    int ret = sock_create(family, type, protocol, res);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(input_unregister_device, (struct input_dev *dev), {
    PRE_WRAP(dev);
    input_unregister_device(dev);
})

FUNCTION_WRAPPER(journal_join_abort, (struct reiserfs_transaction_handle *th, struct super_block *sb, unsigned long nblocks), {
    PRE_WRAP(th);
    PRE_WRAP(sb);
    int ret = journal_join_abort(th, sb, nblocks);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_sendmsg, (struct socket *sock, struct msghdr *msg, size_t size), {
    PRE_WRAP(sock);
    PRE_WRAP(msg);
    int ret = sock_sendmsg(sock, msg, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dquot_alloc, (struct super_block *sb, int type), {
    PRE_WRAP(sb);
    struct dquot *ret = dquot_alloc(sb, type);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_dev_put, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_dev_put(dev);
})

FUNCTION_WRAPPER(journal_update_format, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = journal_update_format(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_attr_open, (struct inode *inode, struct file *file, int (*get)(void *, u64 *), int (*set)(void *, u64), const char *fmt), {
    PRE_WRAP(inode);
    PRE_WRAP(file);
    WRAP_FUNCTION(get);
    WRAP_FUNCTION(set);
    int ret = simple_attr_open(inode, file, get, set, fmt);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(block_write_end, (struct file *file, struct address_space *mapping, loff_t pos, unsigned int len, unsigned int copied, struct page *page, void *fsdata), {
    PRE_WRAP(file);
    PRE_WRAP(mapping);
    PRE_WRAP(page);
    int ret = block_write_end(file, mapping, pos, len, copied, page, fsdata);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(proc_id_connector, (struct task_struct *task, int which_id), {
    PRE_WRAP(task);
    proc_id_connector(task, which_id);
})

FUNCTION_WRAPPER(pci_set_power_state, (struct pci_dev *dev, pci_power_t state), {
    PRE_WRAP(dev);
    int ret = pci_set_power_state(dev, state);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(set_blocksize, (struct block_device *bdev, int size), {
    PRE_WRAP(bdev);
    int ret = set_blocksize(bdev, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(mod_timer_pinned, (struct timer_list *timer, unsigned long expires), {
    PRE_WRAP(timer);
    int ret = mod_timer_pinned(timer, expires);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(page_follow_link_light, (struct dentry *dentry, struct nameidata *nd), {
    PRE_WRAP(dentry);
    PRE_WRAP(nd);
    void *ret = page_follow_link_light(dentry, nd);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(_spin_lock_irq, (spinlock_t *lock), {
    PRE_WRAP(lock);
    _spin_lock_irq(lock);
})

FUNCTION_WRAPPER(inode_change_ok, (const struct inode *inode, struct iattr *attr), {
    PRE_WRAP(inode);
    PRE_WRAP(attr);
    int ret = inode_change_ok(inode, attr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(unregister_xenstore_notifier, (struct notifier_block *nb), {
    PRE_WRAP(nb);
    unregister_xenstore_notifier(nb);
})

FUNCTION_WRAPPER(skb_dma_map, (struct device *dev, struct sk_buff *skb, enum dma_data_direction dir), {
    PRE_WRAP(dev);
    PRE_WRAP(skb);
    int ret = skb_dma_map(dev, skb, dir);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(free_irq, (unsigned int _arg1, void *_arg2), {
    free_irq(_arg1, _arg2);
})

FUNCTION_WRAPPER(proc_pid_statm, (struct seq_file *m, struct pid_namespace *ns, struct pid *pid, struct task_struct *task), {
    PRE_WRAP(m);
    PRE_WRAP(ns);
    PRE_WRAP(pid);
    PRE_WRAP(task);
    int ret = proc_pid_statm(m, ns, pid, task);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(napi_skb_finish, (gro_result_t ret, struct sk_buff *skb), {
    PRE_WRAP(skb);
    gro_result_t ret = napi_skb_finish(ret, skb);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_check_available_features, (journal_t *journal, unsigned long compat, unsigned long ro, unsigned long incompat), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_check_available_features(journal, compat, ro, incompat);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_revoke, (handle_t *handle, unsigned int blocknr, struct buffer_head *bh_in), {
    PRE_WRAP(handle);
    PRE_WRAP(bh_in);
    int ret = journal_revoke(handle, blocknr, bh_in);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_request_card_device, (struct pnp_card_link *clink, const char *id, struct pnp_dev *from), {
    PRE_WRAP(clink);
    PRE_WRAP(from);
    struct pnp_dev *ret = pnp_request_card_device(clink, id, from);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(unregister_xenbus_watch, (struct xenbus_watch *watch), {
    PRE_WRAP(watch);
    unregister_xenbus_watch(watch);
})

FUNCTION_WRAPPER(request_irq, (unsigned int irq, irq_handler_t handler, unsigned long flags, const char *name, void *dev), {
    WRAP_FUNCTION(handler);
    int ret = request_irq(irq, handler, flags, name, dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_file_buffered_write, (struct kiocb *iocb, const struct iovec *iov, unsigned long nr_segs, loff_t pos, loff_t *ppos, size_t count, ssize_t written), {
    PRE_WRAP(iocb);
    PRE_WRAP(iov);
    ssize_t ret = generic_file_buffered_write(iocb, iov, nr_segs, pos, ppos, count, written);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_read_driver_state, (const char *path), {
    enum xenbus_state ret = xenbus_read_driver_state(path);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(msleep, (unsigned int msecs), {
    msleep(msecs);
})

FUNCTION_WRAPPER(net_ratelimit, (), {
    int ret = net_ratelimit();
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(phy_stop, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    phy_stop(phydev);
})

FUNCTION_WRAPPER(pci_pme_capable, (struct pci_dev *dev, pci_power_t state), {
    PRE_WRAP(dev);
    bool ret = pci_pme_capable(dev, state);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_cpu_clock_set, (const clockid_t which_clock, const struct timespec *tp), {
    PRE_WRAP(tp);
    int ret = posix_cpu_clock_set(which_clock, tp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_enable_msi_block, (struct pci_dev *dev, unsigned int nvec), {
    PRE_WRAP(dev);
    int ret = pci_enable_msi_block(dev, nvec);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(posix_cpu_timer_get, (struct k_itimer *timer, struct itimerspec *itp), {
    PRE_WRAP(timer);
    PRE_WRAP(itp);
    posix_cpu_timer_get(timer, itp);
})

FUNCTION_WRAPPER(msleep_interruptible, (unsigned int msecs), {
    long ret = msleep_interruptible(msecs);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_force_commit, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_force_commit(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_skip_recovery, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_skip_recovery(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(ethtool_op_set_tx_csum, (struct net_device *dev, u32 data), {
    PRE_WRAP(dev);
    int ret = ethtool_op_set_tx_csum(dev, data);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_enable_device, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_enable_device(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(skb_copy_expand, (const struct sk_buff *skb, int newheadroom, int newtailroom, gfp_t priority), {
    PRE_WRAP(skb);
    struct sk_buff *ret = skb_copy_expand(skb, newheadroom, newtailroom, priority);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(generic_delete_inode, (struct inode *inode), {
    PRE_WRAP(inode);
    generic_delete_inode(inode);
})

FUNCTION_WRAPPER(journal_forget, (handle_t *handle, struct buffer_head *bh), {
    PRE_WRAP(handle);
    PRE_WRAP(bh);
    int ret = journal_forget(handle, bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_statfs, (struct dentry *dentry, struct kstatfs *buf), {
    PRE_WRAP(dentry);
    PRE_WRAP(buf);
    int ret = simple_statfs(dentry, buf);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(current_kernel_time, (), {
    struct timespec ret = current_kernel_time();
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_recvmsg, (struct socket *sock, struct msghdr *msg, size_t size, int flags), {
    PRE_WRAP(sock);
    PRE_WRAP(msg);
    int ret = sock_recvmsg(sock, msg, size, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(insert_inode_locked, (struct inode *inode), {
    PRE_WRAP(inode);
    int ret = insert_inode_locked(inode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_bus_read_config_byte, (struct pci_bus *bus, unsigned int devfn, int pos, u8 *value), {
    PRE_WRAP(bus);
    int ret = pci_bus_read_config_byte(bus, devfn, pos, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_release_error, (struct reiserfs_transaction_handle *th, struct super_block *sb), {
    PRE_WRAP(th);
    PRE_WRAP(sb);
    int ret = journal_release_error(th, sb);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_tid_stat, (struct seq_file *m, struct pid_namespace *ns, struct pid *pid, struct task_struct *task), {
    PRE_WRAP(m);
    PRE_WRAP(ns);
    PRE_WRAP(pid);
    PRE_WRAP(task);
    int ret = proc_tid_stat(m, ns, pid, task);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_set_revoke, (journal_t *journal, unsigned long long blocknr, tid_t sequence), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_set_revoke(journal, blocknr, sequence);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(device_del, (struct device *dev), {
    PRE_WRAP(dev);
    device_del(dev);
})

FUNCTION_WRAPPER(journal_begin, (struct reiserfs_transaction_handle *th, struct super_block *sb, unsigned long nblocks), {
    PRE_WRAP(th);
    PRE_WRAP(sb);
    int ret = journal_begin(th, sb, nblocks);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(phy_connect_direct, (struct net_device *dev, struct phy_device *phydev, void (*handler)(struct net_device *), u32 flags, phy_interface_t interface), {
    PRE_WRAP(dev);
    PRE_WRAP(phydev);
    WRAP_FUNCTION(handler);
    int ret = phy_connect_direct(dev, phydev, handler, flags, interface);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(log_wait_commit, (journal_t *journal, tid_t tid), {
    PRE_WRAP(journal);
    int ret = log_wait_commit(journal, tid);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_enable_ari, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_enable_ari(dev);
})

FUNCTION_WRAPPER(dmi_walk, (void (*decode)(const struct dmi_header *, void *), void *private_data), {
    WRAP_FUNCTION(decode);
    int ret = dmi_walk(decode, private_data);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_mkdir, (struct inode *dir, struct dentry *dentry, int mode), {
    PRE_WRAP(dir);
    PRE_WRAP(dentry);
    int ret = vfs_mkdir(dir, dentry, mode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(phy_clear_interrupt, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = phy_clear_interrupt(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_cpu_nsleep, (const clockid_t which_clock, int flags, struct timespec *rqtp, struct timespec *rmtp), {
    PRE_WRAP(rqtp);
    PRE_WRAP(rmtp);
    int ret = posix_cpu_nsleep(which_clock, flags, rqtp, rmtp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_set_dqblk, (struct super_block *sb, int type, qid_t id, struct if_dqblk *di), {
    PRE_WRAP(sb);
    PRE_WRAP(di);
    int ret = vfs_set_dqblk(sb, type, id, di);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pnp_remove_card, (struct pnp_card *card), {
    PRE_WRAP(card);
    pnp_remove_card(card);
})

FUNCTION_WRAPPER(posix_timer_event, (struct k_itimer *timr, int si_private), {
    PRE_WRAP(timr);
    int ret = posix_timer_event(timr, si_private);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(param_array_get, (char *buffer, struct kernel_param *kp), {
    PRE_WRAP(kp);
    int ret = param_array_get(buffer, kp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_mkdir, (const char *name, struct proc_dir_entry *parent), {
    PRE_WRAP(parent);
    struct proc_dir_entry *ret = proc_mkdir(name, parent);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_dohung_task_timeout_secs, (struct ctl_table *table, int write, void *buffer, size_t *lenp, loff_t *ppos), {
    PRE_WRAP(table);
    int ret = proc_dohung_task_timeout_secs(table, write, buffer, lenp, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_is_active, (struct pnp_dev *dev), {
    PRE_WRAP(dev);
    int ret = pnp_is_active(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(inode_sub_bytes, (struct inode *inode, loff_t bytes), {
    PRE_WRAP(inode);
    inode_sub_bytes(inode, bytes);
})

FUNCTION_WRAPPER_VOID(block_sync_page, (struct page *page), {
    PRE_WRAP(page);
    block_sync_page(page);
})

FUNCTION_WRAPPER_VOID(pci_intx, (struct pci_dev *pdev, int enable), {
    PRE_WRAP(pdev);
    pci_intx(pdev, enable);
})

FUNCTION_WRAPPER(dmi_first_match, (const struct dmi_system_id *list), {
    PRE_WRAP(list);
    const struct dmi_system_id *ret = dmi_first_match(list);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_disable_pcie_error_reporting, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_disable_pcie_error_reporting(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(input_get_keycode, (struct input_dev *dev, int scancode, int *keycode), {
    PRE_WRAP(dev);
    int ret = input_get_keycode(dev, scancode, keycode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_scan_single_device, (struct pci_bus *bus, int devfn), {
    PRE_WRAP(bus);
    struct pci_dev *ret = pci_scan_single_device(bus, devfn);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_unlock_updates, (journal_t *journal), {
    PRE_WRAP(journal);
    jbd2_journal_unlock_updates(journal);
})

FUNCTION_WRAPPER_VOID(pci_block_user_cfg_access, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_block_user_cfg_access(dev);
})

FUNCTION_WRAPPER_VOID(wake_up_bit, (void *word, int bit), {
    wake_up_bit(word, bit);
})

FUNCTION_WRAPPER(vfs_readlink, (struct dentry *dentry, char *buffer, int buflen, const char *link), {
    PRE_WRAP(dentry);
    int ret = vfs_readlink(dentry, buffer, buflen, link);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_destroy, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = journal_destroy(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(iget_locked, (struct super_block *sb, unsigned long ino), {
    PRE_WRAP(sb);
    struct inode *ret = iget_locked(sb, ino);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(mutex_unlock, (struct mutex *lock), {
    PRE_WRAP(lock);
    mutex_unlock(lock);
})

FUNCTION_WRAPPER(xenbus_map_ring_valloc, (struct xenbus_device *dev, int gnt_ref, void **vaddr), {
    PRE_WRAP(dev);
    int ret = xenbus_map_ring_valloc(dev, gnt_ref, vaddr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_i_uid, (struct sock *sk), {
    PRE_WRAP(sk);
    int ret = sock_i_uid(sk);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(skb_dma_unmap, (struct device *dev, struct sk_buff *skb, enum dma_data_direction dir), {
    PRE_WRAP(dev);
    PRE_WRAP(skb);
    skb_dma_unmap(dev, skb, dir);
})

FUNCTION_WRAPPER_VOID(napi_reuse_skb, (struct napi_struct *napi, struct sk_buff *skb), {
    PRE_WRAP(napi);
    PRE_WRAP(skb);
    napi_reuse_skb(napi, skb);
})

FUNCTION_WRAPPER(jbd2_journal_clear_err, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_clear_err(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(ethtool_op_set_tx_ipv6_csum, (struct net_device *dev, u32 data), {
    PRE_WRAP(dev);
    int ret = ethtool_op_set_tx_ipv6_csum(dev, data);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_possible_config, (struct pnp_dev *dev, int type, resource_size_t start, resource_size_t size), {
    PRE_WRAP(dev);
    int ret = pnp_possible_config(dev, type, start, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_cancel_revoke, (handle_t *handle, struct journal_head *jh), {
    PRE_WRAP(handle);
    PRE_WRAP(jh);
    int ret = jbd2_journal_cancel_revoke(handle, jh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_scan_bus_on_node, (int busno, struct pci_ops *ops, int node), {
    PRE_WRAP(ops);
    struct pci_bus *ret = pci_scan_bus_on_node(busno, ops, node);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_acl_set, (struct inode *inode, struct generic_acl_operations *ops, int type, const void *value, size_t size), {
    PRE_WRAP(inode);
    PRE_WRAP(ops);
    int ret = generic_acl_set(inode, ops, type, value, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(phy_print_status, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    phy_print_status(phydev);
})

FUNCTION_WRAPPER_VOID(dev_kfree_skb_irq, (struct sk_buff *skb), {
    PRE_WRAP(skb);
    dev_kfree_skb_irq(skb);
})

FUNCTION_WRAPPER(grab_cache_page_write_begin, (struct address_space *mapping, unsigned long index, unsigned int flags), {
    PRE_WRAP(mapping);
    struct page *ret = grab_cache_page_write_begin(mapping, index, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(register_xenstore_notifier, (struct notifier_block *nb), {
    PRE_WRAP(nb);
    int ret = register_xenstore_notifier(nb);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_flush, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_flush(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_no_accept, (struct socket *sock, struct socket *newsock, int flags), {
    PRE_WRAP(sock);
    PRE_WRAP(newsock);
    int ret = sock_no_accept(sock, newsock, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(create_prof_cpu_mask, (struct proc_dir_entry *root_irq_dir), {
    PRE_WRAP(root_irq_dir);
    create_prof_cpu_mask(root_irq_dir);
})

FUNCTION_WRAPPER(dmi_get_system_info, (int field), {
    const char *ret = dmi_get_system_info(field);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_getxattr, (struct dentry *dentry, const char *name, void *value, size_t size), {
    PRE_WRAP(dentry);
    ssize_t ret = vfs_getxattr(dentry, name, value, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(napi_frags_finish, (struct napi_struct *napi, struct sk_buff *skb, gro_result_t ret), {
    PRE_WRAP(napi);
    PRE_WRAP(skb);
    gro_result_t ret = napi_frags_finish(napi, skb, ret);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_pid_status, (struct seq_file *m, struct pid_namespace *ns, struct pid *pid, struct task_struct *task), {
    PRE_WRAP(m);
    PRE_WRAP(ns);
    PRE_WRAP(pid);
    PRE_WRAP(task);
    int ret = proc_pid_status(m, ns, pid, task);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dev_get_drvdata, (const struct device *dev), {
    PRE_WRAP(dev);
    void *ret = dev_get_drvdata(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_cleanup_journal_tail, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = jbd2_cleanup_journal_tail(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_add_mem_resource, (struct pnp_dev *dev, resource_size_t start, resource_size_t end, int flags), {
    PRE_WRAP(dev);
    struct pnp_resource *ret = pnp_add_mem_resource(dev, start, end, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_end, (struct reiserfs_transaction_handle *th, struct super_block *sb, unsigned long nblocks), {
    PRE_WRAP(th);
    PRE_WRAP(sb);
    int ret = journal_end(th, sb, nblocks);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(xenbus_probe, (struct work_struct *unused), {
    PRE_WRAP(unused);
    xenbus_probe(unused);
})

FUNCTION_WRAPPER(vfs_statfs, (struct dentry *dentry, struct kstatfs *buf), {
    PRE_WRAP(dentry);
    PRE_WRAP(buf);
    int ret = vfs_statfs(dentry, buf);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_kmalloc, (struct sock *sk, int size, gfp_t priority), {
    PRE_WRAP(sk);
    void *ret = sock_kmalloc(sk, size, priority);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(mb_cache_destroy, (struct mb_cache *cache), {
    PRE_WRAP(cache);
    mb_cache_destroy(cache);
})

FUNCTION_WRAPPER(vfs_setxattr, (struct dentry *dentry, const char *name, const void *value, size_t size, int flags), {
    PRE_WRAP(dentry);
    int ret = vfs_setxattr(dentry, name, value, size, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(i2c_smbus_write_i2c_block_data, (struct i2c_client *client, u8 command, u8 length, const u8 *values), {
    PRE_WRAP(client);
    s32 ret = i2c_smbus_write_i2c_block_data(client, command, length, values);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_setlease, (struct file *filp, long arg, struct file_lock **flp), {
    PRE_WRAP(filp);
    int ret = generic_setlease(filp, arg, flp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(sock_release, (struct socket *sock), {
    PRE_WRAP(sock);
    sock_release(sock);
})

FUNCTION_WRAPPER(pnp_activate_dev, (struct pnp_dev *dev), {
    PRE_WRAP(dev);
    int ret = pnp_activate_dev(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(unregister_netdevice_notifier, (struct notifier_block *nb), {
    PRE_WRAP(nb);
    int ret = unregister_netdevice_notifier(nb);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_detach_inode, (struct inode *inode), {
    PRE_WRAP(inode);
    int ret = generic_detach_inode(inode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(device_create_bin_file, (struct device *dev, struct bin_attribute *attr), {
    PRE_WRAP(dev);
    PRE_WRAP(attr);
    int ret = device_create_bin_file(dev, attr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_get_interrupt_pin, (struct pci_dev *dev, struct pci_dev **bridge), {
    PRE_WRAP(dev);
    int ret = pci_get_interrupt_pin(dev, bridge);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_get_slot, (struct pci_bus *bus, unsigned int devfn), {
    PRE_WRAP(bus);
    struct pci_dev *ret = pci_get_slot(bus, devfn);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_log_wait_commit, (journal_t *journal, tid_t tid), {
    PRE_WRAP(journal);
    int ret = jbd2_log_wait_commit(journal, tid);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_get_free_region, (unsigned long base, unsigned long size, int replace_reg), {
    int ret = generic_get_free_region(base, size, replace_reg);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dquot_reserve_space, (struct inode *inode, qsize_t number, int warn), {
    PRE_WRAP(inode);
    int ret = dquot_reserve_space(inode, number, warn);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(register_netdev, (struct net_device *dev), {
    PRE_WRAP(dev);
    int ret = register_netdev(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_scan_slot, (struct pci_bus *bus, int devfn), {
    PRE_WRAP(bus);
    int ret = pci_scan_slot(bus, devfn);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_symlink, (const char *name, struct proc_dir_entry *parent, const char *dest), {
    PRE_WRAP(parent);
    struct proc_dir_entry *ret = proc_symlink(name, parent, dest);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(free_pages, (unsigned long addr, unsigned int order), {
    free_pages(addr, order);
})

FUNCTION_WRAPPER(netdev_set_master, (struct net_device *slave, struct net_device *master), {
    PRE_WRAP(slave);
    PRE_WRAP(master);
    int ret = netdev_set_master(slave, master);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_proc_detach_bus, (struct pci_bus *bus), {
    PRE_WRAP(bus);
    int ret = pci_proc_detach_bus(bus);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(rb_last, (const struct rb_root *root), {
    PRE_WRAP(root);
    struct rb_node *ret = rb_last(root);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sata_std_hardreset, (struct ata_link *link, unsigned int *class_ele, unsigned long deadline), {
    PRE_WRAP(link);
    int ret = sata_std_hardreset(link, class_ele, deadline);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_clear_features, (journal_t *journal, unsigned long compat, unsigned long ro, unsigned long incompat), {
    PRE_WRAP(journal);
    jbd2_journal_clear_features(journal, compat, ro, incompat);
})

FUNCTION_WRAPPER(genphy_update_link, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = genphy_update_link(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dma_generic_alloc_coherent, (struct device *dev, size_t size, dma_addr_t *dma_addr, gfp_t flag), {
    PRE_WRAP(dev);
    void *ret = dma_generic_alloc_coherent(dev, size, dma_addr, flag);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(mdiobus_unregister, (struct mii_bus *bus), {
    PRE_WRAP(bus);
    mdiobus_unregister(bus);
})

FUNCTION_WRAPPER(simple_link, (struct dentry *old_dentry, struct inode *dir, struct dentry *dentry), {
    PRE_WRAP(old_dentry);
    PRE_WRAP(dir);
    PRE_WRAP(dentry);
    int ret = simple_link(old_dentry, dir, dentry);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(try_to_del_timer_sync, (struct timer_list *timer), {
    PRE_WRAP(timer);
    int ret = try_to_del_timer_sync(timer);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(init_timer_key, (struct timer_list *timer, const char *name, struct lock_class_key *key), {
    PRE_WRAP(timer);
    PRE_WRAP(key);
    init_timer_key(timer, name, key);
})

FUNCTION_WRAPPER(sata_pmp_qc_defer_cmd_switch, (struct ata_queued_cmd *qc), {
    PRE_WRAP(qc);
    int ret = sata_pmp_qc_defer_cmd_switch(qc);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(end_buffer_read_sync, (struct buffer_head *bh, int uptodate), {
    PRE_WRAP(bh);
    end_buffer_read_sync(bh, uptodate);
})

FUNCTION_WRAPPER_VOID(pci_bus_assign_resources, (const struct pci_bus *bus), {
    PRE_WRAP(bus);
    pci_bus_assign_resources(bus);
})

FUNCTION_WRAPPER(dquot_claim_space, (struct inode *inode, qsize_t number), {
    PRE_WRAP(inode);
    int ret = dquot_claim_space(inode, number);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_get_device, (unsigned int vendor, unsigned int device, struct pci_dev *from), {
    PRE_WRAP(from);
    struct pci_dev *ret = pci_get_device(vendor, device, from);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(_spin_lock_bh, (spinlock_t *lock), {
    PRE_WRAP(lock);
    _spin_lock_bh(lock);
})

FUNCTION_WRAPPER_VOID(create_empty_buffers, (struct page *page, unsigned long blocksize, unsigned long b_state), {
    PRE_WRAP(page);
    create_empty_buffers(page, blocksize, b_state);
})

FUNCTION_WRAPPER_VOID(pci_disable_msi, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_disable_msi(dev);
})

TYPE_WRAPPER(struct poll_table_struct, {
    PRE {
        WRAP_FUNCTION(arg.qproc);
    }
    NO_POST
    NO_RETURN
})

FUNCTION_WRAPPER(sock_no_poll, (struct file *file, struct socket *sock, poll_table *pt), {
    PRE_WRAP(file);
    PRE_WRAP(sock);
    PRE_WRAP(pt);
    int ret = sock_no_poll(file, sock, pt);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(refrigerator, (), {
    refrigerator();
})

FUNCTION_WRAPPER_VOID(_spin_unlock_irqrestore, (spinlock_t *lock, unsigned long flags), {
    PRE_WRAP(lock);
    _spin_unlock_irqrestore(lock, flags);
})

FUNCTION_WRAPPER(jbd2_journal_try_to_free_buffers, (journal_t *journal, struct page *page, gfp_t gfp_mask), {
    PRE_WRAP(journal);
    PRE_WRAP(page);
    int ret = jbd2_journal_try_to_free_buffers(journal, page, gfp_mask);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(new_inode_smack, (char *smack), {
    struct inode_smack *ret = new_inode_smack(smack);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(ata_pci_device_do_resume, (struct pci_dev *pdev), {
    PRE_WRAP(pdev);
    int ret = ata_pci_device_do_resume(pdev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_find_upstream_pcie_bridge, (struct pci_dev *pdev), {
    PRE_WRAP(pdev);
    struct pci_dev *ret = pci_find_upstream_pcie_bridge(pdev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_nmi_enabled, (struct ctl_table *table, int write, void *buffer, size_t *length, loff_t *ppos), {
    PRE_WRAP(table);
    int ret = proc_nmi_enabled(table, write, buffer, length, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(param_get_int, (char *buffer, struct kernel_param *kp), {
    PRE_WRAP(kp);
    int ret = param_get_int(buffer, kp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_register_driver, (struct pnp_driver *drv), {
    PRE_WRAP(drv);
    int ret = pnp_register_driver(drv);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_request_selected_regions, (struct pci_dev *pdev, int bars, const char *res_name), {
    PRE_WRAP(pdev);
    int ret = pci_request_selected_regions(pdev, bars, res_name);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sata_down_spd_limit, (struct ata_link *link, u32 spd_limit), {
    PRE_WRAP(link);
    int ret = sata_down_spd_limit(link, spd_limit);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(device_create_file, (struct device *dev, struct device_attribute *attr), {
    PRE_WRAP(dev);
    PRE_WRAP(attr);
    int ret = device_create_file(dev, attr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_init_revoke_caches, (), {
    int ret = journal_init_revoke_caches();
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(mdiobus_write, (struct mii_bus *bus, int addr, u16 regnum, u16 val), {
    PRE_WRAP(bus);
    int ret = mdiobus_write(bus, addr, regnum, val);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_check_available_features, (journal_t *journal, unsigned long compat, unsigned long ro, unsigned long incompat), {
    PRE_WRAP(journal);
    int ret = journal_check_available_features(journal, compat, ro, incompat);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(synchronize_irq, (unsigned int irq), {
    synchronize_irq(irq);
})

FUNCTION_WRAPPER(generic_acl_get, (struct inode *inode, struct generic_acl_operations *ops, int type, void *buffer, size_t size), {
    PRE_WRAP(inode);
    PRE_WRAP(ops);
    int ret = generic_acl_get(inode, ops, type, buffer, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_validate_add_page, (unsigned long base, unsigned long size, unsigned int type), {
    int ret = generic_validate_add_page(base, size, type);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(set_page_dirty, (struct page *page), {
    PRE_WRAP(page);
    int ret = set_page_dirty(page);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(netdev_class_create_file, (struct class_attribute *class_attr), {
    PRE_WRAP(class_attr);
    int ret = netdev_class_create_file(class_attr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(phy_start_interrupts, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = phy_start_interrupts(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_cpu_timer_set, (struct k_itimer *timer, int flags, struct itimerspec *new_data, struct itimerspec *old), {
    PRE_WRAP(timer);
    PRE_WRAP(new_data);
    PRE_WRAP(old);
    int ret = posix_cpu_timer_set(timer, flags, new_data, old);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_cpu_nsleep_restart, (struct restart_block *restart_block), {
    PRE_WRAP(restart_block);
    long ret = posix_cpu_nsleep_restart(restart_block);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_alloc_send_skb, (struct sock *sk, unsigned long size, int noblock, int *errcode), {
    PRE_WRAP(sk);
    struct sk_buff *ret = sock_alloc_send_skb(sk, size, noblock, errcode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(proc_net_remove, (struct net *net, const char *name), {
    PRE_WRAP(net);
    proc_net_remove(net, name);
})

FUNCTION_WRAPPER(call_rcu, (struct rcu_head *head, rcu_func func), {
    PRE_WRAP(head);
    WRAP_FUNCTION(func);
    int ret = call_rcu(head, func);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_common_setsockopt, (struct socket *sock, int level, int optname, char *optval, unsigned int optlen), {
    PRE_WRAP(sock);
    int ret = sock_common_setsockopt(sock, level, optname, optval, optlen);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_force_commit_nested, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = journal_force_commit_nested(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_release_selected_regions, (struct pci_dev *pdev, int bars), {
    PRE_WRAP(pdev);
    pci_release_selected_regions(pdev, bars);
})

FUNCTION_WRAPPER(jbd2_journal_check_used_features, (journal_t *journal, unsigned long compat, unsigned long ro, unsigned long incompat), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_check_used_features(journal, compat, ro, incompat);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_refile_buffer, (journal_t *journal, struct journal_head *jh), {
    PRE_WRAP(journal);
    PRE_WRAP(jh);
    jbd2_journal_refile_buffer(journal, jh);
})

FUNCTION_WRAPPER(simple_fsync, (struct file *file, struct dentry *dentry, int datasync), {
    PRE_WRAP(file);
    PRE_WRAP(dentry);
    int ret = simple_fsync(file, dentry, datasync);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(truncate_inode_pages, (struct address_space *mapping, loff_t lstart), {
    PRE_WRAP(mapping);
    truncate_inode_pages(mapping, lstart);
})

FUNCTION_WRAPPER(simple_empty, (struct dentry *dentry), {
    PRE_WRAP(dentry);
    int ret = simple_empty(dentry);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sata_link_debounce, (struct ata_link *link, unsigned const long *params, unsigned long deadline), {
    PRE_WRAP(link);
    int ret = sata_link_debounce(link, params, deadline);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(page_zero_new_buffers, (struct page *page, unsigned int from, unsigned int to), {
    PRE_WRAP(page);
    page_zero_new_buffers(page, from, to);
})

FUNCTION_WRAPPER_VOID(pci_release_regions, (struct pci_dev *pdev), {
    PRE_WRAP(pdev);
    pci_release_regions(pdev);
})

FUNCTION_WRAPPER_VOID(down_read, (struct rw_semaphore *sem), {
    PRE_WRAP(sem);
    down_read(sem);
})

FUNCTION_WRAPPER(xenbus_frontend_closed, (struct xenbus_device *dev), {
    PRE_WRAP(dev);
    int ret = xenbus_frontend_closed(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(phy_device_free, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    phy_device_free(phydev);
})

FUNCTION_WRAPPER_VOID(pci_disable_bridge_window, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_disable_bridge_window(dev);
})

FUNCTION_WRAPPER(mpage_writepages, (struct address_space *mapping, struct writeback_control *wbc, get_block_t get_block), {
    PRE_WRAP(mapping);
    PRE_WRAP(wbc);
    WRAP_FUNCTION(get_block);
    int ret = mpage_writepages(mapping, wbc, get_block);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(bdev_read_only, (struct block_device *bdev), {
    PRE_WRAP(bdev);
    int ret = bdev_read_only(bdev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_tgid_stat, (struct seq_file *m, struct pid_namespace *ns, struct pid *pid, struct task_struct *task), {
    PRE_WRAP(m);
    PRE_WRAP(ns);
    PRE_WRAP(pid);
    PRE_WRAP(task);
    int ret = proc_tgid_stat(m, ns, pid, task);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_file_aio_write, (struct kiocb *iocb, const struct iovec *iov, unsigned long nr_segs, loff_t pos), {
    PRE_WRAP(iocb);
    PRE_WRAP(iov);
    ssize_t ret = generic_file_aio_write(iocb, iov, nr_segs, pos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_add_device, (struct pnp_dev *dev), {
    PRE_WRAP(dev);
    int ret = pnp_add_device(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_build_option, (struct pnp_dev *dev, unsigned long type, unsigned int option_flags), {
    PRE_WRAP(dev);
    struct pnp_option *ret = pnp_build_option(dev, type, option_flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_allocate_cap_save_buffers, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_allocate_cap_save_buffers(dev);
})

FUNCTION_WRAPPER(jbd2_journal_forget, (handle_t *handle, struct buffer_head *bh), {
    PRE_WRAP(handle);
    PRE_WRAP(bh);
    int ret = jbd2_journal_forget(handle, bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_sriov_resource_alignment, (struct pci_dev *dev, int resno), {
    PRE_WRAP(dev);
    int ret = pci_sriov_resource_alignment(dev, resno);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_write_sync, (struct file *file, loff_t pos, loff_t count), {
    PRE_WRAP(file);
    int ret = generic_write_sync(file, pos, count);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(release_firmware, (const struct firmware *fw), {
    PRE_WRAP(fw);
    release_firmware(fw);
})

FUNCTION_WRAPPER(generic_acl_init, (struct inode *inode, struct inode *dir, struct generic_acl_operations *ops), {
    PRE_WRAP(inode);
    PRE_WRAP(dir);
    PRE_WRAP(ops);
    int ret = generic_acl_init(inode, dir, ops);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(compare_pnp_id, (struct pnp_id *pos, const char *id), {
    PRE_WRAP(pos);
    int ret = compare_pnp_id(pos, id);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(bd_claim, (struct block_device *bdev, void *holder), {
    PRE_WRAP(bdev);
    int ret = bd_claim(bdev, holder);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(phy_start_aneg, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = phy_start_aneg(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(up_read, (struct rw_semaphore *sem), {
    PRE_WRAP(sem);
    up_read(sem);
})

FUNCTION_WRAPPER(vfs_write, (struct file *file, const char *buf, size_t count, loff_t *pos), {
    PRE_WRAP(file);
    ssize_t ret = vfs_write(file, buf, count, pos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_add_card_device, (struct pnp_card *card, struct pnp_dev *dev), {
    PRE_WRAP(card);
    PRE_WRAP(dev);
    int ret = pnp_add_card_device(card, dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_setsockopt, (struct socket *sock, int level, int optname, char *optval, unsigned int optlen), {
    PRE_WRAP(sock);
    int ret = sock_setsockopt(sock, level, optname, optval, optlen);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dquot_free_space, (struct inode *inode, qsize_t number), {
    PRE_WRAP(inode);
    int ret = dquot_free_space(inode, number);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_update_current_state, (struct pci_dev *dev, pci_power_t state), {
    PRE_WRAP(dev);
    pci_update_current_state(dev, state);
})

FUNCTION_WRAPPER_VOID(pnp_release_card_device, (struct pnp_dev *dev), {
    PRE_WRAP(dev);
    pnp_release_card_device(dev);
})

FUNCTION_WRAPPER(jbd2_journal_recover, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_recover(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(journal_switch_revoke_table, (journal_t *journal), {
    PRE_WRAP(journal);
    journal_switch_revoke_table(journal);
})

FUNCTION_WRAPPER_VOID(generic_pipe_buf_get, (struct pipe_inode_info *pipe, struct pipe_buffer *buf), {
    PRE_WRAP(pipe);
    PRE_WRAP(buf);
    generic_pipe_buf_get(pipe, buf);
})

FUNCTION_WRAPPER(generic_ptrace_peekdata, (struct task_struct *tsk, long addr, long data), {
    PRE_WRAP(tsk);
    int ret = generic_ptrace_peekdata(tsk, addr, data);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(ata_pci_device_suspend, (struct pci_dev *pdev, pm_message_t mesg), {
    PRE_WRAP(pdev);
    PRE_WRAP(mesg);
    int ret = ata_pci_device_suspend(pdev, mesg);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_set_platform_pm, (struct pci_platform_pm_ops *ops), {
    PRE_WRAP(ops);
    int ret = pci_set_platform_pm(ops);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(debugfs_create_symlink, (const char *name, struct dentry *parent, const char *target), {
    PRE_WRAP(parent);
    struct dentry *ret = debugfs_create_symlink(name, parent, target);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_map_fd, (struct socket *sock, int flags), {
    PRE_WRAP(sock);
    int ret = sock_map_fd(sock, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(phy_ethtool_gset, (struct phy_device *phydev, struct ethtool_cmd *cmd), {
    PRE_WRAP(phydev);
    PRE_WRAP(cmd);
    int ret = phy_ethtool_gset(phydev, cmd);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_create_sysfs_dev_files, (struct pci_dev *pdev), {
    PRE_WRAP(pdev);
    int ret = pci_create_sysfs_dev_files(pdev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_user_write_config_word, (struct pci_dev *dev, int pos, u16 val), {
    PRE_WRAP(dev);
    int ret = pci_user_write_config_word(dev, pos, val);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_dirty_metadata, (handle_t *handle, struct buffer_head *bh), {
    PRE_WRAP(handle);
    PRE_WRAP(bh);
    int ret = journal_dirty_metadata(handle, bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_get_coarse_res, (const clockid_t which_clock, struct timespec *tp), {
    PRE_WRAP(tp);
    int ret = posix_get_coarse_res(which_clock, tp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_unblock_user_cfg_access, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_unblock_user_cfg_access(dev);
})

FUNCTION_WRAPPER(pnp_start_dev, (struct pnp_dev *dev), {
    PRE_WRAP(dev);
    int ret = pnp_start_dev(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(device_destroy, (struct class_decl *class_data, dev_t devt), {
    PRE_WRAP(class_data);
    device_destroy(class_data, devt);
})

FUNCTION_WRAPPER(jbd2_journal_force_commit_nested, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_force_commit_nested(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_wake_async, (struct socket *sock, int how, int band), {
    PRE_WRAP(sock);
    int ret = sock_wake_async(sock, how, band);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(debugfs_create_u64, (const char *name, mode_t mode, struct dentry *parent, u64 *value), {
    PRE_WRAP(parent);
    struct dentry *ret = debugfs_create_u64(name, mode, parent, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(up_write, (struct rw_semaphore *sem), {
    PRE_WRAP(sem);
    up_write(sem);
})

FUNCTION_WRAPPER(debugfs_rename, (struct dentry *old_dir, struct dentry *old_dentry, struct dentry *new_dir, const char *new_name), {
    PRE_WRAP(old_dir);
    PRE_WRAP(old_dentry);
    PRE_WRAP(new_dir);
    struct dentry *ret = debugfs_rename(old_dir, old_dentry, new_dir, new_name);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_prot_inuse_get, (struct net *net, struct proto *prot), {
    PRE_WRAP(net);
    PRE_WRAP(prot);
    int ret = sock_prot_inuse_get(net, prot);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(kfree, (void *x), {
    void *ret = kfree(x);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_grant_ring, (struct xenbus_device *dev, unsigned long ring_mfn), {
    PRE_WRAP(dev);
    int ret = xenbus_grant_ring(dev, ring_mfn);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(get_random_bytes, (void *buf, int nbytes), {
    get_random_bytes(buf, nbytes);
})

FUNCTION_WRAPPER(acpi_smbus_read, (struct acpi_smb_hc *hc, u8 protocol, u8 address, u8 command, u8 *data), {
    PRE_WRAP(hc);
    int ret = acpi_smbus_read(hc, protocol, address, command, data);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(rb_erase, (struct rb_node *node, struct rb_root *root), {
    PRE_WRAP(node);
    PRE_WRAP(root);
    rb_erase(node, root);
})

FUNCTION_WRAPPER(journal_end_sync, (struct reiserfs_transaction_handle *th, struct super_block *sb, unsigned long nblocks), {
    PRE_WRAP(th);
    PRE_WRAP(sb);
    int ret = journal_end_sync(th, sb, nblocks);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_restart, (handle_t *handle, int nblocks), {
    PRE_WRAP(handle);
    int ret = journal_restart(handle, nblocks);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(mb_cache_entry_find_first, (struct mb_cache *cache, int index, struct block_device *bdev, unsigned int key), {
    PRE_WRAP(cache);
    PRE_WRAP(bdev);
    struct mb_cache_entry *ret = mb_cache_entry_find_first(cache, index, bdev, key);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_pid_lookup, (struct inode *dir, struct dentry *dentry, struct nameidata *nd), {
    PRE_WRAP(dir);
    PRE_WRAP(dentry);
    PRE_WRAP(nd);
    struct dentry *ret = proc_pid_lookup(dir, dentry, nd);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(input_unregister_handle, (struct input_handle *handle), {
    PRE_WRAP(handle);
    input_unregister_handle(handle);
})

FUNCTION_WRAPPER(journal_get_create_access, (handle_t *handle, struct buffer_head *bh), {
    PRE_WRAP(handle);
    PRE_WRAP(bh);
    int ret = journal_get_create_access(handle, bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_add_dma_resource, (struct pnp_dev *dev, int dma, int flags), {
    PRE_WRAP(dev);
    struct pnp_resource *ret = pnp_add_dma_resource(dev, dma, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_getattr, (struct vfsmount *mnt, struct dentry *dentry, struct kstat *stat), {
    PRE_WRAP(mnt);
    PRE_WRAP(dentry);
    PRE_WRAP(stat);
    int ret = simple_getattr(mnt, dentry, stat);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_remove_journal_head, (struct buffer_head *bh), {
    PRE_WRAP(bh);
    jbd2_journal_remove_journal_head(bh);
})

FUNCTION_WRAPPER(dev_close, (struct net_device *dev), {
    PRE_WRAP(dev);
    int ret = dev_close(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(rcu_watch_alloc_, (void *addr, const char *loc), {
    void *ret = rcu_watch_alloc_(addr, loc);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(phy_sanitize_settings, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    phy_sanitize_settings(phydev);
})

FUNCTION_WRAPPER(pci_assign_resource, (struct pci_dev *dev, int resno), {
    PRE_WRAP(dev);
    int ret = pci_assign_resource(dev, resno);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(hrtimer_start_range_ns, (struct hrtimer *timer, ktime_t tim, unsigned long delta_ns, const enum hrtimer_mode mode), {
    PRE_WRAP(timer);
    int ret = hrtimer_start_range_ns(timer, tim, delta_ns, mode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(in_group_p, (gid_t grp), {
    int ret = in_group_p(grp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_save_state, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_save_state(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_hp_create_module_link, (struct pci_slot *pci_slot), {
    PRE_WRAP(pci_slot);
    pci_hp_create_module_link(pci_slot);
})

FUNCTION_WRAPPER(current_umask, (), {
    int ret = current_umask();
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(netdev_bonding_change, (struct net_device *dev, unsigned long event), {
    PRE_WRAP(dev);
    netdev_bonding_change(dev, event);
})

FUNCTION_WRAPPER(pnp_resource_type, (struct resource *res), {
    PRE_WRAP(res);
    long ret = pnp_resource_type(res);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(input_grab_device, (struct input_handle *handle), {
    PRE_WRAP(handle);
    int ret = input_grab_device(handle);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(inode_init_once, (struct inode *inode), {
    PRE_WRAP(inode);
    inode_init_once(inode);
})

FUNCTION_WRAPPER_VOID(proc_exit_connector, (struct task_struct *task), {
    PRE_WRAP(task);
    proc_exit_connector(task);
})

FUNCTION_WRAPPER(journal_cancel_revoke, (handle_t *handle, struct journal_head *jh), {
    PRE_WRAP(handle);
    PRE_WRAP(jh);
    int ret = journal_cancel_revoke(handle, jh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_strstate, (enum xenbus_state state), {
    const char *ret = xenbus_strstate(state);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(generic_fillattr, (struct inode *inode, struct kstat *stat), {
    PRE_WRAP(inode);
    PRE_WRAP(stat);
    generic_fillattr(inode, stat);
})

FUNCTION_WRAPPER(acpi_smbus_register_callback, (struct acpi_smb_hc *hc, smbus_alarm_callback callback, void *context), {
    PRE_WRAP(hc);
    WRAP_FUNCTION(callback);
    int ret = acpi_smbus_register_callback(hc, callback, context);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(eth_rebuild_header, (struct sk_buff *skb), {
    PRE_WRAP(skb);
    int ret = eth_rebuild_header(skb);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(register_timer_hook, (int (*hook)(struct pt_regs *)), {
    WRAP_FUNCTION(hook);
    int ret = register_timer_hook(hook);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(kmem_cache_alloc, (struct kmem_cache *s, gfp_t gfpflags), {
    PRE_WRAP(s);
    void *ret = kmem_cache_alloc(s, gfpflags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(phy_device_create, (struct mii_bus *bus, int addr, int phy_id), {
    PRE_WRAP(bus);
    struct phy_device *ret = phy_device_create(bus, addr, phy_id);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(kill_block_super, (struct super_block *sb), {
    PRE_WRAP(sb);
    kill_block_super(sb);
})

FUNCTION_WRAPPER(vprintk, (const char *fmt, va_list args), {
    int ret = vprintk(fmt, args);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(sock_kfree_s, (struct sock *sk, void *mem, int size), {
    PRE_WRAP(sk);
    sock_kfree_s(sk, mem, size);
})

FUNCTION_WRAPPER(mnt_want_write, (struct vfsmount *mnt), {
    PRE_WRAP(mnt);
    int ret = mnt_want_write(mnt);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_no_sendpage, (struct socket *sock, struct page *page, int offset, size_t size, int flags), {
    PRE_WRAP(sock);
    PRE_WRAP(page);
    ssize_t ret = sock_no_sendpage(sock, page, offset, size, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_create_kern, (int family, int type, int protocol, struct socket **res), {
    int ret = sock_create_kern(family, type, protocol, res);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_blocks_per_page, (struct inode *inode), {
    PRE_WRAP(inode);
    int ret = journal_blocks_per_page(inode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(debugfs_create_bool, (const char *name, mode_t mode, struct dentry *parent, u32 *value), {
    PRE_WRAP(parent);
    struct dentry *ret = debugfs_create_bool(name, mode, parent, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_set_triggers, (struct buffer_head *bh, struct jbd2_buffer_trigger_type *type), {
    PRE_WRAP(bh);
    PRE_WRAP(type);
    jbd2_journal_set_triggers(bh, type);
})

FUNCTION_WRAPPER(xenbus_dev_request_and_reply, (struct xsd_sockmsg *msg), {
    PRE_WRAP(msg);
    void *ret = xenbus_dev_request_and_reply(msg);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(netdev_state_change, (struct net_device *dev), {
    PRE_WRAP(dev);
    netdev_state_change(dev);
})

FUNCTION_WRAPPER(do_posix_clock_nosettime, (const clockid_t clockid, struct timespec *tp), {
    PRE_WRAP(tp);
    int ret = do_posix_clock_nosettime(clockid, tp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(device_shutdown, (), {
    device_shutdown();
})

FUNCTION_WRAPPER_VOID(generic_unplug_device, (struct request_queue *q), {
    PRE_WRAP(q);
    generic_unplug_device(q);
})

FUNCTION_WRAPPER(pnp_alloc_card, (struct pnp_protocol *protocol, int id, char *pnpid), {
    PRE_WRAP(protocol);
    struct pnp_card *ret = pnp_alloc_card(protocol, id, pnpid);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(x86_pci_root_bus_res_quirks, (struct pci_bus *b), {
    PRE_WRAP(b);
    x86_pci_root_bus_res_quirks(b);
})

FUNCTION_WRAPPER(blkdev_issue_flush, (struct block_device *bdev, sector_t *error_sector), {
    PRE_WRAP(bdev);
    int ret = blkdev_issue_flush(bdev, error_sector);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(bmap, (struct inode *inode, sector_t block), {
    PRE_WRAP(inode);
    sector_t ret = bmap(inode, block);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_request_region, (struct pci_dev *pdev, int bar, const char *res_name), {
    PRE_WRAP(pdev);
    int ret = pci_request_region(pdev, bar, res_name);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_transaction_get, (struct file *file, const char *buf, size_t size), {
    PRE_WRAP(file);
    char *ret = simple_transaction_get(file, buf, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dquot_mark_dquot_dirty, (struct dquot *dquot), {
    PRE_WRAP(dquot);
    int ret = dquot_mark_dquot_dirty(dquot);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_llseek, (struct file *file, loff_t offset, int origin), {
    PRE_WRAP(file);
    loff_t ret = vfs_llseek(file, offset, origin);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dquot_commit_info, (struct super_block *sb, int type), {
    PRE_WRAP(sb);
    int ret = dquot_commit_info(sb, type);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_dostring, (struct ctl_table *table, int write, void *buffer, size_t *lenp, loff_t *ppos), {
    PRE_WRAP(table);
    int ret = proc_dostring(table, write, buffer, lenp, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(register_xenbus_watch, (struct xenbus_watch *watch), {
    PRE_WRAP(watch);
    int ret = register_xenbus_watch(watch);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(do_sync_write, (struct file *filp, const char *buf, size_t len, loff_t *ppos), {
    PRE_WRAP(filp);
    ssize_t ret = do_sync_write(filp, buf, len, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_attr_read, (struct file *file, char *buf, size_t len, loff_t *ppos), {
    PRE_WRAP(file);
    ssize_t ret = simple_attr_read(file, buf, len, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(driver_probe_device, (struct device_driver *drv, struct device *dev), {
    PRE_WRAP(drv);
    PRE_WRAP(dev);
    int ret = driver_probe_device(drv, dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_scan_bridge, (struct pci_bus *bus, struct pci_dev *dev, int max, int pass), {
    PRE_WRAP(bus);
    PRE_WRAP(dev);
    int ret = pci_scan_bridge(bus, dev, max, pass);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_dointvec_minmax, (struct ctl_table *table, int write, void *buffer, size_t *lenp, loff_t *ppos), {
    PRE_WRAP(table);
    int ret = proc_dointvec_minmax(table, write, buffer, lenp, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_stop, (handle_t *handle), {
    PRE_WRAP(handle);
    int ret = jbd2_journal_stop(handle);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_common_getsockopt, (struct socket *sock, int level, int optname, char *optval, int *optlen), {
    PRE_WRAP(sock);
    int ret = sock_common_getsockopt(sock, level, optname, optval, optlen);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(dump_stack, (), {
    dump_stack();
})

FUNCTION_WRAPPER(simple_strtoul, (const char *cp, char **endp, unsigned int base), {
    long ret = simple_strtoul(cp, endp, base);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_directory, (struct xenbus_transaction t, const char *dir, const char *node, unsigned int *num), {
    PRE_WRAP(t);
    char **ret = xenbus_directory(t, dir, node, num);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_set_mwi, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_set_mwi(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_getattr, (struct vfsmount *mnt, struct dentry *dentry, struct kstat *stat), {
    PRE_WRAP(mnt);
    PRE_WRAP(dentry);
    PRE_WRAP(stat);
    int ret = vfs_getattr(mnt, dentry, stat);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_net_mkdir, (struct net *net, const char *name, struct proc_dir_entry *parent), {
    PRE_WRAP(net);
    PRE_WRAP(parent);
    struct proc_dir_entry *ret = proc_net_mkdir(net, name, parent);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_init_dev, (struct block_device *bdev, struct block_device *fs_dev, int start, int len, int blocksize), {
    PRE_WRAP(bdev);
    PRE_WRAP(fs_dev);
    journal_t *ret = journal_init_dev(bdev, fs_dev, start, len, blocksize);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pm_qos_update_requirement, (int pm_qos_class, char *name, s32 new_value), {
    int ret = pm_qos_update_requirement(pm_qos_class, name, new_value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_start, (journal_t *journal, int nblocks), {
    PRE_WRAP(journal);
    handle_t *ret = jbd2_journal_start(journal, nblocks);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(hrtimer_cancel, (struct hrtimer *timer), {
    PRE_WRAP(timer);
    int ret = hrtimer_cancel(timer);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(del_timer_sync, (struct timer_list *timer), {
    PRE_WRAP(timer);
    int ret = del_timer_sync(timer);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_find_bus, (int domain, int busnr), {
    struct pci_bus *ret = pci_find_bus(domain, busnr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(no_pci_devices, (), {
    int ret = no_pci_devices();
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(is_bad_inode, (struct inode *inode), {
    PRE_WRAP(inode);
    int ret = is_bad_inode(inode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_readlink, (struct dentry *dentry, char *buffer, int buflen), {
    PRE_WRAP(dentry);
    int ret = generic_readlink(dentry, buffer, buflen);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_load, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = journal_load(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_acl_permission, (struct inode *inode, const struct posix_acl *acl, int want), {
    PRE_WRAP(inode);
    PRE_WRAP(acl);
    int ret = posix_acl_permission(inode, acl, want);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pcibios_disable_device, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pcibios_disable_device(dev);
})

FUNCTION_WRAPPER(sync_blockdev, (struct block_device *bdev), {
    PRE_WRAP(bdev);
    int ret = sync_blockdev(bdev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_ioremap_bar, (struct pci_dev *pdev, int bar), {
    PRE_WRAP(pdev);
    void *ret = pci_ioremap_bar(pdev, bar);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(phy_mii_ioctl, (struct phy_device *phydev, struct mii_ioctl_data *mii_data, int cmd), {
    PRE_WRAP(phydev);
    PRE_WRAP(mii_data);
    int ret = phy_mii_ioctl(phydev, mii_data, cmd);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_acl_alloc, (int count, gfp_t flags), {
    struct posix_acl *ret = posix_acl_alloc(count, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_transaction_release, (struct inode *inode, struct file *file), {
    PRE_WRAP(inode);
    PRE_WRAP(file);
    int ret = simple_transaction_release(inode, file);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(mb_cache_entry_release, (struct mb_cache_entry *ce), {
    PRE_WRAP(ce);
    mb_cache_entry_release(ce);
})

FUNCTION_WRAPPER(seq_puts, (struct seq_file *m, const char *s), {
    PRE_WRAP(m);
    int ret = seq_puts(m, s);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sb_set_blocksize, (struct super_block *sb, int size), {
    PRE_WRAP(sb);
    int ret = sb_set_blocksize(sb, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(msi_remove_pci_irq_vectors, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    msi_remove_pci_irq_vectors(dev);
})

FUNCTION_WRAPPER(simple_lookup, (struct inode *dir, struct dentry *dentry, struct nameidata *nd), {
    PRE_WRAP(dir);
    PRE_WRAP(dentry);
    PRE_WRAP(nd);
    struct dentry *ret = simple_lookup(dir, dentry, nd);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_get_hp_params, (struct pci_dev *dev, struct hotplug_params *hpp), {
    PRE_WRAP(dev);
    PRE_WRAP(hpp);
    int ret = pci_get_hp_params(dev, hpp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(eth_header, (struct sk_buff *skb, struct net_device *dev, unsigned short type, const void *daddr, const void *saddr, unsigned int len), {
    PRE_WRAP(skb);
    PRE_WRAP(dev);
    int ret = eth_header(skb, dev, type, daddr, saddr, len);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(napi_frags_skb, (struct napi_struct *napi), {
    PRE_WRAP(napi);
    struct sk_buff *ret = napi_frags_skb(napi);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sata_link_init_spd, (struct ata_link *link), {
    PRE_WRAP(link);
    int ret = sata_link_init_spd(link);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_set_revoke, (journal_t *journal, unsigned int blocknr, tid_t sequence), {
    PRE_WRAP(journal);
    int ret = journal_set_revoke(journal, blocknr, sequence);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(debugfs_remove_recursive, (struct dentry *dentry), {
    PRE_WRAP(dentry);
    debugfs_remove_recursive(dentry);
})

FUNCTION_WRAPPER(pci_write_vpd, (struct pci_dev *dev, loff_t pos, size_t count, const void *buf), {
    PRE_WRAP(dev);
    ssize_t ret = pci_write_vpd(dev, pos, count, buf);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(genphy_suspend, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = genphy_suspend(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dmi_check_system, (const struct dmi_system_id *list), {
    PRE_WRAP(list);
    int ret = dmi_check_system(list);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_bus_alloc_resource, (struct pci_bus *bus, struct resource *res, resource_size_t size, resource_size_t align, resource_size_t min, unsigned int type_mask, void (*alignf)(void *, struct resource *, resource_size_t, resource_size_t), void *alignf_data), {
    PRE_WRAP(bus);
    PRE_WRAP(res);
    WRAP_FUNCTION(alignf);
    int ret = pci_bus_alloc_resource(bus, res, size, align, min, type_mask, alignf, alignf_data);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_remove_bus_device, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_remove_bus_device(dev);
})

FUNCTION_WRAPPER(proc_dointvec_ms_jiffies, (struct ctl_table *table, int write, void *buffer, size_t *lenp, loff_t *ppos), {
    PRE_WRAP(table);
    int ret = proc_dointvec_ms_jiffies(table, write, buffer, lenp, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_restore_iov_state, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_restore_iov_state(dev);
})

FUNCTION_WRAPPER_VOID(unlock_buffer, (struct buffer_head *bh), {
    PRE_WRAP(bh);
    unlock_buffer(bh);
})

FUNCTION_WRAPPER(pci_enable_wake, (struct pci_dev *dev, pci_power_t state, bool enable), {
    PRE_WRAP(dev);
    int ret = pci_enable_wake(dev, state, enable);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_acl_list, (struct inode *inode, struct generic_acl_operations *ops, int type, char *list, size_t list_size), {
    PRE_WRAP(inode);
    PRE_WRAP(ops);
    size_t ret = generic_acl_list(inode, ops, type, list, list_size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_disable_rom, (struct pci_dev *pdev), {
    PRE_WRAP(pdev);
    pci_disable_rom(pdev);
})

FUNCTION_WRAPPER(pci_bus_write_config_dword, (struct pci_bus *bus, unsigned int devfn, int pos, u32 value), {
    PRE_WRAP(bus);
    int ret = pci_bus_write_config_dword(bus, devfn, pos, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(register_netdevice, (struct net_device *dev), {
    PRE_WRAP(dev);
    int ret = register_netdevice(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(sock_wfree, (struct sk_buff *skb), {
    PRE_WRAP(skb);
    sock_wfree(skb);
})

FUNCTION_WRAPPER(wake_bit_function, (wait_queue_t *wait, unsigned int mode, int sync, void *arg), {
    PRE_WRAP(wait);
    int ret = wake_bit_function(wait, mode, sync, arg);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_reset_function, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_reset_function(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_write_revoke_records, (journal_t *journal, transaction_t *transaction, int write_op), {
    PRE_WRAP(journal);
    PRE_WRAP(transaction);
    jbd2_journal_write_revoke_records(journal, transaction, write_op);
})

FUNCTION_WRAPPER(pci_prepare_to_sleep, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_prepare_to_sleep(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_clear_mwi, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_clear_mwi(dev);
})

FUNCTION_WRAPPER(xenbus_read, (struct xenbus_transaction t, const char *dir, const char *node, unsigned int *len), {
    PRE_WRAP(t);
    void *ret = xenbus_read(t, dir, node, len);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_set_features, (journal_t *journal, unsigned long compat, unsigned long ro, unsigned long incompat), {
    PRE_WRAP(journal);
    int ret = journal_set_features(journal, compat, ro, incompat);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_bus_find_capability, (struct pci_bus *bus, unsigned int devfn, int cap), {
    PRE_WRAP(bus);
    int ret = pci_bus_find_capability(bus, devfn, cap);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_find_ht_capability, (struct pci_dev *dev, int ht_cap), {
    PRE_WRAP(dev);
    int ret = pci_find_ht_capability(dev, ht_cap);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(unblock_all_signals, (), {
    unblock_all_signals();
})

FUNCTION_WRAPPER(ethtool_op_set_tso, (struct net_device *dev, u32 data), {
    PRE_WRAP(dev);
    int ret = ethtool_op_set_tso(dev, data);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_init_inode, (struct inode *inode), {
    PRE_WRAP(inode);
    journal_t *ret = jbd2_journal_init_inode(inode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_sort_breadthfirst, (), {
    pci_sort_breadthfirst();
})

FUNCTION_WRAPPER_VOID(pci_fixup_device, (enum pci_fixup_pass pass, struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_fixup_device(pass, dev);
})

FUNCTION_WRAPPER_VOID(pci_no_msi, (), {
    pci_no_msi();
})

FUNCTION_WRAPPER(napi_get_frags, (struct napi_struct *napi), {
    PRE_WRAP(napi);
    struct sk_buff *ret = napi_get_frags(napi);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dmi_get_date, (int field, int *yearp, int *monthp, int *dayp), {
    bool ret = dmi_get_date(field, yearp, monthp, dayp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_strtoull, (const char *cp, char **endp, unsigned int base), {
    long long ret = simple_strtoull(cp, endp, base);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(alloc_pci_dev, (), {
    struct pci_dev *ret = alloc_pci_dev();
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(device_bind_driver, (struct device *dev), {
    PRE_WRAP(dev);
    int ret = device_bind_driver(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(journal_release_buffer, (handle_t *handle, struct buffer_head *bh), {
    PRE_WRAP(handle);
    PRE_WRAP(bh);
    journal_release_buffer(handle, bh);
})

FUNCTION_WRAPPER(pci_common_swizzle, (struct pci_dev *dev, u8 *pinp), {
    PRE_WRAP(dev);
    u8 ret = pci_common_swizzle(dev, pinp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(debugfs_create_x32, (const char *name, mode_t mode, struct dentry *parent, u32 *value), {
    PRE_WRAP(parent);
    struct dentry *ret = debugfs_create_x32(name, mode, parent, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pde_users_dec, (struct proc_dir_entry *pde), {
    PRE_WRAP(pde);
    pde_users_dec(pde);
})

FUNCTION_WRAPPER(jbd2_journal_begin_ordered_truncate, (journal_t *journal, struct jbd2_inode *jinode, loff_t new_size), {
    PRE_WRAP(journal);
    PRE_WRAP(jinode);
    int ret = jbd2_journal_begin_ordered_truncate(journal, jinode, new_size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_exists, (struct xenbus_transaction t, const char *dir, const char *node), {
    PRE_WRAP(t);
    int ret = xenbus_exists(t, dir, node);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_nr_files, (struct ctl_table *table, int write, void *buffer, size_t *lenp, loff_t *ppos), {
    PRE_WRAP(table);
    int ret = proc_nr_files(table, write, buffer, lenp, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_rmdir, (struct inode *dir, struct dentry *dentry), {
    PRE_WRAP(dir);
    PRE_WRAP(dentry);
    int ret = simple_rmdir(dir, dentry);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pnp_free_options, (struct pnp_dev *dev), {
    PRE_WRAP(dev);
    pnp_free_options(dev);
})

FUNCTION_WRAPPER_VOID(netif_device_attach, (struct net_device *dev), {
    PRE_WRAP(dev);
    netif_device_attach(dev);
})

FUNCTION_WRAPPER(pci_request_regions_exclusive, (struct pci_dev *pdev, const char *res_name), {
    PRE_WRAP(pdev);
    int ret = pci_request_regions_exclusive(pdev, res_name);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sata_scr_read, (struct ata_link *link, int reg, u32 *val), {
    PRE_WRAP(link);
    int ret = sata_scr_read(link, reg, val);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(mod_timer_pending, (struct timer_list *timer, unsigned long expires), {
    PRE_WRAP(timer);
    int ret = mod_timer_pending(timer, expires);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pnp_eisa_id_to_string, (u32 id, char *str), {
    pnp_eisa_id_to_string(id, str);
})

FUNCTION_WRAPPER_VOID(ata_pci_remove_one, (struct pci_dev *pdev), {
    PRE_WRAP(pdev);
    ata_pci_remove_one(pdev);
})

FUNCTION_WRAPPER(pnp_option_priority_name, (struct pnp_option *option), {
    PRE_WRAP(option);
    char *ret = pnp_option_priority_name(option);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_write_end, (struct file *file, struct address_space *mapping, loff_t pos, unsigned int len, unsigned int copied, struct page *page, void *fsdata), {
    PRE_WRAP(file);
    PRE_WRAP(mapping);
    PRE_WRAP(page);
    int ret = simple_write_end(file, mapping, pos, len, copied, page, fsdata);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_register_mem_resource, (struct pnp_dev *dev, unsigned int option_flags, resource_size_t min, resource_size_t max, resource_size_t align, resource_size_t size, unsigned char flags), {
    PRE_WRAP(dev);
    int ret = pnp_register_mem_resource(dev, option_flags, min, max, align, size, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(inode_setattr, (struct inode *inode, struct iattr *attr), {
    PRE_WRAP(inode);
    PRE_WRAP(attr);
    int ret = inode_setattr(inode, attr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(rcu_watch_read_unlock_bh, (const char *loc), {
    rcu_watch_read_unlock_bh(loc);
})

FUNCTION_WRAPPER(jbd2_journal_write_metadata_buffer, (transaction_t *transaction, struct journal_head *jh_in, struct journal_head **jh_out, unsigned long long blocknr), {
    PRE_WRAP(transaction);
    PRE_WRAP(jh_in);
    int ret = jbd2_journal_write_metadata_buffer(transaction, jh_in, jh_out, blocknr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(device_move, (struct device *dev, struct device *new_parent, enum dpm_order dpm_order), {
    PRE_WRAP(dev);
    PRE_WRAP(new_parent);
    int ret = device_move(dev, new_parent, dpm_order);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_remove_sysfs_dev_files, (struct pci_dev *pdev), {
    PRE_WRAP(pdev);
    pci_remove_sysfs_dev_files(pdev);
})

FUNCTION_WRAPPER(pci_find_next_bus, (const struct pci_bus *from), {
    PRE_WRAP(from);
    struct pci_bus *ret = pci_find_next_bus(from);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(kernel_sock_shutdown, (struct socket *sock, enum sock_shutdown_cmd how), {
    PRE_WRAP(sock);
    int ret = kernel_sock_shutdown(sock, how);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(bd_release, (struct block_device *bdev), {
    PRE_WRAP(bdev);
    bd_release(bdev);
})

FUNCTION_WRAPPER(journal_recover, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = journal_recover(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_unmap_ring, (struct xenbus_device *dev, grant_handle_t handle, void *vaddr), {
    PRE_WRAP(dev);
    int ret = xenbus_unmap_ring(dev, handle, vaddr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(debugfs_create_size_t, (const char *name, mode_t mode, struct dentry *parent, size_t *value), {
    PRE_WRAP(parent);
    struct dentry *ret = debugfs_create_size_t(name, mode, parent, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_fsync_range, (struct file *file, struct dentry *dentry, loff_t start, loff_t end, int datasync), {
    PRE_WRAP(file);
    PRE_WRAP(dentry);
    int ret = vfs_fsync_range(file, dentry, start, end, datasync);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_enable_resources, (struct pci_dev *dev, int mask), {
    PRE_WRAP(dev);
    int ret = pci_enable_resources(dev, mask);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(memscan, (void *addr, int c, size_t size), {
    void *ret = memscan(addr, c, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_lock_updates, (journal_t *journal), {
    PRE_WRAP(journal);
    jbd2_journal_lock_updates(journal);
})

FUNCTION_WRAPPER(ethtool_op_get_link, (struct net_device *dev), {
    PRE_WRAP(dev);
    u32 ret = ethtool_op_get_link(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_commit_transaction, (journal_t *journal), {
    PRE_WRAP(journal);
    jbd2_journal_commit_transaction(journal);
})

FUNCTION_WRAPPER(acpi_smbus_write, (struct acpi_smb_hc *hc, u8 protocol, u8 address, u8 command, u8 *data, u8 length), {
    PRE_WRAP(hc);
    int ret = acpi_smbus_write(hc, protocol, address, command, data, length);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_enable_sriov, (struct pci_dev *dev, int nr_virtfn), {
    PRE_WRAP(dev);
    int ret = pci_enable_sriov(dev, nr_virtfn);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_read, (struct file *file, char *buf, size_t count, loff_t *pos), {
    PRE_WRAP(file);
    ssize_t ret = vfs_read(file, buf, count, pos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_get_resource, (struct pnp_dev *dev, unsigned long type, unsigned int num), {
    PRE_WRAP(dev);
    struct resource *ret = pnp_get_resource(dev, type, num);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(proc_sid_connector, (struct task_struct *task), {
    PRE_WRAP(task);
    proc_sid_connector(task);
})

FUNCTION_WRAPPER(pnp_add_card, (struct pnp_card *card), {
    PRE_WRAP(card);
    int ret = pnp_add_card(card);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_clear_err, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = journal_clear_err(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(del_timer, (struct timer_list *timer), {
    PRE_WRAP(timer);
    int ret = del_timer(timer);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(kmem_cache_create, (const char *name, size_t size, size_t align, unsigned long flags, void (*ctor)(void *)), {
    WRAP_FUNCTION(ctor);
    struct kmem_cache *ret = kmem_cache_create(name, size, align, flags, ctor);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_dev_probe, (struct device *_dev), {
    PRE_WRAP(_dev);
    int ret = xenbus_dev_probe(_dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(journal_lock_updates, (journal_t *journal), {
    PRE_WRAP(journal);
    journal_lock_updates(journal);
})

FUNCTION_WRAPPER_VOID(simple_transaction_set, (struct file *file, size_t n), {
    PRE_WRAP(file);
    simple_transaction_set(file, n);
})

FUNCTION_WRAPPER(i2c_smbus_write_block_data, (struct i2c_client *client, u8 command, u8 length, const u8 *values), {
    PRE_WRAP(client);
    s32 ret = i2c_smbus_write_block_data(client, command, length, values);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(lock_kernel, (), {
    lock_kernel();
})

FUNCTION_WRAPPER_VOID(unlock_page, (struct page *page), {
    PRE_WRAP(page);
    unlock_page(page);
})

FUNCTION_WRAPPER_VOID(input_set_capability, (struct input_dev *dev, unsigned int type, unsigned int code), {
    PRE_WRAP(dev);
    input_set_capability(dev, type, code);
})

FUNCTION_WRAPPER(match_int, (substring_t *s, int *result), {
    PRE_WRAP(s);
    int ret = match_int(s, result);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(input_register_handler, (struct input_handler *handler), {
    PRE_WRAP(handler);
    int ret = input_register_handler(handler);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_claim_resource, (struct pci_dev *dev, int resource), {
    PRE_WRAP(dev);
    int ret = pci_claim_resource(dev, resource);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_permission, (struct inode *inode, int mask, int (*check_acl)(struct inode *, int)), {
    PRE_WRAP(inode);
    WRAP_FUNCTION(check_acl);
    int ret = generic_permission(inode, mask, check_acl);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_dointvec_userhz_jiffies, (struct ctl_table *table, int write, void *buffer, size_t *lenp, loff_t *ppos), {
    PRE_WRAP(table);
    int ret = proc_dointvec_userhz_jiffies(table, write, buffer, lenp, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(block_truncate_page, (struct address_space *mapping, loff_t from, get_block_t get_block), {
    PRE_WRAP(mapping);
    WRAP_FUNCTION(get_block);
    int ret = block_truncate_page(mapping, from, get_block);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(netif_notify_peers, (struct net_device *dev), {
    PRE_WRAP(dev);
    netif_notify_peers(dev);
})

FUNCTION_WRAPPER(vfs_readv, (struct file *file, const struct iovec *vec, unsigned long vlen, loff_t *pos), {
    PRE_WRAP(file);
    PRE_WRAP(vec);
    ssize_t ret = vfs_readv(file, vec, vlen, pos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(debugfs_remove, (struct dentry *dentry), {
    PRE_WRAP(dentry);
    debugfs_remove(dentry);
})

FUNCTION_WRAPPER(input_event_from_user, (const char *buffer, struct input_event *event), {
    PRE_WRAP(event);
    int ret = input_event_from_user(buffer, event);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_cpu_clock_getres, (const clockid_t which_clock, struct timespec *tp), {
    PRE_WRAP(tp);
    int ret = posix_cpu_clock_getres(which_clock, tp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(journal_abort, (journal_t *journal, int errno), {
    PRE_WRAP(journal);
    journal_abort(journal, errno);
})

FUNCTION_WRAPPER(xenbus_transaction_end, (struct xenbus_transaction t, int abort), {
    PRE_WRAP(t);
    int ret = xenbus_transaction_end(t, abort);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_wmalloc, (struct sock *sk, unsigned long size, int force, gfp_t priority), {
    PRE_WRAP(sk);
    struct sk_buff *ret = sock_wmalloc(sk, size, force, priority);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_quota_off, (struct super_block *sb, int type, int remount), {
    PRE_WRAP(sb);
    int ret = vfs_quota_off(sb, type, remount);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_file_llseek, (struct file *file, loff_t offset, int origin), {
    PRE_WRAP(file);
    loff_t ret = generic_file_llseek(file, offset, origin);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(input_ff_event, (struct input_dev *dev, unsigned int type, unsigned int code, int value), {
    PRE_WRAP(dev);
    int ret = input_ff_event(dev, type, code, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(netif_device_detach, (struct net_device *dev), {
    PRE_WRAP(dev);
    netif_device_detach(dev);
})

FUNCTION_WRAPPER(jbd2_journal_restart, (handle_t *handle, int nblocks), {
    PRE_WRAP(handle);
    int ret = jbd2_journal_restart(handle, nblocks);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(simple_release_fs, (struct vfsmount **mount, int *count), {
    simple_release_fs(mount, count);
})

FUNCTION_WRAPPER(do_posix_clock_nonanosleep, (const clockid_t clock, int flags, struct timespec *t, struct timespec *r), {
    PRE_WRAP(t);
    PRE_WRAP(r);
    int ret = do_posix_clock_nonanosleep(clock, flags, t, r);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_ats_queue_depth, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_ats_queue_depth(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(rcu_watch_read_unlock_sched, (const char *loc), {
    rcu_watch_read_unlock_sched(loc);
})

FUNCTION_WRAPPER_VOID(jbd2_journal_file_buffer, (struct journal_head *jh, transaction_t *transaction, int jlist), {
    PRE_WRAP(jh);
    PRE_WRAP(transaction);
    jbd2_journal_file_buffer(jh, transaction, jlist);
})

FUNCTION_WRAPPER_VOID(add_input_randomness, (unsigned int type, unsigned int code, unsigned int value), {
    add_input_randomness(type, code, value);
})

FUNCTION_WRAPPER(pnp_range_reserved, (resource_size_t start, resource_size_t end), {
    int ret = pnp_range_reserved(start, end);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(xenbus_dev_error, (struct xenbus_device *dev, int err, const char *fmt, ...), {
    // TODO: variadic arguments
    PRE_WRAP(dev);
    xenbus_dev_error(dev, err, fmt);
})

FUNCTION_WRAPPER(simple_attr_release, (struct inode *inode, struct file *file), {
    PRE_WRAP(inode);
    PRE_WRAP(file);
    int ret = simple_attr_release(inode, file);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(remove_irq, (unsigned int irq, struct irqaction *act), {
    PRE_WRAP(act);
    remove_irq(irq, act);
})

FUNCTION_WRAPPER_VOID(rcu_watch_read_unlock, (const char *loc), {
    rcu_watch_read_unlock(loc);
})

FUNCTION_WRAPPER(journal_bmap, (journal_t *journal, unsigned int blocknr, unsigned int *retp), {
    PRE_WRAP(journal);
    int ret = journal_bmap(journal, blocknr, retp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_force_commit, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = journal_force_commit(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_listxattr, (struct dentry *d, char *list, size_t size), {
    PRE_WRAP(d);
    ssize_t ret = vfs_listxattr(d, list, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(journal_ack_err, (journal_t *journal), {
    PRE_WRAP(journal);
    journal_ack_err(journal);
})

FUNCTION_WRAPPER(jbd2_journal_bmap, (journal_t *journal, unsigned long blocknr, unsigned long long *retp), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_bmap(journal, blocknr, retp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(lock_super, (struct super_block *sb), {
    PRE_WRAP(sb);
    lock_super(sb);
})

FUNCTION_WRAPPER_VOID(free_proc_entry, (struct proc_dir_entry *de), {
    PRE_WRAP(de);
    free_proc_entry(de);
})

FUNCTION_WRAPPER(mdiobus_alloc, (), {
    struct mii_bus *ret = mdiobus_alloc();
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_add_journal_head, (struct buffer_head *bh), {
    PRE_WRAP(bh);
    struct journal_head *ret = jbd2_journal_add_journal_head(bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_transaction_read, (struct file *file, char *buf, size_t size, loff_t *pos), {
    PRE_WRAP(file);
    ssize_t ret = simple_transaction_read(file, buf, size, pos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(genphy_resume, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = genphy_resume(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(read_otherend_details, (struct xenbus_device *xendev, char *id_node, char *path_node), {
    PRE_WRAP(xendev);
    int ret = read_otherend_details(xendev, id_node, path_node);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_enable_device_io, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_enable_device_io(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(alloc_etherdev_mq, (int sizeof_priv, unsigned int queue_count), {
    struct net_device *ret = alloc_etherdev_mq(sizeof_priv, queue_count);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sata_link_hardreset, (struct ata_link *link, unsigned const long *timing, unsigned long deadline, bool *online, int (*check_ready)(struct ata_link *)), {
    PRE_WRAP(link);
    WRAP_FUNCTION(check_ready);
    int ret = sata_link_hardreset(link, timing, deadline, online, check_ready);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(input_ff_destroy, (struct input_dev *dev), {
    PRE_WRAP(dev);
    input_ff_destroy(dev);
})

FUNCTION_WRAPPER(napi_gro_receive, (struct napi_struct *napi, struct sk_buff *skb), {
    PRE_WRAP(napi);
    PRE_WRAP(skb);
    gro_result_t ret = napi_gro_receive(napi, skb);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_start, (journal_t *journal, int nblocks), {
    PRE_WRAP(journal);
    handle_t *ret = journal_start(journal, nblocks);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(alloc_pages_current, (gfp_t gfp, unsigned int order), {
    struct page *ret = alloc_pages_current(gfp, order);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_create, (struct inode *dir, struct dentry *dentry, int mode, struct nameidata *nd), {
    PRE_WRAP(dir);
    PRE_WRAP(dentry);
    PRE_WRAP(nd);
    int ret = vfs_create(dir, dentry, mode, nd);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_tag_bytes, (journal_t *journal), {
    PRE_WRAP(journal);
    size_t ret = journal_tag_bytes(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_switch_state, (struct xenbus_device *dev, enum xenbus_state state), {
    PRE_WRAP(dev);
    int ret = xenbus_switch_state(dev, state);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_pipe_buf_steal, (struct pipe_inode_info *pipe, struct pipe_buffer *buf), {
    PRE_WRAP(pipe);
    PRE_WRAP(buf);
    int ret = generic_pipe_buf_steal(pipe, buf);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(phy_register_fixup, (const char *bus_id, u32 phy_uid, u32 phy_uid_mask, int (*run)(struct phy_device *)), {
    WRAP_FUNCTION(run);
    int ret = phy_register_fixup(bus_id, phy_uid, phy_uid_mask, run);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_test_lock, (struct file *filp, struct file_lock *fl), {
    PRE_WRAP(filp);
    PRE_WRAP(fl);
    int ret = vfs_test_lock(filp, fl);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_dev_get, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    struct pci_dev *ret = pci_dev_get(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_dirty_metadata, (handle_t *handle, struct buffer_head *bh), {
    PRE_WRAP(handle);
    PRE_WRAP(bh);
    int ret = jbd2_journal_dirty_metadata(handle, bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(wake_up_process, (struct task_struct *p), {
    PRE_WRAP(p);
    int ret = wake_up_process(p);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(mpage_readpage, (struct page *page, get_block_t get_block), {
    PRE_WRAP(page);
    WRAP_FUNCTION(get_block);
    int ret = mpage_readpage(page, get_block);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(device_find_child, (struct device *parent, void *data, int (*match)(struct device *, void *)), {
    PRE_WRAP(parent);
    WRAP_FUNCTION(match);
    struct device *ret = device_find_child(parent, data, match);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_get_write_access, (handle_t *handle, struct buffer_head *bh), {
    PRE_WRAP(handle);
    PRE_WRAP(bh);
    int ret = jbd2_journal_get_write_access(handle, bh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_unmap_ring_vfree, (struct xenbus_device *dev, void *vaddr), {
    PRE_WRAP(dev);
    int ret = xenbus_unmap_ring_vfree(dev, vaddr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_cpu_clock_get, (const clockid_t which_clock, struct timespec *tp), {
    PRE_WRAP(tp);
    int ret = posix_cpu_clock_get(which_clock, tp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(eth_header_cache, (const struct neighbour *neigh, struct hh_cache *hh), {
    PRE_WRAP(neigh);
    PRE_WRAP(hh);
    int ret = eth_header_cache(neigh, hh);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(input_ff_effect_from_user, (const char *buffer, size_t size, struct ff_effect *effect), {
    PRE_WRAP(effect);
    int ret = input_ff_effect_from_user(buffer, size, effect);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(param_get_uint, (char *buffer, struct kernel_param *kp), {
    PRE_WRAP(kp);
    int ret = param_get_uint(buffer, kp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_add_dynid, (struct pci_driver *drv, unsigned int vendor, unsigned int device, unsigned int subvendor, unsigned int subdevice, unsigned int class_ele, unsigned int class_mask, unsigned long driver_data), {
    PRE_WRAP(drv);
    int ret = pci_add_dynid(drv, vendor, device, subvendor, subdevice, class_ele, class_mask, driver_data);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(phy_enable_interrupts, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = phy_enable_interrupts(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_mkdir_mode, (const char *name, mode_t mode, struct proc_dir_entry *parent), {
    PRE_WRAP(parent);
    struct proc_dir_entry *ret = proc_mkdir_mode(name, mode, parent);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(free_buffer_head, (struct buffer_head *bh), {
    PRE_WRAP(bh);
    free_buffer_head(bh);
})

FUNCTION_WRAPPER(journal_try_to_free_buffers, (journal_t *journal, struct page *page, gfp_t gfp_mask), {
    PRE_WRAP(journal);
    PRE_WRAP(page);
    int ret = journal_try_to_free_buffers(journal, page, gfp_mask);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(dbg_pnp_show_option, (struct pnp_dev *dev, struct pnp_option *option), {
    PRE_WRAP(dev);
    PRE_WRAP(option);
    dbg_pnp_show_option(dev, option);
})

FUNCTION_WRAPPER_VOID(mcount, (), {
    mcount();
})

FUNCTION_WRAPPER(generic_file_direct_write, (struct kiocb *iocb, const struct iovec *iov, unsigned long *nr_segs, loff_t pos, loff_t *ppos, size_t count, size_t ocount), {
    PRE_WRAP(iocb);
    PRE_WRAP(iov);
    ssize_t ret = generic_file_direct_write(iocb, iov, nr_segs, pos, ppos, count, ocount);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(ata_pci_sff_init_host, (struct ata_host *host), {
    PRE_WRAP(host);
    int ret = ata_pci_sff_init_host(host);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_user_read_config_dword, (struct pci_dev *dev, int pos, u32 *val), {
    PRE_WRAP(dev);
    int ret = pci_user_read_config_dword(dev, pos, val);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_create_lite, (int family, int type, int protocol, struct socket **res), {
    int ret = sock_create_lite(family, type, protocol, res);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dev_driver_string, (const struct device *dev), {
    PRE_WRAP(dev);
    const char *ret = dev_driver_string(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(sock_unregister, (int family), {
    sock_unregister(family);
})

FUNCTION_WRAPPER_VOID(mutex_lock, (struct mutex *lock), {
    PRE_WRAP(lock);
    mutex_lock(lock);
})

FUNCTION_WRAPPER_VOID(rcu_watch_read_lock_sched, (const char *loc), {
    rcu_watch_read_lock_sched(loc);
})

FUNCTION_WRAPPER(posix_lock_file, (struct file *filp, struct file_lock *fl, struct file_lock *conflock), {
    PRE_WRAP(filp);
    PRE_WRAP(fl);
    PRE_WRAP(conflock);
    int ret = posix_lock_file(filp, fl, conflock);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_add_new_bus, (struct pci_bus *parent, struct pci_dev *dev, int busnr), {
    PRE_WRAP(parent);
    PRE_WRAP(dev);
    struct pci_bus *ret = pci_add_new_bus(parent, dev, busnr);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_lookup, (struct inode *dir, struct dentry *dentry, struct nameidata *nd), {
    PRE_WRAP(dir);
    PRE_WRAP(dentry);
    PRE_WRAP(nd);
    struct dentry *ret = proc_lookup(dir, dentry, nd);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(posix_acl_from_xattr, (void *value, size_t size), {
    struct posix_acl *ret = posix_acl_from_xattr(value, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_scan_child_bus, (struct pci_bus *bus), {
    PRE_WRAP(bus);
    int ret = pci_scan_child_bus(bus);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_check_irq, (struct pnp_dev *dev, struct resource *res), {
    PRE_WRAP(dev);
    PRE_WRAP(res);
    int ret = pnp_check_irq(dev, res);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(param_array_set, (const char *val, struct kernel_param *kp), {
    PRE_WRAP(kp);
    int ret = param_array_set(val, kp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(genphy_config_advert, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = genphy_config_advert(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_restore_state, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_restore_state(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(sock_register, (const struct net_proto_family *ops), {
    PRE_WRAP(ops);
    int ret = sock_register(ops);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_journal_destroy_revoke_caches, (), {
    jbd2_journal_destroy_revoke_caches();
})

FUNCTION_WRAPPER(sock_no_getsockopt, (struct socket *sock, int level, int optname, char *optval, int *optlen), {
    PRE_WRAP(sock);
    int ret = sock_no_getsockopt(sock, level, optname, optval, optlen);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_lock_file, (struct file *filp, unsigned int cmd, struct file_lock *fl, struct file_lock *conf), {
    PRE_WRAP(filp);
    PRE_WRAP(fl);
    PRE_WRAP(conf);
    int ret = vfs_lock_file(filp, cmd, fl, conf);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_error_remove_page, (struct address_space *mapping, struct page *page), {
    PRE_WRAP(mapping);
    PRE_WRAP(page);
    int ret = generic_error_remove_page(mapping, page);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_choose_state, (struct pci_dev *dev, pm_message_t state), {
    PRE_WRAP(dev);
    PRE_WRAP(state);
    pci_power_t ret = pci_choose_state(dev, state);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_register_driver_common, (struct xenbus_driver *drv, struct xen_bus_type *bus, struct module *owner, const char *mod_name), {
    PRE_WRAP(drv);
    PRE_WRAP(bus);
    PRE_WRAP(owner);
    int ret = xenbus_register_driver_common(drv, bus, owner, mod_name);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(input_set_keycode, (struct input_dev *dev, int scancode, int keycode), {
    PRE_WRAP(dev);
    int ret = input_set_keycode(dev, scancode, keycode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_get_descriptor_buffer, (journal_t *journal), {
    PRE_WRAP(journal);
    struct journal_head *ret = journal_get_descriptor_buffer(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_file_open, (struct inode *inode, struct file *filp), {
    PRE_WRAP(inode);
    PRE_WRAP(filp);
    int ret = generic_file_open(inode, filp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pnp_unregister_driver, (struct pnp_driver *drv), {
    PRE_WRAP(drv);
    pnp_unregister_driver(drv);
})

FUNCTION_WRAPPER(proc_dointvec_jiffies, (struct ctl_table *table, int write, void *buffer, size_t *lenp, loff_t *ppos), {
    PRE_WRAP(table);
    int ret = proc_dointvec_jiffies(table, write, buffer, lenp, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(platform_pci_wakeup_init, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    platform_pci_wakeup_init(dev);
})

FUNCTION_WRAPPER(generic_setxattr, (struct dentry *dentry, char *name, void *value, size_t size, int flags), {
    PRE_WRAP(dentry);
    int ret = generic_setxattr(dentry, name, value, size, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(ktime_get, (), {
    ktime_t ret = ktime_get();
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_reenable_device, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    int ret = pci_reenable_device(dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_match_id, (const struct pci_device_id *ids, struct pci_dev *dev), {
    PRE_WRAP(ids);
    PRE_WRAP(dev);
    const struct pci_device_id *ret = pci_match_id(ids, dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(debugfs_create_u8, (const char *name, mode_t mode, struct dentry *parent, u8 *value), {
    PRE_WRAP(parent);
    struct dentry *ret = debugfs_create_u8(name, mode, parent, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_enable_msix, (struct pci_dev *dev, struct msix_entry *entries, int nvec), {
    PRE_WRAP(dev);
    PRE_WRAP(entries);
    int ret = pci_enable_msix(dev, entries, nvec);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_select_bars, (struct pci_dev *dev, unsigned long flags), {
    PRE_WRAP(dev);
    int ret = pci_select_bars(dev, flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pnp_device_attach, (struct pnp_dev *pnp_dev), {
    PRE_WRAP(pnp_dev);
    int ret = pnp_device_attach(pnp_dev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(debugfs_create_blob, (const char *name, mode_t mode, struct dentry *parent, struct debugfs_blob_wrapper *blob), {
    PRE_WRAP(parent);
    PRE_WRAP(blob);
    struct dentry *ret = debugfs_create_blob(name, mode, parent, blob);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(jbd2_buffer_abort_trigger, (struct journal_head *jh, struct jbd2_buffer_trigger_type *triggers), {
    PRE_WRAP(jh);
    PRE_WRAP(triggers);
    jbd2_buffer_abort_trigger(jh, triggers);
})

FUNCTION_WRAPPER(pci_create_bus, (struct device *parent, int bus, struct pci_ops *ops, void *sysdata), {
    PRE_WRAP(parent);
    PRE_WRAP(ops);
    struct pci_bus *ret = pci_create_bus(parent, bus, ops, sysdata);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_hp_deregister, (struct hotplug_slot *hotplug), {
    PRE_WRAP(hotplug);
    int ret = pci_hp_deregister(hotplug);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(input_flush_device, (struct input_handle *handle, struct file *file), {
    PRE_WRAP(handle);
    PRE_WRAP(file);
    int ret = input_flush_device(handle, file);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_watch_path, (struct xenbus_device *dev, const char *path, struct xenbus_watch *watch, void (*callback)(struct xenbus_watch *, const char **, unsigned int)), {
    PRE_WRAP(dev);
    PRE_WRAP(watch);
    WRAP_FUNCTION(callback);
    int ret = xenbus_watch_path(dev, path, watch, callback);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(debugfs_create_x16, (const char *name, mode_t mode, struct dentry *parent, u16 *value), {
    PRE_WRAP(parent);
    struct dentry *ret = debugfs_create_x16(name, mode, parent, value);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(inode_add_bytes, (struct inode *inode, loff_t bytes), {
    PRE_WRAP(inode);
    inode_add_bytes(inode, bytes);
})

FUNCTION_WRAPPER_VOID(device_release_driver, (struct device *dev), {
    PRE_WRAP(dev);
    device_release_driver(dev);
})

FUNCTION_WRAPPER(_spin_trylock, (spinlock_t *lock), {
    PRE_WRAP(lock);
    int ret = _spin_trylock(lock);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(xenbus_dev_fatal, (struct xenbus_device *dev, int err, const char *fmt, ...), {
    // TODO: variadic arguments
    PRE_WRAP(dev);
    xenbus_dev_fatal(dev, err, fmt);
})

FUNCTION_WRAPPER_VOID(set_bh_page, (struct buffer_head *bh, struct page *page, unsigned long offset), {
    PRE_WRAP(bh);
    PRE_WRAP(page);
    set_bh_page(bh, page, offset);
})

FUNCTION_WRAPPER(pnp_alloc_dev, (struct pnp_protocol *protocol, int id, char *pnpid), {
    PRE_WRAP(protocol);
    struct pnp_dev *ret = pnp_alloc_dev(protocol, id, pnpid);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(_write_lock_irqsave, (rwlock_t *lock), {
    PRE_WRAP(lock);
    long ret = _write_lock_irqsave(lock);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(eth_header_cache_update, (struct hh_cache *hh, const struct net_device *dev, unsigned const char *haddr), {
    PRE_WRAP(hh);
    PRE_WRAP(dev);
    eth_header_cache_update(hh, dev, haddr);
})

FUNCTION_WRAPPER(skb_gso_segment, (struct sk_buff *skb, int features), {
    PRE_WRAP(skb);
    struct sk_buff *ret = skb_gso_segment(skb, features);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(ata_pci_device_resume, (struct pci_dev *pdev), {
    PRE_WRAP(pdev);
    int ret = ata_pci_device_resume(pdev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(schedule, (), {
    schedule();
})

FUNCTION_WRAPPER(pnp_check_dma, (struct pnp_dev *dev, struct resource *res), {
    PRE_WRAP(dev);
    PRE_WRAP(res);
    int ret = pnp_check_dma(dev, res);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(vfs_quota_on, (struct super_block *sb, int type, int format_id, char *name, int remount), {
    PRE_WRAP(sb);
    int ret = vfs_quota_on(sb, type, format_id, name, remount);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(nobh_write_begin, (struct file *file, struct address_space *mapping, loff_t pos, unsigned int len, unsigned int flags, struct page **pagep, void **fsdata, get_block_t get_block), {
    PRE_WRAP(file);
    PRE_WRAP(mapping);
    WRAP_FUNCTION(get_block);
    int ret = nobh_write_begin(file, mapping, pos, len, flags, pagep, fsdata, get_block);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(simple_strtol, (const char *cp, char **endp, unsigned int base), {
    long ret = simple_strtol(cp, endp, base);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_segment_checks, (const struct iovec *iov, unsigned long *nr_segs, size_t *count, int access_flags), {
    PRE_WRAP(iov);
    int ret = generic_segment_checks(iov, nr_segs, count, access_flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(jbd2_journal_update_format, (journal_t *journal), {
    PRE_WRAP(journal);
    int ret = jbd2_journal_update_format(journal);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_dev_present, (const struct pci_device_id *ids), {
    PRE_WRAP(ids);
    int ret = pci_dev_present(ids);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(autoremove_wake_function, (wait_queue_t *wait, unsigned int mode, int sync, void *key), {
    PRE_WRAP(wait);
    int ret = autoremove_wake_function(wait, mode, sync, key);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(netif_rx_ni, (struct sk_buff *skb), {
    PRE_WRAP(skb);
    int ret = netif_rx_ni(skb);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(genphy_read_status, (struct phy_device *phydev), {
    PRE_WRAP(phydev);
    int ret = genphy_read_status(phydev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(block_prepare_write, (struct page *page, unsigned int from, unsigned int to, get_block_t get_block), {
    PRE_WRAP(page);
    WRAP_FUNCTION(get_block);
    int ret = block_prepare_write(page, from, to, get_block);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(xenbus_match, (struct device *_dev, struct device_driver *_drv), {
    PRE_WRAP(_dev);
    PRE_WRAP(_drv);
    int ret = xenbus_match(_dev, _drv);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_next_log_block, (journal_t *journal, unsigned int *retp), {
    PRE_WRAP(journal);
    int ret = journal_next_log_block(journal, retp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dquot_free_inode, (const struct inode *inode, qsize_t number), {
    PRE_WRAP(inode);
    int ret = dquot_free_inode(inode, number);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dquot_commit, (struct dquot *dquot), {
    PRE_WRAP(dquot);
    int ret = dquot_commit(dquot);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(acpi_smbus_unregister_callback, (struct acpi_smb_hc *hc), {
    PRE_WRAP(hc);
    int ret = acpi_smbus_unregister_callback(hc);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(flush_scheduled_work, (), {
    flush_scheduled_work();
})

FUNCTION_WRAPPER(pcim_enable_device, (struct pci_dev *pdev), {
    PRE_WRAP(pdev);
    int ret = pcim_enable_device(pdev);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pnp_remove_card_device, (struct pnp_dev *dev), {
    PRE_WRAP(dev);
    pnp_remove_card_device(dev);
})

FUNCTION_WRAPPER(generic_pipe_buf_map, (struct pipe_inode_info *pipe, struct pipe_buffer *buf, int atomic), {
    PRE_WRAP(pipe);
    PRE_WRAP(buf);
    void *ret = generic_pipe_buf_map(pipe, buf, atomic);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(cancel_work_sync, (struct work_struct *work), {
    PRE_WRAP(work);
    int ret = cancel_work_sync(work);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(skb_put, (struct sk_buff *skb, unsigned int len), {
    PRE_WRAP(skb);
    unsigned char *ret = skb_put(skb, len);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(generic_fh_to_parent, (struct super_block *sb, struct fid *fid, int fh_len, int fh_type, get_inode get_node_data), {
    PRE_WRAP(sb);
    PRE_WRAP(fid);
    WRAP_FUNCTION(get_node_data);
    struct dentry *ret = generic_fh_to_parent(sb, fid, fh_len, fh_type, get_node_data);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(journal_update_superblock, (journal_t *journal, int wait), {
    PRE_WRAP(journal);
    journal_update_superblock(journal, wait);
})

FUNCTION_WRAPPER(vfs_follow_link, (struct nameidata *nd, const char *link), {
    PRE_WRAP(nd);
    int ret = vfs_follow_link(nd, link);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(ata_pci_sff_activate_host, (struct ata_host *host, irq_handler_t irq_handler, struct scsi_host_template *sht), {
    PRE_WRAP(host);
    WRAP_FUNCTION(irq_handler);
    PRE_WRAP(sht);
    int ret = ata_pci_sff_activate_host(host, irq_handler, sht);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(param_set_invbool, (const char *val, struct kernel_param *kp), {
    PRE_WRAP(kp);
    int ret = param_set_invbool(val, kp);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(mb_cache_entry_alloc, (struct mb_cache *cache, gfp_t gfp_flags), {
    PRE_WRAP(cache);
    struct mb_cache_entry *ret = mb_cache_entry_alloc(cache, gfp_flags);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(device_remove_bin_file, (struct device *dev, struct bin_attribute *attr), {
    PRE_WRAP(dev);
    PRE_WRAP(attr);
    device_remove_bin_file(dev, attr);
})

FUNCTION_WRAPPER(d_obtain_alias, (struct inode *inode), {
    PRE_WRAP(inode);
    struct dentry *ret = d_obtain_alias(inode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(journal_init_inode, (struct inode *inode), {
    PRE_WRAP(inode);
    journal_t *ret = journal_init_inode(inode);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(pci_get_rom_size, (struct pci_dev *pdev, void *rom, size_t size), {
    PRE_WRAP(pdev);
    size_t ret = pci_get_rom_size(pdev, rom, size);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pnp_init_resources, (struct pnp_dev *dev), {
    PRE_WRAP(dev);
    pnp_init_resources(dev);
})

FUNCTION_WRAPPER_VOID(pci_disable_msix, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_disable_msix(dev);
})

FUNCTION_WRAPPER(get_sb_bdev, (struct file_system_type *fs_type, int flags, const char *dev_name, void *data, fill_super fill_super_var, struct vfsmount *mnt), {
    PRE_WRAP(fs_type);
    WRAP_FUNCTION(fill_super_var);
    PRE_WRAP(mnt);
    int ret = get_sb_bdev(fs_type, flags, dev_name, data, fill_super_var, mnt);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(netdev_features_change, (struct net_device *dev), {
    PRE_WRAP(dev);
    netdev_features_change(dev);
})

FUNCTION_WRAPPER(posix_acl_valid, (const struct posix_acl *acl), {
    PRE_WRAP(acl);
    int ret = posix_acl_valid(acl);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(proc_doulongvec_ms_jiffies_minmax, (struct ctl_table *table, int write, void *buffer, size_t *lenp, loff_t *ppos), {
    PRE_WRAP(table);
    int ret = proc_doulongvec_ms_jiffies_minmax(table, write, buffer, lenp, ppos);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(path_put, (struct path *path), {
    PRE_WRAP(path);
    path_put(path);
})

FUNCTION_WRAPPER_VOID(pci_remove_behind_bridge, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_remove_behind_bridge(dev);
})

FUNCTION_WRAPPER(jbd2_journal_revoke, (handle_t *handle, unsigned long long blocknr, struct buffer_head *bh_in), {
    PRE_WRAP(handle);
    PRE_WRAP(bh_in);
    int ret = jbd2_journal_revoke(handle, blocknr, bh_in);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER(dmi_name_in_vendors, (const char *str), {
    int ret = dmi_name_in_vendors(str);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(pci_disable_enabled_device, (struct pci_dev *dev), {
    PRE_WRAP(dev);
    pci_disable_enabled_device(dev);
})

FUNCTION_WRAPPER(xenbus_free_evtchn, (struct xenbus_device *dev, int port), {
    PRE_WRAP(dev);
    int ret = xenbus_free_evtchn(dev, port);
    RETURN_WRAP(ret);
    return ret;
})

FUNCTION_WRAPPER_VOID(vfs_dq_drop, (struct inode *inode), {
    PRE_WRAP(inode);
    vfs_dq_drop(inode);
})

