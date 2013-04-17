#ifndef CAN_WRAP_setup_ioapic_dest
#   define CAN_WRAP_setup_ioapic_dest 0
#endif
DETACH(setup_ioapic_dest)
#ifndef CAN_WRAP_inet_twsk_deschedule
#   define CAN_WRAP_inet_twsk_deschedule 1
#endif
#if CAN_WRAP_inet_twsk_deschedule
    WRAP_FOR_DETACH(inet_twsk_deschedule)
#endif
#ifndef CAN_WRAP_pcibios_penalize_isa_irq
#   define CAN_WRAP_pcibios_penalize_isa_irq 0
#endif
DETACH(pcibios_penalize_isa_irq)
#ifndef CAN_WRAP_pcim_iomap_regions
#   define CAN_WRAP_pcim_iomap_regions 1
#endif
#if CAN_WRAP_pcim_iomap_regions
    WRAP_FOR_DETACH(pcim_iomap_regions)
#endif
#ifndef CAN_WRAP_blk_rq_check_limits
#   define CAN_WRAP_blk_rq_check_limits 1
#endif
#if CAN_WRAP_blk_rq_check_limits
    WRAP_FOR_DETACH(blk_rq_check_limits)
#endif
#ifndef CAN_WRAP___iowrite32_copy
#   define CAN_WRAP___iowrite32_copy 0
#endif
DETACH(__iowrite32_copy)
#ifndef CAN_WRAP_cgroup_taskset_cur_cgroup
#   define CAN_WRAP_cgroup_taskset_cur_cgroup 1
#endif
#if CAN_WRAP_cgroup_taskset_cur_cgroup
    WRAP_FOR_DETACH(cgroup_taskset_cur_cgroup)
#endif
#ifndef CAN_WRAP_acpi_get_override_irq
#   define CAN_WRAP_acpi_get_override_irq 0
#endif
DETACH(acpi_get_override_irq)
#ifndef CAN_WRAP_invalidate_interrupt10
#   define CAN_WRAP_invalidate_interrupt10 0
#endif
DETACH(invalidate_interrupt10)
#ifndef CAN_WRAP_cleancache_register_ops
#   define CAN_WRAP_cleancache_register_ops 1
#endif
#if CAN_WRAP_cleancache_register_ops
    WRAP_FOR_DETACH(cleancache_register_ops)
#endif
#ifndef CAN_WRAP_dma_find_channel
#   define CAN_WRAP_dma_find_channel 1
#endif
#if CAN_WRAP_dma_find_channel
    WRAP_FOR_DETACH(dma_find_channel)
#endif
#ifndef CAN_WRAP_ata_unpack_xfermask
#   define CAN_WRAP_ata_unpack_xfermask 0
#endif
DETACH(ata_unpack_xfermask)
#ifndef CAN_WRAP_cpu_disable_common
#   define CAN_WRAP_cpu_disable_common 0
#endif
DETACH(cpu_disable_common)
#ifndef CAN_WRAP_alternatives_smp_module_add
#   define CAN_WRAP_alternatives_smp_module_add 1
#endif
#if CAN_WRAP_alternatives_smp_module_add
    WRAP_FOR_DETACH(alternatives_smp_module_add)
#endif
#ifndef CAN_WRAP_pci_set_mwi
#   define CAN_WRAP_pci_set_mwi 1
#endif
#if CAN_WRAP_pci_set_mwi
    WRAP_FOR_DETACH(pci_set_mwi)
#endif
#ifndef CAN_WRAP_synchronize_net
#   define CAN_WRAP_synchronize_net 0
#endif
DETACH(synchronize_net)
#ifndef CAN_WRAP_proc_sched_set_task
#   define CAN_WRAP_proc_sched_set_task 1
#endif
#if CAN_WRAP_proc_sched_set_task
    WRAP_FOR_DETACH(proc_sched_set_task)
#endif
#ifndef CAN_WRAP_sysfs_merge_group
#   define CAN_WRAP_sysfs_merge_group 1
#endif
#if CAN_WRAP_sysfs_merge_group
    WRAP_FOR_DETACH(sysfs_merge_group)
#endif
#ifndef CAN_WRAP_eth_type_trans
#   define CAN_WRAP_eth_type_trans 1
#endif
#if CAN_WRAP_eth_type_trans
    WRAP_FOR_DETACH(eth_type_trans)
#endif
#ifndef CAN_WRAP_acpi_map_lsapic
#   define CAN_WRAP_acpi_map_lsapic 0
#endif
DETACH(acpi_map_lsapic)
#ifndef CAN_WRAP_numa_set_distance
#   define CAN_WRAP_numa_set_distance 0
#endif
DETACH(numa_set_distance)
#ifndef CAN_WRAP_crypto_destroy_tfm
#   define CAN_WRAP_crypto_destroy_tfm 1
#endif
#if CAN_WRAP_crypto_destroy_tfm
    WRAP_FOR_DETACH(crypto_destroy_tfm)
#endif
#ifndef CAN_WRAP_sparse_add_one_section
#   define CAN_WRAP_sparse_add_one_section 1
#endif
#if CAN_WRAP_sparse_add_one_section
    WRAP_FOR_DETACH(sparse_add_one_section)
#endif
#ifndef CAN_WRAP_nf_register_hooks
#   define CAN_WRAP_nf_register_hooks 1
#endif
#if CAN_WRAP_nf_register_hooks
    WRAP_FOR_DETACH(nf_register_hooks)
#endif
#ifndef CAN_WRAP_hrtimer_get_res
#   define CAN_WRAP_hrtimer_get_res 1
#endif
#if CAN_WRAP_hrtimer_get_res
    WRAP_FOR_DETACH(hrtimer_get_res)
#endif
#ifndef CAN_WRAP_alloc_disk_node
#   define CAN_WRAP_alloc_disk_node 1
#endif
#if CAN_WRAP_alloc_disk_node
    WRAP_FOR_DETACH(alloc_disk_node)
#endif
#ifndef CAN_WRAP___put_user_8
#   define CAN_WRAP___put_user_8 0
#endif
DETACH(__put_user_8)
#ifndef CAN_WRAP_vzalloc_node
#   define CAN_WRAP_vzalloc_node 0
#endif
DETACH(vzalloc_node)
#ifndef CAN_WRAP___symbol_put
#   define CAN_WRAP___symbol_put 0
#endif
DETACH(__symbol_put)
#ifndef CAN_WRAP_register_sysctl_root
#   define CAN_WRAP_register_sysctl_root 1
#endif
#if CAN_WRAP_register_sysctl_root
    WRAP_FOR_DETACH(register_sysctl_root)
#endif
#ifndef CAN_WRAP_mb_cache_entry_get
#   define CAN_WRAP_mb_cache_entry_get 1
#endif
#if CAN_WRAP_mb_cache_entry_get
    WRAP_FOR_DETACH(mb_cache_entry_get)
#endif
#ifndef CAN_WRAP_keyring_search
#   define CAN_WRAP_keyring_search 1
#endif
#if CAN_WRAP_keyring_search
    WRAP_FOR_DETACH(keyring_search)
#endif
#ifndef CAN_WRAP_get_seconds
#   define CAN_WRAP_get_seconds 0
#endif
DETACH(get_seconds)
#ifndef CAN_WRAP_clear_all_latency_tracing
#   define CAN_WRAP_clear_all_latency_tracing 1
#endif
#if CAN_WRAP_clear_all_latency_tracing
    WRAP_FOR_DETACH(clear_all_latency_tracing)
#endif
#ifndef CAN_WRAP_blk_queue_free_tags
#   define CAN_WRAP_blk_queue_free_tags 1
#endif
#if CAN_WRAP_blk_queue_free_tags
    WRAP_FOR_DETACH(blk_queue_free_tags)
#endif
#ifndef CAN_WRAP_security_inode_rmdir
#   define CAN_WRAP_security_inode_rmdir 1
#endif
#if CAN_WRAP_security_inode_rmdir
    WRAP_FOR_DETACH(security_inode_rmdir)
#endif
#ifndef CAN_WRAP_acpi_remove_table_handler
#   define CAN_WRAP_acpi_remove_table_handler 1
#endif
#if CAN_WRAP_acpi_remove_table_handler
    WRAP_FOR_DETACH(acpi_remove_table_handler)
#endif
#ifndef CAN_WRAP_dev_pm_qos_constraints_init
#   define CAN_WRAP_dev_pm_qos_constraints_init 1
#endif
#if CAN_WRAP_dev_pm_qos_constraints_init
    WRAP_FOR_DETACH(dev_pm_qos_constraints_init)
#endif
#ifndef CAN_WRAP_nr_processes
#   define CAN_WRAP_nr_processes 0
#endif
DETACH(nr_processes)
#ifndef CAN_WRAP_devres_for_each_res
#   define CAN_WRAP_devres_for_each_res 1
#endif
#if CAN_WRAP_devres_for_each_res
    WRAP_FOR_DETACH(devres_for_each_res)
#endif
#ifndef CAN_WRAP___jbd2_journal_abort_hard
#   define CAN_WRAP___jbd2_journal_abort_hard 1
#endif
#if CAN_WRAP___jbd2_journal_abort_hard
#   ifdef DETACH_ADDR___jbd2_journal_abort_hard
        WRAP_FOR_DETACH(__jbd2_journal_abort_hard)
#   else
        TYPED_DETACH(__jbd2_journal_abort_hard)
#   endif
#endif
#ifndef CAN_WRAP_alloc_buffer_head
#   define CAN_WRAP_alloc_buffer_head 1
#endif
#if CAN_WRAP_alloc_buffer_head
    WRAP_FOR_DETACH(alloc_buffer_head)
#endif
#ifndef CAN_WRAP___next_cpu
#   define CAN_WRAP___next_cpu 1
#endif
#if CAN_WRAP___next_cpu
#   ifdef DETACH_ADDR___next_cpu
        WRAP_FOR_DETACH(__next_cpu)
#   else
        TYPED_DETACH(__next_cpu)
#   endif
#endif
#ifndef CAN_WRAP_phy_get_eee_err
#   define CAN_WRAP_phy_get_eee_err 1
#endif
#if CAN_WRAP_phy_get_eee_err
    WRAP_FOR_DETACH(phy_get_eee_err)
#endif
#ifndef CAN_WRAP___d_drop
#   define CAN_WRAP___d_drop 1
#endif
#if CAN_WRAP___d_drop
#   ifdef DETACH_ADDR___d_drop
        WRAP_FOR_DETACH(__d_drop)
#   else
        TYPED_DETACH(__d_drop)
#   endif
#endif
#ifndef CAN_WRAP___alloc_pages_nodemask
#   define CAN_WRAP___alloc_pages_nodemask 1
#endif
#if CAN_WRAP___alloc_pages_nodemask
#   ifdef DETACH_ADDR___alloc_pages_nodemask
        WRAP_FOR_DETACH(__alloc_pages_nodemask)
#   else
        TYPED_DETACH(__alloc_pages_nodemask)
#   endif
#endif
#ifndef CAN_WRAP_bio_uncopy_user
#   define CAN_WRAP_bio_uncopy_user 1
#endif
#if CAN_WRAP_bio_uncopy_user
    WRAP_FOR_DETACH(bio_uncopy_user)
#endif
#ifndef CAN_WRAP_sata_pmp_error_handler
#   define CAN_WRAP_sata_pmp_error_handler 1
#endif
#if CAN_WRAP_sata_pmp_error_handler
    WRAP_FOR_DETACH(sata_pmp_error_handler)
#endif
#ifndef CAN_WRAP_inode_owner_or_capable
#   define CAN_WRAP_inode_owner_or_capable 1
#endif
#if CAN_WRAP_inode_owner_or_capable
    WRAP_FOR_DETACH(inode_owner_or_capable)
#endif
#ifndef CAN_WRAP_refresh_cpu_vm_stats
#   define CAN_WRAP_refresh_cpu_vm_stats 0
#endif
DETACH(refresh_cpu_vm_stats)
#ifndef CAN_WRAP_native_apic_wait_icr_idle
#   define CAN_WRAP_native_apic_wait_icr_idle 0
#endif
DETACH(native_apic_wait_icr_idle)
#ifndef CAN_WRAP_ll_rw_block
#   define CAN_WRAP_ll_rw_block 0
#endif
DETACH(ll_rw_block)
#ifndef CAN_WRAP_security_task_create
#   define CAN_WRAP_security_task_create 0
#endif
DETACH(security_task_create)
#ifndef CAN_WRAP_register_chrdev_region
#   define CAN_WRAP_register_chrdev_region 0
#endif
DETACH(register_chrdev_region)
#ifndef CAN_WRAP_mempool_alloc
#   define CAN_WRAP_mempool_alloc 1
#endif
#if CAN_WRAP_mempool_alloc
    WRAP_FOR_DETACH(mempool_alloc)
#endif
#ifndef CAN_WRAP_seq_release_private
#   define CAN_WRAP_seq_release_private 1
#endif
#if CAN_WRAP_seq_release_private
    WRAP_FOR_DETACH(seq_release_private)
#endif
#ifndef CAN_WRAP_pm_qos_request
#   define CAN_WRAP_pm_qos_request 0
#endif
DETACH(pm_qos_request)
#ifndef CAN_WRAP_blk_rq_map_sg
#   define CAN_WRAP_blk_rq_map_sg 1
#endif
#if CAN_WRAP_blk_rq_map_sg
    WRAP_FOR_DETACH(blk_rq_map_sg)
#endif
#ifndef CAN_WRAP_quota_send_warning
#   define CAN_WRAP_quota_send_warning 1
#endif
#if CAN_WRAP_quota_send_warning
    WRAP_FOR_DETACH(quota_send_warning)
#endif
#ifndef CAN_WRAP___register_sysctl_paths
#   define CAN_WRAP___register_sysctl_paths 1
#endif
#if CAN_WRAP___register_sysctl_paths
#   ifdef DETACH_ADDR___register_sysctl_paths
        WRAP_FOR_DETACH(__register_sysctl_paths)
#   else
        TYPED_DETACH(__register_sysctl_paths)
#   endif
#endif
#ifndef CAN_WRAP_clocksource_change_rating
#   define CAN_WRAP_clocksource_change_rating 1
#endif
#if CAN_WRAP_clocksource_change_rating
    WRAP_FOR_DETACH(clocksource_change_rating)
#endif
#ifndef CAN_WRAP_cleanup_module
#   define CAN_WRAP_cleanup_module 0
#endif
DETACH(cleanup_module)
#ifndef CAN_WRAP_tracepoint_probe_update_all
#   define CAN_WRAP_tracepoint_probe_update_all 0
#endif
DETACH(tracepoint_probe_update_all)
#ifndef CAN_WRAP_cap_task_setnice
#   define CAN_WRAP_cap_task_setnice 1
#endif
#if CAN_WRAP_cap_task_setnice
    WRAP_FOR_DETACH(cap_task_setnice)
#endif
#ifndef CAN_WRAP_acpi_disable
#   define CAN_WRAP_acpi_disable 0
#endif
DETACH(acpi_disable)
#ifndef CAN_WRAP_unmap_underlying_metadata
#   define CAN_WRAP_unmap_underlying_metadata 1
#endif
#if CAN_WRAP_unmap_underlying_metadata
    WRAP_FOR_DETACH(unmap_underlying_metadata)
#endif
#ifndef CAN_WRAP___isolate_lru_page
#   define CAN_WRAP___isolate_lru_page 1
#endif
#if CAN_WRAP___isolate_lru_page
#   ifdef DETACH_ADDR___isolate_lru_page
        WRAP_FOR_DETACH(__isolate_lru_page)
#   else
        TYPED_DETACH(__isolate_lru_page)
#   endif
#endif
#ifndef CAN_WRAP_put_io_context
#   define CAN_WRAP_put_io_context 1
#endif
#if CAN_WRAP_put_io_context
    WRAP_FOR_DETACH(put_io_context)
#endif
#ifndef CAN_WRAP_sysenter_setup
#   define CAN_WRAP_sysenter_setup 0
#endif
DETACH(sysenter_setup)
#ifndef CAN_WRAP_inet_twsk_schedule
#   define CAN_WRAP_inet_twsk_schedule 1
#endif
#if CAN_WRAP_inet_twsk_schedule
    WRAP_FOR_DETACH(inet_twsk_schedule)
#endif
#ifndef CAN_WRAP_profile_task_exit
#   define CAN_WRAP_profile_task_exit 1
#endif
#if CAN_WRAP_profile_task_exit
    WRAP_FOR_DETACH(profile_task_exit)
#endif
#ifndef CAN_WRAP_transfer_pid
#   define CAN_WRAP_transfer_pid 1
#endif
#if CAN_WRAP_transfer_pid
    WRAP_FOR_DETACH(transfer_pid)
#endif
#ifndef CAN_WRAP_neigh_table_init
#   define CAN_WRAP_neigh_table_init 1
#endif
#if CAN_WRAP_neigh_table_init
    WRAP_FOR_DETACH(neigh_table_init)
#endif
#ifndef CAN_WRAP_seq_hlist_start_head
#   define CAN_WRAP_seq_hlist_start_head 1
#endif
#if CAN_WRAP_seq_hlist_start_head
    WRAP_FOR_DETACH(seq_hlist_start_head)
#endif
#ifndef CAN_WRAP_mb_cache_entry_insert
#   define CAN_WRAP_mb_cache_entry_insert 1
#endif
#if CAN_WRAP_mb_cache_entry_insert
    WRAP_FOR_DETACH(mb_cache_entry_insert)
#endif
#ifndef CAN_WRAP_exit_signals
#   define CAN_WRAP_exit_signals 1
#endif
#if CAN_WRAP_exit_signals
    WRAP_FOR_DETACH(exit_signals)
#endif
#ifndef CAN_WRAP_sched_init
#   define CAN_WRAP_sched_init 0
#endif
DETACH(sched_init)
#ifndef CAN_WRAP_nf_setsockopt
#   define CAN_WRAP_nf_setsockopt 1
#endif
#if CAN_WRAP_nf_setsockopt
    WRAP_FOR_DETACH(nf_setsockopt)
#endif
#ifndef CAN_WRAP_writeback_inodes_sb_nr
#   define CAN_WRAP_writeback_inodes_sb_nr 1
#endif
#if CAN_WRAP_writeback_inodes_sb_nr
    WRAP_FOR_DETACH(writeback_inodes_sb_nr)
#endif
#ifndef CAN_WRAP_driver_find_device
#   define CAN_WRAP_driver_find_device 1
#endif
#if CAN_WRAP_driver_find_device
    WRAP_FOR_DETACH(driver_find_device)
#endif
#ifndef CAN_WRAP_vm_unmap_aliases
#   define CAN_WRAP_vm_unmap_aliases 0
#endif
DETACH(vm_unmap_aliases)
#ifndef CAN_WRAP_acpi_subsys_runtime_suspend
#   define CAN_WRAP_acpi_subsys_runtime_suspend 1
#endif
#if CAN_WRAP_acpi_subsys_runtime_suspend
    WRAP_FOR_DETACH(acpi_subsys_runtime_suspend)
#endif
#ifndef CAN_WRAP_irq_gc_noop
#   define CAN_WRAP_irq_gc_noop 1
#endif
#if CAN_WRAP_irq_gc_noop
    WRAP_FOR_DETACH(irq_gc_noop)
#endif
#ifndef CAN_WRAP_generic_shutdown_super
#   define CAN_WRAP_generic_shutdown_super 1
#endif
#if CAN_WRAP_generic_shutdown_super
    WRAP_FOR_DETACH(generic_shutdown_super)
#endif
#ifndef CAN_WRAP___udelay
#   define CAN_WRAP___udelay 0
#endif
DETACH(__udelay)
#ifndef CAN_WRAP_down_trylock
#   define CAN_WRAP_down_trylock 1
#endif
#if CAN_WRAP_down_trylock
    WRAP_FOR_DETACH(down_trylock)
#endif
#ifndef CAN_WRAP_cancel_dirty_page
#   define CAN_WRAP_cancel_dirty_page 1
#endif
#if CAN_WRAP_cancel_dirty_page
    WRAP_FOR_DETACH(cancel_dirty_page)
#endif
#ifndef CAN_WRAP_gen_estimator_active
#   define CAN_WRAP_gen_estimator_active 1
#endif
#if CAN_WRAP_gen_estimator_active
    WRAP_FOR_DETACH(gen_estimator_active)
#endif
#ifndef CAN_WRAP_security_socket_getpeersec_stream
#   define CAN_WRAP_security_socket_getpeersec_stream 1
#endif
#if CAN_WRAP_security_socket_getpeersec_stream
    WRAP_FOR_DETACH(security_socket_getpeersec_stream)
#endif
#ifndef CAN_WRAP_pci_destroy_slot
#   define CAN_WRAP_pci_destroy_slot 1
#endif
#if CAN_WRAP_pci_destroy_slot
    WRAP_FOR_DETACH(pci_destroy_slot)
#endif
#ifndef CAN_WRAP_sync_Arb_IDs
#   define CAN_WRAP_sync_Arb_IDs 0
#endif
DETACH(sync_Arb_IDs)
#ifndef CAN_WRAP_pci_bus_max_busnr
#   define CAN_WRAP_pci_bus_max_busnr 1
#endif
#if CAN_WRAP_pci_bus_max_busnr
    WRAP_FOR_DETACH(pci_bus_max_busnr)
#endif
#ifndef CAN_WRAP_napi_complete
#   define CAN_WRAP_napi_complete 1
#endif
#if CAN_WRAP_napi_complete
    WRAP_FOR_DETACH(napi_complete)
#endif
#ifndef CAN_WRAP_scsi_cmd_ioctl
#   define CAN_WRAP_scsi_cmd_ioctl 1
#endif
#if CAN_WRAP_scsi_cmd_ioctl
    WRAP_FOR_DETACH(scsi_cmd_ioctl)
#endif
#ifndef CAN_WRAP_set_online_page_callback
#   define CAN_WRAP_set_online_page_callback 1
#endif
#if CAN_WRAP_set_online_page_callback
    WRAP_FOR_DETACH(set_online_page_callback)
#endif
#ifndef CAN_WRAP_css_id
#   define CAN_WRAP_css_id 1
#endif
#if CAN_WRAP_css_id
    WRAP_FOR_DETACH(css_id)
#endif
#ifndef CAN_WRAP_sk_clear_memalloc
#   define CAN_WRAP_sk_clear_memalloc 1
#endif
#if CAN_WRAP_sk_clear_memalloc
    WRAP_FOR_DETACH(sk_clear_memalloc)
#endif
#ifndef CAN_WRAP_compat_sys_getsockopt
#   define CAN_WRAP_compat_sys_getsockopt 0
#endif
DETACH(compat_sys_getsockopt)
#ifndef CAN_WRAP_filemap_fdatawrite_range
#   define CAN_WRAP_filemap_fdatawrite_range 1
#endif
#if CAN_WRAP_filemap_fdatawrite_range
    WRAP_FOR_DETACH(filemap_fdatawrite_range)
#endif
#ifndef CAN_WRAP_bus_unregister
#   define CAN_WRAP_bus_unregister 1
#endif
#if CAN_WRAP_bus_unregister
    WRAP_FOR_DETACH(bus_unregister)
#endif
#ifndef CAN_WRAP_dev_pm_qos_add_notifier
#   define CAN_WRAP_dev_pm_qos_add_notifier 1
#endif
#if CAN_WRAP_dev_pm_qos_add_notifier
    WRAP_FOR_DETACH(dev_pm_qos_add_notifier)
#endif
#ifndef CAN_WRAP_call_srcu
#   define CAN_WRAP_call_srcu 1
#endif
#if CAN_WRAP_call_srcu
    WRAP_FOR_DETACH(call_srcu)
#endif
#ifndef CAN_WRAP___jbd2_log_start_commit
#   define CAN_WRAP___jbd2_log_start_commit 1
#endif
#if CAN_WRAP___jbd2_log_start_commit
#   ifdef DETACH_ADDR___jbd2_log_start_commit
        WRAP_FOR_DETACH(__jbd2_log_start_commit)
#   else
        TYPED_DETACH(__jbd2_log_start_commit)
#   endif
#endif
#ifndef CAN_WRAP_pcpu_page_first_chunk
#   define CAN_WRAP_pcpu_page_first_chunk 1
#endif
#if CAN_WRAP_pcpu_page_first_chunk
    WRAP_FOR_DETACH(pcpu_page_first_chunk)
#endif
#ifndef CAN_WRAP_acpi_bus_generate_proc_event4
#   define CAN_WRAP_acpi_bus_generate_proc_event4 0
#endif
DETACH(acpi_bus_generate_proc_event4)
#ifndef CAN_WRAP_sock_no_connect
#   define CAN_WRAP_sock_no_connect 1
#endif
#if CAN_WRAP_sock_no_connect
    WRAP_FOR_DETACH(sock_no_connect)
#endif
#ifndef CAN_WRAP_try_to_free_pages
#   define CAN_WRAP_try_to_free_pages 1
#endif
#if CAN_WRAP_try_to_free_pages
    WRAP_FOR_DETACH(try_to_free_pages)
#endif
#ifndef CAN_WRAP_ata_sff_data_xfer32
#   define CAN_WRAP_ata_sff_data_xfer32 1
#endif
#if CAN_WRAP_ata_sff_data_xfer32
    WRAP_FOR_DETACH(ata_sff_data_xfer32)
#endif
#ifndef CAN_WRAP_sock_no_getname
#   define CAN_WRAP_sock_no_getname 1
#endif
#if CAN_WRAP_sock_no_getname
    WRAP_FOR_DETACH(sock_no_getname)
#endif
#ifndef CAN_WRAP___fprop_inc_single
#   define CAN_WRAP___fprop_inc_single 1
#endif
#if CAN_WRAP___fprop_inc_single
#   ifdef DETACH_ADDR___fprop_inc_single
        WRAP_FOR_DETACH(__fprop_inc_single)
#   else
        TYPED_DETACH(__fprop_inc_single)
#   endif
#endif
#ifndef CAN_WRAP_mark_buffer_dirty
#   define CAN_WRAP_mark_buffer_dirty 1
#endif
#if CAN_WRAP_mark_buffer_dirty
    WRAP_FOR_DETACH(mark_buffer_dirty)
#endif
#ifndef CAN_WRAP_radix_tree_tag_clear
#   define CAN_WRAP_radix_tree_tag_clear 1
#endif
#if CAN_WRAP_radix_tree_tag_clear
    WRAP_FOR_DETACH(radix_tree_tag_clear)
#endif
#ifndef CAN_WRAP_putname
#   define CAN_WRAP_putname 1
#endif
#if CAN_WRAP_putname
    WRAP_FOR_DETACH(putname)
#endif
#ifndef CAN_WRAP_pci_add_resource_offset
#   define CAN_WRAP_pci_add_resource_offset 1
#endif
#if CAN_WRAP_pci_add_resource_offset
    WRAP_FOR_DETACH(pci_add_resource_offset)
#endif
#ifndef CAN_WRAP_compat_sys_open_by_handle_at
#   define CAN_WRAP_compat_sys_open_by_handle_at 1
#endif
#if CAN_WRAP_compat_sys_open_by_handle_at
    WRAP_FOR_DETACH(compat_sys_open_by_handle_at)
#endif
#ifndef CAN_WRAP_ata_pci_bmdma_init
#   define CAN_WRAP_ata_pci_bmdma_init 1
#endif
#if CAN_WRAP_ata_pci_bmdma_init
    WRAP_FOR_DETACH(ata_pci_bmdma_init)
#endif
#ifndef CAN_WRAP_calculate_pressure_threshold
#   define CAN_WRAP_calculate_pressure_threshold 1
#endif
#if CAN_WRAP_calculate_pressure_threshold
    WRAP_FOR_DETACH(calculate_pressure_threshold)
#endif
#ifndef CAN_WRAP_acpi_register_gsi
#   define CAN_WRAP_acpi_register_gsi 1
#endif
#if CAN_WRAP_acpi_register_gsi
    WRAP_FOR_DETACH(acpi_register_gsi)
#endif
#ifndef CAN_WRAP_inet_csk_get_port
#   define CAN_WRAP_inet_csk_get_port 1
#endif
#if CAN_WRAP_inet_csk_get_port
    WRAP_FOR_DETACH(inet_csk_get_port)
#endif
#ifndef CAN_WRAP_acpi_os_delete_lock
#   define CAN_WRAP_acpi_os_delete_lock 1
#endif
#if CAN_WRAP_acpi_os_delete_lock
    WRAP_FOR_DETACH(acpi_os_delete_lock)
#endif
#ifndef CAN_WRAP_copy_siginfo_to_user
#   define CAN_WRAP_copy_siginfo_to_user 1
#endif
#if CAN_WRAP_copy_siginfo_to_user
    WRAP_FOR_DETACH(copy_siginfo_to_user)
#endif
#ifndef CAN_WRAP___jbd2_log_space_left
#   define CAN_WRAP___jbd2_log_space_left 1
#endif
#if CAN_WRAP___jbd2_log_space_left
#   ifdef DETACH_ADDR___jbd2_log_space_left
        WRAP_FOR_DETACH(__jbd2_log_space_left)
#   else
        TYPED_DETACH(__jbd2_log_space_left)
#   endif
#endif
#ifndef CAN_WRAP_cred_to_ucred
#   define CAN_WRAP_cred_to_ucred 1
#endif
#if CAN_WRAP_cred_to_ucred
    WRAP_FOR_DETACH(cred_to_ucred)
#endif
#ifndef CAN_WRAP___dquot_free_space
#   define CAN_WRAP___dquot_free_space 1
#endif
#if CAN_WRAP___dquot_free_space
#   ifdef DETACH_ADDR___dquot_free_space
        WRAP_FOR_DETACH(__dquot_free_space)
#   else
        TYPED_DETACH(__dquot_free_space)
#   endif
#endif
#ifndef CAN_WRAP_ioread8_rep
#   define CAN_WRAP_ioread8_rep 0
#endif
DETACH(ioread8_rep)
#ifndef CAN_WRAP_kill_anon_super
#   define CAN_WRAP_kill_anon_super 1
#endif
#if CAN_WRAP_kill_anon_super
    WRAP_FOR_DETACH(kill_anon_super)
#endif
#ifndef CAN_WRAP_consume_skb
#   define CAN_WRAP_consume_skb 1
#endif
#if CAN_WRAP_consume_skb
    WRAP_FOR_DETACH(consume_skb)
#endif
#ifndef CAN_WRAP_time_to_tm
#   define CAN_WRAP_time_to_tm 1
#endif
#if CAN_WRAP_time_to_tm
    WRAP_FOR_DETACH(time_to_tm)
#endif
#ifndef CAN_WRAP___current_kernel_time
#   define CAN_WRAP___current_kernel_time 1
#endif
#if CAN_WRAP___current_kernel_time
#   ifdef DETACH_ADDR___current_kernel_time
        WRAP_FOR_DETACH(__current_kernel_time)
#   else
        TYPED_DETACH(__current_kernel_time)
#   endif
#endif
#ifndef CAN_WRAP_acpi_os_unmap_memory
#   define CAN_WRAP_acpi_os_unmap_memory 0
#endif
DETACH(acpi_os_unmap_memory)
#ifndef CAN_WRAP_compat_sys_time
#   define CAN_WRAP_compat_sys_time 0
#endif
DETACH(compat_sys_time)
#ifndef CAN_WRAP_strndup_user
#   define CAN_WRAP_strndup_user 0
#endif
DETACH(strndup_user)
#ifndef CAN_WRAP_signal_wake_up_state
#   define CAN_WRAP_signal_wake_up_state 1
#endif
#if CAN_WRAP_signal_wake_up_state
    WRAP_FOR_DETACH(signal_wake_up_state)
#endif
#ifndef CAN_WRAP_ata_timing_cycle2mode
#   define CAN_WRAP_ata_timing_cycle2mode 0
#endif
DETACH(ata_timing_cycle2mode)
#ifndef CAN_WRAP___online_page_free
#   define CAN_WRAP___online_page_free 1
#endif
#if CAN_WRAP___online_page_free
#   ifdef DETACH_ADDR___online_page_free
        WRAP_FOR_DETACH(__online_page_free)
#   else
        TYPED_DETACH(__online_page_free)
#   endif
#endif
#ifndef CAN_WRAP_cap_inode_need_killpriv
#   define CAN_WRAP_cap_inode_need_killpriv 1
#endif
#if CAN_WRAP_cap_inode_need_killpriv
    WRAP_FOR_DETACH(cap_inode_need_killpriv)
#endif
#ifndef CAN_WRAP_dma_async_memcpy_buf_to_buf
#   define CAN_WRAP_dma_async_memcpy_buf_to_buf 1
#endif
#if CAN_WRAP_dma_async_memcpy_buf_to_buf
    WRAP_FOR_DETACH(dma_async_memcpy_buf_to_buf)
#endif
#ifndef CAN_WRAP_wait_for_completion_killable_timeout
#   define CAN_WRAP_wait_for_completion_killable_timeout 1
#endif
#if CAN_WRAP_wait_for_completion_killable_timeout
    WRAP_FOR_DETACH(wait_for_completion_killable_timeout)
#endif
#ifndef CAN_WRAP_generic_make_request
#   define CAN_WRAP_generic_make_request 1
#endif
#if CAN_WRAP_generic_make_request
    WRAP_FOR_DETACH(generic_make_request)
#endif
#ifndef CAN_WRAP_acpi_match_device
#   define CAN_WRAP_acpi_match_device 1
#endif
#if CAN_WRAP_acpi_match_device
    WRAP_FOR_DETACH(acpi_match_device)
#endif
#ifndef CAN_WRAP_end_buffer_write_sync
#   define CAN_WRAP_end_buffer_write_sync 1
#endif
#if CAN_WRAP_end_buffer_write_sync
    WRAP_FOR_DETACH(end_buffer_write_sync)
#endif
#ifndef CAN_WRAP_schedule_delayed_work
#   define CAN_WRAP_schedule_delayed_work 1
#endif
#if CAN_WRAP_schedule_delayed_work
    WRAP_FOR_DETACH(schedule_delayed_work)
#endif
#ifndef CAN_WRAP_ata_sff_hsm_move
#   define CAN_WRAP_ata_sff_hsm_move 1
#endif
#if CAN_WRAP_ata_sff_hsm_move
    WRAP_FOR_DETACH(ata_sff_hsm_move)
#endif
#ifndef CAN_WRAP_start_thread_ia32
#   define CAN_WRAP_start_thread_ia32 1
#endif
#if CAN_WRAP_start_thread_ia32
    WRAP_FOR_DETACH(start_thread_ia32)
#endif
#ifndef CAN_WRAP_bd_link_disk_holder
#   define CAN_WRAP_bd_link_disk_holder 1
#endif
#if CAN_WRAP_bd_link_disk_holder
    WRAP_FOR_DETACH(bd_link_disk_holder)
#endif
#ifndef CAN_WRAP_kmem_cache_shrink
#   define CAN_WRAP_kmem_cache_shrink 1
#endif
#if CAN_WRAP_kmem_cache_shrink
    WRAP_FOR_DETACH(kmem_cache_shrink)
#endif
#ifndef CAN_WRAP_security_inode_create
#   define CAN_WRAP_security_inode_create 1
#endif
#if CAN_WRAP_security_inode_create
    WRAP_FOR_DETACH(security_inode_create)
#endif
#ifndef CAN_WRAP___hrtimer_start_range_ns
#   define CAN_WRAP___hrtimer_start_range_ns 1
#endif
#if CAN_WRAP___hrtimer_start_range_ns
#   ifdef DETACH_ADDR___hrtimer_start_range_ns
        WRAP_FOR_DETACH(__hrtimer_start_range_ns)
#   else
        TYPED_DETACH(__hrtimer_start_range_ns)
#   endif
#endif
#ifndef CAN_WRAP___module_address
#   define CAN_WRAP___module_address 1
#endif
#if CAN_WRAP___module_address
#   ifdef DETACH_ADDR___module_address
        WRAP_FOR_DETACH(__module_address)
#   else
        TYPED_DETACH(__module_address)
#   endif
#endif
#ifndef CAN_WRAP_bio_alloc_bioset
#   define CAN_WRAP_bio_alloc_bioset 1
#endif
#if CAN_WRAP_bio_alloc_bioset
    WRAP_FOR_DETACH(bio_alloc_bioset)
#endif
#ifndef CAN_WRAP_iov_shorten
#   define CAN_WRAP_iov_shorten 1
#endif
#if CAN_WRAP_iov_shorten
    WRAP_FOR_DETACH(iov_shorten)
#endif
#ifndef CAN_WRAP_jbd2_journal_switch_revoke_table
#   define CAN_WRAP_jbd2_journal_switch_revoke_table 1
#endif
#if CAN_WRAP_jbd2_journal_switch_revoke_table
    WRAP_FOR_DETACH(jbd2_journal_switch_revoke_table)
#endif
#ifndef CAN_WRAP_bio_copy_user
#   define CAN_WRAP_bio_copy_user 1
#endif
#if CAN_WRAP_bio_copy_user
    WRAP_FOR_DETACH(bio_copy_user)
#endif
#ifndef CAN_WRAP_sysfs_remove_dir
#   define CAN_WRAP_sysfs_remove_dir 1
#endif
#if CAN_WRAP_sysfs_remove_dir
    WRAP_FOR_DETACH(sysfs_remove_dir)
#endif
#ifndef CAN_WRAP_security_inode_setsecurity
#   define CAN_WRAP_security_inode_setsecurity 1
#endif
#if CAN_WRAP_security_inode_setsecurity
    WRAP_FOR_DETACH(security_inode_setsecurity)
#endif
#ifndef CAN_WRAP_vfs_link
#   define CAN_WRAP_vfs_link 1
#endif
#if CAN_WRAP_vfs_link
    WRAP_FOR_DETACH(vfs_link)
#endif
#ifndef CAN_WRAP_pci_user_write_config_byte
#   define CAN_WRAP_pci_user_write_config_byte 1
#endif
#if CAN_WRAP_pci_user_write_config_byte
    WRAP_FOR_DETACH(pci_user_write_config_byte)
#endif
#ifndef CAN_WRAP_unregister_cpu_under_node
#   define CAN_WRAP_unregister_cpu_under_node 0
#endif
DETACH(unregister_cpu_under_node)
#ifndef CAN_WRAP_tick_oneshot_mode_active
#   define CAN_WRAP_tick_oneshot_mode_active 0
#endif
DETACH(tick_oneshot_mode_active)
#ifndef CAN_WRAP_jiffies_to_msecs
#   define CAN_WRAP_jiffies_to_msecs 0
#endif
DETACH(jiffies_to_msecs)
#ifndef CAN_WRAP_sata_link_scr_lpm
#   define CAN_WRAP_sata_link_scr_lpm 1
#endif
#if CAN_WRAP_sata_link_scr_lpm
    WRAP_FOR_DETACH(sata_link_scr_lpm)
#endif
#ifndef CAN_WRAP_copy_vma
#   define CAN_WRAP_copy_vma 1
#endif
#if CAN_WRAP_copy_vma
    WRAP_FOR_DETACH(copy_vma)
#endif
#ifndef CAN_WRAP_pci_iomap
#   define CAN_WRAP_pci_iomap 1
#endif
#if CAN_WRAP_pci_iomap
    WRAP_FOR_DETACH(pci_iomap)
#endif
#ifndef CAN_WRAP_truncate_pagecache_range
#   define CAN_WRAP_truncate_pagecache_range 1
#endif
#if CAN_WRAP_truncate_pagecache_range
    WRAP_FOR_DETACH(truncate_pagecache_range)
#endif
#ifndef CAN_WRAP_timeval_to_jiffies
#   define CAN_WRAP_timeval_to_jiffies 1
#endif
#if CAN_WRAP_timeval_to_jiffies
    WRAP_FOR_DETACH(timeval_to_jiffies)
#endif
#ifndef CAN_WRAP_cred_init
#   define CAN_WRAP_cred_init 0
#endif
DETACH(cred_init)
#ifndef CAN_WRAP_dev_forward_skb
#   define CAN_WRAP_dev_forward_skb 1
#endif
#if CAN_WRAP_dev_forward_skb
    WRAP_FOR_DETACH(dev_forward_skb)
#endif
#ifndef CAN_WRAP_safe_xapic_wait_icr_idle
#   define CAN_WRAP_safe_xapic_wait_icr_idle 0
#endif
DETACH(safe_xapic_wait_icr_idle)
#ifndef CAN_WRAP_neigh_direct_output
#   define CAN_WRAP_neigh_direct_output 1
#endif
#if CAN_WRAP_neigh_direct_output
    WRAP_FOR_DETACH(neigh_direct_output)
#endif
#ifndef CAN_WRAP_crypto_alloc_base
#   define CAN_WRAP_crypto_alloc_base 1
#endif
#if CAN_WRAP_crypto_alloc_base
    WRAP_FOR_DETACH(crypto_alloc_base)
#endif
#ifndef CAN_WRAP_wait_for_completion_timeout
#   define CAN_WRAP_wait_for_completion_timeout 1
#endif
#if CAN_WRAP_wait_for_completion_timeout
    WRAP_FOR_DETACH(wait_for_completion_timeout)
#endif
#ifndef CAN_WRAP_scsi_calculate_bounce_limit
#   define CAN_WRAP_scsi_calculate_bounce_limit 1
#endif
#if CAN_WRAP_scsi_calculate_bounce_limit
    WRAP_FOR_DETACH(scsi_calculate_bounce_limit)
#endif
#ifndef CAN_WRAP_si_swapinfo
#   define CAN_WRAP_si_swapinfo 1
#endif
#if CAN_WRAP_si_swapinfo
    WRAP_FOR_DETACH(si_swapinfo)
#endif
#ifndef CAN_WRAP___jbd2_journal_drop_transaction
#   define CAN_WRAP___jbd2_journal_drop_transaction 1
#endif
#if CAN_WRAP___jbd2_journal_drop_transaction
#   ifdef DETACH_ADDR___jbd2_journal_drop_transaction
        WRAP_FOR_DETACH(__jbd2_journal_drop_transaction)
#   else
        TYPED_DETACH(__jbd2_journal_drop_transaction)
#   endif
#endif
#ifndef CAN_WRAP_pci_disable_ltr
#   define CAN_WRAP_pci_disable_ltr 1
#endif
#if CAN_WRAP_pci_disable_ltr
    WRAP_FOR_DETACH(pci_disable_ltr)
#endif
#ifndef CAN_WRAP_cap_task_fix_setuid
#   define CAN_WRAP_cap_task_fix_setuid 1
#endif
#if CAN_WRAP_cap_task_fix_setuid
    WRAP_FOR_DETACH(cap_task_fix_setuid)
#endif
#ifndef CAN_WRAP_jbd2_journal_init_jbd_inode
#   define CAN_WRAP_jbd2_journal_init_jbd_inode 1
#endif
#if CAN_WRAP_jbd2_journal_init_jbd_inode
    WRAP_FOR_DETACH(jbd2_journal_init_jbd_inode)
#endif
#ifndef CAN_WRAP_simple_strtoll
#   define CAN_WRAP_simple_strtoll 0
#endif
DETACH(simple_strtoll)
#ifndef CAN_WRAP_vm_insert_pfn
#   define CAN_WRAP_vm_insert_pfn 1
#endif
#if CAN_WRAP_vm_insert_pfn
    WRAP_FOR_DETACH(vm_insert_pfn)
#endif
#ifndef CAN_WRAP_blocking_notifier_chain_unregister
#   define CAN_WRAP_blocking_notifier_chain_unregister 1
#endif
#if CAN_WRAP_blocking_notifier_chain_unregister
    WRAP_FOR_DETACH(blocking_notifier_chain_unregister)
#endif
#ifndef CAN_WRAP_lru_add_drain_all
#   define CAN_WRAP_lru_add_drain_all 0
#endif
DETACH(lru_add_drain_all)
#ifndef CAN_WRAP_find_or_create_page
#   define CAN_WRAP_find_or_create_page 1
#endif
#if CAN_WRAP_find_or_create_page
    WRAP_FOR_DETACH(find_or_create_page)
#endif
#ifndef CAN_WRAP_replace_mount_options
#   define CAN_WRAP_replace_mount_options 1
#endif
#if CAN_WRAP_replace_mount_options
    WRAP_FOR_DETACH(replace_mount_options)
#endif
#ifndef CAN_WRAP_raw_notifier_call_chain
#   define CAN_WRAP_raw_notifier_call_chain 1
#endif
#if CAN_WRAP_raw_notifier_call_chain
    WRAP_FOR_DETACH(raw_notifier_call_chain)
#endif
#ifndef CAN_WRAP_full_name_hash
#   define CAN_WRAP_full_name_hash 0
#endif
DETACH(full_name_hash)
#ifndef CAN_WRAP_security_req_classify_flow
#   define CAN_WRAP_security_req_classify_flow 1
#endif
#if CAN_WRAP_security_req_classify_flow
    WRAP_FOR_DETACH(security_req_classify_flow)
#endif
#ifndef CAN_WRAP_compat_sys_msgrcv
#   define CAN_WRAP_compat_sys_msgrcv 0
#endif
DETACH(compat_sys_msgrcv)
#ifndef CAN_WRAP_seq_release_net
#   define CAN_WRAP_seq_release_net 1
#endif
#if CAN_WRAP_seq_release_net
    WRAP_FOR_DETACH(seq_release_net)
#endif
#ifndef CAN_WRAP_bio_sector_offset
#   define CAN_WRAP_bio_sector_offset 1
#endif
#if CAN_WRAP_bio_sector_offset
    WRAP_FOR_DETACH(bio_sector_offset)
#endif
#ifndef CAN_WRAP_unregister_netdev
#   define CAN_WRAP_unregister_netdev 1
#endif
#if CAN_WRAP_unregister_netdev
    WRAP_FOR_DETACH(unregister_netdev)
#endif
#ifndef CAN_WRAP_ata_sff_interrupt
#   define CAN_WRAP_ata_sff_interrupt 0
#endif
DETACH(ata_sff_interrupt)
#ifndef CAN_WRAP_seq_bitmap
#   define CAN_WRAP_seq_bitmap 1
#endif
#if CAN_WRAP_seq_bitmap
    WRAP_FOR_DETACH(seq_bitmap)
#endif
#ifndef CAN_WRAP_irq_set_msi_desc
#   define CAN_WRAP_irq_set_msi_desc 1
#endif
#if CAN_WRAP_irq_set_msi_desc
    WRAP_FOR_DETACH(irq_set_msi_desc)
#endif
#ifndef CAN_WRAP_ata_noop_qc_prep
#   define CAN_WRAP_ata_noop_qc_prep 1
#endif
#if CAN_WRAP_ata_noop_qc_prep
    WRAP_FOR_DETACH(ata_noop_qc_prep)
#endif
#ifndef CAN_WRAP_dm_wait_event
#   define CAN_WRAP_dm_wait_event 1
#endif
#if CAN_WRAP_dm_wait_event
    WRAP_FOR_DETACH(dm_wait_event)
#endif
#ifndef CAN_WRAP_in_gate_area
#   define CAN_WRAP_in_gate_area 1
#endif
#if CAN_WRAP_in_gate_area
    WRAP_FOR_DETACH(in_gate_area)
#endif
#ifndef CAN_WRAP_textsearch_register
#   define CAN_WRAP_textsearch_register 1
#endif
#if CAN_WRAP_textsearch_register
    WRAP_FOR_DETACH(textsearch_register)
#endif
#ifndef CAN_WRAP_cgroup_attach_task_all
#   define CAN_WRAP_cgroup_attach_task_all 1
#endif
#if CAN_WRAP_cgroup_attach_task_all
    WRAP_FOR_DETACH(cgroup_attach_task_all)
#endif
#ifndef CAN_WRAP_driver_attach
#   define CAN_WRAP_driver_attach 1
#endif
#if CAN_WRAP_driver_attach
    WRAP_FOR_DETACH(driver_attach)
#endif
#ifndef CAN_WRAP_pm_generic_poweroff_noirq
#   define CAN_WRAP_pm_generic_poweroff_noirq 1
#endif
#if CAN_WRAP_pm_generic_poweroff_noirq
    WRAP_FOR_DETACH(pm_generic_poweroff_noirq)
#endif
#ifndef CAN_WRAP_our_mnt
#   define CAN_WRAP_our_mnt 1
#endif
#if CAN_WRAP_our_mnt
    WRAP_FOR_DETACH(our_mnt)
#endif
#ifndef CAN_WRAP_wait_rcu_gp
#   define CAN_WRAP_wait_rcu_gp 0
#endif
DETACH(wait_rcu_gp)
#ifndef CAN_WRAP_device_wakeup_enable
#   define CAN_WRAP_device_wakeup_enable 1
#endif
#if CAN_WRAP_device_wakeup_enable
    WRAP_FOR_DETACH(device_wakeup_enable)
#endif
#ifndef CAN_WRAP_get_options
#   define CAN_WRAP_get_options 0
#endif
DETACH(get_options)
#ifndef CAN_WRAP_native_cpu_disable
#   define CAN_WRAP_native_cpu_disable 0
#endif
DETACH(native_cpu_disable)
#ifndef CAN_WRAP_phy_stop_interrupts
#   define CAN_WRAP_phy_stop_interrupts 1
#endif
#if CAN_WRAP_phy_stop_interrupts
    WRAP_FOR_DETACH(phy_stop_interrupts)
#endif
#ifndef CAN_WRAP_acpi_os_fixed_event_count
#   define CAN_WRAP_acpi_os_fixed_event_count 0
#endif
DETACH(acpi_os_fixed_event_count)
#ifndef CAN_WRAP_lookup_swap_cache
#   define CAN_WRAP_lookup_swap_cache 1
#endif
#if CAN_WRAP_lookup_swap_cache
    WRAP_FOR_DETACH(lookup_swap_cache)
#endif
#ifndef CAN_WRAP_block_is_partially_uptodate
#   define CAN_WRAP_block_is_partially_uptodate 1
#endif
#if CAN_WRAP_block_is_partially_uptodate
    WRAP_FOR_DETACH(block_is_partially_uptodate)
#endif
#ifndef CAN_WRAP_keyring_clear
#   define CAN_WRAP_keyring_clear 1
#endif
#if CAN_WRAP_keyring_clear
    WRAP_FOR_DETACH(keyring_clear)
#endif
#ifndef CAN_WRAP_hrtimer_interrupt
#   define CAN_WRAP_hrtimer_interrupt 1
#endif
#if CAN_WRAP_hrtimer_interrupt
    WRAP_FOR_DETACH(hrtimer_interrupt)
#endif
#ifndef CAN_WRAP_partition_sched_domains
#   define CAN_WRAP_partition_sched_domains 1
#endif
#if CAN_WRAP_partition_sched_domains
    WRAP_FOR_DETACH(partition_sched_domains)
#endif
#ifndef CAN_WRAP_jbd2_journal_file_inode
#   define CAN_WRAP_jbd2_journal_file_inode 1
#endif
#if CAN_WRAP_jbd2_journal_file_inode
    WRAP_FOR_DETACH(jbd2_journal_file_inode)
#endif
#ifndef CAN_WRAP_irq_set_affinity_hint
#   define CAN_WRAP_irq_set_affinity_hint 1
#endif
#if CAN_WRAP_irq_set_affinity_hint
    WRAP_FOR_DETACH(irq_set_affinity_hint)
#endif
#ifndef CAN_WRAP_vmemmap_verify
#   define CAN_WRAP_vmemmap_verify 1
#endif
#if CAN_WRAP_vmemmap_verify
    WRAP_FOR_DETACH(vmemmap_verify)
#endif
#ifndef CAN_WRAP___get_user_pages_fast
#   define CAN_WRAP___get_user_pages_fast 0
#endif
DETACH(__get_user_pages_fast)
#ifndef CAN_WRAP_acpi_bus_get_ejd
#   define CAN_WRAP_acpi_bus_get_ejd 0
#endif
DETACH(acpi_bus_get_ejd)
#ifndef CAN_WRAP_dev_set_allmulti
#   define CAN_WRAP_dev_set_allmulti 1
#endif
#if CAN_WRAP_dev_set_allmulti
    WRAP_FOR_DETACH(dev_set_allmulti)
#endif
#ifndef CAN_WRAP_show_swap_cache_info
#   define CAN_WRAP_show_swap_cache_info 0
#endif
DETACH(show_swap_cache_info)
#ifndef CAN_WRAP___bitmap_shift_right
#   define CAN_WRAP___bitmap_shift_right 0
#endif
DETACH(__bitmap_shift_right)
#ifndef CAN_WRAP_vma_interval_tree_insert_after
#   define CAN_WRAP_vma_interval_tree_insert_after 1
#endif
#if CAN_WRAP_vma_interval_tree_insert_after
    WRAP_FOR_DETACH(vma_interval_tree_insert_after)
#endif
#ifndef CAN_WRAP_acpi_video_dmi_promote_vendor
#   define CAN_WRAP_acpi_video_dmi_promote_vendor 0
#endif
DETACH(acpi_video_dmi_promote_vendor)
#ifndef CAN_WRAP_clear_inode
#   define CAN_WRAP_clear_inode 1
#endif
#if CAN_WRAP_clear_inode
    WRAP_FOR_DETACH(clear_inode)
#endif
#ifndef CAN_WRAP_security_unix_stream_connect
#   define CAN_WRAP_security_unix_stream_connect 1
#endif
#if CAN_WRAP_security_unix_stream_connect
    WRAP_FOR_DETACH(security_unix_stream_connect)
#endif
#ifndef CAN_WRAP_sysfs_chmod_file
#   define CAN_WRAP_sysfs_chmod_file 1
#endif
#if CAN_WRAP_sysfs_chmod_file
    WRAP_FOR_DETACH(sysfs_chmod_file)
#endif
#ifndef CAN_WRAP__paravirt_ident_32
#   define CAN_WRAP__paravirt_ident_32 0
#endif
DETACH(_paravirt_ident_32)
#ifndef CAN_WRAP_pci_bus_set_ops
#   define CAN_WRAP_pci_bus_set_ops 1
#endif
#if CAN_WRAP_pci_bus_set_ops
    WRAP_FOR_DETACH(pci_bus_set_ops)
#endif
#ifndef CAN_WRAP_read_persistent_clock
#   define CAN_WRAP_read_persistent_clock 1
#endif
#if CAN_WRAP_read_persistent_clock
    WRAP_FOR_DETACH(read_persistent_clock)
#endif
#ifndef CAN_WRAP_generic_file_aio_read
#   define CAN_WRAP_generic_file_aio_read 1
#endif
#if CAN_WRAP_generic_file_aio_read
    WRAP_FOR_DETACH(generic_file_aio_read)
#endif
#ifndef CAN_WRAP_compat_sys_semtimedop
#   define CAN_WRAP_compat_sys_semtimedop 1
#endif
#if CAN_WRAP_compat_sys_semtimedop
    WRAP_FOR_DETACH(compat_sys_semtimedop)
#endif
#ifndef CAN_WRAP_pcibios_config_init
#   define CAN_WRAP_pcibios_config_init 0
#endif
DETACH(pcibios_config_init)
#ifndef CAN_WRAP_netif_carrier_off
#   define CAN_WRAP_netif_carrier_off 1
#endif
#if CAN_WRAP_netif_carrier_off
    WRAP_FOR_DETACH(netif_carrier_off)
#endif
#ifndef CAN_WRAP_local_bh_enable_ip
#   define CAN_WRAP_local_bh_enable_ip 0
#endif
DETACH(local_bh_enable_ip)
#ifndef CAN_WRAP___neigh_create
#   define CAN_WRAP___neigh_create 1
#endif
#if CAN_WRAP___neigh_create
#   ifdef DETACH_ADDR___neigh_create
        WRAP_FOR_DETACH(__neigh_create)
#   else
        TYPED_DETACH(__neigh_create)
#   endif
#endif
#ifndef CAN_WRAP_pm_generic_complete
#   define CAN_WRAP_pm_generic_complete 1
#endif
#if CAN_WRAP_pm_generic_complete
    WRAP_FOR_DETACH(pm_generic_complete)
#endif
#ifndef CAN_WRAP___jbd2_update_log_tail
#   define CAN_WRAP___jbd2_update_log_tail 1
#endif
#if CAN_WRAP___jbd2_update_log_tail
#   ifdef DETACH_ADDR___jbd2_update_log_tail
        WRAP_FOR_DETACH(__jbd2_update_log_tail)
#   else
        TYPED_DETACH(__jbd2_update_log_tail)
#   endif
#endif
#ifndef CAN_WRAP_pci_read_vpd
#   define CAN_WRAP_pci_read_vpd 1
#endif
#if CAN_WRAP_pci_read_vpd
    WRAP_FOR_DETACH(pci_read_vpd)
#endif
#ifndef CAN_WRAP_update_pm_runtime_accounting
#   define CAN_WRAP_update_pm_runtime_accounting 1
#endif
#if CAN_WRAP_update_pm_runtime_accounting
    WRAP_FOR_DETACH(update_pm_runtime_accounting)
#endif
#ifndef CAN_WRAP_input_event
#   define CAN_WRAP_input_event 1
#endif
#if CAN_WRAP_input_event
    WRAP_FOR_DETACH(input_event)
#endif
#ifndef CAN_WRAP_alloc_uid
#   define CAN_WRAP_alloc_uid 1
#endif
#if CAN_WRAP_alloc_uid
    WRAP_FOR_DETACH(alloc_uid)
#endif
#ifndef CAN_WRAP_search_extable
#   define CAN_WRAP_search_extable 1
#endif
#if CAN_WRAP_search_extable
    WRAP_FOR_DETACH(search_extable)
#endif
#ifndef CAN_WRAP_irq_exit
#   define CAN_WRAP_irq_exit 0
#endif
DETACH(irq_exit)
#ifndef CAN_WRAP_compat_sys_gettimeofday
#   define CAN_WRAP_compat_sys_gettimeofday 1
#endif
#if CAN_WRAP_compat_sys_gettimeofday
    WRAP_FOR_DETACH(compat_sys_gettimeofday)
#endif
#ifndef CAN_WRAP_handle_irq
#   define CAN_WRAP_handle_irq 1
#endif
#if CAN_WRAP_handle_irq
    WRAP_FOR_DETACH(handle_irq)
#endif
#ifndef CAN_WRAP___register_sysctl_table
#   define CAN_WRAP___register_sysctl_table 1
#endif
#if CAN_WRAP___register_sysctl_table
#   ifdef DETACH_ADDR___register_sysctl_table
        WRAP_FOR_DETACH(__register_sysctl_table)
#   else
        TYPED_DETACH(__register_sysctl_table)
#   endif
#endif
#ifndef CAN_WRAP_acpi_map_pxm_to_node
#   define CAN_WRAP_acpi_map_pxm_to_node 0
#endif
DETACH(acpi_map_pxm_to_node)
#ifndef CAN_WRAP_clocks_calc_mult_shift
#   define CAN_WRAP_clocks_calc_mult_shift 0
#endif
DETACH(clocks_calc_mult_shift)
#ifndef CAN_WRAP_qdisc_tree_decrease_qlen
#   define CAN_WRAP_qdisc_tree_decrease_qlen 1
#endif
#if CAN_WRAP_qdisc_tree_decrease_qlen
    WRAP_FOR_DETACH(qdisc_tree_decrease_qlen)
#endif
#ifndef CAN_WRAP_drain_local_pages
#   define CAN_WRAP_drain_local_pages 0
#endif
DETACH(drain_local_pages)
#ifndef CAN_WRAP_acpi_reset
#   define CAN_WRAP_acpi_reset 0
#endif
DETACH(acpi_reset)
#ifndef CAN_WRAP_mem_cgroup_sockets_init
#   define CAN_WRAP_mem_cgroup_sockets_init 1
#endif
#if CAN_WRAP_mem_cgroup_sockets_init
    WRAP_FOR_DETACH(mem_cgroup_sockets_init)
#endif
#ifndef CAN_WRAP_fprop_local_init_single
#   define CAN_WRAP_fprop_local_init_single 1
#endif
#if CAN_WRAP_fprop_local_init_single
    WRAP_FOR_DETACH(fprop_local_init_single)
#endif
#ifndef CAN_WRAP_acpi_subsys_resume_early
#   define CAN_WRAP_acpi_subsys_resume_early 1
#endif
#if CAN_WRAP_acpi_subsys_resume_early
    WRAP_FOR_DETACH(acpi_subsys_resume_early)
#endif
#ifndef CAN_WRAP_oops_exit
#   define CAN_WRAP_oops_exit 0
#endif
DETACH(oops_exit)
#ifndef CAN_WRAP_page_evictable
#   define CAN_WRAP_page_evictable 1
#endif
#if CAN_WRAP_page_evictable
    WRAP_FOR_DETACH(page_evictable)
#endif
#ifndef CAN_WRAP_pci_bus_add_device
#   define CAN_WRAP_pci_bus_add_device 1
#endif
#if CAN_WRAP_pci_bus_add_device
    WRAP_FOR_DETACH(pci_bus_add_device)
#endif
#ifndef CAN_WRAP_blk_integrity_is_initialized
#   define CAN_WRAP_blk_integrity_is_initialized 1
#endif
#if CAN_WRAP_blk_integrity_is_initialized
    WRAP_FOR_DETACH(blk_integrity_is_initialized)
#endif
#ifndef CAN_WRAP_locks_release_private
#   define CAN_WRAP_locks_release_private 1
#endif
#if CAN_WRAP_locks_release_private
    WRAP_FOR_DETACH(locks_release_private)
#endif
#ifndef CAN_WRAP_regs_query_register_name
#   define CAN_WRAP_regs_query_register_name 0
#endif
DETACH(regs_query_register_name)
#ifndef CAN_WRAP_device_attach
#   define CAN_WRAP_device_attach 1
#endif
#if CAN_WRAP_device_attach
    WRAP_FOR_DETACH(device_attach)
#endif
#ifndef CAN_WRAP_flush_signals
#   define CAN_WRAP_flush_signals 1
#endif
#if CAN_WRAP_flush_signals
    WRAP_FOR_DETACH(flush_signals)
#endif
#ifndef CAN_WRAP_dev_restart
#   define CAN_WRAP_dev_restart 1
#endif
#if CAN_WRAP_dev_restart
    WRAP_FOR_DETACH(dev_restart)
#endif
#ifndef CAN_WRAP_net_drop_ns
#   define CAN_WRAP_net_drop_ns 0
#endif
DETACH(net_drop_ns)
#ifndef CAN_WRAP___online_page_increment_counters
#   define CAN_WRAP___online_page_increment_counters 1
#endif
#if CAN_WRAP___online_page_increment_counters
#   ifdef DETACH_ADDR___online_page_increment_counters
        WRAP_FOR_DETACH(__online_page_increment_counters)
#   else
        TYPED_DETACH(__online_page_increment_counters)
#   endif
#endif
#ifndef CAN_WRAP_thaw_bdev
#   define CAN_WRAP_thaw_bdev 1
#endif
#if CAN_WRAP_thaw_bdev
    WRAP_FOR_DETACH(thaw_bdev)
#endif
#ifndef CAN_WRAP_usermodehelper_init
#   define CAN_WRAP_usermodehelper_init 0
#endif
DETACH(usermodehelper_init)
#ifndef CAN_WRAP___rtnl_link_register
#   define CAN_WRAP___rtnl_link_register 1
#endif
#if CAN_WRAP___rtnl_link_register
#   ifdef DETACH_ADDR___rtnl_link_register
        WRAP_FOR_DETACH(__rtnl_link_register)
#   else
        TYPED_DETACH(__rtnl_link_register)
#   endif
#endif
#ifndef CAN_WRAP___free_pages
#   define CAN_WRAP___free_pages 1
#endif
#if CAN_WRAP___free_pages
#   ifdef DETACH_ADDR___free_pages
        WRAP_FOR_DETACH(__free_pages)
#   else
        TYPED_DETACH(__free_pages)
#   endif
#endif
#ifndef CAN_WRAP_device_pm_wait_for_dev
#   define CAN_WRAP_device_pm_wait_for_dev 1
#endif
#if CAN_WRAP_device_pm_wait_for_dev
    WRAP_FOR_DETACH(device_pm_wait_for_dev)
#endif
#ifndef CAN_WRAP_map_vm_area
#   define CAN_WRAP_map_vm_area 1
#endif
#if CAN_WRAP_map_vm_area
    WRAP_FOR_DETACH(map_vm_area)
#endif
#ifndef CAN_WRAP_mempool_destroy
#   define CAN_WRAP_mempool_destroy 1
#endif
#if CAN_WRAP_mempool_destroy
    WRAP_FOR_DETACH(mempool_destroy)
#endif
#ifndef CAN_WRAP_find_lock_page
#   define CAN_WRAP_find_lock_page 1
#endif
#if CAN_WRAP_find_lock_page
    WRAP_FOR_DETACH(find_lock_page)
#endif
#ifndef CAN_WRAP_pci_stop_root_bus
#   define CAN_WRAP_pci_stop_root_bus 1
#endif
#if CAN_WRAP_pci_stop_root_bus
    WRAP_FOR_DETACH(pci_stop_root_bus)
#endif
#ifndef CAN_WRAP_e820_end_of_ram_pfn
#   define CAN_WRAP_e820_end_of_ram_pfn 0
#endif
DETACH(e820_end_of_ram_pfn)
#ifndef CAN_WRAP_probe_irq_off
#   define CAN_WRAP_probe_irq_off 0
#endif
DETACH(probe_irq_off)
#ifndef CAN_WRAP___getblk
#   define CAN_WRAP___getblk 1
#endif
#if CAN_WRAP___getblk
#   ifdef DETACH_ADDR___getblk
        WRAP_FOR_DETACH(__getblk)
#   else
        TYPED_DETACH(__getblk)
#   endif
#endif
#ifndef CAN_WRAP_vlan_vid_add
#   define CAN_WRAP_vlan_vid_add 1
#endif
#if CAN_WRAP_vlan_vid_add
    WRAP_FOR_DETACH(vlan_vid_add)
#endif
#ifndef CAN_WRAP_rcu_barrier
#   define CAN_WRAP_rcu_barrier 0
#endif
DETACH(rcu_barrier)
#ifndef CAN_WRAP_security_file_mprotect
#   define CAN_WRAP_security_file_mprotect 1
#endif
#if CAN_WRAP_security_file_mprotect
    WRAP_FOR_DETACH(security_file_mprotect)
#endif
#ifndef CAN_WRAP_kstrtoll
#   define CAN_WRAP_kstrtoll 0
#endif
DETACH(kstrtoll)
#ifndef CAN_WRAP_default_file_splice_read
#   define CAN_WRAP_default_file_splice_read 1
#endif
#if CAN_WRAP_default_file_splice_read
    WRAP_FOR_DETACH(default_file_splice_read)
#endif
#ifndef CAN_WRAP_vmalloc_init
#   define CAN_WRAP_vmalloc_init 0
#endif
DETACH(vmalloc_init)
#ifndef CAN_WRAP_param_get_short
#   define CAN_WRAP_param_get_short 1
#endif
#if CAN_WRAP_param_get_short
    WRAP_FOR_DETACH(param_get_short)
#endif
#ifndef CAN_WRAP_nf_hook_slow
#   define CAN_WRAP_nf_hook_slow 1
#endif
#if CAN_WRAP_nf_hook_slow
    WRAP_FOR_DETACH(nf_hook_slow)
#endif
#ifndef CAN_WRAP_compat_sys_futimesat
#   define CAN_WRAP_compat_sys_futimesat 1
#endif
#if CAN_WRAP_compat_sys_futimesat
    WRAP_FOR_DETACH(compat_sys_futimesat)
#endif
#ifndef CAN_WRAP_set_current_groups
#   define CAN_WRAP_set_current_groups 1
#endif
#if CAN_WRAP_set_current_groups
    WRAP_FOR_DETACH(set_current_groups)
#endif
#ifndef CAN_WRAP_radix_tree_locate_item
#   define CAN_WRAP_radix_tree_locate_item 1
#endif
#if CAN_WRAP_radix_tree_locate_item
    WRAP_FOR_DETACH(radix_tree_locate_item)
#endif
#ifndef CAN_WRAP_subtract_range
#   define CAN_WRAP_subtract_range 1
#endif
#if CAN_WRAP_subtract_range
    WRAP_FOR_DETACH(subtract_range)
#endif
#ifndef CAN_WRAP_dev_pm_qos_read_value
#   define CAN_WRAP_dev_pm_qos_read_value 1
#endif
#if CAN_WRAP_dev_pm_qos_read_value
    WRAP_FOR_DETACH(dev_pm_qos_read_value)
#endif
#ifndef CAN_WRAP_skb_checksum_help
#   define CAN_WRAP_skb_checksum_help 1
#endif
#if CAN_WRAP_skb_checksum_help
    WRAP_FOR_DETACH(skb_checksum_help)
#endif
#ifndef CAN_WRAP_ptep_clear_flush_young
#   define CAN_WRAP_ptep_clear_flush_young 1
#endif
#if CAN_WRAP_ptep_clear_flush_young
    WRAP_FOR_DETACH(ptep_clear_flush_young)
#endif
#ifndef CAN_WRAP_put_device
#   define CAN_WRAP_put_device 1
#endif
#if CAN_WRAP_put_device
    WRAP_FOR_DETACH(put_device)
#endif
#ifndef CAN_WRAP_clocksource_touch_watchdog
#   define CAN_WRAP_clocksource_touch_watchdog 0
#endif
DETACH(clocksource_touch_watchdog)
#ifndef CAN_WRAP_ida_get_new_above
#   define CAN_WRAP_ida_get_new_above 1
#endif
#if CAN_WRAP_ida_get_new_above
    WRAP_FOR_DETACH(ida_get_new_above)
#endif
#ifndef CAN_WRAP_set_cpu_online
#   define CAN_WRAP_set_cpu_online 0
#endif
DETACH(set_cpu_online)
#ifndef CAN_WRAP_compat_sys_openat
#   define CAN_WRAP_compat_sys_openat 0
#endif
DETACH(compat_sys_openat)
#ifndef CAN_WRAP_yama_ptrace_access_check
#   define CAN_WRAP_yama_ptrace_access_check 1
#endif
#if CAN_WRAP_yama_ptrace_access_check
    WRAP_FOR_DETACH(yama_ptrace_access_check)
#endif
#ifndef CAN_WRAP_cgroup_load_subsys
#   define CAN_WRAP_cgroup_load_subsys 1
#endif
#if CAN_WRAP_cgroup_load_subsys
    WRAP_FOR_DETACH(cgroup_load_subsys)
#endif
#ifndef CAN_WRAP_crypto_alloc_shash
#   define CAN_WRAP_crypto_alloc_shash 1
#endif
#if CAN_WRAP_crypto_alloc_shash
    WRAP_FOR_DETACH(crypto_alloc_shash)
#endif
#ifndef CAN_WRAP_ftrace_off_permanent
#   define CAN_WRAP_ftrace_off_permanent 0
#endif
DETACH(ftrace_off_permanent)
#ifndef CAN_WRAP_get_filesystem_list
#   define CAN_WRAP_get_filesystem_list 0
#endif
DETACH(get_filesystem_list)
#ifndef CAN_WRAP_ata_link_nr_enabled
#   define CAN_WRAP_ata_link_nr_enabled 1
#endif
#if CAN_WRAP_ata_link_nr_enabled
    WRAP_FOR_DETACH(ata_link_nr_enabled)
#endif
#ifndef CAN_WRAP___xchg_wrong_size
#   define CAN_WRAP___xchg_wrong_size 0
#endif
DETACH(__xchg_wrong_size)
#ifndef CAN_WRAP_prctl_get_seccomp
#   define CAN_WRAP_prctl_get_seccomp 0
#endif
DETACH(prctl_get_seccomp)
#ifndef CAN_WRAP___sock_create
#   define CAN_WRAP___sock_create 1
#endif
#if CAN_WRAP___sock_create
#   ifdef DETACH_ADDR___sock_create
        WRAP_FOR_DETACH(__sock_create)
#   else
        TYPED_DETACH(__sock_create)
#   endif
#endif
#ifndef CAN_WRAP_tsk_fork_get_node
#   define CAN_WRAP_tsk_fork_get_node 1
#endif
#if CAN_WRAP_tsk_fork_get_node
    WRAP_FOR_DETACH(tsk_fork_get_node)
#endif
#ifndef CAN_WRAP_bus_for_each_dev
#   define CAN_WRAP_bus_for_each_dev 1
#endif
#if CAN_WRAP_bus_for_each_dev
    WRAP_FOR_DETACH(bus_for_each_dev)
#endif
#ifndef CAN_WRAP_security_socket_create
#   define CAN_WRAP_security_socket_create 0
#endif
DETACH(security_socket_create)
#ifndef CAN_WRAP_simple_xattr_list
#   define CAN_WRAP_simple_xattr_list 1
#endif
#if CAN_WRAP_simple_xattr_list
    WRAP_FOR_DETACH(simple_xattr_list)
#endif
#ifndef CAN_WRAP_netdev_class_remove_file
#   define CAN_WRAP_netdev_class_remove_file 1
#endif
#if CAN_WRAP_netdev_class_remove_file
    WRAP_FOR_DETACH(netdev_class_remove_file)
#endif
#ifndef CAN_WRAP_lockup_detector_init
#   define CAN_WRAP_lockup_detector_init 0
#endif
DETACH(lockup_detector_init)
#ifndef CAN_WRAP___blocking_notifier_call_chain
#   define CAN_WRAP___blocking_notifier_call_chain 1
#endif
#if CAN_WRAP___blocking_notifier_call_chain
#   ifdef DETACH_ADDR___blocking_notifier_call_chain
        WRAP_FOR_DETACH(__blocking_notifier_call_chain)
#   else
        TYPED_DETACH(__blocking_notifier_call_chain)
#   endif
#endif
#ifndef CAN_WRAP_cancel_delayed_work
#   define CAN_WRAP_cancel_delayed_work 1
#endif
#if CAN_WRAP_cancel_delayed_work
    WRAP_FOR_DETACH(cancel_delayed_work)
#endif
#ifndef CAN_WRAP_acpi_dev_get_resources
#   define CAN_WRAP_acpi_dev_get_resources 1
#endif
#if CAN_WRAP_acpi_dev_get_resources
    WRAP_FOR_DETACH(acpi_dev_get_resources)
#endif
#ifndef CAN_WRAP___clocksource_updatefreq_scale
#   define CAN_WRAP___clocksource_updatefreq_scale 1
#endif
#if CAN_WRAP___clocksource_updatefreq_scale
#   ifdef DETACH_ADDR___clocksource_updatefreq_scale
        WRAP_FOR_DETACH(__clocksource_updatefreq_scale)
#   else
        TYPED_DETACH(__clocksource_updatefreq_scale)
#   endif
#endif
#ifndef CAN_WRAP_kobj_ns_netlink
#   define CAN_WRAP_kobj_ns_netlink 1
#endif
#if CAN_WRAP_kobj_ns_netlink
    WRAP_FOR_DETACH(kobj_ns_netlink)
#endif
#ifndef CAN_WRAP_pmd_clear_bad
#   define CAN_WRAP_pmd_clear_bad 1
#endif
#if CAN_WRAP_pmd_clear_bad
    WRAP_FOR_DETACH(pmd_clear_bad)
#endif
#ifndef CAN_WRAP_touch_all_softlockup_watchdogs
#   define CAN_WRAP_touch_all_softlockup_watchdogs 0
#endif
DETACH(touch_all_softlockup_watchdogs)
#ifndef CAN_WRAP_netdev_drivername
#   define CAN_WRAP_netdev_drivername 1
#endif
#if CAN_WRAP_netdev_drivername
    WRAP_FOR_DETACH(netdev_drivername)
#endif
#ifndef CAN_WRAP___class_create
#   define CAN_WRAP___class_create 1
#endif
#if CAN_WRAP___class_create
#   ifdef DETACH_ADDR___class_create
        WRAP_FOR_DETACH(__class_create)
#   else
        TYPED_DETACH(__class_create)
#   endif
#endif
#ifndef CAN_WRAP_sysfs_streq
#   define CAN_WRAP_sysfs_streq 0
#endif
DETACH(sysfs_streq)
#ifndef CAN_WRAP_compat_sys_recvmsg
#   define CAN_WRAP_compat_sys_recvmsg 1
#endif
#if CAN_WRAP_compat_sys_recvmsg
    WRAP_FOR_DETACH(compat_sys_recvmsg)
#endif
#ifndef CAN_WRAP_radix_tree_gang_lookup
#   define CAN_WRAP_radix_tree_gang_lookup 1
#endif
#if CAN_WRAP_radix_tree_gang_lookup
    WRAP_FOR_DETACH(radix_tree_gang_lookup)
#endif
#ifndef CAN_WRAP_balance_dirty_pages_ratelimited
#   define CAN_WRAP_balance_dirty_pages_ratelimited 1
#endif
#if CAN_WRAP_balance_dirty_pages_ratelimited
    WRAP_FOR_DETACH(balance_dirty_pages_ratelimited)
#endif
#ifndef CAN_WRAP_dev_disable_lro
#   define CAN_WRAP_dev_disable_lro 1
#endif
#if CAN_WRAP_dev_disable_lro
    WRAP_FOR_DETACH(dev_disable_lro)
#endif
#ifndef CAN_WRAP_fixup_early_ioremap
#   define CAN_WRAP_fixup_early_ioremap 0
#endif
DETACH(fixup_early_ioremap)
#ifndef CAN_WRAP_lru_cache_add_lru
#   define CAN_WRAP_lru_cache_add_lru 1
#endif
#if CAN_WRAP_lru_cache_add_lru
    WRAP_FOR_DETACH(lru_cache_add_lru)
#endif
#ifndef CAN_WRAP_crypto_alloc_ablkcipher
#   define CAN_WRAP_crypto_alloc_ablkcipher 1
#endif
#if CAN_WRAP_crypto_alloc_ablkcipher
    WRAP_FOR_DETACH(crypto_alloc_ablkcipher)
#endif
#ifndef CAN_WRAP_split_free_page
#   define CAN_WRAP_split_free_page 1
#endif
#if CAN_WRAP_split_free_page
    WRAP_FOR_DETACH(split_free_page)
#endif
#ifndef CAN_WRAP__set_memory_uc
#   define CAN_WRAP__set_memory_uc 0
#endif
DETACH(_set_memory_uc)
#ifndef CAN_WRAP___cleancache_get_page
#   define CAN_WRAP___cleancache_get_page 1
#endif
#if CAN_WRAP___cleancache_get_page
#   ifdef DETACH_ADDR___cleancache_get_page
        WRAP_FOR_DETACH(__cleancache_get_page)
#   else
        TYPED_DETACH(__cleancache_get_page)
#   endif
#endif
#ifndef CAN_WRAP___acpi_acquire_global_lock
#   define CAN_WRAP___acpi_acquire_global_lock 0
#endif
DETACH(__acpi_acquire_global_lock)
#ifndef CAN_WRAP_get_swap_page
#   define CAN_WRAP_get_swap_page 1
#endif
#if CAN_WRAP_get_swap_page
    WRAP_FOR_DETACH(get_swap_page)
#endif
#ifndef CAN_WRAP_sched_autogroup_detach
#   define CAN_WRAP_sched_autogroup_detach 1
#endif
#if CAN_WRAP_sched_autogroup_detach
    WRAP_FOR_DETACH(sched_autogroup_detach)
#endif
#ifndef CAN_WRAP___neigh_event_send
#   define CAN_WRAP___neigh_event_send 1
#endif
#if CAN_WRAP___neigh_event_send
#   ifdef DETACH_ADDR___neigh_event_send
        WRAP_FOR_DETACH(__neigh_event_send)
#   else
        TYPED_DETACH(__neigh_event_send)
#   endif
#endif
#ifndef CAN_WRAP_enable_percpu_irq
#   define CAN_WRAP_enable_percpu_irq 0
#endif
DETACH(enable_percpu_irq)
#ifndef CAN_WRAP_pci_scan_bus_with_sysdata
#   define CAN_WRAP_pci_scan_bus_with_sysdata 1
#endif
#if CAN_WRAP_pci_scan_bus_with_sysdata
    WRAP_FOR_DETACH(pci_scan_bus_with_sysdata)
#endif
#ifndef CAN_WRAP_pci_mmcfg_late_init
#   define CAN_WRAP_pci_mmcfg_late_init 0
#endif
DETACH(pci_mmcfg_late_init)
#ifndef CAN_WRAP_acpi_get_object_info
#   define CAN_WRAP_acpi_get_object_info 0
#endif
DETACH(acpi_get_object_info)
#ifndef CAN_WRAP_down_write
#   define CAN_WRAP_down_write 1
#endif
#if CAN_WRAP_down_write
    WRAP_FOR_DETACH(down_write)
#endif
#ifndef CAN_WRAP_find_min_pfn_with_active_regions
#   define CAN_WRAP_find_min_pfn_with_active_regions 0
#endif
DETACH(find_min_pfn_with_active_regions)
#ifndef CAN_WRAP_generate_random_uuid
#   define CAN_WRAP_generate_random_uuid 0
#endif
DETACH(generate_random_uuid)
#ifndef CAN_WRAP__raw_spin_lock_irq
#   define CAN_WRAP__raw_spin_lock_irq 1
#endif
#if CAN_WRAP__raw_spin_lock_irq
    WRAP_FOR_DETACH(_raw_spin_lock_irq)
#endif
#ifndef CAN_WRAP_devm_request_and_ioremap
#   define CAN_WRAP_devm_request_and_ioremap 1
#endif
#if CAN_WRAP_devm_request_and_ioremap
    WRAP_FOR_DETACH(devm_request_and_ioremap)
#endif
#ifndef CAN_WRAP_locks_init_lock
#   define CAN_WRAP_locks_init_lock 1
#endif
#if CAN_WRAP_locks_init_lock
    WRAP_FOR_DETACH(locks_init_lock)
#endif
#ifndef CAN_WRAP_numa_add_cpu
#   define CAN_WRAP_numa_add_cpu 0
#endif
DETACH(numa_add_cpu)
#ifndef CAN_WRAP_e820_end_of_low_ram_pfn
#   define CAN_WRAP_e820_end_of_low_ram_pfn 0
#endif
DETACH(e820_end_of_low_ram_pfn)
#ifndef CAN_WRAP_swiotlb_unmap_page
#   define CAN_WRAP_swiotlb_unmap_page 1
#endif
#if CAN_WRAP_swiotlb_unmap_page
    WRAP_FOR_DETACH(swiotlb_unmap_page)
#endif
#ifndef CAN_WRAP_kobject_set_name_vargs
#   define CAN_WRAP_kobject_set_name_vargs 1
#endif
#if CAN_WRAP_kobject_set_name_vargs
    WRAP_FOR_DETACH(kobject_set_name_vargs)
#endif
#ifndef CAN_WRAP_bdi_setup_and_register
#   define CAN_WRAP_bdi_setup_and_register 1
#endif
#if CAN_WRAP_bdi_setup_and_register
    WRAP_FOR_DETACH(bdi_setup_and_register)
#endif
#ifndef CAN_WRAP_acpi_initialize_subsystem
#   define CAN_WRAP_acpi_initialize_subsystem 0
#endif
DETACH(acpi_initialize_subsystem)
#ifndef CAN_WRAP___probe_kernel_write
#   define CAN_WRAP___probe_kernel_write 0
#endif
DETACH(__probe_kernel_write)
#ifndef CAN_WRAP_menu_hrtimer_cancel
#   define CAN_WRAP_menu_hrtimer_cancel 0
#endif
DETACH(menu_hrtimer_cancel)
#ifndef CAN_WRAP_compat_get_timespec
#   define CAN_WRAP_compat_get_timespec 1
#endif
#if CAN_WRAP_compat_get_timespec
    WRAP_FOR_DETACH(compat_get_timespec)
#endif
#ifndef CAN_WRAP_radix_tree_gang_lookup_slot
#   define CAN_WRAP_radix_tree_gang_lookup_slot 1
#endif
#if CAN_WRAP_radix_tree_gang_lookup_slot
    WRAP_FOR_DETACH(radix_tree_gang_lookup_slot)
#endif
#ifndef CAN_WRAP___dev_notify_flags
#   define CAN_WRAP___dev_notify_flags 1
#endif
#if CAN_WRAP___dev_notify_flags
#   ifdef DETACH_ADDR___dev_notify_flags
        WRAP_FOR_DETACH(__dev_notify_flags)
#   else
        TYPED_DETACH(__dev_notify_flags)
#   endif
#endif
#ifndef CAN_WRAP_io_delay_init
#   define CAN_WRAP_io_delay_init 0
#endif
DETACH(io_delay_init)
#ifndef CAN_WRAP_block_write_end
#   define CAN_WRAP_block_write_end 1
#endif
#if CAN_WRAP_block_write_end
    WRAP_FOR_DETACH(block_write_end)
#endif
#ifndef CAN_WRAP___kill_pgrp_info
#   define CAN_WRAP___kill_pgrp_info 1
#endif
#if CAN_WRAP___kill_pgrp_info
#   ifdef DETACH_ADDR___kill_pgrp_info
        WRAP_FOR_DETACH(__kill_pgrp_info)
#   else
        TYPED_DETACH(__kill_pgrp_info)
#   endif
#endif
#ifndef CAN_WRAP_paravirt_disable_iospace
#   define CAN_WRAP_paravirt_disable_iospace 0
#endif
DETACH(paravirt_disable_iospace)
#ifndef CAN_WRAP_vmemmap_populate_print_last
#   define CAN_WRAP_vmemmap_populate_print_last 0
#endif
DETACH(vmemmap_populate_print_last)
#ifndef CAN_WRAP_check_tsc_sync_target
#   define CAN_WRAP_check_tsc_sync_target 0
#endif
DETACH(check_tsc_sync_target)
#ifndef CAN_WRAP_dev_set_rx_mode
#   define CAN_WRAP_dev_set_rx_mode 1
#endif
#if CAN_WRAP_dev_set_rx_mode
    WRAP_FOR_DETACH(dev_set_rx_mode)
#endif
#ifndef CAN_WRAP_ata_sff_std_ports
#   define CAN_WRAP_ata_sff_std_ports 1
#endif
#if CAN_WRAP_ata_sff_std_ports
    WRAP_FOR_DETACH(ata_sff_std_ports)
#endif
#ifndef CAN_WRAP_set_create_files_as
#   define CAN_WRAP_set_create_files_as 1
#endif
#if CAN_WRAP_set_create_files_as
    WRAP_FOR_DETACH(set_create_files_as)
#endif
#ifndef CAN_WRAP_io_schedule
#   define CAN_WRAP_io_schedule 0
#endif
DETACH(io_schedule)
#ifndef CAN_WRAP_iput
#   define CAN_WRAP_iput 1
#endif
#if CAN_WRAP_iput
    WRAP_FOR_DETACH(iput)
#endif
#ifndef CAN_WRAP_netdev_notify_peers
#   define CAN_WRAP_netdev_notify_peers 1
#endif
#if CAN_WRAP_netdev_notify_peers
    WRAP_FOR_DETACH(netdev_notify_peers)
#endif
#ifndef CAN_WRAP_has_capability
#   define CAN_WRAP_has_capability 1
#endif
#if CAN_WRAP_has_capability
    WRAP_FOR_DETACH(has_capability)
#endif
#ifndef CAN_WRAP_irq_gc_mask_disable_reg_and_ack
#   define CAN_WRAP_irq_gc_mask_disable_reg_and_ack 1
#endif
#if CAN_WRAP_irq_gc_mask_disable_reg_and_ack
    WRAP_FOR_DETACH(irq_gc_mask_disable_reg_and_ack)
#endif
#ifndef CAN_WRAP_security_capable_noaudit
#   define CAN_WRAP_security_capable_noaudit 1
#endif
#if CAN_WRAP_security_capable_noaudit
    WRAP_FOR_DETACH(security_capable_noaudit)
#endif
#ifndef CAN_WRAP_ata_scsi_detect
#   define CAN_WRAP_ata_scsi_detect 1
#endif
#if CAN_WRAP_ata_scsi_detect
    WRAP_FOR_DETACH(ata_scsi_detect)
#endif
#ifndef CAN_WRAP_compat_sys_sendmmsg
#   define CAN_WRAP_compat_sys_sendmmsg 1
#endif
#if CAN_WRAP_compat_sys_sendmmsg
    WRAP_FOR_DETACH(compat_sys_sendmmsg)
#endif
#ifndef CAN_WRAP_generic_write_end
#   define CAN_WRAP_generic_write_end 1
#endif
#if CAN_WRAP_generic_write_end
    WRAP_FOR_DETACH(generic_write_end)
#endif
#ifndef CAN_WRAP_strlcat
#   define CAN_WRAP_strlcat 0
#endif
DETACH(strlcat)
#ifndef CAN_WRAP_param_set_ulong
#   define CAN_WRAP_param_set_ulong 1
#endif
#if CAN_WRAP_param_set_ulong
    WRAP_FOR_DETACH(param_set_ulong)
#endif
#ifndef CAN_WRAP_all_vm_events
#   define CAN_WRAP_all_vm_events 0
#endif
DETACH(all_vm_events)
#ifndef CAN_WRAP_request_key_with_auxdata
#   define CAN_WRAP_request_key_with_auxdata 1
#endif
#if CAN_WRAP_request_key_with_auxdata
    WRAP_FOR_DETACH(request_key_with_auxdata)
#endif
#ifndef CAN_WRAP_rcu_nmi_exit
#   define CAN_WRAP_rcu_nmi_exit 0
#endif
DETACH(rcu_nmi_exit)
#ifndef CAN_WRAP_pm_generic_freeze_late
#   define CAN_WRAP_pm_generic_freeze_late 1
#endif
#if CAN_WRAP_pm_generic_freeze_late
    WRAP_FOR_DETACH(pm_generic_freeze_late)
#endif
#ifndef CAN_WRAP_sock_get_timestampns
#   define CAN_WRAP_sock_get_timestampns 1
#endif
#if CAN_WRAP_sock_get_timestampns
    WRAP_FOR_DETACH(sock_get_timestampns)
#endif
#ifndef CAN_WRAP_ns_to_timeval
#   define CAN_WRAP_ns_to_timeval 1
#endif
#if CAN_WRAP_ns_to_timeval
    WRAP_FOR_DETACH(ns_to_timeval)
#endif
#ifndef CAN_WRAP_inet6_sk_rebuild_header
#   define CAN_WRAP_inet6_sk_rebuild_header 1
#endif
#if CAN_WRAP_inet6_sk_rebuild_header
    WRAP_FOR_DETACH(inet6_sk_rebuild_header)
#endif
#ifndef CAN_WRAP_wait_for_completion
#   define CAN_WRAP_wait_for_completion 1
#endif
#if CAN_WRAP_wait_for_completion
    WRAP_FOR_DETACH(wait_for_completion)
#endif
#ifndef CAN_WRAP_find_next_bit
#   define CAN_WRAP_find_next_bit 0
#endif
DETACH(find_next_bit)
#ifndef CAN_WRAP_acpi_unmap_lsapic
#   define CAN_WRAP_acpi_unmap_lsapic 0
#endif
DETACH(acpi_unmap_lsapic)
#ifndef CAN_WRAP_security_path_rename
#   define CAN_WRAP_security_path_rename 1
#endif
#if CAN_WRAP_security_path_rename
    WRAP_FOR_DETACH(security_path_rename)
#endif
#ifndef CAN_WRAP_sync_mapping_buffers
#   define CAN_WRAP_sync_mapping_buffers 1
#endif
#if CAN_WRAP_sync_mapping_buffers
    WRAP_FOR_DETACH(sync_mapping_buffers)
#endif
#ifndef CAN_WRAP_drain_zone_pages
#   define CAN_WRAP_drain_zone_pages 1
#endif
#if CAN_WRAP_drain_zone_pages
    WRAP_FOR_DETACH(drain_zone_pages)
#endif
#ifndef CAN_WRAP_pre_init_apic_IRQ0
#   define CAN_WRAP_pre_init_apic_IRQ0 0
#endif
DETACH(pre_init_apic_IRQ0)
#ifndef CAN_WRAP_fcntl_setlk
#   define CAN_WRAP_fcntl_setlk 1
#endif
#if CAN_WRAP_fcntl_setlk
    WRAP_FOR_DETACH(fcntl_setlk)
#endif
#ifndef CAN_WRAP_inode_has_buffers
#   define CAN_WRAP_inode_has_buffers 1
#endif
#if CAN_WRAP_inode_has_buffers
    WRAP_FOR_DETACH(inode_has_buffers)
#endif
#ifndef CAN_WRAP_set_all_modules_text_rw
#   define CAN_WRAP_set_all_modules_text_rw 0
#endif
DETACH(set_all_modules_text_rw)
#ifndef CAN_WRAP_blk_add_request_payload
#   define CAN_WRAP_blk_add_request_payload 1
#endif
#if CAN_WRAP_blk_add_request_payload
    WRAP_FOR_DETACH(blk_add_request_payload)
#endif
#ifndef CAN_WRAP_cgroup_post_fork
#   define CAN_WRAP_cgroup_post_fork 1
#endif
#if CAN_WRAP_cgroup_post_fork
    WRAP_FOR_DETACH(cgroup_post_fork)
#endif
#ifndef CAN_WRAP_sata_scr_write_flush
#   define CAN_WRAP_sata_scr_write_flush 1
#endif
#if CAN_WRAP_sata_scr_write_flush
    WRAP_FOR_DETACH(sata_scr_write_flush)
#endif
#ifndef CAN_WRAP_sg_copy_from_buffer
#   define CAN_WRAP_sg_copy_from_buffer 1
#endif
#if CAN_WRAP_sg_copy_from_buffer
    WRAP_FOR_DETACH(sg_copy_from_buffer)
#endif
#ifndef CAN_WRAP_set_all_modules_text_ro
#   define CAN_WRAP_set_all_modules_text_ro 0
#endif
DETACH(set_all_modules_text_ro)
#ifndef CAN_WRAP_dquot_quota_sync
#   define CAN_WRAP_dquot_quota_sync 1
#endif
#if CAN_WRAP_dquot_quota_sync
    WRAP_FOR_DETACH(dquot_quota_sync)
#endif
#ifndef CAN_WRAP_read_cache_page_gfp
#   define CAN_WRAP_read_cache_page_gfp 1
#endif
#if CAN_WRAP_read_cache_page_gfp
    WRAP_FOR_DETACH(read_cache_page_gfp)
#endif
#ifndef CAN_WRAP_allocate_resource
#   define CAN_WRAP_allocate_resource 1
#endif
#if CAN_WRAP_allocate_resource
    WRAP_FOR_DETACH(allocate_resource)
#endif
#ifndef CAN_WRAP_cgroup_iter_end
#   define CAN_WRAP_cgroup_iter_end 1
#endif
#if CAN_WRAP_cgroup_iter_end
    WRAP_FOR_DETACH(cgroup_iter_end)
#endif
#ifndef CAN_WRAP_swap_duplicate
#   define CAN_WRAP_swap_duplicate 1
#endif
#if CAN_WRAP_swap_duplicate
    WRAP_FOR_DETACH(swap_duplicate)
#endif
#ifndef CAN_WRAP_flush_itimer_signals
#   define CAN_WRAP_flush_itimer_signals 0
#endif
DETACH(flush_itimer_signals)
#ifndef CAN_WRAP_schedule_hrtimeout_range_clock
#   define CAN_WRAP_schedule_hrtimeout_range_clock 0
#endif
DETACH(schedule_hrtimeout_range_clock)
#ifndef CAN_WRAP_memcg_update_all_caches
#   define CAN_WRAP_memcg_update_all_caches 0
#endif
DETACH(memcg_update_all_caches)
#ifndef CAN_WRAP_setup_real_mode
#   define CAN_WRAP_setup_real_mode 0
#endif
DETACH(setup_real_mode)
#ifndef CAN_WRAP_timerqueue_del
#   define CAN_WRAP_timerqueue_del 1
#endif
#if CAN_WRAP_timerqueue_del
    WRAP_FOR_DETACH(timerqueue_del)
#endif
#ifndef CAN_WRAP_clocksource_mmio_readw_up
#   define CAN_WRAP_clocksource_mmio_readw_up 1
#endif
#if CAN_WRAP_clocksource_mmio_readw_up
    WRAP_FOR_DETACH(clocksource_mmio_readw_up)
#endif
#ifndef CAN_WRAP_sysfs_move_dir
#   define CAN_WRAP_sysfs_move_dir 1
#endif
#if CAN_WRAP_sysfs_move_dir
    WRAP_FOR_DETACH(sysfs_move_dir)
#endif
#ifndef CAN_WRAP_kset_create_and_add
#   define CAN_WRAP_kset_create_and_add 1
#endif
#if CAN_WRAP_kset_create_and_add
    WRAP_FOR_DETACH(kset_create_and_add)
#endif
#ifndef CAN_WRAP_deactivate_super
#   define CAN_WRAP_deactivate_super 1
#endif
#if CAN_WRAP_deactivate_super
    WRAP_FOR_DETACH(deactivate_super)
#endif
#ifndef CAN_WRAP_vfree
#   define CAN_WRAP_vfree 0
#endif
DETACH(vfree)
#ifndef CAN_WRAP_blk_rq_init
#   define CAN_WRAP_blk_rq_init 1
#endif
#if CAN_WRAP_blk_rq_init
    WRAP_FOR_DETACH(blk_rq_init)
#endif
#ifndef CAN_WRAP_bitmap_parselist
#   define CAN_WRAP_bitmap_parselist 0
#endif
DETACH(bitmap_parselist)
#ifndef CAN_WRAP_kstrtou8_from_user
#   define CAN_WRAP_kstrtou8_from_user 0
#endif
DETACH(kstrtou8_from_user)
#ifndef CAN_WRAP_security_socket_shutdown
#   define CAN_WRAP_security_socket_shutdown 1
#endif
#if CAN_WRAP_security_socket_shutdown
    WRAP_FOR_DETACH(security_socket_shutdown)
#endif
#ifndef CAN_WRAP_cdrom_mode_select
#   define CAN_WRAP_cdrom_mode_select 1
#endif
#if CAN_WRAP_cdrom_mode_select
    WRAP_FOR_DETACH(cdrom_mode_select)
#endif
#ifndef CAN_WRAP_strncat
#   define CAN_WRAP_strncat 0
#endif
DETACH(strncat)
#ifndef CAN_WRAP_skb_pull_rcsum
#   define CAN_WRAP_skb_pull_rcsum 1
#endif
#if CAN_WRAP_skb_pull_rcsum
    WRAP_FOR_DETACH(skb_pull_rcsum)
#endif
#ifndef CAN_WRAP_set_dumpable
#   define CAN_WRAP_set_dumpable 1
#endif
#if CAN_WRAP_set_dumpable
    WRAP_FOR_DETACH(set_dumpable)
#endif
#ifndef CAN_WRAP_ata_bmdma_status
#   define CAN_WRAP_ata_bmdma_status 1
#endif
#if CAN_WRAP_ata_bmdma_status
    WRAP_FOR_DETACH(ata_bmdma_status)
#endif
#ifndef CAN_WRAP_native_io_apic_modify
#   define CAN_WRAP_native_io_apic_modify 0
#endif
DETACH(native_io_apic_modify)
#ifndef CAN_WRAP_cgroup_next_descendant_post
#   define CAN_WRAP_cgroup_next_descendant_post 1
#endif
#if CAN_WRAP_cgroup_next_descendant_post
    WRAP_FOR_DETACH(cgroup_next_descendant_post)
#endif
#ifndef CAN_WRAP_ata_sff_postreset
#   define CAN_WRAP_ata_sff_postreset 1
#endif
#if CAN_WRAP_ata_sff_postreset
    WRAP_FOR_DETACH(ata_sff_postreset)
#endif
#ifndef CAN_WRAP_unmapped_area_topdown
#   define CAN_WRAP_unmapped_area_topdown 1
#endif
#if CAN_WRAP_unmapped_area_topdown
    WRAP_FOR_DETACH(unmapped_area_topdown)
#endif
#ifndef CAN_WRAP_strtobool
#   define CAN_WRAP_strtobool 0
#endif
DETACH(strtobool)
#ifndef CAN_WRAP_check_tsc_sync_source
#   define CAN_WRAP_check_tsc_sync_source 0
#endif
DETACH(check_tsc_sync_source)
#ifndef CAN_WRAP_cap_ptrace_access_check
#   define CAN_WRAP_cap_ptrace_access_check 1
#endif
#if CAN_WRAP_cap_ptrace_access_check
    WRAP_FOR_DETACH(cap_ptrace_access_check)
#endif
#ifndef CAN_WRAP_security_secmark_refcount_inc
#   define CAN_WRAP_security_secmark_refcount_inc 0
#endif
DETACH(security_secmark_refcount_inc)
#ifndef CAN_WRAP_task_handoff_unregister
#   define CAN_WRAP_task_handoff_unregister 1
#endif
#if CAN_WRAP_task_handoff_unregister
    WRAP_FOR_DETACH(task_handoff_unregister)
#endif
#ifndef CAN_WRAP_jiffies_64_to_clock_t
#   define CAN_WRAP_jiffies_64_to_clock_t 0
#endif
DETACH(jiffies_64_to_clock_t)
#ifndef CAN_WRAP___iowrite64_copy
#   define CAN_WRAP___iowrite64_copy 0
#endif
DETACH(__iowrite64_copy)
#ifndef CAN_WRAP_single_release_net
#   define CAN_WRAP_single_release_net 1
#endif
#if CAN_WRAP_single_release_net
    WRAP_FOR_DETACH(single_release_net)
#endif
#ifndef CAN_WRAP_pnp_activate_dev
#   define CAN_WRAP_pnp_activate_dev 1
#endif
#if CAN_WRAP_pnp_activate_dev
    WRAP_FOR_DETACH(pnp_activate_dev)
#endif
#ifndef CAN_WRAP_skb_push
#   define CAN_WRAP_skb_push 1
#endif
#if CAN_WRAP_skb_push
    WRAP_FOR_DETACH(skb_push)
#endif
#ifndef CAN_WRAP_posix_acl_from_mode
#   define CAN_WRAP_posix_acl_from_mode 1
#endif
#if CAN_WRAP_posix_acl_from_mode
    WRAP_FOR_DETACH(posix_acl_from_mode)
#endif
#ifndef CAN_WRAP_native_smp_cpus_done
#   define CAN_WRAP_native_smp_cpus_done 0
#endif
DETACH(native_smp_cpus_done)
#ifndef CAN_WRAP_irq_free_descs
#   define CAN_WRAP_irq_free_descs 0
#endif
DETACH(irq_free_descs)
#ifndef CAN_WRAP_tasklet_hrtimer_init
#   define CAN_WRAP_tasklet_hrtimer_init 1
#endif
#if CAN_WRAP_tasklet_hrtimer_init
    WRAP_FOR_DETACH(tasklet_hrtimer_init)
#endif
#ifndef CAN_WRAP_dst_alloc
#   define CAN_WRAP_dst_alloc 1
#endif
#if CAN_WRAP_dst_alloc
    WRAP_FOR_DETACH(dst_alloc)
#endif
#ifndef CAN_WRAP_pmdp_splitting_flush
#   define CAN_WRAP_pmdp_splitting_flush 1
#endif
#if CAN_WRAP_pmdp_splitting_flush
    WRAP_FOR_DETACH(pmdp_splitting_flush)
#endif
#ifndef CAN_WRAP_sk_page_frag_refill
#   define CAN_WRAP_sk_page_frag_refill 1
#endif
#if CAN_WRAP_sk_page_frag_refill
    WRAP_FOR_DETACH(sk_page_frag_refill)
#endif
#ifndef CAN_WRAP_security_kernel_module_from_file
#   define CAN_WRAP_security_kernel_module_from_file 1
#endif
#if CAN_WRAP_security_kernel_module_from_file
    WRAP_FOR_DETACH(security_kernel_module_from_file)
#endif
#ifndef CAN_WRAP_set_pages_x
#   define CAN_WRAP_set_pages_x 1
#endif
#if CAN_WRAP_set_pages_x
    WRAP_FOR_DETACH(set_pages_x)
#endif
#ifndef CAN_WRAP_arch_uprobe_pre_xol
#   define CAN_WRAP_arch_uprobe_pre_xol 1
#endif
#if CAN_WRAP_arch_uprobe_pre_xol
    WRAP_FOR_DETACH(arch_uprobe_pre_xol)
#endif
#ifndef CAN_WRAP_sched_show_task
#   define CAN_WRAP_sched_show_task 1
#endif
#if CAN_WRAP_sched_show_task
    WRAP_FOR_DETACH(sched_show_task)
#endif
#ifndef CAN_WRAP_d_validate
#   define CAN_WRAP_d_validate 1
#endif
#if CAN_WRAP_d_validate
    WRAP_FOR_DETACH(d_validate)
#endif
#ifndef CAN_WRAP_elv_merged_request
#   define CAN_WRAP_elv_merged_request 1
#endif
#if CAN_WRAP_elv_merged_request
    WRAP_FOR_DETACH(elv_merged_request)
#endif
#ifndef CAN_WRAP_copy_creds
#   define CAN_WRAP_copy_creds 1
#endif
#if CAN_WRAP_copy_creds
    WRAP_FOR_DETACH(copy_creds)
#endif
#ifndef CAN_WRAP_save_mount_options
#   define CAN_WRAP_save_mount_options 1
#endif
#if CAN_WRAP_save_mount_options
    WRAP_FOR_DETACH(save_mount_options)
#endif
#ifndef CAN_WRAP_security_inode_readlink
#   define CAN_WRAP_security_inode_readlink 1
#endif
#if CAN_WRAP_security_inode_readlink
    WRAP_FOR_DETACH(security_inode_readlink)
#endif
#ifndef CAN_WRAP_call_usermodehelper_fns
#   define CAN_WRAP_call_usermodehelper_fns 1
#endif
#if CAN_WRAP_call_usermodehelper_fns
    WRAP_FOR_DETACH(call_usermodehelper_fns)
#endif
#ifndef CAN_WRAP_memchr
#   define CAN_WRAP_memchr 0
#endif
DETACH(memchr)
#ifndef CAN_WRAP_get_filesystem
#   define CAN_WRAP_get_filesystem 1
#endif
#if CAN_WRAP_get_filesystem
    WRAP_FOR_DETACH(get_filesystem)
#endif
#ifndef CAN_WRAP_bio_integrity_free
#   define CAN_WRAP_bio_integrity_free 1
#endif
#if CAN_WRAP_bio_integrity_free
    WRAP_FOR_DETACH(bio_integrity_free)
#endif
#ifndef CAN_WRAP_copy_huge_pmd
#   define CAN_WRAP_copy_huge_pmd 1
#endif
#if CAN_WRAP_copy_huge_pmd
    WRAP_FOR_DETACH(copy_huge_pmd)
#endif
#ifndef CAN_WRAP__raw_write_lock_irq
#   define CAN_WRAP__raw_write_lock_irq 1
#endif
#if CAN_WRAP__raw_write_lock_irq
    WRAP_FOR_DETACH(_raw_write_lock_irq)
#endif
#ifndef CAN_WRAP_path_is_under
#   define CAN_WRAP_path_is_under 1
#endif
#if CAN_WRAP_path_is_under
    WRAP_FOR_DETACH(path_is_under)
#endif
#ifndef CAN_WRAP_d_find_alias
#   define CAN_WRAP_d_find_alias 1
#endif
#if CAN_WRAP_d_find_alias
    WRAP_FOR_DETACH(d_find_alias)
#endif
#ifndef CAN_WRAP_kobj_ns_grab_current
#   define CAN_WRAP_kobj_ns_grab_current 0
#endif
DETACH(kobj_ns_grab_current)
#ifndef CAN_WRAP_setup_IO_APIC_irq_extra
#   define CAN_WRAP_setup_IO_APIC_irq_extra 0
#endif
DETACH(setup_IO_APIC_irq_extra)
#ifndef CAN_WRAP_securityfs_create_file
#   define CAN_WRAP_securityfs_create_file 1
#endif
#if CAN_WRAP_securityfs_create_file
    WRAP_FOR_DETACH(securityfs_create_file)
#endif
#ifndef CAN_WRAP_security_vm_enough_memory_mm
#   define CAN_WRAP_security_vm_enough_memory_mm 1
#endif
#if CAN_WRAP_security_vm_enough_memory_mm
    WRAP_FOR_DETACH(security_vm_enough_memory_mm)
#endif
#ifndef CAN_WRAP_rcutorture_record_test_transition
#   define CAN_WRAP_rcutorture_record_test_transition 0
#endif
DETACH(rcutorture_record_test_transition)
#ifndef CAN_WRAP_ptep_set_access_flags
#   define CAN_WRAP_ptep_set_access_flags 1
#endif
#if CAN_WRAP_ptep_set_access_flags
    WRAP_FOR_DETACH(ptep_set_access_flags)
#endif
#ifndef CAN_WRAP_sk_stream_wait_connect
#   define CAN_WRAP_sk_stream_wait_connect 1
#endif
#if CAN_WRAP_sk_stream_wait_connect
    WRAP_FOR_DETACH(sk_stream_wait_connect)
#endif
#ifndef CAN_WRAP_pci_set_host_bridge_release
#   define CAN_WRAP_pci_set_host_bridge_release 1
#endif
#if CAN_WRAP_pci_set_host_bridge_release
    WRAP_FOR_DETACH(pci_set_host_bridge_release)
#endif
#ifndef CAN_WRAP_simple_readpage
#   define CAN_WRAP_simple_readpage 1
#endif
#if CAN_WRAP_simple_readpage
    WRAP_FOR_DETACH(simple_readpage)
#endif
#ifndef CAN_WRAP_acpi_parse_mcfg
#   define CAN_WRAP_acpi_parse_mcfg 1
#endif
#if CAN_WRAP_acpi_parse_mcfg
    WRAP_FOR_DETACH(acpi_parse_mcfg)
#endif
#ifndef CAN_WRAP_hrtimer_forward
#   define CAN_WRAP_hrtimer_forward 1
#endif
#if CAN_WRAP_hrtimer_forward
    WRAP_FOR_DETACH(hrtimer_forward)
#endif
#ifndef CAN_WRAP_compat_sys_old_readdir
#   define CAN_WRAP_compat_sys_old_readdir 1
#endif
#if CAN_WRAP_compat_sys_old_readdir
    WRAP_FOR_DETACH(compat_sys_old_readdir)
#endif
#ifndef CAN_WRAP_anon_vma_interval_tree_iter_next
#   define CAN_WRAP_anon_vma_interval_tree_iter_next 1
#endif
#if CAN_WRAP_anon_vma_interval_tree_iter_next
    WRAP_FOR_DETACH(anon_vma_interval_tree_iter_next)
#endif
#ifndef CAN_WRAP_reuse_swap_page
#   define CAN_WRAP_reuse_swap_page 1
#endif
#if CAN_WRAP_reuse_swap_page
    WRAP_FOR_DETACH(reuse_swap_page)
#endif
#ifndef CAN_WRAP_pvclock_set_flags
#   define CAN_WRAP_pvclock_set_flags 0
#endif
DETACH(pvclock_set_flags)
#ifndef CAN_WRAP_next_signal
#   define CAN_WRAP_next_signal 1
#endif
#if CAN_WRAP_next_signal
    WRAP_FOR_DETACH(next_signal)
#endif
#ifndef CAN_WRAP_blk_rq_unprep_clone
#   define CAN_WRAP_blk_rq_unprep_clone 1
#endif
#if CAN_WRAP_blk_rq_unprep_clone
    WRAP_FOR_DETACH(blk_rq_unprep_clone)
#endif
#ifndef CAN_WRAP_elv_put_request
#   define CAN_WRAP_elv_put_request 1
#endif
#if CAN_WRAP_elv_put_request
    WRAP_FOR_DETACH(elv_put_request)
#endif
#ifndef CAN_WRAP_align_vdso_addr
#   define CAN_WRAP_align_vdso_addr 0
#endif
DETACH(align_vdso_addr)
#ifndef CAN_WRAP_css_is_ancestor
#   define CAN_WRAP_css_is_ancestor 1
#endif
#if CAN_WRAP_css_is_ancestor
    WRAP_FOR_DETACH(css_is_ancestor)
#endif
#ifndef CAN_WRAP_cgroup_attach_task
#   define CAN_WRAP_cgroup_attach_task 1
#endif
#if CAN_WRAP_cgroup_attach_task
    WRAP_FOR_DETACH(cgroup_attach_task)
#endif
#ifndef CAN_WRAP_check_disk_size_change
#   define CAN_WRAP_check_disk_size_change 1
#endif
#if CAN_WRAP_check_disk_size_change
    WRAP_FOR_DETACH(check_disk_size_change)
#endif
#ifndef CAN_WRAP_acpi_os_acquire_lock
#   define CAN_WRAP_acpi_os_acquire_lock 1
#endif
#if CAN_WRAP_acpi_os_acquire_lock
    WRAP_FOR_DETACH(acpi_os_acquire_lock)
#endif
#ifndef CAN_WRAP___pm_relax
#   define CAN_WRAP___pm_relax 1
#endif
#if CAN_WRAP___pm_relax
#   ifdef DETACH_ADDR___pm_relax
        WRAP_FOR_DETACH(__pm_relax)
#   else
        TYPED_DETACH(__pm_relax)
#   endif
#endif
#ifndef CAN_WRAP_kernel_sendmsg
#   define CAN_WRAP_kernel_sendmsg 1
#endif
#if CAN_WRAP_kernel_sendmsg
    WRAP_FOR_DETACH(kernel_sendmsg)
#endif
#ifndef CAN_WRAP_klist_add_before
#   define CAN_WRAP_klist_add_before 1
#endif
#if CAN_WRAP_klist_add_before
    WRAP_FOR_DETACH(klist_add_before)
#endif
#ifndef CAN_WRAP_tick_check_idle
#   define CAN_WRAP_tick_check_idle 0
#endif
DETACH(tick_check_idle)
#ifndef CAN_WRAP_bd_set_size
#   define CAN_WRAP_bd_set_size 1
#endif
#if CAN_WRAP_bd_set_size
    WRAP_FOR_DETACH(bd_set_size)
#endif
#ifndef CAN_WRAP_do_notify_parent
#   define CAN_WRAP_do_notify_parent 1
#endif
#if CAN_WRAP_do_notify_parent
    WRAP_FOR_DETACH(do_notify_parent)
#endif
#ifndef CAN_WRAP_get_xtime_and_monotonic_and_sleep_offset
#   define CAN_WRAP_get_xtime_and_monotonic_and_sleep_offset 1
#endif
#if CAN_WRAP_get_xtime_and_monotonic_and_sleep_offset
    WRAP_FOR_DETACH(get_xtime_and_monotonic_and_sleep_offset)
#endif
#ifndef CAN_WRAP_skb_trim
#   define CAN_WRAP_skb_trim 1
#endif
#if CAN_WRAP_skb_trim
    WRAP_FOR_DETACH(skb_trim)
#endif
#ifndef CAN_WRAP__raw_write_lock_irqsave
#   define CAN_WRAP__raw_write_lock_irqsave 1
#endif
#if CAN_WRAP__raw_write_lock_irqsave
    WRAP_FOR_DETACH(_raw_write_lock_irqsave)
#endif
#ifndef CAN_WRAP___css_put
#   define CAN_WRAP___css_put 1
#endif
#if CAN_WRAP___css_put
#   ifdef DETACH_ADDR___css_put
        WRAP_FOR_DETACH(__css_put)
#   else
        TYPED_DETACH(__css_put)
#   endif
#endif
#ifndef CAN_WRAP___ndelay
#   define CAN_WRAP___ndelay 0
#endif
DETACH(__ndelay)
#ifndef CAN_WRAP_pci_find_next_ht_capability
#   define CAN_WRAP_pci_find_next_ht_capability 1
#endif
#if CAN_WRAP_pci_find_next_ht_capability
    WRAP_FOR_DETACH(pci_find_next_ht_capability)
#endif
#ifndef CAN_WRAP_timecounter_init
#   define CAN_WRAP_timecounter_init 1
#endif
#if CAN_WRAP_timecounter_init
    WRAP_FOR_DETACH(timecounter_init)
#endif
#ifndef CAN_WRAP_dst_discard
#   define CAN_WRAP_dst_discard 1
#endif
#if CAN_WRAP_dst_discard
    WRAP_FOR_DETACH(dst_discard)
#endif
#ifndef CAN_WRAP_cdrom_ioctl
#   define CAN_WRAP_cdrom_ioctl 1
#endif
#if CAN_WRAP_cdrom_ioctl
    WRAP_FOR_DETACH(cdrom_ioctl)
#endif
#ifndef CAN_WRAP_pcix_get_mmrbc
#   define CAN_WRAP_pcix_get_mmrbc 1
#endif
#if CAN_WRAP_pcix_get_mmrbc
    WRAP_FOR_DETACH(pcix_get_mmrbc)
#endif
#ifndef CAN_WRAP_proc_sys_poll_notify
#   define CAN_WRAP_proc_sys_poll_notify 1
#endif
#if CAN_WRAP_proc_sys_poll_notify
    WRAP_FOR_DETACH(proc_sys_poll_notify)
#endif
#ifndef CAN_WRAP__copy_to_user
#   define CAN_WRAP__copy_to_user 0
#endif
DETACH(_copy_to_user)
#ifndef CAN_WRAP_ata_host_suspend
#   define CAN_WRAP_ata_host_suspend 1
#endif
#if CAN_WRAP_ata_host_suspend
    WRAP_FOR_DETACH(ata_host_suspend)
#endif
#ifndef CAN_WRAP_seq_put_decimal_ull
#   define CAN_WRAP_seq_put_decimal_ull 1
#endif
#if CAN_WRAP_seq_put_decimal_ull
    WRAP_FOR_DETACH(seq_put_decimal_ull)
#endif
#ifndef CAN_WRAP_crypto_shash_setkey
#   define CAN_WRAP_crypto_shash_setkey 1
#endif
#if CAN_WRAP_crypto_shash_setkey
    WRAP_FOR_DETACH(crypto_shash_setkey)
#endif
#ifndef CAN_WRAP_free_pages_exact
#   define CAN_WRAP_free_pages_exact 0
#endif
DETACH(free_pages_exact)
#ifndef CAN_WRAP___phys_addr
#   define CAN_WRAP___phys_addr 0
#endif
DETACH(__phys_addr)
#ifndef CAN_WRAP___sk_dst_check
#   define CAN_WRAP___sk_dst_check 1
#endif
#if CAN_WRAP___sk_dst_check
#   ifdef DETACH_ADDR___sk_dst_check
        WRAP_FOR_DETACH(__sk_dst_check)
#   else
        TYPED_DETACH(__sk_dst_check)
#   endif
#endif
#ifndef CAN_WRAP_bio_integrity_clone
#   define CAN_WRAP_bio_integrity_clone 1
#endif
#if CAN_WRAP_bio_integrity_clone
    WRAP_FOR_DETACH(bio_integrity_clone)
#endif
#ifndef CAN_WRAP_phy_start_machine
#   define CAN_WRAP_phy_start_machine 1
#endif
#if CAN_WRAP_phy_start_machine
    WRAP_FOR_DETACH(phy_start_machine)
#endif
#ifndef CAN_WRAP_mark_buffer_dirty_inode
#   define CAN_WRAP_mark_buffer_dirty_inode 1
#endif
#if CAN_WRAP_mark_buffer_dirty_inode
    WRAP_FOR_DETACH(mark_buffer_dirty_inode)
#endif
#ifndef CAN_WRAP_strpbrk
#   define CAN_WRAP_strpbrk 0
#endif
DETACH(strpbrk)
#ifndef CAN_WRAP_curr_task
#   define CAN_WRAP_curr_task 1
#endif
#if CAN_WRAP_curr_task
    WRAP_FOR_DETACH(curr_task)
#endif
#ifndef CAN_WRAP_dma_async_device_unregister
#   define CAN_WRAP_dma_async_device_unregister 1
#endif
#if CAN_WRAP_dma_async_device_unregister
    WRAP_FOR_DETACH(dma_async_device_unregister)
#endif
#ifndef CAN_WRAP_skb_split
#   define CAN_WRAP_skb_split 1
#endif
#if CAN_WRAP_skb_split
    WRAP_FOR_DETACH(skb_split)
#endif
#ifndef CAN_WRAP_pcie_capability_read_dword
#   define CAN_WRAP_pcie_capability_read_dword 1
#endif
#if CAN_WRAP_pcie_capability_read_dword
    WRAP_FOR_DETACH(pcie_capability_read_dword)
#endif
#ifndef CAN_WRAP_numa_zonelist_order_handler
#   define CAN_WRAP_numa_zonelist_order_handler 1
#endif
#if CAN_WRAP_numa_zonelist_order_handler
    WRAP_FOR_DETACH(numa_zonelist_order_handler)
#endif
#ifndef CAN_WRAP_jbd2_journal_update_sb_errno
#   define CAN_WRAP_jbd2_journal_update_sb_errno 1
#endif
#if CAN_WRAP_jbd2_journal_update_sb_errno
    WRAP_FOR_DETACH(jbd2_journal_update_sb_errno)
#endif
#ifndef CAN_WRAP_bsp_end_local_APIC_setup
#   define CAN_WRAP_bsp_end_local_APIC_setup 0
#endif
DETACH(bsp_end_local_APIC_setup)
#ifndef CAN_WRAP_compat_sys_utimensat
#   define CAN_WRAP_compat_sys_utimensat 1
#endif
#if CAN_WRAP_compat_sys_utimensat
    WRAP_FOR_DETACH(compat_sys_utimensat)
#endif
#ifndef CAN_WRAP_compat_sys_sched_getaffinity
#   define CAN_WRAP_compat_sys_sched_getaffinity 0
#endif
DETACH(compat_sys_sched_getaffinity)
#ifndef CAN_WRAP_devtmpfs_delete_node
#   define CAN_WRAP_devtmpfs_delete_node 1
#endif
#if CAN_WRAP_devtmpfs_delete_node
    WRAP_FOR_DETACH(devtmpfs_delete_node)
#endif
#ifndef CAN_WRAP_paravirt_patch_ident_32
#   define CAN_WRAP_paravirt_patch_ident_32 0
#endif
DETACH(paravirt_patch_ident_32)
#ifndef CAN_WRAP_irq_get_irq_data
#   define CAN_WRAP_irq_get_irq_data 1
#endif
#if CAN_WRAP_irq_get_irq_data
    WRAP_FOR_DETACH(irq_get_irq_data)
#endif
#ifndef CAN_WRAP_acpi_power_resource_register_device
#   define CAN_WRAP_acpi_power_resource_register_device 1
#endif
#if CAN_WRAP_acpi_power_resource_register_device
    WRAP_FOR_DETACH(acpi_power_resource_register_device)
#endif
#ifndef CAN_WRAP__set_memory_wc
#   define CAN_WRAP__set_memory_wc 0
#endif
DETACH(_set_memory_wc)
#ifndef CAN_WRAP__set_memory_wb
#   define CAN_WRAP__set_memory_wb 0
#endif
DETACH(_set_memory_wb)
#ifndef CAN_WRAP_proc_root_init
#   define CAN_WRAP_proc_root_init 0
#endif
DETACH(proc_root_init)
#ifndef CAN_WRAP_freeze_workqueues_begin
#   define CAN_WRAP_freeze_workqueues_begin 0
#endif
DETACH(freeze_workqueues_begin)
#ifndef CAN_WRAP___cleancache_invalidate_page
#   define CAN_WRAP___cleancache_invalidate_page 1
#endif
#if CAN_WRAP___cleancache_invalidate_page
#   ifdef DETACH_ADDR___cleancache_invalidate_page
        WRAP_FOR_DETACH(__cleancache_invalidate_page)
#   else
        TYPED_DETACH(__cleancache_invalidate_page)
#   endif
#endif
#ifndef CAN_WRAP_security_path_chroot
#   define CAN_WRAP_security_path_chroot 1
#endif
#if CAN_WRAP_security_path_chroot
    WRAP_FOR_DETACH(security_path_chroot)
#endif
#ifndef CAN_WRAP_bio_set_pages_dirty
#   define CAN_WRAP_bio_set_pages_dirty 1
#endif
#if CAN_WRAP_bio_set_pages_dirty
    WRAP_FOR_DETACH(bio_set_pages_dirty)
#endif
#ifndef CAN_WRAP_security_shm_shmctl
#   define CAN_WRAP_security_shm_shmctl 1
#endif
#if CAN_WRAP_security_shm_shmctl
    WRAP_FOR_DETACH(security_shm_shmctl)
#endif
#ifndef CAN_WRAP_security_task_free
#   define CAN_WRAP_security_task_free 1
#endif
#if CAN_WRAP_security_task_free
    WRAP_FOR_DETACH(security_task_free)
#endif
#ifndef CAN_WRAP_sg_init_one
#   define CAN_WRAP_sg_init_one 1
#endif
#if CAN_WRAP_sg_init_one
    WRAP_FOR_DETACH(sg_init_one)
#endif
#ifndef CAN_WRAP_compat_sys_getrusage
#   define CAN_WRAP_compat_sys_getrusage 1
#endif
#if CAN_WRAP_compat_sys_getrusage
    WRAP_FOR_DETACH(compat_sys_getrusage)
#endif
#ifndef CAN_WRAP_swiotlb_alloc_coherent
#   define CAN_WRAP_swiotlb_alloc_coherent 1
#endif
#if CAN_WRAP_swiotlb_alloc_coherent
    WRAP_FOR_DETACH(swiotlb_alloc_coherent)
#endif
#ifndef CAN_WRAP_netif_rx
#   define CAN_WRAP_netif_rx 1
#endif
#if CAN_WRAP_netif_rx
    WRAP_FOR_DETACH(netif_rx)
#endif
#ifndef CAN_WRAP_may_expand_vm
#   define CAN_WRAP_may_expand_vm 1
#endif
#if CAN_WRAP_may_expand_vm
    WRAP_FOR_DETACH(may_expand_vm)
#endif
#ifndef CAN_WRAP_vm_area_add_early
#   define CAN_WRAP_vm_area_add_early 1
#endif
#if CAN_WRAP_vm_area_add_early
    WRAP_FOR_DETACH(vm_area_add_early)
#endif
#ifndef CAN_WRAP_vfs_fstatat
#   define CAN_WRAP_vfs_fstatat 1
#endif
#if CAN_WRAP_vfs_fstatat
    WRAP_FOR_DETACH(vfs_fstatat)
#endif
#ifndef CAN_WRAP_swiotlb_tbl_map_single
#   define CAN_WRAP_swiotlb_tbl_map_single 1
#endif
#if CAN_WRAP_swiotlb_tbl_map_single
    WRAP_FOR_DETACH(swiotlb_tbl_map_single)
#endif
#ifndef CAN_WRAP_pm_qos_request_active
#   define CAN_WRAP_pm_qos_request_active 1
#endif
#if CAN_WRAP_pm_qos_request_active
    WRAP_FOR_DETACH(pm_qos_request_active)
#endif
#ifndef CAN_WRAP_netif_napi_del
#   define CAN_WRAP_netif_napi_del 1
#endif
#if CAN_WRAP_netif_napi_del
    WRAP_FOR_DETACH(netif_napi_del)
#endif
#ifndef CAN_WRAP_generic_file_splice_read
#   define CAN_WRAP_generic_file_splice_read 1
#endif
#if CAN_WRAP_generic_file_splice_read
    WRAP_FOR_DETACH(generic_file_splice_read)
#endif
#ifndef CAN_WRAP_neigh_update
#   define CAN_WRAP_neigh_update 1
#endif
#if CAN_WRAP_neigh_update
    WRAP_FOR_DETACH(neigh_update)
#endif
#ifndef CAN_WRAP_func_ptr_is_kernel_text
#   define CAN_WRAP_func_ptr_is_kernel_text 0
#endif
DETACH(func_ptr_is_kernel_text)
#ifndef CAN_WRAP_flush_kthread_work
#   define CAN_WRAP_flush_kthread_work 1
#endif
#if CAN_WRAP_flush_kthread_work
    WRAP_FOR_DETACH(flush_kthread_work)
#endif
#ifndef CAN_WRAP_compat_sys_msgctl
#   define CAN_WRAP_compat_sys_msgctl 0
#endif
DETACH(compat_sys_msgctl)
#ifndef CAN_WRAP_netdev_set_default_ethtool_ops
#   define CAN_WRAP_netdev_set_default_ethtool_ops 1
#endif
#if CAN_WRAP_netdev_set_default_ethtool_ops
    WRAP_FOR_DETACH(netdev_set_default_ethtool_ops)
#endif
#ifndef CAN_WRAP_acpi_get_node
#   define CAN_WRAP_acpi_get_node 0
#endif
DETACH(acpi_get_node)
#ifndef CAN_WRAP_elv_iosched_store
#   define CAN_WRAP_elv_iosched_store 1
#endif
#if CAN_WRAP_elv_iosched_store
    WRAP_FOR_DETACH(elv_iosched_store)
#endif
#ifndef CAN_WRAP_key_lookup
#   define CAN_WRAP_key_lookup 1
#endif
#if CAN_WRAP_key_lookup
    WRAP_FOR_DETACH(key_lookup)
#endif
#ifndef CAN_WRAP_fixup_user_fault
#   define CAN_WRAP_fixup_user_fault 1
#endif
#if CAN_WRAP_fixup_user_fault
    WRAP_FOR_DETACH(fixup_user_fault)
#endif
#ifndef CAN_WRAP_paravirt_patch_jmp
#   define CAN_WRAP_paravirt_patch_jmp 0
#endif
DETACH(paravirt_patch_jmp)
#ifndef CAN_WRAP_setup_local_APIC
#   define CAN_WRAP_setup_local_APIC 0
#endif
DETACH(setup_local_APIC)
#ifndef CAN_WRAP_invalidate_inode_page
#   define CAN_WRAP_invalidate_inode_page 1
#endif
#if CAN_WRAP_invalidate_inode_page
    WRAP_FOR_DETACH(invalidate_inode_page)
#endif
#ifndef CAN_WRAP_acpi_pci_irq_enable
#   define CAN_WRAP_acpi_pci_irq_enable 1
#endif
#if CAN_WRAP_acpi_pci_irq_enable
    WRAP_FOR_DETACH(acpi_pci_irq_enable)
#endif
#ifndef CAN_WRAP___set_page_dirty_nobuffers
#   define CAN_WRAP___set_page_dirty_nobuffers 1
#endif
#if CAN_WRAP___set_page_dirty_nobuffers
#   ifdef DETACH_ADDR___set_page_dirty_nobuffers
        WRAP_FOR_DETACH(__set_page_dirty_nobuffers)
#   else
        TYPED_DETACH(__set_page_dirty_nobuffers)
#   endif
#endif
#ifndef CAN_WRAP_nf_conntrack_destroy
#   define CAN_WRAP_nf_conntrack_destroy 1
#endif
#if CAN_WRAP_nf_conntrack_destroy
    WRAP_FOR_DETACH(nf_conntrack_destroy)
#endif
#ifndef CAN_WRAP_cap_bprm_set_creds
#   define CAN_WRAP_cap_bprm_set_creds 1
#endif
#if CAN_WRAP_cap_bprm_set_creds
    WRAP_FOR_DETACH(cap_bprm_set_creds)
#endif
#ifndef CAN_WRAP_keventd_up
#   define CAN_WRAP_keventd_up 0
#endif
DETACH(keventd_up)
#ifndef CAN_WRAP_shrink_dcache_sb
#   define CAN_WRAP_shrink_dcache_sb 1
#endif
#if CAN_WRAP_shrink_dcache_sb
    WRAP_FOR_DETACH(shrink_dcache_sb)
#endif
#ifndef CAN_WRAP_end_swap_bio_read
#   define CAN_WRAP_end_swap_bio_read 1
#endif
#if CAN_WRAP_end_swap_bio_read
    WRAP_FOR_DETACH(end_swap_bio_read)
#endif
#ifndef CAN_WRAP_xapic_icr_write
#   define CAN_WRAP_xapic_icr_write 0
#endif
DETACH(xapic_icr_write)
#ifndef CAN_WRAP___flush_signals
#   define CAN_WRAP___flush_signals 1
#endif
#if CAN_WRAP___flush_signals
#   ifdef DETACH_ADDR___flush_signals
        WRAP_FOR_DETACH(__flush_signals)
#   else
        TYPED_DETACH(__flush_signals)
#   endif
#endif
#ifndef CAN_WRAP_wait_iff_congested
#   define CAN_WRAP_wait_iff_congested 1
#endif
#if CAN_WRAP_wait_iff_congested
    WRAP_FOR_DETACH(wait_iff_congested)
#endif
#ifndef CAN_WRAP_wmi_remove_notify_handler
#   define CAN_WRAP_wmi_remove_notify_handler 0
#endif
DETACH(wmi_remove_notify_handler)
#ifndef CAN_WRAP_ata_bmdma_dumb_qc_prep
#   define CAN_WRAP_ata_bmdma_dumb_qc_prep 1
#endif
#if CAN_WRAP_ata_bmdma_dumb_qc_prep
    WRAP_FOR_DETACH(ata_bmdma_dumb_qc_prep)
#endif
#ifndef CAN_WRAP_security_socket_getpeersec_dgram
#   define CAN_WRAP_security_socket_getpeersec_dgram 1
#endif
#if CAN_WRAP_security_socket_getpeersec_dgram
    WRAP_FOR_DETACH(security_socket_getpeersec_dgram)
#endif
#ifndef CAN_WRAP_call_netdevice_notifiers
#   define CAN_WRAP_call_netdevice_notifiers 1
#endif
#if CAN_WRAP_call_netdevice_notifiers
    WRAP_FOR_DETACH(call_netdevice_notifiers)
#endif
#ifndef CAN_WRAP_free_sched_domains
#   define CAN_WRAP_free_sched_domains 0
#endif
DETACH(free_sched_domains)
#ifndef CAN_WRAP_pci_cfg_space_size
#   define CAN_WRAP_pci_cfg_space_size 1
#endif
#if CAN_WRAP_pci_cfg_space_size
    WRAP_FOR_DETACH(pci_cfg_space_size)
#endif
#ifndef CAN_WRAP_kernel_read
#   define CAN_WRAP_kernel_read 1
#endif
#if CAN_WRAP_kernel_read
    WRAP_FOR_DETACH(kernel_read)
#endif
#ifndef CAN_WRAP_generic_file_readonly_mmap
#   define CAN_WRAP_generic_file_readonly_mmap 1
#endif
#if CAN_WRAP_generic_file_readonly_mmap
    WRAP_FOR_DETACH(generic_file_readonly_mmap)
#endif
#ifndef CAN_WRAP_acpi_os_write_memory
#   define CAN_WRAP_acpi_os_write_memory 0
#endif
DETACH(acpi_os_write_memory)
#ifndef CAN_WRAP_scsi_host_set_state
#   define CAN_WRAP_scsi_host_set_state 1
#endif
#if CAN_WRAP_scsi_host_set_state
    WRAP_FOR_DETACH(scsi_host_set_state)
#endif
#ifndef CAN_WRAP_timekeeping_inject_offset
#   define CAN_WRAP_timekeeping_inject_offset 1
#endif
#if CAN_WRAP_timekeeping_inject_offset
    WRAP_FOR_DETACH(timekeeping_inject_offset)
#endif
#ifndef CAN_WRAP_phy_ethtool_set_eee
#   define CAN_WRAP_phy_ethtool_set_eee 1
#endif
#if CAN_WRAP_phy_ethtool_set_eee
    WRAP_FOR_DETACH(phy_ethtool_set_eee)
#endif
#ifndef CAN_WRAP_compat_restore_altstack
#   define CAN_WRAP_compat_restore_altstack 1
#endif
#if CAN_WRAP_compat_restore_altstack
    WRAP_FOR_DETACH(compat_restore_altstack)
#endif
#ifndef CAN_WRAP_bio_integrity_enabled
#   define CAN_WRAP_bio_integrity_enabled 1
#endif
#if CAN_WRAP_bio_integrity_enabled
    WRAP_FOR_DETACH(bio_integrity_enabled)
#endif
#ifndef CAN_WRAP_destroy_irq
#   define CAN_WRAP_destroy_irq 0
#endif
DETACH(destroy_irq)
#ifndef CAN_WRAP_skb_queue_purge
#   define CAN_WRAP_skb_queue_purge 1
#endif
#if CAN_WRAP_skb_queue_purge
    WRAP_FOR_DETACH(skb_queue_purge)
#endif
#ifndef CAN_WRAP_sysfs_remove_file
#   define CAN_WRAP_sysfs_remove_file 1
#endif
#if CAN_WRAP_sysfs_remove_file
    WRAP_FOR_DETACH(sysfs_remove_file)
#endif
#ifndef CAN_WRAP_netdev_state_change
#   define CAN_WRAP_netdev_state_change 1
#endif
#if CAN_WRAP_netdev_state_change
    WRAP_FOR_DETACH(netdev_state_change)
#endif
#ifndef CAN_WRAP_early_ioremap
#   define CAN_WRAP_early_ioremap 0
#endif
DETACH(early_ioremap)
#ifndef CAN_WRAP_pci_bus_write_config_word
#   define CAN_WRAP_pci_bus_write_config_word 1
#endif
#if CAN_WRAP_pci_bus_write_config_word
    WRAP_FOR_DETACH(pci_bus_write_config_word)
#endif
#ifndef CAN_WRAP_hrtimer_run_queues
#   define CAN_WRAP_hrtimer_run_queues 0
#endif
DETACH(hrtimer_run_queues)
#ifndef CAN_WRAP_jbd2_journal_destroy_revoke
#   define CAN_WRAP_jbd2_journal_destroy_revoke 1
#endif
#if CAN_WRAP_jbd2_journal_destroy_revoke
    WRAP_FOR_DETACH(jbd2_journal_destroy_revoke)
#endif
#ifndef CAN_WRAP_pcix_get_max_mmrbc
#   define CAN_WRAP_pcix_get_max_mmrbc 1
#endif
#if CAN_WRAP_pcix_get_max_mmrbc
    WRAP_FOR_DETACH(pcix_get_max_mmrbc)
#endif
#ifndef CAN_WRAP_get_wchan
#   define CAN_WRAP_get_wchan 1
#endif
#if CAN_WRAP_get_wchan
    WRAP_FOR_DETACH(get_wchan)
#endif
#ifndef CAN_WRAP_native_safe_apic_wait_icr_idle
#   define CAN_WRAP_native_safe_apic_wait_icr_idle 0
#endif
DETACH(native_safe_apic_wait_icr_idle)
#ifndef CAN_WRAP_dquot_destroy
#   define CAN_WRAP_dquot_destroy 1
#endif
#if CAN_WRAP_dquot_destroy
    WRAP_FOR_DETACH(dquot_destroy)
#endif
#ifndef CAN_WRAP_fprop_new_period
#   define CAN_WRAP_fprop_new_period 1
#endif
#if CAN_WRAP_fprop_new_period
    WRAP_FOR_DETACH(fprop_new_period)
#endif
#ifndef CAN_WRAP_usermodehelper_read_lock_wait
#   define CAN_WRAP_usermodehelper_read_lock_wait 0
#endif
DETACH(usermodehelper_read_lock_wait)
#ifndef CAN_WRAP_get_net_ns_by_pid
#   define CAN_WRAP_get_net_ns_by_pid 1
#endif
#if CAN_WRAP_get_net_ns_by_pid
    WRAP_FOR_DETACH(get_net_ns_by_pid)
#endif
#ifndef CAN_WRAP___blk_complete_request
#   define CAN_WRAP___blk_complete_request 1
#endif
#if CAN_WRAP___blk_complete_request
#   ifdef DETACH_ADDR___blk_complete_request
        WRAP_FOR_DETACH(__blk_complete_request)
#   else
        TYPED_DETACH(__blk_complete_request)
#   endif
#endif
#ifndef CAN_WRAP_acpi_os_physical_table_override
#   define CAN_WRAP_acpi_os_physical_table_override 1
#endif
#if CAN_WRAP_acpi_os_physical_table_override
    WRAP_FOR_DETACH(acpi_os_physical_table_override)
#endif
#ifndef CAN_WRAP_netlink_broadcast_filtered
#   define CAN_WRAP_netlink_broadcast_filtered 1
#endif
#if CAN_WRAP_netlink_broadcast_filtered
    WRAP_FOR_DETACH(netlink_broadcast_filtered)
#endif
#ifndef CAN_WRAP_pcie_bus_configure_settings
#   define CAN_WRAP_pcie_bus_configure_settings 1
#endif
#if CAN_WRAP_pcie_bus_configure_settings
    WRAP_FOR_DETACH(pcie_bus_configure_settings)
#endif
#ifndef CAN_WRAP_klist_init
#   define CAN_WRAP_klist_init 1
#endif
#if CAN_WRAP_klist_init
    WRAP_FOR_DETACH(klist_init)
#endif
#ifndef CAN_WRAP_ilookup
#   define CAN_WRAP_ilookup 1
#endif
#if CAN_WRAP_ilookup
    WRAP_FOR_DETACH(ilookup)
#endif
#ifndef CAN_WRAP_sched_group_set_rt_runtime
#   define CAN_WRAP_sched_group_set_rt_runtime 1
#endif
#if CAN_WRAP_sched_group_set_rt_runtime
    WRAP_FOR_DETACH(sched_group_set_rt_runtime)
#endif
#ifndef CAN_WRAP___skb_checksum_complete_head
#   define CAN_WRAP___skb_checksum_complete_head 1
#endif
#if CAN_WRAP___skb_checksum_complete_head
#   ifdef DETACH_ADDR___skb_checksum_complete_head
        WRAP_FOR_DETACH(__skb_checksum_complete_head)
#   else
        TYPED_DETACH(__skb_checksum_complete_head)
#   endif
#endif
#ifndef CAN_WRAP_dev_pm_qos_add_global_notifier
#   define CAN_WRAP_dev_pm_qos_add_global_notifier 1
#endif
#if CAN_WRAP_dev_pm_qos_add_global_notifier
    WRAP_FOR_DETACH(dev_pm_qos_add_global_notifier)
#endif
#ifndef CAN_WRAP_tracepoint_iter_reset
#   define CAN_WRAP_tracepoint_iter_reset 1
#endif
#if CAN_WRAP_tracepoint_iter_reset
    WRAP_FOR_DETACH(tracepoint_iter_reset)
#endif
#ifndef CAN_WRAP_install_thread_keyring_to_cred
#   define CAN_WRAP_install_thread_keyring_to_cred 1
#endif
#if CAN_WRAP_install_thread_keyring_to_cred
    WRAP_FOR_DETACH(install_thread_keyring_to_cred)
#endif
#ifndef CAN_WRAP_bd_forget
#   define CAN_WRAP_bd_forget 1
#endif
#if CAN_WRAP_bd_forget
    WRAP_FOR_DETACH(bd_forget)
#endif
#ifndef CAN_WRAP_user_shm_lock
#   define CAN_WRAP_user_shm_lock 1
#endif
#if CAN_WRAP_user_shm_lock
    WRAP_FOR_DETACH(user_shm_lock)
#endif
#ifndef CAN_WRAP_acpi_callocate
#   define CAN_WRAP_acpi_callocate 0
#endif
DETACH(acpi_callocate)
#ifndef CAN_WRAP_netlink_getsockbyfilp
#   define CAN_WRAP_netlink_getsockbyfilp 1
#endif
#if CAN_WRAP_netlink_getsockbyfilp
    WRAP_FOR_DETACH(netlink_getsockbyfilp)
#endif
#ifndef CAN_WRAP_mem_cgroup_sockets_destroy
#   define CAN_WRAP_mem_cgroup_sockets_destroy 1
#endif
#if CAN_WRAP_mem_cgroup_sockets_destroy
    WRAP_FOR_DETACH(mem_cgroup_sockets_destroy)
#endif
#ifndef CAN_WRAP_pci_find_upstream_pcie_bridge
#   define CAN_WRAP_pci_find_upstream_pcie_bridge 1
#endif
#if CAN_WRAP_pci_find_upstream_pcie_bridge
    WRAP_FOR_DETACH(pci_find_upstream_pcie_bridge)
#endif
#ifndef CAN_WRAP_aio_complete
#   define CAN_WRAP_aio_complete 1
#endif
#if CAN_WRAP_aio_complete
    WRAP_FOR_DETACH(aio_complete)
#endif
#ifndef CAN_WRAP_compat_nf_setsockopt
#   define CAN_WRAP_compat_nf_setsockopt 1
#endif
#if CAN_WRAP_compat_nf_setsockopt
    WRAP_FOR_DETACH(compat_nf_setsockopt)
#endif
#ifndef CAN_WRAP_node_random
#   define CAN_WRAP_node_random 1
#endif
#if CAN_WRAP_node_random
    WRAP_FOR_DETACH(node_random)
#endif
#ifndef CAN_WRAP_iterate_supers_type
#   define CAN_WRAP_iterate_supers_type 1
#endif
#if CAN_WRAP_iterate_supers_type
    WRAP_FOR_DETACH(iterate_supers_type)
#endif
#ifndef CAN_WRAP_warn_slowpath_null
#   define CAN_WRAP_warn_slowpath_null 0
#endif
DETACH(warn_slowpath_null)
#ifndef CAN_WRAP_compat_sys_clock_nanosleep
#   define CAN_WRAP_compat_sys_clock_nanosleep 1
#endif
#if CAN_WRAP_compat_sys_clock_nanosleep
    WRAP_FOR_DETACH(compat_sys_clock_nanosleep)
#endif
#ifndef CAN_WRAP_alloc_chrdev_region
#   define CAN_WRAP_alloc_chrdev_region 0
#endif
DETACH(alloc_chrdev_region)
#ifndef CAN_WRAP_key_unlink
#   define CAN_WRAP_key_unlink 1
#endif
#if CAN_WRAP_key_unlink
    WRAP_FOR_DETACH(key_unlink)
#endif
#ifndef CAN_WRAP_ata_sff_dev_classify
#   define CAN_WRAP_ata_sff_dev_classify 1
#endif
#if CAN_WRAP_ata_sff_dev_classify
    WRAP_FOR_DETACH(ata_sff_dev_classify)
#endif
#ifndef CAN_WRAP_ata_host_detach
#   define CAN_WRAP_ata_host_detach 1
#endif
#if CAN_WRAP_ata_host_detach
    WRAP_FOR_DETACH(ata_host_detach)
#endif
#ifndef CAN_WRAP_vfs_lstat
#   define CAN_WRAP_vfs_lstat 1
#endif
#if CAN_WRAP_vfs_lstat
    WRAP_FOR_DETACH(vfs_lstat)
#endif
#ifndef CAN_WRAP_ata_sff_dma_pause
#   define CAN_WRAP_ata_sff_dma_pause 1
#endif
#if CAN_WRAP_ata_sff_dma_pause
    WRAP_FOR_DETACH(ata_sff_dma_pause)
#endif
#ifndef CAN_WRAP_generic_file_fsync
#   define CAN_WRAP_generic_file_fsync 1
#endif
#if CAN_WRAP_generic_file_fsync
    WRAP_FOR_DETACH(generic_file_fsync)
#endif
#ifndef CAN_WRAP_memmove
#   define CAN_WRAP_memmove 0
#endif
DETACH(memmove)
#ifndef CAN_WRAP_dma_run_dependencies
#   define CAN_WRAP_dma_run_dependencies 1
#endif
#if CAN_WRAP_dma_run_dependencies
    WRAP_FOR_DETACH(dma_run_dependencies)
#endif
#ifndef CAN_WRAP_bio_integrity_split
#   define CAN_WRAP_bio_integrity_split 1
#endif
#if CAN_WRAP_bio_integrity_split
    WRAP_FOR_DETACH(bio_integrity_split)
#endif
#ifndef CAN_WRAP_simple_write_begin
#   define CAN_WRAP_simple_write_begin 1
#endif
#if CAN_WRAP_simple_write_begin
    WRAP_FOR_DETACH(simple_write_begin)
#endif
#ifndef CAN_WRAP_skb_copy_datagram_iovec
#   define CAN_WRAP_skb_copy_datagram_iovec 1
#endif
#if CAN_WRAP_skb_copy_datagram_iovec
    WRAP_FOR_DETACH(skb_copy_datagram_iovec)
#endif
#ifndef CAN_WRAP___bread
#   define CAN_WRAP___bread 1
#endif
#if CAN_WRAP___bread
#   ifdef DETACH_ADDR___bread
        WRAP_FOR_DETACH(__bread)
#   else
        TYPED_DETACH(__bread)
#   endif
#endif
#ifndef CAN_WRAP_arch_get_unmapped_area_topdown
#   define CAN_WRAP_arch_get_unmapped_area_topdown 1
#endif
#if CAN_WRAP_arch_get_unmapped_area_topdown
    WRAP_FOR_DETACH(arch_get_unmapped_area_topdown)
#endif
#ifndef CAN_WRAP_generic_getxattr
#   define CAN_WRAP_generic_getxattr 1
#endif
#if CAN_WRAP_generic_getxattr
    WRAP_FOR_DETACH(generic_getxattr)
#endif
#ifndef CAN_WRAP_netdev_update_features
#   define CAN_WRAP_netdev_update_features 1
#endif
#if CAN_WRAP_netdev_update_features
    WRAP_FOR_DETACH(netdev_update_features)
#endif
#ifndef CAN_WRAP___pud_alloc
#   define CAN_WRAP___pud_alloc 1
#endif
#if CAN_WRAP___pud_alloc
#   ifdef DETACH_ADDR___pud_alloc
        WRAP_FOR_DETACH(__pud_alloc)
#   else
        TYPED_DETACH(__pud_alloc)
#   endif
#endif
#ifndef CAN_WRAP_add_interrupt_randomness
#   define CAN_WRAP_add_interrupt_randomness 0
#endif
DETACH(add_interrupt_randomness)
#ifndef CAN_WRAP___cond_resched_lock
#   define CAN_WRAP___cond_resched_lock 1
#endif
#if CAN_WRAP___cond_resched_lock
#   ifdef DETACH_ADDR___cond_resched_lock
        WRAP_FOR_DETACH(__cond_resched_lock)
#   else
        TYPED_DETACH(__cond_resched_lock)
#   endif
#endif
#ifndef CAN_WRAP_timekeeping_inject_sleeptime
#   define CAN_WRAP_timekeeping_inject_sleeptime 1
#endif
#if CAN_WRAP_timekeeping_inject_sleeptime
    WRAP_FOR_DETACH(timekeeping_inject_sleeptime)
#endif
#ifndef CAN_WRAP__raw_read_lock_irqsave
#   define CAN_WRAP__raw_read_lock_irqsave 1
#endif
#if CAN_WRAP__raw_read_lock_irqsave
    WRAP_FOR_DETACH(_raw_read_lock_irqsave)
#endif
#ifndef CAN_WRAP_find_next_zero_bit
#   define CAN_WRAP_find_next_zero_bit 0
#endif
DETACH(find_next_zero_bit)
#ifndef CAN_WRAP_get_signal_to_deliver
#   define CAN_WRAP_get_signal_to_deliver 1
#endif
#if CAN_WRAP_get_signal_to_deliver
    WRAP_FOR_DETACH(get_signal_to_deliver)
#endif
#ifndef CAN_WRAP_hrtimer_get_next_event
#   define CAN_WRAP_hrtimer_get_next_event 0
#endif
DETACH(hrtimer_get_next_event)
#ifndef CAN_WRAP_dm_swap_table
#   define CAN_WRAP_dm_swap_table 1
#endif
#if CAN_WRAP_dm_swap_table
    WRAP_FOR_DETACH(dm_swap_table)
#endif
#ifndef CAN_WRAP_dm_get_rq_mapinfo
#   define CAN_WRAP_dm_get_rq_mapinfo 1
#endif
#if CAN_WRAP_dm_get_rq_mapinfo
    WRAP_FOR_DETACH(dm_get_rq_mapinfo)
#endif
#ifndef CAN_WRAP_text_poke_smp_batch
#   define CAN_WRAP_text_poke_smp_batch 1
#endif
#if CAN_WRAP_text_poke_smp_batch
    WRAP_FOR_DETACH(text_poke_smp_batch)
#endif
#ifndef CAN_WRAP_kobject_move
#   define CAN_WRAP_kobject_move 1
#endif
#if CAN_WRAP_kobject_move
    WRAP_FOR_DETACH(kobject_move)
#endif
#ifndef CAN_WRAP_set_security_override_from_ctx
#   define CAN_WRAP_set_security_override_from_ctx 1
#endif
#if CAN_WRAP_set_security_override_from_ctx
    WRAP_FOR_DETACH(set_security_override_from_ctx)
#endif
#ifndef CAN_WRAP_ata_bmdma_interrupt
#   define CAN_WRAP_ata_bmdma_interrupt 0
#endif
DETACH(ata_bmdma_interrupt)
#ifndef CAN_WRAP_sk_free
#   define CAN_WRAP_sk_free 1
#endif
#if CAN_WRAP_sk_free
    WRAP_FOR_DETACH(sk_free)
#endif
#ifndef CAN_WRAP_pci_swizzle_interrupt_pin
#   define CAN_WRAP_pci_swizzle_interrupt_pin 1
#endif
#if CAN_WRAP_pci_swizzle_interrupt_pin
    WRAP_FOR_DETACH(pci_swizzle_interrupt_pin)
#endif
#ifndef CAN_WRAP_dev_mc_del_global
#   define CAN_WRAP_dev_mc_del_global 1
#endif
#if CAN_WRAP_dev_mc_del_global
    WRAP_FOR_DETACH(dev_mc_del_global)
#endif
#ifndef CAN_WRAP_pci_cfg_access_lock
#   define CAN_WRAP_pci_cfg_access_lock 1
#endif
#if CAN_WRAP_pci_cfg_access_lock
    WRAP_FOR_DETACH(pci_cfg_access_lock)
#endif
#ifndef CAN_WRAP_threshold_interrupt
#   define CAN_WRAP_threshold_interrupt 0
#endif
DETACH(threshold_interrupt)
#ifndef CAN_WRAP_param_set_bool
#   define CAN_WRAP_param_set_bool 1
#endif
#if CAN_WRAP_param_set_bool
    WRAP_FOR_DETACH(param_set_bool)
#endif
#ifndef CAN_WRAP_ata_acpi_gtm
#   define CAN_WRAP_ata_acpi_gtm 1
#endif
#if CAN_WRAP_ata_acpi_gtm
    WRAP_FOR_DETACH(ata_acpi_gtm)
#endif
#ifndef CAN_WRAP_devm_input_allocate_device
#   define CAN_WRAP_devm_input_allocate_device 1
#endif
#if CAN_WRAP_devm_input_allocate_device
    WRAP_FOR_DETACH(devm_input_allocate_device)
#endif
#ifndef CAN_WRAP_d_instantiate
#   define CAN_WRAP_d_instantiate 1
#endif
#if CAN_WRAP_d_instantiate
    WRAP_FOR_DETACH(d_instantiate)
#endif
#ifndef CAN_WRAP_io_apic_set_pci_routing
#   define CAN_WRAP_io_apic_set_pci_routing 1
#endif
#if CAN_WRAP_io_apic_set_pci_routing
    WRAP_FOR_DETACH(io_apic_set_pci_routing)
#endif
#ifndef CAN_WRAP_tracepoint_probe_unregister
#   define CAN_WRAP_tracepoint_probe_unregister 0
#endif
DETACH(tracepoint_probe_unregister)
#ifndef CAN_WRAP_complete
#   define CAN_WRAP_complete 1
#endif
#if CAN_WRAP_complete
    WRAP_FOR_DETACH(complete)
#endif
#ifndef CAN_WRAP_prepare_exec_creds
#   define CAN_WRAP_prepare_exec_creds 1
#endif
#if CAN_WRAP_prepare_exec_creds
    WRAP_FOR_DETACH(prepare_exec_creds)
#endif
#ifndef CAN_WRAP_sock_common_recvmsg
#   define CAN_WRAP_sock_common_recvmsg 1
#endif
#if CAN_WRAP_sock_common_recvmsg
    WRAP_FOR_DETACH(sock_common_recvmsg)
#endif
#ifndef CAN_WRAP___generic_block_fiemap
#   define CAN_WRAP___generic_block_fiemap 1
#endif
#if CAN_WRAP___generic_block_fiemap
#   ifdef DETACH_ADDR___generic_block_fiemap
        WRAP_FOR_DETACH(__generic_block_fiemap)
#   else
        TYPED_DETACH(__generic_block_fiemap)
#   endif
#endif
#ifndef CAN_WRAP_profile_tick
#   define CAN_WRAP_profile_tick 0
#endif
DETACH(profile_tick)
#ifndef CAN_WRAP_vfs_ustat
#   define CAN_WRAP_vfs_ustat 1
#endif
#if CAN_WRAP_vfs_ustat
    WRAP_FOR_DETACH(vfs_ustat)
#endif
#ifndef CAN_WRAP_default_get_smp_config
#   define CAN_WRAP_default_get_smp_config 0
#endif
DETACH(default_get_smp_config)
#ifndef CAN_WRAP_idr_for_each
#   define CAN_WRAP_idr_for_each 1
#endif
#if CAN_WRAP_idr_for_each
    WRAP_FOR_DETACH(idr_for_each)
#endif
#ifndef CAN_WRAP_retire_sysctl_set
#   define CAN_WRAP_retire_sysctl_set 1
#endif
#if CAN_WRAP_retire_sysctl_set
    WRAP_FOR_DETACH(retire_sysctl_set)
#endif
#ifndef CAN_WRAP_sock_rmalloc
#   define CAN_WRAP_sock_rmalloc 1
#endif
#if CAN_WRAP_sock_rmalloc
    WRAP_FOR_DETACH(sock_rmalloc)
#endif
#ifndef CAN_WRAP_address_space_init_once
#   define CAN_WRAP_address_space_init_once 1
#endif
#if CAN_WRAP_address_space_init_once
    WRAP_FOR_DETACH(address_space_init_once)
#endif
#ifndef CAN_WRAP_ata_sff_exec_command
#   define CAN_WRAP_ata_sff_exec_command 1
#endif
#if CAN_WRAP_ata_sff_exec_command
    WRAP_FOR_DETACH(ata_sff_exec_command)
#endif
#ifndef CAN_WRAP_hrtimer_init_sleeper
#   define CAN_WRAP_hrtimer_init_sleeper 1
#endif
#if CAN_WRAP_hrtimer_init_sleeper
    WRAP_FOR_DETACH(hrtimer_init_sleeper)
#endif
#ifndef CAN_WRAP___qdisc_calculate_pkt_len
#   define CAN_WRAP___qdisc_calculate_pkt_len 1
#endif
#if CAN_WRAP___qdisc_calculate_pkt_len
#   ifdef DETACH_ADDR___qdisc_calculate_pkt_len
        WRAP_FOR_DETACH(__qdisc_calculate_pkt_len)
#   else
        TYPED_DETACH(__qdisc_calculate_pkt_len)
#   endif
#endif
#ifndef CAN_WRAP_clockevents_config_and_register
#   define CAN_WRAP_clockevents_config_and_register 1
#endif
#if CAN_WRAP_clockevents_config_and_register
    WRAP_FOR_DETACH(clockevents_config_and_register)
#endif
#ifndef CAN_WRAP_randomize_range
#   define CAN_WRAP_randomize_range 0
#endif
DETACH(randomize_range)
#ifndef CAN_WRAP_compat_sys_ustat
#   define CAN_WRAP_compat_sys_ustat 1
#endif
#if CAN_WRAP_compat_sys_ustat
    WRAP_FOR_DETACH(compat_sys_ustat)
#endif
#ifndef CAN_WRAP_anon_vma_interval_tree_iter_first
#   define CAN_WRAP_anon_vma_interval_tree_iter_first 1
#endif
#if CAN_WRAP_anon_vma_interval_tree_iter_first
    WRAP_FOR_DETACH(anon_vma_interval_tree_iter_first)
#endif
#ifndef CAN_WRAP_dpm_prepare
#   define CAN_WRAP_dpm_prepare 1
#endif
#if CAN_WRAP_dpm_prepare
    WRAP_FOR_DETACH(dpm_prepare)
#endif
#ifndef CAN_WRAP_parameqn
#   define CAN_WRAP_parameqn 0
#endif
DETACH(parameqn)
#ifndef CAN_WRAP_ata_sff_tf_read
#   define CAN_WRAP_ata_sff_tf_read 1
#endif
#if CAN_WRAP_ata_sff_tf_read
    WRAP_FOR_DETACH(ata_sff_tf_read)
#endif
#ifndef CAN_WRAP_dmam_pool_create
#   define CAN_WRAP_dmam_pool_create 1
#endif
#if CAN_WRAP_dmam_pool_create
    WRAP_FOR_DETACH(dmam_pool_create)
#endif
#ifndef CAN_WRAP_inode_init
#   define CAN_WRAP_inode_init 0
#endif
DETACH(inode_init)
#ifndef CAN_WRAP_generic_show_options
#   define CAN_WRAP_generic_show_options 1
#endif
#if CAN_WRAP_generic_show_options
    WRAP_FOR_DETACH(generic_show_options)
#endif
#ifndef CAN_WRAP_security_init
#   define CAN_WRAP_security_init 0
#endif
DETACH(security_init)
#ifndef CAN_WRAP_acpi_evaluate_integer
#   define CAN_WRAP_acpi_evaluate_integer 1
#endif
#if CAN_WRAP_acpi_evaluate_integer
    WRAP_FOR_DETACH(acpi_evaluate_integer)
#endif
#ifndef CAN_WRAP_radix_tree_prev_hole
#   define CAN_WRAP_radix_tree_prev_hole 1
#endif
#if CAN_WRAP_radix_tree_prev_hole
    WRAP_FOR_DETACH(radix_tree_prev_hole)
#endif
#ifndef CAN_WRAP_security_inode_setsecctx
#   define CAN_WRAP_security_inode_setsecctx 1
#endif
#if CAN_WRAP_security_inode_setsecctx
    WRAP_FOR_DETACH(security_inode_setsecctx)
#endif
#ifndef CAN_WRAP_security_inode_permission
#   define CAN_WRAP_security_inode_permission 1
#endif
#if CAN_WRAP_security_inode_permission
    WRAP_FOR_DETACH(security_inode_permission)
#endif
#ifndef CAN_WRAP_get_fs_type
#   define CAN_WRAP_get_fs_type 1
#endif
#if CAN_WRAP_get_fs_type
    WRAP_FOR_DETACH(get_fs_type)
#endif
#ifndef CAN_WRAP_lock_memory_hotplug
#   define CAN_WRAP_lock_memory_hotplug 0
#endif
DETACH(lock_memory_hotplug)
#ifndef CAN_WRAP_put_page
#   define CAN_WRAP_put_page 1
#endif
#if CAN_WRAP_put_page
    WRAP_FOR_DETACH(put_page)
#endif
#ifndef CAN_WRAP_security_bprm_committing_creds
#   define CAN_WRAP_security_bprm_committing_creds 1
#endif
#if CAN_WRAP_security_bprm_committing_creds
    WRAP_FOR_DETACH(security_bprm_committing_creds)
#endif
#ifndef CAN_WRAP___set_current_blocked
#   define CAN_WRAP___set_current_blocked 1
#endif
#if CAN_WRAP___set_current_blocked
#   ifdef DETACH_ADDR___set_current_blocked
        WRAP_FOR_DETACH(__set_current_blocked)
#   else
        TYPED_DETACH(__set_current_blocked)
#   endif
#endif
#ifndef CAN_WRAP_swiotlb_unmap_sg
#   define CAN_WRAP_swiotlb_unmap_sg 1
#endif
#if CAN_WRAP_swiotlb_unmap_sg
    WRAP_FOR_DETACH(swiotlb_unmap_sg)
#endif
#ifndef CAN_WRAP_tracepoint_iter_start
#   define CAN_WRAP_tracepoint_iter_start 1
#endif
#if CAN_WRAP_tracepoint_iter_start
    WRAP_FOR_DETACH(tracepoint_iter_start)
#endif
#ifndef CAN_WRAP_irq_move_masked_irq
#   define CAN_WRAP_irq_move_masked_irq 1
#endif
#if CAN_WRAP_irq_move_masked_irq
    WRAP_FOR_DETACH(irq_move_masked_irq)
#endif
#ifndef CAN_WRAP_rb_next
#   define CAN_WRAP_rb_next 1
#endif
#if CAN_WRAP_rb_next
    WRAP_FOR_DETACH(rb_next)
#endif
#ifndef CAN_WRAP_input_unregister_device
#   define CAN_WRAP_input_unregister_device 1
#endif
#if CAN_WRAP_input_unregister_device
    WRAP_FOR_DETACH(input_unregister_device)
#endif
#ifndef CAN_WRAP_security_sem_alloc
#   define CAN_WRAP_security_sem_alloc 1
#endif
#if CAN_WRAP_security_sem_alloc
    WRAP_FOR_DETACH(security_sem_alloc)
#endif
#ifndef CAN_WRAP_arch_unmap_area_topdown
#   define CAN_WRAP_arch_unmap_area_topdown 1
#endif
#if CAN_WRAP_arch_unmap_area_topdown
    WRAP_FOR_DETACH(arch_unmap_area_topdown)
#endif
#ifndef CAN_WRAP_blk_check_plugged
#   define CAN_WRAP_blk_check_plugged 1
#endif
#if CAN_WRAP_blk_check_plugged
    WRAP_FOR_DETACH(blk_check_plugged)
#endif
#ifndef CAN_WRAP_scsi_block_requests
#   define CAN_WRAP_scsi_block_requests 1
#endif
#if CAN_WRAP_scsi_block_requests
    WRAP_FOR_DETACH(scsi_block_requests)
#endif
#ifndef CAN_WRAP_complete_all
#   define CAN_WRAP_complete_all 1
#endif
#if CAN_WRAP_complete_all
    WRAP_FOR_DETACH(complete_all)
#endif
#ifndef CAN_WRAP_clockevents_update_freq
#   define CAN_WRAP_clockevents_update_freq 1
#endif
#if CAN_WRAP_clockevents_update_freq
    WRAP_FOR_DETACH(clockevents_update_freq)
#endif
#ifndef CAN_WRAP_bitmap_remap
#   define CAN_WRAP_bitmap_remap 0
#endif
DETACH(bitmap_remap)
#ifndef CAN_WRAP_setup_node_to_cpumask_map
#   define CAN_WRAP_setup_node_to_cpumask_map 0
#endif
DETACH(setup_node_to_cpumask_map)
#ifndef CAN_WRAP_irq_set_chip
#   define CAN_WRAP_irq_set_chip 1
#endif
#if CAN_WRAP_irq_set_chip
    WRAP_FOR_DETACH(irq_set_chip)
#endif
#ifndef CAN_WRAP_notify_change
#   define CAN_WRAP_notify_change 1
#endif
#if CAN_WRAP_notify_change
    WRAP_FOR_DETACH(notify_change)
#endif
#ifndef CAN_WRAP_pci_load_and_free_saved_state
#   define CAN_WRAP_pci_load_and_free_saved_state 1
#endif
#if CAN_WRAP_pci_load_and_free_saved_state
    WRAP_FOR_DETACH(pci_load_and_free_saved_state)
#endif
#ifndef CAN_WRAP_scsi_host_get
#   define CAN_WRAP_scsi_host_get 1
#endif
#if CAN_WRAP_scsi_host_get
    WRAP_FOR_DETACH(scsi_host_get)
#endif
#ifndef CAN_WRAP_free_area_init_node
#   define CAN_WRAP_free_area_init_node 0
#endif
DETACH(free_area_init_node)
#ifndef CAN_WRAP_inode_change_ok
#   define CAN_WRAP_inode_change_ok 1
#endif
#if CAN_WRAP_inode_change_ok
    WRAP_FOR_DETACH(inode_change_ok)
#endif
#ifndef CAN_WRAP_dcbnl_cee_notify
#   define CAN_WRAP_dcbnl_cee_notify 1
#endif
#if CAN_WRAP_dcbnl_cee_notify
    WRAP_FOR_DETACH(dcbnl_cee_notify)
#endif
#ifndef CAN_WRAP_sysfs_create_dir
#   define CAN_WRAP_sysfs_create_dir 1
#endif
#if CAN_WRAP_sysfs_create_dir
    WRAP_FOR_DETACH(sysfs_create_dir)
#endif
#ifndef CAN_WRAP___wake_up_bit
#   define CAN_WRAP___wake_up_bit 1
#endif
#if CAN_WRAP___wake_up_bit
#   ifdef DETACH_ADDR___wake_up_bit
        WRAP_FOR_DETACH(__wake_up_bit)
#   else
        TYPED_DETACH(__wake_up_bit)
#   endif
#endif
#ifndef CAN_WRAP___const_udelay
#   define CAN_WRAP___const_udelay 0
#endif
DETACH(__const_udelay)
#ifndef CAN_WRAP_acpi_read_bit_register
#   define CAN_WRAP_acpi_read_bit_register 0
#endif
DETACH(acpi_read_bit_register)
#ifndef CAN_WRAP_get_vm_area
#   define CAN_WRAP_get_vm_area 1
#endif
#if CAN_WRAP_get_vm_area
    WRAP_FOR_DETACH(get_vm_area)
#endif
#ifndef CAN_WRAP_prepare_namespace
#   define CAN_WRAP_prepare_namespace 0
#endif
DETACH(prepare_namespace)
#ifndef CAN_WRAP_profile_event_unregister
#   define CAN_WRAP_profile_event_unregister 1
#endif
#if CAN_WRAP_profile_event_unregister
    WRAP_FOR_DETACH(profile_event_unregister)
#endif
#ifndef CAN_WRAP_blk_alloc_queue_node
#   define CAN_WRAP_blk_alloc_queue_node 1
#endif
#if CAN_WRAP_blk_alloc_queue_node
    WRAP_FOR_DETACH(blk_alloc_queue_node)
#endif
#ifndef CAN_WRAP_module_bug_finalize
#   define CAN_WRAP_module_bug_finalize 1
#endif
#if CAN_WRAP_module_bug_finalize
    WRAP_FOR_DETACH(module_bug_finalize)
#endif
#ifndef CAN_WRAP_shrink_slab
#   define CAN_WRAP_shrink_slab 1
#endif
#if CAN_WRAP_shrink_slab
    WRAP_FOR_DETACH(shrink_slab)
#endif
#ifndef CAN_WRAP_mb_cache_entry_alloc
#   define CAN_WRAP_mb_cache_entry_alloc 1
#endif
#if CAN_WRAP_mb_cache_entry_alloc
    WRAP_FOR_DETACH(mb_cache_entry_alloc)
#endif
#ifndef CAN_WRAP_pci_mmcfg_early_init
#   define CAN_WRAP_pci_mmcfg_early_init 0
#endif
DETACH(pci_mmcfg_early_init)
#ifndef CAN_WRAP_mutex_lock_killable
#   define CAN_WRAP_mutex_lock_killable 1
#endif
#if CAN_WRAP_mutex_lock_killable
    WRAP_FOR_DETACH(mutex_lock_killable)
#endif
#ifndef CAN_WRAP_blk_init_tags
#   define CAN_WRAP_blk_init_tags 1
#endif
#if CAN_WRAP_blk_init_tags
    WRAP_FOR_DETACH(blk_init_tags)
#endif
#ifndef CAN_WRAP_compat_sys_ptrace
#   define CAN_WRAP_compat_sys_ptrace 0
#endif
DETACH(compat_sys_ptrace)
#ifndef CAN_WRAP_profile_munmap
#   define CAN_WRAP_profile_munmap 0
#endif
DETACH(profile_munmap)
#ifndef CAN_WRAP_copy_user_generic_string
#   define CAN_WRAP_copy_user_generic_string 0
#endif
DETACH(copy_user_generic_string)
#ifndef CAN_WRAP_blk_sync_queue
#   define CAN_WRAP_blk_sync_queue 1
#endif
#if CAN_WRAP_blk_sync_queue
    WRAP_FOR_DETACH(blk_sync_queue)
#endif
#ifndef CAN_WRAP_securityfs_remove
#   define CAN_WRAP_securityfs_remove 1
#endif
#if CAN_WRAP_securityfs_remove
    WRAP_FOR_DETACH(securityfs_remove)
#endif
#ifndef CAN_WRAP_current_kernel_time
#   define CAN_WRAP_current_kernel_time 1
#endif
#if CAN_WRAP_current_kernel_time
    WRAP_FOR_DETACH(current_kernel_time)
#endif
#ifndef CAN_WRAP_register_one_node
#   define CAN_WRAP_register_one_node 0
#endif
DETACH(register_one_node)
#ifndef CAN_WRAP_alternatives_enable_smp
#   define CAN_WRAP_alternatives_enable_smp 0
#endif
DETACH(alternatives_enable_smp)
#ifndef CAN_WRAP_acpi_os_sleep
#   define CAN_WRAP_acpi_os_sleep 0
#endif
DETACH(acpi_os_sleep)
#ifndef CAN_WRAP_blkdev_get
#   define CAN_WRAP_blkdev_get 1
#endif
#if CAN_WRAP_blkdev_get
    WRAP_FOR_DETACH(blkdev_get)
#endif
#ifndef CAN_WRAP_blk_queue_update_dma_alignment
#   define CAN_WRAP_blk_queue_update_dma_alignment 1
#endif
#if CAN_WRAP_blk_queue_update_dma_alignment
    WRAP_FOR_DETACH(blk_queue_update_dma_alignment)
#endif
#ifndef CAN_WRAP_pci_setup_bridge
#   define CAN_WRAP_pci_setup_bridge 1
#endif
#if CAN_WRAP_pci_setup_bridge
    WRAP_FOR_DETACH(pci_setup_bridge)
#endif
#ifndef CAN_WRAP_qdisc_watchdog_schedule
#   define CAN_WRAP_qdisc_watchdog_schedule 1
#endif
#if CAN_WRAP_qdisc_watchdog_schedule
    WRAP_FOR_DETACH(qdisc_watchdog_schedule)
#endif
#ifndef CAN_WRAP_rtnl_af_unregister
#   define CAN_WRAP_rtnl_af_unregister 1
#endif
#if CAN_WRAP_rtnl_af_unregister
    WRAP_FOR_DETACH(rtnl_af_unregister)
#endif
#ifndef CAN_WRAP_dev_addr_del_multiple
#   define CAN_WRAP_dev_addr_del_multiple 1
#endif
#if CAN_WRAP_dev_addr_del_multiple
    WRAP_FOR_DETACH(dev_addr_del_multiple)
#endif
#ifndef CAN_WRAP_driver_remove_file
#   define CAN_WRAP_driver_remove_file 1
#endif
#if CAN_WRAP_driver_remove_file
    WRAP_FOR_DETACH(driver_remove_file)
#endif
#ifndef CAN_WRAP_native_load_gs_index
#   define CAN_WRAP_native_load_gs_index 0
#endif
DETACH(native_load_gs_index)
#ifndef CAN_WRAP_phy_connect_direct
#   define CAN_WRAP_phy_connect_direct 1
#endif
#if CAN_WRAP_phy_connect_direct
    WRAP_FOR_DETACH(phy_connect_direct)
#endif
#ifndef CAN_WRAP_acpi_boot_init
#   define CAN_WRAP_acpi_boot_init 0
#endif
DETACH(acpi_boot_init)
#ifndef CAN_WRAP_tick_nohz_idle_exit
#   define CAN_WRAP_tick_nohz_idle_exit 0
#endif
DETACH(tick_nohz_idle_exit)
#ifndef CAN_WRAP_dma_async_tx_descriptor_init
#   define CAN_WRAP_dma_async_tx_descriptor_init 1
#endif
#if CAN_WRAP_dma_async_tx_descriptor_init
    WRAP_FOR_DETACH(dma_async_tx_descriptor_init)
#endif
#ifndef CAN_WRAP_key_invalidate
#   define CAN_WRAP_key_invalidate 1
#endif
#if CAN_WRAP_key_invalidate
    WRAP_FOR_DETACH(key_invalidate)
#endif
#ifndef CAN_WRAP_sget
#   define CAN_WRAP_sget 1
#endif
#if CAN_WRAP_sget
    WRAP_FOR_DETACH(sget)
#endif
#ifndef CAN_WRAP_vfs_mkdir
#   define CAN_WRAP_vfs_mkdir 1
#endif
#if CAN_WRAP_vfs_mkdir
    WRAP_FOR_DETACH(vfs_mkdir)
#endif
#ifndef CAN_WRAP_elv_dispatch_sort
#   define CAN_WRAP_elv_dispatch_sort 1
#endif
#if CAN_WRAP_elv_dispatch_sort
    WRAP_FOR_DETACH(elv_dispatch_sort)
#endif
#ifndef CAN_WRAP_prandom_seed
#   define CAN_WRAP_prandom_seed 0
#endif
DETACH(prandom_seed)
#ifndef CAN_WRAP_zone_statistics
#   define CAN_WRAP_zone_statistics 1
#endif
#if CAN_WRAP_zone_statistics
    WRAP_FOR_DETACH(zone_statistics)
#endif
#ifndef CAN_WRAP_rcu_scheduler_starting
#   define CAN_WRAP_rcu_scheduler_starting 0
#endif
DETACH(rcu_scheduler_starting)
#ifndef CAN_WRAP_skb_splice_bits
#   define CAN_WRAP_skb_splice_bits 1
#endif
#if CAN_WRAP_skb_splice_bits
    WRAP_FOR_DETACH(skb_splice_bits)
#endif
#ifndef CAN_WRAP_sparse_memory_present_with_active_regions
#   define CAN_WRAP_sparse_memory_present_with_active_regions 0
#endif
DETACH(sparse_memory_present_with_active_regions)
#ifndef CAN_WRAP_filemap_page_mkwrite
#   define CAN_WRAP_filemap_page_mkwrite 1
#endif
#if CAN_WRAP_filemap_page_mkwrite
    WRAP_FOR_DETACH(filemap_page_mkwrite)
#endif
#ifndef CAN_WRAP_acpi_match_device_ids
#   define CAN_WRAP_acpi_match_device_ids 1
#endif
#if CAN_WRAP_acpi_match_device_ids
    WRAP_FOR_DETACH(acpi_match_device_ids)
#endif
#ifndef CAN_WRAP_put_seccomp_filter
#   define CAN_WRAP_put_seccomp_filter 1
#endif
#if CAN_WRAP_put_seccomp_filter
    WRAP_FOR_DETACH(put_seccomp_filter)
#endif
#ifndef CAN_WRAP_find_get_pages_tag
#   define CAN_WRAP_find_get_pages_tag 1
#endif
#if CAN_WRAP_find_get_pages_tag
    WRAP_FOR_DETACH(find_get_pages_tag)
#endif
#ifndef CAN_WRAP_hex_dump_to_buffer
#   define CAN_WRAP_hex_dump_to_buffer 0
#endif
DETACH(hex_dump_to_buffer)
#ifndef CAN_WRAP_blk_init_queue
#   define CAN_WRAP_blk_init_queue 1
#endif
#if CAN_WRAP_blk_init_queue
    WRAP_FOR_DETACH(blk_init_queue)
#endif
#ifndef CAN_WRAP_remove_memory
#   define CAN_WRAP_remove_memory 0
#endif
DETACH(remove_memory)
#ifndef CAN_WRAP_block_sync_page
#   define CAN_WRAP_block_sync_page 1
#endif
#if CAN_WRAP_block_sync_page
    WRAP_FOR_DETACH(block_sync_page)
#endif
#ifndef CAN_WRAP___dec_zone_state
#   define CAN_WRAP___dec_zone_state 1
#endif
#if CAN_WRAP___dec_zone_state
#   ifdef DETACH_ADDR___dec_zone_state
        WRAP_FOR_DETACH(__dec_zone_state)
#   else
        TYPED_DETACH(__dec_zone_state)
#   endif
#endif
#ifndef CAN_WRAP_ignore_signals
#   define CAN_WRAP_ignore_signals 1
#endif
#if CAN_WRAP_ignore_signals
    WRAP_FOR_DETACH(ignore_signals)
#endif
#ifndef CAN_WRAP_acpi_set_firmware_waking_vector
#   define CAN_WRAP_acpi_set_firmware_waking_vector 0
#endif
DETACH(acpi_set_firmware_waking_vector)
#ifndef CAN_WRAP_qdisc_lookup_class
#   define CAN_WRAP_qdisc_lookup_class 1
#endif
#if CAN_WRAP_qdisc_lookup_class
    WRAP_FOR_DETACH(qdisc_lookup_class)
#endif
#ifndef CAN_WRAP_part_size_show
#   define CAN_WRAP_part_size_show 1
#endif
#if CAN_WRAP_part_size_show
    WRAP_FOR_DETACH(part_size_show)
#endif
#ifndef CAN_WRAP_profile_init
#   define CAN_WRAP_profile_init 0
#endif
DETACH(profile_init)
#ifndef CAN_WRAP_hrtimer_nanosleep
#   define CAN_WRAP_hrtimer_nanosleep 1
#endif
#if CAN_WRAP_hrtimer_nanosleep
    WRAP_FOR_DETACH(hrtimer_nanosleep)
#endif
#ifndef CAN_WRAP_vm_map_ram
#   define CAN_WRAP_vm_map_ram 1
#endif
#if CAN_WRAP_vm_map_ram
    WRAP_FOR_DETACH(vm_map_ram)
#endif
#ifndef CAN_WRAP_truncate_setsize
#   define CAN_WRAP_truncate_setsize 1
#endif
#if CAN_WRAP_truncate_setsize
    WRAP_FOR_DETACH(truncate_setsize)
#endif
#ifndef CAN_WRAP_device_show_bool
#   define CAN_WRAP_device_show_bool 1
#endif
#if CAN_WRAP_device_show_bool
    WRAP_FOR_DETACH(device_show_bool)
#endif
#ifndef CAN_WRAP_atomic_dec_and_mutex_lock
#   define CAN_WRAP_atomic_dec_and_mutex_lock 1
#endif
#if CAN_WRAP_atomic_dec_and_mutex_lock
    WRAP_FOR_DETACH(atomic_dec_and_mutex_lock)
#endif
#ifndef CAN_WRAP_security_sb_parse_opts_str
#   define CAN_WRAP_security_sb_parse_opts_str 1
#endif
#if CAN_WRAP_security_sb_parse_opts_str
    WRAP_FOR_DETACH(security_sb_parse_opts_str)
#endif
#ifndef CAN_WRAP_elv_completed_request
#   define CAN_WRAP_elv_completed_request 1
#endif
#if CAN_WRAP_elv_completed_request
    WRAP_FOR_DETACH(elv_completed_request)
#endif
#ifndef CAN_WRAP_ata_sff_qc_fill_rtf
#   define CAN_WRAP_ata_sff_qc_fill_rtf 1
#endif
#if CAN_WRAP_ata_sff_qc_fill_rtf
    WRAP_FOR_DETACH(ata_sff_qc_fill_rtf)
#endif
#ifndef CAN_WRAP_acpi_os_read_memory
#   define CAN_WRAP_acpi_os_read_memory 0
#endif
DETACH(acpi_os_read_memory)
#ifndef CAN_WRAP_acpi_get_name
#   define CAN_WRAP_acpi_get_name 1
#endif
#if CAN_WRAP_acpi_get_name
    WRAP_FOR_DETACH(acpi_get_name)
#endif
#ifndef CAN_WRAP_skb_partial_csum_set
#   define CAN_WRAP_skb_partial_csum_set 1
#endif
#if CAN_WRAP_skb_partial_csum_set
    WRAP_FOR_DETACH(skb_partial_csum_set)
#endif
#ifndef CAN_WRAP_bdgrab
#   define CAN_WRAP_bdgrab 1
#endif
#if CAN_WRAP_bdgrab
    WRAP_FOR_DETACH(bdgrab)
#endif
#ifndef CAN_WRAP_mp_register_gsi
#   define CAN_WRAP_mp_register_gsi 1
#endif
#if CAN_WRAP_mp_register_gsi
    WRAP_FOR_DETACH(mp_register_gsi)
#endif
#ifndef CAN_WRAP_timer_stats_update_stats
#   define CAN_WRAP_timer_stats_update_stats 0
#endif
DETACH(timer_stats_update_stats)
#ifndef CAN_WRAP_jbd2_journal_cancel_revoke
#   define CAN_WRAP_jbd2_journal_cancel_revoke 1
#endif
#if CAN_WRAP_jbd2_journal_cancel_revoke
    WRAP_FOR_DETACH(jbd2_journal_cancel_revoke)
#endif
#ifndef CAN_WRAP_kstrdup
#   define CAN_WRAP_kstrdup 0
#endif
DETACH(kstrdup)
#ifndef CAN_WRAP_pci_scan_bus_on_node
#   define CAN_WRAP_pci_scan_bus_on_node 1
#endif
#if CAN_WRAP_pci_scan_bus_on_node
    WRAP_FOR_DETACH(pci_scan_bus_on_node)
#endif
#ifndef CAN_WRAP___vm_enough_memory
#   define CAN_WRAP___vm_enough_memory 1
#endif
#if CAN_WRAP___vm_enough_memory
#   ifdef DETACH_ADDR___vm_enough_memory
        WRAP_FOR_DETACH(__vm_enough_memory)
#   else
        TYPED_DETACH(__vm_enough_memory)
#   endif
#endif
#ifndef CAN_WRAP_security_path_mkdir
#   define CAN_WRAP_security_path_mkdir 1
#endif
#if CAN_WRAP_security_path_mkdir
    WRAP_FOR_DETACH(security_path_mkdir)
#endif
#ifndef CAN_WRAP_compat_sock_common_setsockopt
#   define CAN_WRAP_compat_sock_common_setsockopt 1
#endif
#if CAN_WRAP_compat_sock_common_setsockopt
    WRAP_FOR_DETACH(compat_sock_common_setsockopt)
#endif
#ifndef CAN_WRAP_rt_mutex_unlock
#   define CAN_WRAP_rt_mutex_unlock 1
#endif
#if CAN_WRAP_rt_mutex_unlock
    WRAP_FOR_DETACH(rt_mutex_unlock)
#endif
#ifndef CAN_WRAP_acpi_info
#   define CAN_WRAP_acpi_info 0
#endif
DETACH(acpi_info)
#ifndef CAN_WRAP_wakeup_source_destroy
#   define CAN_WRAP_wakeup_source_destroy 1
#endif
#if CAN_WRAP_wakeup_source_destroy
    WRAP_FOR_DETACH(wakeup_source_destroy)
#endif
#ifndef CAN_WRAP_sched_clock_cpu
#   define CAN_WRAP_sched_clock_cpu 0
#endif
DETACH(sched_clock_cpu)
#ifndef CAN_WRAP_sock_no_accept
#   define CAN_WRAP_sock_no_accept 1
#endif
#if CAN_WRAP_sock_no_accept
    WRAP_FOR_DETACH(sock_no_accept)
#endif
#ifndef CAN_WRAP_devm_kzalloc
#   define CAN_WRAP_devm_kzalloc 1
#endif
#if CAN_WRAP_devm_kzalloc
    WRAP_FOR_DETACH(devm_kzalloc)
#endif
#ifndef CAN_WRAP_create_prof_cpu_mask
#   define CAN_WRAP_create_prof_cpu_mask 1
#endif
#if CAN_WRAP_create_prof_cpu_mask
    WRAP_FOR_DETACH(create_prof_cpu_mask)
#endif
#ifndef CAN_WRAP_security_task_fix_setuid
#   define CAN_WRAP_security_task_fix_setuid 1
#endif
#if CAN_WRAP_security_task_fix_setuid
    WRAP_FOR_DETACH(security_task_fix_setuid)
#endif
#ifndef CAN_WRAP_ata_bmdma_stop
#   define CAN_WRAP_ata_bmdma_stop 1
#endif
#if CAN_WRAP_ata_bmdma_stop
    WRAP_FOR_DETACH(ata_bmdma_stop)
#endif
#ifndef CAN_WRAP_sysfs_unmerge_group
#   define CAN_WRAP_sysfs_unmerge_group 1
#endif
#if CAN_WRAP_sysfs_unmerge_group
    WRAP_FOR_DETACH(sysfs_unmerge_group)
#endif
#ifndef CAN_WRAP_dget_parent
#   define CAN_WRAP_dget_parent 1
#endif
#if CAN_WRAP_dget_parent
    WRAP_FOR_DETACH(dget_parent)
#endif
#ifndef CAN_WRAP_shake_page
#   define CAN_WRAP_shake_page 1
#endif
#if CAN_WRAP_shake_page
    WRAP_FOR_DETACH(shake_page)
#endif
#ifndef CAN_WRAP_sock_no_bind
#   define CAN_WRAP_sock_no_bind 1
#endif
#if CAN_WRAP_sock_no_bind
    WRAP_FOR_DETACH(sock_no_bind)
#endif
#ifndef CAN_WRAP___secure_computing
#   define CAN_WRAP___secure_computing 0
#endif
DETACH(__secure_computing)
#ifndef CAN_WRAP_rcu_barrier_sched
#   define CAN_WRAP_rcu_barrier_sched 0
#endif
DETACH(rcu_barrier_sched)
#ifndef CAN_WRAP_get_monotonic_coarse
#   define CAN_WRAP_get_monotonic_coarse 1
#endif
#if CAN_WRAP_get_monotonic_coarse
    WRAP_FOR_DETACH(get_monotonic_coarse)
#endif
#ifndef CAN_WRAP_strrchr
#   define CAN_WRAP_strrchr 0
#endif
DETACH(strrchr)
#ifndef CAN_WRAP_filp_open
#   define CAN_WRAP_filp_open 1
#endif
#if CAN_WRAP_filp_open
    WRAP_FOR_DETACH(filp_open)
#endif
#ifndef CAN_WRAP_ata_sff_softreset
#   define CAN_WRAP_ata_sff_softreset 1
#endif
#if CAN_WRAP_ata_sff_softreset
    WRAP_FOR_DETACH(ata_sff_softreset)
#endif
#ifndef CAN_WRAP_init_per_zone_wmark_min
#   define CAN_WRAP_init_per_zone_wmark_min 0
#endif
DETACH(init_per_zone_wmark_min)
#ifndef CAN_WRAP_unregister_netdevice_notifier
#   define CAN_WRAP_unregister_netdevice_notifier 1
#endif
#if CAN_WRAP_unregister_netdevice_notifier
    WRAP_FOR_DETACH(unregister_netdevice_notifier)
#endif
#ifndef CAN_WRAP_pci_get_interrupt_pin
#   define CAN_WRAP_pci_get_interrupt_pin 1
#endif
#if CAN_WRAP_pci_get_interrupt_pin
    WRAP_FOR_DETACH(pci_get_interrupt_pin)
#endif
#ifndef CAN_WRAP_pci_get_slot
#   define CAN_WRAP_pci_get_slot 1
#endif
#if CAN_WRAP_pci_get_slot
    WRAP_FOR_DETACH(pci_get_slot)
#endif
#ifndef CAN_WRAP_lapic_get_maxlvt
#   define CAN_WRAP_lapic_get_maxlvt 0
#endif
DETACH(lapic_get_maxlvt)
#ifndef CAN_WRAP_synchronize_rcu_expedited
#   define CAN_WRAP_synchronize_rcu_expedited 0
#endif
DETACH(synchronize_rcu_expedited)
#ifndef CAN_WRAP_disk_get_part
#   define CAN_WRAP_disk_get_part 1
#endif
#if CAN_WRAP_disk_get_part
    WRAP_FOR_DETACH(disk_get_part)
#endif
#ifndef CAN_WRAP_read_cache_page
#   define CAN_WRAP_read_cache_page 1
#endif
#if CAN_WRAP_read_cache_page
    WRAP_FOR_DETACH(read_cache_page)
#endif
#ifndef CAN_WRAP___online_page_set_limits
#   define CAN_WRAP___online_page_set_limits 1
#endif
#if CAN_WRAP___online_page_set_limits
#   ifdef DETACH_ADDR___online_page_set_limits
        WRAP_FOR_DETACH(__online_page_set_limits)
#   else
        TYPED_DETACH(__online_page_set_limits)
#   endif
#endif
#ifndef CAN_WRAP_bitmap_allocate_region
#   define CAN_WRAP_bitmap_allocate_region 0
#endif
DETACH(bitmap_allocate_region)
#ifndef CAN_WRAP_do_sys_poll
#   define CAN_WRAP_do_sys_poll 1
#endif
#if CAN_WRAP_do_sys_poll
    WRAP_FOR_DETACH(do_sys_poll)
#endif
#ifndef CAN_WRAP_iov_iter_copy_from_user_atomic
#   define CAN_WRAP_iov_iter_copy_from_user_atomic 1
#endif
#if CAN_WRAP_iov_iter_copy_from_user_atomic
    WRAP_FOR_DETACH(iov_iter_copy_from_user_atomic)
#endif
#ifndef CAN_WRAP_compat_sys_recvmmsg
#   define CAN_WRAP_compat_sys_recvmmsg 1
#endif
#if CAN_WRAP_compat_sys_recvmmsg
    WRAP_FOR_DETACH(compat_sys_recvmmsg)
#endif
#ifndef CAN_WRAP_swiotlb_init_with_tbl
#   define CAN_WRAP_swiotlb_init_with_tbl 0
#endif
DETACH(swiotlb_init_with_tbl)
#ifndef CAN_WRAP_rb_last
#   define CAN_WRAP_rb_last 1
#endif
#if CAN_WRAP_rb_last
    WRAP_FOR_DETACH(rb_last)
#endif
#ifndef CAN_WRAP_bio_map_user
#   define CAN_WRAP_bio_map_user 1
#endif
#if CAN_WRAP_bio_map_user
    WRAP_FOR_DETACH(bio_map_user)
#endif
#ifndef CAN_WRAP_lease_modify
#   define CAN_WRAP_lease_modify 0
#endif
DETACH(lease_modify)
#ifndef CAN_WRAP_genphy_update_link
#   define CAN_WRAP_genphy_update_link 1
#endif
#if CAN_WRAP_genphy_update_link
    WRAP_FOR_DETACH(genphy_update_link)
#endif
#ifndef CAN_WRAP_dmam_pool_destroy
#   define CAN_WRAP_dmam_pool_destroy 1
#endif
#if CAN_WRAP_dmam_pool_destroy
    WRAP_FOR_DETACH(dmam_pool_destroy)
#endif
#ifndef CAN_WRAP_cap_capable
#   define CAN_WRAP_cap_capable 1
#endif
#if CAN_WRAP_cap_capable
    WRAP_FOR_DETACH(cap_capable)
#endif
#ifndef CAN_WRAP_percpu_free_rwsem
#   define CAN_WRAP_percpu_free_rwsem 1
#endif
#if CAN_WRAP_percpu_free_rwsem
    WRAP_FOR_DETACH(percpu_free_rwsem)
#endif
#ifndef CAN_WRAP_remove_mapping
#   define CAN_WRAP_remove_mapping 1
#endif
#if CAN_WRAP_remove_mapping
    WRAP_FOR_DETACH(remove_mapping)
#endif
#ifndef CAN_WRAP_dma_generic_alloc_coherent
#   define CAN_WRAP_dma_generic_alloc_coherent 1
#endif
#if CAN_WRAP_dma_generic_alloc_coherent
    WRAP_FOR_DETACH(dma_generic_alloc_coherent)
#endif
#ifndef CAN_WRAP_sock_no_poll
#   define CAN_WRAP_sock_no_poll 1
#endif
#if CAN_WRAP_sock_no_poll
    WRAP_FOR_DETACH(sock_no_poll)
#endif
#ifndef CAN_WRAP_security_mmap_addr
#   define CAN_WRAP_security_mmap_addr 0
#endif
DETACH(security_mmap_addr)
#ifndef CAN_WRAP_find_inode_number
#   define CAN_WRAP_find_inode_number 1
#endif
#if CAN_WRAP_find_inode_number
    WRAP_FOR_DETACH(find_inode_number)
#endif
#ifndef CAN_WRAP_sched_fork
#   define CAN_WRAP_sched_fork 1
#endif
#if CAN_WRAP_sched_fork
    WRAP_FOR_DETACH(sched_fork)
#endif
#ifndef CAN_WRAP_class_interface_register
#   define CAN_WRAP_class_interface_register 1
#endif
#if CAN_WRAP_class_interface_register
    WRAP_FOR_DETACH(class_interface_register)
#endif
#ifndef CAN_WRAP___symbol_get
#   define CAN_WRAP___symbol_get 0
#endif
DETACH(__symbol_get)
#ifndef CAN_WRAP_bio_integrity_prep
#   define CAN_WRAP_bio_integrity_prep 1
#endif
#if CAN_WRAP_bio_integrity_prep
    WRAP_FOR_DETACH(bio_integrity_prep)
#endif
#ifndef CAN_WRAP_do_sigaction
#   define CAN_WRAP_do_sigaction 1
#endif
#if CAN_WRAP_do_sigaction
    WRAP_FOR_DETACH(do_sigaction)
#endif
#ifndef CAN_WRAP_compat_sys_get_robust_list
#   define CAN_WRAP_compat_sys_get_robust_list 0
#endif
DETACH(compat_sys_get_robust_list)
#ifndef CAN_WRAP_call_function_interrupt
#   define CAN_WRAP_call_function_interrupt 0
#endif
DETACH(call_function_interrupt)
#ifndef CAN_WRAP_add_taint
#   define CAN_WRAP_add_taint 0
#endif
DETACH(add_taint)
#ifndef CAN_WRAP_x2apic_icr_write
#   define CAN_WRAP_x2apic_icr_write 0
#endif
DETACH(x2apic_icr_write)
#ifndef CAN_WRAP___raw_notifier_call_chain
#   define CAN_WRAP___raw_notifier_call_chain 1
#endif
#if CAN_WRAP___raw_notifier_call_chain
#   ifdef DETACH_ADDR___raw_notifier_call_chain
        WRAP_FOR_DETACH(__raw_notifier_call_chain)
#   else
        TYPED_DETACH(__raw_notifier_call_chain)
#   endif
#endif
#ifndef CAN_WRAP_pci_bus_assign_resources
#   define CAN_WRAP_pci_bus_assign_resources 1
#endif
#if CAN_WRAP_pci_bus_assign_resources
    WRAP_FOR_DETACH(pci_bus_assign_resources)
#endif
#ifndef CAN_WRAP_dm_error
#   define CAN_WRAP_dm_error 0
#endif
DETACH(dm_error)
#ifndef CAN_WRAP_getnstime_raw_and_real
#   define CAN_WRAP_getnstime_raw_and_real 1
#endif
#if CAN_WRAP_getnstime_raw_and_real
    WRAP_FOR_DETACH(getnstime_raw_and_real)
#endif
#ifndef CAN_WRAP_security_shm_alloc
#   define CAN_WRAP_security_shm_alloc 1
#endif
#if CAN_WRAP_security_shm_alloc
    WRAP_FOR_DETACH(security_shm_alloc)
#endif
#ifndef CAN_WRAP_invalidate_interrupt8
#   define CAN_WRAP_invalidate_interrupt8 0
#endif
DETACH(invalidate_interrupt8)
#ifndef CAN_WRAP_mount_subtree
#   define CAN_WRAP_mount_subtree 1
#endif
#if CAN_WRAP_mount_subtree
    WRAP_FOR_DETACH(mount_subtree)
#endif
#ifndef CAN_WRAP_netif_skb_features
#   define CAN_WRAP_netif_skb_features 1
#endif
#if CAN_WRAP_netif_skb_features
    WRAP_FOR_DETACH(netif_skb_features)
#endif
#ifndef CAN_WRAP_invalidate_interrupt0
#   define CAN_WRAP_invalidate_interrupt0 0
#endif
DETACH(invalidate_interrupt0)
#ifndef CAN_WRAP_d_alloc
#   define CAN_WRAP_d_alloc 1
#endif
#if CAN_WRAP_d_alloc
    WRAP_FOR_DETACH(d_alloc)
#endif
#ifndef CAN_WRAP_invalidate_interrupt2
#   define CAN_WRAP_invalidate_interrupt2 0
#endif
DETACH(invalidate_interrupt2)
#ifndef CAN_WRAP_invalidate_interrupt3
#   define CAN_WRAP_invalidate_interrupt3 0
#endif
DETACH(invalidate_interrupt3)
#ifndef CAN_WRAP_invalidate_interrupt4
#   define CAN_WRAP_invalidate_interrupt4 0
#endif
DETACH(invalidate_interrupt4)
#ifndef CAN_WRAP_ata_ehi_push_desc
#   define CAN_WRAP_ata_ehi_push_desc 1
#endif
#if CAN_WRAP_ata_ehi_push_desc
    WRAP_FOR_DETACH(ata_ehi_push_desc)
#endif
#ifndef CAN_WRAP_invalidate_interrupt6
#   define CAN_WRAP_invalidate_interrupt6 0
#endif
DETACH(invalidate_interrupt6)
#ifndef CAN_WRAP_invalidate_interrupt7
#   define CAN_WRAP_invalidate_interrupt7 0
#endif
DETACH(invalidate_interrupt7)
#ifndef CAN_WRAP_force_sig_info
#   define CAN_WRAP_force_sig_info 1
#endif
#if CAN_WRAP_force_sig_info
    WRAP_FOR_DETACH(force_sig_info)
#endif
#ifndef CAN_WRAP_unmapped_area
#   define CAN_WRAP_unmapped_area 1
#endif
#if CAN_WRAP_unmapped_area
    WRAP_FOR_DETACH(unmapped_area)
#endif
#ifndef CAN_WRAP_read_current_timer
#   define CAN_WRAP_read_current_timer 0
#endif
DETACH(read_current_timer)
#ifndef CAN_WRAP_nr_running
#   define CAN_WRAP_nr_running 0
#endif
DETACH(nr_running)
#ifndef CAN_WRAP_tracing_off_permanent
#   define CAN_WRAP_tracing_off_permanent 0
#endif
DETACH(tracing_off_permanent)
#ifndef CAN_WRAP_jbd2_journal_try_to_free_buffers
#   define CAN_WRAP_jbd2_journal_try_to_free_buffers 1
#endif
#if CAN_WRAP_jbd2_journal_try_to_free_buffers
    WRAP_FOR_DETACH(jbd2_journal_try_to_free_buffers)
#endif
#ifndef CAN_WRAP__raw_write_lock_bh
#   define CAN_WRAP__raw_write_lock_bh 1
#endif
#if CAN_WRAP__raw_write_lock_bh
    WRAP_FOR_DETACH(_raw_write_lock_bh)
#endif
#ifndef CAN_WRAP_kmem_cache_create_memcg
#   define CAN_WRAP_kmem_cache_create_memcg 1
#endif
#if CAN_WRAP_kmem_cache_create_memcg
    WRAP_FOR_DETACH(kmem_cache_create_memcg)
#endif
#ifndef CAN_WRAP___raise_softirq_irqoff
#   define CAN_WRAP___raise_softirq_irqoff 0
#endif
DETACH(__raise_softirq_irqoff)
#ifndef CAN_WRAP_bio_integrity_advance
#   define CAN_WRAP_bio_integrity_advance 1
#endif
#if CAN_WRAP_bio_integrity_advance
    WRAP_FOR_DETACH(bio_integrity_advance)
#endif
#ifndef CAN_WRAP_acpi_get_event_status
#   define CAN_WRAP_acpi_get_event_status 0
#endif
DETACH(acpi_get_event_status)
#ifndef CAN_WRAP___pci_reset_function
#   define CAN_WRAP___pci_reset_function 1
#endif
#if CAN_WRAP___pci_reset_function
#   ifdef DETACH_ADDR___pci_reset_function
        WRAP_FOR_DETACH(__pci_reset_function)
#   else
        TYPED_DETACH(__pci_reset_function)
#   endif
#endif
#ifndef CAN_WRAP_bdi_set_max_ratio
#   define CAN_WRAP_bdi_set_max_ratio 1
#endif
#if CAN_WRAP_bdi_set_max_ratio
    WRAP_FOR_DETACH(bdi_set_max_ratio)
#endif
#ifndef CAN_WRAP_pid_vnr
#   define CAN_WRAP_pid_vnr 1
#endif
#if CAN_WRAP_pid_vnr
    WRAP_FOR_DETACH(pid_vnr)
#endif
#ifndef CAN_WRAP_get_taint
#   define CAN_WRAP_get_taint 0
#endif
DETACH(get_taint)
#ifndef CAN_WRAP_pci_acs_path_enabled
#   define CAN_WRAP_pci_acs_path_enabled 1
#endif
#if CAN_WRAP_pci_acs_path_enabled
    WRAP_FOR_DETACH(pci_acs_path_enabled)
#endif
#ifndef CAN_WRAP_ata_sas_sync_probe
#   define CAN_WRAP_ata_sas_sync_probe 1
#endif
#if CAN_WRAP_ata_sas_sync_probe
    WRAP_FOR_DETACH(ata_sas_sync_probe)
#endif
#ifndef CAN_WRAP_scan_unevictable_handler
#   define CAN_WRAP_scan_unevictable_handler 1
#endif
#if CAN_WRAP_scan_unevictable_handler
    WRAP_FOR_DETACH(scan_unevictable_handler)
#endif
#ifndef CAN_WRAP_ata_scsi_port_error_handler
#   define CAN_WRAP_ata_scsi_port_error_handler 1
#endif
#if CAN_WRAP_ata_scsi_port_error_handler
    WRAP_FOR_DETACH(ata_scsi_port_error_handler)
#endif
#ifndef CAN_WRAP_synchronize_sched_expedited
#   define CAN_WRAP_synchronize_sched_expedited 0
#endif
DETACH(synchronize_sched_expedited)
#ifndef CAN_WRAP_shrink_dcache_parent
#   define CAN_WRAP_shrink_dcache_parent 1
#endif
#if CAN_WRAP_shrink_dcache_parent
    WRAP_FOR_DETACH(shrink_dcache_parent)
#endif
#ifndef CAN_WRAP_native_init_IRQ
#   define CAN_WRAP_native_init_IRQ 0
#endif
DETACH(native_init_IRQ)
#ifndef CAN_WRAP_dev_get_by_name_rcu
#   define CAN_WRAP_dev_get_by_name_rcu 1
#endif
#if CAN_WRAP_dev_get_by_name_rcu
    WRAP_FOR_DETACH(dev_get_by_name_rcu)
#endif
#ifndef CAN_WRAP_srcu_batches_completed
#   define CAN_WRAP_srcu_batches_completed 1
#endif
#if CAN_WRAP_srcu_batches_completed
    WRAP_FOR_DETACH(srcu_batches_completed)
#endif
#ifndef CAN_WRAP_pcim_iounmap_regions
#   define CAN_WRAP_pcim_iounmap_regions 1
#endif
#if CAN_WRAP_pcim_iounmap_regions
    WRAP_FOR_DETACH(pcim_iounmap_regions)
#endif
#ifndef CAN_WRAP_blk_queue_flush
#   define CAN_WRAP_blk_queue_flush 1
#endif
#if CAN_WRAP_blk_queue_flush
    WRAP_FOR_DETACH(blk_queue_flush)
#endif
#ifndef CAN_WRAP_kernel_listen
#   define CAN_WRAP_kernel_listen 1
#endif
#if CAN_WRAP_kernel_listen
    WRAP_FOR_DETACH(kernel_listen)
#endif
#ifndef CAN_WRAP_get_random_int
#   define CAN_WRAP_get_random_int 0
#endif
DETACH(get_random_int)
#ifndef CAN_WRAP_mempool_kmalloc
#   define CAN_WRAP_mempool_kmalloc 0
#endif
DETACH(mempool_kmalloc)
#ifndef CAN_WRAP_blk_peek_request
#   define CAN_WRAP_blk_peek_request 1
#endif
#if CAN_WRAP_blk_peek_request
    WRAP_FOR_DETACH(blk_peek_request)
#endif
#ifndef CAN_WRAP_bio_integrity_alloc
#   define CAN_WRAP_bio_integrity_alloc 1
#endif
#if CAN_WRAP_bio_integrity_alloc
    WRAP_FOR_DETACH(bio_integrity_alloc)
#endif
#ifndef CAN_WRAP_locks_mandatory_locked
#   define CAN_WRAP_locks_mandatory_locked 1
#endif
#if CAN_WRAP_locks_mandatory_locked
    WRAP_FOR_DETACH(locks_mandatory_locked)
#endif
#ifndef CAN_WRAP_free_pages_and_swap_cache
#   define CAN_WRAP_free_pages_and_swap_cache 0
#endif
DETACH(free_pages_and_swap_cache)
#ifndef CAN_WRAP_security_ptrace_access_check
#   define CAN_WRAP_security_ptrace_access_check 1
#endif
#if CAN_WRAP_security_ptrace_access_check
    WRAP_FOR_DETACH(security_ptrace_access_check)
#endif
#ifndef CAN_WRAP_pci_cfg_access_unlock
#   define CAN_WRAP_pci_cfg_access_unlock 1
#endif
#if CAN_WRAP_pci_cfg_access_unlock
    WRAP_FOR_DETACH(pci_cfg_access_unlock)
#endif
#ifndef CAN_WRAP_dm_table_create
#   define CAN_WRAP_dm_table_create 1
#endif
#if CAN_WRAP_dm_table_create
    WRAP_FOR_DETACH(dm_table_create)
#endif
#ifndef CAN_WRAP_kstrtoull_from_user
#   define CAN_WRAP_kstrtoull_from_user 0
#endif
DETACH(kstrtoull_from_user)
#ifndef CAN_WRAP_security_task_setrlimit
#   define CAN_WRAP_security_task_setrlimit 1
#endif
#if CAN_WRAP_security_task_setrlimit
    WRAP_FOR_DETACH(security_task_setrlimit)
#endif
#ifndef CAN_WRAP_ata_bmdma_qc_prep
#   define CAN_WRAP_ata_bmdma_qc_prep 1
#endif
#if CAN_WRAP_ata_bmdma_qc_prep
    WRAP_FOR_DETACH(ata_bmdma_qc_prep)
#endif
#ifndef CAN_WRAP_task_tgid_nr_ns
#   define CAN_WRAP_task_tgid_nr_ns 1
#endif
#if CAN_WRAP_task_tgid_nr_ns
    WRAP_FOR_DETACH(task_tgid_nr_ns)
#endif
#ifndef CAN_WRAP_class_interface_unregister
#   define CAN_WRAP_class_interface_unregister 1
#endif
#if CAN_WRAP_class_interface_unregister
    WRAP_FOR_DETACH(class_interface_unregister)
#endif
#ifndef CAN_WRAP_qid_eq
#   define CAN_WRAP_qid_eq 1
#endif
#if CAN_WRAP_qid_eq
    WRAP_FOR_DETACH(qid_eq)
#endif
#ifndef CAN_WRAP_jbd2_journal_check_used_features
#   define CAN_WRAP_jbd2_journal_check_used_features 1
#endif
#if CAN_WRAP_jbd2_journal_check_used_features
    WRAP_FOR_DETACH(jbd2_journal_check_used_features)
#endif
#ifndef CAN_WRAP_sysctl_min_unmapped_ratio_sysctl_handler
#   define CAN_WRAP_sysctl_min_unmapped_ratio_sysctl_handler 1
#endif
#if CAN_WRAP_sysctl_min_unmapped_ratio_sysctl_handler
    WRAP_FOR_DETACH(sysctl_min_unmapped_ratio_sysctl_handler)
#endif
#ifndef CAN_WRAP_set_pm_idle_to_default
#   define CAN_WRAP_set_pm_idle_to_default 0
#endif
DETACH(set_pm_idle_to_default)
#ifndef CAN_WRAP_kstrtos8_from_user
#   define CAN_WRAP_kstrtos8_from_user 0
#endif
DETACH(kstrtos8_from_user)
#ifndef CAN_WRAP_simple_empty
#   define CAN_WRAP_simple_empty 1
#endif
#if CAN_WRAP_simple_empty
    WRAP_FOR_DETACH(simple_empty)
#endif
#ifndef CAN_WRAP_group_send_sig_info
#   define CAN_WRAP_group_send_sig_info 1
#endif
#if CAN_WRAP_group_send_sig_info
    WRAP_FOR_DETACH(group_send_sig_info)
#endif
#ifndef CAN_WRAP_acpi_dev_suspend_late
#   define CAN_WRAP_acpi_dev_suspend_late 1
#endif
#if CAN_WRAP_acpi_dev_suspend_late
    WRAP_FOR_DETACH(acpi_dev_suspend_late)
#endif
#ifndef CAN_WRAP_dev_pm_qos_remove_global_notifier
#   define CAN_WRAP_dev_pm_qos_remove_global_notifier 1
#endif
#if CAN_WRAP_dev_pm_qos_remove_global_notifier
    WRAP_FOR_DETACH(dev_pm_qos_remove_global_notifier)
#endif
#ifndef CAN_WRAP_get_nr_irqs_gsi
#   define CAN_WRAP_get_nr_irqs_gsi 0
#endif
DETACH(get_nr_irqs_gsi)
#ifndef CAN_WRAP_native_cpu_up
#   define CAN_WRAP_native_cpu_up 1
#endif
#if CAN_WRAP_native_cpu_up
    WRAP_FOR_DETACH(native_cpu_up)
#endif
#ifndef CAN_WRAP_vm_unmap_ram
#   define CAN_WRAP_vm_unmap_ram 0
#endif
DETACH(vm_unmap_ram)
#ifndef CAN_WRAP___cleanup_sighand
#   define CAN_WRAP___cleanup_sighand 1
#endif
#if CAN_WRAP___cleanup_sighand
#   ifdef DETACH_ADDR___cleanup_sighand
        WRAP_FOR_DETACH(__cleanup_sighand)
#   else
        TYPED_DETACH(__cleanup_sighand)
#   endif
#endif
#ifndef CAN_WRAP_page_zero_new_buffers
#   define CAN_WRAP_page_zero_new_buffers 1
#endif
#if CAN_WRAP_page_zero_new_buffers
    WRAP_FOR_DETACH(page_zero_new_buffers)
#endif
#ifndef CAN_WRAP_acpi_get_current_resources
#   define CAN_WRAP_acpi_get_current_resources 1
#endif
#if CAN_WRAP_acpi_get_current_resources
    WRAP_FOR_DETACH(acpi_get_current_resources)
#endif
#ifndef CAN_WRAP_res_counter_read_u64
#   define CAN_WRAP_res_counter_read_u64 1
#endif
#if CAN_WRAP_res_counter_read_u64
    WRAP_FOR_DETACH(res_counter_read_u64)
#endif
#ifndef CAN_WRAP_ata_ap_acpi_handle
#   define CAN_WRAP_ata_ap_acpi_handle 1
#endif
#if CAN_WRAP_ata_ap_acpi_handle
    WRAP_FOR_DETACH(ata_ap_acpi_handle)
#endif
#ifndef CAN_WRAP_down_read
#   define CAN_WRAP_down_read 1
#endif
#if CAN_WRAP_down_read
    WRAP_FOR_DETACH(down_read)
#endif
#ifndef CAN_WRAP___wake_up_locked_key
#   define CAN_WRAP___wake_up_locked_key 1
#endif
#if CAN_WRAP___wake_up_locked_key
#   ifdef DETACH_ADDR___wake_up_locked_key
        WRAP_FOR_DETACH(__wake_up_locked_key)
#   else
        TYPED_DETACH(__wake_up_locked_key)
#   endif
#endif
#ifndef CAN_WRAP_note_interrupt
#   define CAN_WRAP_note_interrupt 1
#endif
#if CAN_WRAP_note_interrupt
    WRAP_FOR_DETACH(note_interrupt)
#endif
#ifndef CAN_WRAP_cancel_delayed_work_sync
#   define CAN_WRAP_cancel_delayed_work_sync 1
#endif
#if CAN_WRAP_cancel_delayed_work_sync
    WRAP_FOR_DETACH(cancel_delayed_work_sync)
#endif
#ifndef CAN_WRAP_set_pageblock_flags_group
#   define CAN_WRAP_set_pageblock_flags_group 1
#endif
#if CAN_WRAP_set_pageblock_flags_group
    WRAP_FOR_DETACH(set_pageblock_flags_group)
#endif
#ifndef CAN_WRAP_find_pid_ns
#   define CAN_WRAP_find_pid_ns 1
#endif
#if CAN_WRAP_find_pid_ns
    WRAP_FOR_DETACH(find_pid_ns)
#endif
#ifndef CAN_WRAP_pm_generic_freeze_noirq
#   define CAN_WRAP_pm_generic_freeze_noirq 1
#endif
#if CAN_WRAP_pm_generic_freeze_noirq
    WRAP_FOR_DETACH(pm_generic_freeze_noirq)
#endif
#ifndef CAN_WRAP_bdev_read_only
#   define CAN_WRAP_bdev_read_only 1
#endif
#if CAN_WRAP_bdev_read_only
    WRAP_FOR_DETACH(bdev_read_only)
#endif
#ifndef CAN_WRAP_copy_semundo
#   define CAN_WRAP_copy_semundo 1
#endif
#if CAN_WRAP_copy_semundo
    WRAP_FOR_DETACH(copy_semundo)
#endif
#ifndef CAN_WRAP_prandom_u32_state
#   define CAN_WRAP_prandom_u32_state 1
#endif
#if CAN_WRAP_prandom_u32_state
    WRAP_FOR_DETACH(prandom_u32_state)
#endif
#ifndef CAN_WRAP_set_task_comm
#   define CAN_WRAP_set_task_comm 1
#endif
#if CAN_WRAP_set_task_comm
    WRAP_FOR_DETACH(set_task_comm)
#endif
#ifndef CAN_WRAP_sched_rt_can_attach
#   define CAN_WRAP_sched_rt_can_attach 1
#endif
#if CAN_WRAP_sched_rt_can_attach
    WRAP_FOR_DETACH(sched_rt_can_attach)
#endif
#ifndef CAN_WRAP_irq_gc_mask_clr_bit
#   define CAN_WRAP_irq_gc_mask_clr_bit 1
#endif
#if CAN_WRAP_irq_gc_mask_clr_bit
    WRAP_FOR_DETACH(irq_gc_mask_clr_bit)
#endif
#ifndef CAN_WRAP_input_scancode_to_scalar
#   define CAN_WRAP_input_scancode_to_scalar 1
#endif
#if CAN_WRAP_input_scancode_to_scalar
    WRAP_FOR_DETACH(input_scancode_to_scalar)
#endif
#ifndef CAN_WRAP_sched_group_rt_period
#   define CAN_WRAP_sched_group_rt_period 1
#endif
#if CAN_WRAP_sched_group_rt_period
    WRAP_FOR_DETACH(sched_group_rt_period)
#endif
#ifndef CAN_WRAP___hw_addr_init
#   define CAN_WRAP___hw_addr_init 1
#endif
#if CAN_WRAP___hw_addr_init
#   ifdef DETACH_ADDR___hw_addr_init
        WRAP_FOR_DETACH(__hw_addr_init)
#   else
        TYPED_DETACH(__hw_addr_init)
#   endif
#endif
#ifndef CAN_WRAP___vma_link_rb
#   define CAN_WRAP___vma_link_rb 1
#endif
#if CAN_WRAP___vma_link_rb
#   ifdef DETACH_ADDR___vma_link_rb
        WRAP_FOR_DETACH(__vma_link_rb)
#   else
        TYPED_DETACH(__vma_link_rb)
#   endif
#endif
#ifndef CAN_WRAP_prop_fraction_percpu
#   define CAN_WRAP_prop_fraction_percpu 1
#endif
#if CAN_WRAP_prop_fraction_percpu
    WRAP_FOR_DETACH(prop_fraction_percpu)
#endif
#ifndef CAN_WRAP_free_pid
#   define CAN_WRAP_free_pid 1
#endif
#if CAN_WRAP_free_pid
    WRAP_FOR_DETACH(free_pid)
#endif
#ifndef CAN_WRAP_ioprio_best
#   define CAN_WRAP_ioprio_best 0
#endif
DETACH(ioprio_best)
#ifndef CAN_WRAP_dev_uc_init
#   define CAN_WRAP_dev_uc_init 1
#endif
#if CAN_WRAP_dev_uc_init
    WRAP_FOR_DETACH(dev_uc_init)
#endif
#ifndef CAN_WRAP_security_inet_conn_established
#   define CAN_WRAP_security_inet_conn_established 1
#endif
#if CAN_WRAP_security_inet_conn_established
    WRAP_FOR_DETACH(security_inet_conn_established)
#endif
#ifndef CAN_WRAP_acpi_register_ioapic
#   define CAN_WRAP_acpi_register_ioapic 0
#endif
DETACH(acpi_register_ioapic)
#ifndef CAN_WRAP_phy_start_aneg
#   define CAN_WRAP_phy_start_aneg 1
#endif
#if CAN_WRAP_phy_start_aneg
    WRAP_FOR_DETACH(phy_start_aneg)
#endif
#ifndef CAN_WRAP___hw_addr_unsync
#   define CAN_WRAP___hw_addr_unsync 1
#endif
#if CAN_WRAP___hw_addr_unsync
#   ifdef DETACH_ADDR___hw_addr_unsync
        WRAP_FOR_DETACH(__hw_addr_unsync)
#   else
        TYPED_DETACH(__hw_addr_unsync)
#   endif
#endif
#ifndef CAN_WRAP_module_put
#   define CAN_WRAP_module_put 1
#endif
#if CAN_WRAP_module_put
    WRAP_FOR_DETACH(module_put)
#endif
#ifndef CAN_WRAP___blk_end_request_err
#   define CAN_WRAP___blk_end_request_err 1
#endif
#if CAN_WRAP___blk_end_request_err
#   ifdef DETACH_ADDR___blk_end_request_err
        WRAP_FOR_DETACH(__blk_end_request_err)
#   else
        TYPED_DETACH(__blk_end_request_err)
#   endif
#endif
#ifndef CAN_WRAP_arch_init_ideal_nops
#   define CAN_WRAP_arch_init_ideal_nops 0
#endif
DETACH(arch_init_ideal_nops)
#ifndef CAN_WRAP___netlink_kernel_create
#   define CAN_WRAP___netlink_kernel_create 1
#endif
#if CAN_WRAP___netlink_kernel_create
#   ifdef DETACH_ADDR___netlink_kernel_create
        WRAP_FOR_DETACH(__netlink_kernel_create)
#   else
        TYPED_DETACH(__netlink_kernel_create)
#   endif
#endif
#ifndef CAN_WRAP___dev_getfirstbyhwtype
#   define CAN_WRAP___dev_getfirstbyhwtype 1
#endif
#if CAN_WRAP___dev_getfirstbyhwtype
#   ifdef DETACH_ADDR___dev_getfirstbyhwtype
        WRAP_FOR_DETACH(__dev_getfirstbyhwtype)
#   else
        TYPED_DETACH(__dev_getfirstbyhwtype)
#   endif
#endif
#ifndef CAN_WRAP_arch_disable_smp_support
#   define CAN_WRAP_arch_disable_smp_support 0
#endif
DETACH(arch_disable_smp_support)
#ifndef CAN_WRAP_pnp_release_card_device
#   define CAN_WRAP_pnp_release_card_device 1
#endif
#if CAN_WRAP_pnp_release_card_device
    WRAP_FOR_DETACH(pnp_release_card_device)
#endif
#ifndef CAN_WRAP_scm_fp_dup
#   define CAN_WRAP_scm_fp_dup 1
#endif
#if CAN_WRAP_scm_fp_dup
    WRAP_FOR_DETACH(scm_fp_dup)
#endif
#ifndef CAN_WRAP_devm_free_irq
#   define CAN_WRAP_devm_free_irq 1
#endif
#if CAN_WRAP_devm_free_irq
    WRAP_FOR_DETACH(devm_free_irq)
#endif
#ifndef CAN_WRAP_acpi_pm_device_sleep_state
#   define CAN_WRAP_acpi_pm_device_sleep_state 1
#endif
#if CAN_WRAP_acpi_pm_device_sleep_state
    WRAP_FOR_DETACH(acpi_pm_device_sleep_state)
#endif
#ifndef CAN_WRAP_kthreadd
#   define CAN_WRAP_kthreadd 0
#endif
DETACH(kthreadd)
#ifndef CAN_WRAP_posix_acl_init
#   define CAN_WRAP_posix_acl_init 1
#endif
#if CAN_WRAP_posix_acl_init
    WRAP_FOR_DETACH(posix_acl_init)
#endif
#ifndef CAN_WRAP_handle_level_irq
#   define CAN_WRAP_handle_level_irq 1
#endif
#if CAN_WRAP_handle_level_irq
    WRAP_FOR_DETACH(handle_level_irq)
#endif
#ifndef CAN_WRAP_pci_fixup_cardbus
#   define CAN_WRAP_pci_fixup_cardbus 1
#endif
#if CAN_WRAP_pci_fixup_cardbus
    WRAP_FOR_DETACH(pci_fixup_cardbus)
#endif
#ifndef CAN_WRAP_acpi_isa_irq_to_gsi
#   define CAN_WRAP_acpi_isa_irq_to_gsi 0
#endif
DETACH(acpi_isa_irq_to_gsi)
#ifndef CAN_WRAP_next_zones_zonelist
#   define CAN_WRAP_next_zones_zonelist 1
#endif
#if CAN_WRAP_next_zones_zonelist
    WRAP_FOR_DETACH(next_zones_zonelist)
#endif
#ifndef CAN_WRAP_copy_pte_range
#   define CAN_WRAP_copy_pte_range 1
#endif
#if CAN_WRAP_copy_pte_range
    WRAP_FOR_DETACH(copy_pte_range)
#endif
#ifndef CAN_WRAP_vmalloc_sync_all
#   define CAN_WRAP_vmalloc_sync_all 0
#endif
DETACH(vmalloc_sync_all)
#ifndef CAN_WRAP_input_alloc_absinfo
#   define CAN_WRAP_input_alloc_absinfo 1
#endif
#if CAN_WRAP_input_alloc_absinfo
    WRAP_FOR_DETACH(input_alloc_absinfo)
#endif
#ifndef CAN_WRAP_crypto_unregister_algs
#   define CAN_WRAP_crypto_unregister_algs 1
#endif
#if CAN_WRAP_crypto_unregister_algs
    WRAP_FOR_DETACH(crypto_unregister_algs)
#endif
#ifndef CAN_WRAP_sock_wake_async
#   define CAN_WRAP_sock_wake_async 1
#endif
#if CAN_WRAP_sock_wake_async
    WRAP_FOR_DETACH(sock_wake_async)
#endif
#ifndef CAN_WRAP_submit_bio
#   define CAN_WRAP_submit_bio 1
#endif
#if CAN_WRAP_submit_bio
    WRAP_FOR_DETACH(submit_bio)
#endif
#ifndef CAN_WRAP_blk_queue_end_tag
#   define CAN_WRAP_blk_queue_end_tag 1
#endif
#if CAN_WRAP_blk_queue_end_tag
    WRAP_FOR_DETACH(blk_queue_end_tag)
#endif
#ifndef CAN_WRAP_acpi_os_create_cache
#   define CAN_WRAP_acpi_os_create_cache 0
#endif
DETACH(acpi_os_create_cache)
#ifndef CAN_WRAP_rcu_cpu_stall_reset
#   define CAN_WRAP_rcu_cpu_stall_reset 0
#endif
DETACH(rcu_cpu_stall_reset)
#ifndef CAN_WRAP_calc_load_enter_idle
#   define CAN_WRAP_calc_load_enter_idle 0
#endif
DETACH(calc_load_enter_idle)
#ifndef CAN_WRAP_thaw_workqueues
#   define CAN_WRAP_thaw_workqueues 0
#endif
DETACH(thaw_workqueues)
#ifndef CAN_WRAP__raw_spin_lock_irqsave
#   define CAN_WRAP__raw_spin_lock_irqsave 1
#endif
#if CAN_WRAP__raw_spin_lock_irqsave
    WRAP_FOR_DETACH(_raw_spin_lock_irqsave)
#endif
#ifndef CAN_WRAP_get_random_bytes
#   define CAN_WRAP_get_random_bytes 0
#endif
DETACH(get_random_bytes)
#ifndef CAN_WRAP_call_rcu_bh
#   define CAN_WRAP_call_rcu_bh 1
#endif
#if CAN_WRAP_call_rcu_bh
    WRAP_FOR_DETACH(call_rcu_bh)
#endif
#ifndef CAN_WRAP_acpi_numa_arch_fixup
#   define CAN_WRAP_acpi_numa_arch_fixup 0
#endif
DETACH(acpi_numa_arch_fixup)
#ifndef CAN_WRAP_vm_insert_page
#   define CAN_WRAP_vm_insert_page 1
#endif
#if CAN_WRAP_vm_insert_page
    WRAP_FOR_DETACH(vm_insert_page)
#endif
#ifndef CAN_WRAP_compat_sys_adjtimex
#   define CAN_WRAP_compat_sys_adjtimex 1
#endif
#if CAN_WRAP_compat_sys_adjtimex
    WRAP_FOR_DETACH(compat_sys_adjtimex)
#endif
#ifndef CAN_WRAP_mark_tsc_unstable
#   define CAN_WRAP_mark_tsc_unstable 0
#endif
DETACH(mark_tsc_unstable)
#ifndef CAN_WRAP_class_compat_create_link
#   define CAN_WRAP_class_compat_create_link 1
#endif
#if CAN_WRAP_class_compat_create_link
    WRAP_FOR_DETACH(class_compat_create_link)
#endif
#ifndef CAN_WRAP_acpi_pci_link_free_irq
#   define CAN_WRAP_acpi_pci_link_free_irq 0
#endif
DETACH(acpi_pci_link_free_irq)
#ifndef CAN_WRAP_pcie_aspm_enabled
#   define CAN_WRAP_pcie_aspm_enabled 0
#endif
DETACH(pcie_aspm_enabled)
#ifndef CAN_WRAP_security_task_wait
#   define CAN_WRAP_security_task_wait 1
#endif
#if CAN_WRAP_security_task_wait
    WRAP_FOR_DETACH(security_task_wait)
#endif
#ifndef CAN_WRAP_rps_may_expire_flow
#   define CAN_WRAP_rps_may_expire_flow 1
#endif
#if CAN_WRAP_rps_may_expire_flow
    WRAP_FOR_DETACH(rps_may_expire_flow)
#endif
#ifndef CAN_WRAP_finish_e820_parsing
#   define CAN_WRAP_finish_e820_parsing 0
#endif
DETACH(finish_e820_parsing)
#ifndef CAN_WRAP_inet_twdr_hangman
#   define CAN_WRAP_inet_twdr_hangman 0
#endif
DETACH(inet_twdr_hangman)
#ifndef CAN_WRAP_test_set_page_writeback
#   define CAN_WRAP_test_set_page_writeback 1
#endif
#if CAN_WRAP_test_set_page_writeback
    WRAP_FOR_DETACH(test_set_page_writeback)
#endif
#ifndef CAN_WRAP_reschedule_interrupt
#   define CAN_WRAP_reschedule_interrupt 0
#endif
DETACH(reschedule_interrupt)
#ifndef CAN_WRAP_acpi_os_read_pci_configuration
#   define CAN_WRAP_acpi_os_read_pci_configuration 1
#endif
#if CAN_WRAP_acpi_os_read_pci_configuration
    WRAP_FOR_DETACH(acpi_os_read_pci_configuration)
#endif
#ifndef CAN_WRAP_prandom_bytes_state
#   define CAN_WRAP_prandom_bytes_state 1
#endif
#if CAN_WRAP_prandom_bytes_state
    WRAP_FOR_DETACH(prandom_bytes_state)
#endif
#ifndef CAN_WRAP_irq_setup_generic_chip
#   define CAN_WRAP_irq_setup_generic_chip 1
#endif
#if CAN_WRAP_irq_setup_generic_chip
    WRAP_FOR_DETACH(irq_setup_generic_chip)
#endif
#ifndef CAN_WRAP_mpage_writepage
#   define CAN_WRAP_mpage_writepage 1
#endif
#if CAN_WRAP_mpage_writepage
    WRAP_FOR_DETACH(mpage_writepage)
#endif
#ifndef CAN_WRAP_current_umask
#   define CAN_WRAP_current_umask 0
#endif
DETACH(current_umask)
#ifndef CAN_WRAP_blk_rq_err_bytes
#   define CAN_WRAP_blk_rq_err_bytes 1
#endif
#if CAN_WRAP_blk_rq_err_bytes
    WRAP_FOR_DETACH(blk_rq_err_bytes)
#endif
#ifndef CAN_WRAP_acpi_evaluate_reference
#   define CAN_WRAP_acpi_evaluate_reference 1
#endif
#if CAN_WRAP_acpi_evaluate_reference
    WRAP_FOR_DETACH(acpi_evaluate_reference)
#endif
#ifndef CAN_WRAP_input_grab_device
#   define CAN_WRAP_input_grab_device 1
#endif
#if CAN_WRAP_input_grab_device
    WRAP_FOR_DETACH(input_grab_device)
#endif
#ifndef CAN_WRAP___nla_put
#   define CAN_WRAP___nla_put 1
#endif
#if CAN_WRAP___nla_put
#   ifdef DETACH_ADDR___nla_put
        WRAP_FOR_DETACH(__nla_put)
#   else
        TYPED_DETACH(__nla_put)
#   endif
#endif
#ifndef CAN_WRAP_generic_fillattr
#   define CAN_WRAP_generic_fillattr 1
#endif
#if CAN_WRAP_generic_fillattr
    WRAP_FOR_DETACH(generic_fillattr)
#endif
#ifndef CAN_WRAP_ntp_clear
#   define CAN_WRAP_ntp_clear 0
#endif
DETACH(ntp_clear)
#ifndef CAN_WRAP_register_timer_hook
#   define CAN_WRAP_register_timer_hook 1
#endif
#if CAN_WRAP_register_timer_hook
    WRAP_FOR_DETACH(register_timer_hook)
#endif
#ifndef CAN_WRAP_acpi_walk_resources
#   define CAN_WRAP_acpi_walk_resources 1
#endif
#if CAN_WRAP_acpi_walk_resources
    WRAP_FOR_DETACH(acpi_walk_resources)
#endif
#ifndef CAN_WRAP_done_path_create
#   define CAN_WRAP_done_path_create 1
#endif
#if CAN_WRAP_done_path_create
    WRAP_FOR_DETACH(done_path_create)
#endif
#ifndef CAN_WRAP_mntget
#   define CAN_WRAP_mntget 1
#endif
#if CAN_WRAP_mntget
    WRAP_FOR_DETACH(mntget)
#endif
#ifndef CAN_WRAP_rt_mutex_destroy
#   define CAN_WRAP_rt_mutex_destroy 1
#endif
#if CAN_WRAP_rt_mutex_destroy
    WRAP_FOR_DETACH(rt_mutex_destroy)
#endif
#ifndef CAN_WRAP_disable_irq_nosync
#   define CAN_WRAP_disable_irq_nosync 0
#endif
DETACH(disable_irq_nosync)
#ifndef CAN_WRAP_mnt_want_write
#   define CAN_WRAP_mnt_want_write 1
#endif
#if CAN_WRAP_mnt_want_write
    WRAP_FOR_DETACH(mnt_want_write)
#endif
#ifndef CAN_WRAP_do_sigaltstack
#   define CAN_WRAP_do_sigaltstack 1
#endif
#if CAN_WRAP_do_sigaltstack
    WRAP_FOR_DETACH(do_sigaltstack)
#endif
#ifndef CAN_WRAP_up
#   define CAN_WRAP_up 1
#endif
#if CAN_WRAP_up
    WRAP_FOR_DETACH(up)
#endif
#ifndef CAN_WRAP_devres_release_group
#   define CAN_WRAP_devres_release_group 1
#endif
#if CAN_WRAP_devres_release_group
    WRAP_FOR_DETACH(devres_release_group)
#endif
#ifndef CAN_WRAP_qdisc_put_stab
#   define CAN_WRAP_qdisc_put_stab 1
#endif
#if CAN_WRAP_qdisc_put_stab
    WRAP_FOR_DETACH(qdisc_put_stab)
#endif
#ifndef CAN_WRAP_security_inode_post_setxattr
#   define CAN_WRAP_security_inode_post_setxattr 1
#endif
#if CAN_WRAP_security_inode_post_setxattr
    WRAP_FOR_DETACH(security_inode_post_setxattr)
#endif
#ifndef CAN_WRAP_acpi_install_gpe_handler
#   define CAN_WRAP_acpi_install_gpe_handler 1
#endif
#if CAN_WRAP_acpi_install_gpe_handler
    WRAP_FOR_DETACH(acpi_install_gpe_handler)
#endif
#ifndef CAN_WRAP_pm_generic_thaw_noirq
#   define CAN_WRAP_pm_generic_thaw_noirq 1
#endif
#if CAN_WRAP_pm_generic_thaw_noirq
    WRAP_FOR_DETACH(pm_generic_thaw_noirq)
#endif
#ifndef CAN_WRAP_irq_gc_set_wake
#   define CAN_WRAP_irq_gc_set_wake 1
#endif
#if CAN_WRAP_irq_gc_set_wake
    WRAP_FOR_DETACH(irq_gc_set_wake)
#endif
#ifndef CAN_WRAP_dm_create
#   define CAN_WRAP_dm_create 0
#endif
DETACH(dm_create)
#ifndef CAN_WRAP_jbd2_journal_set_triggers
#   define CAN_WRAP_jbd2_journal_set_triggers 1
#endif
#if CAN_WRAP_jbd2_journal_set_triggers
    WRAP_FOR_DETACH(jbd2_journal_set_triggers)
#endif
#ifndef CAN_WRAP_arch_irq_stat_cpu
#   define CAN_WRAP_arch_irq_stat_cpu 0
#endif
DETACH(arch_irq_stat_cpu)
#ifndef CAN_WRAP___srcu_read_unlock
#   define CAN_WRAP___srcu_read_unlock 1
#endif
#if CAN_WRAP___srcu_read_unlock
#   ifdef DETACH_ADDR___srcu_read_unlock
        WRAP_FOR_DETACH(__srcu_read_unlock)
#   else
        TYPED_DETACH(__srcu_read_unlock)
#   endif
#endif
#ifndef CAN_WRAP_get_next_ino
#   define CAN_WRAP_get_next_ino 0
#endif
DETACH(get_next_ino)
#ifndef CAN_WRAP_free_anon_bdev
#   define CAN_WRAP_free_anon_bdev 0
#endif
DETACH(free_anon_bdev)
#ifndef CAN_WRAP_acpi_acquire_global_lock
#   define CAN_WRAP_acpi_acquire_global_lock 0
#endif
DETACH(acpi_acquire_global_lock)
#ifndef CAN_WRAP_insert_resource
#   define CAN_WRAP_insert_resource 1
#endif
#if CAN_WRAP_insert_resource
    WRAP_FOR_DETACH(insert_resource)
#endif
#ifndef CAN_WRAP_pci_request_region
#   define CAN_WRAP_pci_request_region 1
#endif
#if CAN_WRAP_pci_request_region
    WRAP_FOR_DETACH(pci_request_region)
#endif
#ifndef CAN_WRAP_find_task_by_pid_ns
#   define CAN_WRAP_find_task_by_pid_ns 1
#endif
#if CAN_WRAP_find_task_by_pid_ns
    WRAP_FOR_DETACH(find_task_by_pid_ns)
#endif
#ifndef CAN_WRAP_ata_pack_xfermask
#   define CAN_WRAP_ata_pack_xfermask 0
#endif
DETACH(ata_pack_xfermask)
#ifndef CAN_WRAP___release_region
#   define CAN_WRAP___release_region 1
#endif
#if CAN_WRAP___release_region
#   ifdef DETACH_ADDR___release_region
        WRAP_FOR_DETACH(__release_region)
#   else
        TYPED_DETACH(__release_region)
#   endif
#endif
#ifndef CAN_WRAP___jbd2_log_wait_for_space
#   define CAN_WRAP___jbd2_log_wait_for_space 1
#endif
#if CAN_WRAP___jbd2_log_wait_for_space
#   ifdef DETACH_ADDR___jbd2_log_wait_for_space
        WRAP_FOR_DETACH(__jbd2_log_wait_for_space)
#   else
        TYPED_DETACH(__jbd2_log_wait_for_space)
#   endif
#endif
#ifndef CAN_WRAP_security_release_secctx
#   define CAN_WRAP_security_release_secctx 0
#endif
DETACH(security_release_secctx)
#ifndef CAN_WRAP_inet_frags_exit_net
#   define CAN_WRAP_inet_frags_exit_net 1
#endif
#if CAN_WRAP_inet_frags_exit_net
    WRAP_FOR_DETACH(inet_frags_exit_net)
#endif
#ifndef CAN_WRAP_calc_load_exit_idle
#   define CAN_WRAP_calc_load_exit_idle 0
#endif
DETACH(calc_load_exit_idle)
#ifndef CAN_WRAP_do_sync_write
#   define CAN_WRAP_do_sync_write 1
#endif
#if CAN_WRAP_do_sync_write
    WRAP_FOR_DETACH(do_sync_write)
#endif
#ifndef CAN_WRAP_stop_this_cpu
#   define CAN_WRAP_stop_this_cpu 0
#endif
DETACH(stop_this_cpu)
#ifndef CAN_WRAP___usermodehelper_disable
#   define CAN_WRAP___usermodehelper_disable 0
#endif
DETACH(__usermodehelper_disable)
#ifndef CAN_WRAP_core_sys_select
#   define CAN_WRAP_core_sys_select 1
#endif
#if CAN_WRAP_core_sys_select
    WRAP_FOR_DETACH(core_sys_select)
#endif
#ifndef CAN_WRAP_vma_interval_tree_iter_first
#   define CAN_WRAP_vma_interval_tree_iter_first 1
#endif
#if CAN_WRAP_vma_interval_tree_iter_first
    WRAP_FOR_DETACH(vma_interval_tree_iter_first)
#endif
#ifndef CAN_WRAP_drain_all_pages
#   define CAN_WRAP_drain_all_pages 0
#endif
DETACH(drain_all_pages)
#ifndef CAN_WRAP_class_compat_unregister
#   define CAN_WRAP_class_compat_unregister 1
#endif
#if CAN_WRAP_class_compat_unregister
    WRAP_FOR_DETACH(class_compat_unregister)
#endif
#ifndef CAN_WRAP_proc_dointvec_minmax
#   define CAN_WRAP_proc_dointvec_minmax 1
#endif
#if CAN_WRAP_proc_dointvec_minmax
    WRAP_FOR_DETACH(proc_dointvec_minmax)
#endif
#ifndef CAN_WRAP_tsc_restore_sched_clock_state
#   define CAN_WRAP_tsc_restore_sched_clock_state 0
#endif
DETACH(tsc_restore_sched_clock_state)
#ifndef CAN_WRAP_dentry_path
#   define CAN_WRAP_dentry_path 1
#endif
#if CAN_WRAP_dentry_path
    WRAP_FOR_DETACH(dentry_path)
#endif
#ifndef CAN_WRAP_scsi_host_alloc
#   define CAN_WRAP_scsi_host_alloc 1
#endif
#if CAN_WRAP_scsi_host_alloc
    WRAP_FOR_DETACH(scsi_host_alloc)
#endif
#ifndef CAN_WRAP_param_set_copystring
#   define CAN_WRAP_param_set_copystring 1
#endif
#if CAN_WRAP_param_set_copystring
    WRAP_FOR_DETACH(param_set_copystring)
#endif
#ifndef CAN_WRAP_kthread_worker_fn
#   define CAN_WRAP_kthread_worker_fn 0
#endif
DETACH(kthread_worker_fn)
#ifndef CAN_WRAP_dirty_background_bytes_handler
#   define CAN_WRAP_dirty_background_bytes_handler 1
#endif
#if CAN_WRAP_dirty_background_bytes_handler
    WRAP_FOR_DETACH(dirty_background_bytes_handler)
#endif
#ifndef CAN_WRAP_jbd2_journal_start
#   define CAN_WRAP_jbd2_journal_start 1
#endif
#if CAN_WRAP_jbd2_journal_start
    WRAP_FOR_DETACH(jbd2_journal_start)
#endif
#ifndef CAN_WRAP_compat_sys_migrate_pages
#   define CAN_WRAP_compat_sys_migrate_pages 0
#endif
DETACH(compat_sys_migrate_pages)
#ifndef CAN_WRAP_nr_iowait
#   define CAN_WRAP_nr_iowait 0
#endif
DETACH(nr_iowait)
#ifndef CAN_WRAP_hrtimer_cancel
#   define CAN_WRAP_hrtimer_cancel 1
#endif
#if CAN_WRAP_hrtimer_cancel
    WRAP_FOR_DETACH(hrtimer_cancel)
#endif
#ifndef CAN_WRAP_timecounter_cyc2time
#   define CAN_WRAP_timecounter_cyc2time 1
#endif
#if CAN_WRAP_timecounter_cyc2time
    WRAP_FOR_DETACH(timecounter_cyc2time)
#endif
#ifndef CAN_WRAP_paravirt_patch_insns
#   define CAN_WRAP_paravirt_patch_insns 0
#endif
DETACH(paravirt_patch_insns)
#ifndef CAN_WRAP_icmpv6_init
#   define CAN_WRAP_icmpv6_init 0
#endif
DETACH(icmpv6_init)
#ifndef CAN_WRAP_jbd2_free
#   define CAN_WRAP_jbd2_free 0
#endif
DETACH(jbd2_free)
#ifndef CAN_WRAP_kobject_create_and_add
#   define CAN_WRAP_kobject_create_and_add 1
#endif
#if CAN_WRAP_kobject_create_and_add
    WRAP_FOR_DETACH(kobject_create_and_add)
#endif
#ifndef CAN_WRAP_vmalloc_32_user
#   define CAN_WRAP_vmalloc_32_user 0
#endif
DETACH(vmalloc_32_user)
#ifndef CAN_WRAP_compat_sys_statfs64
#   define CAN_WRAP_compat_sys_statfs64 1
#endif
#if CAN_WRAP_compat_sys_statfs64
    WRAP_FOR_DETACH(compat_sys_statfs64)
#endif
#ifndef CAN_WRAP_sock_rfree
#   define CAN_WRAP_sock_rfree 1
#endif
#if CAN_WRAP_sock_rfree
    WRAP_FOR_DETACH(sock_rfree)
#endif
#ifndef CAN_WRAP_nf_register_hook
#   define CAN_WRAP_nf_register_hook 1
#endif
#if CAN_WRAP_nf_register_hook
    WRAP_FOR_DETACH(nf_register_hook)
#endif
#ifndef CAN_WRAP_unmap_kernel_range
#   define CAN_WRAP_unmap_kernel_range 0
#endif
DETACH(unmap_kernel_range)
#ifndef CAN_WRAP_security_unix_may_send
#   define CAN_WRAP_security_unix_may_send 1
#endif
#if CAN_WRAP_security_unix_may_send
    WRAP_FOR_DETACH(security_unix_may_send)
#endif
#ifndef CAN_WRAP_seq_putc
#   define CAN_WRAP_seq_putc 1
#endif
#if CAN_WRAP_seq_putc
    WRAP_FOR_DETACH(seq_putc)
#endif
#ifndef CAN_WRAP_get_compat_timespec
#   define CAN_WRAP_get_compat_timespec 1
#endif
#if CAN_WRAP_get_compat_timespec
    WRAP_FOR_DETACH(get_compat_timespec)
#endif
#ifndef CAN_WRAP_task_clear_jobctl_pending
#   define CAN_WRAP_task_clear_jobctl_pending 1
#endif
#if CAN_WRAP_task_clear_jobctl_pending
    WRAP_FOR_DETACH(task_clear_jobctl_pending)
#endif
#ifndef CAN_WRAP_seq_puts
#   define CAN_WRAP_seq_puts 1
#endif
#if CAN_WRAP_seq_puts
    WRAP_FOR_DETACH(seq_puts)
#endif
#ifndef CAN_WRAP_acpi_os_delete_semaphore
#   define CAN_WRAP_acpi_os_delete_semaphore 0
#endif
DETACH(acpi_os_delete_semaphore)
#ifndef CAN_WRAP_compat_sys_timer_create
#   define CAN_WRAP_compat_sys_timer_create 1
#endif
#if CAN_WRAP_compat_sys_timer_create
    WRAP_FOR_DETACH(compat_sys_timer_create)
#endif
#ifndef CAN_WRAP_dql_init
#   define CAN_WRAP_dql_init 1
#endif
#if CAN_WRAP_dql_init
    WRAP_FOR_DETACH(dql_init)
#endif
#ifndef CAN_WRAP_skb_copy_and_csum_datagram_iovec
#   define CAN_WRAP_skb_copy_and_csum_datagram_iovec 1
#endif
#if CAN_WRAP_skb_copy_and_csum_datagram_iovec
    WRAP_FOR_DETACH(skb_copy_and_csum_datagram_iovec)
#endif
#ifndef CAN_WRAP_sk_send_sigurg
#   define CAN_WRAP_sk_send_sigurg 1
#endif
#if CAN_WRAP_sk_send_sigurg
    WRAP_FOR_DETACH(sk_send_sigurg)
#endif
#ifndef CAN_WRAP_simple_lookup
#   define CAN_WRAP_simple_lookup 1
#endif
#if CAN_WRAP_simple_lookup
    WRAP_FOR_DETACH(simple_lookup)
#endif
#ifndef CAN_WRAP_dm_uevent_add
#   define CAN_WRAP_dm_uevent_add 1
#endif
#if CAN_WRAP_dm_uevent_add
    WRAP_FOR_DETACH(dm_uevent_add)
#endif
#ifndef CAN_WRAP_get_tsc_mode
#   define CAN_WRAP_get_tsc_mode 0
#endif
DETACH(get_tsc_mode)
#ifndef CAN_WRAP_dm_noflush_suspending
#   define CAN_WRAP_dm_noflush_suspending 1
#endif
#if CAN_WRAP_dm_noflush_suspending
    WRAP_FOR_DETACH(dm_noflush_suspending)
#endif
#ifndef CAN_WRAP_compat_sys_sendfile
#   define CAN_WRAP_compat_sys_sendfile 0
#endif
DETACH(compat_sys_sendfile)
#ifndef CAN_WRAP_device_show_int
#   define CAN_WRAP_device_show_int 1
#endif
#if CAN_WRAP_device_show_int
    WRAP_FOR_DETACH(device_show_int)
#endif
#ifndef CAN_WRAP_truncate_inode_page
#   define CAN_WRAP_truncate_inode_page 1
#endif
#if CAN_WRAP_truncate_inode_page
    WRAP_FOR_DETACH(truncate_inode_page)
#endif
#ifndef CAN_WRAP_early_memremap
#   define CAN_WRAP_early_memremap 0
#endif
DETACH(early_memremap)
#ifndef CAN_WRAP_dm_get
#   define CAN_WRAP_dm_get 1
#endif
#if CAN_WRAP_dm_get
    WRAP_FOR_DETACH(dm_get)
#endif
#ifndef CAN_WRAP_compat_sys_move_pages
#   define CAN_WRAP_compat_sys_move_pages 0
#endif
DETACH(compat_sys_move_pages)
#ifndef CAN_WRAP_rcu_bh_force_quiescent_state
#   define CAN_WRAP_rcu_bh_force_quiescent_state 0
#endif
DETACH(rcu_bh_force_quiescent_state)
#ifndef CAN_WRAP___dev_pm_qos_flags
#   define CAN_WRAP___dev_pm_qos_flags 1
#endif
#if CAN_WRAP___dev_pm_qos_flags
#   ifdef DETACH_ADDR___dev_pm_qos_flags
        WRAP_FOR_DETACH(__dev_pm_qos_flags)
#   else
        TYPED_DETACH(__dev_pm_qos_flags)
#   endif
#endif
#ifndef CAN_WRAP_blk_set_stacking_limits
#   define CAN_WRAP_blk_set_stacking_limits 1
#endif
#if CAN_WRAP_blk_set_stacking_limits
    WRAP_FOR_DETACH(blk_set_stacking_limits)
#endif
#ifndef CAN_WRAP_dcache_dir_open
#   define CAN_WRAP_dcache_dir_open 1
#endif
#if CAN_WRAP_dcache_dir_open
    WRAP_FOR_DETACH(dcache_dir_open)
#endif
#ifndef CAN_WRAP_pci_bus_alloc_resource
#   define CAN_WRAP_pci_bus_alloc_resource 1
#endif
#if CAN_WRAP_pci_bus_alloc_resource
    WRAP_FOR_DETACH(pci_bus_alloc_resource)
#endif
#ifndef CAN_WRAP_native_play_dead
#   define CAN_WRAP_native_play_dead 0
#endif
DETACH(native_play_dead)
#ifndef CAN_WRAP_acpi_os_hotplug_execute
#   define CAN_WRAP_acpi_os_hotplug_execute 1
#endif
#if CAN_WRAP_acpi_os_hotplug_execute
    WRAP_FOR_DETACH(acpi_os_hotplug_execute)
#endif
#ifndef CAN_WRAP_pci_bus_resource_n
#   define CAN_WRAP_pci_bus_resource_n 1
#endif
#if CAN_WRAP_pci_bus_resource_n
    WRAP_FOR_DETACH(pci_bus_resource_n)
#endif
#ifndef CAN_WRAP___find_get_block
#   define CAN_WRAP___find_get_block 1
#endif
#if CAN_WRAP___find_get_block
#   ifdef DETACH_ADDR___find_get_block
        WRAP_FOR_DETACH(__find_get_block)
#   else
        TYPED_DETACH(__find_get_block)
#   endif
#endif
#ifndef CAN_WRAP_free_pgd_range
#   define CAN_WRAP_free_pgd_range 1
#endif
#if CAN_WRAP_free_pgd_range
    WRAP_FOR_DETACH(free_pgd_range)
#endif
#ifndef CAN_WRAP_free_bootmem_with_active_regions
#   define CAN_WRAP_free_bootmem_with_active_regions 0
#endif
DETACH(free_bootmem_with_active_regions)
#ifndef CAN_WRAP_pci_disable_rom
#   define CAN_WRAP_pci_disable_rom 1
#endif
#if CAN_WRAP_pci_disable_rom
    WRAP_FOR_DETACH(pci_disable_rom)
#endif
#ifndef CAN_WRAP_sched_group_set_shares
#   define CAN_WRAP_sched_group_set_shares 1
#endif
#if CAN_WRAP_sched_group_set_shares
    WRAP_FOR_DETACH(sched_group_set_shares)
#endif
#ifndef CAN_WRAP_sock_wfree
#   define CAN_WRAP_sock_wfree 1
#endif
#if CAN_WRAP_sock_wfree
    WRAP_FOR_DETACH(sock_wfree)
#endif
#ifndef CAN_WRAP_security_sock_rcv_skb
#   define CAN_WRAP_security_sock_rcv_skb 1
#endif
#if CAN_WRAP_security_sock_rcv_skb
    WRAP_FOR_DETACH(security_sock_rcv_skb)
#endif
#ifndef CAN_WRAP_disk_map_sector_rcu
#   define CAN_WRAP_disk_map_sector_rcu 1
#endif
#if CAN_WRAP_disk_map_sector_rcu
    WRAP_FOR_DETACH(disk_map_sector_rcu)
#endif
#ifndef CAN_WRAP_acpi_get_devices
#   define CAN_WRAP_acpi_get_devices 1
#endif
#if CAN_WRAP_acpi_get_devices
    WRAP_FOR_DETACH(acpi_get_devices)
#endif
#ifndef CAN_WRAP_pci_clear_mwi
#   define CAN_WRAP_pci_clear_mwi 1
#endif
#if CAN_WRAP_pci_clear_mwi
    WRAP_FOR_DETACH(pci_clear_mwi)
#endif
#ifndef CAN_WRAP_compat_sys_msgsnd
#   define CAN_WRAP_compat_sys_msgsnd 0
#endif
DETACH(compat_sys_msgsnd)
#ifndef CAN_WRAP___kfree_skb
#   define CAN_WRAP___kfree_skb 1
#endif
#if CAN_WRAP___kfree_skb
#   ifdef DETACH_ADDR___kfree_skb
        WRAP_FOR_DETACH(__kfree_skb)
#   else
        TYPED_DETACH(__kfree_skb)
#   endif
#endif
#ifndef CAN_WRAP_sysfs_remove_group
#   define CAN_WRAP_sysfs_remove_group 1
#endif
#if CAN_WRAP_sysfs_remove_group
    WRAP_FOR_DETACH(sysfs_remove_group)
#endif
#ifndef CAN_WRAP_security_sem_free
#   define CAN_WRAP_security_sem_free 1
#endif
#if CAN_WRAP_security_sem_free
    WRAP_FOR_DETACH(security_sem_free)
#endif
#ifndef CAN_WRAP_elv_requeue_request
#   define CAN_WRAP_elv_requeue_request 1
#endif
#if CAN_WRAP_elv_requeue_request
    WRAP_FOR_DETACH(elv_requeue_request)
#endif
#ifndef CAN_WRAP_jbd2_journal_init_inode
#   define CAN_WRAP_jbd2_journal_init_inode 1
#endif
#if CAN_WRAP_jbd2_journal_init_inode
    WRAP_FOR_DETACH(jbd2_journal_init_inode)
#endif
#ifndef CAN_WRAP_pci_sort_breadthfirst
#   define CAN_WRAP_pci_sort_breadthfirst 0
#endif
DETACH(pci_sort_breadthfirst)
#ifndef CAN_WRAP___netdev_update_features
#   define CAN_WRAP___netdev_update_features 1
#endif
#if CAN_WRAP___netdev_update_features
#   ifdef DETACH_ADDR___netdev_update_features
        WRAP_FOR_DETACH(__netdev_update_features)
#   else
        TYPED_DETACH(__netdev_update_features)
#   endif
#endif
#ifndef CAN_WRAP_get_user_pages_fast
#   define CAN_WRAP_get_user_pages_fast 0
#endif
DETACH(get_user_pages_fast)
#ifndef CAN_WRAP_setup_nr_cpu_ids
#   define CAN_WRAP_setup_nr_cpu_ids 0
#endif
DETACH(setup_nr_cpu_ids)
#ifndef CAN_WRAP_simple_strtoull
#   define CAN_WRAP_simple_strtoull 0
#endif
DETACH(simple_strtoull)
#ifndef CAN_WRAP_security_sk_classify_flow
#   define CAN_WRAP_security_sk_classify_flow 1
#endif
#if CAN_WRAP_security_sk_classify_flow
    WRAP_FOR_DETACH(security_sk_classify_flow)
#endif
#ifndef CAN_WRAP_napi_get_frags
#   define CAN_WRAP_napi_get_frags 1
#endif
#if CAN_WRAP_napi_get_frags
    WRAP_FOR_DETACH(napi_get_frags)
#endif
#ifndef CAN_WRAP_set_cpus_allowed_ptr
#   define CAN_WRAP_set_cpus_allowed_ptr 1
#endif
#if CAN_WRAP_set_cpus_allowed_ptr
    WRAP_FOR_DETACH(set_cpus_allowed_ptr)
#endif
#ifndef CAN_WRAP_ata_sff_wait_after_reset
#   define CAN_WRAP_ata_sff_wait_after_reset 1
#endif
#if CAN_WRAP_ata_sff_wait_after_reset
    WRAP_FOR_DETACH(ata_sff_wait_after_reset)
#endif
#ifndef CAN_WRAP_ata_qc_complete
#   define CAN_WRAP_ata_qc_complete 1
#endif
#if CAN_WRAP_ata_qc_complete
    WRAP_FOR_DETACH(ata_qc_complete)
#endif
#ifndef CAN_WRAP_pci_swiotlb_detect_4gb
#   define CAN_WRAP_pci_swiotlb_detect_4gb 0
#endif
DETACH(pci_swiotlb_detect_4gb)
#ifndef CAN_WRAP_device_bind_driver
#   define CAN_WRAP_device_bind_driver 1
#endif
#if CAN_WRAP_device_bind_driver
    WRAP_FOR_DETACH(device_bind_driver)
#endif
#ifndef CAN_WRAP_scsi_cmd_blk_ioctl
#   define CAN_WRAP_scsi_cmd_blk_ioctl 1
#endif
#if CAN_WRAP_scsi_cmd_blk_ioctl
    WRAP_FOR_DETACH(scsi_cmd_blk_ioctl)
#endif
#ifndef CAN_WRAP_driver_unregister
#   define CAN_WRAP_driver_unregister 1
#endif
#if CAN_WRAP_driver_unregister
    WRAP_FOR_DETACH(driver_unregister)
#endif
#ifndef CAN_WRAP_rtnl_set_sk_err
#   define CAN_WRAP_rtnl_set_sk_err 1
#endif
#if CAN_WRAP_rtnl_set_sk_err
    WRAP_FOR_DETACH(rtnl_set_sk_err)
#endif
#ifndef CAN_WRAP_vmemmap_pte_populate
#   define CAN_WRAP_vmemmap_pte_populate 1
#endif
#if CAN_WRAP_vmemmap_pte_populate
    WRAP_FOR_DETACH(vmemmap_pte_populate)
#endif
#ifndef CAN_WRAP_acpi_pci_bind_root
#   define CAN_WRAP_acpi_pci_bind_root 1
#endif
#if CAN_WRAP_acpi_pci_bind_root
    WRAP_FOR_DETACH(acpi_pci_bind_root)
#endif
#ifndef CAN_WRAP_rcu_batches_completed
#   define CAN_WRAP_rcu_batches_completed 0
#endif
DETACH(rcu_batches_completed)
#ifndef CAN_WRAP_init_srcu_struct
#   define CAN_WRAP_init_srcu_struct 1
#endif
#if CAN_WRAP_init_srcu_struct
    WRAP_FOR_DETACH(init_srcu_struct)
#endif
#ifndef CAN_WRAP_scsi_register
#   define CAN_WRAP_scsi_register 1
#endif
#if CAN_WRAP_scsi_register
    WRAP_FOR_DETACH(scsi_register)
#endif
#ifndef CAN_WRAP_stable_page_flags
#   define CAN_WRAP_stable_page_flags 1
#endif
#if CAN_WRAP_stable_page_flags
    WRAP_FOR_DETACH(stable_page_flags)
#endif
#ifndef CAN_WRAP_neigh_ifdown
#   define CAN_WRAP_neigh_ifdown 1
#endif
#if CAN_WRAP_neigh_ifdown
    WRAP_FOR_DETACH(neigh_ifdown)
#endif
#ifndef CAN_WRAP_neigh_parms_release
#   define CAN_WRAP_neigh_parms_release 1
#endif
#if CAN_WRAP_neigh_parms_release
    WRAP_FOR_DETACH(neigh_parms_release)
#endif
#ifndef CAN_WRAP___scsi_alloc_queue
#   define CAN_WRAP___scsi_alloc_queue 1
#endif
#if CAN_WRAP___scsi_alloc_queue
#   ifdef DETACH_ADDR___scsi_alloc_queue
        WRAP_FOR_DETACH(__scsi_alloc_queue)
#   else
        TYPED_DETACH(__scsi_alloc_queue)
#   endif
#endif
#ifndef CAN_WRAP_paravirt_patch_nop
#   define CAN_WRAP_paravirt_patch_nop 0
#endif
DETACH(paravirt_patch_nop)
#ifndef CAN_WRAP_security_msg_msg_alloc
#   define CAN_WRAP_security_msg_msg_alloc 1
#endif
#if CAN_WRAP_security_msg_msg_alloc
    WRAP_FOR_DETACH(security_msg_msg_alloc)
#endif
#ifndef CAN_WRAP_tracepoint_probe_register
#   define CAN_WRAP_tracepoint_probe_register 0
#endif
DETACH(tracepoint_probe_register)
#ifndef CAN_WRAP_bio_endio
#   define CAN_WRAP_bio_endio 1
#endif
#if CAN_WRAP_bio_endio
    WRAP_FOR_DETACH(bio_endio)
#endif
#ifndef CAN_WRAP_jbd2_journal_begin_ordered_truncate
#   define CAN_WRAP_jbd2_journal_begin_ordered_truncate 1
#endif
#if CAN_WRAP_jbd2_journal_begin_ordered_truncate
    WRAP_FOR_DETACH(jbd2_journal_begin_ordered_truncate)
#endif
#ifndef CAN_WRAP_disable_IO_APIC
#   define CAN_WRAP_disable_IO_APIC 0
#endif
DETACH(disable_IO_APIC)
#ifndef CAN_WRAP_prepare_creds
#   define CAN_WRAP_prepare_creds 1
#endif
#if CAN_WRAP_prepare_creds
    WRAP_FOR_DETACH(prepare_creds)
#endif
#ifndef CAN_WRAP_netif_device_attach
#   define CAN_WRAP_netif_device_attach 1
#endif
#if CAN_WRAP_netif_device_attach
    WRAP_FOR_DETACH(netif_device_attach)
#endif
#ifndef CAN_WRAP_pci_vpd_find_tag
#   define CAN_WRAP_pci_vpd_find_tag 0
#endif
DETACH(pci_vpd_find_tag)
#ifndef CAN_WRAP_sysfs_create_files
#   define CAN_WRAP_sysfs_create_files 1
#endif
#if CAN_WRAP_sysfs_create_files
    WRAP_FOR_DETACH(sysfs_create_files)
#endif
#ifndef CAN_WRAP_swiotlb_free_coherent
#   define CAN_WRAP_swiotlb_free_coherent 1
#endif
#if CAN_WRAP_swiotlb_free_coherent
    WRAP_FOR_DETACH(swiotlb_free_coherent)
#endif
#ifndef CAN_WRAP_ramfs_mount
#   define CAN_WRAP_ramfs_mount 1
#endif
#if CAN_WRAP_ramfs_mount
    WRAP_FOR_DETACH(ramfs_mount)
#endif
#ifndef CAN_WRAP_input_close_device
#   define CAN_WRAP_input_close_device 1
#endif
#if CAN_WRAP_input_close_device
    WRAP_FOR_DETACH(input_close_device)
#endif
#ifndef CAN_WRAP_dirty_background_ratio_handler
#   define CAN_WRAP_dirty_background_ratio_handler 1
#endif
#if CAN_WRAP_dirty_background_ratio_handler
    WRAP_FOR_DETACH(dirty_background_ratio_handler)
#endif
#ifndef CAN_WRAP_mod_timer_pending
#   define CAN_WRAP_mod_timer_pending 1
#endif
#if CAN_WRAP_mod_timer_pending
    WRAP_FOR_DETACH(mod_timer_pending)
#endif
#ifndef CAN_WRAP_kobject_uevent
#   define CAN_WRAP_kobject_uevent 1
#endif
#if CAN_WRAP_kobject_uevent
    WRAP_FOR_DETACH(kobject_uevent)
#endif
#ifndef CAN_WRAP_nsecs_to_jiffies64
#   define CAN_WRAP_nsecs_to_jiffies64 0
#endif
DETACH(nsecs_to_jiffies64)
#ifndef CAN_WRAP_skb_init
#   define CAN_WRAP_skb_init 0
#endif
DETACH(skb_init)
#ifndef CAN_WRAP_memcpy_toiovecend
#   define CAN_WRAP_memcpy_toiovecend 1
#endif
#if CAN_WRAP_memcpy_toiovecend
    WRAP_FOR_DETACH(memcpy_toiovecend)
#endif
#ifndef CAN_WRAP_getname
#   define CAN_WRAP_getname 1
#endif
#if CAN_WRAP_getname
    WRAP_FOR_DETACH(getname)
#endif
#ifndef CAN_WRAP_elv_register_queue
#   define CAN_WRAP_elv_register_queue 1
#endif
#if CAN_WRAP_elv_register_queue
    WRAP_FOR_DETACH(elv_register_queue)
#endif
#ifndef CAN_WRAP_set_groups
#   define CAN_WRAP_set_groups 1
#endif
#if CAN_WRAP_set_groups
    WRAP_FOR_DETACH(set_groups)
#endif
#ifndef CAN_WRAP_register_refined_jiffies
#   define CAN_WRAP_register_refined_jiffies 0
#endif
DETACH(register_refined_jiffies)
#ifndef CAN_WRAP_synchronize_rcu_bh
#   define CAN_WRAP_synchronize_rcu_bh 0
#endif
DETACH(synchronize_rcu_bh)
#ifndef CAN_WRAP_poll_initwait
#   define CAN_WRAP_poll_initwait 1
#endif
#if CAN_WRAP_poll_initwait
    WRAP_FOR_DETACH(poll_initwait)
#endif
#ifndef CAN_WRAP_kzfree
#   define CAN_WRAP_kzfree 0
#endif
DETACH(kzfree)
#ifndef CAN_WRAP_get_pfn_range_for_nid
#   define CAN_WRAP_get_pfn_range_for_nid 0
#endif
DETACH(get_pfn_range_for_nid)
#ifndef CAN_WRAP_sysfs_rename_dir
#   define CAN_WRAP_sysfs_rename_dir 1
#endif
#if CAN_WRAP_sysfs_rename_dir
    WRAP_FOR_DETACH(sysfs_rename_dir)
#endif
#ifndef CAN_WRAP_show_free_areas
#   define CAN_WRAP_show_free_areas 0
#endif
DETACH(show_free_areas)
#ifndef CAN_WRAP_device_move
#   define CAN_WRAP_device_move 1
#endif
#if CAN_WRAP_device_move
    WRAP_FOR_DETACH(device_move)
#endif
#ifndef CAN_WRAP_blkdev_get_by_dev
#   define CAN_WRAP_blkdev_get_by_dev 1
#endif
#if CAN_WRAP_blkdev_get_by_dev
    WRAP_FOR_DETACH(blkdev_get_by_dev)
#endif
#ifndef CAN_WRAP___inc_zone_state
#   define CAN_WRAP___inc_zone_state 1
#endif
#if CAN_WRAP___inc_zone_state
#   ifdef DETACH_ADDR___inc_zone_state
        WRAP_FOR_DETACH(__inc_zone_state)
#   else
        TYPED_DETACH(__inc_zone_state)
#   endif
#endif
#ifndef CAN_WRAP_ata_sas_async_probe
#   define CAN_WRAP_ata_sas_async_probe 1
#endif
#if CAN_WRAP_ata_sas_async_probe
    WRAP_FOR_DETACH(ata_sas_async_probe)
#endif
#ifndef CAN_WRAP_key_validate
#   define CAN_WRAP_key_validate 1
#endif
#if CAN_WRAP_key_validate
    WRAP_FOR_DETACH(key_validate)
#endif
#ifndef CAN_WRAP_pci_find_next_bus
#   define CAN_WRAP_pci_find_next_bus 1
#endif
#if CAN_WRAP_pci_find_next_bus
    WRAP_FOR_DETACH(pci_find_next_bus)
#endif
#ifndef CAN_WRAP_sg_miter_stop
#   define CAN_WRAP_sg_miter_stop 1
#endif
#if CAN_WRAP_sg_miter_stop
    WRAP_FOR_DETACH(sg_miter_stop)
#endif
#ifndef CAN_WRAP_task_set_jobctl_pending
#   define CAN_WRAP_task_set_jobctl_pending 1
#endif
#if CAN_WRAP_task_set_jobctl_pending
    WRAP_FOR_DETACH(task_set_jobctl_pending)
#endif
#ifndef CAN_WRAP_wake_up_state
#   define CAN_WRAP_wake_up_state 1
#endif
#if CAN_WRAP_wake_up_state
    WRAP_FOR_DETACH(wake_up_state)
#endif
#ifndef CAN_WRAP_vm_get_page_prot
#   define CAN_WRAP_vm_get_page_prot 1
#endif
#if CAN_WRAP_vm_get_page_prot
    WRAP_FOR_DETACH(vm_get_page_prot)
#endif
#ifndef CAN_WRAP_count_swap_pages
#   define CAN_WRAP_count_swap_pages 0
#endif
DETACH(count_swap_pages)
#ifndef CAN_WRAP_memory_read_from_buffer
#   define CAN_WRAP_memory_read_from_buffer 0
#endif
DETACH(memory_read_from_buffer)
#ifndef CAN_WRAP_laptop_io_completion
#   define CAN_WRAP_laptop_io_completion 1
#endif
#if CAN_WRAP_laptop_io_completion
    WRAP_FOR_DETACH(laptop_io_completion)
#endif
#ifndef CAN_WRAP_security_task_getsid
#   define CAN_WRAP_security_task_getsid 1
#endif
#if CAN_WRAP_security_task_getsid
    WRAP_FOR_DETACH(security_task_getsid)
#endif
#ifndef CAN_WRAP_jbd_blocks_per_page
#   define CAN_WRAP_jbd_blocks_per_page 1
#endif
#if CAN_WRAP_jbd_blocks_per_page
    WRAP_FOR_DETACH(jbd_blocks_per_page)
#endif
#ifndef CAN_WRAP_freeze_bdev
#   define CAN_WRAP_freeze_bdev 1
#endif
#if CAN_WRAP_freeze_bdev
    WRAP_FOR_DETACH(freeze_bdev)
#endif
#ifndef CAN_WRAP_rtnl_af_register
#   define CAN_WRAP_rtnl_af_register 1
#endif
#if CAN_WRAP_rtnl_af_register
    WRAP_FOR_DETACH(rtnl_af_register)
#endif
#ifndef CAN_WRAP_cgroup_lock_is_held
#   define CAN_WRAP_cgroup_lock_is_held 0
#endif
DETACH(cgroup_lock_is_held)
#ifndef CAN_WRAP_load_percpu_segment
#   define CAN_WRAP_load_percpu_segment 0
#endif
DETACH(load_percpu_segment)
#ifndef CAN_WRAP_follow_down_one
#   define CAN_WRAP_follow_down_one 1
#endif
#if CAN_WRAP_follow_down_one
    WRAP_FOR_DETACH(follow_down_one)
#endif
#ifndef CAN_WRAP_jbd2_journal_lock_updates
#   define CAN_WRAP_jbd2_journal_lock_updates 1
#endif
#if CAN_WRAP_jbd2_journal_lock_updates
    WRAP_FOR_DETACH(jbd2_journal_lock_updates)
#endif
#ifndef CAN_WRAP_acpi_get_next_object
#   define CAN_WRAP_acpi_get_next_object 0
#endif
DETACH(acpi_get_next_object)
#ifndef CAN_WRAP_init_cpu_present
#   define CAN_WRAP_init_cpu_present 1
#endif
#if CAN_WRAP_init_cpu_present
    WRAP_FOR_DETACH(init_cpu_present)
#endif
#ifndef CAN_WRAP_jbd2_journal_commit_transaction
#   define CAN_WRAP_jbd2_journal_commit_transaction 1
#endif
#if CAN_WRAP_jbd2_journal_commit_transaction
    WRAP_FOR_DETACH(jbd2_journal_commit_transaction)
#endif
#ifndef CAN_WRAP_drop_nlink
#   define CAN_WRAP_drop_nlink 1
#endif
#if CAN_WRAP_drop_nlink
    WRAP_FOR_DETACH(drop_nlink)
#endif
#ifndef CAN_WRAP_pci_enable_sriov
#   define CAN_WRAP_pci_enable_sriov 1
#endif
#if CAN_WRAP_pci_enable_sriov
    WRAP_FOR_DETACH(pci_enable_sriov)
#endif
#ifndef CAN_WRAP_early_cpu_init
#   define CAN_WRAP_early_cpu_init 0
#endif
DETACH(early_cpu_init)
#ifndef CAN_WRAP_KSTK_ESP
#   define CAN_WRAP_KSTK_ESP 1
#endif
#if CAN_WRAP_KSTK_ESP
    WRAP_FOR_DETACH(KSTK_ESP)
#endif
#ifndef CAN_WRAP_find_module
#   define CAN_WRAP_find_module 1
#endif
#if CAN_WRAP_find_module
    WRAP_FOR_DETACH(find_module)
#endif
#ifndef CAN_WRAP_cgroup_init
#   define CAN_WRAP_cgroup_init 0
#endif
DETACH(cgroup_init)
#ifndef CAN_WRAP_exit_itimers
#   define CAN_WRAP_exit_itimers 1
#endif
#if CAN_WRAP_exit_itimers
    WRAP_FOR_DETACH(exit_itimers)
#endif
#ifndef CAN_WRAP_simple_transaction_set
#   define CAN_WRAP_simple_transaction_set 1
#endif
#if CAN_WRAP_simple_transaction_set
    WRAP_FOR_DETACH(simple_transaction_set)
#endif
#ifndef CAN_WRAP_bio_disassociate_task
#   define CAN_WRAP_bio_disassociate_task 1
#endif
#if CAN_WRAP_bio_disassociate_task
    WRAP_FOR_DETACH(bio_disassociate_task)
#endif
#ifndef CAN_WRAP___dquot_alloc_space
#   define CAN_WRAP___dquot_alloc_space 1
#endif
#if CAN_WRAP___dquot_alloc_space
#   ifdef DETACH_ADDR___dquot_alloc_space
        WRAP_FOR_DETACH(__dquot_alloc_space)
#   else
        TYPED_DETACH(__dquot_alloc_space)
#   endif
#endif
#ifndef CAN_WRAP_request_key
#   define CAN_WRAP_request_key 1
#endif
#if CAN_WRAP_request_key
    WRAP_FOR_DETACH(request_key)
#endif
#ifndef CAN_WRAP_acpi_notifier_call_chain
#   define CAN_WRAP_acpi_notifier_call_chain 1
#endif
#if CAN_WRAP_acpi_notifier_call_chain
    WRAP_FOR_DETACH(acpi_notifier_call_chain)
#endif
#ifndef CAN_WRAP_input_set_capability
#   define CAN_WRAP_input_set_capability 1
#endif
#if CAN_WRAP_input_set_capability
    WRAP_FOR_DETACH(input_set_capability)
#endif
#ifndef CAN_WRAP_acpi_bus_generate_proc_event
#   define CAN_WRAP_acpi_bus_generate_proc_event 1
#endif
#if CAN_WRAP_acpi_bus_generate_proc_event
    WRAP_FOR_DETACH(acpi_bus_generate_proc_event)
#endif
#ifndef CAN_WRAP_strnchr
#   define CAN_WRAP_strnchr 0
#endif
DETACH(strnchr)
#ifndef CAN_WRAP__raw_read_lock_irq
#   define CAN_WRAP__raw_read_lock_irq 1
#endif
#if CAN_WRAP__raw_read_lock_irq
    WRAP_FOR_DETACH(_raw_read_lock_irq)
#endif
#ifndef CAN_WRAP_input_register_handler
#   define CAN_WRAP_input_register_handler 1
#endif
#if CAN_WRAP_input_register_handler
    WRAP_FOR_DETACH(input_register_handler)
#endif
#ifndef CAN_WRAP_check_disk_change
#   define CAN_WRAP_check_disk_change 1
#endif
#if CAN_WRAP_check_disk_change
    WRAP_FOR_DETACH(check_disk_change)
#endif
#ifndef CAN_WRAP_generic_permission
#   define CAN_WRAP_generic_permission 1
#endif
#if CAN_WRAP_generic_permission
    WRAP_FOR_DETACH(generic_permission)
#endif
#ifndef CAN_WRAP_compat_sys_vmsplice
#   define CAN_WRAP_compat_sys_vmsplice 1
#endif
#if CAN_WRAP_compat_sys_vmsplice
    WRAP_FOR_DETACH(compat_sys_vmsplice)
#endif
#ifndef CAN_WRAP_acpi_get_type
#   define CAN_WRAP_acpi_get_type 0
#endif
DETACH(acpi_get_type)
#ifndef CAN_WRAP_vfs_xattr_cmp
#   define CAN_WRAP_vfs_xattr_cmp 1
#endif
#if CAN_WRAP_vfs_xattr_cmp
    WRAP_FOR_DETACH(vfs_xattr_cmp)
#endif
#ifndef CAN_WRAP___get_locked_pte
#   define CAN_WRAP___get_locked_pte 1
#endif
#if CAN_WRAP___get_locked_pte
#   ifdef DETACH_ADDR___get_locked_pte
        WRAP_FOR_DETACH(__get_locked_pte)
#   else
        TYPED_DETACH(__get_locked_pte)
#   endif
#endif
#ifndef CAN_WRAP_xtime_update
#   define CAN_WRAP_xtime_update 0
#endif
DETACH(xtime_update)
#ifndef CAN_WRAP_acpi_disable_all_gpes
#   define CAN_WRAP_acpi_disable_all_gpes 0
#endif
DETACH(acpi_disable_all_gpes)
#ifndef CAN_WRAP_qdisc_class_hash_grow
#   define CAN_WRAP_qdisc_class_hash_grow 1
#endif
#if CAN_WRAP_qdisc_class_hash_grow
    WRAP_FOR_DETACH(qdisc_class_hash_grow)
#endif
#ifndef CAN_WRAP_blk_queue_prep_rq
#   define CAN_WRAP_blk_queue_prep_rq 1
#endif
#if CAN_WRAP_blk_queue_prep_rq
    WRAP_FOR_DETACH(blk_queue_prep_rq)
#endif
#ifndef CAN_WRAP_scsi_unregister_acpi_bus_type
#   define CAN_WRAP_scsi_unregister_acpi_bus_type 1
#endif
#if CAN_WRAP_scsi_unregister_acpi_bus_type
    WRAP_FOR_DETACH(scsi_unregister_acpi_bus_type)
#endif
#ifndef CAN_WRAP_lookup_one_len
#   define CAN_WRAP_lookup_one_len 1
#endif
#if CAN_WRAP_lookup_one_len
    WRAP_FOR_DETACH(lookup_one_len)
#endif
#ifndef CAN_WRAP_account_page_dirtied
#   define CAN_WRAP_account_page_dirtied 1
#endif
#if CAN_WRAP_account_page_dirtied
    WRAP_FOR_DETACH(account_page_dirtied)
#endif
#ifndef CAN_WRAP_pci_remove_root_bus
#   define CAN_WRAP_pci_remove_root_bus 1
#endif
#if CAN_WRAP_pci_remove_root_bus
    WRAP_FOR_DETACH(pci_remove_root_bus)
#endif
#ifndef CAN_WRAP_inet_frag_find
#   define CAN_WRAP_inet_frag_find 1
#endif
#if CAN_WRAP_inet_frag_find
    WRAP_FOR_DETACH(inet_frag_find)
#endif
#ifndef CAN_WRAP_security_audit_rule_match
#   define CAN_WRAP_security_audit_rule_match 1
#endif
#if CAN_WRAP_security_audit_rule_match
    WRAP_FOR_DETACH(security_audit_rule_match)
#endif
#ifndef CAN_WRAP_compat_sys_utimes
#   define CAN_WRAP_compat_sys_utimes 1
#endif
#if CAN_WRAP_compat_sys_utimes
    WRAP_FOR_DETACH(compat_sys_utimes)
#endif
#ifndef CAN_WRAP_sysfs_add_file_to_group
#   define CAN_WRAP_sysfs_add_file_to_group 1
#endif
#if CAN_WRAP_sysfs_add_file_to_group
    WRAP_FOR_DETACH(sysfs_add_file_to_group)
#endif
#ifndef CAN_WRAP_dm_table_add_target_callbacks
#   define CAN_WRAP_dm_table_add_target_callbacks 1
#endif
#if CAN_WRAP_dm_table_add_target_callbacks
    WRAP_FOR_DETACH(dm_table_add_target_callbacks)
#endif
#ifndef CAN_WRAP_sock_wmalloc
#   define CAN_WRAP_sock_wmalloc 1
#endif
#if CAN_WRAP_sock_wmalloc
    WRAP_FOR_DETACH(sock_wmalloc)
#endif
#ifndef CAN_WRAP_pci_assign_unassigned_resources
#   define CAN_WRAP_pci_assign_unassigned_resources 0
#endif
DETACH(pci_assign_unassigned_resources)
#ifndef CAN_WRAP_ata_scsi_simulate
#   define CAN_WRAP_ata_scsi_simulate 1
#endif
#if CAN_WRAP_ata_scsi_simulate
    WRAP_FOR_DETACH(ata_scsi_simulate)
#endif
#ifndef CAN_WRAP_dma_supported
#   define CAN_WRAP_dma_supported 1
#endif
#if CAN_WRAP_dma_supported
    WRAP_FOR_DETACH(dma_supported)
#endif
#ifndef CAN_WRAP_leave_mm
#   define CAN_WRAP_leave_mm 0
#endif
DETACH(leave_mm)
#ifndef CAN_WRAP_ata_sff_pause
#   define CAN_WRAP_ata_sff_pause 1
#endif
#if CAN_WRAP_ata_sff_pause
    WRAP_FOR_DETACH(ata_sff_pause)
#endif
#ifndef CAN_WRAP_sk_setup_caps
#   define CAN_WRAP_sk_setup_caps 1
#endif
#if CAN_WRAP_sk_setup_caps
    WRAP_FOR_DETACH(sk_setup_caps)
#endif
#ifndef CAN_WRAP_bdget_disk
#   define CAN_WRAP_bdget_disk 1
#endif
#if CAN_WRAP_bdget_disk
    WRAP_FOR_DETACH(bdget_disk)
#endif
#ifndef CAN_WRAP_net_sysctl_init
#   define CAN_WRAP_net_sysctl_init 0
#endif
DETACH(net_sysctl_init)
#ifndef CAN_WRAP_jbd2_journal_restart
#   define CAN_WRAP_jbd2_journal_restart 1
#endif
#if CAN_WRAP_jbd2_journal_restart
    WRAP_FOR_DETACH(jbd2_journal_restart)
#endif
#ifndef CAN_WRAP__raw_spin_lock_nested
#   define CAN_WRAP__raw_spin_lock_nested 1
#endif
#if CAN_WRAP__raw_spin_lock_nested
    WRAP_FOR_DETACH(_raw_spin_lock_nested)
#endif
#ifndef CAN_WRAP_inet_csk_reqsk_queue_hash_add
#   define CAN_WRAP_inet_csk_reqsk_queue_hash_add 1
#endif
#if CAN_WRAP_inet_csk_reqsk_queue_hash_add
    WRAP_FOR_DETACH(inet_csk_reqsk_queue_hash_add)
#endif
#ifndef CAN_WRAP_rcu_barrier_bh
#   define CAN_WRAP_rcu_barrier_bh 0
#endif
DETACH(rcu_barrier_bh)
#ifndef CAN_WRAP____ratelimit
#   define CAN_WRAP____ratelimit 1
#endif
#if CAN_WRAP____ratelimit
#   ifdef DETACH_ADDR____ratelimit
        WRAP_FOR_DETACH(___ratelimit)
#   else
        TYPED_DETACH(___ratelimit)
#   endif
#endif
#ifndef CAN_WRAP_clockevents_register_device
#   define CAN_WRAP_clockevents_register_device 1
#endif
#if CAN_WRAP_clockevents_register_device
    WRAP_FOR_DETACH(clockevents_register_device)
#endif
#ifndef CAN_WRAP_set_pages_rw
#   define CAN_WRAP_set_pages_rw 1
#endif
#if CAN_WRAP_set_pages_rw
    WRAP_FOR_DETACH(set_pages_rw)
#endif
#ifndef CAN_WRAP_add_input_randomness
#   define CAN_WRAP_add_input_randomness 0
#endif
DETACH(add_input_randomness)
#ifndef CAN_WRAP_sysctl_init
#   define CAN_WRAP_sysctl_init 0
#endif
DETACH(sysctl_init)
#ifndef CAN_WRAP_security_settime
#   define CAN_WRAP_security_settime 1
#endif
#if CAN_WRAP_security_settime
    WRAP_FOR_DETACH(security_settime)
#endif
#ifndef CAN_WRAP_kstrtoll_from_user
#   define CAN_WRAP_kstrtoll_from_user 0
#endif
DETACH(kstrtoll_from_user)
#ifndef CAN_WRAP_simple_attr_release
#   define CAN_WRAP_simple_attr_release 1
#endif
#if CAN_WRAP_simple_attr_release
    WRAP_FOR_DETACH(simple_attr_release)
#endif
#ifndef CAN_WRAP_set_pages_ro
#   define CAN_WRAP_set_pages_ro 1
#endif
#if CAN_WRAP_set_pages_ro
    WRAP_FOR_DETACH(set_pages_ro)
#endif
#ifndef CAN_WRAP_skb_abort_seq_read
#   define CAN_WRAP_skb_abort_seq_read 1
#endif
#if CAN_WRAP_skb_abort_seq_read
    WRAP_FOR_DETACH(skb_abort_seq_read)
#endif
#ifndef CAN_WRAP_dev_uc_unsync
#   define CAN_WRAP_dev_uc_unsync 1
#endif
#if CAN_WRAP_dev_uc_unsync
    WRAP_FOR_DETACH(dev_uc_unsync)
#endif
#ifndef CAN_WRAP_remove_irq
#   define CAN_WRAP_remove_irq 1
#endif
#if CAN_WRAP_remove_irq
    WRAP_FOR_DETACH(remove_irq)
#endif
#ifndef CAN_WRAP_arch_probe_nr_irqs
#   define CAN_WRAP_arch_probe_nr_irqs 0
#endif
DETACH(arch_probe_nr_irqs)
#ifndef CAN_WRAP_sk_clone_lock
#   define CAN_WRAP_sk_clone_lock 1
#endif
#if CAN_WRAP_sk_clone_lock
    WRAP_FOR_DETACH(sk_clone_lock)
#endif
#ifndef CAN_WRAP_vfs_listxattr
#   define CAN_WRAP_vfs_listxattr 1
#endif
#if CAN_WRAP_vfs_listxattr
    WRAP_FOR_DETACH(vfs_listxattr)
#endif
#ifndef CAN_WRAP_kobj_ns_drop
#   define CAN_WRAP_kobj_ns_drop 0
#endif
DETACH(kobj_ns_drop)
#ifndef CAN_WRAP_simple_write_end
#   define CAN_WRAP_simple_write_end 1
#endif
#if CAN_WRAP_simple_write_end
    WRAP_FOR_DETACH(simple_write_end)
#endif
#ifndef CAN_WRAP_cap_inode_killpriv
#   define CAN_WRAP_cap_inode_killpriv 1
#endif
#if CAN_WRAP_cap_inode_killpriv
    WRAP_FOR_DETACH(cap_inode_killpriv)
#endif
#ifndef CAN_WRAP_bio_init
#   define CAN_WRAP_bio_init 1
#endif
#if CAN_WRAP_bio_init
    WRAP_FOR_DETACH(bio_init)
#endif
#ifndef CAN_WRAP_find_vpid
#   define CAN_WRAP_find_vpid 1
#endif
#if CAN_WRAP_find_vpid
    WRAP_FOR_DETACH(find_vpid)
#endif
#ifndef CAN_WRAP_set_task_blockstep
#   define CAN_WRAP_set_task_blockstep 1
#endif
#if CAN_WRAP_set_task_blockstep
    WRAP_FOR_DETACH(set_task_blockstep)
#endif
#ifndef CAN_WRAP_pm_wakeup_event
#   define CAN_WRAP_pm_wakeup_event 1
#endif
#if CAN_WRAP_pm_wakeup_event
    WRAP_FOR_DETACH(pm_wakeup_event)
#endif
#ifndef CAN_WRAP_pci_enable_device_io
#   define CAN_WRAP_pci_enable_device_io 1
#endif
#if CAN_WRAP_pci_enable_device_io
    WRAP_FOR_DETACH(pci_enable_device_io)
#endif
#ifndef CAN_WRAP_swap_readpage
#   define CAN_WRAP_swap_readpage 1
#endif
#if CAN_WRAP_swap_readpage
    WRAP_FOR_DETACH(swap_readpage)
#endif
#ifndef CAN_WRAP_memcpy
#   define CAN_WRAP_memcpy 0
#endif
DETACH(memcpy)
#ifndef CAN_WRAP_swap_setup
#   define CAN_WRAP_swap_setup 0
#endif
DETACH(swap_setup)
#ifndef CAN_WRAP_input_ff_destroy
#   define CAN_WRAP_input_ff_destroy 1
#endif
#if CAN_WRAP_input_ff_destroy
    WRAP_FOR_DETACH(input_ff_destroy)
#endif
#ifndef CAN_WRAP_memory_add_physaddr_to_nid
#   define CAN_WRAP_memory_add_physaddr_to_nid 0
#endif
DETACH(memory_add_physaddr_to_nid)
#ifndef CAN_WRAP_dqget
#   define CAN_WRAP_dqget 1
#endif
#if CAN_WRAP_dqget
    WRAP_FOR_DETACH(dqget)
#endif
#ifndef CAN_WRAP_napi_gro_receive
#   define CAN_WRAP_napi_gro_receive 1
#endif
#if CAN_WRAP_napi_gro_receive
    WRAP_FOR_DETACH(napi_gro_receive)
#endif
#ifndef CAN_WRAP_memmap_init_zone
#   define CAN_WRAP_memmap_init_zone 0
#endif
DETACH(memmap_init_zone)
#ifndef CAN_WRAP_journal_tag_bytes
#   define CAN_WRAP_journal_tag_bytes 1
#endif
#if CAN_WRAP_journal_tag_bytes
    WRAP_FOR_DETACH(journal_tag_bytes)
#endif
#ifndef CAN_WRAP_mod_delayed_work
#   define CAN_WRAP_mod_delayed_work 1
#endif
#if CAN_WRAP_mod_delayed_work
    WRAP_FOR_DETACH(mod_delayed_work)
#endif
#ifndef CAN_WRAP_dm_put_device
#   define CAN_WRAP_dm_put_device 1
#endif
#if CAN_WRAP_dm_put_device
    WRAP_FOR_DETACH(dm_put_device)
#endif
#ifndef CAN_WRAP___remove_inode_hash
#   define CAN_WRAP___remove_inode_hash 1
#endif
#if CAN_WRAP___remove_inode_hash
#   ifdef DETACH_ADDR___remove_inode_hash
        WRAP_FOR_DETACH(__remove_inode_hash)
#   else
        TYPED_DETACH(__remove_inode_hash)
#   endif
#endif
#ifndef CAN_WRAP_move_addr_to_kernel
#   define CAN_WRAP_move_addr_to_kernel 1
#endif
#if CAN_WRAP_move_addr_to_kernel
    WRAP_FOR_DETACH(move_addr_to_kernel)
#endif
#ifndef CAN_WRAP_writeback_inodes_sb_nr_if_idle
#   define CAN_WRAP_writeback_inodes_sb_nr_if_idle 1
#endif
#if CAN_WRAP_writeback_inodes_sb_nr_if_idle
    WRAP_FOR_DETACH(writeback_inodes_sb_nr_if_idle)
#endif
#ifndef CAN_WRAP_phy_drivers_register
#   define CAN_WRAP_phy_drivers_register 1
#endif
#if CAN_WRAP_phy_drivers_register
    WRAP_FOR_DETACH(phy_drivers_register)
#endif
#ifndef CAN_WRAP_bust_spinlocks
#   define CAN_WRAP_bust_spinlocks 0
#endif
DETACH(bust_spinlocks)
#ifndef CAN_WRAP_pci_check_and_mask_intx
#   define CAN_WRAP_pci_check_and_mask_intx 1
#endif
#if CAN_WRAP_pci_check_and_mask_intx
    WRAP_FOR_DETACH(pci_check_and_mask_intx)
#endif
#ifndef CAN_WRAP_mpage_readpage
#   define CAN_WRAP_mpage_readpage 1
#endif
#if CAN_WRAP_mpage_readpage
    WRAP_FOR_DETACH(mpage_readpage)
#endif
#ifndef CAN_WRAP_res_counter_memparse_write_strategy
#   define CAN_WRAP_res_counter_memparse_write_strategy 0
#endif
DETACH(res_counter_memparse_write_strategy)
#ifndef CAN_WRAP_text_poke_smp
#   define CAN_WRAP_text_poke_smp 0
#endif
DETACH(text_poke_smp)
#ifndef CAN_WRAP_security_task_to_inode
#   define CAN_WRAP_security_task_to_inode 1
#endif
#if CAN_WRAP_security_task_to_inode
    WRAP_FOR_DETACH(security_task_to_inode)
#endif
#ifndef CAN_WRAP___delete_from_page_cache
#   define CAN_WRAP___delete_from_page_cache 1
#endif
#if CAN_WRAP___delete_from_page_cache
#   ifdef DETACH_ADDR___delete_from_page_cache
        WRAP_FOR_DETACH(__delete_from_page_cache)
#   else
        TYPED_DETACH(__delete_from_page_cache)
#   endif
#endif
#ifndef CAN_WRAP_wrmsr_safe_regs_on_cpu
#   define CAN_WRAP_wrmsr_safe_regs_on_cpu 0
#endif
DETACH(wrmsr_safe_regs_on_cpu)
#ifndef CAN_WRAP_clocksource_mmio_readl_up
#   define CAN_WRAP_clocksource_mmio_readl_up 1
#endif
#if CAN_WRAP_clocksource_mmio_readl_up
    WRAP_FOR_DETACH(clocksource_mmio_readl_up)
#endif
#ifndef CAN_WRAP_tick_nohz_irq_exit
#   define CAN_WRAP_tick_nohz_irq_exit 0
#endif
DETACH(tick_nohz_irq_exit)
#ifndef CAN_WRAP_eth_header_cache
#   define CAN_WRAP_eth_header_cache 1
#endif
#if CAN_WRAP_eth_header_cache
    WRAP_FOR_DETACH(eth_header_cache)
#endif
#ifndef CAN_WRAP_csum_partial_copy_fromiovecend
#   define CAN_WRAP_csum_partial_copy_fromiovecend 1
#endif
#if CAN_WRAP_csum_partial_copy_fromiovecend
    WRAP_FOR_DETACH(csum_partial_copy_fromiovecend)
#endif
#ifndef CAN_WRAP_blk_queue_flush_queueable
#   define CAN_WRAP_blk_queue_flush_queueable 1
#endif
#if CAN_WRAP_blk_queue_flush_queueable
    WRAP_FOR_DETACH(blk_queue_flush_queueable)
#endif
#ifndef CAN_WRAP_expand_stack
#   define CAN_WRAP_expand_stack 1
#endif
#if CAN_WRAP_expand_stack
    WRAP_FOR_DETACH(expand_stack)
#endif
#ifndef CAN_WRAP_kick_iocb
#   define CAN_WRAP_kick_iocb 1
#endif
#if CAN_WRAP_kick_iocb
    WRAP_FOR_DETACH(kick_iocb)
#endif
#ifndef CAN_WRAP_acpi_boot_table_init
#   define CAN_WRAP_acpi_boot_table_init 0
#endif
DETACH(acpi_boot_table_init)
#ifndef CAN_WRAP_compat_sys_recv
#   define CAN_WRAP_compat_sys_recv 0
#endif
DETACH(compat_sys_recv)
#ifndef CAN_WRAP_unregister_acpi_bus_notifier
#   define CAN_WRAP_unregister_acpi_bus_notifier 1
#endif
#if CAN_WRAP_unregister_acpi_bus_notifier
    WRAP_FOR_DETACH(unregister_acpi_bus_notifier)
#endif
#ifndef CAN_WRAP_test_clear_page_writeback
#   define CAN_WRAP_test_clear_page_writeback 1
#endif
#if CAN_WRAP_test_clear_page_writeback
    WRAP_FOR_DETACH(test_clear_page_writeback)
#endif
#ifndef CAN_WRAP_mp_find_ioapic
#   define CAN_WRAP_mp_find_ioapic 0
#endif
DETACH(mp_find_ioapic)
#ifndef CAN_WRAP_revalidate_disk
#   define CAN_WRAP_revalidate_disk 1
#endif
#if CAN_WRAP_revalidate_disk
    WRAP_FOR_DETACH(revalidate_disk)
#endif
#ifndef CAN_WRAP_request_any_context_irq
#   define CAN_WRAP_request_any_context_irq 1
#endif
#if CAN_WRAP_request_any_context_irq
    WRAP_FOR_DETACH(request_any_context_irq)
#endif
#ifndef CAN_WRAP_sysfs_notify
#   define CAN_WRAP_sysfs_notify 1
#endif
#if CAN_WRAP_sysfs_notify
    WRAP_FOR_DETACH(sysfs_notify)
#endif
#ifndef CAN_WRAP_ata_pci_sff_init_host
#   define CAN_WRAP_ata_pci_sff_init_host 1
#endif
#if CAN_WRAP_ata_pci_sff_init_host
    WRAP_FOR_DETACH(ata_pci_sff_init_host)
#endif
#ifndef CAN_WRAP_irq_gc_eoi
#   define CAN_WRAP_irq_gc_eoi 1
#endif
#if CAN_WRAP_irq_gc_eoi
    WRAP_FOR_DETACH(irq_gc_eoi)
#endif
#ifndef CAN_WRAP_generic_bigsmp_probe
#   define CAN_WRAP_generic_bigsmp_probe 0
#endif
DETACH(generic_bigsmp_probe)
#ifndef CAN_WRAP_sync_global_pgds
#   define CAN_WRAP_sync_global_pgds 0
#endif
DETACH(sync_global_pgds)
#ifndef CAN_WRAP_security_ptrace_traceme
#   define CAN_WRAP_security_ptrace_traceme 1
#endif
#if CAN_WRAP_security_ptrace_traceme
    WRAP_FOR_DETACH(security_ptrace_traceme)
#endif
#ifndef CAN_WRAP_acpi_update_all_gpes
#   define CAN_WRAP_acpi_update_all_gpes 0
#endif
DETACH(acpi_update_all_gpes)
#ifndef CAN_WRAP_heap_init
#   define CAN_WRAP_heap_init 1
#endif
#if CAN_WRAP_heap_init
    WRAP_FOR_DETACH(heap_init)
#endif
#ifndef CAN_WRAP_writeback_set_ratelimit
#   define CAN_WRAP_writeback_set_ratelimit 0
#endif
DETACH(writeback_set_ratelimit)
#ifndef CAN_WRAP_do_io_submit
#   define CAN_WRAP_do_io_submit 0
#endif
DETACH(do_io_submit)
#ifndef CAN_WRAP_blk_put_queue
#   define CAN_WRAP_blk_put_queue 1
#endif
#if CAN_WRAP_blk_put_queue
    WRAP_FOR_DETACH(blk_put_queue)
#endif
#ifndef CAN_WRAP_inode_add_rsv_space
#   define CAN_WRAP_inode_add_rsv_space 1
#endif
#if CAN_WRAP_inode_add_rsv_space
    WRAP_FOR_DETACH(inode_add_rsv_space)
#endif
#ifndef CAN_WRAP_calculate_normal_threshold
#   define CAN_WRAP_calculate_normal_threshold 1
#endif
#if CAN_WRAP_calculate_normal_threshold
    WRAP_FOR_DETACH(calculate_normal_threshold)
#endif
#ifndef CAN_WRAP_mutex_lock
#   define CAN_WRAP_mutex_lock 1
#endif
#if CAN_WRAP_mutex_lock
    WRAP_FOR_DETACH(mutex_lock)
#endif
#ifndef CAN_WRAP_nla_put_nohdr
#   define CAN_WRAP_nla_put_nohdr 1
#endif
#if CAN_WRAP_nla_put_nohdr
    WRAP_FOR_DETACH(nla_put_nohdr)
#endif
#ifndef CAN_WRAP_neigh_destroy
#   define CAN_WRAP_neigh_destroy 1
#endif
#if CAN_WRAP_neigh_destroy
    WRAP_FOR_DETACH(neigh_destroy)
#endif
#ifndef CAN_WRAP_radix_tree_next_chunk
#   define CAN_WRAP_radix_tree_next_chunk 1
#endif
#if CAN_WRAP_radix_tree_next_chunk
    WRAP_FOR_DETACH(radix_tree_next_chunk)
#endif
#ifndef CAN_WRAP_posix_lock_file
#   define CAN_WRAP_posix_lock_file 1
#endif
#if CAN_WRAP_posix_lock_file
    WRAP_FOR_DETACH(posix_lock_file)
#endif
#ifndef CAN_WRAP_IO_APIC_get_PCI_irq_vector
#   define CAN_WRAP_IO_APIC_get_PCI_irq_vector 1
#endif
#if CAN_WRAP_IO_APIC_get_PCI_irq_vector
    WRAP_FOR_DETACH(IO_APIC_get_PCI_irq_vector)
#endif
#ifndef CAN_WRAP___block_write_begin
#   define CAN_WRAP___block_write_begin 1
#endif
#if CAN_WRAP___block_write_begin
#   ifdef DETACH_ADDR___block_write_begin
        WRAP_FOR_DETACH(__block_write_begin)
#   else
        TYPED_DETACH(__block_write_begin)
#   endif
#endif
#ifndef CAN_WRAP_sk_alloc
#   define CAN_WRAP_sk_alloc 1
#endif
#if CAN_WRAP_sk_alloc
    WRAP_FOR_DETACH(sk_alloc)
#endif
#ifndef CAN_WRAP___sg_alloc_table
#   define CAN_WRAP___sg_alloc_table 1
#endif
#if CAN_WRAP___sg_alloc_table
#   ifdef DETACH_ADDR___sg_alloc_table
        WRAP_FOR_DETACH(__sg_alloc_table)
#   else
        TYPED_DETACH(__sg_alloc_table)
#   endif
#endif
#ifndef CAN_WRAP_update_page_count
#   define CAN_WRAP_update_page_count 0
#endif
DETACH(update_page_count)
#ifndef CAN_WRAP_unregister_chrdev_region
#   define CAN_WRAP_unregister_chrdev_region 0
#endif
DETACH(unregister_chrdev_region)
#ifndef CAN_WRAP_blk_dump_rq_flags
#   define CAN_WRAP_blk_dump_rq_flags 1
#endif
#if CAN_WRAP_blk_dump_rq_flags
    WRAP_FOR_DETACH(blk_dump_rq_flags)
#endif
#ifndef CAN_WRAP_filemap_fault
#   define CAN_WRAP_filemap_fault 1
#endif
#if CAN_WRAP_filemap_fault
    WRAP_FOR_DETACH(filemap_fault)
#endif
#ifndef CAN_WRAP_cpu_detect
#   define CAN_WRAP_cpu_detect 1
#endif
#if CAN_WRAP_cpu_detect
    WRAP_FOR_DETACH(cpu_detect)
#endif
#ifndef CAN_WRAP_set_memory_rw
#   define CAN_WRAP_set_memory_rw 0
#endif
DETACH(set_memory_rw)
#ifndef CAN_WRAP_radix_tree_tag_get
#   define CAN_WRAP_radix_tree_tag_get 1
#endif
#if CAN_WRAP_radix_tree_tag_get
    WRAP_FOR_DETACH(radix_tree_tag_get)
#endif
#ifndef CAN_WRAP_get_device
#   define CAN_WRAP_get_device 1
#endif
#if CAN_WRAP_get_device
    WRAP_FOR_DETACH(get_device)
#endif
#ifndef CAN_WRAP_cdrom_release
#   define CAN_WRAP_cdrom_release 1
#endif
#if CAN_WRAP_cdrom_release
    WRAP_FOR_DETACH(cdrom_release)
#endif
#ifndef CAN_WRAP_inet_twsk_bind_unhash
#   define CAN_WRAP_inet_twsk_bind_unhash 1
#endif
#if CAN_WRAP_inet_twsk_bind_unhash
    WRAP_FOR_DETACH(inet_twsk_bind_unhash)
#endif
#ifndef CAN_WRAP_vfs_getxattr
#   define CAN_WRAP_vfs_getxattr 1
#endif
#if CAN_WRAP_vfs_getxattr
    WRAP_FOR_DETACH(vfs_getxattr)
#endif
#ifndef CAN_WRAP_smp_call_function
#   define CAN_WRAP_smp_call_function 1
#endif
#if CAN_WRAP_smp_call_function
    WRAP_FOR_DETACH(smp_call_function)
#endif
#ifndef CAN_WRAP_set_memory_ro
#   define CAN_WRAP_set_memory_ro 0
#endif
DETACH(set_memory_ro)
#ifndef CAN_WRAP_phy_find_first
#   define CAN_WRAP_phy_find_first 1
#endif
#if CAN_WRAP_phy_find_first
    WRAP_FOR_DETACH(phy_find_first)
#endif
#ifndef CAN_WRAP_jbd2_journal_destroy_revoke_caches
#   define CAN_WRAP_jbd2_journal_destroy_revoke_caches 0
#endif
DETACH(jbd2_journal_destroy_revoke_caches)
#ifndef CAN_WRAP_pcie_aspm_support_enabled
#   define CAN_WRAP_pcie_aspm_support_enabled 0
#endif
DETACH(pcie_aspm_support_enabled)
#ifndef CAN_WRAP_sock_alloc_file
#   define CAN_WRAP_sock_alloc_file 1
#endif
#if CAN_WRAP_sock_alloc_file
    WRAP_FOR_DETACH(sock_alloc_file)
#endif
#ifndef CAN_WRAP_do_munmap
#   define CAN_WRAP_do_munmap 1
#endif
#if CAN_WRAP_do_munmap
    WRAP_FOR_DETACH(do_munmap)
#endif
#ifndef CAN_WRAP_generic_error_remove_page
#   define CAN_WRAP_generic_error_remove_page 1
#endif
#if CAN_WRAP_generic_error_remove_page
    WRAP_FOR_DETACH(generic_error_remove_page)
#endif
#ifndef CAN_WRAP_netdev_pick_tx
#   define CAN_WRAP_netdev_pick_tx 1
#endif
#if CAN_WRAP_netdev_pick_tx
    WRAP_FOR_DETACH(netdev_pick_tx)
#endif
#ifndef CAN_WRAP___put_task_struct
#   define CAN_WRAP___put_task_struct 1
#endif
#if CAN_WRAP___put_task_struct
#   ifdef DETACH_ADDR___put_task_struct
        WRAP_FOR_DETACH(__put_task_struct)
#   else
        TYPED_DETACH(__put_task_struct)
#   endif
#endif
#ifndef CAN_WRAP_input_set_keycode
#   define CAN_WRAP_input_set_keycode 1
#endif
#if CAN_WRAP_input_set_keycode
    WRAP_FOR_DETACH(input_set_keycode)
#endif
#ifndef CAN_WRAP_rtmsg_ifinfo
#   define CAN_WRAP_rtmsg_ifinfo 1
#endif
#if CAN_WRAP_rtmsg_ifinfo
    WRAP_FOR_DETACH(rtmsg_ifinfo)
#endif
#ifndef CAN_WRAP_vm_normal_page
#   define CAN_WRAP_vm_normal_page 1
#endif
#if CAN_WRAP_vm_normal_page
    WRAP_FOR_DETACH(vm_normal_page)
#endif
#ifndef CAN_WRAP_pnp_unregister_driver
#   define CAN_WRAP_pnp_unregister_driver 1
#endif
#if CAN_WRAP_pnp_unregister_driver
    WRAP_FOR_DETACH(pnp_unregister_driver)
#endif
#ifndef CAN_WRAP___kmalloc_track_caller
#   define CAN_WRAP___kmalloc_track_caller 0
#endif
DETACH(__kmalloc_track_caller)
#ifndef CAN_WRAP_ata_port_pbar_desc
#   define CAN_WRAP_ata_port_pbar_desc 1
#endif
#if CAN_WRAP_ata_port_pbar_desc
    WRAP_FOR_DETACH(ata_port_pbar_desc)
#endif
#ifndef CAN_WRAP_wakeup_source_prepare
#   define CAN_WRAP_wakeup_source_prepare 1
#endif
#if CAN_WRAP_wakeup_source_prepare
    WRAP_FOR_DETACH(wakeup_source_prepare)
#endif
#ifndef CAN_WRAP_generic_setxattr
#   define CAN_WRAP_generic_setxattr 1
#endif
#if CAN_WRAP_generic_setxattr
    WRAP_FOR_DETACH(generic_setxattr)
#endif
#ifndef CAN_WRAP_pci_reenable_device
#   define CAN_WRAP_pci_reenable_device 1
#endif
#if CAN_WRAP_pci_reenable_device
    WRAP_FOR_DETACH(pci_reenable_device)
#endif
#ifndef CAN_WRAP_pci_match_id
#   define CAN_WRAP_pci_match_id 1
#endif
#if CAN_WRAP_pci_match_id
    WRAP_FOR_DETACH(pci_match_id)
#endif
#ifndef CAN_WRAP_jbd2_alloc
#   define CAN_WRAP_jbd2_alloc 0
#endif
DETACH(jbd2_alloc)
#ifndef CAN_WRAP_pci_dev_run_wake
#   define CAN_WRAP_pci_dev_run_wake 1
#endif
#if CAN_WRAP_pci_dev_run_wake
    WRAP_FOR_DETACH(pci_dev_run_wake)
#endif
#ifndef CAN_WRAP_mpc_ioapic_id
#   define CAN_WRAP_mpc_ioapic_id 0
#endif
DETACH(mpc_ioapic_id)
#ifndef CAN_WRAP_numa_clear_node
#   define CAN_WRAP_numa_clear_node 0
#endif
DETACH(numa_clear_node)
#ifndef CAN_WRAP_qtree_entry_unused
#   define CAN_WRAP_qtree_entry_unused 1
#endif
#if CAN_WRAP_qtree_entry_unused
    WRAP_FOR_DETACH(qtree_entry_unused)
#endif
#ifndef CAN_WRAP_get_gendisk
#   define CAN_WRAP_get_gendisk 1
#endif
#if CAN_WRAP_get_gendisk
    WRAP_FOR_DETACH(get_gendisk)
#endif
#ifndef CAN_WRAP_congestion_wait
#   define CAN_WRAP_congestion_wait 0
#endif
DETACH(congestion_wait)
#ifndef CAN_WRAP_acpi_os_get_root_pointer
#   define CAN_WRAP_acpi_os_get_root_pointer 0
#endif
DETACH(acpi_os_get_root_pointer)
#ifndef CAN_WRAP_exit_rcu
#   define CAN_WRAP_exit_rcu 0
#endif
DETACH(exit_rcu)
#ifndef CAN_WRAP_jbd2_buffer_abort_trigger
#   define CAN_WRAP_jbd2_buffer_abort_trigger 1
#endif
#if CAN_WRAP_jbd2_buffer_abort_trigger
    WRAP_FOR_DETACH(jbd2_buffer_abort_trigger)
#endif
#ifndef CAN_WRAP_atapi_cmd_type
#   define CAN_WRAP_atapi_cmd_type 0
#endif
DETACH(atapi_cmd_type)
#ifndef CAN_WRAP_irq_gc_unmask_enable_reg
#   define CAN_WRAP_irq_gc_unmask_enable_reg 1
#endif
#if CAN_WRAP_irq_gc_unmask_enable_reg
    WRAP_FOR_DETACH(irq_gc_unmask_enable_reg)
#endif
#ifndef CAN_WRAP_register_gifconf
#   define CAN_WRAP_register_gifconf 1
#endif
#if CAN_WRAP_register_gifconf
    WRAP_FOR_DETACH(register_gifconf)
#endif
#ifndef CAN_WRAP_dm_table_get_size
#   define CAN_WRAP_dm_table_get_size 1
#endif
#if CAN_WRAP_dm_table_get_size
    WRAP_FOR_DETACH(dm_table_get_size)
#endif
#ifndef CAN_WRAP_nla_validate
#   define CAN_WRAP_nla_validate 1
#endif
#if CAN_WRAP_nla_validate
    WRAP_FOR_DETACH(nla_validate)
#endif
#ifndef CAN_WRAP_proc_ns_fget
#   define CAN_WRAP_proc_ns_fget 1
#endif
#if CAN_WRAP_proc_ns_fget
    WRAP_FOR_DETACH(proc_ns_fget)
#endif
#ifndef CAN_WRAP_ignore_sysret
#   define CAN_WRAP_ignore_sysret 0
#endif
DETACH(ignore_sysret)
#ifndef CAN_WRAP_memdup_user
#   define CAN_WRAP_memdup_user 0
#endif
DETACH(memdup_user)
#ifndef CAN_WRAP_security_inode_mknod
#   define CAN_WRAP_security_inode_mknod 1
#endif
#if CAN_WRAP_security_inode_mknod
    WRAP_FOR_DETACH(security_inode_mknod)
#endif
#ifndef CAN_WRAP_inode_add_bytes
#   define CAN_WRAP_inode_add_bytes 1
#endif
#if CAN_WRAP_inode_add_bytes
    WRAP_FOR_DETACH(inode_add_bytes)
#endif
#ifndef CAN_WRAP_ata_dev_acpi_handle
#   define CAN_WRAP_ata_dev_acpi_handle 1
#endif
#if CAN_WRAP_ata_dev_acpi_handle
    WRAP_FOR_DETACH(ata_dev_acpi_handle)
#endif
#ifndef CAN_WRAP_truncate_pagecache
#   define CAN_WRAP_truncate_pagecache 1
#endif
#if CAN_WRAP_truncate_pagecache
    WRAP_FOR_DETACH(truncate_pagecache)
#endif
#ifndef CAN_WRAP_pci_stop_and_remove_bus_device
#   define CAN_WRAP_pci_stop_and_remove_bus_device 1
#endif
#if CAN_WRAP_pci_stop_and_remove_bus_device
    WRAP_FOR_DETACH(pci_stop_and_remove_bus_device)
#endif
#ifndef CAN_WRAP_set_bh_page
#   define CAN_WRAP_set_bh_page 1
#endif
#if CAN_WRAP_set_bh_page
    WRAP_FOR_DETACH(set_bh_page)
#endif
#ifndef CAN_WRAP_neigh_seq_next
#   define CAN_WRAP_neigh_seq_next 1
#endif
#if CAN_WRAP_neigh_seq_next
    WRAP_FOR_DETACH(neigh_seq_next)
#endif
#ifndef CAN_WRAP_dev_addr_flush
#   define CAN_WRAP_dev_addr_flush 1
#endif
#if CAN_WRAP_dev_addr_flush
    WRAP_FOR_DETACH(dev_addr_flush)
#endif
#ifndef CAN_WRAP_security_task_setnice
#   define CAN_WRAP_security_task_setnice 1
#endif
#if CAN_WRAP_security_task_setnice
    WRAP_FOR_DETACH(security_task_setnice)
#endif
#ifndef CAN_WRAP_kfree_skb_partial
#   define CAN_WRAP_kfree_skb_partial 1
#endif
#if CAN_WRAP_kfree_skb_partial
    WRAP_FOR_DETACH(kfree_skb_partial)
#endif
#ifndef CAN_WRAP_kobject_set_name
#   define CAN_WRAP_kobject_set_name 1
#endif
#if CAN_WRAP_kobject_set_name
    WRAP_FOR_DETACH(kobject_set_name)
#endif
#ifndef CAN_WRAP_compat_sys_clock_adjtime
#   define CAN_WRAP_compat_sys_clock_adjtime 1
#endif
#if CAN_WRAP_compat_sys_clock_adjtime
    WRAP_FOR_DETACH(compat_sys_clock_adjtime)
#endif
#ifndef CAN_WRAP_mapping_tagged
#   define CAN_WRAP_mapping_tagged 1
#endif
#if CAN_WRAP_mapping_tagged
    WRAP_FOR_DETACH(mapping_tagged)
#endif
#ifndef CAN_WRAP_cgroup_init_early
#   define CAN_WRAP_cgroup_init_early 0
#endif
DETACH(cgroup_init_early)
#ifndef CAN_WRAP_zone_dirty_ok
#   define CAN_WRAP_zone_dirty_ok 1
#endif
#if CAN_WRAP_zone_dirty_ok
    WRAP_FOR_DETACH(zone_dirty_ok)
#endif
#ifndef CAN_WRAP_d_delete
#   define CAN_WRAP_d_delete 1
#endif
#if CAN_WRAP_d_delete
    WRAP_FOR_DETACH(d_delete)
#endif
#ifndef CAN_WRAP_security_shm_free
#   define CAN_WRAP_security_shm_free 1
#endif
#if CAN_WRAP_security_shm_free
    WRAP_FOR_DETACH(security_shm_free)
#endif
#ifndef CAN_WRAP_schedule
#   define CAN_WRAP_schedule 0
#endif
DETACH(schedule)
#ifndef CAN_WRAP_mp_override_legacy_irq
#   define CAN_WRAP_mp_override_legacy_irq 0
#endif
DETACH(mp_override_legacy_irq)
#ifndef CAN_WRAP_setup_boot_APIC_clock
#   define CAN_WRAP_setup_boot_APIC_clock 0
#endif
DETACH(setup_boot_APIC_clock)
#ifndef CAN_WRAP_acpi_pci_register_driver
#   define CAN_WRAP_acpi_pci_register_driver 1
#endif
#if CAN_WRAP_acpi_pci_register_driver
    WRAP_FOR_DETACH(acpi_pci_register_driver)
#endif
#ifndef CAN_WRAP_user_path_at_empty
#   define CAN_WRAP_user_path_at_empty 1
#endif
#if CAN_WRAP_user_path_at_empty
    WRAP_FOR_DETACH(user_path_at_empty)
#endif
#ifndef CAN_WRAP_simple_xattr_get
#   define CAN_WRAP_simple_xattr_get 1
#endif
#if CAN_WRAP_simple_xattr_get
    WRAP_FOR_DETACH(simple_xattr_get)
#endif
#ifndef CAN_WRAP_skb_tx_error
#   define CAN_WRAP_skb_tx_error 1
#endif
#if CAN_WRAP_skb_tx_error
    WRAP_FOR_DETACH(skb_tx_error)
#endif
#ifndef CAN_WRAP_blk_delay_queue
#   define CAN_WRAP_blk_delay_queue 1
#endif
#if CAN_WRAP_blk_delay_queue
    WRAP_FOR_DETACH(blk_delay_queue)
#endif
#ifndef CAN_WRAP_iowrite16be
#   define CAN_WRAP_iowrite16be 0
#endif
DETACH(iowrite16be)
#ifndef CAN_WRAP_disable_TSC
#   define CAN_WRAP_disable_TSC 0
#endif
DETACH(disable_TSC)
#ifndef CAN_WRAP_acpi_table_init
#   define CAN_WRAP_acpi_table_init 0
#endif
DETACH(acpi_table_init)
#ifndef CAN_WRAP_dm_table_complete
#   define CAN_WRAP_dm_table_complete 1
#endif
#if CAN_WRAP_dm_table_complete
    WRAP_FOR_DETACH(dm_table_complete)
#endif
#ifndef CAN_WRAP_jbd2_journal_update_format
#   define CAN_WRAP_jbd2_journal_update_format 1
#endif
#if CAN_WRAP_jbd2_journal_update_format
    WRAP_FOR_DETACH(jbd2_journal_update_format)
#endif
#ifndef CAN_WRAP_security_msg_queue_msgrcv
#   define CAN_WRAP_security_msg_queue_msgrcv 1
#endif
#if CAN_WRAP_security_msg_queue_msgrcv
    WRAP_FOR_DETACH(security_msg_queue_msgrcv)
#endif
#ifndef CAN_WRAP_kobject_action_type
#   define CAN_WRAP_kobject_action_type 0
#endif
DETACH(kobject_action_type)
#ifndef CAN_WRAP_blk_insert_cloned_request
#   define CAN_WRAP_blk_insert_cloned_request 1
#endif
#if CAN_WRAP_blk_insert_cloned_request
    WRAP_FOR_DETACH(blk_insert_cloned_request)
#endif
#ifndef CAN_WRAP_dpm_suspend_start
#   define CAN_WRAP_dpm_suspend_start 1
#endif
#if CAN_WRAP_dpm_suspend_start
    WRAP_FOR_DETACH(dpm_suspend_start)
#endif
#ifndef CAN_WRAP_blk_stack_limits
#   define CAN_WRAP_blk_stack_limits 1
#endif
#if CAN_WRAP_blk_stack_limits
    WRAP_FOR_DETACH(blk_stack_limits)
#endif
#ifndef CAN_WRAP_scsi_scan_host
#   define CAN_WRAP_scsi_scan_host 1
#endif
#if CAN_WRAP_scsi_scan_host
    WRAP_FOR_DETACH(scsi_scan_host)
#endif
#ifndef CAN_WRAP_node_memmap_size_bytes
#   define CAN_WRAP_node_memmap_size_bytes 0
#endif
DETACH(node_memmap_size_bytes)
#ifndef CAN_WRAP_smp_irq_move_cleanup_interrupt
#   define CAN_WRAP_smp_irq_move_cleanup_interrupt 0
#endif
DETACH(smp_irq_move_cleanup_interrupt)
#ifndef CAN_WRAP_security_audit_rule_free
#   define CAN_WRAP_security_audit_rule_free 0
#endif
DETACH(security_audit_rule_free)
#ifndef CAN_WRAP_set_iounmap_nonlazy
#   define CAN_WRAP_set_iounmap_nonlazy 0
#endif
DETACH(set_iounmap_nonlazy)
#ifndef CAN_WRAP_do_sigtimedwait
#   define CAN_WRAP_do_sigtimedwait 1
#endif
#if CAN_WRAP_do_sigtimedwait
    WRAP_FOR_DETACH(do_sigtimedwait)
#endif
#ifndef CAN_WRAP_dma_pool_free
#   define CAN_WRAP_dma_pool_free 1
#endif
#if CAN_WRAP_dma_pool_free
    WRAP_FOR_DETACH(dma_pool_free)
#endif
#ifndef CAN_WRAP___clear_user
#   define CAN_WRAP___clear_user 0
#endif
DETACH(__clear_user)
#ifndef CAN_WRAP_is_mem_section_removable
#   define CAN_WRAP_is_mem_section_removable 0
#endif
DETACH(is_mem_section_removable)
#ifndef CAN_WRAP___init_kthread_worker
#   define CAN_WRAP___init_kthread_worker 1
#endif
#if CAN_WRAP___init_kthread_worker
#   ifdef DETACH_ADDR___init_kthread_worker
        WRAP_FOR_DETACH(__init_kthread_worker)
#   else
        TYPED_DETACH(__init_kthread_worker)
#   endif
#endif
#ifndef CAN_WRAP_cancel_work_sync
#   define CAN_WRAP_cancel_work_sync 1
#endif
#if CAN_WRAP_cancel_work_sync
    WRAP_FOR_DETACH(cancel_work_sync)
#endif
#ifndef CAN_WRAP_linkwatch_forget_dev
#   define CAN_WRAP_linkwatch_forget_dev 1
#endif
#if CAN_WRAP_linkwatch_forget_dev
    WRAP_FOR_DETACH(linkwatch_forget_dev)
#endif
#ifndef CAN_WRAP_init_extra_mapping_wb
#   define CAN_WRAP_init_extra_mapping_wb 0
#endif
DETACH(init_extra_mapping_wb)
#ifndef CAN_WRAP_blk_rq_prep_clone
#   define CAN_WRAP_blk_rq_prep_clone 1
#endif
#if CAN_WRAP_blk_rq_prep_clone
    WRAP_FOR_DETACH(blk_rq_prep_clone)
#endif
#ifndef CAN_WRAP___wake_up_parent
#   define CAN_WRAP___wake_up_parent 1
#endif
#if CAN_WRAP___wake_up_parent
#   ifdef DETACH_ADDR___wake_up_parent
        WRAP_FOR_DETACH(__wake_up_parent)
#   else
        TYPED_DETACH(__wake_up_parent)
#   endif
#endif
#ifndef CAN_WRAP_security_socket_bind
#   define CAN_WRAP_security_socket_bind 1
#endif
#if CAN_WRAP_security_socket_bind
    WRAP_FOR_DETACH(security_socket_bind)
#endif
#ifndef CAN_WRAP_param_get_uint
#   define CAN_WRAP_param_get_uint 1
#endif
#if CAN_WRAP_param_get_uint
    WRAP_FOR_DETACH(param_get_uint)
#endif
#ifndef CAN_WRAP_sscanf
#   define CAN_WRAP_sscanf 0
#endif
DETACH(sscanf)
#ifndef CAN_WRAP_pneigh_for_each
#   define CAN_WRAP_pneigh_for_each 1
#endif
#if CAN_WRAP_pneigh_for_each
    WRAP_FOR_DETACH(pneigh_for_each)
#endif
#ifndef CAN_WRAP_ata_pci_sff_activate_host
#   define CAN_WRAP_ata_pci_sff_activate_host 1
#endif
#if CAN_WRAP_ata_pci_sff_activate_host
    WRAP_FOR_DETACH(ata_pci_sff_activate_host)
#endif
#ifndef CAN_WRAP_argv_split
#   define CAN_WRAP_argv_split 0
#endif
DETACH(argv_split)
#ifndef CAN_WRAP_param_set_invbool
#   define CAN_WRAP_param_set_invbool 1
#endif
#if CAN_WRAP_param_set_invbool
    WRAP_FOR_DETACH(param_set_invbool)
#endif
#ifndef CAN_WRAP_have_submounts
#   define CAN_WRAP_have_submounts 1
#endif
#if CAN_WRAP_have_submounts
    WRAP_FOR_DETACH(have_submounts)
#endif
#ifndef CAN_WRAP_srcu_notifier_chain_register
#   define CAN_WRAP_srcu_notifier_chain_register 1
#endif
#if CAN_WRAP_srcu_notifier_chain_register
    WRAP_FOR_DETACH(srcu_notifier_chain_register)
#endif
#ifndef CAN_WRAP_anon_vma_interval_tree_insert
#   define CAN_WRAP_anon_vma_interval_tree_insert 1
#endif
#if CAN_WRAP_anon_vma_interval_tree_insert
    WRAP_FOR_DETACH(anon_vma_interval_tree_insert)
#endif
#ifndef CAN_WRAP_device_remove_bin_file
#   define CAN_WRAP_device_remove_bin_file 1
#endif
#if CAN_WRAP_device_remove_bin_file
    WRAP_FOR_DETACH(device_remove_bin_file)
#endif
#ifndef CAN_WRAP_wake_up_new_task
#   define CAN_WRAP_wake_up_new_task 1
#endif
#if CAN_WRAP_wake_up_new_task
    WRAP_FOR_DETACH(wake_up_new_task)
#endif
#ifndef CAN_WRAP_skb_append_datato_frags
#   define CAN_WRAP_skb_append_datato_frags 1
#endif
#if CAN_WRAP_skb_append_datato_frags
    WRAP_FOR_DETACH(skb_append_datato_frags)
#endif
#ifndef CAN_WRAP_ktime_get_ts
#   define CAN_WRAP_ktime_get_ts 1
#endif
#if CAN_WRAP_ktime_get_ts
    WRAP_FOR_DETACH(ktime_get_ts)
#endif
#ifndef CAN_WRAP__raw_read_lock
#   define CAN_WRAP__raw_read_lock 1
#endif
#if CAN_WRAP__raw_read_lock
    WRAP_FOR_DETACH(_raw_read_lock)
#endif
#ifndef CAN_WRAP_icmpv6_param_prob
#   define CAN_WRAP_icmpv6_param_prob 1
#endif
#if CAN_WRAP_icmpv6_param_prob
    WRAP_FOR_DETACH(icmpv6_param_prob)
#endif
#ifndef CAN_WRAP_input_get_new_minor
#   define CAN_WRAP_input_get_new_minor 0
#endif
DETACH(input_get_new_minor)
#ifndef CAN_WRAP_security_quota_on
#   define CAN_WRAP_security_quota_on 1
#endif
#if CAN_WRAP_security_quota_on
    WRAP_FOR_DETACH(security_quota_on)
#endif
#ifndef CAN_WRAP_acpi_decode_pld_buffer
#   define CAN_WRAP_acpi_decode_pld_buffer 0
#endif
DETACH(acpi_decode_pld_buffer)
#ifndef CAN_WRAP_mntput
#   define CAN_WRAP_mntput 1
#endif
#if CAN_WRAP_mntput
    WRAP_FOR_DETACH(mntput)
#endif
#ifndef CAN_WRAP_set_personality_64bit
#   define CAN_WRAP_set_personality_64bit 0
#endif
DETACH(set_personality_64bit)
#ifndef CAN_WRAP_symbol_put_addr
#   define CAN_WRAP_symbol_put_addr 0
#endif
DETACH(symbol_put_addr)
#ifndef CAN_WRAP_get_cpu_idle_time_us
#   define CAN_WRAP_get_cpu_idle_time_us 0
#endif
DETACH(get_cpu_idle_time_us)
#ifndef CAN_WRAP_jbd2_journal_revoke
#   define CAN_WRAP_jbd2_journal_revoke 1
#endif
#if CAN_WRAP_jbd2_journal_revoke
    WRAP_FOR_DETACH(jbd2_journal_revoke)
#endif
#ifndef CAN_WRAP_ata_sas_port_init
#   define CAN_WRAP_ata_sas_port_init 1
#endif
#if CAN_WRAP_ata_sas_port_init
    WRAP_FOR_DETACH(ata_sas_port_init)
#endif
#ifndef CAN_WRAP_security_sb_remount
#   define CAN_WRAP_security_sb_remount 1
#endif
#if CAN_WRAP_security_sb_remount
    WRAP_FOR_DETACH(security_sb_remount)
#endif
#ifndef CAN_WRAP_pci_disable_msix
#   define CAN_WRAP_pci_disable_msix 1
#endif
#if CAN_WRAP_pci_disable_msix
    WRAP_FOR_DETACH(pci_disable_msix)
#endif
#ifndef CAN_WRAP_jbd2_journal_get_descriptor_buffer
#   define CAN_WRAP_jbd2_journal_get_descriptor_buffer 1
#endif
#if CAN_WRAP_jbd2_journal_get_descriptor_buffer
    WRAP_FOR_DETACH(jbd2_journal_get_descriptor_buffer)
#endif
#ifndef CAN_WRAP_netdev_boot_setup
#   define CAN_WRAP_netdev_boot_setup 0
#endif
DETACH(netdev_boot_setup)
#ifndef CAN_WRAP_dquot_scan_active
#   define CAN_WRAP_dquot_scan_active 1
#endif
#if CAN_WRAP_dquot_scan_active
    WRAP_FOR_DETACH(dquot_scan_active)
#endif
#ifndef CAN_WRAP_skb_tstamp_tx
#   define CAN_WRAP_skb_tstamp_tx 1
#endif
#if CAN_WRAP_skb_tstamp_tx
    WRAP_FOR_DETACH(skb_tstamp_tx)
#endif
#ifndef CAN_WRAP_security_inode_getattr
#   define CAN_WRAP_security_inode_getattr 1
#endif
#if CAN_WRAP_security_inode_getattr
    WRAP_FOR_DETACH(security_inode_getattr)
#endif
#ifndef CAN_WRAP_seccomp_bpf_load
#   define CAN_WRAP_seccomp_bpf_load 0
#endif
DETACH(seccomp_bpf_load)
#ifndef CAN_WRAP_set_nx
#   define CAN_WRAP_set_nx 0
#endif
DETACH(set_nx)
#ifndef CAN_WRAP_dmam_free_noncoherent
#   define CAN_WRAP_dmam_free_noncoherent 1
#endif
#if CAN_WRAP_dmam_free_noncoherent
    WRAP_FOR_DETACH(dmam_free_noncoherent)
#endif
#ifndef CAN_WRAP_bio_reset
#   define CAN_WRAP_bio_reset 1
#endif
#if CAN_WRAP_bio_reset
    WRAP_FOR_DETACH(bio_reset)
#endif
#ifndef CAN_WRAP_pci_set_ltr
#   define CAN_WRAP_pci_set_ltr 1
#endif
#if CAN_WRAP_pci_set_ltr
    WRAP_FOR_DETACH(pci_set_ltr)
#endif
#ifndef CAN_WRAP_ata_sas_port_start
#   define CAN_WRAP_ata_sas_port_start 1
#endif
#if CAN_WRAP_ata_sas_port_start
    WRAP_FOR_DETACH(ata_sas_port_start)
#endif
#ifndef CAN_WRAP_enable_sep_cpu
#   define CAN_WRAP_enable_sep_cpu 0
#endif
DETACH(enable_sep_cpu)
#ifndef CAN_WRAP_param_set_uint
#   define CAN_WRAP_param_set_uint 1
#endif
#if CAN_WRAP_param_set_uint
    WRAP_FOR_DETACH(param_set_uint)
#endif
#ifndef CAN_WRAP_generic_file_splice_write
#   define CAN_WRAP_generic_file_splice_write 1
#endif
#if CAN_WRAP_generic_file_splice_write
    WRAP_FOR_DETACH(generic_file_splice_write)
#endif
#ifndef CAN_WRAP_pci_device_add
#   define CAN_WRAP_pci_device_add 1
#endif
#if CAN_WRAP_pci_device_add
    WRAP_FOR_DETACH(pci_device_add)
#endif
#ifndef CAN_WRAP_dm_get_mapinfo
#   define CAN_WRAP_dm_get_mapinfo 1
#endif
#if CAN_WRAP_dm_get_mapinfo
    WRAP_FOR_DETACH(dm_get_mapinfo)
#endif
#ifndef CAN_WRAP_skb_complete_tx_timestamp
#   define CAN_WRAP_skb_complete_tx_timestamp 1
#endif
#if CAN_WRAP_skb_complete_tx_timestamp
    WRAP_FOR_DETACH(skb_complete_tx_timestamp)
#endif
#ifndef CAN_WRAP_is_vsmp_box
#   define CAN_WRAP_is_vsmp_box 0
#endif
DETACH(is_vsmp_box)
#ifndef CAN_WRAP_x32_setup_additional_pages
#   define CAN_WRAP_x32_setup_additional_pages 1
#endif
#if CAN_WRAP_x32_setup_additional_pages
    WRAP_FOR_DETACH(x32_setup_additional_pages)
#endif
#ifndef CAN_WRAP_unlock_vector_lock
#   define CAN_WRAP_unlock_vector_lock 0
#endif
DETACH(unlock_vector_lock)
#ifndef CAN_WRAP_pskb_expand_head
#   define CAN_WRAP_pskb_expand_head 1
#endif
#if CAN_WRAP_pskb_expand_head
    WRAP_FOR_DETACH(pskb_expand_head)
#endif
#ifndef CAN_WRAP_percpu_up_write
#   define CAN_WRAP_percpu_up_write 1
#endif
#if CAN_WRAP_percpu_up_write
    WRAP_FOR_DETACH(percpu_up_write)
#endif
#ifndef CAN_WRAP_blk_queue_io_opt
#   define CAN_WRAP_blk_queue_io_opt 1
#endif
#if CAN_WRAP_blk_queue_io_opt
    WRAP_FOR_DETACH(blk_queue_io_opt)
#endif
#ifndef CAN_WRAP_generic_mps_oem_check
#   define CAN_WRAP_generic_mps_oem_check 1
#endif
#if CAN_WRAP_generic_mps_oem_check
    WRAP_FOR_DETACH(generic_mps_oem_check)
#endif
#ifndef CAN_WRAP_free_netdev
#   define CAN_WRAP_free_netdev 1
#endif
#if CAN_WRAP_free_netdev
    WRAP_FOR_DETACH(free_netdev)
#endif
#ifndef CAN_WRAP_inet_frag_destroy
#   define CAN_WRAP_inet_frag_destroy 1
#endif
#if CAN_WRAP_inet_frag_destroy
    WRAP_FOR_DETACH(inet_frag_destroy)
#endif
#ifndef CAN_WRAP_ata_pci_sff_prepare_host
#   define CAN_WRAP_ata_pci_sff_prepare_host 1
#endif
#if CAN_WRAP_ata_pci_sff_prepare_host
    WRAP_FOR_DETACH(ata_pci_sff_prepare_host)
#endif
#ifndef CAN_WRAP_dev_uc_flush
#   define CAN_WRAP_dev_uc_flush 1
#endif
#if CAN_WRAP_dev_uc_flush
    WRAP_FOR_DETACH(dev_uc_flush)
#endif
#ifndef CAN_WRAP_blk_run_queue
#   define CAN_WRAP_blk_run_queue 1
#endif
#if CAN_WRAP_blk_run_queue
    WRAP_FOR_DETACH(blk_run_queue)
#endif
#ifndef CAN_WRAP___pm_stay_awake
#   define CAN_WRAP___pm_stay_awake 1
#endif
#if CAN_WRAP___pm_stay_awake
#   ifdef DETACH_ADDR___pm_stay_awake
        WRAP_FOR_DETACH(__pm_stay_awake)
#   else
        TYPED_DETACH(__pm_stay_awake)
#   endif
#endif
#ifndef CAN_WRAP_generic_block_fiemap
#   define CAN_WRAP_generic_block_fiemap 1
#endif
#if CAN_WRAP_generic_block_fiemap
    WRAP_FOR_DETACH(generic_block_fiemap)
#endif
#ifndef CAN_WRAP_devm_ioport_map
#   define CAN_WRAP_devm_ioport_map 1
#endif
#if CAN_WRAP_devm_ioport_map
    WRAP_FOR_DETACH(devm_ioport_map)
#endif
#ifndef CAN_WRAP_profile_hits
#   define CAN_WRAP_profile_hits 0
#endif
DETACH(profile_hits)
#ifndef CAN_WRAP_acpi_get_pci_rootbridge_handle
#   define CAN_WRAP_acpi_get_pci_rootbridge_handle 0
#endif
DETACH(acpi_get_pci_rootbridge_handle)
#ifndef CAN_WRAP_vfs_cancel_lock
#   define CAN_WRAP_vfs_cancel_lock 1
#endif
#if CAN_WRAP_vfs_cancel_lock
    WRAP_FOR_DETACH(vfs_cancel_lock)
#endif
#ifndef CAN_WRAP_probe_irq_on
#   define CAN_WRAP_probe_irq_on 0
#endif
DETACH(probe_irq_on)
#ifndef CAN_WRAP_cap_capset
#   define CAN_WRAP_cap_capset 1
#endif
#if CAN_WRAP_cap_capset
    WRAP_FOR_DETACH(cap_capset)
#endif
#ifndef CAN_WRAP_find_get_pid
#   define CAN_WRAP_find_get_pid 1
#endif
#if CAN_WRAP_find_get_pid
    WRAP_FOR_DETACH(find_get_pid)
#endif
#ifndef CAN_WRAP___acpi_device_run_wake
#   define CAN_WRAP___acpi_device_run_wake 1
#endif
#if CAN_WRAP___acpi_device_run_wake
#   ifdef DETACH_ADDR___acpi_device_run_wake
        WRAP_FOR_DETACH(__acpi_device_run_wake)
#   else
        TYPED_DETACH(__acpi_device_run_wake)
#   endif
#endif
#ifndef CAN_WRAP_on_each_cpu_cond
#   define CAN_WRAP_on_each_cpu_cond 1
#endif
#if CAN_WRAP_on_each_cpu_cond
    WRAP_FOR_DETACH(on_each_cpu_cond)
#endif
#ifndef CAN_WRAP_mount_nodev
#   define CAN_WRAP_mount_nodev 1
#endif
#if CAN_WRAP_mount_nodev
    WRAP_FOR_DETACH(mount_nodev)
#endif
#ifndef CAN_WRAP___sk_mem_schedule
#   define CAN_WRAP___sk_mem_schedule 1
#endif
#if CAN_WRAP___sk_mem_schedule
#   ifdef DETACH_ADDR___sk_mem_schedule
        WRAP_FOR_DETACH(__sk_mem_schedule)
#   else
        TYPED_DETACH(__sk_mem_schedule)
#   endif
#endif
#ifndef CAN_WRAP_nr_blockdev_pages
#   define CAN_WRAP_nr_blockdev_pages 0
#endif
DETACH(nr_blockdev_pages)
#ifndef CAN_WRAP_skb_seq_read
#   define CAN_WRAP_skb_seq_read 1
#endif
#if CAN_WRAP_skb_seq_read
    WRAP_FOR_DETACH(skb_seq_read)
#endif
#ifndef CAN_WRAP_acpi_evaluate_object_typed
#   define CAN_WRAP_acpi_evaluate_object_typed 1
#endif
#if CAN_WRAP_acpi_evaluate_object_typed
    WRAP_FOR_DETACH(acpi_evaluate_object_typed)
#endif
#ifndef CAN_WRAP_inode_wait
#   define CAN_WRAP_inode_wait 0
#endif
DETACH(inode_wait)
#ifndef CAN_WRAP_ata_sff_queue_work
#   define CAN_WRAP_ata_sff_queue_work 1
#endif
#if CAN_WRAP_ata_sff_queue_work
    WRAP_FOR_DETACH(ata_sff_queue_work)
#endif
#ifndef CAN_WRAP_blk_rq_map_integrity_sg
#   define CAN_WRAP_blk_rq_map_integrity_sg 1
#endif
#if CAN_WRAP_blk_rq_map_integrity_sg
    WRAP_FOR_DETACH(blk_rq_map_integrity_sg)
#endif
#ifndef CAN_WRAP_e820_reserve_resources_late
#   define CAN_WRAP_e820_reserve_resources_late 0
#endif
DETACH(e820_reserve_resources_late)
#ifndef CAN_WRAP__raw_write_unlock_irqrestore
#   define CAN_WRAP__raw_write_unlock_irqrestore 1
#endif
#if CAN_WRAP__raw_write_unlock_irqrestore
    WRAP_FOR_DETACH(_raw_write_unlock_irqrestore)
#endif
#ifndef CAN_WRAP_acpi_install_notify_handler
#   define CAN_WRAP_acpi_install_notify_handler 1
#endif
#if CAN_WRAP_acpi_install_notify_handler
    WRAP_FOR_DETACH(acpi_install_notify_handler)
#endif
#ifndef CAN_WRAP_pm_generic_suspend
#   define CAN_WRAP_pm_generic_suspend 1
#endif
#if CAN_WRAP_pm_generic_suspend
    WRAP_FOR_DETACH(pm_generic_suspend)
#endif
#ifndef CAN_WRAP_dm_get_live_table
#   define CAN_WRAP_dm_get_live_table 1
#endif
#if CAN_WRAP_dm_get_live_table
    WRAP_FOR_DETACH(dm_get_live_table)
#endif
#ifndef CAN_WRAP_d_make_root
#   define CAN_WRAP_d_make_root 1
#endif
#if CAN_WRAP_d_make_root
    WRAP_FOR_DETACH(d_make_root)
#endif
#ifndef CAN_WRAP___hw_addr_flush
#   define CAN_WRAP___hw_addr_flush 1
#endif
#if CAN_WRAP___hw_addr_flush
#   ifdef DETACH_ADDR___hw_addr_flush
        WRAP_FOR_DETACH(__hw_addr_flush)
#   else
        TYPED_DETACH(__hw_addr_flush)
#   endif
#endif
#ifndef CAN_WRAP_acpi_bus_unregister_driver
#   define CAN_WRAP_acpi_bus_unregister_driver 1
#endif
#if CAN_WRAP_acpi_bus_unregister_driver
    WRAP_FOR_DETACH(acpi_bus_unregister_driver)
#endif
#ifndef CAN_WRAP_security_msg_queue_free
#   define CAN_WRAP_security_msg_queue_free 1
#endif
#if CAN_WRAP_security_msg_queue_free
    WRAP_FOR_DETACH(security_msg_queue_free)
#endif
#ifndef CAN_WRAP_generic_mii_ioctl
#   define CAN_WRAP_generic_mii_ioctl 1
#endif
#if CAN_WRAP_generic_mii_ioctl
    WRAP_FOR_DETACH(generic_mii_ioctl)
#endif
#ifndef CAN_WRAP_dev_mc_del
#   define CAN_WRAP_dev_mc_del 1
#endif
#if CAN_WRAP_dev_mc_del
    WRAP_FOR_DETACH(dev_mc_del)
#endif
#ifndef CAN_WRAP_is_valid_bugaddr
#   define CAN_WRAP_is_valid_bugaddr 0
#endif
DETACH(is_valid_bugaddr)
#ifndef CAN_WRAP_arch_unmap_area
#   define CAN_WRAP_arch_unmap_area 1
#endif
#if CAN_WRAP_arch_unmap_area
    WRAP_FOR_DETACH(arch_unmap_area)
#endif
#ifndef CAN_WRAP_down_write_trylock
#   define CAN_WRAP_down_write_trylock 1
#endif
#if CAN_WRAP_down_write_trylock
    WRAP_FOR_DETACH(down_write_trylock)
#endif
#ifndef CAN_WRAP_get_kernel_page
#   define CAN_WRAP_get_kernel_page 0
#endif
DETACH(get_kernel_page)
#ifndef CAN_WRAP_e820_remove_range
#   define CAN_WRAP_e820_remove_range 0
#endif
DETACH(e820_remove_range)
#ifndef CAN_WRAP_acpi_os_open_directory
#   define CAN_WRAP_acpi_os_open_directory 0
#endif
DETACH(acpi_os_open_directory)
#ifndef CAN_WRAP_unregister_acpi_notifier
#   define CAN_WRAP_unregister_acpi_notifier 1
#endif
#if CAN_WRAP_unregister_acpi_notifier
    WRAP_FOR_DETACH(unregister_acpi_notifier)
#endif
#ifndef CAN_WRAP_prepare_to_wait
#   define CAN_WRAP_prepare_to_wait 1
#endif
#if CAN_WRAP_prepare_to_wait
    WRAP_FOR_DETACH(prepare_to_wait)
#endif
#ifndef CAN_WRAP_set_cpu_possible
#   define CAN_WRAP_set_cpu_possible 0
#endif
DETACH(set_cpu_possible)
#ifndef CAN_WRAP_wmi_has_guid
#   define CAN_WRAP_wmi_has_guid 0
#endif
DETACH(wmi_has_guid)
#ifndef CAN_WRAP_blk_queue_find_tag
#   define CAN_WRAP_blk_queue_find_tag 1
#endif
#if CAN_WRAP_blk_queue_find_tag
    WRAP_FOR_DETACH(blk_queue_find_tag)
#endif
#ifndef CAN_WRAP_page_follow_link_light
#   define CAN_WRAP_page_follow_link_light 1
#endif
#if CAN_WRAP_page_follow_link_light
    WRAP_FOR_DETACH(page_follow_link_light)
#endif
#ifndef CAN_WRAP_it_real_fn
#   define CAN_WRAP_it_real_fn 1
#endif
#if CAN_WRAP_it_real_fn
    WRAP_FOR_DETACH(it_real_fn)
#endif
#ifndef CAN_WRAP_apic_is_clustered_box
#   define CAN_WRAP_apic_is_clustered_box 0
#endif
DETACH(apic_is_clustered_box)
#ifndef CAN_WRAP_nla_memcpy
#   define CAN_WRAP_nla_memcpy 1
#endif
#if CAN_WRAP_nla_memcpy
    WRAP_FOR_DETACH(nla_memcpy)
#endif
#ifndef CAN_WRAP_pm_generic_resume
#   define CAN_WRAP_pm_generic_resume 1
#endif
#if CAN_WRAP_pm_generic_resume
    WRAP_FOR_DETACH(pm_generic_resume)
#endif
#ifndef CAN_WRAP_flush_workqueue
#   define CAN_WRAP_flush_workqueue 1
#endif
#if CAN_WRAP_flush_workqueue
    WRAP_FOR_DETACH(flush_workqueue)
#endif
#ifndef CAN_WRAP_do_trace_rcu_torture_read
#   define CAN_WRAP_do_trace_rcu_torture_read 1
#endif
#if CAN_WRAP_do_trace_rcu_torture_read
    WRAP_FOR_DETACH(do_trace_rcu_torture_read)
#endif
#ifndef CAN_WRAP_inode_wait_for_writeback
#   define CAN_WRAP_inode_wait_for_writeback 1
#endif
#if CAN_WRAP_inode_wait_for_writeback
    WRAP_FOR_DETACH(inode_wait_for_writeback)
#endif
#ifndef CAN_WRAP_change_protection
#   define CAN_WRAP_change_protection 1
#endif
#if CAN_WRAP_change_protection
    WRAP_FOR_DETACH(change_protection)
#endif
#ifndef CAN_WRAP_pcibios_setup
#   define CAN_WRAP_pcibios_setup 0
#endif
DETACH(pcibios_setup)
#ifndef CAN_WRAP_acpi_pm_device_sleep_wake
#   define CAN_WRAP_acpi_pm_device_sleep_wake 1
#endif
#if CAN_WRAP_acpi_pm_device_sleep_wake
    WRAP_FOR_DETACH(acpi_pm_device_sleep_wake)
#endif
#ifndef CAN_WRAP_compat_sys_sched_setaffinity
#   define CAN_WRAP_compat_sys_sched_setaffinity 0
#endif
DETACH(compat_sys_sched_setaffinity)
#ifndef CAN_WRAP_rcu_sched_qs
#   define CAN_WRAP_rcu_sched_qs 0
#endif
DETACH(rcu_sched_qs)
#ifndef CAN_WRAP___free_memcg_kmem_pages
#   define CAN_WRAP___free_memcg_kmem_pages 1
#endif
#if CAN_WRAP___free_memcg_kmem_pages
#   ifdef DETACH_ADDR___free_memcg_kmem_pages
        WRAP_FOR_DETACH(__free_memcg_kmem_pages)
#   else
        TYPED_DETACH(__free_memcg_kmem_pages)
#   endif
#endif
#ifndef CAN_WRAP_register_exec_domain
#   define CAN_WRAP_register_exec_domain 1
#endif
#if CAN_WRAP_register_exec_domain
    WRAP_FOR_DETACH(register_exec_domain)
#endif
#ifndef CAN_WRAP_kmem_cache_create
#   define CAN_WRAP_kmem_cache_create 1
#endif
#if CAN_WRAP_kmem_cache_create
    WRAP_FOR_DETACH(kmem_cache_create)
#endif
#ifndef CAN_WRAP_kill_litter_super
#   define CAN_WRAP_kill_litter_super 1
#endif
#if CAN_WRAP_kill_litter_super
    WRAP_FOR_DETACH(kill_litter_super)
#endif
#ifndef CAN_WRAP_qdisc_alloc
#   define CAN_WRAP_qdisc_alloc 1
#endif
#if CAN_WRAP_qdisc_alloc
    WRAP_FOR_DETACH(qdisc_alloc)
#endif
#ifndef CAN_WRAP_idle_task_exit
#   define CAN_WRAP_idle_task_exit 0
#endif
DETACH(idle_task_exit)
#ifndef CAN_WRAP_absent_pages_in_range
#   define CAN_WRAP_absent_pages_in_range 0
#endif
DETACH(absent_pages_in_range)
#ifndef CAN_WRAP_init_intel_cacheinfo
#   define CAN_WRAP_init_intel_cacheinfo 1
#endif
#if CAN_WRAP_init_intel_cacheinfo
    WRAP_FOR_DETACH(init_intel_cacheinfo)
#endif
#ifndef CAN_WRAP_pci_update_resource
#   define CAN_WRAP_pci_update_resource 1
#endif
#if CAN_WRAP_pci_update_resource
    WRAP_FOR_DETACH(pci_update_resource)
#endif
#ifndef CAN_WRAP_jbd2_journal_init_revoke_caches
#   define CAN_WRAP_jbd2_journal_init_revoke_caches 0
#endif
DETACH(jbd2_journal_init_revoke_caches)
#ifndef CAN_WRAP_acpi_os_write_pci_configuration
#   define CAN_WRAP_acpi_os_write_pci_configuration 1
#endif
#if CAN_WRAP_acpi_os_write_pci_configuration
    WRAP_FOR_DETACH(acpi_os_write_pci_configuration)
#endif
#ifndef CAN_WRAP_num_to_str
#   define CAN_WRAP_num_to_str 0
#endif
DETACH(num_to_str)
#ifndef CAN_WRAP___wake_up_sync_key
#   define CAN_WRAP___wake_up_sync_key 1
#endif
#if CAN_WRAP___wake_up_sync_key
#   ifdef DETACH_ADDR___wake_up_sync_key
        WRAP_FOR_DETACH(__wake_up_sync_key)
#   else
        TYPED_DETACH(__wake_up_sync_key)
#   endif
#endif
#ifndef CAN_WRAP_register_filesystem
#   define CAN_WRAP_register_filesystem 1
#endif
#if CAN_WRAP_register_filesystem
    WRAP_FOR_DETACH(register_filesystem)
#endif
#ifndef CAN_WRAP_msecs_to_jiffies
#   define CAN_WRAP_msecs_to_jiffies 0
#endif
DETACH(msecs_to_jiffies)
#ifndef CAN_WRAP_proc_create_data
#   define CAN_WRAP_proc_create_data 1
#endif
#if CAN_WRAP_proc_create_data
    WRAP_FOR_DETACH(proc_create_data)
#endif
#ifndef CAN_WRAP_do_utimes
#   define CAN_WRAP_do_utimes 1
#endif
#if CAN_WRAP_do_utimes
    WRAP_FOR_DETACH(do_utimes)
#endif
#ifndef CAN_WRAP_anon_vma_interval_tree_remove
#   define CAN_WRAP_anon_vma_interval_tree_remove 1
#endif
#if CAN_WRAP_anon_vma_interval_tree_remove
    WRAP_FOR_DETACH(anon_vma_interval_tree_remove)
#endif
#ifndef CAN_WRAP_sock_no_listen
#   define CAN_WRAP_sock_no_listen 1
#endif
#if CAN_WRAP_sock_no_listen
    WRAP_FOR_DETACH(sock_no_listen)
#endif
#ifndef CAN_WRAP_nla_append
#   define CAN_WRAP_nla_append 1
#endif
#if CAN_WRAP_nla_append
    WRAP_FOR_DETACH(nla_append)
#endif
#ifndef CAN_WRAP_mod_delayed_work_on
#   define CAN_WRAP_mod_delayed_work_on 1
#endif
#if CAN_WRAP_mod_delayed_work_on
    WRAP_FOR_DETACH(mod_delayed_work_on)
#endif
#ifndef CAN_WRAP_ata_link_abort
#   define CAN_WRAP_ata_link_abort 1
#endif
#if CAN_WRAP_ata_link_abort
    WRAP_FOR_DETACH(ata_link_abort)
#endif
#ifndef CAN_WRAP_arch_irq_stat
#   define CAN_WRAP_arch_irq_stat 0
#endif
DETACH(arch_irq_stat)
#ifndef CAN_WRAP_ata_sas_slave_configure
#   define CAN_WRAP_ata_sas_slave_configure 1
#endif
#if CAN_WRAP_ata_sas_slave_configure
    WRAP_FOR_DETACH(ata_sas_slave_configure)
#endif
#ifndef CAN_WRAP_task_dirty_inc
#   define CAN_WRAP_task_dirty_inc 1
#endif
#if CAN_WRAP_task_dirty_inc
    WRAP_FOR_DETACH(task_dirty_inc)
#endif
#ifndef CAN_WRAP_compat_nf_getsockopt
#   define CAN_WRAP_compat_nf_getsockopt 1
#endif
#if CAN_WRAP_compat_nf_getsockopt
    WRAP_FOR_DETACH(compat_nf_getsockopt)
#endif
#ifndef CAN_WRAP_cgroup_lock
#   define CAN_WRAP_cgroup_lock 0
#endif
DETACH(cgroup_lock)
#ifndef CAN_WRAP_security_path_unlink
#   define CAN_WRAP_security_path_unlink 1
#endif
#if CAN_WRAP_security_path_unlink
    WRAP_FOR_DETACH(security_path_unlink)
#endif
#ifndef CAN_WRAP_bio_integrity_get_tag
#   define CAN_WRAP_bio_integrity_get_tag 1
#endif
#if CAN_WRAP_bio_integrity_get_tag
    WRAP_FOR_DETACH(bio_integrity_get_tag)
#endif
#ifndef CAN_WRAP_kobject_rename
#   define CAN_WRAP_kobject_rename 1
#endif
#if CAN_WRAP_kobject_rename
    WRAP_FOR_DETACH(kobject_rename)
#endif
#ifndef CAN_WRAP_smp_send_stop
#   define CAN_WRAP_smp_send_stop 0
#endif
DETACH(smp_send_stop)
#ifndef CAN_WRAP_inode_init_always
#   define CAN_WRAP_inode_init_always 1
#endif
#if CAN_WRAP_inode_init_always
    WRAP_FOR_DETACH(inode_init_always)
#endif
#ifndef CAN_WRAP_pci_user_read_config_word
#   define CAN_WRAP_pci_user_read_config_word 1
#endif
#if CAN_WRAP_pci_user_read_config_word
    WRAP_FOR_DETACH(pci_user_read_config_word)
#endif
#ifndef CAN_WRAP_write_dirty_buffer
#   define CAN_WRAP_write_dirty_buffer 1
#endif
#if CAN_WRAP_write_dirty_buffer
    WRAP_FOR_DETACH(write_dirty_buffer)
#endif
#ifndef CAN_WRAP___bad_udelay
#   define CAN_WRAP___bad_udelay 0
#endif
DETACH(__bad_udelay)
#ifndef CAN_WRAP_inet_csk_clear_xmit_timers
#   define CAN_WRAP_inet_csk_clear_xmit_timers 1
#endif
#if CAN_WRAP_inet_csk_clear_xmit_timers
    WRAP_FOR_DETACH(inet_csk_clear_xmit_timers)
#endif
#ifndef CAN_WRAP_vm_insert_mixed
#   define CAN_WRAP_vm_insert_mixed 1
#endif
#if CAN_WRAP_vm_insert_mixed
    WRAP_FOR_DETACH(vm_insert_mixed)
#endif
#ifndef CAN_WRAP_fcntl_getlk
#   define CAN_WRAP_fcntl_getlk 1
#endif
#if CAN_WRAP_fcntl_getlk
    WRAP_FOR_DETACH(fcntl_getlk)
#endif
#ifndef CAN_WRAP_inode_permission
#   define CAN_WRAP_inode_permission 1
#endif
#if CAN_WRAP_inode_permission
    WRAP_FOR_DETACH(inode_permission)
#endif
#ifndef CAN_WRAP_wmi_install_notify_handler
#   define CAN_WRAP_wmi_install_notify_handler 1
#endif
#if CAN_WRAP_wmi_install_notify_handler
    WRAP_FOR_DETACH(wmi_install_notify_handler)
#endif
#ifndef CAN_WRAP_pci_find_next_capability
#   define CAN_WRAP_pci_find_next_capability 1
#endif
#if CAN_WRAP_pci_find_next_capability
    WRAP_FOR_DETACH(pci_find_next_capability)
#endif
#ifndef CAN_WRAP_match_strlcpy
#   define CAN_WRAP_match_strlcpy 1
#endif
#if CAN_WRAP_match_strlcpy
    WRAP_FOR_DETACH(match_strlcpy)
#endif
#ifndef CAN_WRAP_dquot_disable
#   define CAN_WRAP_dquot_disable 1
#endif
#if CAN_WRAP_dquot_disable
    WRAP_FOR_DETACH(dquot_disable)
#endif
#ifndef CAN_WRAP_security_inode_mkdir
#   define CAN_WRAP_security_inode_mkdir 1
#endif
#if CAN_WRAP_security_inode_mkdir
    WRAP_FOR_DETACH(security_inode_mkdir)
#endif
#ifndef CAN_WRAP_bitmap_find_next_zero_area
#   define CAN_WRAP_bitmap_find_next_zero_area 0
#endif
DETACH(bitmap_find_next_zero_area)
#ifndef CAN_WRAP_swapcache_prepare
#   define CAN_WRAP_swapcache_prepare 1
#endif
#if CAN_WRAP_swapcache_prepare
    WRAP_FOR_DETACH(swapcache_prepare)
#endif
#ifndef CAN_WRAP_vwrite
#   define CAN_WRAP_vwrite 0
#endif
DETACH(vwrite)
#ifndef CAN_WRAP_pcix_set_mmrbc
#   define CAN_WRAP_pcix_set_mmrbc 1
#endif
#if CAN_WRAP_pcix_set_mmrbc
    WRAP_FOR_DETACH(pcix_set_mmrbc)
#endif
#ifndef CAN_WRAP_vmemmap_populate
#   define CAN_WRAP_vmemmap_populate 1
#endif
#if CAN_WRAP_vmemmap_populate
    WRAP_FOR_DETACH(vmemmap_populate)
#endif
#ifndef CAN_WRAP_get_task_mm
#   define CAN_WRAP_get_task_mm 1
#endif
#if CAN_WRAP_get_task_mm
    WRAP_FOR_DETACH(get_task_mm)
#endif
#ifndef CAN_WRAP_disable_ioapic_support
#   define CAN_WRAP_disable_ioapic_support 0
#endif
DETACH(disable_ioapic_support)
#ifndef CAN_WRAP_strncpy
#   define CAN_WRAP_strncpy 0
#endif
DETACH(strncpy)
#ifndef CAN_WRAP_pci_acpi_scan_root
#   define CAN_WRAP_pci_acpi_scan_root 1
#endif
#if CAN_WRAP_pci_acpi_scan_root
    WRAP_FOR_DETACH(pci_acpi_scan_root)
#endif
#ifndef CAN_WRAP_device_set_wakeup_enable
#   define CAN_WRAP_device_set_wakeup_enable 1
#endif
#if CAN_WRAP_device_set_wakeup_enable
    WRAP_FOR_DETACH(device_set_wakeup_enable)
#endif
#ifndef CAN_WRAP_crypto_register_alg
#   define CAN_WRAP_crypto_register_alg 1
#endif
#if CAN_WRAP_crypto_register_alg
    WRAP_FOR_DETACH(crypto_register_alg)
#endif
#ifndef CAN_WRAP_sched_create_group
#   define CAN_WRAP_sched_create_group 1
#endif
#if CAN_WRAP_sched_create_group
    WRAP_FOR_DETACH(sched_create_group)
#endif
#ifndef CAN_WRAP_qtree_read_dquot
#   define CAN_WRAP_qtree_read_dquot 1
#endif
#if CAN_WRAP_qtree_read_dquot
    WRAP_FOR_DETACH(qtree_read_dquot)
#endif
#ifndef CAN_WRAP_pci_renumber_slot
#   define CAN_WRAP_pci_renumber_slot 1
#endif
#if CAN_WRAP_pci_renumber_slot
    WRAP_FOR_DETACH(pci_renumber_slot)
#endif
#ifndef CAN_WRAP_key_link
#   define CAN_WRAP_key_link 1
#endif
#if CAN_WRAP_key_link
    WRAP_FOR_DETACH(key_link)
#endif
#ifndef CAN_WRAP_free_vm_area
#   define CAN_WRAP_free_vm_area 1
#endif
#if CAN_WRAP_free_vm_area
    WRAP_FOR_DETACH(free_vm_area)
#endif
#ifndef CAN_WRAP_dirty_bytes_handler
#   define CAN_WRAP_dirty_bytes_handler 1
#endif
#if CAN_WRAP_dirty_bytes_handler
    WRAP_FOR_DETACH(dirty_bytes_handler)
#endif
#ifndef CAN_WRAP_pci_bus_size_bridges
#   define CAN_WRAP_pci_bus_size_bridges 1
#endif
#if CAN_WRAP_pci_bus_size_bridges
    WRAP_FOR_DETACH(pci_bus_size_bridges)
#endif
#ifndef CAN_WRAP_blk_queue_bounce
#   define CAN_WRAP_blk_queue_bounce 1
#endif
#if CAN_WRAP_blk_queue_bounce
    WRAP_FOR_DETACH(blk_queue_bounce)
#endif
#ifndef CAN_WRAP_block_read_full_page
#   define CAN_WRAP_block_read_full_page 1
#endif
#if CAN_WRAP_block_read_full_page
    WRAP_FOR_DETACH(block_read_full_page)
#endif
#ifndef CAN_WRAP_ata_sas_queuecmd
#   define CAN_WRAP_ata_sas_queuecmd 1
#endif
#if CAN_WRAP_ata_sas_queuecmd
    WRAP_FOR_DETACH(ata_sas_queuecmd)
#endif
#ifndef CAN_WRAP_socket_seq_show
#   define CAN_WRAP_socket_seq_show 1
#endif
#if CAN_WRAP_socket_seq_show
    WRAP_FOR_DETACH(socket_seq_show)
#endif
#ifndef CAN_WRAP_add_range_with_merge
#   define CAN_WRAP_add_range_with_merge 1
#endif
#if CAN_WRAP_add_range_with_merge
    WRAP_FOR_DETACH(add_range_with_merge)
#endif
#ifndef CAN_WRAP_user_path_create
#   define CAN_WRAP_user_path_create 1
#endif
#if CAN_WRAP_user_path_create
    WRAP_FOR_DETACH(user_path_create)
#endif
#ifndef CAN_WRAP_radix_tree_gang_lookup_tag
#   define CAN_WRAP_radix_tree_gang_lookup_tag 1
#endif
#if CAN_WRAP_radix_tree_gang_lookup_tag
    WRAP_FOR_DETACH(radix_tree_gang_lookup_tag)
#endif
#ifndef CAN_WRAP_neigh_seq_stop
#   define CAN_WRAP_neigh_seq_stop 1
#endif
#if CAN_WRAP_neigh_seq_stop
    WRAP_FOR_DETACH(neigh_seq_stop)
#endif
#ifndef CAN_WRAP_ioctl_preallocate
#   define CAN_WRAP_ioctl_preallocate 1
#endif
#if CAN_WRAP_ioctl_preallocate
    WRAP_FOR_DETACH(ioctl_preallocate)
#endif
#ifndef CAN_WRAP_kthread_stop
#   define CAN_WRAP_kthread_stop 1
#endif
#if CAN_WRAP_kthread_stop
    WRAP_FOR_DETACH(kthread_stop)
#endif
#ifndef CAN_WRAP_wakeup_source_remove
#   define CAN_WRAP_wakeup_source_remove 1
#endif
#if CAN_WRAP_wakeup_source_remove
    WRAP_FOR_DETACH(wakeup_source_remove)
#endif
#ifndef CAN_WRAP_xen_hvm_need_lapic
#   define CAN_WRAP_xen_hvm_need_lapic 0
#endif
DETACH(xen_hvm_need_lapic)
#ifndef CAN_WRAP_sk_set_memalloc
#   define CAN_WRAP_sk_set_memalloc 1
#endif
#if CAN_WRAP_sk_set_memalloc
    WRAP_FOR_DETACH(sk_set_memalloc)
#endif
#ifndef CAN_WRAP_blk_stop_queue
#   define CAN_WRAP_blk_stop_queue 1
#endif
#if CAN_WRAP_blk_stop_queue
    WRAP_FOR_DETACH(blk_stop_queue)
#endif
#ifndef CAN_WRAP_jbd2_journal_errno
#   define CAN_WRAP_jbd2_journal_errno 1
#endif
#if CAN_WRAP_jbd2_journal_errno
    WRAP_FOR_DETACH(jbd2_journal_errno)
#endif
#ifndef CAN_WRAP_find_get_pages
#   define CAN_WRAP_find_get_pages 1
#endif
#if CAN_WRAP_find_get_pages
    WRAP_FOR_DETACH(find_get_pages)
#endif
#ifndef CAN_WRAP_security_inode_getxattr
#   define CAN_WRAP_security_inode_getxattr 1
#endif
#if CAN_WRAP_security_inode_getxattr
    WRAP_FOR_DETACH(security_inode_getxattr)
#endif
#ifndef CAN_WRAP_submit_bh
#   define CAN_WRAP_submit_bh 1
#endif
#if CAN_WRAP_submit_bh
    WRAP_FOR_DETACH(submit_bh)
#endif
#ifndef CAN_WRAP_early_reserve_e820_mpc_new
#   define CAN_WRAP_early_reserve_e820_mpc_new 0
#endif
DETACH(early_reserve_e820_mpc_new)
#ifndef CAN_WRAP_security_file_fcntl
#   define CAN_WRAP_security_file_fcntl 1
#endif
#if CAN_WRAP_security_file_fcntl
    WRAP_FOR_DETACH(security_file_fcntl)
#endif
#ifndef CAN_WRAP_iter_div_u64_rem
#   define CAN_WRAP_iter_div_u64_rem 0
#endif
DETACH(iter_div_u64_rem)
#ifndef CAN_WRAP_pci_bus_read_config_word
#   define CAN_WRAP_pci_bus_read_config_word 1
#endif
#if CAN_WRAP_pci_bus_read_config_word
    WRAP_FOR_DETACH(pci_bus_read_config_word)
#endif
#ifndef CAN_WRAP_find_task_by_vpid
#   define CAN_WRAP_find_task_by_vpid 1
#endif
#if CAN_WRAP_find_task_by_vpid
    WRAP_FOR_DETACH(find_task_by_vpid)
#endif
#ifndef CAN_WRAP_vlan_dev_vlan_id
#   define CAN_WRAP_vlan_dev_vlan_id 1
#endif
#if CAN_WRAP_vlan_dev_vlan_id
    WRAP_FOR_DETACH(vlan_dev_vlan_id)
#endif
#ifndef CAN_WRAP_single_open_net
#   define CAN_WRAP_single_open_net 1
#endif
#if CAN_WRAP_single_open_net
    WRAP_FOR_DETACH(single_open_net)
#endif
#ifndef CAN_WRAP_release_child_resources
#   define CAN_WRAP_release_child_resources 1
#endif
#if CAN_WRAP_release_child_resources
    WRAP_FOR_DETACH(release_child_resources)
#endif
#ifndef CAN_WRAP_security_cred_free
#   define CAN_WRAP_security_cred_free 1
#endif
#if CAN_WRAP_security_cred_free
    WRAP_FOR_DETACH(security_cred_free)
#endif
#ifndef CAN_WRAP_default_mpc_oem_bus_info
#   define CAN_WRAP_default_mpc_oem_bus_info 1
#endif
#if CAN_WRAP_default_mpc_oem_bus_info
    WRAP_FOR_DETACH(default_mpc_oem_bus_info)
#endif
#ifndef CAN_WRAP_clockevents_suspend
#   define CAN_WRAP_clockevents_suspend 0
#endif
DETACH(clockevents_suspend)
#ifndef CAN_WRAP_net_ratelimit
#   define CAN_WRAP_net_ratelimit 0
#endif
DETACH(net_ratelimit)
#ifndef CAN_WRAP___blk_end_request
#   define CAN_WRAP___blk_end_request 1
#endif
#if CAN_WRAP___blk_end_request
#   ifdef DETACH_ADDR___blk_end_request
        WRAP_FOR_DETACH(__blk_end_request)
#   else
        TYPED_DETACH(__blk_end_request)
#   endif
#endif
#ifndef CAN_WRAP_netdev_alloc_frag
#   define CAN_WRAP_netdev_alloc_frag 0
#endif
DETACH(netdev_alloc_frag)
#ifndef CAN_WRAP_dpm_suspend
#   define CAN_WRAP_dpm_suspend 1
#endif
#if CAN_WRAP_dpm_suspend
    WRAP_FOR_DETACH(dpm_suspend)
#endif
#ifndef CAN_WRAP_mount_bdev
#   define CAN_WRAP_mount_bdev 1
#endif
#if CAN_WRAP_mount_bdev
    WRAP_FOR_DETACH(mount_bdev)
#endif
#ifndef CAN_WRAP___bitmap_weight
#   define CAN_WRAP___bitmap_weight 0
#endif
DETACH(__bitmap_weight)
#ifndef CAN_WRAP_init_extra_mapping_uc
#   define CAN_WRAP_init_extra_mapping_uc 0
#endif
DETACH(init_extra_mapping_uc)
#ifndef CAN_WRAP_ioread32_rep
#   define CAN_WRAP_ioread32_rep 0
#endif
DETACH(ioread32_rep)
#ifndef CAN_WRAP_inc_nlink
#   define CAN_WRAP_inc_nlink 1
#endif
#if CAN_WRAP_inc_nlink
    WRAP_FOR_DETACH(inc_nlink)
#endif
#ifndef CAN_WRAP_crypto_alloc_aead
#   define CAN_WRAP_crypto_alloc_aead 1
#endif
#if CAN_WRAP_crypto_alloc_aead
    WRAP_FOR_DETACH(crypto_alloc_aead)
#endif
#ifndef CAN_WRAP_ata_link_offline
#   define CAN_WRAP_ata_link_offline 1
#endif
#if CAN_WRAP_ata_link_offline
    WRAP_FOR_DETACH(ata_link_offline)
#endif
#ifndef CAN_WRAP_warn_slowpath_fmt
#   define CAN_WRAP_warn_slowpath_fmt 0
#endif
DETACH(warn_slowpath_fmt)
#ifndef CAN_WRAP_pci_check_and_unmask_intx
#   define CAN_WRAP_pci_check_and_unmask_intx 1
#endif
#if CAN_WRAP_pci_check_and_unmask_intx
    WRAP_FOR_DETACH(pci_check_and_unmask_intx)
#endif
#ifndef CAN_WRAP_d_rehash
#   define CAN_WRAP_d_rehash 1
#endif
#if CAN_WRAP_d_rehash
    WRAP_FOR_DETACH(d_rehash)
#endif
#ifndef CAN_WRAP_rb_replace_node
#   define CAN_WRAP_rb_replace_node 1
#endif
#if CAN_WRAP_rb_replace_node
    WRAP_FOR_DETACH(rb_replace_node)
#endif
#ifndef CAN_WRAP__raw_write_lock
#   define CAN_WRAP__raw_write_lock 1
#endif
#if CAN_WRAP__raw_write_lock
    WRAP_FOR_DETACH(_raw_write_lock)
#endif
#ifndef CAN_WRAP_find_first_bit
#   define CAN_WRAP_find_first_bit 0
#endif
DETACH(find_first_bit)
#ifndef CAN_WRAP_is_pageblock_removable_nolock
#   define CAN_WRAP_is_pageblock_removable_nolock 1
#endif
#if CAN_WRAP_is_pageblock_removable_nolock
    WRAP_FOR_DETACH(is_pageblock_removable_nolock)
#endif
#ifndef CAN_WRAP_pci_ioremap_bar
#   define CAN_WRAP_pci_ioremap_bar 1
#endif
#if CAN_WRAP_pci_ioremap_bar
    WRAP_FOR_DETACH(pci_ioremap_bar)
#endif
#ifndef CAN_WRAP_get_pageblock_flags_group
#   define CAN_WRAP_get_pageblock_flags_group 1
#endif
#if CAN_WRAP_get_pageblock_flags_group
    WRAP_FOR_DETACH(get_pageblock_flags_group)
#endif
#ifndef CAN_WRAP_dynamic_dname
#   define CAN_WRAP_dynamic_dname 1
#endif
#if CAN_WRAP_dynamic_dname
    WRAP_FOR_DETACH(dynamic_dname)
#endif
#ifndef CAN_WRAP_nf_register_sockopt
#   define CAN_WRAP_nf_register_sockopt 1
#endif
#if CAN_WRAP_nf_register_sockopt
    WRAP_FOR_DETACH(nf_register_sockopt)
#endif
#ifndef CAN_WRAP_e820_all_mapped
#   define CAN_WRAP_e820_all_mapped 0
#endif
DETACH(e820_all_mapped)
#ifndef CAN_WRAP___jbd2_journal_insert_checkpoint
#   define CAN_WRAP___jbd2_journal_insert_checkpoint 1
#endif
#if CAN_WRAP___jbd2_journal_insert_checkpoint
#   ifdef DETACH_ADDR___jbd2_journal_insert_checkpoint
        WRAP_FOR_DETACH(__jbd2_journal_insert_checkpoint)
#   else
        TYPED_DETACH(__jbd2_journal_insert_checkpoint)
#   endif
#endif
#ifndef CAN_WRAP_idr_get_next
#   define CAN_WRAP_idr_get_next 1
#endif
#if CAN_WRAP_idr_get_next
    WRAP_FOR_DETACH(idr_get_next)
#endif
#ifndef CAN_WRAP_iomem_map_sanity_check
#   define CAN_WRAP_iomem_map_sanity_check 0
#endif
DETACH(iomem_map_sanity_check)
#ifndef CAN_WRAP_remove_wait_queue
#   define CAN_WRAP_remove_wait_queue 1
#endif
#if CAN_WRAP_remove_wait_queue
    WRAP_FOR_DETACH(remove_wait_queue)
#endif
#ifndef CAN_WRAP_gnet_stats_copy_basic
#   define CAN_WRAP_gnet_stats_copy_basic 1
#endif
#if CAN_WRAP_gnet_stats_copy_basic
    WRAP_FOR_DETACH(gnet_stats_copy_basic)
#endif
#ifndef CAN_WRAP_pnp_stop_dev
#   define CAN_WRAP_pnp_stop_dev 1
#endif
#if CAN_WRAP_pnp_stop_dev
    WRAP_FOR_DETACH(pnp_stop_dev)
#endif
#ifndef CAN_WRAP_mangle_path
#   define CAN_WRAP_mangle_path 0
#endif
DETACH(mangle_path)
#ifndef CAN_WRAP_sock_alloc_send_pskb
#   define CAN_WRAP_sock_alloc_send_pskb 1
#endif
#if CAN_WRAP_sock_alloc_send_pskb
    WRAP_FOR_DETACH(sock_alloc_send_pskb)
#endif
#ifndef CAN_WRAP_tasklet_init
#   define CAN_WRAP_tasklet_init 1
#endif
#if CAN_WRAP_tasklet_init
    WRAP_FOR_DETACH(tasklet_init)
#endif
#ifndef CAN_WRAP_pci_dev_specific_acs_enabled
#   define CAN_WRAP_pci_dev_specific_acs_enabled 1
#endif
#if CAN_WRAP_pci_dev_specific_acs_enabled
    WRAP_FOR_DETACH(pci_dev_specific_acs_enabled)
#endif
#ifndef CAN_WRAP_profile_setup
#   define CAN_WRAP_profile_setup 0
#endif
DETACH(profile_setup)
#ifndef CAN_WRAP_create_irq
#   define CAN_WRAP_create_irq 0
#endif
DETACH(create_irq)
#ifndef CAN_WRAP_device_initialize
#   define CAN_WRAP_device_initialize 1
#endif
#if CAN_WRAP_device_initialize
    WRAP_FOR_DETACH(device_initialize)
#endif
#ifndef CAN_WRAP_skb_prepare_seq_read
#   define CAN_WRAP_skb_prepare_seq_read 1
#endif
#if CAN_WRAP_skb_prepare_seq_read
    WRAP_FOR_DETACH(skb_prepare_seq_read)
#endif
#ifndef CAN_WRAP_mm_drop_all_locks
#   define CAN_WRAP_mm_drop_all_locks 1
#endif
#if CAN_WRAP_mm_drop_all_locks
    WRAP_FOR_DETACH(mm_drop_all_locks)
#endif
#ifndef CAN_WRAP_unhandled_signal
#   define CAN_WRAP_unhandled_signal 1
#endif
#if CAN_WRAP_unhandled_signal
    WRAP_FOR_DETACH(unhandled_signal)
#endif
#ifndef CAN_WRAP_on_each_cpu_mask
#   define CAN_WRAP_on_each_cpu_mask 1
#endif
#if CAN_WRAP_on_each_cpu_mask
    WRAP_FOR_DETACH(on_each_cpu_mask)
#endif
#ifndef CAN_WRAP_strcat
#   define CAN_WRAP_strcat 0
#endif
DETACH(strcat)
#ifndef CAN_WRAP_sysrq_timer_list_show
#   define CAN_WRAP_sysrq_timer_list_show 0
#endif
DETACH(sysrq_timer_list_show)
#ifndef CAN_WRAP_native_patch
#   define CAN_WRAP_native_patch 0
#endif
DETACH(native_patch)
#ifndef CAN_WRAP_input_ff_erase
#   define CAN_WRAP_input_ff_erase 1
#endif
#if CAN_WRAP_input_ff_erase
    WRAP_FOR_DETACH(input_ff_erase)
#endif
#ifndef CAN_WRAP___task_pid_nr_ns
#   define CAN_WRAP___task_pid_nr_ns 1
#endif
#if CAN_WRAP___task_pid_nr_ns
#   ifdef DETACH_ADDR___task_pid_nr_ns
        WRAP_FOR_DETACH(__task_pid_nr_ns)
#   else
        TYPED_DETACH(__task_pid_nr_ns)
#   endif
#endif
#ifndef CAN_WRAP_pci_pme_capable
#   define CAN_WRAP_pci_pme_capable 1
#endif
#if CAN_WRAP_pci_pme_capable
    WRAP_FOR_DETACH(pci_pme_capable)
#endif
#ifndef CAN_WRAP_phy_driver_register
#   define CAN_WRAP_phy_driver_register 1
#endif
#if CAN_WRAP_phy_driver_register
    WRAP_FOR_DETACH(phy_driver_register)
#endif
#ifndef CAN_WRAP_tasklet_kill
#   define CAN_WRAP_tasklet_kill 1
#endif
#if CAN_WRAP_tasklet_kill
    WRAP_FOR_DETACH(tasklet_kill)
#endif
#ifndef CAN_WRAP_pci_target_state
#   define CAN_WRAP_pci_target_state 1
#endif
#if CAN_WRAP_pci_target_state
    WRAP_FOR_DETACH(pci_target_state)
#endif
#ifndef CAN_WRAP_dev_pm_qos_hide_flags
#   define CAN_WRAP_dev_pm_qos_hide_flags 1
#endif
#if CAN_WRAP_dev_pm_qos_hide_flags
    WRAP_FOR_DETACH(dev_pm_qos_hide_flags)
#endif
#ifndef CAN_WRAP_unregister_shrinker
#   define CAN_WRAP_unregister_shrinker 1
#endif
#if CAN_WRAP_unregister_shrinker
    WRAP_FOR_DETACH(unregister_shrinker)
#endif
#ifndef CAN_WRAP_laptop_mode_sync
#   define CAN_WRAP_laptop_mode_sync 1
#endif
#if CAN_WRAP_laptop_mode_sync
    WRAP_FOR_DETACH(laptop_mode_sync)
#endif
#ifndef CAN_WRAP_smp_prepare_cpus
#   define CAN_WRAP_smp_prepare_cpus 0
#endif
DETACH(smp_prepare_cpus)
#ifndef CAN_WRAP_irq_modify_status
#   define CAN_WRAP_irq_modify_status 0
#endif
DETACH(irq_modify_status)
#ifndef CAN_WRAP_pcpu_setup_first_chunk
#   define CAN_WRAP_pcpu_setup_first_chunk 1
#endif
#if CAN_WRAP_pcpu_setup_first_chunk
    WRAP_FOR_DETACH(pcpu_setup_first_chunk)
#endif
#ifndef CAN_WRAP_netif_set_real_num_rx_queues
#   define CAN_WRAP_netif_set_real_num_rx_queues 1
#endif
#if CAN_WRAP_netif_set_real_num_rx_queues
    WRAP_FOR_DETACH(netif_set_real_num_rx_queues)
#endif
#ifndef CAN_WRAP_clflush_cache_range
#   define CAN_WRAP_clflush_cache_range 0
#endif
DETACH(clflush_cache_range)
#ifndef CAN_WRAP_device_schedule_callback_owner
#   define CAN_WRAP_device_schedule_callback_owner 1
#endif
#if CAN_WRAP_device_schedule_callback_owner
    WRAP_FOR_DETACH(device_schedule_callback_owner)
#endif
#ifndef CAN_WRAP_security_task_kill
#   define CAN_WRAP_security_task_kill 1
#endif
#if CAN_WRAP_security_task_kill
    WRAP_FOR_DETACH(security_task_kill)
#endif
#ifndef CAN_WRAP_register_shrinker
#   define CAN_WRAP_register_shrinker 1
#endif
#if CAN_WRAP_register_shrinker
    WRAP_FOR_DETACH(register_shrinker)
#endif
#ifndef CAN_WRAP___init_rwsem
#   define CAN_WRAP___init_rwsem 1
#endif
#if CAN_WRAP___init_rwsem
#   ifdef DETACH_ADDR___init_rwsem
        WRAP_FOR_DETACH(__init_rwsem)
#   else
        TYPED_DETACH(__init_rwsem)
#   endif
#endif
#ifndef CAN_WRAP_sock_tx_timestamp
#   define CAN_WRAP_sock_tx_timestamp 1
#endif
#if CAN_WRAP_sock_tx_timestamp
    WRAP_FOR_DETACH(sock_tx_timestamp)
#endif
#ifndef CAN_WRAP_early_iounmap
#   define CAN_WRAP_early_iounmap 0
#endif
DETACH(early_iounmap)
#ifndef CAN_WRAP_dev_change_net_namespace
#   define CAN_WRAP_dev_change_net_namespace 1
#endif
#if CAN_WRAP_dev_change_net_namespace
    WRAP_FOR_DETACH(dev_change_net_namespace)
#endif
#ifndef CAN_WRAP_input_ff_create
#   define CAN_WRAP_input_ff_create 1
#endif
#if CAN_WRAP_input_ff_create
    WRAP_FOR_DETACH(input_ff_create)
#endif
#ifndef CAN_WRAP_free_inode_nonrcu
#   define CAN_WRAP_free_inode_nonrcu 1
#endif
#if CAN_WRAP_free_inode_nonrcu
    WRAP_FOR_DETACH(free_inode_nonrcu)
#endif
#ifndef CAN_WRAP_blk_queue_dma_pad
#   define CAN_WRAP_blk_queue_dma_pad 1
#endif
#if CAN_WRAP_blk_queue_dma_pad
    WRAP_FOR_DETACH(blk_queue_dma_pad)
#endif
#ifndef CAN_WRAP_compat_sys_newfstatat
#   define CAN_WRAP_compat_sys_newfstatat 1
#endif
#if CAN_WRAP_compat_sys_newfstatat
    WRAP_FOR_DETACH(compat_sys_newfstatat)
#endif
#ifndef CAN_WRAP_setup_per_zone_wmarks
#   define CAN_WRAP_setup_per_zone_wmarks 0
#endif
DETACH(setup_per_zone_wmarks)
#ifndef CAN_WRAP_driver_init
#   define CAN_WRAP_driver_init 0
#endif
DETACH(driver_init)
#ifndef CAN_WRAP_insert_inode_locked4
#   define CAN_WRAP_insert_inode_locked4 1
#endif
#if CAN_WRAP_insert_inode_locked4
    WRAP_FOR_DETACH(insert_inode_locked4)
#endif
#ifndef CAN_WRAP_compat_sys_clock_getres
#   define CAN_WRAP_compat_sys_clock_getres 1
#endif
#if CAN_WRAP_compat_sys_clock_getres
    WRAP_FOR_DETACH(compat_sys_clock_getres)
#endif
#ifndef CAN_WRAP_fiemap_check_flags
#   define CAN_WRAP_fiemap_check_flags 1
#endif
#if CAN_WRAP_fiemap_check_flags
    WRAP_FOR_DETACH(fiemap_check_flags)
#endif
#ifndef CAN_WRAP_timekeeping_init
#   define CAN_WRAP_timekeeping_init 0
#endif
DETACH(timekeeping_init)
#ifndef CAN_WRAP_pci_remove_bus
#   define CAN_WRAP_pci_remove_bus 1
#endif
#if CAN_WRAP_pci_remove_bus
    WRAP_FOR_DETACH(pci_remove_bus)
#endif
#ifndef CAN_WRAP_neigh_event_ns
#   define CAN_WRAP_neigh_event_ns 1
#endif
#if CAN_WRAP_neigh_event_ns
    WRAP_FOR_DETACH(neigh_event_ns)
#endif
#ifndef CAN_WRAP_compat_rw_copy_check_uvector
#   define CAN_WRAP_compat_rw_copy_check_uvector 1
#endif
#if CAN_WRAP_compat_rw_copy_check_uvector
    WRAP_FOR_DETACH(compat_rw_copy_check_uvector)
#endif
#ifndef CAN_WRAP_add_wait_queue
#   define CAN_WRAP_add_wait_queue 1
#endif
#if CAN_WRAP_add_wait_queue
    WRAP_FOR_DETACH(add_wait_queue)
#endif
#ifndef CAN_WRAP___bitmap_intersects
#   define CAN_WRAP___bitmap_intersects 0
#endif
DETACH(__bitmap_intersects)
#ifndef CAN_WRAP_pcpu_free_vm_areas
#   define CAN_WRAP_pcpu_free_vm_areas 0
#endif
DETACH(pcpu_free_vm_areas)
#ifndef CAN_WRAP_posix_test_lock
#   define CAN_WRAP_posix_test_lock 1
#endif
#if CAN_WRAP_posix_test_lock
    WRAP_FOR_DETACH(posix_test_lock)
#endif
#ifndef CAN_WRAP_init_currently_empty_zone
#   define CAN_WRAP_init_currently_empty_zone 1
#endif
#if CAN_WRAP_init_currently_empty_zone
    WRAP_FOR_DETACH(init_currently_empty_zone)
#endif
#ifndef CAN_WRAP___bitmap_complement
#   define CAN_WRAP___bitmap_complement 0
#endif
DETACH(__bitmap_complement)
#ifndef CAN_WRAP_vfs_writev
#   define CAN_WRAP_vfs_writev 1
#endif
#if CAN_WRAP_vfs_writev
    WRAP_FOR_DETACH(vfs_writev)
#endif
#ifndef CAN_WRAP_bvec_alloc_bs
#   define CAN_WRAP_bvec_alloc_bs 1
#endif
#if CAN_WRAP_bvec_alloc_bs
    WRAP_FOR_DETACH(bvec_alloc_bs)
#endif
#ifndef CAN_WRAP_clear_huge_page
#   define CAN_WRAP_clear_huge_page 1
#endif
#if CAN_WRAP_clear_huge_page
    WRAP_FOR_DETACH(clear_huge_page)
#endif
#ifndef CAN_WRAP_mpage_readpages
#   define CAN_WRAP_mpage_readpages 1
#endif
#if CAN_WRAP_mpage_readpages
    WRAP_FOR_DETACH(mpage_readpages)
#endif
#ifndef CAN_WRAP_cap_task_setscheduler
#   define CAN_WRAP_cap_task_setscheduler 1
#endif
#if CAN_WRAP_cap_task_setscheduler
    WRAP_FOR_DETACH(cap_task_setscheduler)
#endif
#ifndef CAN_WRAP_skb_queue_head
#   define CAN_WRAP_skb_queue_head 1
#endif
#if CAN_WRAP_skb_queue_head
    WRAP_FOR_DETACH(skb_queue_head)
#endif
#ifndef CAN_WRAP_rt_mutex_adjust_pi
#   define CAN_WRAP_rt_mutex_adjust_pi 1
#endif
#if CAN_WRAP_rt_mutex_adjust_pi
    WRAP_FOR_DETACH(rt_mutex_adjust_pi)
#endif
#ifndef CAN_WRAP_neigh_seq_start
#   define CAN_WRAP_neigh_seq_start 1
#endif
#if CAN_WRAP_neigh_seq_start
    WRAP_FOR_DETACH(neigh_seq_start)
#endif
#ifndef CAN_WRAP_acpi_table_parse_madt
#   define CAN_WRAP_acpi_table_parse_madt 1
#endif
#if CAN_WRAP_acpi_table_parse_madt
    WRAP_FOR_DETACH(acpi_table_parse_madt)
#endif
#ifndef CAN_WRAP_bitmap_onto
#   define CAN_WRAP_bitmap_onto 0
#endif
DETACH(bitmap_onto)
#ifndef CAN_WRAP___inc_zone_page_state
#   define CAN_WRAP___inc_zone_page_state 1
#endif
#if CAN_WRAP___inc_zone_page_state
#   ifdef DETACH_ADDR___inc_zone_page_state
        WRAP_FOR_DETACH(__inc_zone_page_state)
#   else
        TYPED_DETACH(__inc_zone_page_state)
#   endif
#endif
#ifndef CAN_WRAP_do_mmap_pgoff
#   define CAN_WRAP_do_mmap_pgoff 1
#endif
#if CAN_WRAP_do_mmap_pgoff
    WRAP_FOR_DETACH(do_mmap_pgoff)
#endif
#ifndef CAN_WRAP_param_set_charp
#   define CAN_WRAP_param_set_charp 1
#endif
#if CAN_WRAP_param_set_charp
    WRAP_FOR_DETACH(param_set_charp)
#endif
#ifndef CAN_WRAP_pci_read_bridge_bases
#   define CAN_WRAP_pci_read_bridge_bases 1
#endif
#if CAN_WRAP_pci_read_bridge_bases
    WRAP_FOR_DETACH(pci_read_bridge_bases)
#endif
#ifndef CAN_WRAP_seq_list_next
#   define CAN_WRAP_seq_list_next 1
#endif
#if CAN_WRAP_seq_list_next
    WRAP_FOR_DETACH(seq_list_next)
#endif
#ifndef CAN_WRAP_pci_request_selected_regions_exclusive
#   define CAN_WRAP_pci_request_selected_regions_exclusive 1
#endif
#if CAN_WRAP_pci_request_selected_regions_exclusive
    WRAP_FOR_DETACH(pci_request_selected_regions_exclusive)
#endif
#ifndef CAN_WRAP_acpi_buffer_to_resource
#   define CAN_WRAP_acpi_buffer_to_resource 0
#endif
DETACH(acpi_buffer_to_resource)
#ifndef CAN_WRAP_test_taint
#   define CAN_WRAP_test_taint 0
#endif
DETACH(test_taint)
#ifndef CAN_WRAP_ata_sas_port_async_suspend
#   define CAN_WRAP_ata_sas_port_async_suspend 1
#endif
#if CAN_WRAP_ata_sas_port_async_suspend
    WRAP_FOR_DETACH(ata_sas_port_async_suspend)
#endif
#ifndef CAN_WRAP_tick_get_broadcast_oneshot_mask
#   define CAN_WRAP_tick_get_broadcast_oneshot_mask 1
#endif
#if CAN_WRAP_tick_get_broadcast_oneshot_mask
    WRAP_FOR_DETACH(tick_get_broadcast_oneshot_mask)
#endif
#ifndef CAN_WRAP_exit_mmap
#   define CAN_WRAP_exit_mmap 1
#endif
#if CAN_WRAP_exit_mmap
    WRAP_FOR_DETACH(exit_mmap)
#endif
#ifndef CAN_WRAP_ioremap_nocache
#   define CAN_WRAP_ioremap_nocache 0
#endif
DETACH(ioremap_nocache)
#ifndef CAN_WRAP_lookup_bdev
#   define CAN_WRAP_lookup_bdev 1
#endif
#if CAN_WRAP_lookup_bdev
    WRAP_FOR_DETACH(lookup_bdev)
#endif
#ifndef CAN_WRAP_acpi_bus_get_private_data
#   define CAN_WRAP_acpi_bus_get_private_data 0
#endif
DETACH(acpi_bus_get_private_data)
#ifndef CAN_WRAP_add_partition
#   define CAN_WRAP_add_partition 1
#endif
#if CAN_WRAP_add_partition
    WRAP_FOR_DETACH(add_partition)
#endif
#ifndef CAN_WRAP_timerfd_clock_was_set
#   define CAN_WRAP_timerfd_clock_was_set 0
#endif
DETACH(timerfd_clock_was_set)
#ifndef CAN_WRAP_skb_cow_data
#   define CAN_WRAP_skb_cow_data 1
#endif
#if CAN_WRAP_skb_cow_data
    WRAP_FOR_DETACH(skb_cow_data)
#endif
#ifndef CAN_WRAP_ioport_map
#   define CAN_WRAP_ioport_map 0
#endif
DETACH(ioport_map)
#ifndef CAN_WRAP_native_apic_icr_write
#   define CAN_WRAP_native_apic_icr_write 0
#endif
DETACH(native_apic_icr_write)
#ifndef CAN_WRAP_register_quota_format
#   define CAN_WRAP_register_quota_format 1
#endif
#if CAN_WRAP_register_quota_format
    WRAP_FOR_DETACH(register_quota_format)
#endif
#ifndef CAN_WRAP_klist_iter_init
#   define CAN_WRAP_klist_iter_init 1
#endif
#if CAN_WRAP_klist_iter_init
    WRAP_FOR_DETACH(klist_iter_init)
#endif
#ifndef CAN_WRAP_selinux_is_enabled
#   define CAN_WRAP_selinux_is_enabled 0
#endif
DETACH(selinux_is_enabled)
#ifndef CAN_WRAP_replace_page_cache_page
#   define CAN_WRAP_replace_page_cache_page 1
#endif
#if CAN_WRAP_replace_page_cache_page
    WRAP_FOR_DETACH(replace_page_cache_page)
#endif
#ifndef CAN_WRAP___netif_schedule
#   define CAN_WRAP___netif_schedule 1
#endif
#if CAN_WRAP___netif_schedule
#   ifdef DETACH_ADDR___netif_schedule
        WRAP_FOR_DETACH(__netif_schedule)
#   else
        TYPED_DETACH(__netif_schedule)
#   endif
#endif
#ifndef CAN_WRAP_disk_stack_limits
#   define CAN_WRAP_disk_stack_limits 1
#endif
#if CAN_WRAP_disk_stack_limits
    WRAP_FOR_DETACH(disk_stack_limits)
#endif
#ifndef CAN_WRAP_devm_kfree
#   define CAN_WRAP_devm_kfree 1
#endif
#if CAN_WRAP_devm_kfree
    WRAP_FOR_DETACH(devm_kfree)
#endif
#ifndef CAN_WRAP_xfrm_lookup
#   define CAN_WRAP_xfrm_lookup 1
#endif
#if CAN_WRAP_xfrm_lookup
    WRAP_FOR_DETACH(xfrm_lookup)
#endif
#ifndef CAN_WRAP_get_nohz_timer_target
#   define CAN_WRAP_get_nohz_timer_target 0
#endif
DETACH(get_nohz_timer_target)
#ifndef CAN_WRAP_filemap_flush
#   define CAN_WRAP_filemap_flush 1
#endif
#if CAN_WRAP_filemap_flush
    WRAP_FOR_DETACH(filemap_flush)
#endif
#ifndef CAN_WRAP_invalidate_inode_pages2_range
#   define CAN_WRAP_invalidate_inode_pages2_range 1
#endif
#if CAN_WRAP_invalidate_inode_pages2_range
    WRAP_FOR_DETACH(invalidate_inode_pages2_range)
#endif
#ifndef CAN_WRAP_unregister_cdrom
#   define CAN_WRAP_unregister_cdrom 1
#endif
#if CAN_WRAP_unregister_cdrom
    WRAP_FOR_DETACH(unregister_cdrom)
#endif
#ifndef CAN_WRAP___pm_wakeup_event
#   define CAN_WRAP___pm_wakeup_event 1
#endif
#if CAN_WRAP___pm_wakeup_event
#   ifdef DETACH_ADDR___pm_wakeup_event
        WRAP_FOR_DETACH(__pm_wakeup_event)
#   else
        TYPED_DETACH(__pm_wakeup_event)
#   endif
#endif
#ifndef CAN_WRAP_security_getprocattr
#   define CAN_WRAP_security_getprocattr 1
#endif
#if CAN_WRAP_security_getprocattr
    WRAP_FOR_DETACH(security_getprocattr)
#endif
#ifndef CAN_WRAP___nla_reserve_nohdr
#   define CAN_WRAP___nla_reserve_nohdr 1
#endif
#if CAN_WRAP___nla_reserve_nohdr
#   ifdef DETACH_ADDR___nla_reserve_nohdr
        WRAP_FOR_DETACH(__nla_reserve_nohdr)
#   else
        TYPED_DETACH(__nla_reserve_nohdr)
#   endif
#endif
#ifndef CAN_WRAP_vmemmap_pud_populate
#   define CAN_WRAP_vmemmap_pud_populate 1
#endif
#if CAN_WRAP_vmemmap_pud_populate
    WRAP_FOR_DETACH(vmemmap_pud_populate)
#endif
#ifndef CAN_WRAP_pci_enable_bridges
#   define CAN_WRAP_pci_enable_bridges 1
#endif
#if CAN_WRAP_pci_enable_bridges
    WRAP_FOR_DETACH(pci_enable_bridges)
#endif
#ifndef CAN_WRAP_vfs_unlink
#   define CAN_WRAP_vfs_unlink 1
#endif
#if CAN_WRAP_vfs_unlink
    WRAP_FOR_DETACH(vfs_unlink)
#endif
#ifndef CAN_WRAP_inode_dio_wait
#   define CAN_WRAP_inode_dio_wait 1
#endif
#if CAN_WRAP_inode_dio_wait
    WRAP_FOR_DETACH(inode_dio_wait)
#endif
#ifndef CAN_WRAP_fixup_exception
#   define CAN_WRAP_fixup_exception 1
#endif
#if CAN_WRAP_fixup_exception
    WRAP_FOR_DETACH(fixup_exception)
#endif
#ifndef CAN_WRAP_put_compat_timeval
#   define CAN_WRAP_put_compat_timeval 1
#endif
#if CAN_WRAP_put_compat_timeval
    WRAP_FOR_DETACH(put_compat_timeval)
#endif
#ifndef CAN_WRAP_smp_x86_platform_ipi
#   define CAN_WRAP_smp_x86_platform_ipi 1
#endif
#if CAN_WRAP_smp_x86_platform_ipi
    WRAP_FOR_DETACH(smp_x86_platform_ipi)
#endif
#ifndef CAN_WRAP_dcache_readdir
#   define CAN_WRAP_dcache_readdir 1
#endif
#if CAN_WRAP_dcache_readdir
    WRAP_FOR_DETACH(dcache_readdir)
#endif
#ifndef CAN_WRAP_page_put_link
#   define CAN_WRAP_page_put_link 1
#endif
#if CAN_WRAP_page_put_link
    WRAP_FOR_DETACH(page_put_link)
#endif
#ifndef CAN_WRAP_init_special_inode
#   define CAN_WRAP_init_special_inode 1
#endif
#if CAN_WRAP_init_special_inode
    WRAP_FOR_DETACH(init_special_inode)
#endif
#ifndef CAN_WRAP_sk_attach_filter
#   define CAN_WRAP_sk_attach_filter 1
#endif
#if CAN_WRAP_sk_attach_filter
    WRAP_FOR_DETACH(sk_attach_filter)
#endif
#ifndef CAN_WRAP_blocking_notifier_chain_register
#   define CAN_WRAP_blocking_notifier_chain_register 1
#endif
#if CAN_WRAP_blocking_notifier_chain_register
    WRAP_FOR_DETACH(blocking_notifier_chain_register)
#endif
#ifndef CAN_WRAP_kmem_cache_init
#   define CAN_WRAP_kmem_cache_init 0
#endif
DETACH(kmem_cache_init)
#ifndef CAN_WRAP___ata_change_queue_depth
#   define CAN_WRAP___ata_change_queue_depth 1
#endif
#if CAN_WRAP___ata_change_queue_depth
#   ifdef DETACH_ADDR___ata_change_queue_depth
        WRAP_FOR_DETACH(__ata_change_queue_depth)
#   else
        TYPED_DETACH(__ata_change_queue_depth)
#   endif
#endif
#ifndef CAN_WRAP_jbd2_journal_unfile_buffer
#   define CAN_WRAP_jbd2_journal_unfile_buffer 1
#endif
#if CAN_WRAP_jbd2_journal_unfile_buffer
    WRAP_FOR_DETACH(jbd2_journal_unfile_buffer)
#endif
#ifndef CAN_WRAP_handle_percpu_irq
#   define CAN_WRAP_handle_percpu_irq 1
#endif
#if CAN_WRAP_handle_percpu_irq
    WRAP_FOR_DETACH(handle_percpu_irq)
#endif
#ifndef CAN_WRAP_pcim_iomap_regions_request_all
#   define CAN_WRAP_pcim_iomap_regions_request_all 1
#endif
#if CAN_WRAP_pcim_iomap_regions_request_all
    WRAP_FOR_DETACH(pcim_iomap_regions_request_all)
#endif
#ifndef CAN_WRAP_vma_merge
#   define CAN_WRAP_vma_merge 1
#endif
#if CAN_WRAP_vma_merge
    WRAP_FOR_DETACH(vma_merge)
#endif
#ifndef CAN_WRAP_dirty_ratio_handler
#   define CAN_WRAP_dirty_ratio_handler 1
#endif
#if CAN_WRAP_dirty_ratio_handler
    WRAP_FOR_DETACH(dirty_ratio_handler)
#endif
#ifndef CAN_WRAP_pvclock_get_vsyscall_time_info
#   define CAN_WRAP_pvclock_get_vsyscall_time_info 1
#endif
#if CAN_WRAP_pvclock_get_vsyscall_time_info
    WRAP_FOR_DETACH(pvclock_get_vsyscall_time_info)
#endif
#ifndef CAN_WRAP_set_pcie_port_type
#   define CAN_WRAP_set_pcie_port_type 1
#endif
#if CAN_WRAP_set_pcie_port_type
    WRAP_FOR_DETACH(set_pcie_port_type)
#endif
#ifndef CAN_WRAP_seq_hlist_next_rcu
#   define CAN_WRAP_seq_hlist_next_rcu 1
#endif
#if CAN_WRAP_seq_hlist_next_rcu
    WRAP_FOR_DETACH(seq_hlist_next_rcu)
#endif
#ifndef CAN_WRAP___mutex_init
#   define CAN_WRAP___mutex_init 1
#endif
#if CAN_WRAP___mutex_init
#   ifdef DETACH_ADDR___mutex_init
        WRAP_FOR_DETACH(__mutex_init)
#   else
        TYPED_DETACH(__mutex_init)
#   endif
#endif
#ifndef CAN_WRAP_class_for_each_device
#   define CAN_WRAP_class_for_each_device 1
#endif
#if CAN_WRAP_class_for_each_device
    WRAP_FOR_DETACH(class_for_each_device)
#endif
#ifndef CAN_WRAP_sparse_mem_maps_populate_node
#   define CAN_WRAP_sparse_mem_maps_populate_node 0
#endif
DETACH(sparse_mem_maps_populate_node)
#ifndef CAN_WRAP_klist_add_tail
#   define CAN_WRAP_klist_add_tail 1
#endif
#if CAN_WRAP_klist_add_tail
    WRAP_FOR_DETACH(klist_add_tail)
#endif
#ifndef CAN_WRAP_jbd2_journal_start_commit
#   define CAN_WRAP_jbd2_journal_start_commit 1
#endif
#if CAN_WRAP_jbd2_journal_start_commit
    WRAP_FOR_DETACH(jbd2_journal_start_commit)
#endif
#ifndef CAN_WRAP_rcu_check_callbacks
#   define CAN_WRAP_rcu_check_callbacks 0
#endif
DETACH(rcu_check_callbacks)
#ifndef CAN_WRAP_print_oops_end_marker
#   define CAN_WRAP_print_oops_end_marker 0
#endif
DETACH(print_oops_end_marker)
#ifndef CAN_WRAP_map_kernel_range_noflush
#   define CAN_WRAP_map_kernel_range_noflush 1
#endif
#if CAN_WRAP_map_kernel_range_noflush
    WRAP_FOR_DETACH(map_kernel_range_noflush)
#endif
#ifndef CAN_WRAP_register_hugetlbfs_with_node
#   define CAN_WRAP_register_hugetlbfs_with_node 1
#endif
#if CAN_WRAP_register_hugetlbfs_with_node
    WRAP_FOR_DETACH(register_hugetlbfs_with_node)
#endif
#ifndef CAN_WRAP_security_shm_shmat
#   define CAN_WRAP_security_shm_shmat 1
#endif
#if CAN_WRAP_security_shm_shmat
    WRAP_FOR_DETACH(security_shm_shmat)
#endif
#ifndef CAN_WRAP_compat_sock_common_getsockopt
#   define CAN_WRAP_compat_sock_common_getsockopt 1
#endif
#if CAN_WRAP_compat_sock_common_getsockopt
    WRAP_FOR_DETACH(compat_sock_common_getsockopt)
#endif
#ifndef CAN_WRAP_free_css_id
#   define CAN_WRAP_free_css_id 1
#endif
#if CAN_WRAP_free_css_id
    WRAP_FOR_DETACH(free_css_id)
#endif
#ifndef CAN_WRAP_sk_reset_timer
#   define CAN_WRAP_sk_reset_timer 1
#endif
#if CAN_WRAP_sk_reset_timer
    WRAP_FOR_DETACH(sk_reset_timer)
#endif
#ifndef CAN_WRAP_bus_rescan_devices
#   define CAN_WRAP_bus_rescan_devices 1
#endif
#if CAN_WRAP_bus_rescan_devices
    WRAP_FOR_DETACH(bus_rescan_devices)
#endif
#ifndef CAN_WRAP_acpi_bios_error
#   define CAN_WRAP_acpi_bios_error 0
#endif
DETACH(acpi_bios_error)
#ifndef CAN_WRAP_kmem_cache_free
#   define CAN_WRAP_kmem_cache_free 1
#endif
#if CAN_WRAP_kmem_cache_free
    WRAP_FOR_DETACH(kmem_cache_free)
#endif
#ifndef CAN_WRAP_do_sigpending
#   define CAN_WRAP_do_sigpending 0
#endif
DETACH(do_sigpending)
#ifndef CAN_WRAP_proc_flush_task
#   define CAN_WRAP_proc_flush_task 1
#endif
#if CAN_WRAP_proc_flush_task
    WRAP_FOR_DETACH(proc_flush_task)
#endif
#ifndef CAN_WRAP_do_schedule_next_timer
#   define CAN_WRAP_do_schedule_next_timer 1
#endif
#if CAN_WRAP_do_schedule_next_timer
    WRAP_FOR_DETACH(do_schedule_next_timer)
#endif
#ifndef CAN_WRAP_elv_latter_request
#   define CAN_WRAP_elv_latter_request 1
#endif
#if CAN_WRAP_elv_latter_request
    WRAP_FOR_DETACH(elv_latter_request)
#endif
#ifndef CAN_WRAP_kernel_restart_prepare
#   define CAN_WRAP_kernel_restart_prepare 0
#endif
DETACH(kernel_restart_prepare)
#ifndef CAN_WRAP_put_compat_timespec
#   define CAN_WRAP_put_compat_timespec 1
#endif
#if CAN_WRAP_put_compat_timespec
    WRAP_FOR_DETACH(put_compat_timespec)
#endif
#ifndef CAN_WRAP___css_tryget
#   define CAN_WRAP___css_tryget 1
#endif
#if CAN_WRAP___css_tryget
#   ifdef DETACH_ADDR___css_tryget
        WRAP_FOR_DETACH(__css_tryget)
#   else
        TYPED_DETACH(__css_tryget)
#   endif
#endif
#ifndef CAN_WRAP_mark_mounts_for_expiry
#   define CAN_WRAP_mark_mounts_for_expiry 1
#endif
#if CAN_WRAP_mark_mounts_for_expiry
    WRAP_FOR_DETACH(mark_mounts_for_expiry)
#endif
#ifndef CAN_WRAP_ata_port_freeze
#   define CAN_WRAP_ata_port_freeze 1
#endif
#if CAN_WRAP_ata_port_freeze
    WRAP_FOR_DETACH(ata_port_freeze)
#endif
#ifndef CAN_WRAP___pci_register_driver
#   define CAN_WRAP___pci_register_driver 1
#endif
#if CAN_WRAP___pci_register_driver
#   ifdef DETACH_ADDR___pci_register_driver
        WRAP_FOR_DETACH(__pci_register_driver)
#   else
        TYPED_DETACH(__pci_register_driver)
#   endif
#endif
#ifndef CAN_WRAP_invalidate_partition
#   define CAN_WRAP_invalidate_partition 1
#endif
#if CAN_WRAP_invalidate_partition
    WRAP_FOR_DETACH(invalidate_partition)
#endif
#ifndef CAN_WRAP_ata_do_set_mode
#   define CAN_WRAP_ata_do_set_mode 1
#endif
#if CAN_WRAP_ata_do_set_mode
    WRAP_FOR_DETACH(ata_do_set_mode)
#endif
#ifndef CAN_WRAP_free_hot_cold_page
#   define CAN_WRAP_free_hot_cold_page 1
#endif
#if CAN_WRAP_free_hot_cold_page
    WRAP_FOR_DETACH(free_hot_cold_page)
#endif
#ifndef CAN_WRAP_online_pages
#   define CAN_WRAP_online_pages 0
#endif
DETACH(online_pages)
#ifndef CAN_WRAP_netdev_stats_to_stats64
#   define CAN_WRAP_netdev_stats_to_stats64 1
#endif
#if CAN_WRAP_netdev_stats_to_stats64
    WRAP_FOR_DETACH(netdev_stats_to_stats64)
#endif
#ifndef CAN_WRAP_acpi_subsys_runtime_resume
#   define CAN_WRAP_acpi_subsys_runtime_resume 1
#endif
#if CAN_WRAP_acpi_subsys_runtime_resume
    WRAP_FOR_DETACH(acpi_subsys_runtime_resume)
#endif
#ifndef CAN_WRAP_dev_uc_add
#   define CAN_WRAP_dev_uc_add 1
#endif
#if CAN_WRAP_dev_uc_add
    WRAP_FOR_DETACH(dev_uc_add)
#endif
#ifndef CAN_WRAP___pte_alloc
#   define CAN_WRAP___pte_alloc 1
#endif
#if CAN_WRAP___pte_alloc
#   ifdef DETACH_ADDR___pte_alloc
        WRAP_FOR_DETACH(__pte_alloc)
#   else
        TYPED_DETACH(__pte_alloc)
#   endif
#endif
#ifndef CAN_WRAP_tracing_stop
#   define CAN_WRAP_tracing_stop 0
#endif
DETACH(tracing_stop)
#ifndef CAN_WRAP_ata_id_xfermask
#   define CAN_WRAP_ata_id_xfermask 0
#endif
DETACH(ata_id_xfermask)
#ifndef CAN_WRAP___netdev_alloc_skb
#   define CAN_WRAP___netdev_alloc_skb 1
#endif
#if CAN_WRAP___netdev_alloc_skb
#   ifdef DETACH_ADDR___netdev_alloc_skb
        WRAP_FOR_DETACH(__netdev_alloc_skb)
#   else
        TYPED_DETACH(__netdev_alloc_skb)
#   endif
#endif
#ifndef CAN_WRAP_call_rcu_sched
#   define CAN_WRAP_call_rcu_sched 1
#endif
#if CAN_WRAP_call_rcu_sched
    WRAP_FOR_DETACH(call_rcu_sched)
#endif
#ifndef CAN_WRAP_dev_ingress_queue_create
#   define CAN_WRAP_dev_ingress_queue_create 1
#endif
#if CAN_WRAP_dev_ingress_queue_create
    WRAP_FOR_DETACH(dev_ingress_queue_create)
#endif
#ifndef CAN_WRAP_skb_dequeue_tail
#   define CAN_WRAP_skb_dequeue_tail 1
#endif
#if CAN_WRAP_skb_dequeue_tail
    WRAP_FOR_DETACH(skb_dequeue_tail)
#endif
#ifndef CAN_WRAP_kset_register
#   define CAN_WRAP_kset_register 1
#endif
#if CAN_WRAP_kset_register
    WRAP_FOR_DETACH(kset_register)
#endif
#ifndef CAN_WRAP_sg_scsi_ioctl
#   define CAN_WRAP_sg_scsi_ioctl 1
#endif
#if CAN_WRAP_sg_scsi_ioctl
    WRAP_FOR_DETACH(sg_scsi_ioctl)
#endif
#ifndef CAN_WRAP_nr_free_buffer_pages
#   define CAN_WRAP_nr_free_buffer_pages 0
#endif
DETACH(nr_free_buffer_pages)
#ifndef CAN_WRAP___krealloc
#   define CAN_WRAP___krealloc 0
#endif
DETACH(__krealloc)
#ifndef CAN_WRAP_pm_qos_update_request_timeout
#   define CAN_WRAP_pm_qos_update_request_timeout 1
#endif
#if CAN_WRAP_pm_qos_update_request_timeout
    WRAP_FOR_DETACH(pm_qos_update_request_timeout)
#endif
#ifndef CAN_WRAP_klist_iter_init_node
#   define CAN_WRAP_klist_iter_init_node 1
#endif
#if CAN_WRAP_klist_iter_init_node
    WRAP_FOR_DETACH(klist_iter_init_node)
#endif
#ifndef CAN_WRAP_irq_setup_alt_chip
#   define CAN_WRAP_irq_setup_alt_chip 1
#endif
#if CAN_WRAP_irq_setup_alt_chip
    WRAP_FOR_DETACH(irq_setup_alt_chip)
#endif
#ifndef CAN_WRAP_kill_pid_info_as_cred
#   define CAN_WRAP_kill_pid_info_as_cred 1
#endif
#if CAN_WRAP_kill_pid_info_as_cred
    WRAP_FOR_DETACH(kill_pid_info_as_cred)
#endif
#ifndef CAN_WRAP_neigh_changeaddr
#   define CAN_WRAP_neigh_changeaddr 1
#endif
#if CAN_WRAP_neigh_changeaddr
    WRAP_FOR_DETACH(neigh_changeaddr)
#endif
#ifndef CAN_WRAP___get_vm_area
#   define CAN_WRAP___get_vm_area 1
#endif
#if CAN_WRAP___get_vm_area
#   ifdef DETACH_ADDR___get_vm_area
        WRAP_FOR_DETACH(__get_vm_area)
#   else
        TYPED_DETACH(__get_vm_area)
#   endif
#endif
#ifndef CAN_WRAP_sched_getaffinity
#   define CAN_WRAP_sched_getaffinity 1
#endif
#if CAN_WRAP_sched_getaffinity
    WRAP_FOR_DETACH(sched_getaffinity)
#endif
#ifndef CAN_WRAP_plist_add
#   define CAN_WRAP_plist_add 1
#endif
#if CAN_WRAP_plist_add
    WRAP_FOR_DETACH(plist_add)
#endif
#ifndef CAN_WRAP_compat_sys_io_submit
#   define CAN_WRAP_compat_sys_io_submit 0
#endif
DETACH(compat_sys_io_submit)
#ifndef CAN_WRAP_vfs_fsync
#   define CAN_WRAP_vfs_fsync 1
#endif
#if CAN_WRAP_vfs_fsync
    WRAP_FOR_DETACH(vfs_fsync)
#endif
#ifndef CAN_WRAP_scsi_cmd_get_serial
#   define CAN_WRAP_scsi_cmd_get_serial 1
#endif
#if CAN_WRAP_scsi_cmd_get_serial
    WRAP_FOR_DETACH(scsi_cmd_get_serial)
#endif
#ifndef CAN_WRAP_pnp_register_card_driver
#   define CAN_WRAP_pnp_register_card_driver 1
#endif
#if CAN_WRAP_pnp_register_card_driver
    WRAP_FOR_DETACH(pnp_register_card_driver)
#endif
#ifndef CAN_WRAP_do_notify_resume
#   define CAN_WRAP_do_notify_resume 1
#endif
#if CAN_WRAP_do_notify_resume
    WRAP_FOR_DETACH(do_notify_resume)
#endif
#ifndef CAN_WRAP_ec_get_handle
#   define CAN_WRAP_ec_get_handle 0
#endif
DETACH(ec_get_handle)
#ifndef CAN_WRAP_clocksource_default_clock
#   define CAN_WRAP_clocksource_default_clock 1
#endif
#if CAN_WRAP_clocksource_default_clock
    WRAP_FOR_DETACH(clocksource_default_clock)
#endif
#ifndef CAN_WRAP_call_function_single_interrupt
#   define CAN_WRAP_call_function_single_interrupt 0
#endif
DETACH(call_function_single_interrupt)
#ifndef CAN_WRAP_kernel_getsockopt
#   define CAN_WRAP_kernel_getsockopt 1
#endif
#if CAN_WRAP_kernel_getsockopt
    WRAP_FOR_DETACH(kernel_getsockopt)
#endif
#ifndef CAN_WRAP_vm_brk
#   define CAN_WRAP_vm_brk 0
#endif
DETACH(vm_brk)
#ifndef CAN_WRAP_yama_task_free
#   define CAN_WRAP_yama_task_free 1
#endif
#if CAN_WRAP_yama_task_free
    WRAP_FOR_DETACH(yama_task_free)
#endif
#ifndef CAN_WRAP_radix_tree_range_tag_if_tagged
#   define CAN_WRAP_radix_tree_range_tag_if_tagged 1
#endif
#if CAN_WRAP_radix_tree_range_tag_if_tagged
    WRAP_FOR_DETACH(radix_tree_range_tag_if_tagged)
#endif
#ifndef CAN_WRAP_ata_id_string
#   define CAN_WRAP_ata_id_string 0
#endif
DETACH(ata_id_string)
#ifndef CAN_WRAP_x86_idle_thread_init
#   define CAN_WRAP_x86_idle_thread_init 1
#endif
#if CAN_WRAP_x86_idle_thread_init
    WRAP_FOR_DETACH(x86_idle_thread_init)
#endif
#ifndef CAN_WRAP_acpi_dev_resume_early
#   define CAN_WRAP_acpi_dev_resume_early 1
#endif
#if CAN_WRAP_acpi_dev_resume_early
    WRAP_FOR_DETACH(acpi_dev_resume_early)
#endif
#ifndef CAN_WRAP_acpi_bios_warning
#   define CAN_WRAP_acpi_bios_warning 0
#endif
DETACH(acpi_bios_warning)
#ifndef CAN_WRAP_is_vmalloc_or_module_addr
#   define CAN_WRAP_is_vmalloc_or_module_addr 0
#endif
DETACH(is_vmalloc_or_module_addr)
#ifndef CAN_WRAP_acpi_bus_update_power
#   define CAN_WRAP_acpi_bus_update_power 0
#endif
DETACH(acpi_bus_update_power)
#ifndef CAN_WRAP_register_pernet_device
#   define CAN_WRAP_register_pernet_device 1
#endif
#if CAN_WRAP_register_pernet_device
    WRAP_FOR_DETACH(register_pernet_device)
#endif
#ifndef CAN_WRAP_generic_smp_call_function_single_interrupt
#   define CAN_WRAP_generic_smp_call_function_single_interrupt 0
#endif
DETACH(generic_smp_call_function_single_interrupt)
#ifndef CAN_WRAP_device_wakeup_disable
#   define CAN_WRAP_device_wakeup_disable 1
#endif
#if CAN_WRAP_device_wakeup_disable
    WRAP_FOR_DETACH(device_wakeup_disable)
#endif
#ifndef CAN_WRAP_default_mpc_apic_id
#   define CAN_WRAP_default_mpc_apic_id 1
#endif
#if CAN_WRAP_default_mpc_apic_id
    WRAP_FOR_DETACH(default_mpc_apic_id)
#endif
#ifndef CAN_WRAP_acpi_dev_pm_attach
#   define CAN_WRAP_acpi_dev_pm_attach 1
#endif
#if CAN_WRAP_acpi_dev_pm_attach
    WRAP_FOR_DETACH(acpi_dev_pm_attach)
#endif
#ifndef CAN_WRAP_radix_tree_insert
#   define CAN_WRAP_radix_tree_insert 1
#endif
#if CAN_WRAP_radix_tree_insert
    WRAP_FOR_DETACH(radix_tree_insert)
#endif
#ifndef CAN_WRAP_pci_user_read_config_byte
#   define CAN_WRAP_pci_user_read_config_byte 1
#endif
#if CAN_WRAP_pci_user_read_config_byte
    WRAP_FOR_DETACH(pci_user_read_config_byte)
#endif
#ifndef CAN_WRAP_eth_change_mtu
#   define CAN_WRAP_eth_change_mtu 1
#endif
#if CAN_WRAP_eth_change_mtu
    WRAP_FOR_DETACH(eth_change_mtu)
#endif
#ifndef CAN_WRAP_rwsem_downgrade_wake
#   define CAN_WRAP_rwsem_downgrade_wake 1
#endif
#if CAN_WRAP_rwsem_downgrade_wake
    WRAP_FOR_DETACH(rwsem_downgrade_wake)
#endif
#ifndef CAN_WRAP_nf_unregister_afinfo
#   define CAN_WRAP_nf_unregister_afinfo 1
#endif
#if CAN_WRAP_nf_unregister_afinfo
    WRAP_FOR_DETACH(nf_unregister_afinfo)
#endif
#ifndef CAN_WRAP_unregister_module_notifier
#   define CAN_WRAP_unregister_module_notifier 1
#endif
#if CAN_WRAP_unregister_module_notifier
    WRAP_FOR_DETACH(unregister_module_notifier)
#endif
#ifndef CAN_WRAP___sw_hweight8
#   define CAN_WRAP___sw_hweight8 0
#endif
DETACH(__sw_hweight8)
#ifndef CAN_WRAP_request_threaded_irq
#   define CAN_WRAP_request_threaded_irq 1
#endif
#if CAN_WRAP_request_threaded_irq
    WRAP_FOR_DETACH(request_threaded_irq)
#endif
#ifndef CAN_WRAP_do_one_initcall
#   define CAN_WRAP_do_one_initcall 1
#endif
#if CAN_WRAP_do_one_initcall
    WRAP_FOR_DETACH(do_one_initcall)
#endif
#ifndef CAN_WRAP_acpi_remove_fixed_event_handler
#   define CAN_WRAP_acpi_remove_fixed_event_handler 1
#endif
#if CAN_WRAP_acpi_remove_fixed_event_handler
    WRAP_FOR_DETACH(acpi_remove_fixed_event_handler)
#endif
#ifndef CAN_WRAP_pdflush_proc_obsolete
#   define CAN_WRAP_pdflush_proc_obsolete 1
#endif
#if CAN_WRAP_pdflush_proc_obsolete
    WRAP_FOR_DETACH(pdflush_proc_obsolete)
#endif
#ifndef CAN_WRAP_run_local_timers
#   define CAN_WRAP_run_local_timers 0
#endif
DETACH(run_local_timers)
#ifndef CAN_WRAP_swiotlb_tbl_unmap_single
#   define CAN_WRAP_swiotlb_tbl_unmap_single 1
#endif
#if CAN_WRAP_swiotlb_tbl_unmap_single
    WRAP_FOR_DETACH(swiotlb_tbl_unmap_single)
#endif
#ifndef CAN_WRAP_cgroup_lock_live_group
#   define CAN_WRAP_cgroup_lock_live_group 1
#endif
#if CAN_WRAP_cgroup_lock_live_group
    WRAP_FOR_DETACH(cgroup_lock_live_group)
#endif
#ifndef CAN_WRAP_detect_extended_topology
#   define CAN_WRAP_detect_extended_topology 1
#endif
#if CAN_WRAP_detect_extended_topology
    WRAP_FOR_DETACH(detect_extended_topology)
#endif
#ifndef CAN_WRAP_pci_add_resource
#   define CAN_WRAP_pci_add_resource 1
#endif
#if CAN_WRAP_pci_add_resource
    WRAP_FOR_DETACH(pci_add_resource)
#endif
#ifndef CAN_WRAP_page_writeback_init
#   define CAN_WRAP_page_writeback_init 0
#endif
DETACH(page_writeback_init)
#ifndef CAN_WRAP_alloc_netdev_mqs
#   define CAN_WRAP_alloc_netdev_mqs 1
#endif
#if CAN_WRAP_alloc_netdev_mqs
    WRAP_FOR_DETACH(alloc_netdev_mqs)
#endif
#ifndef CAN_WRAP_inode_init_once
#   define CAN_WRAP_inode_init_once 1
#endif
#if CAN_WRAP_inode_init_once
    WRAP_FOR_DETACH(inode_init_once)
#endif
#ifndef CAN_WRAP_neigh_table_clear
#   define CAN_WRAP_neigh_table_clear 1
#endif
#if CAN_WRAP_neigh_table_clear
    WRAP_FOR_DETACH(neigh_table_clear)
#endif
#ifndef CAN_WRAP_jbd2_journal_update_sb_log_tail
#   define CAN_WRAP_jbd2_journal_update_sb_log_tail 1
#endif
#if CAN_WRAP_jbd2_journal_update_sb_log_tail
    WRAP_FOR_DETACH(jbd2_journal_update_sb_log_tail)
#endif
#ifndef CAN_WRAP_sata_scr_write
#   define CAN_WRAP_sata_scr_write 1
#endif
#if CAN_WRAP_sata_scr_write
    WRAP_FOR_DETACH(sata_scr_write)
#endif
#ifndef CAN_WRAP_mb_cache_entry_find_next
#   define CAN_WRAP_mb_cache_entry_find_next 1
#endif
#if CAN_WRAP_mb_cache_entry_find_next
    WRAP_FOR_DETACH(mb_cache_entry_find_next)
#endif
#ifndef CAN_WRAP_do_sys_open
#   define CAN_WRAP_do_sys_open 0
#endif
DETACH(do_sys_open)
#ifndef CAN_WRAP_acpi_remove_gpe_block
#   define CAN_WRAP_acpi_remove_gpe_block 0
#endif
DETACH(acpi_remove_gpe_block)
#ifndef CAN_WRAP_rtnl_is_locked
#   define CAN_WRAP_rtnl_is_locked 0
#endif
DETACH(rtnl_is_locked)
#ifndef CAN_WRAP_unregister_blkdev
#   define CAN_WRAP_unregister_blkdev 0
#endif
DETACH(unregister_blkdev)
#ifndef CAN_WRAP_dmaengine_put
#   define CAN_WRAP_dmaengine_put 0
#endif
DETACH(dmaengine_put)
#ifndef CAN_WRAP_vma_interval_tree_remove
#   define CAN_WRAP_vma_interval_tree_remove 1
#endif
#if CAN_WRAP_vma_interval_tree_remove
    WRAP_FOR_DETACH(vma_interval_tree_remove)
#endif
#ifndef CAN_WRAP_elv_iosched_show
#   define CAN_WRAP_elv_iosched_show 1
#endif
#if CAN_WRAP_elv_iosched_show
    WRAP_FOR_DETACH(elv_iosched_show)
#endif
#ifndef CAN_WRAP_blk_queue_alignment_offset
#   define CAN_WRAP_blk_queue_alignment_offset 1
#endif
#if CAN_WRAP_blk_queue_alignment_offset
    WRAP_FOR_DETACH(blk_queue_alignment_offset)
#endif
#ifndef CAN_WRAP_devres_remove_group
#   define CAN_WRAP_devres_remove_group 1
#endif
#if CAN_WRAP_devres_remove_group
    WRAP_FOR_DETACH(devres_remove_group)
#endif
#ifndef CAN_WRAP_add_wait_queue_exclusive
#   define CAN_WRAP_add_wait_queue_exclusive 1
#endif
#if CAN_WRAP_add_wait_queue_exclusive
    WRAP_FOR_DETACH(add_wait_queue_exclusive)
#endif
#ifndef CAN_WRAP_module_kallsyms_on_each_symbol
#   define CAN_WRAP_module_kallsyms_on_each_symbol 1
#endif
#if CAN_WRAP_module_kallsyms_on_each_symbol
    WRAP_FOR_DETACH(module_kallsyms_on_each_symbol)
#endif
#ifndef CAN_WRAP_sysfs_put
#   define CAN_WRAP_sysfs_put 1
#endif
#if CAN_WRAP_sysfs_put
    WRAP_FOR_DETACH(sysfs_put)
#endif
#ifndef CAN_WRAP_security_syslog
#   define CAN_WRAP_security_syslog 0
#endif
DETACH(security_syslog)
#ifndef CAN_WRAP_compat_ptrace_request
#   define CAN_WRAP_compat_ptrace_request 1
#endif
#if CAN_WRAP_compat_ptrace_request
    WRAP_FOR_DETACH(compat_ptrace_request)
#endif
#ifndef CAN_WRAP_smp_call_function_single_interrupt
#   define CAN_WRAP_smp_call_function_single_interrupt 1
#endif
#if CAN_WRAP_smp_call_function_single_interrupt
    WRAP_FOR_DETACH(smp_call_function_single_interrupt)
#endif
#ifndef CAN_WRAP_workqueue_congested
#   define CAN_WRAP_workqueue_congested 1
#endif
#if CAN_WRAP_workqueue_congested
    WRAP_FOR_DETACH(workqueue_congested)
#endif
#ifndef CAN_WRAP_netif_napi_add
#   define CAN_WRAP_netif_napi_add 1
#endif
#if CAN_WRAP_netif_napi_add
    WRAP_FOR_DETACH(netif_napi_add)
#endif
#ifndef CAN_WRAP_phy_register_fixup_for_id
#   define CAN_WRAP_phy_register_fixup_for_id 1
#endif
#if CAN_WRAP_phy_register_fixup_for_id
    WRAP_FOR_DETACH(phy_register_fixup_for_id)
#endif
#ifndef CAN_WRAP___scm_destroy
#   define CAN_WRAP___scm_destroy 1
#endif
#if CAN_WRAP___scm_destroy
#   ifdef DETACH_ADDR___scm_destroy
        WRAP_FOR_DETACH(__scm_destroy)
#   else
        TYPED_DETACH(__scm_destroy)
#   endif
#endif
#ifndef CAN_WRAP_proc_nr_files
#   define CAN_WRAP_proc_nr_files 1
#endif
#if CAN_WRAP_proc_nr_files
    WRAP_FOR_DETACH(proc_nr_files)
#endif
#ifndef CAN_WRAP___bio_clone
#   define CAN_WRAP___bio_clone 1
#endif
#if CAN_WRAP___bio_clone
#   ifdef DETACH_ADDR___bio_clone
        WRAP_FOR_DETACH(__bio_clone)
#   else
        TYPED_DETACH(__bio_clone)
#   endif
#endif
#ifndef CAN_WRAP_cap_bprm_secureexec
#   define CAN_WRAP_cap_bprm_secureexec 1
#endif
#if CAN_WRAP_cap_bprm_secureexec
    WRAP_FOR_DETACH(cap_bprm_secureexec)
#endif
#ifndef CAN_WRAP_block_write_full_page
#   define CAN_WRAP_block_write_full_page 1
#endif
#if CAN_WRAP_block_write_full_page
    WRAP_FOR_DETACH(block_write_full_page)
#endif
#ifndef CAN_WRAP_acpi_os_get_timer
#   define CAN_WRAP_acpi_os_get_timer 0
#endif
DETACH(acpi_os_get_timer)
#ifndef CAN_WRAP_security_inet_conn_request
#   define CAN_WRAP_security_inet_conn_request 1
#endif
#if CAN_WRAP_security_inet_conn_request
    WRAP_FOR_DETACH(security_inet_conn_request)
#endif
#ifndef CAN_WRAP_blk_abort_request
#   define CAN_WRAP_blk_abort_request 1
#endif
#if CAN_WRAP_blk_abort_request
    WRAP_FOR_DETACH(blk_abort_request)
#endif
#ifndef CAN_WRAP_fd_statfs
#   define CAN_WRAP_fd_statfs 1
#endif
#if CAN_WRAP_fd_statfs
    WRAP_FOR_DETACH(fd_statfs)
#endif
#ifndef CAN_WRAP_security_sk_clone
#   define CAN_WRAP_security_sk_clone 1
#endif
#if CAN_WRAP_security_sk_clone
    WRAP_FOR_DETACH(security_sk_clone)
#endif
#ifndef CAN_WRAP_clocksource_mmio_readl_down
#   define CAN_WRAP_clocksource_mmio_readl_down 1
#endif
#if CAN_WRAP_clocksource_mmio_readl_down
    WRAP_FOR_DETACH(clocksource_mmio_readl_down)
#endif
#ifndef CAN_WRAP_irq_work_interrupt
#   define CAN_WRAP_irq_work_interrupt 0
#endif
DETACH(irq_work_interrupt)
#ifndef CAN_WRAP_get_monotonic_boottime
#   define CAN_WRAP_get_monotonic_boottime 1
#endif
#if CAN_WRAP_get_monotonic_boottime
    WRAP_FOR_DETACH(get_monotonic_boottime)
#endif
#ifndef CAN_WRAP_vlan_dev_real_dev
#   define CAN_WRAP_vlan_dev_real_dev 1
#endif
#if CAN_WRAP_vlan_dev_real_dev
    WRAP_FOR_DETACH(vlan_dev_real_dev)
#endif
#ifndef CAN_WRAP_pci_get_subsys
#   define CAN_WRAP_pci_get_subsys 1
#endif
#if CAN_WRAP_pci_get_subsys
    WRAP_FOR_DETACH(pci_get_subsys)
#endif
#ifndef CAN_WRAP_e820_print_map
#   define CAN_WRAP_e820_print_map 0
#endif
DETACH(e820_print_map)
#ifndef CAN_WRAP_pci_get_class
#   define CAN_WRAP_pci_get_class 1
#endif
#if CAN_WRAP_pci_get_class
    WRAP_FOR_DETACH(pci_get_class)
#endif
#ifndef CAN_WRAP_inet_csk_delete_keepalive_timer
#   define CAN_WRAP_inet_csk_delete_keepalive_timer 1
#endif
#if CAN_WRAP_inet_csk_delete_keepalive_timer
    WRAP_FOR_DETACH(inet_csk_delete_keepalive_timer)
#endif
#ifndef CAN_WRAP_seq_hlist_start
#   define CAN_WRAP_seq_hlist_start 1
#endif
#if CAN_WRAP_seq_hlist_start
    WRAP_FOR_DETACH(seq_hlist_start)
#endif
#ifndef CAN_WRAP_acpi_bus_generate_netlink_event
#   define CAN_WRAP_acpi_bus_generate_netlink_event 0
#endif
DETACH(acpi_bus_generate_netlink_event)
#ifndef CAN_WRAP_acpi_osi_setup
#   define CAN_WRAP_acpi_osi_setup 0
#endif
DETACH(acpi_osi_setup)
#ifndef CAN_WRAP_sk_detach_filter
#   define CAN_WRAP_sk_detach_filter 1
#endif
#if CAN_WRAP_sk_detach_filter
    WRAP_FOR_DETACH(sk_detach_filter)
#endif
#ifndef CAN_WRAP_bitmap_parse_user
#   define CAN_WRAP_bitmap_parse_user 0
#endif
DETACH(bitmap_parse_user)
#ifndef CAN_WRAP_acpi_os_remove_interrupt_handler
#   define CAN_WRAP_acpi_os_remove_interrupt_handler 1
#endif
#if CAN_WRAP_acpi_os_remove_interrupt_handler
    WRAP_FOR_DETACH(acpi_os_remove_interrupt_handler)
#endif
#ifndef CAN_WRAP_blk_rq_map_user
#   define CAN_WRAP_blk_rq_map_user 1
#endif
#if CAN_WRAP_blk_rq_map_user
    WRAP_FOR_DETACH(blk_rq_map_user)
#endif
#ifndef CAN_WRAP_idr_remove
#   define CAN_WRAP_idr_remove 1
#endif
#if CAN_WRAP_idr_remove
    WRAP_FOR_DETACH(idr_remove)
#endif
#ifndef CAN_WRAP_qdisc_watchdog_init
#   define CAN_WRAP_qdisc_watchdog_init 1
#endif
#if CAN_WRAP_qdisc_watchdog_init
    WRAP_FOR_DETACH(qdisc_watchdog_init)
#endif
#ifndef CAN_WRAP_phy_drivers_unregister
#   define CAN_WRAP_phy_drivers_unregister 1
#endif
#if CAN_WRAP_phy_drivers_unregister
    WRAP_FOR_DETACH(phy_drivers_unregister)
#endif
#ifndef CAN_WRAP_acpi_gsi_to_irq
#   define CAN_WRAP_acpi_gsi_to_irq 0
#endif
DETACH(acpi_gsi_to_irq)
#ifndef CAN_WRAP_security_key_getsecurity
#   define CAN_WRAP_security_key_getsecurity 1
#endif
#if CAN_WRAP_security_key_getsecurity
    WRAP_FOR_DETACH(security_key_getsecurity)
#endif
#ifndef CAN_WRAP_lapic_shutdown
#   define CAN_WRAP_lapic_shutdown 0
#endif
DETACH(lapic_shutdown)
#ifndef CAN_WRAP_simple_write_to_buffer
#   define CAN_WRAP_simple_write_to_buffer 0
#endif
DETACH(simple_write_to_buffer)
#ifndef CAN_WRAP_get_parent_ip
#   define CAN_WRAP_get_parent_ip 0
#endif
DETACH(get_parent_ip)
#ifndef CAN_WRAP_pvclock_read_flags
#   define CAN_WRAP_pvclock_read_flags 1
#endif
#if CAN_WRAP_pvclock_read_flags
    WRAP_FOR_DETACH(pvclock_read_flags)
#endif
#ifndef CAN_WRAP_pci_iounmap
#   define CAN_WRAP_pci_iounmap 1
#endif
#if CAN_WRAP_pci_iounmap
    WRAP_FOR_DETACH(pci_iounmap)
#endif
#ifndef CAN_WRAP_ata_std_qc_defer
#   define CAN_WRAP_ata_std_qc_defer 1
#endif
#if CAN_WRAP_ata_std_qc_defer
    WRAP_FOR_DETACH(ata_std_qc_defer)
#endif
#ifndef CAN_WRAP_unlink_file_vma
#   define CAN_WRAP_unlink_file_vma 1
#endif
#if CAN_WRAP_unlink_file_vma
    WRAP_FOR_DETACH(unlink_file_vma)
#endif
#ifndef CAN_WRAP_eisa_set_level_irq
#   define CAN_WRAP_eisa_set_level_irq 0
#endif
DETACH(eisa_set_level_irq)
#ifndef CAN_WRAP_set_pages_array_wc
#   define CAN_WRAP_set_pages_array_wc 0
#endif
DETACH(set_pages_array_wc)
#ifndef CAN_WRAP_set_pages_array_wb
#   define CAN_WRAP_set_pages_array_wb 0
#endif
DETACH(set_pages_array_wb)
#ifndef CAN_WRAP_percpu_down_read
#   define CAN_WRAP_percpu_down_read 1
#endif
#if CAN_WRAP_percpu_down_read
    WRAP_FOR_DETACH(percpu_down_read)
#endif
#ifndef CAN_WRAP___register_chrdev
#   define CAN_WRAP___register_chrdev 1
#endif
#if CAN_WRAP___register_chrdev
#   ifdef DETACH_ADDR___register_chrdev
        WRAP_FOR_DETACH(__register_chrdev)
#   else
        TYPED_DETACH(__register_chrdev)
#   endif
#endif
#ifndef CAN_WRAP_security_capset
#   define CAN_WRAP_security_capset 1
#endif
#if CAN_WRAP_security_capset
    WRAP_FOR_DETACH(security_capset)
#endif
#ifndef CAN_WRAP_get_super_thawed
#   define CAN_WRAP_get_super_thawed 1
#endif
#if CAN_WRAP_get_super_thawed
    WRAP_FOR_DETACH(get_super_thawed)
#endif
#ifndef CAN_WRAP_sk_stream_error
#   define CAN_WRAP_sk_stream_error 1
#endif
#if CAN_WRAP_sk_stream_error
    WRAP_FOR_DETACH(sk_stream_error)
#endif
#ifndef CAN_WRAP_mii_check_gmii_support
#   define CAN_WRAP_mii_check_gmii_support 1
#endif
#if CAN_WRAP_mii_check_gmii_support
    WRAP_FOR_DETACH(mii_check_gmii_support)
#endif
#ifndef CAN_WRAP_deactivate_locked_super
#   define CAN_WRAP_deactivate_locked_super 1
#endif
#if CAN_WRAP_deactivate_locked_super
    WRAP_FOR_DETACH(deactivate_locked_super)
#endif
#ifndef CAN_WRAP_acpi_run_osc
#   define CAN_WRAP_acpi_run_osc 1
#endif
#if CAN_WRAP_acpi_run_osc
    WRAP_FOR_DETACH(acpi_run_osc)
#endif
#ifndef CAN_WRAP_walk_system_ram_range
#   define CAN_WRAP_walk_system_ram_range 1
#endif
#if CAN_WRAP_walk_system_ram_range
    WRAP_FOR_DETACH(walk_system_ram_range)
#endif
#ifndef CAN_WRAP_render_sigset_t
#   define CAN_WRAP_render_sigset_t 1
#endif
#if CAN_WRAP_render_sigset_t
    WRAP_FOR_DETACH(render_sigset_t)
#endif
#ifndef CAN_WRAP_irq_get_next_irq
#   define CAN_WRAP_irq_get_next_irq 0
#endif
DETACH(irq_get_next_irq)
#ifndef CAN_WRAP_generic_handle_irq
#   define CAN_WRAP_generic_handle_irq 0
#endif
DETACH(generic_handle_irq)
#ifndef CAN_WRAP___ethtool_get_settings
#   define CAN_WRAP___ethtool_get_settings 1
#endif
#if CAN_WRAP___ethtool_get_settings
#   ifdef DETACH_ADDR___ethtool_get_settings
        WRAP_FOR_DETACH(__ethtool_get_settings)
#   else
        TYPED_DETACH(__ethtool_get_settings)
#   endif
#endif
#ifndef CAN_WRAP___bitmap_subset
#   define CAN_WRAP___bitmap_subset 0
#endif
DETACH(__bitmap_subset)
#ifndef CAN_WRAP_finish_wait
#   define CAN_WRAP_finish_wait 1
#endif
#if CAN_WRAP_finish_wait
    WRAP_FOR_DETACH(finish_wait)
#endif
#ifndef CAN_WRAP_device_add
#   define CAN_WRAP_device_add 1
#endif
#if CAN_WRAP_device_add
    WRAP_FOR_DETACH(device_add)
#endif
#ifndef CAN_WRAP_key_revoke
#   define CAN_WRAP_key_revoke 1
#endif
#if CAN_WRAP_key_revoke
    WRAP_FOR_DETACH(key_revoke)
#endif
#ifndef CAN_WRAP_acpi_install_interface_handler
#   define CAN_WRAP_acpi_install_interface_handler 1
#endif
#if CAN_WRAP_acpi_install_interface_handler
    WRAP_FOR_DETACH(acpi_install_interface_handler)
#endif
#ifndef CAN_WRAP_paravirt_end_context_switch
#   define CAN_WRAP_paravirt_end_context_switch 1
#endif
#if CAN_WRAP_paravirt_end_context_switch
    WRAP_FOR_DETACH(paravirt_end_context_switch)
#endif
#ifndef CAN_WRAP_device_register
#   define CAN_WRAP_device_register 1
#endif
#if CAN_WRAP_device_register
    WRAP_FOR_DETACH(device_register)
#endif
#ifndef CAN_WRAP___rt_mutex_init
#   define CAN_WRAP___rt_mutex_init 1
#endif
#if CAN_WRAP___rt_mutex_init
#   ifdef DETACH_ADDR___rt_mutex_init
        WRAP_FOR_DETACH(__rt_mutex_init)
#   else
        TYPED_DETACH(__rt_mutex_init)
#   endif
#endif
#ifndef CAN_WRAP_native_set_fixmap
#   define CAN_WRAP_native_set_fixmap 1
#endif
#if CAN_WRAP_native_set_fixmap
    WRAP_FOR_DETACH(native_set_fixmap)
#endif
#ifndef CAN_WRAP_ata_std_bios_param
#   define CAN_WRAP_ata_std_bios_param 1
#endif
#if CAN_WRAP_ata_std_bios_param
    WRAP_FOR_DETACH(ata_std_bios_param)
#endif
#ifndef CAN_WRAP_vlan_vids_add_by_dev
#   define CAN_WRAP_vlan_vids_add_by_dev 1
#endif
#if CAN_WRAP_vlan_vids_add_by_dev
    WRAP_FOR_DETACH(vlan_vids_add_by_dev)
#endif
#ifndef CAN_WRAP_do_splice_direct
#   define CAN_WRAP_do_splice_direct 1
#endif
#if CAN_WRAP_do_splice_direct
    WRAP_FOR_DETACH(do_splice_direct)
#endif
#ifndef CAN_WRAP_bio_map_user_iov
#   define CAN_WRAP_bio_map_user_iov 1
#endif
#if CAN_WRAP_bio_map_user_iov
    WRAP_FOR_DETACH(bio_map_user_iov)
#endif
#ifndef CAN_WRAP_unlock_flocks
#   define CAN_WRAP_unlock_flocks 0
#endif
DETACH(unlock_flocks)
#ifndef CAN_WRAP_skb_make_writable
#   define CAN_WRAP_skb_make_writable 1
#endif
#if CAN_WRAP_skb_make_writable
    WRAP_FOR_DETACH(skb_make_writable)
#endif
#ifndef CAN_WRAP_do_pipe_flags
#   define CAN_WRAP_do_pipe_flags 0
#endif
DETACH(do_pipe_flags)
#ifndef CAN_WRAP_module_refcount
#   define CAN_WRAP_module_refcount 1
#endif
#if CAN_WRAP_module_refcount
    WRAP_FOR_DETACH(module_refcount)
#endif
#ifndef CAN_WRAP_request_firmware_nowait
#   define CAN_WRAP_request_firmware_nowait 1
#endif
#if CAN_WRAP_request_firmware_nowait
    WRAP_FOR_DETACH(request_firmware_nowait)
#endif
#ifndef CAN_WRAP_default_setup_apic_routing
#   define CAN_WRAP_default_setup_apic_routing 0
#endif
DETACH(default_setup_apic_routing)
#ifndef CAN_WRAP_map_swap_page
#   define CAN_WRAP_map_swap_page 1
#endif
#if CAN_WRAP_map_swap_page
    WRAP_FOR_DETACH(map_swap_page)
#endif
#ifndef CAN_WRAP_phy_disconnect
#   define CAN_WRAP_phy_disconnect 1
#endif
#if CAN_WRAP_phy_disconnect
    WRAP_FOR_DETACH(phy_disconnect)
#endif
#ifndef CAN_WRAP_pid_ns_release_proc
#   define CAN_WRAP_pid_ns_release_proc 1
#endif
#if CAN_WRAP_pid_ns_release_proc
    WRAP_FOR_DETACH(pid_ns_release_proc)
#endif
#ifndef CAN_WRAP_phy_attach
#   define CAN_WRAP_phy_attach 1
#endif
#if CAN_WRAP_phy_attach
    WRAP_FOR_DETACH(phy_attach)
#endif
#ifndef CAN_WRAP_native_io_apic_read
#   define CAN_WRAP_native_io_apic_read 0
#endif
DETACH(native_io_apic_read)
#ifndef CAN_WRAP_set_normalized_timespec
#   define CAN_WRAP_set_normalized_timespec 1
#endif
#if CAN_WRAP_set_normalized_timespec
    WRAP_FOR_DETACH(set_normalized_timespec)
#endif
#ifndef CAN_WRAP_kernel_thread
#   define CAN_WRAP_kernel_thread 1
#endif
#if CAN_WRAP_kernel_thread
    WRAP_FOR_DETACH(kernel_thread)
#endif
#ifndef CAN_WRAP_exit_sem
#   define CAN_WRAP_exit_sem 1
#endif
#if CAN_WRAP_exit_sem
    WRAP_FOR_DETACH(exit_sem)
#endif
#ifndef CAN_WRAP_put_filesystem
#   define CAN_WRAP_put_filesystem 1
#endif
#if CAN_WRAP_put_filesystem
    WRAP_FOR_DETACH(put_filesystem)
#endif
#ifndef CAN_WRAP_unregister_filesystem
#   define CAN_WRAP_unregister_filesystem 1
#endif
#if CAN_WRAP_unregister_filesystem
    WRAP_FOR_DETACH(unregister_filesystem)
#endif
#ifndef CAN_WRAP_datagram_poll
#   define CAN_WRAP_datagram_poll 1
#endif
#if CAN_WRAP_datagram_poll
    WRAP_FOR_DETACH(datagram_poll)
#endif
#ifndef CAN_WRAP_pci_fixup_irqs
#   define CAN_WRAP_pci_fixup_irqs 1
#endif
#if CAN_WRAP_pci_fixup_irqs
    WRAP_FOR_DETACH(pci_fixup_irqs)
#endif
#ifndef CAN_WRAP_switch_to_new_gdt
#   define CAN_WRAP_switch_to_new_gdt 0
#endif
DETACH(switch_to_new_gdt)
#ifndef CAN_WRAP_clocksource_mmio_readw_down
#   define CAN_WRAP_clocksource_mmio_readw_down 1
#endif
#if CAN_WRAP_clocksource_mmio_readw_down
    WRAP_FOR_DETACH(clocksource_mmio_readw_down)
#endif
#ifndef CAN_WRAP_request_key_async
#   define CAN_WRAP_request_key_async 1
#endif
#if CAN_WRAP_request_key_async
    WRAP_FOR_DETACH(request_key_async)
#endif
#ifndef CAN_WRAP_idr_replace
#   define CAN_WRAP_idr_replace 1
#endif
#if CAN_WRAP_idr_replace
    WRAP_FOR_DETACH(idr_replace)
#endif
#ifndef CAN_WRAP_sk_chk_filter
#   define CAN_WRAP_sk_chk_filter 1
#endif
#if CAN_WRAP_sk_chk_filter
    WRAP_FOR_DETACH(sk_chk_filter)
#endif
#ifndef CAN_WRAP_abort_creds
#   define CAN_WRAP_abort_creds 1
#endif
#if CAN_WRAP_abort_creds
    WRAP_FOR_DETACH(abort_creds)
#endif
#ifndef CAN_WRAP_revert_creds
#   define CAN_WRAP_revert_creds 1
#endif
#if CAN_WRAP_revert_creds
    WRAP_FOR_DETACH(revert_creds)
#endif
#ifndef CAN_WRAP_handle_edge_eoi_irq
#   define CAN_WRAP_handle_edge_eoi_irq 1
#endif
#if CAN_WRAP_handle_edge_eoi_irq
    WRAP_FOR_DETACH(handle_edge_eoi_irq)
#endif
#ifndef CAN_WRAP_irq_set_percpu_devid
#   define CAN_WRAP_irq_set_percpu_devid 0
#endif
DETACH(irq_set_percpu_devid)
#ifndef CAN_WRAP_dma_wait_for_async_tx
#   define CAN_WRAP_dma_wait_for_async_tx 1
#endif
#if CAN_WRAP_dma_wait_for_async_tx
    WRAP_FOR_DETACH(dma_wait_for_async_tx)
#endif
#ifndef CAN_WRAP_sk_prot_clear_portaddr_nulls
#   define CAN_WRAP_sk_prot_clear_portaddr_nulls 1
#endif
#if CAN_WRAP_sk_prot_clear_portaddr_nulls
    WRAP_FOR_DETACH(sk_prot_clear_portaddr_nulls)
#endif
#ifndef CAN_WRAP_ata_sff_wait_ready
#   define CAN_WRAP_ata_sff_wait_ready 1
#endif
#if CAN_WRAP_ata_sff_wait_ready
    WRAP_FOR_DETACH(ata_sff_wait_ready)
#endif
#ifndef CAN_WRAP_schedule_on_each_cpu
#   define CAN_WRAP_schedule_on_each_cpu 1
#endif
#if CAN_WRAP_schedule_on_each_cpu
    WRAP_FOR_DETACH(schedule_on_each_cpu)
#endif
#ifndef CAN_WRAP_init_irq_proc
#   define CAN_WRAP_init_irq_proc 0
#endif
DETACH(init_irq_proc)
#ifndef CAN_WRAP_blk_integrity_unregister
#   define CAN_WRAP_blk_integrity_unregister 1
#endif
#if CAN_WRAP_blk_integrity_unregister
    WRAP_FOR_DETACH(blk_integrity_unregister)
#endif
#ifndef CAN_WRAP_find_get_pages_contig
#   define CAN_WRAP_find_get_pages_contig 1
#endif
#if CAN_WRAP_find_get_pages_contig
    WRAP_FOR_DETACH(find_get_pages_contig)
#endif
#ifndef CAN_WRAP_irq_can_set_affinity
#   define CAN_WRAP_irq_can_set_affinity 0
#endif
DETACH(irq_can_set_affinity)
#ifndef CAN_WRAP_e820_update_range
#   define CAN_WRAP_e820_update_range 0
#endif
DETACH(e820_update_range)
#ifndef CAN_WRAP_rotate_reclaimable_page
#   define CAN_WRAP_rotate_reclaimable_page 1
#endif
#if CAN_WRAP_rotate_reclaimable_page
    WRAP_FOR_DETACH(rotate_reclaimable_page)
#endif
#ifndef CAN_WRAP_sk_receive_skb
#   define CAN_WRAP_sk_receive_skb 1
#endif
#if CAN_WRAP_sk_receive_skb
    WRAP_FOR_DETACH(sk_receive_skb)
#endif
#ifndef CAN_WRAP_ata_acpi_stm
#   define CAN_WRAP_ata_acpi_stm 1
#endif
#if CAN_WRAP_ata_acpi_stm
    WRAP_FOR_DETACH(ata_acpi_stm)
#endif
#ifndef CAN_WRAP_set_device_ro
#   define CAN_WRAP_set_device_ro 1
#endif
#if CAN_WRAP_set_device_ro
    WRAP_FOR_DETACH(set_device_ro)
#endif
#ifndef CAN_WRAP_copy_from_user_nmi
#   define CAN_WRAP_copy_from_user_nmi 0
#endif
DETACH(copy_from_user_nmi)
#ifndef CAN_WRAP_dma_pool_create
#   define CAN_WRAP_dma_pool_create 1
#endif
#if CAN_WRAP_dma_pool_create
    WRAP_FOR_DETACH(dma_pool_create)
#endif
#ifndef CAN_WRAP_exit_files
#   define CAN_WRAP_exit_files 1
#endif
#if CAN_WRAP_exit_files
    WRAP_FOR_DETACH(exit_files)
#endif
#ifndef CAN_WRAP_insert_resource_conflict
#   define CAN_WRAP_insert_resource_conflict 1
#endif
#if CAN_WRAP_insert_resource_conflict
    WRAP_FOR_DETACH(insert_resource_conflict)
#endif
#ifndef CAN_WRAP_rdmsr_on_cpu
#   define CAN_WRAP_rdmsr_on_cpu 0
#endif
DETACH(rdmsr_on_cpu)
#ifndef CAN_WRAP_security_file_send_sigiotask
#   define CAN_WRAP_security_file_send_sigiotask 1
#endif
#if CAN_WRAP_security_file_send_sigiotask
    WRAP_FOR_DETACH(security_file_send_sigiotask)
#endif
#ifndef CAN_WRAP_add_to_page_cache_lru
#   define CAN_WRAP_add_to_page_cache_lru 1
#endif
#if CAN_WRAP_add_to_page_cache_lru
    WRAP_FOR_DETACH(add_to_page_cache_lru)
#endif
#ifndef CAN_WRAP_in_egroup_p
#   define CAN_WRAP_in_egroup_p 0
#endif
DETACH(in_egroup_p)
#ifndef CAN_WRAP_irq_force_complete_move
#   define CAN_WRAP_irq_force_complete_move 0
#endif
DETACH(irq_force_complete_move)
#ifndef CAN_WRAP_bio_add_pc_page
#   define CAN_WRAP_bio_add_pc_page 1
#endif
#if CAN_WRAP_bio_add_pc_page
    WRAP_FOR_DETACH(bio_add_pc_page)
#endif
#ifndef CAN_WRAP_cpu_has_amd_erratum
#   define CAN_WRAP_cpu_has_amd_erratum 0
#endif
DETACH(cpu_has_amd_erratum)
#ifndef CAN_WRAP_rb_first
#   define CAN_WRAP_rb_first 1
#endif
#if CAN_WRAP_rb_first
    WRAP_FOR_DETACH(rb_first)
#endif
#ifndef CAN_WRAP_ktime_add_safe
#   define CAN_WRAP_ktime_add_safe 0
#endif
DETACH(ktime_add_safe)
#ifndef CAN_WRAP_jbd2_journal_extend
#   define CAN_WRAP_jbd2_journal_extend 1
#endif
#if CAN_WRAP_jbd2_journal_extend
    WRAP_FOR_DETACH(jbd2_journal_extend)
#endif
#ifndef CAN_WRAP___put_cred
#   define CAN_WRAP___put_cred 1
#endif
#if CAN_WRAP___put_cred
#   ifdef DETACH_ADDR___put_cred
        WRAP_FOR_DETACH(__put_cred)
#   else
        TYPED_DETACH(__put_cred)
#   endif
#endif
#ifndef CAN_WRAP_file_read_actor
#   define CAN_WRAP_file_read_actor 1
#endif
#if CAN_WRAP_file_read_actor
    WRAP_FOR_DETACH(file_read_actor)
#endif
#ifndef CAN_WRAP_pci_lost_interrupt
#   define CAN_WRAP_pci_lost_interrupt 1
#endif
#if CAN_WRAP_pci_lost_interrupt
    WRAP_FOR_DETACH(pci_lost_interrupt)
#endif
#ifndef CAN_WRAP_kmem_cache_alloc_node_trace
#   define CAN_WRAP_kmem_cache_alloc_node_trace 1
#endif
#if CAN_WRAP_kmem_cache_alloc_node_trace
    WRAP_FOR_DETACH(kmem_cache_alloc_node_trace)
#endif
#ifndef CAN_WRAP_d_materialise_unique
#   define CAN_WRAP_d_materialise_unique 1
#endif
#if CAN_WRAP_d_materialise_unique
    WRAP_FOR_DETACH(d_materialise_unique)
#endif
#ifndef CAN_WRAP_security_cred_alloc_blank
#   define CAN_WRAP_security_cred_alloc_blank 1
#endif
#if CAN_WRAP_security_cred_alloc_blank
    WRAP_FOR_DETACH(security_cred_alloc_blank)
#endif
#ifndef CAN_WRAP_vfs_mknod
#   define CAN_WRAP_vfs_mknod 1
#endif
#if CAN_WRAP_vfs_mknod
    WRAP_FOR_DETACH(vfs_mknod)
#endif
#ifndef CAN_WRAP_sock_i_uid
#   define CAN_WRAP_sock_i_uid 1
#endif
#if CAN_WRAP_sock_i_uid
    WRAP_FOR_DETACH(sock_i_uid)
#endif
#ifndef CAN_WRAP_acpi_get_physical_device_location
#   define CAN_WRAP_acpi_get_physical_device_location 0
#endif
DETACH(acpi_get_physical_device_location)
#ifndef CAN_WRAP_clockevent_delta2ns
#   define CAN_WRAP_clockevent_delta2ns 1
#endif
#if CAN_WRAP_clockevent_delta2ns
    WRAP_FOR_DETACH(clockevent_delta2ns)
#endif
#ifndef CAN_WRAP_jbd2_trans_will_send_data_barrier
#   define CAN_WRAP_jbd2_trans_will_send_data_barrier 1
#endif
#if CAN_WRAP_jbd2_trans_will_send_data_barrier
    WRAP_FOR_DETACH(jbd2_trans_will_send_data_barrier)
#endif
#ifndef CAN_WRAP_set_kernel_text_rw
#   define CAN_WRAP_set_kernel_text_rw 0
#endif
DETACH(set_kernel_text_rw)
#ifndef CAN_WRAP_pmdp_invalidate
#   define CAN_WRAP_pmdp_invalidate 1
#endif
#if CAN_WRAP_pmdp_invalidate
    WRAP_FOR_DETACH(pmdp_invalidate)
#endif
#ifndef CAN_WRAP_set_kernel_text_ro
#   define CAN_WRAP_set_kernel_text_ro 0
#endif
DETACH(set_kernel_text_ro)
#ifndef CAN_WRAP_rtnl_configure_link
#   define CAN_WRAP_rtnl_configure_link 1
#endif
#if CAN_WRAP_rtnl_configure_link
    WRAP_FOR_DETACH(rtnl_configure_link)
#endif
#ifndef CAN_WRAP_timekeeping_notify
#   define CAN_WRAP_timekeeping_notify 1
#endif
#if CAN_WRAP_timekeeping_notify
    WRAP_FOR_DETACH(timekeeping_notify)
#endif
#ifndef CAN_WRAP_irq_set_handler_data
#   define CAN_WRAP_irq_set_handler_data 0
#endif
DETACH(irq_set_handler_data)
#ifndef CAN_WRAP_strnstr
#   define CAN_WRAP_strnstr 0
#endif
DETACH(strnstr)
#ifndef CAN_WRAP_int_sqrt
#   define CAN_WRAP_int_sqrt 0
#endif
DETACH(int_sqrt)
#ifndef CAN_WRAP_security_sb_clone_mnt_opts
#   define CAN_WRAP_security_sb_clone_mnt_opts 1
#endif
#if CAN_WRAP_security_sb_clone_mnt_opts
    WRAP_FOR_DETACH(security_sb_clone_mnt_opts)
#endif
#ifndef CAN_WRAP_raw_pci_read
#   define CAN_WRAP_raw_pci_read 0
#endif
DETACH(raw_pci_read)
#ifndef CAN_WRAP_security_path_chmod
#   define CAN_WRAP_security_path_chmod 1
#endif
#if CAN_WRAP_security_path_chmod
    WRAP_FOR_DETACH(security_path_chmod)
#endif
#ifndef CAN_WRAP_compat_sys_newfstat
#   define CAN_WRAP_compat_sys_newfstat 1
#endif
#if CAN_WRAP_compat_sys_newfstat
    WRAP_FOR_DETACH(compat_sys_newfstat)
#endif
#ifndef CAN_WRAP_ioread16_rep
#   define CAN_WRAP_ioread16_rep 0
#endif
DETACH(ioread16_rep)
#ifndef CAN_WRAP_disk_clear_events
#   define CAN_WRAP_disk_clear_events 1
#endif
#if CAN_WRAP_disk_clear_events
    WRAP_FOR_DETACH(disk_clear_events)
#endif
#ifndef CAN_WRAP_security_inode_free
#   define CAN_WRAP_security_inode_free 1
#endif
#if CAN_WRAP_security_inode_free
    WRAP_FOR_DETACH(security_inode_free)
#endif
#ifndef CAN_WRAP_gnet_stats_copy_rate_est
#   define CAN_WRAP_gnet_stats_copy_rate_est 1
#endif
#if CAN_WRAP_gnet_stats_copy_rate_est
    WRAP_FOR_DETACH(gnet_stats_copy_rate_est)
#endif
#ifndef CAN_WRAP_dev_pm_qos_update_flags
#   define CAN_WRAP_dev_pm_qos_update_flags 1
#endif
#if CAN_WRAP_dev_pm_qos_update_flags
    WRAP_FOR_DETACH(dev_pm_qos_update_flags)
#endif
#ifndef CAN_WRAP_dquot_release
#   define CAN_WRAP_dquot_release 1
#endif
#if CAN_WRAP_dquot_release
    WRAP_FOR_DETACH(dquot_release)
#endif
#ifndef CAN_WRAP_cpu_coregroup_mask
#   define CAN_WRAP_cpu_coregroup_mask 1
#endif
#if CAN_WRAP_cpu_coregroup_mask
    WRAP_FOR_DETACH(cpu_coregroup_mask)
#endif
#ifndef CAN_WRAP_clocksource_resume
#   define CAN_WRAP_clocksource_resume 0
#endif
DETACH(clocksource_resume)
#ifndef CAN_WRAP_security_tun_dev_open
#   define CAN_WRAP_security_tun_dev_open 0
#endif
DETACH(security_tun_dev_open)
#ifndef CAN_WRAP_ata_tf_from_fis
#   define CAN_WRAP_ata_tf_from_fis 1
#endif
#if CAN_WRAP_ata_tf_from_fis
    WRAP_FOR_DETACH(ata_tf_from_fis)
#endif
#ifndef CAN_WRAP_devm_request_threaded_irq
#   define CAN_WRAP_devm_request_threaded_irq 1
#endif
#if CAN_WRAP_devm_request_threaded_irq
    WRAP_FOR_DETACH(devm_request_threaded_irq)
#endif
#ifndef CAN_WRAP_compat_sys_mq_notify
#   define CAN_WRAP_compat_sys_mq_notify 1
#endif
#if CAN_WRAP_compat_sys_mq_notify
    WRAP_FOR_DETACH(compat_sys_mq_notify)
#endif
#ifndef CAN_WRAP_bus_create_file
#   define CAN_WRAP_bus_create_file 1
#endif
#if CAN_WRAP_bus_create_file
    WRAP_FOR_DETACH(bus_create_file)
#endif
#ifndef CAN_WRAP_dcb_getapp
#   define CAN_WRAP_dcb_getapp 1
#endif
#if CAN_WRAP_dcb_getapp
    WRAP_FOR_DETACH(dcb_getapp)
#endif
#ifndef CAN_WRAP_sock_no_recvmsg
#   define CAN_WRAP_sock_no_recvmsg 1
#endif
#if CAN_WRAP_sock_no_recvmsg
    WRAP_FOR_DETACH(sock_no_recvmsg)
#endif
#ifndef CAN_WRAP_dev_pm_qos_constraints_destroy
#   define CAN_WRAP_dev_pm_qos_constraints_destroy 1
#endif
#if CAN_WRAP_dev_pm_qos_constraints_destroy
    WRAP_FOR_DETACH(dev_pm_qos_constraints_destroy)
#endif
#ifndef CAN_WRAP_set_nlink
#   define CAN_WRAP_set_nlink 1
#endif
#if CAN_WRAP_set_nlink
    WRAP_FOR_DETACH(set_nlink)
#endif
#ifndef CAN_WRAP_mm_release
#   define CAN_WRAP_mm_release 1
#endif
#if CAN_WRAP_mm_release
    WRAP_FOR_DETACH(mm_release)
#endif
#ifndef CAN_WRAP_compat_sys_fstatfs
#   define CAN_WRAP_compat_sys_fstatfs 1
#endif
#if CAN_WRAP_compat_sys_fstatfs
    WRAP_FOR_DETACH(compat_sys_fstatfs)
#endif
#ifndef CAN_WRAP_netlink_unregister_notifier
#   define CAN_WRAP_netlink_unregister_notifier 1
#endif
#if CAN_WRAP_netlink_unregister_notifier
    WRAP_FOR_DETACH(netlink_unregister_notifier)
#endif
#ifndef CAN_WRAP_machine_restart
#   define CAN_WRAP_machine_restart 0
#endif
DETACH(machine_restart)
#ifndef CAN_WRAP___wait_on_buffer
#   define CAN_WRAP___wait_on_buffer 1
#endif
#if CAN_WRAP___wait_on_buffer
#   ifdef DETACH_ADDR___wait_on_buffer
        WRAP_FOR_DETACH(__wait_on_buffer)
#   else
        TYPED_DETACH(__wait_on_buffer)
#   endif
#endif
#ifndef CAN_WRAP_skb_complete_wifi_ack
#   define CAN_WRAP_skb_complete_wifi_ack 1
#endif
#if CAN_WRAP_skb_complete_wifi_ack
    WRAP_FOR_DETACH(skb_complete_wifi_ack)
#endif
#ifndef CAN_WRAP_security_kernel_create_files_as
#   define CAN_WRAP_security_kernel_create_files_as 1
#endif
#if CAN_WRAP_security_kernel_create_files_as
    WRAP_FOR_DETACH(security_kernel_create_files_as)
#endif
#ifndef CAN_WRAP_inet_proto_csum_replace16
#   define CAN_WRAP_inet_proto_csum_replace16 1
#endif
#if CAN_WRAP_inet_proto_csum_replace16
    WRAP_FOR_DETACH(inet_proto_csum_replace16)
#endif
#ifndef CAN_WRAP___bitmap_empty
#   define CAN_WRAP___bitmap_empty 0
#endif
DETACH(__bitmap_empty)
#ifndef CAN_WRAP_copy_user_generic_unrolled
#   define CAN_WRAP_copy_user_generic_unrolled 0
#endif
DETACH(copy_user_generic_unrolled)
#ifndef CAN_WRAP_param_get_ulong
#   define CAN_WRAP_param_get_ulong 1
#endif
#if CAN_WRAP_param_get_ulong
    WRAP_FOR_DETACH(param_get_ulong)
#endif
#ifndef CAN_WRAP_acpi_find_root_pointer
#   define CAN_WRAP_acpi_find_root_pointer 0
#endif
DETACH(acpi_find_root_pointer)
#ifndef CAN_WRAP_laptop_sync_completion
#   define CAN_WRAP_laptop_sync_completion 0
#endif
DETACH(laptop_sync_completion)
#ifndef CAN_WRAP_down_interruptible
#   define CAN_WRAP_down_interruptible 1
#endif
#if CAN_WRAP_down_interruptible
    WRAP_FOR_DETACH(down_interruptible)
#endif
#ifndef CAN_WRAP_sparse_remove_one_section
#   define CAN_WRAP_sparse_remove_one_section 1
#endif
#if CAN_WRAP_sparse_remove_one_section
    WRAP_FOR_DETACH(sparse_remove_one_section)
#endif
#ifndef CAN_WRAP_spurious_interrupt
#   define CAN_WRAP_spurious_interrupt 0
#endif
DETACH(spurious_interrupt)
#ifndef CAN_WRAP_mp_find_ioapic_pin
#   define CAN_WRAP_mp_find_ioapic_pin 0
#endif
DETACH(mp_find_ioapic_pin)
#ifndef CAN_WRAP_add_to_swap
#   define CAN_WRAP_add_to_swap 1
#endif
#if CAN_WRAP_add_to_swap
    WRAP_FOR_DETACH(add_to_swap)
#endif
#ifndef CAN_WRAP_swiotlb_sync_sg_for_cpu
#   define CAN_WRAP_swiotlb_sync_sg_for_cpu 1
#endif
#if CAN_WRAP_swiotlb_sync_sg_for_cpu
    WRAP_FOR_DETACH(swiotlb_sync_sg_for_cpu)
#endif
#ifndef CAN_WRAP___kmalloc_node_track_caller
#   define CAN_WRAP___kmalloc_node_track_caller 0
#endif
DETACH(__kmalloc_node_track_caller)
#ifndef CAN_WRAP_acpi_set_current_resources
#   define CAN_WRAP_acpi_set_current_resources 1
#endif
#if CAN_WRAP_acpi_set_current_resources
    WRAP_FOR_DETACH(acpi_set_current_resources)
#endif
#ifndef CAN_WRAP___copy_user_nocache
#   define CAN_WRAP___copy_user_nocache 0
#endif
DETACH(__copy_user_nocache)
#ifndef CAN_WRAP___journal_free_buffer
#   define CAN_WRAP___journal_free_buffer 1
#endif
#if CAN_WRAP___journal_free_buffer
#   ifdef DETACH_ADDR___journal_free_buffer
        WRAP_FOR_DETACH(__journal_free_buffer)
#   else
        TYPED_DETACH(__journal_free_buffer)
#   endif
#endif
#ifndef CAN_WRAP_blk_queue_max_write_same_sectors
#   define CAN_WRAP_blk_queue_max_write_same_sectors 1
#endif
#if CAN_WRAP_blk_queue_max_write_same_sectors
    WRAP_FOR_DETACH(blk_queue_max_write_same_sectors)
#endif
#ifndef CAN_WRAP_devres_remove
#   define CAN_WRAP_devres_remove 1
#endif
#if CAN_WRAP_devres_remove
    WRAP_FOR_DETACH(devres_remove)
#endif
#ifndef CAN_WRAP_cdrom_mode_sense
#   define CAN_WRAP_cdrom_mode_sense 1
#endif
#if CAN_WRAP_cdrom_mode_sense
    WRAP_FOR_DETACH(cdrom_mode_sense)
#endif
#ifndef CAN_WRAP_security_inode_removexattr
#   define CAN_WRAP_security_inode_removexattr 1
#endif
#if CAN_WRAP_security_inode_removexattr
    WRAP_FOR_DETACH(security_inode_removexattr)
#endif
#ifndef CAN_WRAP_scan_unevictable_unregister_node
#   define CAN_WRAP_scan_unevictable_unregister_node 1
#endif
#if CAN_WRAP_scan_unevictable_unregister_node
    WRAP_FOR_DETACH(scan_unevictable_unregister_node)
#endif
#ifndef CAN_WRAP_acpi_disable_gpe
#   define CAN_WRAP_acpi_disable_gpe 0
#endif
DETACH(acpi_disable_gpe)
#ifndef CAN_WRAP_do_huge_pmd_anonymous_page
#   define CAN_WRAP_do_huge_pmd_anonymous_page 1
#endif
#if CAN_WRAP_do_huge_pmd_anonymous_page
    WRAP_FOR_DETACH(do_huge_pmd_anonymous_page)
#endif
#ifndef CAN_WRAP_block_commit_write
#   define CAN_WRAP_block_commit_write 1
#endif
#if CAN_WRAP_block_commit_write
    WRAP_FOR_DETACH(block_commit_write)
#endif
#ifndef CAN_WRAP_grab_cache_page_nowait
#   define CAN_WRAP_grab_cache_page_nowait 1
#endif
#if CAN_WRAP_grab_cache_page_nowait
    WRAP_FOR_DETACH(grab_cache_page_nowait)
#endif
#ifndef CAN_WRAP_ioread16be
#   define CAN_WRAP_ioread16be 0
#endif
DETACH(ioread16be)
#ifndef CAN_WRAP_blk_execute_rq
#   define CAN_WRAP_blk_execute_rq 1
#endif
#if CAN_WRAP_blk_execute_rq
    WRAP_FOR_DETACH(blk_execute_rq)
#endif
#ifndef CAN_WRAP_process_srcu
#   define CAN_WRAP_process_srcu 1
#endif
#if CAN_WRAP_process_srcu
    WRAP_FOR_DETACH(process_srcu)
#endif
#ifndef CAN_WRAP_acpi_get_pci_dev
#   define CAN_WRAP_acpi_get_pci_dev 1
#endif
#if CAN_WRAP_acpi_get_pci_dev
    WRAP_FOR_DETACH(acpi_get_pci_dev)
#endif
#ifndef CAN_WRAP_compat_sys_waitid
#   define CAN_WRAP_compat_sys_waitid 1
#endif
#if CAN_WRAP_compat_sys_waitid
    WRAP_FOR_DETACH(compat_sys_waitid)
#endif
#ifndef CAN_WRAP_setup_IO_APIC
#   define CAN_WRAP_setup_IO_APIC 0
#endif
DETACH(setup_IO_APIC)
#ifndef CAN_WRAP_vm_munmap
#   define CAN_WRAP_vm_munmap 0
#endif
DETACH(vm_munmap)
#ifndef CAN_WRAP_force_sig
#   define CAN_WRAP_force_sig 1
#endif
#if CAN_WRAP_force_sig
    WRAP_FOR_DETACH(force_sig)
#endif
#ifndef CAN_WRAP_generic_processor_info
#   define CAN_WRAP_generic_processor_info 0
#endif
DETACH(generic_processor_info)
#ifndef CAN_WRAP_rb_insert_color
#   define CAN_WRAP_rb_insert_color 1
#endif
#if CAN_WRAP_rb_insert_color
    WRAP_FOR_DETACH(rb_insert_color)
#endif
#ifndef CAN_WRAP_iterate_bdevs
#   define CAN_WRAP_iterate_bdevs 1
#endif
#if CAN_WRAP_iterate_bdevs
    WRAP_FOR_DETACH(iterate_bdevs)
#endif
#ifndef CAN_WRAP_security_path_truncate
#   define CAN_WRAP_security_path_truncate 1
#endif
#if CAN_WRAP_security_path_truncate
    WRAP_FOR_DETACH(security_path_truncate)
#endif
#ifndef CAN_WRAP_vmalloc_32
#   define CAN_WRAP_vmalloc_32 0
#endif
DETACH(vmalloc_32)
#ifndef CAN_WRAP_monotonic_to_bootbased
#   define CAN_WRAP_monotonic_to_bootbased 1
#endif
#if CAN_WRAP_monotonic_to_bootbased
    WRAP_FOR_DETACH(monotonic_to_bootbased)
#endif
#ifndef CAN_WRAP_pci_bus_add_devices
#   define CAN_WRAP_pci_bus_add_devices 1
#endif
#if CAN_WRAP_pci_bus_add_devices
    WRAP_FOR_DETACH(pci_bus_add_devices)
#endif
#ifndef CAN_WRAP_elv_rq_merge_ok
#   define CAN_WRAP_elv_rq_merge_ok 1
#endif
#if CAN_WRAP_elv_rq_merge_ok
    WRAP_FOR_DETACH(elv_rq_merge_ok)
#endif
#ifndef CAN_WRAP_inode_capable
#   define CAN_WRAP_inode_capable 1
#endif
#if CAN_WRAP_inode_capable
    WRAP_FOR_DETACH(inode_capable)
#endif
#ifndef CAN_WRAP_security_tun_dev_free_security
#   define CAN_WRAP_security_tun_dev_free_security 0
#endif
DETACH(security_tun_dev_free_security)
#ifndef CAN_WRAP_sock_getsockopt
#   define CAN_WRAP_sock_getsockopt 1
#endif
#if CAN_WRAP_sock_getsockopt
    WRAP_FOR_DETACH(sock_getsockopt)
#endif
#ifndef CAN_WRAP_set_cpu_present
#   define CAN_WRAP_set_cpu_present 0
#endif
DETACH(set_cpu_present)
#ifndef CAN_WRAP_vma_wants_writenotify
#   define CAN_WRAP_vma_wants_writenotify 1
#endif
#if CAN_WRAP_vma_wants_writenotify
    WRAP_FOR_DETACH(vma_wants_writenotify)
#endif
#ifndef CAN_WRAP_acpi_dev_irq_flags
#   define CAN_WRAP_acpi_dev_irq_flags 0
#endif
DETACH(acpi_dev_irq_flags)
#ifndef CAN_WRAP_hrtimer_peek_ahead_timers
#   define CAN_WRAP_hrtimer_peek_ahead_timers 0
#endif
DETACH(hrtimer_peek_ahead_timers)
#ifndef CAN_WRAP___lock_task_sighand
#   define CAN_WRAP___lock_task_sighand 1
#endif
#if CAN_WRAP___lock_task_sighand
#   ifdef DETACH_ADDR___lock_task_sighand
        WRAP_FOR_DETACH(__lock_task_sighand)
#   else
        TYPED_DETACH(__lock_task_sighand)
#   endif
#endif
#ifndef CAN_WRAP___delay
#   define CAN_WRAP___delay 0
#endif
DETACH(__delay)
#ifndef CAN_WRAP_writeback_inodes_sb_if_idle
#   define CAN_WRAP_writeback_inodes_sb_if_idle 1
#endif
#if CAN_WRAP_writeback_inodes_sb_if_idle
    WRAP_FOR_DETACH(writeback_inodes_sb_if_idle)
#endif
#ifndef CAN_WRAP_mb_cache_entry_free
#   define CAN_WRAP_mb_cache_entry_free 1
#endif
#if CAN_WRAP_mb_cache_entry_free
    WRAP_FOR_DETACH(mb_cache_entry_free)
#endif
#ifndef CAN_WRAP___fentry__
#   define CAN_WRAP___fentry__ 0
#endif
DETACH(__fentry__)
#ifndef CAN_WRAP_blocking_notifier_chain_cond_register
#   define CAN_WRAP_blocking_notifier_chain_cond_register 1
#endif
#if CAN_WRAP_blocking_notifier_chain_cond_register
    WRAP_FOR_DETACH(blocking_notifier_chain_cond_register)
#endif
#ifndef CAN_WRAP_dcb_setapp
#   define CAN_WRAP_dcb_setapp 1
#endif
#if CAN_WRAP_dcb_setapp
    WRAP_FOR_DETACH(dcb_setapp)
#endif
#ifndef CAN_WRAP_cdrom_media_changed
#   define CAN_WRAP_cdrom_media_changed 1
#endif
#if CAN_WRAP_cdrom_media_changed
    WRAP_FOR_DETACH(cdrom_media_changed)
#endif
#ifndef CAN_WRAP_sched_proc_update_handler
#   define CAN_WRAP_sched_proc_update_handler 1
#endif
#if CAN_WRAP_sched_proc_update_handler
    WRAP_FOR_DETACH(sched_proc_update_handler)
#endif
#ifndef CAN_WRAP_lru_add_drain_cpu
#   define CAN_WRAP_lru_add_drain_cpu 0
#endif
DETACH(lru_add_drain_cpu)
#ifndef CAN_WRAP_compat_sys_readv
#   define CAN_WRAP_compat_sys_readv 1
#endif
#if CAN_WRAP_compat_sys_readv
    WRAP_FOR_DETACH(compat_sys_readv)
#endif
#ifndef CAN_WRAP_blk_register_region
#   define CAN_WRAP_blk_register_region 1
#endif
#if CAN_WRAP_blk_register_region
    WRAP_FOR_DETACH(blk_register_region)
#endif
#ifndef CAN_WRAP_ida_remove
#   define CAN_WRAP_ida_remove 1
#endif
#if CAN_WRAP_ida_remove
    WRAP_FOR_DETACH(ida_remove)
#endif
#ifndef CAN_WRAP_pci_unregister_driver
#   define CAN_WRAP_pci_unregister_driver 1
#endif
#if CAN_WRAP_pci_unregister_driver
    WRAP_FOR_DETACH(pci_unregister_driver)
#endif
#ifndef CAN_WRAP_nobh_truncate_page
#   define CAN_WRAP_nobh_truncate_page 1
#endif
#if CAN_WRAP_nobh_truncate_page
    WRAP_FOR_DETACH(nobh_truncate_page)
#endif
#ifndef CAN_WRAP_can_do_mlock
#   define CAN_WRAP_can_do_mlock 0
#endif
DETACH(can_do_mlock)
#ifndef CAN_WRAP_module_param_sysfs_remove
#   define CAN_WRAP_module_param_sysfs_remove 1
#endif
#if CAN_WRAP_module_param_sysfs_remove
    WRAP_FOR_DETACH(module_param_sysfs_remove)
#endif
#ifndef CAN_WRAP_jbd2_journal_flush
#   define CAN_WRAP_jbd2_journal_flush 1
#endif
#if CAN_WRAP_jbd2_journal_flush
    WRAP_FOR_DETACH(jbd2_journal_flush)
#endif
#ifndef CAN_WRAP_select_estimate_accuracy
#   define CAN_WRAP_select_estimate_accuracy 1
#endif
#if CAN_WRAP_select_estimate_accuracy
    WRAP_FOR_DETACH(select_estimate_accuracy)
#endif
#ifndef CAN_WRAP_pci_msix_table_size
#   define CAN_WRAP_pci_msix_table_size 1
#endif
#if CAN_WRAP_pci_msix_table_size
    WRAP_FOR_DETACH(pci_msix_table_size)
#endif
#ifndef CAN_WRAP_iowrite32_rep
#   define CAN_WRAP_iowrite32_rep 0
#endif
DETACH(iowrite32_rep)
#ifndef CAN_WRAP_d_path_with_unreachable
#   define CAN_WRAP_d_path_with_unreachable 1
#endif
#if CAN_WRAP_d_path_with_unreachable
    WRAP_FOR_DETACH(d_path_with_unreachable)
#endif
#ifndef CAN_WRAP_simple_setattr
#   define CAN_WRAP_simple_setattr 1
#endif
#if CAN_WRAP_simple_setattr
    WRAP_FOR_DETACH(simple_setattr)
#endif
#ifndef CAN_WRAP___qdisc_run
#   define CAN_WRAP___qdisc_run 1
#endif
#if CAN_WRAP___qdisc_run
#   ifdef DETACH_ADDR___qdisc_run
        WRAP_FOR_DETACH(__qdisc_run)
#   else
        TYPED_DETACH(__qdisc_run)
#   endif
#endif
#ifndef CAN_WRAP_ata_link_online
#   define CAN_WRAP_ata_link_online 1
#endif
#if CAN_WRAP_ata_link_online
    WRAP_FOR_DETACH(ata_link_online)
#endif
#ifndef CAN_WRAP_cap_task_prctl
#   define CAN_WRAP_cap_task_prctl 0
#endif
DETACH(cap_task_prctl)
#ifndef CAN_WRAP_simple_xattr_remove
#   define CAN_WRAP_simple_xattr_remove 1
#endif
#if CAN_WRAP_simple_xattr_remove
    WRAP_FOR_DETACH(simple_xattr_remove)
#endif
#ifndef CAN_WRAP___bitmap_shift_left
#   define CAN_WRAP___bitmap_shift_left 0
#endif
DETACH(__bitmap_shift_left)
#ifndef CAN_WRAP_preempt_notifier_register
#   define CAN_WRAP_preempt_notifier_register 1
#endif
#if CAN_WRAP_preempt_notifier_register
    WRAP_FOR_DETACH(preempt_notifier_register)
#endif
#ifndef CAN_WRAP_sk_get_filter
#   define CAN_WRAP_sk_get_filter 1
#endif
#if CAN_WRAP_sk_get_filter
    WRAP_FOR_DETACH(sk_get_filter)
#endif
#ifndef CAN_WRAP_dev_mc_unsync
#   define CAN_WRAP_dev_mc_unsync 1
#endif
#if CAN_WRAP_dev_mc_unsync
    WRAP_FOR_DETACH(dev_mc_unsync)
#endif
#ifndef CAN_WRAP_change_create_files_as
#   define CAN_WRAP_change_create_files_as 1
#endif
#if CAN_WRAP_change_create_files_as
    WRAP_FOR_DETACH(change_create_files_as)
#endif
#ifndef CAN_WRAP_pci_disable_sriov
#   define CAN_WRAP_pci_disable_sriov 1
#endif
#if CAN_WRAP_pci_disable_sriov
    WRAP_FOR_DETACH(pci_disable_sriov)
#endif
#ifndef CAN_WRAP_acpi_os_stall
#   define CAN_WRAP_acpi_os_stall 0
#endif
DETACH(acpi_os_stall)
#ifndef CAN_WRAP_acpi_unregister_gsi
#   define CAN_WRAP_acpi_unregister_gsi 0
#endif
DETACH(acpi_unregister_gsi)
#ifndef CAN_WRAP_sock_no_shutdown
#   define CAN_WRAP_sock_no_shutdown 1
#endif
#if CAN_WRAP_sock_no_shutdown
    WRAP_FOR_DETACH(sock_no_shutdown)
#endif
#ifndef CAN_WRAP_compat_sys_shmat
#   define CAN_WRAP_compat_sys_shmat 0
#endif
DETACH(compat_sys_shmat)
#ifndef CAN_WRAP___kmalloc_node
#   define CAN_WRAP___kmalloc_node 0
#endif
DETACH(__kmalloc_node)
#ifndef CAN_WRAP_select_idle_routine
#   define CAN_WRAP_select_idle_routine 1
#endif
#if CAN_WRAP_select_idle_routine
    WRAP_FOR_DETACH(select_idle_routine)
#endif
#ifndef CAN_WRAP_devmem_is_allowed
#   define CAN_WRAP_devmem_is_allowed 0
#endif
DETACH(devmem_is_allowed)
#ifndef CAN_WRAP_dev_uc_add_excl
#   define CAN_WRAP_dev_uc_add_excl 1
#endif
#if CAN_WRAP_dev_uc_add_excl
    WRAP_FOR_DETACH(dev_uc_add_excl)
#endif
#ifndef CAN_WRAP_crypto_shash_digest
#   define CAN_WRAP_crypto_shash_digest 1
#endif
#if CAN_WRAP_crypto_shash_digest
    WRAP_FOR_DETACH(crypto_shash_digest)
#endif
#ifndef CAN_WRAP_acpi_allocate
#   define CAN_WRAP_acpi_allocate 0
#endif
DETACH(acpi_allocate)
#ifndef CAN_WRAP_kclist_add
#   define CAN_WRAP_kclist_add 1
#endif
#if CAN_WRAP_kclist_add
    WRAP_FOR_DETACH(kclist_add)
#endif
#ifndef CAN_WRAP_pci_store_saved_state
#   define CAN_WRAP_pci_store_saved_state 1
#endif
#if CAN_WRAP_pci_store_saved_state
    WRAP_FOR_DETACH(pci_store_saved_state)
#endif
#ifndef CAN_WRAP_can_nice
#   define CAN_WRAP_can_nice 1
#endif
#if CAN_WRAP_can_nice
    WRAP_FOR_DETACH(can_nice)
#endif
#ifndef CAN_WRAP_dmam_alloc_coherent
#   define CAN_WRAP_dmam_alloc_coherent 1
#endif
#if CAN_WRAP_dmam_alloc_coherent
    WRAP_FOR_DETACH(dmam_alloc_coherent)
#endif
#ifndef CAN_WRAP_mempool_alloc_slab
#   define CAN_WRAP_mempool_alloc_slab 0
#endif
DETACH(mempool_alloc_slab)
#ifndef CAN_WRAP_locks_copy_lock
#   define CAN_WRAP_locks_copy_lock 1
#endif
#if CAN_WRAP_locks_copy_lock
    WRAP_FOR_DETACH(locks_copy_lock)
#endif
#ifndef CAN_WRAP_device_unregister
#   define CAN_WRAP_device_unregister 1
#endif
#if CAN_WRAP_device_unregister
    WRAP_FOR_DETACH(device_unregister)
#endif
#ifndef CAN_WRAP_security_task_prctl
#   define CAN_WRAP_security_task_prctl 0
#endif
DETACH(security_task_prctl)
#ifndef CAN_WRAP__raw_write_unlock
#   define CAN_WRAP__raw_write_unlock 1
#endif
#if CAN_WRAP__raw_write_unlock
    WRAP_FOR_DETACH(_raw_write_unlock)
#endif
#ifndef CAN_WRAP_add_to_swap_cache
#   define CAN_WRAP_add_to_swap_cache 1
#endif
#if CAN_WRAP_add_to_swap_cache
    WRAP_FOR_DETACH(add_to_swap_cache)
#endif
#ifndef CAN_WRAP_memcpy_fromiovec
#   define CAN_WRAP_memcpy_fromiovec 1
#endif
#if CAN_WRAP_memcpy_fromiovec
    WRAP_FOR_DETACH(memcpy_fromiovec)
#endif
#ifndef CAN_WRAP_pci_setup_cardbus
#   define CAN_WRAP_pci_setup_cardbus 1
#endif
#if CAN_WRAP_pci_setup_cardbus
    WRAP_FOR_DETACH(pci_setup_cardbus)
#endif
#ifndef CAN_WRAP_nd_jump_link
#   define CAN_WRAP_nd_jump_link 1
#endif
#if CAN_WRAP_nd_jump_link
    WRAP_FOR_DETACH(nd_jump_link)
#endif
#ifndef CAN_WRAP_devm_ioport_unmap
#   define CAN_WRAP_devm_ioport_unmap 1
#endif
#if CAN_WRAP_devm_ioport_unmap
    WRAP_FOR_DETACH(devm_ioport_unmap)
#endif
#ifndef CAN_WRAP_compat_sys_setrlimit
#   define CAN_WRAP_compat_sys_setrlimit 1
#endif
#if CAN_WRAP_compat_sys_setrlimit
    WRAP_FOR_DETACH(compat_sys_setrlimit)
#endif
#ifndef CAN_WRAP_try_module_get
#   define CAN_WRAP_try_module_get 1
#endif
#if CAN_WRAP_try_module_get
    WRAP_FOR_DETACH(try_module_get)
#endif
#ifndef CAN_WRAP_security_task_getsecid
#   define CAN_WRAP_security_task_getsecid 1
#endif
#if CAN_WRAP_security_task_getsecid
    WRAP_FOR_DETACH(security_task_getsecid)
#endif
#ifndef CAN_WRAP_security_sem_semop
#   define CAN_WRAP_security_sem_semop 1
#endif
#if CAN_WRAP_security_sem_semop
    WRAP_FOR_DETACH(security_sem_semop)
#endif
#ifndef CAN_WRAP_pci_pme_wakeup_bus
#   define CAN_WRAP_pci_pme_wakeup_bus 1
#endif
#if CAN_WRAP_pci_pme_wakeup_bus
    WRAP_FOR_DETACH(pci_pme_wakeup_bus)
#endif
#ifndef CAN_WRAP_blk_queue_max_hw_sectors
#   define CAN_WRAP_blk_queue_max_hw_sectors 1
#endif
#if CAN_WRAP_blk_queue_max_hw_sectors
    WRAP_FOR_DETACH(blk_queue_max_hw_sectors)
#endif
#ifndef CAN_WRAP_dev_add_pack
#   define CAN_WRAP_dev_add_pack 1
#endif
#if CAN_WRAP_dev_add_pack
    WRAP_FOR_DETACH(dev_add_pack)
#endif
#ifndef CAN_WRAP_blk_queue_rq_timed_out
#   define CAN_WRAP_blk_queue_rq_timed_out 1
#endif
#if CAN_WRAP_blk_queue_rq_timed_out
    WRAP_FOR_DETACH(blk_queue_rq_timed_out)
#endif
#ifndef CAN_WRAP_nsec_to_clock_t
#   define CAN_WRAP_nsec_to_clock_t 0
#endif
DETACH(nsec_to_clock_t)
#ifndef CAN_WRAP_generic_fh_to_dentry
#   define CAN_WRAP_generic_fh_to_dentry 1
#endif
#if CAN_WRAP_generic_fh_to_dentry
    WRAP_FOR_DETACH(generic_fh_to_dentry)
#endif
#ifndef CAN_WRAP_pvclock_clocksource_read
#   define CAN_WRAP_pvclock_clocksource_read 1
#endif
#if CAN_WRAP_pvclock_clocksource_read
    WRAP_FOR_DETACH(pvclock_clocksource_read)
#endif
#ifndef CAN_WRAP_ntp_tick_length
#   define CAN_WRAP_ntp_tick_length 0
#endif
DETACH(ntp_tick_length)
#ifndef CAN_WRAP___dev_pm_qos_read_value
#   define CAN_WRAP___dev_pm_qos_read_value 1
#endif
#if CAN_WRAP___dev_pm_qos_read_value
#   ifdef DETACH_ADDR___dev_pm_qos_read_value
        WRAP_FOR_DETACH(__dev_pm_qos_read_value)
#   else
        TYPED_DETACH(__dev_pm_qos_read_value)
#   endif
#endif
#ifndef CAN_WRAP_acpi_enable_subsystem
#   define CAN_WRAP_acpi_enable_subsystem 0
#endif
DETACH(acpi_enable_subsystem)
#ifndef CAN_WRAP___skb_checksum_complete
#   define CAN_WRAP___skb_checksum_complete 1
#endif
#if CAN_WRAP___skb_checksum_complete
#   ifdef DETACH_ADDR___skb_checksum_complete
        WRAP_FOR_DETACH(__skb_checksum_complete)
#   else
        TYPED_DETACH(__skb_checksum_complete)
#   endif
#endif
#ifndef CAN_WRAP_skb_recv_datagram
#   define CAN_WRAP_skb_recv_datagram 1
#endif
#if CAN_WRAP_skb_recv_datagram
    WRAP_FOR_DETACH(skb_recv_datagram)
#endif
#ifndef CAN_WRAP_set_pages_array_uc
#   define CAN_WRAP_set_pages_array_uc 0
#endif
DETACH(set_pages_array_uc)
#ifndef CAN_WRAP_security_inet_csk_clone
#   define CAN_WRAP_security_inet_csk_clone 1
#endif
#if CAN_WRAP_security_inet_csk_clone
    WRAP_FOR_DETACH(security_inet_csk_clone)
#endif
#ifndef CAN_WRAP_acpi_error
#   define CAN_WRAP_acpi_error 0
#endif
DETACH(acpi_error)
#ifndef CAN_WRAP_handle_bad_irq
#   define CAN_WRAP_handle_bad_irq 1
#endif
#if CAN_WRAP_handle_bad_irq
    WRAP_FOR_DETACH(handle_bad_irq)
#endif
#ifndef CAN_WRAP_pcibios_fixup_bus
#   define CAN_WRAP_pcibios_fixup_bus 1
#endif
#if CAN_WRAP_pcibios_fixup_bus
    WRAP_FOR_DETACH(pcibios_fixup_bus)
#endif
#ifndef CAN_WRAP_security_tun_dev_create
#   define CAN_WRAP_security_tun_dev_create 0
#endif
DETACH(security_tun_dev_create)
#ifndef CAN_WRAP_timespec_trunc
#   define CAN_WRAP_timespec_trunc 1
#endif
#if CAN_WRAP_timespec_trunc
    WRAP_FOR_DETACH(timespec_trunc)
#endif
#ifndef CAN_WRAP_dquot_alloc
#   define CAN_WRAP_dquot_alloc 1
#endif
#if CAN_WRAP_dquot_alloc
    WRAP_FOR_DETACH(dquot_alloc)
#endif
#ifndef CAN_WRAP_dm_table_get_mode
#   define CAN_WRAP_dm_table_get_mode 1
#endif
#if CAN_WRAP_dm_table_get_mode
    WRAP_FOR_DETACH(dm_table_get_mode)
#endif
#ifndef CAN_WRAP_pci_dev_put
#   define CAN_WRAP_pci_dev_put 1
#endif
#if CAN_WRAP_pci_dev_put
    WRAP_FOR_DETACH(pci_dev_put)
#endif
#ifndef CAN_WRAP_cgroup_next_descendant_pre
#   define CAN_WRAP_cgroup_next_descendant_pre 1
#endif
#if CAN_WRAP_cgroup_next_descendant_pre
    WRAP_FOR_DETACH(cgroup_next_descendant_pre)
#endif
#ifndef CAN_WRAP_usecs_to_jiffies
#   define CAN_WRAP_usecs_to_jiffies 0
#endif
DETACH(usecs_to_jiffies)
#ifndef CAN_WRAP_destroy_params
#   define CAN_WRAP_destroy_params 1
#endif
#if CAN_WRAP_destroy_params
    WRAP_FOR_DETACH(destroy_params)
#endif
#ifndef CAN_WRAP_simple_attr_open
#   define CAN_WRAP_simple_attr_open 1
#endif
#if CAN_WRAP_simple_attr_open
    WRAP_FOR_DETACH(simple_attr_open)
#endif
#ifndef CAN_WRAP_emergency_sync
#   define CAN_WRAP_emergency_sync 0
#endif
DETACH(emergency_sync)
#ifndef CAN_WRAP_acpi_os_purge_cache
#   define CAN_WRAP_acpi_os_purge_cache 1
#endif
#if CAN_WRAP_acpi_os_purge_cache
    WRAP_FOR_DETACH(acpi_os_purge_cache)
#endif
#ifndef CAN_WRAP_clear_local_APIC
#   define CAN_WRAP_clear_local_APIC 0
#endif
DETACH(clear_local_APIC)
#ifndef CAN_WRAP_pci_set_power_state
#   define CAN_WRAP_pci_set_power_state 1
#endif
#if CAN_WRAP_pci_set_power_state
    WRAP_FOR_DETACH(pci_set_power_state)
#endif
#ifndef CAN_WRAP_sock_unregister
#   define CAN_WRAP_sock_unregister 0
#endif
DETACH(sock_unregister)
#ifndef CAN_WRAP_move_huge_pmd
#   define CAN_WRAP_move_huge_pmd 1
#endif
#if CAN_WRAP_move_huge_pmd
    WRAP_FOR_DETACH(move_huge_pmd)
#endif
#ifndef CAN_WRAP_dev_pm_qos_expose_flags
#   define CAN_WRAP_dev_pm_qos_expose_flags 1
#endif
#if CAN_WRAP_dev_pm_qos_expose_flags
    WRAP_FOR_DETACH(dev_pm_qos_expose_flags)
#endif
#ifndef CAN_WRAP_register_mem_sect_under_node
#   define CAN_WRAP_register_mem_sect_under_node 1
#endif
#if CAN_WRAP_register_mem_sect_under_node
    WRAP_FOR_DETACH(register_mem_sect_under_node)
#endif
#ifndef CAN_WRAP_css_get_next
#   define CAN_WRAP_css_get_next 1
#endif
#if CAN_WRAP_css_get_next
    WRAP_FOR_DETACH(css_get_next)
#endif
#ifndef CAN_WRAP___tasklet_schedule
#   define CAN_WRAP___tasklet_schedule 1
#endif
#if CAN_WRAP___tasklet_schedule
#   ifdef DETACH_ADDR___tasklet_schedule
        WRAP_FOR_DETACH(__tasklet_schedule)
#   else
        TYPED_DETACH(__tasklet_schedule)
#   endif
#endif
#ifndef CAN_WRAP_free_irq
#   define CAN_WRAP_free_irq 0
#endif
DETACH(free_irq)
#ifndef CAN_WRAP_jbd2_journal_check_available_features
#   define CAN_WRAP_jbd2_journal_check_available_features 1
#endif
#if CAN_WRAP_jbd2_journal_check_available_features
    WRAP_FOR_DETACH(jbd2_journal_check_available_features)
#endif
#ifndef CAN_WRAP_compat_sys_preadv
#   define CAN_WRAP_compat_sys_preadv 1
#endif
#if CAN_WRAP_compat_sys_preadv
    WRAP_FOR_DETACH(compat_sys_preadv)
#endif
#ifndef CAN_WRAP_acpi_get_table_header
#   define CAN_WRAP_acpi_get_table_header 1
#endif
#if CAN_WRAP_acpi_get_table_header
    WRAP_FOR_DETACH(acpi_get_table_header)
#endif
#ifndef CAN_WRAP_dquot_initialize
#   define CAN_WRAP_dquot_initialize 1
#endif
#if CAN_WRAP_dquot_initialize
    WRAP_FOR_DETACH(dquot_initialize)
#endif
#ifndef CAN_WRAP_rtnl_unicast
#   define CAN_WRAP_rtnl_unicast 1
#endif
#if CAN_WRAP_rtnl_unicast
    WRAP_FOR_DETACH(rtnl_unicast)
#endif
#ifndef CAN_WRAP_register_acpi_notifier
#   define CAN_WRAP_register_acpi_notifier 1
#endif
#if CAN_WRAP_register_acpi_notifier
    WRAP_FOR_DETACH(register_acpi_notifier)
#endif
#ifndef CAN_WRAP_pci_assign_unassigned_bridge_resources
#   define CAN_WRAP_pci_assign_unassigned_bridge_resources 1
#endif
#if CAN_WRAP_pci_assign_unassigned_bridge_resources
    WRAP_FOR_DETACH(pci_assign_unassigned_bridge_resources)
#endif
#ifndef CAN_WRAP_reboot_interrupt
#   define CAN_WRAP_reboot_interrupt 0
#endif
DETACH(reboot_interrupt)
#ifndef CAN_WRAP_add_uevent_var
#   define CAN_WRAP_add_uevent_var 0
#endif
DETACH(add_uevent_var)
#ifndef CAN_WRAP_netlink_unicast
#   define CAN_WRAP_netlink_unicast 1
#endif
#if CAN_WRAP_netlink_unicast
    WRAP_FOR_DETACH(netlink_unicast)
#endif
#ifndef CAN_WRAP_default_check_phys_apicid_present
#   define CAN_WRAP_default_check_phys_apicid_present 0
#endif
DETACH(default_check_phys_apicid_present)
#ifndef CAN_WRAP_ata_sff_lost_interrupt
#   define CAN_WRAP_ata_sff_lost_interrupt 1
#endif
#if CAN_WRAP_ata_sff_lost_interrupt
    WRAP_FOR_DETACH(ata_sff_lost_interrupt)
#endif
#ifndef CAN_WRAP_elv_add_request
#   define CAN_WRAP_elv_add_request 1
#endif
#if CAN_WRAP_elv_add_request
    WRAP_FOR_DETACH(elv_add_request)
#endif
#ifndef CAN_WRAP_wbinvd_on_cpu
#   define CAN_WRAP_wbinvd_on_cpu 0
#endif
DETACH(wbinvd_on_cpu)
#ifndef CAN_WRAP_generic_file_buffered_write
#   define CAN_WRAP_generic_file_buffered_write 1
#endif
#if CAN_WRAP_generic_file_buffered_write
    WRAP_FOR_DETACH(generic_file_buffered_write)
#endif
#ifndef CAN_WRAP_ata_eh_thaw_port
#   define CAN_WRAP_ata_eh_thaw_port 1
#endif
#if CAN_WRAP_ata_eh_thaw_port
    WRAP_FOR_DETACH(ata_eh_thaw_port)
#endif
#ifndef CAN_WRAP_kernel_bind
#   define CAN_WRAP_kernel_bind 1
#endif
#if CAN_WRAP_kernel_bind
    WRAP_FOR_DETACH(kernel_bind)
#endif
#ifndef CAN_WRAP_unlock_rename
#   define CAN_WRAP_unlock_rename 1
#endif
#if CAN_WRAP_unlock_rename
    WRAP_FOR_DETACH(unlock_rename)
#endif
#ifndef CAN_WRAP_out_of_line_wait_on_bit_lock
#   define CAN_WRAP_out_of_line_wait_on_bit_lock 1
#endif
#if CAN_WRAP_out_of_line_wait_on_bit_lock
    WRAP_FOR_DETACH(out_of_line_wait_on_bit_lock)
#endif
#ifndef CAN_WRAP_preempt_notifier_unregister
#   define CAN_WRAP_preempt_notifier_unregister 1
#endif
#if CAN_WRAP_preempt_notifier_unregister
    WRAP_FOR_DETACH(preempt_notifier_unregister)
#endif
#ifndef CAN_WRAP_inet_csk_addr2sockaddr
#   define CAN_WRAP_inet_csk_addr2sockaddr 1
#endif
#if CAN_WRAP_inet_csk_addr2sockaddr
    WRAP_FOR_DETACH(inet_csk_addr2sockaddr)
#endif
#ifndef CAN_WRAP_msleep_interruptible
#   define CAN_WRAP_msleep_interruptible 0
#endif
DETACH(msleep_interruptible)
#ifndef CAN_WRAP___dev_remove_pack
#   define CAN_WRAP___dev_remove_pack 1
#endif
#if CAN_WRAP___dev_remove_pack
#   ifdef DETACH_ADDR___dev_remove_pack
        WRAP_FOR_DETACH(__dev_remove_pack)
#   else
        TYPED_DETACH(__dev_remove_pack)
#   endif
#endif
#ifndef CAN_WRAP_acpi_remove_interface
#   define CAN_WRAP_acpi_remove_interface 0
#endif
DETACH(acpi_remove_interface)
#ifndef CAN_WRAP_jbd2_journal_skip_recovery
#   define CAN_WRAP_jbd2_journal_skip_recovery 1
#endif
#if CAN_WRAP_jbd2_journal_skip_recovery
    WRAP_FOR_DETACH(jbd2_journal_skip_recovery)
#endif
#ifndef CAN_WRAP_timespec_add_safe
#   define CAN_WRAP_timespec_add_safe 1
#endif
#if CAN_WRAP_timespec_add_safe
    WRAP_FOR_DETACH(timespec_add_safe)
#endif
#ifndef CAN_WRAP_nr_uninterruptible
#   define CAN_WRAP_nr_uninterruptible 0
#endif
DETACH(nr_uninterruptible)
#ifndef CAN_WRAP_pci_enable_device
#   define CAN_WRAP_pci_enable_device 1
#endif
#if CAN_WRAP_pci_enable_device
    WRAP_FOR_DETACH(pci_enable_device)
#endif
#ifndef CAN_WRAP_files_init
#   define CAN_WRAP_files_init 0
#endif
DETACH(files_init)
#ifndef CAN_WRAP_security_inode_follow_link
#   define CAN_WRAP_security_inode_follow_link 1
#endif
#if CAN_WRAP_security_inode_follow_link
    WRAP_FOR_DETACH(security_inode_follow_link)
#endif
#ifndef CAN_WRAP_skb_copy_expand
#   define CAN_WRAP_skb_copy_expand 1
#endif
#if CAN_WRAP_skb_copy_expand
    WRAP_FOR_DETACH(skb_copy_expand)
#endif
#ifndef CAN_WRAP_ata_pci_bmdma_prepare_host
#   define CAN_WRAP_ata_pci_bmdma_prepare_host 1
#endif
#if CAN_WRAP_ata_pci_bmdma_prepare_host
    WRAP_FOR_DETACH(ata_pci_bmdma_prepare_host)
#endif
#ifndef CAN_WRAP_mnt_set_expiry
#   define CAN_WRAP_mnt_set_expiry 1
#endif
#if CAN_WRAP_mnt_set_expiry
    WRAP_FOR_DETACH(mnt_set_expiry)
#endif
#ifndef CAN_WRAP_param_get_ushort
#   define CAN_WRAP_param_get_ushort 1
#endif
#if CAN_WRAP_param_get_ushort
    WRAP_FOR_DETACH(param_get_ushort)
#endif
#ifndef CAN_WRAP_show_mem
#   define CAN_WRAP_show_mem 0
#endif
DETACH(show_mem)
#ifndef CAN_WRAP___percpu_init_rwsem
#   define CAN_WRAP___percpu_init_rwsem 1
#endif
#if CAN_WRAP___percpu_init_rwsem
#   ifdef DETACH_ADDR___percpu_init_rwsem
        WRAP_FOR_DETACH(__percpu_init_rwsem)
#   else
        TYPED_DETACH(__percpu_init_rwsem)
#   endif
#endif
#ifndef CAN_WRAP_pci_bus_read_config_byte
#   define CAN_WRAP_pci_bus_read_config_byte 1
#endif
#if CAN_WRAP_pci_bus_read_config_byte
    WRAP_FOR_DETACH(pci_bus_read_config_byte)
#endif
#ifndef CAN_WRAP_swap_writepage
#   define CAN_WRAP_swap_writepage 1
#endif
#if CAN_WRAP_swap_writepage
    WRAP_FOR_DETACH(swap_writepage)
#endif
#ifndef CAN_WRAP_bioset_free
#   define CAN_WRAP_bioset_free 1
#endif
#if CAN_WRAP_bioset_free
    WRAP_FOR_DETACH(bioset_free)
#endif
#ifndef CAN_WRAP___jbd2_journal_file_buffer
#   define CAN_WRAP___jbd2_journal_file_buffer 1
#endif
#if CAN_WRAP___jbd2_journal_file_buffer
#   ifdef DETACH_ADDR___jbd2_journal_file_buffer
        WRAP_FOR_DETACH(__jbd2_journal_file_buffer)
#   else
        TYPED_DETACH(__jbd2_journal_file_buffer)
#   endif
#endif
#ifndef CAN_WRAP_security_socket_listen
#   define CAN_WRAP_security_socket_listen 1
#endif
#if CAN_WRAP_security_socket_listen
    WRAP_FOR_DETACH(security_socket_listen)
#endif
#ifndef CAN_WRAP_device_reprobe
#   define CAN_WRAP_device_reprobe 1
#endif
#if CAN_WRAP_device_reprobe
    WRAP_FOR_DETACH(device_reprobe)
#endif
#ifndef CAN_WRAP_device_del
#   define CAN_WRAP_device_del 1
#endif
#if CAN_WRAP_device_del
    WRAP_FOR_DETACH(device_del)
#endif
#ifndef CAN_WRAP_free_uid
#   define CAN_WRAP_free_uid 1
#endif
#if CAN_WRAP_free_uid
    WRAP_FOR_DETACH(free_uid)
#endif
#ifndef CAN_WRAP_disk_expand_part_tbl
#   define CAN_WRAP_disk_expand_part_tbl 1
#endif
#if CAN_WRAP_disk_expand_part_tbl
    WRAP_FOR_DETACH(disk_expand_part_tbl)
#endif
#ifndef CAN_WRAP_dev_change_name
#   define CAN_WRAP_dev_change_name 1
#endif
#if CAN_WRAP_dev_change_name
    WRAP_FOR_DETACH(dev_change_name)
#endif
#ifndef CAN_WRAP_irq_gc_ack_clr_bit
#   define CAN_WRAP_irq_gc_ack_clr_bit 1
#endif
#if CAN_WRAP_irq_gc_ack_clr_bit
    WRAP_FOR_DETACH(irq_gc_ack_clr_bit)
#endif
#ifndef CAN_WRAP_write_one_page
#   define CAN_WRAP_write_one_page 1
#endif
#if CAN_WRAP_write_one_page
    WRAP_FOR_DETACH(write_one_page)
#endif
#ifndef CAN_WRAP_device_pm_unlock
#   define CAN_WRAP_device_pm_unlock 0
#endif
DETACH(device_pm_unlock)
#ifndef CAN_WRAP_invalidate_interrupt29
#   define CAN_WRAP_invalidate_interrupt29 0
#endif
DETACH(invalidate_interrupt29)
#ifndef CAN_WRAP_invalidate_interrupt28
#   define CAN_WRAP_invalidate_interrupt28 0
#endif
DETACH(invalidate_interrupt28)
#ifndef CAN_WRAP_kill_pid
#   define CAN_WRAP_kill_pid 1
#endif
#if CAN_WRAP_kill_pid
    WRAP_FOR_DETACH(kill_pid)
#endif
#ifndef CAN_WRAP_schedule_work_on
#   define CAN_WRAP_schedule_work_on 1
#endif
#if CAN_WRAP_schedule_work_on
    WRAP_FOR_DETACH(schedule_work_on)
#endif
#ifndef CAN_WRAP_invalidate_interrupt23
#   define CAN_WRAP_invalidate_interrupt23 0
#endif
DETACH(invalidate_interrupt23)
#ifndef CAN_WRAP_invalidate_interrupt22
#   define CAN_WRAP_invalidate_interrupt22 0
#endif
DETACH(invalidate_interrupt22)
#ifndef CAN_WRAP_invalidate_interrupt21
#   define CAN_WRAP_invalidate_interrupt21 0
#endif
DETACH(invalidate_interrupt21)
#ifndef CAN_WRAP_invalidate_interrupt20
#   define CAN_WRAP_invalidate_interrupt20 0
#endif
DETACH(invalidate_interrupt20)
#ifndef CAN_WRAP_invalidate_interrupt27
#   define CAN_WRAP_invalidate_interrupt27 0
#endif
DETACH(invalidate_interrupt27)
#ifndef CAN_WRAP_invalidate_interrupt26
#   define CAN_WRAP_invalidate_interrupt26 0
#endif
DETACH(invalidate_interrupt26)
#ifndef CAN_WRAP_invalidate_interrupt25
#   define CAN_WRAP_invalidate_interrupt25 0
#endif
DETACH(invalidate_interrupt25)
#ifndef CAN_WRAP_invalidate_interrupt24
#   define CAN_WRAP_invalidate_interrupt24 0
#endif
DETACH(invalidate_interrupt24)
#ifndef CAN_WRAP_ata_sff_dev_select
#   define CAN_WRAP_ata_sff_dev_select 1
#endif
#if CAN_WRAP_ata_sff_dev_select
    WRAP_FOR_DETACH(ata_sff_dev_select)
#endif
#ifndef CAN_WRAP_raise_softirq
#   define CAN_WRAP_raise_softirq 0
#endif
DETACH(raise_softirq)
#ifndef CAN_WRAP_inet_twdr_twkill_work
#   define CAN_WRAP_inet_twdr_twkill_work 1
#endif
#if CAN_WRAP_inet_twdr_twkill_work
    WRAP_FOR_DETACH(inet_twdr_twkill_work)
#endif
#ifndef CAN_WRAP_register_lapic_address
#   define CAN_WRAP_register_lapic_address 0
#endif
DETACH(register_lapic_address)
#ifndef CAN_WRAP_split_huge_page
#   define CAN_WRAP_split_huge_page 1
#endif
#if CAN_WRAP_split_huge_page
    WRAP_FOR_DETACH(split_huge_page)
#endif
#ifndef CAN_WRAP_pci_mmap_page_range
#   define CAN_WRAP_pci_mmap_page_range 1
#endif
#if CAN_WRAP_pci_mmap_page_range
    WRAP_FOR_DETACH(pci_mmap_page_range)
#endif
#ifndef CAN_WRAP_ktime_get_real
#   define CAN_WRAP_ktime_get_real 0
#endif
DETACH(ktime_get_real)
#ifndef CAN_WRAP_acpi_nvs_nosave
#   define CAN_WRAP_acpi_nvs_nosave 0
#endif
DETACH(acpi_nvs_nosave)
#ifndef CAN_WRAP_ata_sff_irq_on
#   define CAN_WRAP_ata_sff_irq_on 1
#endif
#if CAN_WRAP_ata_sff_irq_on
    WRAP_FOR_DETACH(ata_sff_irq_on)
#endif
#ifndef CAN_WRAP_has_ns_capability
#   define CAN_WRAP_has_ns_capability 1
#endif
#if CAN_WRAP_has_ns_capability
    WRAP_FOR_DETACH(has_ns_capability)
#endif
#ifndef CAN_WRAP_iov_iter_copy_from_user
#   define CAN_WRAP_iov_iter_copy_from_user 1
#endif
#if CAN_WRAP_iov_iter_copy_from_user
    WRAP_FOR_DETACH(iov_iter_copy_from_user)
#endif
#ifndef CAN_WRAP_skb_pad
#   define CAN_WRAP_skb_pad 1
#endif
#if CAN_WRAP_skb_pad
    WRAP_FOR_DETACH(skb_pad)
#endif
#ifndef CAN_WRAP_dma_memcpy_to_iovec
#   define CAN_WRAP_dma_memcpy_to_iovec 1
#endif
#if CAN_WRAP_dma_memcpy_to_iovec
    WRAP_FOR_DETACH(dma_memcpy_to_iovec)
#endif
#ifndef CAN_WRAP_acpi_numa_slit_init
#   define CAN_WRAP_acpi_numa_slit_init 1
#endif
#if CAN_WRAP_acpi_numa_slit_init
    WRAP_FOR_DETACH(acpi_numa_slit_init)
#endif
#ifndef CAN_WRAP_is_subdir
#   define CAN_WRAP_is_subdir 1
#endif
#if CAN_WRAP_is_subdir
    WRAP_FOR_DETACH(is_subdir)
#endif
#ifndef CAN_WRAP_input_get_keycode
#   define CAN_WRAP_input_get_keycode 1
#endif
#if CAN_WRAP_input_get_keycode
    WRAP_FOR_DETACH(input_get_keycode)
#endif
#ifndef CAN_WRAP_cgroup_unlock
#   define CAN_WRAP_cgroup_unlock 0
#endif
DETACH(cgroup_unlock)
#ifndef CAN_WRAP_do_mremap
#   define CAN_WRAP_do_mremap 0
#endif
DETACH(do_mremap)
#ifndef CAN_WRAP___suspend_report_result
#   define CAN_WRAP___suspend_report_result 0
#endif
DETACH(__suspend_report_result)
#ifndef CAN_WRAP_sysfs_create_link
#   define CAN_WRAP_sysfs_create_link 1
#endif
#if CAN_WRAP_sysfs_create_link
    WRAP_FOR_DETACH(sysfs_create_link)
#endif
#ifndef CAN_WRAP_jbd2_journal_unlock_updates
#   define CAN_WRAP_jbd2_journal_unlock_updates 1
#endif
#if CAN_WRAP_jbd2_journal_unlock_updates
    WRAP_FOR_DETACH(jbd2_journal_unlock_updates)
#endif
#ifndef CAN_WRAP_netlink_set_err
#   define CAN_WRAP_netlink_set_err 1
#endif
#if CAN_WRAP_netlink_set_err
    WRAP_FOR_DETACH(netlink_set_err)
#endif
#ifndef CAN_WRAP_ata_host_start
#   define CAN_WRAP_ata_host_start 1
#endif
#if CAN_WRAP_ata_host_start
    WRAP_FOR_DETACH(ata_host_start)
#endif
#ifndef CAN_WRAP_vfs_readlink
#   define CAN_WRAP_vfs_readlink 1
#endif
#if CAN_WRAP_vfs_readlink
    WRAP_FOR_DETACH(vfs_readlink)
#endif
#ifndef CAN_WRAP_dev_getbyhwaddr_rcu
#   define CAN_WRAP_dev_getbyhwaddr_rcu 1
#endif
#if CAN_WRAP_dev_getbyhwaddr_rcu
    WRAP_FOR_DETACH(dev_getbyhwaddr_rcu)
#endif
#ifndef CAN_WRAP_tick_get_broadcast_device
#   define CAN_WRAP_tick_get_broadcast_device 1
#endif
#if CAN_WRAP_tick_get_broadcast_device
    WRAP_FOR_DETACH(tick_get_broadcast_device)
#endif
#ifndef CAN_WRAP_nsproxy_cache_init
#   define CAN_WRAP_nsproxy_cache_init 0
#endif
DETACH(nsproxy_cache_init)
#ifndef CAN_WRAP_dev_shutdown
#   define CAN_WRAP_dev_shutdown 1
#endif
#if CAN_WRAP_dev_shutdown
    WRAP_FOR_DETACH(dev_shutdown)
#endif
#ifndef CAN_WRAP_native_setup_msi_irqs
#   define CAN_WRAP_native_setup_msi_irqs 1
#endif
#if CAN_WRAP_native_setup_msi_irqs
    WRAP_FOR_DETACH(native_setup_msi_irqs)
#endif
#ifndef CAN_WRAP_pcibios_assign_all_busses
#   define CAN_WRAP_pcibios_assign_all_busses 0
#endif
DETACH(pcibios_assign_all_busses)
#ifndef CAN_WRAP_ip_compute_csum
#   define CAN_WRAP_ip_compute_csum 0
#endif
DETACH(ip_compute_csum)
#ifndef CAN_WRAP_parameq
#   define CAN_WRAP_parameq 0
#endif
DETACH(parameq)
#ifndef CAN_WRAP_should_remove_suid
#   define CAN_WRAP_should_remove_suid 1
#endif
#if CAN_WRAP_should_remove_suid
    WRAP_FOR_DETACH(should_remove_suid)
#endif
#ifndef CAN_WRAP_security_msg_queue_msgctl
#   define CAN_WRAP_security_msg_queue_msgctl 1
#endif
#if CAN_WRAP_security_msg_queue_msgctl
    WRAP_FOR_DETACH(security_msg_queue_msgctl)
#endif
#ifndef CAN_WRAP_llist_del_first
#   define CAN_WRAP_llist_del_first 1
#endif
#if CAN_WRAP_llist_del_first
    WRAP_FOR_DETACH(llist_del_first)
#endif
#ifndef CAN_WRAP_dcbnl_ieee_notify
#   define CAN_WRAP_dcbnl_ieee_notify 1
#endif
#if CAN_WRAP_dcbnl_ieee_notify
    WRAP_FOR_DETACH(dcbnl_ieee_notify)
#endif
#ifndef CAN_WRAP_strnlen
#   define CAN_WRAP_strnlen 0
#endif
DETACH(strnlen)
#ifndef CAN_WRAP_dev_kfree_skb_irq
#   define CAN_WRAP_dev_kfree_skb_irq 1
#endif
#if CAN_WRAP_dev_kfree_skb_irq
    WRAP_FOR_DETACH(dev_kfree_skb_irq)
#endif
#ifndef CAN_WRAP_pxm_to_node
#   define CAN_WRAP_pxm_to_node 0
#endif
DETACH(pxm_to_node)
#ifndef CAN_WRAP_lock_vector_lock
#   define CAN_WRAP_lock_vector_lock 0
#endif
DETACH(lock_vector_lock)
#ifndef CAN_WRAP_acpi_os_install_interrupt_handler
#   define CAN_WRAP_acpi_os_install_interrupt_handler 1
#endif
#if CAN_WRAP_acpi_os_install_interrupt_handler
    WRAP_FOR_DETACH(acpi_os_install_interrupt_handler)
#endif
#ifndef CAN_WRAP_security_file_receive
#   define CAN_WRAP_security_file_receive 1
#endif
#if CAN_WRAP_security_file_receive
    WRAP_FOR_DETACH(security_file_receive)
#endif
#ifndef CAN_WRAP___acpi_map_table
#   define CAN_WRAP___acpi_map_table 0
#endif
DETACH(__acpi_map_table)
#ifndef CAN_WRAP_acpi_dev_resource_io
#   define CAN_WRAP_acpi_dev_resource_io 1
#endif
#if CAN_WRAP_acpi_dev_resource_io
    WRAP_FOR_DETACH(acpi_dev_resource_io)
#endif
#ifndef CAN_WRAP_security_kernel_act_as
#   define CAN_WRAP_security_kernel_act_as 1
#endif
#if CAN_WRAP_security_kernel_act_as
    WRAP_FOR_DETACH(security_kernel_act_as)
#endif
#ifndef CAN_WRAP_rcu_batches_completed_bh
#   define CAN_WRAP_rcu_batches_completed_bh 0
#endif
DETACH(rcu_batches_completed_bh)
#ifndef CAN_WRAP_blk_end_request_err
#   define CAN_WRAP_blk_end_request_err 1
#endif
#if CAN_WRAP_blk_end_request_err
    WRAP_FOR_DETACH(blk_end_request_err)
#endif
#ifndef CAN_WRAP_elv_merge
#   define CAN_WRAP_elv_merge 1
#endif
#if CAN_WRAP_elv_merge
    WRAP_FOR_DETACH(elv_merge)
#endif
#ifndef CAN_WRAP_vfs_getxattr_alloc
#   define CAN_WRAP_vfs_getxattr_alloc 1
#endif
#if CAN_WRAP_vfs_getxattr_alloc
    WRAP_FOR_DETACH(vfs_getxattr_alloc)
#endif
#ifndef CAN_WRAP_input_unregister_handler
#   define CAN_WRAP_input_unregister_handler 1
#endif
#if CAN_WRAP_input_unregister_handler
    WRAP_FOR_DETACH(input_unregister_handler)
#endif
#ifndef CAN_WRAP_kernel_sendpage
#   define CAN_WRAP_kernel_sendpage 1
#endif
#if CAN_WRAP_kernel_sendpage
    WRAP_FOR_DETACH(kernel_sendpage)
#endif
#ifndef CAN_WRAP_dm_next_uevent_seq
#   define CAN_WRAP_dm_next_uevent_seq 1
#endif
#if CAN_WRAP_dm_next_uevent_seq
    WRAP_FOR_DETACH(dm_next_uevent_seq)
#endif
#ifndef CAN_WRAP_elv_abort_queue
#   define CAN_WRAP_elv_abort_queue 1
#endif
#if CAN_WRAP_elv_abort_queue
    WRAP_FOR_DETACH(elv_abort_queue)
#endif
#ifndef CAN_WRAP_filemap_fdatawait
#   define CAN_WRAP_filemap_fdatawait 1
#endif
#if CAN_WRAP_filemap_fdatawait
    WRAP_FOR_DETACH(filemap_fdatawait)
#endif
#ifndef CAN_WRAP_dump_page
#   define CAN_WRAP_dump_page 1
#endif
#if CAN_WRAP_dump_page
    WRAP_FOR_DETACH(dump_page)
#endif
#ifndef CAN_WRAP_pcibios_bus_to_resource
#   define CAN_WRAP_pcibios_bus_to_resource 1
#endif
#if CAN_WRAP_pcibios_bus_to_resource
    WRAP_FOR_DETACH(pcibios_bus_to_resource)
#endif
#ifndef CAN_WRAP_native_read_tsc
#   define CAN_WRAP_native_read_tsc 0
#endif
DETACH(native_read_tsc)
#ifndef CAN_WRAP_blk_queue_resize_tags
#   define CAN_WRAP_blk_queue_resize_tags 1
#endif
#if CAN_WRAP_blk_queue_resize_tags
    WRAP_FOR_DETACH(blk_queue_resize_tags)
#endif
#ifndef CAN_WRAP_inet_csk_route_req
#   define CAN_WRAP_inet_csk_route_req 1
#endif
#if CAN_WRAP_inet_csk_route_req
    WRAP_FOR_DETACH(inet_csk_route_req)
#endif
#ifndef CAN_WRAP_native_calibrate_tsc
#   define CAN_WRAP_native_calibrate_tsc 0
#endif
DETACH(native_calibrate_tsc)
#ifndef CAN_WRAP___bforget
#   define CAN_WRAP___bforget 1
#endif
#if CAN_WRAP___bforget
#   ifdef DETACH_ADDR___bforget
        WRAP_FOR_DETACH(__bforget)
#   else
        TYPED_DETACH(__bforget)
#   endif
#endif
#ifndef CAN_WRAP_memblock_find_dma_reserve
#   define CAN_WRAP_memblock_find_dma_reserve 0
#endif
DETACH(memblock_find_dma_reserve)
#ifndef CAN_WRAP_bdi_dirty_limit
#   define CAN_WRAP_bdi_dirty_limit 1
#endif
#if CAN_WRAP_bdi_dirty_limit
    WRAP_FOR_DETACH(bdi_dirty_limit)
#endif
#ifndef CAN_WRAP_sock_kmalloc
#   define CAN_WRAP_sock_kmalloc 1
#endif
#if CAN_WRAP_sock_kmalloc
    WRAP_FOR_DETACH(sock_kmalloc)
#endif
#ifndef CAN_WRAP_synchronize_srcu
#   define CAN_WRAP_synchronize_srcu 1
#endif
#if CAN_WRAP_synchronize_srcu
    WRAP_FOR_DETACH(synchronize_srcu)
#endif
#ifndef CAN_WRAP_ata_xfer_mask2mode
#   define CAN_WRAP_ata_xfer_mask2mode 0
#endif
DETACH(ata_xfer_mask2mode)
#ifndef CAN_WRAP_sched_init_smp
#   define CAN_WRAP_sched_init_smp 0
#endif
DETACH(sched_init_smp)
#ifndef CAN_WRAP_generic_setlease
#   define CAN_WRAP_generic_setlease 1
#endif
#if CAN_WRAP_generic_setlease
    WRAP_FOR_DETACH(generic_setlease)
#endif
#ifndef CAN_WRAP_device_create_bin_file
#   define CAN_WRAP_device_create_bin_file 1
#endif
#if CAN_WRAP_device_create_bin_file
    WRAP_FOR_DETACH(device_create_bin_file)
#endif
#ifndef CAN_WRAP_dev_pm_qos_hide_latency_limit
#   define CAN_WRAP_dev_pm_qos_hide_latency_limit 1
#endif
#if CAN_WRAP_dev_pm_qos_hide_latency_limit
    WRAP_FOR_DETACH(dev_pm_qos_hide_latency_limit)
#endif
#ifndef CAN_WRAP_compat_sys_set_mempolicy
#   define CAN_WRAP_compat_sys_set_mempolicy 0
#endif
DETACH(compat_sys_set_mempolicy)
#ifndef CAN_WRAP_sched_setscheduler_nocheck
#   define CAN_WRAP_sched_setscheduler_nocheck 1
#endif
#if CAN_WRAP_sched_setscheduler_nocheck
    WRAP_FOR_DETACH(sched_setscheduler_nocheck)
#endif
#ifndef CAN_WRAP_nla_memcmp
#   define CAN_WRAP_nla_memcmp 1
#endif
#if CAN_WRAP_nla_memcmp
    WRAP_FOR_DETACH(nla_memcmp)
#endif
#ifndef CAN_WRAP_copy_thread
#   define CAN_WRAP_copy_thread 1
#endif
#if CAN_WRAP_copy_thread
    WRAP_FOR_DETACH(copy_thread)
#endif
#ifndef CAN_WRAP_bdi_lock_two
#   define CAN_WRAP_bdi_lock_two 1
#endif
#if CAN_WRAP_bdi_lock_two
    WRAP_FOR_DETACH(bdi_lock_two)
#endif
#ifndef CAN_WRAP_clear_user
#   define CAN_WRAP_clear_user 0
#endif
DETACH(clear_user)
#ifndef CAN_WRAP_early_quirks
#   define CAN_WRAP_early_quirks 0
#endif
DETACH(early_quirks)
#ifndef CAN_WRAP_proc_symlink
#   define CAN_WRAP_proc_symlink 1
#endif
#if CAN_WRAP_proc_symlink
    WRAP_FOR_DETACH(proc_symlink)
#endif
#ifndef CAN_WRAP_kmem_cache_alloc_trace
#   define CAN_WRAP_kmem_cache_alloc_trace 1
#endif
#if CAN_WRAP_kmem_cache_alloc_trace
    WRAP_FOR_DETACH(kmem_cache_alloc_trace)
#endif
#ifndef CAN_WRAP_queue_work
#   define CAN_WRAP_queue_work 1
#endif
#if CAN_WRAP_queue_work
    WRAP_FOR_DETACH(queue_work)
#endif
#ifndef CAN_WRAP_sysfs_remove_link
#   define CAN_WRAP_sysfs_remove_link 1
#endif
#if CAN_WRAP_sysfs_remove_link
    WRAP_FOR_DETACH(sysfs_remove_link)
#endif
#ifndef CAN_WRAP_normalize_rt_tasks
#   define CAN_WRAP_normalize_rt_tasks 0
#endif
DETACH(normalize_rt_tasks)
#ifndef CAN_WRAP_ilookup5_nowait
#   define CAN_WRAP_ilookup5_nowait 1
#endif
#if CAN_WRAP_ilookup5_nowait
    WRAP_FOR_DETACH(ilookup5_nowait)
#endif
#ifndef CAN_WRAP_swap_type_of
#   define CAN_WRAP_swap_type_of 0
#endif
DETACH(swap_type_of)
#ifndef CAN_WRAP_thread_group_cputime_adjusted
#   define CAN_WRAP_thread_group_cputime_adjusted 1
#endif
#if CAN_WRAP_thread_group_cputime_adjusted
    WRAP_FOR_DETACH(thread_group_cputime_adjusted)
#endif
#ifndef CAN_WRAP_current_user_ns
#   define CAN_WRAP_current_user_ns 1
#endif
#if CAN_WRAP_current_user_ns
    WRAP_FOR_DETACH(current_user_ns)
#endif
#ifndef CAN_WRAP_dst_destroy
#   define CAN_WRAP_dst_destroy 1
#endif
#if CAN_WRAP_dst_destroy
    WRAP_FOR_DETACH(dst_destroy)
#endif
#ifndef CAN_WRAP_default_cpu_mask_to_apicid_and
#   define CAN_WRAP_default_cpu_mask_to_apicid_and 1
#endif
#if CAN_WRAP_default_cpu_mask_to_apicid_and
    WRAP_FOR_DETACH(default_cpu_mask_to_apicid_and)
#endif
#ifndef CAN_WRAP_blk_queue_max_segment_size
#   define CAN_WRAP_blk_queue_max_segment_size 1
#endif
#if CAN_WRAP_blk_queue_max_segment_size
    WRAP_FOR_DETACH(blk_queue_max_segment_size)
#endif
#ifndef CAN_WRAP_security_task_getpgid
#   define CAN_WRAP_security_task_getpgid 1
#endif
#if CAN_WRAP_security_task_getpgid
    WRAP_FOR_DETACH(security_task_getpgid)
#endif
#ifndef CAN_WRAP_dm_get_md
#   define CAN_WRAP_dm_get_md 1
#endif
#if CAN_WRAP_dm_get_md
    WRAP_FOR_DETACH(dm_get_md)
#endif
#ifndef CAN_WRAP___fprop_inc_percpu_max
#   define CAN_WRAP___fprop_inc_percpu_max 1
#endif
#if CAN_WRAP___fprop_inc_percpu_max
#   ifdef DETACH_ADDR___fprop_inc_percpu_max
        WRAP_FOR_DETACH(__fprop_inc_percpu_max)
#   else
        TYPED_DETACH(__fprop_inc_percpu_max)
#   endif
#endif
#ifndef CAN_WRAP_sata_pmp_qc_defer_cmd_switch
#   define CAN_WRAP_sata_pmp_qc_defer_cmd_switch 1
#endif
#if CAN_WRAP_sata_pmp_qc_defer_cmd_switch
    WRAP_FOR_DETACH(sata_pmp_qc_defer_cmd_switch)
#endif
#ifndef CAN_WRAP_io_schedule_timeout
#   define CAN_WRAP_io_schedule_timeout 0
#endif
DETACH(io_schedule_timeout)
#ifndef CAN_WRAP_net_enable_timestamp
#   define CAN_WRAP_net_enable_timestamp 0
#endif
DETACH(net_enable_timestamp)
#ifndef CAN_WRAP_runqueue_is_locked
#   define CAN_WRAP_runqueue_is_locked 0
#endif
DETACH(runqueue_is_locked)
#ifndef CAN_WRAP_kill_pid_info
#   define CAN_WRAP_kill_pid_info 1
#endif
#if CAN_WRAP_kill_pid_info
    WRAP_FOR_DETACH(kill_pid_info)
#endif
#ifndef CAN_WRAP_pgtable_trans_huge_deposit
#   define CAN_WRAP_pgtable_trans_huge_deposit 1
#endif
#if CAN_WRAP_pgtable_trans_huge_deposit
    WRAP_FOR_DETACH(pgtable_trans_huge_deposit)
#endif
#ifndef CAN_WRAP_end_buffer_read_sync
#   define CAN_WRAP_end_buffer_read_sync 1
#endif
#if CAN_WRAP_end_buffer_read_sync
    WRAP_FOR_DETACH(end_buffer_read_sync)
#endif
#ifndef CAN_WRAP_ata_sff_busy_sleep
#   define CAN_WRAP_ata_sff_busy_sleep 1
#endif
#if CAN_WRAP_ata_sff_busy_sleep
    WRAP_FOR_DETACH(ata_sff_busy_sleep)
#endif
#ifndef CAN_WRAP___sk_mem_reclaim
#   define CAN_WRAP___sk_mem_reclaim 1
#endif
#if CAN_WRAP___sk_mem_reclaim
#   ifdef DETACH_ADDR___sk_mem_reclaim
        WRAP_FOR_DETACH(__sk_mem_reclaim)
#   else
        TYPED_DETACH(__sk_mem_reclaim)
#   endif
#endif
#ifndef CAN_WRAP___get_user_bad
#   define CAN_WRAP___get_user_bad 0
#endif
DETACH(__get_user_bad)
#ifndef CAN_WRAP___kernel_text_address
#   define CAN_WRAP___kernel_text_address 0
#endif
DETACH(__kernel_text_address)
#ifndef CAN_WRAP___pci_reset_function_locked
#   define CAN_WRAP___pci_reset_function_locked 1
#endif
#if CAN_WRAP___pci_reset_function_locked
#   ifdef DETACH_ADDR___pci_reset_function_locked
        WRAP_FOR_DETACH(__pci_reset_function_locked)
#   else
        TYPED_DETACH(__pci_reset_function_locked)
#   endif
#endif
#ifndef CAN_WRAP_save_ioapic_entries
#   define CAN_WRAP_save_ioapic_entries 0
#endif
DETACH(save_ioapic_entries)
#ifndef CAN_WRAP_copy_net_ns
#   define CAN_WRAP_copy_net_ns 1
#endif
#if CAN_WRAP_copy_net_ns
    WRAP_FOR_DETACH(copy_net_ns)
#endif
#ifndef CAN_WRAP_verify_iovec
#   define CAN_WRAP_verify_iovec 1
#endif
#if CAN_WRAP_verify_iovec
    WRAP_FOR_DETACH(verify_iovec)
#endif
#ifndef CAN_WRAP_proc_sched_autogroup_show_task
#   define CAN_WRAP_proc_sched_autogroup_show_task 1
#endif
#if CAN_WRAP_proc_sched_autogroup_show_task
    WRAP_FOR_DETACH(proc_sched_autogroup_show_task)
#endif
#ifndef CAN_WRAP_sock_kfree_s
#   define CAN_WRAP_sock_kfree_s 1
#endif
#if CAN_WRAP_sock_kfree_s
    WRAP_FOR_DETACH(sock_kfree_s)
#endif
#ifndef CAN_WRAP___usermodehelper_set_disable_depth
#   define CAN_WRAP___usermodehelper_set_disable_depth 0
#endif
DETACH(__usermodehelper_set_disable_depth)
#ifndef CAN_WRAP_task_curr
#   define CAN_WRAP_task_curr 1
#endif
#if CAN_WRAP_task_curr
    WRAP_FOR_DETACH(task_curr)
#endif
#ifndef CAN_WRAP_release_thread
#   define CAN_WRAP_release_thread 1
#endif
#if CAN_WRAP_release_thread
    WRAP_FOR_DETACH(release_thread)
#endif
#ifndef CAN_WRAP_seq_put_decimal_ll
#   define CAN_WRAP_seq_put_decimal_ll 1
#endif
#if CAN_WRAP_seq_put_decimal_ll
    WRAP_FOR_DETACH(seq_put_decimal_ll)
#endif
#ifndef CAN_WRAP_acpi_dev_resource_address_space
#   define CAN_WRAP_acpi_dev_resource_address_space 1
#endif
#if CAN_WRAP_acpi_dev_resource_address_space
    WRAP_FOR_DETACH(acpi_dev_resource_address_space)
#endif
#ifndef CAN_WRAP_param_set_ushort
#   define CAN_WRAP_param_set_ushort 1
#endif
#if CAN_WRAP_param_set_ushort
    WRAP_FOR_DETACH(param_set_ushort)
#endif
#ifndef CAN_WRAP_param_get_int
#   define CAN_WRAP_param_get_int 1
#endif
#if CAN_WRAP_param_get_int
    WRAP_FOR_DETACH(param_get_int)
#endif
#ifndef CAN_WRAP___nlmsg_put
#   define CAN_WRAP___nlmsg_put 1
#endif
#if CAN_WRAP___nlmsg_put
#   ifdef DETACH_ADDR___nlmsg_put
        WRAP_FOR_DETACH(__nlmsg_put)
#   else
        TYPED_DETACH(__nlmsg_put)
#   endif
#endif
#ifndef CAN_WRAP_adjust_resource
#   define CAN_WRAP_adjust_resource 1
#endif
#if CAN_WRAP_adjust_resource
    WRAP_FOR_DETACH(adjust_resource)
#endif
#ifndef CAN_WRAP___netlink_clear_multicast_users
#   define CAN_WRAP___netlink_clear_multicast_users 1
#endif
#if CAN_WRAP___netlink_clear_multicast_users
#   ifdef DETACH_ADDR___netlink_clear_multicast_users
        WRAP_FOR_DETACH(__netlink_clear_multicast_users)
#   else
        TYPED_DETACH(__netlink_clear_multicast_users)
#   endif
#endif
#ifndef CAN_WRAP_show_class_attr_string
#   define CAN_WRAP_show_class_attr_string 1
#endif
#if CAN_WRAP_show_class_attr_string
    WRAP_FOR_DETACH(show_class_attr_string)
#endif
#ifndef CAN_WRAP_ntp_init
#   define CAN_WRAP_ntp_init 0
#endif
DETACH(ntp_init)
#ifndef CAN_WRAP_keyring_alloc
#   define CAN_WRAP_keyring_alloc 1
#endif
#if CAN_WRAP_keyring_alloc
    WRAP_FOR_DETACH(keyring_alloc)
#endif
#ifndef CAN_WRAP_ata_cable_40wire
#   define CAN_WRAP_ata_cable_40wire 1
#endif
#if CAN_WRAP_ata_cable_40wire
    WRAP_FOR_DETACH(ata_cable_40wire)
#endif
#ifndef CAN_WRAP_pneigh_enqueue
#   define CAN_WRAP_pneigh_enqueue 1
#endif
#if CAN_WRAP_pneigh_enqueue
    WRAP_FOR_DETACH(pneigh_enqueue)
#endif
#ifndef CAN_WRAP_rwsem_down_read_failed
#   define CAN_WRAP_rwsem_down_read_failed 1
#endif
#if CAN_WRAP_rwsem_down_read_failed
    WRAP_FOR_DETACH(rwsem_down_read_failed)
#endif
#ifndef CAN_WRAP_wait_for_device_probe
#   define CAN_WRAP_wait_for_device_probe 0
#endif
DETACH(wait_for_device_probe)
#ifndef CAN_WRAP_jbd2__journal_restart
#   define CAN_WRAP_jbd2__journal_restart 1
#endif
#if CAN_WRAP_jbd2__journal_restart
    WRAP_FOR_DETACH(jbd2__journal_restart)
#endif
#ifndef CAN_WRAP_swiotlb_map_sg
#   define CAN_WRAP_swiotlb_map_sg 1
#endif
#if CAN_WRAP_swiotlb_map_sg
    WRAP_FOR_DETACH(swiotlb_map_sg)
#endif
#ifndef CAN_WRAP_ata_timing_merge
#   define CAN_WRAP_ata_timing_merge 1
#endif
#if CAN_WRAP_ata_timing_merge
    WRAP_FOR_DETACH(ata_timing_merge)
#endif
#ifndef CAN_WRAP_acpi_remove_gpe_handler
#   define CAN_WRAP_acpi_remove_gpe_handler 1
#endif
#if CAN_WRAP_acpi_remove_gpe_handler
    WRAP_FOR_DETACH(acpi_remove_gpe_handler)
#endif
#ifndef CAN_WRAP_ata_print_version
#   define CAN_WRAP_ata_print_version 1
#endif
#if CAN_WRAP_ata_print_version
    WRAP_FOR_DETACH(ata_print_version)
#endif
#ifndef CAN_WRAP_synchronize_irq
#   define CAN_WRAP_synchronize_irq 0
#endif
DETACH(synchronize_irq)
#ifndef CAN_WRAP_inet_twdr_twcal_tick
#   define CAN_WRAP_inet_twdr_twcal_tick 0
#endif
DETACH(inet_twdr_twcal_tick)
#ifndef CAN_WRAP_set_page_dirty
#   define CAN_WRAP_set_page_dirty 1
#endif
#if CAN_WRAP_set_page_dirty
    WRAP_FOR_DETACH(set_page_dirty)
#endif
#ifndef CAN_WRAP_netdev_class_create_file
#   define CAN_WRAP_netdev_class_create_file 1
#endif
#if CAN_WRAP_netdev_class_create_file
    WRAP_FOR_DETACH(netdev_class_create_file)
#endif
#ifndef CAN_WRAP_account_page_writeback
#   define CAN_WRAP_account_page_writeback 1
#endif
#if CAN_WRAP_account_page_writeback
    WRAP_FOR_DETACH(account_page_writeback)
#endif
#ifndef CAN_WRAP_swap_set_page_dirty
#   define CAN_WRAP_swap_set_page_dirty 1
#endif
#if CAN_WRAP_swap_set_page_dirty
    WRAP_FOR_DETACH(swap_set_page_dirty)
#endif
#ifndef CAN_WRAP_security_setprocattr
#   define CAN_WRAP_security_setprocattr 1
#endif
#if CAN_WRAP_security_setprocattr
    WRAP_FOR_DETACH(security_setprocattr)
#endif
#ifndef CAN_WRAP_tracing_is_on
#   define CAN_WRAP_tracing_is_on 0
#endif
DETACH(tracing_is_on)
#ifndef CAN_WRAP_mutex_lock_interruptible
#   define CAN_WRAP_mutex_lock_interruptible 1
#endif
#if CAN_WRAP_mutex_lock_interruptible
    WRAP_FOR_DETACH(mutex_lock_interruptible)
#endif
#ifndef CAN_WRAP_key_set_timeout
#   define CAN_WRAP_key_set_timeout 1
#endif
#if CAN_WRAP_key_set_timeout
    WRAP_FOR_DETACH(key_set_timeout)
#endif
#ifndef CAN_WRAP_timespec_to_jiffies
#   define CAN_WRAP_timespec_to_jiffies 1
#endif
#if CAN_WRAP_timespec_to_jiffies
    WRAP_FOR_DETACH(timespec_to_jiffies)
#endif
#ifndef CAN_WRAP_class_dev_iter_exit
#   define CAN_WRAP_class_dev_iter_exit 1
#endif
#if CAN_WRAP_class_dev_iter_exit
    WRAP_FOR_DETACH(class_dev_iter_exit)
#endif
#ifndef CAN_WRAP_ata_ehi_clear_desc
#   define CAN_WRAP_ata_ehi_clear_desc 1
#endif
#if CAN_WRAP_ata_ehi_clear_desc
    WRAP_FOR_DETACH(ata_ehi_clear_desc)
#endif
#ifndef CAN_WRAP_sock_common_setsockopt
#   define CAN_WRAP_sock_common_setsockopt 1
#endif
#if CAN_WRAP_sock_common_setsockopt
    WRAP_FOR_DETACH(sock_common_setsockopt)
#endif
#ifndef CAN_WRAP_tcf_destroy_chain
#   define CAN_WRAP_tcf_destroy_chain 0
#endif
DETACH(tcf_destroy_chain)
#ifndef CAN_WRAP_dev_pm_qos_update_request
#   define CAN_WRAP_dev_pm_qos_update_request 1
#endif
#if CAN_WRAP_dev_pm_qos_update_request
    WRAP_FOR_DETACH(dev_pm_qos_update_request)
#endif
#ifndef CAN_WRAP_proc_caches_init
#   define CAN_WRAP_proc_caches_init 0
#endif
DETACH(proc_caches_init)
#ifndef CAN_WRAP_each_symbol_section
#   define CAN_WRAP_each_symbol_section 1
#endif
#if CAN_WRAP_each_symbol_section
    WRAP_FOR_DETACH(each_symbol_section)
#endif
#ifndef CAN_WRAP_bio_integrity_trim
#   define CAN_WRAP_bio_integrity_trim 1
#endif
#if CAN_WRAP_bio_integrity_trim
    WRAP_FOR_DETACH(bio_integrity_trim)
#endif
#ifndef CAN_WRAP_arch_remove_reservations
#   define CAN_WRAP_arch_remove_reservations 1
#endif
#if CAN_WRAP_arch_remove_reservations
    WRAP_FOR_DETACH(arch_remove_reservations)
#endif
#ifndef CAN_WRAP_no_llseek
#   define CAN_WRAP_no_llseek 1
#endif
#if CAN_WRAP_no_llseek
    WRAP_FOR_DETACH(no_llseek)
#endif
#ifndef CAN_WRAP___acpi_unmap_table
#   define CAN_WRAP___acpi_unmap_table 0
#endif
DETACH(__acpi_unmap_table)
#ifndef CAN_WRAP___bdevname
#   define CAN_WRAP___bdevname 0
#endif
DETACH(__bdevname)
#ifndef CAN_WRAP_path_get
#   define CAN_WRAP_path_get 1
#endif
#if CAN_WRAP_path_get
    WRAP_FOR_DETACH(path_get)
#endif
#ifndef CAN_WRAP_register_dock_notifier
#   define CAN_WRAP_register_dock_notifier 1
#endif
#if CAN_WRAP_register_dock_notifier
    WRAP_FOR_DETACH(register_dock_notifier)
#endif
#ifndef CAN_WRAP_si_meminfo_node
#   define CAN_WRAP_si_meminfo_node 1
#endif
#if CAN_WRAP_si_meminfo_node
    WRAP_FOR_DETACH(si_meminfo_node)
#endif
#ifndef CAN_WRAP_devres_release
#   define CAN_WRAP_devres_release 1
#endif
#if CAN_WRAP_devres_release
    WRAP_FOR_DETACH(devres_release)
#endif
#ifndef CAN_WRAP_hrtimer_init
#   define CAN_WRAP_hrtimer_init 1
#endif
#if CAN_WRAP_hrtimer_init
    WRAP_FOR_DETACH(hrtimer_init)
#endif
#ifndef CAN_WRAP_acpi_device_hid
#   define CAN_WRAP_acpi_device_hid 1
#endif
#if CAN_WRAP_acpi_device_hid
    WRAP_FOR_DETACH(acpi_device_hid)
#endif
#ifndef CAN_WRAP_dev_get_by_flags_rcu
#   define CAN_WRAP_dev_get_by_flags_rcu 1
#endif
#if CAN_WRAP_dev_get_by_flags_rcu
    WRAP_FOR_DETACH(dev_get_by_flags_rcu)
#endif
#ifndef CAN_WRAP_unxlate_dev_mem_ptr
#   define CAN_WRAP_unxlate_dev_mem_ptr 0
#endif
DETACH(unxlate_dev_mem_ptr)
#ifndef CAN_WRAP_cleanup_srcu_struct
#   define CAN_WRAP_cleanup_srcu_struct 1
#endif
#if CAN_WRAP_cleanup_srcu_struct
    WRAP_FOR_DETACH(cleanup_srcu_struct)
#endif
#ifndef CAN_WRAP_seq_path
#   define CAN_WRAP_seq_path 1
#endif
#if CAN_WRAP_seq_path
    WRAP_FOR_DETACH(seq_path)
#endif
#ifndef CAN_WRAP_tsc_save_sched_clock_state
#   define CAN_WRAP_tsc_save_sched_clock_state 0
#endif
DETACH(tsc_save_sched_clock_state)
#ifndef CAN_WRAP_init_idle
#   define CAN_WRAP_init_idle 1
#endif
#if CAN_WRAP_init_idle
    WRAP_FOR_DETACH(init_idle)
#endif
#ifndef CAN_WRAP_wakeup_secondary_cpu_via_nmi
#   define CAN_WRAP_wakeup_secondary_cpu_via_nmi 0
#endif
DETACH(wakeup_secondary_cpu_via_nmi)
#ifndef CAN_WRAP_inet_csk_reqsk_queue_prune
#   define CAN_WRAP_inet_csk_reqsk_queue_prune 1
#endif
#if CAN_WRAP_inet_csk_reqsk_queue_prune
    WRAP_FOR_DETACH(inet_csk_reqsk_queue_prune)
#endif
#ifndef CAN_WRAP_nf_register_afinfo
#   define CAN_WRAP_nf_register_afinfo 1
#endif
#if CAN_WRAP_nf_register_afinfo
    WRAP_FOR_DETACH(nf_register_afinfo)
#endif
#ifndef CAN_WRAP_phy_device_free
#   define CAN_WRAP_phy_device_free 1
#endif
#if CAN_WRAP_phy_device_free
    WRAP_FOR_DETACH(phy_device_free)
#endif
#ifndef CAN_WRAP_offline_pages
#   define CAN_WRAP_offline_pages 0
#endif
DETACH(offline_pages)
#ifndef CAN_WRAP_prop_local_destroy_single
#   define CAN_WRAP_prop_local_destroy_single 1
#endif
#if CAN_WRAP_prop_local_destroy_single
    WRAP_FOR_DETACH(prop_local_destroy_single)
#endif
#ifndef CAN_WRAP_init_scattered_cpuid_features
#   define CAN_WRAP_init_scattered_cpuid_features 1
#endif
#if CAN_WRAP_init_scattered_cpuid_features
    WRAP_FOR_DETACH(init_scattered_cpuid_features)
#endif
#ifndef CAN_WRAP_mempool_free_slab
#   define CAN_WRAP_mempool_free_slab 0
#endif
DETACH(mempool_free_slab)
#ifndef CAN_WRAP_acpi_power_resource_unregister_device
#   define CAN_WRAP_acpi_power_resource_unregister_device 1
#endif
#if CAN_WRAP_acpi_power_resource_unregister_device
    WRAP_FOR_DETACH(acpi_power_resource_unregister_device)
#endif
#ifndef CAN_WRAP_mpage_writepages
#   define CAN_WRAP_mpage_writepages 1
#endif
#if CAN_WRAP_mpage_writepages
    WRAP_FOR_DETACH(mpage_writepages)
#endif
#ifndef CAN_WRAP_do_huge_pmd_wp_page
#   define CAN_WRAP_do_huge_pmd_wp_page 1
#endif
#if CAN_WRAP_do_huge_pmd_wp_page
    WRAP_FOR_DETACH(do_huge_pmd_wp_page)
#endif
#ifndef CAN_WRAP_fasync_helper
#   define CAN_WRAP_fasync_helper 1
#endif
#if CAN_WRAP_fasync_helper
    WRAP_FOR_DETACH(fasync_helper)
#endif
#ifndef CAN_WRAP_crypto_register_algs
#   define CAN_WRAP_crypto_register_algs 1
#endif
#if CAN_WRAP_crypto_register_algs
    WRAP_FOR_DETACH(crypto_register_algs)
#endif
#ifndef CAN_WRAP___round_jiffies_up_relative
#   define CAN_WRAP___round_jiffies_up_relative 0
#endif
DETACH(__round_jiffies_up_relative)
#ifndef CAN_WRAP_acpi_pci_link_allocate_irq
#   define CAN_WRAP_acpi_pci_link_allocate_irq 0
#endif
DETACH(acpi_pci_link_allocate_irq)
#ifndef CAN_WRAP_mem_cgroup_shrink_node_zone
#   define CAN_WRAP_mem_cgroup_shrink_node_zone 1
#endif
#if CAN_WRAP_mem_cgroup_shrink_node_zone
    WRAP_FOR_DETACH(mem_cgroup_shrink_node_zone)
#endif
#ifndef CAN_WRAP_zone_pcp_reset
#   define CAN_WRAP_zone_pcp_reset 1
#endif
#if CAN_WRAP_zone_pcp_reset
    WRAP_FOR_DETACH(zone_pcp_reset)
#endif
#ifndef CAN_WRAP_dev_seq_next
#   define CAN_WRAP_dev_seq_next 1
#endif
#if CAN_WRAP_dev_seq_next
    WRAP_FOR_DETACH(dev_seq_next)
#endif
#ifndef CAN_WRAP_generic_file_aio_write
#   define CAN_WRAP_generic_file_aio_write 1
#endif
#if CAN_WRAP_generic_file_aio_write
    WRAP_FOR_DETACH(generic_file_aio_write)
#endif
#ifndef CAN_WRAP_flock_lock_file_wait
#   define CAN_WRAP_flock_lock_file_wait 1
#endif
#if CAN_WRAP_flock_lock_file_wait
    WRAP_FOR_DETACH(flock_lock_file_wait)
#endif
#ifndef CAN_WRAP_inet_frags_init_net
#   define CAN_WRAP_inet_frags_init_net 1
#endif
#if CAN_WRAP_inet_frags_init_net
    WRAP_FOR_DETACH(inet_frags_init_net)
#endif
#ifndef CAN_WRAP_end_page_writeback
#   define CAN_WRAP_end_page_writeback 1
#endif
#if CAN_WRAP_end_page_writeback
    WRAP_FOR_DETACH(end_page_writeback)
#endif
#ifndef CAN_WRAP_tc_classify_compat
#   define CAN_WRAP_tc_classify_compat 1
#endif
#if CAN_WRAP_tc_classify_compat
    WRAP_FOR_DETACH(tc_classify_compat)
#endif
#ifndef CAN_WRAP_generic_write_sync
#   define CAN_WRAP_generic_write_sync 1
#endif
#if CAN_WRAP_generic_write_sync
    WRAP_FOR_DETACH(generic_write_sync)
#endif
#ifndef CAN_WRAP_vzalloc
#   define CAN_WRAP_vzalloc 0
#endif
DETACH(vzalloc)
#ifndef CAN_WRAP_sched_move_task
#   define CAN_WRAP_sched_move_task 1
#endif
#if CAN_WRAP_sched_move_task
    WRAP_FOR_DETACH(sched_move_task)
#endif
#ifndef CAN_WRAP_blocking_notifier_call_chain
#   define CAN_WRAP_blocking_notifier_call_chain 1
#endif
#if CAN_WRAP_blocking_notifier_call_chain
    WRAP_FOR_DETACH(blocking_notifier_call_chain)
#endif
#ifndef CAN_WRAP_res_counter_charge
#   define CAN_WRAP_res_counter_charge 1
#endif
#if CAN_WRAP_res_counter_charge
    WRAP_FOR_DETACH(res_counter_charge)
#endif
#ifndef CAN_WRAP_lru_add_drain
#   define CAN_WRAP_lru_add_drain 0
#endif
DETACH(lru_add_drain)
#ifndef CAN_WRAP_acpi_os_predefined_override
#   define CAN_WRAP_acpi_os_predefined_override 1
#endif
#if CAN_WRAP_acpi_os_predefined_override
    WRAP_FOR_DETACH(acpi_os_predefined_override)
#endif
#ifndef CAN_WRAP_ec_write
#   define CAN_WRAP_ec_write 0
#endif
DETACH(ec_write)
#ifndef CAN_WRAP_acpi_release_mutex
#   define CAN_WRAP_acpi_release_mutex 0
#endif
DETACH(acpi_release_mutex)
#ifndef CAN_WRAP_mii_check_media
#   define CAN_WRAP_mii_check_media 1
#endif
#if CAN_WRAP_mii_check_media
    WRAP_FOR_DETACH(mii_check_media)
#endif
#ifndef CAN_WRAP_csum_partial_copy_to_user
#   define CAN_WRAP_csum_partial_copy_to_user 0
#endif
DETACH(csum_partial_copy_to_user)
#ifndef CAN_WRAP___page_file_mapping
#   define CAN_WRAP___page_file_mapping 1
#endif
#if CAN_WRAP___page_file_mapping
#   ifdef DETACH_ADDR___page_file_mapping
        WRAP_FOR_DETACH(__page_file_mapping)
#   else
        TYPED_DETACH(__page_file_mapping)
#   endif
#endif
#ifndef CAN_WRAP_cont_write_begin
#   define CAN_WRAP_cont_write_begin 1
#endif
#if CAN_WRAP_cont_write_begin
    WRAP_FOR_DETACH(cont_write_begin)
#endif
#ifndef CAN_WRAP_seq_list_start_head
#   define CAN_WRAP_seq_list_start_head 1
#endif
#if CAN_WRAP_seq_list_start_head
    WRAP_FOR_DETACH(seq_list_start_head)
#endif
#ifndef CAN_WRAP_acpi_bus_start
#   define CAN_WRAP_acpi_bus_start 1
#endif
#if CAN_WRAP_acpi_bus_start
    WRAP_FOR_DETACH(acpi_bus_start)
#endif
#ifndef CAN_WRAP_input_open_device
#   define CAN_WRAP_input_open_device 1
#endif
#if CAN_WRAP_input_open_device
    WRAP_FOR_DETACH(input_open_device)
#endif
#ifndef CAN_WRAP_paravirt_get_lazy_mode
#   define CAN_WRAP_paravirt_get_lazy_mode 0
#endif
DETACH(paravirt_get_lazy_mode)
#ifndef CAN_WRAP_acpi_bus_can_wakeup
#   define CAN_WRAP_acpi_bus_can_wakeup 0
#endif
DETACH(acpi_bus_can_wakeup)
#ifndef CAN_WRAP___set_page_dirty_no_writeback
#   define CAN_WRAP___set_page_dirty_no_writeback 1
#endif
#if CAN_WRAP___set_page_dirty_no_writeback
#   ifdef DETACH_ADDR___set_page_dirty_no_writeback
        WRAP_FOR_DETACH(__set_page_dirty_no_writeback)
#   else
        TYPED_DETACH(__set_page_dirty_no_writeback)
#   endif
#endif
#ifndef CAN_WRAP_get_task_pid
#   define CAN_WRAP_get_task_pid 1
#endif
#if CAN_WRAP_get_task_pid
    WRAP_FOR_DETACH(get_task_pid)
#endif
#ifndef CAN_WRAP_xen_biovec_phys_mergeable
#   define CAN_WRAP_xen_biovec_phys_mergeable 1
#endif
#if CAN_WRAP_xen_biovec_phys_mergeable
    WRAP_FOR_DETACH(xen_biovec_phys_mergeable)
#endif
#ifndef CAN_WRAP_elv_drain_elevator
#   define CAN_WRAP_elv_drain_elevator 1
#endif
#if CAN_WRAP_elv_drain_elevator
    WRAP_FOR_DETACH(elv_drain_elevator)
#endif
#ifndef CAN_WRAP_seq_hlist_next
#   define CAN_WRAP_seq_hlist_next 1
#endif
#if CAN_WRAP_seq_hlist_next
    WRAP_FOR_DETACH(seq_hlist_next)
#endif
#ifndef CAN_WRAP_jbd2_journal_init_transaction_cache
#   define CAN_WRAP_jbd2_journal_init_transaction_cache 0
#endif
DETACH(jbd2_journal_init_transaction_cache)
#ifndef CAN_WRAP__raw_spin_lock
#   define CAN_WRAP__raw_spin_lock 1
#endif
#if CAN_WRAP__raw_spin_lock
    WRAP_FOR_DETACH(_raw_spin_lock)
#endif
#ifndef CAN_WRAP_set_mm_exe_file
#   define CAN_WRAP_set_mm_exe_file 1
#endif
#if CAN_WRAP_set_mm_exe_file
    WRAP_FOR_DETACH(set_mm_exe_file)
#endif
#ifndef CAN_WRAP_inet_csk_reset_keepalive_timer
#   define CAN_WRAP_inet_csk_reset_keepalive_timer 1
#endif
#if CAN_WRAP_inet_csk_reset_keepalive_timer
    WRAP_FOR_DETACH(inet_csk_reset_keepalive_timer)
#endif
#ifndef CAN_WRAP_lock_rename
#   define CAN_WRAP_lock_rename 1
#endif
#if CAN_WRAP_lock_rename
    WRAP_FOR_DETACH(lock_rename)
#endif
#ifndef CAN_WRAP_ndo_dflt_bridge_getlink
#   define CAN_WRAP_ndo_dflt_bridge_getlink 1
#endif
#if CAN_WRAP_ndo_dflt_bridge_getlink
    WRAP_FOR_DETACH(ndo_dflt_bridge_getlink)
#endif
#ifndef CAN_WRAP_up_write
#   define CAN_WRAP_up_write 1
#endif
#if CAN_WRAP_up_write
    WRAP_FOR_DETACH(up_write)
#endif
#ifndef CAN_WRAP_strstr
#   define CAN_WRAP_strstr 0
#endif
DETACH(strstr)
#ifndef CAN_WRAP_remove_vm_area
#   define CAN_WRAP_remove_vm_area 1
#endif
#if CAN_WRAP_remove_vm_area
    WRAP_FOR_DETACH(remove_vm_area)
#endif
#ifndef CAN_WRAP_down_timeout
#   define CAN_WRAP_down_timeout 1
#endif
#if CAN_WRAP_down_timeout
    WRAP_FOR_DETACH(down_timeout)
#endif
#ifndef CAN_WRAP_dquot_alloc_inode
#   define CAN_WRAP_dquot_alloc_inode 1
#endif
#if CAN_WRAP_dquot_alloc_inode
    WRAP_FOR_DETACH(dquot_alloc_inode)
#endif
#ifndef CAN_WRAP_sysfs_get
#   define CAN_WRAP_sysfs_get 1
#endif
#if CAN_WRAP_sysfs_get
    WRAP_FOR_DETACH(sysfs_get)
#endif
#ifndef CAN_WRAP_rtnl_link_get_net
#   define CAN_WRAP_rtnl_link_get_net 1
#endif
#if CAN_WRAP_rtnl_link_get_net
    WRAP_FOR_DETACH(rtnl_link_get_net)
#endif
#ifndef CAN_WRAP_default_idle
#   define CAN_WRAP_default_idle 0
#endif
DETACH(default_idle)
#ifndef CAN_WRAP_ktime_get_update_offsets
#   define CAN_WRAP_ktime_get_update_offsets 0
#endif
DETACH(ktime_get_update_offsets)
#ifndef CAN_WRAP_acpi_get_parent
#   define CAN_WRAP_acpi_get_parent 0
#endif
DETACH(acpi_get_parent)
#ifndef CAN_WRAP_security_sb_pivotroot
#   define CAN_WRAP_security_sb_pivotroot 1
#endif
#if CAN_WRAP_security_sb_pivotroot
    WRAP_FOR_DETACH(security_sb_pivotroot)
#endif
#ifndef CAN_WRAP_acpi_disable_wakeup_device_power
#   define CAN_WRAP_acpi_disable_wakeup_device_power 1
#endif
#if CAN_WRAP_acpi_disable_wakeup_device_power
    WRAP_FOR_DETACH(acpi_disable_wakeup_device_power)
#endif
#ifndef CAN_WRAP_dquot_resume
#   define CAN_WRAP_dquot_resume 1
#endif
#if CAN_WRAP_dquot_resume
    WRAP_FOR_DETACH(dquot_resume)
#endif
#ifndef CAN_WRAP_idle_cpu
#   define CAN_WRAP_idle_cpu 0
#endif
DETACH(idle_cpu)
#ifndef CAN_WRAP_rt_mutex_lock_interruptible
#   define CAN_WRAP_rt_mutex_lock_interruptible 1
#endif
#if CAN_WRAP_rt_mutex_lock_interruptible
    WRAP_FOR_DETACH(rt_mutex_lock_interruptible)
#endif
#ifndef CAN_WRAP___module_text_address
#   define CAN_WRAP___module_text_address 1
#endif
#if CAN_WRAP___module_text_address
#   ifdef DETACH_ADDR___module_text_address
        WRAP_FOR_DETACH(__module_text_address)
#   else
        TYPED_DETACH(__module_text_address)
#   endif
#endif
#ifndef CAN_WRAP_set_pages_nx
#   define CAN_WRAP_set_pages_nx 1
#endif
#if CAN_WRAP_set_pages_nx
    WRAP_FOR_DETACH(set_pages_nx)
#endif
#ifndef CAN_WRAP_compat_sys_timerfd_settime
#   define CAN_WRAP_compat_sys_timerfd_settime 1
#endif
#if CAN_WRAP_compat_sys_timerfd_settime
    WRAP_FOR_DETACH(compat_sys_timerfd_settime)
#endif
#ifndef CAN_WRAP_get_compat_sigevent
#   define CAN_WRAP_get_compat_sigevent 1
#endif
#if CAN_WRAP_get_compat_sigevent
    WRAP_FOR_DETACH(get_compat_sigevent)
#endif
#ifndef CAN_WRAP_bus_find_device_by_name
#   define CAN_WRAP_bus_find_device_by_name 1
#endif
#if CAN_WRAP_bus_find_device_by_name
    WRAP_FOR_DETACH(bus_find_device_by_name)
#endif
#ifndef CAN_WRAP_acpi_remove_pm_notifier
#   define CAN_WRAP_acpi_remove_pm_notifier 1
#endif
#if CAN_WRAP_acpi_remove_pm_notifier
    WRAP_FOR_DETACH(acpi_remove_pm_notifier)
#endif
#ifndef CAN_WRAP_bdi_register
#   define CAN_WRAP_bdi_register 1
#endif
#if CAN_WRAP_bdi_register
    WRAP_FOR_DETACH(bdi_register)
#endif
#ifndef CAN_WRAP_unregister_exec_domain
#   define CAN_WRAP_unregister_exec_domain 1
#endif
#if CAN_WRAP_unregister_exec_domain
    WRAP_FOR_DETACH(unregister_exec_domain)
#endif
#ifndef CAN_WRAP_pm_restore_gfp_mask
#   define CAN_WRAP_pm_restore_gfp_mask 0
#endif
DETACH(pm_restore_gfp_mask)
#ifndef CAN_WRAP_pm_generic_thaw_early
#   define CAN_WRAP_pm_generic_thaw_early 1
#endif
#if CAN_WRAP_pm_generic_thaw_early
    WRAP_FOR_DETACH(pm_generic_thaw_early)
#endif
#ifndef CAN_WRAP_sysfs_remove_bin_file
#   define CAN_WRAP_sysfs_remove_bin_file 1
#endif
#if CAN_WRAP_sysfs_remove_bin_file
    WRAP_FOR_DETACH(sysfs_remove_bin_file)
#endif
#ifndef CAN_WRAP_acpi_os_wait_semaphore
#   define CAN_WRAP_acpi_os_wait_semaphore 0
#endif
DETACH(acpi_os_wait_semaphore)
#ifndef CAN_WRAP_getrawmonotonic
#   define CAN_WRAP_getrawmonotonic 1
#endif
#if CAN_WRAP_getrawmonotonic
    WRAP_FOR_DETACH(getrawmonotonic)
#endif
#ifndef CAN_WRAP_acpi_target_system_state
#   define CAN_WRAP_acpi_target_system_state 0
#endif
DETACH(acpi_target_system_state)
#ifndef CAN_WRAP___sync_dirty_buffer
#   define CAN_WRAP___sync_dirty_buffer 1
#endif
#if CAN_WRAP___sync_dirty_buffer
#   ifdef DETACH_ADDR___sync_dirty_buffer
        WRAP_FOR_DETACH(__sync_dirty_buffer)
#   else
        TYPED_DETACH(__sync_dirty_buffer)
#   endif
#endif
#ifndef CAN_WRAP_seq_escape
#   define CAN_WRAP_seq_escape 1
#endif
#if CAN_WRAP_seq_escape
    WRAP_FOR_DETACH(seq_escape)
#endif
#ifndef CAN_WRAP_ata_pio_need_iordy
#   define CAN_WRAP_ata_pio_need_iordy 1
#endif
#if CAN_WRAP_ata_pio_need_iordy
    WRAP_FOR_DETACH(ata_pio_need_iordy)
#endif
#ifndef CAN_WRAP_kernel_power_off
#   define CAN_WRAP_kernel_power_off 0
#endif
DETACH(kernel_power_off)
#ifndef CAN_WRAP_compat_sys_wait4
#   define CAN_WRAP_compat_sys_wait4 1
#endif
#if CAN_WRAP_compat_sys_wait4
    WRAP_FOR_DETACH(compat_sys_wait4)
#endif
#ifndef CAN_WRAP_mempool_alloc_pages
#   define CAN_WRAP_mempool_alloc_pages 0
#endif
DETACH(mempool_alloc_pages)
#ifndef CAN_WRAP_mincore_huge_pmd
#   define CAN_WRAP_mincore_huge_pmd 1
#endif
#if CAN_WRAP_mincore_huge_pmd
    WRAP_FOR_DETACH(mincore_huge_pmd)
#endif
#ifndef CAN_WRAP_build_ehash_secret
#   define CAN_WRAP_build_ehash_secret 0
#endif
DETACH(build_ehash_secret)
#ifndef CAN_WRAP_security_path_chown
#   define CAN_WRAP_security_path_chown 1
#endif
#if CAN_WRAP_security_path_chown
    WRAP_FOR_DETACH(security_path_chown)
#endif
#ifndef CAN_WRAP_pci_iommu_alloc
#   define CAN_WRAP_pci_iommu_alloc 0
#endif
DETACH(pci_iommu_alloc)
#ifndef CAN_WRAP_radix_tree_preload
#   define CAN_WRAP_radix_tree_preload 0
#endif
DETACH(radix_tree_preload)
#ifndef CAN_WRAP_resume_device_irqs
#   define CAN_WRAP_resume_device_irqs 0
#endif
DETACH(resume_device_irqs)
#ifndef CAN_WRAP_vm_is_stack
#   define CAN_WRAP_vm_is_stack 1
#endif
#if CAN_WRAP_vm_is_stack
    WRAP_FOR_DETACH(vm_is_stack)
#endif
#ifndef CAN_WRAP_rcu_nmi_enter
#   define CAN_WRAP_rcu_nmi_enter 0
#endif
DETACH(rcu_nmi_enter)
#ifndef CAN_WRAP___request_module
#   define CAN_WRAP___request_module 0
#endif
DETACH(__request_module)
#ifndef CAN_WRAP_xlate_dev_mem_ptr
#   define CAN_WRAP_xlate_dev_mem_ptr 0
#endif
DETACH(xlate_dev_mem_ptr)
#ifndef CAN_WRAP_acpi_numa_init
#   define CAN_WRAP_acpi_numa_init 0
#endif
DETACH(acpi_numa_init)
#ifndef CAN_WRAP_match_octal
#   define CAN_WRAP_match_octal 1
#endif
#if CAN_WRAP_match_octal
    WRAP_FOR_DETACH(match_octal)
#endif
#ifndef CAN_WRAP_prandom_bytes
#   define CAN_WRAP_prandom_bytes 0
#endif
DETACH(prandom_bytes)
#ifndef CAN_WRAP_do_get_thread_area
#   define CAN_WRAP_do_get_thread_area 1
#endif
#if CAN_WRAP_do_get_thread_area
    WRAP_FOR_DETACH(do_get_thread_area)
#endif
#ifndef CAN_WRAP_dm_table_get
#   define CAN_WRAP_dm_table_get 1
#endif
#if CAN_WRAP_dm_table_get
    WRAP_FOR_DETACH(dm_table_get)
#endif
#ifndef CAN_WRAP_trace_dump_stack
#   define CAN_WRAP_trace_dump_stack 0
#endif
DETACH(trace_dump_stack)
#ifndef CAN_WRAP_sg_alloc_table
#   define CAN_WRAP_sg_alloc_table 1
#endif
#if CAN_WRAP_sg_alloc_table
    WRAP_FOR_DETACH(sg_alloc_table)
#endif
#ifndef CAN_WRAP_bmap
#   define CAN_WRAP_bmap 1
#endif
#if CAN_WRAP_bmap
    WRAP_FOR_DETACH(bmap)
#endif
#ifndef CAN_WRAP_jbd2_journal_get_log_tail
#   define CAN_WRAP_jbd2_journal_get_log_tail 1
#endif
#if CAN_WRAP_jbd2_journal_get_log_tail
    WRAP_FOR_DETACH(jbd2_journal_get_log_tail)
#endif
#ifndef CAN_WRAP_round_jiffies_relative
#   define CAN_WRAP_round_jiffies_relative 0
#endif
DETACH(round_jiffies_relative)
#ifndef CAN_WRAP_kernel_sock_ioctl
#   define CAN_WRAP_kernel_sock_ioctl 1
#endif
#if CAN_WRAP_kernel_sock_ioctl
    WRAP_FOR_DETACH(kernel_sock_ioctl)
#endif
#ifndef CAN_WRAP_pnp_unregister_card_driver
#   define CAN_WRAP_pnp_unregister_card_driver 1
#endif
#if CAN_WRAP_pnp_unregister_card_driver
    WRAP_FOR_DETACH(pnp_unregister_card_driver)
#endif
#ifndef CAN_WRAP_device_for_each_child
#   define CAN_WRAP_device_for_each_child 1
#endif
#if CAN_WRAP_device_for_each_child
    WRAP_FOR_DETACH(device_for_each_child)
#endif
#ifndef CAN_WRAP_bd_unlink_disk_holder
#   define CAN_WRAP_bd_unlink_disk_holder 1
#endif
#if CAN_WRAP_bd_unlink_disk_holder
    WRAP_FOR_DETACH(bd_unlink_disk_holder)
#endif
#ifndef CAN_WRAP_sigsuspend
#   define CAN_WRAP_sigsuspend 1
#endif
#if CAN_WRAP_sigsuspend
    WRAP_FOR_DETACH(sigsuspend)
#endif
#ifndef CAN_WRAP_dquot_mark_dquot_dirty
#   define CAN_WRAP_dquot_mark_dquot_dirty 1
#endif
#if CAN_WRAP_dquot_mark_dquot_dirty
    WRAP_FOR_DETACH(dquot_mark_dquot_dirty)
#endif
#ifndef CAN_WRAP_scsi_free_host_dev
#   define CAN_WRAP_scsi_free_host_dev 1
#endif
#if CAN_WRAP_scsi_free_host_dev
    WRAP_FOR_DETACH(scsi_free_host_dev)
#endif
#ifndef CAN_WRAP_sg_init_table
#   define CAN_WRAP_sg_init_table 1
#endif
#if CAN_WRAP_sg_init_table
    WRAP_FOR_DETACH(sg_init_table)
#endif
#ifndef CAN_WRAP_insert_resource_expand_to_fit
#   define CAN_WRAP_insert_resource_expand_to_fit 1
#endif
#if CAN_WRAP_insert_resource_expand_to_fit
    WRAP_FOR_DETACH(insert_resource_expand_to_fit)
#endif
#ifndef CAN_WRAP_acpi_evaluate_hotplug_ost
#   define CAN_WRAP_acpi_evaluate_hotplug_ost 1
#endif
#if CAN_WRAP_acpi_evaluate_hotplug_ost
    WRAP_FOR_DETACH(acpi_evaluate_hotplug_ost)
#endif
#ifndef CAN_WRAP_early_ioremap_reset
#   define CAN_WRAP_early_ioremap_reset 0
#endif
DETACH(early_ioremap_reset)
#ifndef CAN_WRAP_proc_dostring
#   define CAN_WRAP_proc_dostring 1
#endif
#if CAN_WRAP_proc_dostring
    WRAP_FOR_DETACH(proc_dostring)
#endif
#ifndef CAN_WRAP_dm_suspend
#   define CAN_WRAP_dm_suspend 1
#endif
#if CAN_WRAP_dm_suspend
    WRAP_FOR_DETACH(dm_suspend)
#endif
#ifndef CAN_WRAP_alternatives_text_reserved
#   define CAN_WRAP_alternatives_text_reserved 0
#endif
DETACH(alternatives_text_reserved)
#ifndef CAN_WRAP_ata_sff_qc_issue
#   define CAN_WRAP_ata_sff_qc_issue 1
#endif
#if CAN_WRAP_ata_sff_qc_issue
    WRAP_FOR_DETACH(ata_sff_qc_issue)
#endif
#ifndef CAN_WRAP_pid_ns_prepare_proc
#   define CAN_WRAP_pid_ns_prepare_proc 1
#endif
#if CAN_WRAP_pid_ns_prepare_proc
    WRAP_FOR_DETACH(pid_ns_prepare_proc)
#endif
#ifndef CAN_WRAP_compat_sys_ppoll
#   define CAN_WRAP_compat_sys_ppoll 1
#endif
#if CAN_WRAP_compat_sys_ppoll
    WRAP_FOR_DETACH(compat_sys_ppoll)
#endif
#ifndef CAN_WRAP_pci_scan_bridge
#   define CAN_WRAP_pci_scan_bridge 1
#endif
#if CAN_WRAP_pci_scan_bridge
    WRAP_FOR_DETACH(pci_scan_bridge)
#endif
#ifndef CAN_WRAP_task_sched_runtime
#   define CAN_WRAP_task_sched_runtime 1
#endif
#if CAN_WRAP_task_sched_runtime
    WRAP_FOR_DETACH(task_sched_runtime)
#endif
#ifndef CAN_WRAP_pgd_clear_bad
#   define CAN_WRAP_pgd_clear_bad 1
#endif
#if CAN_WRAP_pgd_clear_bad
    WRAP_FOR_DETACH(pgd_clear_bad)
#endif
#ifndef CAN_WRAP_jbd2_journal_stop
#   define CAN_WRAP_jbd2_journal_stop 1
#endif
#if CAN_WRAP_jbd2_journal_stop
    WRAP_FOR_DETACH(jbd2_journal_stop)
#endif
#ifndef CAN_WRAP_pm_generic_resume_early
#   define CAN_WRAP_pm_generic_resume_early 1
#endif
#if CAN_WRAP_pm_generic_resume_early
    WRAP_FOR_DETACH(pm_generic_resume_early)
#endif
#ifndef CAN_WRAP_csum_partial_copy_nocheck
#   define CAN_WRAP_csum_partial_copy_nocheck 0
#endif
DETACH(csum_partial_copy_nocheck)
#ifndef CAN_WRAP_follow_up
#   define CAN_WRAP_follow_up 1
#endif
#if CAN_WRAP_follow_up
    WRAP_FOR_DETACH(follow_up)
#endif
#ifndef CAN_WRAP_skb_copy_ubufs
#   define CAN_WRAP_skb_copy_ubufs 1
#endif
#if CAN_WRAP_skb_copy_ubufs
    WRAP_FOR_DETACH(skb_copy_ubufs)
#endif
#ifndef CAN_WRAP_irq_cpu_online
#   define CAN_WRAP_irq_cpu_online 0
#endif
DETACH(irq_cpu_online)
#ifndef CAN_WRAP_fasync_insert_entry
#   define CAN_WRAP_fasync_insert_entry 1
#endif
#if CAN_WRAP_fasync_insert_entry
    WRAP_FOR_DETACH(fasync_insert_entry)
#endif
#ifndef CAN_WRAP_dev_get_by_index_rcu
#   define CAN_WRAP_dev_get_by_index_rcu 1
#endif
#if CAN_WRAP_dev_get_by_index_rcu
    WRAP_FOR_DETACH(dev_get_by_index_rcu)
#endif
#ifndef CAN_WRAP_warn_slowpath_fmt_taint
#   define CAN_WRAP_warn_slowpath_fmt_taint 0
#endif
DETACH(warn_slowpath_fmt_taint)
#ifndef CAN_WRAP_sk_reset_txq
#   define CAN_WRAP_sk_reset_txq 1
#endif
#if CAN_WRAP_sk_reset_txq
    WRAP_FOR_DETACH(sk_reset_txq)
#endif
#ifndef CAN_WRAP_ethtool_op_get_ts_info
#   define CAN_WRAP_ethtool_op_get_ts_info 1
#endif
#if CAN_WRAP_ethtool_op_get_ts_info
    WRAP_FOR_DETACH(ethtool_op_get_ts_info)
#endif
#ifndef CAN_WRAP_exit_creds
#   define CAN_WRAP_exit_creds 1
#endif
#if CAN_WRAP_exit_creds
    WRAP_FOR_DETACH(exit_creds)
#endif
#ifndef CAN_WRAP_pci_find_bus
#   define CAN_WRAP_pci_find_bus 1
#endif
#if CAN_WRAP_pci_find_bus
    WRAP_FOR_DETACH(pci_find_bus)
#endif
#ifndef CAN_WRAP_handle_pte_fault
#   define CAN_WRAP_handle_pte_fault 1
#endif
#if CAN_WRAP_handle_pte_fault
    WRAP_FOR_DETACH(handle_pte_fault)
#endif
#ifndef CAN_WRAP_set_personality_ia32
#   define CAN_WRAP_set_personality_ia32 0
#endif
DETACH(set_personality_ia32)
#ifndef CAN_WRAP_vfs_caches_init_early
#   define CAN_WRAP_vfs_caches_init_early 0
#endif
DETACH(vfs_caches_init_early)
#ifndef CAN_WRAP_blk_flush_plug_list
#   define CAN_WRAP_blk_flush_plug_list 1
#endif
#if CAN_WRAP_blk_flush_plug_list
    WRAP_FOR_DETACH(blk_flush_plug_list)
#endif
#ifndef CAN_WRAP_irq_gc_mask_set_bit
#   define CAN_WRAP_irq_gc_mask_set_bit 1
#endif
#if CAN_WRAP_irq_gc_mask_set_bit
    WRAP_FOR_DETACH(irq_gc_mask_set_bit)
#endif
#ifndef CAN_WRAP_pid_nr_ns
#   define CAN_WRAP_pid_nr_ns 1
#endif
#if CAN_WRAP_pid_nr_ns
    WRAP_FOR_DETACH(pid_nr_ns)
#endif
#ifndef CAN_WRAP_round_jiffies_up_relative
#   define CAN_WRAP_round_jiffies_up_relative 0
#endif
DETACH(round_jiffies_up_relative)
#ifndef CAN_WRAP_posix_acl_permission
#   define CAN_WRAP_posix_acl_permission 1
#endif
#if CAN_WRAP_posix_acl_permission
    WRAP_FOR_DETACH(posix_acl_permission)
#endif
#ifndef CAN_WRAP_qdisc_get_rtab
#   define CAN_WRAP_qdisc_get_rtab 1
#endif
#if CAN_WRAP_qdisc_get_rtab
    WRAP_FOR_DETACH(qdisc_get_rtab)
#endif
#ifndef CAN_WRAP_numa_free_all_bootmem
#   define CAN_WRAP_numa_free_all_bootmem 0
#endif
DETACH(numa_free_all_bootmem)
#ifndef CAN_WRAP_update_process_times
#   define CAN_WRAP_update_process_times 0
#endif
DETACH(update_process_times)
#ifndef CAN_WRAP_blk_make_request
#   define CAN_WRAP_blk_make_request 1
#endif
#if CAN_WRAP_blk_make_request
    WRAP_FOR_DETACH(blk_make_request)
#endif
#ifndef CAN_WRAP_phy_mii_ioctl
#   define CAN_WRAP_phy_mii_ioctl 1
#endif
#if CAN_WRAP_phy_mii_ioctl
    WRAP_FOR_DETACH(phy_mii_ioctl)
#endif
#ifndef CAN_WRAP_pci_cfg_space_size_ext
#   define CAN_WRAP_pci_cfg_space_size_ext 1
#endif
#if CAN_WRAP_pci_cfg_space_size_ext
    WRAP_FOR_DETACH(pci_cfg_space_size_ext)
#endif
#ifndef CAN_WRAP_posix_acl_alloc
#   define CAN_WRAP_posix_acl_alloc 1
#endif
#if CAN_WRAP_posix_acl_alloc
    WRAP_FOR_DETACH(posix_acl_alloc)
#endif
#ifndef CAN_WRAP_set_memory_np
#   define CAN_WRAP_set_memory_np 0
#endif
DETACH(set_memory_np)
#ifndef CAN_WRAP_kthread_bind
#   define CAN_WRAP_kthread_bind 1
#endif
#if CAN_WRAP_kthread_bind
    WRAP_FOR_DETACH(kthread_bind)
#endif
#ifndef CAN_WRAP_set_memory_nx
#   define CAN_WRAP_set_memory_nx 0
#endif
DETACH(set_memory_nx)
#ifndef CAN_WRAP_class_create_file
#   define CAN_WRAP_class_create_file 1
#endif
#if CAN_WRAP_class_create_file
    WRAP_FOR_DETACH(class_create_file)
#endif
#ifndef CAN_WRAP_kstrtoint_from_user
#   define CAN_WRAP_kstrtoint_from_user 0
#endif
DETACH(kstrtoint_from_user)
#ifndef CAN_WRAP_tracing_start
#   define CAN_WRAP_tracing_start 0
#endif
DETACH(tracing_start)
#ifndef CAN_WRAP_sb_set_blocksize
#   define CAN_WRAP_sb_set_blocksize 1
#endif
#if CAN_WRAP_sb_set_blocksize
    WRAP_FOR_DETACH(sb_set_blocksize)
#endif
#ifndef CAN_WRAP_msi_remove_pci_irq_vectors
#   define CAN_WRAP_msi_remove_pci_irq_vectors 1
#endif
#if CAN_WRAP_msi_remove_pci_irq_vectors
    WRAP_FOR_DETACH(msi_remove_pci_irq_vectors)
#endif
#ifndef CAN_WRAP_netlink_kernel_release
#   define CAN_WRAP_netlink_kernel_release 1
#endif
#if CAN_WRAP_netlink_kernel_release
    WRAP_FOR_DETACH(netlink_kernel_release)
#endif
#ifndef CAN_WRAP___pmd_alloc
#   define CAN_WRAP___pmd_alloc 1
#endif
#if CAN_WRAP___pmd_alloc
#   ifdef DETACH_ADDR___pmd_alloc
        WRAP_FOR_DETACH(__pmd_alloc)
#   else
        TYPED_DETACH(__pmd_alloc)
#   endif
#endif
#ifndef CAN_WRAP_fprop_global_destroy
#   define CAN_WRAP_fprop_global_destroy 1
#endif
#if CAN_WRAP_fprop_global_destroy
    WRAP_FOR_DETACH(fprop_global_destroy)
#endif
#ifndef CAN_WRAP_this_cpu_load
#   define CAN_WRAP_this_cpu_load 0
#endif
DETACH(this_cpu_load)
#ifndef CAN_WRAP_lock_flocks
#   define CAN_WRAP_lock_flocks 0
#endif
DETACH(lock_flocks)
#ifndef CAN_WRAP_pci_write_vpd
#   define CAN_WRAP_pci_write_vpd 1
#endif
#if CAN_WRAP_pci_write_vpd
    WRAP_FOR_DETACH(pci_write_vpd)
#endif
#ifndef CAN_WRAP_bitmap_release_region
#   define CAN_WRAP_bitmap_release_region 0
#endif
DETACH(bitmap_release_region)
#ifndef CAN_WRAP_genphy_suspend
#   define CAN_WRAP_genphy_suspend 1
#endif
#if CAN_WRAP_genphy_suspend
    WRAP_FOR_DETACH(genphy_suspend)
#endif
#ifndef CAN_WRAP_compat_sys_stime
#   define CAN_WRAP_compat_sys_stime 0
#endif
DETACH(compat_sys_stime)
#ifndef CAN_WRAP_security_socket_connect
#   define CAN_WRAP_security_socket_connect 1
#endif
#if CAN_WRAP_security_socket_connect
    WRAP_FOR_DETACH(security_socket_connect)
#endif
#ifndef CAN_WRAP_compat_sys_sysctl
#   define CAN_WRAP_compat_sys_sysctl 1
#endif
#if CAN_WRAP_compat_sys_sysctl
    WRAP_FOR_DETACH(compat_sys_sysctl)
#endif
#ifndef CAN_WRAP_unlock_buffer
#   define CAN_WRAP_unlock_buffer 1
#endif
#if CAN_WRAP_unlock_buffer
    WRAP_FOR_DETACH(unlock_buffer)
#endif
#ifndef CAN_WRAP_find_extend_vma
#   define CAN_WRAP_find_extend_vma 1
#endif
#if CAN_WRAP_find_extend_vma
    WRAP_FOR_DETACH(find_extend_vma)
#endif
#ifndef CAN_WRAP_arch_randomize_brk
#   define CAN_WRAP_arch_randomize_brk 1
#endif
#if CAN_WRAP_arch_randomize_brk
    WRAP_FOR_DETACH(arch_randomize_brk)
#endif
#ifndef CAN_WRAP_skb_copy_and_csum_bits
#   define CAN_WRAP_skb_copy_and_csum_bits 1
#endif
#if CAN_WRAP_skb_copy_and_csum_bits
    WRAP_FOR_DETACH(skb_copy_and_csum_bits)
#endif
#ifndef CAN_WRAP_swiotlb_map_sg_attrs
#   define CAN_WRAP_swiotlb_map_sg_attrs 1
#endif
#if CAN_WRAP_swiotlb_map_sg_attrs
    WRAP_FOR_DETACH(swiotlb_map_sg_attrs)
#endif
#ifndef CAN_WRAP_destroy_workqueue
#   define CAN_WRAP_destroy_workqueue 1
#endif
#if CAN_WRAP_destroy_workqueue
    WRAP_FOR_DETACH(destroy_workqueue)
#endif
#ifndef CAN_WRAP_pci_bus_write_config_dword
#   define CAN_WRAP_pci_bus_write_config_dword 1
#endif
#if CAN_WRAP_pci_bus_write_config_dword
    WRAP_FOR_DETACH(pci_bus_write_config_dword)
#endif
#ifndef CAN_WRAP_netlink_has_listeners
#   define CAN_WRAP_netlink_has_listeners 1
#endif
#if CAN_WRAP_netlink_has_listeners
    WRAP_FOR_DETACH(netlink_has_listeners)
#endif
#ifndef CAN_WRAP_inet_csk_clone_lock
#   define CAN_WRAP_inet_csk_clone_lock 1
#endif
#if CAN_WRAP_inet_csk_clone_lock
    WRAP_FOR_DETACH(inet_csk_clone_lock)
#endif
#ifndef CAN_WRAP_huge_pmd_set_accessed
#   define CAN_WRAP_huge_pmd_set_accessed 1
#endif
#if CAN_WRAP_huge_pmd_set_accessed
    WRAP_FOR_DETACH(huge_pmd_set_accessed)
#endif
#ifndef CAN_WRAP_devres_alloc
#   define CAN_WRAP_devres_alloc 1
#endif
#if CAN_WRAP_devres_alloc
    WRAP_FOR_DETACH(devres_alloc)
#endif
#ifndef CAN_WRAP_scsi_flush_work
#   define CAN_WRAP_scsi_flush_work 1
#endif
#if CAN_WRAP_scsi_flush_work
    WRAP_FOR_DETACH(scsi_flush_work)
#endif
#ifndef CAN_WRAP_radix_tree_init
#   define CAN_WRAP_radix_tree_init 0
#endif
DETACH(radix_tree_init)
#ifndef CAN_WRAP_acpi_dev_free_resource_list
#   define CAN_WRAP_acpi_dev_free_resource_list 1
#endif
#if CAN_WRAP_acpi_dev_free_resource_list
    WRAP_FOR_DETACH(acpi_dev_free_resource_list)
#endif
#ifndef CAN_WRAP_pci_prepare_to_sleep
#   define CAN_WRAP_pci_prepare_to_sleep 1
#endif
#if CAN_WRAP_pci_prepare_to_sleep
    WRAP_FOR_DETACH(pci_prepare_to_sleep)
#endif
#ifndef CAN_WRAP_pci_bus_find_capability
#   define CAN_WRAP_pci_bus_find_capability 1
#endif
#if CAN_WRAP_pci_bus_find_capability
    WRAP_FOR_DETACH(pci_bus_find_capability)
#endif
#ifndef CAN_WRAP_dma_release_channel
#   define CAN_WRAP_dma_release_channel 1
#endif
#if CAN_WRAP_dma_release_channel
    WRAP_FOR_DETACH(dma_release_channel)
#endif
#ifndef CAN_WRAP_unblock_all_signals
#   define CAN_WRAP_unblock_all_signals 0
#endif
DETACH(unblock_all_signals)
#ifndef CAN_WRAP_elv_dispatch_add_tail
#   define CAN_WRAP_elv_dispatch_add_tail 1
#endif
#if CAN_WRAP_elv_dispatch_add_tail
    WRAP_FOR_DETACH(elv_dispatch_add_tail)
#endif
#ifndef CAN_WRAP_devres_free
#   define CAN_WRAP_devres_free 0
#endif
DETACH(devres_free)
#ifndef CAN_WRAP_qdisc_class_hash_remove
#   define CAN_WRAP_qdisc_class_hash_remove 1
#endif
#if CAN_WRAP_qdisc_class_hash_remove
    WRAP_FOR_DETACH(qdisc_class_hash_remove)
#endif
#ifndef CAN_WRAP_pcim_iomap
#   define CAN_WRAP_pcim_iomap 1
#endif
#if CAN_WRAP_pcim_iomap
    WRAP_FOR_DETACH(pcim_iomap)
#endif
#ifndef CAN_WRAP_offline_memory_block
#   define CAN_WRAP_offline_memory_block 1
#endif
#if CAN_WRAP_offline_memory_block
    WRAP_FOR_DETACH(offline_memory_block)
#endif
#ifndef CAN_WRAP_security_secid_to_secctx
#   define CAN_WRAP_security_secid_to_secctx 0
#endif
DETACH(security_secid_to_secctx)
#ifndef CAN_WRAP_percpu_counter_set
#   define CAN_WRAP_percpu_counter_set 1
#endif
#if CAN_WRAP_percpu_counter_set
    WRAP_FOR_DETACH(percpu_counter_set)
#endif
#ifndef CAN_WRAP_pci_common_swizzle
#   define CAN_WRAP_pci_common_swizzle 1
#endif
#if CAN_WRAP_pci_common_swizzle
    WRAP_FOR_DETACH(pci_common_swizzle)
#endif
#ifndef CAN_WRAP_bitmap_bitremap
#   define CAN_WRAP_bitmap_bitremap 0
#endif
DETACH(bitmap_bitremap)
#ifndef CAN_WRAP_posix_acl_create
#   define CAN_WRAP_posix_acl_create 0
#endif
DETACH(posix_acl_create)
#ifndef CAN_WRAP___irq_set_handler
#   define CAN_WRAP___irq_set_handler 1
#endif
#if CAN_WRAP___irq_set_handler
#   ifdef DETACH_ADDR___irq_set_handler
        WRAP_FOR_DETACH(__irq_set_handler)
#   else
        TYPED_DETACH(__irq_set_handler)
#   endif
#endif
#ifndef CAN_WRAP_inet_csk_prepare_forced_close
#   define CAN_WRAP_inet_csk_prepare_forced_close 1
#endif
#if CAN_WRAP_inet_csk_prepare_forced_close
    WRAP_FOR_DETACH(inet_csk_prepare_forced_close)
#endif
#ifndef CAN_WRAP_pm_qos_read_value
#   define CAN_WRAP_pm_qos_read_value 1
#endif
#if CAN_WRAP_pm_qos_read_value
    WRAP_FOR_DETACH(pm_qos_read_value)
#endif
#ifndef CAN_WRAP_pcibios_update_irq
#   define CAN_WRAP_pcibios_update_irq 1
#endif
#if CAN_WRAP_pcibios_update_irq
    WRAP_FOR_DETACH(pcibios_update_irq)
#endif
#ifndef CAN_WRAP_sk_stream_alloc_skb
#   define CAN_WRAP_sk_stream_alloc_skb 1
#endif
#if CAN_WRAP_sk_stream_alloc_skb
    WRAP_FOR_DETACH(sk_stream_alloc_skb)
#endif
#ifndef CAN_WRAP_pnp_range_reserved
#   define CAN_WRAP_pnp_range_reserved 0
#endif
DETACH(pnp_range_reserved)
#ifndef CAN_WRAP_free_percpu_irq
#   define CAN_WRAP_free_percpu_irq 0
#endif
DETACH(free_percpu_irq)
#ifndef CAN_WRAP_enable_IR_x2apic
#   define CAN_WRAP_enable_IR_x2apic 0
#endif
DETACH(enable_IR_x2apic)
#ifndef CAN_WRAP_neigh_compat_output
#   define CAN_WRAP_neigh_compat_output 1
#endif
#if CAN_WRAP_neigh_compat_output
    WRAP_FOR_DETACH(neigh_compat_output)
#endif
#ifndef CAN_WRAP_timecounter_read
#   define CAN_WRAP_timecounter_read 1
#endif
#if CAN_WRAP_timecounter_read
    WRAP_FOR_DETACH(timecounter_read)
#endif
#ifndef CAN_WRAP_usermodehelper_read_unlock
#   define CAN_WRAP_usermodehelper_read_unlock 0
#endif
DETACH(usermodehelper_read_unlock)
#ifndef CAN_WRAP___request_region
#   define CAN_WRAP___request_region 1
#endif
#if CAN_WRAP___request_region
#   ifdef DETACH_ADDR___request_region
        WRAP_FOR_DETACH(__request_region)
#   else
        TYPED_DETACH(__request_region)
#   endif
#endif
#ifndef CAN_WRAP___locks_copy_lock
#   define CAN_WRAP___locks_copy_lock 1
#endif
#if CAN_WRAP___locks_copy_lock
#   ifdef DETACH_ADDR___locks_copy_lock
        WRAP_FOR_DETACH(__locks_copy_lock)
#   else
        TYPED_DETACH(__locks_copy_lock)
#   endif
#endif
#ifndef CAN_WRAP_dquot_free_inode
#   define CAN_WRAP_dquot_free_inode 1
#endif
#if CAN_WRAP_dquot_free_inode
    WRAP_FOR_DETACH(dquot_free_inode)
#endif
#ifndef CAN_WRAP_security_sb_statfs
#   define CAN_WRAP_security_sb_statfs 1
#endif
#if CAN_WRAP_security_sb_statfs
    WRAP_FOR_DETACH(security_sb_statfs)
#endif
#ifndef CAN_WRAP_setup_arch
#   define CAN_WRAP_setup_arch 0
#endif
DETACH(setup_arch)
#ifndef CAN_WRAP___f_setown
#   define CAN_WRAP___f_setown 1
#endif
#if CAN_WRAP___f_setown
#   ifdef DETACH_ADDR___f_setown
        WRAP_FOR_DETACH(__f_setown)
#   else
        TYPED_DETACH(__f_setown)
#   endif
#endif
#ifndef CAN_WRAP_irq_gc_ack_set_bit
#   define CAN_WRAP_irq_gc_ack_set_bit 1
#endif
#if CAN_WRAP_irq_gc_ack_set_bit
    WRAP_FOR_DETACH(irq_gc_ack_set_bit)
#endif
#ifndef CAN_WRAP_ata_wait_after_reset
#   define CAN_WRAP_ata_wait_after_reset 1
#endif
#if CAN_WRAP_ata_wait_after_reset
    WRAP_FOR_DETACH(ata_wait_after_reset)
#endif
#ifndef CAN_WRAP_wait_for_key_construction
#   define CAN_WRAP_wait_for_key_construction 1
#endif
#if CAN_WRAP_wait_for_key_construction
    WRAP_FOR_DETACH(wait_for_key_construction)
#endif
#ifndef CAN_WRAP_blk_queue_io_min
#   define CAN_WRAP_blk_queue_io_min 1
#endif
#if CAN_WRAP_blk_queue_io_min
    WRAP_FOR_DETACH(blk_queue_io_min)
#endif
#ifndef CAN_WRAP___wake_up
#   define CAN_WRAP___wake_up 1
#endif
#if CAN_WRAP___wake_up
#   ifdef DETACH_ADDR___wake_up
        WRAP_FOR_DETACH(__wake_up)
#   else
        TYPED_DETACH(__wake_up)
#   endif
#endif
#ifndef CAN_WRAP_blk_limits_max_hw_sectors
#   define CAN_WRAP_blk_limits_max_hw_sectors 1
#endif
#if CAN_WRAP_blk_limits_max_hw_sectors
    WRAP_FOR_DETACH(blk_limits_max_hw_sectors)
#endif
#ifndef CAN_WRAP_request_key_async_with_auxdata
#   define CAN_WRAP_request_key_async_with_auxdata 1
#endif
#if CAN_WRAP_request_key_async_with_auxdata
    WRAP_FOR_DETACH(request_key_async_with_auxdata)
#endif
#ifndef CAN_WRAP_arch_vma_name
#   define CAN_WRAP_arch_vma_name 1
#endif
#if CAN_WRAP_arch_vma_name
    WRAP_FOR_DETACH(arch_vma_name)
#endif
#ifndef CAN_WRAP_elv_register
#   define CAN_WRAP_elv_register 1
#endif
#if CAN_WRAP_elv_register
    WRAP_FOR_DETACH(elv_register)
#endif
#ifndef CAN_WRAP_collect_mounts
#   define CAN_WRAP_collect_mounts 1
#endif
#if CAN_WRAP_collect_mounts
    WRAP_FOR_DETACH(collect_mounts)
#endif
#ifndef CAN_WRAP_security_inode_getsecctx
#   define CAN_WRAP_security_inode_getsecctx 1
#endif
#if CAN_WRAP_security_inode_getsecctx
    WRAP_FOR_DETACH(security_inode_getsecctx)
#endif
#ifndef CAN_WRAP___do_softirq
#   define CAN_WRAP___do_softirq 0
#endif
DETACH(__do_softirq)
#ifndef CAN_WRAP_exportfs_decode_fh
#   define CAN_WRAP_exportfs_decode_fh 1
#endif
#if CAN_WRAP_exportfs_decode_fh
    WRAP_FOR_DETACH(exportfs_decode_fh)
#endif
#ifndef CAN_WRAP_blk_integrity_register
#   define CAN_WRAP_blk_integrity_register 1
#endif
#if CAN_WRAP_blk_integrity_register
    WRAP_FOR_DETACH(blk_integrity_register)
#endif
#ifndef CAN_WRAP_wake_up_idle_cpu
#   define CAN_WRAP_wake_up_idle_cpu 0
#endif
DETACH(wake_up_idle_cpu)
#ifndef CAN_WRAP_acpi_early_init
#   define CAN_WRAP_acpi_early_init 0
#endif
DETACH(acpi_early_init)
#ifndef CAN_WRAP_simple_xattr_set
#   define CAN_WRAP_simple_xattr_set 1
#endif
#if CAN_WRAP_simple_xattr_set
    WRAP_FOR_DETACH(simple_xattr_set)
#endif
#ifndef CAN_WRAP_vfs_fsync_range
#   define CAN_WRAP_vfs_fsync_range 1
#endif
#if CAN_WRAP_vfs_fsync_range
    WRAP_FOR_DETACH(vfs_fsync_range)
#endif
#ifndef CAN_WRAP_amd_get_nb_id
#   define CAN_WRAP_amd_get_nb_id 0
#endif
DETACH(amd_get_nb_id)
#ifndef CAN_WRAP_pdev_enable_device
#   define CAN_WRAP_pdev_enable_device 1
#endif
#if CAN_WRAP_pdev_enable_device
    WRAP_FOR_DETACH(pdev_enable_device)
#endif
#ifndef CAN_WRAP_dm_vcalloc
#   define CAN_WRAP_dm_vcalloc 0
#endif
DETACH(dm_vcalloc)
#ifndef CAN_WRAP_add_timer
#   define CAN_WRAP_add_timer 1
#endif
#if CAN_WRAP_add_timer
    WRAP_FOR_DETACH(add_timer)
#endif
#ifndef CAN_WRAP_cgroup_css_from_dir
#   define CAN_WRAP_cgroup_css_from_dir 1
#endif
#if CAN_WRAP_cgroup_css_from_dir
    WRAP_FOR_DETACH(cgroup_css_from_dir)
#endif
#ifndef CAN_WRAP_set_memory_array_uc
#   define CAN_WRAP_set_memory_array_uc 0
#endif
DETACH(set_memory_array_uc)
#ifndef CAN_WRAP_pm_generic_poweroff
#   define CAN_WRAP_pm_generic_poweroff 1
#endif
#if CAN_WRAP_pm_generic_poweroff
    WRAP_FOR_DETACH(pm_generic_poweroff)
#endif
#ifndef CAN_WRAP_pcie_capability_read_word
#   define CAN_WRAP_pcie_capability_read_word 1
#endif
#if CAN_WRAP_pcie_capability_read_word
    WRAP_FOR_DETACH(pcie_capability_read_word)
#endif
#ifndef CAN_WRAP_kthread_create_on_node
#   define CAN_WRAP_kthread_create_on_node 1
#endif
#if CAN_WRAP_kthread_create_on_node
    WRAP_FOR_DETACH(kthread_create_on_node)
#endif
#ifndef CAN_WRAP___sock_recv_ts_and_drops
#   define CAN_WRAP___sock_recv_ts_and_drops 1
#endif
#if CAN_WRAP___sock_recv_ts_and_drops
#   ifdef DETACH_ADDR___sock_recv_ts_and_drops
        WRAP_FOR_DETACH(__sock_recv_ts_and_drops)
#   else
        TYPED_DETACH(__sock_recv_ts_and_drops)
#   endif
#endif
#ifndef CAN_WRAP_find_vma
#   define CAN_WRAP_find_vma 1
#endif
#if CAN_WRAP_find_vma
    WRAP_FOR_DETACH(find_vma)
#endif
#ifndef CAN_WRAP_print_slabinfo_header
#   define CAN_WRAP_print_slabinfo_header 1
#endif
#if CAN_WRAP_print_slabinfo_header
    WRAP_FOR_DETACH(print_slabinfo_header)
#endif
#ifndef CAN_WRAP___bitmap_or
#   define CAN_WRAP___bitmap_or 0
#endif
DETACH(__bitmap_or)
#ifndef CAN_WRAP_has_ns_capability_noaudit
#   define CAN_WRAP_has_ns_capability_noaudit 1
#endif
#if CAN_WRAP_has_ns_capability_noaudit
    WRAP_FOR_DETACH(has_ns_capability_noaudit)
#endif
#ifndef CAN_WRAP_dm_dispatch_request
#   define CAN_WRAP_dm_dispatch_request 1
#endif
#if CAN_WRAP_dm_dispatch_request
    WRAP_FOR_DETACH(dm_dispatch_request)
#endif
#ifndef CAN_WRAP_mii_link_ok
#   define CAN_WRAP_mii_link_ok 1
#endif
#if CAN_WRAP_mii_link_ok
    WRAP_FOR_DETACH(mii_link_ok)
#endif
#ifndef CAN_WRAP_acpi_get_child
#   define CAN_WRAP_acpi_get_child 0
#endif
DETACH(acpi_get_child)
#ifndef CAN_WRAP_setup_sysctl_set
#   define CAN_WRAP_setup_sysctl_set 1
#endif
#if CAN_WRAP_setup_sysctl_set
    WRAP_FOR_DETACH(setup_sysctl_set)
#endif
#ifndef CAN_WRAP___scm_send
#   define CAN_WRAP___scm_send 1
#endif
#if CAN_WRAP___scm_send
#   ifdef DETACH_ADDR___scm_send
        WRAP_FOR_DETACH(__scm_send)
#   else
        TYPED_DETACH(__scm_send)
#   endif
#endif
#ifndef CAN_WRAP_drain_zonestat
#   define CAN_WRAP_drain_zonestat 1
#endif
#if CAN_WRAP_drain_zonestat
    WRAP_FOR_DETACH(drain_zonestat)
#endif
#ifndef CAN_WRAP_unlock_page
#   define CAN_WRAP_unlock_page 1
#endif
#if CAN_WRAP_unlock_page
    WRAP_FOR_DETACH(unlock_page)
#endif
#ifndef CAN_WRAP_pci_enable_obff
#   define CAN_WRAP_pci_enable_obff 1
#endif
#if CAN_WRAP_pci_enable_obff
    WRAP_FOR_DETACH(pci_enable_obff)
#endif
#ifndef CAN_WRAP___smp_call_function_single
#   define CAN_WRAP___smp_call_function_single 1
#endif
#if CAN_WRAP___smp_call_function_single
#   ifdef DETACH_ADDR___smp_call_function_single
        WRAP_FOR_DETACH(__smp_call_function_single)
#   else
        TYPED_DETACH(__smp_call_function_single)
#   endif
#endif
#ifndef CAN_WRAP_module_param_sysfs_setup
#   define CAN_WRAP_module_param_sysfs_setup 1
#endif
#if CAN_WRAP_module_param_sysfs_setup
    WRAP_FOR_DETACH(module_param_sysfs_setup)
#endif
#ifndef CAN_WRAP_kthread_parkme
#   define CAN_WRAP_kthread_parkme 0
#endif
DETACH(kthread_parkme)
#ifndef CAN_WRAP_arch_uprobe_xol_was_trapped
#   define CAN_WRAP_arch_uprobe_xol_was_trapped 1
#endif
#if CAN_WRAP_arch_uprobe_xol_was_trapped
    WRAP_FOR_DETACH(arch_uprobe_xol_was_trapped)
#endif
#ifndef CAN_WRAP_set_user_nice
#   define CAN_WRAP_set_user_nice 1
#endif
#if CAN_WRAP_set_user_nice
    WRAP_FOR_DETACH(set_user_nice)
#endif
#ifndef CAN_WRAP_sg_miter_next
#   define CAN_WRAP_sg_miter_next 1
#endif
#if CAN_WRAP_sg_miter_next
    WRAP_FOR_DETACH(sg_miter_next)
#endif
#ifndef CAN_WRAP_nlmsg_notify
#   define CAN_WRAP_nlmsg_notify 1
#endif
#if CAN_WRAP_nlmsg_notify
    WRAP_FOR_DETACH(nlmsg_notify)
#endif
#ifndef CAN_WRAP_wrmsr_on_cpus
#   define CAN_WRAP_wrmsr_on_cpus 1
#endif
#if CAN_WRAP_wrmsr_on_cpus
    WRAP_FOR_DETACH(wrmsr_on_cpus)
#endif
#ifndef CAN_WRAP_commit_creds
#   define CAN_WRAP_commit_creds 1
#endif
#if CAN_WRAP_commit_creds
    WRAP_FOR_DETACH(commit_creds)
#endif
#ifndef CAN_WRAP_compat_sys_setitimer
#   define CAN_WRAP_compat_sys_setitimer 1
#endif
#if CAN_WRAP_compat_sys_setitimer
    WRAP_FOR_DETACH(compat_sys_setitimer)
#endif
#ifndef CAN_WRAP_block_truncate_page
#   define CAN_WRAP_block_truncate_page 1
#endif
#if CAN_WRAP_block_truncate_page
    WRAP_FOR_DETACH(block_truncate_page)
#endif
#ifndef CAN_WRAP_page_swap_info
#   define CAN_WRAP_page_swap_info 1
#endif
#if CAN_WRAP_page_swap_info
    WRAP_FOR_DETACH(page_swap_info)
#endif
#ifndef CAN_WRAP_pmdp_test_and_clear_young
#   define CAN_WRAP_pmdp_test_and_clear_young 1
#endif
#if CAN_WRAP_pmdp_test_and_clear_young
    WRAP_FOR_DETACH(pmdp_test_and_clear_young)
#endif
#ifndef CAN_WRAP_qdisc_list_del
#   define CAN_WRAP_qdisc_list_del 1
#endif
#if CAN_WRAP_qdisc_list_del
    WRAP_FOR_DETACH(qdisc_list_del)
#endif
#ifndef CAN_WRAP_compat_sys_pwritev
#   define CAN_WRAP_compat_sys_pwritev 1
#endif
#if CAN_WRAP_compat_sys_pwritev
    WRAP_FOR_DETACH(compat_sys_pwritev)
#endif
#ifndef CAN_WRAP_pcibios_scan_root
#   define CAN_WRAP_pcibios_scan_root 1
#endif
#if CAN_WRAP_pcibios_scan_root
    WRAP_FOR_DETACH(pcibios_scan_root)
#endif
#ifndef CAN_WRAP_do_gettimeofday
#   define CAN_WRAP_do_gettimeofday 1
#endif
#if CAN_WRAP_do_gettimeofday
    WRAP_FOR_DETACH(do_gettimeofday)
#endif
#ifndef CAN_WRAP_vmemmap_pmd_populate
#   define CAN_WRAP_vmemmap_pmd_populate 1
#endif
#if CAN_WRAP_vmemmap_pmd_populate
    WRAP_FOR_DETACH(vmemmap_pmd_populate)
#endif
#ifndef CAN_WRAP_smp_reschedule_interrupt
#   define CAN_WRAP_smp_reschedule_interrupt 1
#endif
#if CAN_WRAP_smp_reschedule_interrupt
    WRAP_FOR_DETACH(smp_reschedule_interrupt)
#endif
#ifndef CAN_WRAP_wrmsr_on_cpu
#   define CAN_WRAP_wrmsr_on_cpu 0
#endif
DETACH(wrmsr_on_cpu)
#ifndef CAN_WRAP_flow_cache_lookup
#   define CAN_WRAP_flow_cache_lookup 1
#endif
#if CAN_WRAP_flow_cache_lookup
    WRAP_FOR_DETACH(flow_cache_lookup)
#endif
#ifndef CAN_WRAP_acpi_table_parse_entries
#   define CAN_WRAP_acpi_table_parse_entries 1
#endif
#if CAN_WRAP_acpi_table_parse_entries
    WRAP_FOR_DETACH(acpi_table_parse_entries)
#endif
#ifndef CAN_WRAP_netif_device_detach
#   define CAN_WRAP_netif_device_detach 1
#endif
#if CAN_WRAP_netif_device_detach
    WRAP_FOR_DETACH(netif_device_detach)
#endif
#ifndef CAN_WRAP_blk_alloc_devt
#   define CAN_WRAP_blk_alloc_devt 1
#endif
#if CAN_WRAP_blk_alloc_devt
    WRAP_FOR_DETACH(blk_alloc_devt)
#endif
#ifndef CAN_WRAP_proc_net_remove
#   define CAN_WRAP_proc_net_remove 1
#endif
#if CAN_WRAP_proc_net_remove
    WRAP_FOR_DETACH(proc_net_remove)
#endif
#ifndef CAN_WRAP__copy_from_user
#   define CAN_WRAP__copy_from_user 0
#endif
DETACH(_copy_from_user)
#ifndef CAN_WRAP_kernel_getsockname
#   define CAN_WRAP_kernel_getsockname 1
#endif
#if CAN_WRAP_kernel_getsockname
    WRAP_FOR_DETACH(kernel_getsockname)
#endif
#ifndef CAN_WRAP_sg_free_table
#   define CAN_WRAP_sg_free_table 1
#endif
#if CAN_WRAP_sg_free_table
    WRAP_FOR_DETACH(sg_free_table)
#endif
#ifndef CAN_WRAP_kobj_ns_type_registered
#   define CAN_WRAP_kobj_ns_type_registered 0
#endif
DETACH(kobj_ns_type_registered)
#ifndef CAN_WRAP___account_scheduler_latency
#   define CAN_WRAP___account_scheduler_latency 1
#endif
#if CAN_WRAP___account_scheduler_latency
#   ifdef DETACH_ADDR___account_scheduler_latency
        WRAP_FOR_DETACH(__account_scheduler_latency)
#   else
        TYPED_DETACH(__account_scheduler_latency)
#   endif
#endif
#ifndef CAN_WRAP_idr_pre_get
#   define CAN_WRAP_idr_pre_get 1
#endif
#if CAN_WRAP_idr_pre_get
    WRAP_FOR_DETACH(idr_pre_get)
#endif
#ifndef CAN_WRAP_jbd2_journal_file_buffer
#   define CAN_WRAP_jbd2_journal_file_buffer 1
#endif
#if CAN_WRAP_jbd2_journal_file_buffer
    WRAP_FOR_DETACH(jbd2_journal_file_buffer)
#endif
#ifndef CAN_WRAP_unregister_node
#   define CAN_WRAP_unregister_node 1
#endif
#if CAN_WRAP_unregister_node
    WRAP_FOR_DETACH(unregister_node)
#endif
#ifndef CAN_WRAP_ata_host_activate
#   define CAN_WRAP_ata_host_activate 1
#endif
#if CAN_WRAP_ata_host_activate
    WRAP_FOR_DETACH(ata_host_activate)
#endif
#ifndef CAN_WRAP___alloc_skb
#   define CAN_WRAP___alloc_skb 1
#endif
#if CAN_WRAP___alloc_skb
#   ifdef DETACH_ADDR___alloc_skb
        WRAP_FOR_DETACH(__alloc_skb)
#   else
        TYPED_DETACH(__alloc_skb)
#   endif
#endif
#ifndef CAN_WRAP_vmalloc_exec
#   define CAN_WRAP_vmalloc_exec 0
#endif
DETACH(vmalloc_exec)
#ifndef CAN_WRAP___bdi_update_bandwidth
#   define CAN_WRAP___bdi_update_bandwidth 1
#endif
#if CAN_WRAP___bdi_update_bandwidth
#   ifdef DETACH_ADDR___bdi_update_bandwidth
        WRAP_FOR_DETACH(__bdi_update_bandwidth)
#   else
        TYPED_DETACH(__bdi_update_bandwidth)
#   endif
#endif
#ifndef CAN_WRAP_add_page_wait_queue
#   define CAN_WRAP_add_page_wait_queue 1
#endif
#if CAN_WRAP_add_page_wait_queue
    WRAP_FOR_DETACH(add_page_wait_queue)
#endif
#ifndef CAN_WRAP_sk_common_release
#   define CAN_WRAP_sk_common_release 1
#endif
#if CAN_WRAP_sk_common_release
    WRAP_FOR_DETACH(sk_common_release)
#endif
#ifndef CAN_WRAP_task_prio
#   define CAN_WRAP_task_prio 1
#endif
#if CAN_WRAP_task_prio
    WRAP_FOR_DETACH(task_prio)
#endif
#ifndef CAN_WRAP_bvec_nr_vecs
#   define CAN_WRAP_bvec_nr_vecs 0
#endif
DETACH(bvec_nr_vecs)
#ifndef CAN_WRAP_security_inode_symlink
#   define CAN_WRAP_security_inode_symlink 1
#endif
#if CAN_WRAP_security_inode_symlink
    WRAP_FOR_DETACH(security_inode_symlink)
#endif
#ifndef CAN_WRAP_default_banner
#   define CAN_WRAP_default_banner 0
#endif
DETACH(default_banner)
#ifndef CAN_WRAP_enable_x2apic
#   define CAN_WRAP_enable_x2apic 0
#endif
DETACH(enable_x2apic)
#ifndef CAN_WRAP_switch_task_namespaces
#   define CAN_WRAP_switch_task_namespaces 1
#endif
#if CAN_WRAP_switch_task_namespaces
    WRAP_FOR_DETACH(switch_task_namespaces)
#endif
#ifndef CAN_WRAP_sk_stream_wait_close
#   define CAN_WRAP_sk_stream_wait_close 1
#endif
#if CAN_WRAP_sk_stream_wait_close
    WRAP_FOR_DETACH(sk_stream_wait_close)
#endif
#ifndef CAN_WRAP_driver_register
#   define CAN_WRAP_driver_register 1
#endif
#if CAN_WRAP_driver_register
    WRAP_FOR_DETACH(driver_register)
#endif
#ifndef CAN_WRAP_rwsem_wake
#   define CAN_WRAP_rwsem_wake 1
#endif
#if CAN_WRAP_rwsem_wake
    WRAP_FOR_DETACH(rwsem_wake)
#endif
#ifndef CAN_WRAP_genphy_resume
#   define CAN_WRAP_genphy_resume 1
#endif
#if CAN_WRAP_genphy_resume
    WRAP_FOR_DETACH(genphy_resume)
#endif
#ifndef CAN_WRAP_clocksource_get_next
#   define CAN_WRAP_clocksource_get_next 1
#endif
#if CAN_WRAP_clocksource_get_next
    WRAP_FOR_DETACH(clocksource_get_next)
#endif
#ifndef CAN_WRAP_bio_check_pages_dirty
#   define CAN_WRAP_bio_check_pages_dirty 1
#endif
#if CAN_WRAP_bio_check_pages_dirty
    WRAP_FOR_DETACH(bio_check_pages_dirty)
#endif
#ifndef CAN_WRAP_security_sb_umount
#   define CAN_WRAP_security_sb_umount 1
#endif
#if CAN_WRAP_security_sb_umount
    WRAP_FOR_DETACH(security_sb_umount)
#endif
#ifndef CAN_WRAP_is_vma_temporary_stack
#   define CAN_WRAP_is_vma_temporary_stack 1
#endif
#if CAN_WRAP_is_vma_temporary_stack
    WRAP_FOR_DETACH(is_vma_temporary_stack)
#endif
#ifndef CAN_WRAP_pci_set_master
#   define CAN_WRAP_pci_set_master 1
#endif
#if CAN_WRAP_pci_set_master
    WRAP_FOR_DETACH(pci_set_master)
#endif
#ifndef CAN_WRAP_sata_link_hardreset
#   define CAN_WRAP_sata_link_hardreset 1
#endif
#if CAN_WRAP_sata_link_hardreset
    WRAP_FOR_DETACH(sata_link_hardreset)
#endif
#ifndef CAN_WRAP_textsearch_destroy
#   define CAN_WRAP_textsearch_destroy 1
#endif
#if CAN_WRAP_textsearch_destroy
    WRAP_FOR_DETACH(textsearch_destroy)
#endif
#ifndef CAN_WRAP_set_memory_4k
#   define CAN_WRAP_set_memory_4k 0
#endif
DETACH(set_memory_4k)
#ifndef CAN_WRAP_scsi_is_host_device
#   define CAN_WRAP_scsi_is_host_device 1
#endif
#if CAN_WRAP_scsi_is_host_device
    WRAP_FOR_DETACH(scsi_is_host_device)
#endif
#ifndef CAN_WRAP_zone_watermark_ok
#   define CAN_WRAP_zone_watermark_ok 1
#endif
#if CAN_WRAP_zone_watermark_ok
    WRAP_FOR_DETACH(zone_watermark_ok)
#endif
#ifndef CAN_WRAP_copy_siginfo_to_user32
#   define CAN_WRAP_copy_siginfo_to_user32 1
#endif
#if CAN_WRAP_copy_siginfo_to_user32
    WRAP_FOR_DETACH(copy_siginfo_to_user32)
#endif
#ifndef CAN_WRAP___block_page_mkwrite
#   define CAN_WRAP___block_page_mkwrite 1
#endif
#if CAN_WRAP___block_page_mkwrite
#   ifdef DETACH_ADDR___block_page_mkwrite
        WRAP_FOR_DETACH(__block_page_mkwrite)
#   else
        TYPED_DETACH(__block_page_mkwrite)
#   endif
#endif
#ifndef CAN_WRAP_reserve_top_address
#   define CAN_WRAP_reserve_top_address 0
#endif
DETACH(reserve_top_address)
#ifndef CAN_WRAP_bitmap_copy_le
#   define CAN_WRAP_bitmap_copy_le 0
#endif
DETACH(bitmap_copy_le)
#ifndef CAN_WRAP_cap_capget
#   define CAN_WRAP_cap_capget 1
#endif
#if CAN_WRAP_cap_capget
    WRAP_FOR_DETACH(cap_capget)
#endif
#ifndef CAN_WRAP_mdiobus_alloc_size
#   define CAN_WRAP_mdiobus_alloc_size 1
#endif
#if CAN_WRAP_mdiobus_alloc_size
    WRAP_FOR_DETACH(mdiobus_alloc_size)
#endif
#ifndef CAN_WRAP_sort_range
#   define CAN_WRAP_sort_range 1
#endif
#if CAN_WRAP_sort_range
    WRAP_FOR_DETACH(sort_range)
#endif
#ifndef CAN_WRAP_read_swap_cache_async
#   define CAN_WRAP_read_swap_cache_async 1
#endif
#if CAN_WRAP_read_swap_cache_async
    WRAP_FOR_DETACH(read_swap_cache_async)
#endif
#ifndef CAN_WRAP_I_BDEV
#   define CAN_WRAP_I_BDEV 1
#endif
#if CAN_WRAP_I_BDEV
    WRAP_FOR_DETACH(I_BDEV)
#endif
#ifndef CAN_WRAP_rcu_irq_enter
#   define CAN_WRAP_rcu_irq_enter 0
#endif
DETACH(rcu_irq_enter)
#ifndef CAN_WRAP___modver_version_show
#   define CAN_WRAP___modver_version_show 1
#endif
#if CAN_WRAP___modver_version_show
#   ifdef DETACH_ADDR___modver_version_show
        WRAP_FOR_DETACH(__modver_version_show)
#   else
        TYPED_DETACH(__modver_version_show)
#   endif
#endif
#ifndef CAN_WRAP_device_find_child
#   define CAN_WRAP_device_find_child 1
#endif
#if CAN_WRAP_device_find_child
    WRAP_FOR_DETACH(device_find_child)
#endif
#ifndef CAN_WRAP_jbd2_journal_get_write_access
#   define CAN_WRAP_jbd2_journal_get_write_access 1
#endif
#if CAN_WRAP_jbd2_journal_get_write_access
    WRAP_FOR_DETACH(jbd2_journal_get_write_access)
#endif
#ifndef CAN_WRAP_css_lookup
#   define CAN_WRAP_css_lookup 1
#endif
#if CAN_WRAP_css_lookup
    WRAP_FOR_DETACH(css_lookup)
#endif
#ifndef CAN_WRAP_pid_task
#   define CAN_WRAP_pid_task 1
#endif
#if CAN_WRAP_pid_task
    WRAP_FOR_DETACH(pid_task)
#endif
#ifndef CAN_WRAP_native_cpu_die
#   define CAN_WRAP_native_cpu_die 0
#endif
DETACH(native_cpu_die)
#ifndef CAN_WRAP_dm_read_arg
#   define CAN_WRAP_dm_read_arg 1
#endif
#if CAN_WRAP_dm_read_arg
    WRAP_FOR_DETACH(dm_read_arg)
#endif
#ifndef CAN_WRAP_pcibios_add_device
#   define CAN_WRAP_pcibios_add_device 1
#endif
#if CAN_WRAP_pcibios_add_device
    WRAP_FOR_DETACH(pcibios_add_device)
#endif
#ifndef CAN_WRAP_acpi_read
#   define CAN_WRAP_acpi_read 1
#endif
#if CAN_WRAP_acpi_read
    WRAP_FOR_DETACH(acpi_read)
#endif
#ifndef CAN_WRAP_remap_pfn_range
#   define CAN_WRAP_remap_pfn_range 1
#endif
#if CAN_WRAP_remap_pfn_range
    WRAP_FOR_DETACH(remap_pfn_range)
#endif
#ifndef CAN_WRAP_mmput
#   define CAN_WRAP_mmput 1
#endif
#if CAN_WRAP_mmput
    WRAP_FOR_DETACH(mmput)
#endif
#ifndef CAN_WRAP__raw_read_unlock
#   define CAN_WRAP__raw_read_unlock 1
#endif
#if CAN_WRAP__raw_read_unlock
    WRAP_FOR_DETACH(_raw_read_unlock)
#endif
#ifndef CAN_WRAP_dev_pm_qos_remove_request
#   define CAN_WRAP_dev_pm_qos_remove_request 1
#endif
#if CAN_WRAP_dev_pm_qos_remove_request
    WRAP_FOR_DETACH(dev_pm_qos_remove_request)
#endif
#ifndef CAN_WRAP_apic_force_enable
#   define CAN_WRAP_apic_force_enable 0
#endif
DETACH(apic_force_enable)
#ifndef CAN_WRAP_ata_slave_link_init
#   define CAN_WRAP_ata_slave_link_init 1
#endif
#if CAN_WRAP_ata_slave_link_init
    WRAP_FOR_DETACH(ata_slave_link_init)
#endif
#ifndef CAN_WRAP_expand_downwards
#   define CAN_WRAP_expand_downwards 1
#endif
#if CAN_WRAP_expand_downwards
    WRAP_FOR_DETACH(expand_downwards)
#endif
#ifndef CAN_WRAP_compat_sys_rt_sigtimedwait
#   define CAN_WRAP_compat_sys_rt_sigtimedwait 1
#endif
#if CAN_WRAP_compat_sys_rt_sigtimedwait
    WRAP_FOR_DETACH(compat_sys_rt_sigtimedwait)
#endif
#ifndef CAN_WRAP_dquot_transfer
#   define CAN_WRAP_dquot_transfer 1
#endif
#if CAN_WRAP_dquot_transfer
    WRAP_FOR_DETACH(dquot_transfer)
#endif
#ifndef CAN_WRAP_netlink_attachskb
#   define CAN_WRAP_netlink_attachskb 1
#endif
#if CAN_WRAP_netlink_attachskb
    WRAP_FOR_DETACH(netlink_attachskb)
#endif
#ifndef CAN_WRAP_compat_sys_rt_sigsuspend
#   define CAN_WRAP_compat_sys_rt_sigsuspend 1
#endif
#if CAN_WRAP_compat_sys_rt_sigsuspend
    WRAP_FOR_DETACH(compat_sys_rt_sigsuspend)
#endif
#ifndef CAN_WRAP_proc_dowatchdog_thresh
#   define CAN_WRAP_proc_dowatchdog_thresh 1
#endif
#if CAN_WRAP_proc_dowatchdog_thresh
    WRAP_FOR_DETACH(proc_dowatchdog_thresh)
#endif
#ifndef CAN_WRAP_do_invalidatepage
#   define CAN_WRAP_do_invalidatepage 1
#endif
#if CAN_WRAP_do_invalidatepage
    WRAP_FOR_DETACH(do_invalidatepage)
#endif
#ifndef CAN_WRAP_ioread16
#   define CAN_WRAP_ioread16 0
#endif
DETACH(ioread16)
#ifndef CAN_WRAP_getnstimeofday
#   define CAN_WRAP_getnstimeofday 1
#endif
#if CAN_WRAP_getnstimeofday
    WRAP_FOR_DETACH(getnstimeofday)
#endif
#ifndef CAN_WRAP___vlan_find_dev_deep
#   define CAN_WRAP___vlan_find_dev_deep 1
#endif
#if CAN_WRAP___vlan_find_dev_deep
#   ifdef DETACH_ADDR___vlan_find_dev_deep
        WRAP_FOR_DETACH(__vlan_find_dev_deep)
#   else
        TYPED_DETACH(__vlan_find_dev_deep)
#   endif
#endif
#ifndef CAN_WRAP_linear_hugepage_index
#   define CAN_WRAP_linear_hugepage_index 1
#endif
#if CAN_WRAP_linear_hugepage_index
    WRAP_FOR_DETACH(linear_hugepage_index)
#endif
#ifndef CAN_WRAP_dev_pm_qos_add_ancestor_request
#   define CAN_WRAP_dev_pm_qos_add_ancestor_request 1
#endif
#if CAN_WRAP_dev_pm_qos_add_ancestor_request
    WRAP_FOR_DETACH(dev_pm_qos_add_ancestor_request)
#endif
#ifndef CAN_WRAP_sock_create_lite
#   define CAN_WRAP_sock_create_lite 0
#endif
DETACH(sock_create_lite)
#ifndef CAN_WRAP_pvclock_read_wallclock
#   define CAN_WRAP_pvclock_read_wallclock 1
#endif
#if CAN_WRAP_pvclock_read_wallclock
    WRAP_FOR_DETACH(pvclock_read_wallclock)
#endif
#ifndef CAN_WRAP_end_local_APIC_setup
#   define CAN_WRAP_end_local_APIC_setup 0
#endif
DETACH(end_local_APIC_setup)
#ifndef CAN_WRAP_acpi_release_global_lock
#   define CAN_WRAP_acpi_release_global_lock 0
#endif
DETACH(acpi_release_global_lock)
#ifndef CAN_WRAP_getrusage
#   define CAN_WRAP_getrusage 1
#endif
#if CAN_WRAP_getrusage
    WRAP_FOR_DETACH(getrusage)
#endif
#ifndef CAN_WRAP_match_hex
#   define CAN_WRAP_match_hex 1
#endif
#if CAN_WRAP_match_hex
    WRAP_FOR_DETACH(match_hex)
#endif
#ifndef CAN_WRAP_init_VISWS_APIC_irqs
#   define CAN_WRAP_init_VISWS_APIC_irqs 0
#endif
DETACH(init_VISWS_APIC_irqs)
#ifndef CAN_WRAP_phy_ethtool_gset
#   define CAN_WRAP_phy_ethtool_gset 1
#endif
#if CAN_WRAP_phy_ethtool_gset
    WRAP_FOR_DETACH(phy_ethtool_gset)
#endif
#ifndef CAN_WRAP_percpu_counter_compare
#   define CAN_WRAP_percpu_counter_compare 1
#endif
#if CAN_WRAP_percpu_counter_compare
    WRAP_FOR_DETACH(percpu_counter_compare)
#endif
#ifndef CAN_WRAP_bio_add_page
#   define CAN_WRAP_bio_add_page 1
#endif
#if CAN_WRAP_bio_add_page
    WRAP_FOR_DETACH(bio_add_page)
#endif
#ifndef CAN_WRAP_queue_work_on
#   define CAN_WRAP_queue_work_on 1
#endif
#if CAN_WRAP_queue_work_on
    WRAP_FOR_DETACH(queue_work_on)
#endif
#ifndef CAN_WRAP_put_io_context_active
#   define CAN_WRAP_put_io_context_active 1
#endif
#if CAN_WRAP_put_io_context_active
    WRAP_FOR_DETACH(put_io_context_active)
#endif
#ifndef CAN_WRAP_acpi_get_table
#   define CAN_WRAP_acpi_get_table 0
#endif
DETACH(acpi_get_table)
#ifndef CAN_WRAP_add_to_page_cache_locked
#   define CAN_WRAP_add_to_page_cache_locked 1
#endif
#if CAN_WRAP_add_to_page_cache_locked
    WRAP_FOR_DETACH(add_to_page_cache_locked)
#endif
#ifndef CAN_WRAP_usemap_size
#   define CAN_WRAP_usemap_size 0
#endif
DETACH(usemap_size)
#ifndef CAN_WRAP_zone_watermark_ok_safe
#   define CAN_WRAP_zone_watermark_ok_safe 1
#endif
#if CAN_WRAP_zone_watermark_ok_safe
    WRAP_FOR_DETACH(zone_watermark_ok_safe)
#endif
#ifndef CAN_WRAP_unregister_sysctl_table
#   define CAN_WRAP_unregister_sysctl_table 1
#endif
#if CAN_WRAP_unregister_sysctl_table
    WRAP_FOR_DETACH(unregister_sysctl_table)
#endif
#ifndef CAN_WRAP_compat_sys_utime
#   define CAN_WRAP_compat_sys_utime 1
#endif
#if CAN_WRAP_compat_sys_utime
    WRAP_FOR_DETACH(compat_sys_utime)
#endif
#ifndef CAN_WRAP_dev_init_scheduler
#   define CAN_WRAP_dev_init_scheduler 1
#endif
#if CAN_WRAP_dev_init_scheduler
    WRAP_FOR_DETACH(dev_init_scheduler)
#endif
#ifndef CAN_WRAP_compat_sys_signalfd
#   define CAN_WRAP_compat_sys_signalfd 1
#endif
#if CAN_WRAP_compat_sys_signalfd
    WRAP_FOR_DETACH(compat_sys_signalfd)
#endif
#ifndef CAN_WRAP_tag_pages_for_writeback
#   define CAN_WRAP_tag_pages_for_writeback 1
#endif
#if CAN_WRAP_tag_pages_for_writeback
    WRAP_FOR_DETACH(tag_pages_for_writeback)
#endif
#ifndef CAN_WRAP_dst_init
#   define CAN_WRAP_dst_init 0
#endif
DETACH(dst_init)
#ifndef CAN_WRAP_iowrite32
#   define CAN_WRAP_iowrite32 0
#endif
DETACH(iowrite32)
#ifndef CAN_WRAP_acpi_pm_device_run_wake
#   define CAN_WRAP_acpi_pm_device_run_wake 1
#endif
#if CAN_WRAP_acpi_pm_device_run_wake
    WRAP_FOR_DETACH(acpi_pm_device_run_wake)
#endif
#ifndef CAN_WRAP_find_symbol
#   define CAN_WRAP_find_symbol 1
#endif
#if CAN_WRAP_find_symbol
    WRAP_FOR_DETACH(find_symbol)
#endif
#ifndef CAN_WRAP_acpi_install_table_handler
#   define CAN_WRAP_acpi_install_table_handler 1
#endif
#if CAN_WRAP_acpi_install_table_handler
    WRAP_FOR_DETACH(acpi_install_table_handler)
#endif
#ifndef CAN_WRAP___bad_uid
#   define CAN_WRAP___bad_uid 0
#endif
DETACH(__bad_uid)
#ifndef CAN_WRAP_can_request_irq
#   define CAN_WRAP_can_request_irq 0
#endif
DETACH(can_request_irq)
#ifndef CAN_WRAP_bio_copy_kern
#   define CAN_WRAP_bio_copy_kern 1
#endif
#if CAN_WRAP_bio_copy_kern
    WRAP_FOR_DETACH(bio_copy_kern)
#endif
#ifndef CAN_WRAP___elv_add_request
#   define CAN_WRAP___elv_add_request 1
#endif
#if CAN_WRAP___elv_add_request
#   ifdef DETACH_ADDR___elv_add_request
        WRAP_FOR_DETACH(__elv_add_request)
#   else
        TYPED_DETACH(__elv_add_request)
#   endif
#endif
#ifndef CAN_WRAP__raw_spin_lock_nest_lock
#   define CAN_WRAP__raw_spin_lock_nest_lock 1
#endif
#if CAN_WRAP__raw_spin_lock_nest_lock
    WRAP_FOR_DETACH(_raw_spin_lock_nest_lock)
#endif
#ifndef CAN_WRAP_acpi_dev_resource_ext_address_space
#   define CAN_WRAP_acpi_dev_resource_ext_address_space 1
#endif
#if CAN_WRAP_acpi_dev_resource_ext_address_space
    WRAP_FOR_DETACH(acpi_dev_resource_ext_address_space)
#endif
#ifndef CAN_WRAP_ktime_get
#   define CAN_WRAP_ktime_get 0
#endif
DETACH(ktime_get)
#ifndef CAN_WRAP_create_irq_nr
#   define CAN_WRAP_create_irq_nr 0
#endif
DETACH(create_irq_nr)
#ifndef CAN_WRAP__raw_write_trylock
#   define CAN_WRAP__raw_write_trylock 1
#endif
#if CAN_WRAP__raw_write_trylock
    WRAP_FOR_DETACH(_raw_write_trylock)
#endif
#ifndef CAN_WRAP_blk_integrity_compare
#   define CAN_WRAP_blk_integrity_compare 1
#endif
#if CAN_WRAP_blk_integrity_compare
    WRAP_FOR_DETACH(blk_integrity_compare)
#endif
#ifndef CAN_WRAP_wrmsr_safe_regs
#   define CAN_WRAP_wrmsr_safe_regs 0
#endif
DETACH(wrmsr_safe_regs)
#ifndef CAN_WRAP_csum_partial_copy_generic
#   define CAN_WRAP_csum_partial_copy_generic 0
#endif
DETACH(csum_partial_copy_generic)
#ifndef CAN_WRAP_ata_scsi_ioctl
#   define CAN_WRAP_ata_scsi_ioctl 1
#endif
#if CAN_WRAP_ata_scsi_ioctl
    WRAP_FOR_DETACH(ata_scsi_ioctl)
#endif
#ifndef CAN_WRAP_bdi_writeback_thread
#   define CAN_WRAP_bdi_writeback_thread 0
#endif
DETACH(bdi_writeback_thread)
#ifndef CAN_WRAP_walk_page_range
#   define CAN_WRAP_walk_page_range 1
#endif
#if CAN_WRAP_walk_page_range
    WRAP_FOR_DETACH(walk_page_range)
#endif
#ifndef CAN_WRAP_set_dma_reserve
#   define CAN_WRAP_set_dma_reserve 0
#endif
DETACH(set_dma_reserve)
#ifndef CAN_WRAP_dcb_ieee_setapp
#   define CAN_WRAP_dcb_ieee_setapp 1
#endif
#if CAN_WRAP_dcb_ieee_setapp
    WRAP_FOR_DETACH(dcb_ieee_setapp)
#endif
#ifndef CAN_WRAP_qtree_release_dquot
#   define CAN_WRAP_qtree_release_dquot 1
#endif
#if CAN_WRAP_qtree_release_dquot
    WRAP_FOR_DETACH(qtree_release_dquot)
#endif
#ifndef CAN_WRAP_device_release_driver
#   define CAN_WRAP_device_release_driver 1
#endif
#if CAN_WRAP_device_release_driver
    WRAP_FOR_DETACH(device_release_driver)
#endif
#ifndef CAN_WRAP_security_netlink_send
#   define CAN_WRAP_security_netlink_send 1
#endif
#if CAN_WRAP_security_netlink_send
    WRAP_FOR_DETACH(security_netlink_send)
#endif
#ifndef CAN_WRAP_delete_from_swap_cache
#   define CAN_WRAP_delete_from_swap_cache 1
#endif
#if CAN_WRAP_delete_from_swap_cache
    WRAP_FOR_DETACH(delete_from_swap_cache)
#endif
#ifndef CAN_WRAP_netif_get_num_default_rss_queues
#   define CAN_WRAP_netif_get_num_default_rss_queues 0
#endif
DETACH(netif_get_num_default_rss_queues)
#ifndef CAN_WRAP_pci_acs_enabled
#   define CAN_WRAP_pci_acs_enabled 1
#endif
#if CAN_WRAP_pci_acs_enabled
    WRAP_FOR_DETACH(pci_acs_enabled)
#endif
#ifndef CAN_WRAP_security_file_set_fowner
#   define CAN_WRAP_security_file_set_fowner 1
#endif
#if CAN_WRAP_security_file_set_fowner
    WRAP_FOR_DETACH(security_file_set_fowner)
#endif
#ifndef CAN_WRAP_skb_gso_segment
#   define CAN_WRAP_skb_gso_segment 1
#endif
#if CAN_WRAP_skb_gso_segment
    WRAP_FOR_DETACH(skb_gso_segment)
#endif
#ifndef CAN_WRAP_net_dma_find_channel
#   define CAN_WRAP_net_dma_find_channel 1
#endif
#if CAN_WRAP_net_dma_find_channel
    WRAP_FOR_DETACH(net_dma_find_channel)
#endif
#ifndef CAN_WRAP_bpf_jit_compile
#   define CAN_WRAP_bpf_jit_compile 1
#endif
#if CAN_WRAP_bpf_jit_compile
    WRAP_FOR_DETACH(bpf_jit_compile)
#endif
#ifndef CAN_WRAP_pmdp_clear_flush_young
#   define CAN_WRAP_pmdp_clear_flush_young 1
#endif
#if CAN_WRAP_pmdp_clear_flush_young
    WRAP_FOR_DETACH(pmdp_clear_flush_young)
#endif
#ifndef CAN_WRAP_clockevents_set_mode
#   define CAN_WRAP_clockevents_set_mode 1
#endif
#if CAN_WRAP_clockevents_set_mode
    WRAP_FOR_DETACH(clockevents_set_mode)
#endif
#ifndef CAN_WRAP__raw_read_unlock_irqrestore
#   define CAN_WRAP__raw_read_unlock_irqrestore 1
#endif
#if CAN_WRAP__raw_read_unlock_irqrestore
    WRAP_FOR_DETACH(_raw_read_unlock_irqrestore)
#endif
#ifndef CAN_WRAP_get_task_cred
#   define CAN_WRAP_get_task_cred 1
#endif
#if CAN_WRAP_get_task_cred
    WRAP_FOR_DETACH(get_task_cred)
#endif
#ifndef CAN_WRAP_proto_unregister
#   define CAN_WRAP_proto_unregister 1
#endif
#if CAN_WRAP_proto_unregister
    WRAP_FOR_DETACH(proto_unregister)
#endif
#ifndef CAN_WRAP_nobh_write_begin
#   define CAN_WRAP_nobh_write_begin 1
#endif
#if CAN_WRAP_nobh_write_begin
    WRAP_FOR_DETACH(nobh_write_begin)
#endif
#ifndef CAN_WRAP_simple_strtol
#   define CAN_WRAP_simple_strtol 0
#endif
DETACH(simple_strtol)
#ifndef CAN_WRAP_strcpy
#   define CAN_WRAP_strcpy 0
#endif
DETACH(strcpy)
#ifndef CAN_WRAP_do_send_sig_info
#   define CAN_WRAP_do_send_sig_info 1
#endif
#if CAN_WRAP_do_send_sig_info
    WRAP_FOR_DETACH(do_send_sig_info)
#endif
#ifndef CAN_WRAP_vma_adjust
#   define CAN_WRAP_vma_adjust 1
#endif
#if CAN_WRAP_vma_adjust
    WRAP_FOR_DETACH(vma_adjust)
#endif
#ifndef CAN_WRAP_kfree_call_rcu
#   define CAN_WRAP_kfree_call_rcu 1
#endif
#if CAN_WRAP_kfree_call_rcu
    WRAP_FOR_DETACH(kfree_call_rcu)
#endif
#ifndef CAN_WRAP_release_task
#   define CAN_WRAP_release_task 1
#endif
#if CAN_WRAP_release_task
    WRAP_FOR_DETACH(release_task)
#endif
#ifndef CAN_WRAP_dev_mcast_init
#   define CAN_WRAP_dev_mcast_init 0
#endif
DETACH(dev_mcast_init)
#ifndef CAN_WRAP_netif_rx_ni
#   define CAN_WRAP_netif_rx_ni 1
#endif
#if CAN_WRAP_netif_rx_ni
    WRAP_FOR_DETACH(netif_rx_ni)
#endif
#ifndef CAN_WRAP_early_reserve_e820
#   define CAN_WRAP_early_reserve_e820 0
#endif
DETACH(early_reserve_e820)
#ifndef CAN_WRAP___blk_put_request
#   define CAN_WRAP___blk_put_request 1
#endif
#if CAN_WRAP___blk_put_request
#   ifdef DETACH_ADDR___blk_put_request
        WRAP_FOR_DETACH(__blk_put_request)
#   else
        TYPED_DETACH(__blk_put_request)
#   endif
#endif
#ifndef CAN_WRAP_dst_release
#   define CAN_WRAP_dst_release 1
#endif
#if CAN_WRAP_dst_release
    WRAP_FOR_DETACH(dst_release)
#endif
#ifndef CAN_WRAP_disable_percpu_irq
#   define CAN_WRAP_disable_percpu_irq 0
#endif
DETACH(disable_percpu_irq)
#ifndef CAN_WRAP_dquot_commit
#   define CAN_WRAP_dquot_commit 1
#endif
#if CAN_WRAP_dquot_commit
    WRAP_FOR_DETACH(dquot_commit)
#endif
#ifndef CAN_WRAP_acpi_remove_dir
#   define CAN_WRAP_acpi_remove_dir 1
#endif
#if CAN_WRAP_acpi_remove_dir
    WRAP_FOR_DETACH(acpi_remove_dir)
#endif
#ifndef CAN_WRAP_initmem_init
#   define CAN_WRAP_initmem_init 0
#endif
DETACH(initmem_init)
#ifndef CAN_WRAP_do_sys_times
#   define CAN_WRAP_do_sys_times 1
#endif
#if CAN_WRAP_do_sys_times
    WRAP_FOR_DETACH(do_sys_times)
#endif
#ifndef CAN_WRAP___clocksource_register_scale
#   define CAN_WRAP___clocksource_register_scale 1
#endif
#if CAN_WRAP___clocksource_register_scale
#   ifdef DETACH_ADDR___clocksource_register_scale
        WRAP_FOR_DETACH(__clocksource_register_scale)
#   else
        TYPED_DETACH(__clocksource_register_scale)
#   endif
#endif
#ifndef CAN_WRAP_get_user_pages
#   define CAN_WRAP_get_user_pages 1
#endif
#if CAN_WRAP_get_user_pages
    WRAP_FOR_DETACH(get_user_pages)
#endif
#ifndef CAN_WRAP_set_memory_array_wc
#   define CAN_WRAP_set_memory_array_wc 0
#endif
DETACH(set_memory_array_wc)
#ifndef CAN_WRAP_set_memory_array_wb
#   define CAN_WRAP_set_memory_array_wb 0
#endif
DETACH(set_memory_array_wb)
#ifndef CAN_WRAP_flush_scheduled_work
#   define CAN_WRAP_flush_scheduled_work 0
#endif
DETACH(flush_scheduled_work)
#ifndef CAN_WRAP_inet_proto_csum_replace4
#   define CAN_WRAP_inet_proto_csum_replace4 1
#endif
#if CAN_WRAP_inet_proto_csum_replace4
    WRAP_FOR_DETACH(inet_proto_csum_replace4)
#endif
#ifndef CAN_WRAP_ata_sff_thaw
#   define CAN_WRAP_ata_sff_thaw 1
#endif
#if CAN_WRAP_ata_sff_thaw
    WRAP_FOR_DETACH(ata_sff_thaw)
#endif
#ifndef CAN_WRAP_inode_sb_list_add
#   define CAN_WRAP_inode_sb_list_add 1
#endif
#if CAN_WRAP_inode_sb_list_add
    WRAP_FOR_DETACH(inode_sb_list_add)
#endif
#ifndef CAN_WRAP_disk_flush_events
#   define CAN_WRAP_disk_flush_events 1
#endif
#if CAN_WRAP_disk_flush_events
    WRAP_FOR_DETACH(disk_flush_events)
#endif
#ifndef CAN_WRAP_node_to_pxm
#   define CAN_WRAP_node_to_pxm 0
#endif
DETACH(node_to_pxm)
#ifndef CAN_WRAP_srcu_notifier_chain_unregister
#   define CAN_WRAP_srcu_notifier_chain_unregister 1
#endif
#if CAN_WRAP_srcu_notifier_chain_unregister
    WRAP_FOR_DETACH(srcu_notifier_chain_unregister)
#endif
#ifndef CAN_WRAP_security_path_rmdir
#   define CAN_WRAP_security_path_rmdir 1
#endif
#if CAN_WRAP_security_path_rmdir
    WRAP_FOR_DETACH(security_path_rmdir)
#endif
#ifndef CAN_WRAP_pci_aer_available
#   define CAN_WRAP_pci_aer_available 0
#endif
DETACH(pci_aer_available)
#ifndef CAN_WRAP___vmalloc
#   define CAN_WRAP___vmalloc 1
#endif
#if CAN_WRAP___vmalloc
#   ifdef DETACH_ADDR___vmalloc
        WRAP_FOR_DETACH(__vmalloc)
#   else
        TYPED_DETACH(__vmalloc)
#   endif
#endif
#ifndef CAN_WRAP_bus_sort_breadthfirst
#   define CAN_WRAP_bus_sort_breadthfirst 1
#endif
#if CAN_WRAP_bus_sort_breadthfirst
    WRAP_FOR_DETACH(bus_sort_breadthfirst)
#endif
#ifndef CAN_WRAP_strspn
#   define CAN_WRAP_strspn 0
#endif
DETACH(strspn)
#ifndef CAN_WRAP_abort_exclusive_wait
#   define CAN_WRAP_abort_exclusive_wait 1
#endif
#if CAN_WRAP_abort_exclusive_wait
    WRAP_FOR_DETACH(abort_exclusive_wait)
#endif
#ifndef CAN_WRAP_prandom_u32
#   define CAN_WRAP_prandom_u32 0
#endif
DETACH(prandom_u32)
#ifndef CAN_WRAP_pagefault_out_of_memory
#   define CAN_WRAP_pagefault_out_of_memory 0
#endif
DETACH(pagefault_out_of_memory)
#ifndef CAN_WRAP_skb_free_datagram
#   define CAN_WRAP_skb_free_datagram 1
#endif
#if CAN_WRAP_skb_free_datagram
    WRAP_FOR_DETACH(skb_free_datagram)
#endif
#ifndef CAN_WRAP_bdi_unregister
#   define CAN_WRAP_bdi_unregister 1
#endif
#if CAN_WRAP_bdi_unregister
    WRAP_FOR_DETACH(bdi_unregister)
#endif
#ifndef CAN_WRAP___wake_up_sync
#   define CAN_WRAP___wake_up_sync 1
#endif
#if CAN_WRAP___wake_up_sync
#   ifdef DETACH_ADDR___wake_up_sync
        WRAP_FOR_DETACH(__wake_up_sync)
#   else
        TYPED_DETACH(__wake_up_sync)
#   endif
#endif
#ifndef CAN_WRAP_do_no_restart_syscall
#   define CAN_WRAP_do_no_restart_syscall 1
#endif
#if CAN_WRAP_do_no_restart_syscall
    WRAP_FOR_DETACH(do_no_restart_syscall)
#endif
#ifndef CAN_WRAP_dm_set_mdptr
#   define CAN_WRAP_dm_set_mdptr 1
#endif
#if CAN_WRAP_dm_set_mdptr
    WRAP_FOR_DETACH(dm_set_mdptr)
#endif
#ifndef CAN_WRAP_blk_update_request
#   define CAN_WRAP_blk_update_request 1
#endif
#if CAN_WRAP_blk_update_request
    WRAP_FOR_DETACH(blk_update_request)
#endif
#ifndef CAN_WRAP_cdrom_get_last_written
#   define CAN_WRAP_cdrom_get_last_written 1
#endif
#if CAN_WRAP_cdrom_get_last_written
    WRAP_FOR_DETACH(cdrom_get_last_written)
#endif
#ifndef CAN_WRAP_get_task_io_context
#   define CAN_WRAP_get_task_io_context 1
#endif
#if CAN_WRAP_get_task_io_context
    WRAP_FOR_DETACH(get_task_io_context)
#endif
#ifndef CAN_WRAP_dequeue_signal
#   define CAN_WRAP_dequeue_signal 1
#endif
#if CAN_WRAP_dequeue_signal
    WRAP_FOR_DETACH(dequeue_signal)
#endif
#ifndef CAN_WRAP_ioread32be
#   define CAN_WRAP_ioread32be 0
#endif
DETACH(ioread32be)
#ifndef CAN_WRAP_acpi_mps_check
#   define CAN_WRAP_acpi_mps_check 0
#endif
DETACH(acpi_mps_check)
#ifndef CAN_WRAP_force_sigsegv
#   define CAN_WRAP_force_sigsegv 1
#endif
#if CAN_WRAP_force_sigsegv
    WRAP_FOR_DETACH(force_sigsegv)
#endif
#ifndef CAN_WRAP_mark_page_accessed
#   define CAN_WRAP_mark_page_accessed 1
#endif
#if CAN_WRAP_mark_page_accessed
    WRAP_FOR_DETACH(mark_page_accessed)
#endif
#ifndef CAN_WRAP___get_page_tail
#   define CAN_WRAP___get_page_tail 1
#endif
#if CAN_WRAP___get_page_tail
#   ifdef DETACH_ADDR___get_page_tail
        WRAP_FOR_DETACH(__get_page_tail)
#   else
        TYPED_DETACH(__get_page_tail)
#   endif
#endif
#ifndef CAN_WRAP_rcu_bh_qs
#   define CAN_WRAP_rcu_bh_qs 0
#endif
DETACH(rcu_bh_qs)
#ifndef CAN_WRAP_invalidate_mapping_pages
#   define CAN_WRAP_invalidate_mapping_pages 1
#endif
#if CAN_WRAP_invalidate_mapping_pages
    WRAP_FOR_DETACH(invalidate_mapping_pages)
#endif
#ifndef CAN_WRAP_write_boundary_block
#   define CAN_WRAP_write_boundary_block 1
#endif
#if CAN_WRAP_write_boundary_block
    WRAP_FOR_DETACH(write_boundary_block)
#endif
#ifndef CAN_WRAP_ddebug_add_module
#   define CAN_WRAP_ddebug_add_module 1
#endif
#if CAN_WRAP_ddebug_add_module
    WRAP_FOR_DETACH(ddebug_add_module)
#endif
#ifndef CAN_WRAP_prop_descriptor_init
#   define CAN_WRAP_prop_descriptor_init 1
#endif
#if CAN_WRAP_prop_descriptor_init
    WRAP_FOR_DETACH(prop_descriptor_init)
#endif
#ifndef CAN_WRAP_ata_sff_queue_delayed_work
#   define CAN_WRAP_ata_sff_queue_delayed_work 1
#endif
#if CAN_WRAP_ata_sff_queue_delayed_work
    WRAP_FOR_DETACH(ata_sff_queue_delayed_work)
#endif
#ifndef CAN_WRAP_set_posix_acl
#   define CAN_WRAP_set_posix_acl 1
#endif
#if CAN_WRAP_set_posix_acl
    WRAP_FOR_DETACH(set_posix_acl)
#endif
#ifndef CAN_WRAP_paravirt_start_context_switch
#   define CAN_WRAP_paravirt_start_context_switch 1
#endif
#if CAN_WRAP_paravirt_start_context_switch
    WRAP_FOR_DETACH(paravirt_start_context_switch)
#endif
#ifndef CAN_WRAP_dev_mc_add
#   define CAN_WRAP_dev_mc_add 1
#endif
#if CAN_WRAP_dev_mc_add
    WRAP_FOR_DETACH(dev_mc_add)
#endif
#ifndef CAN_WRAP_handle_edge_irq
#   define CAN_WRAP_handle_edge_irq 1
#endif
#if CAN_WRAP_handle_edge_irq
    WRAP_FOR_DETACH(handle_edge_irq)
#endif
#ifndef CAN_WRAP_security_socket_getpeername
#   define CAN_WRAP_security_socket_getpeername 1
#endif
#if CAN_WRAP_security_socket_getpeername
    WRAP_FOR_DETACH(security_socket_getpeername)
#endif
#ifndef CAN_WRAP__raw_spin_unlock_irqrestore
#   define CAN_WRAP__raw_spin_unlock_irqrestore 1
#endif
#if CAN_WRAP__raw_spin_unlock_irqrestore
    WRAP_FOR_DETACH(_raw_spin_unlock_irqrestore)
#endif
#ifndef CAN_WRAP___acpi_release_global_lock
#   define CAN_WRAP___acpi_release_global_lock 0
#endif
DETACH(__acpi_release_global_lock)
#ifndef CAN_WRAP_acpi_unload_parent_table
#   define CAN_WRAP_acpi_unload_parent_table 0
#endif
DETACH(acpi_unload_parent_table)
#ifndef CAN_WRAP_get_task_comm
#   define CAN_WRAP_get_task_comm 1
#endif
#if CAN_WRAP_get_task_comm
    WRAP_FOR_DETACH(get_task_comm)
#endif
#ifndef CAN_WRAP_dquot_quota_on
#   define CAN_WRAP_dquot_quota_on 1
#endif
#if CAN_WRAP_dquot_quota_on
    WRAP_FOR_DETACH(dquot_quota_on)
#endif
#ifndef CAN_WRAP_tick_nohz_get_sleep_length
#   define CAN_WRAP_tick_nohz_get_sleep_length 0
#endif
DETACH(tick_nohz_get_sleep_length)
#ifndef CAN_WRAP_acpi_is_root_bridge
#   define CAN_WRAP_acpi_is_root_bridge 0
#endif
DETACH(acpi_is_root_bridge)
#ifndef CAN_WRAP_mdiobus_free
#   define CAN_WRAP_mdiobus_free 1
#endif
#if CAN_WRAP_mdiobus_free
    WRAP_FOR_DETACH(mdiobus_free)
#endif
#ifndef CAN_WRAP_proc_tty_register_driver
#   define CAN_WRAP_proc_tty_register_driver 1
#endif
#if CAN_WRAP_proc_tty_register_driver
    WRAP_FOR_DETACH(proc_tty_register_driver)
#endif
#ifndef CAN_WRAP_tc_classify
#   define CAN_WRAP_tc_classify 1
#endif
#if CAN_WRAP_tc_classify
    WRAP_FOR_DETACH(tc_classify)
#endif
#ifndef CAN_WRAP_timekeeping_valid_for_hres
#   define CAN_WRAP_timekeeping_valid_for_hres 0
#endif
DETACH(timekeeping_valid_for_hres)
#ifndef CAN_WRAP_key_fsuid_changed
#   define CAN_WRAP_key_fsuid_changed 1
#endif
#if CAN_WRAP_key_fsuid_changed
    WRAP_FOR_DETACH(key_fsuid_changed)
#endif
#ifndef CAN_WRAP_dev_mc_init
#   define CAN_WRAP_dev_mc_init 1
#endif
#if CAN_WRAP_dev_mc_init
    WRAP_FOR_DETACH(dev_mc_init)
#endif
#ifndef CAN_WRAP_compat_sys_rt_tgsigqueueinfo
#   define CAN_WRAP_compat_sys_rt_tgsigqueueinfo 1
#endif
#if CAN_WRAP_compat_sys_rt_tgsigqueueinfo
    WRAP_FOR_DETACH(compat_sys_rt_tgsigqueueinfo)
#endif
#ifndef CAN_WRAP_jbd2_update_log_tail
#   define CAN_WRAP_jbd2_update_log_tail 1
#endif
#if CAN_WRAP_jbd2_update_log_tail
    WRAP_FOR_DETACH(jbd2_update_log_tail)
#endif
#ifndef CAN_WRAP_dquot_enable
#   define CAN_WRAP_dquot_enable 1
#endif
#if CAN_WRAP_dquot_enable
    WRAP_FOR_DETACH(dquot_enable)
#endif
#ifndef CAN_WRAP_block_page_mkwrite
#   define CAN_WRAP_block_page_mkwrite 1
#endif
#if CAN_WRAP_block_page_mkwrite
    WRAP_FOR_DETACH(block_page_mkwrite)
#endif
#ifndef CAN_WRAP___offline_isolated_pages
#   define CAN_WRAP___offline_isolated_pages 0
#endif
DETACH(__offline_isolated_pages)
#ifndef CAN_WRAP_apply_alternatives
#   define CAN_WRAP_apply_alternatives 1
#endif
#if CAN_WRAP_apply_alternatives
    WRAP_FOR_DETACH(apply_alternatives)
#endif
#ifndef CAN_WRAP_inet_frag_evictor
#   define CAN_WRAP_inet_frag_evictor 1
#endif
#if CAN_WRAP_inet_frag_evictor
    WRAP_FOR_DETACH(inet_frag_evictor)
#endif
#ifndef CAN_WRAP_ata_host_alloc
#   define CAN_WRAP_ata_host_alloc 1
#endif
#if CAN_WRAP_ata_host_alloc
    WRAP_FOR_DETACH(ata_host_alloc)
#endif
#ifndef CAN_WRAP_srcu_barrier
#   define CAN_WRAP_srcu_barrier 1
#endif
#if CAN_WRAP_srcu_barrier
    WRAP_FOR_DETACH(srcu_barrier)
#endif
#ifndef CAN_WRAP_schedule_preempt_disabled
#   define CAN_WRAP_schedule_preempt_disabled 0
#endif
DETACH(schedule_preempt_disabled)
#ifndef CAN_WRAP_dev_get_by_name
#   define CAN_WRAP_dev_get_by_name 1
#endif
#if CAN_WRAP_dev_get_by_name
    WRAP_FOR_DETACH(dev_get_by_name)
#endif
#ifndef CAN_WRAP_copy_in_user
#   define CAN_WRAP_copy_in_user 0
#endif
DETACH(copy_in_user)
#ifndef CAN_WRAP_apply_paravirt
#   define CAN_WRAP_apply_paravirt 1
#endif
#if CAN_WRAP_apply_paravirt
    WRAP_FOR_DETACH(apply_paravirt)
#endif
#ifndef CAN_WRAP_qdisc_put_rtab
#   define CAN_WRAP_qdisc_put_rtab 1
#endif
#if CAN_WRAP_qdisc_put_rtab
    WRAP_FOR_DETACH(qdisc_put_rtab)
#endif
#ifndef CAN_WRAP_blk_queue_logical_block_size
#   define CAN_WRAP_blk_queue_logical_block_size 1
#endif
#if CAN_WRAP_blk_queue_logical_block_size
    WRAP_FOR_DETACH(blk_queue_logical_block_size)
#endif
#ifndef CAN_WRAP_smp_call_function_interrupt
#   define CAN_WRAP_smp_call_function_interrupt 1
#endif
#if CAN_WRAP_smp_call_function_interrupt
    WRAP_FOR_DETACH(smp_call_function_interrupt)
#endif
#ifndef CAN_WRAP_scan_unevictable_register_node
#   define CAN_WRAP_scan_unevictable_register_node 1
#endif
#if CAN_WRAP_scan_unevictable_register_node
    WRAP_FOR_DETACH(scan_unevictable_register_node)
#endif
#ifndef CAN_WRAP_kmem_cache_destroy
#   define CAN_WRAP_kmem_cache_destroy 1
#endif
#if CAN_WRAP_kmem_cache_destroy
    WRAP_FOR_DETACH(kmem_cache_destroy)
#endif
#ifndef CAN_WRAP_acpi_extract_package
#   define CAN_WRAP_acpi_extract_package 1
#endif
#if CAN_WRAP_acpi_extract_package
    WRAP_FOR_DETACH(acpi_extract_package)
#endif
#ifndef CAN_WRAP_nsown_capable
#   define CAN_WRAP_nsown_capable 0
#endif
DETACH(nsown_capable)
#ifndef CAN_WRAP___dev_get_by_name
#   define CAN_WRAP___dev_get_by_name 1
#endif
#if CAN_WRAP___dev_get_by_name
#   ifdef DETACH_ADDR___dev_get_by_name
        WRAP_FOR_DETACH(__dev_get_by_name)
#   else
        TYPED_DETACH(__dev_get_by_name)
#   endif
#endif
#ifndef CAN_WRAP_acpi_exception
#   define CAN_WRAP_acpi_exception 0
#endif
DETACH(acpi_exception)
#ifndef CAN_WRAP_vfs_statfs
#   define CAN_WRAP_vfs_statfs 1
#endif
#if CAN_WRAP_vfs_statfs
    WRAP_FOR_DETACH(vfs_statfs)
#endif
#ifndef CAN_WRAP_cgroup_taskset_size
#   define CAN_WRAP_cgroup_taskset_size 1
#endif
#if CAN_WRAP_cgroup_taskset_size
    WRAP_FOR_DETACH(cgroup_taskset_size)
#endif
#ifndef CAN_WRAP_device_store_bool
#   define CAN_WRAP_device_store_bool 1
#endif
#if CAN_WRAP_device_store_bool
    WRAP_FOR_DETACH(device_store_bool)
#endif
#ifndef CAN_WRAP___ata_ehi_push_desc
#   define CAN_WRAP___ata_ehi_push_desc 1
#endif
#if CAN_WRAP___ata_ehi_push_desc
#   ifdef DETACH_ADDR___ata_ehi_push_desc
        WRAP_FOR_DETACH(__ata_ehi_push_desc)
#   else
        TYPED_DETACH(__ata_ehi_push_desc)
#   endif
#endif
#ifndef CAN_WRAP_acpi_enter_sleep_state_s4bios
#   define CAN_WRAP_acpi_enter_sleep_state_s4bios 0
#endif
DETACH(acpi_enter_sleep_state_s4bios)
#ifndef CAN_WRAP___pci_enable_wake
#   define CAN_WRAP___pci_enable_wake 1
#endif
#if CAN_WRAP___pci_enable_wake
#   ifdef DETACH_ADDR___pci_enable_wake
        WRAP_FOR_DETACH(__pci_enable_wake)
#   else
        TYPED_DETACH(__pci_enable_wake)
#   endif
#endif
#ifndef CAN_WRAP_new_inode_pseudo
#   define CAN_WRAP_new_inode_pseudo 1
#endif
#if CAN_WRAP_new_inode_pseudo
    WRAP_FOR_DETACH(new_inode_pseudo)
#endif
#ifndef CAN_WRAP__kstrtol
#   define CAN_WRAP__kstrtol 0
#endif
DETACH(_kstrtol)
#ifndef CAN_WRAP_inet_rtx_syn_ack
#   define CAN_WRAP_inet_rtx_syn_ack 1
#endif
#if CAN_WRAP_inet_rtx_syn_ack
    WRAP_FOR_DETACH(inet_rtx_syn_ack)
#endif
#ifndef CAN_WRAP_pm_qos_add_notifier
#   define CAN_WRAP_pm_qos_add_notifier 1
#endif
#if CAN_WRAP_pm_qos_add_notifier
    WRAP_FOR_DETACH(pm_qos_add_notifier)
#endif
#ifndef CAN_WRAP__raw_write_unlock_irq
#   define CAN_WRAP__raw_write_unlock_irq 1
#endif
#if CAN_WRAP__raw_write_unlock_irq
    WRAP_FOR_DETACH(_raw_write_unlock_irq)
#endif
#ifndef CAN_WRAP_pci_msi_off
#   define CAN_WRAP_pci_msi_off 1
#endif
#if CAN_WRAP_pci_msi_off
    WRAP_FOR_DETACH(pci_msi_off)
#endif
#ifndef CAN_WRAP_pm_relax
#   define CAN_WRAP_pm_relax 1
#endif
#if CAN_WRAP_pm_relax
    WRAP_FOR_DETACH(pm_relax)
#endif
#ifndef CAN_WRAP_tick_get_tick_sched
#   define CAN_WRAP_tick_get_tick_sched 1
#endif
#if CAN_WRAP_tick_get_tick_sched
    WRAP_FOR_DETACH(tick_get_tick_sched)
#endif
#ifndef CAN_WRAP_interruptible_sleep_on
#   define CAN_WRAP_interruptible_sleep_on 1
#endif
#if CAN_WRAP_interruptible_sleep_on
    WRAP_FOR_DETACH(interruptible_sleep_on)
#endif
#ifndef CAN_WRAP_bdi_init
#   define CAN_WRAP_bdi_init 1
#endif
#if CAN_WRAP_bdi_init
    WRAP_FOR_DETACH(bdi_init)
#endif
#ifndef CAN_WRAP_ata_sff_freeze
#   define CAN_WRAP_ata_sff_freeze 1
#endif
#if CAN_WRAP_ata_sff_freeze
    WRAP_FOR_DETACH(ata_sff_freeze)
#endif
#ifndef CAN_WRAP_security_inode_init_security
#   define CAN_WRAP_security_inode_init_security 1
#endif
#if CAN_WRAP_security_inode_init_security
    WRAP_FOR_DETACH(security_inode_init_security)
#endif
#ifndef CAN_WRAP_global_dirty_limits
#   define CAN_WRAP_global_dirty_limits 0
#endif
DETACH(global_dirty_limits)
#ifndef CAN_WRAP___blk_run_queue
#   define CAN_WRAP___blk_run_queue 1
#endif
#if CAN_WRAP___blk_run_queue
#   ifdef DETACH_ADDR___blk_run_queue
        WRAP_FOR_DETACH(__blk_run_queue)
#   else
        TYPED_DETACH(__blk_run_queue)
#   endif
#endif
#ifndef CAN_WRAP_may_umount
#   define CAN_WRAP_may_umount 1
#endif
#if CAN_WRAP_may_umount
    WRAP_FOR_DETACH(may_umount)
#endif
#ifndef CAN_WRAP_get_gate_vma
#   define CAN_WRAP_get_gate_vma 1
#endif
#if CAN_WRAP_get_gate_vma
    WRAP_FOR_DETACH(get_gate_vma)
#endif
#ifndef CAN_WRAP_key_init
#   define CAN_WRAP_key_init 0
#endif
DETACH(key_init)
#ifndef CAN_WRAP_security_task_getscheduler
#   define CAN_WRAP_security_task_getscheduler 1
#endif
#if CAN_WRAP_security_task_getscheduler
    WRAP_FOR_DETACH(security_task_getscheduler)
#endif
#ifndef CAN_WRAP_ioread32
#   define CAN_WRAP_ioread32 0
#endif
DETACH(ioread32)
#ifndef CAN_WRAP_linkwatch_run_queue
#   define CAN_WRAP_linkwatch_run_queue 0
#endif
DETACH(linkwatch_run_queue)
#ifndef CAN_WRAP_alloc_pages_exact
#   define CAN_WRAP_alloc_pages_exact 0
#endif
DETACH(alloc_pages_exact)
#ifndef CAN_WRAP_dm_table_get_md
#   define CAN_WRAP_dm_table_get_md 1
#endif
#if CAN_WRAP_dm_table_get_md
    WRAP_FOR_DETACH(dm_table_get_md)
#endif
#ifndef CAN_WRAP_may_umount_tree
#   define CAN_WRAP_may_umount_tree 1
#endif
#if CAN_WRAP_may_umount_tree
    WRAP_FOR_DETACH(may_umount_tree)
#endif
#ifndef CAN_WRAP_acpi_install_fixed_event_handler
#   define CAN_WRAP_acpi_install_fixed_event_handler 1
#endif
#if CAN_WRAP_acpi_install_fixed_event_handler
    WRAP_FOR_DETACH(acpi_install_fixed_event_handler)
#endif
#ifndef CAN_WRAP_schedule_hrtimeout
#   define CAN_WRAP_schedule_hrtimeout 0
#endif
DETACH(schedule_hrtimeout)
#ifndef CAN_WRAP_touch_softlockup_watchdog
#   define CAN_WRAP_touch_softlockup_watchdog 0
#endif
DETACH(touch_softlockup_watchdog)
#ifndef CAN_WRAP_scheduler_ipi
#   define CAN_WRAP_scheduler_ipi 0
#endif
DETACH(scheduler_ipi)
#ifndef CAN_WRAP_swiotlb_init
#   define CAN_WRAP_swiotlb_init 0
#endif
DETACH(swiotlb_init)
#ifndef CAN_WRAP_compat_sys_select
#   define CAN_WRAP_compat_sys_select 1
#endif
#if CAN_WRAP_compat_sys_select
    WRAP_FOR_DETACH(compat_sys_select)
#endif
#ifndef CAN_WRAP_blk_requeue_request
#   define CAN_WRAP_blk_requeue_request 1
#endif
#if CAN_WRAP_blk_requeue_request
    WRAP_FOR_DETACH(blk_requeue_request)
#endif
#ifndef CAN_WRAP_locks_alloc_lock
#   define CAN_WRAP_locks_alloc_lock 1
#endif
#if CAN_WRAP_locks_alloc_lock
    WRAP_FOR_DETACH(locks_alloc_lock)
#endif
#ifndef CAN_WRAP_swiotlb_late_init_with_tbl
#   define CAN_WRAP_swiotlb_late_init_with_tbl 0
#endif
DETACH(swiotlb_late_init_with_tbl)
#ifndef CAN_WRAP_dpm_resume
#   define CAN_WRAP_dpm_resume 1
#endif
#if CAN_WRAP_dpm_resume
    WRAP_FOR_DETACH(dpm_resume)
#endif
#ifndef CAN_WRAP_nf_unregister_hook
#   define CAN_WRAP_nf_unregister_hook 1
#endif
#if CAN_WRAP_nf_unregister_hook
    WRAP_FOR_DETACH(nf_unregister_hook)
#endif
#ifndef CAN_WRAP_pci_find_capability
#   define CAN_WRAP_pci_find_capability 1
#endif
#if CAN_WRAP_pci_find_capability
    WRAP_FOR_DETACH(pci_find_capability)
#endif
#ifndef CAN_WRAP_sysfs_remove_file_from_group
#   define CAN_WRAP_sysfs_remove_file_from_group 1
#endif
#if CAN_WRAP_sysfs_remove_file_from_group
    WRAP_FOR_DETACH(sysfs_remove_file_from_group)
#endif
#ifndef CAN_WRAP_compat_sys_getdents
#   define CAN_WRAP_compat_sys_getdents 1
#endif
#if CAN_WRAP_compat_sys_getdents
    WRAP_FOR_DETACH(compat_sys_getdents)
#endif
#ifndef CAN_WRAP___lru_cache_add
#   define CAN_WRAP___lru_cache_add 1
#endif
#if CAN_WRAP___lru_cache_add
#   ifdef DETACH_ADDR___lru_cache_add
        WRAP_FOR_DETACH(__lru_cache_add)
#   else
        TYPED_DETACH(__lru_cache_add)
#   endif
#endif
#ifndef CAN_WRAP_get_random_bytes_arch
#   define CAN_WRAP_get_random_bytes_arch 0
#endif
DETACH(get_random_bytes_arch)
#ifndef CAN_WRAP_nonseekable_open
#   define CAN_WRAP_nonseekable_open 1
#endif
#if CAN_WRAP_nonseekable_open
    WRAP_FOR_DETACH(nonseekable_open)
#endif
#ifndef CAN_WRAP_jbd2_log_do_checkpoint
#   define CAN_WRAP_jbd2_log_do_checkpoint 1
#endif
#if CAN_WRAP_jbd2_log_do_checkpoint
    WRAP_FOR_DETACH(jbd2_log_do_checkpoint)
#endif
#ifndef CAN_WRAP_qid_valid
#   define CAN_WRAP_qid_valid 1
#endif
#if CAN_WRAP_qid_valid
    WRAP_FOR_DETACH(qid_valid)
#endif
#ifndef CAN_WRAP_oops_may_print
#   define CAN_WRAP_oops_may_print 0
#endif
DETACH(oops_may_print)
#ifndef CAN_WRAP_zap_page_range
#   define CAN_WRAP_zap_page_range 1
#endif
#if CAN_WRAP_zap_page_range
    WRAP_FOR_DETACH(zap_page_range)
#endif
#ifndef CAN_WRAP_qdisc_destroy
#   define CAN_WRAP_qdisc_destroy 1
#endif
#if CAN_WRAP_qdisc_destroy
    WRAP_FOR_DETACH(qdisc_destroy)
#endif
#ifndef CAN_WRAP_posix_unblock_lock
#   define CAN_WRAP_posix_unblock_lock 1
#endif
#if CAN_WRAP_posix_unblock_lock
    WRAP_FOR_DETACH(posix_unblock_lock)
#endif
#ifndef CAN_WRAP_get_dump_page
#   define CAN_WRAP_get_dump_page 1
#endif
#if CAN_WRAP_get_dump_page
    WRAP_FOR_DETACH(get_dump_page)
#endif
#ifndef CAN_WRAP_security_file_lock
#   define CAN_WRAP_security_file_lock 1
#endif
#if CAN_WRAP_security_file_lock
    WRAP_FOR_DETACH(security_file_lock)
#endif
#ifndef CAN_WRAP_smp_store_cpu_info
#   define CAN_WRAP_smp_store_cpu_info 0
#endif
DETACH(smp_store_cpu_info)
#ifndef CAN_WRAP_pci_bus_read_config_dword
#   define CAN_WRAP_pci_bus_read_config_dword 1
#endif
#if CAN_WRAP_pci_bus_read_config_dword
    WRAP_FOR_DETACH(pci_bus_read_config_dword)
#endif
#ifndef CAN_WRAP_pci_find_parent_resource
#   define CAN_WRAP_pci_find_parent_resource 1
#endif
#if CAN_WRAP_pci_find_parent_resource
    WRAP_FOR_DETACH(pci_find_parent_resource)
#endif
#ifndef CAN_WRAP_first_online_pgdat
#   define CAN_WRAP_first_online_pgdat 1
#endif
#if CAN_WRAP_first_online_pgdat
    WRAP_FOR_DETACH(first_online_pgdat)
#endif
#ifndef CAN_WRAP_neigh_sysctl_register
#   define CAN_WRAP_neigh_sysctl_register 1
#endif
#if CAN_WRAP_neigh_sysctl_register
    WRAP_FOR_DETACH(neigh_sysctl_register)
#endif
#ifndef CAN_WRAP_alloc_pages_vma
#   define CAN_WRAP_alloc_pages_vma 1
#endif
#if CAN_WRAP_alloc_pages_vma
    WRAP_FOR_DETACH(alloc_pages_vma)
#endif
#ifndef CAN_WRAP_device_store_ulong
#   define CAN_WRAP_device_store_ulong 1
#endif
#if CAN_WRAP_device_store_ulong
    WRAP_FOR_DETACH(device_store_ulong)
#endif
#ifndef CAN_WRAP_smp_call_function_single
#   define CAN_WRAP_smp_call_function_single 1
#endif
#if CAN_WRAP_smp_call_function_single
    WRAP_FOR_DETACH(smp_call_function_single)
#endif
#ifndef CAN_WRAP_local_bh_enable
#   define CAN_WRAP_local_bh_enable 0
#endif
DETACH(local_bh_enable)
#ifndef CAN_WRAP_blk_unregister_region
#   define CAN_WRAP_blk_unregister_region 0
#endif
DETACH(blk_unregister_region)
#ifndef CAN_WRAP_iowrite16
#   define CAN_WRAP_iowrite16 0
#endif
DETACH(iowrite16)
#ifndef CAN_WRAP_rt_mutex_lock
#   define CAN_WRAP_rt_mutex_lock 1
#endif
#if CAN_WRAP_rt_mutex_lock
    WRAP_FOR_DETACH(rt_mutex_lock)
#endif
#ifndef CAN_WRAP_poll_freewait
#   define CAN_WRAP_poll_freewait 1
#endif
#if CAN_WRAP_poll_freewait
    WRAP_FOR_DETACH(poll_freewait)
#endif
#ifndef CAN_WRAP_send_remote_softirq
#   define CAN_WRAP_send_remote_softirq 1
#endif
#if CAN_WRAP_send_remote_softirq
    WRAP_FOR_DETACH(send_remote_softirq)
#endif
#ifndef CAN_WRAP_vsscanf
#   define CAN_WRAP_vsscanf 0
#endif
DETACH(vsscanf)
#ifndef CAN_WRAP_security_key_alloc
#   define CAN_WRAP_security_key_alloc 1
#endif
#if CAN_WRAP_security_key_alloc
    WRAP_FOR_DETACH(security_key_alloc)
#endif
#ifndef CAN_WRAP_compat_sys_getdents64
#   define CAN_WRAP_compat_sys_getdents64 1
#endif
#if CAN_WRAP_compat_sys_getdents64
    WRAP_FOR_DETACH(compat_sys_getdents64)
#endif
#ifndef CAN_WRAP_pci_cfg_access_trylock
#   define CAN_WRAP_pci_cfg_access_trylock 1
#endif
#if CAN_WRAP_pci_cfg_access_trylock
    WRAP_FOR_DETACH(pci_cfg_access_trylock)
#endif
#ifndef CAN_WRAP_arch_show_interrupts
#   define CAN_WRAP_arch_show_interrupts 1
#endif
#if CAN_WRAP_arch_show_interrupts
    WRAP_FOR_DETACH(arch_show_interrupts)
#endif
#ifndef CAN_WRAP_init_buffer
#   define CAN_WRAP_init_buffer 1
#endif
#if CAN_WRAP_init_buffer
    WRAP_FOR_DETACH(init_buffer)
#endif
#ifndef CAN_WRAP_blk_init_allocated_queue
#   define CAN_WRAP_blk_init_allocated_queue 1
#endif
#if CAN_WRAP_blk_init_allocated_queue
    WRAP_FOR_DETACH(blk_init_allocated_queue)
#endif
#ifndef CAN_WRAP_kernel_setsockopt
#   define CAN_WRAP_kernel_setsockopt 1
#endif
#if CAN_WRAP_kernel_setsockopt
    WRAP_FOR_DETACH(kernel_setsockopt)
#endif
#ifndef CAN_WRAP_pci_map_rom
#   define CAN_WRAP_pci_map_rom 1
#endif
#if CAN_WRAP_pci_map_rom
    WRAP_FOR_DETACH(pci_map_rom)
#endif
#ifndef CAN_WRAP_sock_enable_timestamp
#   define CAN_WRAP_sock_enable_timestamp 1
#endif
#if CAN_WRAP_sock_enable_timestamp
    WRAP_FOR_DETACH(sock_enable_timestamp)
#endif
#ifndef CAN_WRAP_sata_sff_hardreset
#   define CAN_WRAP_sata_sff_hardreset 1
#endif
#if CAN_WRAP_sata_sff_hardreset
    WRAP_FOR_DETACH(sata_sff_hardreset)
#endif
#ifndef CAN_WRAP_acpi_os_create_semaphore
#   define CAN_WRAP_acpi_os_create_semaphore 0
#endif
DETACH(acpi_os_create_semaphore)
#ifndef CAN_WRAP_init_amd_cacheinfo
#   define CAN_WRAP_init_amd_cacheinfo 1
#endif
#if CAN_WRAP_init_amd_cacheinfo
    WRAP_FOR_DETACH(init_amd_cacheinfo)
#endif
#ifndef CAN_WRAP_acpi_load_tables
#   define CAN_WRAP_acpi_load_tables 0
#endif
DETACH(acpi_load_tables)
#ifndef CAN_WRAP_do_IRQ
#   define CAN_WRAP_do_IRQ 1
#endif
#if CAN_WRAP_do_IRQ
    WRAP_FOR_DETACH(do_IRQ)
#endif
#ifndef CAN_WRAP_free_task
#   define CAN_WRAP_free_task 1
#endif
#if CAN_WRAP_free_task
    WRAP_FOR_DETACH(free_task)
#endif
#ifndef CAN_WRAP_bdevname
#   define CAN_WRAP_bdevname 1
#endif
#if CAN_WRAP_bdevname
    WRAP_FOR_DETACH(bdevname)
#endif
#ifndef CAN_WRAP_smp_setup_processor_id
#   define CAN_WRAP_smp_setup_processor_id 0
#endif
DETACH(smp_setup_processor_id)
#ifndef CAN_WRAP_acpi_resources_are_enforced
#   define CAN_WRAP_acpi_resources_are_enforced 0
#endif
DETACH(acpi_resources_are_enforced)
#ifndef CAN_WRAP_csum_partial_copy_from_user
#   define CAN_WRAP_csum_partial_copy_from_user 0
#endif
DETACH(csum_partial_copy_from_user)
#ifndef CAN_WRAP_icmpv6_cleanup
#   define CAN_WRAP_icmpv6_cleanup 0
#endif
DETACH(icmpv6_cleanup)
#ifndef CAN_WRAP_rt_mutex_timed_lock
#   define CAN_WRAP_rt_mutex_timed_lock 1
#endif
#if CAN_WRAP_rt_mutex_timed_lock
    WRAP_FOR_DETACH(rt_mutex_timed_lock)
#endif
#ifndef CAN_WRAP_acpi_dev_resource_memory
#   define CAN_WRAP_acpi_dev_resource_memory 1
#endif
#if CAN_WRAP_acpi_dev_resource_memory
    WRAP_FOR_DETACH(acpi_dev_resource_memory)
#endif
#ifndef CAN_WRAP___delete_from_swap_cache
#   define CAN_WRAP___delete_from_swap_cache 1
#endif
#if CAN_WRAP___delete_from_swap_cache
#   ifdef DETACH_ADDR___delete_from_swap_cache
        WRAP_FOR_DETACH(__delete_from_swap_cache)
#   else
        TYPED_DETACH(__delete_from_swap_cache)
#   endif
#endif
#ifndef CAN_WRAP_log_buf_kexec_setup
#   define CAN_WRAP_log_buf_kexec_setup 0
#endif
DETACH(log_buf_kexec_setup)
#ifndef CAN_WRAP_sock_release
#   define CAN_WRAP_sock_release 1
#endif
#if CAN_WRAP_sock_release
    WRAP_FOR_DETACH(sock_release)
#endif
#ifndef CAN_WRAP_ioctl_by_bdev
#   define CAN_WRAP_ioctl_by_bdev 1
#endif
#if CAN_WRAP_ioctl_by_bdev
    WRAP_FOR_DETACH(ioctl_by_bdev)
#endif
#ifndef CAN_WRAP___add_pages
#   define CAN_WRAP___add_pages 1
#endif
#if CAN_WRAP___add_pages
#   ifdef DETACH_ADDR___add_pages
        WRAP_FOR_DETACH(__add_pages)
#   else
        TYPED_DETACH(__add_pages)
#   endif
#endif
#ifndef CAN_WRAP_security_sem_associate
#   define CAN_WRAP_security_sem_associate 1
#endif
#if CAN_WRAP_security_sem_associate
    WRAP_FOR_DETACH(security_sem_associate)
#endif
#ifndef CAN_WRAP_wakeup_flusher_threads
#   define CAN_WRAP_wakeup_flusher_threads 0
#endif
DETACH(wakeup_flusher_threads)
#ifndef CAN_WRAP_memcmp
#   define CAN_WRAP_memcmp 0
#endif
DETACH(memcmp)
#ifndef CAN_WRAP_compat_sys_open
#   define CAN_WRAP_compat_sys_open 0
#endif
DETACH(compat_sys_open)
#ifndef CAN_WRAP_do_sync_read
#   define CAN_WRAP_do_sync_read 1
#endif
#if CAN_WRAP_do_sync_read
    WRAP_FOR_DETACH(do_sync_read)
#endif
#ifndef CAN_WRAP_skb_copy_and_csum_dev
#   define CAN_WRAP_skb_copy_and_csum_dev 1
#endif
#if CAN_WRAP_skb_copy_and_csum_dev
    WRAP_FOR_DETACH(skb_copy_and_csum_dev)
#endif
#ifndef CAN_WRAP_input_register_handle
#   define CAN_WRAP_input_register_handle 1
#endif
#if CAN_WRAP_input_register_handle
    WRAP_FOR_DETACH(input_register_handle)
#endif
#ifndef CAN_WRAP_generic_swapfile_activate
#   define CAN_WRAP_generic_swapfile_activate 1
#endif
#if CAN_WRAP_generic_swapfile_activate
    WRAP_FOR_DETACH(generic_swapfile_activate)
#endif
#ifndef CAN_WRAP_scsi_unregister
#   define CAN_WRAP_scsi_unregister 1
#endif
#if CAN_WRAP_scsi_unregister
    WRAP_FOR_DETACH(scsi_unregister)
#endif
#ifndef CAN_WRAP_memparse
#   define CAN_WRAP_memparse 0
#endif
DETACH(memparse)
#ifndef CAN_WRAP_devres_destroy
#   define CAN_WRAP_devres_destroy 1
#endif
#if CAN_WRAP_devres_destroy
    WRAP_FOR_DETACH(devres_destroy)
#endif
#ifndef CAN_WRAP_vunmap
#   define CAN_WRAP_vunmap 0
#endif
DETACH(vunmap)
#ifndef CAN_WRAP_global_reclaimable_pages
#   define CAN_WRAP_global_reclaimable_pages 0
#endif
DETACH(global_reclaimable_pages)
#ifndef CAN_WRAP_copy_page
#   define CAN_WRAP_copy_page 0
#endif
DETACH(copy_page)
#ifndef CAN_WRAP_pcie_capability_write_word
#   define CAN_WRAP_pcie_capability_write_word 1
#endif
#if CAN_WRAP_pcie_capability_write_word
    WRAP_FOR_DETACH(pcie_capability_write_word)
#endif
#ifndef CAN_WRAP_wait_for_completion_interruptible_timeout
#   define CAN_WRAP_wait_for_completion_interruptible_timeout 1
#endif
#if CAN_WRAP_wait_for_completion_interruptible_timeout
    WRAP_FOR_DETACH(wait_for_completion_interruptible_timeout)
#endif
#ifndef CAN_WRAP_track_pfn_insert
#   define CAN_WRAP_track_pfn_insert 1
#endif
#if CAN_WRAP_track_pfn_insert
    WRAP_FOR_DETACH(track_pfn_insert)
#endif
#ifndef CAN_WRAP_security_inode_notifysecctx
#   define CAN_WRAP_security_inode_notifysecctx 1
#endif
#if CAN_WRAP_security_inode_notifysecctx
    WRAP_FOR_DETACH(security_inode_notifysecctx)
#endif
#ifndef CAN_WRAP_uids_sysfs_init
#   define CAN_WRAP_uids_sysfs_init 0
#endif
DETACH(uids_sysfs_init)
#ifndef CAN_WRAP_param_set_short
#   define CAN_WRAP_param_set_short 1
#endif
#if CAN_WRAP_param_set_short
    WRAP_FOR_DETACH(param_set_short)
#endif
#ifndef CAN_WRAP_mii_nway_restart
#   define CAN_WRAP_mii_nway_restart 1
#endif
#if CAN_WRAP_mii_nway_restart
    WRAP_FOR_DETACH(mii_nway_restart)
#endif
#ifndef CAN_WRAP_fasync_remove_entry
#   define CAN_WRAP_fasync_remove_entry 1
#endif
#if CAN_WRAP_fasync_remove_entry
    WRAP_FOR_DETACH(fasync_remove_entry)
#endif
#ifndef CAN_WRAP_search_module_extables
#   define CAN_WRAP_search_module_extables 1
#endif
#if CAN_WRAP_search_module_extables
    WRAP_FOR_DETACH(search_module_extables)
#endif
#ifndef CAN_WRAP_get_option
#   define CAN_WRAP_get_option 0
#endif
DETACH(get_option)
#ifndef CAN_WRAP_security_inode_setattr
#   define CAN_WRAP_security_inode_setattr 1
#endif
#if CAN_WRAP_security_inode_setattr
    WRAP_FOR_DETACH(security_inode_setattr)
#endif
#ifndef CAN_WRAP_ns_to_timespec
#   define CAN_WRAP_ns_to_timespec 1
#endif
#if CAN_WRAP_ns_to_timespec
    WRAP_FOR_DETACH(ns_to_timespec)
#endif
#ifndef CAN_WRAP_elv_rb_former_request
#   define CAN_WRAP_elv_rb_former_request 1
#endif
#if CAN_WRAP_elv_rb_former_request
    WRAP_FOR_DETACH(elv_rb_former_request)
#endif
#ifndef CAN_WRAP_textsearch_unregister
#   define CAN_WRAP_textsearch_unregister 1
#endif
#if CAN_WRAP_textsearch_unregister
    WRAP_FOR_DETACH(textsearch_unregister)
#endif
#ifndef CAN_WRAP_sparse_init
#   define CAN_WRAP_sparse_init 0
#endif
DETACH(sparse_init)
#ifndef CAN_WRAP___timer_stats_timer_set_start_info
#   define CAN_WRAP___timer_stats_timer_set_start_info 1
#endif
#if CAN_WRAP___timer_stats_timer_set_start_info
#   ifdef DETACH_ADDR___timer_stats_timer_set_start_info
        WRAP_FOR_DETACH(__timer_stats_timer_set_start_info)
#   else
        TYPED_DETACH(__timer_stats_timer_set_start_info)
#   endif
#endif
#ifndef CAN_WRAP_elv_merge_requests
#   define CAN_WRAP_elv_merge_requests 1
#endif
#if CAN_WRAP_elv_merge_requests
    WRAP_FOR_DETACH(elv_merge_requests)
#endif
#ifndef CAN_WRAP_add_timer_on
#   define CAN_WRAP_add_timer_on 1
#endif
#if CAN_WRAP_add_timer_on
    WRAP_FOR_DETACH(add_timer_on)
#endif
#ifndef CAN_WRAP_neigh_lookup_nodev
#   define CAN_WRAP_neigh_lookup_nodev 1
#endif
#if CAN_WRAP_neigh_lookup_nodev
    WRAP_FOR_DETACH(neigh_lookup_nodev)
#endif
#ifndef CAN_WRAP_register_sysctl_paths
#   define CAN_WRAP_register_sysctl_paths 1
#endif
#if CAN_WRAP_register_sysctl_paths
    WRAP_FOR_DETACH(register_sysctl_paths)
#endif
#ifndef CAN_WRAP_bh_waitq_head
#   define CAN_WRAP_bh_waitq_head 1
#endif
#if CAN_WRAP_bh_waitq_head
    WRAP_FOR_DETACH(bh_waitq_head)
#endif
#ifndef CAN_WRAP_pci_pme_active
#   define CAN_WRAP_pci_pme_active 1
#endif
#if CAN_WRAP_pci_pme_active
    WRAP_FOR_DETACH(pci_pme_active)
#endif
#ifndef CAN_WRAP_prop_fraction_single
#   define CAN_WRAP_prop_fraction_single 1
#endif
#if CAN_WRAP_prop_fraction_single
    WRAP_FOR_DETACH(prop_fraction_single)
#endif
#ifndef CAN_WRAP_tick_init
#   define CAN_WRAP_tick_init 0
#endif
DETACH(tick_init)
#ifndef CAN_WRAP_seq_open
#   define CAN_WRAP_seq_open 1
#endif
#if CAN_WRAP_seq_open
    WRAP_FOR_DETACH(seq_open)
#endif
#ifndef CAN_WRAP___root_device_register
#   define CAN_WRAP___root_device_register 1
#endif
#if CAN_WRAP___root_device_register
#   ifdef DETACH_ADDR___root_device_register
        WRAP_FOR_DETACH(__root_device_register)
#   else
        TYPED_DETACH(__root_device_register)
#   endif
#endif
#ifndef CAN_WRAP_security_inode_getsecid
#   define CAN_WRAP_security_inode_getsecid 1
#endif
#if CAN_WRAP_security_inode_getsecid
    WRAP_FOR_DETACH(security_inode_getsecid)
#endif
#ifndef CAN_WRAP_inet_sk_rebuild_header
#   define CAN_WRAP_inet_sk_rebuild_header 1
#endif
#if CAN_WRAP_inet_sk_rebuild_header
    WRAP_FOR_DETACH(inet_sk_rebuild_header)
#endif
#ifndef CAN_WRAP_task_clear_jobctl_trapping
#   define CAN_WRAP_task_clear_jobctl_trapping 1
#endif
#if CAN_WRAP_task_clear_jobctl_trapping
    WRAP_FOR_DETACH(task_clear_jobctl_trapping)
#endif
#ifndef CAN_WRAP_jbd2_journal_grab_journal_head
#   define CAN_WRAP_jbd2_journal_grab_journal_head 1
#endif
#if CAN_WRAP_jbd2_journal_grab_journal_head
    WRAP_FOR_DETACH(jbd2_journal_grab_journal_head)
#endif
#ifndef CAN_WRAP_notsc_setup
#   define CAN_WRAP_notsc_setup 0
#endif
DETACH(notsc_setup)
#ifndef CAN_WRAP_put_compat_itimerspec
#   define CAN_WRAP_put_compat_itimerspec 1
#endif
#if CAN_WRAP_put_compat_itimerspec
    WRAP_FOR_DETACH(put_compat_itimerspec)
#endif
#ifndef CAN_WRAP_calibrate_delay
#   define CAN_WRAP_calibrate_delay 0
#endif
DETACH(calibrate_delay)
#ifndef CAN_WRAP_acpi_suspend_lowlevel
#   define CAN_WRAP_acpi_suspend_lowlevel 0
#endif
DETACH(acpi_suspend_lowlevel)
#ifndef CAN_WRAP_subsys_find_device_by_id
#   define CAN_WRAP_subsys_find_device_by_id 1
#endif
#if CAN_WRAP_subsys_find_device_by_id
    WRAP_FOR_DETACH(subsys_find_device_by_id)
#endif
#ifndef CAN_WRAP_ioremap_wc
#   define CAN_WRAP_ioremap_wc 0
#endif
DETACH(ioremap_wc)
#ifndef CAN_WRAP_mdiobus_scan
#   define CAN_WRAP_mdiobus_scan 1
#endif
#if CAN_WRAP_mdiobus_scan
    WRAP_FOR_DETACH(mdiobus_scan)
#endif
#ifndef CAN_WRAP_pci_sriov_set_totalvfs
#   define CAN_WRAP_pci_sriov_set_totalvfs 1
#endif
#if CAN_WRAP_pci_sriov_set_totalvfs
    WRAP_FOR_DETACH(pci_sriov_set_totalvfs)
#endif
#ifndef CAN_WRAP_ramfs_get_inode
#   define CAN_WRAP_ramfs_get_inode 1
#endif
#if CAN_WRAP_ramfs_get_inode
    WRAP_FOR_DETACH(ramfs_get_inode)
#endif
#ifndef CAN_WRAP_vfs_kern_mount
#   define CAN_WRAP_vfs_kern_mount 1
#endif
#if CAN_WRAP_vfs_kern_mount
    WRAP_FOR_DETACH(vfs_kern_mount)
#endif
#ifndef CAN_WRAP_blk_start_request
#   define CAN_WRAP_blk_start_request 1
#endif
#if CAN_WRAP_blk_start_request
    WRAP_FOR_DETACH(blk_start_request)
#endif
#ifndef CAN_WRAP_change_huge_pmd
#   define CAN_WRAP_change_huge_pmd 1
#endif
#if CAN_WRAP_change_huge_pmd
    WRAP_FOR_DETACH(change_huge_pmd)
#endif
#ifndef CAN_WRAP_class_find_device
#   define CAN_WRAP_class_find_device 1
#endif
#if CAN_WRAP_class_find_device
    WRAP_FOR_DETACH(class_find_device)
#endif
#ifndef CAN_WRAP_follow_phys
#   define CAN_WRAP_follow_phys 1
#endif
#if CAN_WRAP_follow_phys
    WRAP_FOR_DETACH(follow_phys)
#endif
#ifndef CAN_WRAP_acpi_bus_get_device
#   define CAN_WRAP_acpi_bus_get_device 0
#endif
DETACH(acpi_bus_get_device)
#ifndef CAN_WRAP_nla_reserve
#   define CAN_WRAP_nla_reserve 1
#endif
#if CAN_WRAP_nla_reserve
    WRAP_FOR_DETACH(nla_reserve)
#endif
#ifndef CAN_WRAP_copy_user_huge_page
#   define CAN_WRAP_copy_user_huge_page 1
#endif
#if CAN_WRAP_copy_user_huge_page
    WRAP_FOR_DETACH(copy_user_huge_page)
#endif
#ifndef CAN_WRAP_pm_generic_freeze
#   define CAN_WRAP_pm_generic_freeze 1
#endif
#if CAN_WRAP_pm_generic_freeze
    WRAP_FOR_DETACH(pm_generic_freeze)
#endif
#ifndef CAN_WRAP_send_sig
#   define CAN_WRAP_send_sig 1
#endif
#if CAN_WRAP_send_sig
    WRAP_FOR_DETACH(send_sig)
#endif
#ifndef CAN_WRAP_eth_mac_addr
#   define CAN_WRAP_eth_mac_addr 1
#endif
#if CAN_WRAP_eth_mac_addr
    WRAP_FOR_DETACH(eth_mac_addr)
#endif
#ifndef CAN_WRAP_unregister_pernet_device
#   define CAN_WRAP_unregister_pernet_device 1
#endif
#if CAN_WRAP_unregister_pernet_device
    WRAP_FOR_DETACH(unregister_pernet_device)
#endif
#ifndef CAN_WRAP_sched_autogroup_fork
#   define CAN_WRAP_sched_autogroup_fork 1
#endif
#if CAN_WRAP_sched_autogroup_fork
    WRAP_FOR_DETACH(sched_autogroup_fork)
#endif
#ifndef CAN_WRAP_kstrtou16
#   define CAN_WRAP_kstrtou16 0
#endif
DETACH(kstrtou16)
#ifndef CAN_WRAP_swiotlb_dma_mapping_error
#   define CAN_WRAP_swiotlb_dma_mapping_error 1
#endif
#if CAN_WRAP_swiotlb_dma_mapping_error
    WRAP_FOR_DETACH(swiotlb_dma_mapping_error)
#endif
#ifndef CAN_WRAP_blk_queue_unprep_rq
#   define CAN_WRAP_blk_queue_unprep_rq 1
#endif
#if CAN_WRAP_blk_queue_unprep_rq
    WRAP_FOR_DETACH(blk_queue_unprep_rq)
#endif
#ifndef CAN_WRAP_pci_enable_rom
#   define CAN_WRAP_pci_enable_rom 1
#endif
#if CAN_WRAP_pci_enable_rom
    WRAP_FOR_DETACH(pci_enable_rom)
#endif
#ifndef CAN_WRAP_native_smp_prepare_boot_cpu
#   define CAN_WRAP_native_smp_prepare_boot_cpu 0
#endif
DETACH(native_smp_prepare_boot_cpu)
#ifndef CAN_WRAP_fifo_set_limit
#   define CAN_WRAP_fifo_set_limit 1
#endif
#if CAN_WRAP_fifo_set_limit
    WRAP_FOR_DETACH(fifo_set_limit)
#endif
#ifndef CAN_WRAP_rcu_force_quiescent_state
#   define CAN_WRAP_rcu_force_quiescent_state 0
#endif
DETACH(rcu_force_quiescent_state)
#ifndef CAN_WRAP_pcie_get_readrq
#   define CAN_WRAP_pcie_get_readrq 1
#endif
#if CAN_WRAP_pcie_get_readrq
    WRAP_FOR_DETACH(pcie_get_readrq)
#endif
#ifndef CAN_WRAP_free_swap_and_cache
#   define CAN_WRAP_free_swap_and_cache 1
#endif
#if CAN_WRAP_free_swap_and_cache
    WRAP_FOR_DETACH(free_swap_and_cache)
#endif
#ifndef CAN_WRAP_cgroup_unload_subsys
#   define CAN_WRAP_cgroup_unload_subsys 1
#endif
#if CAN_WRAP_cgroup_unload_subsys
    WRAP_FOR_DETACH(cgroup_unload_subsys)
#endif
#ifndef CAN_WRAP_send_sig_info
#   define CAN_WRAP_send_sig_info 1
#endif
#if CAN_WRAP_send_sig_info
    WRAP_FOR_DETACH(send_sig_info)
#endif
#ifndef CAN_WRAP_writeback_in_progress
#   define CAN_WRAP_writeback_in_progress 1
#endif
#if CAN_WRAP_writeback_in_progress
    WRAP_FOR_DETACH(writeback_in_progress)
#endif
#ifndef CAN_WRAP_eth_header_parse
#   define CAN_WRAP_eth_header_parse 1
#endif
#if CAN_WRAP_eth_header_parse
    WRAP_FOR_DETACH(eth_header_parse)
#endif
#ifndef CAN_WRAP_enable_irq
#   define CAN_WRAP_enable_irq 0
#endif
DETACH(enable_irq)
#ifndef CAN_WRAP_seq_hlist_start_head_rcu
#   define CAN_WRAP_seq_hlist_start_head_rcu 1
#endif
#if CAN_WRAP_seq_hlist_start_head_rcu
    WRAP_FOR_DETACH(seq_hlist_start_head_rcu)
#endif
#ifndef CAN_WRAP_tick_nohz_idle_enter
#   define CAN_WRAP_tick_nohz_idle_enter 0
#endif
DETACH(tick_nohz_idle_enter)
#ifndef CAN_WRAP____pskb_trim
#   define CAN_WRAP____pskb_trim 1
#endif
#if CAN_WRAP____pskb_trim
#   ifdef DETACH_ADDR____pskb_trim
        WRAP_FOR_DETACH(___pskb_trim)
#   else
        TYPED_DETACH(___pskb_trim)
#   endif
#endif
#ifndef CAN_WRAP_dev_set_drvdata
#   define CAN_WRAP_dev_set_drvdata 1
#endif
#if CAN_WRAP_dev_set_drvdata
    WRAP_FOR_DETACH(dev_set_drvdata)
#endif
#ifndef CAN_WRAP_filemap_fdatawait_range
#   define CAN_WRAP_filemap_fdatawait_range 1
#endif
#if CAN_WRAP_filemap_fdatawait_range
    WRAP_FOR_DETACH(filemap_fdatawait_range)
#endif
#ifndef CAN_WRAP_netlink_detachskb
#   define CAN_WRAP_netlink_detachskb 1
#endif
#if CAN_WRAP_netlink_detachskb
    WRAP_FOR_DETACH(netlink_detachskb)
#endif
#ifndef CAN_WRAP_sysfs_delete_link
#   define CAN_WRAP_sysfs_delete_link 1
#endif
#if CAN_WRAP_sysfs_delete_link
    WRAP_FOR_DETACH(sysfs_delete_link)
#endif
#ifndef CAN_WRAP_lookup_module_symbol_name
#   define CAN_WRAP_lookup_module_symbol_name 0
#endif
DETACH(lookup_module_symbol_name)
#ifndef CAN_WRAP_print_hex_dump_bytes
#   define CAN_WRAP_print_hex_dump_bytes 0
#endif
DETACH(print_hex_dump_bytes)
#ifndef CAN_WRAP_gnet_stats_start_copy_compat
#   define CAN_WRAP_gnet_stats_start_copy_compat 1
#endif
#if CAN_WRAP_gnet_stats_start_copy_compat
    WRAP_FOR_DETACH(gnet_stats_start_copy_compat)
#endif
#ifndef CAN_WRAP_write_inode_now
#   define CAN_WRAP_write_inode_now 1
#endif
#if CAN_WRAP_write_inode_now
    WRAP_FOR_DETACH(write_inode_now)
#endif
#ifndef CAN_WRAP_vfs_stat
#   define CAN_WRAP_vfs_stat 1
#endif
#if CAN_WRAP_vfs_stat
    WRAP_FOR_DETACH(vfs_stat)
#endif
#ifndef CAN_WRAP_bio_put
#   define CAN_WRAP_bio_put 1
#endif
#if CAN_WRAP_bio_put
    WRAP_FOR_DETACH(bio_put)
#endif
#ifndef CAN_WRAP___blk_end_request_all
#   define CAN_WRAP___blk_end_request_all 1
#endif
#if CAN_WRAP___blk_end_request_all
#   ifdef DETACH_ADDR___blk_end_request_all
        WRAP_FOR_DETACH(__blk_end_request_all)
#   else
        TYPED_DETACH(__blk_end_request_all)
#   endif
#endif
#ifndef CAN_WRAP_sigset_from_compat
#   define CAN_WRAP_sigset_from_compat 1
#endif
#if CAN_WRAP_sigset_from_compat
    WRAP_FOR_DETACH(sigset_from_compat)
#endif
#ifndef CAN_WRAP_fasync_alloc
#   define CAN_WRAP_fasync_alloc 1
#endif
#if CAN_WRAP_fasync_alloc
    WRAP_FOR_DETACH(fasync_alloc)
#endif
#ifndef CAN_WRAP___add_wrong_size
#   define CAN_WRAP___add_wrong_size 0
#endif
DETACH(__add_wrong_size)
#ifndef CAN_WRAP_blk_integrity_merge_bio
#   define CAN_WRAP_blk_integrity_merge_bio 1
#endif
#if CAN_WRAP_blk_integrity_merge_bio
    WRAP_FOR_DETACH(blk_integrity_merge_bio)
#endif
#ifndef CAN_WRAP_kill_fasync
#   define CAN_WRAP_kill_fasync 0
#endif
DETACH(kill_fasync)
#ifndef CAN_WRAP_netlink_register_notifier
#   define CAN_WRAP_netlink_register_notifier 1
#endif
#if CAN_WRAP_netlink_register_notifier
    WRAP_FOR_DETACH(netlink_register_notifier)
#endif
#ifndef CAN_WRAP_proc_sched_show_task
#   define CAN_WRAP_proc_sched_show_task 1
#endif
#if CAN_WRAP_proc_sched_show_task
    WRAP_FOR_DETACH(proc_sched_show_task)
#endif
#ifndef CAN_WRAP_elevator_init
#   define CAN_WRAP_elevator_init 1
#endif
#if CAN_WRAP_elevator_init
    WRAP_FOR_DETACH(elevator_init)
#endif
#ifndef CAN_WRAP_out_of_line_wait_on_bit
#   define CAN_WRAP_out_of_line_wait_on_bit 1
#endif
#if CAN_WRAP_out_of_line_wait_on_bit
    WRAP_FOR_DETACH(out_of_line_wait_on_bit)
#endif
#ifndef CAN_WRAP_nohz_balance_enter_idle
#   define CAN_WRAP_nohz_balance_enter_idle 0
#endif
DETACH(nohz_balance_enter_idle)
#ifndef CAN_WRAP_sata_async_notification
#   define CAN_WRAP_sata_async_notification 1
#endif
#if CAN_WRAP_sata_async_notification
    WRAP_FOR_DETACH(sata_async_notification)
#endif
#ifndef CAN_WRAP_jbd2_journal_put_journal_head
#   define CAN_WRAP_jbd2_journal_put_journal_head 1
#endif
#if CAN_WRAP_jbd2_journal_put_journal_head
    WRAP_FOR_DETACH(jbd2_journal_put_journal_head)
#endif
#ifndef CAN_WRAP_init_ISA_irqs
#   define CAN_WRAP_init_ISA_irqs 0
#endif
DETACH(init_ISA_irqs)
#ifndef CAN_WRAP___d_lookup
#   define CAN_WRAP___d_lookup 1
#endif
#if CAN_WRAP___d_lookup
#   ifdef DETACH_ADDR___d_lookup
        WRAP_FOR_DETACH(__d_lookup)
#   else
        TYPED_DETACH(__d_lookup)
#   endif
#endif
#ifndef CAN_WRAP_phy_state_machine
#   define CAN_WRAP_phy_state_machine 1
#endif
#if CAN_WRAP_phy_state_machine
    WRAP_FOR_DETACH(phy_state_machine)
#endif
#ifndef CAN_WRAP_machine_crash_shutdown
#   define CAN_WRAP_machine_crash_shutdown 1
#endif
#if CAN_WRAP_machine_crash_shutdown
    WRAP_FOR_DETACH(machine_crash_shutdown)
#endif
#ifndef CAN_WRAP_zone_reclaimable_pages
#   define CAN_WRAP_zone_reclaimable_pages 1
#endif
#if CAN_WRAP_zone_reclaimable_pages
    WRAP_FOR_DETACH(zone_reclaimable_pages)
#endif
#ifndef CAN_WRAP_nobh_write_end
#   define CAN_WRAP_nobh_write_end 1
#endif
#if CAN_WRAP_nobh_write_end
    WRAP_FOR_DETACH(nobh_write_end)
#endif
#ifndef CAN_WRAP_acpi_bus_hot_remove_device
#   define CAN_WRAP_acpi_bus_hot_remove_device 0
#endif
DETACH(acpi_bus_hot_remove_device)
#ifndef CAN_WRAP_pci_request_region_exclusive
#   define CAN_WRAP_pci_request_region_exclusive 1
#endif
#if CAN_WRAP_pci_request_region_exclusive
    WRAP_FOR_DETACH(pci_request_region_exclusive)
#endif
#ifndef CAN_WRAP_security_audit_rule_init
#   define CAN_WRAP_security_audit_rule_init 0
#endif
DETACH(security_audit_rule_init)
#ifndef CAN_WRAP_irq_alloc_generic_chip
#   define CAN_WRAP_irq_alloc_generic_chip 1
#endif
#if CAN_WRAP_irq_alloc_generic_chip
    WRAP_FOR_DETACH(irq_alloc_generic_chip)
#endif
#ifndef CAN_WRAP_qdisc_watchdog_cancel
#   define CAN_WRAP_qdisc_watchdog_cancel 1
#endif
#if CAN_WRAP_qdisc_watchdog_cancel
    WRAP_FOR_DETACH(qdisc_watchdog_cancel)
#endif
#ifndef CAN_WRAP___put_net
#   define CAN_WRAP___put_net 1
#endif
#if CAN_WRAP___put_net
#   ifdef DETACH_ADDR___put_net
        WRAP_FOR_DETACH(__put_net)
#   else
        TYPED_DETACH(__put_net)
#   endif
#endif
#ifndef CAN_WRAP_security_path_mknod
#   define CAN_WRAP_security_path_mknod 1
#endif
#if CAN_WRAP_security_path_mknod
    WRAP_FOR_DETACH(security_path_mknod)
#endif
#ifndef CAN_WRAP_pcpu_embed_first_chunk
#   define CAN_WRAP_pcpu_embed_first_chunk 1
#endif
#if CAN_WRAP_pcpu_embed_first_chunk
    WRAP_FOR_DETACH(pcpu_embed_first_chunk)
#endif
#ifndef CAN_WRAP_slab_is_available
#   define CAN_WRAP_slab_is_available 0
#endif
DETACH(slab_is_available)
#ifndef CAN_WRAP_restore_online_page_callback
#   define CAN_WRAP_restore_online_page_callback 1
#endif
#if CAN_WRAP_restore_online_page_callback
    WRAP_FOR_DETACH(restore_online_page_callback)
#endif
#ifndef CAN_WRAP_check_wakeup_irqs
#   define CAN_WRAP_check_wakeup_irqs 0
#endif
DETACH(check_wakeup_irqs)
#ifndef CAN_WRAP_pci_vpd_truncate
#   define CAN_WRAP_pci_vpd_truncate 1
#endif
#if CAN_WRAP_pci_vpd_truncate
    WRAP_FOR_DETACH(pci_vpd_truncate)
#endif
#ifndef CAN_WRAP_compat_put_bitmap
#   define CAN_WRAP_compat_put_bitmap 0
#endif
DETACH(compat_put_bitmap)
#ifndef CAN_WRAP_try_to_release_page
#   define CAN_WRAP_try_to_release_page 1
#endif
#if CAN_WRAP_try_to_release_page
    WRAP_FOR_DETACH(try_to_release_page)
#endif
#ifndef CAN_WRAP_pci_try_set_mwi
#   define CAN_WRAP_pci_try_set_mwi 1
#endif
#if CAN_WRAP_pci_try_set_mwi
    WRAP_FOR_DETACH(pci_try_set_mwi)
#endif
#ifndef CAN_WRAP_ata_pci_bmdma_clear_simplex
#   define CAN_WRAP_ata_pci_bmdma_clear_simplex 1
#endif
#if CAN_WRAP_ata_pci_bmdma_clear_simplex
    WRAP_FOR_DETACH(ata_pci_bmdma_clear_simplex)
#endif
#ifndef CAN_WRAP_smp_apic_timer_interrupt
#   define CAN_WRAP_smp_apic_timer_interrupt 1
#endif
#if CAN_WRAP_smp_apic_timer_interrupt
    WRAP_FOR_DETACH(smp_apic_timer_interrupt)
#endif
#ifndef CAN_WRAP_del_gendisk
#   define CAN_WRAP_del_gendisk 1
#endif
#if CAN_WRAP_del_gendisk
    WRAP_FOR_DETACH(del_gendisk)
#endif
#ifndef CAN_WRAP_file_update_time
#   define CAN_WRAP_file_update_time 1
#endif
#if CAN_WRAP_file_update_time
    WRAP_FOR_DETACH(file_update_time)
#endif
#ifndef CAN_WRAP_disconnect_bsp_APIC
#   define CAN_WRAP_disconnect_bsp_APIC 0
#endif
DETACH(disconnect_bsp_APIC)
#ifndef CAN_WRAP_res_counter_init
#   define CAN_WRAP_res_counter_init 1
#endif
#if CAN_WRAP_res_counter_init
    WRAP_FOR_DETACH(res_counter_init)
#endif
#ifndef CAN_WRAP_blk_queue_lld_busy
#   define CAN_WRAP_blk_queue_lld_busy 1
#endif
#if CAN_WRAP_blk_queue_lld_busy
    WRAP_FOR_DETACH(blk_queue_lld_busy)
#endif
#ifndef CAN_WRAP_devtmpfs_mount
#   define CAN_WRAP_devtmpfs_mount 0
#endif
DETACH(devtmpfs_mount)
#ifndef CAN_WRAP_linkwatch_init_dev
#   define CAN_WRAP_linkwatch_init_dev 1
#endif
#if CAN_WRAP_linkwatch_init_dev
    WRAP_FOR_DETACH(linkwatch_init_dev)
#endif
#ifndef CAN_WRAP_pm_stay_awake
#   define CAN_WRAP_pm_stay_awake 1
#endif
#if CAN_WRAP_pm_stay_awake
    WRAP_FOR_DETACH(pm_stay_awake)
#endif
#ifndef CAN_WRAP_mii_check_link
#   define CAN_WRAP_mii_check_link 1
#endif
#if CAN_WRAP_mii_check_link
    WRAP_FOR_DETACH(mii_check_link)
#endif
#ifndef CAN_WRAP_ata_std_sched_eh
#   define CAN_WRAP_ata_std_sched_eh 1
#endif
#if CAN_WRAP_ata_std_sched_eh
    WRAP_FOR_DETACH(ata_std_sched_eh)
#endif
#ifndef CAN_WRAP_ata_host_alloc_pinfo
#   define CAN_WRAP_ata_host_alloc_pinfo 1
#endif
#if CAN_WRAP_ata_host_alloc_pinfo
    WRAP_FOR_DETACH(ata_host_alloc_pinfo)
#endif
#ifndef CAN_WRAP_proc_ns_inode
#   define CAN_WRAP_proc_ns_inode 1
#endif
#if CAN_WRAP_proc_ns_inode
    WRAP_FOR_DETACH(proc_ns_inode)
#endif
#ifndef CAN_WRAP_thermal_interrupt
#   define CAN_WRAP_thermal_interrupt 0
#endif
DETACH(thermal_interrupt)
#ifndef CAN_WRAP_compat_sys_mq_open
#   define CAN_WRAP_compat_sys_mq_open 1
#endif
#if CAN_WRAP_compat_sys_mq_open
    WRAP_FOR_DETACH(compat_sys_mq_open)
#endif
#ifndef CAN_WRAP_sg_miter_start
#   define CAN_WRAP_sg_miter_start 1
#endif
#if CAN_WRAP_sg_miter_start
    WRAP_FOR_DETACH(sg_miter_start)
#endif
#ifndef CAN_WRAP_seq_hlist_start_rcu
#   define CAN_WRAP_seq_hlist_start_rcu 1
#endif
#if CAN_WRAP_seq_hlist_start_rcu
    WRAP_FOR_DETACH(seq_hlist_start_rcu)
#endif
#ifndef CAN_WRAP___vmalloc_node_range
#   define CAN_WRAP___vmalloc_node_range 1
#endif
#if CAN_WRAP___vmalloc_node_range
#   ifdef DETACH_ADDR___vmalloc_node_range
        WRAP_FOR_DETACH(__vmalloc_node_range)
#   else
        TYPED_DETACH(__vmalloc_node_range)
#   endif
#endif
#ifndef CAN_WRAP_vfs_rename
#   define CAN_WRAP_vfs_rename 1
#endif
#if CAN_WRAP_vfs_rename
    WRAP_FOR_DETACH(vfs_rename)
#endif
#ifndef CAN_WRAP_acpi_get_vendor_resource
#   define CAN_WRAP_acpi_get_vendor_resource 1
#endif
#if CAN_WRAP_acpi_get_vendor_resource
    WRAP_FOR_DETACH(acpi_get_vendor_resource)
#endif
#ifndef CAN_WRAP_complete_and_exit
#   define CAN_WRAP_complete_and_exit 1
#endif
#if CAN_WRAP_complete_and_exit
    DETACH(complete_and_exit)
#endif
#ifndef CAN_WRAP_bio_integrity_init
#   define CAN_WRAP_bio_integrity_init 0
#endif
DETACH(bio_integrity_init)
#ifndef CAN_WRAP_cap_ptrace_traceme
#   define CAN_WRAP_cap_ptrace_traceme 1
#endif
#if CAN_WRAP_cap_ptrace_traceme
    WRAP_FOR_DETACH(cap_ptrace_traceme)
#endif
#ifndef CAN_WRAP_acpi_remove_notify_handler
#   define CAN_WRAP_acpi_remove_notify_handler 1
#endif
#if CAN_WRAP_acpi_remove_notify_handler
    WRAP_FOR_DETACH(acpi_remove_notify_handler)
#endif
#ifndef CAN_WRAP_on_each_cpu
#   define CAN_WRAP_on_each_cpu 1
#endif
#if CAN_WRAP_on_each_cpu
    WRAP_FOR_DETACH(on_each_cpu)
#endif
#ifndef CAN_WRAP_acpi_unregister_ioapic
#   define CAN_WRAP_acpi_unregister_ioapic 0
#endif
DETACH(acpi_unregister_ioapic)
#ifndef CAN_WRAP_security_file_permission
#   define CAN_WRAP_security_file_permission 1
#endif
#if CAN_WRAP_security_file_permission
    WRAP_FOR_DETACH(security_file_permission)
#endif
#ifndef CAN_WRAP_find_mergeable_anon_vma
#   define CAN_WRAP_find_mergeable_anon_vma 1
#endif
#if CAN_WRAP_find_mergeable_anon_vma
    WRAP_FOR_DETACH(find_mergeable_anon_vma)
#endif
#ifndef CAN_WRAP_kobj_ns_type_register
#   define CAN_WRAP_kobj_ns_type_register 1
#endif
#if CAN_WRAP_kobj_ns_type_register
    WRAP_FOR_DETACH(kobj_ns_type_register)
#endif
#ifndef CAN_WRAP_dqput
#   define CAN_WRAP_dqput 1
#endif
#if CAN_WRAP_dqput
    WRAP_FOR_DETACH(dqput)
#endif
#ifndef CAN_WRAP_dm_table_put
#   define CAN_WRAP_dm_table_put 1
#endif
#if CAN_WRAP_dm_table_put
    WRAP_FOR_DETACH(dm_table_put)
#endif
#ifndef CAN_WRAP_blk_rq_count_integrity_sg
#   define CAN_WRAP_blk_rq_count_integrity_sg 1
#endif
#if CAN_WRAP_blk_rq_count_integrity_sg
    WRAP_FOR_DETACH(blk_rq_count_integrity_sg)
#endif
#ifndef CAN_WRAP_add_swap_extent
#   define CAN_WRAP_add_swap_extent 1
#endif
#if CAN_WRAP_add_swap_extent
    WRAP_FOR_DETACH(add_swap_extent)
#endif
#ifndef CAN_WRAP_kobject_init
#   define CAN_WRAP_kobject_init 1
#endif
#if CAN_WRAP_kobject_init
    WRAP_FOR_DETACH(kobject_init)
#endif
#ifndef CAN_WRAP_connect_bsp_APIC
#   define CAN_WRAP_connect_bsp_APIC 0
#endif
DETACH(connect_bsp_APIC)
#ifndef CAN_WRAP_sync_filesystem
#   define CAN_WRAP_sync_filesystem 1
#endif
#if CAN_WRAP_sync_filesystem
    WRAP_FOR_DETACH(sync_filesystem)
#endif
#ifndef CAN_WRAP_kobject_get
#   define CAN_WRAP_kobject_get 1
#endif
#if CAN_WRAP_kobject_get
    WRAP_FOR_DETACH(kobject_get)
#endif
#ifndef CAN_WRAP_generic_access_phys
#   define CAN_WRAP_generic_access_phys 1
#endif
#if CAN_WRAP_generic_access_phys
    WRAP_FOR_DETACH(generic_access_phys)
#endif
#ifndef CAN_WRAP_kswapd_run
#   define CAN_WRAP_kswapd_run 0
#endif
DETACH(kswapd_run)
#ifndef CAN_WRAP_inode_sub_rsv_space
#   define CAN_WRAP_inode_sub_rsv_space 1
#endif
#if CAN_WRAP_inode_sub_rsv_space
    WRAP_FOR_DETACH(inode_sub_rsv_space)
#endif
#ifndef CAN_WRAP_device_rename
#   define CAN_WRAP_device_rename 1
#endif
#if CAN_WRAP_device_rename
    WRAP_FOR_DETACH(device_rename)
#endif
#ifndef CAN_WRAP_security_path_symlink
#   define CAN_WRAP_security_path_symlink 1
#endif
#if CAN_WRAP_security_path_symlink
    WRAP_FOR_DETACH(security_path_symlink)
#endif
#ifndef CAN_WRAP_filp_close
#   define CAN_WRAP_filp_close 1
#endif
#if CAN_WRAP_filp_close
    WRAP_FOR_DETACH(filp_close)
#endif
#ifndef CAN_WRAP_blkdev_put
#   define CAN_WRAP_blkdev_put 1
#endif
#if CAN_WRAP_blkdev_put
    WRAP_FOR_DETACH(blkdev_put)
#endif
#ifndef CAN_WRAP___jbd2_journal_remove_checkpoint
#   define CAN_WRAP___jbd2_journal_remove_checkpoint 1
#endif
#if CAN_WRAP___jbd2_journal_remove_checkpoint
#   ifdef DETACH_ADDR___jbd2_journal_remove_checkpoint
        WRAP_FOR_DETACH(__jbd2_journal_remove_checkpoint)
#   else
        TYPED_DETACH(__jbd2_journal_remove_checkpoint)
#   endif
#endif
#ifndef CAN_WRAP_generic_writepages
#   define CAN_WRAP_generic_writepages 1
#endif
#if CAN_WRAP_generic_writepages
    WRAP_FOR_DETACH(generic_writepages)
#endif
#ifndef CAN_WRAP_ht_destroy_irq
#   define CAN_WRAP_ht_destroy_irq 0
#endif
DETACH(ht_destroy_irq)
#ifndef CAN_WRAP_enable_IO_APIC
#   define CAN_WRAP_enable_IO_APIC 0
#endif
DETACH(enable_IO_APIC)
#ifndef CAN_WRAP_down
#   define CAN_WRAP_down 1
#endif
#if CAN_WRAP_down
    WRAP_FOR_DETACH(down)
#endif
#ifndef CAN_WRAP_rcu_is_cpu_idle
#   define CAN_WRAP_rcu_is_cpu_idle 0
#endif
DETACH(rcu_is_cpu_idle)
#ifndef CAN_WRAP_clockevents_exchange_device
#   define CAN_WRAP_clockevents_exchange_device 1
#endif
#if CAN_WRAP_clockevents_exchange_device
    WRAP_FOR_DETACH(clockevents_exchange_device)
#endif
#ifndef CAN_WRAP_dma_generic_free_coherent
#   define CAN_WRAP_dma_generic_free_coherent 1
#endif
#if CAN_WRAP_dma_generic_free_coherent
    WRAP_FOR_DETACH(dma_generic_free_coherent)
#endif
#ifndef CAN_WRAP_jbd2_journal_test_revoke
#   define CAN_WRAP_jbd2_journal_test_revoke 1
#endif
#if CAN_WRAP_jbd2_journal_test_revoke
    WRAP_FOR_DETACH(jbd2_journal_test_revoke)
#endif
#ifndef CAN_WRAP_pci_dev_driver
#   define CAN_WRAP_pci_dev_driver 1
#endif
#if CAN_WRAP_pci_dev_driver
    WRAP_FOR_DETACH(pci_dev_driver)
#endif
#ifndef CAN_WRAP_ndo_dflt_fdb_dump
#   define CAN_WRAP_ndo_dflt_fdb_dump 1
#endif
#if CAN_WRAP_ndo_dflt_fdb_dump
    WRAP_FOR_DETACH(ndo_dflt_fdb_dump)
#endif
#ifndef CAN_WRAP___skb_get_rxhash
#   define CAN_WRAP___skb_get_rxhash 1
#endif
#if CAN_WRAP___skb_get_rxhash
#   ifdef DETACH_ADDR___skb_get_rxhash
        WRAP_FOR_DETACH(__skb_get_rxhash)
#   else
        TYPED_DETACH(__skb_get_rxhash)
#   endif
#endif
#ifndef CAN_WRAP_compat_sys_mq_getsetattr
#   define CAN_WRAP_compat_sys_mq_getsetattr 1
#endif
#if CAN_WRAP_compat_sys_mq_getsetattr
    WRAP_FOR_DETACH(compat_sys_mq_getsetattr)
#endif
#ifndef CAN_WRAP_mii_ethtool_gset
#   define CAN_WRAP_mii_ethtool_gset 1
#endif
#if CAN_WRAP_mii_ethtool_gset
    WRAP_FOR_DETACH(mii_ethtool_gset)
#endif
#ifndef CAN_WRAP_phy_device_register
#   define CAN_WRAP_phy_device_register 1
#endif
#if CAN_WRAP_phy_device_register
    WRAP_FOR_DETACH(phy_device_register)
#endif
#ifndef CAN_WRAP_d_splice_alias
#   define CAN_WRAP_d_splice_alias 1
#endif
#if CAN_WRAP_d_splice_alias
    WRAP_FOR_DETACH(d_splice_alias)
#endif
#ifndef CAN_WRAP___filemap_fdatawrite_range
#   define CAN_WRAP___filemap_fdatawrite_range 1
#endif
#if CAN_WRAP___filemap_fdatawrite_range
#   ifdef DETACH_ADDR___filemap_fdatawrite_range
        WRAP_FOR_DETACH(__filemap_fdatawrite_range)
#   else
        TYPED_DETACH(__filemap_fdatawrite_range)
#   endif
#endif
#ifndef CAN_WRAP_cgroupstats_build
#   define CAN_WRAP_cgroupstats_build 1
#endif
#if CAN_WRAP_cgroupstats_build
    WRAP_FOR_DETACH(cgroupstats_build)
#endif
#ifndef CAN_WRAP_disk_name
#   define CAN_WRAP_disk_name 1
#endif
#if CAN_WRAP_disk_name
    WRAP_FOR_DETACH(disk_name)
#endif
#ifndef CAN_WRAP_early_acpi_os_unmap_memory
#   define CAN_WRAP_early_acpi_os_unmap_memory 0
#endif
DETACH(early_acpi_os_unmap_memory)
#ifndef CAN_WRAP_sched_setscheduler
#   define CAN_WRAP_sched_setscheduler 1
#endif
#if CAN_WRAP_sched_setscheduler
    WRAP_FOR_DETACH(sched_setscheduler)
#endif
#ifndef CAN_WRAP_sock_init_data
#   define CAN_WRAP_sock_init_data 1
#endif
#if CAN_WRAP_sock_init_data
    WRAP_FOR_DETACH(sock_init_data)
#endif
#ifndef CAN_WRAP_dentry_open
#   define CAN_WRAP_dentry_open 1
#endif
#if CAN_WRAP_dentry_open
    WRAP_FOR_DETACH(dentry_open)
#endif
#ifndef CAN_WRAP_hrtimer_start
#   define CAN_WRAP_hrtimer_start 1
#endif
#if CAN_WRAP_hrtimer_start
    WRAP_FOR_DETACH(hrtimer_start)
#endif
#ifndef CAN_WRAP_pcpu_get_vm_areas
#   define CAN_WRAP_pcpu_get_vm_areas 0
#endif
DETACH(pcpu_get_vm_areas)
#ifndef CAN_WRAP_neigh_app_ns
#   define CAN_WRAP_neigh_app_ns 1
#endif
#if CAN_WRAP_neigh_app_ns
    WRAP_FOR_DETACH(neigh_app_ns)
#endif
#ifndef CAN_WRAP_synchronize_srcu_expedited
#   define CAN_WRAP_synchronize_srcu_expedited 1
#endif
#if CAN_WRAP_synchronize_srcu_expedited
    WRAP_FOR_DETACH(synchronize_srcu_expedited)
#endif
#ifndef CAN_WRAP_pcie_set_mps
#   define CAN_WRAP_pcie_set_mps 1
#endif
#if CAN_WRAP_pcie_set_mps
    WRAP_FOR_DETACH(pcie_set_mps)
#endif
#ifndef CAN_WRAP_acpi_enable_wakeup_device_power
#   define CAN_WRAP_acpi_enable_wakeup_device_power 1
#endif
#if CAN_WRAP_acpi_enable_wakeup_device_power
    WRAP_FOR_DETACH(acpi_enable_wakeup_device_power)
#endif
#ifndef CAN_WRAP_ata_std_error_handler
#   define CAN_WRAP_ata_std_error_handler 1
#endif
#if CAN_WRAP_ata_std_error_handler
    WRAP_FOR_DETACH(ata_std_error_handler)
#endif
#ifndef CAN_WRAP_pci_clear_master
#   define CAN_WRAP_pci_clear_master 1
#endif
#if CAN_WRAP_pci_clear_master
    WRAP_FOR_DETACH(pci_clear_master)
#endif
#ifndef CAN_WRAP_phy_start
#   define CAN_WRAP_phy_start 1
#endif
#if CAN_WRAP_phy_start
    WRAP_FOR_DETACH(phy_start)
#endif
#ifndef CAN_WRAP_blk_queue_init_tags
#   define CAN_WRAP_blk_queue_init_tags 1
#endif
#if CAN_WRAP_blk_queue_init_tags
    WRAP_FOR_DETACH(blk_queue_init_tags)
#endif
#ifndef CAN_WRAP_acpi_leave_sleep_state
#   define CAN_WRAP_acpi_leave_sleep_state 0
#endif
DETACH(acpi_leave_sleep_state)
#ifndef CAN_WRAP_bio_integrity_add_page
#   define CAN_WRAP_bio_integrity_add_page 1
#endif
#if CAN_WRAP_bio_integrity_add_page
    WRAP_FOR_DETACH(bio_integrity_add_page)
#endif
#ifndef CAN_WRAP_clock_t_to_jiffies
#   define CAN_WRAP_clock_t_to_jiffies 0
#endif
DETACH(clock_t_to_jiffies)
#ifndef CAN_WRAP_init_rootfs
#   define CAN_WRAP_init_rootfs 0
#endif
DETACH(init_rootfs)
#ifndef CAN_WRAP_ata_platform_remove_one
#   define CAN_WRAP_ata_platform_remove_one 1
#endif
#if CAN_WRAP_ata_platform_remove_one
    WRAP_FOR_DETACH(ata_platform_remove_one)
#endif
#ifndef CAN_WRAP_netif_receive_skb
#   define CAN_WRAP_netif_receive_skb 1
#endif
#if CAN_WRAP_netif_receive_skb
    WRAP_FOR_DETACH(netif_receive_skb)
#endif
#ifndef CAN_WRAP_acpi_enable
#   define CAN_WRAP_acpi_enable 0
#endif
DETACH(acpi_enable)
#ifndef CAN_WRAP_jbd2_journal_abort
#   define CAN_WRAP_jbd2_journal_abort 1
#endif
#if CAN_WRAP_jbd2_journal_abort
    WRAP_FOR_DETACH(jbd2_journal_abort)
#endif
#ifndef CAN_WRAP___cond_resched_softirq
#   define CAN_WRAP___cond_resched_softirq 0
#endif
DETACH(__cond_resched_softirq)
#ifndef CAN_WRAP_pci_back_from_sleep
#   define CAN_WRAP_pci_back_from_sleep 1
#endif
#if CAN_WRAP_pci_back_from_sleep
    WRAP_FOR_DETACH(pci_back_from_sleep)
#endif
#ifndef CAN_WRAP_register_qdisc
#   define CAN_WRAP_register_qdisc 1
#endif
#if CAN_WRAP_register_qdisc
    WRAP_FOR_DETACH(register_qdisc)
#endif
#ifndef CAN_WRAP_phy_scan_fixups
#   define CAN_WRAP_phy_scan_fixups 1
#endif
#if CAN_WRAP_phy_scan_fixups
    WRAP_FOR_DETACH(phy_scan_fixups)
#endif
#ifndef CAN_WRAP_invalidate_inode_buffers
#   define CAN_WRAP_invalidate_inode_buffers 1
#endif
#if CAN_WRAP_invalidate_inode_buffers
    WRAP_FOR_DETACH(invalidate_inode_buffers)
#endif
#ifndef CAN_WRAP_acpi_os_release_object
#   define CAN_WRAP_acpi_os_release_object 1
#endif
#if CAN_WRAP_acpi_os_release_object
    WRAP_FOR_DETACH(acpi_os_release_object)
#endif
#ifndef CAN_WRAP_posix_lock_file_wait
#   define CAN_WRAP_posix_lock_file_wait 1
#endif
#if CAN_WRAP_posix_lock_file_wait
    WRAP_FOR_DETACH(posix_lock_file_wait)
#endif
#ifndef CAN_WRAP_key_fsgid_changed
#   define CAN_WRAP_key_fsgid_changed 1
#endif
#if CAN_WRAP_key_fsgid_changed
    WRAP_FOR_DETACH(key_fsgid_changed)
#endif
#ifndef CAN_WRAP___neigh_for_each_release
#   define CAN_WRAP___neigh_for_each_release 1
#endif
#if CAN_WRAP___neigh_for_each_release
#   ifdef DETACH_ADDR___neigh_for_each_release
        WRAP_FOR_DETACH(__neigh_for_each_release)
#   else
        TYPED_DETACH(__neigh_for_each_release)
#   endif
#endif
#ifndef CAN_WRAP_native_send_call_func_single_ipi
#   define CAN_WRAP_native_send_call_func_single_ipi 0
#endif
DETACH(native_send_call_func_single_ipi)
#ifndef CAN_WRAP_iov_iter_fault_in_readable
#   define CAN_WRAP_iov_iter_fault_in_readable 1
#endif
#if CAN_WRAP_iov_iter_fault_in_readable
    WRAP_FOR_DETACH(iov_iter_fault_in_readable)
#endif
#ifndef CAN_WRAP___acpi_device_sleep_wake
#   define CAN_WRAP___acpi_device_sleep_wake 1
#endif
#if CAN_WRAP___acpi_device_sleep_wake
#   ifdef DETACH_ADDR___acpi_device_sleep_wake
        WRAP_FOR_DETACH(__acpi_device_sleep_wake)
#   else
        TYPED_DETACH(__acpi_device_sleep_wake)
#   endif
#endif
#ifndef CAN_WRAP_add_swap_count_continuation
#   define CAN_WRAP_add_swap_count_continuation 1
#endif
#if CAN_WRAP_add_swap_count_continuation
    WRAP_FOR_DETACH(add_swap_count_continuation)
#endif
#ifndef CAN_WRAP_blk_queue_merge_bvec
#   define CAN_WRAP_blk_queue_merge_bvec 1
#endif
#if CAN_WRAP_blk_queue_merge_bvec
    WRAP_FOR_DETACH(blk_queue_merge_bvec)
#endif
#ifndef CAN_WRAP_writeback_inodes_sb
#   define CAN_WRAP_writeback_inodes_sb 1
#endif
#if CAN_WRAP_writeback_inodes_sb
    WRAP_FOR_DETACH(writeback_inodes_sb)
#endif
#ifndef CAN_WRAP_memory_present
#   define CAN_WRAP_memory_present 0
#endif
DETACH(memory_present)
#ifndef CAN_WRAP_init_cpu_to_node
#   define CAN_WRAP_init_cpu_to_node 0
#endif
DETACH(init_cpu_to_node)
#ifndef CAN_WRAP_f_getown
#   define CAN_WRAP_f_getown 1
#endif
#if CAN_WRAP_f_getown
    WRAP_FOR_DETACH(f_getown)
#endif
#ifndef CAN_WRAP_machine_power_off
#   define CAN_WRAP_machine_power_off 0
#endif
DETACH(machine_power_off)
#ifndef CAN_WRAP_ata_do_eh
#   define CAN_WRAP_ata_do_eh 1
#endif
#if CAN_WRAP_ata_do_eh
    WRAP_FOR_DETACH(ata_do_eh)
#endif
#ifndef CAN_WRAP_pci_wake_from_d3
#   define CAN_WRAP_pci_wake_from_d3 1
#endif
#if CAN_WRAP_pci_wake_from_d3
    WRAP_FOR_DETACH(pci_wake_from_d3)
#endif
#ifndef CAN_WRAP_jbd2_buffer_frozen_trigger
#   define CAN_WRAP_jbd2_buffer_frozen_trigger 1
#endif
#if CAN_WRAP_jbd2_buffer_frozen_trigger
    WRAP_FOR_DETACH(jbd2_buffer_frozen_trigger)
#endif
#ifndef CAN_WRAP_arch_task_cache_init
#   define CAN_WRAP_arch_task_cache_init 0
#endif
DETACH(arch_task_cache_init)
#ifndef CAN_WRAP_nf_unregister_hooks
#   define CAN_WRAP_nf_unregister_hooks 1
#endif
#if CAN_WRAP_nf_unregister_hooks
    WRAP_FOR_DETACH(nf_unregister_hooks)
#endif
#ifndef CAN_WRAP_delete_partition
#   define CAN_WRAP_delete_partition 1
#endif
#if CAN_WRAP_delete_partition
    WRAP_FOR_DETACH(delete_partition)
#endif
#ifndef CAN_WRAP_sk_stop_timer
#   define CAN_WRAP_sk_stop_timer 1
#endif
#if CAN_WRAP_sk_stop_timer
    WRAP_FOR_DETACH(sk_stop_timer)
#endif
#ifndef CAN_WRAP_irq_move_cleanup_interrupt
#   define CAN_WRAP_irq_move_cleanup_interrupt 0
#endif
DETACH(irq_move_cleanup_interrupt)
#ifndef CAN_WRAP_set_pte_vaddr
#   define CAN_WRAP_set_pte_vaddr 1
#endif
#if CAN_WRAP_set_pte_vaddr
    WRAP_FOR_DETACH(set_pte_vaddr)
#endif
#ifndef CAN_WRAP_idr_init
#   define CAN_WRAP_idr_init 1
#endif
#if CAN_WRAP_idr_init
    WRAP_FOR_DETACH(idr_init)
#endif
#ifndef CAN_WRAP_net_disable_timestamp
#   define CAN_WRAP_net_disable_timestamp 0
#endif
DETACH(net_disable_timestamp)
#ifndef CAN_WRAP_disable_local_APIC
#   define CAN_WRAP_disable_local_APIC 0
#endif
DETACH(disable_local_APIC)
#ifndef CAN_WRAP_pcibios_scan_specific_bus
#   define CAN_WRAP_pcibios_scan_specific_bus 0
#endif
DETACH(pcibios_scan_specific_bus)
#ifndef CAN_WRAP_rt_mutex_getprio
#   define CAN_WRAP_rt_mutex_getprio 1
#endif
#if CAN_WRAP_rt_mutex_getprio
    WRAP_FOR_DETACH(rt_mutex_getprio)
#endif
#ifndef CAN_WRAP_security_sb_mount
#   define CAN_WRAP_security_sb_mount 1
#endif
#if CAN_WRAP_security_sb_mount
    WRAP_FOR_DETACH(security_sb_mount)
#endif
#ifndef CAN_WRAP_d_find_any_alias
#   define CAN_WRAP_d_find_any_alias 1
#endif
#if CAN_WRAP_d_find_any_alias
    WRAP_FOR_DETACH(d_find_any_alias)
#endif
#ifndef CAN_WRAP_dma_pool_destroy
#   define CAN_WRAP_dma_pool_destroy 1
#endif
#if CAN_WRAP_dma_pool_destroy
    WRAP_FOR_DETACH(dma_pool_destroy)
#endif
#ifndef CAN_WRAP_device_store_int
#   define CAN_WRAP_device_store_int 1
#endif
#if CAN_WRAP_device_store_int
    WRAP_FOR_DETACH(device_store_int)
#endif
#ifndef CAN_WRAP_redirty_page_for_writepage
#   define CAN_WRAP_redirty_page_for_writepage 1
#endif
#if CAN_WRAP_redirty_page_for_writepage
    WRAP_FOR_DETACH(redirty_page_for_writepage)
#endif
#ifndef CAN_WRAP_dentry_update_name_case
#   define CAN_WRAP_dentry_update_name_case 1
#endif
#if CAN_WRAP_dentry_update_name_case
    WRAP_FOR_DETACH(dentry_update_name_case)
#endif
#ifndef CAN_WRAP_mark_rodata_ro
#   define CAN_WRAP_mark_rodata_ro 0
#endif
DETACH(mark_rodata_ro)
#ifndef CAN_WRAP_pci_scan_bus
#   define CAN_WRAP_pci_scan_bus 1
#endif
#if CAN_WRAP_pci_scan_bus
    WRAP_FOR_DETACH(pci_scan_bus)
#endif
#ifndef CAN_WRAP_acpi_check_address_range
#   define CAN_WRAP_acpi_check_address_range 0
#endif
DETACH(acpi_check_address_range)
#ifndef CAN_WRAP_gnet_stats_finish_copy
#   define CAN_WRAP_gnet_stats_finish_copy 1
#endif
#if CAN_WRAP_gnet_stats_finish_copy
    WRAP_FOR_DETACH(gnet_stats_finish_copy)
#endif
#ifndef CAN_WRAP_security_socket_setsockopt
#   define CAN_WRAP_security_socket_setsockopt 1
#endif
#if CAN_WRAP_security_socket_setsockopt
    WRAP_FOR_DETACH(security_socket_setsockopt)
#endif
#ifndef CAN_WRAP___dma_request_channel
#   define CAN_WRAP___dma_request_channel 1
#endif
#if CAN_WRAP___dma_request_channel
#   ifdef DETACH_ADDR___dma_request_channel
        WRAP_FOR_DETACH(__dma_request_channel)
#   else
        TYPED_DETACH(__dma_request_channel)
#   endif
#endif
#ifndef CAN_WRAP_blkdev_fsync
#   define CAN_WRAP_blkdev_fsync 1
#endif
#if CAN_WRAP_blkdev_fsync
    WRAP_FOR_DETACH(blkdev_fsync)
#endif
#ifndef CAN_WRAP_request_firmware
#   define CAN_WRAP_request_firmware 1
#endif
#if CAN_WRAP_request_firmware
    WRAP_FOR_DETACH(request_firmware)
#endif
#ifndef CAN_WRAP_security_d_instantiate
#   define CAN_WRAP_security_d_instantiate 1
#endif
#if CAN_WRAP_security_d_instantiate
    WRAP_FOR_DETACH(security_d_instantiate)
#endif
#ifndef CAN_WRAP_request_resource_conflict
#   define CAN_WRAP_request_resource_conflict 1
#endif
#if CAN_WRAP_request_resource_conflict
    WRAP_FOR_DETACH(request_resource_conflict)
#endif
#ifndef CAN_WRAP_elv_former_request
#   define CAN_WRAP_elv_former_request 1
#endif
#if CAN_WRAP_elv_former_request
    WRAP_FOR_DETACH(elv_former_request)
#endif
#ifndef CAN_WRAP_schedule_work
#   define CAN_WRAP_schedule_work 1
#endif
#if CAN_WRAP_schedule_work
    WRAP_FOR_DETACH(schedule_work)
#endif
#ifndef CAN_WRAP_kstrtol_from_user
#   define CAN_WRAP_kstrtol_from_user 0
#endif
DETACH(kstrtol_from_user)
#ifndef CAN_WRAP_d_move
#   define CAN_WRAP_d_move 1
#endif
#if CAN_WRAP_d_move
    WRAP_FOR_DETACH(d_move)
#endif
#ifndef CAN_WRAP_kernel_accept
#   define CAN_WRAP_kernel_accept 1
#endif
#if CAN_WRAP_kernel_accept
    WRAP_FOR_DETACH(kernel_accept)
#endif
#ifndef CAN_WRAP_kobject_add
#   define CAN_WRAP_kobject_add 1
#endif
#if CAN_WRAP_kobject_add
    WRAP_FOR_DETACH(kobject_add)
#endif
#ifndef CAN_WRAP_acpi_os_initialize
#   define CAN_WRAP_acpi_os_initialize 0
#endif
DETACH(acpi_os_initialize)
#ifndef CAN_WRAP_compat_sys_io_getevents
#   define CAN_WRAP_compat_sys_io_getevents 1
#endif
#if CAN_WRAP_compat_sys_io_getevents
    WRAP_FOR_DETACH(compat_sys_io_getevents)
#endif
#ifndef CAN_WRAP_register_acpi_bus_type
#   define CAN_WRAP_register_acpi_bus_type 1
#endif
#if CAN_WRAP_register_acpi_bus_type
    WRAP_FOR_DETACH(register_acpi_bus_type)
#endif
#ifndef CAN_WRAP_iowrite8
#   define CAN_WRAP_iowrite8 0
#endif
DETACH(iowrite8)
#ifndef CAN_WRAP_irq_enter
#   define CAN_WRAP_irq_enter 0
#endif
DETACH(irq_enter)
#ifndef CAN_WRAP_page_cache_sync_readahead
#   define CAN_WRAP_page_cache_sync_readahead 1
#endif
#if CAN_WRAP_page_cache_sync_readahead
    WRAP_FOR_DETACH(page_cache_sync_readahead)
#endif
#ifndef CAN_WRAP_blk_queue_bounce_limit
#   define CAN_WRAP_blk_queue_bounce_limit 1
#endif
#if CAN_WRAP_blk_queue_bounce_limit
    WRAP_FOR_DETACH(blk_queue_bounce_limit)
#endif
#ifndef CAN_WRAP_res_counter_read
#   define CAN_WRAP_res_counter_read 1
#endif
#if CAN_WRAP_res_counter_read
    WRAP_FOR_DETACH(res_counter_read)
#endif
#ifndef CAN_WRAP_strnicmp
#   define CAN_WRAP_strnicmp 0
#endif
DETACH(strnicmp)
#ifndef CAN_WRAP_dm_requeue_unmapped_request
#   define CAN_WRAP_dm_requeue_unmapped_request 1
#endif
#if CAN_WRAP_dm_requeue_unmapped_request
    WRAP_FOR_DETACH(dm_requeue_unmapped_request)
#endif
#ifndef CAN_WRAP_jbd2_journal_get_create_access
#   define CAN_WRAP_jbd2_journal_get_create_access 1
#endif
#if CAN_WRAP_jbd2_journal_get_create_access
    WRAP_FOR_DETACH(jbd2_journal_get_create_access)
#endif
#ifndef CAN_WRAP_native_teardown_msi_irq
#   define CAN_WRAP_native_teardown_msi_irq 0
#endif
DETACH(native_teardown_msi_irq)
#ifndef CAN_WRAP_show_regs_common
#   define CAN_WRAP_show_regs_common 0
#endif
DETACH(show_regs_common)
#ifndef CAN_WRAP___bitmap_full
#   define CAN_WRAP___bitmap_full 0
#endif
DETACH(__bitmap_full)
#ifndef CAN_WRAP_filemap_write_and_wait_range
#   define CAN_WRAP_filemap_write_and_wait_range 1
#endif
#if CAN_WRAP_filemap_write_and_wait_range
    WRAP_FOR_DETACH(filemap_write_and_wait_range)
#endif
#ifndef CAN_WRAP_dev_add_offload
#   define CAN_WRAP_dev_add_offload 1
#endif
#if CAN_WRAP_dev_add_offload
    WRAP_FOR_DETACH(dev_add_offload)
#endif
#ifndef CAN_WRAP_kthread_unpark
#   define CAN_WRAP_kthread_unpark 1
#endif
#if CAN_WRAP_kthread_unpark
    WRAP_FOR_DETACH(kthread_unpark)
#endif
#ifndef CAN_WRAP_security_task_setscheduler
#   define CAN_WRAP_security_task_setscheduler 1
#endif
#if CAN_WRAP_security_task_setscheduler
    WRAP_FOR_DETACH(security_task_setscheduler)
#endif
#ifndef CAN_WRAP_mdiobus_read
#   define CAN_WRAP_mdiobus_read 1
#endif
#if CAN_WRAP_mdiobus_read
    WRAP_FOR_DETACH(mdiobus_read)
#endif
#ifndef CAN_WRAP_kern_path_locked
#   define CAN_WRAP_kern_path_locked 1
#endif
#if CAN_WRAP_kern_path_locked
    WRAP_FOR_DETACH(kern_path_locked)
#endif
#ifndef CAN_WRAP_security_key_permission
#   define CAN_WRAP_security_key_permission 1
#endif
#if CAN_WRAP_security_key_permission
    WRAP_FOR_DETACH(security_key_permission)
#endif
#ifndef CAN_WRAP_do_fallocate
#   define CAN_WRAP_do_fallocate 1
#endif
#if CAN_WRAP_do_fallocate
    WRAP_FOR_DETACH(do_fallocate)
#endif
#ifndef CAN_WRAP_crypto_ahash_digest
#   define CAN_WRAP_crypto_ahash_digest 1
#endif
#if CAN_WRAP_crypto_ahash_digest
    WRAP_FOR_DETACH(crypto_ahash_digest)
#endif
#ifndef CAN_WRAP_pm_generic_thaw
#   define CAN_WRAP_pm_generic_thaw 1
#endif
#if CAN_WRAP_pm_generic_thaw
    WRAP_FOR_DETACH(pm_generic_thaw)
#endif
#ifndef CAN_WRAP_security_task_setpgid
#   define CAN_WRAP_security_task_setpgid 1
#endif
#if CAN_WRAP_security_task_setpgid
    WRAP_FOR_DETACH(security_task_setpgid)
#endif
#ifndef CAN_WRAP_pci_hp_create_module_link
#   define CAN_WRAP_pci_hp_create_module_link 1
#endif
#if CAN_WRAP_pci_hp_create_module_link
    WRAP_FOR_DETACH(pci_hp_create_module_link)
#endif
#ifndef CAN_WRAP_f_setown
#   define CAN_WRAP_f_setown 1
#endif
#if CAN_WRAP_f_setown
    WRAP_FOR_DETACH(f_setown)
#endif
#ifndef CAN_WRAP_dev_pm_put_subsys_data
#   define CAN_WRAP_dev_pm_put_subsys_data 1
#endif
#if CAN_WRAP_dev_pm_put_subsys_data
    WRAP_FOR_DETACH(dev_pm_put_subsys_data)
#endif
#ifndef CAN_WRAP_strcasecmp
#   define CAN_WRAP_strcasecmp 0
#endif
DETACH(strcasecmp)
#ifndef CAN_WRAP_security_secctx_to_secid
#   define CAN_WRAP_security_secctx_to_secid 0
#endif
DETACH(security_secctx_to_secid)
#ifndef CAN_WRAP_msrs_alloc
#   define CAN_WRAP_msrs_alloc 1
#endif
#if CAN_WRAP_msrs_alloc
    WRAP_FOR_DETACH(msrs_alloc)
#endif
#ifndef CAN_WRAP_get_unmapped_area
#   define CAN_WRAP_get_unmapped_area 1
#endif
#if CAN_WRAP_get_unmapped_area
    WRAP_FOR_DETACH(get_unmapped_area)
#endif
#ifndef CAN_WRAP_subsys_interface_unregister
#   define CAN_WRAP_subsys_interface_unregister 1
#endif
#if CAN_WRAP_subsys_interface_unregister
    WRAP_FOR_DETACH(subsys_interface_unregister)
#endif
#ifndef CAN_WRAP_acpi_install_global_event_handler
#   define CAN_WRAP_acpi_install_global_event_handler 1
#endif
#if CAN_WRAP_acpi_install_global_event_handler
    WRAP_FOR_DETACH(acpi_install_global_event_handler)
#endif
#ifndef CAN_WRAP___bitmap_andnot
#   define CAN_WRAP___bitmap_andnot 0
#endif
DETACH(__bitmap_andnot)
#ifndef CAN_WRAP_devres_close_group
#   define CAN_WRAP_devres_close_group 1
#endif
#if CAN_WRAP_devres_close_group
    WRAP_FOR_DETACH(devres_close_group)
#endif
#ifndef CAN_WRAP_blk_limits_io_opt
#   define CAN_WRAP_blk_limits_io_opt 1
#endif
#if CAN_WRAP_blk_limits_io_opt
    WRAP_FOR_DETACH(blk_limits_io_opt)
#endif
#ifndef CAN_WRAP___virt_addr_valid
#   define CAN_WRAP___virt_addr_valid 0
#endif
DETACH(__virt_addr_valid)
#ifndef CAN_WRAP_cgroup_task_count
#   define CAN_WRAP_cgroup_task_count 1
#endif
#if CAN_WRAP_cgroup_task_count
    WRAP_FOR_DETACH(cgroup_task_count)
#endif
#ifndef CAN_WRAP_recalc_sigpending
#   define CAN_WRAP_recalc_sigpending 0
#endif
DETACH(recalc_sigpending)
#ifndef CAN_WRAP_key_update
#   define CAN_WRAP_key_update 1
#endif
#if CAN_WRAP_key_update
    WRAP_FOR_DETACH(key_update)
#endif
#ifndef CAN_WRAP_default_scale_freq_power
#   define CAN_WRAP_default_scale_freq_power 1
#endif
#if CAN_WRAP_default_scale_freq_power
    WRAP_FOR_DETACH(default_scale_freq_power)
#endif
#ifndef CAN_WRAP_pci_set_dma_seg_boundary
#   define CAN_WRAP_pci_set_dma_seg_boundary 1
#endif
#if CAN_WRAP_pci_set_dma_seg_boundary
    WRAP_FOR_DETACH(pci_set_dma_seg_boundary)
#endif
#ifndef CAN_WRAP_early_ioremap_init
#   define CAN_WRAP_early_ioremap_init 0
#endif
DETACH(early_ioremap_init)
#ifndef CAN_WRAP_securityfs_create_dir
#   define CAN_WRAP_securityfs_create_dir 1
#endif
#if CAN_WRAP_securityfs_create_dir
    WRAP_FOR_DETACH(securityfs_create_dir)
#endif
#ifndef CAN_WRAP_e820_reserve_resources
#   define CAN_WRAP_e820_reserve_resources 0
#endif
DETACH(e820_reserve_resources)
#ifndef CAN_WRAP_phy_stop_machine
#   define CAN_WRAP_phy_stop_machine 1
#endif
#if CAN_WRAP_phy_stop_machine
    WRAP_FOR_DETACH(phy_stop_machine)
#endif
#ifndef CAN_WRAP_qdisc_warn_nonwc
#   define CAN_WRAP_qdisc_warn_nonwc 1
#endif
#if CAN_WRAP_qdisc_warn_nonwc
    WRAP_FOR_DETACH(qdisc_warn_nonwc)
#endif
#ifndef CAN_WRAP___napi_complete
#   define CAN_WRAP___napi_complete 1
#endif
#if CAN_WRAP___napi_complete
#   ifdef DETACH_ADDR___napi_complete
        WRAP_FOR_DETACH(__napi_complete)
#   else
        TYPED_DETACH(__napi_complete)
#   endif
#endif
#ifndef CAN_WRAP_acpi_format_exception
#   define CAN_WRAP_acpi_format_exception 0
#endif
DETACH(acpi_format_exception)
#ifndef CAN_WRAP_kernel_halt
#   define CAN_WRAP_kernel_halt 0
#endif
DETACH(kernel_halt)
#ifndef CAN_WRAP_generic_read_dir
#   define CAN_WRAP_generic_read_dir 1
#endif
#if CAN_WRAP_generic_read_dir
    WRAP_FOR_DETACH(generic_read_dir)
#endif
#ifndef CAN_WRAP_exit_thread
#   define CAN_WRAP_exit_thread 0
#endif
DETACH(exit_thread)
#ifndef CAN_WRAP_neigh_lookup
#   define CAN_WRAP_neigh_lookup 1
#endif
#if CAN_WRAP_neigh_lookup
    WRAP_FOR_DETACH(neigh_lookup)
#endif
#ifndef CAN_WRAP_native_restore_msi_irqs
#   define CAN_WRAP_native_restore_msi_irqs 1
#endif
#if CAN_WRAP_native_restore_msi_irqs
    WRAP_FOR_DETACH(native_restore_msi_irqs)
#endif
#ifndef CAN_WRAP_skb_copy
#   define CAN_WRAP_skb_copy 1
#endif
#if CAN_WRAP_skb_copy
    WRAP_FOR_DETACH(skb_copy)
#endif
#ifndef CAN_WRAP_simple_pin_fs
#   define CAN_WRAP_simple_pin_fs 1
#endif
#if CAN_WRAP_simple_pin_fs
    WRAP_FOR_DETACH(simple_pin_fs)
#endif
#ifndef CAN_WRAP___generic_file_aio_write
#   define CAN_WRAP___generic_file_aio_write 1
#endif
#if CAN_WRAP___generic_file_aio_write
#   ifdef DETACH_ADDR___generic_file_aio_write
        WRAP_FOR_DETACH(__generic_file_aio_write)
#   else
        TYPED_DETACH(__generic_file_aio_write)
#   endif
#endif
#ifndef CAN_WRAP_device_remove_file
#   define CAN_WRAP_device_remove_file 1
#endif
#if CAN_WRAP_device_remove_file
    WRAP_FOR_DETACH(device_remove_file)
#endif
#ifndef CAN_WRAP_elv_unregister
#   define CAN_WRAP_elv_unregister 1
#endif
#if CAN_WRAP_elv_unregister
    WRAP_FOR_DETACH(elv_unregister)
#endif
#ifndef CAN_WRAP_heap_insert
#   define CAN_WRAP_heap_insert 1
#endif
#if CAN_WRAP_heap_insert
    WRAP_FOR_DETACH(heap_insert)
#endif
#ifndef CAN_WRAP_dev_open
#   define CAN_WRAP_dev_open 1
#endif
#if CAN_WRAP_dev_open
    WRAP_FOR_DETACH(dev_open)
#endif
#ifndef CAN_WRAP___iget
#   define CAN_WRAP___iget 1
#endif
#if CAN_WRAP___iget
#   ifdef DETACH_ADDR___iget
        WRAP_FOR_DETACH(__iget)
#   else
        TYPED_DETACH(__iget)
#   endif
#endif
#ifndef CAN_WRAP___mnt_is_readonly
#   define CAN_WRAP___mnt_is_readonly 1
#endif
#if CAN_WRAP___mnt_is_readonly
#   ifdef DETACH_ADDR___mnt_is_readonly
        WRAP_FOR_DETACH(__mnt_is_readonly)
#   else
        TYPED_DETACH(__mnt_is_readonly)
#   endif
#endif
#ifndef CAN_WRAP___probe_kernel_read
#   define CAN_WRAP___probe_kernel_read 0
#endif
DETACH(__probe_kernel_read)
#ifndef CAN_WRAP_pci_vpd_find_info_keyword
#   define CAN_WRAP_pci_vpd_find_info_keyword 0
#endif
DETACH(pci_vpd_find_info_keyword)
#ifndef CAN_WRAP_vfs_rmdir
#   define CAN_WRAP_vfs_rmdir 1
#endif
#if CAN_WRAP_vfs_rmdir
    WRAP_FOR_DETACH(vfs_rmdir)
#endif
#ifndef CAN_WRAP__cond_resched
#   define CAN_WRAP__cond_resched 0
#endif
DETACH(_cond_resched)
#ifndef CAN_WRAP_init_amd_e400_c1e_mask
#   define CAN_WRAP_init_amd_e400_c1e_mask 0
#endif
DETACH(init_amd_e400_c1e_mask)
#ifndef CAN_WRAP_tick_init_highres
#   define CAN_WRAP_tick_init_highres 0
#endif
DETACH(tick_init_highres)
#ifndef CAN_WRAP_setup_vector_irq
#   define CAN_WRAP_setup_vector_irq 0
#endif
DETACH(setup_vector_irq)
#ifndef CAN_WRAP_soft_offline_page
#   define CAN_WRAP_soft_offline_page 1
#endif
#if CAN_WRAP_soft_offline_page
    WRAP_FOR_DETACH(soft_offline_page)
#endif
#ifndef CAN_WRAP_acpi_dmi_osi_linux
#   define CAN_WRAP_acpi_dmi_osi_linux 1
#endif
#if CAN_WRAP_acpi_dmi_osi_linux
    WRAP_FOR_DETACH(acpi_dmi_osi_linux)
#endif
#ifndef CAN_WRAP_skb_copy_bits
#   define CAN_WRAP_skb_copy_bits 1
#endif
#if CAN_WRAP_skb_copy_bits
    WRAP_FOR_DETACH(skb_copy_bits)
#endif
#ifndef CAN_WRAP_csum_ipv6_magic
#   define CAN_WRAP_csum_ipv6_magic 1
#endif
#if CAN_WRAP_csum_ipv6_magic
    WRAP_FOR_DETACH(csum_ipv6_magic)
#endif
#ifndef CAN_WRAP_exportfs_encode_fh
#   define CAN_WRAP_exportfs_encode_fh 1
#endif
#if CAN_WRAP_exportfs_encode_fh
    WRAP_FOR_DETACH(exportfs_encode_fh)
#endif
#ifndef CAN_WRAP___devm_release_region
#   define CAN_WRAP___devm_release_region 1
#endif
#if CAN_WRAP___devm_release_region
#   ifdef DETACH_ADDR___devm_release_region
        WRAP_FOR_DETACH(__devm_release_region)
#   else
        TYPED_DETACH(__devm_release_region)
#   endif
#endif
#ifndef CAN_WRAP_security_socket_getsockname
#   define CAN_WRAP_security_socket_getsockname 1
#endif
#if CAN_WRAP_security_socket_getsockname
    WRAP_FOR_DETACH(security_socket_getsockname)
#endif
#ifndef CAN_WRAP_security_secmark_refcount_dec
#   define CAN_WRAP_security_secmark_refcount_dec 0
#endif
DETACH(security_secmark_refcount_dec)
#ifndef CAN_WRAP_vector_used_by_percpu_irq
#   define CAN_WRAP_vector_used_by_percpu_irq 0
#endif
DETACH(vector_used_by_percpu_irq)
#ifndef CAN_WRAP_bus_unregister_notifier
#   define CAN_WRAP_bus_unregister_notifier 1
#endif
#if CAN_WRAP_bus_unregister_notifier
    WRAP_FOR_DETACH(bus_unregister_notifier)
#endif
#ifndef CAN_WRAP_inet_csk_init_xmit_timers
#   define CAN_WRAP_inet_csk_init_xmit_timers 1
#endif
#if CAN_WRAP_inet_csk_init_xmit_timers
    WRAP_FOR_DETACH(inet_csk_init_xmit_timers)
#endif
#ifndef CAN_WRAP_compat_sys_process_vm_writev
#   define CAN_WRAP_compat_sys_process_vm_writev 1
#endif
#if CAN_WRAP_compat_sys_process_vm_writev
    WRAP_FOR_DETACH(compat_sys_process_vm_writev)
#endif
#ifndef CAN_WRAP_sg_nents
#   define CAN_WRAP_sg_nents 1
#endif
#if CAN_WRAP_sg_nents
    WRAP_FOR_DETACH(sg_nents)
#endif
#ifndef CAN_WRAP_dev_hard_start_xmit
#   define CAN_WRAP_dev_hard_start_xmit 1
#endif
#if CAN_WRAP_dev_hard_start_xmit
    WRAP_FOR_DETACH(dev_hard_start_xmit)
#endif
#ifndef CAN_WRAP__raw_read_unlock_irq
#   define CAN_WRAP__raw_read_unlock_irq 1
#endif
#if CAN_WRAP__raw_read_unlock_irq
    WRAP_FOR_DETACH(_raw_read_unlock_irq)
#endif
#ifndef CAN_WRAP_bio_integrity_set_tag
#   define CAN_WRAP_bio_integrity_set_tag 1
#endif
#if CAN_WRAP_bio_integrity_set_tag
    WRAP_FOR_DETACH(bio_integrity_set_tag)
#endif
#ifndef CAN_WRAP_jiffies_to_clock_t
#   define CAN_WRAP_jiffies_to_clock_t 0
#endif
DETACH(jiffies_to_clock_t)
#ifndef CAN_WRAP_ata_ratelimit
#   define CAN_WRAP_ata_ratelimit 0
#endif
DETACH(ata_ratelimit)
#ifndef CAN_WRAP_pm_qos_update_flags
#   define CAN_WRAP_pm_qos_update_flags 1
#endif
#if CAN_WRAP_pm_qos_update_flags
    WRAP_FOR_DETACH(pm_qos_update_flags)
#endif
#ifndef CAN_WRAP_module_get_kallsym
#   define CAN_WRAP_module_get_kallsym 0
#endif
DETACH(module_get_kallsym)
#ifndef CAN_WRAP_get_posix_acl
#   define CAN_WRAP_get_posix_acl 1
#endif
#if CAN_WRAP_get_posix_acl
    WRAP_FOR_DETACH(get_posix_acl)
#endif
#ifndef CAN_WRAP_set_pgdat_percpu_threshold
#   define CAN_WRAP_set_pgdat_percpu_threshold 1
#endif
#if CAN_WRAP_set_pgdat_percpu_threshold
    WRAP_FOR_DETACH(set_pgdat_percpu_threshold)
#endif
#ifndef CAN_WRAP_access_remote_vm
#   define CAN_WRAP_access_remote_vm 1
#endif
#if CAN_WRAP_access_remote_vm
    WRAP_FOR_DETACH(access_remote_vm)
#endif
#ifndef CAN_WRAP_search_exception_tables
#   define CAN_WRAP_search_exception_tables 1
#endif
#if CAN_WRAP_search_exception_tables
    WRAP_FOR_DETACH(search_exception_tables)
#endif
#ifndef CAN_WRAP_blk_fetch_request
#   define CAN_WRAP_blk_fetch_request 1
#endif
#if CAN_WRAP_blk_fetch_request
    WRAP_FOR_DETACH(blk_fetch_request)
#endif
#ifndef CAN_WRAP_rdmsr_safe_regs_on_cpu
#   define CAN_WRAP_rdmsr_safe_regs_on_cpu 0
#endif
DETACH(rdmsr_safe_regs_on_cpu)
#ifndef CAN_WRAP_x86_init_noop
#   define CAN_WRAP_x86_init_noop 0
#endif
DETACH(x86_init_noop)
#ifndef CAN_WRAP_vma_interval_tree_insert
#   define CAN_WRAP_vma_interval_tree_insert 1
#endif
#if CAN_WRAP_vma_interval_tree_insert
    WRAP_FOR_DETACH(vma_interval_tree_insert)
#endif
#ifndef CAN_WRAP_do_getitimer
#   define CAN_WRAP_do_getitimer 1
#endif
#if CAN_WRAP_do_getitimer
    WRAP_FOR_DETACH(do_getitimer)
#endif
#ifndef CAN_WRAP_dquot_quota_on_mount
#   define CAN_WRAP_dquot_quota_on_mount 1
#endif
#if CAN_WRAP_dquot_quota_on_mount
    WRAP_FOR_DETACH(dquot_quota_on_mount)
#endif
#ifndef CAN_WRAP_blk_init_queue_node
#   define CAN_WRAP_blk_init_queue_node 1
#endif
#if CAN_WRAP_blk_init_queue_node
    WRAP_FOR_DETACH(blk_init_queue_node)
#endif
#ifndef CAN_WRAP_cgroup_iter_start
#   define CAN_WRAP_cgroup_iter_start 1
#endif
#if CAN_WRAP_cgroup_iter_start
    WRAP_FOR_DETACH(cgroup_iter_start)
#endif
#ifndef CAN_WRAP___sys_sendmmsg
#   define CAN_WRAP___sys_sendmmsg 1
#endif
#if CAN_WRAP___sys_sendmmsg
#   ifdef DETACH_ADDR___sys_sendmmsg
        WRAP_FOR_DETACH(__sys_sendmmsg)
#   else
        TYPED_DETACH(__sys_sendmmsg)
#   endif
#endif
#ifndef CAN_WRAP_irq_move_irq
#   define CAN_WRAP_irq_move_irq 1
#endif
#if CAN_WRAP_irq_move_irq
    WRAP_FOR_DETACH(irq_move_irq)
#endif
#ifndef CAN_WRAP_pci_disable_ido
#   define CAN_WRAP_pci_disable_ido 1
#endif
#if CAN_WRAP_pci_disable_ido
    WRAP_FOR_DETACH(pci_disable_ido)
#endif
#ifndef CAN_WRAP__paravirt_ident_64
#   define CAN_WRAP__paravirt_ident_64 0
#endif
DETACH(_paravirt_ident_64)
#ifndef CAN_WRAP_cgroup_iter_next
#   define CAN_WRAP_cgroup_iter_next 1
#endif
#if CAN_WRAP_cgroup_iter_next
    WRAP_FOR_DETACH(cgroup_iter_next)
#endif
#ifndef CAN_WRAP__raw_spin_unlock_bh
#   define CAN_WRAP__raw_spin_unlock_bh 1
#endif
#if CAN_WRAP__raw_spin_unlock_bh
    WRAP_FOR_DETACH(_raw_spin_unlock_bh)
#endif
#ifndef CAN_WRAP_bitmap_clear
#   define CAN_WRAP_bitmap_clear 0
#endif
DETACH(bitmap_clear)
#ifndef CAN_WRAP_inode_dio_done
#   define CAN_WRAP_inode_dio_done 1
#endif
#if CAN_WRAP_inode_dio_done
    WRAP_FOR_DETACH(inode_dio_done)
#endif
#ifndef CAN_WRAP_proc_dointvec
#   define CAN_WRAP_proc_dointvec 1
#endif
#if CAN_WRAP_proc_dointvec
    WRAP_FOR_DETACH(proc_dointvec)
#endif
#ifndef CAN_WRAP_dev_activate
#   define CAN_WRAP_dev_activate 1
#endif
#if CAN_WRAP_dev_activate
    WRAP_FOR_DETACH(dev_activate)
#endif
#ifndef CAN_WRAP_acpi_get_table_with_size
#   define CAN_WRAP_acpi_get_table_with_size 0
#endif
DETACH(acpi_get_table_with_size)
#ifndef CAN_WRAP___set_page_dirty_buffers
#   define CAN_WRAP___set_page_dirty_buffers 1
#endif
#if CAN_WRAP___set_page_dirty_buffers
#   ifdef DETACH_ADDR___set_page_dirty_buffers
        WRAP_FOR_DETACH(__set_page_dirty_buffers)
#   else
        TYPED_DETACH(__set_page_dirty_buffers)
#   endif
#endif
#ifndef CAN_WRAP___round_jiffies_relative
#   define CAN_WRAP___round_jiffies_relative 0
#endif
DETACH(__round_jiffies_relative)
#ifndef CAN_WRAP_hrtimer_try_to_cancel
#   define CAN_WRAP_hrtimer_try_to_cancel 1
#endif
#if CAN_WRAP_hrtimer_try_to_cancel
    WRAP_FOR_DETACH(hrtimer_try_to_cancel)
#endif
#ifndef CAN_WRAP_get_swap_page_of_type
#   define CAN_WRAP_get_swap_page_of_type 1
#endif
#if CAN_WRAP_get_swap_page_of_type
    WRAP_FOR_DETACH(get_swap_page_of_type)
#endif
#ifndef CAN_WRAP___page_symlink
#   define CAN_WRAP___page_symlink 1
#endif
#if CAN_WRAP___page_symlink
#   ifdef DETACH_ADDR___page_symlink
        WRAP_FOR_DETACH(__page_symlink)
#   else
        TYPED_DETACH(__page_symlink)
#   endif
#endif
#ifndef CAN_WRAP_ata_bmdma_setup
#   define CAN_WRAP_ata_bmdma_setup 1
#endif
#if CAN_WRAP_ata_bmdma_setup
    WRAP_FOR_DETACH(ata_bmdma_setup)
#endif
#ifndef CAN_WRAP_error_interrupt
#   define CAN_WRAP_error_interrupt 0
#endif
DETACH(error_interrupt)
#ifndef CAN_WRAP_dentry_path_raw
#   define CAN_WRAP_dentry_path_raw 1
#endif
#if CAN_WRAP_dentry_path_raw
    WRAP_FOR_DETACH(dentry_path_raw)
#endif
#ifndef CAN_WRAP___alloc_reserved_percpu
#   define CAN_WRAP___alloc_reserved_percpu 0
#endif
DETACH(__alloc_reserved_percpu)
#ifndef CAN_WRAP_try_to_free_swap
#   define CAN_WRAP_try_to_free_swap 1
#endif
#if CAN_WRAP_try_to_free_swap
    WRAP_FOR_DETACH(try_to_free_swap)
#endif
#ifndef CAN_WRAP_pci_request_regions
#   define CAN_WRAP_pci_request_regions 1
#endif
#if CAN_WRAP_pci_request_regions
    WRAP_FOR_DETACH(pci_request_regions)
#endif
#ifndef CAN_WRAP_netif_carrier_on
#   define CAN_WRAP_netif_carrier_on 1
#endif
#if CAN_WRAP_netif_carrier_on
    WRAP_FOR_DETACH(netif_carrier_on)
#endif
#ifndef CAN_WRAP_pci_rescan_bus
#   define CAN_WRAP_pci_rescan_bus 1
#endif
#if CAN_WRAP_pci_rescan_bus
    WRAP_FOR_DETACH(pci_rescan_bus)
#endif
#ifndef CAN_WRAP_compat_sys_set_robust_list
#   define CAN_WRAP_compat_sys_set_robust_list 1
#endif
#if CAN_WRAP_compat_sys_set_robust_list
    WRAP_FOR_DETACH(compat_sys_set_robust_list)
#endif
#ifndef CAN_WRAP_dev_get_flags
#   define CAN_WRAP_dev_get_flags 1
#endif
#if CAN_WRAP_dev_get_flags
    WRAP_FOR_DETACH(dev_get_flags)
#endif
#ifndef CAN_WRAP_ata_sff_data_xfer_noirq
#   define CAN_WRAP_ata_sff_data_xfer_noirq 1
#endif
#if CAN_WRAP_ata_sff_data_xfer_noirq
    WRAP_FOR_DETACH(ata_sff_data_xfer_noirq)
#endif
#ifndef CAN_WRAP_gnet_stats_start_copy
#   define CAN_WRAP_gnet_stats_start_copy 1
#endif
#if CAN_WRAP_gnet_stats_start_copy
    WRAP_FOR_DETACH(gnet_stats_start_copy)
#endif
#ifndef CAN_WRAP_compat_sys_writev
#   define CAN_WRAP_compat_sys_writev 1
#endif
#if CAN_WRAP_compat_sys_writev
    WRAP_FOR_DETACH(compat_sys_writev)
#endif
#ifndef CAN_WRAP_sched_autogroup_create_attach
#   define CAN_WRAP_sched_autogroup_create_attach 1
#endif
#if CAN_WRAP_sched_autogroup_create_attach
    WRAP_FOR_DETACH(sched_autogroup_create_attach)
#endif
#ifndef CAN_WRAP_mprotect_fixup
#   define CAN_WRAP_mprotect_fixup 1
#endif
#if CAN_WRAP_mprotect_fixup
    WRAP_FOR_DETACH(mprotect_fixup)
#endif
#ifndef CAN_WRAP_yield
#   define CAN_WRAP_yield 0
#endif
DETACH(yield)
#ifndef CAN_WRAP_kthread_should_stop
#   define CAN_WRAP_kthread_should_stop 0
#endif
DETACH(kthread_should_stop)
#ifndef CAN_WRAP_acpi_resource_to_address64
#   define CAN_WRAP_acpi_resource_to_address64 1
#endif
#if CAN_WRAP_acpi_resource_to_address64
    WRAP_FOR_DETACH(acpi_resource_to_address64)
#endif
#ifndef CAN_WRAP_rescan_partitions
#   define CAN_WRAP_rescan_partitions 1
#endif
#if CAN_WRAP_rescan_partitions
    WRAP_FOR_DETACH(rescan_partitions)
#endif
#ifndef CAN_WRAP_devres_add
#   define CAN_WRAP_devres_add 1
#endif
#if CAN_WRAP_devres_add
    WRAP_FOR_DETACH(devres_add)
#endif
#ifndef CAN_WRAP___hw_addr_del_multiple
#   define CAN_WRAP___hw_addr_del_multiple 1
#endif
#if CAN_WRAP___hw_addr_del_multiple
#   ifdef DETACH_ADDR___hw_addr_del_multiple
        WRAP_FOR_DETACH(__hw_addr_del_multiple)
#   else
        TYPED_DETACH(__hw_addr_del_multiple)
#   endif
#endif
#ifndef CAN_WRAP_do_huge_pmd_numa_page
#   define CAN_WRAP_do_huge_pmd_numa_page 1
#endif
#if CAN_WRAP_do_huge_pmd_numa_page
    WRAP_FOR_DETACH(do_huge_pmd_numa_page)
#endif
#ifndef CAN_WRAP_pnp_disable_dev
#   define CAN_WRAP_pnp_disable_dev 1
#endif
#if CAN_WRAP_pnp_disable_dev
    WRAP_FOR_DETACH(pnp_disable_dev)
#endif
#ifndef CAN_WRAP_acpi_get_table_by_index
#   define CAN_WRAP_acpi_get_table_by_index 0
#endif
DETACH(acpi_get_table_by_index)
#ifndef CAN_WRAP_ata_pci_device_do_suspend
#   define CAN_WRAP_ata_pci_device_do_suspend 1
#endif
#if CAN_WRAP_ata_pci_device_do_suspend
    WRAP_FOR_DETACH(ata_pci_device_do_suspend)
#endif
#ifndef CAN_WRAP_security_socket_recvmsg
#   define CAN_WRAP_security_socket_recvmsg 1
#endif
#if CAN_WRAP_security_socket_recvmsg
    WRAP_FOR_DETACH(security_socket_recvmsg)
#endif
#ifndef CAN_WRAP_inet_twsk_unhash
#   define CAN_WRAP_inet_twsk_unhash 1
#endif
#if CAN_WRAP_inet_twsk_unhash
    WRAP_FOR_DETACH(inet_twsk_unhash)
#endif
#ifndef CAN_WRAP_dm_set_geometry
#   define CAN_WRAP_dm_set_geometry 1
#endif
#if CAN_WRAP_dm_set_geometry
    WRAP_FOR_DETACH(dm_set_geometry)
#endif
#ifndef CAN_WRAP_schedule_timeout_interruptible
#   define CAN_WRAP_schedule_timeout_interruptible 0
#endif
DETACH(schedule_timeout_interruptible)
#ifndef CAN_WRAP_register_module_notifier
#   define CAN_WRAP_register_module_notifier 1
#endif
#if CAN_WRAP_register_module_notifier
    WRAP_FOR_DETACH(register_module_notifier)
#endif
#ifndef CAN_WRAP_ata_sff_port_intr
#   define CAN_WRAP_ata_sff_port_intr 1
#endif
#if CAN_WRAP_ata_sff_port_intr
    WRAP_FOR_DETACH(ata_sff_port_intr)
#endif
#ifndef CAN_WRAP_proc_net_fops_create
#   define CAN_WRAP_proc_net_fops_create 1
#endif
#if CAN_WRAP_proc_net_fops_create
    WRAP_FOR_DETACH(proc_net_fops_create)
#endif
#ifndef CAN_WRAP_class_dev_iter_init
#   define CAN_WRAP_class_dev_iter_init 1
#endif
#if CAN_WRAP_class_dev_iter_init
    WRAP_FOR_DETACH(class_dev_iter_init)
#endif
#ifndef CAN_WRAP_blk_finish_plug
#   define CAN_WRAP_blk_finish_plug 1
#endif
#if CAN_WRAP_blk_finish_plug
    WRAP_FOR_DETACH(blk_finish_plug)
#endif
#ifndef CAN_WRAP_rand_initialize_disk
#   define CAN_WRAP_rand_initialize_disk 1
#endif
#if CAN_WRAP_rand_initialize_disk
    WRAP_FOR_DETACH(rand_initialize_disk)
#endif
#ifndef CAN_WRAP_from_kqid_munged
#   define CAN_WRAP_from_kqid_munged 1
#endif
#if CAN_WRAP_from_kqid_munged
    WRAP_FOR_DETACH(from_kqid_munged)
#endif
#ifndef CAN_WRAP___irq_set_affinity_locked
#   define CAN_WRAP___irq_set_affinity_locked 1
#endif
#if CAN_WRAP___irq_set_affinity_locked
#   ifdef DETACH_ADDR___irq_set_affinity_locked
        WRAP_FOR_DETACH(__irq_set_affinity_locked)
#   else
        TYPED_DETACH(__irq_set_affinity_locked)
#   endif
#endif
#ifndef CAN_WRAP_acpi_irq_penalty_init
#   define CAN_WRAP_acpi_irq_penalty_init 0
#endif
DETACH(acpi_irq_penalty_init)
#ifndef CAN_WRAP___unregister_chrdev
#   define CAN_WRAP___unregister_chrdev 0
#endif
DETACH(__unregister_chrdev)
#ifndef CAN_WRAP_split_page
#   define CAN_WRAP_split_page 1
#endif
#if CAN_WRAP_split_page
    WRAP_FOR_DETACH(split_page)
#endif
#ifndef CAN_WRAP_call_function_init
#   define CAN_WRAP_call_function_init 0
#endif
DETACH(call_function_init)
#ifndef CAN_WRAP_ra_submit
#   define CAN_WRAP_ra_submit 1
#endif
#if CAN_WRAP_ra_submit
    WRAP_FOR_DETACH(ra_submit)
#endif
#ifndef CAN_WRAP_compat_sys_mbind
#   define CAN_WRAP_compat_sys_mbind 0
#endif
DETACH(compat_sys_mbind)
#ifndef CAN_WRAP_acpi_enable_event
#   define CAN_WRAP_acpi_enable_event 0
#endif
DETACH(acpi_enable_event)
#ifndef CAN_WRAP_acpi_install_initialization_handler
#   define CAN_WRAP_acpi_install_initialization_handler 1
#endif
#if CAN_WRAP_acpi_install_initialization_handler
    WRAP_FOR_DETACH(acpi_install_initialization_handler)
#endif
#ifndef CAN_WRAP_compat_sys_sysinfo
#   define CAN_WRAP_compat_sys_sysinfo 1
#endif
#if CAN_WRAP_compat_sys_sysinfo
    WRAP_FOR_DETACH(compat_sys_sysinfo)
#endif
#ifndef CAN_WRAP_io_apic_setup_irq_pin_once
#   define CAN_WRAP_io_apic_setup_irq_pin_once 1
#endif
#if CAN_WRAP_io_apic_setup_irq_pin_once
    WRAP_FOR_DETACH(io_apic_setup_irq_pin_once)
#endif
#ifndef CAN_WRAP_rcu_note_context_switch
#   define CAN_WRAP_rcu_note_context_switch 0
#endif
DETACH(rcu_note_context_switch)
#ifndef CAN_WRAP_jbd2_journal_load
#   define CAN_WRAP_jbd2_journal_load 1
#endif
#if CAN_WRAP_jbd2_journal_load
    WRAP_FOR_DETACH(jbd2_journal_load)
#endif
#ifndef CAN_WRAP_sigprocmask
#   define CAN_WRAP_sigprocmask 1
#endif
#if CAN_WRAP_sigprocmask
    WRAP_FOR_DETACH(sigprocmask)
#endif
#ifndef CAN_WRAP___lock_page_killable
#   define CAN_WRAP___lock_page_killable 1
#endif
#if CAN_WRAP___lock_page_killable
#   ifdef DETACH_ADDR___lock_page_killable
        WRAP_FOR_DETACH(__lock_page_killable)
#   else
        TYPED_DETACH(__lock_page_killable)
#   endif
#endif
#ifndef CAN_WRAP_do_select
#   define CAN_WRAP_do_select 1
#endif
#if CAN_WRAP_do_select
    WRAP_FOR_DETACH(do_select)
#endif
#ifndef CAN_WRAP_drain_workqueue
#   define CAN_WRAP_drain_workqueue 1
#endif
#if CAN_WRAP_drain_workqueue
    WRAP_FOR_DETACH(drain_workqueue)
#endif
#ifndef CAN_WRAP_capable
#   define CAN_WRAP_capable 0
#endif
DETACH(capable)
#ifndef CAN_WRAP_blkdev_ioctl
#   define CAN_WRAP_blkdev_ioctl 1
#endif
#if CAN_WRAP_blkdev_ioctl
    WRAP_FOR_DETACH(blkdev_ioctl)
#endif
#ifndef CAN_WRAP___init_waitqueue_head
#   define CAN_WRAP___init_waitqueue_head 1
#endif
#if CAN_WRAP___init_waitqueue_head
#   ifdef DETACH_ADDR___init_waitqueue_head
        WRAP_FOR_DETACH(__init_waitqueue_head)
#   else
        TYPED_DETACH(__init_waitqueue_head)
#   endif
#endif
#ifndef CAN_WRAP_d_set_d_op
#   define CAN_WRAP_d_set_d_op 1
#endif
#if CAN_WRAP_d_set_d_op
    WRAP_FOR_DETACH(d_set_d_op)
#endif
#ifndef CAN_WRAP_acpi_warning
#   define CAN_WRAP_acpi_warning 0
#endif
DETACH(acpi_warning)
#ifndef CAN_WRAP_native_pagetable_reserve
#   define CAN_WRAP_native_pagetable_reserve 0
#endif
DETACH(native_pagetable_reserve)
#ifndef CAN_WRAP_tracing_on
#   define CAN_WRAP_tracing_on 0
#endif
DETACH(tracing_on)
#ifndef CAN_WRAP_compat_sys_recvfrom
#   define CAN_WRAP_compat_sys_recvfrom 1
#endif
#if CAN_WRAP_compat_sys_recvfrom
    WRAP_FOR_DETACH(compat_sys_recvfrom)
#endif
#ifndef CAN_WRAP___class_register
#   define CAN_WRAP___class_register 1
#endif
#if CAN_WRAP___class_register
#   ifdef DETACH_ADDR___class_register
        WRAP_FOR_DETACH(__class_register)
#   else
        TYPED_DETACH(__class_register)
#   endif
#endif
#ifndef CAN_WRAP_sock_no_mmap
#   define CAN_WRAP_sock_no_mmap 1
#endif
#if CAN_WRAP_sock_no_mmap
    WRAP_FOR_DETACH(sock_no_mmap)
#endif
#ifndef CAN_WRAP_inode_claim_rsv_space
#   define CAN_WRAP_inode_claim_rsv_space 1
#endif
#if CAN_WRAP_inode_claim_rsv_space
    WRAP_FOR_DETACH(inode_claim_rsv_space)
#endif
#ifndef CAN_WRAP_class_destroy
#   define CAN_WRAP_class_destroy 1
#endif
#if CAN_WRAP_class_destroy
    WRAP_FOR_DETACH(class_destroy)
#endif
#ifndef CAN_WRAP___blkdev_driver_ioctl
#   define CAN_WRAP___blkdev_driver_ioctl 1
#endif
#if CAN_WRAP___blkdev_driver_ioctl
#   ifdef DETACH_ADDR___blkdev_driver_ioctl
        WRAP_FOR_DETACH(__blkdev_driver_ioctl)
#   else
        TYPED_DETACH(__blkdev_driver_ioctl)
#   endif
#endif
#ifndef CAN_WRAP_netif_set_real_num_tx_queues
#   define CAN_WRAP_netif_set_real_num_tx_queues 1
#endif
#if CAN_WRAP_netif_set_real_num_tx_queues
    WRAP_FOR_DETACH(netif_set_real_num_tx_queues)
#endif
#ifndef CAN_WRAP_smp_prepare_boot_cpu
#   define CAN_WRAP_smp_prepare_boot_cpu 0
#endif
DETACH(smp_prepare_boot_cpu)
#ifndef CAN_WRAP_probe_kernel_write
#   define CAN_WRAP_probe_kernel_write 0
#endif
DETACH(probe_kernel_write)
#ifndef CAN_WRAP_acpi_finish_gpe
#   define CAN_WRAP_acpi_finish_gpe 0
#endif
DETACH(acpi_finish_gpe)
#ifndef CAN_WRAP_native_apic_icr_read
#   define CAN_WRAP_native_apic_icr_read 0
#endif
DETACH(native_apic_icr_read)
#ifndef CAN_WRAP_put_pid
#   define CAN_WRAP_put_pid 1
#endif
#if CAN_WRAP_put_pid
    WRAP_FOR_DETACH(put_pid)
#endif
#ifndef CAN_WRAP_force_page_cache_readahead
#   define CAN_WRAP_force_page_cache_readahead 1
#endif
#if CAN_WRAP_force_page_cache_readahead
    WRAP_FOR_DETACH(force_page_cache_readahead)
#endif
#ifndef CAN_WRAP_devtmpfs_create_node
#   define CAN_WRAP_devtmpfs_create_node 1
#endif
#if CAN_WRAP_devtmpfs_create_node
    WRAP_FOR_DETACH(devtmpfs_create_node)
#endif
#ifndef CAN_WRAP_acpi_acquire_mutex
#   define CAN_WRAP_acpi_acquire_mutex 0
#endif
DETACH(acpi_acquire_mutex)
#ifndef CAN_WRAP_generic_file_mmap
#   define CAN_WRAP_generic_file_mmap 1
#endif
#if CAN_WRAP_generic_file_mmap
    WRAP_FOR_DETACH(generic_file_mmap)
#endif
#ifndef CAN_WRAP_cap_vm_enough_memory
#   define CAN_WRAP_cap_vm_enough_memory 1
#endif
#if CAN_WRAP_cap_vm_enough_memory
    WRAP_FOR_DETACH(cap_vm_enough_memory)
#endif
#ifndef CAN_WRAP_rcutorture_record_progress
#   define CAN_WRAP_rcutorture_record_progress 0
#endif
DETACH(rcutorture_record_progress)
#ifndef CAN_WRAP_hrtimer_get_remaining
#   define CAN_WRAP_hrtimer_get_remaining 1
#endif
#if CAN_WRAP_hrtimer_get_remaining
    WRAP_FOR_DETACH(hrtimer_get_remaining)
#endif
#ifndef CAN_WRAP_dm_set_device_limits
#   define CAN_WRAP_dm_set_device_limits 1
#endif
#if CAN_WRAP_dm_set_device_limits
    WRAP_FOR_DETACH(dm_set_device_limits)
#endif
#ifndef CAN_WRAP_interruptible_sleep_on_timeout
#   define CAN_WRAP_interruptible_sleep_on_timeout 1
#endif
#if CAN_WRAP_interruptible_sleep_on_timeout
    WRAP_FOR_DETACH(interruptible_sleep_on_timeout)
#endif
#ifndef CAN_WRAP_show_state_filter
#   define CAN_WRAP_show_state_filter 0
#endif
DETACH(show_state_filter)
#ifndef CAN_WRAP_sysfs_remove_files
#   define CAN_WRAP_sysfs_remove_files 1
#endif
#if CAN_WRAP_sysfs_remove_files
    WRAP_FOR_DETACH(sysfs_remove_files)
#endif
#ifndef CAN_WRAP_profile_handoff_task
#   define CAN_WRAP_profile_handoff_task 1
#endif
#if CAN_WRAP_profile_handoff_task
    WRAP_FOR_DETACH(profile_handoff_task)
#endif
#ifndef CAN_WRAP_disk_part_iter_init
#   define CAN_WRAP_disk_part_iter_init 1
#endif
#if CAN_WRAP_disk_part_iter_init
    WRAP_FOR_DETACH(disk_part_iter_init)
#endif
#ifndef CAN_WRAP_blk_complete_request
#   define CAN_WRAP_blk_complete_request 1
#endif
#if CAN_WRAP_blk_complete_request
    WRAP_FOR_DETACH(blk_complete_request)
#endif
#ifndef CAN_WRAP_vlan_untag
#   define CAN_WRAP_vlan_untag 1
#endif
#if CAN_WRAP_vlan_untag
    WRAP_FOR_DETACH(vlan_untag)
#endif
#ifndef CAN_WRAP_name_to_dev_t
#   define CAN_WRAP_name_to_dev_t 0
#endif
DETACH(name_to_dev_t)
#ifndef CAN_WRAP_dev_kfree_skb_any
#   define CAN_WRAP_dev_kfree_skb_any 1
#endif
#if CAN_WRAP_dev_kfree_skb_any
    WRAP_FOR_DETACH(dev_kfree_skb_any)
#endif
#ifndef CAN_WRAP__local_bh_enable
#   define CAN_WRAP__local_bh_enable 0
#endif
DETACH(_local_bh_enable)
#ifndef CAN_WRAP_inode_set_bytes
#   define CAN_WRAP_inode_set_bytes 1
#endif
#if CAN_WRAP_inode_set_bytes
    WRAP_FOR_DETACH(inode_set_bytes)
#endif
#ifndef CAN_WRAP_textsearch_find_continuous
#   define CAN_WRAP_textsearch_find_continuous 1
#endif
#if CAN_WRAP_textsearch_find_continuous
    WRAP_FOR_DETACH(textsearch_find_continuous)
#endif
#ifndef CAN_WRAP___seq_open_private
#   define CAN_WRAP___seq_open_private 1
#endif
#if CAN_WRAP___seq_open_private
#   ifdef DETACH_ADDR___seq_open_private
        WRAP_FOR_DETACH(__seq_open_private)
#   else
        TYPED_DETACH(__seq_open_private)
#   endif
#endif
#ifndef CAN_WRAP_hardpps
#   define CAN_WRAP_hardpps 1
#endif
#if CAN_WRAP_hardpps
    WRAP_FOR_DETACH(hardpps)
#endif
#ifndef CAN_WRAP_seq_open_net
#   define CAN_WRAP_seq_open_net 1
#endif
#if CAN_WRAP_seq_open_net
    WRAP_FOR_DETACH(seq_open_net)
#endif
#ifndef CAN_WRAP_ata_wait_register
#   define CAN_WRAP_ata_wait_register 1
#endif
#if CAN_WRAP_ata_wait_register
    WRAP_FOR_DETACH(ata_wait_register)
#endif
#ifndef CAN_WRAP_dm_device_name
#   define CAN_WRAP_dm_device_name 1
#endif
#if CAN_WRAP_dm_device_name
    WRAP_FOR_DETACH(dm_device_name)
#endif
#ifndef CAN_WRAP_compat_sys_statfs
#   define CAN_WRAP_compat_sys_statfs 1
#endif
#if CAN_WRAP_compat_sys_statfs
    WRAP_FOR_DETACH(compat_sys_statfs)
#endif
#ifndef CAN_WRAP_acpi_unload_table_id
#   define CAN_WRAP_acpi_unload_table_id 0
#endif
DETACH(acpi_unload_table_id)
#ifndef CAN_WRAP_simple_read_from_buffer
#   define CAN_WRAP_simple_read_from_buffer 0
#endif
DETACH(simple_read_from_buffer)
#ifndef CAN_WRAP_build_all_zonelists
#   define CAN_WRAP_build_all_zonelists 1
#endif
#if CAN_WRAP_build_all_zonelists
    WRAP_FOR_DETACH(build_all_zonelists)
#endif
#ifndef CAN_WRAP_init_bsp_APIC
#   define CAN_WRAP_init_bsp_APIC 0
#endif
DETACH(init_bsp_APIC)
#ifndef CAN_WRAP_icmpv6_err_convert
#   define CAN_WRAP_icmpv6_err_convert 0
#endif
DETACH(icmpv6_err_convert)
#ifndef CAN_WRAP_kstrtoint
#   define CAN_WRAP_kstrtoint 0
#endif
DETACH(kstrtoint)
#ifndef CAN_WRAP_follow_trans_huge_pmd
#   define CAN_WRAP_follow_trans_huge_pmd 1
#endif
#if CAN_WRAP_follow_trans_huge_pmd
    WRAP_FOR_DETACH(follow_trans_huge_pmd)
#endif
#ifndef CAN_WRAP_inet_csk_accept
#   define CAN_WRAP_inet_csk_accept 1
#endif
#if CAN_WRAP_inet_csk_accept
    WRAP_FOR_DETACH(inet_csk_accept)
#endif
#ifndef CAN_WRAP_setup_cpu_local_masks
#   define CAN_WRAP_setup_cpu_local_masks 0
#endif
DETACH(setup_cpu_local_masks)
#ifndef CAN_WRAP_free_area_init_nodes
#   define CAN_WRAP_free_area_init_nodes 0
#endif
DETACH(free_area_init_nodes)
#ifndef CAN_WRAP_security_key_free
#   define CAN_WRAP_security_key_free 1
#endif
#if CAN_WRAP_security_key_free
    WRAP_FOR_DETACH(security_key_free)
#endif
#ifndef CAN_WRAP_rwsem_down_write_failed
#   define CAN_WRAP_rwsem_down_write_failed 1
#endif
#if CAN_WRAP_rwsem_down_write_failed
    WRAP_FOR_DETACH(rwsem_down_write_failed)
#endif
#ifndef CAN_WRAP_security_inode_need_killpriv
#   define CAN_WRAP_security_inode_need_killpriv 1
#endif
#if CAN_WRAP_security_inode_need_killpriv
    WRAP_FOR_DETACH(security_inode_need_killpriv)
#endif
#ifndef CAN_WRAP_key_put
#   define CAN_WRAP_key_put 1
#endif
#if CAN_WRAP_key_put
    WRAP_FOR_DETACH(key_put)
#endif
#ifndef CAN_WRAP_compat_sys_getitimer
#   define CAN_WRAP_compat_sys_getitimer 1
#endif
#if CAN_WRAP_compat_sys_getitimer
    WRAP_FOR_DETACH(compat_sys_getitimer)
#endif
#ifndef CAN_WRAP_pci_bus_add_resource
#   define CAN_WRAP_pci_bus_add_resource 1
#endif
#if CAN_WRAP_pci_bus_add_resource
    WRAP_FOR_DETACH(pci_bus_add_resource)
#endif
#ifndef CAN_WRAP_mnt_drop_write_file
#   define CAN_WRAP_mnt_drop_write_file 1
#endif
#if CAN_WRAP_mnt_drop_write_file
    WRAP_FOR_DETACH(mnt_drop_write_file)
#endif
#ifndef CAN_WRAP_pgd_page_get_mm
#   define CAN_WRAP_pgd_page_get_mm 1
#endif
#if CAN_WRAP_pgd_page_get_mm
    WRAP_FOR_DETACH(pgd_page_get_mm)
#endif
#ifndef CAN_WRAP_handle_mm_fault
#   define CAN_WRAP_handle_mm_fault 1
#endif
#if CAN_WRAP_handle_mm_fault
    WRAP_FOR_DETACH(handle_mm_fault)
#endif
#ifndef CAN_WRAP_read_dev_sector
#   define CAN_WRAP_read_dev_sector 1
#endif
#if CAN_WRAP_read_dev_sector
    WRAP_FOR_DETACH(read_dev_sector)
#endif
#ifndef CAN_WRAP_is_module_address
#   define CAN_WRAP_is_module_address 0
#endif
DETACH(is_module_address)
#ifndef CAN_WRAP_blk_run_queue_async
#   define CAN_WRAP_blk_run_queue_async 1
#endif
#if CAN_WRAP_blk_run_queue_async
    WRAP_FOR_DETACH(blk_run_queue_async)
#endif
#ifndef CAN_WRAP_trap_init
#   define CAN_WRAP_trap_init 0
#endif
DETACH(trap_init)
#ifndef CAN_WRAP_wrmsr_safe_on_cpu
#   define CAN_WRAP_wrmsr_safe_on_cpu 0
#endif
DETACH(wrmsr_safe_on_cpu)
#ifndef CAN_WRAP_unregister_timer_hook
#   define CAN_WRAP_unregister_timer_hook 1
#endif
#if CAN_WRAP_unregister_timer_hook
    WRAP_FOR_DETACH(unregister_timer_hook)
#endif
#ifndef CAN_WRAP___inquire_remote_apic
#   define CAN_WRAP___inquire_remote_apic 0
#endif
DETACH(__inquire_remote_apic)
#ifndef CAN_WRAP_vmalloc
#   define CAN_WRAP_vmalloc 0
#endif
DETACH(vmalloc)
#ifndef CAN_WRAP_kset_init
#   define CAN_WRAP_kset_init 1
#endif
#if CAN_WRAP_kset_init
    WRAP_FOR_DETACH(kset_init)
#endif
#ifndef CAN_WRAP___first_cpu
#   define CAN_WRAP___first_cpu 1
#endif
#if CAN_WRAP___first_cpu
#   ifdef DETACH_ADDR___first_cpu
        WRAP_FOR_DETACH(__first_cpu)
#   else
        TYPED_DETACH(__first_cpu)
#   endif
#endif
#ifndef CAN_WRAP_devres_open_group
#   define CAN_WRAP_devres_open_group 1
#endif
#if CAN_WRAP_devres_open_group
    WRAP_FOR_DETACH(devres_open_group)
#endif
#ifndef CAN_WRAP_security_file_open
#   define CAN_WRAP_security_file_open 1
#endif
#if CAN_WRAP_security_file_open
    WRAP_FOR_DETACH(security_file_open)
#endif
#ifndef CAN_WRAP_nr_iowait_cpu
#   define CAN_WRAP_nr_iowait_cpu 0
#endif
DETACH(nr_iowait_cpu)
#ifndef CAN_WRAP_simple_transaction_get
#   define CAN_WRAP_simple_transaction_get 1
#endif
#if CAN_WRAP_simple_transaction_get
    WRAP_FOR_DETACH(simple_transaction_get)
#endif
#ifndef CAN_WRAP_init_dummy_netdev
#   define CAN_WRAP_init_dummy_netdev 1
#endif
#if CAN_WRAP_init_dummy_netdev
    WRAP_FOR_DETACH(init_dummy_netdev)
#endif
#ifndef CAN_WRAP_kstrtos16
#   define CAN_WRAP_kstrtos16 0
#endif
DETACH(kstrtos16)
#ifndef CAN_WRAP_compat_sys_old_select
#   define CAN_WRAP_compat_sys_old_select 1
#endif
#if CAN_WRAP_compat_sys_old_select
    WRAP_FOR_DETACH(compat_sys_old_select)
#endif
#ifndef CAN_WRAP_pcim_iounmap
#   define CAN_WRAP_pcim_iounmap 1
#endif
#if CAN_WRAP_pcim_iounmap
    WRAP_FOR_DETACH(pcim_iounmap)
#endif
#ifndef CAN_WRAP_icmpv6_send
#   define CAN_WRAP_icmpv6_send 1
#endif
#if CAN_WRAP_icmpv6_send
    WRAP_FOR_DETACH(icmpv6_send)
#endif
#ifndef CAN_WRAP_e820_add_region
#   define CAN_WRAP_e820_add_region 0
#endif
DETACH(e820_add_region)
#ifndef CAN_WRAP_pci_legacy_init
#   define CAN_WRAP_pci_legacy_init 0
#endif
DETACH(pci_legacy_init)
#ifndef CAN_WRAP_ec_transaction
#   define CAN_WRAP_ec_transaction 0
#endif
DETACH(ec_transaction)
#ifndef CAN_WRAP_unregister_pernet_subsys
#   define CAN_WRAP_unregister_pernet_subsys 1
#endif
#if CAN_WRAP_unregister_pernet_subsys
    WRAP_FOR_DETACH(unregister_pernet_subsys)
#endif
#ifndef CAN_WRAP___symbol_get_gpl
#   define CAN_WRAP___symbol_get_gpl 0
#endif
DETACH(__symbol_get_gpl)
#ifndef CAN_WRAP___dec_zone_page_state
#   define CAN_WRAP___dec_zone_page_state 1
#endif
#if CAN_WRAP___dec_zone_page_state
#   ifdef DETACH_ADDR___dec_zone_page_state
        WRAP_FOR_DETACH(__dec_zone_page_state)
#   else
        TYPED_DETACH(__dec_zone_page_state)
#   endif
#endif
#ifndef CAN_WRAP_round_jiffies
#   define CAN_WRAP_round_jiffies 0
#endif
DETACH(round_jiffies)
#ifndef CAN_WRAP_clockevents_resume
#   define CAN_WRAP_clockevents_resume 0
#endif
DETACH(clockevents_resume)
#ifndef CAN_WRAP_phy_register_fixup_for_uid
#   define CAN_WRAP_phy_register_fixup_for_uid 1
#endif
#if CAN_WRAP_phy_register_fixup_for_uid
    WRAP_FOR_DETACH(phy_register_fixup_for_uid)
#endif
#ifndef CAN_WRAP_acpi_old_suspend_ordering
#   define CAN_WRAP_acpi_old_suspend_ordering 0
#endif
DETACH(acpi_old_suspend_ordering)
#ifndef CAN_WRAP_param_get_long
#   define CAN_WRAP_param_get_long 1
#endif
#if CAN_WRAP_param_get_long
    WRAP_FOR_DETACH(param_get_long)
#endif
#ifndef CAN_WRAP_strim
#   define CAN_WRAP_strim 0
#endif
DETACH(strim)
#ifndef CAN_WRAP_init_memory_mapping
#   define CAN_WRAP_init_memory_mapping 0
#endif
DETACH(init_memory_mapping)
#ifndef CAN_WRAP_dput
#   define CAN_WRAP_dput 1
#endif
#if CAN_WRAP_dput
    WRAP_FOR_DETACH(dput)
#endif
#ifndef CAN_WRAP_assign_irq_vector
#   define CAN_WRAP_assign_irq_vector 1
#endif
#if CAN_WRAP_assign_irq_vector
    WRAP_FOR_DETACH(assign_irq_vector)
#endif
#ifndef CAN_WRAP_inet_csk_compat_setsockopt
#   define CAN_WRAP_inet_csk_compat_setsockopt 1
#endif
#if CAN_WRAP_inet_csk_compat_setsockopt
    WRAP_FOR_DETACH(inet_csk_compat_setsockopt)
#endif
#ifndef CAN_WRAP_kernel_getpeername
#   define CAN_WRAP_kernel_getpeername 1
#endif
#if CAN_WRAP_kernel_getpeername
    WRAP_FOR_DETACH(kernel_getpeername)
#endif
#ifndef CAN_WRAP___fprop_inc_percpu
#   define CAN_WRAP___fprop_inc_percpu 1
#endif
#if CAN_WRAP___fprop_inc_percpu
#   ifdef DETACH_ADDR___fprop_inc_percpu
        WRAP_FOR_DETACH(__fprop_inc_percpu)
#   else
        TYPED_DETACH(__fprop_inc_percpu)
#   endif
#endif
#ifndef CAN_WRAP_security_transfer_creds
#   define CAN_WRAP_security_transfer_creds 1
#endif
#if CAN_WRAP_security_transfer_creds
    WRAP_FOR_DETACH(security_transfer_creds)
#endif
#ifndef CAN_WRAP_param_get_byte
#   define CAN_WRAP_param_get_byte 1
#endif
#if CAN_WRAP_param_get_byte
    WRAP_FOR_DETACH(param_get_byte)
#endif
#ifndef CAN_WRAP_blk_end_request
#   define CAN_WRAP_blk_end_request 1
#endif
#if CAN_WRAP_blk_end_request
    WRAP_FOR_DETACH(blk_end_request)
#endif
#ifndef CAN_WRAP_radix_tree_tagged
#   define CAN_WRAP_radix_tree_tagged 1
#endif
#if CAN_WRAP_radix_tree_tagged
    WRAP_FOR_DETACH(radix_tree_tagged)
#endif
#ifndef CAN_WRAP___invalidate_device
#   define CAN_WRAP___invalidate_device 1
#endif
#if CAN_WRAP___invalidate_device
#   ifdef DETACH_ADDR___invalidate_device
        WRAP_FOR_DETACH(__invalidate_device)
#   else
        TYPED_DETACH(__invalidate_device)
#   endif
#endif
#ifndef CAN_WRAP_get_anon_bdev
#   define CAN_WRAP_get_anon_bdev 0
#endif
DETACH(get_anon_bdev)
#ifndef CAN_WRAP_acpi_subsys_prepare
#   define CAN_WRAP_acpi_subsys_prepare 1
#endif
#if CAN_WRAP_acpi_subsys_prepare
    WRAP_FOR_DETACH(acpi_subsys_prepare)
#endif
#ifndef CAN_WRAP_cap_task_setioprio
#   define CAN_WRAP_cap_task_setioprio 1
#endif
#if CAN_WRAP_cap_task_setioprio
    WRAP_FOR_DETACH(cap_task_setioprio)
#endif
#ifndef CAN_WRAP_prctl_set_seccomp
#   define CAN_WRAP_prctl_set_seccomp 0
#endif
DETACH(prctl_set_seccomp)
#ifndef CAN_WRAP_pcie_get_mps
#   define CAN_WRAP_pcie_get_mps 1
#endif
#if CAN_WRAP_pcie_get_mps
    WRAP_FOR_DETACH(pcie_get_mps)
#endif
#ifndef CAN_WRAP_jbd2_journal_bmap
#   define CAN_WRAP_jbd2_journal_bmap 1
#endif
#if CAN_WRAP_jbd2_journal_bmap
    WRAP_FOR_DETACH(jbd2_journal_bmap)
#endif
#ifndef CAN_WRAP___destroy_inode
#   define CAN_WRAP___destroy_inode 1
#endif
#if CAN_WRAP___destroy_inode
#   ifdef DETACH_ADDR___destroy_inode
        WRAP_FOR_DETACH(__destroy_inode)
#   else
        TYPED_DETACH(__destroy_inode)
#   endif
#endif
#ifndef CAN_WRAP_blk_lld_busy
#   define CAN_WRAP_blk_lld_busy 1
#endif
#if CAN_WRAP_blk_lld_busy
    WRAP_FOR_DETACH(blk_lld_busy)
#endif
#ifndef CAN_WRAP_execute_in_process_context
#   define CAN_WRAP_execute_in_process_context 1
#endif
#if CAN_WRAP_execute_in_process_context
    WRAP_FOR_DETACH(execute_in_process_context)
#endif
#ifndef CAN_WRAP___tasklet_hi_schedule_first
#   define CAN_WRAP___tasklet_hi_schedule_first 1
#endif
#if CAN_WRAP___tasklet_hi_schedule_first
#   ifdef DETACH_ADDR___tasklet_hi_schedule_first
        WRAP_FOR_DETACH(__tasklet_hi_schedule_first)
#   else
        TYPED_DETACH(__tasklet_hi_schedule_first)
#   endif
#endif
#ifndef CAN_WRAP_irq_select_affinity
#   define CAN_WRAP_irq_select_affinity 0
#endif
DETACH(irq_select_affinity)
#ifndef CAN_WRAP_crypto_alloc_ahash
#   define CAN_WRAP_crypto_alloc_ahash 1
#endif
#if CAN_WRAP_crypto_alloc_ahash
    WRAP_FOR_DETACH(crypto_alloc_ahash)
#endif
#ifndef CAN_WRAP_dpm_resume_end
#   define CAN_WRAP_dpm_resume_end 1
#endif
#if CAN_WRAP_dpm_resume_end
    WRAP_FOR_DETACH(dpm_resume_end)
#endif
#ifndef CAN_WRAP_check_move_unevictable_pages
#   define CAN_WRAP_check_move_unevictable_pages 0
#endif
DETACH(check_move_unevictable_pages)
#ifndef CAN_WRAP_compat_sys_clock_gettime
#   define CAN_WRAP_compat_sys_clock_gettime 1
#endif
#if CAN_WRAP_compat_sys_clock_gettime
    WRAP_FOR_DETACH(compat_sys_clock_gettime)
#endif
#ifndef CAN_WRAP_kstrndup
#   define CAN_WRAP_kstrndup 0
#endif
DETACH(kstrndup)
#ifndef CAN_WRAP_scsi_get_host_dev
#   define CAN_WRAP_scsi_get_host_dev 1
#endif
#if CAN_WRAP_scsi_get_host_dev
    WRAP_FOR_DETACH(scsi_get_host_dev)
#endif
#ifndef CAN_WRAP_bdi_writeout_inc
#   define CAN_WRAP_bdi_writeout_inc 1
#endif
#if CAN_WRAP_bdi_writeout_inc
    WRAP_FOR_DETACH(bdi_writeout_inc)
#endif
#ifndef CAN_WRAP_pci_swiotlb_late_init
#   define CAN_WRAP_pci_swiotlb_late_init 0
#endif
DETACH(pci_swiotlb_late_init)
#ifndef CAN_WRAP_deactivate_page
#   define CAN_WRAP_deactivate_page 1
#endif
#if CAN_WRAP_deactivate_page
    WRAP_FOR_DETACH(deactivate_page)
#endif
#ifndef CAN_WRAP_tick_get_device
#   define CAN_WRAP_tick_get_device 1
#endif
#if CAN_WRAP_tick_get_device
    WRAP_FOR_DETACH(tick_get_device)
#endif
#ifndef CAN_WRAP_dev_pm_qos_flags
#   define CAN_WRAP_dev_pm_qos_flags 1
#endif
#if CAN_WRAP_dev_pm_qos_flags
    WRAP_FOR_DETACH(dev_pm_qos_flags)
#endif
#ifndef CAN_WRAP_finish_no_open
#   define CAN_WRAP_finish_no_open 1
#endif
#if CAN_WRAP_finish_no_open
    WRAP_FOR_DETACH(finish_no_open)
#endif
#ifndef CAN_WRAP_sb_min_blocksize
#   define CAN_WRAP_sb_min_blocksize 1
#endif
#if CAN_WRAP_sb_min_blocksize
    WRAP_FOR_DETACH(sb_min_blocksize)
#endif
#ifndef CAN_WRAP_unregister_one_node
#   define CAN_WRAP_unregister_one_node 0
#endif
DETACH(unregister_one_node)
#ifndef CAN_WRAP_ata_port_abort
#   define CAN_WRAP_ata_port_abort 1
#endif
#if CAN_WRAP_ata_port_abort
    WRAP_FOR_DETACH(ata_port_abort)
#endif
#ifndef CAN_WRAP_pm_qos_remove_notifier
#   define CAN_WRAP_pm_qos_remove_notifier 1
#endif
#if CAN_WRAP_pm_qos_remove_notifier
    WRAP_FOR_DETACH(pm_qos_remove_notifier)
#endif
#ifndef CAN_WRAP_ata_scsi_slave_destroy
#   define CAN_WRAP_ata_scsi_slave_destroy 1
#endif
#if CAN_WRAP_ata_scsi_slave_destroy
    WRAP_FOR_DETACH(ata_scsi_slave_destroy)
#endif
#ifndef CAN_WRAP_activate_page
#   define CAN_WRAP_activate_page 1
#endif
#if CAN_WRAP_activate_page
    WRAP_FOR_DETACH(activate_page)
#endif
#ifndef CAN_WRAP___cleancache_invalidate_inode
#   define CAN_WRAP___cleancache_invalidate_inode 1
#endif
#if CAN_WRAP___cleancache_invalidate_inode
#   ifdef DETACH_ADDR___cleancache_invalidate_inode
        WRAP_FOR_DETACH(__cleancache_invalidate_inode)
#   else
        TYPED_DETACH(__cleancache_invalidate_inode)
#   endif
#endif
#ifndef CAN_WRAP_block_all_signals
#   define CAN_WRAP_block_all_signals 1
#endif
#if CAN_WRAP_block_all_signals
    WRAP_FOR_DETACH(block_all_signals)
#endif
#ifndef CAN_WRAP_workqueue_set_max_active
#   define CAN_WRAP_workqueue_set_max_active 1
#endif
#if CAN_WRAP_workqueue_set_max_active
    WRAP_FOR_DETACH(workqueue_set_max_active)
#endif
#ifndef CAN_WRAP_set_curr_task
#   define CAN_WRAP_set_curr_task 1
#endif
#if CAN_WRAP_set_curr_task
    WRAP_FOR_DETACH(set_curr_task)
#endif
#ifndef CAN_WRAP_bio_clone_bioset
#   define CAN_WRAP_bio_clone_bioset 1
#endif
#if CAN_WRAP_bio_clone_bioset
    WRAP_FOR_DETACH(bio_clone_bioset)
#endif
#ifndef CAN_WRAP_vmemmap_populate_basepages
#   define CAN_WRAP_vmemmap_populate_basepages 1
#endif
#if CAN_WRAP_vmemmap_populate_basepages
    WRAP_FOR_DETACH(vmemmap_populate_basepages)
#endif
#ifndef CAN_WRAP_mark_buffer_async_write
#   define CAN_WRAP_mark_buffer_async_write 1
#endif
#if CAN_WRAP_mark_buffer_async_write
    WRAP_FOR_DETACH(mark_buffer_async_write)
#endif
#ifndef CAN_WRAP_dentry_unhash
#   define CAN_WRAP_dentry_unhash 1
#endif
#if CAN_WRAP_dentry_unhash
    WRAP_FOR_DETACH(dentry_unhash)
#endif
#ifndef CAN_WRAP_ihold
#   define CAN_WRAP_ihold 1
#endif
#if CAN_WRAP_ihold
    WRAP_FOR_DETACH(ihold)
#endif
#ifndef CAN_WRAP_disable_irq
#   define CAN_WRAP_disable_irq 0
#endif
DETACH(disable_irq)
#ifndef CAN_WRAP_wmi_get_event_data
#   define CAN_WRAP_wmi_get_event_data 1
#endif
#if CAN_WRAP_wmi_get_event_data
    WRAP_FOR_DETACH(wmi_get_event_data)
#endif
#ifndef CAN_WRAP_rcu_needs_cpu
#   define CAN_WRAP_rcu_needs_cpu 0
#endif
DETACH(rcu_needs_cpu)
#ifndef CAN_WRAP_unlock_new_inode
#   define CAN_WRAP_unlock_new_inode 1
#endif
#if CAN_WRAP_unlock_new_inode
    WRAP_FOR_DETACH(unlock_new_inode)
#endif
#ifndef CAN_WRAP_sock_create
#   define CAN_WRAP_sock_create 0
#endif
DETACH(sock_create)
#ifndef CAN_WRAP_default_restore_msi_irqs
#   define CAN_WRAP_default_restore_msi_irqs 1
#endif
#if CAN_WRAP_default_restore_msi_irqs
    WRAP_FOR_DETACH(default_restore_msi_irqs)
#endif
#ifndef CAN_WRAP_pvclock_tsc_khz
#   define CAN_WRAP_pvclock_tsc_khz 1
#endif
#if CAN_WRAP_pvclock_tsc_khz
    WRAP_FOR_DETACH(pvclock_tsc_khz)
#endif
#ifndef CAN_WRAP_dev_get_stats
#   define CAN_WRAP_dev_get_stats 1
#endif
#if CAN_WRAP_dev_get_stats
    WRAP_FOR_DETACH(dev_get_stats)
#endif
#ifndef CAN_WRAP_compat_sys_shmctl
#   define CAN_WRAP_compat_sys_shmctl 0
#endif
DETACH(compat_sys_shmctl)
#ifndef CAN_WRAP_acpi_get_irq_routing_table
#   define CAN_WRAP_acpi_get_irq_routing_table 1
#endif
#if CAN_WRAP_acpi_get_irq_routing_table
    WRAP_FOR_DETACH(acpi_get_irq_routing_table)
#endif
#ifndef CAN_WRAP_class_dev_iter_next
#   define CAN_WRAP_class_dev_iter_next 1
#endif
#if CAN_WRAP_class_dev_iter_next
    WRAP_FOR_DETACH(class_dev_iter_next)
#endif
#ifndef CAN_WRAP_unregister_quota_format
#   define CAN_WRAP_unregister_quota_format 1
#endif
#if CAN_WRAP_unregister_quota_format
    WRAP_FOR_DETACH(unregister_quota_format)
#endif
#ifndef CAN_WRAP___mmdrop
#   define CAN_WRAP___mmdrop 1
#endif
#if CAN_WRAP___mmdrop
#   ifdef DETACH_ADDR___mmdrop
        WRAP_FOR_DETACH(__mmdrop)
#   else
        TYPED_DETACH(__mmdrop)
#   endif
#endif
#ifndef CAN_WRAP_dql_completed
#   define CAN_WRAP_dql_completed 1
#endif
#if CAN_WRAP_dql_completed
    WRAP_FOR_DETACH(dql_completed)
#endif
#ifndef CAN_WRAP_set_blocksize
#   define CAN_WRAP_set_blocksize 1
#endif
#if CAN_WRAP_set_blocksize
    WRAP_FOR_DETACH(set_blocksize)
#endif
#ifndef CAN_WRAP_dev_ethtool
#   define CAN_WRAP_dev_ethtool 1
#endif
#if CAN_WRAP_dev_ethtool
    WRAP_FOR_DETACH(dev_ethtool)
#endif
#ifndef CAN_WRAP_bio_pair_release
#   define CAN_WRAP_bio_pair_release 1
#endif
#if CAN_WRAP_bio_pair_release
    WRAP_FOR_DETACH(bio_pair_release)
#endif
#ifndef CAN_WRAP_pci_bus_update_busn_res_end
#   define CAN_WRAP_pci_bus_update_busn_res_end 1
#endif
#if CAN_WRAP_pci_bus_update_busn_res_end
    WRAP_FOR_DETACH(pci_bus_update_busn_res_end)
#endif
#ifndef CAN_WRAP_is_dock_device
#   define CAN_WRAP_is_dock_device 0
#endif
DETACH(is_dock_device)
#ifndef CAN_WRAP_krealloc
#   define CAN_WRAP_krealloc 0
#endif
DETACH(krealloc)
#ifndef CAN_WRAP_generic_file_llseek_size
#   define CAN_WRAP_generic_file_llseek_size 1
#endif
#if CAN_WRAP_generic_file_llseek_size
    WRAP_FOR_DETACH(generic_file_llseek_size)
#endif
#ifndef CAN_WRAP_mnt_want_write_file
#   define CAN_WRAP_mnt_want_write_file 1
#endif
#if CAN_WRAP_mnt_want_write_file
    WRAP_FOR_DETACH(mnt_want_write_file)
#endif
#ifndef CAN_WRAP_tcf_destroy
#   define CAN_WRAP_tcf_destroy 1
#endif
#if CAN_WRAP_tcf_destroy
    WRAP_FOR_DETACH(tcf_destroy)
#endif
#ifndef CAN_WRAP_setup_APIC_eilvt
#   define CAN_WRAP_setup_APIC_eilvt 0
#endif
DETACH(setup_APIC_eilvt)
#ifndef CAN_WRAP___delete_partition
#   define CAN_WRAP___delete_partition 1
#endif
#if CAN_WRAP___delete_partition
#   ifdef DETACH_ADDR___delete_partition
        WRAP_FOR_DETACH(__delete_partition)
#   else
        TYPED_DETACH(__delete_partition)
#   endif
#endif
#ifndef CAN_WRAP_wb_do_writeback
#   define CAN_WRAP_wb_do_writeback 1
#endif
#if CAN_WRAP_wb_do_writeback
    WRAP_FOR_DETACH(wb_do_writeback)
#endif
#ifndef CAN_WRAP_inet_frags_init
#   define CAN_WRAP_inet_frags_init 1
#endif
#if CAN_WRAP_inet_frags_init
    WRAP_FOR_DETACH(inet_frags_init)
#endif
#ifndef CAN_WRAP_dcache_dir_close
#   define CAN_WRAP_dcache_dir_close 1
#endif
#if CAN_WRAP_dcache_dir_close
    WRAP_FOR_DETACH(dcache_dir_close)
#endif
#ifndef CAN_WRAP_cpumask_any_but
#   define CAN_WRAP_cpumask_any_but 1
#endif
#if CAN_WRAP_cpumask_any_but
    WRAP_FOR_DETACH(cpumask_any_but)
#endif
#ifndef CAN_WRAP_acpi_os_get_thread_id
#   define CAN_WRAP_acpi_os_get_thread_id 0
#endif
DETACH(acpi_os_get_thread_id)
#ifndef CAN_WRAP_pci_set_cacheline_size
#   define CAN_WRAP_pci_set_cacheline_size 1
#endif
#if CAN_WRAP_pci_set_cacheline_size
    WRAP_FOR_DETACH(pci_set_cacheline_size)
#endif
#ifndef CAN_WRAP___irq_alloc_descs
#   define CAN_WRAP___irq_alloc_descs 1
#endif
#if CAN_WRAP___irq_alloc_descs
#   ifdef DETACH_ADDR___irq_alloc_descs
        WRAP_FOR_DETACH(__irq_alloc_descs)
#   else
        TYPED_DETACH(__irq_alloc_descs)
#   endif
#endif
#ifndef CAN_WRAP_acpi_os_set_prepare_sleep
#   define CAN_WRAP_acpi_os_set_prepare_sleep 1
#endif
#if CAN_WRAP_acpi_os_set_prepare_sleep
    WRAP_FOR_DETACH(acpi_os_set_prepare_sleep)
#endif
#ifndef CAN_WRAP_phy_stop
#   define CAN_WRAP_phy_stop 1
#endif
#if CAN_WRAP_phy_stop
    WRAP_FOR_DETACH(phy_stop)
#endif
#ifndef CAN_WRAP_add_page_to_unevictable_list
#   define CAN_WRAP_add_page_to_unevictable_list 1
#endif
#if CAN_WRAP_add_page_to_unevictable_list
    WRAP_FOR_DETACH(add_page_to_unevictable_list)
#endif
#ifndef CAN_WRAP_acpi_pci_unregister_driver
#   define CAN_WRAP_acpi_pci_unregister_driver 1
#endif
#if CAN_WRAP_acpi_pci_unregister_driver
    WRAP_FOR_DETACH(acpi_pci_unregister_driver)
#endif
#ifndef CAN_WRAP_bio_copy_user_iov
#   define CAN_WRAP_bio_copy_user_iov 1
#endif
#if CAN_WRAP_bio_copy_user_iov
    WRAP_FOR_DETACH(bio_copy_user_iov)
#endif
#ifndef CAN_WRAP_generic_write_checks
#   define CAN_WRAP_generic_write_checks 1
#endif
#if CAN_WRAP_generic_write_checks
    WRAP_FOR_DETACH(generic_write_checks)
#endif
#ifndef CAN_WRAP_lock_may_write
#   define CAN_WRAP_lock_may_write 1
#endif
#if CAN_WRAP_lock_may_write
    WRAP_FOR_DETACH(lock_may_write)
#endif
#ifndef CAN_WRAP_tick_program_event
#   define CAN_WRAP_tick_program_event 0
#endif
DETACH(tick_program_event)
#ifndef CAN_WRAP_clocksource_suspend
#   define CAN_WRAP_clocksource_suspend 0
#endif
DETACH(clocksource_suspend)
#ifndef CAN_WRAP_smp_call_function_many
#   define CAN_WRAP_smp_call_function_many 1
#endif
#if CAN_WRAP_smp_call_function_many
    WRAP_FOR_DETACH(smp_call_function_many)
#endif
#ifndef CAN_WRAP_ata_scsi_change_queue_depth
#   define CAN_WRAP_ata_scsi_change_queue_depth 1
#endif
#if CAN_WRAP_ata_scsi_change_queue_depth
    WRAP_FOR_DETACH(ata_scsi_change_queue_depth)
#endif
#ifndef CAN_WRAP_generic_removexattr
#   define CAN_WRAP_generic_removexattr 1
#endif
#if CAN_WRAP_generic_removexattr
    WRAP_FOR_DETACH(generic_removexattr)
#endif
#ifndef CAN_WRAP_zone_pcp_update
#   define CAN_WRAP_zone_pcp_update 1
#endif
#if CAN_WRAP_zone_pcp_update
    WRAP_FOR_DETACH(zone_pcp_update)
#endif
#ifndef CAN_WRAP___pmd_trans_huge_lock
#   define CAN_WRAP___pmd_trans_huge_lock 1
#endif
#if CAN_WRAP___pmd_trans_huge_lock
#   ifdef DETACH_ADDR___pmd_trans_huge_lock
        WRAP_FOR_DETACH(__pmd_trans_huge_lock)
#   else
        TYPED_DETACH(__pmd_trans_huge_lock)
#   endif
#endif
#ifndef CAN_WRAP_sock_recvmsg
#   define CAN_WRAP_sock_recvmsg 1
#endif
#if CAN_WRAP_sock_recvmsg
    WRAP_FOR_DETACH(sock_recvmsg)
#endif
#ifndef CAN_WRAP_identify_secondary_cpu
#   define CAN_WRAP_identify_secondary_cpu 1
#endif
#if CAN_WRAP_identify_secondary_cpu
    WRAP_FOR_DETACH(identify_secondary_cpu)
#endif
#ifndef CAN_WRAP_cgroup_is_removed
#   define CAN_WRAP_cgroup_is_removed 1
#endif
#if CAN_WRAP_cgroup_is_removed
    WRAP_FOR_DETACH(cgroup_is_removed)
#endif
#ifndef CAN_WRAP_security_inode_link
#   define CAN_WRAP_security_inode_link 1
#endif
#if CAN_WRAP_security_inode_link
    WRAP_FOR_DETACH(security_inode_link)
#endif
#ifndef CAN_WRAP_device_pm_lock
#   define CAN_WRAP_device_pm_lock 0
#endif
DETACH(device_pm_lock)
#ifndef CAN_WRAP_ata_eh_freeze_port
#   define CAN_WRAP_ata_eh_freeze_port 1
#endif
#if CAN_WRAP_ata_eh_freeze_port
    WRAP_FOR_DETACH(ata_eh_freeze_port)
#endif
#ifndef CAN_WRAP_arch_update_cpu_topology
#   define CAN_WRAP_arch_update_cpu_topology 0
#endif
DETACH(arch_update_cpu_topology)
#ifndef CAN_WRAP_jbd2_journal_set_revoke
#   define CAN_WRAP_jbd2_journal_set_revoke 1
#endif
#if CAN_WRAP_jbd2_journal_set_revoke
    WRAP_FOR_DETACH(jbd2_journal_set_revoke)
#endif
#ifndef CAN_WRAP_nla_policy_len
#   define CAN_WRAP_nla_policy_len 1
#endif
#if CAN_WRAP_nla_policy_len
    WRAP_FOR_DETACH(nla_policy_len)
#endif
#ifndef CAN_WRAP___get_free_pages
#   define CAN_WRAP___get_free_pages 0
#endif
DETACH(__get_free_pages)
#ifndef CAN_WRAP_netdev_rx_handler_unregister
#   define CAN_WRAP_netdev_rx_handler_unregister 1
#endif
#if CAN_WRAP_netdev_rx_handler_unregister
    WRAP_FOR_DETACH(netdev_rx_handler_unregister)
#endif
#ifndef CAN_WRAP_writeback_inodes_wb
#   define CAN_WRAP_writeback_inodes_wb 1
#endif
#if CAN_WRAP_writeback_inodes_wb
    WRAP_FOR_DETACH(writeback_inodes_wb)
#endif
#ifndef CAN_WRAP_scsi_add_host_with_dma
#   define CAN_WRAP_scsi_add_host_with_dma 1
#endif
#if CAN_WRAP_scsi_add_host_with_dma
    WRAP_FOR_DETACH(scsi_add_host_with_dma)
#endif
#ifndef CAN_WRAP_locks_mandatory_area
#   define CAN_WRAP_locks_mandatory_area 1
#endif
#if CAN_WRAP_locks_mandatory_area
    WRAP_FOR_DETACH(locks_mandatory_area)
#endif
#ifndef CAN_WRAP_phy_init_hw
#   define CAN_WRAP_phy_init_hw 1
#endif
#if CAN_WRAP_phy_init_hw
    WRAP_FOR_DETACH(phy_init_hw)
#endif
#ifndef CAN_WRAP_netlink_table_ungrab
#   define CAN_WRAP_netlink_table_ungrab 0
#endif
DETACH(netlink_table_ungrab)
#ifndef CAN_WRAP_cdrom_get_media_event
#   define CAN_WRAP_cdrom_get_media_event 1
#endif
#if CAN_WRAP_cdrom_get_media_event
    WRAP_FOR_DETACH(cdrom_get_media_event)
#endif
#ifndef CAN_WRAP_acpi_bus_private_data_handler
#   define CAN_WRAP_acpi_bus_private_data_handler 0
#endif
DETACH(acpi_bus_private_data_handler)
#ifndef CAN_WRAP_devm_ioremap_release
#   define CAN_WRAP_devm_ioremap_release 1
#endif
#if CAN_WRAP_devm_ioremap_release
    WRAP_FOR_DETACH(devm_ioremap_release)
#endif
#ifndef CAN_WRAP_res_counter_charge_nofail
#   define CAN_WRAP_res_counter_charge_nofail 1
#endif
#if CAN_WRAP_res_counter_charge_nofail
    WRAP_FOR_DETACH(res_counter_charge_nofail)
#endif
#ifndef CAN_WRAP_irq_cpu_offline
#   define CAN_WRAP_irq_cpu_offline 0
#endif
DETACH(irq_cpu_offline)
#ifndef CAN_WRAP_skb_copy_datagram_from_iovec
#   define CAN_WRAP_skb_copy_datagram_from_iovec 1
#endif
#if CAN_WRAP_skb_copy_datagram_from_iovec
    WRAP_FOR_DETACH(skb_copy_datagram_from_iovec)
#endif
#ifndef CAN_WRAP_strlen
#   define CAN_WRAP_strlen 0
#endif
DETACH(strlen)
#ifndef CAN_WRAP_percpu_up_read
#   define CAN_WRAP_percpu_up_read 1
#endif
#if CAN_WRAP_percpu_up_read
    WRAP_FOR_DETACH(percpu_up_read)
#endif
#ifndef CAN_WRAP_fprop_local_init_percpu
#   define CAN_WRAP_fprop_local_init_percpu 1
#endif
#if CAN_WRAP_fprop_local_init_percpu
    WRAP_FOR_DETACH(fprop_local_init_percpu)
#endif
#ifndef CAN_WRAP_acpi_install_gpe_block
#   define CAN_WRAP_acpi_install_gpe_block 1
#endif
#if CAN_WRAP_acpi_install_gpe_block
    WRAP_FOR_DETACH(acpi_install_gpe_block)
#endif
#ifndef CAN_WRAP_arch_dup_task_struct
#   define CAN_WRAP_arch_dup_task_struct 1
#endif
#if CAN_WRAP_arch_dup_task_struct
    WRAP_FOR_DETACH(arch_dup_task_struct)
#endif
#ifndef CAN_WRAP_inode_sub_bytes
#   define CAN_WRAP_inode_sub_bytes 1
#endif
#if CAN_WRAP_inode_sub_bytes
    WRAP_FOR_DETACH(inode_sub_bytes)
#endif
#ifndef CAN_WRAP_acpi_load_table
#   define CAN_WRAP_acpi_load_table 1
#endif
#if CAN_WRAP_acpi_load_table
    WRAP_FOR_DETACH(acpi_load_table)
#endif
#ifndef CAN_WRAP_security_kernel_module_request
#   define CAN_WRAP_security_kernel_module_request 0
#endif
DETACH(security_kernel_module_request)
#ifndef CAN_WRAP_pci_scan_single_device
#   define CAN_WRAP_pci_scan_single_device 1
#endif
#if CAN_WRAP_pci_scan_single_device
    WRAP_FOR_DETACH(pci_scan_single_device)
#endif
#ifndef CAN_WRAP_klist_add_after
#   define CAN_WRAP_klist_add_after 1
#endif
#if CAN_WRAP_klist_add_after
    WRAP_FOR_DETACH(klist_add_after)
#endif
#ifndef CAN_WRAP_try_to_free_mem_cgroup_pages
#   define CAN_WRAP_try_to_free_mem_cgroup_pages 1
#endif
#if CAN_WRAP_try_to_free_mem_cgroup_pages
    WRAP_FOR_DETACH(try_to_free_mem_cgroup_pages)
#endif
#ifndef CAN_WRAP_security_inode_setxattr
#   define CAN_WRAP_security_inode_setxattr 1
#endif
#if CAN_WRAP_security_inode_setxattr
    WRAP_FOR_DETACH(security_inode_setxattr)
#endif
#ifndef CAN_WRAP_elv_bio_merged
#   define CAN_WRAP_elv_bio_merged 1
#endif
#if CAN_WRAP_elv_bio_merged
    WRAP_FOR_DETACH(elv_bio_merged)
#endif
#ifndef CAN_WRAP_numa_cpu_node
#   define CAN_WRAP_numa_cpu_node 0
#endif
DETACH(numa_cpu_node)
#ifndef CAN_WRAP_iget_locked
#   define CAN_WRAP_iget_locked 1
#endif
#if CAN_WRAP_iget_locked
    WRAP_FOR_DETACH(iget_locked)
#endif
#ifndef CAN_WRAP_thaw_super
#   define CAN_WRAP_thaw_super 1
#endif
#if CAN_WRAP_thaw_super
    WRAP_FOR_DETACH(thaw_super)
#endif
#ifndef CAN_WRAP_memory_failure
#   define CAN_WRAP_memory_failure 0
#endif
DETACH(memory_failure)
#ifndef CAN_WRAP_do_softirq
#   define CAN_WRAP_do_softirq 0
#endif
DETACH(do_softirq)
#ifndef CAN_WRAP_dec_zone_page_state
#   define CAN_WRAP_dec_zone_page_state 1
#endif
#if CAN_WRAP_dec_zone_page_state
    WRAP_FOR_DETACH(dec_zone_page_state)
#endif
#ifndef CAN_WRAP_vma_interval_tree_iter_next
#   define CAN_WRAP_vma_interval_tree_iter_next 1
#endif
#if CAN_WRAP_vma_interval_tree_iter_next
    WRAP_FOR_DETACH(vma_interval_tree_iter_next)
#endif
#ifndef CAN_WRAP_sock_queue_rcv_skb
#   define CAN_WRAP_sock_queue_rcv_skb 1
#endif
#if CAN_WRAP_sock_queue_rcv_skb
    WRAP_FOR_DETACH(sock_queue_rcv_skb)
#endif
#ifndef CAN_WRAP_jbd2_journal_clear_revoke
#   define CAN_WRAP_jbd2_journal_clear_revoke 1
#endif
#if CAN_WRAP_jbd2_journal_clear_revoke
    WRAP_FOR_DETACH(jbd2_journal_clear_revoke)
#endif
#ifndef CAN_WRAP_gnet_stats_copy_queue
#   define CAN_WRAP_gnet_stats_copy_queue 1
#endif
#if CAN_WRAP_gnet_stats_copy_queue
    WRAP_FOR_DETACH(gnet_stats_copy_queue)
#endif
#ifndef CAN_WRAP_pnp_possible_config
#   define CAN_WRAP_pnp_possible_config 1
#endif
#if CAN_WRAP_pnp_possible_config
    WRAP_FOR_DETACH(pnp_possible_config)
#endif
#ifndef CAN_WRAP_alloc_sched_domains
#   define CAN_WRAP_alloc_sched_domains 0
#endif
DETACH(alloc_sched_domains)
#ifndef CAN_WRAP___get_user_pages
#   define CAN_WRAP___get_user_pages 1
#endif
#if CAN_WRAP___get_user_pages
#   ifdef DETACH_ADDR___get_user_pages
        WRAP_FOR_DETACH(__get_user_pages)
#   else
        TYPED_DETACH(__get_user_pages)
#   endif
#endif
#ifndef CAN_WRAP_swapin_readahead
#   define CAN_WRAP_swapin_readahead 1
#endif
#if CAN_WRAP_swapin_readahead
    WRAP_FOR_DETACH(swapin_readahead)
#endif
#ifndef CAN_WRAP_ktime_get_monotonic_offset
#   define CAN_WRAP_ktime_get_monotonic_offset 0
#endif
DETACH(ktime_get_monotonic_offset)
#ifndef CAN_WRAP_phy_print_status
#   define CAN_WRAP_phy_print_status 1
#endif
#if CAN_WRAP_phy_print_status
    WRAP_FOR_DETACH(phy_print_status)
#endif
#ifndef CAN_WRAP_acpi_setup_gpe_for_wake
#   define CAN_WRAP_acpi_setup_gpe_for_wake 0
#endif
DETACH(acpi_setup_gpe_for_wake)
#ifndef CAN_WRAP_prepare_kernel_cred
#   define CAN_WRAP_prepare_kernel_cred 1
#endif
#if CAN_WRAP_prepare_kernel_cred
    WRAP_FOR_DETACH(prepare_kernel_cred)
#endif
#ifndef CAN_WRAP_compat_sys_nanosleep
#   define CAN_WRAP_compat_sys_nanosleep 1
#endif
#if CAN_WRAP_compat_sys_nanosleep
    WRAP_FOR_DETACH(compat_sys_nanosleep)
#endif
#ifndef CAN_WRAP_llist_add_batch
#   define CAN_WRAP_llist_add_batch 1
#endif
#if CAN_WRAP_llist_add_batch
    WRAP_FOR_DETACH(llist_add_batch)
#endif
#ifndef CAN_WRAP___get_vm_area_caller
#   define CAN_WRAP___get_vm_area_caller 1
#endif
#if CAN_WRAP___get_vm_area_caller
#   ifdef DETACH_ADDR___get_vm_area_caller
        WRAP_FOR_DETACH(__get_vm_area_caller)
#   else
        TYPED_DETACH(__get_vm_area_caller)
#   endif
#endif
#ifndef CAN_WRAP_profile_pc
#   define CAN_WRAP_profile_pc 1
#endif
#if CAN_WRAP_profile_pc
    WRAP_FOR_DETACH(profile_pc)
#endif
#ifndef CAN_WRAP_pci_free_resource_list
#   define CAN_WRAP_pci_free_resource_list 1
#endif
#if CAN_WRAP_pci_free_resource_list
    WRAP_FOR_DETACH(pci_free_resource_list)
#endif
#ifndef CAN_WRAP_acpi_os_read_port
#   define CAN_WRAP_acpi_os_read_port 0
#endif
DETACH(acpi_os_read_port)
#ifndef CAN_WRAP_kstrtoull
#   define CAN_WRAP_kstrtoull 0
#endif
DETACH(kstrtoull)
#ifndef CAN_WRAP_crypto_ahash_final
#   define CAN_WRAP_crypto_ahash_final 1
#endif
#if CAN_WRAP_crypto_ahash_final
    WRAP_FOR_DETACH(crypto_ahash_final)
#endif
#ifndef CAN_WRAP_percpu_pagelist_fraction_sysctl_handler
#   define CAN_WRAP_percpu_pagelist_fraction_sysctl_handler 1
#endif
#if CAN_WRAP_percpu_pagelist_fraction_sysctl_handler
    WRAP_FOR_DETACH(percpu_pagelist_fraction_sysctl_handler)
#endif
#ifndef CAN_WRAP_acpi_dev_runtime_resume
#   define CAN_WRAP_acpi_dev_runtime_resume 1
#endif
#if CAN_WRAP_acpi_dev_runtime_resume
    WRAP_FOR_DETACH(acpi_dev_runtime_resume)
#endif
#ifndef CAN_WRAP_check_signature
#   define CAN_WRAP_check_signature 0
#endif
DETACH(check_signature)
#ifndef CAN_WRAP_set_current_blocked
#   define CAN_WRAP_set_current_blocked 1
#endif
#if CAN_WRAP_set_current_blocked
    WRAP_FOR_DETACH(set_current_blocked)
#endif
#ifndef CAN_WRAP_paravirt_patch_ident_64
#   define CAN_WRAP_paravirt_patch_ident_64 0
#endif
DETACH(paravirt_patch_ident_64)
#ifndef CAN_WRAP_clear_page
#   define CAN_WRAP_clear_page 0
#endif
DETACH(clear_page)
#ifndef CAN_WRAP_device_create_vargs
#   define CAN_WRAP_device_create_vargs 1
#endif
#if CAN_WRAP_device_create_vargs
    WRAP_FOR_DETACH(device_create_vargs)
#endif
#ifndef CAN_WRAP_set_bdi_congested
#   define CAN_WRAP_set_bdi_congested 1
#endif
#if CAN_WRAP_set_bdi_congested
    WRAP_FOR_DETACH(set_bdi_congested)
#endif
#ifndef CAN_WRAP_jbd2_cleanup_journal_tail
#   define CAN_WRAP_jbd2_cleanup_journal_tail 1
#endif
#if CAN_WRAP_jbd2_cleanup_journal_tail
    WRAP_FOR_DETACH(jbd2_cleanup_journal_tail)
#endif
#ifndef CAN_WRAP_machine_shutdown
#   define CAN_WRAP_machine_shutdown 0
#endif
DETACH(machine_shutdown)
#ifndef CAN_WRAP_compat_sys_keyctl
#   define CAN_WRAP_compat_sys_keyctl 0
#endif
DETACH(compat_sys_keyctl)
#ifndef CAN_WRAP_vmalloc_to_page
#   define CAN_WRAP_vmalloc_to_page 1
#endif
#if CAN_WRAP_vmalloc_to_page
    WRAP_FOR_DETACH(vmalloc_to_page)
#endif
#ifndef CAN_WRAP_mnt_pin
#   define CAN_WRAP_mnt_pin 1
#endif
#if CAN_WRAP_mnt_pin
    WRAP_FOR_DETACH(mnt_pin)
#endif
#ifndef CAN_WRAP_page_cache_async_readahead
#   define CAN_WRAP_page_cache_async_readahead 1
#endif
#if CAN_WRAP_page_cache_async_readahead
    WRAP_FOR_DETACH(page_cache_async_readahead)
#endif
#ifndef CAN_WRAP_pm_generic_prepare
#   define CAN_WRAP_pm_generic_prepare 1
#endif
#if CAN_WRAP_pm_generic_prepare
    WRAP_FOR_DETACH(pm_generic_prepare)
#endif
#ifndef CAN_WRAP_x86_pci_root_bus_resources
#   define CAN_WRAP_x86_pci_root_bus_resources 1
#endif
#if CAN_WRAP_x86_pci_root_bus_resources
    WRAP_FOR_DETACH(x86_pci_root_bus_resources)
#endif
#ifndef CAN_WRAP_fork_idle
#   define CAN_WRAP_fork_idle 1
#endif
#if CAN_WRAP_fork_idle
    WRAP_FOR_DETACH(fork_idle)
#endif
#ifndef CAN_WRAP_synchronize_sched
#   define CAN_WRAP_synchronize_sched 0
#endif
DETACH(synchronize_sched)
#ifndef CAN_WRAP_iowrite16_rep
#   define CAN_WRAP_iowrite16_rep 0
#endif
DETACH(iowrite16_rep)
#ifndef CAN_WRAP_pgtable_trans_huge_withdraw
#   define CAN_WRAP_pgtable_trans_huge_withdraw 1
#endif
#if CAN_WRAP_pgtable_trans_huge_withdraw
    WRAP_FOR_DETACH(pgtable_trans_huge_withdraw)
#endif
#ifndef CAN_WRAP_elv_unregister_queue
#   define CAN_WRAP_elv_unregister_queue 1
#endif
#if CAN_WRAP_elv_unregister_queue
    WRAP_FOR_DETACH(elv_unregister_queue)
#endif
#ifndef CAN_WRAP_dirty_writeback_centisecs_handler
#   define CAN_WRAP_dirty_writeback_centisecs_handler 1
#endif
#if CAN_WRAP_dirty_writeback_centisecs_handler
    WRAP_FOR_DETACH(dirty_writeback_centisecs_handler)
#endif
#ifndef CAN_WRAP_acpi_enable_all_runtime_gpes
#   define CAN_WRAP_acpi_enable_all_runtime_gpes 0
#endif
DETACH(acpi_enable_all_runtime_gpes)
#ifndef CAN_WRAP_mmap_min_addr_handler
#   define CAN_WRAP_mmap_min_addr_handler 1
#endif
#if CAN_WRAP_mmap_min_addr_handler
    WRAP_FOR_DETACH(mmap_min_addr_handler)
#endif
#ifndef CAN_WRAP_jbd2_log_wait_commit
#   define CAN_WRAP_jbd2_log_wait_commit 1
#endif
#if CAN_WRAP_jbd2_log_wait_commit
    WRAP_FOR_DETACH(jbd2_log_wait_commit)
#endif
#ifndef CAN_WRAP_register_netdev
#   define CAN_WRAP_register_netdev 1
#endif
#if CAN_WRAP_register_netdev
    WRAP_FOR_DETACH(register_netdev)
#endif
#ifndef CAN_WRAP_inode_init_owner
#   define CAN_WRAP_inode_init_owner 1
#endif
#if CAN_WRAP_inode_init_owner
    WRAP_FOR_DETACH(inode_init_owner)
#endif
#ifndef CAN_WRAP_blk_bio_map_sg
#   define CAN_WRAP_blk_bio_map_sg 1
#endif
#if CAN_WRAP_blk_bio_map_sg
    WRAP_FOR_DETACH(blk_bio_map_sg)
#endif
#ifndef CAN_WRAP_generic_listxattr
#   define CAN_WRAP_generic_listxattr 1
#endif
#if CAN_WRAP_generic_listxattr
    WRAP_FOR_DETACH(generic_listxattr)
#endif
#ifndef CAN_WRAP_free_pages
#   define CAN_WRAP_free_pages 0
#endif
DETACH(free_pages)
#ifndef CAN_WRAP_memchr_inv
#   define CAN_WRAP_memchr_inv 0
#endif
DETACH(memchr_inv)
#ifndef CAN_WRAP_proc_alloc_inum
#   define CAN_WRAP_proc_alloc_inum 0
#endif
DETACH(proc_alloc_inum)
#ifndef CAN_WRAP_kernel_connect
#   define CAN_WRAP_kernel_connect 1
#endif
#if CAN_WRAP_kernel_connect
    WRAP_FOR_DETACH(kernel_connect)
#endif
#ifndef CAN_WRAP_netdev_set_master
#   define CAN_WRAP_netdev_set_master 1
#endif
#if CAN_WRAP_netdev_set_master
    WRAP_FOR_DETACH(netdev_set_master)
#endif
#ifndef CAN_WRAP_mempool_kfree
#   define CAN_WRAP_mempool_kfree 0
#endif
DETACH(mempool_kfree)
#ifndef CAN_WRAP_heap_free
#   define CAN_WRAP_heap_free 1
#endif
#if CAN_WRAP_heap_free
    WRAP_FOR_DETACH(heap_free)
#endif
#ifndef CAN_WRAP_dma_unpin_iovec_pages
#   define CAN_WRAP_dma_unpin_iovec_pages 1
#endif
#if CAN_WRAP_dma_unpin_iovec_pages
    WRAP_FOR_DETACH(dma_unpin_iovec_pages)
#endif
#ifndef CAN_WRAP_sync_inode
#   define CAN_WRAP_sync_inode 1
#endif
#if CAN_WRAP_sync_inode
    WRAP_FOR_DETACH(sync_inode)
#endif
#ifndef CAN_WRAP_ata_sff_data_xfer
#   define CAN_WRAP_ata_sff_data_xfer 1
#endif
#if CAN_WRAP_ata_sff_data_xfer
    WRAP_FOR_DETACH(ata_sff_data_xfer)
#endif
#ifndef CAN_WRAP_d_invalidate
#   define CAN_WRAP_d_invalidate 1
#endif
#if CAN_WRAP_d_invalidate
    WRAP_FOR_DETACH(d_invalidate)
#endif
#ifndef CAN_WRAP_security_ipc_getsecid
#   define CAN_WRAP_security_ipc_getsecid 1
#endif
#if CAN_WRAP_security_ipc_getsecid
    WRAP_FOR_DETACH(security_ipc_getsecid)
#endif
#ifndef CAN_WRAP_compat_sys_clock_settime
#   define CAN_WRAP_compat_sys_clock_settime 1
#endif
#if CAN_WRAP_compat_sys_clock_settime
    WRAP_FOR_DETACH(compat_sys_clock_settime)
#endif
#ifndef CAN_WRAP_kern_unmount
#   define CAN_WRAP_kern_unmount 1
#endif
#if CAN_WRAP_kern_unmount
    WRAP_FOR_DETACH(kern_unmount)
#endif
#ifndef CAN_WRAP_min_free_kbytes_sysctl_handler
#   define CAN_WRAP_min_free_kbytes_sysctl_handler 1
#endif
#if CAN_WRAP_min_free_kbytes_sysctl_handler
    WRAP_FOR_DETACH(min_free_kbytes_sysctl_handler)
#endif
#ifndef CAN_WRAP_driver_create_file
#   define CAN_WRAP_driver_create_file 1
#endif
#if CAN_WRAP_driver_create_file
    WRAP_FOR_DETACH(driver_create_file)
#endif
#ifndef CAN_WRAP_init_timer_key
#   define CAN_WRAP_init_timer_key 1
#endif
#if CAN_WRAP_init_timer_key
    WRAP_FOR_DETACH(init_timer_key)
#endif
#ifndef CAN_WRAP_inc_zone_page_state
#   define CAN_WRAP_inc_zone_page_state 1
#endif
#if CAN_WRAP_inc_zone_page_state
    WRAP_FOR_DETACH(inc_zone_page_state)
#endif
#ifndef CAN_WRAP_pm_qos_update_request
#   define CAN_WRAP_pm_qos_update_request 1
#endif
#if CAN_WRAP_pm_qos_update_request
    WRAP_FOR_DETACH(pm_qos_update_request)
#endif
#ifndef CAN_WRAP_jbd2_journal_recover
#   define CAN_WRAP_jbd2_journal_recover 1
#endif
#if CAN_WRAP_jbd2_journal_recover
    WRAP_FOR_DETACH(jbd2_journal_recover)
#endif
#ifndef CAN_WRAP_set_page_dirty_lock
#   define CAN_WRAP_set_page_dirty_lock 1
#endif
#if CAN_WRAP_set_page_dirty_lock
    WRAP_FOR_DETACH(set_page_dirty_lock)
#endif
#ifndef CAN_WRAP_pci_request_acs
#   define CAN_WRAP_pci_request_acs 0
#endif
DETACH(pci_request_acs)
#ifndef CAN_WRAP_lru_add_page_tail
#   define CAN_WRAP_lru_add_page_tail 1
#endif
#if CAN_WRAP_lru_add_page_tail
    WRAP_FOR_DETACH(lru_add_page_tail)
#endif
#ifndef CAN_WRAP_syscall_trace_enter
#   define CAN_WRAP_syscall_trace_enter 1
#endif
#if CAN_WRAP_syscall_trace_enter
    WRAP_FOR_DETACH(syscall_trace_enter)
#endif
#ifndef CAN_WRAP_groups_search
#   define CAN_WRAP_groups_search 1
#endif
#if CAN_WRAP_groups_search
    WRAP_FOR_DETACH(groups_search)
#endif
#ifndef CAN_WRAP_add_device_randomness
#   define CAN_WRAP_add_device_randomness 0
#endif
DETACH(add_device_randomness)
#ifndef CAN_WRAP_create_empty_buffers
#   define CAN_WRAP_create_empty_buffers 1
#endif
#if CAN_WRAP_create_empty_buffers
    WRAP_FOR_DETACH(create_empty_buffers)
#endif
#ifndef CAN_WRAP_dev_remove_pack
#   define CAN_WRAP_dev_remove_pack 1
#endif
#if CAN_WRAP_dev_remove_pack
    WRAP_FOR_DETACH(dev_remove_pack)
#endif
#ifndef CAN_WRAP_oops_enter
#   define CAN_WRAP_oops_enter 0
#endif
DETACH(oops_enter)
#ifndef CAN_WRAP_security_msg_queue_alloc
#   define CAN_WRAP_security_msg_queue_alloc 1
#endif
#if CAN_WRAP_security_msg_queue_alloc
    WRAP_FOR_DETACH(security_msg_queue_alloc)
#endif
#ifndef CAN_WRAP_root_device_unregister
#   define CAN_WRAP_root_device_unregister 1
#endif
#if CAN_WRAP_root_device_unregister
    WRAP_FOR_DETACH(root_device_unregister)
#endif
#ifndef CAN_WRAP_class_compat_remove_link
#   define CAN_WRAP_class_compat_remove_link 1
#endif
#if CAN_WRAP_class_compat_remove_link
    WRAP_FOR_DETACH(class_compat_remove_link)
#endif
#ifndef CAN_WRAP_allow_signal
#   define CAN_WRAP_allow_signal 0
#endif
DETACH(allow_signal)
#ifndef CAN_WRAP_acpi_get_event_resources
#   define CAN_WRAP_acpi_get_event_resources 1
#endif
#if CAN_WRAP_acpi_get_event_resources
    WRAP_FOR_DETACH(acpi_get_event_resources)
#endif
#ifndef CAN_WRAP_iov_iter_advance
#   define CAN_WRAP_iov_iter_advance 1
#endif
#if CAN_WRAP_iov_iter_advance
    WRAP_FOR_DETACH(iov_iter_advance)
#endif
#ifndef CAN_WRAP_dynamic_irq_cleanup
#   define CAN_WRAP_dynamic_irq_cleanup 0
#endif
DETACH(dynamic_irq_cleanup)
#ifndef CAN_WRAP_ref_module
#   define CAN_WRAP_ref_module 1
#endif
#if CAN_WRAP_ref_module
    WRAP_FOR_DETACH(ref_module)
#endif
#ifndef CAN_WRAP_klist_remove
#   define CAN_WRAP_klist_remove 1
#endif
#if CAN_WRAP_klist_remove
    WRAP_FOR_DETACH(klist_remove)
#endif
#ifndef CAN_WRAP_reqsk_queue_destroy
#   define CAN_WRAP_reqsk_queue_destroy 1
#endif
#if CAN_WRAP_reqsk_queue_destroy
    WRAP_FOR_DETACH(reqsk_queue_destroy)
#endif
#ifndef CAN_WRAP_ata_pci_device_do_resume
#   define CAN_WRAP_ata_pci_device_do_resume 1
#endif
#if CAN_WRAP_ata_pci_device_do_resume
    WRAP_FOR_DETACH(ata_pci_device_do_resume)
#endif
#ifndef CAN_WRAP_sk_stream_wait_memory
#   define CAN_WRAP_sk_stream_wait_memory 1
#endif
#if CAN_WRAP_sk_stream_wait_memory
    WRAP_FOR_DETACH(sk_stream_wait_memory)
#endif
#ifndef CAN_WRAP_kstrtou16_from_user
#   define CAN_WRAP_kstrtou16_from_user 0
#endif
DETACH(kstrtou16_from_user)
#ifndef CAN_WRAP_bdev_stack_limits
#   define CAN_WRAP_bdev_stack_limits 1
#endif
#if CAN_WRAP_bdev_stack_limits
    WRAP_FOR_DETACH(bdev_stack_limits)
#endif
#ifndef CAN_WRAP_netdev_boot_setup_check
#   define CAN_WRAP_netdev_boot_setup_check 1
#endif
#if CAN_WRAP_netdev_boot_setup_check
    WRAP_FOR_DETACH(netdev_boot_setup_check)
#endif
#ifndef CAN_WRAP_fprop_fraction_percpu
#   define CAN_WRAP_fprop_fraction_percpu 1
#endif
#if CAN_WRAP_fprop_fraction_percpu
    WRAP_FOR_DETACH(fprop_fraction_percpu)
#endif
#ifndef CAN_WRAP_sanitize_e820_map
#   define CAN_WRAP_sanitize_e820_map 1
#endif
#if CAN_WRAP_sanitize_e820_map
    WRAP_FOR_DETACH(sanitize_e820_map)
#endif
#ifndef CAN_WRAP_mm_alloc
#   define CAN_WRAP_mm_alloc 1
#endif
#if CAN_WRAP_mm_alloc
    WRAP_FOR_DETACH(mm_alloc)
#endif
#ifndef CAN_WRAP_pci_request_selected_regions
#   define CAN_WRAP_pci_request_selected_regions 1
#endif
#if CAN_WRAP_pci_request_selected_regions
    WRAP_FOR_DETACH(pci_request_selected_regions)
#endif
#ifndef CAN_WRAP___sb_end_write
#   define CAN_WRAP___sb_end_write 1
#endif
#if CAN_WRAP___sb_end_write
#   ifdef DETACH_ADDR___sb_end_write
        WRAP_FOR_DETACH(__sb_end_write)
#   else
        TYPED_DETACH(__sb_end_write)
#   endif
#endif
#ifndef CAN_WRAP_skb_free_datagram_locked
#   define CAN_WRAP_skb_free_datagram_locked 1
#endif
#if CAN_WRAP_skb_free_datagram_locked
    WRAP_FOR_DETACH(skb_free_datagram_locked)
#endif
#ifndef CAN_WRAP_orderly_poweroff
#   define CAN_WRAP_orderly_poweroff 0
#endif
DETACH(orderly_poweroff)
#ifndef CAN_WRAP_kmalloc_order_trace
#   define CAN_WRAP_kmalloc_order_trace 0
#endif
DETACH(kmalloc_order_trace)
#ifndef CAN_WRAP_strsep
#   define CAN_WRAP_strsep 0
#endif
DETACH(strsep)
#ifndef CAN_WRAP_dm_set_target_max_io_len
#   define CAN_WRAP_dm_set_target_max_io_len 1
#endif
#if CAN_WRAP_dm_set_target_max_io_len
    WRAP_FOR_DETACH(dm_set_target_max_io_len)
#endif
#ifndef CAN_WRAP_security_sb_kern_mount
#   define CAN_WRAP_security_sb_kern_mount 1
#endif
#if CAN_WRAP_security_sb_kern_mount
    WRAP_FOR_DETACH(security_sb_kern_mount)
#endif
#ifndef CAN_WRAP_vfs_removexattr
#   define CAN_WRAP_vfs_removexattr 1
#endif
#if CAN_WRAP_vfs_removexattr
    WRAP_FOR_DETACH(vfs_removexattr)
#endif
#ifndef CAN_WRAP_kthread_should_park
#   define CAN_WRAP_kthread_should_park 0
#endif
DETACH(kthread_should_park)
#ifndef CAN_WRAP_dev_get_drvdata
#   define CAN_WRAP_dev_get_drvdata 1
#endif
#if CAN_WRAP_dev_get_drvdata
    WRAP_FOR_DETACH(dev_get_drvdata)
#endif
#ifndef CAN_WRAP___bitmap_and
#   define CAN_WRAP___bitmap_and 0
#endif
DETACH(__bitmap_and)
#ifndef CAN_WRAP_arch_get_unmapped_area
#   define CAN_WRAP_arch_get_unmapped_area 1
#endif
#if CAN_WRAP_arch_get_unmapped_area
    WRAP_FOR_DETACH(arch_get_unmapped_area)
#endif
#ifndef CAN_WRAP_swiotlb_unmap_sg_attrs
#   define CAN_WRAP_swiotlb_unmap_sg_attrs 1
#endif
#if CAN_WRAP_swiotlb_unmap_sg_attrs
    WRAP_FOR_DETACH(swiotlb_unmap_sg_attrs)
#endif
#ifndef CAN_WRAP_key_create_or_update
#   define CAN_WRAP_key_create_or_update 1
#endif
#if CAN_WRAP_key_create_or_update
    WRAP_FOR_DETACH(key_create_or_update)
#endif
#ifndef CAN_WRAP_unregister_reboot_notifier
#   define CAN_WRAP_unregister_reboot_notifier 1
#endif
#if CAN_WRAP_unregister_reboot_notifier
    WRAP_FOR_DETACH(unregister_reboot_notifier)
#endif
#ifndef CAN_WRAP_phy_start_interrupts
#   define CAN_WRAP_phy_start_interrupts 1
#endif
#if CAN_WRAP_phy_start_interrupts
    WRAP_FOR_DETACH(phy_start_interrupts)
#endif
#ifndef CAN_WRAP_compat_sys_sched_rr_get_interval
#   define CAN_WRAP_compat_sys_sched_rr_get_interval 1
#endif
#if CAN_WRAP_compat_sys_sched_rr_get_interval
    WRAP_FOR_DETACH(compat_sys_sched_rr_get_interval)
#endif
#ifndef CAN_WRAP_jbd2_journal_get_undo_access
#   define CAN_WRAP_jbd2_journal_get_undo_access 1
#endif
#if CAN_WRAP_jbd2_journal_get_undo_access
    WRAP_FOR_DETACH(jbd2_journal_get_undo_access)
#endif
#ifndef CAN_WRAP_set_tsc_mode
#   define CAN_WRAP_set_tsc_mode 0
#endif
DETACH(set_tsc_mode)
#ifndef CAN_WRAP_dev_loopback_xmit
#   define CAN_WRAP_dev_loopback_xmit 1
#endif
#if CAN_WRAP_dev_loopback_xmit
    WRAP_FOR_DETACH(dev_loopback_xmit)
#endif
#ifndef CAN_WRAP_sock_alloc_send_skb
#   define CAN_WRAP_sock_alloc_send_skb 1
#endif
#if CAN_WRAP_sock_alloc_send_skb
    WRAP_FOR_DETACH(sock_alloc_send_skb)
#endif
#ifndef CAN_WRAP_ata_bmdma_qc_issue
#   define CAN_WRAP_ata_bmdma_qc_issue 1
#endif
#if CAN_WRAP_ata_bmdma_qc_issue
    WRAP_FOR_DETACH(ata_bmdma_qc_issue)
#endif
#ifndef CAN_WRAP_dev_get_by_index
#   define CAN_WRAP_dev_get_by_index 1
#endif
#if CAN_WRAP_dev_get_by_index
    WRAP_FOR_DETACH(dev_get_by_index)
#endif
#ifndef CAN_WRAP___put_user_bad
#   define CAN_WRAP___put_user_bad 0
#endif
DETACH(__put_user_bad)
#ifndef CAN_WRAP_compat_sys_mq_timedsend
#   define CAN_WRAP_compat_sys_mq_timedsend 1
#endif
#if CAN_WRAP_compat_sys_mq_timedsend
    WRAP_FOR_DETACH(compat_sys_mq_timedsend)
#endif
#ifndef CAN_WRAP_disallow_signal
#   define CAN_WRAP_disallow_signal 0
#endif
DETACH(disallow_signal)
#ifndef CAN_WRAP_device_set_wakeup_capable
#   define CAN_WRAP_device_set_wakeup_capable 1
#endif
#if CAN_WRAP_device_set_wakeup_capable
    WRAP_FOR_DETACH(device_set_wakeup_capable)
#endif
#ifndef CAN_WRAP_pcibios_retrieve_fw_addr
#   define CAN_WRAP_pcibios_retrieve_fw_addr 1
#endif
#if CAN_WRAP_pcibios_retrieve_fw_addr
    WRAP_FOR_DETACH(pcibios_retrieve_fw_addr)
#endif
#ifndef CAN_WRAP_sched_destroy_group
#   define CAN_WRAP_sched_destroy_group 1
#endif
#if CAN_WRAP_sched_destroy_group
    WRAP_FOR_DETACH(sched_destroy_group)
#endif
#ifndef CAN_WRAP_text_poke
#   define CAN_WRAP_text_poke 0
#endif
DETACH(text_poke)
#ifndef CAN_WRAP_skb_shift
#   define CAN_WRAP_skb_shift 1
#endif
#if CAN_WRAP_skb_shift
    WRAP_FOR_DETACH(skb_shift)
#endif
#ifndef CAN_WRAP___xadd_wrong_size
#   define CAN_WRAP___xadd_wrong_size 0
#endif
DETACH(__xadd_wrong_size)
#ifndef CAN_WRAP_acpi_video_backlight_support
#   define CAN_WRAP_acpi_video_backlight_support 0
#endif
DETACH(acpi_video_backlight_support)
#ifndef CAN_WRAP_blkdev_issue_discard
#   define CAN_WRAP_blkdev_issue_discard 1
#endif
#if CAN_WRAP_blkdev_issue_discard
    WRAP_FOR_DETACH(blkdev_issue_discard)
#endif
#ifndef CAN_WRAP_input_handler_for_each_handle
#   define CAN_WRAP_input_handler_for_each_handle 1
#endif
#if CAN_WRAP_input_handler_for_each_handle
    WRAP_FOR_DETACH(input_handler_for_each_handle)
#endif
#ifndef CAN_WRAP_subsys_dev_iter_next
#   define CAN_WRAP_subsys_dev_iter_next 1
#endif
#if CAN_WRAP_subsys_dev_iter_next
    WRAP_FOR_DETACH(subsys_dev_iter_next)
#endif
#ifndef CAN_WRAP_e820_search_gap
#   define CAN_WRAP_e820_search_gap 0
#endif
DETACH(e820_search_gap)
#ifndef CAN_WRAP_fprop_local_destroy_single
#   define CAN_WRAP_fprop_local_destroy_single 1
#endif
#if CAN_WRAP_fprop_local_destroy_single
    WRAP_FOR_DETACH(fprop_local_destroy_single)
#endif
#ifndef CAN_WRAP_nf_getsockopt
#   define CAN_WRAP_nf_getsockopt 1
#endif
#if CAN_WRAP_nf_getsockopt
    WRAP_FOR_DETACH(nf_getsockopt)
#endif
#ifndef CAN_WRAP_dquot_set_dqblk
#   define CAN_WRAP_dquot_set_dqblk 1
#endif
#if CAN_WRAP_dquot_set_dqblk
    WRAP_FOR_DETACH(dquot_set_dqblk)
#endif
#ifndef CAN_WRAP_sysfs_format_mac
#   define CAN_WRAP_sysfs_format_mac 0
#endif
DETACH(sysfs_format_mac)
#ifndef CAN_WRAP_skb_add_rx_frag
#   define CAN_WRAP_skb_add_rx_frag 1
#endif
#if CAN_WRAP_skb_add_rx_frag
    WRAP_FOR_DETACH(skb_add_rx_frag)
#endif
#ifndef CAN_WRAP_truncate_inode_pages
#   define CAN_WRAP_truncate_inode_pages 1
#endif
#if CAN_WRAP_truncate_inode_pages
    WRAP_FOR_DETACH(truncate_inode_pages)
#endif
#ifndef CAN_WRAP_schedule_timeout
#   define CAN_WRAP_schedule_timeout 0
#endif
DETACH(schedule_timeout)
#ifndef CAN_WRAP_register_pernet_subsys
#   define CAN_WRAP_register_pernet_subsys 1
#endif
#if CAN_WRAP_register_pernet_subsys
    WRAP_FOR_DETACH(register_pernet_subsys)
#endif
#ifndef CAN_WRAP_page_readlink
#   define CAN_WRAP_page_readlink 1
#endif
#if CAN_WRAP_page_readlink
    WRAP_FOR_DETACH(page_readlink)
#endif
#ifndef CAN_WRAP_unshare_nsproxy_namespaces
#   define CAN_WRAP_unshare_nsproxy_namespaces 1
#endif
#if CAN_WRAP_unshare_nsproxy_namespaces
    WRAP_FOR_DETACH(unshare_nsproxy_namespaces)
#endif
#ifndef CAN_WRAP_ata_sas_port_destroy
#   define CAN_WRAP_ata_sas_port_destroy 1
#endif
#if CAN_WRAP_ata_sas_port_destroy
    WRAP_FOR_DETACH(ata_sas_port_destroy)
#endif
#ifndef CAN_WRAP_pcpu_free_alloc_info
#   define CAN_WRAP_pcpu_free_alloc_info 1
#endif
#if CAN_WRAP_pcpu_free_alloc_info
    WRAP_FOR_DETACH(pcpu_free_alloc_info)
#endif
#ifndef CAN_WRAP_pci_release_regions
#   define CAN_WRAP_pci_release_regions 1
#endif
#if CAN_WRAP_pci_release_regions
    WRAP_FOR_DETACH(pci_release_regions)
#endif
#ifndef CAN_WRAP_jbd2_clear_buffer_revoked_flags
#   define CAN_WRAP_jbd2_clear_buffer_revoked_flags 1
#endif
#if CAN_WRAP_jbd2_clear_buffer_revoked_flags
    WRAP_FOR_DETACH(jbd2_clear_buffer_revoked_flags)
#endif
#ifndef CAN_WRAP_blk_limits_io_min
#   define CAN_WRAP_blk_limits_io_min 1
#endif
#if CAN_WRAP_blk_limits_io_min
    WRAP_FOR_DETACH(blk_limits_io_min)
#endif
#ifndef CAN_WRAP_get_compat_timeval
#   define CAN_WRAP_get_compat_timeval 1
#endif
#if CAN_WRAP_get_compat_timeval
    WRAP_FOR_DETACH(get_compat_timeval)
#endif
#ifndef CAN_WRAP_suspend_device_irqs
#   define CAN_WRAP_suspend_device_irqs 0
#endif
DETACH(suspend_device_irqs)
#ifndef CAN_WRAP_invalidate_partitions
#   define CAN_WRAP_invalidate_partitions 1
#endif
#if CAN_WRAP_invalidate_partitions
    WRAP_FOR_DETACH(invalidate_partitions)
#endif
#ifndef CAN_WRAP_wmi_set_block
#   define CAN_WRAP_wmi_set_block 1
#endif
#if CAN_WRAP_wmi_set_block
    WRAP_FOR_DETACH(wmi_set_block)
#endif
#ifndef CAN_WRAP___put_user_4
#   define CAN_WRAP___put_user_4 0
#endif
DETACH(__put_user_4)
#ifndef CAN_WRAP_schedule_hrtimeout_range
#   define CAN_WRAP_schedule_hrtimeout_range 0
#endif
DETACH(schedule_hrtimeout_range)
#ifndef CAN_WRAP___quota_error
#   define CAN_WRAP___quota_error 1
#endif
#if CAN_WRAP___quota_error
#   ifdef DETACH_ADDR___quota_error
        WRAP_FOR_DETACH(__quota_error)
#   else
        TYPED_DETACH(__quota_error)
#   endif
#endif
#ifndef CAN_WRAP___put_user_1
#   define CAN_WRAP___put_user_1 0
#endif
DETACH(__put_user_1)
#ifndef CAN_WRAP___put_user_2
#   define CAN_WRAP___put_user_2 0
#endif
DETACH(__put_user_2)
#ifndef CAN_WRAP_print_vma_addr
#   define CAN_WRAP_print_vma_addr 0
#endif
DETACH(print_vma_addr)
#ifndef CAN_WRAP_dma_sync_wait
#   define CAN_WRAP_dma_sync_wait 1
#endif
#if CAN_WRAP_dma_sync_wait
    WRAP_FOR_DETACH(dma_sync_wait)
#endif
#ifndef CAN_WRAP_vread
#   define CAN_WRAP_vread 0
#endif
DETACH(vread)
#ifndef CAN_WRAP_alternatives_smp_module_del
#   define CAN_WRAP_alternatives_smp_module_del 1
#endif
#if CAN_WRAP_alternatives_smp_module_del
    WRAP_FOR_DETACH(alternatives_smp_module_del)
#endif
#ifndef CAN_WRAP_acpi_os_allocate
#   define CAN_WRAP_acpi_os_allocate 0
#endif
DETACH(acpi_os_allocate)
#ifndef CAN_WRAP_acpi_write_bit_register
#   define CAN_WRAP_acpi_write_bit_register 0
#endif
DETACH(acpi_write_bit_register)
#ifndef CAN_WRAP___srcu_notifier_call_chain
#   define CAN_WRAP___srcu_notifier_call_chain 1
#endif
#if CAN_WRAP___srcu_notifier_call_chain
#   ifdef DETACH_ADDR___srcu_notifier_call_chain
        WRAP_FOR_DETACH(__srcu_notifier_call_chain)
#   else
        TYPED_DETACH(__srcu_notifier_call_chain)
#   endif
#endif
#ifndef CAN_WRAP_strcmp
#   define CAN_WRAP_strcmp 0
#endif
DETACH(strcmp)
#ifndef CAN_WRAP_up_read
#   define CAN_WRAP_up_read 1
#endif
#if CAN_WRAP_up_read
    WRAP_FOR_DETACH(up_read)
#endif
#ifndef CAN_WRAP_vfs_write
#   define CAN_WRAP_vfs_write 1
#endif
#if CAN_WRAP_vfs_write
    WRAP_FOR_DETACH(vfs_write)
#endif
#ifndef CAN_WRAP_acpi_disable_event
#   define CAN_WRAP_acpi_disable_event 0
#endif
DETACH(acpi_disable_event)
#ifndef CAN_WRAP_sock_setsockopt
#   define CAN_WRAP_sock_setsockopt 1
#endif
#if CAN_WRAP_sock_setsockopt
    WRAP_FOR_DETACH(sock_setsockopt)
#endif
#ifndef CAN_WRAP_sg_last
#   define CAN_WRAP_sg_last 1
#endif
#if CAN_WRAP_sg_last
    WRAP_FOR_DETACH(sg_last)
#endif
#ifndef CAN_WRAP_ata_pci_device_suspend
#   define CAN_WRAP_ata_pci_device_suspend 1
#endif
#if CAN_WRAP_ata_pci_device_suspend
    WRAP_FOR_DETACH(ata_pci_device_suspend)
#endif
#ifndef CAN_WRAP_percpu_counter_destroy
#   define CAN_WRAP_percpu_counter_destroy 1
#endif
#if CAN_WRAP_percpu_counter_destroy
    WRAP_FOR_DETACH(percpu_counter_destroy)
#endif
#ifndef CAN_WRAP_local_bh_disable
#   define CAN_WRAP_local_bh_disable 0
#endif
DETACH(local_bh_disable)
#ifndef CAN_WRAP_dma_common_get_sgtable
#   define CAN_WRAP_dma_common_get_sgtable 1
#endif
#if CAN_WRAP_dma_common_get_sgtable
    WRAP_FOR_DETACH(dma_common_get_sgtable)
#endif
#ifndef CAN_WRAP_dma_chan_cleanup
#   define CAN_WRAP_dma_chan_cleanup 1
#endif
#if CAN_WRAP_dma_chan_cleanup
    WRAP_FOR_DETACH(dma_chan_cleanup)
#endif
#ifndef CAN_WRAP_kstrtou8
#   define CAN_WRAP_kstrtou8 0
#endif
DETACH(kstrtou8)
#ifndef CAN_WRAP___alloc_workqueue_key
#   define CAN_WRAP___alloc_workqueue_key 0
#endif
DETACH(__alloc_workqueue_key)
#ifndef CAN_WRAP_compat_sys_sigaltstack
#   define CAN_WRAP_compat_sys_sigaltstack 1
#endif
#if CAN_WRAP_compat_sys_sigaltstack
    WRAP_FOR_DETACH(compat_sys_sigaltstack)
#endif
#ifndef CAN_WRAP_page_swapcount
#   define CAN_WRAP_page_swapcount 1
#endif
#if CAN_WRAP_page_swapcount
    WRAP_FOR_DETACH(page_swapcount)
#endif
#ifndef CAN_WRAP_vlan_vid_del
#   define CAN_WRAP_vlan_vid_del 1
#endif
#if CAN_WRAP_vlan_vid_del
    WRAP_FOR_DETACH(vlan_vid_del)
#endif
#ifndef CAN_WRAP_security_sk_free
#   define CAN_WRAP_security_sk_free 1
#endif
#if CAN_WRAP_security_sk_free
    WRAP_FOR_DETACH(security_sk_free)
#endif
#ifndef CAN_WRAP_follow_page
#   define CAN_WRAP_follow_page 1
#endif
#if CAN_WRAP_follow_page
    WRAP_FOR_DETACH(follow_page)
#endif
#ifndef CAN_WRAP_init_cpu_possible
#   define CAN_WRAP_init_cpu_possible 1
#endif
#if CAN_WRAP_init_cpu_possible
    WRAP_FOR_DETACH(init_cpu_possible)
#endif
#ifndef CAN_WRAP_queue_kthread_work
#   define CAN_WRAP_queue_kthread_work 1
#endif
#if CAN_WRAP_queue_kthread_work
    WRAP_FOR_DETACH(queue_kthread_work)
#endif
#ifndef CAN_WRAP_dev_seq_stop
#   define CAN_WRAP_dev_seq_stop 1
#endif
#if CAN_WRAP_dev_seq_stop
    WRAP_FOR_DETACH(dev_seq_stop)
#endif
#ifndef CAN_WRAP_set_pcie_hotplug_bridge
#   define CAN_WRAP_set_pcie_hotplug_bridge 1
#endif
#if CAN_WRAP_set_pcie_hotplug_bridge
    WRAP_FOR_DETACH(set_pcie_hotplug_bridge)
#endif
#ifndef CAN_WRAP_per_cpu_ptr_to_phys
#   define CAN_WRAP_per_cpu_ptr_to_phys 0
#endif
DETACH(per_cpu_ptr_to_phys)
#ifndef CAN_WRAP_dquot_get_dqinfo
#   define CAN_WRAP_dquot_get_dqinfo 1
#endif
#if CAN_WRAP_dquot_get_dqinfo
    WRAP_FOR_DETACH(dquot_get_dqinfo)
#endif
#ifndef CAN_WRAP_skip_free_areas_node
#   define CAN_WRAP_skip_free_areas_node 0
#endif
DETACH(skip_free_areas_node)
#ifndef CAN_WRAP_disable_pid_allocation
#   define CAN_WRAP_disable_pid_allocation 1
#endif
#if CAN_WRAP_disable_pid_allocation
    WRAP_FOR_DETACH(disable_pid_allocation)
#endif
#ifndef CAN_WRAP_untrack_pfn
#   define CAN_WRAP_untrack_pfn 1
#endif
#if CAN_WRAP_untrack_pfn
    WRAP_FOR_DETACH(untrack_pfn)
#endif
#ifndef CAN_WRAP_acpi_terminate
#   define CAN_WRAP_acpi_terminate 0
#endif
DETACH(acpi_terminate)
#ifndef CAN_WRAP_kfree
#   define CAN_WRAP_kfree 1
#endif
#if CAN_WRAP_kfree
    WRAP_FOR_DETACH(kfree)
#endif
#ifndef CAN_WRAP_mutex_spin_on_owner
#   define CAN_WRAP_mutex_spin_on_owner 1
#endif
#if CAN_WRAP_mutex_spin_on_owner
    WRAP_FOR_DETACH(mutex_spin_on_owner)
#endif
#ifndef CAN_WRAP_default_scale_smt_power
#   define CAN_WRAP_default_scale_smt_power 1
#endif
#if CAN_WRAP_default_scale_smt_power
    WRAP_FOR_DETACH(default_scale_smt_power)
#endif
#ifndef CAN_WRAP_security_ipc_permission
#   define CAN_WRAP_security_ipc_permission 1
#endif
#if CAN_WRAP_security_ipc_permission
    WRAP_FOR_DETACH(security_ipc_permission)
#endif
#ifndef CAN_WRAP_ata_sas_port_alloc
#   define CAN_WRAP_ata_sas_port_alloc 1
#endif
#if CAN_WRAP_ata_sas_port_alloc
    WRAP_FOR_DETACH(ata_sas_port_alloc)
#endif
#ifndef CAN_WRAP_pcie_set_readrq
#   define CAN_WRAP_pcie_set_readrq 1
#endif
#if CAN_WRAP_pcie_set_readrq
    WRAP_FOR_DETACH(pcie_set_readrq)
#endif
#ifndef CAN_WRAP_init_timer_stats
#   define CAN_WRAP_init_timer_stats 0
#endif
DETACH(init_timer_stats)
#ifndef CAN_WRAP_vfs_fstat
#   define CAN_WRAP_vfs_fstat 1
#endif
#if CAN_WRAP_vfs_fstat
    WRAP_FOR_DETACH(vfs_fstat)
#endif
#ifndef CAN_WRAP_netlink_rcv_skb
#   define CAN_WRAP_netlink_rcv_skb 1
#endif
#if CAN_WRAP_netlink_rcv_skb
    WRAP_FOR_DETACH(netlink_rcv_skb)
#endif
#ifndef CAN_WRAP___rtnl_af_unregister
#   define CAN_WRAP___rtnl_af_unregister 1
#endif
#if CAN_WRAP___rtnl_af_unregister
#   ifdef DETACH_ADDR___rtnl_af_unregister
        WRAP_FOR_DETACH(__rtnl_af_unregister)
#   else
        TYPED_DETACH(__rtnl_af_unregister)
#   endif
#endif
#ifndef CAN_WRAP_probe_irq_mask
#   define CAN_WRAP_probe_irq_mask 0
#endif
DETACH(probe_irq_mask)
#ifndef CAN_WRAP_register_blkdev
#   define CAN_WRAP_register_blkdev 0
#endif
DETACH(register_blkdev)
#ifndef CAN_WRAP_follow_pfn
#   define CAN_WRAP_follow_pfn 1
#endif
#if CAN_WRAP_follow_pfn
    WRAP_FOR_DETACH(follow_pfn)
#endif
#ifndef CAN_WRAP_genphy_restart_aneg
#   define CAN_WRAP_genphy_restart_aneg 1
#endif
#if CAN_WRAP_genphy_restart_aneg
    WRAP_FOR_DETACH(genphy_restart_aneg)
#endif
#ifndef CAN_WRAP_do_mount
#   define CAN_WRAP_do_mount 0
#endif
DETACH(do_mount)
#ifndef CAN_WRAP_simple_getattr
#   define CAN_WRAP_simple_getattr 1
#endif
#if CAN_WRAP_simple_getattr
    WRAP_FOR_DETACH(simple_getattr)
#endif
#ifndef CAN_WRAP_make_bad_inode
#   define CAN_WRAP_make_bad_inode 1
#endif
#if CAN_WRAP_make_bad_inode
    WRAP_FOR_DETACH(make_bad_inode)
#endif
#ifndef CAN_WRAP_dev_close
#   define CAN_WRAP_dev_close 1
#endif
#if CAN_WRAP_dev_close
    WRAP_FOR_DETACH(dev_close)
#endif
#ifndef CAN_WRAP_sock_queue_err_skb
#   define CAN_WRAP_sock_queue_err_skb 1
#endif
#if CAN_WRAP_sock_queue_err_skb
    WRAP_FOR_DETACH(sock_queue_err_skb)
#endif
#ifndef CAN_WRAP_dma_set_mask
#   define CAN_WRAP_dma_set_mask 1
#endif
#if CAN_WRAP_dma_set_mask
    WRAP_FOR_DETACH(dma_set_mask)
#endif
#ifndef CAN_WRAP_release_pages
#   define CAN_WRAP_release_pages 0
#endif
DETACH(release_pages)
#ifndef CAN_WRAP_simple_xattr_list_add
#   define CAN_WRAP_simple_xattr_list_add 1
#endif
#if CAN_WRAP_simple_xattr_list_add
    WRAP_FOR_DETACH(simple_xattr_list_add)
#endif
#ifndef CAN_WRAP_sched_group_set_rt_period
#   define CAN_WRAP_sched_group_set_rt_period 1
#endif
#if CAN_WRAP_sched_group_set_rt_period
    WRAP_FOR_DETACH(sched_group_set_rt_period)
#endif
#ifndef CAN_WRAP_tasklet_kill_immediate
#   define CAN_WRAP_tasklet_kill_immediate 1
#endif
#if CAN_WRAP_tasklet_kill_immediate
    WRAP_FOR_DETACH(tasklet_kill_immediate)
#endif
#ifndef CAN_WRAP_dev_getfirstbyhwtype
#   define CAN_WRAP_dev_getfirstbyhwtype 1
#endif
#if CAN_WRAP_dev_getfirstbyhwtype
    WRAP_FOR_DETACH(dev_getfirstbyhwtype)
#endif
#ifndef CAN_WRAP___dst_destroy_metrics_generic
#   define CAN_WRAP___dst_destroy_metrics_generic 1
#endif
#if CAN_WRAP___dst_destroy_metrics_generic
#   ifdef DETACH_ADDR___dst_destroy_metrics_generic
        WRAP_FOR_DETACH(__dst_destroy_metrics_generic)
#   else
        TYPED_DETACH(__dst_destroy_metrics_generic)
#   endif
#endif
#ifndef CAN_WRAP_hrtimer_start_range_ns
#   define CAN_WRAP_hrtimer_start_range_ns 1
#endif
#if CAN_WRAP_hrtimer_start_range_ns
    WRAP_FOR_DETACH(hrtimer_start_range_ns)
#endif
#ifndef CAN_WRAP_xattr_getsecurity
#   define CAN_WRAP_xattr_getsecurity 1
#endif
#if CAN_WRAP_xattr_getsecurity
    WRAP_FOR_DETACH(xattr_getsecurity)
#endif
#ifndef CAN_WRAP_setup_memory_map
#   define CAN_WRAP_setup_memory_map 0
#endif
DETACH(setup_memory_map)
#ifndef CAN_WRAP_in_group_p
#   define CAN_WRAP_in_group_p 0
#endif
DETACH(in_group_p)
#ifndef CAN_WRAP_pci_save_state
#   define CAN_WRAP_pci_save_state 1
#endif
#if CAN_WRAP_pci_save_state
    WRAP_FOR_DETACH(pci_save_state)
#endif
#ifndef CAN_WRAP_pm_generic_suspend_noirq
#   define CAN_WRAP_pm_generic_suspend_noirq 1
#endif
#if CAN_WRAP_pm_generic_suspend_noirq
    WRAP_FOR_DETACH(pm_generic_suspend_noirq)
#endif
#ifndef CAN_WRAP_acpi_os_prepare_sleep
#   define CAN_WRAP_acpi_os_prepare_sleep 0
#endif
DETACH(acpi_os_prepare_sleep)
#ifndef CAN_WRAP_scsi_queue_work
#   define CAN_WRAP_scsi_queue_work 1
#endif
#if CAN_WRAP_scsi_queue_work
    WRAP_FOR_DETACH(scsi_queue_work)
#endif
#ifndef CAN_WRAP_sock_prot_inuse_add
#   define CAN_WRAP_sock_prot_inuse_add 1
#endif
#if CAN_WRAP_sock_prot_inuse_add
    WRAP_FOR_DETACH(sock_prot_inuse_add)
#endif
#ifndef CAN_WRAP_move_page_tables
#   define CAN_WRAP_move_page_tables 1
#endif
#if CAN_WRAP_move_page_tables
    WRAP_FOR_DETACH(move_page_tables)
#endif
#ifndef CAN_WRAP_kmemdup
#   define CAN_WRAP_kmemdup 0
#endif
DETACH(kmemdup)
#ifndef CAN_WRAP_eth_rebuild_header
#   define CAN_WRAP_eth_rebuild_header 1
#endif
#if CAN_WRAP_eth_rebuild_header
    WRAP_FOR_DETACH(eth_rebuild_header)
#endif
#ifndef CAN_WRAP_cred_alloc_blank
#   define CAN_WRAP_cred_alloc_blank 1
#endif
#if CAN_WRAP_cred_alloc_blank
    WRAP_FOR_DETACH(cred_alloc_blank)
#endif
#ifndef CAN_WRAP_generic_smp_call_function_interrupt
#   define CAN_WRAP_generic_smp_call_function_interrupt 0
#endif
DETACH(generic_smp_call_function_interrupt)
#ifndef CAN_WRAP_dev_set_promiscuity
#   define CAN_WRAP_dev_set_promiscuity 1
#endif
#if CAN_WRAP_dev_set_promiscuity
    WRAP_FOR_DETACH(dev_set_promiscuity)
#endif
#ifndef CAN_WRAP_dm_register_target
#   define CAN_WRAP_dm_register_target 1
#endif
#if CAN_WRAP_dm_register_target
    WRAP_FOR_DETACH(dm_register_target)
#endif
#ifndef CAN_WRAP_sleep_on_timeout
#   define CAN_WRAP_sleep_on_timeout 1
#endif
#if CAN_WRAP_sleep_on_timeout
    WRAP_FOR_DETACH(sleep_on_timeout)
#endif
#ifndef CAN_WRAP_sock_no_sendpage
#   define CAN_WRAP_sock_no_sendpage 1
#endif
#if CAN_WRAP_sock_no_sendpage
    WRAP_FOR_DETACH(sock_no_sendpage)
#endif
#ifndef CAN_WRAP_acpi_bus_power_manageable
#   define CAN_WRAP_acpi_bus_power_manageable 0
#endif
DETACH(acpi_bus_power_manageable)
#ifndef CAN_WRAP_vm_mmap
#   define CAN_WRAP_vm_mmap 1
#endif
#if CAN_WRAP_vm_mmap
    WRAP_FOR_DETACH(vm_mmap)
#endif
#ifndef CAN_WRAP_sock_create_kern
#   define CAN_WRAP_sock_create_kern 0
#endif
DETACH(sock_create_kern)
#ifndef CAN_WRAP_pcibios_set_irq_routing
#   define CAN_WRAP_pcibios_set_irq_routing 1
#endif
#if CAN_WRAP_pcibios_set_irq_routing
    WRAP_FOR_DETACH(pcibios_set_irq_routing)
#endif
#ifndef CAN_WRAP_clean_sort_range
#   define CAN_WRAP_clean_sort_range 1
#endif
#if CAN_WRAP_clean_sort_range
    WRAP_FOR_DETACH(clean_sort_range)
#endif
#ifndef CAN_WRAP_compat_sys_settimeofday
#   define CAN_WRAP_compat_sys_settimeofday 1
#endif
#if CAN_WRAP_compat_sys_settimeofday
    WRAP_FOR_DETACH(compat_sys_settimeofday)
#endif
#ifndef CAN_WRAP_device_shutdown
#   define CAN_WRAP_device_shutdown 0
#endif
DETACH(device_shutdown)
#ifndef CAN_WRAP_regs_query_register_offset
#   define CAN_WRAP_regs_query_register_offset 0
#endif
DETACH(regs_query_register_offset)
#ifndef CAN_WRAP_get_vfs_caps_from_disk
#   define CAN_WRAP_get_vfs_caps_from_disk 1
#endif
#if CAN_WRAP_get_vfs_caps_from_disk
    WRAP_FOR_DETACH(get_vfs_caps_from_disk)
#endif
#ifndef CAN_WRAP_bus_get_kset
#   define CAN_WRAP_bus_get_kset 1
#endif
#if CAN_WRAP_bus_get_kset
    WRAP_FOR_DETACH(bus_get_kset)
#endif
#ifndef CAN_WRAP_nr_free_pagecache_pages
#   define CAN_WRAP_nr_free_pagecache_pages 0
#endif
DETACH(nr_free_pagecache_pages)
#ifndef CAN_WRAP_rdmsr_safe_regs
#   define CAN_WRAP_rdmsr_safe_regs 0
#endif
DETACH(rdmsr_safe_regs)
#ifndef CAN_WRAP___reqsk_queue_destroy
#   define CAN_WRAP___reqsk_queue_destroy 1
#endif
#if CAN_WRAP___reqsk_queue_destroy
#   ifdef DETACH_ADDR___reqsk_queue_destroy
        WRAP_FOR_DETACH(__reqsk_queue_destroy)
#   else
        TYPED_DETACH(__reqsk_queue_destroy)
#   endif
#endif
#ifndef CAN_WRAP_native_smp_prepare_cpus
#   define CAN_WRAP_native_smp_prepare_cpus 0
#endif
DETACH(native_smp_prepare_cpus)
#ifndef CAN_WRAP_ec_read
#   define CAN_WRAP_ec_read 0
#endif
DETACH(ec_read)
#ifndef CAN_WRAP_ida_get_new
#   define CAN_WRAP_ida_get_new 1
#endif
#if CAN_WRAP_ida_get_new
    WRAP_FOR_DETACH(ida_get_new)
#endif
#ifndef CAN_WRAP_vfs_llseek
#   define CAN_WRAP_vfs_llseek 1
#endif
#if CAN_WRAP_vfs_llseek
    WRAP_FOR_DETACH(vfs_llseek)
#endif
#ifndef CAN_WRAP_ata_std_postreset
#   define CAN_WRAP_ata_std_postreset 1
#endif
#if CAN_WRAP_ata_std_postreset
    WRAP_FOR_DETACH(ata_std_postreset)
#endif
#ifndef CAN_WRAP_reqsk_fastopen_remove
#   define CAN_WRAP_reqsk_fastopen_remove 1
#endif
#if CAN_WRAP_reqsk_fastopen_remove
    WRAP_FOR_DETACH(reqsk_fastopen_remove)
#endif
#ifndef CAN_WRAP_kill_proc_info
#   define CAN_WRAP_kill_proc_info 1
#endif
#if CAN_WRAP_kill_proc_info
    WRAP_FOR_DETACH(kill_proc_info)
#endif
#ifndef CAN_WRAP___bad_unaligned_access_size
#   define CAN_WRAP___bad_unaligned_access_size 0
#endif
DETACH(__bad_unaligned_access_size)
#ifndef CAN_WRAP_default_cpu_present_to_apicid
#   define CAN_WRAP_default_cpu_present_to_apicid 0
#endif
DETACH(default_cpu_present_to_apicid)
#ifndef CAN_WRAP_simple_attr_read
#   define CAN_WRAP_simple_attr_read 1
#endif
#if CAN_WRAP_simple_attr_read
    WRAP_FOR_DETACH(simple_attr_read)
#endif
#ifndef CAN_WRAP_cdrom_open
#   define CAN_WRAP_cdrom_open 1
#endif
#if CAN_WRAP_cdrom_open
    WRAP_FOR_DETACH(cdrom_open)
#endif
#ifndef CAN_WRAP_part_inflight_show
#   define CAN_WRAP_part_inflight_show 1
#endif
#if CAN_WRAP_part_inflight_show
    WRAP_FOR_DETACH(part_inflight_show)
#endif
#ifndef CAN_WRAP_netdev_set_bond_master
#   define CAN_WRAP_netdev_set_bond_master 1
#endif
#if CAN_WRAP_netdev_set_bond_master
    WRAP_FOR_DETACH(netdev_set_bond_master)
#endif
#ifndef CAN_WRAP_iov_iter_single_seg_count
#   define CAN_WRAP_iov_iter_single_seg_count 1
#endif
#if CAN_WRAP_iov_iter_single_seg_count
    WRAP_FOR_DETACH(iov_iter_single_seg_count)
#endif
#ifndef CAN_WRAP_sock_common_getsockopt
#   define CAN_WRAP_sock_common_getsockopt 1
#endif
#if CAN_WRAP_sock_common_getsockopt
    WRAP_FOR_DETACH(sock_common_getsockopt)
#endif
#ifndef CAN_WRAP_dump_stack
#   define CAN_WRAP_dump_stack 0
#endif
DETACH(dump_stack)
#ifndef CAN_WRAP___this_fixmap_does_not_exist
#   define CAN_WRAP___this_fixmap_does_not_exist 0
#endif
DETACH(__this_fixmap_does_not_exist)
#ifndef CAN_WRAP_blk_queue_rq_timeout
#   define CAN_WRAP_blk_queue_rq_timeout 1
#endif
#if CAN_WRAP_blk_queue_rq_timeout
    WRAP_FOR_DETACH(blk_queue_rq_timeout)
#endif
#ifndef CAN_WRAP_inet_frags_fini
#   define CAN_WRAP_inet_frags_fini 1
#endif
#if CAN_WRAP_inet_frags_fini
    WRAP_FOR_DETACH(inet_frags_fini)
#endif
#ifndef CAN_WRAP_security_secmark_relabel_packet
#   define CAN_WRAP_security_secmark_relabel_packet 0
#endif
DETACH(security_secmark_relabel_packet)
#ifndef CAN_WRAP_cgroup_scan_tasks
#   define CAN_WRAP_cgroup_scan_tasks 1
#endif
#if CAN_WRAP_cgroup_scan_tasks
    WRAP_FOR_DETACH(cgroup_scan_tasks)
#endif
#ifndef CAN_WRAP_proc_net_mkdir
#   define CAN_WRAP_proc_net_mkdir 1
#endif
#if CAN_WRAP_proc_net_mkdir
    WRAP_FOR_DETACH(proc_net_mkdir)
#endif
#ifndef CAN_WRAP_acpi_os_table_override
#   define CAN_WRAP_acpi_os_table_override 1
#endif
#if CAN_WRAP_acpi_os_table_override
    WRAP_FOR_DETACH(acpi_os_table_override)
#endif
#ifndef CAN_WRAP_bitmap_fold
#   define CAN_WRAP_bitmap_fold 0
#endif
DETACH(bitmap_fold)
#ifndef CAN_WRAP_del_timer_sync
#   define CAN_WRAP_del_timer_sync 1
#endif
#if CAN_WRAP_del_timer_sync
    WRAP_FOR_DETACH(del_timer_sync)
#endif
#ifndef CAN_WRAP_skb_segment
#   define CAN_WRAP_skb_segment 1
#endif
#if CAN_WRAP_skb_segment
    WRAP_FOR_DETACH(skb_segment)
#endif
#ifndef CAN_WRAP_acpi_os_wait_events_complete
#   define CAN_WRAP_acpi_os_wait_events_complete 0
#endif
DETACH(acpi_os_wait_events_complete)
#ifndef CAN_WRAP_no_pci_devices
#   define CAN_WRAP_no_pci_devices 0
#endif
DETACH(no_pci_devices)
#ifndef CAN_WRAP_radix_tree_lookup
#   define CAN_WRAP_radix_tree_lookup 1
#endif
#if CAN_WRAP_radix_tree_lookup
    WRAP_FOR_DETACH(radix_tree_lookup)
#endif
#ifndef CAN_WRAP_phy_init_eee
#   define CAN_WRAP_phy_init_eee 1
#endif
#if CAN_WRAP_phy_init_eee
    WRAP_FOR_DETACH(phy_init_eee)
#endif
#ifndef CAN_WRAP_ata_bmdma_error_handler
#   define CAN_WRAP_ata_bmdma_error_handler 1
#endif
#if CAN_WRAP_ata_bmdma_error_handler
    WRAP_FOR_DETACH(ata_bmdma_error_handler)
#endif
#ifndef CAN_WRAP_generic_readlink
#   define CAN_WRAP_generic_readlink 1
#endif
#if CAN_WRAP_generic_readlink
    WRAP_FOR_DETACH(generic_readlink)
#endif
#ifndef CAN_WRAP_prune_icache_sb
#   define CAN_WRAP_prune_icache_sb 1
#endif
#if CAN_WRAP_prune_icache_sb
    WRAP_FOR_DETACH(prune_icache_sb)
#endif
#ifndef CAN_WRAP___send_remote_softirq
#   define CAN_WRAP___send_remote_softirq 1
#endif
#if CAN_WRAP___send_remote_softirq
#   ifdef DETACH_ADDR___send_remote_softirq
        WRAP_FOR_DETACH(__send_remote_softirq)
#   else
        TYPED_DETACH(__send_remote_softirq)
#   endif
#endif
#ifndef CAN_WRAP_vmalloc_node
#   define CAN_WRAP_vmalloc_node 0
#endif
DETACH(vmalloc_node)
#ifndef CAN_WRAP_invalidate_inode_pages2
#   define CAN_WRAP_invalidate_inode_pages2 1
#endif
#if CAN_WRAP_invalidate_inode_pages2
    WRAP_FOR_DETACH(invalidate_inode_pages2)
#endif
#ifndef CAN_WRAP_setup_irq
#   define CAN_WRAP_setup_irq 1
#endif
#if CAN_WRAP_setup_irq
    WRAP_FOR_DETACH(setup_irq)
#endif
#ifndef CAN_WRAP_e820_mark_nosave_regions
#   define CAN_WRAP_e820_mark_nosave_regions 0
#endif
DETACH(e820_mark_nosave_regions)
#ifndef CAN_WRAP_parse_e820_ext
#   define CAN_WRAP_parse_e820_ext 1
#endif
#if CAN_WRAP_parse_e820_ext
    WRAP_FOR_DETACH(parse_e820_ext)
#endif
#ifndef CAN_WRAP_memory_failure_queue
#   define CAN_WRAP_memory_failure_queue 0
#endif
DETACH(memory_failure_queue)
#ifndef CAN_WRAP_pci_msi_shutdown
#   define CAN_WRAP_pci_msi_shutdown 1
#endif
#if CAN_WRAP_pci_msi_shutdown
    WRAP_FOR_DETACH(pci_msi_shutdown)
#endif
#ifndef CAN_WRAP_security_sem_semctl
#   define CAN_WRAP_security_sem_semctl 1
#endif
#if CAN_WRAP_security_sem_semctl
    WRAP_FOR_DETACH(security_sem_semctl)
#endif
#ifndef CAN_WRAP_rtnl_put_cacheinfo
#   define CAN_WRAP_rtnl_put_cacheinfo 1
#endif
#if CAN_WRAP_rtnl_put_cacheinfo
    WRAP_FOR_DETACH(rtnl_put_cacheinfo)
#endif
#ifndef CAN_WRAP_default_machine_specific_memory_setup
#   define CAN_WRAP_default_machine_specific_memory_setup 0
#endif
DETACH(default_machine_specific_memory_setup)
#ifndef CAN_WRAP_blk_queue_physical_block_size
#   define CAN_WRAP_blk_queue_physical_block_size 1
#endif
#if CAN_WRAP_blk_queue_physical_block_size
    WRAP_FOR_DETACH(blk_queue_physical_block_size)
#endif
#ifndef CAN_WRAP_simple_transaction_release
#   define CAN_WRAP_simple_transaction_release 1
#endif
#if CAN_WRAP_simple_transaction_release
    WRAP_FOR_DETACH(simple_transaction_release)
#endif
#ifndef CAN_WRAP_____ilog2_NaN
#   define CAN_WRAP_____ilog2_NaN 0
#endif
DETACH(____ilog2_NaN)
#ifndef CAN_WRAP_ata_host_resume
#   define CAN_WRAP_ata_host_resume 1
#endif
#if CAN_WRAP_ata_host_resume
    WRAP_FOR_DETACH(ata_host_resume)
#endif
#ifndef CAN_WRAP___mark_inode_dirty
#   define CAN_WRAP___mark_inode_dirty 1
#endif
#if CAN_WRAP___mark_inode_dirty
#   ifdef DETACH_ADDR___mark_inode_dirty
        WRAP_FOR_DETACH(__mark_inode_dirty)
#   else
        TYPED_DETACH(__mark_inode_dirty)
#   endif
#endif
#ifndef CAN_WRAP_compat_sys_kexec_load
#   define CAN_WRAP_compat_sys_kexec_load 1
#endif
#if CAN_WRAP_compat_sys_kexec_load
    WRAP_FOR_DETACH(compat_sys_kexec_load)
#endif
#ifndef CAN_WRAP_cap_mmap_addr
#   define CAN_WRAP_cap_mmap_addr 0
#endif
DETACH(cap_mmap_addr)
#ifndef CAN_WRAP_blk_queue_segment_boundary
#   define CAN_WRAP_blk_queue_segment_boundary 1
#endif
#if CAN_WRAP_blk_queue_segment_boundary
    WRAP_FOR_DETACH(blk_queue_segment_boundary)
#endif
#ifndef CAN_WRAP_d_alloc_name
#   define CAN_WRAP_d_alloc_name 1
#endif
#if CAN_WRAP_d_alloc_name
    WRAP_FOR_DETACH(d_alloc_name)
#endif
#ifndef CAN_WRAP_eth_header
#   define CAN_WRAP_eth_header 1
#endif
#if CAN_WRAP_eth_header
    WRAP_FOR_DETACH(eth_header)
#endif
#ifndef CAN_WRAP_ht_create_irq
#   define CAN_WRAP_ht_create_irq 1
#endif
#if CAN_WRAP_ht_create_irq
    WRAP_FOR_DETACH(ht_create_irq)
#endif
#ifndef CAN_WRAP_ata_pci_bmdma_init_one
#   define CAN_WRAP_ata_pci_bmdma_init_one 1
#endif
#if CAN_WRAP_ata_pci_bmdma_init_one
    WRAP_FOR_DETACH(ata_pci_bmdma_init_one)
#endif
#ifndef CAN_WRAP_print_tainted
#   define CAN_WRAP_print_tainted 0
#endif
DETACH(print_tainted)
#ifndef CAN_WRAP_acpi_get_sleep_type_data
#   define CAN_WRAP_acpi_get_sleep_type_data 0
#endif
DETACH(acpi_get_sleep_type_data)
#ifndef CAN_WRAP_put_pages_list
#   define CAN_WRAP_put_pages_list 1
#endif
#if CAN_WRAP_put_pages_list
    WRAP_FOR_DETACH(put_pages_list)
#endif
#ifndef CAN_WRAP_paging_init
#   define CAN_WRAP_paging_init 0
#endif
DETACH(paging_init)
#ifndef CAN_WRAP_vm_stat_account
#   define CAN_WRAP_vm_stat_account 1
#endif
#if CAN_WRAP_vm_stat_account
    WRAP_FOR_DETACH(vm_stat_account)
#endif
#ifndef CAN_WRAP_wake_up_bit
#   define CAN_WRAP_wake_up_bit 0
#endif
DETACH(wake_up_bit)
#ifndef CAN_WRAP_make_pages_present
#   define CAN_WRAP_make_pages_present 0
#endif
DETACH(make_pages_present)
#ifndef CAN_WRAP_rtnl_unlock
#   define CAN_WRAP_rtnl_unlock 0
#endif
DETACH(rtnl_unlock)
#ifndef CAN_WRAP_smp_init
#   define CAN_WRAP_smp_init 0
#endif
DETACH(smp_init)
#ifndef CAN_WRAP_acpi_enter_sleep_state
#   define CAN_WRAP_acpi_enter_sleep_state 0
#endif
DETACH(acpi_enter_sleep_state)
#ifndef CAN_WRAP_emergency_thaw_all
#   define CAN_WRAP_emergency_thaw_all 0
#endif
DETACH(emergency_thaw_all)
#ifndef CAN_WRAP_page_check_address_pmd
#   define CAN_WRAP_page_check_address_pmd 1
#endif
#if CAN_WRAP_page_check_address_pmd
    WRAP_FOR_DETACH(page_check_address_pmd)
#endif
#ifndef CAN_WRAP_user_statfs
#   define CAN_WRAP_user_statfs 1
#endif
#if CAN_WRAP_user_statfs
    WRAP_FOR_DETACH(user_statfs)
#endif
#ifndef CAN_WRAP_proc_dointvec_ms_jiffies
#   define CAN_WRAP_proc_dointvec_ms_jiffies 1
#endif
#if CAN_WRAP_proc_dointvec_ms_jiffies
    WRAP_FOR_DETACH(proc_dointvec_ms_jiffies)
#endif
#ifndef CAN_WRAP_ata_bmdma_start
#   define CAN_WRAP_ata_bmdma_start 1
#endif
#if CAN_WRAP_ata_bmdma_start
    WRAP_FOR_DETACH(ata_bmdma_start)
#endif
#ifndef CAN_WRAP_compat_put_timeval
#   define CAN_WRAP_compat_put_timeval 1
#endif
#if CAN_WRAP_compat_put_timeval
    WRAP_FOR_DETACH(compat_put_timeval)
#endif
#ifndef CAN_WRAP_alternative_instructions
#   define CAN_WRAP_alternative_instructions 0
#endif
DETACH(alternative_instructions)
#ifndef CAN_WRAP_touch_atime
#   define CAN_WRAP_touch_atime 1
#endif
#if CAN_WRAP_touch_atime
    WRAP_FOR_DETACH(touch_atime)
#endif
#ifndef CAN_WRAP_register_netdevice
#   define CAN_WRAP_register_netdevice 1
#endif
#if CAN_WRAP_register_netdevice
    WRAP_FOR_DETACH(register_netdevice)
#endif
#ifndef CAN_WRAP_set_task_cpu
#   define CAN_WRAP_set_task_cpu 1
#endif
#if CAN_WRAP_set_task_cpu
    WRAP_FOR_DETACH(set_task_cpu)
#endif
#ifndef CAN_WRAP_skb_timestamping_init
#   define CAN_WRAP_skb_timestamping_init 0
#endif
DETACH(skb_timestamping_init)
#ifndef CAN_WRAP_strlen_user
#   define CAN_WRAP_strlen_user 0
#endif
DETACH(strlen_user)
#ifndef CAN_WRAP_free_memcg_kmem_pages
#   define CAN_WRAP_free_memcg_kmem_pages 0
#endif
DETACH(free_memcg_kmem_pages)
#ifndef CAN_WRAP_node_map_pfn_alignment
#   define CAN_WRAP_node_map_pfn_alignment 0
#endif
DETACH(node_map_pfn_alignment)
#ifndef CAN_WRAP_pci_find_ht_capability
#   define CAN_WRAP_pci_find_ht_capability 1
#endif
#if CAN_WRAP_pci_find_ht_capability
    WRAP_FOR_DETACH(pci_find_ht_capability)
#endif
#ifndef CAN_WRAP_work_cpu
#   define CAN_WRAP_work_cpu 1
#endif
#if CAN_WRAP_work_cpu
    WRAP_FOR_DETACH(work_cpu)
#endif
#ifndef CAN_WRAP_pci_reset_function
#   define CAN_WRAP_pci_reset_function 1
#endif
#if CAN_WRAP_pci_reset_function
    WRAP_FOR_DETACH(pci_reset_function)
#endif
#ifndef CAN_WRAP_prune_dcache_sb
#   define CAN_WRAP_prune_dcache_sb 1
#endif
#if CAN_WRAP_prune_dcache_sb
    WRAP_FOR_DETACH(prune_dcache_sb)
#endif
#ifndef CAN_WRAP_pci_fixup_device
#   define CAN_WRAP_pci_fixup_device 1
#endif
#if CAN_WRAP_pci_fixup_device
    WRAP_FOR_DETACH(pci_fixup_device)
#endif
#ifndef CAN_WRAP_security_file_alloc
#   define CAN_WRAP_security_file_alloc 1
#endif
#if CAN_WRAP_security_file_alloc
    WRAP_FOR_DETACH(security_file_alloc)
#endif
#ifndef CAN_WRAP_dmam_alloc_noncoherent
#   define CAN_WRAP_dmam_alloc_noncoherent 1
#endif
#if CAN_WRAP_dmam_alloc_noncoherent
    WRAP_FOR_DETACH(dmam_alloc_noncoherent)
#endif
#ifndef CAN_WRAP_free_page_and_swap_cache
#   define CAN_WRAP_free_page_and_swap_cache 1
#endif
#if CAN_WRAP_free_page_and_swap_cache
    WRAP_FOR_DETACH(free_page_and_swap_cache)
#endif
#ifndef CAN_WRAP_alloc_pci_dev
#   define CAN_WRAP_alloc_pci_dev 1
#endif
#if CAN_WRAP_alloc_pci_dev
    WRAP_FOR_DETACH(alloc_pci_dev)
#endif
#ifndef CAN_WRAP_setup_per_cpu_areas
#   define CAN_WRAP_setup_per_cpu_areas 0
#endif
DETACH(setup_per_cpu_areas)
#ifndef CAN_WRAP___percpu_counter_init
#   define CAN_WRAP___percpu_counter_init 1
#endif
#if CAN_WRAP___percpu_counter_init
#   ifdef DETACH_ADDR___percpu_counter_init
        WRAP_FOR_DETACH(__percpu_counter_init)
#   else
        TYPED_DETACH(__percpu_counter_init)
#   endif
#endif
#ifndef CAN_WRAP_mmap_region
#   define CAN_WRAP_mmap_region 1
#endif
#if CAN_WRAP_mmap_region
    WRAP_FOR_DETACH(mmap_region)
#endif
#ifndef CAN_WRAP_verify_mem_not_deleted
#   define CAN_WRAP_verify_mem_not_deleted 0
#endif
DETACH(verify_mem_not_deleted)
#ifndef CAN_WRAP_ata_sff_irq_clear
#   define CAN_WRAP_ata_sff_irq_clear 1
#endif
#if CAN_WRAP_ata_sff_irq_clear
    WRAP_FOR_DETACH(ata_sff_irq_clear)
#endif
#ifndef CAN_WRAP_scm_detach_fds_compat
#   define CAN_WRAP_scm_detach_fds_compat 1
#endif
#if CAN_WRAP_scm_detach_fds_compat
    WRAP_FOR_DETACH(scm_detach_fds_compat)
#endif
#ifndef CAN_WRAP_scsi_host_state_name
#   define CAN_WRAP_scsi_host_state_name 0
#endif
DETACH(scsi_host_state_name)
#ifndef CAN_WRAP_acpi_get_pxm
#   define CAN_WRAP_acpi_get_pxm 0
#endif
DETACH(acpi_get_pxm)
#ifndef CAN_WRAP_write_cache_pages
#   define CAN_WRAP_write_cache_pages 1
#endif
#if CAN_WRAP_write_cache_pages
    WRAP_FOR_DETACH(write_cache_pages)
#endif
#ifndef CAN_WRAP_sk_dst_check
#   define CAN_WRAP_sk_dst_check 1
#endif
#if CAN_WRAP_sk_dst_check
    WRAP_FOR_DETACH(sk_dst_check)
#endif
#ifndef CAN_WRAP_mdio_bus_init
#   define CAN_WRAP_mdio_bus_init 0
#endif
DETACH(mdio_bus_init)
#ifndef CAN_WRAP_dpm_complete
#   define CAN_WRAP_dpm_complete 1
#endif
#if CAN_WRAP_dpm_complete
    WRAP_FOR_DETACH(dpm_complete)
#endif
#ifndef CAN_WRAP_acpi_os_write_port
#   define CAN_WRAP_acpi_os_write_port 0
#endif
DETACH(acpi_os_write_port)
#ifndef CAN_WRAP_ata_timing_find_mode
#   define CAN_WRAP_ata_timing_find_mode 1
#endif
#if CAN_WRAP_ata_timing_find_mode
    WRAP_FOR_DETACH(ata_timing_find_mode)
#endif
#ifndef CAN_WRAP_sg_alloc_table_from_pages
#   define CAN_WRAP_sg_alloc_table_from_pages 1
#endif
#if CAN_WRAP_sg_alloc_table_from_pages
    WRAP_FOR_DETACH(sg_alloc_table_from_pages)
#endif
#ifndef CAN_WRAP_copy_namespaces
#   define CAN_WRAP_copy_namespaces 1
#endif
#if CAN_WRAP_copy_namespaces
    WRAP_FOR_DETACH(copy_namespaces)
#endif
#ifndef CAN_WRAP_gnet_stats_copy_app
#   define CAN_WRAP_gnet_stats_copy_app 1
#endif
#if CAN_WRAP_gnet_stats_copy_app
    WRAP_FOR_DETACH(gnet_stats_copy_app)
#endif
#ifndef CAN_WRAP_wait_for_completion_interruptible
#   define CAN_WRAP_wait_for_completion_interruptible 1
#endif
#if CAN_WRAP_wait_for_completion_interruptible
    WRAP_FOR_DETACH(wait_for_completion_interruptible)
#endif
#ifndef CAN_WRAP_delayed_work_timer_fn
#   define CAN_WRAP_delayed_work_timer_fn 0
#endif
DETACH(delayed_work_timer_fn)
#ifndef CAN_WRAP_smp_invalidate_interrupt
#   define CAN_WRAP_smp_invalidate_interrupt 1
#endif
#if CAN_WRAP_smp_invalidate_interrupt
    WRAP_FOR_DETACH(smp_invalidate_interrupt)
#endif
#ifndef CAN_WRAP___section_nr
#   define CAN_WRAP___section_nr 1
#endif
#if CAN_WRAP___section_nr
#   ifdef DETACH_ADDR___section_nr
        WRAP_FOR_DETACH(__section_nr)
#   else
        TYPED_DETACH(__section_nr)
#   endif
#endif
#ifndef CAN_WRAP_file_open_name
#   define CAN_WRAP_file_open_name 1
#endif
#if CAN_WRAP_file_open_name
    WRAP_FOR_DETACH(file_open_name)
#endif
#ifndef CAN_WRAP_vmalloc_user
#   define CAN_WRAP_vmalloc_user 0
#endif
DETACH(vmalloc_user)
#ifndef CAN_WRAP___vfs_setxattr_noperm
#   define CAN_WRAP___vfs_setxattr_noperm 1
#endif
#if CAN_WRAP___vfs_setxattr_noperm
#   ifdef DETACH_ADDR___vfs_setxattr_noperm
        WRAP_FOR_DETACH(__vfs_setxattr_noperm)
#   else
        TYPED_DETACH(__vfs_setxattr_noperm)
#   endif
#endif
#ifndef CAN_WRAP_add_memory
#   define CAN_WRAP_add_memory 0
#endif
DETACH(add_memory)
#ifndef CAN_WRAP_rtnl_create_link
#   define CAN_WRAP_rtnl_create_link 1
#endif
#if CAN_WRAP_rtnl_create_link
    WRAP_FOR_DETACH(rtnl_create_link)
#endif
#ifndef CAN_WRAP_register_acpi_bus_notifier
#   define CAN_WRAP_register_acpi_bus_notifier 1
#endif
#if CAN_WRAP_register_acpi_bus_notifier
    WRAP_FOR_DETACH(register_acpi_bus_notifier)
#endif
#ifndef CAN_WRAP_bdget
#   define CAN_WRAP_bdget 1
#endif
#if CAN_WRAP_bdget
    WRAP_FOR_DETACH(bdget)
#endif
#ifndef CAN_WRAP_early_pfn_to_nid
#   define CAN_WRAP_early_pfn_to_nid 0
#endif
DETACH(early_pfn_to_nid)
#ifndef CAN_WRAP_cpu_clock
#   define CAN_WRAP_cpu_clock 0
#endif
DETACH(cpu_clock)
#ifndef CAN_WRAP_getboottime
#   define CAN_WRAP_getboottime 1
#endif
#if CAN_WRAP_getboottime
    WRAP_FOR_DETACH(getboottime)
#endif
#ifndef CAN_WRAP_blkdev_aio_write
#   define CAN_WRAP_blkdev_aio_write 1
#endif
#if CAN_WRAP_blkdev_aio_write
    WRAP_FOR_DETACH(blkdev_aio_write)
#endif
#ifndef CAN_WRAP_ata_pci_remove_one
#   define CAN_WRAP_ata_pci_remove_one 1
#endif
#if CAN_WRAP_ata_pci_remove_one
    WRAP_FOR_DETACH(ata_pci_remove_one)
#endif
#ifndef CAN_WRAP_x86_acpi_numa_init
#   define CAN_WRAP_x86_acpi_numa_init 0
#endif
DETACH(x86_acpi_numa_init)
#ifndef CAN_WRAP_irq_set_chip_data
#   define CAN_WRAP_irq_set_chip_data 0
#endif
DETACH(irq_set_chip_data)
#ifndef CAN_WRAP_kthread_data
#   define CAN_WRAP_kthread_data 1
#endif
#if CAN_WRAP_kthread_data
    WRAP_FOR_DETACH(kthread_data)
#endif
#ifndef CAN_WRAP_skb_dequeue
#   define CAN_WRAP_skb_dequeue 1
#endif
#if CAN_WRAP_skb_dequeue
    WRAP_FOR_DETACH(skb_dequeue)
#endif
#ifndef CAN_WRAP_dpm_for_each_dev
#   define CAN_WRAP_dpm_for_each_dev 1
#endif
#if CAN_WRAP_dpm_for_each_dev
    WRAP_FOR_DETACH(dpm_for_each_dev)
#endif
#ifndef CAN_WRAP_pm_qos_remove_request
#   define CAN_WRAP_pm_qos_remove_request 1
#endif
#if CAN_WRAP_pm_qos_remove_request
    WRAP_FOR_DETACH(pm_qos_remove_request)
#endif
#ifndef CAN_WRAP_acpi_clear_event
#   define CAN_WRAP_acpi_clear_event 0
#endif
DETACH(acpi_clear_event)
#ifndef CAN_WRAP_get_cpu_iowait_time_us
#   define CAN_WRAP_get_cpu_iowait_time_us 0
#endif
DETACH(get_cpu_iowait_time_us)
#ifndef CAN_WRAP_kfree_skb
#   define CAN_WRAP_kfree_skb 1
#endif
#if CAN_WRAP_kfree_skb
    WRAP_FOR_DETACH(kfree_skb)
#endif
#ifndef CAN_WRAP_qtree_write_dquot
#   define CAN_WRAP_qtree_write_dquot 1
#endif
#if CAN_WRAP_qtree_write_dquot
    WRAP_FOR_DETACH(qtree_write_dquot)
#endif
#ifndef CAN_WRAP_kernel_sock_shutdown
#   define CAN_WRAP_kernel_sock_shutdown 1
#endif
#if CAN_WRAP_kernel_sock_shutdown
    WRAP_FOR_DETACH(kernel_sock_shutdown)
#endif
#ifndef CAN_WRAP_tick_check_oneshot_change
#   define CAN_WRAP_tick_check_oneshot_change 0
#endif
DETACH(tick_check_oneshot_change)
#ifndef CAN_WRAP_blk_execute_rq_nowait
#   define CAN_WRAP_blk_execute_rq_nowait 1
#endif
#if CAN_WRAP_blk_execute_rq_nowait
    WRAP_FOR_DETACH(blk_execute_rq_nowait)
#endif
#ifndef CAN_WRAP_hrtimers_resume
#   define CAN_WRAP_hrtimers_resume 0
#endif
DETACH(hrtimers_resume)
#ifndef CAN_WRAP_dm_copy_name_and_uuid
#   define CAN_WRAP_dm_copy_name_and_uuid 1
#endif
#if CAN_WRAP_dm_copy_name_and_uuid
    WRAP_FOR_DETACH(dm_copy_name_and_uuid)
#endif
#ifndef CAN_WRAP_pm_qos_update_target
#   define CAN_WRAP_pm_qos_update_target 1
#endif
#if CAN_WRAP_pm_qos_update_target
    WRAP_FOR_DETACH(pm_qos_update_target)
#endif
#ifndef CAN_WRAP_atomic_notifier_chain_unregister
#   define CAN_WRAP_atomic_notifier_chain_unregister 1
#endif
#if CAN_WRAP_atomic_notifier_chain_unregister
    WRAP_FOR_DETACH(atomic_notifier_chain_unregister)
#endif
#ifndef CAN_WRAP_setup_percpu_irq
#   define CAN_WRAP_setup_percpu_irq 1
#endif
#if CAN_WRAP_setup_percpu_irq
    WRAP_FOR_DETACH(setup_percpu_irq)
#endif
#ifndef CAN_WRAP_filemap_fdatawrite
#   define CAN_WRAP_filemap_fdatawrite 1
#endif
#if CAN_WRAP_filemap_fdatawrite
    WRAP_FOR_DETACH(filemap_fdatawrite)
#endif
#ifndef CAN_WRAP_pci_enable_resources
#   define CAN_WRAP_pci_enable_resources 1
#endif
#if CAN_WRAP_pci_enable_resources
    WRAP_FOR_DETACH(pci_enable_resources)
#endif
#ifndef CAN_WRAP_d_alloc_pseudo
#   define CAN_WRAP_d_alloc_pseudo 1
#endif
#if CAN_WRAP_d_alloc_pseudo
    WRAP_FOR_DETACH(d_alloc_pseudo)
#endif
#ifndef CAN_WRAP___blk_stop_queue
#   define CAN_WRAP___blk_stop_queue 1
#endif
#if CAN_WRAP___blk_stop_queue
#   ifdef DETACH_ADDR___blk_stop_queue
        WRAP_FOR_DETACH(__blk_stop_queue)
#   else
        TYPED_DETACH(__blk_stop_queue)
#   endif
#endif
#ifndef CAN_WRAP_ethtool_op_get_link
#   define CAN_WRAP_ethtool_op_get_link 1
#endif
#if CAN_WRAP_ethtool_op_get_link
    WRAP_FOR_DETACH(ethtool_op_get_link)
#endif
#ifndef CAN_WRAP_vfs_caches_init
#   define CAN_WRAP_vfs_caches_init 0
#endif
DETACH(vfs_caches_init)
#ifndef CAN_WRAP_pci_swiotlb_init
#   define CAN_WRAP_pci_swiotlb_init 0
#endif
DETACH(pci_swiotlb_init)
#ifndef CAN_WRAP_down_killable
#   define CAN_WRAP_down_killable 1
#endif
#if CAN_WRAP_down_killable
    WRAP_FOR_DETACH(down_killable)
#endif
#ifndef CAN_WRAP_restore_ioapic_entries
#   define CAN_WRAP_restore_ioapic_entries 0
#endif
DETACH(restore_ioapic_entries)
#ifndef CAN_WRAP_ata_eh_qc_retry
#   define CAN_WRAP_ata_eh_qc_retry 1
#endif
#if CAN_WRAP_ata_eh_qc_retry
    WRAP_FOR_DETACH(ata_eh_qc_retry)
#endif
#ifndef CAN_WRAP_dev_addr_del
#   define CAN_WRAP_dev_addr_del 1
#endif
#if CAN_WRAP_dev_addr_del
    WRAP_FOR_DETACH(dev_addr_del)
#endif
#ifndef CAN_WRAP_d_hash_and_lookup
#   define CAN_WRAP_d_hash_and_lookup 1
#endif
#if CAN_WRAP_d_hash_and_lookup
    WRAP_FOR_DETACH(d_hash_and_lookup)
#endif
#ifndef CAN_WRAP___nla_put_nohdr
#   define CAN_WRAP___nla_put_nohdr 1
#endif
#if CAN_WRAP___nla_put_nohdr
#   ifdef DETACH_ADDR___nla_put_nohdr
        WRAP_FOR_DETACH(__nla_put_nohdr)
#   else
        TYPED_DETACH(__nla_put_nohdr)
#   endif
#endif
#ifndef CAN_WRAP_compat_sys_setsockopt
#   define CAN_WRAP_compat_sys_setsockopt 0
#endif
DETACH(compat_sys_setsockopt)
#ifndef CAN_WRAP_clockevents_config
#   define CAN_WRAP_clockevents_config 1
#endif
#if CAN_WRAP_clockevents_config
    WRAP_FOR_DETACH(clockevents_config)
#endif
#ifndef CAN_WRAP_wake_up_klogd
#   define CAN_WRAP_wake_up_klogd 0
#endif
DETACH(wake_up_klogd)
#ifndef CAN_WRAP_tracepoint_iter_stop
#   define CAN_WRAP_tracepoint_iter_stop 1
#endif
#if CAN_WRAP_tracepoint_iter_stop
    WRAP_FOR_DETACH(tracepoint_iter_stop)
#endif
#ifndef CAN_WRAP_del_timer
#   define CAN_WRAP_del_timer 1
#endif
#if CAN_WRAP_del_timer
    WRAP_FOR_DETACH(del_timer)
#endif
#ifndef CAN_WRAP_inode_init_early
#   define CAN_WRAP_inode_init_early 0
#endif
DETACH(inode_init_early)
#ifndef CAN_WRAP___check_region
#   define CAN_WRAP___check_region 1
#endif
#if CAN_WRAP___check_region
#   ifdef DETACH_ADDR___check_region
        WRAP_FOR_DETACH(__check_region)
#   else
        TYPED_DETACH(__check_region)
#   endif
#endif
#ifndef CAN_WRAP_sparse_decode_mem_map
#   define CAN_WRAP_sparse_decode_mem_map 1
#endif
#if CAN_WRAP_sparse_decode_mem_map
    WRAP_FOR_DETACH(sparse_decode_mem_map)
#endif
#ifndef CAN_WRAP_bus_find_device
#   define CAN_WRAP_bus_find_device 1
#endif
#if CAN_WRAP_bus_find_device
    WRAP_FOR_DETACH(bus_find_device)
#endif
#ifndef CAN_WRAP_ata_bmdma_port_start32
#   define CAN_WRAP_ata_bmdma_port_start32 1
#endif
#if CAN_WRAP_ata_bmdma_port_start32
    WRAP_FOR_DETACH(ata_bmdma_port_start32)
#endif
#ifndef CAN_WRAP_compat_sys_ioctl
#   define CAN_WRAP_compat_sys_ioctl 0
#endif
DETACH(compat_sys_ioctl)
#ifndef CAN_WRAP_security_bprm_secureexec
#   define CAN_WRAP_security_bprm_secureexec 1
#endif
#if CAN_WRAP_security_bprm_secureexec
    WRAP_FOR_DETACH(security_bprm_secureexec)
#endif
#ifndef CAN_WRAP_security_task_movememory
#   define CAN_WRAP_security_task_movememory 1
#endif
#if CAN_WRAP_security_task_movememory
    WRAP_FOR_DETACH(security_task_movememory)
#endif
#ifndef CAN_WRAP_security_msg_queue_associate
#   define CAN_WRAP_security_msg_queue_associate 1
#endif
#if CAN_WRAP_security_msg_queue_associate
    WRAP_FOR_DETACH(security_msg_queue_associate)
#endif
#ifndef CAN_WRAP_compat_sys_times
#   define CAN_WRAP_compat_sys_times 1
#endif
#if CAN_WRAP_compat_sys_times
    WRAP_FOR_DETACH(compat_sys_times)
#endif
#ifndef CAN_WRAP_swiotlb_sync_single_for_cpu
#   define CAN_WRAP_swiotlb_sync_single_for_cpu 1
#endif
#if CAN_WRAP_swiotlb_sync_single_for_cpu
    WRAP_FOR_DETACH(swiotlb_sync_single_for_cpu)
#endif
#ifndef CAN_WRAP___wake_up_locked
#   define CAN_WRAP___wake_up_locked 1
#endif
#if CAN_WRAP___wake_up_locked
#   ifdef DETACH_ADDR___wake_up_locked
        WRAP_FOR_DETACH(__wake_up_locked)
#   else
        TYPED_DETACH(__wake_up_locked)
#   endif
#endif
#ifndef CAN_WRAP_vlan_do_receive
#   define CAN_WRAP_vlan_do_receive 0
#endif
DETACH(vlan_do_receive)
#ifndef CAN_WRAP_posix_acl_chmod
#   define CAN_WRAP_posix_acl_chmod 0
#endif
DETACH(posix_acl_chmod)
#ifndef CAN_WRAP_module_address_lookup
#   define CAN_WRAP_module_address_lookup 0
#endif
DETACH(module_address_lookup)
#ifndef CAN_WRAP_ata_eh_qc_complete
#   define CAN_WRAP_ata_eh_qc_complete 1
#endif
#if CAN_WRAP_ata_eh_qc_complete
    WRAP_FOR_DETACH(ata_eh_qc_complete)
#endif
#ifndef CAN_WRAP_pci_claim_resource
#   define CAN_WRAP_pci_claim_resource 1
#endif
#if CAN_WRAP_pci_claim_resource
    WRAP_FOR_DETACH(pci_claim_resource)
#endif
#ifndef CAN_WRAP_compat_get_bitmap
#   define CAN_WRAP_compat_get_bitmap 0
#endif
DETACH(compat_get_bitmap)
#ifndef CAN_WRAP_skb_try_coalesce
#   define CAN_WRAP_skb_try_coalesce 1
#endif
#if CAN_WRAP_skb_try_coalesce
    WRAP_FOR_DETACH(skb_try_coalesce)
#endif
#ifndef CAN_WRAP_scsi_verify_blk_ioctl
#   define CAN_WRAP_scsi_verify_blk_ioctl 1
#endif
#if CAN_WRAP_scsi_verify_blk_ioctl
    WRAP_FOR_DETACH(scsi_verify_blk_ioctl)
#endif
#ifndef CAN_WRAP_security_tun_dev_attach_queue
#   define CAN_WRAP_security_tun_dev_attach_queue 0
#endif
DETACH(security_tun_dev_attach_queue)
#ifndef CAN_WRAP_acpi_video_dmi_demote_vendor
#   define CAN_WRAP_acpi_video_dmi_demote_vendor 0
#endif
DETACH(acpi_video_dmi_demote_vendor)
#ifndef CAN_WRAP_pcim_pin_device
#   define CAN_WRAP_pcim_pin_device 1
#endif
#if CAN_WRAP_pcim_pin_device
    WRAP_FOR_DETACH(pcim_pin_device)
#endif
#ifndef CAN_WRAP_handle_simple_irq
#   define CAN_WRAP_handle_simple_irq 1
#endif
#if CAN_WRAP_handle_simple_irq
    WRAP_FOR_DETACH(handle_simple_irq)
#endif
#ifndef CAN_WRAP_mod_zone_page_state
#   define CAN_WRAP_mod_zone_page_state 1
#endif
#if CAN_WRAP_mod_zone_page_state
    WRAP_FOR_DETACH(mod_zone_page_state)
#endif
#ifndef CAN_WRAP_wakeup_source_drop
#   define CAN_WRAP_wakeup_source_drop 1
#endif
#if CAN_WRAP_wakeup_source_drop
    WRAP_FOR_DETACH(wakeup_source_drop)
#endif
#ifndef CAN_WRAP_dquot_get_dqblk
#   define CAN_WRAP_dquot_get_dqblk 1
#endif
#if CAN_WRAP_dquot_get_dqblk
    WRAP_FOR_DETACH(dquot_get_dqblk)
#endif
#ifndef CAN_WRAP_wait_on_sync_kiocb
#   define CAN_WRAP_wait_on_sync_kiocb 1
#endif
#if CAN_WRAP_wait_on_sync_kiocb
    WRAP_FOR_DETACH(wait_on_sync_kiocb)
#endif
#ifndef CAN_WRAP_vfs_readv
#   define CAN_WRAP_vfs_readv 1
#endif
#if CAN_WRAP_vfs_readv
    WRAP_FOR_DETACH(vfs_readv)
#endif
#ifndef CAN_WRAP_ata_port_desc
#   define CAN_WRAP_ata_port_desc 1
#endif
#if CAN_WRAP_ata_port_desc
    WRAP_FOR_DETACH(ata_port_desc)
#endif
#ifndef CAN_WRAP_sysfs_create_link_nowarn
#   define CAN_WRAP_sysfs_create_link_nowarn 1
#endif
#if CAN_WRAP_sysfs_create_link_nowarn
    WRAP_FOR_DETACH(sysfs_create_link_nowarn)
#endif
#ifndef CAN_WRAP_argv_free
#   define CAN_WRAP_argv_free 0
#endif
DETACH(argv_free)
#ifndef CAN_WRAP_register_net_sysctl
#   define CAN_WRAP_register_net_sysctl 1
#endif
#if CAN_WRAP_register_net_sysctl
    WRAP_FOR_DETACH(register_net_sysctl)
#endif
#ifndef CAN_WRAP_kmem_cache_alloc_node
#   define CAN_WRAP_kmem_cache_alloc_node 1
#endif
#if CAN_WRAP_kmem_cache_alloc_node
    WRAP_FOR_DETACH(kmem_cache_alloc_node)
#endif
#ifndef CAN_WRAP_ata_timing_compute
#   define CAN_WRAP_ata_timing_compute 1
#endif
#if CAN_WRAP_ata_timing_compute
    WRAP_FOR_DETACH(ata_timing_compute)
#endif
#ifndef CAN_WRAP_poll_select_set_timeout
#   define CAN_WRAP_poll_select_set_timeout 1
#endif
#if CAN_WRAP_poll_select_set_timeout
    WRAP_FOR_DETACH(poll_select_set_timeout)
#endif
#ifndef CAN_WRAP_fprop_fraction_single
#   define CAN_WRAP_fprop_fraction_single 1
#endif
#if CAN_WRAP_fprop_fraction_single
    WRAP_FOR_DETACH(fprop_fraction_single)
#endif
#ifndef CAN_WRAP_dev_mc_add_excl
#   define CAN_WRAP_dev_mc_add_excl 1
#endif
#if CAN_WRAP_dev_mc_add_excl
    WRAP_FOR_DETACH(dev_mc_add_excl)
#endif
#ifndef CAN_WRAP_dm_disk
#   define CAN_WRAP_dm_disk 1
#endif
#if CAN_WRAP_dm_disk
    WRAP_FOR_DETACH(dm_disk)
#endif
#ifndef CAN_WRAP_skb_checksum
#   define CAN_WRAP_skb_checksum 1
#endif
#if CAN_WRAP_skb_checksum
    WRAP_FOR_DETACH(skb_checksum)
#endif
#ifndef CAN_WRAP_security_socket_post_create
#   define CAN_WRAP_security_socket_post_create 1
#endif
#if CAN_WRAP_security_socket_post_create
    WRAP_FOR_DETACH(security_socket_post_create)
#endif
#ifndef CAN_WRAP_generic_file_llseek
#   define CAN_WRAP_generic_file_llseek 1
#endif
#if CAN_WRAP_generic_file_llseek
    WRAP_FOR_DETACH(generic_file_llseek)
#endif
#ifndef CAN_WRAP_input_ff_event
#   define CAN_WRAP_input_ff_event 1
#endif
#if CAN_WRAP_input_ff_event
    WRAP_FOR_DETACH(input_ff_event)
#endif
#ifndef CAN_WRAP___jbd2_journal_refile_buffer
#   define CAN_WRAP___jbd2_journal_refile_buffer 1
#endif
#if CAN_WRAP___jbd2_journal_refile_buffer
#   ifdef DETACH_ADDR___jbd2_journal_refile_buffer
        WRAP_FOR_DETACH(__jbd2_journal_refile_buffer)
#   else
        TYPED_DETACH(__jbd2_journal_refile_buffer)
#   endif
#endif
#ifndef CAN_WRAP___page_cache_alloc
#   define CAN_WRAP___page_cache_alloc 1
#endif
#if CAN_WRAP___page_cache_alloc
#   ifdef DETACH_ADDR___page_cache_alloc
        WRAP_FOR_DETACH(__page_cache_alloc)
#   else
        TYPED_DETACH(__page_cache_alloc)
#   endif
#endif
#ifndef CAN_WRAP_lock_sock_nested
#   define CAN_WRAP_lock_sock_nested 1
#endif
#if CAN_WRAP_lock_sock_nested
    WRAP_FOR_DETACH(lock_sock_nested)
#endif
#ifndef CAN_WRAP_simple_release_fs
#   define CAN_WRAP_simple_release_fs 0
#endif
DETACH(simple_release_fs)
#ifndef CAN_WRAP_dma_async_device_register
#   define CAN_WRAP_dma_async_device_register 1
#endif
#if CAN_WRAP_dma_async_device_register
    WRAP_FOR_DETACH(dma_async_device_register)
#endif
#ifndef CAN_WRAP_skb_copy_datagram_const_iovec
#   define CAN_WRAP_skb_copy_datagram_const_iovec 1
#endif
#if CAN_WRAP_skb_copy_datagram_const_iovec
    WRAP_FOR_DETACH(skb_copy_datagram_const_iovec)
#endif
#ifndef CAN_WRAP_bio_phys_segments
#   define CAN_WRAP_bio_phys_segments 1
#endif
#if CAN_WRAP_bio_phys_segments
    WRAP_FOR_DETACH(bio_phys_segments)
#endif
#ifndef CAN_WRAP_blk_queue_max_segments
#   define CAN_WRAP_blk_queue_max_segments 1
#endif
#if CAN_WRAP_blk_queue_max_segments
    WRAP_FOR_DETACH(blk_queue_max_segments)
#endif
#ifndef CAN_WRAP_blk_free_devt
#   define CAN_WRAP_blk_free_devt 0
#endif
DETACH(blk_free_devt)
#ifndef CAN_WRAP_wakeup_source_add
#   define CAN_WRAP_wakeup_source_add 1
#endif
#if CAN_WRAP_wakeup_source_add
    WRAP_FOR_DETACH(wakeup_source_add)
#endif
#ifndef CAN_WRAP_param_set_long
#   define CAN_WRAP_param_set_long 1
#endif
#if CAN_WRAP_param_set_long
    WRAP_FOR_DETACH(param_set_long)
#endif
#ifndef CAN_WRAP_read_cache_page_async
#   define CAN_WRAP_read_cache_page_async 1
#endif
#if CAN_WRAP_read_cache_page_async
    WRAP_FOR_DETACH(read_cache_page_async)
#endif
#ifndef CAN_WRAP_final_putname
#   define CAN_WRAP_final_putname 1
#endif
#if CAN_WRAP_final_putname
    WRAP_FOR_DETACH(final_putname)
#endif
#ifndef CAN_WRAP_kernel_recvmsg
#   define CAN_WRAP_kernel_recvmsg 1
#endif
#if CAN_WRAP_kernel_recvmsg
    WRAP_FOR_DETACH(kernel_recvmsg)
#endif
#ifndef CAN_WRAP_pmdp_clear_flush
#   define CAN_WRAP_pmdp_clear_flush 1
#endif
#if CAN_WRAP_pmdp_clear_flush
    WRAP_FOR_DETACH(pmdp_clear_flush)
#endif
#ifndef CAN_WRAP_security_file_ioctl
#   define CAN_WRAP_security_file_ioctl 1
#endif
#if CAN_WRAP_security_file_ioctl
    WRAP_FOR_DETACH(security_file_ioctl)
#endif
#ifndef CAN_WRAP_native_io_delay
#   define CAN_WRAP_native_io_delay 0
#endif
DETACH(native_io_delay)
#ifndef CAN_WRAP_do_set_cpus_allowed
#   define CAN_WRAP_do_set_cpus_allowed 1
#endif
#if CAN_WRAP_do_set_cpus_allowed
    WRAP_FOR_DETACH(do_set_cpus_allowed)
#endif
#ifndef CAN_WRAP_schedule_timeout_killable
#   define CAN_WRAP_schedule_timeout_killable 0
#endif
DETACH(schedule_timeout_killable)
#ifndef CAN_WRAP_mempool_free_pages
#   define CAN_WRAP_mempool_free_pages 0
#endif
DETACH(mempool_free_pages)
#ifndef CAN_WRAP_default_find_smp_config
#   define CAN_WRAP_default_find_smp_config 0
#endif
DETACH(default_find_smp_config)
#ifndef CAN_WRAP_cgroup_path
#   define CAN_WRAP_cgroup_path 1
#endif
#if CAN_WRAP_cgroup_path
    WRAP_FOR_DETACH(cgroup_path)
#endif
#ifndef CAN_WRAP_touch_softlockup_watchdog_sync
#   define CAN_WRAP_touch_softlockup_watchdog_sync 0
#endif
DETACH(touch_softlockup_watchdog_sync)
#ifndef CAN_WRAP_yield_to
#   define CAN_WRAP_yield_to 1
#endif
#if CAN_WRAP_yield_to
    WRAP_FOR_DETACH(yield_to)
#endif
#ifndef CAN_WRAP___blockdev_direct_IO
#   define CAN_WRAP___blockdev_direct_IO 1
#endif
#if CAN_WRAP___blockdev_direct_IO
#   ifdef DETACH_ADDR___blockdev_direct_IO
        WRAP_FOR_DETACH(__blockdev_direct_IO)
#   else
        TYPED_DETACH(__blockdev_direct_IO)
#   endif
#endif
#ifndef CAN_WRAP_probe_kernel_read
#   define CAN_WRAP_probe_kernel_read 0
#endif
DETACH(probe_kernel_read)
#ifndef CAN_WRAP_jbd2_journal_add_journal_head
#   define CAN_WRAP_jbd2_journal_add_journal_head 1
#endif
#if CAN_WRAP_jbd2_journal_add_journal_head
    WRAP_FOR_DETACH(jbd2_journal_add_journal_head)
#endif
#ifndef CAN_WRAP_smp_send_reschedule
#   define CAN_WRAP_smp_send_reschedule 0
#endif
DETACH(smp_send_reschedule)
#ifndef CAN_WRAP_remove_percpu_irq
#   define CAN_WRAP_remove_percpu_irq 1
#endif
#if CAN_WRAP_remove_percpu_irq
    WRAP_FOR_DETACH(remove_percpu_irq)
#endif
#ifndef CAN_WRAP_security_inode_alloc
#   define CAN_WRAP_security_inode_alloc 1
#endif
#if CAN_WRAP_security_inode_alloc
    WRAP_FOR_DETACH(security_inode_alloc)
#endif
#ifndef CAN_WRAP_cap_mmap_file
#   define CAN_WRAP_cap_mmap_file 1
#endif
#if CAN_WRAP_cap_mmap_file
    WRAP_FOR_DETACH(cap_mmap_file)
#endif
#ifndef CAN_WRAP_bh_uptodate_or_lock
#   define CAN_WRAP_bh_uptodate_or_lock 1
#endif
#if CAN_WRAP_bh_uptodate_or_lock
    WRAP_FOR_DETACH(bh_uptodate_or_lock)
#endif
#ifndef CAN_WRAP_prop_local_init_percpu
#   define CAN_WRAP_prop_local_init_percpu 1
#endif
#if CAN_WRAP_prop_local_init_percpu
    WRAP_FOR_DETACH(prop_local_init_percpu)
#endif
#ifndef CAN_WRAP_alloc_pages_current
#   define CAN_WRAP_alloc_pages_current 1
#endif
#if CAN_WRAP_alloc_pages_current
    WRAP_FOR_DETACH(alloc_pages_current)
#endif
#ifndef CAN_WRAP_phy_register_fixup
#   define CAN_WRAP_phy_register_fixup 1
#endif
#if CAN_WRAP_phy_register_fixup
    WRAP_FOR_DETACH(phy_register_fixup)
#endif
#ifndef CAN_WRAP_vfs_test_lock
#   define CAN_WRAP_vfs_test_lock 1
#endif
#if CAN_WRAP_vfs_test_lock
    WRAP_FOR_DETACH(vfs_test_lock)
#endif
#ifndef CAN_WRAP_sk_stream_write_space
#   define CAN_WRAP_sk_stream_write_space 1
#endif
#if CAN_WRAP_sk_stream_write_space
    WRAP_FOR_DETACH(sk_stream_write_space)
#endif
#ifndef CAN_WRAP_flush_delayed_work
#   define CAN_WRAP_flush_delayed_work 1
#endif
#if CAN_WRAP_flush_delayed_work
    WRAP_FOR_DETACH(flush_delayed_work)
#endif
#ifndef CAN_WRAP_swiotlb_free
#   define CAN_WRAP_swiotlb_free 0
#endif
DETACH(swiotlb_free)
#ifndef CAN_WRAP_kthread_freezable_should_stop
#   define CAN_WRAP_kthread_freezable_should_stop 0
#endif
DETACH(kthread_freezable_should_stop)
#ifndef CAN_WRAP_drop_super
#   define CAN_WRAP_drop_super 1
#endif
#if CAN_WRAP_drop_super
    WRAP_FOR_DETACH(drop_super)
#endif
#ifndef CAN_WRAP_dm_read_arg_group
#   define CAN_WRAP_dm_read_arg_group 1
#endif
#if CAN_WRAP_dm_read_arg_group
    WRAP_FOR_DETACH(dm_read_arg_group)
#endif
#ifndef CAN_WRAP_wake_up_process
#   define CAN_WRAP_wake_up_process 1
#endif
#if CAN_WRAP_wake_up_process
    WRAP_FOR_DETACH(wake_up_process)
#endif
#ifndef CAN_WRAP___pskb_pull_tail
#   define CAN_WRAP___pskb_pull_tail 1
#endif
#if CAN_WRAP___pskb_pull_tail
#   ifdef DETACH_ADDR___pskb_pull_tail
        WRAP_FOR_DETACH(__pskb_pull_tail)
#   else
        TYPED_DETACH(__pskb_pull_tail)
#   endif
#endif
#ifndef CAN_WRAP_irq_to_desc
#   define CAN_WRAP_irq_to_desc 1
#endif
#if CAN_WRAP_irq_to_desc
    WRAP_FOR_DETACH(irq_to_desc)
#endif
#ifndef CAN_WRAP_arch_uprobe_exception_notify
#   define CAN_WRAP_arch_uprobe_exception_notify 1
#endif
#if CAN_WRAP_arch_uprobe_exception_notify
    WRAP_FOR_DETACH(arch_uprobe_exception_notify)
#endif
#ifndef CAN_WRAP_pci_unmap_rom
#   define CAN_WRAP_pci_unmap_rom 1
#endif
#if CAN_WRAP_pci_unmap_rom
    WRAP_FOR_DETACH(pci_unmap_rom)
#endif
#ifndef CAN_WRAP_pcibios_set_master
#   define CAN_WRAP_pcibios_set_master 1
#endif
#if CAN_WRAP_pcibios_set_master
    WRAP_FOR_DETACH(pcibios_set_master)
#endif
#ifndef CAN_WRAP_ioport_unmap
#   define CAN_WRAP_ioport_unmap 0
#endif
DETACH(ioport_unmap)
#ifndef CAN_WRAP_gfp_pfmemalloc_allowed
#   define CAN_WRAP_gfp_pfmemalloc_allowed 0
#endif
DETACH(gfp_pfmemalloc_allowed)
#ifndef CAN_WRAP_signals_init
#   define CAN_WRAP_signals_init 0
#endif
DETACH(signals_init)
#ifndef CAN_WRAP_acpi_no_s4_hw_signature
#   define CAN_WRAP_acpi_no_s4_hw_signature 0
#endif
DETACH(acpi_no_s4_hw_signature)
#ifndef CAN_WRAP_skb_kill_datagram
#   define CAN_WRAP_skb_kill_datagram 1
#endif
#if CAN_WRAP_skb_kill_datagram
    WRAP_FOR_DETACH(skb_kill_datagram)
#endif
#ifndef CAN_WRAP_identify_boot_cpu
#   define CAN_WRAP_identify_boot_cpu 0
#endif
DETACH(identify_boot_cpu)
#ifndef CAN_WRAP_xapic_wait_icr_idle
#   define CAN_WRAP_xapic_wait_icr_idle 0
#endif
DETACH(xapic_wait_icr_idle)
#ifndef CAN_WRAP_pci_add_dynid
#   define CAN_WRAP_pci_add_dynid 1
#endif
#if CAN_WRAP_pci_add_dynid
    WRAP_FOR_DETACH(pci_add_dynid)
#endif
#ifndef CAN_WRAP_has_capability_noaudit
#   define CAN_WRAP_has_capability_noaudit 1
#endif
#if CAN_WRAP_has_capability_noaudit
    WRAP_FOR_DETACH(has_capability_noaudit)
#endif
#ifndef CAN_WRAP_rw_copy_check_uvector
#   define CAN_WRAP_rw_copy_check_uvector 1
#endif
#if CAN_WRAP_rw_copy_check_uvector
    WRAP_FOR_DETACH(rw_copy_check_uvector)
#endif
#ifndef CAN_WRAP___cleancache_init_fs
#   define CAN_WRAP___cleancache_init_fs 1
#endif
#if CAN_WRAP___cleancache_init_fs
#   ifdef DETACH_ADDR___cleancache_init_fs
        WRAP_FOR_DETACH(__cleancache_init_fs)
#   else
        TYPED_DETACH(__cleancache_init_fs)
#   endif
#endif
#ifndef CAN_WRAP_crypto_shash_finup
#   define CAN_WRAP_crypto_shash_finup 1
#endif
#if CAN_WRAP_crypto_shash_finup
    WRAP_FOR_DETACH(crypto_shash_finup)
#endif
#ifndef CAN_WRAP_x86_init_uint_noop
#   define CAN_WRAP_x86_init_uint_noop 0
#endif
DETACH(x86_init_uint_noop)
#ifndef CAN_WRAP_try_wait_for_completion
#   define CAN_WRAP_try_wait_for_completion 1
#endif
#if CAN_WRAP_try_wait_for_completion
    WRAP_FOR_DETACH(try_wait_for_completion)
#endif
#ifndef CAN_WRAP_thread_group_cputimer
#   define CAN_WRAP_thread_group_cputimer 1
#endif
#if CAN_WRAP_thread_group_cputimer
    WRAP_FOR_DETACH(thread_group_cputimer)
#endif
#ifndef CAN_WRAP_find_get_page
#   define CAN_WRAP_find_get_page 1
#endif
#if CAN_WRAP_find_get_page
    WRAP_FOR_DETACH(find_get_page)
#endif
#ifndef CAN_WRAP_iterate_mounts
#   define CAN_WRAP_iterate_mounts 1
#endif
#if CAN_WRAP_iterate_mounts
    WRAP_FOR_DETACH(iterate_mounts)
#endif
#ifndef CAN_WRAP_acpi_os_delete_cache
#   define CAN_WRAP_acpi_os_delete_cache 1
#endif
#if CAN_WRAP_acpi_os_delete_cache
    WRAP_FOR_DETACH(acpi_os_delete_cache)
#endif
#ifndef CAN_WRAP_mcount
#   define CAN_WRAP_mcount 0
#endif
DETACH(mcount)
#ifndef CAN_WRAP_scheduler_tick
#   define CAN_WRAP_scheduler_tick 0
#endif
DETACH(scheduler_tick)
#ifndef CAN_WRAP_sata_scr_read
#   define CAN_WRAP_sata_scr_read 1
#endif
#if CAN_WRAP_sata_scr_read
    WRAP_FOR_DETACH(sata_scr_read)
#endif
#ifndef CAN_WRAP_setup_log_buf
#   define CAN_WRAP_setup_log_buf 0
#endif
DETACH(setup_log_buf)
#ifndef CAN_WRAP_pci_check_pme_status
#   define CAN_WRAP_pci_check_pme_status 1
#endif
#if CAN_WRAP_pci_check_pme_status
    WRAP_FOR_DETACH(pci_check_pme_status)
#endif
#ifndef CAN_WRAP_schedule_tail
#   define CAN_WRAP_schedule_tail 1
#endif
#if CAN_WRAP_schedule_tail
    WRAP_FOR_DETACH(schedule_tail)
#endif
#ifndef CAN_WRAP_restore_altstack
#   define CAN_WRAP_restore_altstack 1
#endif
#if CAN_WRAP_restore_altstack
    WRAP_FOR_DETACH(restore_altstack)
#endif
#ifndef CAN_WRAP_radix_tree_tag_set
#   define CAN_WRAP_radix_tree_tag_set 1
#endif
#if CAN_WRAP_radix_tree_tag_set
    WRAP_FOR_DETACH(radix_tree_tag_set)
#endif
#ifndef CAN_WRAP_cap_inode_setxattr
#   define CAN_WRAP_cap_inode_setxattr 1
#endif
#if CAN_WRAP_cap_inode_setxattr
    WRAP_FOR_DETACH(cap_inode_setxattr)
#endif
#ifndef CAN_WRAP_do_adjtimex
#   define CAN_WRAP_do_adjtimex 1
#endif
#if CAN_WRAP_do_adjtimex
    WRAP_FOR_DETACH(do_adjtimex)
#endif
#ifndef CAN_WRAP_prop_local_init_single
#   define CAN_WRAP_prop_local_init_single 1
#endif
#if CAN_WRAP_prop_local_init_single
    WRAP_FOR_DETACH(prop_local_init_single)
#endif
#ifndef CAN_WRAP_hex2bin
#   define CAN_WRAP_hex2bin 0
#endif
DETACH(hex2bin)
#ifndef CAN_WRAP_next_online_pgdat
#   define CAN_WRAP_next_online_pgdat 1
#endif
#if CAN_WRAP_next_online_pgdat
    WRAP_FOR_DETACH(next_online_pgdat)
#endif
#ifndef CAN_WRAP_idr_get_new_above
#   define CAN_WRAP_idr_get_new_above 1
#endif
#if CAN_WRAP_idr_get_new_above
    WRAP_FOR_DETACH(idr_get_new_above)
#endif
#ifndef CAN_WRAP___d_lookup_rcu
#   define CAN_WRAP___d_lookup_rcu 1
#endif
#if CAN_WRAP___d_lookup_rcu
#   ifdef DETACH_ADDR___d_lookup_rcu
        WRAP_FOR_DETACH(__d_lookup_rcu)
#   else
        TYPED_DETACH(__d_lookup_rcu)
#   endif
#endif
#ifndef CAN_WRAP_radix_tree_delete
#   define CAN_WRAP_radix_tree_delete 1
#endif
#if CAN_WRAP_radix_tree_delete
    WRAP_FOR_DETACH(radix_tree_delete)
#endif
#ifndef CAN_WRAP_pci_add_new_bus
#   define CAN_WRAP_pci_add_new_bus 1
#endif
#if CAN_WRAP_pci_add_new_bus
    WRAP_FOR_DETACH(pci_add_new_bus)
#endif
#ifndef CAN_WRAP_get_super
#   define CAN_WRAP_get_super 1
#endif
#if CAN_WRAP_get_super
    WRAP_FOR_DETACH(get_super)
#endif
#ifndef CAN_WRAP_dev_driver_string
#   define CAN_WRAP_dev_driver_string 1
#endif
#if CAN_WRAP_dev_driver_string
    WRAP_FOR_DETACH(dev_driver_string)
#endif
#ifndef CAN_WRAP_inet_csk_route_child_sock
#   define CAN_WRAP_inet_csk_route_child_sock 1
#endif
#if CAN_WRAP_inet_csk_route_child_sock
    WRAP_FOR_DETACH(inet_csk_route_child_sock)
#endif
#ifndef CAN_WRAP_get_mm_exe_file
#   define CAN_WRAP_get_mm_exe_file 1
#endif
#if CAN_WRAP_get_mm_exe_file
    WRAP_FOR_DETACH(get_mm_exe_file)
#endif
#ifndef CAN_WRAP_bioset_create
#   define CAN_WRAP_bioset_create 1
#endif
#if CAN_WRAP_bioset_create
    WRAP_FOR_DETACH(bioset_create)
#endif
#ifndef CAN_WRAP_apic_timer_interrupt
#   define CAN_WRAP_apic_timer_interrupt 0
#endif
DETACH(apic_timer_interrupt)
#ifndef CAN_WRAP_pci_restore_state
#   define CAN_WRAP_pci_restore_state 1
#endif
#if CAN_WRAP_pci_restore_state
    WRAP_FOR_DETACH(pci_restore_state)
#endif
#ifndef CAN_WRAP_bio_associate_current
#   define CAN_WRAP_bio_associate_current 1
#endif
#if CAN_WRAP_bio_associate_current
    WRAP_FOR_DETACH(bio_associate_current)
#endif
#ifndef CAN_WRAP___bitmap_equal
#   define CAN_WRAP___bitmap_equal 0
#endif
DETACH(__bitmap_equal)
#ifndef CAN_WRAP_sock_register
#   define CAN_WRAP_sock_register 1
#endif
#if CAN_WRAP_sock_register
    WRAP_FOR_DETACH(sock_register)
#endif
#ifndef CAN_WRAP_acpi_set_firmware_waking_vector64
#   define CAN_WRAP_acpi_set_firmware_waking_vector64 0
#endif
DETACH(acpi_set_firmware_waking_vector64)
#ifndef CAN_WRAP_sock_no_getsockopt
#   define CAN_WRAP_sock_no_getsockopt 1
#endif
#if CAN_WRAP_sock_no_getsockopt
    WRAP_FOR_DETACH(sock_no_getsockopt)
#endif
#ifndef CAN_WRAP_locks_remove_posix
#   define CAN_WRAP_locks_remove_posix 1
#endif
#if CAN_WRAP_locks_remove_posix
    WRAP_FOR_DETACH(locks_remove_posix)
#endif
#ifndef CAN_WRAP_dma_async_memcpy_buf_to_pg
#   define CAN_WRAP_dma_async_memcpy_buf_to_pg 1
#endif
#if CAN_WRAP_dma_async_memcpy_buf_to_pg
    WRAP_FOR_DETACH(dma_async_memcpy_buf_to_pg)
#endif
#ifndef CAN_WRAP_profile_event_register
#   define CAN_WRAP_profile_event_register 1
#endif
#if CAN_WRAP_profile_event_register
    WRAP_FOR_DETACH(profile_event_register)
#endif
#ifndef CAN_WRAP_pci_choose_state
#   define CAN_WRAP_pci_choose_state 1
#endif
#if CAN_WRAP_pci_choose_state
    WRAP_FOR_DETACH(pci_choose_state)
#endif
#ifndef CAN_WRAP_dev_addr_init
#   define CAN_WRAP_dev_addr_init 1
#endif
#if CAN_WRAP_dev_addr_init
    WRAP_FOR_DETACH(dev_addr_init)
#endif
#ifndef CAN_WRAP_acpi_os_gpe_count
#   define CAN_WRAP_acpi_os_gpe_count 0
#endif
DETACH(acpi_os_gpe_count)
#ifndef CAN_WRAP_cgroup_taskset_first
#   define CAN_WRAP_cgroup_taskset_first 1
#endif
#if CAN_WRAP_cgroup_taskset_first
    WRAP_FOR_DETACH(cgroup_taskset_first)
#endif
#ifndef CAN_WRAP_sigqueue_alloc
#   define CAN_WRAP_sigqueue_alloc 1
#endif
#if CAN_WRAP_sigqueue_alloc
    WRAP_FOR_DETACH(sigqueue_alloc)
#endif
#ifndef CAN_WRAP_ata_sff_prereset
#   define CAN_WRAP_ata_sff_prereset 1
#endif
#if CAN_WRAP_ata_sff_prereset
    WRAP_FOR_DETACH(ata_sff_prereset)
#endif
#ifndef CAN_WRAP_bio_unmap_user
#   define CAN_WRAP_bio_unmap_user 1
#endif
#if CAN_WRAP_bio_unmap_user
    WRAP_FOR_DETACH(bio_unmap_user)
#endif
#ifndef CAN_WRAP_pci_create_root_bus
#   define CAN_WRAP_pci_create_root_bus 1
#endif
#if CAN_WRAP_pci_create_root_bus
    WRAP_FOR_DETACH(pci_create_root_bus)
#endif
#ifndef CAN_WRAP_paravirt_patch_ignore
#   define CAN_WRAP_paravirt_patch_ignore 0
#endif
DETACH(paravirt_patch_ignore)
#ifndef CAN_WRAP_generic_file_open
#   define CAN_WRAP_generic_file_open 1
#endif
#if CAN_WRAP_generic_file_open
    WRAP_FOR_DETACH(generic_file_open)
#endif
#ifndef CAN_WRAP_unregister_switch_driver
#   define CAN_WRAP_unregister_switch_driver 1
#endif
#if CAN_WRAP_unregister_switch_driver
    WRAP_FOR_DETACH(unregister_switch_driver)
#endif
#ifndef CAN_WRAP_ata_id_c_string
#   define CAN_WRAP_ata_id_c_string 0
#endif
DETACH(ata_id_c_string)
#ifndef CAN_WRAP_pci_release_region
#   define CAN_WRAP_pci_release_region 1
#endif
#if CAN_WRAP_pci_release_region
    WRAP_FOR_DETACH(pci_release_region)
#endif
#ifndef CAN_WRAP_paravirt_enter_lazy_mmu
#   define CAN_WRAP_paravirt_enter_lazy_mmu 0
#endif
DETACH(paravirt_enter_lazy_mmu)
#ifndef CAN_WRAP_rdmsr_safe_on_cpu
#   define CAN_WRAP_rdmsr_safe_on_cpu 0
#endif
DETACH(rdmsr_safe_on_cpu)
#ifndef CAN_WRAP_d_lookup
#   define CAN_WRAP_d_lookup 1
#endif
#if CAN_WRAP_d_lookup
    WRAP_FOR_DETACH(d_lookup)
#endif
#ifndef CAN_WRAP_dev_mc_sync
#   define CAN_WRAP_dev_mc_sync 1
#endif
#if CAN_WRAP_dev_mc_sync
    WRAP_FOR_DETACH(dev_mc_sync)
#endif
#ifndef CAN_WRAP_free_nsproxy
#   define CAN_WRAP_free_nsproxy 1
#endif
#if CAN_WRAP_free_nsproxy
    WRAP_FOR_DETACH(free_nsproxy)
#endif
#ifndef CAN_WRAP_pci_enable_msix
#   define CAN_WRAP_pci_enable_msix 1
#endif
#if CAN_WRAP_pci_enable_msix
    WRAP_FOR_DETACH(pci_enable_msix)
#endif
#ifndef CAN_WRAP_ata_sas_port_stop
#   define CAN_WRAP_ata_sas_port_stop 1
#endif
#if CAN_WRAP_ata_sas_port_stop
    WRAP_FOR_DETACH(ata_sas_port_stop)
#endif
#ifndef CAN_WRAP_file_open_root
#   define CAN_WRAP_file_open_root 1
#endif
#if CAN_WRAP_file_open_root
    WRAP_FOR_DETACH(file_open_root)
#endif
#ifndef CAN_WRAP_acpi_install_method
#   define CAN_WRAP_acpi_install_method 0
#endif
DETACH(acpi_install_method)
#ifndef CAN_WRAP_crypto_has_alg
#   define CAN_WRAP_crypto_has_alg 0
#endif
DETACH(crypto_has_alg)
#ifndef CAN_WRAP_swapdev_block
#   define CAN_WRAP_swapdev_block 0
#endif
DETACH(swapdev_block)
#ifndef CAN_WRAP_prop_change_shift
#   define CAN_WRAP_prop_change_shift 1
#endif
#if CAN_WRAP_prop_change_shift
    WRAP_FOR_DETACH(prop_change_shift)
#endif
#ifndef CAN_WRAP_acpi_get_gpe_device
#   define CAN_WRAP_acpi_get_gpe_device 0
#endif
DETACH(acpi_get_gpe_device)
#ifndef CAN_WRAP_cache_show
#   define CAN_WRAP_cache_show 1
#endif
#if CAN_WRAP_cache_show
    WRAP_FOR_DETACH(cache_show)
#endif
#ifndef CAN_WRAP__raw_spin_unlock
#   define CAN_WRAP__raw_spin_unlock 1
#endif
#if CAN_WRAP__raw_spin_unlock
    WRAP_FOR_DETACH(_raw_spin_unlock)
#endif
#ifndef CAN_WRAP_input_flush_device
#   define CAN_WRAP_input_flush_device 1
#endif
#if CAN_WRAP_input_flush_device
    WRAP_FOR_DETACH(input_flush_device)
#endif
#ifndef CAN_WRAP_ata_acpi_cbl_80wire
#   define CAN_WRAP_ata_acpi_cbl_80wire 1
#endif
#if CAN_WRAP_ata_acpi_cbl_80wire
    WRAP_FOR_DETACH(ata_acpi_cbl_80wire)
#endif
#ifndef CAN_WRAP_task_handoff_register
#   define CAN_WRAP_task_handoff_register 1
#endif
#if CAN_WRAP_task_handoff_register
    WRAP_FOR_DETACH(task_handoff_register)
#endif
#ifndef CAN_WRAP___dev_change_flags
#   define CAN_WRAP___dev_change_flags 1
#endif
#if CAN_WRAP___dev_change_flags
#   ifdef DETACH_ADDR___dev_change_flags
        WRAP_FOR_DETACH(__dev_change_flags)
#   else
        TYPED_DETACH(__dev_change_flags)
#   endif
#endif
#ifndef CAN_WRAP_shrink_dcache_for_umount
#   define CAN_WRAP_shrink_dcache_for_umount 1
#endif
#if CAN_WRAP_shrink_dcache_for_umount
    WRAP_FOR_DETACH(shrink_dcache_for_umount)
#endif
#ifndef CAN_WRAP_kstrtouint_from_user
#   define CAN_WRAP_kstrtouint_from_user 0
#endif
DETACH(kstrtouint_from_user)
#ifndef CAN_WRAP_ata_dev_disable
#   define CAN_WRAP_ata_dev_disable 1
#endif
#if CAN_WRAP_ata_dev_disable
    WRAP_FOR_DETACH(ata_dev_disable)
#endif
#ifndef CAN_WRAP_core_kernel_text
#   define CAN_WRAP_core_kernel_text 0
#endif
DETACH(core_kernel_text)
#ifndef CAN_WRAP_bdi_destroy
#   define CAN_WRAP_bdi_destroy 1
#endif
#if CAN_WRAP_bdi_destroy
    WRAP_FOR_DETACH(bdi_destroy)
#endif
#ifndef CAN_WRAP_dpm_suspend_end
#   define CAN_WRAP_dpm_suspend_end 1
#endif
#if CAN_WRAP_dpm_suspend_end
    WRAP_FOR_DETACH(dpm_suspend_end)
#endif
#ifndef CAN_WRAP___inet_twsk_hashdance
#   define CAN_WRAP___inet_twsk_hashdance 1
#endif
#if CAN_WRAP___inet_twsk_hashdance
#   ifdef DETACH_ADDR___inet_twsk_hashdance
        WRAP_FOR_DETACH(__inet_twsk_hashdance)
#   else
        TYPED_DETACH(__inet_twsk_hashdance)
#   endif
#endif
#ifndef CAN_WRAP_dm_get_mdptr
#   define CAN_WRAP_dm_get_mdptr 1
#endif
#if CAN_WRAP_dm_get_mdptr
    WRAP_FOR_DETACH(dm_get_mdptr)
#endif
#ifndef CAN_WRAP_single_release
#   define CAN_WRAP_single_release 1
#endif
#if CAN_WRAP_single_release
    WRAP_FOR_DETACH(single_release)
#endif
#ifndef CAN_WRAP_pci_disable_obff
#   define CAN_WRAP_pci_disable_obff 1
#endif
#if CAN_WRAP_pci_disable_obff
    WRAP_FOR_DETACH(pci_disable_obff)
#endif
#ifndef CAN_WRAP_sysfs_create_file
#   define CAN_WRAP_sysfs_create_file 1
#endif
#if CAN_WRAP_sysfs_create_file
    WRAP_FOR_DETACH(sysfs_create_file)
#endif
#ifndef CAN_WRAP_skb_gro_receive
#   define CAN_WRAP_skb_gro_receive 1
#endif
#if CAN_WRAP_skb_gro_receive
    WRAP_FOR_DETACH(skb_gro_receive)
#endif
#ifndef CAN_WRAP_swap_free
#   define CAN_WRAP_swap_free 1
#endif
#if CAN_WRAP_swap_free
    WRAP_FOR_DETACH(swap_free)
#endif
#ifndef CAN_WRAP_param_get_string
#   define CAN_WRAP_param_get_string 1
#endif
#if CAN_WRAP_param_get_string
    WRAP_FOR_DETACH(param_get_string)
#endif
#ifndef CAN_WRAP_sk_unattached_filter_create
#   define CAN_WRAP_sk_unattached_filter_create 1
#endif
#if CAN_WRAP_sk_unattached_filter_create
    WRAP_FOR_DETACH(sk_unattached_filter_create)
#endif
#ifndef CAN_WRAP_ata_scsi_slave_config
#   define CAN_WRAP_ata_scsi_slave_config 1
#endif
#if CAN_WRAP_ata_scsi_slave_config
    WRAP_FOR_DETACH(ata_scsi_slave_config)
#endif
#ifndef CAN_WRAP_blk_queue_stack_limits
#   define CAN_WRAP_blk_queue_stack_limits 1
#endif
#if CAN_WRAP_blk_queue_stack_limits
    WRAP_FOR_DETACH(blk_queue_stack_limits)
#endif
#ifndef CAN_WRAP___srcu_read_lock
#   define CAN_WRAP___srcu_read_lock 1
#endif
#if CAN_WRAP___srcu_read_lock
#   ifdef DETACH_ADDR___srcu_read_lock
        WRAP_FOR_DETACH(__srcu_read_lock)
#   else
        TYPED_DETACH(__srcu_read_lock)
#   endif
#endif
#ifndef CAN_WRAP_dm_table_event
#   define CAN_WRAP_dm_table_event 1
#endif
#if CAN_WRAP_dm_table_event
    WRAP_FOR_DETACH(dm_table_event)
#endif
#ifndef CAN_WRAP_pci_dev_present
#   define CAN_WRAP_pci_dev_present 1
#endif
#if CAN_WRAP_pci_dev_present
    WRAP_FOR_DETACH(pci_dev_present)
#endif
#ifndef CAN_WRAP_kobject_get_path
#   define CAN_WRAP_kobject_get_path 1
#endif
#if CAN_WRAP_kobject_get_path
    WRAP_FOR_DETACH(kobject_get_path)
#endif
#ifndef CAN_WRAP_sg_copy_to_buffer
#   define CAN_WRAP_sg_copy_to_buffer 1
#endif
#if CAN_WRAP_sg_copy_to_buffer
    WRAP_FOR_DETACH(sg_copy_to_buffer)
#endif
#ifndef CAN_WRAP_dm_kill_unmapped_request
#   define CAN_WRAP_dm_kill_unmapped_request 1
#endif
#if CAN_WRAP_dm_kill_unmapped_request
    WRAP_FOR_DETACH(dm_kill_unmapped_request)
#endif
#ifndef CAN_WRAP_acpi_leave_sleep_state_prep
#   define CAN_WRAP_acpi_leave_sleep_state_prep 0
#endif
DETACH(acpi_leave_sleep_state_prep)
#ifndef CAN_WRAP_sock_from_file
#   define CAN_WRAP_sock_from_file 1
#endif
#if CAN_WRAP_sock_from_file
    WRAP_FOR_DETACH(sock_from_file)
#endif
#ifndef CAN_WRAP_module_bug_cleanup
#   define CAN_WRAP_module_bug_cleanup 1
#endif
#if CAN_WRAP_module_bug_cleanup
    WRAP_FOR_DETACH(module_bug_cleanup)
#endif
#ifndef CAN_WRAP__raw_spin_trylock
#   define CAN_WRAP__raw_spin_trylock 1
#endif
#if CAN_WRAP__raw_spin_trylock
    WRAP_FOR_DETACH(_raw_spin_trylock)
#endif
#ifndef CAN_WRAP_dql_reset
#   define CAN_WRAP_dql_reset 1
#endif
#if CAN_WRAP_dql_reset
    WRAP_FOR_DETACH(dql_reset)
#endif
#ifndef CAN_WRAP_rtnetlink_init
#   define CAN_WRAP_rtnetlink_init 0
#endif
DETACH(rtnetlink_init)
#ifndef CAN_WRAP_compat_sys_timer_gettime
#   define CAN_WRAP_compat_sys_timer_gettime 1
#endif
#if CAN_WRAP_compat_sys_timer_gettime
    WRAP_FOR_DETACH(compat_sys_timer_gettime)
#endif
#ifndef CAN_WRAP_sched_exec
#   define CAN_WRAP_sched_exec 0
#endif
DETACH(sched_exec)
#ifndef CAN_WRAP_neigh_parms_alloc
#   define CAN_WRAP_neigh_parms_alloc 1
#endif
#if CAN_WRAP_neigh_parms_alloc
    WRAP_FOR_DETACH(neigh_parms_alloc)
#endif
#ifndef CAN_WRAP_unmap_mapping_range
#   define CAN_WRAP_unmap_mapping_range 1
#endif
#if CAN_WRAP_unmap_mapping_range
    WRAP_FOR_DETACH(unmap_mapping_range)
#endif
#ifndef CAN_WRAP_vm_events_fold_cpu
#   define CAN_WRAP_vm_events_fold_cpu 0
#endif
DETACH(vm_events_fold_cpu)
#ifndef CAN_WRAP_netlink_sendskb
#   define CAN_WRAP_netlink_sendskb 1
#endif
#if CAN_WRAP_netlink_sendskb
    WRAP_FOR_DETACH(netlink_sendskb)
#endif
#ifndef CAN_WRAP_kobject_create
#   define CAN_WRAP_kobject_create 1
#endif
#if CAN_WRAP_kobject_create
    WRAP_FOR_DETACH(kobject_create)
#endif
#ifndef CAN_WRAP_unlock_memory_hotplug
#   define CAN_WRAP_unlock_memory_hotplug 0
#endif
DETACH(unlock_memory_hotplug)
#ifndef CAN_WRAP_skb_put
#   define CAN_WRAP_skb_put 1
#endif
#if CAN_WRAP_skb_put
    WRAP_FOR_DETACH(skb_put)
#endif
#ifndef CAN_WRAP_mempool_resize
#   define CAN_WRAP_mempool_resize 1
#endif
#if CAN_WRAP_mempool_resize
    WRAP_FOR_DETACH(mempool_resize)
#endif
#ifndef CAN_WRAP_kick_all_cpus_sync
#   define CAN_WRAP_kick_all_cpus_sync 0
#endif
DETACH(kick_all_cpus_sync)
#ifndef CAN_WRAP_security_inode_killpriv
#   define CAN_WRAP_security_inode_killpriv 1
#endif
#if CAN_WRAP_security_inode_killpriv
    WRAP_FOR_DETACH(security_inode_killpriv)
#endif
#ifndef CAN_WRAP_bitmap_set
#   define CAN_WRAP_bitmap_set 0
#endif
DETACH(bitmap_set)
#ifndef CAN_WRAP_show_stack
#   define CAN_WRAP_show_stack 1
#endif
#if CAN_WRAP_show_stack
    WRAP_FOR_DETACH(show_stack)
#endif
#ifndef CAN_WRAP_wait_on_page_bit_killable
#   define CAN_WRAP_wait_on_page_bit_killable 1
#endif
#if CAN_WRAP_wait_on_page_bit_killable
    WRAP_FOR_DETACH(wait_on_page_bit_killable)
#endif
#ifndef CAN_WRAP_get_next_timer_interrupt
#   define CAN_WRAP_get_next_timer_interrupt 0
#endif
DETACH(get_next_timer_interrupt)
#ifndef CAN_WRAP_dm_get_geometry
#   define CAN_WRAP_dm_get_geometry 1
#endif
#if CAN_WRAP_dm_get_geometry
    WRAP_FOR_DETACH(dm_get_geometry)
#endif
#ifndef CAN_WRAP_dev_graft_qdisc
#   define CAN_WRAP_dev_graft_qdisc 1
#endif
#if CAN_WRAP_dev_graft_qdisc
    WRAP_FOR_DETACH(dev_graft_qdisc)
#endif
#ifndef CAN_WRAP_input_set_abs_params
#   define CAN_WRAP_input_set_abs_params 1
#endif
#if CAN_WRAP_input_set_abs_params
    WRAP_FOR_DETACH(input_set_abs_params)
#endif
#ifndef CAN_WRAP_d_obtain_alias
#   define CAN_WRAP_d_obtain_alias 1
#endif
#if CAN_WRAP_d_obtain_alias
    WRAP_FOR_DETACH(d_obtain_alias)
#endif
#ifndef CAN_WRAP_pci_get_rom_size
#   define CAN_WRAP_pci_get_rom_size 1
#endif
#if CAN_WRAP_pci_get_rom_size
    WRAP_FOR_DETACH(pci_get_rom_size)
#endif
#ifndef CAN_WRAP_vmemmap_alloc_block_buf
#   define CAN_WRAP_vmemmap_alloc_block_buf 0
#endif
DETACH(vmemmap_alloc_block_buf)
#ifndef CAN_WRAP_hex_to_bin
#   define CAN_WRAP_hex_to_bin 0
#endif
DETACH(hex_to_bin)
#ifndef CAN_WRAP_memweight
#   define CAN_WRAP_memweight 0
#endif
DETACH(memweight)
#ifndef CAN_WRAP_setup_ioapic_ids_from_mpc
#   define CAN_WRAP_setup_ioapic_ids_from_mpc 0
#endif
DETACH(setup_ioapic_ids_from_mpc)
#ifndef CAN_WRAP_tick_clock_notify
#   define CAN_WRAP_tick_clock_notify 0
#endif
DETACH(tick_clock_notify)
#ifndef CAN_WRAP_add_one_highpage
#   define CAN_WRAP_add_one_highpage 1
#endif
#if CAN_WRAP_add_one_highpage
    WRAP_FOR_DETACH(add_one_highpage)
#endif
#ifndef CAN_WRAP_netdev_features_change
#   define CAN_WRAP_netdev_features_change 1
#endif
#if CAN_WRAP_netdev_features_change
    WRAP_FOR_DETACH(netdev_features_change)
#endif
#ifndef CAN_WRAP_pcpu_alloc_alloc_info
#   define CAN_WRAP_pcpu_alloc_alloc_info 1
#endif
#if CAN_WRAP_pcpu_alloc_alloc_info
    WRAP_FOR_DETACH(pcpu_alloc_alloc_info)
#endif
#ifndef CAN_WRAP_proc_doulongvec_ms_jiffies_minmax
#   define CAN_WRAP_proc_doulongvec_ms_jiffies_minmax 1
#endif
#if CAN_WRAP_proc_doulongvec_ms_jiffies_minmax
    WRAP_FOR_DETACH(proc_doulongvec_ms_jiffies_minmax)
#endif
#ifndef CAN_WRAP_proc_do_large_bitmap
#   define CAN_WRAP_proc_do_large_bitmap 1
#endif
#if CAN_WRAP_proc_do_large_bitmap
    WRAP_FOR_DETACH(proc_do_large_bitmap)
#endif
#ifndef CAN_WRAP_lookup_resource
#   define CAN_WRAP_lookup_resource 1
#endif
#if CAN_WRAP_lookup_resource
    WRAP_FOR_DETACH(lookup_resource)
#endif
#ifndef CAN_WRAP_alloc_pid
#   define CAN_WRAP_alloc_pid 1
#endif
#if CAN_WRAP_alloc_pid
    WRAP_FOR_DETACH(alloc_pid)
#endif
#ifndef CAN_WRAP_proc_free_inum
#   define CAN_WRAP_proc_free_inum 0
#endif
DETACH(proc_free_inum)
#ifndef CAN_WRAP_klist_next
#   define CAN_WRAP_klist_next 1
#endif
#if CAN_WRAP_klist_next
    WRAP_FOR_DETACH(klist_next)
#endif
#ifndef CAN_WRAP_gen_kill_estimator
#   define CAN_WRAP_gen_kill_estimator 1
#endif
#if CAN_WRAP_gen_kill_estimator
    WRAP_FOR_DETACH(gen_kill_estimator)
#endif
#ifndef CAN_WRAP_acpi_pci_find_root
#   define CAN_WRAP_acpi_pci_find_root 1
#endif
#if CAN_WRAP_acpi_pci_find_root
    WRAP_FOR_DETACH(acpi_pci_find_root)
#endif
#ifndef CAN_WRAP_cdrom_number_of_slots
#   define CAN_WRAP_cdrom_number_of_slots 1
#endif
#if CAN_WRAP_cdrom_number_of_slots
    WRAP_FOR_DETACH(cdrom_number_of_slots)
#endif
#ifndef CAN_WRAP_skip_spaces
#   define CAN_WRAP_skip_spaces 0
#endif
DETACH(skip_spaces)
#ifndef CAN_WRAP_cpu_init
#   define CAN_WRAP_cpu_init 0
#endif
DETACH(cpu_init)
#ifndef CAN_WRAP_inet_csk_listen_start
#   define CAN_WRAP_inet_csk_listen_start 1
#endif
#if CAN_WRAP_inet_csk_listen_start
    WRAP_FOR_DETACH(inet_csk_listen_start)
#endif
#ifndef CAN_WRAP_pnp_auto_config_dev
#   define CAN_WRAP_pnp_auto_config_dev 1
#endif
#if CAN_WRAP_pnp_auto_config_dev
    WRAP_FOR_DETACH(pnp_auto_config_dev)
#endif
#ifndef CAN_WRAP_css_depth
#   define CAN_WRAP_css_depth 1
#endif
#if CAN_WRAP_css_depth
    WRAP_FOR_DETACH(css_depth)
#endif
#ifndef CAN_WRAP_task_can_switch_user
#   define CAN_WRAP_task_can_switch_user 1
#endif
#if CAN_WRAP_task_can_switch_user
    WRAP_FOR_DETACH(task_can_switch_user)
#endif
#ifndef CAN_WRAP_subsys_interface_register
#   define CAN_WRAP_subsys_interface_register 1
#endif
#if CAN_WRAP_subsys_interface_register
    WRAP_FOR_DETACH(subsys_interface_register)
#endif
#ifndef CAN_WRAP_compat_sys_mount
#   define CAN_WRAP_compat_sys_mount 0
#endif
DETACH(compat_sys_mount)
#ifndef CAN_WRAP_calc_global_load
#   define CAN_WRAP_calc_global_load 0
#endif
DETACH(calc_global_load)
#ifndef CAN_WRAP_memblock_x86_fill
#   define CAN_WRAP_memblock_x86_fill 0
#endif
DETACH(memblock_x86_fill)
#ifndef CAN_WRAP_register_hotplug_dock_device
#   define CAN_WRAP_register_hotplug_dock_device 1
#endif
#if CAN_WRAP_register_hotplug_dock_device
    WRAP_FOR_DETACH(register_hotplug_dock_device)
#endif
#ifndef CAN_WRAP_pci_scan_bus_parented
#   define CAN_WRAP_pci_scan_bus_parented 1
#endif
#if CAN_WRAP_pci_scan_bus_parented
    WRAP_FOR_DETACH(pci_scan_bus_parented)
#endif
#ifndef CAN_WRAP_request_percpu_irq
#   define CAN_WRAP_request_percpu_irq 1
#endif
#if CAN_WRAP_request_percpu_irq
    WRAP_FOR_DETACH(request_percpu_irq)
#endif
#ifndef CAN_WRAP_jbd2_journal_blocks_per_page
#   define CAN_WRAP_jbd2_journal_blocks_per_page 1
#endif
#if CAN_WRAP_jbd2_journal_blocks_per_page
    WRAP_FOR_DETACH(jbd2_journal_blocks_per_page)
#endif
#ifndef CAN_WRAP_from_kqid
#   define CAN_WRAP_from_kqid 1
#endif
#if CAN_WRAP_from_kqid
    WRAP_FOR_DETACH(from_kqid)
#endif
#ifndef CAN_WRAP_sata_link_resume
#   define CAN_WRAP_sata_link_resume 1
#endif
#if CAN_WRAP_sata_link_resume
    WRAP_FOR_DETACH(sata_link_resume)
#endif
#ifndef CAN_WRAP_acpi_get_id
#   define CAN_WRAP_acpi_get_id 0
#endif
DETACH(acpi_get_id)
#ifndef CAN_WRAP__raw_read_unlock_bh
#   define CAN_WRAP__raw_read_unlock_bh 1
#endif
#if CAN_WRAP__raw_read_unlock_bh
    WRAP_FOR_DETACH(_raw_read_unlock_bh)
#endif
#ifndef CAN_WRAP_register_sysctl
#   define CAN_WRAP_register_sysctl 1
#endif
#if CAN_WRAP_register_sysctl
    WRAP_FOR_DETACH(register_sysctl)
#endif
#ifndef CAN_WRAP_pcibios_align_resource
#   define CAN_WRAP_pcibios_align_resource 1
#endif
#if CAN_WRAP_pcibios_align_resource
    WRAP_FOR_DETACH(pcibios_align_resource)
#endif
#ifndef CAN_WRAP_flow_cache_flush
#   define CAN_WRAP_flow_cache_flush 0
#endif
DETACH(flow_cache_flush)
#ifndef CAN_WRAP_kblockd_schedule_work
#   define CAN_WRAP_kblockd_schedule_work 1
#endif
#if CAN_WRAP_kblockd_schedule_work
    WRAP_FOR_DETACH(kblockd_schedule_work)
#endif
#ifndef CAN_WRAP_pagecache_write_end
#   define CAN_WRAP_pagecache_write_end 1
#endif
#if CAN_WRAP_pagecache_write_end
    WRAP_FOR_DETACH(pagecache_write_end)
#endif
#ifndef CAN_WRAP_init_idle_bootup_task
#   define CAN_WRAP_init_idle_bootup_task 1
#endif
#if CAN_WRAP_init_idle_bootup_task
    WRAP_FOR_DETACH(init_idle_bootup_task)
#endif
#ifndef CAN_WRAP_input_reset_device
#   define CAN_WRAP_input_reset_device 1
#endif
#if CAN_WRAP_input_reset_device
    WRAP_FOR_DETACH(input_reset_device)
#endif
#ifndef CAN_WRAP___percpu_counter_add
#   define CAN_WRAP___percpu_counter_add 1
#endif
#if CAN_WRAP___percpu_counter_add
#   ifdef DETACH_ADDR___percpu_counter_add
        WRAP_FOR_DETACH(__percpu_counter_add)
#   else
        TYPED_DETACH(__percpu_counter_add)
#   endif
#endif
#ifndef CAN_WRAP_block_invalidatepage
#   define CAN_WRAP_block_invalidatepage 1
#endif
#if CAN_WRAP_block_invalidatepage
    WRAP_FOR_DETACH(block_invalidatepage)
#endif
#ifndef CAN_WRAP_sock_no_sendmsg
#   define CAN_WRAP_sock_no_sendmsg 1
#endif
#if CAN_WRAP_sock_no_sendmsg
    WRAP_FOR_DETACH(sock_no_sendmsg)
#endif
#ifndef CAN_WRAP_generic_splice_sendpage
#   define CAN_WRAP_generic_splice_sendpage 1
#endif
#if CAN_WRAP_generic_splice_sendpage
    WRAP_FOR_DETACH(generic_splice_sendpage)
#endif
#ifndef CAN_WRAP_ptep_test_and_clear_young
#   define CAN_WRAP_ptep_test_and_clear_young 1
#endif
#if CAN_WRAP_ptep_test_and_clear_young
    WRAP_FOR_DETACH(ptep_test_and_clear_young)
#endif
#ifndef CAN_WRAP_dm_get_event_nr
#   define CAN_WRAP_dm_get_event_nr 1
#endif
#if CAN_WRAP_dm_get_event_nr
    WRAP_FOR_DETACH(dm_get_event_nr)
#endif
#ifndef CAN_WRAP___bitmap_xor
#   define CAN_WRAP___bitmap_xor 0
#endif
DETACH(__bitmap_xor)
#ifndef CAN_WRAP_phy_ethtool_sset
#   define CAN_WRAP_phy_ethtool_sset 1
#endif
#if CAN_WRAP_phy_ethtool_sset
    WRAP_FOR_DETACH(phy_ethtool_sset)
#endif
#ifndef CAN_WRAP_send_cleanup_vector
#   define CAN_WRAP_send_cleanup_vector 1
#endif
#if CAN_WRAP_send_cleanup_vector
    WRAP_FOR_DETACH(send_cleanup_vector)
#endif
#ifndef CAN_WRAP_build_skb
#   define CAN_WRAP_build_skb 1
#endif
#if CAN_WRAP_build_skb
    WRAP_FOR_DETACH(build_skb)
#endif
#ifndef CAN_WRAP_acpi_is_video_device
#   define CAN_WRAP_acpi_is_video_device 1
#endif
#if CAN_WRAP_acpi_is_video_device
    WRAP_FOR_DETACH(acpi_is_video_device)
#endif
#ifndef CAN_WRAP_subsys_system_register
#   define CAN_WRAP_subsys_system_register 1
#endif
#if CAN_WRAP_subsys_system_register
    WRAP_FOR_DETACH(subsys_system_register)
#endif
#ifndef CAN_WRAP__paravirt_nop
#   define CAN_WRAP__paravirt_nop 0
#endif
DETACH(_paravirt_nop)
#ifndef CAN_WRAP_neigh_connected_output
#   define CAN_WRAP_neigh_connected_output 1
#endif
#if CAN_WRAP_neigh_connected_output
    WRAP_FOR_DETACH(neigh_connected_output)
#endif
#ifndef CAN_WRAP_crypto_unregister_alg
#   define CAN_WRAP_crypto_unregister_alg 1
#endif
#if CAN_WRAP_crypto_unregister_alg
    WRAP_FOR_DETACH(crypto_unregister_alg)
#endif
#ifndef CAN_WRAP_module_kallsyms_lookup_name
#   define CAN_WRAP_module_kallsyms_lookup_name 0
#endif
DETACH(module_kallsyms_lookup_name)
#ifndef CAN_WRAP_copy_siginfo_from_user32
#   define CAN_WRAP_copy_siginfo_from_user32 1
#endif
#if CAN_WRAP_copy_siginfo_from_user32
    WRAP_FOR_DETACH(copy_siginfo_from_user32)
#endif
#ifndef CAN_WRAP_mp_ioapic_gsi_routing
#   define CAN_WRAP_mp_ioapic_gsi_routing 1
#endif
#if CAN_WRAP_mp_ioapic_gsi_routing
    WRAP_FOR_DETACH(mp_ioapic_gsi_routing)
#endif
#ifndef CAN_WRAP_phy_connect
#   define CAN_WRAP_phy_connect 1
#endif
#if CAN_WRAP_phy_connect
    WRAP_FOR_DETACH(phy_connect)
#endif
#ifndef CAN_WRAP_signal_delivered
#   define CAN_WRAP_signal_delivered 1
#endif
#if CAN_WRAP_signal_delivered
    WRAP_FOR_DETACH(signal_delivered)
#endif
#ifndef CAN_WRAP_security_inode_listxattr
#   define CAN_WRAP_security_inode_listxattr 1
#endif
#if CAN_WRAP_security_inode_listxattr
    WRAP_FOR_DETACH(security_inode_listxattr)
#endif
#ifndef CAN_WRAP_bio_map_kern
#   define CAN_WRAP_bio_map_kern 1
#endif
#if CAN_WRAP_bio_map_kern
    WRAP_FOR_DETACH(bio_map_kern)
#endif
#ifndef CAN_WRAP_blk_queue_dma_drain
#   define CAN_WRAP_blk_queue_dma_drain 1
#endif
#if CAN_WRAP_blk_queue_dma_drain
    WRAP_FOR_DETACH(blk_queue_dma_drain)
#endif
#ifndef CAN_WRAP_kset_find_obj
#   define CAN_WRAP_kset_find_obj 1
#endif
#if CAN_WRAP_kset_find_obj
    WRAP_FOR_DETACH(kset_find_obj)
#endif
#ifndef CAN_WRAP_set_security_override
#   define CAN_WRAP_set_security_override 1
#endif
#if CAN_WRAP_set_security_override
    WRAP_FOR_DETACH(set_security_override)
#endif
#ifndef CAN_WRAP_inode_needs_sync
#   define CAN_WRAP_inode_needs_sync 1
#endif
#if CAN_WRAP_inode_needs_sync
    WRAP_FOR_DETACH(inode_needs_sync)
#endif
#ifndef CAN_WRAP_vlan_vids_del_by_dev
#   define CAN_WRAP_vlan_vids_del_by_dev 1
#endif
#if CAN_WRAP_vlan_vids_del_by_dev
    WRAP_FOR_DETACH(vlan_vids_del_by_dev)
#endif
#ifndef CAN_WRAP_acpi_bus_get_status
#   define CAN_WRAP_acpi_bus_get_status 1
#endif
#if CAN_WRAP_acpi_bus_get_status
    WRAP_FOR_DETACH(acpi_bus_get_status)
#endif
#ifndef CAN_WRAP_swiotlb_map_page
#   define CAN_WRAP_swiotlb_map_page 1
#endif
#if CAN_WRAP_swiotlb_map_page
    WRAP_FOR_DETACH(swiotlb_map_page)
#endif
#ifndef CAN_WRAP___lock_page
#   define CAN_WRAP___lock_page 1
#endif
#if CAN_WRAP___lock_page
#   ifdef DETACH_ADDR___lock_page
        WRAP_FOR_DETACH(__lock_page)
#   else
        TYPED_DETACH(__lock_page)
#   endif
#endif
#ifndef CAN_WRAP___atomic_notifier_call_chain
#   define CAN_WRAP___atomic_notifier_call_chain 1
#endif
#if CAN_WRAP___atomic_notifier_call_chain
#   ifdef DETACH_ADDR___atomic_notifier_call_chain
        WRAP_FOR_DETACH(__atomic_notifier_call_chain)
#   else
        TYPED_DETACH(__atomic_notifier_call_chain)
#   endif
#endif
#ifndef CAN_WRAP_lookup_address
#   define CAN_WRAP_lookup_address 1
#endif
#if CAN_WRAP_lookup_address
    WRAP_FOR_DETACH(lookup_address)
#endif
#ifndef CAN_WRAP_put_compat_rusage
#   define CAN_WRAP_put_compat_rusage 1
#endif
#if CAN_WRAP_put_compat_rusage
    WRAP_FOR_DETACH(put_compat_rusage)
#endif
#ifndef CAN_WRAP_blk_unregister_queue
#   define CAN_WRAP_blk_unregister_queue 1
#endif
#if CAN_WRAP_blk_unregister_queue
    WRAP_FOR_DETACH(blk_unregister_queue)
#endif
#ifndef CAN_WRAP_ata_sas_scsi_ioctl
#   define CAN_WRAP_ata_sas_scsi_ioctl 1
#endif
#if CAN_WRAP_ata_sas_scsi_ioctl
    WRAP_FOR_DETACH(ata_sas_scsi_ioctl)
#endif
#ifndef CAN_WRAP_mp_config_acpi_legacy_irqs
#   define CAN_WRAP_mp_config_acpi_legacy_irqs 0
#endif
DETACH(mp_config_acpi_legacy_irqs)
#ifndef CAN_WRAP_sysfs_create_bin_file
#   define CAN_WRAP_sysfs_create_bin_file 1
#endif
#if CAN_WRAP_sysfs_create_bin_file
    WRAP_FOR_DETACH(sysfs_create_bin_file)
#endif
#ifndef CAN_WRAP_set_mp_bus_to_node
#   define CAN_WRAP_set_mp_bus_to_node 0
#endif
DETACH(set_mp_bus_to_node)
#ifndef CAN_WRAP_dev_uc_sync
#   define CAN_WRAP_dev_uc_sync 1
#endif
#if CAN_WRAP_dev_uc_sync
    WRAP_FOR_DETACH(dev_uc_sync)
#endif
#ifndef CAN_WRAP_bh_submit_read
#   define CAN_WRAP_bh_submit_read 1
#endif
#if CAN_WRAP_bh_submit_read
    WRAP_FOR_DETACH(bh_submit_read)
#endif
#ifndef CAN_WRAP_override_creds
#   define CAN_WRAP_override_creds 1
#endif
#if CAN_WRAP_override_creds
    WRAP_FOR_DETACH(override_creds)
#endif
#ifndef CAN_WRAP_subsys_dev_iter_exit
#   define CAN_WRAP_subsys_dev_iter_exit 1
#endif
#if CAN_WRAP_subsys_dev_iter_exit
    WRAP_FOR_DETACH(subsys_dev_iter_exit)
#endif
#ifndef CAN_WRAP_security_sb_alloc
#   define CAN_WRAP_security_sb_alloc 1
#endif
#if CAN_WRAP_security_sb_alloc
    WRAP_FOR_DETACH(security_sb_alloc)
#endif
#ifndef CAN_WRAP_dma_pin_iovec_pages
#   define CAN_WRAP_dma_pin_iovec_pages 1
#endif
#if CAN_WRAP_dma_pin_iovec_pages
    WRAP_FOR_DETACH(dma_pin_iovec_pages)
#endif
#ifndef CAN_WRAP_schedule_timeout_uninterruptible
#   define CAN_WRAP_schedule_timeout_uninterruptible 0
#endif
DETACH(schedule_timeout_uninterruptible)
#ifndef CAN_WRAP_bpf_jit_free
#   define CAN_WRAP_bpf_jit_free 1
#endif
#if CAN_WRAP_bpf_jit_free
    WRAP_FOR_DETACH(bpf_jit_free)
#endif
#ifndef CAN_WRAP_blk_free_tags
#   define CAN_WRAP_blk_free_tags 1
#endif
#if CAN_WRAP_blk_free_tags
    WRAP_FOR_DETACH(blk_free_tags)
#endif
#ifndef CAN_WRAP_napi_gro_frags
#   define CAN_WRAP_napi_gro_frags 1
#endif
#if CAN_WRAP_napi_gro_frags
    WRAP_FOR_DETACH(napi_gro_frags)
#endif
#ifndef CAN_WRAP_set_pages_uc
#   define CAN_WRAP_set_pages_uc 1
#endif
#if CAN_WRAP_set_pages_uc
    WRAP_FOR_DETACH(set_pages_uc)
#endif
#ifndef CAN_WRAP_param_get_invbool
#   define CAN_WRAP_param_get_invbool 1
#endif
#if CAN_WRAP_param_get_invbool
    WRAP_FOR_DETACH(param_get_invbool)
#endif
#ifndef CAN_WRAP_part_stat_show
#   define CAN_WRAP_part_stat_show 1
#endif
#if CAN_WRAP_part_stat_show
    WRAP_FOR_DETACH(part_stat_show)
#endif
#ifndef CAN_WRAP_ata_msleep
#   define CAN_WRAP_ata_msleep 1
#endif
#if CAN_WRAP_ata_msleep
    WRAP_FOR_DETACH(ata_msleep)
#endif
#ifndef CAN_WRAP_class_remove_file
#   define CAN_WRAP_class_remove_file 1
#endif
#if CAN_WRAP_class_remove_file
    WRAP_FOR_DETACH(class_remove_file)
#endif
#ifndef CAN_WRAP_buffer_migrate_page
#   define CAN_WRAP_buffer_migrate_page 1
#endif
#if CAN_WRAP_buffer_migrate_page
    WRAP_FOR_DETACH(buffer_migrate_page)
#endif
#ifndef CAN_WRAP_security_sk_alloc
#   define CAN_WRAP_security_sk_alloc 1
#endif
#if CAN_WRAP_security_sk_alloc
    WRAP_FOR_DETACH(security_sk_alloc)
#endif
#ifndef CAN_WRAP_set_timer_slack
#   define CAN_WRAP_set_timer_slack 1
#endif
#if CAN_WRAP_set_timer_slack
    WRAP_FOR_DETACH(set_timer_slack)
#endif
#ifndef CAN_WRAP_mnt_clone_write
#   define CAN_WRAP_mnt_clone_write 1
#endif
#if CAN_WRAP_mnt_clone_write
    WRAP_FOR_DETACH(mnt_clone_write)
#endif
#ifndef CAN_WRAP_mod_timer
#   define CAN_WRAP_mod_timer 1
#endif
#if CAN_WRAP_mod_timer
    WRAP_FOR_DETACH(mod_timer)
#endif
#ifndef CAN_WRAP___rtnl_link_unregister
#   define CAN_WRAP___rtnl_link_unregister 1
#endif
#if CAN_WRAP___rtnl_link_unregister
#   ifdef DETACH_ADDR___rtnl_link_unregister
        WRAP_FOR_DETACH(__rtnl_link_unregister)
#   else
        TYPED_DETACH(__rtnl_link_unregister)
#   endif
#endif
#ifndef CAN_WRAP_dev_set_group
#   define CAN_WRAP_dev_set_group 1
#endif
#if CAN_WRAP_dev_set_group
    WRAP_FOR_DETACH(dev_set_group)
#endif
#ifndef CAN_WRAP_locks_end_grace
#   define CAN_WRAP_locks_end_grace 1
#endif
#if CAN_WRAP_locks_end_grace
    WRAP_FOR_DETACH(locks_end_grace)
#endif
#ifndef CAN_WRAP_clockevents_register_notifier
#   define CAN_WRAP_clockevents_register_notifier 1
#endif
#if CAN_WRAP_clockevents_register_notifier
    WRAP_FOR_DETACH(clockevents_register_notifier)
#endif
#ifndef CAN_WRAP_dev_load
#   define CAN_WRAP_dev_load 1
#endif
#if CAN_WRAP_dev_load
    WRAP_FOR_DETACH(dev_load)
#endif
#ifndef CAN_WRAP_do_exit
#   define CAN_WRAP_do_exit 0
#endif
DETACH(do_exit)
#ifndef CAN_WRAP_blkdev_issue_write_same
#   define CAN_WRAP_blkdev_issue_write_same 1
#endif
#if CAN_WRAP_blkdev_issue_write_same
    WRAP_FOR_DETACH(blkdev_issue_write_same)
#endif
#ifndef CAN_WRAP_irq_set_affinity
#   define CAN_WRAP_irq_set_affinity 1
#endif
#if CAN_WRAP_irq_set_affinity
    WRAP_FOR_DETACH(irq_set_affinity)
#endif
#ifndef CAN_WRAP_freeze_workqueues_busy
#   define CAN_WRAP_freeze_workqueues_busy 0
#endif
DETACH(freeze_workqueues_busy)
#ifndef CAN_WRAP_compat_sys_pselect6
#   define CAN_WRAP_compat_sys_pselect6 1
#endif
#if CAN_WRAP_compat_sys_pselect6
    WRAP_FOR_DETACH(compat_sys_pselect6)
#endif
#ifndef CAN_WRAP_setup_profiling_timer
#   define CAN_WRAP_setup_profiling_timer 0
#endif
DETACH(setup_profiling_timer)
#ifndef CAN_WRAP___node_distance
#   define CAN_WRAP___node_distance 0
#endif
DETACH(__node_distance)
#ifndef CAN_WRAP_inet_twsk_alloc
#   define CAN_WRAP_inet_twsk_alloc 1
#endif
#if CAN_WRAP_inet_twsk_alloc
    WRAP_FOR_DETACH(inet_twsk_alloc)
#endif
#ifndef CAN_WRAP_ptep_clear_flush
#   define CAN_WRAP_ptep_clear_flush 1
#endif
#if CAN_WRAP_ptep_clear_flush
    WRAP_FOR_DETACH(ptep_clear_flush)
#endif
#ifndef CAN_WRAP_machine_emergency_restart
#   define CAN_WRAP_machine_emergency_restart 0
#endif
DETACH(machine_emergency_restart)
#ifndef CAN_WRAP_user_path_at
#   define CAN_WRAP_user_path_at 1
#endif
#if CAN_WRAP_user_path_at
    WRAP_FOR_DETACH(user_path_at)
#endif
#ifndef CAN_WRAP_pm_qos_add_request
#   define CAN_WRAP_pm_qos_add_request 1
#endif
#if CAN_WRAP_pm_qos_add_request
    WRAP_FOR_DETACH(pm_qos_add_request)
#endif
#ifndef CAN_WRAP_acpi_check_resource_conflict
#   define CAN_WRAP_acpi_check_resource_conflict 1
#endif
#if CAN_WRAP_acpi_check_resource_conflict
    WRAP_FOR_DETACH(acpi_check_resource_conflict)
#endif
#ifndef CAN_WRAP_cap_netlink_send
#   define CAN_WRAP_cap_netlink_send 1
#endif
#if CAN_WRAP_cap_netlink_send
    WRAP_FOR_DETACH(cap_netlink_send)
#endif
#ifndef CAN_WRAP_strcspn
#   define CAN_WRAP_strcspn 0
#endif
DETACH(strcspn)
#ifndef CAN_WRAP_bdi_has_dirty_io
#   define CAN_WRAP_bdi_has_dirty_io 1
#endif
#if CAN_WRAP_bdi_has_dirty_io
    WRAP_FOR_DETACH(bdi_has_dirty_io)
#endif
#ifndef CAN_WRAP___netlink_change_ngroups
#   define CAN_WRAP___netlink_change_ngroups 1
#endif
#if CAN_WRAP___netlink_change_ngroups
#   ifdef DETACH_ADDR___netlink_change_ngroups
        WRAP_FOR_DETACH(__netlink_change_ngroups)
#   else
        TYPED_DETACH(__netlink_change_ngroups)
#   endif
#endif
#ifndef CAN_WRAP_param_get_bool
#   define CAN_WRAP_param_get_bool 1
#endif
#if CAN_WRAP_param_get_bool
    WRAP_FOR_DETACH(param_get_bool)
#endif
#ifndef CAN_WRAP_acpi_dev_pm_detach
#   define CAN_WRAP_acpi_dev_pm_detach 1
#endif
#if CAN_WRAP_acpi_dev_pm_detach
    WRAP_FOR_DETACH(acpi_dev_pm_detach)
#endif
#ifndef CAN_WRAP_wmi_query_block
#   define CAN_WRAP_wmi_query_block 1
#endif
#if CAN_WRAP_wmi_query_block
    WRAP_FOR_DETACH(wmi_query_block)
#endif
#ifndef CAN_WRAP_paravirt_patch_default
#   define CAN_WRAP_paravirt_patch_default 0
#endif
DETACH(paravirt_patch_default)
#ifndef CAN_WRAP_napi_gro_flush
#   define CAN_WRAP_napi_gro_flush 1
#endif
#if CAN_WRAP_napi_gro_flush
    WRAP_FOR_DETACH(napi_gro_flush)
#endif
#ifndef CAN_WRAP_hrtimer_run_pending
#   define CAN_WRAP_hrtimer_run_pending 0
#endif
DETACH(hrtimer_run_pending)
#ifndef CAN_WRAP_rcu_idle_exit
#   define CAN_WRAP_rcu_idle_exit 0
#endif
DETACH(rcu_idle_exit)
#ifndef CAN_WRAP_mb_cache_shrink
#   define CAN_WRAP_mb_cache_shrink 1
#endif
#if CAN_WRAP_mb_cache_shrink
    WRAP_FOR_DETACH(mb_cache_shrink)
#endif
#ifndef CAN_WRAP_ktime_get_boottime
#   define CAN_WRAP_ktime_get_boottime 0
#endif
DETACH(ktime_get_boottime)
#ifndef CAN_WRAP_ata_qc_complete_multiple
#   define CAN_WRAP_ata_qc_complete_multiple 1
#endif
#if CAN_WRAP_ata_qc_complete_multiple
    WRAP_FOR_DETACH(ata_qc_complete_multiple)
#endif
#ifndef CAN_WRAP_blk_queue_softirq_done
#   define CAN_WRAP_blk_queue_softirq_done 1
#endif
#if CAN_WRAP_blk_queue_softirq_done
    WRAP_FOR_DETACH(blk_queue_softirq_done)
#endif
#ifndef CAN_WRAP_posix_acl_equiv_mode
#   define CAN_WRAP_posix_acl_equiv_mode 1
#endif
#if CAN_WRAP_posix_acl_equiv_mode
    WRAP_FOR_DETACH(posix_acl_equiv_mode)
#endif
#ifndef CAN_WRAP_cpumask_next_and
#   define CAN_WRAP_cpumask_next_and 1
#endif
#if CAN_WRAP_cpumask_next_and
    WRAP_FOR_DETACH(cpumask_next_and)
#endif
#ifndef CAN_WRAP_smp_spurious_interrupt
#   define CAN_WRAP_smp_spurious_interrupt 1
#endif
#if CAN_WRAP_smp_spurious_interrupt
    WRAP_FOR_DETACH(smp_spurious_interrupt)
#endif
#ifndef CAN_WRAP_security_bprm_committed_creds
#   define CAN_WRAP_security_bprm_committed_creds 1
#endif
#if CAN_WRAP_security_bprm_committed_creds
    WRAP_FOR_DETACH(security_bprm_committed_creds)
#endif
#ifndef CAN_WRAP___insert_inode_hash
#   define CAN_WRAP___insert_inode_hash 1
#endif
#if CAN_WRAP___insert_inode_hash
#   ifdef DETACH_ADDR___insert_inode_hash
        WRAP_FOR_DETACH(__insert_inode_hash)
#   else
        TYPED_DETACH(__insert_inode_hash)
#   endif
#endif
#ifndef CAN_WRAP__raw_spin_trylock_bh
#   define CAN_WRAP__raw_spin_trylock_bh 1
#endif
#if CAN_WRAP__raw_spin_trylock_bh
    WRAP_FOR_DETACH(_raw_spin_trylock_bh)
#endif
#ifndef CAN_WRAP_compat_sys_mq_timedreceive
#   define CAN_WRAP_compat_sys_mq_timedreceive 1
#endif
#if CAN_WRAP_compat_sys_mq_timedreceive
    WRAP_FOR_DETACH(compat_sys_mq_timedreceive)
#endif
#ifndef CAN_WRAP_scsi_unblock_requests
#   define CAN_WRAP_scsi_unblock_requests 1
#endif
#if CAN_WRAP_scsi_unblock_requests
    WRAP_FOR_DETACH(scsi_unblock_requests)
#endif
#ifndef CAN_WRAP_filemap_write_and_wait
#   define CAN_WRAP_filemap_write_and_wait 1
#endif
#if CAN_WRAP_filemap_write_and_wait
    WRAP_FOR_DETACH(filemap_write_and_wait)
#endif
#ifndef CAN_WRAP_compat_sys_socketcall
#   define CAN_WRAP_compat_sys_socketcall 0
#endif
DETACH(compat_sys_socketcall)
#ifndef CAN_WRAP_sched_dead
#   define CAN_WRAP_sched_dead 1
#endif
#if CAN_WRAP_sched_dead
    WRAP_FOR_DETACH(sched_dead)
#endif
#ifndef CAN_WRAP_track_pfn_remap
#   define CAN_WRAP_track_pfn_remap 1
#endif
#if CAN_WRAP_track_pfn_remap
    WRAP_FOR_DETACH(track_pfn_remap)
#endif
#ifndef CAN_WRAP_nla_reserve_nohdr
#   define CAN_WRAP_nla_reserve_nohdr 1
#endif
#if CAN_WRAP_nla_reserve_nohdr
    WRAP_FOR_DETACH(nla_reserve_nohdr)
#endif
#ifndef CAN_WRAP_security_sock_graft
#   define CAN_WRAP_security_sock_graft 1
#endif
#if CAN_WRAP_security_sock_graft
    WRAP_FOR_DETACH(security_sock_graft)
#endif
#ifndef CAN_WRAP_mempool_free
#   define CAN_WRAP_mempool_free 1
#endif
#if CAN_WRAP_mempool_free
    WRAP_FOR_DETACH(mempool_free)
#endif
#ifndef CAN_WRAP_unregister_hotplug_dock_device
#   define CAN_WRAP_unregister_hotplug_dock_device 0
#endif
DETACH(unregister_hotplug_dock_device)
#ifndef CAN_WRAP_dev_trans_start
#   define CAN_WRAP_dev_trans_start 1
#endif
#if CAN_WRAP_dev_trans_start
    WRAP_FOR_DETACH(dev_trans_start)
#endif
#ifndef CAN_WRAP_acpi_nvs_for_each_region
#   define CAN_WRAP_acpi_nvs_for_each_region 1
#endif
#if CAN_WRAP_acpi_nvs_for_each_region
    WRAP_FOR_DETACH(acpi_nvs_for_each_region)
#endif
#ifndef CAN_WRAP_wakeup_source_register
#   define CAN_WRAP_wakeup_source_register 1
#endif
#if CAN_WRAP_wakeup_source_register
    WRAP_FOR_DETACH(wakeup_source_register)
#endif
#ifndef CAN_WRAP_flush_signal_handlers
#   define CAN_WRAP_flush_signal_handlers 1
#endif
#if CAN_WRAP_flush_signal_handlers
    WRAP_FOR_DETACH(flush_signal_handlers)
#endif
#ifndef CAN_WRAP_thread_group_cputime
#   define CAN_WRAP_thread_group_cputime 1
#endif
#if CAN_WRAP_thread_group_cputime
    WRAP_FOR_DETACH(thread_group_cputime)
#endif
#ifndef CAN_WRAP_sync_inodes_sb
#   define CAN_WRAP_sync_inodes_sb 1
#endif
#if CAN_WRAP_sync_inodes_sb
    WRAP_FOR_DETACH(sync_inodes_sb)
#endif
#ifndef CAN_WRAP_acpi_dev_resource_interrupt
#   define CAN_WRAP_acpi_dev_resource_interrupt 1
#endif
#if CAN_WRAP_acpi_dev_resource_interrupt
    WRAP_FOR_DETACH(acpi_dev_resource_interrupt)
#endif
#ifndef CAN_WRAP_pci_enable_device_mem
#   define CAN_WRAP_pci_enable_device_mem 1
#endif
#if CAN_WRAP_pci_enable_device_mem
    WRAP_FOR_DETACH(pci_enable_device_mem)
#endif
#ifndef CAN_WRAP_disk_part_iter_next
#   define CAN_WRAP_disk_part_iter_next 1
#endif
#if CAN_WRAP_disk_part_iter_next
    WRAP_FOR_DETACH(disk_part_iter_next)
#endif
#ifndef CAN_WRAP_ata_scsi_queuecmd
#   define CAN_WRAP_ata_scsi_queuecmd 1
#endif
#if CAN_WRAP_ata_scsi_queuecmd
    WRAP_FOR_DETACH(ata_scsi_queuecmd)
#endif
#ifndef CAN_WRAP_free_init_pages
#   define CAN_WRAP_free_init_pages 0
#endif
DETACH(free_init_pages)
#ifndef CAN_WRAP___hw_addr_add_multiple
#   define CAN_WRAP___hw_addr_add_multiple 1
#endif
#if CAN_WRAP___hw_addr_add_multiple
#   ifdef DETACH_ADDR___hw_addr_add_multiple
        WRAP_FOR_DETACH(__hw_addr_add_multiple)
#   else
        TYPED_DETACH(__hw_addr_add_multiple)
#   endif
#endif
#ifndef CAN_WRAP_ata_dev_next
#   define CAN_WRAP_ata_dev_next 1
#endif
#if CAN_WRAP_ata_dev_next
    WRAP_FOR_DETACH(ata_dev_next)
#endif
#ifndef CAN_WRAP_rtnl_register
#   define CAN_WRAP_rtnl_register 1
#endif
#if CAN_WRAP_rtnl_register
    WRAP_FOR_DETACH(rtnl_register)
#endif
#ifndef CAN_WRAP_lock_may_read
#   define CAN_WRAP_lock_may_read 1
#endif
#if CAN_WRAP_lock_may_read
    WRAP_FOR_DETACH(lock_may_read)
#endif
#ifndef CAN_WRAP_generic_cont_expand_simple
#   define CAN_WRAP_generic_cont_expand_simple 1
#endif
#if CAN_WRAP_generic_cont_expand_simple
    WRAP_FOR_DETACH(generic_cont_expand_simple)
#endif
#ifndef CAN_WRAP___sock_recv_wifi_status
#   define CAN_WRAP___sock_recv_wifi_status 1
#endif
#if CAN_WRAP___sock_recv_wifi_status
#   ifdef DETACH_ADDR___sock_recv_wifi_status
        WRAP_FOR_DETACH(__sock_recv_wifi_status)
#   else
        TYPED_DETACH(__sock_recv_wifi_status)
#   endif
#endif
#ifndef CAN_WRAP_rt_mutex_trylock
#   define CAN_WRAP_rt_mutex_trylock 1
#endif
#if CAN_WRAP_rt_mutex_trylock
    WRAP_FOR_DETACH(rt_mutex_trylock)
#endif
#ifndef CAN_WRAP_dev_pm_qos_remove_notifier
#   define CAN_WRAP_dev_pm_qos_remove_notifier 1
#endif
#if CAN_WRAP_dev_pm_qos_remove_notifier
    WRAP_FOR_DETACH(dev_pm_qos_remove_notifier)
#endif
#ifndef CAN_WRAP_compat_sys_fcntl
#   define CAN_WRAP_compat_sys_fcntl 0
#endif
DETACH(compat_sys_fcntl)
#ifndef CAN_WRAP_input_ff_upload
#   define CAN_WRAP_input_ff_upload 1
#endif
#if CAN_WRAP_input_ff_upload
    WRAP_FOR_DETACH(input_ff_upload)
#endif
#ifndef CAN_WRAP_cgroup_is_descendant
#   define CAN_WRAP_cgroup_is_descendant 1
#endif
#if CAN_WRAP_cgroup_is_descendant
    WRAP_FOR_DETACH(cgroup_is_descendant)
#endif
#ifndef CAN_WRAP___ioapic_set_affinity
#   define CAN_WRAP___ioapic_set_affinity 1
#endif
#if CAN_WRAP___ioapic_set_affinity
#   ifdef DETACH_ADDR___ioapic_set_affinity
        WRAP_FOR_DETACH(__ioapic_set_affinity)
#   else
        TYPED_DETACH(__ioapic_set_affinity)
#   endif
#endif
#ifndef CAN_WRAP_pci_user_write_config_dword
#   define CAN_WRAP_pci_user_write_config_dword 1
#endif
#if CAN_WRAP_pci_user_write_config_dword
    WRAP_FOR_DETACH(pci_user_write_config_dword)
#endif
#ifndef CAN_WRAP_do_execve
#   define CAN_WRAP_do_execve 0
#endif
DETACH(do_execve)
#ifndef CAN_WRAP___dst_free
#   define CAN_WRAP___dst_free 1
#endif
#if CAN_WRAP___dst_free
#   ifdef DETACH_ADDR___dst_free
        WRAP_FOR_DETACH(__dst_free)
#   else
        TYPED_DETACH(__dst_free)
#   endif
#endif
#ifndef CAN_WRAP_jbd2_journal_release_jbd_inode
#   define CAN_WRAP_jbd2_journal_release_jbd_inode 1
#endif
#if CAN_WRAP_jbd2_journal_release_jbd_inode
    WRAP_FOR_DETACH(jbd2_journal_release_jbd_inode)
#endif
#ifndef CAN_WRAP_kstrtos8
#   define CAN_WRAP_kstrtos8 0
#endif
DETACH(kstrtos8)
#ifndef CAN_WRAP___pskb_copy
#   define CAN_WRAP___pskb_copy 1
#endif
#if CAN_WRAP___pskb_copy
#   ifdef DETACH_ADDR___pskb_copy
        WRAP_FOR_DETACH(__pskb_copy)
#   else
        TYPED_DETACH(__pskb_copy)
#   endif
#endif
#ifndef CAN_WRAP_dev_ioctl
#   define CAN_WRAP_dev_ioctl 1
#endif
#if CAN_WRAP_dev_ioctl
    WRAP_FOR_DETACH(dev_ioctl)
#endif
#ifndef CAN_WRAP_pci_enable_ido
#   define CAN_WRAP_pci_enable_ido 1
#endif
#if CAN_WRAP_pci_enable_ido
    WRAP_FOR_DETACH(pci_enable_ido)
#endif
#ifndef CAN_WRAP_mount_pseudo
#   define CAN_WRAP_mount_pseudo 1
#endif
#if CAN_WRAP_mount_pseudo
    WRAP_FOR_DETACH(mount_pseudo)
#endif
#ifndef CAN_WRAP_sk_filter
#   define CAN_WRAP_sk_filter 1
#endif
#if CAN_WRAP_sk_filter
    WRAP_FOR_DETACH(sk_filter)
#endif
#ifndef CAN_WRAP_show_regs
#   define CAN_WRAP_show_regs 1
#endif
#if CAN_WRAP_show_regs
    WRAP_FOR_DETACH(show_regs)
#endif
#ifndef CAN_WRAP_is_kernel_percpu_address
#   define CAN_WRAP_is_kernel_percpu_address 0
#endif
DETACH(is_kernel_percpu_address)
#ifndef CAN_WRAP___cleancache_put_page
#   define CAN_WRAP___cleancache_put_page 1
#endif
#if CAN_WRAP___cleancache_put_page
#   ifdef DETACH_ADDR___cleancache_put_page
        WRAP_FOR_DETACH(__cleancache_put_page)
#   else
        TYPED_DETACH(__cleancache_put_page)
#   endif
#endif
#ifndef CAN_WRAP_dev_mc_add_global
#   define CAN_WRAP_dev_mc_add_global 1
#endif
#if CAN_WRAP_dev_mc_add_global
    WRAP_FOR_DETACH(dev_mc_add_global)
#endif
#ifndef CAN_WRAP_dm_put
#   define CAN_WRAP_dm_put 1
#endif
#if CAN_WRAP_dm_put
    WRAP_FOR_DETACH(dm_put)
#endif
#ifndef CAN_WRAP_sch_direct_xmit
#   define CAN_WRAP_sch_direct_xmit 1
#endif
#if CAN_WRAP_sch_direct_xmit
    WRAP_FOR_DETACH(sch_direct_xmit)
#endif
#ifndef CAN_WRAP___next_cpu_nr
#   define CAN_WRAP___next_cpu_nr 1
#endif
#if CAN_WRAP___next_cpu_nr
#   ifdef DETACH_ADDR___next_cpu_nr
        WRAP_FOR_DETACH(__next_cpu_nr)
#   else
        TYPED_DETACH(__next_cpu_nr)
#   endif
#endif
#ifndef CAN_WRAP_rtnl_unregister
#   define CAN_WRAP_rtnl_unregister 0
#endif
DETACH(rtnl_unregister)
#ifndef CAN_WRAP_get_kernel_pages
#   define CAN_WRAP_get_kernel_pages 1
#endif
#if CAN_WRAP_get_kernel_pages
    WRAP_FOR_DETACH(get_kernel_pages)
#endif
#ifndef CAN_WRAP_security_sb_show_options
#   define CAN_WRAP_security_sb_show_options 1
#endif
#if CAN_WRAP_security_sb_show_options
    WRAP_FOR_DETACH(security_sb_show_options)
#endif
#ifndef CAN_WRAP_prop_local_destroy_percpu
#   define CAN_WRAP_prop_local_destroy_percpu 1
#endif
#if CAN_WRAP_prop_local_destroy_percpu
    WRAP_FOR_DETACH(prop_local_destroy_percpu)
#endif
#ifndef CAN_WRAP_acpi_subsys_suspend_late
#   define CAN_WRAP_acpi_subsys_suspend_late 1
#endif
#if CAN_WRAP_acpi_subsys_suspend_late
    WRAP_FOR_DETACH(acpi_subsys_suspend_late)
#endif
#ifndef CAN_WRAP_hrtimer_nanosleep_restart
#   define CAN_WRAP_hrtimer_nanosleep_restart 1
#endif
#if CAN_WRAP_hrtimer_nanosleep_restart
    WRAP_FOR_DETACH(hrtimer_nanosleep_restart)
#endif
#ifndef CAN_WRAP_security_audit_rule_known
#   define CAN_WRAP_security_audit_rule_known 1
#endif
#if CAN_WRAP_security_audit_rule_known
    WRAP_FOR_DETACH(security_audit_rule_known)
#endif
#ifndef CAN_WRAP_round_jiffies_up
#   define CAN_WRAP_round_jiffies_up 0
#endif
DETACH(round_jiffies_up)
#ifndef CAN_WRAP_sysfs_create_group
#   define CAN_WRAP_sysfs_create_group 1
#endif
#if CAN_WRAP_sysfs_create_group
    WRAP_FOR_DETACH(sysfs_create_group)
#endif
#ifndef CAN_WRAP_vmalloc_to_pfn
#   define CAN_WRAP_vmalloc_to_pfn 0
#endif
DETACH(vmalloc_to_pfn)
#ifndef CAN_WRAP_dev_mc_flush
#   define CAN_WRAP_dev_mc_flush 1
#endif
#if CAN_WRAP_dev_mc_flush
    WRAP_FOR_DETACH(dev_mc_flush)
#endif
#ifndef CAN_WRAP_netlink_clear_multicast_users
#   define CAN_WRAP_netlink_clear_multicast_users 1
#endif
#if CAN_WRAP_netlink_clear_multicast_users
    WRAP_FOR_DETACH(netlink_clear_multicast_users)
#endif
#ifndef CAN_WRAP_input_inject_event
#   define CAN_WRAP_input_inject_event 1
#endif
#if CAN_WRAP_input_inject_event
    WRAP_FOR_DETACH(input_inject_event)
#endif
#ifndef CAN_WRAP_seq_list_start
#   define CAN_WRAP_seq_list_start 1
#endif
#if CAN_WRAP_seq_list_start
    WRAP_FOR_DETACH(seq_list_start)
#endif
#ifndef CAN_WRAP_bsg_unregister_queue
#   define CAN_WRAP_bsg_unregister_queue 1
#endif
#if CAN_WRAP_bsg_unregister_queue
    WRAP_FOR_DETACH(bsg_unregister_queue)
#endif
#ifndef CAN_WRAP_pvclock_init_vsyscall
#   define CAN_WRAP_pvclock_init_vsyscall 1
#endif
#if CAN_WRAP_pvclock_init_vsyscall
    WRAP_FOR_DETACH(pvclock_init_vsyscall)
#endif
#ifndef CAN_WRAP_dup_mm
#   define CAN_WRAP_dup_mm 1
#endif
#if CAN_WRAP_dup_mm
    WRAP_FOR_DETACH(dup_mm)
#endif
#ifndef CAN_WRAP_lookup_module_symbol_attrs
#   define CAN_WRAP_lookup_module_symbol_attrs 0
#endif
DETACH(lookup_module_symbol_attrs)
#ifndef CAN_WRAP_security_socket_getsockopt
#   define CAN_WRAP_security_socket_getsockopt 1
#endif
#if CAN_WRAP_security_socket_getsockopt
    WRAP_FOR_DETACH(security_socket_getsockopt)
#endif
#ifndef CAN_WRAP_update_cpu_load_nohz
#   define CAN_WRAP_update_cpu_load_nohz 0
#endif
DETACH(update_cpu_load_nohz)
#ifndef CAN_WRAP_fcntl_setlease
#   define CAN_WRAP_fcntl_setlease 1
#endif
#if CAN_WRAP_fcntl_setlease
    WRAP_FOR_DETACH(fcntl_setlease)
#endif
#ifndef CAN_WRAP_kill_bdev
#   define CAN_WRAP_kill_bdev 1
#endif
#if CAN_WRAP_kill_bdev
    WRAP_FOR_DETACH(kill_bdev)
#endif
#ifndef CAN_WRAP_pci_set_dma_max_seg_size
#   define CAN_WRAP_pci_set_dma_max_seg_size 1
#endif
#if CAN_WRAP_pci_set_dma_max_seg_size
    WRAP_FOR_DETACH(pci_set_dma_max_seg_size)
#endif
#ifndef CAN_WRAP_set_anon_super
#   define CAN_WRAP_set_anon_super 1
#endif
#if CAN_WRAP_set_anon_super
    WRAP_FOR_DETACH(set_anon_super)
#endif
#ifndef CAN_WRAP___breadahead
#   define CAN_WRAP___breadahead 1
#endif
#if CAN_WRAP___breadahead
#   ifdef DETACH_ADDR___breadahead
        WRAP_FOR_DETACH(__breadahead)
#   else
        TYPED_DETACH(__breadahead)
#   endif
#endif
#ifndef CAN_WRAP_sched_group_shares
#   define CAN_WRAP_sched_group_shares 1
#endif
#if CAN_WRAP_sched_group_shares
    WRAP_FOR_DETACH(sched_group_shares)
#endif
#ifndef CAN_WRAP_sched_group_rt_runtime
#   define CAN_WRAP_sched_group_rt_runtime 1
#endif
#if CAN_WRAP_sched_group_rt_runtime
    WRAP_FOR_DETACH(sched_group_rt_runtime)
#endif
#ifndef CAN_WRAP_skb_morph
#   define CAN_WRAP_skb_morph 1
#endif
#if CAN_WRAP_skb_morph
    WRAP_FOR_DETACH(skb_morph)
#endif
#ifndef CAN_WRAP_rtnl_trylock
#   define CAN_WRAP_rtnl_trylock 0
#endif
DETACH(rtnl_trylock)
#ifndef CAN_WRAP_register_sysctl_table
#   define CAN_WRAP_register_sysctl_table 1
#endif
#if CAN_WRAP_register_sysctl_table
    WRAP_FOR_DETACH(register_sysctl_table)
#endif
#ifndef CAN_WRAP_set_memory_wc
#   define CAN_WRAP_set_memory_wc 0
#endif
DETACH(set_memory_wc)
#ifndef CAN_WRAP_set_memory_wb
#   define CAN_WRAP_set_memory_wb 0
#endif
DETACH(set_memory_wb)
#ifndef CAN_WRAP_iget_failed
#   define CAN_WRAP_iget_failed 1
#endif
#if CAN_WRAP_iget_failed
    WRAP_FOR_DETACH(iget_failed)
#endif
#ifndef CAN_WRAP_pci_intx_mask_supported
#   define CAN_WRAP_pci_intx_mask_supported 1
#endif
#if CAN_WRAP_pci_intx_mask_supported
    WRAP_FOR_DETACH(pci_intx_mask_supported)
#endif
#ifndef CAN_WRAP_cpu_set_gdt
#   define CAN_WRAP_cpu_set_gdt 0
#endif
DETACH(cpu_set_gdt)
#ifndef CAN_WRAP_show_interrupts
#   define CAN_WRAP_show_interrupts 1
#endif
#if CAN_WRAP_show_interrupts
    WRAP_FOR_DETACH(show_interrupts)
#endif
#ifndef CAN_WRAP_dm_table_add_target
#   define CAN_WRAP_dm_table_add_target 1
#endif
#if CAN_WRAP_dm_table_add_target
    WRAP_FOR_DETACH(dm_table_add_target)
#endif
#ifndef CAN_WRAP_proc_dointvec_jiffies
#   define CAN_WRAP_proc_dointvec_jiffies 1
#endif
#if CAN_WRAP_proc_dointvec_jiffies
    WRAP_FOR_DETACH(proc_dointvec_jiffies)
#endif
#ifndef CAN_WRAP_jbd2_journal_init_dev
#   define CAN_WRAP_jbd2_journal_init_dev 1
#endif
#if CAN_WRAP_jbd2_journal_init_dev
    WRAP_FOR_DETACH(jbd2_journal_init_dev)
#endif
#ifndef CAN_WRAP_noop_llseek
#   define CAN_WRAP_noop_llseek 1
#endif
#if CAN_WRAP_noop_llseek
    WRAP_FOR_DETACH(noop_llseek)
#endif
#ifndef CAN_WRAP_smp_call_function_any
#   define CAN_WRAP_smp_call_function_any 1
#endif
#if CAN_WRAP_smp_call_function_any
    WRAP_FOR_DETACH(smp_call_function_any)
#endif
#ifndef CAN_WRAP_strncpy_from_user
#   define CAN_WRAP_strncpy_from_user 0
#endif
DETACH(strncpy_from_user)
#ifndef CAN_WRAP_sysctl_min_slab_ratio_sysctl_handler
#   define CAN_WRAP_sysctl_min_slab_ratio_sysctl_handler 1
#endif
#if CAN_WRAP_sysctl_min_slab_ratio_sysctl_handler
    WRAP_FOR_DETACH(sysctl_min_slab_ratio_sysctl_handler)
#endif
#ifndef CAN_WRAP_dev_addr_add_multiple
#   define CAN_WRAP_dev_addr_add_multiple 1
#endif
#if CAN_WRAP_dev_addr_add_multiple
    WRAP_FOR_DETACH(dev_addr_add_multiple)
#endif
#ifndef CAN_WRAP_do_set_thread_area
#   define CAN_WRAP_do_set_thread_area 1
#endif
#if CAN_WRAP_do_set_thread_area
    WRAP_FOR_DETACH(do_set_thread_area)
#endif
#ifndef CAN_WRAP_sock_get_timestamp
#   define CAN_WRAP_sock_get_timestamp 1
#endif
#if CAN_WRAP_sock_get_timestamp
    WRAP_FOR_DETACH(sock_get_timestamp)
#endif
#ifndef CAN_WRAP_input_release_device
#   define CAN_WRAP_input_release_device 1
#endif
#if CAN_WRAP_input_release_device
    WRAP_FOR_DETACH(input_release_device)
#endif
#ifndef CAN_WRAP_ioremap_change_attr
#   define CAN_WRAP_ioremap_change_attr 0
#endif
DETACH(ioremap_change_attr)
#ifndef CAN_WRAP_rcu_init
#   define CAN_WRAP_rcu_init 0
#endif
DETACH(rcu_init)
#ifndef CAN_WRAP_phy_detach
#   define CAN_WRAP_phy_detach 1
#endif
#if CAN_WRAP_phy_detach
    WRAP_FOR_DETACH(phy_detach)
#endif
#ifndef CAN_WRAP_scsi_remove_host
#   define CAN_WRAP_scsi_remove_host 1
#endif
#if CAN_WRAP_scsi_remove_host
    WRAP_FOR_DETACH(scsi_remove_host)
#endif
#ifndef CAN_WRAP_dev_deactivate
#   define CAN_WRAP_dev_deactivate 1
#endif
#if CAN_WRAP_dev_deactivate
    WRAP_FOR_DETACH(dev_deactivate)
#endif
#ifndef CAN_WRAP_jbd2_log_start_commit
#   define CAN_WRAP_jbd2_log_start_commit 1
#endif
#if CAN_WRAP_jbd2_log_start_commit
    WRAP_FOR_DETACH(jbd2_log_start_commit)
#endif
#ifndef CAN_WRAP_swapcache_free
#   define CAN_WRAP_swapcache_free 1
#endif
#if CAN_WRAP_swapcache_free
    WRAP_FOR_DETACH(swapcache_free)
#endif
#ifndef CAN_WRAP_register_cpu_under_node
#   define CAN_WRAP_register_cpu_under_node 0
#endif
DETACH(register_cpu_under_node)
#ifndef CAN_WRAP_get_phy_device
#   define CAN_WRAP_get_phy_device 1
#endif
#if CAN_WRAP_get_phy_device
    WRAP_FOR_DETACH(get_phy_device)
#endif
#ifndef CAN_WRAP_blk_alloc_queue
#   define CAN_WRAP_blk_alloc_queue 1
#endif
#if CAN_WRAP_blk_alloc_queue
    WRAP_FOR_DETACH(blk_alloc_queue)
#endif
#ifndef CAN_WRAP___bad_gid
#   define CAN_WRAP___bad_gid 0
#endif
DETACH(__bad_gid)
#ifndef CAN_WRAP_acpi_numa_memory_affinity_init
#   define CAN_WRAP_acpi_numa_memory_affinity_init 1
#endif
#if CAN_WRAP_acpi_numa_memory_affinity_init
    WRAP_FOR_DETACH(acpi_numa_memory_affinity_init)
#endif
#ifndef CAN_WRAP_jbd2_journal_invalidatepage
#   define CAN_WRAP_jbd2_journal_invalidatepage 1
#endif
#if CAN_WRAP_jbd2_journal_invalidatepage
    WRAP_FOR_DETACH(jbd2_journal_invalidatepage)
#endif
#ifndef CAN_WRAP_sysfs_get_dirent
#   define CAN_WRAP_sysfs_get_dirent 1
#endif
#if CAN_WRAP_sysfs_get_dirent
    WRAP_FOR_DETACH(sysfs_get_dirent)
#endif
#ifndef CAN_WRAP_device_create
#   define CAN_WRAP_device_create 1
#endif
#if CAN_WRAP_device_create
    WRAP_FOR_DETACH(device_create)
#endif
#ifndef CAN_WRAP_register_netdevice_notifier
#   define CAN_WRAP_register_netdevice_notifier 1
#endif
#if CAN_WRAP_register_netdevice_notifier
    WRAP_FOR_DETACH(register_netdevice_notifier)
#endif
#ifndef CAN_WRAP_generic_file_remap_pages
#   define CAN_WRAP_generic_file_remap_pages 1
#endif
#if CAN_WRAP_generic_file_remap_pages
    WRAP_FOR_DETACH(generic_file_remap_pages)
#endif
#ifndef CAN_WRAP_jbd2_journal_next_log_block
#   define CAN_WRAP_jbd2_journal_next_log_block 1
#endif
#if CAN_WRAP_jbd2_journal_next_log_block
    WRAP_FOR_DETACH(jbd2_journal_next_log_block)
#endif
#ifndef CAN_WRAP_simple_statfs
#   define CAN_WRAP_simple_statfs 1
#endif
#if CAN_WRAP_simple_statfs
    WRAP_FOR_DETACH(simple_statfs)
#endif
#ifndef CAN_WRAP_tick_cancel_sched_timer
#   define CAN_WRAP_tick_cancel_sched_timer 0
#endif
DETACH(tick_cancel_sched_timer)
#ifndef CAN_WRAP_send_sigio
#   define CAN_WRAP_send_sigio 1
#endif
#if CAN_WRAP_send_sigio
    WRAP_FOR_DETACH(send_sigio)
#endif
#ifndef CAN_WRAP_simple_fill_super
#   define CAN_WRAP_simple_fill_super 1
#endif
#if CAN_WRAP_simple_fill_super
    WRAP_FOR_DETACH(simple_fill_super)
#endif
#ifndef CAN_WRAP_acpi_bus_set_power
#   define CAN_WRAP_acpi_bus_set_power 0
#endif
DETACH(acpi_bus_set_power)
#ifndef CAN_WRAP_dev_set_mtu
#   define CAN_WRAP_dev_set_mtu 1
#endif
#if CAN_WRAP_dev_set_mtu
    WRAP_FOR_DETACH(dev_set_mtu)
#endif
#ifndef CAN_WRAP___dev_remove_offload
#   define CAN_WRAP___dev_remove_offload 1
#endif
#if CAN_WRAP___dev_remove_offload
#   ifdef DETACH_ADDR___dev_remove_offload
        WRAP_FOR_DETACH(__dev_remove_offload)
#   else
        TYPED_DETACH(__dev_remove_offload)
#   endif
#endif
#ifndef CAN_WRAP_acpi_os_redirect_output
#   define CAN_WRAP_acpi_os_redirect_output 0
#endif
DETACH(acpi_os_redirect_output)
#ifndef CAN_WRAP_dev_change_flags
#   define CAN_WRAP_dev_change_flags 1
#endif
#if CAN_WRAP_dev_change_flags
    WRAP_FOR_DETACH(dev_change_flags)
#endif
#ifndef CAN_WRAP_pcibios_set_pcie_reset_state
#   define CAN_WRAP_pcibios_set_pcie_reset_state 1
#endif
#if CAN_WRAP_pcibios_set_pcie_reset_state
    WRAP_FOR_DETACH(pcibios_set_pcie_reset_state)
#endif
#ifndef CAN_WRAP_unregister_qdisc
#   define CAN_WRAP_unregister_qdisc 1
#endif
#if CAN_WRAP_unregister_qdisc
    WRAP_FOR_DETACH(unregister_qdisc)
#endif
#ifndef CAN_WRAP_ata_port_wait_eh
#   define CAN_WRAP_ata_port_wait_eh 1
#endif
#if CAN_WRAP_ata_port_wait_eh
    WRAP_FOR_DETACH(ata_port_wait_eh)
#endif
#ifndef CAN_WRAP_security_tun_dev_attach
#   define CAN_WRAP_security_tun_dev_attach 1
#endif
#if CAN_WRAP_security_tun_dev_attach
    WRAP_FOR_DETACH(security_tun_dev_attach)
#endif
#ifndef CAN_WRAP_groups_free
#   define CAN_WRAP_groups_free 1
#endif
#if CAN_WRAP_groups_free
    WRAP_FOR_DETACH(groups_free)
#endif
#ifndef CAN_WRAP_split_vma
#   define CAN_WRAP_split_vma 1
#endif
#if CAN_WRAP_split_vma
    WRAP_FOR_DETACH(split_vma)
#endif
#ifndef CAN_WRAP_ata_dev_pair
#   define CAN_WRAP_ata_dev_pair 1
#endif
#if CAN_WRAP_ata_dev_pair
    WRAP_FOR_DETACH(ata_dev_pair)
#endif
#ifndef CAN_WRAP_generic_delete_inode
#   define CAN_WRAP_generic_delete_inode 1
#endif
#if CAN_WRAP_generic_delete_inode
    WRAP_FOR_DETACH(generic_delete_inode)
#endif
#ifndef CAN_WRAP_mempool_create_node
#   define CAN_WRAP_mempool_create_node 1
#endif
#if CAN_WRAP_mempool_create_node
    WRAP_FOR_DETACH(mempool_create_node)
#endif
#ifndef CAN_WRAP_memcpy_fromiovecend
#   define CAN_WRAP_memcpy_fromiovecend 1
#endif
#if CAN_WRAP_memcpy_fromiovecend
    WRAP_FOR_DETACH(memcpy_fromiovecend)
#endif
#ifndef CAN_WRAP_apic_send_IPI_self
#   define CAN_WRAP_apic_send_IPI_self 0
#endif
DETACH(apic_send_IPI_self)
#ifndef CAN_WRAP_bus_get_device_klist
#   define CAN_WRAP_bus_get_device_klist 1
#endif
#if CAN_WRAP_bus_get_device_klist
    WRAP_FOR_DETACH(bus_get_device_klist)
#endif
#ifndef CAN_WRAP_seq_dentry
#   define CAN_WRAP_seq_dentry 1
#endif
#if CAN_WRAP_seq_dentry
    WRAP_FOR_DETACH(seq_dentry)
#endif
#ifndef CAN_WRAP_invalidate_interrupt
#   define CAN_WRAP_invalidate_interrupt 0
#endif
DETACH(invalidate_interrupt)
#ifndef CAN_WRAP_compat_arch_ptrace
#   define CAN_WRAP_compat_arch_ptrace 1
#endif
#if CAN_WRAP_compat_arch_ptrace
    WRAP_FOR_DETACH(compat_arch_ptrace)
#endif
#ifndef CAN_WRAP_rt_mutex_setprio
#   define CAN_WRAP_rt_mutex_setprio 1
#endif
#if CAN_WRAP_rt_mutex_setprio
    WRAP_FOR_DETACH(rt_mutex_setprio)
#endif
#ifndef CAN_WRAP_jbd2__journal_start
#   define CAN_WRAP_jbd2__journal_start 1
#endif
#if CAN_WRAP_jbd2__journal_start
    WRAP_FOR_DETACH(jbd2__journal_start)
#endif
#ifndef CAN_WRAP_pcibios_enable_device
#   define CAN_WRAP_pcibios_enable_device 1
#endif
#if CAN_WRAP_pcibios_enable_device
    WRAP_FOR_DETACH(pcibios_enable_device)
#endif
#ifndef CAN_WRAP_acpi_set_gpe_wake_mask
#   define CAN_WRAP_acpi_set_gpe_wake_mask 0
#endif
DETACH(acpi_set_gpe_wake_mask)
#ifndef CAN_WRAP_jbd2_journal_set_features
#   define CAN_WRAP_jbd2_journal_set_features 1
#endif
#if CAN_WRAP_jbd2_journal_set_features
    WRAP_FOR_DETACH(jbd2_journal_set_features)
#endif
#ifndef CAN_WRAP_vfs_readdir
#   define CAN_WRAP_vfs_readdir 1
#endif
#if CAN_WRAP_vfs_readdir
    WRAP_FOR_DETACH(vfs_readdir)
#endif
#ifndef CAN_WRAP_bitmap_find_free_region
#   define CAN_WRAP_bitmap_find_free_region 0
#endif
DETACH(bitmap_find_free_region)
#ifndef CAN_WRAP_netdev_change_features
#   define CAN_WRAP_netdev_change_features 1
#endif
#if CAN_WRAP_netdev_change_features
    WRAP_FOR_DETACH(netdev_change_features)
#endif
#ifndef CAN_WRAP_fprop_global_init
#   define CAN_WRAP_fprop_global_init 1
#endif
#if CAN_WRAP_fprop_global_init
    WRAP_FOR_DETACH(fprop_global_init)
#endif
#ifndef CAN_WRAP_send_sigqueue
#   define CAN_WRAP_send_sigqueue 1
#endif
#if CAN_WRAP_send_sigqueue
    WRAP_FOR_DETACH(send_sigqueue)
#endif
#ifndef CAN_WRAP_pci_create_slot
#   define CAN_WRAP_pci_create_slot 1
#endif
#if CAN_WRAP_pci_create_slot
    WRAP_FOR_DETACH(pci_create_slot)
#endif
#ifndef CAN_WRAP_get_max_files
#   define CAN_WRAP_get_max_files 0
#endif
DETACH(get_max_files)
#ifndef CAN_WRAP_pci_bus_write_config_byte
#   define CAN_WRAP_pci_bus_write_config_byte 1
#endif
#if CAN_WRAP_pci_bus_write_config_byte
    WRAP_FOR_DETACH(pci_bus_write_config_byte)
#endif
#ifndef CAN_WRAP_compat_sys_get_mempolicy
#   define CAN_WRAP_compat_sys_get_mempolicy 0
#endif
DETACH(compat_sys_get_mempolicy)
#ifndef CAN_WRAP_free_initmem
#   define CAN_WRAP_free_initmem 0
#endif
DETACH(free_initmem)
#ifndef CAN_WRAP_mdiobus_register
#   define CAN_WRAP_mdiobus_register 1
#endif
#if CAN_WRAP_mdiobus_register
    WRAP_FOR_DETACH(mdiobus_register)
#endif
#ifndef CAN_WRAP_res_counter_uncharge_locked
#   define CAN_WRAP_res_counter_uncharge_locked 1
#endif
#if CAN_WRAP_res_counter_uncharge_locked
    WRAP_FOR_DETACH(res_counter_uncharge_locked)
#endif
#ifndef CAN_WRAP_dquot_quota_off
#   define CAN_WRAP_dquot_quota_off 1
#endif
#if CAN_WRAP_dquot_quota_off
    WRAP_FOR_DETACH(dquot_quota_off)
#endif
#ifndef CAN_WRAP_dec_zone_state
#   define CAN_WRAP_dec_zone_state 1
#endif
#if CAN_WRAP_dec_zone_state
    WRAP_FOR_DETACH(dec_zone_state)
#endif
#ifndef CAN_WRAP_sock_no_ioctl
#   define CAN_WRAP_sock_no_ioctl 1
#endif
#if CAN_WRAP_sock_no_ioctl
    WRAP_FOR_DETACH(sock_no_ioctl)
#endif
#ifndef CAN_WRAP_tick_setup_sched_timer
#   define CAN_WRAP_tick_setup_sched_timer 0
#endif
DETACH(tick_setup_sched_timer)
#ifndef CAN_WRAP_set_pages_wb
#   define CAN_WRAP_set_pages_wb 1
#endif
#if CAN_WRAP_set_pages_wb
    WRAP_FOR_DETACH(set_pages_wb)
#endif
#ifndef CAN_WRAP_vfs_path_lookup
#   define CAN_WRAP_vfs_path_lookup 1
#endif
#if CAN_WRAP_vfs_path_lookup
    WRAP_FOR_DETACH(vfs_path_lookup)
#endif
#ifndef CAN_WRAP_dm_get_device
#   define CAN_WRAP_dm_get_device 1
#endif
#if CAN_WRAP_dm_get_device
    WRAP_FOR_DETACH(dm_get_device)
#endif
#ifndef CAN_WRAP_netdev_rx_csum_fault
#   define CAN_WRAP_netdev_rx_csum_fault 1
#endif
#if CAN_WRAP_netdev_rx_csum_fault
    WRAP_FOR_DETACH(netdev_rx_csum_fault)
#endif
#ifndef CAN_WRAP_sysfs_update_group
#   define CAN_WRAP_sysfs_update_group 1
#endif
#if CAN_WRAP_sysfs_update_group
    WRAP_FOR_DETACH(sysfs_update_group)
#endif
#ifndef CAN_WRAP_init_apic_mappings
#   define CAN_WRAP_init_apic_mappings 0
#endif
DETACH(init_apic_mappings)
#ifndef CAN_WRAP___bad_percpu_size
#   define CAN_WRAP___bad_percpu_size 0
#endif
DETACH(__bad_percpu_size)
#ifndef CAN_WRAP_compat_get_timeval
#   define CAN_WRAP_compat_get_timeval 1
#endif
#if CAN_WRAP_compat_get_timeval
    WRAP_FOR_DETACH(compat_get_timeval)
#endif
#ifndef CAN_WRAP_seq_path_root
#   define CAN_WRAP_seq_path_root 1
#endif
#if CAN_WRAP_seq_path_root
    WRAP_FOR_DETACH(seq_path_root)
#endif
#ifndef CAN_WRAP_reserve_region_with_split
#   define CAN_WRAP_reserve_region_with_split 1
#endif
#if CAN_WRAP_reserve_region_with_split
    WRAP_FOR_DETACH(reserve_region_with_split)
#endif
#ifndef CAN_WRAP_ata_sff_drain_fifo
#   define CAN_WRAP_ata_sff_drain_fifo 1
#endif
#if CAN_WRAP_ata_sff_drain_fifo
    WRAP_FOR_DETACH(ata_sff_drain_fifo)
#endif
#ifndef CAN_WRAP_qdisc_create_dflt
#   define CAN_WRAP_qdisc_create_dflt 1
#endif
#if CAN_WRAP_qdisc_create_dflt
    WRAP_FOR_DETACH(qdisc_create_dflt)
#endif
#ifndef CAN_WRAP___d_path
#   define CAN_WRAP___d_path 1
#endif
#if CAN_WRAP___d_path
#   ifdef DETACH_ADDR___d_path
        WRAP_FOR_DETACH(__d_path)
#   else
        TYPED_DETACH(__d_path)
#   endif
#endif
#ifndef CAN_WRAP___sk_backlog_rcv
#   define CAN_WRAP___sk_backlog_rcv 1
#endif
#if CAN_WRAP___sk_backlog_rcv
#   ifdef DETACH_ADDR___sk_backlog_rcv
        WRAP_FOR_DETACH(__sk_backlog_rcv)
#   else
        TYPED_DETACH(__sk_backlog_rcv)
#   endif
#endif
#ifndef CAN_WRAP_security_mmap_file
#   define CAN_WRAP_security_mmap_file 1
#endif
#if CAN_WRAP_security_mmap_file
    WRAP_FOR_DETACH(security_mmap_file)
#endif
#ifndef CAN_WRAP_init_timers
#   define CAN_WRAP_init_timers 0
#endif
DETACH(init_timers)
#ifndef CAN_WRAP_get_net_ns_by_fd
#   define CAN_WRAP_get_net_ns_by_fd 1
#endif
#if CAN_WRAP_get_net_ns_by_fd
    WRAP_FOR_DETACH(get_net_ns_by_fd)
#endif
#ifndef CAN_WRAP___dev_set_rx_mode
#   define CAN_WRAP___dev_set_rx_mode 1
#endif
#if CAN_WRAP___dev_set_rx_mode
#   ifdef DETACH_ADDR___dev_set_rx_mode
        WRAP_FOR_DETACH(__dev_set_rx_mode)
#   else
        TYPED_DETACH(__dev_set_rx_mode)
#   endif
#endif
#ifndef CAN_WRAP_pcim_iomap_table
#   define CAN_WRAP_pcim_iomap_table 1
#endif
#if CAN_WRAP_pcim_iomap_table
    WRAP_FOR_DETACH(pcim_iomap_table)
#endif
#ifndef CAN_WRAP_idr_init_cache
#   define CAN_WRAP_idr_init_cache 0
#endif
DETACH(idr_init_cache)
#ifndef CAN_WRAP_skb_unlink
#   define CAN_WRAP_skb_unlink 1
#endif
#if CAN_WRAP_skb_unlink
    WRAP_FOR_DETACH(skb_unlink)
#endif
#ifndef CAN_WRAP_ata_pci_sff_init_one
#   define CAN_WRAP_ata_pci_sff_init_one 1
#endif
#if CAN_WRAP_ata_pci_sff_init_one
    WRAP_FOR_DETACH(ata_pci_sff_init_one)
#endif
#ifndef CAN_WRAP_irq_gc_mask_disable_reg
#   define CAN_WRAP_irq_gc_mask_disable_reg 1
#endif
#if CAN_WRAP_irq_gc_mask_disable_reg
    WRAP_FOR_DETACH(irq_gc_mask_disable_reg)
#endif
#ifndef CAN_WRAP_acpi_os_acquire_object
#   define CAN_WRAP_acpi_os_acquire_object 1
#endif
#if CAN_WRAP_acpi_os_acquire_object
    WRAP_FOR_DETACH(acpi_os_acquire_object)
#endif
#ifndef CAN_WRAP_acpi_bus_receive_event
#   define CAN_WRAP_acpi_bus_receive_event 1
#endif
#if CAN_WRAP_acpi_bus_receive_event
    WRAP_FOR_DETACH(acpi_bus_receive_event)
#endif
#ifndef CAN_WRAP_nla_strcmp
#   define CAN_WRAP_nla_strcmp 1
#endif
#if CAN_WRAP_nla_strcmp
    WRAP_FOR_DETACH(nla_strcmp)
#endif
#ifndef CAN_WRAP_reset_security_ops
#   define CAN_WRAP_reset_security_ops 0
#endif
DETACH(reset_security_ops)
#ifndef CAN_WRAP_rdmsr_on_cpus
#   define CAN_WRAP_rdmsr_on_cpus 1
#endif
#if CAN_WRAP_rdmsr_on_cpus
    WRAP_FOR_DETACH(rdmsr_on_cpus)
#endif
#ifndef CAN_WRAP_d_instantiate_unique
#   define CAN_WRAP_d_instantiate_unique 1
#endif
#if CAN_WRAP_d_instantiate_unique
    WRAP_FOR_DETACH(d_instantiate_unique)
#endif
#ifndef CAN_WRAP_create_proc_entry
#   define CAN_WRAP_create_proc_entry 1
#endif
#if CAN_WRAP_create_proc_entry
    WRAP_FOR_DETACH(create_proc_entry)
#endif
#ifndef CAN_WRAP_pci_set_pcie_reset_state
#   define CAN_WRAP_pci_set_pcie_reset_state 1
#endif
#if CAN_WRAP_pci_set_pcie_reset_state
    WRAP_FOR_DETACH(pci_set_pcie_reset_state)
#endif
#ifndef CAN_WRAP___dev_get_by_index
#   define CAN_WRAP___dev_get_by_index 1
#endif
#if CAN_WRAP___dev_get_by_index
#   ifdef DETACH_ADDR___dev_get_by_index
        WRAP_FOR_DETACH(__dev_get_by_index)
#   else
        TYPED_DETACH(__dev_get_by_index)
#   endif
#endif
#ifndef CAN_WRAP_cgroup_rm_cftypes
#   define CAN_WRAP_cgroup_rm_cftypes 1
#endif
#if CAN_WRAP_cgroup_rm_cftypes
    WRAP_FOR_DETACH(cgroup_rm_cftypes)
#endif
#ifndef CAN_WRAP_init_emergency_isa_pool
#   define CAN_WRAP_init_emergency_isa_pool 0
#endif
DETACH(init_emergency_isa_pool)
#ifndef CAN_WRAP_arch_uprobe_post_xol
#   define CAN_WRAP_arch_uprobe_post_xol 1
#endif
#if CAN_WRAP_arch_uprobe_post_xol
    WRAP_FOR_DETACH(arch_uprobe_post_xol)
#endif
#ifndef CAN_WRAP_pci_assign_unassigned_bus_resources
#   define CAN_WRAP_pci_assign_unassigned_bus_resources 1
#endif
#if CAN_WRAP_pci_assign_unassigned_bus_resources
    WRAP_FOR_DETACH(pci_assign_unassigned_bus_resources)
#endif
#ifndef CAN_WRAP___lock_page_or_retry
#   define CAN_WRAP___lock_page_or_retry 1
#endif
#if CAN_WRAP___lock_page_or_retry
#   ifdef DETACH_ADDR___lock_page_or_retry
        WRAP_FOR_DETACH(__lock_page_or_retry)
#   else
        TYPED_DETACH(__lock_page_or_retry)
#   endif
#endif
#ifndef CAN_WRAP_ata_port_schedule_eh
#   define CAN_WRAP_ata_port_schedule_eh 1
#endif
#if CAN_WRAP_ata_port_schedule_eh
    WRAP_FOR_DETACH(ata_port_schedule_eh)
#endif
#ifndef CAN_WRAP_nla_find
#   define CAN_WRAP_nla_find 1
#endif
#if CAN_WRAP_nla_find
    WRAP_FOR_DETACH(nla_find)
#endif
#ifndef CAN_WRAP_ata_cable_sata
#   define CAN_WRAP_ata_cable_sata 1
#endif
#if CAN_WRAP_ata_cable_sata
    WRAP_FOR_DETACH(ata_cable_sata)
#endif
#ifndef CAN_WRAP___mod_zone_page_state
#   define CAN_WRAP___mod_zone_page_state 1
#endif
#if CAN_WRAP___mod_zone_page_state
#   ifdef DETACH_ADDR___mod_zone_page_state
        WRAP_FOR_DETACH(__mod_zone_page_state)
#   else
        TYPED_DETACH(__mod_zone_page_state)
#   endif
#endif
#ifndef CAN_WRAP_swiotlb_sync_sg_for_device
#   define CAN_WRAP_swiotlb_sync_sg_for_device 1
#endif
#if CAN_WRAP_swiotlb_sync_sg_for_device
    WRAP_FOR_DETACH(swiotlb_sync_sg_for_device)
#endif
#ifndef CAN_WRAP_pm_generic_restore
#   define CAN_WRAP_pm_generic_restore 1
#endif
#if CAN_WRAP_pm_generic_restore
    WRAP_FOR_DETACH(pm_generic_restore)
#endif
#ifndef CAN_WRAP_match_strdup
#   define CAN_WRAP_match_strdup 1
#endif
#if CAN_WRAP_match_strdup
    WRAP_FOR_DETACH(match_strdup)
#endif
#ifndef CAN_WRAP_find_bug
#   define CAN_WRAP_find_bug 1
#endif
#if CAN_WRAP_find_bug
    WRAP_FOR_DETACH(find_bug)
#endif
#ifndef CAN_WRAP_pci_restore_msi_state
#   define CAN_WRAP_pci_restore_msi_state 1
#endif
#if CAN_WRAP_pci_restore_msi_state
    WRAP_FOR_DETACH(pci_restore_msi_state)
#endif
#ifndef CAN_WRAP_dcb_ieee_delapp
#   define CAN_WRAP_dcb_ieee_delapp 1
#endif
#if CAN_WRAP_dcb_ieee_delapp
    WRAP_FOR_DETACH(dcb_ieee_delapp)
#endif
#ifndef CAN_WRAP_register_reboot_notifier
#   define CAN_WRAP_register_reboot_notifier 1
#endif
#if CAN_WRAP_register_reboot_notifier
    WRAP_FOR_DETACH(register_reboot_notifier)
#endif
#ifndef CAN_WRAP_vlan_uses_dev
#   define CAN_WRAP_vlan_uses_dev 1
#endif
#if CAN_WRAP_vlan_uses_dev
    WRAP_FOR_DETACH(vlan_uses_dev)
#endif
#ifndef CAN_WRAP___cleancache_init_shared_fs
#   define CAN_WRAP___cleancache_init_shared_fs 1
#endif
#if CAN_WRAP___cleancache_init_shared_fs
#   ifdef DETACH_ADDR___cleancache_init_shared_fs
        WRAP_FOR_DETACH(__cleancache_init_shared_fs)
#   else
        TYPED_DETACH(__cleancache_init_shared_fs)
#   endif
#endif
#ifndef CAN_WRAP_clear_page_dirty_for_io
#   define CAN_WRAP_clear_page_dirty_for_io 1
#endif
#if CAN_WRAP_clear_page_dirty_for_io
    WRAP_FOR_DETACH(clear_page_dirty_for_io)
#endif
#ifndef CAN_WRAP_kobj_ns_ops
#   define CAN_WRAP_kobj_ns_ops 1
#endif
#if CAN_WRAP_kobj_ns_ops
    WRAP_FOR_DETACH(kobj_ns_ops)
#endif
#ifndef CAN_WRAP_do_sysinfo
#   define CAN_WRAP_do_sysinfo 1
#endif
#if CAN_WRAP_do_sysinfo
    WRAP_FOR_DETACH(do_sysinfo)
#endif
#ifndef CAN_WRAP_dev_remove_offload
#   define CAN_WRAP_dev_remove_offload 1
#endif
#if CAN_WRAP_dev_remove_offload
    WRAP_FOR_DETACH(dev_remove_offload)
#endif
#ifndef CAN_WRAP_security_msg_msg_free
#   define CAN_WRAP_security_msg_msg_free 1
#endif
#if CAN_WRAP_security_msg_msg_free
    WRAP_FOR_DETACH(security_msg_msg_free)
#endif
#ifndef CAN_WRAP_reqsk_queue_alloc
#   define CAN_WRAP_reqsk_queue_alloc 1
#endif
#if CAN_WRAP_reqsk_queue_alloc
    WRAP_FOR_DETACH(reqsk_queue_alloc)
#endif
#ifndef CAN_WRAP___module_get
#   define CAN_WRAP___module_get 1
#endif
#if CAN_WRAP___module_get
#   ifdef DETACH_ADDR___module_get
        WRAP_FOR_DETACH(__module_get)
#   else
        TYPED_DETACH(__module_get)
#   endif
#endif
#ifndef CAN_WRAP_play_dead_common
#   define CAN_WRAP_play_dead_common 0
#endif
DETACH(play_dead_common)
#ifndef CAN_WRAP_compat_sys_io_setup
#   define CAN_WRAP_compat_sys_io_setup 0
#endif
DETACH(compat_sys_io_setup)
#ifndef CAN_WRAP_bus_for_each_drv
#   define CAN_WRAP_bus_for_each_drv 1
#endif
#if CAN_WRAP_bus_for_each_drv
    WRAP_FOR_DETACH(bus_for_each_drv)
#endif
#ifndef CAN_WRAP_sync_mm_rss
#   define CAN_WRAP_sync_mm_rss 1
#endif
#if CAN_WRAP_sync_mm_rss
    WRAP_FOR_DETACH(sync_mm_rss)
#endif
#ifndef CAN_WRAP_compat_exit_robust_list
#   define CAN_WRAP_compat_exit_robust_list 1
#endif
#if CAN_WRAP_compat_exit_robust_list
    WRAP_FOR_DETACH(compat_exit_robust_list)
#endif
#ifndef CAN_WRAP_zone_reclaim
#   define CAN_WRAP_zone_reclaim 1
#endif
#if CAN_WRAP_zone_reclaim
    WRAP_FOR_DETACH(zone_reclaim)
#endif
#ifndef CAN_WRAP_shmem_zero_setup
#   define CAN_WRAP_shmem_zero_setup 1
#endif
#if CAN_WRAP_shmem_zero_setup
    WRAP_FOR_DETACH(shmem_zero_setup)
#endif
#ifndef CAN_WRAP_ata_do_dev_read_id
#   define CAN_WRAP_ata_do_dev_read_id 1
#endif
#if CAN_WRAP_ata_do_dev_read_id
    WRAP_FOR_DETACH(ata_do_dev_read_id)
#endif
#ifndef CAN_WRAP_get_disk
#   define CAN_WRAP_get_disk 1
#endif
#if CAN_WRAP_get_disk
    WRAP_FOR_DETACH(get_disk)
#endif
#ifndef CAN_WRAP_pci_swiotlb_detect_override
#   define CAN_WRAP_pci_swiotlb_detect_override 0
#endif
DETACH(pci_swiotlb_detect_override)
#ifndef CAN_WRAP_default_wake_function
#   define CAN_WRAP_default_wake_function 1
#endif
#if CAN_WRAP_default_wake_function
    WRAP_FOR_DETACH(default_wake_function)
#endif
#ifndef CAN_WRAP_acpi_add_pm_notifier
#   define CAN_WRAP_acpi_add_pm_notifier 1
#endif
#if CAN_WRAP_acpi_add_pm_notifier
    WRAP_FOR_DETACH(acpi_add_pm_notifier)
#endif
#ifndef CAN_WRAP_clear_nlink
#   define CAN_WRAP_clear_nlink 1
#endif
#if CAN_WRAP_clear_nlink
    WRAP_FOR_DETACH(clear_nlink)
#endif
#ifndef CAN_WRAP_no_action
#   define CAN_WRAP_no_action 0
#endif
DETACH(no_action)
#ifndef CAN_WRAP_tracepoint_probe_unregister_noupdate
#   define CAN_WRAP_tracepoint_probe_unregister_noupdate 0
#endif
DETACH(tracepoint_probe_unregister_noupdate)
#ifndef CAN_WRAP_param_set_byte
#   define CAN_WRAP_param_set_byte 1
#endif
#if CAN_WRAP_param_set_byte
    WRAP_FOR_DETACH(param_set_byte)
#endif
#ifndef CAN_WRAP_rtnl_link_register
#   define CAN_WRAP_rtnl_link_register 1
#endif
#if CAN_WRAP_rtnl_link_register
    WRAP_FOR_DETACH(rtnl_link_register)
#endif
#ifndef CAN_WRAP_klist_iter_exit
#   define CAN_WRAP_klist_iter_exit 1
#endif
#if CAN_WRAP_klist_iter_exit
    WRAP_FOR_DETACH(klist_iter_exit)
#endif
#ifndef CAN_WRAP_blk_queue_dma_alignment
#   define CAN_WRAP_blk_queue_dma_alignment 1
#endif
#if CAN_WRAP_blk_queue_dma_alignment
    WRAP_FOR_DETACH(blk_queue_dma_alignment)
#endif
#ifndef CAN_WRAP_d_absolute_path
#   define CAN_WRAP_d_absolute_path 1
#endif
#if CAN_WRAP_d_absolute_path
    WRAP_FOR_DETACH(d_absolute_path)
#endif
#ifndef CAN_WRAP___prop_inc_percpu_max
#   define CAN_WRAP___prop_inc_percpu_max 1
#endif
#if CAN_WRAP___prop_inc_percpu_max
#   ifdef DETACH_ADDR___prop_inc_percpu_max
        WRAP_FOR_DETACH(__prop_inc_percpu_max)
#   else
        TYPED_DETACH(__prop_inc_percpu_max)
#   endif
#endif
#ifndef CAN_WRAP_sched_setaffinity
#   define CAN_WRAP_sched_setaffinity 1
#endif
#if CAN_WRAP_sched_setaffinity
    WRAP_FOR_DETACH(sched_setaffinity)
#endif
#ifndef CAN_WRAP_is_module_text_address
#   define CAN_WRAP_is_module_text_address 0
#endif
DETACH(is_module_text_address)
#ifndef CAN_WRAP_acpi_pci_irq_add_prt
#   define CAN_WRAP_acpi_pci_irq_add_prt 0
#endif
DETACH(acpi_pci_irq_add_prt)
#ifndef CAN_WRAP_do_vfs_ioctl
#   define CAN_WRAP_do_vfs_ioctl 1
#endif
#if CAN_WRAP_do_vfs_ioctl
    WRAP_FOR_DETACH(do_vfs_ioctl)
#endif
#ifndef CAN_WRAP_remap_vmalloc_range
#   define CAN_WRAP_remap_vmalloc_range 1
#endif
#if CAN_WRAP_remap_vmalloc_range
    WRAP_FOR_DETACH(remap_vmalloc_range)
#endif
#ifndef CAN_WRAP_iowrite32be
#   define CAN_WRAP_iowrite32be 0
#endif
DETACH(iowrite32be)
#ifndef CAN_WRAP_rb_prev
#   define CAN_WRAP_rb_prev 1
#endif
#if CAN_WRAP_rb_prev
    WRAP_FOR_DETACH(rb_prev)
#endif
#ifndef CAN_WRAP_acpi_bus_trim
#   define CAN_WRAP_acpi_bus_trim 1
#endif
#if CAN_WRAP_acpi_bus_trim
    WRAP_FOR_DETACH(acpi_bus_trim)
#endif
#ifndef CAN_WRAP_skb_to_sgvec
#   define CAN_WRAP_skb_to_sgvec 1
#endif
#if CAN_WRAP_skb_to_sgvec
    WRAP_FOR_DETACH(skb_to_sgvec)
#endif
#ifndef CAN_WRAP_exit_task_namespaces
#   define CAN_WRAP_exit_task_namespaces 1
#endif
#if CAN_WRAP_exit_task_namespaces
    WRAP_FOR_DETACH(exit_task_namespaces)
#endif
#ifndef CAN_WRAP_fifo_create_dflt
#   define CAN_WRAP_fifo_create_dflt 1
#endif
#if CAN_WRAP_fifo_create_dflt
    WRAP_FOR_DETACH(fifo_create_dflt)
#endif
#ifndef CAN_WRAP_irq_set_irq_wake
#   define CAN_WRAP_irq_set_irq_wake 0
#endif
DETACH(irq_set_irq_wake)
#ifndef CAN_WRAP_iterate_supers
#   define CAN_WRAP_iterate_supers 1
#endif
#if CAN_WRAP_iterate_supers
    WRAP_FOR_DETACH(iterate_supers)
#endif
#ifndef CAN_WRAP_dump_cpu_task
#   define CAN_WRAP_dump_cpu_task 0
#endif
DETACH(dump_cpu_task)
#ifndef CAN_WRAP_jbd2_journal_wipe
#   define CAN_WRAP_jbd2_journal_wipe 1
#endif
#if CAN_WRAP_jbd2_journal_wipe
    WRAP_FOR_DETACH(jbd2_journal_wipe)
#endif
#ifndef CAN_WRAP_second_overflow
#   define CAN_WRAP_second_overflow 0
#endif
DETACH(second_overflow)
#ifndef CAN_WRAP_kobject_del
#   define CAN_WRAP_kobject_del 1
#endif
#if CAN_WRAP_kobject_del
    WRAP_FOR_DETACH(kobject_del)
#endif
#ifndef CAN_WRAP_freeze_super
#   define CAN_WRAP_freeze_super 1
#endif
#if CAN_WRAP_freeze_super
    WRAP_FOR_DETACH(freeze_super)
#endif
#ifndef CAN_WRAP_arch_release_task_struct
#   define CAN_WRAP_arch_release_task_struct 1
#endif
#if CAN_WRAP_arch_release_task_struct
    WRAP_FOR_DETACH(arch_release_task_struct)
#endif
#ifndef CAN_WRAP_trim_init_extable
#   define CAN_WRAP_trim_init_extable 1
#endif
#if CAN_WRAP_trim_init_extable
    WRAP_FOR_DETACH(trim_init_extable)
#endif
#ifndef CAN_WRAP_iunique
#   define CAN_WRAP_iunique 1
#endif
#if CAN_WRAP_iunique
    WRAP_FOR_DETACH(iunique)
#endif
#ifndef CAN_WRAP_locks_in_grace
#   define CAN_WRAP_locks_in_grace 1
#endif
#if CAN_WRAP_locks_in_grace
    WRAP_FOR_DETACH(locks_in_grace)
#endif
#ifndef CAN_WRAP_uncache_firmware
#   define CAN_WRAP_uncache_firmware 0
#endif
DETACH(uncache_firmware)
#ifndef CAN_WRAP_free_percpu
#   define CAN_WRAP_free_percpu 0
#endif
DETACH(free_percpu)
#ifndef CAN_WRAP_read_cache_pages
#   define CAN_WRAP_read_cache_pages 1
#endif
#if CAN_WRAP_read_cache_pages
    WRAP_FOR_DETACH(read_cache_pages)
#endif
#ifndef CAN_WRAP_timekeeping_max_deferment
#   define CAN_WRAP_timekeeping_max_deferment 0
#endif
DETACH(timekeeping_max_deferment)
#ifndef CAN_WRAP_generic_check_addressable
#   define CAN_WRAP_generic_check_addressable 0
#endif
DETACH(generic_check_addressable)
#ifndef CAN_WRAP_unpoison_memory
#   define CAN_WRAP_unpoison_memory 0
#endif
DETACH(unpoison_memory)
#ifndef CAN_WRAP_noirqdebug_setup
#   define CAN_WRAP_noirqdebug_setup 0
#endif
DETACH(noirqdebug_setup)
#ifndef CAN_WRAP_pm_generic_restore_early
#   define CAN_WRAP_pm_generic_restore_early 1
#endif
#if CAN_WRAP_pm_generic_restore_early
    WRAP_FOR_DETACH(pm_generic_restore_early)
#endif
#ifndef CAN_WRAP_ilookup5
#   define CAN_WRAP_ilookup5 1
#endif
#if CAN_WRAP_ilookup5
    WRAP_FOR_DETACH(ilookup5)
#endif
#ifndef CAN_WRAP_textsearch_prepare
#   define CAN_WRAP_textsearch_prepare 1
#endif
#if CAN_WRAP_textsearch_prepare
    WRAP_FOR_DETACH(textsearch_prepare)
#endif
#ifndef CAN_WRAP_acpi_clear_gpe
#   define CAN_WRAP_acpi_clear_gpe 0
#endif
DETACH(acpi_clear_gpe)
#ifndef CAN_WRAP_create_proc_profile
#   define CAN_WRAP_create_proc_profile 0
#endif
DETACH(create_proc_profile)
#ifndef CAN_WRAP_seq_read
#   define CAN_WRAP_seq_read 1
#endif
#if CAN_WRAP_seq_read
    WRAP_FOR_DETACH(seq_read)
#endif
#ifndef CAN_WRAP_blk_put_request
#   define CAN_WRAP_blk_put_request 1
#endif
#if CAN_WRAP_blk_put_request
    WRAP_FOR_DETACH(blk_put_request)
#endif
#ifndef CAN_WRAP_vmap
#   define CAN_WRAP_vmap 1
#endif
#if CAN_WRAP_vmap
    WRAP_FOR_DETACH(vmap)
#endif
#ifndef CAN_WRAP_use_tsc_delay
#   define CAN_WRAP_use_tsc_delay 0
#endif
DETACH(use_tsc_delay)
#ifndef CAN_WRAP_scsi_host_lookup
#   define CAN_WRAP_scsi_host_lookup 1
#endif
#if CAN_WRAP_scsi_host_lookup
    WRAP_FOR_DETACH(scsi_host_lookup)
#endif
#ifndef CAN_WRAP_timerqueue_iterate_next
#   define CAN_WRAP_timerqueue_iterate_next 1
#endif
#if CAN_WRAP_timerqueue_iterate_next
    WRAP_FOR_DETACH(timerqueue_iterate_next)
#endif
#ifndef CAN_WRAP_pci_test_config_bits
#   define CAN_WRAP_pci_test_config_bits 1
#endif
#if CAN_WRAP_pci_test_config_bits
    WRAP_FOR_DETACH(pci_test_config_bits)
#endif
#ifndef CAN_WRAP_try_to_free_buffers
#   define CAN_WRAP_try_to_free_buffers 1
#endif
#if CAN_WRAP_try_to_free_buffers
    WRAP_FOR_DETACH(try_to_free_buffers)
#endif
#ifndef CAN_WRAP_set_memory_uc
#   define CAN_WRAP_set_memory_uc 0
#endif
DETACH(set_memory_uc)
#ifndef CAN_WRAP_print_cpu_msr
#   define CAN_WRAP_print_cpu_msr 1
#endif
#if CAN_WRAP_print_cpu_msr
    WRAP_FOR_DETACH(print_cpu_msr)
#endif
#ifndef CAN_WRAP_dmaengine_get
#   define CAN_WRAP_dmaengine_get 0
#endif
DETACH(dmaengine_get)
#ifndef CAN_WRAP_simple_unlink
#   define CAN_WRAP_simple_unlink 1
#endif
#if CAN_WRAP_simple_unlink
    WRAP_FOR_DETACH(simple_unlink)
#endif
#ifndef CAN_WRAP_dma_pool_alloc
#   define CAN_WRAP_dma_pool_alloc 1
#endif
#if CAN_WRAP_dma_pool_alloc
    WRAP_FOR_DETACH(dma_pool_alloc)
#endif
#ifndef CAN_WRAP_max_sane_readahead
#   define CAN_WRAP_max_sane_readahead 0
#endif
DETACH(max_sane_readahead)
#ifndef CAN_WRAP_qid_lt
#   define CAN_WRAP_qid_lt 1
#endif
#if CAN_WRAP_qid_lt
    WRAP_FOR_DETACH(qid_lt)
#endif
#ifndef CAN_WRAP_inet_csk_search_req
#   define CAN_WRAP_inet_csk_search_req 1
#endif
#if CAN_WRAP_inet_csk_search_req
    WRAP_FOR_DETACH(inet_csk_search_req)
#endif
#ifndef CAN_WRAP_eth_validate_addr
#   define CAN_WRAP_eth_validate_addr 1
#endif
#if CAN_WRAP_eth_validate_addr
    WRAP_FOR_DETACH(eth_validate_addr)
#endif
#ifndef CAN_WRAP_jiffies_to_timeval
#   define CAN_WRAP_jiffies_to_timeval 1
#endif
#if CAN_WRAP_jiffies_to_timeval
    WRAP_FOR_DETACH(jiffies_to_timeval)
#endif
#ifndef CAN_WRAP_iounmap
#   define CAN_WRAP_iounmap 0
#endif
DETACH(iounmap)
#ifndef CAN_WRAP_swap_shmem_alloc
#   define CAN_WRAP_swap_shmem_alloc 1
#endif
#if CAN_WRAP_swap_shmem_alloc
    WRAP_FOR_DETACH(swap_shmem_alloc)
#endif
#ifndef CAN_WRAP_new_inode
#   define CAN_WRAP_new_inode 1
#endif
#if CAN_WRAP_new_inode
    WRAP_FOR_DETACH(new_inode)
#endif
#ifndef CAN_WRAP_pm_generic_resume_noirq
#   define CAN_WRAP_pm_generic_resume_noirq 1
#endif
#if CAN_WRAP_pm_generic_resume_noirq
    WRAP_FOR_DETACH(pm_generic_resume_noirq)
#endif
#ifndef CAN_WRAP_parse_early_options
#   define CAN_WRAP_parse_early_options 0
#endif
DETACH(parse_early_options)
#ifndef CAN_WRAP___round_jiffies_up
#   define CAN_WRAP___round_jiffies_up 0
#endif
DETACH(__round_jiffies_up)
#ifndef CAN_WRAP_clocksource_unregister
#   define CAN_WRAP_clocksource_unregister 1
#endif
#if CAN_WRAP_clocksource_unregister
    WRAP_FOR_DETACH(clocksource_unregister)
#endif
#ifndef CAN_WRAP___cleancache_invalidate_fs
#   define CAN_WRAP___cleancache_invalidate_fs 1
#endif
#if CAN_WRAP___cleancache_invalidate_fs
#   ifdef DETACH_ADDR___cleancache_invalidate_fs
        WRAP_FOR_DETACH(__cleancache_invalidate_fs)
#   else
        TYPED_DETACH(__cleancache_invalidate_fs)
#   endif
#endif
#ifndef CAN_WRAP_set_task_ioprio
#   define CAN_WRAP_set_task_ioprio 1
#endif
#if CAN_WRAP_set_task_ioprio
    WRAP_FOR_DETACH(set_task_ioprio)
#endif
#ifndef CAN_WRAP_dquot_acquire
#   define CAN_WRAP_dquot_acquire 1
#endif
#if CAN_WRAP_dquot_acquire
    WRAP_FOR_DETACH(dquot_acquire)
#endif
#ifndef CAN_WRAP___rtnl_register
#   define CAN_WRAP___rtnl_register 1
#endif
#if CAN_WRAP___rtnl_register
#   ifdef DETACH_ADDR___rtnl_register
        WRAP_FOR_DETACH(__rtnl_register)
#   else
        TYPED_DETACH(__rtnl_register)
#   endif
#endif
#ifndef CAN_WRAP_proc_mkdir
#   define CAN_WRAP_proc_mkdir 1
#endif
#if CAN_WRAP_proc_mkdir
    WRAP_FOR_DETACH(proc_mkdir)
#endif
#ifndef CAN_WRAP_compat_blkdev_ioctl
#   define CAN_WRAP_compat_blkdev_ioctl 1
#endif
#if CAN_WRAP_compat_blkdev_ioctl
    WRAP_FOR_DETACH(compat_blkdev_ioctl)
#endif
#ifndef CAN_WRAP_usermodehelper_read_trylock
#   define CAN_WRAP_usermodehelper_read_trylock 0
#endif
DETACH(usermodehelper_read_trylock)
#ifndef CAN_WRAP_klist_node_attached
#   define CAN_WRAP_klist_node_attached 1
#endif
#if CAN_WRAP_klist_node_attached
    WRAP_FOR_DETACH(klist_node_attached)
#endif
#ifndef CAN_WRAP_dpm_resume_start
#   define CAN_WRAP_dpm_resume_start 1
#endif
#if CAN_WRAP_dpm_resume_start
    WRAP_FOR_DETACH(dpm_resume_start)
#endif
#ifndef CAN_WRAP_nobh_writepage
#   define CAN_WRAP_nobh_writepage 1
#endif
#if CAN_WRAP_nobh_writepage
    WRAP_FOR_DETACH(nobh_writepage)
#endif
#ifndef CAN_WRAP_tracing_off
#   define CAN_WRAP_tracing_off 0
#endif
DETACH(tracing_off)
#ifndef CAN_WRAP_acpi_os_execute
#   define CAN_WRAP_acpi_os_execute 1
#endif
#if CAN_WRAP_acpi_os_execute
    WRAP_FOR_DETACH(acpi_os_execute)
#endif
#ifndef CAN_WRAP_blk_set_default_limits
#   define CAN_WRAP_blk_set_default_limits 1
#endif
#if CAN_WRAP_blk_set_default_limits
    WRAP_FOR_DETACH(blk_set_default_limits)
#endif
#ifndef CAN_WRAP_arch_reserve_mem_area
#   define CAN_WRAP_arch_reserve_mem_area 0
#endif
DETACH(arch_reserve_mem_area)
#ifndef CAN_WRAP___absent_pages_in_range
#   define CAN_WRAP___absent_pages_in_range 0
#endif
DETACH(__absent_pages_in_range)
#ifndef CAN_WRAP_dcb_ieee_getapp_mask
#   define CAN_WRAP_dcb_ieee_getapp_mask 1
#endif
#if CAN_WRAP_dcb_ieee_getapp_mask
    WRAP_FOR_DETACH(dcb_ieee_getapp_mask)
#endif
#ifndef CAN_WRAP_pci_find_next_ext_capability
#   define CAN_WRAP_pci_find_next_ext_capability 1
#endif
#if CAN_WRAP_pci_find_next_ext_capability
    WRAP_FOR_DETACH(pci_find_next_ext_capability)
#endif
#ifndef CAN_WRAP_inet_csk_listen_stop
#   define CAN_WRAP_inet_csk_listen_stop 1
#endif
#if CAN_WRAP_inet_csk_listen_stop
    WRAP_FOR_DETACH(inet_csk_listen_stop)
#endif
#ifndef CAN_WRAP_blk_queue_invalidate_tags
#   define CAN_WRAP_blk_queue_invalidate_tags 1
#endif
#if CAN_WRAP_blk_queue_invalidate_tags
    WRAP_FOR_DETACH(blk_queue_invalidate_tags)
#endif
#ifndef CAN_WRAP_neigh_for_each
#   define CAN_WRAP_neigh_for_each 1
#endif
#if CAN_WRAP_neigh_for_each
    WRAP_FOR_DETACH(neigh_for_each)
#endif
#ifndef CAN_WRAP_pci_find_ext_capability
#   define CAN_WRAP_pci_find_ext_capability 1
#endif
#if CAN_WRAP_pci_find_ext_capability
    WRAP_FOR_DETACH(pci_find_ext_capability)
#endif
#ifndef CAN_WRAP_dev_deactivate_many
#   define CAN_WRAP_dev_deactivate_many 1
#endif
#if CAN_WRAP_dev_deactivate_many
    WRAP_FOR_DETACH(dev_deactivate_many)
#endif
#ifndef CAN_WRAP_lruvec_init
#   define CAN_WRAP_lruvec_init 1
#endif
#if CAN_WRAP_lruvec_init
    WRAP_FOR_DETACH(lruvec_init)
#endif
#ifndef CAN_WRAP_setattr_copy
#   define CAN_WRAP_setattr_copy 1
#endif
#if CAN_WRAP_setattr_copy
    WRAP_FOR_DETACH(setattr_copy)
#endif
#ifndef CAN_WRAP_dquot_claim_space_nodirty
#   define CAN_WRAP_dquot_claim_space_nodirty 1
#endif
#if CAN_WRAP_dquot_claim_space_nodirty
    WRAP_FOR_DETACH(dquot_claim_space_nodirty)
#endif
#ifndef CAN_WRAP_res_counter_uncharge_until
#   define CAN_WRAP_res_counter_uncharge_until 1
#endif
#if CAN_WRAP_res_counter_uncharge_until
    WRAP_FOR_DETACH(res_counter_uncharge_until)
#endif
#ifndef CAN_WRAP_default_smp_read_mpc_oem
#   define CAN_WRAP_default_smp_read_mpc_oem 1
#endif
#if CAN_WRAP_default_smp_read_mpc_oem
    WRAP_FOR_DETACH(default_smp_read_mpc_oem)
#endif
#ifndef CAN_WRAP_init_cpu_online
#   define CAN_WRAP_init_cpu_online 1
#endif
#if CAN_WRAP_init_cpu_online
    WRAP_FOR_DETACH(init_cpu_online)
#endif
#ifndef CAN_WRAP_split_huge_page_pmd_mm
#   define CAN_WRAP_split_huge_page_pmd_mm 1
#endif
#if CAN_WRAP_split_huge_page_pmd_mm
    WRAP_FOR_DETACH(split_huge_page_pmd_mm)
#endif
#ifndef CAN_WRAP_clocksource_i8253_init
#   define CAN_WRAP_clocksource_i8253_init 0
#endif
DETACH(clocksource_i8253_init)
#ifndef CAN_WRAP_rcu_idle_enter
#   define CAN_WRAP_rcu_idle_enter 0
#endif
DETACH(rcu_idle_enter)
#ifndef CAN_WRAP_pci_sriov_migration
#   define CAN_WRAP_pci_sriov_migration 1
#endif
#if CAN_WRAP_pci_sriov_migration
    WRAP_FOR_DETACH(pci_sriov_migration)
#endif
#ifndef CAN_WRAP_strlcpy
#   define CAN_WRAP_strlcpy 0
#endif
DETACH(strlcpy)
#ifndef CAN_WRAP_pci_msix_shutdown
#   define CAN_WRAP_pci_msix_shutdown 1
#endif
#if CAN_WRAP_pci_msix_shutdown
    WRAP_FOR_DETACH(pci_msix_shutdown)
#endif
#ifndef CAN_WRAP_invalidate_interrupt12
#   define CAN_WRAP_invalidate_interrupt12 0
#endif
DETACH(invalidate_interrupt12)
#ifndef CAN_WRAP_invalidate_interrupt13
#   define CAN_WRAP_invalidate_interrupt13 0
#endif
DETACH(invalidate_interrupt13)
#ifndef CAN_WRAP_mb_cache_create
#   define CAN_WRAP_mb_cache_create 1
#endif
#if CAN_WRAP_mb_cache_create
    WRAP_FOR_DETACH(mb_cache_create)
#endif
#ifndef CAN_WRAP_invalidate_interrupt11
#   define CAN_WRAP_invalidate_interrupt11 0
#endif
DETACH(invalidate_interrupt11)
#ifndef CAN_WRAP_invalidate_interrupt16
#   define CAN_WRAP_invalidate_interrupt16 0
#endif
DETACH(invalidate_interrupt16)
#ifndef CAN_WRAP_invalidate_interrupt17
#   define CAN_WRAP_invalidate_interrupt17 0
#endif
DETACH(invalidate_interrupt17)
#ifndef CAN_WRAP_invalidate_interrupt14
#   define CAN_WRAP_invalidate_interrupt14 0
#endif
DETACH(invalidate_interrupt14)
#ifndef CAN_WRAP_invalidate_interrupt15
#   define CAN_WRAP_invalidate_interrupt15 0
#endif
DETACH(invalidate_interrupt15)
#ifndef CAN_WRAP_invalidate_interrupt18
#   define CAN_WRAP_invalidate_interrupt18 0
#endif
DETACH(invalidate_interrupt18)
#ifndef CAN_WRAP_invalidate_interrupt19
#   define CAN_WRAP_invalidate_interrupt19 0
#endif
DETACH(invalidate_interrupt19)
#ifndef CAN_WRAP_page_symlink
#   define CAN_WRAP_page_symlink 1
#endif
#if CAN_WRAP_page_symlink
    WRAP_FOR_DETACH(page_symlink)
#endif
#ifndef CAN_WRAP_qdisc_class_hash_init
#   define CAN_WRAP_qdisc_class_hash_init 1
#endif
#if CAN_WRAP_qdisc_class_hash_init
    WRAP_FOR_DETACH(qdisc_class_hash_init)
#endif
#ifndef CAN_WRAP_get_avenrun
#   define CAN_WRAP_get_avenrun 0
#endif
DETACH(get_avenrun)
#ifndef CAN_WRAP_bus_remove_file
#   define CAN_WRAP_bus_remove_file 1
#endif
#if CAN_WRAP_bus_remove_file
    WRAP_FOR_DETACH(bus_remove_file)
#endif
#ifndef CAN_WRAP_vmemmap_alloc_block
#   define CAN_WRAP_vmemmap_alloc_block 0
#endif
DETACH(vmemmap_alloc_block)
#ifndef CAN_WRAP_inet_frag_kill
#   define CAN_WRAP_inet_frag_kill 1
#endif
#if CAN_WRAP_inet_frag_kill
    WRAP_FOR_DETACH(inet_frag_kill)
#endif
#ifndef CAN_WRAP_security_module_enable
#   define CAN_WRAP_security_module_enable 1
#endif
#if CAN_WRAP_security_module_enable
    WRAP_FOR_DETACH(security_module_enable)
#endif
#ifndef CAN_WRAP_timerqueue_add
#   define CAN_WRAP_timerqueue_add 1
#endif
#if CAN_WRAP_timerqueue_add
    WRAP_FOR_DETACH(timerqueue_add)
#endif
#ifndef CAN_WRAP_dev_alloc_name
#   define CAN_WRAP_dev_alloc_name 1
#endif
#if CAN_WRAP_dev_alloc_name
    WRAP_FOR_DETACH(dev_alloc_name)
#endif
#ifndef CAN_WRAP_d_add_ci
#   define CAN_WRAP_d_add_ci 1
#endif
#if CAN_WRAP_d_add_ci
    WRAP_FOR_DETACH(d_add_ci)
#endif
#ifndef CAN_WRAP_compat_sys_futex
#   define CAN_WRAP_compat_sys_futex 1
#endif
#if CAN_WRAP_compat_sys_futex
    WRAP_FOR_DETACH(compat_sys_futex)
#endif
#ifndef CAN_WRAP_fsync_bdev
#   define CAN_WRAP_fsync_bdev 1
#endif
#if CAN_WRAP_fsync_bdev
    WRAP_FOR_DETACH(fsync_bdev)
#endif
#ifndef CAN_WRAP_neigh_resolve_output
#   define CAN_WRAP_neigh_resolve_output 1
#endif
#if CAN_WRAP_neigh_resolve_output
    WRAP_FOR_DETACH(neigh_resolve_output)
#endif
#ifndef CAN_WRAP_blkdev_show
#   define CAN_WRAP_blkdev_show 1
#endif
#if CAN_WRAP_blkdev_show
    WRAP_FOR_DETACH(blkdev_show)
#endif
#ifndef CAN_WRAP_set_memory_x
#   define CAN_WRAP_set_memory_x 0
#endif
DETACH(set_memory_x)
#ifndef CAN_WRAP_phy_driver_unregister
#   define CAN_WRAP_phy_driver_unregister 1
#endif
#if CAN_WRAP_phy_driver_unregister
    WRAP_FOR_DETACH(phy_driver_unregister)
#endif
#ifndef CAN_WRAP_mem_init
#   define CAN_WRAP_mem_init 0
#endif
DETACH(mem_init)
#ifndef CAN_WRAP_security_capget
#   define CAN_WRAP_security_capget 1
#endif
#if CAN_WRAP_security_capget
    WRAP_FOR_DETACH(security_capget)
#endif
#ifndef CAN_WRAP_ata_host_init
#   define CAN_WRAP_ata_host_init 1
#endif
#if CAN_WRAP_ata_host_init
    WRAP_FOR_DETACH(ata_host_init)
#endif
#ifndef CAN_WRAP_in_gate_area_no_mm
#   define CAN_WRAP_in_gate_area_no_mm 0
#endif
DETACH(in_gate_area_no_mm)
#ifndef CAN_WRAP_ata_bmdma_port_start
#   define CAN_WRAP_ata_bmdma_port_start 1
#endif
#if CAN_WRAP_ata_bmdma_port_start
    WRAP_FOR_DETACH(ata_bmdma_port_start)
#endif
#ifndef CAN_WRAP_debug_locks_off
#   define CAN_WRAP_debug_locks_off 0
#endif
DETACH(debug_locks_off)
#ifndef CAN_WRAP_jbd2_journal_destroy
#   define CAN_WRAP_jbd2_journal_destroy 1
#endif
#if CAN_WRAP_jbd2_journal_destroy
    WRAP_FOR_DETACH(jbd2_journal_destroy)
#endif
#ifndef CAN_WRAP_ftrace_dump
#   define CAN_WRAP_ftrace_dump 0
#endif
DETACH(ftrace_dump)
#ifndef CAN_WRAP_kern_path
#   define CAN_WRAP_kern_path 1
#endif
#if CAN_WRAP_kern_path
    WRAP_FOR_DETACH(kern_path)
#endif
#ifndef CAN_WRAP_ack_bad_irq
#   define CAN_WRAP_ack_bad_irq 0
#endif
DETACH(ack_bad_irq)
#ifndef CAN_WRAP_vfs_setlease
#   define CAN_WRAP_vfs_setlease 1
#endif
#if CAN_WRAP_vfs_setlease
    WRAP_FOR_DETACH(vfs_setlease)
#endif
#ifndef CAN_WRAP_access_process_vm
#   define CAN_WRAP_access_process_vm 1
#endif
#if CAN_WRAP_access_process_vm
    WRAP_FOR_DETACH(access_process_vm)
#endif
#ifndef CAN_WRAP_block_write_begin
#   define CAN_WRAP_block_write_begin 1
#endif
#if CAN_WRAP_block_write_begin
    WRAP_FOR_DETACH(block_write_begin)
#endif
#ifndef CAN_WRAP___wait_on_journal
#   define CAN_WRAP___wait_on_journal 1
#endif
#if CAN_WRAP___wait_on_journal
#   ifdef DETACH_ADDR___wait_on_journal
        WRAP_FOR_DETACH(__wait_on_journal)
#   else
        TYPED_DETACH(__wait_on_journal)
#   endif
#endif
#ifndef CAN_WRAP_acpi_table_print_madt_entry
#   define CAN_WRAP_acpi_table_print_madt_entry 1
#endif
#if CAN_WRAP_acpi_table_print_madt_entry
    WRAP_FOR_DETACH(acpi_table_print_madt_entry)
#endif
#ifndef CAN_WRAP_locks_start_grace
#   define CAN_WRAP_locks_start_grace 1
#endif
#if CAN_WRAP_locks_start_grace
    WRAP_FOR_DETACH(locks_start_grace)
#endif
#ifndef CAN_WRAP_find_vm_area
#   define CAN_WRAP_find_vm_area 1
#endif
#if CAN_WRAP_find_vm_area
    WRAP_FOR_DETACH(find_vm_area)
#endif
#ifndef CAN_WRAP_irq_set_chip_and_handler_name
#   define CAN_WRAP_irq_set_chip_and_handler_name 1
#endif
#if CAN_WRAP_irq_set_chip_and_handler_name
    WRAP_FOR_DETACH(irq_set_chip_and_handler_name)
#endif
#ifndef CAN_WRAP_native_send_call_func_ipi
#   define CAN_WRAP_native_send_call_func_ipi 1
#endif
#if CAN_WRAP_native_send_call_func_ipi
    WRAP_FOR_DETACH(native_send_call_func_ipi)
#endif
#ifndef CAN_WRAP_pm_restrict_gfp_mask
#   define CAN_WRAP_pm_restrict_gfp_mask 0
#endif
DETACH(pm_restrict_gfp_mask)
#ifndef CAN_WRAP_sort_extable
#   define CAN_WRAP_sort_extable 1
#endif
#if CAN_WRAP_sort_extable
    WRAP_FOR_DETACH(sort_extable)
#endif
#ifndef CAN_WRAP_convert_ip_to_linear
#   define CAN_WRAP_convert_ip_to_linear 1
#endif
#if CAN_WRAP_convert_ip_to_linear
    WRAP_FOR_DETACH(convert_ip_to_linear)
#endif
#ifndef CAN_WRAP_netlink_change_ngroups
#   define CAN_WRAP_netlink_change_ngroups 1
#endif
#if CAN_WRAP_netlink_change_ngroups
    WRAP_FOR_DETACH(netlink_change_ngroups)
#endif
#ifndef CAN_WRAP_queue_delayed_work_on
#   define CAN_WRAP_queue_delayed_work_on 1
#endif
#if CAN_WRAP_queue_delayed_work_on
    WRAP_FOR_DETACH(queue_delayed_work_on)
#endif
#ifndef CAN_WRAP_ata_link_next
#   define CAN_WRAP_ata_link_next 1
#endif
#if CAN_WRAP_ata_link_next
    WRAP_FOR_DETACH(ata_link_next)
#endif
#ifndef CAN_WRAP_sock_edemux
#   define CAN_WRAP_sock_edemux 1
#endif
#if CAN_WRAP_sock_edemux
    WRAP_FOR_DETACH(sock_edemux)
#endif
#ifndef CAN_WRAP_security_socket_sendmsg
#   define CAN_WRAP_security_socket_sendmsg 1
#endif
#if CAN_WRAP_security_socket_sendmsg
    WRAP_FOR_DETACH(security_socket_sendmsg)
#endif
#ifndef CAN_WRAP_wakeup_source_unregister
#   define CAN_WRAP_wakeup_source_unregister 1
#endif
#if CAN_WRAP_wakeup_source_unregister
    WRAP_FOR_DETACH(wakeup_source_unregister)
#endif
#ifndef CAN_WRAP_alloc_page_buffers
#   define CAN_WRAP_alloc_page_buffers 1
#endif
#if CAN_WRAP_alloc_page_buffers
    WRAP_FOR_DETACH(alloc_page_buffers)
#endif
#ifndef CAN_WRAP_d_drop
#   define CAN_WRAP_d_drop 1
#endif
#if CAN_WRAP_d_drop
    WRAP_FOR_DETACH(d_drop)
#endif
#ifndef CAN_WRAP_pm_generic_poweroff_late
#   define CAN_WRAP_pm_generic_poweroff_late 1
#endif
#if CAN_WRAP_pm_generic_poweroff_late
    WRAP_FOR_DETACH(pm_generic_poweroff_late)
#endif
#ifndef CAN_WRAP_pneigh_delete
#   define CAN_WRAP_pneigh_delete 1
#endif
#if CAN_WRAP_pneigh_delete
    WRAP_FOR_DETACH(pneigh_delete)
#endif
#ifndef CAN_WRAP_crypto_aead_setauthsize
#   define CAN_WRAP_crypto_aead_setauthsize 1
#endif
#if CAN_WRAP_crypto_aead_setauthsize
    WRAP_FOR_DETACH(crypto_aead_setauthsize)
#endif
#ifndef CAN_WRAP_acpi_bus_register_driver
#   define CAN_WRAP_acpi_bus_register_driver 1
#endif
#if CAN_WRAP_acpi_bus_register_driver
    WRAP_FOR_DETACH(acpi_bus_register_driver)
#endif
#ifndef CAN_WRAP_alloc_vm_area
#   define CAN_WRAP_alloc_vm_area 1
#endif
#if CAN_WRAP_alloc_vm_area
    WRAP_FOR_DETACH(alloc_vm_area)
#endif
#ifndef CAN_WRAP_ata_sg_init
#   define CAN_WRAP_ata_sg_init 1
#endif
#if CAN_WRAP_ata_sg_init
    WRAP_FOR_DETACH(ata_sg_init)
#endif
#ifndef CAN_WRAP_dev_set_name
#   define CAN_WRAP_dev_set_name 1
#endif
#if CAN_WRAP_dev_set_name
    WRAP_FOR_DETACH(dev_set_name)
#endif
#ifndef CAN_WRAP_idr_get_new
#   define CAN_WRAP_idr_get_new 1
#endif
#if CAN_WRAP_idr_get_new
    WRAP_FOR_DETACH(idr_get_new)
#endif
#ifndef CAN_WRAP_ida_destroy
#   define CAN_WRAP_ida_destroy 1
#endif
#if CAN_WRAP_ida_destroy
    WRAP_FOR_DETACH(ida_destroy)
#endif
#ifndef CAN_WRAP_wakeup_source_create
#   define CAN_WRAP_wakeup_source_create 1
#endif
#if CAN_WRAP_wakeup_source_create
    WRAP_FOR_DETACH(wakeup_source_create)
#endif
#ifndef CAN_WRAP_set_cpu_active
#   define CAN_WRAP_set_cpu_active 0
#endif
DETACH(set_cpu_active)
#ifndef CAN_WRAP_simple_attr_write
#   define CAN_WRAP_simple_attr_write 1
#endif
#if CAN_WRAP_simple_attr_write
    WRAP_FOR_DETACH(simple_attr_write)
#endif
#ifndef CAN_WRAP_handle_fasteoi_irq
#   define CAN_WRAP_handle_fasteoi_irq 1
#endif
#if CAN_WRAP_handle_fasteoi_irq
    WRAP_FOR_DETACH(handle_fasteoi_irq)
#endif
#ifndef CAN_WRAP_truncate_inode_pages_range
#   define CAN_WRAP_truncate_inode_pages_range 1
#endif
#if CAN_WRAP_truncate_inode_pages_range
    WRAP_FOR_DETACH(truncate_inode_pages_range)
#endif
#ifndef CAN_WRAP___pci_complete_power_transition
#   define CAN_WRAP___pci_complete_power_transition 1
#endif
#if CAN_WRAP___pci_complete_power_transition
#   ifdef DETACH_ADDR___pci_complete_power_transition
        WRAP_FOR_DETACH(__pci_complete_power_transition)
#   else
        TYPED_DETACH(__pci_complete_power_transition)
#   endif
#endif
#ifndef CAN_WRAP_mark_info_dirty
#   define CAN_WRAP_mark_info_dirty 1
#endif
#if CAN_WRAP_mark_info_dirty
    WRAP_FOR_DETACH(mark_info_dirty)
#endif
#ifndef CAN_WRAP_pci_set_vga_state
#   define CAN_WRAP_pci_set_vga_state 1
#endif
#if CAN_WRAP_pci_set_vga_state
    WRAP_FOR_DETACH(pci_set_vga_state)
#endif
#ifndef CAN_WRAP_arch_flush_lazy_mmu_mode
#   define CAN_WRAP_arch_flush_lazy_mmu_mode 0
#endif
DETACH(arch_flush_lazy_mmu_mode)
#ifndef CAN_WRAP_unregister_netdevice_many
#   define CAN_WRAP_unregister_netdevice_many 1
#endif
#if CAN_WRAP_unregister_netdevice_many
    WRAP_FOR_DETACH(unregister_netdevice_many)
#endif
#ifndef CAN_WRAP__raw_spin_lock_bh
#   define CAN_WRAP__raw_spin_lock_bh 1
#endif
#if CAN_WRAP__raw_spin_lock_bh
    WRAP_FOR_DETACH(_raw_spin_lock_bh)
#endif
#ifndef CAN_WRAP_sparse_mem_map_populate
#   define CAN_WRAP_sparse_mem_map_populate 1
#endif
#if CAN_WRAP_sparse_mem_map_populate
    WRAP_FOR_DETACH(sparse_mem_map_populate)
#endif
#ifndef CAN_WRAP_pnp_device_detach
#   define CAN_WRAP_pnp_device_detach 1
#endif
#if CAN_WRAP_pnp_device_detach
    WRAP_FOR_DETACH(pnp_device_detach)
#endif
#ifndef CAN_WRAP_bvec_free_bs
#   define CAN_WRAP_bvec_free_bs 1
#endif
#if CAN_WRAP_bvec_free_bs
    WRAP_FOR_DETACH(bvec_free_bs)
#endif
#ifndef CAN_WRAP_register_switch_driver
#   define CAN_WRAP_register_switch_driver 1
#endif
#if CAN_WRAP_register_switch_driver
    WRAP_FOR_DETACH(register_switch_driver)
#endif
#ifndef CAN_WRAP_mmap_init
#   define CAN_WRAP_mmap_init 0
#endif
DETACH(mmap_init)
#ifndef CAN_WRAP_simple_xattr_alloc
#   define CAN_WRAP_simple_xattr_alloc 1
#endif
#if CAN_WRAP_simple_xattr_alloc
    WRAP_FOR_DETACH(simple_xattr_alloc)
#endif
#ifndef CAN_WRAP_get_compat_itimerspec
#   define CAN_WRAP_get_compat_itimerspec 1
#endif
#if CAN_WRAP_get_compat_itimerspec
    WRAP_FOR_DETACH(get_compat_itimerspec)
#endif
#ifndef CAN_WRAP_init_module
#   define CAN_WRAP_init_module 0
#endif
DETACH(init_module)
#ifndef CAN_WRAP_ata_bmdma_port_intr
#   define CAN_WRAP_ata_bmdma_port_intr 1
#endif
#if CAN_WRAP_ata_bmdma_port_intr
    WRAP_FOR_DETACH(ata_bmdma_port_intr)
#endif
#ifndef CAN_WRAP_downgrade_write
#   define CAN_WRAP_downgrade_write 1
#endif
#if CAN_WRAP_downgrade_write
    WRAP_FOR_DETACH(downgrade_write)
#endif
#ifndef CAN_WRAP___kernel_param_lock
#   define CAN_WRAP___kernel_param_lock 0
#endif
DETACH(__kernel_param_lock)
#ifndef CAN_WRAP_bdi_set_min_ratio
#   define CAN_WRAP_bdi_set_min_ratio 1
#endif
#if CAN_WRAP_bdi_set_min_ratio
    WRAP_FOR_DETACH(bdi_set_min_ratio)
#endif
#ifndef CAN_WRAP_schedule_delayed_work_on
#   define CAN_WRAP_schedule_delayed_work_on 1
#endif
#if CAN_WRAP_schedule_delayed_work_on
    WRAP_FOR_DETACH(schedule_delayed_work_on)
#endif
#ifndef CAN_WRAP_early_acpi_boot_init
#   define CAN_WRAP_early_acpi_boot_init 0
#endif
DETACH(early_acpi_boot_init)
#ifndef CAN_WRAP_nla_strlcpy
#   define CAN_WRAP_nla_strlcpy 1
#endif
#if CAN_WRAP_nla_strlcpy
    WRAP_FOR_DETACH(nla_strlcpy)
#endif
#ifndef CAN_WRAP_kern_path_create
#   define CAN_WRAP_kern_path_create 1
#endif
#if CAN_WRAP_kern_path_create
    WRAP_FOR_DETACH(kern_path_create)
#endif
#ifndef CAN_WRAP_sock_no_socketpair
#   define CAN_WRAP_sock_no_socketpair 1
#endif
#if CAN_WRAP_sock_no_socketpair
    WRAP_FOR_DETACH(sock_no_socketpair)
#endif
#ifndef CAN_WRAP_arch_uprobe_abort_xol
#   define CAN_WRAP_arch_uprobe_abort_xol 1
#endif
#if CAN_WRAP_arch_uprobe_abort_xol
    WRAP_FOR_DETACH(arch_uprobe_abort_xol)
#endif
#ifndef CAN_WRAP_proc_doulongvec_minmax
#   define CAN_WRAP_proc_doulongvec_minmax 1
#endif
#if CAN_WRAP_proc_doulongvec_minmax
    WRAP_FOR_DETACH(proc_doulongvec_minmax)
#endif
#ifndef CAN_WRAP_ata_sff_tf_load
#   define CAN_WRAP_ata_sff_tf_load 1
#endif
#if CAN_WRAP_ata_sff_tf_load
    WRAP_FOR_DETACH(ata_sff_tf_load)
#endif
#ifndef CAN_WRAP_inet_twsk_purge
#   define CAN_WRAP_inet_twsk_purge 1
#endif
#if CAN_WRAP_inet_twsk_purge
    WRAP_FOR_DETACH(inet_twsk_purge)
#endif
#ifndef CAN_WRAP_pgprot_writecombine
#   define CAN_WRAP_pgprot_writecombine 1
#endif
#if CAN_WRAP_pgprot_writecombine
    WRAP_FOR_DETACH(pgprot_writecombine)
#endif
#ifndef CAN_WRAP_simple_rename
#   define CAN_WRAP_simple_rename 1
#endif
#if CAN_WRAP_simple_rename
    WRAP_FOR_DETACH(simple_rename)
#endif
#ifndef CAN_WRAP_aio_put_req
#   define CAN_WRAP_aio_put_req 1
#endif
#if CAN_WRAP_aio_put_req
    WRAP_FOR_DETACH(aio_put_req)
#endif
#ifndef CAN_WRAP_idle_task
#   define CAN_WRAP_idle_task 1
#endif
#if CAN_WRAP_idle_task
    WRAP_FOR_DETACH(idle_task)
#endif
#ifndef CAN_WRAP_pci_hp_remove_module_link
#   define CAN_WRAP_pci_hp_remove_module_link 1
#endif
#if CAN_WRAP_pci_hp_remove_module_link
    WRAP_FOR_DETACH(pci_hp_remove_module_link)
#endif
#ifndef CAN_WRAP_ata_host_register
#   define CAN_WRAP_ata_host_register 1
#endif
#if CAN_WRAP_ata_host_register
    WRAP_FOR_DETACH(ata_host_register)
#endif
#ifndef CAN_WRAP_blk_end_request_all
#   define CAN_WRAP_blk_end_request_all 1
#endif
#if CAN_WRAP_blk_end_request_all
    WRAP_FOR_DETACH(blk_end_request_all)
#endif
#ifndef CAN_WRAP___kernel_param_unlock
#   define CAN_WRAP___kernel_param_unlock 0
#endif
DETACH(__kernel_param_unlock)
#ifndef CAN_WRAP_skb_realloc_headroom
#   define CAN_WRAP_skb_realloc_headroom 1
#endif
#if CAN_WRAP_skb_realloc_headroom
    WRAP_FOR_DETACH(skb_realloc_headroom)
#endif
#ifndef CAN_WRAP_skb_pull
#   define CAN_WRAP_skb_pull 1
#endif
#if CAN_WRAP_skb_pull
    WRAP_FOR_DETACH(skb_pull)
#endif
#ifndef CAN_WRAP_pci_disable_device
#   define CAN_WRAP_pci_disable_device 1
#endif
#if CAN_WRAP_pci_disable_device
    WRAP_FOR_DETACH(pci_disable_device)
#endif
#ifndef CAN_WRAP_finish_open
#   define CAN_WRAP_finish_open 1
#endif
#if CAN_WRAP_finish_open
    WRAP_FOR_DETACH(finish_open)
#endif
#ifndef CAN_WRAP_register_task_migration_notifier
#   define CAN_WRAP_register_task_migration_notifier 1
#endif
#if CAN_WRAP_register_task_migration_notifier
    WRAP_FOR_DETACH(register_task_migration_notifier)
#endif
#ifndef CAN_WRAP_acpi_nvs_nosave_s3
#   define CAN_WRAP_acpi_nvs_nosave_s3 0
#endif
DETACH(acpi_nvs_nosave_s3)
#ifndef CAN_WRAP_crypto_ahash_finup
#   define CAN_WRAP_crypto_ahash_finup 1
#endif
#if CAN_WRAP_crypto_ahash_finup
    WRAP_FOR_DETACH(crypto_ahash_finup)
#endif
#ifndef CAN_WRAP_invalidate_bdev
#   define CAN_WRAP_invalidate_bdev 1
#endif
#if CAN_WRAP_invalidate_bdev
    WRAP_FOR_DETACH(invalidate_bdev)
#endif
#ifndef CAN_WRAP_check_x2apic
#   define CAN_WRAP_check_x2apic 0
#endif
DETACH(check_x2apic)
#ifndef CAN_WRAP_inet_csk_compat_getsockopt
#   define CAN_WRAP_inet_csk_compat_getsockopt 1
#endif
#if CAN_WRAP_inet_csk_compat_getsockopt
    WRAP_FOR_DETACH(inet_csk_compat_getsockopt)
#endif
#ifndef CAN_WRAP_inc_zone_state
#   define CAN_WRAP_inc_zone_state 1
#endif
#if CAN_WRAP_inc_zone_state
    WRAP_FOR_DETACH(inc_zone_state)
#endif
#ifndef CAN_WRAP_refresh_zone_stat_thresholds
#   define CAN_WRAP_refresh_zone_stat_thresholds 0
#endif
DETACH(refresh_zone_stat_thresholds)
#ifndef CAN_WRAP_vfs_symlink
#   define CAN_WRAP_vfs_symlink 1
#endif
#if CAN_WRAP_vfs_symlink
    WRAP_FOR_DETACH(vfs_symlink)
#endif
#ifndef CAN_WRAP_acpi_write
#   define CAN_WRAP_acpi_write 1
#endif
#if CAN_WRAP_acpi_write
    WRAP_FOR_DETACH(acpi_write)
#endif
#ifndef CAN_WRAP_set_page_dirty_balance
#   define CAN_WRAP_set_page_dirty_balance 1
#endif
#if CAN_WRAP_set_page_dirty_balance
    WRAP_FOR_DETACH(set_page_dirty_balance)
#endif
#ifndef CAN_WRAP___sg_free_table
#   define CAN_WRAP___sg_free_table 1
#endif
#if CAN_WRAP___sg_free_table
#   ifdef DETACH_ADDR___sg_free_table
        WRAP_FOR_DETACH(__sg_free_table)
#   else
        TYPED_DETACH(__sg_free_table)
#   endif
#endif
#ifndef CAN_WRAP_security_task_getioprio
#   define CAN_WRAP_security_task_getioprio 1
#endif
#if CAN_WRAP_security_task_getioprio
    WRAP_FOR_DETACH(security_task_getioprio)
#endif
#ifndef CAN_WRAP__raw_read_trylock
#   define CAN_WRAP__raw_read_trylock 1
#endif
#if CAN_WRAP__raw_read_trylock
    WRAP_FOR_DETACH(_raw_read_trylock)
#endif
#ifndef CAN_WRAP_security_tun_dev_alloc_security
#   define CAN_WRAP_security_tun_dev_alloc_security 0
#endif
DETACH(security_tun_dev_alloc_security)
#ifndef CAN_WRAP_security_prepare_creds
#   define CAN_WRAP_security_prepare_creds 1
#endif
#if CAN_WRAP_security_prepare_creds
    WRAP_FOR_DETACH(security_prepare_creds)
#endif
#ifndef CAN_WRAP_e820_any_mapped
#   define CAN_WRAP_e820_any_mapped 0
#endif
DETACH(e820_any_mapped)
#ifndef CAN_WRAP_pcibios_resource_to_bus
#   define CAN_WRAP_pcibios_resource_to_bus 1
#endif
#if CAN_WRAP_pcibios_resource_to_bus
    WRAP_FOR_DETACH(pcibios_resource_to_bus)
#endif
#ifndef CAN_WRAP_match_token
#   define CAN_WRAP_match_token 0
#endif
DETACH(match_token)
#ifndef CAN_WRAP_security_sb_set_mnt_opts
#   define CAN_WRAP_security_sb_set_mnt_opts 1
#endif
#if CAN_WRAP_security_sb_set_mnt_opts
    WRAP_FOR_DETACH(security_sb_set_mnt_opts)
#endif
#ifndef CAN_WRAP_vfs_truncate
#   define CAN_WRAP_vfs_truncate 1
#endif
#if CAN_WRAP_vfs_truncate
    WRAP_FOR_DETACH(vfs_truncate)
#endif
#ifndef CAN_WRAP_jbd2_journal_free_transaction
#   define CAN_WRAP_jbd2_journal_free_transaction 1
#endif
#if CAN_WRAP_jbd2_journal_free_transaction
    WRAP_FOR_DETACH(jbd2_journal_free_transaction)
#endif
#ifndef CAN_WRAP_pci_msi_enabled
#   define CAN_WRAP_pci_msi_enabled 0
#endif
DETACH(pci_msi_enabled)
#ifndef CAN_WRAP_dst_cow_metrics_generic
#   define CAN_WRAP_dst_cow_metrics_generic 1
#endif
#if CAN_WRAP_dst_cow_metrics_generic
    WRAP_FOR_DETACH(dst_cow_metrics_generic)
#endif
#ifndef CAN_WRAP_locks_delete_block
#   define CAN_WRAP_locks_delete_block 1
#endif
#if CAN_WRAP_locks_delete_block
    WRAP_FOR_DETACH(locks_delete_block)
#endif
#ifndef CAN_WRAP_qdisc_class_hash_destroy
#   define CAN_WRAP_qdisc_class_hash_destroy 1
#endif
#if CAN_WRAP_qdisc_class_hash_destroy
    WRAP_FOR_DETACH(qdisc_class_hash_destroy)
#endif
#ifndef CAN_WRAP_do_fork
#   define CAN_WRAP_do_fork 0
#endif
DETACH(do_fork)
#ifndef CAN_WRAP_dma_common_mmap
#   define CAN_WRAP_dma_common_mmap 1
#endif
#if CAN_WRAP_dma_common_mmap
    WRAP_FOR_DETACH(dma_common_mmap)
#endif
#ifndef CAN_WRAP_hard_smp_processor_id
#   define CAN_WRAP_hard_smp_processor_id 0
#endif
DETACH(hard_smp_processor_id)
#ifndef CAN_WRAP_acpi_nvs_register
#   define CAN_WRAP_acpi_nvs_register 0
#endif
DETACH(acpi_nvs_register)
#ifndef CAN_WRAP_radix_tree_lookup_slot
#   define CAN_WRAP_radix_tree_lookup_slot 1
#endif
#if CAN_WRAP_radix_tree_lookup_slot
    WRAP_FOR_DETACH(radix_tree_lookup_slot)
#endif
#ifndef CAN_WRAP_exit_aio
#   define CAN_WRAP_exit_aio 1
#endif
#if CAN_WRAP_exit_aio
    WRAP_FOR_DETACH(exit_aio)
#endif
#ifndef CAN_WRAP_pcibios_add_platform_entries
#   define CAN_WRAP_pcibios_add_platform_entries 1
#endif
#if CAN_WRAP_pcibios_add_platform_entries
    WRAP_FOR_DETACH(pcibios_add_platform_entries)
#endif
#ifndef CAN_WRAP_swiotlb_tbl_sync_single
#   define CAN_WRAP_swiotlb_tbl_sync_single 1
#endif
#if CAN_WRAP_swiotlb_tbl_sync_single
    WRAP_FOR_DETACH(swiotlb_tbl_sync_single)
#endif
#ifndef CAN_WRAP_sata_set_spd
#   define CAN_WRAP_sata_set_spd 1
#endif
#if CAN_WRAP_sata_set_spd
    WRAP_FOR_DETACH(sata_set_spd)
#endif
#ifndef CAN_WRAP_pci_load_saved_state
#   define CAN_WRAP_pci_load_saved_state 1
#endif
#if CAN_WRAP_pci_load_saved_state
    WRAP_FOR_DETACH(pci_load_saved_state)
#endif
#ifndef CAN_WRAP_netdev_increment_features
#   define CAN_WRAP_netdev_increment_features 0
#endif
DETACH(netdev_increment_features)
#ifndef CAN_WRAP_kick_process
#   define CAN_WRAP_kick_process 1
#endif
#if CAN_WRAP_kick_process
    WRAP_FOR_DETACH(kick_process)
#endif
#ifndef CAN_WRAP_get_physical_broadcast
#   define CAN_WRAP_get_physical_broadcast 0
#endif
DETACH(get_physical_broadcast)
#ifndef CAN_WRAP_memcpy_toiovec
#   define CAN_WRAP_memcpy_toiovec 1
#endif
#if CAN_WRAP_memcpy_toiovec
    WRAP_FOR_DETACH(memcpy_toiovec)
#endif
#ifndef CAN_WRAP_tsc_init
#   define CAN_WRAP_tsc_init 0
#endif
DETACH(tsc_init)
#ifndef CAN_WRAP_ida_init
#   define CAN_WRAP_ida_init 1
#endif
#if CAN_WRAP_ida_init
    WRAP_FOR_DETACH(ida_init)
#endif
#ifndef CAN_WRAP_compare_pnp_id
#   define CAN_WRAP_compare_pnp_id 1
#endif
#if CAN_WRAP_compare_pnp_id
    WRAP_FOR_DETACH(compare_pnp_id)
#endif
#ifndef CAN_WRAP_scm_detach_fds
#   define CAN_WRAP_scm_detach_fds 1
#endif
#if CAN_WRAP_scm_detach_fds
    WRAP_FOR_DETACH(scm_detach_fds)
#endif
#ifndef CAN_WRAP_sock_no_setsockopt
#   define CAN_WRAP_sock_no_setsockopt 1
#endif
#if CAN_WRAP_sock_no_setsockopt
    WRAP_FOR_DETACH(sock_no_setsockopt)
#endif
#ifndef CAN_WRAP_put_disk
#   define CAN_WRAP_put_disk 1
#endif
#if CAN_WRAP_put_disk
    WRAP_FOR_DETACH(put_disk)
#endif
#ifndef CAN_WRAP_wait_task_inactive
#   define CAN_WRAP_wait_task_inactive 1
#endif
#if CAN_WRAP_wait_task_inactive
    WRAP_FOR_DETACH(wait_task_inactive)
#endif
#ifndef CAN_WRAP_flush_work
#   define CAN_WRAP_flush_work 1
#endif
#if CAN_WRAP_flush_work
    WRAP_FOR_DETACH(flush_work)
#endif
#ifndef CAN_WRAP___break_lease
#   define CAN_WRAP___break_lease 1
#endif
#if CAN_WRAP___break_lease
#   ifdef DETACH_ADDR___break_lease
        WRAP_FOR_DETACH(__break_lease)
#   else
        TYPED_DETACH(__break_lease)
#   endif
#endif
#ifndef CAN_WRAP_swiotlb_dma_supported
#   define CAN_WRAP_swiotlb_dma_supported 1
#endif
#if CAN_WRAP_swiotlb_dma_supported
    WRAP_FOR_DETACH(swiotlb_dma_supported)
#endif
#ifndef CAN_WRAP_parse_early_param
#   define CAN_WRAP_parse_early_param 0
#endif
DETACH(parse_early_param)
#ifndef CAN_WRAP___lock_buffer
#   define CAN_WRAP___lock_buffer 1
#endif
#if CAN_WRAP___lock_buffer
#   ifdef DETACH_ADDR___lock_buffer
        WRAP_FOR_DETACH(__lock_buffer)
#   else
        TYPED_DETACH(__lock_buffer)
#   endif
#endif
#ifndef CAN_WRAP_si_meminfo
#   define CAN_WRAP_si_meminfo 1
#endif
#if CAN_WRAP_si_meminfo
    WRAP_FOR_DETACH(si_meminfo)
#endif
#ifndef CAN_WRAP_free_hot_cold_page_list
#   define CAN_WRAP_free_hot_cold_page_list 1
#endif
#if CAN_WRAP_free_hot_cold_page_list
    WRAP_FOR_DETACH(free_hot_cold_page_list)
#endif
#ifndef CAN_WRAP_dquot_set_dqinfo
#   define CAN_WRAP_dquot_set_dqinfo 1
#endif
#if CAN_WRAP_dquot_set_dqinfo
    WRAP_FOR_DETACH(dquot_set_dqinfo)
#endif
#ifndef CAN_WRAP_generic_block_bmap
#   define CAN_WRAP_generic_block_bmap 1
#endif
#if CAN_WRAP_generic_block_bmap
    WRAP_FOR_DETACH(generic_block_bmap)
#endif
#ifndef CAN_WRAP_numa_add_memblk
#   define CAN_WRAP_numa_add_memblk 0
#endif
DETACH(numa_add_memblk)
#ifndef CAN_WRAP_security_bprm_set_creds
#   define CAN_WRAP_security_bprm_set_creds 1
#endif
#if CAN_WRAP_security_bprm_set_creds
    WRAP_FOR_DETACH(security_bprm_set_creds)
#endif
#ifndef CAN_WRAP_sched_clock
#   define CAN_WRAP_sched_clock 0
#endif
DETACH(sched_clock)
#ifndef CAN_WRAP_pci_ext_cfg_avail
#   define CAN_WRAP_pci_ext_cfg_avail 0
#endif
DETACH(pci_ext_cfg_avail)
#ifndef CAN_WRAP_ioremap_prot
#   define CAN_WRAP_ioremap_prot 0
#endif
DETACH(ioremap_prot)
#ifndef CAN_WRAP_mac_pton
#   define CAN_WRAP_mac_pton 0
#endif
DETACH(mac_pton)
#ifndef CAN_WRAP_default_llseek
#   define CAN_WRAP_default_llseek 1
#endif
#if CAN_WRAP_default_llseek
    WRAP_FOR_DETACH(default_llseek)
#endif
#ifndef CAN_WRAP_bio_split
#   define CAN_WRAP_bio_split 1
#endif
#if CAN_WRAP_bio_split
    WRAP_FOR_DETACH(bio_split)
#endif
#ifndef CAN_WRAP_kstrtoul_from_user
#   define CAN_WRAP_kstrtoul_from_user 0
#endif
DETACH(kstrtoul_from_user)
#ifndef CAN_WRAP_unsynchronized_tsc
#   define CAN_WRAP_unsynchronized_tsc 0
#endif
DETACH(unsynchronized_tsc)
#ifndef CAN_WRAP_ramfs_fill_super
#   define CAN_WRAP_ramfs_fill_super 1
#endif
#if CAN_WRAP_ramfs_fill_super
    WRAP_FOR_DETACH(ramfs_fill_super)
#endif
#ifndef CAN_WRAP_mempool_create
#   define CAN_WRAP_mempool_create 1
#endif
#if CAN_WRAP_mempool_create
    WRAP_FOR_DETACH(mempool_create)
#endif
#ifndef CAN_WRAP_report_bug
#   define CAN_WRAP_report_bug 1
#endif
#if CAN_WRAP_report_bug
    WRAP_FOR_DETACH(report_bug)
#endif
#ifndef CAN_WRAP_dmam_free_coherent
#   define CAN_WRAP_dmam_free_coherent 1
#endif
#if CAN_WRAP_dmam_free_coherent
    WRAP_FOR_DETACH(dmam_free_coherent)
#endif
#ifndef CAN_WRAP_kernel_text_address
#   define CAN_WRAP_kernel_text_address 0
#endif
DETACH(kernel_text_address)
#ifndef CAN_WRAP_sysfs_notify_dirent
#   define CAN_WRAP_sysfs_notify_dirent 1
#endif
#if CAN_WRAP_sysfs_notify_dirent
    WRAP_FOR_DETACH(sysfs_notify_dirent)
#endif
#ifndef CAN_WRAP_driver_find
#   define CAN_WRAP_driver_find 1
#endif
#if CAN_WRAP_driver_find
    WRAP_FOR_DETACH(driver_find)
#endif
#ifndef CAN_WRAP_prepare_to_wait_exclusive
#   define CAN_WRAP_prepare_to_wait_exclusive 1
#endif
#if CAN_WRAP_prepare_to_wait_exclusive
    WRAP_FOR_DETACH(prepare_to_wait_exclusive)
#endif
#ifndef CAN_WRAP_proc_tty_unregister_driver
#   define CAN_WRAP_proc_tty_unregister_driver 1
#endif
#if CAN_WRAP_proc_tty_unregister_driver
    WRAP_FOR_DETACH(proc_tty_unregister_driver)
#endif
#ifndef CAN_WRAP_dm_table_get_num_targets
#   define CAN_WRAP_dm_table_get_num_targets 1
#endif
#if CAN_WRAP_dm_table_get_num_targets
    WRAP_FOR_DETACH(dm_table_get_num_targets)
#endif
#ifndef CAN_WRAP_kernel_restart
#   define CAN_WRAP_kernel_restart 0
#endif
DETACH(kernel_restart)
#ifndef CAN_WRAP_pci_register_set_vga_state
#   define CAN_WRAP_pci_register_set_vga_state 1
#endif
#if CAN_WRAP_pci_register_set_vga_state
    WRAP_FOR_DETACH(pci_register_set_vga_state)
#endif
#ifndef CAN_WRAP___module_put_and_exit
#   define CAN_WRAP___module_put_and_exit 1
#endif
#if CAN_WRAP___module_put_and_exit
#   ifdef DETACH_ADDR___module_put_and_exit
        WRAP_FOR_DETACH(__module_put_and_exit)
#   else
        TYPED_DETACH(__module_put_and_exit)
#   endif
#endif
#ifndef CAN_WRAP_security_inode_listsecurity
#   define CAN_WRAP_security_inode_listsecurity 1
#endif
#if CAN_WRAP_security_inode_listsecurity
    WRAP_FOR_DETACH(security_inode_listsecurity)
#endif
#ifndef CAN_WRAP_ida_simple_remove
#   define CAN_WRAP_ida_simple_remove 1
#endif
#if CAN_WRAP_ida_simple_remove
    WRAP_FOR_DETACH(ida_simple_remove)
#endif
#ifndef CAN_WRAP_remove_proc_entry
#   define CAN_WRAP_remove_proc_entry 1
#endif
#if CAN_WRAP_remove_proc_entry
    WRAP_FOR_DETACH(remove_proc_entry)
#endif
#ifndef CAN_WRAP_bit_waitqueue
#   define CAN_WRAP_bit_waitqueue 1
#endif
#if CAN_WRAP_bit_waitqueue
    WRAP_FOR_DETACH(bit_waitqueue)
#endif
#ifndef CAN_WRAP_acpi_penalize_isa_irq
#   define CAN_WRAP_acpi_penalize_isa_irq 0
#endif
DETACH(acpi_penalize_isa_irq)
#ifndef CAN_WRAP_noop_fsync
#   define CAN_WRAP_noop_fsync 1
#endif
#if CAN_WRAP_noop_fsync
    WRAP_FOR_DETACH(noop_fsync)
#endif
#ifndef CAN_WRAP_acpi_blacklisted
#   define CAN_WRAP_acpi_blacklisted 0
#endif
DETACH(acpi_blacklisted)
#ifndef CAN_WRAP___blk_end_request_cur
#   define CAN_WRAP___blk_end_request_cur 1
#endif
#if CAN_WRAP___blk_end_request_cur
#   ifdef DETACH_ADDR___blk_end_request_cur
        WRAP_FOR_DETACH(__blk_end_request_cur)
#   else
        TYPED_DETACH(__blk_end_request_cur)
#   endif
#endif
#ifndef CAN_WRAP_flush_sigqueue
#   define CAN_WRAP_flush_sigqueue 1
#endif
#if CAN_WRAP_flush_sigqueue
    WRAP_FOR_DETACH(flush_sigqueue)
#endif
#ifndef CAN_WRAP_bdput
#   define CAN_WRAP_bdput 1
#endif
#if CAN_WRAP_bdput
    WRAP_FOR_DETACH(bdput)
#endif
#ifndef CAN_WRAP_invalidate_interrupt30
#   define CAN_WRAP_invalidate_interrupt30 0
#endif
DETACH(invalidate_interrupt30)
#ifndef CAN_WRAP_invalidate_interrupt31
#   define CAN_WRAP_invalidate_interrupt31 0
#endif
DETACH(invalidate_interrupt31)
#ifndef CAN_WRAP_clocksource_mmio_init
#   define CAN_WRAP_clocksource_mmio_init 1
#endif
#if CAN_WRAP_clocksource_mmio_init
    WRAP_FOR_DETACH(clocksource_mmio_init)
#endif
#ifndef CAN_WRAP_irq_remove_generic_chip
#   define CAN_WRAP_irq_remove_generic_chip 1
#endif
#if CAN_WRAP_irq_remove_generic_chip
    WRAP_FOR_DETACH(irq_remove_generic_chip)
#endif
#ifndef CAN_WRAP_wmi_evaluate_method
#   define CAN_WRAP_wmi_evaluate_method 1
#endif
#if CAN_WRAP_wmi_evaluate_method
    WRAP_FOR_DETACH(wmi_evaluate_method)
#endif
#ifndef CAN_WRAP_free_area_init
#   define CAN_WRAP_free_area_init 0
#endif
DETACH(free_area_init)
#ifndef CAN_WRAP_pagecache_write_begin
#   define CAN_WRAP_pagecache_write_begin 1
#endif
#if CAN_WRAP_pagecache_write_begin
    WRAP_FOR_DETACH(pagecache_write_begin)
#endif
#ifndef CAN_WRAP_ata_sff_check_status
#   define CAN_WRAP_ata_sff_check_status 1
#endif
#if CAN_WRAP_ata_sff_check_status
    WRAP_FOR_DETACH(ata_sff_check_status)
#endif
#ifndef CAN_WRAP_netdev_refcnt_read
#   define CAN_WRAP_netdev_refcnt_read 1
#endif
#if CAN_WRAP_netdev_refcnt_read
    WRAP_FOR_DETACH(netdev_refcnt_read)
#endif
#ifndef CAN_WRAP_apply_to_page_range
#   define CAN_WRAP_apply_to_page_range 1
#endif
#if CAN_WRAP_apply_to_page_range
    WRAP_FOR_DETACH(apply_to_page_range)
#endif
#ifndef CAN_WRAP___inode_add_bytes
#   define CAN_WRAP___inode_add_bytes 1
#endif
#if CAN_WRAP___inode_add_bytes
#   ifdef DETACH_ADDR___inode_add_bytes
        WRAP_FOR_DETACH(__inode_add_bytes)
#   else
        TYPED_DETACH(__inode_add_bytes)
#   endif
#endif
#ifndef CAN_WRAP_copy_user_enhanced_fast_string
#   define CAN_WRAP_copy_user_enhanced_fast_string 0
#endif
DETACH(copy_user_enhanced_fast_string)
#ifndef CAN_WRAP_security_shm_associate
#   define CAN_WRAP_security_shm_associate 1
#endif
#if CAN_WRAP_security_shm_associate
    WRAP_FOR_DETACH(security_shm_associate)
#endif
#ifndef CAN_WRAP_ata_xfer_mode2shift
#   define CAN_WRAP_ata_xfer_mode2shift 0
#endif
DETACH(ata_xfer_mode2shift)
#ifndef CAN_WRAP_pci_reassign_resource
#   define CAN_WRAP_pci_reassign_resource 1
#endif
#if CAN_WRAP_pci_reassign_resource
    WRAP_FOR_DETACH(pci_reassign_resource)
#endif
#ifndef CAN_WRAP_rcu_irq_exit
#   define CAN_WRAP_rcu_irq_exit 0
#endif
DETACH(rcu_irq_exit)
#ifndef CAN_WRAP_param_set_int
#   define CAN_WRAP_param_set_int 1
#endif
#if CAN_WRAP_param_set_int
    WRAP_FOR_DETACH(param_set_int)
#endif
#ifndef CAN_WRAP_nf_ct_attach
#   define CAN_WRAP_nf_ct_attach 1
#endif
#if CAN_WRAP_nf_ct_attach
    WRAP_FOR_DETACH(nf_ct_attach)
#endif
#ifndef CAN_WRAP_msrs_free
#   define CAN_WRAP_msrs_free 1
#endif
#if CAN_WRAP_msrs_free
    WRAP_FOR_DETACH(msrs_free)
#endif
#ifndef CAN_WRAP_netif_stacked_transfer_operstate
#   define CAN_WRAP_netif_stacked_transfer_operstate 1
#endif
#if CAN_WRAP_netif_stacked_transfer_operstate
    WRAP_FOR_DETACH(netif_stacked_transfer_operstate)
#endif
#ifndef CAN_WRAP_single_open
#   define CAN_WRAP_single_open 1
#endif
#if CAN_WRAP_single_open
    WRAP_FOR_DETACH(single_open)
#endif
#ifndef CAN_WRAP_pci_walk_bus
#   define CAN_WRAP_pci_walk_bus 1
#endif
#if CAN_WRAP_pci_walk_bus
    WRAP_FOR_DETACH(pci_walk_bus)
#endif
#ifndef CAN_WRAP_tick_get_broadcast_mask
#   define CAN_WRAP_tick_get_broadcast_mask 1
#endif
#if CAN_WRAP_tick_get_broadcast_mask
    WRAP_FOR_DETACH(tick_get_broadcast_mask)
#endif
#ifndef CAN_WRAP_sync_dirty_buffer
#   define CAN_WRAP_sync_dirty_buffer 1
#endif
#if CAN_WRAP_sync_dirty_buffer
    WRAP_FOR_DETACH(sync_dirty_buffer)
#endif
#ifndef CAN_WRAP___sock_recv_timestamp
#   define CAN_WRAP___sock_recv_timestamp 1
#endif
#if CAN_WRAP___sock_recv_timestamp
#   ifdef DETACH_ADDR___sock_recv_timestamp
        WRAP_FOR_DETACH(__sock_recv_timestamp)
#   else
        TYPED_DETACH(__sock_recv_timestamp)
#   endif
#endif
#ifndef CAN_WRAP_page_alloc_init
#   define CAN_WRAP_page_alloc_init 0
#endif
DETACH(page_alloc_init)
#ifndef CAN_WRAP_fiemap_fill_next_extent
#   define CAN_WRAP_fiemap_fill_next_extent 1
#endif
#if CAN_WRAP_fiemap_fill_next_extent
    WRAP_FOR_DETACH(fiemap_fill_next_extent)
#endif
#ifndef CAN_WRAP_init_cdrom_command
#   define CAN_WRAP_init_cdrom_command 1
#endif
#if CAN_WRAP_init_cdrom_command
    WRAP_FOR_DETACH(init_cdrom_command)
#endif
#ifndef CAN_WRAP_arch_align_stack
#   define CAN_WRAP_arch_align_stack 0
#endif
DETACH(arch_align_stack)
#ifndef CAN_WRAP_phys_mem_access_prot_allowed
#   define CAN_WRAP_phys_mem_access_prot_allowed 1
#endif
#if CAN_WRAP_phys_mem_access_prot_allowed
    WRAP_FOR_DETACH(phys_mem_access_prot_allowed)
#endif
#ifndef CAN_WRAP___brelse
#   define CAN_WRAP___brelse 1
#endif
#if CAN_WRAP___brelse
#   ifdef DETACH_ADDR___brelse
        WRAP_FOR_DETACH(__brelse)
#   else
        TYPED_DETACH(__brelse)
#   endif
#endif
#ifndef CAN_WRAP_input_allocate_device
#   define CAN_WRAP_input_allocate_device 1
#endif
#if CAN_WRAP_input_allocate_device
    WRAP_FOR_DETACH(input_allocate_device)
#endif
#ifndef CAN_WRAP_register_security
#   define CAN_WRAP_register_security 1
#endif
#if CAN_WRAP_register_security
    WRAP_FOR_DETACH(register_security)
#endif
#ifndef CAN_WRAP_acpi_bus_get_status_handle
#   define CAN_WRAP_acpi_bus_get_status_handle 0
#endif
DETACH(acpi_bus_get_status_handle)
#ifndef CAN_WRAP___skb_tx_hash
#   define CAN_WRAP___skb_tx_hash 1
#endif
#if CAN_WRAP___skb_tx_hash
#   ifdef DETACH_ADDR___skb_tx_hash
        WRAP_FOR_DETACH(__skb_tx_hash)
#   else
        TYPED_DETACH(__skb_tx_hash)
#   endif
#endif
#ifndef CAN_WRAP_pci_no_aer
#   define CAN_WRAP_pci_no_aer 0
#endif
DETACH(pci_no_aer)
#ifndef CAN_WRAP_blk_verify_command
#   define CAN_WRAP_blk_verify_command 0
#endif
DETACH(blk_verify_command)
#ifndef CAN_WRAP_set_cpu_sd_state_idle
#   define CAN_WRAP_set_cpu_sd_state_idle 0
#endif
DETACH(set_cpu_sd_state_idle)
#ifndef CAN_WRAP_rtnl_lock
#   define CAN_WRAP_rtnl_lock 0
#endif
DETACH(rtnl_lock)
#ifndef CAN_WRAP_bioset_integrity_free
#   define CAN_WRAP_bioset_integrity_free 1
#endif
#if CAN_WRAP_bioset_integrity_free
    WRAP_FOR_DETACH(bioset_integrity_free)
#endif
#ifndef CAN_WRAP_idr_destroy
#   define CAN_WRAP_idr_destroy 1
#endif
#if CAN_WRAP_idr_destroy
    WRAP_FOR_DETACH(idr_destroy)
#endif
#ifndef CAN_WRAP_block_write_full_page_endio
#   define CAN_WRAP_block_write_full_page_endio 1
#endif
#if CAN_WRAP_block_write_full_page_endio
    WRAP_FOR_DETACH(block_write_full_page_endio)
#endif
#ifndef CAN_WRAP_skb_insert
#   define CAN_WRAP_skb_insert 1
#endif
#if CAN_WRAP_skb_insert
    WRAP_FOR_DETACH(skb_insert)
#endif
#ifndef CAN_WRAP_journal_sync_buffer
#   define CAN_WRAP_journal_sync_buffer 1
#endif
#if CAN_WRAP_journal_sync_buffer
    WRAP_FOR_DETACH(journal_sync_buffer)
#endif
#ifndef CAN_WRAP_kobj_child_ns_ops
#   define CAN_WRAP_kobj_child_ns_ops 1
#endif
#if CAN_WRAP_kobj_child_ns_ops
    WRAP_FOR_DETACH(kobj_child_ns_ops)
#endif
#ifndef CAN_WRAP_jiffies_to_usecs
#   define CAN_WRAP_jiffies_to_usecs 0
#endif
DETACH(jiffies_to_usecs)
#ifndef CAN_WRAP_start_thread
#   define CAN_WRAP_start_thread 1
#endif
#if CAN_WRAP_start_thread
    WRAP_FOR_DETACH(start_thread)
#endif
#ifndef CAN_WRAP_cgroup_exit
#   define CAN_WRAP_cgroup_exit 1
#endif
#if CAN_WRAP_cgroup_exit
    WRAP_FOR_DETACH(cgroup_exit)
#endif
#ifndef CAN_WRAP_dma_async_memcpy_pg_to_pg
#   define CAN_WRAP_dma_async_memcpy_pg_to_pg 1
#endif
#if CAN_WRAP_dma_async_memcpy_pg_to_pg
    WRAP_FOR_DETACH(dma_async_memcpy_pg_to_pg)
#endif
#ifndef CAN_WRAP_exportfs_encode_inode_fh
#   define CAN_WRAP_exportfs_encode_inode_fh 1
#endif
#if CAN_WRAP_exportfs_encode_inode_fh
    WRAP_FOR_DETACH(exportfs_encode_inode_fh)
#endif
#ifndef CAN_WRAP_open_exec
#   define CAN_WRAP_open_exec 1
#endif
#if CAN_WRAP_open_exec
    WRAP_FOR_DETACH(open_exec)
#endif
#ifndef CAN_WRAP_pci_bus_insert_busn_res
#   define CAN_WRAP_pci_bus_insert_busn_res 1
#endif
#if CAN_WRAP_pci_bus_insert_busn_res
    WRAP_FOR_DETACH(pci_bus_insert_busn_res)
#endif
#ifndef CAN_WRAP_invalidate_bh_lrus
#   define CAN_WRAP_invalidate_bh_lrus 0
#endif
DETACH(invalidate_bh_lrus)
#ifndef CAN_WRAP_sock_sendmsg
#   define CAN_WRAP_sock_sendmsg 1
#endif
#if CAN_WRAP_sock_sendmsg
    WRAP_FOR_DETACH(sock_sendmsg)
#endif
#ifndef CAN_WRAP_install_special_mapping
#   define CAN_WRAP_install_special_mapping 1
#endif
#if CAN_WRAP_install_special_mapping
    WRAP_FOR_DETACH(install_special_mapping)
#endif
#ifndef CAN_WRAP_elv_set_request
#   define CAN_WRAP_elv_set_request 1
#endif
#if CAN_WRAP_elv_set_request
    WRAP_FOR_DETACH(elv_set_request)
#endif
#ifndef CAN_WRAP_zero_fill_bio
#   define CAN_WRAP_zero_fill_bio 1
#endif
#if CAN_WRAP_zero_fill_bio
    WRAP_FOR_DETACH(zero_fill_bio)
#endif
#ifndef CAN_WRAP_kswapd_stop
#   define CAN_WRAP_kswapd_stop 0
#endif
DETACH(kswapd_stop)
#ifndef CAN_WRAP_nsecs_to_jiffies
#   define CAN_WRAP_nsecs_to_jiffies 0
#endif
DETACH(nsecs_to_jiffies)
#ifndef CAN_WRAP_pci_acpi_crs_quirks
#   define CAN_WRAP_pci_acpi_crs_quirks 0
#endif
DETACH(pci_acpi_crs_quirks)
#ifndef CAN_WRAP_mktime
#   define CAN_WRAP_mktime 0
#endif
DETACH(mktime)
#ifndef CAN_WRAP_mod_timer_pinned
#   define CAN_WRAP_mod_timer_pinned 1
#endif
#if CAN_WRAP_mod_timer_pinned
    WRAP_FOR_DETACH(mod_timer_pinned)
#endif
#ifndef CAN_WRAP_get_active_super
#   define CAN_WRAP_get_active_super 1
#endif
#if CAN_WRAP_get_active_super
    WRAP_FOR_DETACH(get_active_super)
#endif
#ifndef CAN_WRAP_work_busy
#   define CAN_WRAP_work_busy 1
#endif
#if CAN_WRAP_work_busy
    WRAP_FOR_DETACH(work_busy)
#endif
#ifndef CAN_WRAP_pci_bus_remove_resources
#   define CAN_WRAP_pci_bus_remove_resources 1
#endif
#if CAN_WRAP_pci_bus_remove_resources
    WRAP_FOR_DETACH(pci_bus_remove_resources)
#endif
#ifndef CAN_WRAP_sort_main_extable
#   define CAN_WRAP_sort_main_extable 0
#endif
DETACH(sort_main_extable)
#ifndef CAN_WRAP_pnp_request_card_device
#   define CAN_WRAP_pnp_request_card_device 1
#endif
#if CAN_WRAP_pnp_request_card_device
    WRAP_FOR_DETACH(pnp_request_card_device)
#endif
#ifndef CAN_WRAP_ata_std_end_eh
#   define CAN_WRAP_ata_std_end_eh 1
#endif
#if CAN_WRAP_ata_std_end_eh
    WRAP_FOR_DETACH(ata_std_end_eh)
#endif
#ifndef CAN_WRAP_ida_pre_get
#   define CAN_WRAP_ida_pre_get 1
#endif
#if CAN_WRAP_ida_pre_get
    WRAP_FOR_DETACH(ida_pre_get)
#endif
#ifndef CAN_WRAP_sched_clock_tick
#   define CAN_WRAP_sched_clock_tick 0
#endif
DETACH(sched_clock_tick)
#ifndef CAN_WRAP_do_settimeofday
#   define CAN_WRAP_do_settimeofday 1
#endif
#if CAN_WRAP_do_settimeofday
    WRAP_FOR_DETACH(do_settimeofday)
#endif
#ifndef CAN_WRAP_dm_resume
#   define CAN_WRAP_dm_resume 1
#endif
#if CAN_WRAP_dm_resume
    WRAP_FOR_DETACH(dm_resume)
#endif
#ifndef CAN_WRAP_msleep
#   define CAN_WRAP_msleep 0
#endif
DETACH(msleep)
#ifndef CAN_WRAP_inode_newsize_ok
#   define CAN_WRAP_inode_newsize_ok 1
#endif
#if CAN_WRAP_inode_newsize_ok
    WRAP_FOR_DETACH(inode_newsize_ok)
#endif
#ifndef CAN_WRAP_gen_new_estimator
#   define CAN_WRAP_gen_new_estimator 1
#endif
#if CAN_WRAP_gen_new_estimator
    WRAP_FOR_DETACH(gen_new_estimator)
#endif
#ifndef CAN_WRAP_acpi_bus_add
#   define CAN_WRAP_acpi_bus_add 1
#endif
#if CAN_WRAP_acpi_bus_add
    WRAP_FOR_DETACH(acpi_bus_add)
#endif
#ifndef CAN_WRAP_jbd2_journal_destroy_transaction_cache
#   define CAN_WRAP_jbd2_journal_destroy_transaction_cache 0
#endif
DETACH(jbd2_journal_destroy_transaction_cache)
#ifndef CAN_WRAP_disk_unblock_events
#   define CAN_WRAP_disk_unblock_events 1
#endif
#if CAN_WRAP_disk_unblock_events
    WRAP_FOR_DETACH(disk_unblock_events)
#endif
#ifndef CAN_WRAP_swiotlb_sync_single_for_device
#   define CAN_WRAP_swiotlb_sync_single_for_device 1
#endif
#if CAN_WRAP_swiotlb_sync_single_for_device
    WRAP_FOR_DETACH(swiotlb_sync_single_for_device)
#endif
#ifndef CAN_WRAP_skb_append
#   define CAN_WRAP_skb_append 1
#endif
#if CAN_WRAP_skb_append
    WRAP_FOR_DETACH(skb_append)
#endif
#ifndef CAN_WRAP_pci_enable_msi_block
#   define CAN_WRAP_pci_enable_msi_block 1
#endif
#if CAN_WRAP_pci_enable_msi_block
    WRAP_FOR_DETACH(pci_enable_msi_block)
#endif
#ifndef CAN_WRAP_ata_eh_analyze_ncq_error
#   define CAN_WRAP_ata_eh_analyze_ncq_error 1
#endif
#if CAN_WRAP_ata_eh_analyze_ncq_error
    WRAP_FOR_DETACH(ata_eh_analyze_ncq_error)
#endif
#ifndef CAN_WRAP_jbd2_journal_force_commit
#   define CAN_WRAP_jbd2_journal_force_commit 1
#endif
#if CAN_WRAP_jbd2_journal_force_commit
    WRAP_FOR_DETACH(jbd2_journal_force_commit)
#endif
#ifndef CAN_WRAP_bioset_integrity_create
#   define CAN_WRAP_bioset_integrity_create 1
#endif
#if CAN_WRAP_bioset_integrity_create
    WRAP_FOR_DETACH(bioset_integrity_create)
#endif
#ifndef CAN_WRAP___journal_clean_data_list
#   define CAN_WRAP___journal_clean_data_list 1
#endif
#if CAN_WRAP___journal_clean_data_list
#   ifdef DETACH_ADDR___journal_clean_data_list
        WRAP_FOR_DETACH(__journal_clean_data_list)
#   else
        TYPED_DETACH(__journal_clean_data_list)
#   endif
#endif
#ifndef CAN_WRAP_phys_mem_access_prot
#   define CAN_WRAP_phys_mem_access_prot 1
#endif
#if CAN_WRAP_phys_mem_access_prot
    WRAP_FOR_DETACH(phys_mem_access_prot)
#endif
#ifndef CAN_WRAP_end_buffer_async_write
#   define CAN_WRAP_end_buffer_async_write 1
#endif
#if CAN_WRAP_end_buffer_async_write
    WRAP_FOR_DETACH(end_buffer_async_write)
#endif
#ifndef CAN_WRAP_compat_sys_semctl
#   define CAN_WRAP_compat_sys_semctl 0
#endif
DETACH(compat_sys_semctl)
#ifndef CAN_WRAP_security_bprm_check
#   define CAN_WRAP_security_bprm_check 1
#endif
#if CAN_WRAP_security_bprm_check
    WRAP_FOR_DETACH(security_bprm_check)
#endif
#ifndef CAN_WRAP_acpi_os_terminate
#   define CAN_WRAP_acpi_os_terminate 0
#endif
DETACH(acpi_os_terminate)
#ifndef CAN_WRAP_set_disk_ro
#   define CAN_WRAP_set_disk_ro 1
#endif
#if CAN_WRAP_set_disk_ro
    WRAP_FOR_DETACH(set_disk_ro)
#endif
#ifndef CAN_WRAP_pci_get_dma_source
#   define CAN_WRAP_pci_get_dma_source 1
#endif
#if CAN_WRAP_pci_get_dma_source
    WRAP_FOR_DETACH(pci_get_dma_source)
#endif
#ifndef CAN_WRAP_unregister_net_sysctl_table
#   define CAN_WRAP_unregister_net_sysctl_table 1
#endif
#if CAN_WRAP_unregister_net_sysctl_table
    WRAP_FOR_DETACH(unregister_net_sysctl_table)
#endif
#ifndef CAN_WRAP_insert_inode_locked
#   define CAN_WRAP_insert_inode_locked 1
#endif
#if CAN_WRAP_insert_inode_locked
    WRAP_FOR_DETACH(insert_inode_locked)
#endif
#ifndef CAN_WRAP_sk_run_filter
#   define CAN_WRAP_sk_run_filter 1
#endif
#if CAN_WRAP_sk_run_filter
    WRAP_FOR_DETACH(sk_run_filter)
#endif
#ifndef CAN_WRAP_ftrace_int3_handler
#   define CAN_WRAP_ftrace_int3_handler 1
#endif
#if CAN_WRAP_ftrace_int3_handler
    WRAP_FOR_DETACH(ftrace_int3_handler)
#endif
#ifndef CAN_WRAP_mm_access
#   define CAN_WRAP_mm_access 1
#endif
#if CAN_WRAP_mm_access
    WRAP_FOR_DETACH(mm_access)
#endif
#ifndef CAN_WRAP_flush_thread
#   define CAN_WRAP_flush_thread 0
#endif
DETACH(flush_thread)
#ifndef CAN_WRAP_alloc_etherdev_mqs
#   define CAN_WRAP_alloc_etherdev_mqs 1
#endif
#if CAN_WRAP_alloc_etherdev_mqs
    WRAP_FOR_DETACH(alloc_etherdev_mqs)
#endif
#ifndef CAN_WRAP_alloc_disk
#   define CAN_WRAP_alloc_disk 1
#endif
#if CAN_WRAP_alloc_disk
    WRAP_FOR_DETACH(alloc_disk)
#endif
#ifndef CAN_WRAP_sata_scr_valid
#   define CAN_WRAP_sata_scr_valid 1
#endif
#if CAN_WRAP_sata_scr_valid
    WRAP_FOR_DETACH(sata_scr_valid)
#endif
#ifndef CAN_WRAP_inode_get_bytes
#   define CAN_WRAP_inode_get_bytes 1
#endif
#if CAN_WRAP_inode_get_bytes
    WRAP_FOR_DETACH(inode_get_bytes)
#endif
#ifndef CAN_WRAP_acpi_initialize_tables
#   define CAN_WRAP_acpi_initialize_tables 1
#endif
#if CAN_WRAP_acpi_initialize_tables
    WRAP_FOR_DETACH(acpi_initialize_tables)
#endif
#ifndef CAN_WRAP_pci_num_vf
#   define CAN_WRAP_pci_num_vf 1
#endif
#if CAN_WRAP_pci_num_vf
    WRAP_FOR_DETACH(pci_num_vf)
#endif
#ifndef CAN_WRAP_clocksource_register
#   define CAN_WRAP_clocksource_register 1
#endif
#if CAN_WRAP_clocksource_register
    WRAP_FOR_DETACH(clocksource_register)
#endif
#ifndef CAN_WRAP_sockfd_lookup
#   define CAN_WRAP_sockfd_lookup 1
#endif
#if CAN_WRAP_sockfd_lookup
    WRAP_FOR_DETACH(sockfd_lookup)
#endif
#ifndef CAN_WRAP_shrink_all_memory
#   define CAN_WRAP_shrink_all_memory 0
#endif
DETACH(shrink_all_memory)
#ifndef CAN_WRAP___pneigh_lookup
#   define CAN_WRAP___pneigh_lookup 1
#endif
#if CAN_WRAP___pneigh_lookup
#   ifdef DETACH_ADDR___pneigh_lookup
        WRAP_FOR_DETACH(__pneigh_lookup)
#   else
        TYPED_DETACH(__pneigh_lookup)
#   endif
#endif
#ifndef CAN_WRAP_cpus_share_cache
#   define CAN_WRAP_cpus_share_cache 0
#endif
DETACH(cpus_share_cache)
#ifndef CAN_WRAP_compat_alloc_user_space
#   define CAN_WRAP_compat_alloc_user_space 0
#endif
DETACH(compat_alloc_user_space)
#ifndef CAN_WRAP___remove_pages
#   define CAN_WRAP___remove_pages 1
#endif
#if CAN_WRAP___remove_pages
#   ifdef DETACH_ADDR___remove_pages
        WRAP_FOR_DETACH(__remove_pages)
#   else
        TYPED_DETACH(__remove_pages)
#   endif
#endif
#ifndef CAN_WRAP_pm_generic_restore_noirq
#   define CAN_WRAP_pm_generic_restore_noirq 1
#endif
#if CAN_WRAP_pm_generic_restore_noirq
    WRAP_FOR_DETACH(pm_generic_restore_noirq)
#endif
#ifndef CAN_WRAP___sys_recvmmsg
#   define CAN_WRAP___sys_recvmmsg 1
#endif
#if CAN_WRAP___sys_recvmmsg
#   ifdef DETACH_ADDR___sys_recvmmsg
        WRAP_FOR_DETACH(__sys_recvmmsg)
#   else
        TYPED_DETACH(__sys_recvmmsg)
#   endif
#endif
#ifndef CAN_WRAP_proc_dohung_task_timeout_secs
#   define CAN_WRAP_proc_dohung_task_timeout_secs 1
#endif
#if CAN_WRAP_proc_dohung_task_timeout_secs
    WRAP_FOR_DETACH(proc_dohung_task_timeout_secs)
#endif
#ifndef CAN_WRAP_pnp_is_active
#   define CAN_WRAP_pnp_is_active 1
#endif
#if CAN_WRAP_pnp_is_active
    WRAP_FOR_DETACH(pnp_is_active)
#endif
#ifndef CAN_WRAP_task_cputime_adjusted
#   define CAN_WRAP_task_cputime_adjusted 1
#endif
#if CAN_WRAP_task_cputime_adjusted
    WRAP_FOR_DETACH(task_cputime_adjusted)
#endif
#ifndef CAN_WRAP_blk_start_queue
#   define CAN_WRAP_blk_start_queue 1
#endif
#if CAN_WRAP_blk_start_queue
    WRAP_FOR_DETACH(blk_start_queue)
#endif
#ifndef CAN_WRAP_pci_intx
#   define CAN_WRAP_pci_intx 1
#endif
#if CAN_WRAP_pci_intx
    WRAP_FOR_DETACH(pci_intx)
#endif
#ifndef CAN_WRAP_rcu_batches_completed_sched
#   define CAN_WRAP_rcu_batches_completed_sched 0
#endif
DETACH(rcu_batches_completed_sched)
#ifndef CAN_WRAP_key_alloc
#   define CAN_WRAP_key_alloc 1
#endif
#if CAN_WRAP_key_alloc
    WRAP_FOR_DETACH(key_alloc)
#endif
#ifndef CAN_WRAP_ata_std_prereset
#   define CAN_WRAP_ata_std_prereset 1
#endif
#if CAN_WRAP_ata_std_prereset
    WRAP_FOR_DETACH(ata_std_prereset)
#endif
#ifndef CAN_WRAP_sk_unattached_filter_destroy
#   define CAN_WRAP_sk_unattached_filter_destroy 1
#endif
#if CAN_WRAP_sk_unattached_filter_destroy
    WRAP_FOR_DETACH(sk_unattached_filter_destroy)
#endif
#ifndef CAN_WRAP_jiffies_to_timespec
#   define CAN_WRAP_jiffies_to_timespec 1
#endif
#if CAN_WRAP_jiffies_to_timespec
    WRAP_FOR_DETACH(jiffies_to_timespec)
#endif
#ifndef CAN_WRAP_elv_rb_add
#   define CAN_WRAP_elv_rb_add 1
#endif
#if CAN_WRAP_elv_rb_add
    WRAP_FOR_DETACH(elv_rb_add)
#endif
#ifndef CAN_WRAP_kobject_put
#   define CAN_WRAP_kobject_put 1
#endif
#if CAN_WRAP_kobject_put
    WRAP_FOR_DETACH(kobject_put)
#endif
#ifndef CAN_WRAP_current_is_single_threaded
#   define CAN_WRAP_current_is_single_threaded 0
#endif
DETACH(current_is_single_threaded)
#ifndef CAN_WRAP_arch_uprobe_analyze_insn
#   define CAN_WRAP_arch_uprobe_analyze_insn 1
#endif
#if CAN_WRAP_arch_uprobe_analyze_insn
    WRAP_FOR_DETACH(arch_uprobe_analyze_insn)
#endif
#ifndef CAN_WRAP_blk_lookup_devt
#   define CAN_WRAP_blk_lookup_devt 0
#endif
DETACH(blk_lookup_devt)
#ifndef CAN_WRAP_compat_sys_epoll_pwait
#   define CAN_WRAP_compat_sys_epoll_pwait 1
#endif
#if CAN_WRAP_compat_sys_epoll_pwait
    WRAP_FOR_DETACH(compat_sys_epoll_pwait)
#endif
#ifndef CAN_WRAP_mutex_unlock
#   define CAN_WRAP_mutex_unlock 1
#endif
#if CAN_WRAP_mutex_unlock
    WRAP_FOR_DETACH(mutex_unlock)
#endif
#ifndef CAN_WRAP_clockevents_notify
#   define CAN_WRAP_clockevents_notify 0
#endif
DETACH(clockevents_notify)
#ifndef CAN_WRAP_jbd2_journal_init_revoke
#   define CAN_WRAP_jbd2_journal_init_revoke 1
#endif
#if CAN_WRAP_jbd2_journal_init_revoke
    WRAP_FOR_DETACH(jbd2_journal_init_revoke)
#endif
#ifndef CAN_WRAP_ata_bmdma_irq_clear
#   define CAN_WRAP_ata_bmdma_irq_clear 1
#endif
#if CAN_WRAP_ata_bmdma_irq_clear
    WRAP_FOR_DETACH(ata_bmdma_irq_clear)
#endif
#ifndef CAN_WRAP_get_dumpable
#   define CAN_WRAP_get_dumpable 1
#endif
#if CAN_WRAP_get_dumpable
    WRAP_FOR_DETACH(get_dumpable)
#endif
#ifndef CAN_WRAP_jbd2_journal_clear_err
#   define CAN_WRAP_jbd2_journal_clear_err 1
#endif
#if CAN_WRAP_jbd2_journal_clear_err
    WRAP_FOR_DETACH(jbd2_journal_clear_err)
#endif
#ifndef CAN_WRAP_d_genocide
#   define CAN_WRAP_d_genocide 1
#endif
#if CAN_WRAP_d_genocide
    WRAP_FOR_DETACH(d_genocide)
#endif
#ifndef CAN_WRAP___netdev_watchdog_up
#   define CAN_WRAP___netdev_watchdog_up 1
#endif
#if CAN_WRAP___netdev_watchdog_up
#   ifdef DETACH_ADDR___netdev_watchdog_up
        WRAP_FOR_DETACH(__netdev_watchdog_up)
#   else
        TYPED_DETACH(__netdev_watchdog_up)
#   endif
#endif
#ifndef CAN_WRAP_crypto_shash_update
#   define CAN_WRAP_crypto_shash_update 1
#endif
#if CAN_WRAP_crypto_shash_update
    WRAP_FOR_DETACH(crypto_shash_update)
#endif
#ifndef CAN_WRAP_cache_firmware
#   define CAN_WRAP_cache_firmware 0
#endif
DETACH(cache_firmware)
#ifndef CAN_WRAP_zap_huge_pmd
#   define CAN_WRAP_zap_huge_pmd 1
#endif
#if CAN_WRAP_zap_huge_pmd
    WRAP_FOR_DETACH(zap_huge_pmd)
#endif
#ifndef CAN_WRAP___native_set_fixmap
#   define CAN_WRAP___native_set_fixmap 1
#endif
#if CAN_WRAP___native_set_fixmap
#   ifdef DETACH_ADDR___native_set_fixmap
        WRAP_FOR_DETACH(__native_set_fixmap)
#   else
        TYPED_DETACH(__native_set_fixmap)
#   endif
#endif
#ifndef CAN_WRAP_atomic_notifier_chain_register
#   define CAN_WRAP_atomic_notifier_chain_register 1
#endif
#if CAN_WRAP_atomic_notifier_chain_register
    WRAP_FOR_DETACH(atomic_notifier_chain_register)
#endif
#ifndef CAN_WRAP_proc_tty_init
#   define CAN_WRAP_proc_tty_init 0
#endif
DETACH(proc_tty_init)
#ifndef CAN_WRAP_dev_valid_name
#   define CAN_WRAP_dev_valid_name 0
#endif
DETACH(dev_valid_name)
#ifndef CAN_WRAP_blk_get_queue
#   define CAN_WRAP_blk_get_queue 1
#endif
#if CAN_WRAP_blk_get_queue
    WRAP_FOR_DETACH(blk_get_queue)
#endif
#ifndef CAN_WRAP_ata_bmdma_post_internal_cmd
#   define CAN_WRAP_ata_bmdma_post_internal_cmd 1
#endif
#if CAN_WRAP_ata_bmdma_post_internal_cmd
    WRAP_FOR_DETACH(ata_bmdma_post_internal_cmd)
#endif
#ifndef CAN_WRAP_blk_register_queue
#   define CAN_WRAP_blk_register_queue 1
#endif
#if CAN_WRAP_blk_register_queue
    WRAP_FOR_DETACH(blk_register_queue)
#endif
#ifndef CAN_WRAP_d_ancestor
#   define CAN_WRAP_d_ancestor 1
#endif
#if CAN_WRAP_d_ancestor
    WRAP_FOR_DETACH(d_ancestor)
#endif
#ifndef CAN_WRAP_netlink_broadcast
#   define CAN_WRAP_netlink_broadcast 1
#endif
#if CAN_WRAP_netlink_broadcast
    WRAP_FOR_DETACH(netlink_broadcast)
#endif
#ifndef CAN_WRAP_detach_pid
#   define CAN_WRAP_detach_pid 1
#endif
#if CAN_WRAP_detach_pid
    WRAP_FOR_DETACH(detach_pid)
#endif
#ifndef CAN_WRAP_pcie_capability_clear_and_set_word
#   define CAN_WRAP_pcie_capability_clear_and_set_word 1
#endif
#if CAN_WRAP_pcie_capability_clear_and_set_word
    WRAP_FOR_DETACH(pcie_capability_clear_and_set_word)
#endif
#ifndef CAN_WRAP_grab_cache_page_write_begin
#   define CAN_WRAP_grab_cache_page_write_begin 1
#endif
#if CAN_WRAP_grab_cache_page_write_begin
    WRAP_FOR_DETACH(grab_cache_page_write_begin)
#endif
#ifndef CAN_WRAP_neigh_rand_reach_time
#   define CAN_WRAP_neigh_rand_reach_time 0
#endif
DETACH(neigh_rand_reach_time)
#ifndef CAN_WRAP_early_irq_init
#   define CAN_WRAP_early_irq_init 0
#endif
DETACH(early_irq_init)
#ifndef CAN_WRAP_insert_vm_struct
#   define CAN_WRAP_insert_vm_struct 1
#endif
#if CAN_WRAP_insert_vm_struct
    WRAP_FOR_DETACH(insert_vm_struct)
#endif
#ifndef CAN_WRAP___dquot_transfer
#   define CAN_WRAP___dquot_transfer 1
#endif
#if CAN_WRAP___dquot_transfer
#   ifdef DETACH_ADDR___dquot_transfer
        WRAP_FOR_DETACH(__dquot_transfer)
#   else
        TYPED_DETACH(__dquot_transfer)
#   endif
#endif
#ifndef CAN_WRAP_sk_release_kernel
#   define CAN_WRAP_sk_release_kernel 1
#endif
#if CAN_WRAP_sk_release_kernel
    WRAP_FOR_DETACH(sk_release_kernel)
#endif
#ifndef CAN_WRAP_security_quotactl
#   define CAN_WRAP_security_quotactl 1
#endif
#if CAN_WRAP_security_quotactl
    WRAP_FOR_DETACH(security_quotactl)
#endif
#ifndef CAN_WRAP_fprop_local_destroy_percpu
#   define CAN_WRAP_fprop_local_destroy_percpu 1
#endif
#if CAN_WRAP_fprop_local_destroy_percpu
    WRAP_FOR_DETACH(fprop_local_destroy_percpu)
#endif
#ifndef CAN_WRAP___sw_hweight32
#   define CAN_WRAP___sw_hweight32 0
#endif
DETACH(__sw_hweight32)
#ifndef CAN_WRAP__raw_spin_lock_irqsave_nested
#   define CAN_WRAP__raw_spin_lock_irqsave_nested 1
#endif
#if CAN_WRAP__raw_spin_lock_irqsave_nested
    WRAP_FOR_DETACH(_raw_spin_lock_irqsave_nested)
#endif
#ifndef CAN_WRAP_syscall32_setup_pages
#   define CAN_WRAP_syscall32_setup_pages 1
#endif
#if CAN_WRAP_syscall32_setup_pages
    WRAP_FOR_DETACH(syscall32_setup_pages)
#endif
#ifndef CAN_WRAP_free_thread_xstate
#   define CAN_WRAP_free_thread_xstate 1
#endif
#if CAN_WRAP_free_thread_xstate
    WRAP_FOR_DETACH(free_thread_xstate)
#endif
#ifndef CAN_WRAP_lowmem_reserve_ratio_sysctl_handler
#   define CAN_WRAP_lowmem_reserve_ratio_sysctl_handler 1
#endif
#if CAN_WRAP_lowmem_reserve_ratio_sysctl_handler
    WRAP_FOR_DETACH(lowmem_reserve_ratio_sysctl_handler)
#endif
#ifndef CAN_WRAP_pci_get_domain_bus_and_slot
#   define CAN_WRAP_pci_get_domain_bus_and_slot 1
#endif
#if CAN_WRAP_pci_get_domain_bus_and_slot
    WRAP_FOR_DETACH(pci_get_domain_bus_and_slot)
#endif
#ifndef CAN_WRAP_pcibios_get_irq_routing_table
#   define CAN_WRAP_pcibios_get_irq_routing_table 1
#endif
#if CAN_WRAP_pcibios_get_irq_routing_table
    WRAP_FOR_DETACH(pcibios_get_irq_routing_table)
#endif
#ifndef CAN_WRAP_kobject_init_and_add
#   define CAN_WRAP_kobject_init_and_add 1
#endif
#if CAN_WRAP_kobject_init_and_add
    WRAP_FOR_DETACH(kobject_init_and_add)
#endif
#ifndef CAN_WRAP_sk_filter_release_rcu
#   define CAN_WRAP_sk_filter_release_rcu 1
#endif
#if CAN_WRAP_sk_filter_release_rcu
    WRAP_FOR_DETACH(sk_filter_release_rcu)
#endif
#ifndef CAN_WRAP_sched_rt_handler
#   define CAN_WRAP_sched_rt_handler 1
#endif
#if CAN_WRAP_sched_rt_handler
    WRAP_FOR_DETACH(sched_rt_handler)
#endif
#ifndef CAN_WRAP_sync_inode_metadata
#   define CAN_WRAP_sync_inode_metadata 1
#endif
#if CAN_WRAP_sync_inode_metadata
    WRAP_FOR_DETACH(sync_inode_metadata)
#endif
#ifndef CAN_WRAP_mb_cache_destroy
#   define CAN_WRAP_mb_cache_destroy 1
#endif
#if CAN_WRAP_mb_cache_destroy
    WRAP_FOR_DETACH(mb_cache_destroy)
#endif
#ifndef CAN_WRAP_vfs_setxattr
#   define CAN_WRAP_vfs_setxattr 1
#endif
#if CAN_WRAP_vfs_setxattr
    WRAP_FOR_DETACH(vfs_setxattr)
#endif
#ifndef CAN_WRAP_recalc_sigpending_and_wake
#   define CAN_WRAP_recalc_sigpending_and_wake 1
#endif
#if CAN_WRAP_recalc_sigpending_and_wake
    WRAP_FOR_DETACH(recalc_sigpending_and_wake)
#endif
#ifndef CAN_WRAP_pcie_update_link_speed
#   define CAN_WRAP_pcie_update_link_speed 1
#endif
#if CAN_WRAP_pcie_update_link_speed
    WRAP_FOR_DETACH(pcie_update_link_speed)
#endif
#ifndef CAN_WRAP_sleep_on
#   define CAN_WRAP_sleep_on 1
#endif
#if CAN_WRAP_sleep_on
    WRAP_FOR_DETACH(sleep_on)
#endif
#ifndef CAN_WRAP_acpi_dev_runtime_suspend
#   define CAN_WRAP_acpi_dev_runtime_suspend 1
#endif
#if CAN_WRAP_acpi_dev_runtime_suspend
    WRAP_FOR_DETACH(acpi_dev_runtime_suspend)
#endif
#ifndef CAN_WRAP_security_fixup_ops
#   define CAN_WRAP_security_fixup_ops 1
#endif
#if CAN_WRAP_security_fixup_ops
    WRAP_FOR_DETACH(security_fixup_ops)
#endif
#ifndef CAN_WRAP_security_path_link
#   define CAN_WRAP_security_path_link 1
#endif
#if CAN_WRAP_security_path_link
    WRAP_FOR_DETACH(security_path_link)
#endif
#ifndef CAN_WRAP_acpi_os_map_memory
#   define CAN_WRAP_acpi_os_map_memory 0
#endif
DETACH(acpi_os_map_memory)
#ifndef CAN_WRAP_ata_tf_to_fis
#   define CAN_WRAP_ata_tf_to_fis 1
#endif
#if CAN_WRAP_ata_tf_to_fis
    WRAP_FOR_DETACH(ata_tf_to_fis)
#endif
#ifndef CAN_WRAP___wait_on_bit_lock
#   define CAN_WRAP___wait_on_bit_lock 1
#endif
#if CAN_WRAP___wait_on_bit_lock
#   ifdef DETACH_ADDR___wait_on_bit_lock
        WRAP_FOR_DETACH(__wait_on_bit_lock)
#   else
        TYPED_DETACH(__wait_on_bit_lock)
#   endif
#endif
#ifndef CAN_WRAP___sw_hweight64
#   define CAN_WRAP___sw_hweight64 0
#endif
DETACH(__sw_hweight64)
#ifndef CAN_WRAP___skb_warn_lro_forwarding
#   define CAN_WRAP___skb_warn_lro_forwarding 1
#endif
#if CAN_WRAP___skb_warn_lro_forwarding
#   ifdef DETACH_ADDR___skb_warn_lro_forwarding
        WRAP_FOR_DETACH(__skb_warn_lro_forwarding)
#   else
        TYPED_DETACH(__skb_warn_lro_forwarding)
#   endif
#endif
#ifndef CAN_WRAP_add_disk_randomness
#   define CAN_WRAP_add_disk_randomness 1
#endif
#if CAN_WRAP_add_disk_randomness
    WRAP_FOR_DETACH(add_disk_randomness)
#endif
#ifndef CAN_WRAP_pci_scan_slot
#   define CAN_WRAP_pci_scan_slot 1
#endif
#if CAN_WRAP_pci_scan_slot
    WRAP_FOR_DETACH(pci_scan_slot)
#endif
#ifndef CAN_WRAP_compat_sys_newlstat
#   define CAN_WRAP_compat_sys_newlstat 1
#endif
#if CAN_WRAP_compat_sys_newlstat
    WRAP_FOR_DETACH(compat_sys_newlstat)
#endif
#ifndef CAN_WRAP_mdio_bus_exit
#   define CAN_WRAP_mdio_bus_exit 0
#endif
DETACH(mdio_bus_exit)
#ifndef CAN_WRAP_mnt_drop_write
#   define CAN_WRAP_mnt_drop_write 1
#endif
#if CAN_WRAP_mnt_drop_write
    WRAP_FOR_DETACH(mnt_drop_write)
#endif
#ifndef CAN_WRAP_mount_ns
#   define CAN_WRAP_mount_ns 1
#endif
#if CAN_WRAP_mount_ns
    WRAP_FOR_DETACH(mount_ns)
#endif
#ifndef CAN_WRAP_sata_std_hardreset
#   define CAN_WRAP_sata_std_hardreset 1
#endif
#if CAN_WRAP_sata_std_hardreset
    WRAP_FOR_DETACH(sata_std_hardreset)
#endif
#ifndef CAN_WRAP_jbd2_journal_clear_features
#   define CAN_WRAP_jbd2_journal_clear_features 1
#endif
#if CAN_WRAP_jbd2_journal_clear_features
    WRAP_FOR_DETACH(jbd2_journal_clear_features)
#endif
#ifndef CAN_WRAP_dm_consume_args
#   define CAN_WRAP_dm_consume_args 1
#endif
#if CAN_WRAP_dm_consume_args
    WRAP_FOR_DETACH(dm_consume_args)
#endif
#ifndef CAN_WRAP_pvclock_resume
#   define CAN_WRAP_pvclock_resume 0
#endif
DETACH(pvclock_resume)
#ifndef CAN_WRAP_proc_sched_autogroup_set_nice
#   define CAN_WRAP_proc_sched_autogroup_set_nice 1
#endif
#if CAN_WRAP_proc_sched_autogroup_set_nice
    WRAP_FOR_DETACH(proc_sched_autogroup_set_nice)
#endif
#ifndef CAN_WRAP_compat_sys_timer_settime
#   define CAN_WRAP_compat_sys_timer_settime 1
#endif
#if CAN_WRAP_compat_sys_timer_settime
    WRAP_FOR_DETACH(compat_sys_timer_settime)
#endif
#ifndef CAN_WRAP_print_cfs_rq
#   define CAN_WRAP_print_cfs_rq 1
#endif
#if CAN_WRAP_print_cfs_rq
    WRAP_FOR_DETACH(print_cfs_rq)
#endif
#ifndef CAN_WRAP_is_early_ioremap_ptep
#   define CAN_WRAP_is_early_ioremap_ptep 1
#endif
#if CAN_WRAP_is_early_ioremap_ptep
    WRAP_FOR_DETACH(is_early_ioremap_ptep)
#endif
#ifndef CAN_WRAP_numa_set_node
#   define CAN_WRAP_numa_set_node 0
#endif
DETACH(numa_set_node)
#ifndef CAN_WRAP_irq_reserve_irqs
#   define CAN_WRAP_irq_reserve_irqs 0
#endif
DETACH(irq_reserve_irqs)
#ifndef CAN_WRAP_try_to_del_timer_sync
#   define CAN_WRAP_try_to_del_timer_sync 1
#endif
#if CAN_WRAP_try_to_del_timer_sync
    WRAP_FOR_DETACH(try_to_del_timer_sync)
#endif
#ifndef CAN_WRAP_pneigh_lookup
#   define CAN_WRAP_pneigh_lookup 1
#endif
#if CAN_WRAP_pneigh_lookup
    WRAP_FOR_DETACH(pneigh_lookup)
#endif
#ifndef CAN_WRAP_gen_replace_estimator
#   define CAN_WRAP_gen_replace_estimator 1
#endif
#if CAN_WRAP_gen_replace_estimator
    WRAP_FOR_DETACH(gen_replace_estimator)
#endif
#ifndef CAN_WRAP___skb_recv_datagram
#   define CAN_WRAP___skb_recv_datagram 1
#endif
#if CAN_WRAP___skb_recv_datagram
#   ifdef DETACH_ADDR___skb_recv_datagram
        WRAP_FOR_DETACH(__skb_recv_datagram)
#   else
        TYPED_DETACH(__skb_recv_datagram)
#   endif
#endif
#ifndef CAN_WRAP_device_init_wakeup
#   define CAN_WRAP_device_init_wakeup 1
#endif
#if CAN_WRAP_device_init_wakeup
    WRAP_FOR_DETACH(device_init_wakeup)
#endif
#ifndef CAN_WRAP_jbd2_journal_ack_err
#   define CAN_WRAP_jbd2_journal_ack_err 1
#endif
#if CAN_WRAP_jbd2_journal_ack_err
    WRAP_FOR_DETACH(jbd2_journal_ack_err)
#endif
#ifndef CAN_WRAP_do_sys_settimeofday
#   define CAN_WRAP_do_sys_settimeofday 1
#endif
#if CAN_WRAP_do_sys_settimeofday
    WRAP_FOR_DETACH(do_sys_settimeofday)
#endif
#ifndef CAN_WRAP__raw_read_lock_bh
#   define CAN_WRAP__raw_read_lock_bh 1
#endif
#if CAN_WRAP__raw_read_lock_bh
    WRAP_FOR_DETACH(_raw_read_lock_bh)
#endif
#ifndef CAN_WRAP_srcu_init_notifier_head
#   define CAN_WRAP_srcu_init_notifier_head 1
#endif
#if CAN_WRAP_srcu_init_notifier_head
    WRAP_FOR_DETACH(srcu_init_notifier_head)
#endif
#ifndef CAN_WRAP_dev_set_alias
#   define CAN_WRAP_dev_set_alias 1
#endif
#if CAN_WRAP_dev_set_alias
    WRAP_FOR_DETACH(dev_set_alias)
#endif
#ifndef CAN_WRAP_update_e820
#   define CAN_WRAP_update_e820 0
#endif
DETACH(update_e820)
#ifndef CAN_WRAP_netlink_ack
#   define CAN_WRAP_netlink_ack 1
#endif
#if CAN_WRAP_netlink_ack
    WRAP_FOR_DETACH(netlink_ack)
#endif
#ifndef CAN_WRAP_ata_cable_80wire
#   define CAN_WRAP_ata_cable_80wire 1
#endif
#if CAN_WRAP_ata_cable_80wire
    WRAP_FOR_DETACH(ata_cable_80wire)
#endif
#ifndef CAN_WRAP_blk_queue_start_tag
#   define CAN_WRAP_blk_queue_start_tag 1
#endif
#if CAN_WRAP_blk_queue_start_tag
    WRAP_FOR_DETACH(blk_queue_start_tag)
#endif
#ifndef CAN_WRAP_blkdev_get_by_path
#   define CAN_WRAP_blkdev_get_by_path 1
#endif
#if CAN_WRAP_blkdev_get_by_path
    WRAP_FOR_DETACH(blkdev_get_by_path)
#endif
#ifndef CAN_WRAP_pci_disable_msi
#   define CAN_WRAP_pci_disable_msi 1
#endif
#if CAN_WRAP_pci_disable_msi
    WRAP_FOR_DETACH(pci_disable_msi)
#endif
#ifndef CAN_WRAP_print_hex_dump
#   define CAN_WRAP_print_hex_dump 0
#endif
DETACH(print_hex_dump)
#ifndef CAN_WRAP_acpi_os_get_next_filename
#   define CAN_WRAP_acpi_os_get_next_filename 0
#endif
DETACH(acpi_os_get_next_filename)
#ifndef CAN_WRAP_lock_sock_fast
#   define CAN_WRAP_lock_sock_fast 1
#endif
#if CAN_WRAP_lock_sock_fast
    WRAP_FOR_DETACH(lock_sock_fast)
#endif
#ifndef CAN_WRAP_mdiobus_unregister
#   define CAN_WRAP_mdiobus_unregister 1
#endif
#if CAN_WRAP_mdiobus_unregister
    WRAP_FOR_DETACH(mdiobus_unregister)
#endif
#ifndef CAN_WRAP___devm_request_region
#   define CAN_WRAP___devm_request_region 1
#endif
#if CAN_WRAP___devm_request_region
#   ifdef DETACH_ADDR___devm_request_region
        WRAP_FOR_DETACH(__devm_request_region)
#   else
        TYPED_DETACH(__devm_request_region)
#   endif
#endif
#ifndef CAN_WRAP_alarm_setitimer
#   define CAN_WRAP_alarm_setitimer 0
#endif
DETACH(alarm_setitimer)
#ifndef CAN_WRAP_simple_transaction_read
#   define CAN_WRAP_simple_transaction_read 1
#endif
#if CAN_WRAP_simple_transaction_read
    WRAP_FOR_DETACH(simple_transaction_read)
#endif
#ifndef CAN_WRAP_acpi_remove_address_space_handler
#   define CAN_WRAP_acpi_remove_address_space_handler 1
#endif
#if CAN_WRAP_acpi_remove_address_space_handler
    WRAP_FOR_DETACH(acpi_remove_address_space_handler)
#endif
#ifndef CAN_WRAP___bus_register
#   define CAN_WRAP___bus_register 1
#endif
#if CAN_WRAP___bus_register
#   ifdef DETACH_ADDR___bus_register
        WRAP_FOR_DETACH(__bus_register)
#   else
        TYPED_DETACH(__bus_register)
#   endif
#endif
#ifndef CAN_WRAP_clocksource_mark_unstable
#   define CAN_WRAP_clocksource_mark_unstable 1
#endif
#if CAN_WRAP_clocksource_mark_unstable
    WRAP_FOR_DETACH(clocksource_mark_unstable)
#endif
#ifndef CAN_WRAP_acpi_pic_sci_set_trigger
#   define CAN_WRAP_acpi_pic_sci_set_trigger 0
#endif
DETACH(acpi_pic_sci_set_trigger)
#ifndef CAN_WRAP_netdev_boot_base
#   define CAN_WRAP_netdev_boot_base 0
#endif
DETACH(netdev_boot_base)
#ifndef CAN_WRAP_strncasecmp
#   define CAN_WRAP_strncasecmp 0
#endif
DETACH(strncasecmp)
#ifndef CAN_WRAP_locks_remove_flock
#   define CAN_WRAP_locks_remove_flock 1
#endif
#if CAN_WRAP_locks_remove_flock
    WRAP_FOR_DETACH(locks_remove_flock)
#endif
#ifndef CAN_WRAP_simple_link
#   define CAN_WRAP_simple_link 1
#endif
#if CAN_WRAP_simple_link
    WRAP_FOR_DETACH(simple_link)
#endif
#ifndef CAN_WRAP_kthread_park
#   define CAN_WRAP_kthread_park 1
#endif
#if CAN_WRAP_kthread_park
    WRAP_FOR_DETACH(kthread_park)
#endif
#ifndef CAN_WRAP_acpi_install_interface
#   define CAN_WRAP_acpi_install_interface 0
#endif
DETACH(acpi_install_interface)
#ifndef CAN_WRAP_irq_set_irq_type
#   define CAN_WRAP_irq_set_irq_type 0
#endif
DETACH(irq_set_irq_type)
#ifndef CAN_WRAP_pci_scan_root_bus
#   define CAN_WRAP_pci_scan_root_bus 1
#endif
#if CAN_WRAP_pci_scan_root_bus
    WRAP_FOR_DETACH(pci_scan_root_bus)
#endif
#ifndef CAN_WRAP_simple_open
#   define CAN_WRAP_simple_open 1
#endif
#if CAN_WRAP_simple_open
    WRAP_FOR_DETACH(simple_open)
#endif
#ifndef CAN_WRAP_hugepage_madvise
#   define CAN_WRAP_hugepage_madvise 1
#endif
#if CAN_WRAP_hugepage_madvise
    WRAP_FOR_DETACH(hugepage_madvise)
#endif
#ifndef CAN_WRAP_netfilter_init
#   define CAN_WRAP_netfilter_init 0
#endif
DETACH(netfilter_init)
#ifndef CAN_WRAP_mnt_unpin
#   define CAN_WRAP_mnt_unpin 1
#endif
#if CAN_WRAP_mnt_unpin
    WRAP_FOR_DETACH(mnt_unpin)
#endif
#ifndef CAN_WRAP_mount_single
#   define CAN_WRAP_mount_single 1
#endif
#if CAN_WRAP_mount_single
    WRAP_FOR_DETACH(mount_single)
#endif
#ifndef CAN_WRAP_pnp_register_driver
#   define CAN_WRAP_pnp_register_driver 1
#endif
#if CAN_WRAP_pnp_register_driver
    WRAP_FOR_DETACH(pnp_register_driver)
#endif
#ifndef CAN_WRAP_yama_ptrace_traceme
#   define CAN_WRAP_yama_ptrace_traceme 1
#endif
#if CAN_WRAP_yama_ptrace_traceme
    WRAP_FOR_DETACH(yama_ptrace_traceme)
#endif
#ifndef CAN_WRAP_blk_queue_make_request
#   define CAN_WRAP_blk_queue_make_request 1
#endif
#if CAN_WRAP_blk_queue_make_request
    WRAP_FOR_DETACH(blk_queue_make_request)
#endif
#ifndef CAN_WRAP_device_create_file
#   define CAN_WRAP_device_create_file 1
#endif
#if CAN_WRAP_device_create_file
    WRAP_FOR_DETACH(device_create_file)
#endif
#ifndef CAN_WRAP_acpi_numa_processor_affinity_init
#   define CAN_WRAP_acpi_numa_processor_affinity_init 1
#endif
#if CAN_WRAP_acpi_numa_processor_affinity_init
    WRAP_FOR_DETACH(acpi_numa_processor_affinity_init)
#endif
#ifndef CAN_WRAP_nommu_shrink_inode_mappings
#   define CAN_WRAP_nommu_shrink_inode_mappings 1
#endif
#if CAN_WRAP_nommu_shrink_inode_mappings
    WRAP_FOR_DETACH(nommu_shrink_inode_mappings)
#endif
#ifndef CAN_WRAP_ata_acpi_gtm_xfermask
#   define CAN_WRAP_ata_acpi_gtm_xfermask 1
#endif
#if CAN_WRAP_ata_acpi_gtm_xfermask
    WRAP_FOR_DETACH(ata_acpi_gtm_xfermask)
#endif
#ifndef CAN_WRAP_populate_extra_pmd
#   define CAN_WRAP_populate_extra_pmd 1
#endif
#if CAN_WRAP_populate_extra_pmd
    WRAP_FOR_DETACH(populate_extra_pmd)
#endif
#ifndef CAN_WRAP_srcu_notifier_call_chain
#   define CAN_WRAP_srcu_notifier_call_chain 1
#endif
#if CAN_WRAP_srcu_notifier_call_chain
    WRAP_FOR_DETACH(srcu_notifier_call_chain)
#endif
#ifndef CAN_WRAP_page_is_ram
#   define CAN_WRAP_page_is_ram 0
#endif
DETACH(page_is_ram)
#ifndef CAN_WRAP_fixup_irqs
#   define CAN_WRAP_fixup_irqs 0
#endif
DETACH(fixup_irqs)
#ifndef CAN_WRAP_paravirt_leave_lazy_mmu
#   define CAN_WRAP_paravirt_leave_lazy_mmu 0
#endif
DETACH(paravirt_leave_lazy_mmu)
#ifndef CAN_WRAP_seq_write
#   define CAN_WRAP_seq_write 1
#endif
#if CAN_WRAP_seq_write
    WRAP_FOR_DETACH(seq_write)
#endif
#ifndef CAN_WRAP_ata_xfer_mode2mask
#   define CAN_WRAP_ata_xfer_mode2mask 0
#endif
DETACH(ata_xfer_mode2mask)
#ifndef CAN_WRAP_security_inode_getsecurity
#   define CAN_WRAP_security_inode_getsecurity 1
#endif
#if CAN_WRAP_security_inode_getsecurity
    WRAP_FOR_DETACH(security_inode_getsecurity)
#endif
#ifndef CAN_WRAP_strchr
#   define CAN_WRAP_strchr 0
#endif
DETACH(strchr)
#ifndef CAN_WRAP_inet_twsk_put
#   define CAN_WRAP_inet_twsk_put 1
#endif
#if CAN_WRAP_inet_twsk_put
    WRAP_FOR_DETACH(inet_twsk_put)
#endif
#ifndef CAN_WRAP_vlan_ioctl_set
#   define CAN_WRAP_vlan_ioctl_set 1
#endif
#if CAN_WRAP_vlan_ioctl_set
    WRAP_FOR_DETACH(vlan_ioctl_set)
#endif
#ifndef CAN_WRAP_rtnetlink_send
#   define CAN_WRAP_rtnetlink_send 1
#endif
#if CAN_WRAP_rtnetlink_send
    WRAP_FOR_DETACH(rtnetlink_send)
#endif
#ifndef CAN_WRAP_pci_rescan_bus_bridge_resize
#   define CAN_WRAP_pci_rescan_bus_bridge_resize 1
#endif
#if CAN_WRAP_pci_rescan_bus_bridge_resize
    WRAP_FOR_DETACH(pci_rescan_bus_bridge_resize)
#endif
#ifndef CAN_WRAP_compat_sys_signalfd4
#   define CAN_WRAP_compat_sys_signalfd4 1
#endif
#if CAN_WRAP_compat_sys_signalfd4
    WRAP_FOR_DETACH(compat_sys_signalfd4)
#endif
#ifndef CAN_WRAP_acpi_os_release_lock
#   define CAN_WRAP_acpi_os_release_lock 1
#endif
#if CAN_WRAP_acpi_os_release_lock
    WRAP_FOR_DETACH(acpi_os_release_lock)
#endif
#ifndef CAN_WRAP_pci_release_selected_regions
#   define CAN_WRAP_pci_release_selected_regions 1
#endif
#if CAN_WRAP_pci_release_selected_regions
    WRAP_FOR_DETACH(pci_release_selected_regions)
#endif
#ifndef CAN_WRAP_jbd2_journal_refile_buffer
#   define CAN_WRAP_jbd2_journal_refile_buffer 1
#endif
#if CAN_WRAP_jbd2_journal_refile_buffer
    WRAP_FOR_DETACH(jbd2_journal_refile_buffer)
#endif
#ifndef CAN_WRAP_f_delown
#   define CAN_WRAP_f_delown 1
#endif
#if CAN_WRAP_f_delown
    WRAP_FOR_DETACH(f_delown)
#endif
#ifndef CAN_WRAP_kstrtouint
#   define CAN_WRAP_kstrtouint 0
#endif
DETACH(kstrtouint)
#ifndef CAN_WRAP_ata_dev_classify
#   define CAN_WRAP_ata_dev_classify 1
#endif
#if CAN_WRAP_ata_dev_classify
    WRAP_FOR_DETACH(ata_dev_classify)
#endif
#ifndef CAN_WRAP___page_file_index
#   define CAN_WRAP___page_file_index 1
#endif
#if CAN_WRAP___page_file_index
#   ifdef DETACH_ADDR___page_file_index
        WRAP_FOR_DETACH(__page_file_index)
#   else
        TYPED_DETACH(__page_file_index)
#   endif
#endif
#ifndef CAN_WRAP_early_pfn_in_nid
#   define CAN_WRAP_early_pfn_in_nid 0
#endif
DETACH(early_pfn_in_nid)
#ifndef CAN_WRAP___prop_inc_percpu
#   define CAN_WRAP___prop_inc_percpu 1
#endif
#if CAN_WRAP___prop_inc_percpu
#   ifdef DETACH_ADDR___prop_inc_percpu
        WRAP_FOR_DETACH(__prop_inc_percpu)
#   else
        TYPED_DETACH(__prop_inc_percpu)
#   endif
#endif
#ifndef CAN_WRAP_sata_link_debounce
#   define CAN_WRAP_sata_link_debounce 1
#endif
#if CAN_WRAP_sata_link_debounce
    WRAP_FOR_DETACH(sata_link_debounce)
#endif
#ifndef CAN_WRAP_session_of_pgrp
#   define CAN_WRAP_session_of_pgrp 1
#endif
#if CAN_WRAP_session_of_pgrp
    WRAP_FOR_DETACH(session_of_pgrp)
#endif
#ifndef CAN_WRAP_acpi_attach_data
#   define CAN_WRAP_acpi_attach_data 1
#endif
#if CAN_WRAP_acpi_attach_data
    WRAP_FOR_DETACH(acpi_attach_data)
#endif
#ifndef CAN_WRAP_ioread8
#   define CAN_WRAP_ioread8 0
#endif
DETACH(ioread8)
#ifndef CAN_WRAP_acpi_initialize_objects
#   define CAN_WRAP_acpi_initialize_objects 0
#endif
DETACH(acpi_initialize_objects)
#ifndef CAN_WRAP_bus_register_notifier
#   define CAN_WRAP_bus_register_notifier 1
#endif
#if CAN_WRAP_bus_register_notifier
    WRAP_FOR_DETACH(bus_register_notifier)
#endif
#ifndef CAN_WRAP_pci_enable_ltr
#   define CAN_WRAP_pci_enable_ltr 1
#endif
#if CAN_WRAP_pci_enable_ltr
    WRAP_FOR_DETACH(pci_enable_ltr)
#endif
#ifndef CAN_WRAP_strnlen_user
#   define CAN_WRAP_strnlen_user 0
#endif
DETACH(strnlen_user)
#ifndef CAN_WRAP_scsi_host_put
#   define CAN_WRAP_scsi_host_put 1
#endif
#if CAN_WRAP_scsi_host_put
    WRAP_FOR_DETACH(scsi_host_put)
#endif
#ifndef CAN_WRAP_devm_iounmap
#   define CAN_WRAP_devm_iounmap 1
#endif
#if CAN_WRAP_devm_iounmap
    WRAP_FOR_DETACH(devm_iounmap)
#endif
#ifndef CAN_WRAP_security_socket_accept
#   define CAN_WRAP_security_socket_accept 1
#endif
#if CAN_WRAP_security_socket_accept
    WRAP_FOR_DETACH(security_socket_accept)
#endif
#ifndef CAN_WRAP___bad_ndelay
#   define CAN_WRAP___bad_ndelay 0
#endif
DETACH(__bad_ndelay)
#ifndef CAN_WRAP_bdi_register_dev
#   define CAN_WRAP_bdi_register_dev 1
#endif
#if CAN_WRAP_bdi_register_dev
    WRAP_FOR_DETACH(bdi_register_dev)
#endif
#ifndef CAN_WRAP_ata_scsi_unlock_native_capacity
#   define CAN_WRAP_ata_scsi_unlock_native_capacity 1
#endif
#if CAN_WRAP_ata_scsi_unlock_native_capacity
    WRAP_FOR_DETACH(ata_scsi_unlock_native_capacity)
#endif
#ifndef CAN_WRAP_yama_task_prctl
#   define CAN_WRAP_yama_task_prctl 0
#endif
DETACH(yama_task_prctl)
#ifndef CAN_WRAP_smp_store_boot_cpu_info
#   define CAN_WRAP_smp_store_boot_cpu_info 0
#endif
DETACH(smp_store_boot_cpu_info)
#ifndef CAN_WRAP_netdev_resync_ops
#   define CAN_WRAP_netdev_resync_ops 1
#endif
#if CAN_WRAP_netdev_resync_ops
    WRAP_FOR_DETACH(netdev_resync_ops)
#endif
#ifndef CAN_WRAP_blk_rq_map_kern
#   define CAN_WRAP_blk_rq_map_kern 1
#endif
#if CAN_WRAP_blk_rq_map_kern
    WRAP_FOR_DETACH(blk_rq_map_kern)
#endif
#ifndef CAN_WRAP_param_set_bint
#   define CAN_WRAP_param_set_bint 1
#endif
#if CAN_WRAP_param_set_bint
    WRAP_FOR_DETACH(param_set_bint)
#endif
#ifndef CAN_WRAP_register_cdrom
#   define CAN_WRAP_register_cdrom 1
#endif
#if CAN_WRAP_register_cdrom
    WRAP_FOR_DETACH(register_cdrom)
#endif
#ifndef CAN_WRAP_acpi_check_region
#   define CAN_WRAP_acpi_check_region 0
#endif
DETACH(acpi_check_region)
#ifndef CAN_WRAP_radix_tree_gang_lookup_tag_slot
#   define CAN_WRAP_radix_tree_gang_lookup_tag_slot 1
#endif
#if CAN_WRAP_radix_tree_gang_lookup_tag_slot
    WRAP_FOR_DETACH(radix_tree_gang_lookup_tag_slot)
#endif
#ifndef CAN_WRAP_dio_end_io
#   define CAN_WRAP_dio_end_io 1
#endif
#if CAN_WRAP_dio_end_io
    WRAP_FOR_DETACH(dio_end_io)
#endif
#ifndef CAN_WRAP_mm_take_all_locks
#   define CAN_WRAP_mm_take_all_locks 1
#endif
#if CAN_WRAP_mm_take_all_locks
    WRAP_FOR_DETACH(mm_take_all_locks)
#endif
#ifndef CAN_WRAP_wait_on_page_bit
#   define CAN_WRAP_wait_on_page_bit 1
#endif
#if CAN_WRAP_wait_on_page_bit
    WRAP_FOR_DETACH(wait_on_page_bit)
#endif
#ifndef CAN_WRAP_ctrl_alt_del
#   define CAN_WRAP_ctrl_alt_del 0
#endif
DETACH(ctrl_alt_del)
#ifndef CAN_WRAP_blk_get_request
#   define CAN_WRAP_blk_get_request 1
#endif
#if CAN_WRAP_blk_get_request
    WRAP_FOR_DETACH(blk_get_request)
#endif
#ifndef CAN_WRAP___jbd2_journal_clean_checkpoint_list
#   define CAN_WRAP___jbd2_journal_clean_checkpoint_list 1
#endif
#if CAN_WRAP___jbd2_journal_clean_checkpoint_list
#   ifdef DETACH_ADDR___jbd2_journal_clean_checkpoint_list
        WRAP_FOR_DETACH(__jbd2_journal_clean_checkpoint_list)
#   else
        TYPED_DETACH(__jbd2_journal_clean_checkpoint_list)
#   endif
#endif
#ifndef CAN_WRAP_jbd2_journal_forget
#   define CAN_WRAP_jbd2_journal_forget 1
#endif
#if CAN_WRAP_jbd2_journal_forget
    WRAP_FOR_DETACH(jbd2_journal_forget)
#endif
#ifndef CAN_WRAP_cpu_idle
#   define CAN_WRAP_cpu_idle 0
#endif
DETACH(cpu_idle)
#ifndef CAN_WRAP_release_firmware
#   define CAN_WRAP_release_firmware 1
#endif
#if CAN_WRAP_release_firmware
    WRAP_FOR_DETACH(release_firmware)
#endif
#ifndef CAN_WRAP_copy_user_handle_tail
#   define CAN_WRAP_copy_user_handle_tail 0
#endif
DETACH(copy_user_handle_tail)
#ifndef CAN_WRAP_account_page_redirty
#   define CAN_WRAP_account_page_redirty 1
#endif
#if CAN_WRAP_account_page_redirty
    WRAP_FOR_DETACH(account_page_redirty)
#endif
#ifndef CAN_WRAP_pmdp_set_access_flags
#   define CAN_WRAP_pmdp_set_access_flags 1
#endif
#if CAN_WRAP_pmdp_set_access_flags
    WRAP_FOR_DETACH(pmdp_set_access_flags)
#endif
#ifndef CAN_WRAP_acpi_irq_stats_init
#   define CAN_WRAP_acpi_irq_stats_init 0
#endif
DETACH(acpi_irq_stats_init)
#ifndef CAN_WRAP_in_sched_functions
#   define CAN_WRAP_in_sched_functions 0
#endif
DETACH(in_sched_functions)
#ifndef CAN_WRAP_ksize
#   define CAN_WRAP_ksize 0
#endif
DETACH(ksize)
#ifndef CAN_WRAP_arch_add_memory
#   define CAN_WRAP_arch_add_memory 0
#endif
DETACH(arch_add_memory)
#ifndef CAN_WRAP_get_mp_bus_to_node
#   define CAN_WRAP_get_mp_bus_to_node 0
#endif
DETACH(get_mp_bus_to_node)
#ifndef CAN_WRAP_setup_per_cpu_pageset
#   define CAN_WRAP_setup_per_cpu_pageset 0
#endif
DETACH(setup_per_cpu_pageset)
#ifndef CAN_WRAP_release_resource
#   define CAN_WRAP_release_resource 1
#endif
#if CAN_WRAP_release_resource
    WRAP_FOR_DETACH(release_resource)
#endif
#ifndef CAN_WRAP___group_send_sig_info
#   define CAN_WRAP___group_send_sig_info 1
#endif
#if CAN_WRAP___group_send_sig_info
#   ifdef DETACH_ADDR___group_send_sig_info
        WRAP_FOR_DETACH(__group_send_sig_info)
#   else
        TYPED_DETACH(__group_send_sig_info)
#   endif
#endif
#ifndef CAN_WRAP_proto_register
#   define CAN_WRAP_proto_register 1
#endif
#if CAN_WRAP_proto_register
    WRAP_FOR_DETACH(proto_register)
#endif
#ifndef CAN_WRAP_acpi_video_display_switch_support
#   define CAN_WRAP_acpi_video_display_switch_support 0
#endif
DETACH(acpi_video_display_switch_support)
#ifndef CAN_WRAP_acpi_reallocate_root_table
#   define CAN_WRAP_acpi_reallocate_root_table 0
#endif
DETACH(acpi_reallocate_root_table)
#ifndef CAN_WRAP_elv_rb_find
#   define CAN_WRAP_elv_rb_find 1
#endif
#if CAN_WRAP_elv_rb_find
    WRAP_FOR_DETACH(elv_rb_find)
#endif
#ifndef CAN_WRAP_apic_set_eoi_write
#   define CAN_WRAP_apic_set_eoi_write 1
#endif
#if CAN_WRAP_apic_set_eoi_write
    WRAP_FOR_DETACH(apic_set_eoi_write)
#endif
#ifndef CAN_WRAP_acpi_video_get_capabilities
#   define CAN_WRAP_acpi_video_get_capabilities 0
#endif
DETACH(acpi_video_get_capabilities)
#ifndef CAN_WRAP___wait_on_bit
#   define CAN_WRAP___wait_on_bit 1
#endif
#if CAN_WRAP___wait_on_bit
#   ifdef DETACH_ADDR___wait_on_bit
        WRAP_FOR_DETACH(__wait_on_bit)
#   else
        TYPED_DETACH(__wait_on_bit)
#   endif
#endif
#ifndef CAN_WRAP_verify_local_APIC
#   define CAN_WRAP_verify_local_APIC 0
#endif
DETACH(verify_local_APIC)
#ifndef CAN_WRAP_sysfs_schedule_callback
#   define CAN_WRAP_sysfs_schedule_callback 1
#endif
#if CAN_WRAP_sysfs_schedule_callback
    WRAP_FOR_DETACH(sysfs_schedule_callback)
#endif
#ifndef CAN_WRAP_blk_integrity_merge_rq
#   define CAN_WRAP_blk_integrity_merge_rq 1
#endif
#if CAN_WRAP_blk_integrity_merge_rq
    WRAP_FOR_DETACH(blk_integrity_merge_rq)
#endif
#ifndef CAN_WRAP_compat_put_timespec
#   define CAN_WRAP_compat_put_timespec 1
#endif
#if CAN_WRAP_compat_put_timespec
    WRAP_FOR_DETACH(compat_put_timespec)
#endif
#ifndef CAN_WRAP_bio_get_nr_vecs
#   define CAN_WRAP_bio_get_nr_vecs 1
#endif
#if CAN_WRAP_bio_get_nr_vecs
    WRAP_FOR_DETACH(bio_get_nr_vecs)
#endif
#ifndef CAN_WRAP_pci_user_write_config_word
#   define CAN_WRAP_pci_user_write_config_word 1
#endif
#if CAN_WRAP_pci_user_write_config_word
    WRAP_FOR_DETACH(pci_user_write_config_word)
#endif
#ifndef CAN_WRAP_x86_platform_ipi
#   define CAN_WRAP_x86_platform_ipi 0
#endif
DETACH(x86_platform_ipi)
#ifndef CAN_WRAP_security_task_setioprio
#   define CAN_WRAP_security_task_setioprio 1
#endif
#if CAN_WRAP_security_task_setioprio
    WRAP_FOR_DETACH(security_task_setioprio)
#endif
#ifndef CAN_WRAP_device_destroy
#   define CAN_WRAP_device_destroy 1
#endif
#if CAN_WRAP_device_destroy
    WRAP_FOR_DETACH(device_destroy)
#endif
#ifndef CAN_WRAP_ioremap_cache
#   define CAN_WRAP_ioremap_cache 0
#endif
DETACH(ioremap_cache)
#ifndef CAN_WRAP_dev_pm_qos_add_request
#   define CAN_WRAP_dev_pm_qos_add_request 1
#endif
#if CAN_WRAP_dev_pm_qos_add_request
    WRAP_FOR_DETACH(dev_pm_qos_add_request)
#endif
#ifndef CAN_WRAP_jbd2_journal_force_commit_nested
#   define CAN_WRAP_jbd2_journal_force_commit_nested 1
#endif
#if CAN_WRAP_jbd2_journal_force_commit_nested
    WRAP_FOR_DETACH(jbd2_journal_force_commit_nested)
#endif
#ifndef CAN_WRAP_add_disk
#   define CAN_WRAP_add_disk 1
#endif
#if CAN_WRAP_add_disk
    WRAP_FOR_DETACH(add_disk)
#endif
#ifndef CAN_WRAP_pm_generic_suspend_late
#   define CAN_WRAP_pm_generic_suspend_late 1
#endif
#if CAN_WRAP_pm_generic_suspend_late
    WRAP_FOR_DETACH(pm_generic_suspend_late)
#endif
#ifndef CAN_WRAP_skb_dst_set_noref
#   define CAN_WRAP_skb_dst_set_noref 1
#endif
#if CAN_WRAP_skb_dst_set_noref
    WRAP_FOR_DETACH(skb_dst_set_noref)
#endif
#ifndef CAN_WRAP_send_sigurg
#   define CAN_WRAP_send_sigurg 1
#endif
#if CAN_WRAP_send_sigurg
    WRAP_FOR_DETACH(send_sigurg)
#endif
#ifndef CAN_WRAP_driver_for_each_device
#   define CAN_WRAP_driver_for_each_device 1
#endif
#if CAN_WRAP_driver_for_each_device
    WRAP_FOR_DETACH(driver_for_each_device)
#endif
#ifndef CAN_WRAP_cap_settime
#   define CAN_WRAP_cap_settime 1
#endif
#if CAN_WRAP_cap_settime
    WRAP_FOR_DETACH(cap_settime)
#endif
#ifndef CAN_WRAP_current_fs_time
#   define CAN_WRAP_current_fs_time 1
#endif
#if CAN_WRAP_current_fs_time
    WRAP_FOR_DETACH(current_fs_time)
#endif
#ifndef CAN_WRAP_paravirt_patch_call
#   define CAN_WRAP_paravirt_patch_call 0
#endif
DETACH(paravirt_patch_call)
#ifndef CAN_WRAP_sock_prot_inuse_get
#   define CAN_WRAP_sock_prot_inuse_get 1
#endif
#if CAN_WRAP_sock_prot_inuse_get
    WRAP_FOR_DETACH(sock_prot_inuse_get)
#endif
#ifndef CAN_WRAP_rtnl_link_unregister
#   define CAN_WRAP_rtnl_link_unregister 1
#endif
#if CAN_WRAP_rtnl_link_unregister
    WRAP_FOR_DETACH(rtnl_link_unregister)
#endif
#ifndef CAN_WRAP_chrdev_show
#   define CAN_WRAP_chrdev_show 1
#endif
#if CAN_WRAP_chrdev_show
    WRAP_FOR_DETACH(chrdev_show)
#endif
#ifndef CAN_WRAP_handle_nested_irq
#   define CAN_WRAP_handle_nested_irq 0
#endif
DETACH(handle_nested_irq)
#ifndef CAN_WRAP_poll_schedule_timeout
#   define CAN_WRAP_poll_schedule_timeout 1
#endif
#if CAN_WRAP_poll_schedule_timeout
    WRAP_FOR_DETACH(poll_schedule_timeout)
#endif
#ifndef CAN_WRAP_pci_get_device
#   define CAN_WRAP_pci_get_device 1
#endif
#if CAN_WRAP_pci_get_device
    WRAP_FOR_DETACH(pci_get_device)
#endif
#ifndef CAN_WRAP_rb_erase
#   define CAN_WRAP_rb_erase 1
#endif
#if CAN_WRAP_rb_erase
    WRAP_FOR_DETACH(rb_erase)
#endif
#ifndef CAN_WRAP_find_last_bit
#   define CAN_WRAP_find_last_bit 0
#endif
DETACH(find_last_bit)
#ifndef CAN_WRAP_early_trap_init
#   define CAN_WRAP_early_trap_init 0
#endif
DETACH(early_trap_init)
#ifndef CAN_WRAP_input_free_device
#   define CAN_WRAP_input_free_device 1
#endif
#if CAN_WRAP_input_free_device
    WRAP_FOR_DETACH(input_free_device)
#endif
#ifndef CAN_WRAP_syscall_trace_leave
#   define CAN_WRAP_syscall_trace_leave 1
#endif
#if CAN_WRAP_syscall_trace_leave
    WRAP_FOR_DETACH(syscall_trace_leave)
#endif
#ifndef CAN_WRAP_input_unregister_handle
#   define CAN_WRAP_input_unregister_handle 1
#endif
#if CAN_WRAP_input_unregister_handle
    WRAP_FOR_DETACH(input_unregister_handle)
#endif
#ifndef CAN_WRAP_bitmap_parselist_user
#   define CAN_WRAP_bitmap_parselist_user 0
#endif
DETACH(bitmap_parselist_user)
#ifndef CAN_WRAP_igrab
#   define CAN_WRAP_igrab 1
#endif
#if CAN_WRAP_igrab
    WRAP_FOR_DETACH(igrab)
#endif
#ifndef CAN_WRAP_idr_remove_all
#   define CAN_WRAP_idr_remove_all 1
#endif
#if CAN_WRAP_idr_remove_all
    WRAP_FOR_DETACH(idr_remove_all)
#endif
#ifndef CAN_WRAP_dev_seq_start
#   define CAN_WRAP_dev_seq_start 1
#endif
#if CAN_WRAP_dev_seq_start
    WRAP_FOR_DETACH(dev_seq_start)
#endif
#ifndef CAN_WRAP_invalidate_interrupt1
#   define CAN_WRAP_invalidate_interrupt1 0
#endif
DETACH(invalidate_interrupt1)
#ifndef CAN_WRAP_bitmap_ord_to_pos
#   define CAN_WRAP_bitmap_ord_to_pos 0
#endif
DETACH(bitmap_ord_to_pos)
#ifndef CAN_WRAP_param_get_charp
#   define CAN_WRAP_param_get_charp 1
#endif
#if CAN_WRAP_param_get_charp
    WRAP_FOR_DETACH(param_get_charp)
#endif
#ifndef CAN_WRAP_security_old_inode_init_security
#   define CAN_WRAP_security_old_inode_init_security 1
#endif
#if CAN_WRAP_security_old_inode_init_security
    WRAP_FOR_DETACH(security_old_inode_init_security)
#endif
#ifndef CAN_WRAP_acpi_debug_trace
#   define CAN_WRAP_acpi_debug_trace 0
#endif
DETACH(acpi_debug_trace)
#ifndef CAN_WRAP_elevator_exit
#   define CAN_WRAP_elevator_exit 1
#endif
#if CAN_WRAP_elevator_exit
    WRAP_FOR_DETACH(elevator_exit)
#endif
#ifndef CAN_WRAP_blk_start_plug
#   define CAN_WRAP_blk_start_plug 1
#endif
#if CAN_WRAP_blk_start_plug
    WRAP_FOR_DETACH(blk_start_plug)
#endif
#ifndef CAN_WRAP_change_pid
#   define CAN_WRAP_change_pid 1
#endif
#if CAN_WRAP_change_pid
    WRAP_FOR_DETACH(change_pid)
#endif
#ifndef CAN_WRAP_invalidate_interrupt5
#   define CAN_WRAP_invalidate_interrupt5 0
#endif
DETACH(invalidate_interrupt5)
#ifndef CAN_WRAP_detect_ht
#   define CAN_WRAP_detect_ht 1
#endif
#if CAN_WRAP_detect_ht
    WRAP_FOR_DETACH(detect_ht)
#endif
#ifndef CAN_WRAP_mp_save_irq
#   define CAN_WRAP_mp_save_irq 1
#endif
#if CAN_WRAP_mp_save_irq
    WRAP_FOR_DETACH(mp_save_irq)
#endif
#ifndef CAN_WRAP_alg_test
#   define CAN_WRAP_alg_test 0
#endif
DETACH(alg_test)
#ifndef CAN_WRAP_res_counter_charge_locked
#   define CAN_WRAP_res_counter_charge_locked 1
#endif
#if CAN_WRAP_res_counter_charge_locked
    WRAP_FOR_DETACH(res_counter_charge_locked)
#endif
#ifndef CAN_WRAP_pci_assign_resource
#   define CAN_WRAP_pci_assign_resource 1
#endif
#if CAN_WRAP_pci_assign_resource
    WRAP_FOR_DETACH(pci_assign_resource)
#endif
#ifndef CAN_WRAP_e820_setup_gap
#   define CAN_WRAP_e820_setup_gap 0
#endif
DETACH(e820_setup_gap)
#ifndef CAN_WRAP_drop_collected_mounts
#   define CAN_WRAP_drop_collected_mounts 1
#endif
#if CAN_WRAP_drop_collected_mounts
    WRAP_FOR_DETACH(drop_collected_mounts)
#endif
#ifndef CAN_WRAP_blk_recount_segments
#   define CAN_WRAP_blk_recount_segments 1
#endif
#if CAN_WRAP_blk_recount_segments
    WRAP_FOR_DETACH(blk_recount_segments)
#endif
#ifndef CAN_WRAP_skb_clone
#   define CAN_WRAP_skb_clone 1
#endif
#if CAN_WRAP_skb_clone
    WRAP_FOR_DETACH(skb_clone)
#endif
#ifndef CAN_WRAP_kthread_create_on_cpu
#   define CAN_WRAP_kthread_create_on_cpu 1
#endif
#if CAN_WRAP_kthread_create_on_cpu
    WRAP_FOR_DETACH(kthread_create_on_cpu)
#endif
#ifndef CAN_WRAP_delete_from_page_cache
#   define CAN_WRAP_delete_from_page_cache 1
#endif
#if CAN_WRAP_delete_from_page_cache
    WRAP_FOR_DETACH(delete_from_page_cache)
#endif
#ifndef CAN_WRAP__raw_write_unlock_bh
#   define CAN_WRAP__raw_write_unlock_bh 1
#endif
#if CAN_WRAP__raw_write_unlock_bh
    WRAP_FOR_DETACH(_raw_write_unlock_bh)
#endif
#ifndef CAN_WRAP_read_boot_clock
#   define CAN_WRAP_read_boot_clock 1
#endif
#if CAN_WRAP_read_boot_clock
    WRAP_FOR_DETACH(read_boot_clock)
#endif
#ifndef CAN_WRAP___sw_hweight16
#   define CAN_WRAP___sw_hweight16 0
#endif
DETACH(__sw_hweight16)
#ifndef CAN_WRAP_atomic_notifier_call_chain
#   define CAN_WRAP_atomic_notifier_call_chain 1
#endif
#if CAN_WRAP_atomic_notifier_call_chain
    WRAP_FOR_DETACH(atomic_notifier_call_chain)
#endif
#ifndef CAN_WRAP_unregister_dock_notifier
#   define CAN_WRAP_unregister_dock_notifier 1
#endif
#if CAN_WRAP_unregister_dock_notifier
    WRAP_FOR_DETACH(unregister_dock_notifier)
#endif
#ifndef CAN_WRAP_ida_simple_get
#   define CAN_WRAP_ida_simple_get 1
#endif
#if CAN_WRAP_ida_simple_get
    WRAP_FOR_DETACH(ida_simple_get)
#endif
#ifndef CAN_WRAP_clock_was_set
#   define CAN_WRAP_clock_was_set 0
#endif
DETACH(clock_was_set)
#ifndef CAN_WRAP_class_unregister
#   define CAN_WRAP_class_unregister 1
#endif
#if CAN_WRAP_class_unregister
    WRAP_FOR_DETACH(class_unregister)
#endif
#ifndef CAN_WRAP_kmem_cache_alloc
#   define CAN_WRAP_kmem_cache_alloc 1
#endif
#if CAN_WRAP_kmem_cache_alloc
    WRAP_FOR_DETACH(kmem_cache_alloc)
#endif
#ifndef CAN_WRAP_phy_device_create
#   define CAN_WRAP_phy_device_create 1
#endif
#if CAN_WRAP_phy_device_create
    WRAP_FOR_DETACH(phy_device_create)
#endif
#ifndef CAN_WRAP_kill_block_super
#   define CAN_WRAP_kill_block_super 1
#endif
#if CAN_WRAP_kill_block_super
    WRAP_FOR_DETACH(kill_block_super)
#endif
#ifndef CAN_WRAP_dcache_dir_lseek
#   define CAN_WRAP_dcache_dir_lseek 1
#endif
#if CAN_WRAP_dcache_dir_lseek
    WRAP_FOR_DETACH(dcache_dir_lseek)
#endif
#ifndef CAN_WRAP___split_huge_page_pmd
#   define CAN_WRAP___split_huge_page_pmd 1
#endif
#if CAN_WRAP___split_huge_page_pmd
#   ifdef DETACH_ADDR___split_huge_page_pmd
        WRAP_FOR_DETACH(__split_huge_page_pmd)
#   else
        TYPED_DETACH(__split_huge_page_pmd)
#   endif
#endif
#ifndef CAN_WRAP_cap_inode_removexattr
#   define CAN_WRAP_cap_inode_removexattr 1
#endif
#if CAN_WRAP_cap_inode_removexattr
    WRAP_FOR_DETACH(cap_inode_removexattr)
#endif
#ifndef CAN_WRAP_cleanup_highmap
#   define CAN_WRAP_cleanup_highmap 0
#endif
DETACH(cleanup_highmap)
#ifndef CAN_WRAP_arch_setup_additional_pages
#   define CAN_WRAP_arch_setup_additional_pages 1
#endif
#if CAN_WRAP_arch_setup_additional_pages
    WRAP_FOR_DETACH(arch_setup_additional_pages)
#endif
#ifndef CAN_WRAP_laptop_mode_timer_fn
#   define CAN_WRAP_laptop_mode_timer_fn 0
#endif
DETACH(laptop_mode_timer_fn)
#ifndef CAN_WRAP_get_vm_area_caller
#   define CAN_WRAP_get_vm_area_caller 1
#endif
#if CAN_WRAP_get_vm_area_caller
    WRAP_FOR_DETACH(get_vm_area_caller)
#endif
#ifndef CAN_WRAP_security_capable
#   define CAN_WRAP_security_capable 1
#endif
#if CAN_WRAP_security_capable
    WRAP_FOR_DETACH(security_capable)
#endif
#ifndef CAN_WRAP_dev_uc_del
#   define CAN_WRAP_dev_uc_del 1
#endif
#if CAN_WRAP_dev_uc_del
    WRAP_FOR_DETACH(dev_uc_del)
#endif
#ifndef CAN_WRAP_blk_queue_update_dma_pad
#   define CAN_WRAP_blk_queue_update_dma_pad 1
#endif
#if CAN_WRAP_blk_queue_update_dma_pad
    WRAP_FOR_DETACH(blk_queue_update_dma_pad)
#endif
#ifndef CAN_WRAP_native_io_apic_init_mappings
#   define CAN_WRAP_native_io_apic_init_mappings 0
#endif
DETACH(native_io_apic_init_mappings)
#ifndef CAN_WRAP_blkdev_issue_flush
#   define CAN_WRAP_blkdev_issue_flush 1
#endif
#if CAN_WRAP_blkdev_issue_flush
    WRAP_FOR_DETACH(blkdev_issue_flush)
#endif
#ifndef CAN_WRAP_sysfs_init
#   define CAN_WRAP_sysfs_init 0
#endif
DETACH(sysfs_init)
#ifndef CAN_WRAP_elevator_change
#   define CAN_WRAP_elevator_change 1
#endif
#if CAN_WRAP_elevator_change
    WRAP_FOR_DETACH(elevator_change)
#endif
#ifndef CAN_WRAP_d_path
#   define CAN_WRAP_d_path 1
#endif
#if CAN_WRAP_d_path
    WRAP_FOR_DETACH(d_path)
#endif
#ifndef CAN_WRAP_acpi_device_set_power
#   define CAN_WRAP_acpi_device_set_power 1
#endif
#if CAN_WRAP_acpi_device_set_power
    WRAP_FOR_DETACH(acpi_device_set_power)
#endif
#ifndef CAN_WRAP___prop_inc_single
#   define CAN_WRAP___prop_inc_single 1
#endif
#if CAN_WRAP___prop_inc_single
#   ifdef DETACH_ADDR___prop_inc_single
        WRAP_FOR_DETACH(__prop_inc_single)
#   else
        TYPED_DETACH(__prop_inc_single)
#   endif
#endif
#ifndef CAN_WRAP_dquot_commit_info
#   define CAN_WRAP_dquot_commit_info 1
#endif
#if CAN_WRAP_dquot_commit_info
    WRAP_FOR_DETACH(dquot_commit_info)
#endif
#ifndef CAN_WRAP___bad_size_call_parameter
#   define CAN_WRAP___bad_size_call_parameter 0
#endif
DETACH(__bad_size_call_parameter)
#ifndef CAN_WRAP_zap_vma_ptes
#   define CAN_WRAP_zap_vma_ptes 1
#endif
#if CAN_WRAP_zap_vma_ptes
    WRAP_FOR_DETACH(zap_vma_ptes)
#endif
#ifndef CAN_WRAP_kill_pgrp
#   define CAN_WRAP_kill_pgrp 1
#endif
#if CAN_WRAP_kill_pgrp
    WRAP_FOR_DETACH(kill_pgrp)
#endif
#ifndef CAN_WRAP_proc_nr_inodes
#   define CAN_WRAP_proc_nr_inodes 1
#endif
#if CAN_WRAP_proc_nr_inodes
    WRAP_FOR_DETACH(proc_nr_inodes)
#endif
#ifndef CAN_WRAP_dquot_file_open
#   define CAN_WRAP_dquot_file_open 1
#endif
#if CAN_WRAP_dquot_file_open
    WRAP_FOR_DETACH(dquot_file_open)
#endif
#ifndef CAN_WRAP_simple_strtoul
#   define CAN_WRAP_simple_strtoul 0
#endif
DETACH(simple_strtoul)
#ifndef CAN_WRAP_subsys_dev_iter_init
#   define CAN_WRAP_subsys_dev_iter_init 1
#endif
#if CAN_WRAP_subsys_dev_iter_init
    WRAP_FOR_DETACH(subsys_dev_iter_init)
#endif
#ifndef CAN_WRAP_vfs_getattr
#   define CAN_WRAP_vfs_getattr 1
#endif
#if CAN_WRAP_vfs_getattr
    WRAP_FOR_DETACH(vfs_getattr)
#endif
#ifndef CAN_WRAP_flush_kthread_worker
#   define CAN_WRAP_flush_kthread_worker 1
#endif
#if CAN_WRAP_flush_kthread_worker
    WRAP_FOR_DETACH(flush_kthread_worker)
#endif
#ifndef CAN_WRAP_rw_verify_area
#   define CAN_WRAP_rw_verify_area 1
#endif
#if CAN_WRAP_rw_verify_area
    WRAP_FOR_DETACH(rw_verify_area)
#endif
#ifndef CAN_WRAP_vmemmap_pgd_populate
#   define CAN_WRAP_vmemmap_pgd_populate 1
#endif
#if CAN_WRAP_vmemmap_pgd_populate
    WRAP_FOR_DETACH(vmemmap_pgd_populate)
#endif
#ifndef CAN_WRAP_machine_halt
#   define CAN_WRAP_machine_halt 0
#endif
DETACH(machine_halt)
#ifndef CAN_WRAP_strncmp
#   define CAN_WRAP_strncmp 0
#endif
DETACH(strncmp)
#ifndef CAN_WRAP_handle_percpu_devid_irq
#   define CAN_WRAP_handle_percpu_devid_irq 1
#endif
#if CAN_WRAP_handle_percpu_devid_irq
    WRAP_FOR_DETACH(handle_percpu_devid_irq)
#endif
#ifndef CAN_WRAP_acpi_numa_x2apic_affinity_init
#   define CAN_WRAP_acpi_numa_x2apic_affinity_init 1
#endif
#if CAN_WRAP_acpi_numa_x2apic_affinity_init
    WRAP_FOR_DETACH(acpi_numa_x2apic_affinity_init)
#endif
#ifndef CAN_WRAP_dev_addr_add
#   define CAN_WRAP_dev_addr_add 1
#endif
#if CAN_WRAP_dev_addr_add
    WRAP_FOR_DETACH(dev_addr_add)
#endif
#ifndef CAN_WRAP_irq_set_affinity_notifier
#   define CAN_WRAP_irq_set_affinity_notifier 1
#endif
#if CAN_WRAP_irq_set_affinity_notifier
    WRAP_FOR_DETACH(irq_set_affinity_notifier)
#endif
#ifndef CAN_WRAP_setup_secondary_APIC_clock
#   define CAN_WRAP_setup_secondary_APIC_clock 0
#endif
DETACH(setup_secondary_APIC_clock)
#ifndef CAN_WRAP_unmap_kernel_range_noflush
#   define CAN_WRAP_unmap_kernel_range_noflush 0
#endif
DETACH(unmap_kernel_range_noflush)
#ifndef CAN_WRAP_lease_get_mtime
#   define CAN_WRAP_lease_get_mtime 1
#endif
#if CAN_WRAP_lease_get_mtime
    WRAP_FOR_DETACH(lease_get_mtime)
#endif
#ifndef CAN_WRAP_elv_rb_del
#   define CAN_WRAP_elv_rb_del 1
#endif
#if CAN_WRAP_elv_rb_del
    WRAP_FOR_DETACH(elv_rb_del)
#endif
#ifndef CAN_WRAP_mp_register_ioapic
#   define CAN_WRAP_mp_register_ioapic 0
#endif
DETACH(mp_register_ioapic)
#ifndef CAN_WRAP_fcntl_getlease
#   define CAN_WRAP_fcntl_getlease 1
#endif
#if CAN_WRAP_fcntl_getlease
    WRAP_FOR_DETACH(fcntl_getlease)
#endif
#ifndef CAN_WRAP_acpi_device_power_state
#   define CAN_WRAP_acpi_device_power_state 1
#endif
#if CAN_WRAP_acpi_device_power_state
    WRAP_FOR_DETACH(acpi_device_power_state)
#endif
#ifndef CAN_WRAP_is_bad_inode
#   define CAN_WRAP_is_bad_inode 1
#endif
#if CAN_WRAP_is_bad_inode
    WRAP_FOR_DETACH(is_bad_inode)
#endif
#ifndef CAN_WRAP_mask_ioapic_entries
#   define CAN_WRAP_mask_ioapic_entries 0
#endif
DETACH(mask_ioapic_entries)
#ifndef CAN_WRAP_tracepoint_iter_next
#   define CAN_WRAP_tracepoint_iter_next 1
#endif
#if CAN_WRAP_tracepoint_iter_next
    WRAP_FOR_DETACH(tracepoint_iter_next)
#endif
#ifndef CAN_WRAP_class_compat_register
#   define CAN_WRAP_class_compat_register 1
#endif
#if CAN_WRAP_class_compat_register
    WRAP_FOR_DETACH(class_compat_register)
#endif
#ifndef CAN_WRAP_pcibios_disable_device
#   define CAN_WRAP_pcibios_disable_device 1
#endif
#if CAN_WRAP_pcibios_disable_device
    WRAP_FOR_DETACH(pcibios_disable_device)
#endif
#ifndef CAN_WRAP_security_msg_queue_msgsnd
#   define CAN_WRAP_security_msg_queue_msgsnd 1
#endif
#if CAN_WRAP_security_msg_queue_msgsnd
    WRAP_FOR_DETACH(security_msg_queue_msgsnd)
#endif
#ifndef CAN_WRAP_acpi_create_dir
#   define CAN_WRAP_acpi_create_dir 1
#endif
#if CAN_WRAP_acpi_create_dir
    WRAP_FOR_DETACH(acpi_create_dir)
#endif
#ifndef CAN_WRAP_sync_blockdev
#   define CAN_WRAP_sync_blockdev 1
#endif
#if CAN_WRAP_sync_blockdev
    WRAP_FOR_DETACH(sync_blockdev)
#endif
#ifndef CAN_WRAP_memset
#   define CAN_WRAP_memset 0
#endif
DETACH(memset)
#ifndef CAN_WRAP_acpi_install_address_space_handler
#   define CAN_WRAP_acpi_install_address_space_handler 1
#endif
#if CAN_WRAP_acpi_install_address_space_handler
    WRAP_FOR_DETACH(acpi_install_address_space_handler)
#endif
#ifndef CAN_WRAP_groups_alloc
#   define CAN_WRAP_groups_alloc 1
#endif
#if CAN_WRAP_groups_alloc
    WRAP_FOR_DETACH(groups_alloc)
#endif
#ifndef CAN_WRAP_iowrite8_rep
#   define CAN_WRAP_iowrite8_rep 0
#endif
DETACH(iowrite8_rep)
#ifndef CAN_WRAP_security_sb_copy_data
#   define CAN_WRAP_security_sb_copy_data 0
#endif
DETACH(security_sb_copy_data)
#ifndef CAN_WRAP_qdisc_reset
#   define CAN_WRAP_qdisc_reset 1
#endif
#if CAN_WRAP_qdisc_reset
    WRAP_FOR_DETACH(qdisc_reset)
#endif
#ifndef CAN_WRAP_mb_cache_entry_release
#   define CAN_WRAP_mb_cache_entry_release 1
#endif
#if CAN_WRAP_mb_cache_entry_release
    WRAP_FOR_DETACH(mb_cache_entry_release)
#endif
#ifndef CAN_WRAP_cgroup_taskset_next
#   define CAN_WRAP_cgroup_taskset_next 1
#endif
#if CAN_WRAP_cgroup_taskset_next
    WRAP_FOR_DETACH(cgroup_taskset_next)
#endif
#ifndef CAN_WRAP_copy_page_range
#   define CAN_WRAP_copy_page_range 1
#endif
#if CAN_WRAP_copy_page_range
    WRAP_FOR_DETACH(copy_page_range)
#endif
#ifndef CAN_WRAP_kobject_uevent_env
#   define CAN_WRAP_kobject_uevent_env 1
#endif
#if CAN_WRAP_kobject_uevent_env
    WRAP_FOR_DETACH(kobject_uevent_env)
#endif
#ifndef CAN_WRAP___netlink_dump_start
#   define CAN_WRAP___netlink_dump_start 1
#endif
#if CAN_WRAP___netlink_dump_start
#   ifdef DETACH_ADDR___netlink_dump_start
        WRAP_FOR_DETACH(__netlink_dump_start)
#   else
        TYPED_DETACH(__netlink_dump_start)
#   endif
#endif
#ifndef CAN_WRAP_misc_deregister
#   define CAN_WRAP_misc_deregister 1
#endif
#if CAN_WRAP_misc_deregister
    WRAP_FOR_DETACH(misc_deregister)
#endif
#ifndef CAN_WRAP_acpi_table_parse
#   define CAN_WRAP_acpi_table_parse 1
#endif
#if CAN_WRAP_acpi_table_parse
    WRAP_FOR_DETACH(acpi_table_parse)
#endif
#ifndef CAN_WRAP_devm_ioremap_nocache
#   define CAN_WRAP_devm_ioremap_nocache 1
#endif
#if CAN_WRAP_devm_ioremap_nocache
    WRAP_FOR_DETACH(devm_ioremap_nocache)
#endif
#ifndef CAN_WRAP_acpi_os_close_directory
#   define CAN_WRAP_acpi_os_close_directory 0
#endif
DETACH(acpi_os_close_directory)
#ifndef CAN_WRAP_setup_ioapic_ids_from_mpc_nocheck
#   define CAN_WRAP_setup_ioapic_ids_from_mpc_nocheck 0
#endif
DETACH(setup_ioapic_ids_from_mpc_nocheck)
#ifndef CAN_WRAP_do_rt_tgsigqueueinfo
#   define CAN_WRAP_do_rt_tgsigqueueinfo 1
#endif
#if CAN_WRAP_do_rt_tgsigqueueinfo
    WRAP_FOR_DETACH(do_rt_tgsigqueueinfo)
#endif
#ifndef CAN_WRAP_crypto_shash_final
#   define CAN_WRAP_crypto_shash_final 1
#endif
#if CAN_WRAP_crypto_shash_final
    WRAP_FOR_DETACH(crypto_shash_final)
#endif
#ifndef CAN_WRAP_unregister_acpi_bus_type
#   define CAN_WRAP_unregister_acpi_bus_type 1
#endif
#if CAN_WRAP_unregister_acpi_bus_type
    WRAP_FOR_DETACH(unregister_acpi_bus_type)
#endif
#ifndef CAN_WRAP_skb_store_bits
#   define CAN_WRAP_skb_store_bits 1
#endif
#if CAN_WRAP_skb_store_bits
    WRAP_FOR_DETACH(skb_store_bits)
#endif
#ifndef CAN_WRAP_misc_register
#   define CAN_WRAP_misc_register 1
#endif
#if CAN_WRAP_misc_register
    WRAP_FOR_DETACH(misc_register)
#endif
#ifndef CAN_WRAP_pnp_start_dev
#   define CAN_WRAP_pnp_start_dev 1
#endif
#if CAN_WRAP_pnp_start_dev
    WRAP_FOR_DETACH(pnp_start_dev)
#endif
#ifndef CAN_WRAP_acpi_get_data
#   define CAN_WRAP_acpi_get_data 1
#endif
#if CAN_WRAP_acpi_get_data
    WRAP_FOR_DETACH(acpi_get_data)
#endif
#ifndef CAN_WRAP_skb_queue_tail
#   define CAN_WRAP_skb_queue_tail 1
#endif
#if CAN_WRAP_skb_queue_tail
    WRAP_FOR_DETACH(skb_queue_tail)
#endif
#ifndef CAN_WRAP_update_persistent_clock
#   define CAN_WRAP_update_persistent_clock 1
#endif
#if CAN_WRAP_update_persistent_clock
    WRAP_FOR_DETACH(update_persistent_clock)
#endif
#ifndef CAN_WRAP_arch_early_irq_init
#   define CAN_WRAP_arch_early_irq_init 0
#endif
DETACH(arch_early_irq_init)
#ifndef CAN_WRAP_mem_online_node
#   define CAN_WRAP_mem_online_node 0
#endif
DETACH(mem_online_node)
#ifndef CAN_WRAP_acpi_evaluate_object
#   define CAN_WRAP_acpi_evaluate_object 1
#endif
#if CAN_WRAP_acpi_evaluate_object
    WRAP_FOR_DETACH(acpi_evaluate_object)
#endif
#ifndef CAN_WRAP_raw_notifier_chain_register
#   define CAN_WRAP_raw_notifier_chain_register 1
#endif
#if CAN_WRAP_raw_notifier_chain_register
    WRAP_FOR_DETACH(raw_notifier_chain_register)
#endif
#ifndef CAN_WRAP_skb_find_text
#   define CAN_WRAP_skb_find_text 1
#endif
#if CAN_WRAP_skb_find_text
    WRAP_FOR_DETACH(skb_find_text)
#endif
#ifndef CAN_WRAP_APIC_init_uniprocessor
#   define CAN_WRAP_APIC_init_uniprocessor 0
#endif
DETACH(APIC_init_uniprocessor)
#ifndef CAN_WRAP_proc_nr_dentry
#   define CAN_WRAP_proc_nr_dentry 1
#endif
#if CAN_WRAP_proc_nr_dentry
    WRAP_FOR_DETACH(proc_nr_dentry)
#endif
#ifndef CAN_WRAP_wake_bit_function
#   define CAN_WRAP_wake_bit_function 1
#endif
#if CAN_WRAP_wake_bit_function
    WRAP_FOR_DETACH(wake_bit_function)
#endif
#ifndef CAN_WRAP_ata_sff_queue_pio_task
#   define CAN_WRAP_ata_sff_queue_pio_task 1
#endif
#if CAN_WRAP_ata_sff_queue_pio_task
    WRAP_FOR_DETACH(ata_sff_queue_pio_task)
#endif
#ifndef CAN_WRAP_core_kernel_data
#   define CAN_WRAP_core_kernel_data 0
#endif
DETACH(core_kernel_data)
#ifndef CAN_WRAP_kstrtos16_from_user
#   define CAN_WRAP_kstrtos16_from_user 0
#endif
DETACH(kstrtos16_from_user)
#ifndef CAN_WRAP_jbd2_journal_write_revoke_records
#   define CAN_WRAP_jbd2_journal_write_revoke_records 1
#endif
#if CAN_WRAP_jbd2_journal_write_revoke_records
    WRAP_FOR_DETACH(jbd2_journal_write_revoke_records)
#endif
#ifndef CAN_WRAP_dquot_drop
#   define CAN_WRAP_dquot_drop 1
#endif
#if CAN_WRAP_dquot_drop
    WRAP_FOR_DETACH(dquot_drop)
#endif
#ifndef CAN_WRAP_security_file_free
#   define CAN_WRAP_security_file_free 1
#endif
#if CAN_WRAP_security_file_free
    WRAP_FOR_DETACH(security_file_free)
#endif
#ifndef CAN_WRAP___vma_adjust_trans_huge
#   define CAN_WRAP___vma_adjust_trans_huge 1
#endif
#if CAN_WRAP___vma_adjust_trans_huge
#   ifdef DETACH_ADDR___vma_adjust_trans_huge
        WRAP_FOR_DETACH(__vma_adjust_trans_huge)
#   else
        TYPED_DETACH(__vma_adjust_trans_huge)
#   endif
#endif
#ifndef CAN_WRAP_task_nice
#   define CAN_WRAP_task_nice 1
#endif
#if CAN_WRAP_task_nice
    WRAP_FOR_DETACH(task_nice)
#endif
#ifndef CAN_WRAP_cdrom_check_events
#   define CAN_WRAP_cdrom_check_events 1
#endif
#if CAN_WRAP_cdrom_check_events
    WRAP_FOR_DETACH(cdrom_check_events)
#endif
#ifndef CAN_WRAP_blk_end_request_cur
#   define CAN_WRAP_blk_end_request_cur 1
#endif
#if CAN_WRAP_blk_end_request_cur
    WRAP_FOR_DETACH(blk_end_request_cur)
#endif
#ifndef CAN_WRAP_disk_part_iter_exit
#   define CAN_WRAP_disk_part_iter_exit 1
#endif
#if CAN_WRAP_disk_part_iter_exit
    WRAP_FOR_DETACH(disk_part_iter_exit)
#endif
#ifndef CAN_WRAP_tracepoint_probe_register_noupdate
#   define CAN_WRAP_tracepoint_probe_register_noupdate 0
#endif
DETACH(tracepoint_probe_register_noupdate)
#ifndef CAN_WRAP_inet_csk_bind_conflict
#   define CAN_WRAP_inet_csk_bind_conflict 1
#endif
#if CAN_WRAP_inet_csk_bind_conflict
    WRAP_FOR_DETACH(inet_csk_bind_conflict)
#endif
#ifndef CAN_WRAP_input_register_device
#   define CAN_WRAP_input_register_device 1
#endif
#if CAN_WRAP_input_register_device
    WRAP_FOR_DETACH(input_register_device)
#endif
#ifndef CAN_WRAP_local_clock
#   define CAN_WRAP_local_clock 0
#endif
DETACH(local_clock)
#ifndef CAN_WRAP_blk_unprep_request
#   define CAN_WRAP_blk_unprep_request 1
#endif
#if CAN_WRAP_blk_unprep_request
    WRAP_FOR_DETACH(blk_unprep_request)
#endif
#ifndef CAN_WRAP_acpi_pci_osc_control_set
#   define CAN_WRAP_acpi_pci_osc_control_set 0
#endif
DETACH(acpi_pci_osc_control_set)
#ifndef CAN_WRAP_is_module_percpu_address
#   define CAN_WRAP_is_module_percpu_address 0
#endif
DETACH(is_module_percpu_address)
#ifndef CAN_WRAP_dm_underlying_device_busy
#   define CAN_WRAP_dm_underlying_device_busy 1
#endif
#if CAN_WRAP_dm_underlying_device_busy
    WRAP_FOR_DETACH(dm_underlying_device_busy)
#endif
#ifndef CAN_WRAP_pci_sriov_get_totalvfs
#   define CAN_WRAP_pci_sriov_get_totalvfs 1
#endif
#if CAN_WRAP_pci_sriov_get_totalvfs
    WRAP_FOR_DETACH(pci_sriov_get_totalvfs)
#endif
#ifndef CAN_WRAP_wbinvd_on_all_cpus
#   define CAN_WRAP_wbinvd_on_all_cpus 0
#endif
DETACH(wbinvd_on_all_cpus)
#ifndef CAN_WRAP___set_personality
#   define CAN_WRAP___set_personality 0
#endif
DETACH(__set_personality)
#ifndef CAN_WRAP_panic
#   define CAN_WRAP_panic 0
#endif
DETACH(panic)
#ifndef CAN_WRAP_inet_csk_update_pmtu
#   define CAN_WRAP_inet_csk_update_pmtu 1
#endif
#if CAN_WRAP_inet_csk_update_pmtu
    WRAP_FOR_DETACH(inet_csk_update_pmtu)
#endif
#ifndef CAN_WRAP_bdi_wakeup_thread_delayed
#   define CAN_WRAP_bdi_wakeup_thread_delayed 1
#endif
#if CAN_WRAP_bdi_wakeup_thread_delayed
    WRAP_FOR_DETACH(bdi_wakeup_thread_delayed)
#endif
#ifndef CAN_WRAP_acpi_free
#   define CAN_WRAP_acpi_free 0
#endif
DETACH(acpi_free)
#ifndef CAN_WRAP_pci_bus_release_busn_res
#   define CAN_WRAP_pci_bus_release_busn_res 1
#endif
#if CAN_WRAP_pci_bus_release_busn_res
    WRAP_FOR_DETACH(pci_bus_release_busn_res)
#endif
#ifndef CAN_WRAP_arch_report_meminfo
#   define CAN_WRAP_arch_report_meminfo 1
#endif
#if CAN_WRAP_arch_report_meminfo
    WRAP_FOR_DETACH(arch_report_meminfo)
#endif
#ifndef CAN_WRAP_devm_ioremap
#   define CAN_WRAP_devm_ioremap 1
#endif
#if CAN_WRAP_devm_ioremap
    WRAP_FOR_DETACH(devm_ioremap)
#endif
#ifndef CAN_WRAP_sched_autogroup_exit
#   define CAN_WRAP_sched_autogroup_exit 1
#endif
#if CAN_WRAP_sched_autogroup_exit
    WRAP_FOR_DETACH(sched_autogroup_exit)
#endif
#ifndef CAN_WRAP_user_shm_unlock
#   define CAN_WRAP_user_shm_unlock 1
#endif
#if CAN_WRAP_user_shm_unlock
    WRAP_FOR_DETACH(user_shm_unlock)
#endif
#ifndef CAN_WRAP__raw_spin_unlock_irq
#   define CAN_WRAP__raw_spin_unlock_irq 1
#endif
#if CAN_WRAP__raw_spin_unlock_irq
    WRAP_FOR_DETACH(_raw_spin_unlock_irq)
#endif
#ifndef CAN_WRAP___set_special_pids
#   define CAN_WRAP___set_special_pids 1
#endif
#if CAN_WRAP___set_special_pids
#   ifdef DETACH_ADDR___set_special_pids
        WRAP_FOR_DETACH(__set_special_pids)
#   else
        TYPED_DETACH(__set_special_pids)
#   endif
#endif
#ifndef CAN_WRAP_tcp_sock_destruct
#   define CAN_WRAP_tcp_sock_destruct 1
#endif
#if CAN_WRAP_tcp_sock_destruct
    WRAP_FOR_DETACH(tcp_sock_destruct)
#endif
#ifndef CAN_WRAP_simple_rmdir
#   define CAN_WRAP_simple_rmdir 1
#endif
#if CAN_WRAP_simple_rmdir
    WRAP_FOR_DETACH(simple_rmdir)
#endif
#ifndef CAN_WRAP_wait_for_completion_killable
#   define CAN_WRAP_wait_for_completion_killable 1
#endif
#if CAN_WRAP_wait_for_completion_killable
    WRAP_FOR_DETACH(wait_for_completion_killable)
#endif
#ifndef CAN_WRAP_dev_pm_get_subsys_data
#   define CAN_WRAP_dev_pm_get_subsys_data 1
#endif
#if CAN_WRAP_dev_pm_get_subsys_data
    WRAP_FOR_DETACH(dev_pm_get_subsys_data)
#endif
#ifndef CAN_WRAP_put_cmsg
#   define CAN_WRAP_put_cmsg 1
#endif
#if CAN_WRAP_put_cmsg
    WRAP_FOR_DETACH(put_cmsg)
#endif
#ifndef CAN_WRAP_mdiobus_write
#   define CAN_WRAP_mdiobus_write 1
#endif
#if CAN_WRAP_mdiobus_write
    WRAP_FOR_DETACH(mdiobus_write)
#endif
#ifndef CAN_WRAP_do_setitimer
#   define CAN_WRAP_do_setitimer 1
#endif
#if CAN_WRAP_do_setitimer
    WRAP_FOR_DETACH(do_setitimer)
#endif
#ifndef CAN_WRAP_acpi_bus_data_handler
#   define CAN_WRAP_acpi_bus_data_handler 0
#endif
DETACH(acpi_bus_data_handler)
#ifndef CAN_WRAP_elv_may_queue
#   define CAN_WRAP_elv_may_queue 1
#endif
#if CAN_WRAP_elv_may_queue
    WRAP_FOR_DETACH(elv_may_queue)
#endif
#ifndef CAN_WRAP_track_pfn_copy
#   define CAN_WRAP_track_pfn_copy 1
#endif
#if CAN_WRAP_track_pfn_copy
    WRAP_FOR_DETACH(track_pfn_copy)
#endif
#ifndef CAN_WRAP_mutex_trylock
#   define CAN_WRAP_mutex_trylock 1
#endif
#if CAN_WRAP_mutex_trylock
    WRAP_FOR_DETACH(mutex_trylock)
#endif
#ifndef CAN_WRAP_devres_get
#   define CAN_WRAP_devres_get 1
#endif
#if CAN_WRAP_devres_get
    WRAP_FOR_DETACH(devres_get)
#endif
#ifndef CAN_WRAP_get_zeroed_page
#   define CAN_WRAP_get_zeroed_page 0
#endif
DETACH(get_zeroed_page)
#ifndef CAN_WRAP_neigh_sysctl_unregister
#   define CAN_WRAP_neigh_sysctl_unregister 1
#endif
#if CAN_WRAP_neigh_sysctl_unregister
    WRAP_FOR_DETACH(neigh_sysctl_unregister)
#endif
#ifndef CAN_WRAP_blk_cleanup_queue
#   define CAN_WRAP_blk_cleanup_queue 1
#endif
#if CAN_WRAP_blk_cleanup_queue
    WRAP_FOR_DETACH(blk_cleanup_queue)
#endif
#ifndef CAN_WRAP_jbd2_journal_write_metadata_buffer
#   define CAN_WRAP_jbd2_journal_write_metadata_buffer 1
#endif
#if CAN_WRAP_jbd2_journal_write_metadata_buffer
    WRAP_FOR_DETACH(jbd2_journal_write_metadata_buffer)
#endif
#ifndef CAN_WRAP_print_cpu_info
#   define CAN_WRAP_print_cpu_info 1
#endif
#if CAN_WRAP_print_cpu_info
    WRAP_FOR_DETACH(print_cpu_info)
#endif
#ifndef CAN_WRAP___cpu_up
#   define CAN_WRAP___cpu_up 1
#endif
#if CAN_WRAP___cpu_up
#   ifdef DETACH_ADDR___cpu_up
        WRAP_FOR_DETACH(__cpu_up)
#   else
        TYPED_DETACH(__cpu_up)
#   endif
#endif
#ifndef CAN_WRAP_compat_sys_sendmsg
#   define CAN_WRAP_compat_sys_sendmsg 1
#endif
#if CAN_WRAP_compat_sys_sendmsg
    WRAP_FOR_DETACH(compat_sys_sendmsg)
#endif
#ifndef CAN_WRAP_dev_set_mac_address
#   define CAN_WRAP_dev_set_mac_address 1
#endif
#if CAN_WRAP_dev_set_mac_address
    WRAP_FOR_DETACH(dev_set_mac_address)
#endif
#ifndef CAN_WRAP_disk_block_events
#   define CAN_WRAP_disk_block_events 1
#endif
#if CAN_WRAP_disk_block_events
    WRAP_FOR_DETACH(disk_block_events)
#endif
#ifndef CAN_WRAP_resource_alignment
#   define CAN_WRAP_resource_alignment 1
#endif
#if CAN_WRAP_resource_alignment
    WRAP_FOR_DETACH(resource_alignment)
#endif
#ifndef CAN_WRAP_scsi_register_acpi_bus_type
#   define CAN_WRAP_scsi_register_acpi_bus_type 1
#endif
#if CAN_WRAP_scsi_register_acpi_bus_type
    WRAP_FOR_DETACH(scsi_register_acpi_bus_type)
#endif
#ifndef CAN_WRAP_exit_io_context
#   define CAN_WRAP_exit_io_context 1
#endif
#if CAN_WRAP_exit_io_context
    WRAP_FOR_DETACH(exit_io_context)
#endif
#ifndef CAN_WRAP_numa_remove_cpu
#   define CAN_WRAP_numa_remove_cpu 0
#endif
DETACH(numa_remove_cpu)
#ifndef CAN_WRAP_sched_clock_idle_wakeup_event
#   define CAN_WRAP_sched_clock_idle_wakeup_event 0
#endif
DETACH(sched_clock_idle_wakeup_event)
#ifndef CAN_WRAP_memscan
#   define CAN_WRAP_memscan 0
#endif
DETACH(memscan)
#ifndef CAN_WRAP_x86_init_rdrand
#   define CAN_WRAP_x86_init_rdrand 1
#endif
#if CAN_WRAP_x86_init_rdrand
    WRAP_FOR_DETACH(x86_init_rdrand)
#endif
#ifndef CAN_WRAP_ata_sas_port_async_resume
#   define CAN_WRAP_ata_sas_port_async_resume 1
#endif
#if CAN_WRAP_ata_sas_port_async_resume
    WRAP_FOR_DETACH(ata_sas_port_async_resume)
#endif
#ifndef CAN_WRAP_tick_is_oneshot_available
#   define CAN_WRAP_tick_is_oneshot_available 0
#endif
DETACH(tick_is_oneshot_available)
#ifndef CAN_WRAP_seq_open_private
#   define CAN_WRAP_seq_open_private 1
#endif
#if CAN_WRAP_seq_open_private
    WRAP_FOR_DETACH(seq_open_private)
#endif
#ifndef CAN_WRAP_klist_add_head
#   define CAN_WRAP_klist_add_head 1
#endif
#if CAN_WRAP_klist_add_head
    WRAP_FOR_DETACH(klist_add_head)
#endif
#ifndef CAN_WRAP_acpi_enable_gpe
#   define CAN_WRAP_acpi_enable_gpe 0
#endif
DETACH(acpi_enable_gpe)
#ifndef CAN_WRAP___setup_vector_irq
#   define CAN_WRAP___setup_vector_irq 0
#endif
DETACH(__setup_vector_irq)
#ifndef CAN_WRAP_acpi_enter_sleep_state_prep
#   define CAN_WRAP_acpi_enter_sleep_state_prep 0
#endif
DETACH(acpi_enter_sleep_state_prep)
#ifndef CAN_WRAP_device_show_ulong
#   define CAN_WRAP_device_show_ulong 1
#endif
#if CAN_WRAP_device_show_ulong
    WRAP_FOR_DETACH(device_show_ulong)
#endif
#ifndef CAN_WRAP_vfs_read
#   define CAN_WRAP_vfs_read 1
#endif
#if CAN_WRAP_vfs_read
    WRAP_FOR_DETACH(vfs_read)
#endif
#ifndef CAN_WRAP_pnp_get_resource
#   define CAN_WRAP_pnp_get_resource 1
#endif
#if CAN_WRAP_pnp_get_resource
    WRAP_FOR_DETACH(pnp_get_resource)
#endif
#ifndef CAN_WRAP_seq_release
#   define CAN_WRAP_seq_release 1
#endif
#if CAN_WRAP_seq_release
    WRAP_FOR_DETACH(seq_release)
#endif
#ifndef CAN_WRAP_parse_args
#   define CAN_WRAP_parse_args 1
#endif
#if CAN_WRAP_parse_args
    WRAP_FOR_DETACH(parse_args)
#endif
#ifndef CAN_WRAP_nla_put
#   define CAN_WRAP_nla_put 1
#endif
#if CAN_WRAP_nla_put
    WRAP_FOR_DETACH(nla_put)
#endif
#ifndef CAN_WRAP_clockevents_program_event
#   define CAN_WRAP_clockevents_program_event 1
#endif
#if CAN_WRAP_clockevents_program_event
    WRAP_FOR_DETACH(clockevents_program_event)
#endif
#ifndef CAN_WRAP_print_modules
#   define CAN_WRAP_print_modules 0
#endif
DETACH(print_modules)
#ifndef CAN_WRAP_ns_capable
#   define CAN_WRAP_ns_capable 1
#endif
#if CAN_WRAP_ns_capable
    WRAP_FOR_DETACH(ns_capable)
#endif
#ifndef CAN_WRAP_blkdev_issue_zeroout
#   define CAN_WRAP_blkdev_issue_zeroout 1
#endif
#if CAN_WRAP_blkdev_issue_zeroout
    WRAP_FOR_DETACH(blkdev_issue_zeroout)
#endif
#ifndef CAN_WRAP_dma_get_required_mask
#   define CAN_WRAP_dma_get_required_mask 1
#endif
#if CAN_WRAP_dma_get_required_mask
    WRAP_FOR_DETACH(dma_get_required_mask)
#endif
#ifndef CAN_WRAP_clock_was_set_delayed
#   define CAN_WRAP_clock_was_set_delayed 0
#endif
DETACH(clock_was_set_delayed)
#ifndef CAN_WRAP_nla_parse
#   define CAN_WRAP_nla_parse 1
#endif
#if CAN_WRAP_nla_parse
    WRAP_FOR_DETACH(nla_parse)
#endif
#ifndef CAN_WRAP_in_lock_functions
#   define CAN_WRAP_in_lock_functions 0
#endif
DETACH(in_lock_functions)
#ifndef CAN_WRAP_match_int
#   define CAN_WRAP_match_int 1
#endif
#if CAN_WRAP_match_int
    WRAP_FOR_DETACH(match_int)
#endif
#ifndef CAN_WRAP_rtnl_notify
#   define CAN_WRAP_rtnl_notify 1
#endif
#if CAN_WRAP_rtnl_notify
    WRAP_FOR_DETACH(rtnl_notify)
#endif
#ifndef CAN_WRAP_emergency_remount
#   define CAN_WRAP_emergency_remount 0
#endif
DETACH(emergency_remount)
#ifndef CAN_WRAP_cgroup_add_cftypes
#   define CAN_WRAP_cgroup_add_cftypes 1
#endif
#if CAN_WRAP_cgroup_add_cftypes
    WRAP_FOR_DETACH(cgroup_add_cftypes)
#endif
#ifndef CAN_WRAP_file_remove_suid
#   define CAN_WRAP_file_remove_suid 1
#endif
#if CAN_WRAP_file_remove_suid
    WRAP_FOR_DETACH(file_remove_suid)
#endif
#ifndef CAN_WRAP_smp_error_interrupt
#   define CAN_WRAP_smp_error_interrupt 1
#endif
#if CAN_WRAP_smp_error_interrupt
    WRAP_FOR_DETACH(smp_error_interrupt)
#endif
#ifndef CAN_WRAP_softirq_init
#   define CAN_WRAP_softirq_init 0
#endif
DETACH(softirq_init)
#ifndef CAN_WRAP_proc_dointvec_userhz_jiffies
#   define CAN_WRAP_proc_dointvec_userhz_jiffies 1
#endif
#if CAN_WRAP_proc_dointvec_userhz_jiffies
    WRAP_FOR_DETACH(proc_dointvec_userhz_jiffies)
#endif
#ifndef CAN_WRAP_kobj_ns_initial
#   define CAN_WRAP_kobj_ns_initial 0
#endif
DETACH(kobj_ns_initial)
#ifndef CAN_WRAP_crypto_ahash_setkey
#   define CAN_WRAP_crypto_ahash_setkey 1
#endif
#if CAN_WRAP_crypto_ahash_setkey
    WRAP_FOR_DETACH(crypto_ahash_setkey)
#endif
#ifndef CAN_WRAP_raw_pci_write
#   define CAN_WRAP_raw_pci_write 0
#endif
DETACH(raw_pci_write)
#ifndef CAN_WRAP_scsi_rescan_device
#   define CAN_WRAP_scsi_rescan_device 1
#endif
#if CAN_WRAP_scsi_rescan_device
    WRAP_FOR_DETACH(scsi_rescan_device)
#endif
#ifndef CAN_WRAP_input_free_minor
#   define CAN_WRAP_input_free_minor 0
#endif
DETACH(input_free_minor)
#ifndef CAN_WRAP_acpi_walk_namespace
#   define CAN_WRAP_acpi_walk_namespace 1
#endif
#if CAN_WRAP_acpi_walk_namespace
    WRAP_FOR_DETACH(acpi_walk_namespace)
#endif
#ifndef CAN_WRAP_send_sigtrap
#   define CAN_WRAP_send_sigtrap 1
#endif
#if CAN_WRAP_send_sigtrap
    WRAP_FOR_DETACH(send_sigtrap)
#endif
#ifndef CAN_WRAP_add_range
#   define CAN_WRAP_add_range 1
#endif
#if CAN_WRAP_add_range
    WRAP_FOR_DETACH(add_range)
#endif
#ifndef CAN_WRAP_arch_sd_sibiling_asym_packing
#   define CAN_WRAP_arch_sd_sibiling_asym_packing 0
#endif
DETACH(arch_sd_sibiling_asym_packing)
#ifndef CAN_WRAP_open_softirq
#   define CAN_WRAP_open_softirq 1
#endif
#if CAN_WRAP_open_softirq
    WRAP_FOR_DETACH(open_softirq)
#endif
#ifndef CAN_WRAP_dma_memcpy_pg_to_iovec
#   define CAN_WRAP_dma_memcpy_pg_to_iovec 1
#endif
#if CAN_WRAP_dma_memcpy_pg_to_iovec
    WRAP_FOR_DETACH(dma_memcpy_pg_to_iovec)
#endif
#ifndef CAN_WRAP_check_tsc_unstable
#   define CAN_WRAP_check_tsc_unstable 0
#endif
DETACH(check_tsc_unstable)
#ifndef CAN_WRAP_netdev_run_todo
#   define CAN_WRAP_netdev_run_todo 0
#endif
DETACH(netdev_run_todo)
#ifndef CAN_WRAP_pud_clear_bad
#   define CAN_WRAP_pud_clear_bad 1
#endif
#if CAN_WRAP_pud_clear_bad
    WRAP_FOR_DETACH(pud_clear_bad)
#endif
#ifndef CAN_WRAP_request_resource
#   define CAN_WRAP_request_resource 1
#endif
#if CAN_WRAP_request_resource
    WRAP_FOR_DETACH(request_resource)
#endif
#ifndef CAN_WRAP_iomem_is_exclusive
#   define CAN_WRAP_iomem_is_exclusive 0
#endif
DETACH(iomem_is_exclusive)
#ifndef CAN_WRAP_do_writepages
#   define CAN_WRAP_do_writepages 1
#endif
#if CAN_WRAP_do_writepages
    WRAP_FOR_DETACH(do_writepages)
#endif
#ifndef CAN_WRAP_set_cpu_sibling_map
#   define CAN_WRAP_set_cpu_sibling_map 0
#endif
DETACH(set_cpu_sibling_map)
#ifndef CAN_WRAP_keyring_add_key
#   define CAN_WRAP_keyring_add_key 1
#endif
#if CAN_WRAP_keyring_add_key
    WRAP_FOR_DETACH(keyring_add_key)
#endif
#ifndef CAN_WRAP_native_io_apic_write
#   define CAN_WRAP_native_io_apic_write 0
#endif
DETACH(native_io_apic_write)
#ifndef CAN_WRAP_do_group_exit
#   define CAN_WRAP_do_group_exit 0
#endif
DETACH(do_group_exit)
#ifndef CAN_WRAP_zone_grow_waitqueues
#   define CAN_WRAP_zone_grow_waitqueues 1
#endif
#if CAN_WRAP_zone_grow_waitqueues
    WRAP_FOR_DETACH(zone_grow_waitqueues)
#endif
#ifndef CAN_WRAP___alloc_percpu
#   define CAN_WRAP___alloc_percpu 0
#endif
DETACH(__alloc_percpu)
#ifndef CAN_WRAP_find_ge_pid
#   define CAN_WRAP_find_ge_pid 1
#endif
#if CAN_WRAP_find_ge_pid
    WRAP_FOR_DETACH(find_ge_pid)
#endif
#ifndef CAN_WRAP_posix_acl_valid
#   define CAN_WRAP_posix_acl_valid 1
#endif
#if CAN_WRAP_posix_acl_valid
    WRAP_FOR_DETACH(posix_acl_valid)
#endif
#ifndef CAN_WRAP_do_truncate
#   define CAN_WRAP_do_truncate 1
#endif
#if CAN_WRAP_do_truncate
    WRAP_FOR_DETACH(do_truncate)
#endif
#ifndef CAN_WRAP_dev_pm_qos_expose_latency_limit
#   define CAN_WRAP_dev_pm_qos_expose_latency_limit 1
#endif
#if CAN_WRAP_dev_pm_qos_expose_latency_limit
    WRAP_FOR_DETACH(dev_pm_qos_expose_latency_limit)
#endif
#ifndef CAN_WRAP_attach_pid
#   define CAN_WRAP_attach_pid 1
#endif
#if CAN_WRAP_attach_pid
    WRAP_FOR_DETACH(attach_pid)
#endif
#ifndef CAN_WRAP_sysfs_rename_link
#   define CAN_WRAP_sysfs_rename_link 1
#endif
#if CAN_WRAP_sysfs_rename_link
    WRAP_FOR_DETACH(sysfs_rename_link)
#endif
#ifndef CAN_WRAP__atomic_dec_and_lock
#   define CAN_WRAP__atomic_dec_and_lock 1
#endif
#if CAN_WRAP__atomic_dec_and_lock
    WRAP_FOR_DETACH(_atomic_dec_and_lock)
#endif
#ifndef CAN_WRAP_netdev_rx_handler_register
#   define CAN_WRAP_netdev_rx_handler_register 1
#endif
#if CAN_WRAP_netdev_rx_handler_register
    WRAP_FOR_DETACH(netdev_rx_handler_register)
#endif
#ifndef CAN_WRAP_compat_sys_process_vm_readv
#   define CAN_WRAP_compat_sys_process_vm_readv 1
#endif
#if CAN_WRAP_compat_sys_process_vm_readv
    WRAP_FOR_DETACH(compat_sys_process_vm_readv)
#endif
#ifndef CAN_WRAP_kmem_cache_init_late
#   define CAN_WRAP_kmem_cache_init_late 0
#endif
DETACH(kmem_cache_init_late)
#ifndef CAN_WRAP___rtnl_unlock
#   define CAN_WRAP___rtnl_unlock 0
#endif
DETACH(__rtnl_unlock)
#ifndef CAN_WRAP_remove_inode_buffers
#   define CAN_WRAP_remove_inode_buffers 1
#endif
#if CAN_WRAP_remove_inode_buffers
    WRAP_FOR_DETACH(remove_inode_buffers)
#endif
#ifndef CAN_WRAP_blk_queue_max_discard_sectors
#   define CAN_WRAP_blk_queue_max_discard_sectors 1
#endif
#if CAN_WRAP_blk_queue_max_discard_sectors
    WRAP_FOR_DETACH(blk_queue_max_discard_sectors)
#endif
#ifndef CAN_WRAP_compat_sys_fcntl64
#   define CAN_WRAP_compat_sys_fcntl64 0
#endif
DETACH(compat_sys_fcntl64)
#ifndef CAN_WRAP_idr_find
#   define CAN_WRAP_idr_find 1
#endif
#if CAN_WRAP_idr_find
    WRAP_FOR_DETACH(idr_find)
#endif
#ifndef CAN_WRAP_swiotlb_print_info
#   define CAN_WRAP_swiotlb_print_info 0
#endif
DETACH(swiotlb_print_info)
#ifndef CAN_WRAP_next_pidmap
#   define CAN_WRAP_next_pidmap 1
#endif
#if CAN_WRAP_next_pidmap
    WRAP_FOR_DETACH(next_pidmap)
#endif
#ifndef CAN_WRAP_phy_ethtool_get_eee
#   define CAN_WRAP_phy_ethtool_get_eee 1
#endif
#if CAN_WRAP_phy_ethtool_get_eee
    WRAP_FOR_DETACH(phy_ethtool_get_eee)
#endif
#ifndef CAN_WRAP___save_altstack
#   define CAN_WRAP___save_altstack 1
#endif
#if CAN_WRAP___save_altstack
#   ifdef DETACH_ADDR___save_altstack
        WRAP_FOR_DETACH(__save_altstack)
#   else
        TYPED_DETACH(__save_altstack)
#   endif
#endif
#ifndef CAN_WRAP___get_user_8
#   define CAN_WRAP___get_user_8 0
#endif
DETACH(__get_user_8)
#ifndef CAN_WRAP___get_user_4
#   define CAN_WRAP___get_user_4 0
#endif
DETACH(__get_user_4)
#ifndef CAN_WRAP___get_user_1
#   define CAN_WRAP___get_user_1 0
#endif
DETACH(__get_user_1)
#ifndef CAN_WRAP___get_user_2
#   define CAN_WRAP___get_user_2 0
#endif
DETACH(__get_user_2)
#ifndef CAN_WRAP_ether_setup
#   define CAN_WRAP_ether_setup 1
#endif
#if CAN_WRAP_ether_setup
    WRAP_FOR_DETACH(ether_setup)
#endif
#ifndef CAN_WRAP_vfs_create
#   define CAN_WRAP_vfs_create 1
#endif
#if CAN_WRAP_vfs_create
    WRAP_FOR_DETACH(vfs_create)
#endif
#ifndef CAN_WRAP_pci_dev_get
#   define CAN_WRAP_pci_dev_get 1
#endif
#if CAN_WRAP_pci_dev_get
    WRAP_FOR_DETACH(pci_dev_get)
#endif
#ifndef CAN_WRAP_unregister_mem_sect_under_nodes
#   define CAN_WRAP_unregister_mem_sect_under_nodes 1
#endif
#if CAN_WRAP_unregister_mem_sect_under_nodes
    WRAP_FOR_DETACH(unregister_mem_sect_under_nodes)
#endif
#ifndef CAN_WRAP_qdisc_lookup
#   define CAN_WRAP_qdisc_lookup 1
#endif
#if CAN_WRAP_qdisc_lookup
    WRAP_FOR_DETACH(qdisc_lookup)
#endif
#ifndef CAN_WRAP_qtree_delete_dquot
#   define CAN_WRAP_qtree_delete_dquot 1
#endif
#if CAN_WRAP_qtree_delete_dquot
    WRAP_FOR_DETACH(qtree_delete_dquot)
#endif
#ifndef CAN_WRAP_ata_mode_string
#   define CAN_WRAP_ata_mode_string 0
#endif
DETACH(ata_mode_string)
#ifndef CAN_WRAP_jbd2_journal_dirty_metadata
#   define CAN_WRAP_jbd2_journal_dirty_metadata 1
#endif
#if CAN_WRAP_jbd2_journal_dirty_metadata
    WRAP_FOR_DETACH(jbd2_journal_dirty_metadata)
#endif
#ifndef CAN_WRAP_blk_rq_unmap_user
#   define CAN_WRAP_blk_rq_unmap_user 1
#endif
#if CAN_WRAP_blk_rq_unmap_user
    WRAP_FOR_DETACH(blk_rq_unmap_user)
#endif
#ifndef CAN_WRAP_sk_wait_data
#   define CAN_WRAP_sk_wait_data 1
#endif
#if CAN_WRAP_sk_wait_data
    WRAP_FOR_DETACH(sk_wait_data)
#endif
#ifndef CAN_WRAP_unregister_netdevice_queue
#   define CAN_WRAP_unregister_netdevice_queue 1
#endif
#if CAN_WRAP_unregister_netdevice_queue
    WRAP_FOR_DETACH(unregister_netdevice_queue)
#endif
#ifndef CAN_WRAP_compat_sys_newstat
#   define CAN_WRAP_compat_sys_newstat 1
#endif
#if CAN_WRAP_compat_sys_newstat
    WRAP_FOR_DETACH(compat_sys_newstat)
#endif
#ifndef CAN_WRAP_pm_suspended_storage
#   define CAN_WRAP_pm_suspended_storage 0
#endif
DETACH(pm_suspended_storage)
#ifndef CAN_WRAP_bsg_register_queue
#   define CAN_WRAP_bsg_register_queue 1
#endif
#if CAN_WRAP_bsg_register_queue
    WRAP_FOR_DETACH(bsg_register_queue)
#endif
#ifndef CAN_WRAP_find_first_zero_bit
#   define CAN_WRAP_find_first_zero_bit 0
#endif
DETACH(find_first_zero_bit)
#ifndef CAN_WRAP_compat_sys_timerfd_gettime
#   define CAN_WRAP_compat_sys_timerfd_gettime 1
#endif
#if CAN_WRAP_compat_sys_timerfd_gettime
    WRAP_FOR_DETACH(compat_sys_timerfd_gettime)
#endif
#ifndef CAN_WRAP_arch_pick_mmap_layout
#   define CAN_WRAP_arch_pick_mmap_layout 1
#endif
#if CAN_WRAP_arch_pick_mmap_layout
    WRAP_FOR_DETACH(arch_pick_mmap_layout)
#endif
#ifndef CAN_WRAP_early_fixup_exception
#   define CAN_WRAP_early_fixup_exception 0
#endif
DETACH(early_fixup_exception)
#ifndef CAN_WRAP_find_user
#   define CAN_WRAP_find_user 1
#endif
#if CAN_WRAP_find_user
    WRAP_FOR_DETACH(find_user)
#endif
#ifndef CAN_WRAP___pte_alloc_kernel
#   define CAN_WRAP___pte_alloc_kernel 1
#endif
#if CAN_WRAP___pte_alloc_kernel
#   ifdef DETACH_ADDR___pte_alloc_kernel
        WRAP_FOR_DETACH(__pte_alloc_kernel)
#   else
        TYPED_DETACH(__pte_alloc_kernel)
#   endif
#endif
#ifndef CAN_WRAP_blk_rq_map_user_iov
#   define CAN_WRAP_blk_rq_map_user_iov 1
#endif
#if CAN_WRAP_blk_rq_map_user_iov
    WRAP_FOR_DETACH(blk_rq_map_user_iov)
#endif
#ifndef CAN_WRAP_acpi_set_gpe
#   define CAN_WRAP_acpi_set_gpe 0
#endif
DETACH(acpi_set_gpe)
#ifndef CAN_WRAP_throttle_vm_writeout
#   define CAN_WRAP_throttle_vm_writeout 0
#endif
DETACH(throttle_vm_writeout)
#ifndef CAN_WRAP___hw_addr_sync
#   define CAN_WRAP___hw_addr_sync 1
#endif
#if CAN_WRAP___hw_addr_sync
#   ifdef DETACH_ADDR___hw_addr_sync
        WRAP_FOR_DETACH(__hw_addr_sync)
#   else
        TYPED_DETACH(__hw_addr_sync)
#   endif
#endif
#ifndef CAN_WRAP_blk_queue_bio
#   define CAN_WRAP_blk_queue_bio 1
#endif
#if CAN_WRAP_blk_queue_bio
    WRAP_FOR_DETACH(blk_queue_bio)
#endif
#ifndef CAN_WRAP_proc_mkdir_mode
#   define CAN_WRAP_proc_mkdir_mode 1
#endif
#if CAN_WRAP_proc_mkdir_mode
    WRAP_FOR_DETACH(proc_mkdir_mode)
#endif
#ifndef CAN_WRAP_rtnl_unregister_all
#   define CAN_WRAP_rtnl_unregister_all 0
#endif
DETACH(rtnl_unregister_all)
#ifndef CAN_WRAP_free_buffer_head
#   define CAN_WRAP_free_buffer_head 1
#endif
#if CAN_WRAP_free_buffer_head
    WRAP_FOR_DETACH(free_buffer_head)
#endif
#ifndef CAN_WRAP_pcie_capability_clear_and_set_dword
#   define CAN_WRAP_pcie_capability_clear_and_set_dword 1
#endif
#if CAN_WRAP_pcie_capability_clear_and_set_dword
    WRAP_FOR_DETACH(pcie_capability_clear_and_set_dword)
#endif
#ifndef CAN_WRAP_clockevents_handle_noop
#   define CAN_WRAP_clockevents_handle_noop 1
#endif
#if CAN_WRAP_clockevents_handle_noop
    WRAP_FOR_DETACH(clockevents_handle_noop)
#endif
#ifndef CAN_WRAP_sg_next
#   define CAN_WRAP_sg_next 1
#endif
#if CAN_WRAP_sg_next
    WRAP_FOR_DETACH(sg_next)
#endif
#ifndef CAN_WRAP_mii_ethtool_sset
#   define CAN_WRAP_mii_ethtool_sset 1
#endif
#if CAN_WRAP_mii_ethtool_sset
    WRAP_FOR_DETACH(mii_ethtool_sset)
#endif
#ifndef CAN_WRAP_compat_sys_fstatfs64
#   define CAN_WRAP_compat_sys_fstatfs64 1
#endif
#if CAN_WRAP_compat_sys_fstatfs64
    WRAP_FOR_DETACH(compat_sys_fstatfs64)
#endif
#ifndef CAN_WRAP_vm_area_register_early
#   define CAN_WRAP_vm_area_register_early 1
#endif
#if CAN_WRAP_vm_area_register_early
    WRAP_FOR_DETACH(vm_area_register_early)
#endif
#ifndef CAN_WRAP_percpu_down_write
#   define CAN_WRAP_percpu_down_write 1
#endif
#if CAN_WRAP_percpu_down_write
    WRAP_FOR_DETACH(percpu_down_write)
#endif
#ifndef CAN_WRAP_do_prlimit
#   define CAN_WRAP_do_prlimit 1
#endif
#if CAN_WRAP_do_prlimit
    WRAP_FOR_DETACH(do_prlimit)
#endif
#ifndef CAN_WRAP_generic_file_direct_write
#   define CAN_WRAP_generic_file_direct_write 1
#endif
#if CAN_WRAP_generic_file_direct_write
    WRAP_FOR_DETACH(generic_file_direct_write)
#endif
#ifndef CAN_WRAP_invalidate_interrupt9
#   define CAN_WRAP_invalidate_interrupt9 0
#endif
DETACH(invalidate_interrupt9)
#ifndef CAN_WRAP_pci_user_read_config_dword
#   define CAN_WRAP_pci_user_read_config_dword 1
#endif
#if CAN_WRAP_pci_user_read_config_dword
    WRAP_FOR_DETACH(pci_user_read_config_dword)
#endif
#ifndef CAN_WRAP_security_inode_unlink
#   define CAN_WRAP_security_inode_unlink 1
#endif
#if CAN_WRAP_security_inode_unlink
    WRAP_FOR_DETACH(security_inode_unlink)
#endif
#ifndef CAN_WRAP_sched_clock_idle_sleep_event
#   define CAN_WRAP_sched_clock_idle_sleep_event 0
#endif
DETACH(sched_clock_idle_sleep_event)
#ifndef CAN_WRAP_queue_delayed_work
#   define CAN_WRAP_queue_delayed_work 1
#endif
#if CAN_WRAP_queue_delayed_work
    WRAP_FOR_DETACH(queue_delayed_work)
#endif
#ifndef CAN_WRAP_device_get_devnode
#   define CAN_WRAP_device_get_devnode 1
#endif
#if CAN_WRAP_device_get_devnode
    WRAP_FOR_DETACH(device_get_devnode)
#endif
#ifndef CAN_WRAP_inet_csk_destroy_sock
#   define CAN_WRAP_inet_csk_destroy_sock 1
#endif
#if CAN_WRAP_inet_csk_destroy_sock
    WRAP_FOR_DETACH(inet_csk_destroy_sock)
#endif
#ifndef CAN_WRAP_sched_clock_init
#   define CAN_WRAP_sched_clock_init 0
#endif
DETACH(sched_clock_init)
#ifndef CAN_WRAP_follow_down
#   define CAN_WRAP_follow_down 1
#endif
#if CAN_WRAP_follow_down
    WRAP_FOR_DETACH(follow_down)
#endif
#ifndef CAN_WRAP_iget5_locked
#   define CAN_WRAP_iget5_locked 1
#endif
#if CAN_WRAP_iget5_locked
    WRAP_FOR_DETACH(iget5_locked)
#endif
#ifndef CAN_WRAP_completion_done
#   define CAN_WRAP_completion_done 1
#endif
#if CAN_WRAP_completion_done
    WRAP_FOR_DETACH(completion_done)
#endif
#ifndef CAN_WRAP_nf_unregister_sockopt
#   define CAN_WRAP_nf_unregister_sockopt 1
#endif
#if CAN_WRAP_nf_unregister_sockopt
    WRAP_FOR_DETACH(nf_unregister_sockopt)
#endif
#ifndef CAN_WRAP_usleep_range
#   define CAN_WRAP_usleep_range 0
#endif
DETACH(usleep_range)
#ifndef CAN_WRAP_find_vma_prev
#   define CAN_WRAP_find_vma_prev 1
#endif
#if CAN_WRAP_find_vma_prev
    WRAP_FOR_DETACH(find_vma_prev)
#endif
#ifndef CAN_WRAP_default_teardown_msi_irqs
#   define CAN_WRAP_default_teardown_msi_irqs 1
#endif
#if CAN_WRAP_default_teardown_msi_irqs
    WRAP_FOR_DETACH(default_teardown_msi_irqs)
#endif
#ifndef CAN_WRAP___acpi_map_pxm_to_node
#   define CAN_WRAP___acpi_map_pxm_to_node 0
#endif
DETACH(__acpi_map_pxm_to_node)
#ifndef CAN_WRAP_dm_suspended
#   define CAN_WRAP_dm_suspended 1
#endif
#if CAN_WRAP_dm_suspended
    WRAP_FOR_DETACH(dm_suspended)
#endif
#ifndef CAN_WRAP_acpi_get_gpe_status
#   define CAN_WRAP_acpi_get_gpe_status 0
#endif
DETACH(acpi_get_gpe_status)
#ifndef CAN_WRAP_raw_notifier_chain_unregister
#   define CAN_WRAP_raw_notifier_chain_unregister 1
#endif
#if CAN_WRAP_raw_notifier_chain_unregister
    WRAP_FOR_DETACH(raw_notifier_chain_unregister)
#endif
#ifndef CAN_WRAP_scsi_device_type
#   define CAN_WRAP_scsi_device_type 0
#endif
DETACH(scsi_device_type)
#ifndef CAN_WRAP_acpi_pci_irq_disable
#   define CAN_WRAP_acpi_pci_irq_disable 1
#endif
#if CAN_WRAP_acpi_pci_irq_disable
    WRAP_FOR_DETACH(acpi_pci_irq_disable)
#endif
#ifndef CAN_WRAP_text_poke_early
#   define CAN_WRAP_text_poke_early 0
#endif
DETACH(text_poke_early)
#ifndef CAN_WRAP_pci_scan_child_bus
#   define CAN_WRAP_pci_scan_child_bus 1
#endif
#if CAN_WRAP_pci_scan_child_bus
    WRAP_FOR_DETACH(pci_scan_child_bus)
#endif
#ifndef CAN_WRAP_next_zone
#   define CAN_WRAP_next_zone 1
#endif
#if CAN_WRAP_next_zone
    WRAP_FOR_DETACH(next_zone)
#endif
#ifndef CAN_WRAP_kset_unregister
#   define CAN_WRAP_kset_unregister 1
#endif
#if CAN_WRAP_kset_unregister
    WRAP_FOR_DETACH(kset_unregister)
#endif
#ifndef CAN_WRAP_locks_free_lock
#   define CAN_WRAP_locks_free_lock 1
#endif
#if CAN_WRAP_locks_free_lock
    WRAP_FOR_DETACH(locks_free_lock)
#endif
#ifndef CAN_WRAP_raise_softirq_irqoff
#   define CAN_WRAP_raise_softirq_irqoff 0
#endif
DETACH(raise_softirq_irqoff)
#ifndef CAN_WRAP_elv_rb_latter_request
#   define CAN_WRAP_elv_rb_latter_request 1
#endif
#if CAN_WRAP_elv_rb_latter_request
    WRAP_FOR_DETACH(elv_rb_latter_request)
#endif
#ifndef CAN_WRAP_acpi_get_handle
#   define CAN_WRAP_acpi_get_handle 0
#endif
DETACH(acpi_get_handle)
#ifndef CAN_WRAP_emergency_restart
#   define CAN_WRAP_emergency_restart 0
#endif
DETACH(emergency_restart)
#ifndef CAN_WRAP_qdisc_class_hash_insert
#   define CAN_WRAP_qdisc_class_hash_insert 1
#endif
#if CAN_WRAP_qdisc_class_hash_insert
    WRAP_FOR_DETACH(qdisc_class_hash_insert)
#endif
#ifndef CAN_WRAP_compat_sys_getrlimit
#   define CAN_WRAP_compat_sys_getrlimit 1
#endif
#if CAN_WRAP_compat_sys_getrlimit
    WRAP_FOR_DETACH(compat_sys_getrlimit)
#endif
#ifndef CAN_WRAP_dm_unregister_target
#   define CAN_WRAP_dm_unregister_target 1
#endif
#if CAN_WRAP_dm_unregister_target
    WRAP_FOR_DETACH(dm_unregister_target)
#endif
#ifndef CAN_WRAP_rtnetlink_put_metrics
#   define CAN_WRAP_rtnetlink_put_metrics 1
#endif
#if CAN_WRAP_rtnetlink_put_metrics
    WRAP_FOR_DETACH(rtnetlink_put_metrics)
#endif
#ifndef CAN_WRAP_vfs_lock_file
#   define CAN_WRAP_vfs_lock_file 1
#endif
#if CAN_WRAP_vfs_lock_file
    WRAP_FOR_DETACH(vfs_lock_file)
#endif
#ifndef CAN_WRAP___napi_schedule
#   define CAN_WRAP___napi_schedule 1
#endif
#if CAN_WRAP___napi_schedule
#   ifdef DETACH_ADDR___napi_schedule
        WRAP_FOR_DETACH(__napi_schedule)
#   else
        TYPED_DETACH(__napi_schedule)
#   endif
#endif
#ifndef CAN_WRAP_devres_find
#   define CAN_WRAP_devres_find 1
#endif
#if CAN_WRAP_devres_find
    WRAP_FOR_DETACH(devres_find)
#endif
#ifndef CAN_WRAP_genphy_config_aneg
#   define CAN_WRAP_genphy_config_aneg 1
#endif
#if CAN_WRAP_genphy_config_aneg
    WRAP_FOR_DETACH(genphy_config_aneg)
#endif
#ifndef CAN_WRAP_acpi_pci_irq_del_prt
#   define CAN_WRAP_acpi_pci_irq_del_prt 0
#endif
DETACH(acpi_pci_irq_del_prt)
#ifndef CAN_WRAP_res_counter_uncharge
#   define CAN_WRAP_res_counter_uncharge 1
#endif
#if CAN_WRAP_res_counter_uncharge
    WRAP_FOR_DETACH(res_counter_uncharge)
#endif
#ifndef CAN_WRAP_ata_scsi_cmd_error_handler
#   define CAN_WRAP_ata_scsi_cmd_error_handler 1
#endif
#if CAN_WRAP_ata_scsi_cmd_error_handler
    WRAP_FOR_DETACH(ata_scsi_cmd_error_handler)
#endif
#ifndef CAN_WRAP_ioapic_insert_resources
#   define CAN_WRAP_ioapic_insert_resources 0
#endif
DETACH(ioapic_insert_resources)
#ifndef CAN_WRAP___compat_save_altstack
#   define CAN_WRAP___compat_save_altstack 1
#endif
#if CAN_WRAP___compat_save_altstack
#   ifdef DETACH_ADDR___compat_save_altstack
        WRAP_FOR_DETACH(__compat_save_altstack)
#   else
        TYPED_DETACH(__compat_save_altstack)
#   endif
#endif
#ifndef CAN_WRAP_pci_select_bars
#   define CAN_WRAP_pci_select_bars 1
#endif
#if CAN_WRAP_pci_select_bars
    WRAP_FOR_DETACH(pci_select_bars)
#endif
#ifndef CAN_WRAP_klist_del
#   define CAN_WRAP_klist_del 1
#endif
#if CAN_WRAP_klist_del
    WRAP_FOR_DETACH(klist_del)
#endif
#ifndef CAN_WRAP_pcibios_window_alignment
#   define CAN_WRAP_pcibios_window_alignment 1
#endif
#if CAN_WRAP_pcibios_window_alignment
    WRAP_FOR_DETACH(pcibios_window_alignment)
#endif
#ifndef CAN_WRAP_file_ra_state_init
#   define CAN_WRAP_file_ra_state_init 1
#endif
#if CAN_WRAP_file_ra_state_init
    WRAP_FOR_DETACH(file_ra_state_init)
#endif
#ifndef CAN_WRAP_pnp_device_attach
#   define CAN_WRAP_pnp_device_attach 1
#endif
#if CAN_WRAP_pnp_device_attach
    WRAP_FOR_DETACH(pnp_device_attach)
#endif
#ifndef CAN_WRAP___bitmap_parse
#   define CAN_WRAP___bitmap_parse 0
#endif
DETACH(__bitmap_parse)
#ifndef CAN_WRAP_mpc_ioapic_addr
#   define CAN_WRAP_mpc_ioapic_addr 0
#endif
DETACH(mpc_ioapic_addr)
#ifndef CAN_WRAP_sigqueue_free
#   define CAN_WRAP_sigqueue_free 1
#endif
#if CAN_WRAP_sigqueue_free
    WRAP_FOR_DETACH(sigqueue_free)
#endif
#ifndef CAN_WRAP_dma_issue_pending_all
#   define CAN_WRAP_dma_issue_pending_all 0
#endif
DETACH(dma_issue_pending_all)
#ifndef CAN_WRAP___kmalloc
#   define CAN_WRAP___kmalloc 1
#endif
#if CAN_WRAP___kmalloc
#   ifdef DETACH_ADDR___kmalloc
        WRAP_FOR_DETACH(__kmalloc)
#   else
        TYPED_DETACH(__kmalloc)
#   endif
#endif
#ifndef CAN_WRAP_seq_lseek
#   define CAN_WRAP_seq_lseek 1
#endif
#if CAN_WRAP_seq_lseek
    WRAP_FOR_DETACH(seq_lseek)
#endif
#ifndef CAN_WRAP___cmpxchg_wrong_size
#   define CAN_WRAP___cmpxchg_wrong_size 0
#endif
DETACH(__cmpxchg_wrong_size)
#ifndef CAN_WRAP_mb_cache_entry_find_first
#   define CAN_WRAP_mb_cache_entry_find_first 1
#endif
#if CAN_WRAP_mb_cache_entry_find_first
    WRAP_FOR_DETACH(mb_cache_entry_find_first)
#endif
#ifndef CAN_WRAP_seq_bitmap_list
#   define CAN_WRAP_seq_bitmap_list 1
#endif
#if CAN_WRAP_seq_bitmap_list
    WRAP_FOR_DETACH(seq_bitmap_list)
#endif
#ifndef CAN_WRAP_plist_del
#   define CAN_WRAP_plist_del 1
#endif
#if CAN_WRAP_plist_del
    WRAP_FOR_DETACH(plist_del)
#endif
#ifndef CAN_WRAP_bio_integrity_endio
#   define CAN_WRAP_bio_integrity_endio 1
#endif
#if CAN_WRAP_bio_integrity_endio
    WRAP_FOR_DETACH(bio_integrity_endio)
#endif
#ifndef CAN_WRAP_pcie_capability_write_dword
#   define CAN_WRAP_pcie_capability_write_dword 1
#endif
#if CAN_WRAP_pcie_capability_write_dword
    WRAP_FOR_DETACH(pcie_capability_write_dword)
#endif
#ifndef CAN_WRAP_ata_sff_error_handler
#   define CAN_WRAP_ata_sff_error_handler 1
#endif
#if CAN_WRAP_ata_sff_error_handler
    WRAP_FOR_DETACH(ata_sff_error_handler)
#endif
#ifndef CAN_WRAP_dm_shift_arg
#   define CAN_WRAP_dm_shift_arg 1
#endif
#if CAN_WRAP_dm_shift_arg
    WRAP_FOR_DETACH(dm_shift_arg)
#endif
#ifndef CAN_WRAP_buffer_init
#   define CAN_WRAP_buffer_init 0
#endif
DETACH(buffer_init)
#ifndef CAN_WRAP_unmap_vmas
#   define CAN_WRAP_unmap_vmas 1
#endif
#if CAN_WRAP_unmap_vmas
    WRAP_FOR_DETACH(unmap_vmas)
#endif
#ifndef CAN_WRAP_sk_stream_kill_queues
#   define CAN_WRAP_sk_stream_kill_queues 1
#endif
#if CAN_WRAP_sk_stream_kill_queues
    WRAP_FOR_DETACH(sk_stream_kill_queues)
#endif
#ifndef CAN_WRAP_ata_cable_ignore
#   define CAN_WRAP_ata_cable_ignore 1
#endif
#if CAN_WRAP_ata_cable_ignore
    WRAP_FOR_DETACH(ata_cable_ignore)
#endif
#ifndef CAN_WRAP_eth_header_cache_update
#   define CAN_WRAP_eth_header_cache_update 1
#endif
#if CAN_WRAP_eth_header_cache_update
    WRAP_FOR_DETACH(eth_header_cache_update)
#endif
#ifndef CAN_WRAP_ata_pci_device_resume
#   define CAN_WRAP_ata_pci_device_resume 1
#endif
#if CAN_WRAP_ata_pci_device_resume
    WRAP_FOR_DETACH(ata_pci_device_resume)
#endif
#ifndef CAN_WRAP_set_pte_vaddr_pud
#   define CAN_WRAP_set_pte_vaddr_pud 1
#endif
#if CAN_WRAP_set_pte_vaddr_pud
    WRAP_FOR_DETACH(set_pte_vaddr_pud)
#endif
#ifndef CAN_WRAP_security_inode_rename
#   define CAN_WRAP_security_inode_rename 1
#endif
#if CAN_WRAP_security_inode_rename
    WRAP_FOR_DETACH(security_inode_rename)
#endif
#ifndef CAN_WRAP_driver_probe_done
#   define CAN_WRAP_driver_probe_done 0
#endif
DETACH(driver_probe_done)
#ifndef CAN_WRAP_default_acpi_madt_oem_check
#   define CAN_WRAP_default_acpi_madt_oem_check 0
#endif
DETACH(default_acpi_madt_oem_check)
#ifndef CAN_WRAP_populate_extra_pte
#   define CAN_WRAP_populate_extra_pte 1
#endif
#if CAN_WRAP_populate_extra_pte
    WRAP_FOR_DETACH(populate_extra_pte)
#endif
#ifndef CAN_WRAP_radix_tree_next_hole
#   define CAN_WRAP_radix_tree_next_hole 1
#endif
#if CAN_WRAP_radix_tree_next_hole
    WRAP_FOR_DETACH(radix_tree_next_hole)
#endif
#ifndef CAN_WRAP_ata_cable_unknown
#   define CAN_WRAP_ata_cable_unknown 1
#endif
#if CAN_WRAP_ata_cable_unknown
    WRAP_FOR_DETACH(ata_cable_unknown)
#endif
#ifndef CAN_WRAP_thread_info_cache_init
#   define CAN_WRAP_thread_info_cache_init 0
#endif
DETACH(thread_info_cache_init)
#ifndef CAN_WRAP_acpi_purge_cached_objects
#   define CAN_WRAP_acpi_purge_cached_objects 0
#endif
DETACH(acpi_purge_cached_objects)
#ifndef CAN_WRAP_acpi_detach_data
#   define CAN_WRAP_acpi_detach_data 1
#endif
#if CAN_WRAP_acpi_detach_data
    WRAP_FOR_DETACH(acpi_detach_data)
#endif
#ifndef CAN_WRAP_generic_segment_checks
#   define CAN_WRAP_generic_segment_checks 1
#endif
#if CAN_WRAP_generic_segment_checks
    WRAP_FOR_DETACH(generic_segment_checks)
#endif
#ifndef CAN_WRAP_clear_bdi_congested
#   define CAN_WRAP_clear_bdi_congested 1
#endif
#if CAN_WRAP_clear_bdi_congested
    WRAP_FOR_DETACH(clear_bdi_congested)
#endif
#ifndef CAN_WRAP_swiotlb_nr_tbl
#   define CAN_WRAP_swiotlb_nr_tbl 0
#endif
DETACH(swiotlb_nr_tbl)
#ifndef CAN_WRAP___sb_start_write
#   define CAN_WRAP___sb_start_write 1
#endif
#if CAN_WRAP___sb_start_write
#   ifdef DETACH_ADDR___sb_start_write
        WRAP_FOR_DETACH(__sb_start_write)
#   else
        TYPED_DETACH(__sb_start_write)
#   endif
#endif
#ifndef CAN_WRAP_part_round_stats
#   define CAN_WRAP_part_round_stats 1
#endif
#if CAN_WRAP_part_round_stats
    WRAP_FOR_DETACH(part_round_stats)
#endif
#ifndef CAN_WRAP_work_on_cpu
#   define CAN_WRAP_work_on_cpu 1
#endif
#if CAN_WRAP_work_on_cpu
    WRAP_FOR_DETACH(work_on_cpu)
#endif
#ifndef CAN_WRAP_kern_mount_data
#   define CAN_WRAP_kern_mount_data 1
#endif
#if CAN_WRAP_kern_mount_data
    WRAP_FOR_DETACH(kern_mount_data)
#endif
#ifndef CAN_WRAP_autoremove_wake_function
#   define CAN_WRAP_autoremove_wake_function 1
#endif
#if CAN_WRAP_autoremove_wake_function
    WRAP_FOR_DETACH(autoremove_wake_function)
#endif
#ifndef CAN_WRAP_pci_request_regions_exclusive
#   define CAN_WRAP_pci_request_regions_exclusive 1
#endif
#if CAN_WRAP_pci_request_regions_exclusive
    WRAP_FOR_DETACH(pci_request_regions_exclusive)
#endif
#ifndef CAN_WRAP_genphy_read_status
#   define CAN_WRAP_genphy_read_status 1
#endif
#if CAN_WRAP_genphy_read_status
    WRAP_FOR_DETACH(genphy_read_status)
#endif
#ifndef CAN_WRAP_acpi_os_signal_semaphore
#   define CAN_WRAP_acpi_os_signal_semaphore 0
#endif
DETACH(acpi_os_signal_semaphore)
#ifndef CAN_WRAP_input_ff_create_memless
#   define CAN_WRAP_input_ff_create_memless 1
#endif
#if CAN_WRAP_input_ff_create_memless
    WRAP_FOR_DETACH(input_ff_create_memless)
#endif
#ifndef CAN_WRAP___tasklet_hi_schedule
#   define CAN_WRAP___tasklet_hi_schedule 1
#endif
#if CAN_WRAP___tasklet_hi_schedule
#   ifdef DETACH_ADDR___tasklet_hi_schedule
        WRAP_FOR_DETACH(__tasklet_hi_schedule)
#   else
        TYPED_DETACH(__tasklet_hi_schedule)
#   endif
#endif
#ifndef CAN_WRAP_zap_other_threads
#   define CAN_WRAP_zap_other_threads 1
#endif
#if CAN_WRAP_zap_other_threads
    WRAP_FOR_DETACH(zap_other_threads)
#endif
#ifndef CAN_WRAP_bdi_start_background_writeback
#   define CAN_WRAP_bdi_start_background_writeback 1
#endif
#if CAN_WRAP_bdi_start_background_writeback
    WRAP_FOR_DETACH(bdi_start_background_writeback)
#endif
#ifndef CAN_WRAP_icmpv6_flow_init
#   define CAN_WRAP_icmpv6_flow_init 1
#endif
#if CAN_WRAP_icmpv6_flow_init
    WRAP_FOR_DETACH(icmpv6_flow_init)
#endif
#ifndef CAN_WRAP_ioremap_page_range
#   define CAN_WRAP_ioremap_page_range 1
#endif
#if CAN_WRAP_ioremap_page_range
    WRAP_FOR_DETACH(ioremap_page_range)
#endif
#ifndef CAN_WRAP_get_pid_task
#   define CAN_WRAP_get_pid_task 1
#endif
#if CAN_WRAP_get_pid_task
    WRAP_FOR_DETACH(get_pid_task)
#endif
#ifndef CAN_WRAP_csum_partial
#   define CAN_WRAP_csum_partial 0
#endif
DETACH(csum_partial)
#ifndef CAN_WRAP_bdi_start_writeback
#   define CAN_WRAP_bdi_start_writeback 1
#endif
#if CAN_WRAP_bdi_start_writeback
    WRAP_FOR_DETACH(bdi_start_writeback)
#endif
#ifndef CAN_WRAP_drop_caches_sysctl_handler
#   define CAN_WRAP_drop_caches_sysctl_handler 1
#endif
#if CAN_WRAP_drop_caches_sysctl_handler
    WRAP_FOR_DETACH(drop_caches_sysctl_handler)
#endif
#ifndef CAN_WRAP_rcu_sched_force_quiescent_state
#   define CAN_WRAP_rcu_sched_force_quiescent_state 0
#endif
DETACH(rcu_sched_force_quiescent_state)
#ifndef CAN_WRAP_pcim_enable_device
#   define CAN_WRAP_pcim_enable_device 1
#endif
#if CAN_WRAP_pcim_enable_device
    WRAP_FOR_DETACH(pcim_enable_device)
#endif
#ifndef CAN_WRAP_zone_grow_free_lists
#   define CAN_WRAP_zone_grow_free_lists 1
#endif
#if CAN_WRAP_zone_grow_free_lists
    WRAP_FOR_DETACH(zone_grow_free_lists)
#endif
#ifndef CAN_WRAP___round_jiffies
#   define CAN_WRAP___round_jiffies 0
#endif
DETACH(__round_jiffies)
#ifndef CAN_WRAP_linkwatch_fire_event
#   define CAN_WRAP_linkwatch_fire_event 1
#endif
#if CAN_WRAP_linkwatch_fire_event
    WRAP_FOR_DETACH(linkwatch_fire_event)
#endif
#ifndef CAN_WRAP__kstrtoul
#   define CAN_WRAP__kstrtoul 0
#endif
DETACH(_kstrtoul)
#ifndef CAN_WRAP___nla_reserve
#   define CAN_WRAP___nla_reserve 1
#endif
#if CAN_WRAP___nla_reserve
#   ifdef DETACH_ADDR___nla_reserve
        WRAP_FOR_DETACH(__nla_reserve)
#   else
        TYPED_DETACH(__nla_reserve)
#   endif
#endif
#ifndef CAN_WRAP_generic_fh_to_parent
#   define CAN_WRAP_generic_fh_to_parent 1
#endif
#if CAN_WRAP_generic_fh_to_parent
    WRAP_FOR_DETACH(generic_fh_to_parent)
#endif
#ifndef CAN_WRAP_flow_cache_flush_deferred
#   define CAN_WRAP_flow_cache_flush_deferred 0
#endif
DETACH(flow_cache_flush_deferred)
#ifndef CAN_WRAP___percpu_counter_sum
#   define CAN_WRAP___percpu_counter_sum 1
#endif
#if CAN_WRAP___percpu_counter_sum
#   ifdef DETACH_ADDR___percpu_counter_sum
        WRAP_FOR_DETACH(__percpu_counter_sum)
#   else
        TYPED_DETACH(__percpu_counter_sum)
#   endif
#endif
#ifndef CAN_WRAP_vfs_follow_link
#   define CAN_WRAP_vfs_follow_link 1
#endif
#if CAN_WRAP_vfs_follow_link
    WRAP_FOR_DETACH(vfs_follow_link)
#endif
#ifndef CAN_WRAP_d_prune_aliases
#   define CAN_WRAP_d_prune_aliases 1
#endif
#if CAN_WRAP_d_prune_aliases
    WRAP_FOR_DETACH(d_prune_aliases)
#endif
#ifndef CAN_WRAP_smp_cpus_done
#   define CAN_WRAP_smp_cpus_done 0
#endif
DETACH(smp_cpus_done)
#ifndef CAN_WRAP_release_sock
#   define CAN_WRAP_release_sock 1
#endif
#if CAN_WRAP_release_sock
    WRAP_FOR_DETACH(release_sock)
#endif
#ifndef CAN_WRAP_kern_addr_valid
#   define CAN_WRAP_kern_addr_valid 0
#endif
DETACH(kern_addr_valid)
#ifndef CAN_WRAP_netlink_table_grab
#   define CAN_WRAP_netlink_table_grab 0
#endif
DETACH(netlink_table_grab)
#ifndef CAN_WRAP_get_seccomp_filter
#   define CAN_WRAP_get_seccomp_filter 1
#endif
#if CAN_WRAP_get_seccomp_filter
    WRAP_FOR_DETACH(get_seccomp_filter)
#endif
#ifndef CAN_WRAP_dev_queue_xmit
#   define CAN_WRAP_dev_queue_xmit 1
#endif
#if CAN_WRAP_dev_queue_xmit
    WRAP_FOR_DETACH(dev_queue_xmit)
#endif
#ifndef CAN_WRAP_alloc_pages_exact_nid
#   define CAN_WRAP_alloc_pages_exact_nid 0
#endif
DETACH(alloc_pages_exact_nid)
#ifndef CAN_WRAP_sock_i_ino
#   define CAN_WRAP_sock_i_ino 1
#endif
#if CAN_WRAP_sock_i_ino
    WRAP_FOR_DETACH(sock_i_ino)
#endif
#ifndef CAN_WRAP_compat_sys_execve
#   define CAN_WRAP_compat_sys_execve 0
#endif
DETACH(compat_sys_execve)
#ifndef CAN_WRAP_acpi_os_signal
#   define CAN_WRAP_acpi_os_signal 0
#endif
DETACH(acpi_os_signal)
#ifndef CAN_WRAP_fasync_free
#   define CAN_WRAP_fasync_free 1
#endif
#if CAN_WRAP_fasync_free
    WRAP_FOR_DETACH(fasync_free)
#endif
#ifndef CAN_WRAP___rtnl_af_register
#   define CAN_WRAP___rtnl_af_register 1
#endif
#if CAN_WRAP___rtnl_af_register
#   ifdef DETACH_ADDR___rtnl_af_register
        WRAP_FOR_DETACH(__rtnl_af_register)
#   else
        TYPED_DETACH(__rtnl_af_register)
#   endif
#endif
#ifndef CAN_WRAP_hrtimers_init
#   define CAN_WRAP_hrtimers_init 0
#endif
DETACH(hrtimers_init)
#ifndef CAN_WRAP_path_put
#   define CAN_WRAP_path_put 1
#endif
#if CAN_WRAP_path_put
    WRAP_FOR_DETACH(path_put)
#endif
#ifndef CAN_WRAP_percpu_init_late
#   define CAN_WRAP_percpu_init_late 0
#endif
DETACH(percpu_init_late)
#ifndef CAN_WRAP_acpi_paddr_to_node
#   define CAN_WRAP_acpi_paddr_to_node 0
#endif
DETACH(acpi_paddr_to_node)
#ifndef CAN_WRAP_cgroup_fork
#   define CAN_WRAP_cgroup_fork 1
#endif
#if CAN_WRAP_cgroup_fork
    WRAP_FOR_DETACH(cgroup_fork)
#endif
#ifndef CAN_WRAP_down_read_trylock
#   define CAN_WRAP_down_read_trylock 1
#endif
#if CAN_WRAP_down_read_trylock
    WRAP_FOR_DETACH(down_read_trylock)
#endif
#ifndef CAN_WRAP_security_sb_free
#   define CAN_WRAP_security_sb_free 1
#endif
#if CAN_WRAP_security_sb_free
    WRAP_FOR_DETACH(security_sb_free)
#endif
#ifndef CAN_WRAP_wakeup_kswapd
#   define CAN_WRAP_wakeup_kswapd 1
#endif
#if CAN_WRAP_wakeup_kswapd
    WRAP_FOR_DETACH(wakeup_kswapd)
#endif
#ifndef CAN_WRAP_dquot_writeback_dquots
#   define CAN_WRAP_dquot_writeback_dquots 1
#endif
#if CAN_WRAP_dquot_writeback_dquots
    WRAP_FOR_DETACH(dquot_writeback_dquots)
#endif

