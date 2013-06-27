template <typename T>
struct type_id {
    enum {
        ID = 0
    };
};
 

template <typename T>
struct type_id < T* >
    enum {
        ID = type_id <T>::ID
    };
};
 

template <typename T>
struct type_id < T& >
    enum {
        ID = type_id <T>::ID
    };
};
 

template <typename T>
struct type_id < const T >
    enum {
        ID = type_id <T>::ID
    };
}; 
 

template <typename T>
struct type_id < volatile T >
    enum {
        ID = type_id <T>::ID
    };
};
 

struct type_id < const volatile T >
    enum {
        ID = type_id <T>::ID
    };
};
 

template <>
struct type_id < struct pcpu_dstats > {
    enum {
        ID = 1
    };
};
 

template <>
struct type_id < struct dynamic > {
    enum {
        ID = 2
    };
};
 

template <>
struct type_id < struct fiemap_extent > {
    enum {
        ID = 3
    };
};
 

template <>
struct type_id < struct in_pktinfo > {
    enum {
        ID = 4
    };
};
 

template <>
struct type_id < struct rtnl_link_ops > {
    enum {
        ID = 5
    };
};
 

template <>
struct type_id < struct neigh_statistics > {
    enum {
        ID = 6
    };
};
 

template <>
struct type_id < struct mmuext_op > {
    enum {
        ID = 7
    };
};
 

template <>
struct type_id < struct elf64_hdr > {
    enum {
        ID = 8
    };
};
 

template <>
struct type_id < struct icmp6_filter > {
    enum {
        ID = 9
    };
};
 

template <>
struct type_id < struct irq_chip > {
    enum {
        ID = 10
    };
};
 

template <>
struct type_id < struct icmp_mib > {
    enum {
        ID = 11
    };
};
 

template <>
struct type_id < struct user_regs_struct32 > {
    enum {
        ID = 12
    };
};
 

template <>
struct type_id < struct vlan_ioctl_args > {
    enum {
        ID = 13
    };
};
 

template <>
struct type_id < struct tty_audit_buf > {
    enum {
        ID = 14
    };
};
 

template <>
struct type_id < struct acpi_hest_ia_error_bank > {
    enum {
        ID = 15
    };
};
 

template <>
struct type_id < struct ldttss_desc64 > {
    enum {
        ID = 16
    };
};
 

template <>
struct type_id < struct ethtool_wolinfo > {
    enum {
        ID = 17
    };
};
 

template <>
struct type_id < struct elf32_sym > {
    enum {
        ID = 18
    };
};
 

template <>
struct type_id < struct x86_hw_tss > {
    enum {
        ID = 19
    };
};
 

template <>
struct type_id < struct ucred > {
    enum {
        ID = 20
    };
};
 

template <>
struct type_id < struct ff_ramp_effect > {
    enum {
        ID = 21
    };
};
 

template <>
struct type_id < struct ip_options > {
    enum {
        ID = 22
    };
};
 

template <>
struct type_id < struct ata_host > {
    enum {
        ID = 23
    };
};
 

template <>
struct type_id < struct ida_bitmap > {
    enum {
        ID = 24
    };
};
 

template <>
struct type_id < struct acpi_resource_address32 > {
    enum {
        ID = 25
    };
};
 

template <>
struct type_id < struct icmpv6_echo > {
    enum {
        ID = 26
    };
};
 

template <>
struct type_id < struct irq_chip_generic > {
    enum {
        ID = 27
    };
};
 

template <>
struct type_id < struct work_struct > {
    enum {
        ID = 28
    };
};
 

template <>
struct type_id < struct dcb_peer_app_info > {
    enum {
        ID = 29
    };
};
 

template <>
struct type_id < struct tc_sfq_qopt > {
    enum {
        ID = 30
    };
};
 

template <>
struct type_id < struct in_addr > {
    enum {
        ID = 31
    };
};
 

template <>
struct type_id < struct xfrm_id > {
    enum {
        ID = 32
    };
};
 

template <>
struct type_id < struct paravirt_callee_save > {
    enum {
        ID = 33
    };
};
 

template <>
struct type_id < struct builtin_fw > {
    enum {
        ID = 34
    };
};
 

template <>
struct type_id < struct pci_setup_rom > {
    enum {
        ID = 35
    };
};
 

template <>
struct type_id < struct nfq_ct_hook > {
    enum {
        ID = 36
    };
};
 

template <>
struct type_id < struct acpi_csrt_group > {
    enum {
        ID = 37
    };
};
 

template <>
struct type_id < struct path > {
    enum {
        ID = 38
    };
};
 

template <>
struct type_id < struct taskstats > {
    enum {
        ID = 39
    };
};
 

template <>
struct type_id < struct pv_lazy_ops > {
    enum {
        ID = 40
    };
};
 

template <>
struct type_id < struct ip_mreq_source > {
    enum {
        ID = 41
    };
};
 

template <>
struct type_id < struct acpi_hest_ia_nmi > {
    enum {
        ID = 42
    };
};
 

template <>
struct type_id < struct fown_struct > {
    enum {
        ID = 43
    };
};
 

template <>
struct type_id < struct cdev > {
    enum {
        ID = 44
    };
};
 

template <>
struct type_id < struct bin_attribute > {
    enum {
        ID = 45
    };
};
 

template <>
struct type_id < struct nf_generic_net > {
    enum {
        ID = 46
    };
};
 

template <>
struct type_id < struct nfs_lock_info > {
    enum {
        ID = 47
    };
};
 

template <>
struct type_id < struct sighand_struct > {
    enum {
        ID = 48
    };
};
 

template <>
struct type_id < struct request_sock_ops > {
    enum {
        ID = 49
    };
};
 

template <>
struct type_id < struct lockdep_map > {
    enum {
        ID = 50
    };
};
 

template <>
struct type_id < struct media_event_desc > {
    enum {
        ID = 51
    };
};
 

template <>
struct type_id < struct acpi_dmar_header > {
    enum {
        ID = 52
    };
};
 

template <>
struct type_id < struct udp6_sock > {
    enum {
        ID = 53
    };
};
 

template <>
struct type_id < struct acpi_table_mpst > {
    enum {
        ID = 54
    };
};
 

template <>
struct type_id < struct kset_uevent_ops > {
    enum {
        ID = 55
    };
};
 

template <>
struct type_id < struct pm_qos_request > {
    enum {
        ID = 56
    };
};
 

template <>
struct type_id < struct compress_alg > {
    enum {
        ID = 57
    };
};
 

template <>
struct type_id < struct if_dqinfo > {
    enum {
        ID = 58
    };
};
 

template <>
struct type_id < struct scm_fp_list > {
    enum {
        ID = 59
    };
};
 

template <>
struct type_id < struct kobj_uevent_env > {
    enum {
        ID = 60
    };
};
 

template <>
struct type_id < struct acpi_drtm_resource_list > {
    enum {
        ID = 61
    };
};
 

template <>
struct type_id < struct x86_init_irqs > {
    enum {
        ID = 62
    };
};
 

template <>
struct type_id < struct socket_wq > {
    enum {
        ID = 63
    };
};
 

template <>
struct type_id < struct msix_entry > {
    enum {
        ID = 64
    };
};
 

template <>
struct type_id < struct netns_frags > {
    enum {
        ID = 65
    };
};
 

template <>
struct type_id < struct hlist_node > {
    enum {
        ID = 66
    };
};
 

template <>
struct type_id < struct lruvec > {
    enum {
        ID = 67
    };
};
 

template <>
struct type_id < struct neigh_seq_state > {
    enum {
        ID = 68
    };
};
 

template <>
struct type_id < struct pglist_data > {
    enum {
        ID = 69
    };
};
 

template <>
struct type_id < struct modesel_head > {
    enum {
        ID = 70
    };
};
 

template <>
struct type_id < struct acpi_connection_info > {
    enum {
        ID = 71
    };
};
 

template <>
struct type_id < struct xfrm_userspi_info > {
    enum {
        ID = 72
    };
};
 

template <>
struct type_id < struct ethtool_set_features_block > {
    enum {
        ID = 73
    };
};
 

template <>
struct type_id < struct acpi_table_drtm > {
    enum {
        ID = 74
    };
};
 

template <>
struct type_id < struct dvd_copyright > {
    enum {
        ID = 75
    };
};
 

template <>
struct type_id < struct ip_esp_hdr > {
    enum {
        ID = 76
    };
};
 

template <>
struct type_id < struct vm_region > {
    enum {
        ID = 77
    };
};
 

template <>
struct type_id < struct sg_iovec > {
    enum {
        ID = 78
    };
};
 

template <>
struct type_id < struct ethtool_gfeatures > {
    enum {
        ID = 79
    };
};
 

template <>
struct type_id < struct pnp_card_driver > {
    enum {
        ID = 80
    };
};
 

template <>
struct type_id < struct kmem_cache_node > {
    enum {
        ID = 81
    };
};
 

template <>
struct type_id < struct tc_u32_pcnt > {
    enum {
        ID = 82
    };
};
 

template <>
struct type_id < struct ethtool_flow_ext > {
    enum {
        ID = 83
    };
};
 

template <>
struct type_id < struct acpi_ivrs_de_header > {
    enum {
        ID = 84
    };
};
 

template <>
struct type_id < struct ifla_vf_info > {
    enum {
        ID = 85
    };
};
 

template <>
struct type_id < struct dom0_vga_console_info > {
    enum {
        ID = 86
    };
};
 

template <>
struct type_id < struct nf_bridge_info > {
    enum {
        ID = 87
    };
};
 

template <>
struct type_id < struct netdev_hw_addr > {
    enum {
        ID = 88
    };
};
 

template <>
struct type_id < struct dma_map_ops > {
    enum {
        ID = 89
    };
};
 

template <>
struct type_id < struct acpi_ibft_initiator > {
    enum {
        ID = 90
    };
};
 

template <>
struct type_id < struct rq_map_data > {
    enum {
        ID = 91
    };
};
 

template <>
struct type_id < struct nf_proto_net > {
    enum {
        ID = 92
    };
};
 

template <>
struct type_id < struct acpi_device_perf_state > {
    enum {
        ID = 93
    };
};
 

template <>
struct type_id < struct audit_krule > {
    enum {
        ID = 94
    };
};
 

template <>
struct type_id < struct neigh_parms > {
    enum {
        ID = 95
    };
};
 

template <>
struct type_id < struct tcp_options_received > {
    enum {
        ID = 96
    };
};
 

template <>
struct type_id < struct icmpv6msg_mib > {
    enum {
        ID = 97
    };
};
 

template <>
struct type_id < struct packet_command > {
    enum {
        ID = 98
    };
};
 

template <>
struct type_id < struct acpi_fde_info > {
    enum {
        ID = 99
    };
};
 

template <>
struct type_id < struct ethtool_ts_info > {
    enum {
        ID = 100
    };
};
 

template <>
struct type_id < struct fiemap_extent_info > {
    enum {
        ID = 101
    };
};
 

template <>
struct type_id < struct netns_xfrm > {
    enum {
        ID = 102
    };
};
 

template <>
struct type_id < struct ethtool_sset_info > {
    enum {
        ID = 103
    };
};
 

template <>
struct type_id < struct rb_node > {
    enum {
        ID = 104
    };
};
 

template <>
struct type_id < struct sock_iocb > {
    enum {
        ID = 105
    };
};
 

template <>
struct type_id < struct x86_init_mapping > {
    enum {
        ID = 106
    };
};
 

template <>
struct type_id < struct exec_domain > {
    enum {
        ID = 107
    };
};
 

template <>
struct type_id < struct arch_clocksource_data > {
    enum {
        ID = 108
    };
};
 

template <>
struct type_id < struct netdev_rx_queue > {
    enum {
        ID = 109
    };
};
 

template <>
struct type_id < struct fid > {
    enum {
        ID = 110
    };
};
 

template <>
struct type_id < struct cred > {
    enum {
        ID = 111
    };
};
 

template <>
struct type_id < struct xfrmu_spdhinfo > {
    enum {
        ID = 112
    };
};
 

template <>
struct type_id < struct rpmsg_device_id > {
    enum {
        ID = 113
    };
};
 

template <>
struct type_id < struct journal_head > {
    enum {
        ID = 114
    };
};
 

template <>
struct type_id < struct compat_sigaltstack > {
    enum {
        ID = 115
    };
};
 

template <>
struct type_id < struct ip_ct_tcp > {
    enum {
        ID = 116
    };
};
 

template <>
struct type_id < struct tc_prio_qopt > {
    enum {
        ID = 117
    };
};
 

template <>
struct type_id < struct upid > {
    enum {
        ID = 118
    };
};
 

template <>
struct type_id < struct shmid_kernel > {
    enum {
        ID = 119
    };
};
 

template <>
struct type_id < struct futex_pi_state > {
    enum {
        ID = 120
    };
};
 

template <>
struct type_id < struct elevator_type > {
    enum {
        ID = 121
    };
};
 

template <>
struct type_id < struct netns_ct > {
    enum {
        ID = 122
    };
};
 

template <>
struct type_id < struct ctl_table_root > {
    enum {
        ID = 123
    };
};
 

template <>
struct type_id < struct x86_init_pci > {
    enum {
        ID = 124
    };
};
 

template <>
struct type_id < struct tc_u32_sel > {
    enum {
        ID = 125
    };
};
 

template <>
struct type_id < struct thread_struct > {
    enum {
        ID = 126
    };
};
 

template <>
struct type_id < struct Qdisc_class_ops > {
    enum {
        ID = 127
    };
};
 

template <>
struct type_id < struct plist_head > {
    enum {
        ID = 128
    };
};
 

template <>
struct type_id < struct acpi_asf_info > {
    enum {
        ID = 129
    };
};
 

template <>
struct type_id < struct sigevent > {
    enum {
        ID = 130
    };
};
 

template <>
struct type_id < struct cma > {
    enum {
        ID = 131
    };
};
 

template <>
struct type_id < struct pv_cpu_ops > {
    enum {
        ID = 132
    };
};
 

template <>
struct type_id < struct skb_shared_hwtstamps > {
    enum {
        ID = 133
    };
};
 

template <>
struct type_id < struct socket_alloc > {
    enum {
        ID = 134
    };
};
 

template <>
struct type_id < struct hrtimer > {
    enum {
        ID = 135
    };
};
 

template <>
struct type_id < struct rq > {
    enum {
        ID = 136
    };
};
 

template <>
struct type_id < struct nf_conntrack > {
    enum {
        ID = 137
    };
};
 

template <>
struct type_id < struct acpi_resource_extended_address64 > {
    enum {
        ID = 138
    };
};
 

template <>
struct type_id < struct tpacket_stats > {
    enum {
        ID = 139
    };
};
 

template <>
struct type_id < struct mod_arch_specific > {
    enum {
        ID = 140
    };
};
 

template <>
struct type_id < struct dcbmsg > {
    enum {
        ID = 141
    };
};
 

template <>
struct type_id < struct acpi_dmar_reserved_memory > {
    enum {
        ID = 142
    };
};
 

template <>
struct type_id < struct ethtool_modinfo > {
    enum {
        ID = 143
    };
};
 

template <>
struct type_id < struct orig_ist > {
    enum {
        ID = 144
    };
};
 

template <>
struct type_id < struct tc_multiq_qopt > {
    enum {
        ID = 145
    };
};
 

template <>
struct type_id < struct tty_driver > {
    enum {
        ID = 146
    };
};
 

template <>
struct type_id < struct bootmem_data > {
    enum {
        ID = 147
    };
};
 

template <>
struct type_id < struct cmsghdr > {
    enum {
        ID = 148
    };
};
 

template <>
struct type_id < struct compat_sigevent > {
    enum {
        ID = 149
    };
};
 

template <>
struct type_id < struct acpi_table_ibft > {
    enum {
        ID = 150
    };
};
 

template <>
struct type_id < struct sigpending > {
    enum {
        ID = 151
    };
};
 

template <>
struct type_id < struct nf_exp_event_notifier > {
    enum {
        ID = 152
    };
};
 

template <>
struct type_id < struct klist > {
    enum {
        ID = 153
    };
};
 

template <>
struct type_id < struct keyring_name > {
    enum {
        ID = 154
    };
};
 

template <>
struct type_id < struct net_generic > {
    enum {
        ID = 155
    };
};
 

template <>
struct type_id < struct request_queue > {
    enum {
        ID = 156
    };
};
 

template <>
struct type_id < struct tc_estimator > {
    enum {
        ID = 157
    };
};
 

template <>
struct type_id < struct ff_trigger > {
    enum {
        ID = 158
    };
};
 

template <>
struct type_id < struct acpi_device_perf_flags > {
    enum {
        ID = 159
    };
};
 

template <>
struct type_id < struct netns_ipv6 > {
    enum {
        ID = 160
    };
};
 

template <>
struct type_id < struct inet6_request_sock > {
    enum {
        ID = 161
    };
};
 

template <>
struct type_id < struct acpi_drtm_id_list > {
    enum {
        ID = 162
    };
};
 

template <>
struct type_id < struct prot_inuse > {
    enum {
        ID = 163
    };
};
 

template <>
struct type_id < struct cee_pg > {
    enum {
        ID = 164
    };
};
 

template <>
struct type_id < struct inet_peer_base > {
    enum {
        ID = 165
    };
};
 

template <>
struct type_id < struct pci_ops > {
    enum {
        ID = 166
    };
};
 

template <>
struct type_id < struct proc_ns_operations > {
    enum {
        ID = 167
    };
};
 

template <>
struct type_id < struct mpc_bus > {
    enum {
        ID = 168
    };
};
 

template <>
struct type_id < struct vlan_hdr > {
    enum {
        ID = 169
    };
};
 

template <>
struct type_id < struct sctp_mib > {
    enum {
        ID = 170
    };
};
 

template <>
struct type_id < struct sched_domain > {
    enum {
        ID = 171
    };
};
 

template <>
struct type_id < struct nfq_ct_nat_hook > {
    enum {
        ID = 172
    };
};
 

template <>
struct type_id < struct ethtool_regs > {
    enum {
        ID = 173
    };
};
 

template <>
struct type_id < struct pvclock_wall_clock > {
    enum {
        ID = 174
    };
};
 

template <>
struct type_id < struct vlan_info > {
    enum {
        ID = 175
    };
};
 

template <>
struct type_id < struct compat_timeval > {
    enum {
        ID = 176
    };
};
 

template <>
struct type_id < struct group_source_req > {
    enum {
        ID = 177
    };
};
 

template <>
struct type_id < struct acpi_hest_aer_bridge > {
    enum {
        ID = 178
    };
};
 

template <>
struct type_id < struct jbd2_inode > {
    enum {
        ID = 179
    };
};
 

template <>
struct type_id < struct efi_info > {
    enum {
        ID = 180
    };
};
 

template <>
struct type_id < struct pernet_operations > {
    enum {
        ID = 181
    };
};
 

template <>
struct type_id < struct iovec > {
    enum {
        ID = 182
    };
};
 

template <>
struct type_id < struct modversion_info > {
    enum {
        ID = 183
    };
};
 

template <>
struct type_id < struct mm_walk > {
    enum {
        ID = 184
    };
};
 

template <>
struct type_id < struct perf_event_context > {
    enum {
        ID = 185
    };
};
 

template <>
struct type_id < struct tcf_ematch_hdr > {
    enum {
        ID = 186
    };
};
 

template <>
struct type_id < struct acpi_einj_entry > {
    enum {
        ID = 187
    };
};
 

template <>
struct type_id < struct cdrom_device_ops > {
    enum {
        ID = 188
    };
};
 

template <>
struct type_id < struct xfrm_userpolicy_id > {
    enum {
        ID = 189
    };
};
 

template <>
struct type_id < struct acpi_hardware_id > {
    enum {
        ID = 190
    };
};
 

template <>
struct type_id < struct __una_u32 > {
    enum {
        ID = 191
    };
};
 

template <>
struct type_id < struct skb_frag_struct > {
    enum {
        ID = 192
    };
};
 

template <>
struct type_id < struct nlmsgerr > {
    enum {
        ID = 193
    };
};
 

template <>
struct type_id < struct ymmh_struct > {
    enum {
        ID = 194
    };
};
 

template <>
struct type_id < struct kernel_param > {
    enum {
        ID = 195
    };
};
 

template <>
struct type_id < struct ethtool_ah_espip4_spec > {
    enum {
        ID = 196
    };
};
 

template <>
struct type_id < struct seq_operations > {
    enum {
        ID = 197
    };
};
 

template <>
struct type_id < struct aead_givcrypt_request > {
    enum {
        ID = 198
    };
};
 

template <>
struct type_id < struct x86_platform_ops > {
    enum {
        ID = 199
    };
};
 

template <>
struct type_id < struct revectored_struct > {
    enum {
        ID = 200
    };
};
 

template <>
struct type_id < struct request_pm_state > {
    enum {
        ID = 201
    };
};
 

template <>
struct type_id < struct acpi_hest_generic_data > {
    enum {
        ID = 202
    };
};
 

template <>
struct type_id < struct setup_header > {
    enum {
        ID = 203
    };
};
 

template <>
struct type_id < struct icmpv6msg_mib_device > {
    enum {
        ID = 204
    };
};
 

template <>
struct type_id < struct ata_eh_info > {
    enum {
        ID = 205
    };
};
 

template <>
struct type_id < struct partition > {
    enum {
        ID = 206
    };
};
 

template <>
struct type_id < struct netdev_hw_addr_list > {
    enum {
        ID = 207
    };
};
 

template <>
struct type_id < struct acpi_resource_uart_serialbus > {
    enum {
        ID = 208
    };
};
 

template <>
struct type_id < struct ff_replay > {
    enum {
        ID = 209
    };
};
 

template <>
struct type_id < struct acpi_bert_region > {
    enum {
        ID = 210
    };
};
 

template <>
struct type_id < struct bus_type > {
    enum {
        ID = 211
    };
};
 

template <>
struct type_id < struct nf_afinfo > {
    enum {
        ID = 212
    };
};
 

template <>
struct type_id < struct nlattr > {
    enum {
        ID = 213
    };
};
 

template <>
struct type_id < struct sk_filter > {
    enum {
        ID = 214
    };
};
 

template <>
struct type_id < struct elf32_rel > {
    enum {
        ID = 215
    };
};
 

template <>
struct type_id < struct sdio_device_id > {
    enum {
        ID = 216
    };
};
 

template <>
struct type_id < struct kernel_symbol > {
    enum {
        ID = 217
    };
};
 

template <>
struct type_id < struct inet_frag_queue > {
    enum {
        ID = 218
    };
};
 

template <>
struct type_id < struct ip_mc_socklist > {
    enum {
        ID = 219
    };
};
 

template <>
struct type_id < struct acpi_drtm_vtl_list > {
    enum {
        ID = 220
    };
};
 

template <>
struct type_id < struct ethtool_ringparam > {
    enum {
        ID = 221
    };
};
 

template <>
struct type_id < struct poll_wqueues > {
    enum {
        ID = 222
    };
};
 

template <>
struct type_id < struct scsi_host_template > {
    enum {
        ID = 223
    };
};
 

template <>
struct type_id < struct acpi_resource_gpio > {
    enum {
        ID = 224
    };
};
 

template <>
struct type_id < struct dev_ext_attribute > {
    enum {
        ID = 225
    };
};
 

template <>
struct type_id < struct pv_apic_ops > {
    enum {
        ID = 226
    };
};
 

template <>
struct type_id < struct acpi_resource_extended_irq > {
    enum {
        ID = 227
    };
};
 

template <>
struct type_id < struct atomic_notifier_head > {
    enum {
        ID = 228
    };
};
 

template <>
struct type_id < struct tc_hfsc_stats > {
    enum {
        ID = 229
    };
};
 

template <>
struct type_id < struct acpi_table_dmar > {
    enum {
        ID = 230
    };
};
 

template <>
struct type_id < struct scsi_host_cmd_pool > {
    enum {
        ID = 231
    };
};
 

template <>
struct type_id < struct inet_connection_sock_af_ops > {
    enum {
        ID = 232
    };
};
 

template <>
struct type_id < struct acpi_hest_aer_root > {
    enum {
        ID = 233
    };
};
 

template <>
struct type_id < struct tpacket3_hdr > {
    enum {
        ID = 234
    };
};
 

template <>
struct type_id < struct net > {
    enum {
        ID = 235
    };
};
 

template <>
struct type_id < struct xfrm_algo_aead > {
    enum {
        ID = 236
    };
};
 

template <>
struct type_id < struct tree_descr > {
    enum {
        ID = 237
    };
};
 

template <>
struct type_id < struct restart_block > {
    enum {
        ID = 238
    };
};
 

template <>
struct type_id < struct napi_gro_cb > {
    enum {
        ID = 239
    };
};
 

template <>
struct type_id < struct xfrm_usersa_info > {
    enum {
        ID = 240
    };
};
 

template <>
struct type_id < struct linux_xfrm_mib > {
    enum {
        ID = 241
    };
};
 

template <>
struct type_id < struct dev_archdata > {
    enum {
        ID = 242
    };
};
 

template <>
struct type_id < struct tc_hfsc_qopt > {
    enum {
        ID = 243
    };
};
 

template <>
struct type_id < struct compat_timex > {
    enum {
        ID = 244
    };
};
 

template <>
struct type_id < struct rwrt_feature_desc > {
    enum {
        ID = 245
    };
};
 

template <>
struct type_id < struct qstr > {
    enum {
        ID = 246
    };
};
 

template <>
struct type_id < struct scsi_device > {
    enum {
        ID = 247
    };
};
 

template <>
struct type_id < struct nf_conntrack_ecache > {
    enum {
        ID = 248
    };
};
 

template <>
struct type_id < struct nf_tcp_net > {
    enum {
        ID = 249
    };
};
 

template <>
struct type_id < struct e820entry > {
    enum {
        ID = 250
    };
};
 

template <>
struct type_id < struct cgroupfs_root > {
    enum {
        ID = 251
    };
};
 

template <>
struct type_id < struct bcma_device_id > {
    enum {
        ID = 252
    };
};
 

template <>
struct type_id < struct vm_fault > {
    enum {
        ID = 253
    };
};
 

template <>
struct type_id < struct vcpu_time_info > {
    enum {
        ID = 254
    };
};
 

template <>
struct type_id < struct radix_tree_root > {
    enum {
        ID = 255
    };
};
 

template <>
struct type_id < struct filename > {
    enum {
        ID = 256
    };
};
 

template <>
struct type_id < struct address_space > {
    enum {
        ID = 257
    };
};
 

template <>
struct type_id < struct tc_netem_reorder > {
    enum {
        ID = 258
    };
};
 

template <>
struct type_id < struct cdrom_changer_info > {
    enum {
        ID = 259
    };
};
 

template <>
struct type_id < struct fastopen_queue > {
    enum {
        ID = 260
    };
};
 

template <>
struct type_id < struct packet_mreq > {
    enum {
        ID = 261
    };
};
 

template <>
struct type_id < struct tcf_ematch_tree_hdr > {
    enum {
        ID = 262
    };
};
 

template <>
struct type_id < struct user_namespace > {
    enum {
        ID = 263
    };
};
 

template <>
struct type_id < struct tc_red_xstats > {
    enum {
        ID = 264
    };
};
 

template <>
struct type_id < struct compat_rlimit > {
    enum {
        ID = 265
    };
};
 

template <>
struct type_id < struct ifreq > {
    enum {
        ID = 266
    };
};
 

template <>
struct type_id < struct unixware_disklabel > {
    enum {
        ID = 267
    };
};
 

template <>
struct type_id < struct acpi_device_wakeup > {
    enum {
        ID = 268
    };
};
 

template <>
struct type_id < struct msghdr > {
    enum {
        ID = 269
    };
};
 

template <>
struct type_id < struct msg_queue > {
    enum {
        ID = 270
    };
};
 

template <>
struct type_id < struct tc_u32_key > {
    enum {
        ID = 271
    };
};
 

template <>
struct type_id < struct bsg_job > {
    enum {
        ID = 272
    };
};
 

template <>
struct type_id < struct inode > {
    enum {
        ID = 273
    };
};
 

template <>
struct type_id < struct simple_transaction_argresp > {
    enum {
        ID = 274
    };
};
 

template <>
struct type_id < struct tcp_sock > {
    enum {
        ID = 275
    };
};
 

template <>
struct type_id < struct ftrace_branch_data > {
    enum {
        ID = 276
    };
};
 

template <>
struct type_id < struct acpi_resource_address16 > {
    enum {
        ID = 277
    };
};
 

template <>
struct type_id < struct callback_head > {
    enum {
        ID = 278
    };
};
 

template <>
struct type_id < struct ff_effect > {
    enum {
        ID = 279
    };
};
 

template <>
struct type_id < struct k_sigaction > {
    enum {
        ID = 280
    };
};
 

template <>
struct type_id < struct acpi_pnp_device_id_list > {
    enum {
        ID = 281
    };
};
 

template <>
struct type_id < struct sock_filter > {
    enum {
        ID = 282
    };
};
 

template <>
struct type_id < struct inet_frags > {
    enum {
        ID = 283
    };
};
 

template <>
struct type_id < struct gnet_stats_basic_packed > {
    enum {
        ID = 284
    };
};
 

template <>
struct type_id < struct scm_cookie > {
    enum {
        ID = 285
    };
};
 

template <>
struct type_id < struct elf64_rel > {
    enum {
        ID = 286
    };
};
 

template <>
struct type_id < struct cpuinfo_x86 > {
    enum {
        ID = 287
    };
};
 

template <>
struct type_id < struct acpi_device_power > {
    enum {
        ID = 288
    };
};
 

template <>
struct type_id < struct input_dev > {
    enum {
        ID = 289
    };
};
 

template <>
struct type_id < struct compat_tms > {
    enum {
        ID = 290
    };
};
 

template <>
struct type_id < struct compat_ifreq > {
    enum {
        ID = 291
    };
};
 

template <>
struct type_id < struct nl_pktinfo > {
    enum {
        ID = 292
    };
};
 

template <>
struct type_id < struct input_event > {
    enum {
        ID = 293
    };
};
 

template <>
struct type_id < struct pci_host_bridge_window > {
    enum {
        ID = 294
    };
};
 

template <>
struct type_id < struct ifaddrmsg > {
    enum {
        ID = 295
    };
};
 

template <>
struct type_id < struct sg_io_hdr > {
    enum {
        ID = 296
    };
};
 

template <>
struct type_id < struct icmpv6_mib > {
    enum {
        ID = 297
    };
};
 

template <>
struct type_id < struct sockaddr_in > {
    enum {
        ID = 298
    };
};
 

template <>
struct type_id < struct sched_rt_entity > {
    enum {
        ID = 299
    };
};
 

template <>
struct type_id < struct pt_regs > {
    enum {
        ID = 300
    };
};
 

template <>
struct type_id < struct tc_netem_gimodel > {
    enum {
        ID = 301
    };
};
 

template <>
struct type_id < struct crypto_async_request > {
    enum {
        ID = 302
    };
};
 

template <>
struct type_id < struct tc_cbq_police > {
    enum {
        ID = 303
    };
};
 

template <>
struct type_id < struct udp_mib > {
    enum {
        ID = 304
    };
};
 

template <>
struct type_id < struct hrtimer_cpu_base > {
    enum {
        ID = 305
    };
};
 

template <>
struct type_id < struct acpi_whea_header > {
    enum {
        ID = 306
    };
};
 

template <>
struct type_id < struct acpi_hest_header > {
    enum {
        ID = 307
    };
};
 

template <>
struct type_id < struct acpi_resource_i2c_serialbus > {
    enum {
        ID = 308
    };
};
 

template <>
struct type_id < struct acpi_table_mcfg > {
    enum {
        ID = 309
    };
};
 

template <>
struct type_id < struct desc_struct > {
    enum {
        ID = 310
    };
};
 

template <>
struct type_id < struct sg_mapping_iter > {
    enum {
        ID = 311
    };
};
 

template <>
struct type_id < struct rw_semaphore > {
    enum {
        ID = 312
    };
};
 

template <>
struct type_id < struct acpi_ivrs_header > {
    enum {
        ID = 313
    };
};
 

template <>
struct type_id < struct acpi_einj_trigger > {
    enum {
        ID = 314
    };
};
 

template <>
struct type_id < struct mutex_waiter > {
    enum {
        ID = 315
    };
};
 

template <>
struct type_id < struct acpi_pmtt_socket > {
    enum {
        ID = 316
    };
};
 

template <>
struct type_id < struct compat_sysinfo > {
    enum {
        ID = 317
    };
};
 

template <>
struct type_id < struct icmp6hdr > {
    enum {
        ID = 318
    };
};
 

template <>
struct type_id < struct tvec_base > {
    enum {
        ID = 319
    };
};
 

template <>
struct type_id < struct tcp_sock_af_ops > {
    enum {
        ID = 320
    };
};
 

template <>
struct type_id < struct io_event > {
    enum {
        ID = 321
    };
};
 

template <>
struct type_id < struct tracepoint > {
    enum {
        ID = 322
    };
};
 

template <>
struct type_id < struct tpacket_block_desc > {
    enum {
        ID = 323
    };
};
 

template <>
struct type_id < struct nodemask_scratch > {
    enum {
        ID = 324
    };
};
 

template <>
struct type_id < struct elf32_shdr > {
    enum {
        ID = 325
    };
};
 

template <>
struct type_id < struct compat_old_linux_dirent > {
    enum {
        ID = 326
    };
};
 

template <>
struct type_id < struct ethtool_rxfh_indir > {
    enum {
        ID = 327
    };
};
 

template <>
struct type_id < struct fprop_local_single > {
    enum {
        ID = 328
    };
};
 

template <>
struct type_id < struct rt6_statistics > {
    enum {
        ID = 329
    };
};
 

template <>
struct type_id < struct icmpmsg_mib > {
    enum {
        ID = 330
    };
};
 

template <>
struct type_id < struct compat_ethtool_rx_flow_spec > {
    enum {
        ID = 331
    };
};
 

template <>
struct type_id < struct sem_undo_list > {
    enum {
        ID = 332
    };
};
 

template <>
struct type_id < struct tc_stats > {
    enum {
        ID = 333
    };
};
 

template <>
struct type_id < struct dvd_host_send_challenge > {
    enum {
        ID = 334
    };
};
 

template <>
struct type_id < struct kernel_vm86_regs > {
    enum {
        ID = 335
    };
};
 

template <>
struct type_id < struct xfrm_state > {
    enum {
        ID = 336
    };
};
 

template <>
struct type_id < struct neigh_hash_table > {
    enum {
        ID = 337
    };
};
 

template <>
struct type_id < struct quota_format_type > {
    enum {
        ID = 338
    };
};
 

template <>
struct type_id < struct pv_info > {
    enum {
        ID = 339
    };
};
 

template <>
struct type_id < struct xfrm_stats > {
    enum {
        ID = 340
    };
};
 

template <>
struct type_id < struct acpi_table_madt > {
    enum {
        ID = 341
    };
};
 

template <>
struct type_id < struct acpi_slic_header > {
    enum {
        ID = 342
    };
};
 

template <>
struct type_id < struct tpacket_req3 > {
    enum {
        ID = 343
    };
};
 

template <>
struct type_id < struct tcp_cookie_values > {
    enum {
        ID = 344
    };
};
 

template <>
struct type_id < struct rt6_info > {
    enum {
        ID = 345
    };
};
 

template <>
struct type_id < struct transaction_stats_s > {
    enum {
        ID = 346
    };
};
 

template <>
struct type_id < struct tc_cnt > {
    enum {
        ID = 347
    };
};
 

template <>
struct type_id < struct anon_vma_chain > {
    enum {
        ID = 348
    };
};
 

template <>
struct type_id < struct rtmsg > {
    enum {
        ID = 349
    };
};
 

template <>
struct type_id < struct acpi_table_mchi > {
    enum {
        ID = 350
    };
};
 

template <>
struct type_id < struct acpi_hest_notify > {
    enum {
        ID = 351
    };
};
 

template <>
struct type_id < struct ustat > {
    enum {
        ID = 352
    };
};
 

template <>
struct type_id < struct compat_msghdr > {
    enum {
        ID = 353
    };
};
 

template <>
struct type_id < struct mem_dqblk > {
    enum {
        ID = 354
    };
};
 

template <>
struct type_id < struct lock_class_key > {
    enum {
        ID = 355
    };
};
 

template <>
struct type_id < struct acpi_table_ivrs > {
    enum {
        ID = 356
    };
};
 

template <>
struct type_id < struct solaris_x86_slice > {
    enum {
        ID = 357
    };
};
 

template <>
struct type_id < struct bsd_disklabel > {
    enum {
        ID = 358
    };
};
 

template <>
struct type_id < struct pnp_dev > {
    enum {
        ID = 359
    };
};
 

template <>
struct type_id < struct sched_entity > {
    enum {
        ID = 360
    };
};
 

template <>
struct type_id < struct acpi_table_xsdt > {
    enum {
        ID = 361
    };
};
 

template <>
struct type_id < struct mpf_intel > {
    enum {
        ID = 362
    };
};
 

template <>
struct type_id < struct trap_info > {
    enum {
        ID = 363
    };
};
 

template <>
struct type_id < struct clocksource > {
    enum {
        ID = 364
    };
};
 

template <>
struct type_id < struct task_migration_notifier > {
    enum {
        ID = 365
    };
};
 

template <>
struct type_id < struct acpi_resource_end_tag > {
    enum {
        ID = 366
    };
};
 

template <>
struct type_id < struct ctl_dir > {
    enum {
        ID = 367
    };
};
 

template <>
struct type_id < struct journal_header_s > {
    enum {
        ID = 368
    };
};
 

template <>
struct type_id < struct elf64_phdr > {
    enum {
        ID = 369
    };
};
 

template <>
struct type_id < struct journal_block_tag_s > {
    enum {
        ID = 370
    };
};
 

template <>
struct type_id < struct user32 > {
    enum {
        ID = 371
    };
};
 

template <>
struct type_id < struct kernel_cap_struct > {
    enum {
        ID = 372
    };
};
 

template <>
struct type_id < struct exception_table_entry > {
    enum {
        ID = 373
    };
};
 

template <>
struct type_id < struct transaction_run_stats_s > {
    enum {
        ID = 374
    };
};
 

template <>
struct type_id < struct nla_policy > {
    enum {
        ID = 375
    };
};
 

template <>
struct type_id < struct xfrm_user_tmpl > {
    enum {
        ID = 376
    };
};
 

template <>
struct type_id < struct core_state > {
    enum {
        ID = 377
    };
};
 

template <>
struct type_id < struct request_list > {
    enum {
        ID = 378
    };
};
 

template <>
struct type_id < struct msi_desc > {
    enum {
        ID = 379
    };
};
 

template <>
struct type_id < struct flow_cache_ops > {
    enum {
        ID = 380
    };
};
 

template <>
struct type_id < struct prop_local_single > {
    enum {
        ID = 381
    };
};
 

template <>
struct type_id < struct acpi_pmtt_header > {
    enum {
        ID = 382
    };
};
 

template <>
struct type_id < struct resource_list_entry > {
    enum {
        ID = 383
    };
};
 

template <>
struct type_id < struct nf_icmp_net > {
    enum {
        ID = 384
    };
};
 

template <>
struct type_id < struct netns_nf_frag > {
    enum {
        ID = 385
    };
};
 

template <>
struct type_id < struct css_set > {
    enum {
        ID = 386
    };
};
 

template <>
struct type_id < struct phy_device > {
    enum {
        ID = 387
    };
};
 

template <>
struct type_id < struct blk_scsi_cmd_filter > {
    enum {
        ID = 388
    };
};
 

template <>
struct type_id < struct ethtool_pauseparam > {
    enum {
        ID = 389
    };
};
 

template <>
struct type_id < struct kqid > {
    enum {
        ID = 390
    };
};
 

template <>
struct type_id < struct screen_info > {
    enum {
        ID = 391
    };
};
 

template <>
struct type_id < struct req_iterator > {
    enum {
        ID = 392
    };
};
 

template <>
struct type_id < struct simple_xattrs > {
    enum {
        ID = 393
    };
};
 

template <>
struct type_id < struct acpi_resource > {
    enum {
        ID = 394
    };
};
 

template <>
struct type_id < struct blkcipher_desc > {
    enum {
        ID = 395
    };
};
 

template <>
struct type_id < struct rand_pool_info > {
    enum {
        ID = 396
    };
};
 

template <>
struct type_id < struct timer_rand_state > {
    enum {
        ID = 397
    };
};
 

template <>
struct type_id < struct kvec > {
    enum {
        ID = 398
    };
};
 

template <>
struct type_id < struct acpi_msct_proximity > {
    enum {
        ID = 399
    };
};
 

template <>
struct type_id < struct kset > {
    enum {
        ID = 400
    };
};
 

template <>
struct type_id < struct mem_dqinfo > {
    enum {
        ID = 401
    };
};
 

template <>
struct type_id < struct arch_spinlock > {
    enum {
        ID = 402
    };
};
 

template <>
struct type_id < struct ipv6_destopt_hao > {
    enum {
        ID = 403
    };
};
 

template <>
struct type_id < struct autogroup > {
    enum {
        ID = 404
    };
};
 

template <>
struct type_id < struct cpu_rmap > {
    enum {
        ID = 405
    };
};
 

template <>
struct type_id < struct elf32_phdr > {
    enum {
        ID = 406
    };
};
 

template <>
struct type_id < struct sigcontext > {
    enum {
        ID = 407
    };
};
 

template <>
struct type_id < struct acpi_device_dir > {
    enum {
        ID = 408
    };
};
 

template <>
struct type_id < struct ipv6_fl_socklist > {
    enum {
        ID = 409
    };
};
 

template <>
struct type_id < struct ipv6_mc_socklist > {
    enum {
        ID = 410
    };
};
 

template <>
struct type_id < struct data_chunk > {
    enum {
        ID = 411
    };
};
 

template <>
struct type_id < struct acpi_s3pt_header > {
    enum {
        ID = 412
    };
};
 

template <>
struct type_id < struct cdrom_multisession > {
    enum {
        ID = 413
    };
};
 

template <>
struct type_id < struct blk_queue_tags > {
    enum {
        ID = 414
    };
};
 

template <>
struct type_id < struct ip_msfilter > {
    enum {
        ID = 415
    };
};
 

template <>
struct type_id < struct ipv6hdr > {
    enum {
        ID = 416
    };
};
 

template <>
struct type_id < struct tpacket_hdr > {
    enum {
        ID = 417
    };
};
 

template <>
struct type_id < struct pm_qos_flags > {
    enum {
        ID = 418
    };
};
 

template <>
struct type_id < struct timezone > {
    enum {
        ID = 419
    };
};
 

template <>
struct type_id < struct cgroup_map_cb > {
    enum {
        ID = 420
    };
};
 

template <>
struct type_id < struct acpi_table_facs > {
    enum {
        ID = 421
    };
};
 

template <>
struct type_id < struct cipher_tfm > {
    enum {
        ID = 422
    };
};
 

template <>
struct type_id < struct math_emu_info > {
    enum {
        ID = 423
    };
};
 

template <>
struct type_id < struct tcphdr > {
    enum {
        ID = 424
    };
};
 

template <>
struct type_id < struct cdrom_subchnl > {
    enum {
        ID = 425
    };
};
 

template <>
struct type_id < struct dev_pm_ops > {
    enum {
        ID = 426
    };
};
 

template <>
struct type_id < struct node > {
    enum {
        ID = 427
    };
};
 

template <>
struct type_id < struct acpi_madt_local_apic > {
    enum {
        ID = 428
    };
};
 

template <>
struct type_id < struct cdrom_slot > {
    enum {
        ID = 429
    };
};
 

template <>
struct type_id < struct ablkcipher_tfm > {
    enum {
        ID = 430
    };
};
 

template <>
struct type_id < struct intel_iommu > {
    enum {
        ID = 431
    };
};
 

template <>
struct type_id < struct vm_operations_struct > {
    enum {
        ID = 432
    };
};
 

template <>
struct type_id < struct arch_vcpu_info > {
    enum {
        ID = 433
    };
};
 

template <>
struct type_id < struct xfrm_replay_state_esn > {
    enum {
        ID = 434
    };
};
 

template <>
struct type_id < struct i2c_device_id > {
    enum {
        ID = 435
    };
};
 

template <>
struct type_id < struct tc_fifo_qopt > {
    enum {
        ID = 436
    };
};
 

template <>
struct type_id < struct vm86_struct > {
    enum {
        ID = 437
    };
};
 

template <>
struct type_id < struct ethtool_stats > {
    enum {
        ID = 438
    };
};
 

template <>
struct type_id < struct rt_mutex_waiter > {
    enum {
        ID = 439
    };
};
 

template <>
struct type_id < struct tick_device > {
    enum {
        ID = 440
    };
};
 

template <>
struct type_id < struct tc_htb_xstats > {
    enum {
        ID = 441
    };
};
 

template <>
struct type_id < struct acpi_table_uefi > {
    enum {
        ID = 442
    };
};
 

template <>
struct type_id < struct crypto_ahash > {
    enum {
        ID = 443
    };
};
 

template <>
struct type_id < struct gnet_dump > {
    enum {
        ID = 444
    };
};
 

template <>
struct type_id < struct sched_group > {
    enum {
        ID = 445
    };
};
 

template <>
struct type_id < struct tcp_md5sig_info > {
    enum {
        ID = 446
    };
};
 

template <>
struct type_id < struct ipstats_mib > {
    enum {
        ID = 447
    };
};
 

template <>
struct type_id < struct crypto_attr_type > {
    enum {
        ID = 448
    };
};
 

template <>
struct type_id < struct page_cgroup > {
    enum {
        ID = 449
    };
};
 

template <>
struct type_id < struct raw_notifier_head > {
    enum {
        ID = 450
    };
};
 

template <>
struct type_id < struct cdrom_generic_command > {
    enum {
        ID = 451
    };
};
 

template <>
struct type_id < struct bgl_lock > {
    enum {
        ID = 452
    };
};
 

template <>
struct type_id < struct ata_ioports > {
    enum {
        ID = 453
    };
};
 

template <>
struct type_id < struct acpi_table_bgrt > {
    enum {
        ID = 454
    };
};
 

template <>
struct type_id < struct e820map > {
    enum {
        ID = 455
    };
};
 

template <>
struct type_id < struct device_attribute > {
    enum {
        ID = 456
    };
};
 

template <>
struct type_id < struct net_proto_family > {
    enum {
        ID = 457
    };
};
 

template <>
struct type_id < struct offload_callbacks > {
    enum {
        ID = 458
    };
};
 

template <>
struct type_id < struct input_handle > {
    enum {
        ID = 459
    };
};
 

template <>
struct type_id < struct acpi_table_hpet > {
    enum {
        ID = 460
    };
};
 

template <>
struct type_id < struct acpi_resource_start_dependent > {
    enum {
        ID = 461
    };
};
 

template <>
struct type_id < struct qdisc_skb_cb > {
    enum {
        ID = 462
    };
};
 

template <>
struct type_id < struct tpacket_bd_ts > {
    enum {
        ID = 463
    };
};
 

template <>
struct type_id < struct skcipher_givcrypt_request > {
    enum {
        ID = 464
    };
};
 

template <>
struct type_id < struct phy_c45_device_ids > {
    enum {
        ID = 465
    };
};
 

template <>
struct type_id < struct class_attribute_string > {
    enum {
        ID = 466
    };
};
 

template <>
struct type_id < struct pnp_device_id > {
    enum {
        ID = 467
    };
};
 

template <>
struct type_id < struct desc_ptr > {
    enum {
        ID = 468
    };
};
 

template <>
struct type_id < struct sysfs_ops > {
    enum {
        ID = 469
    };
};
 

template <>
struct type_id < struct __wait_queue > {
    enum {
        ID = 470
    };
};
 

template <>
struct type_id < struct task_cputime > {
    enum {
        ID = 471
    };
};
 

template <>
struct type_id < struct mp_ioapic_gsi > {
    enum {
        ID = 472
    };
};
 

template <>
struct type_id < struct timespec > {
    enum {
        ID = 473
    };
};
 

template <>
struct type_id < struct ipc_kludge > {
    enum {
        ID = 474
    };
};
 

template <>
struct type_id < struct pvclock_vcpu_time_info > {
    enum {
        ID = 475
    };
};
 

template <>
struct type_id < struct subsys_interface > {
    enum {
        ID = 476
    };
};
 

template <>
struct type_id < struct compat_iovec > {
    enum {
        ID = 477
    };
};
 

template <>
struct type_id < struct gnet_estimator > {
    enum {
        ID = 478
    };
};
 

template <>
struct type_id < struct ctl_path > {
    enum {
        ID = 479
    };
};
 

template <>
struct type_id < struct attribute_group > {
    enum {
        ID = 480
    };
};
 

template <>
struct type_id < struct tc_rsvp_gpi > {
    enum {
        ID = 481
    };
};
 

template <>
struct type_id < struct request_sock > {
    enum {
        ID = 482
    };
};
 

template <>
struct type_id < struct group_info > {
    enum {
        ID = 483
    };
};
 

template <>
struct type_id < struct _xstate > {
    enum {
        ID = 484
    };
};
 

template <>
struct type_id < struct vm_area_struct > {
    enum {
        ID = 485
    };
};
 

template <>
struct type_id < struct keyring_list > {
    enum {
        ID = 486
    };
};
 

template <>
struct type_id < struct ubuf_info > {
    enum {
        ID = 487
    };
};
 

template <>
struct type_id < struct pci_cap_saved_data > {
    enum {
        ID = 488
    };
};
 

template <>
struct type_id < struct if_settings > {
    enum {
        ID = 489
    };
};
 

template <>
struct type_id < struct cipher_alg > {
    enum {
        ID = 490
    };
};
 

template <>
struct type_id < struct srcu_struct_array > {
    enum {
        ID = 491
    };
};
 

template <>
struct type_id < struct crypto_attr_alg > {
    enum {
        ID = 492
    };
};
 

template <>
struct type_id < struct quota_info > {
    enum {
        ID = 493
    };
};
 

template <>
struct type_id < struct fs_disk_quota > {
    enum {
        ID = 494
    };
};
 

template <>
struct type_id < struct disk_part_iter > {
    enum {
        ID = 495
    };
};
 

template <>
struct type_id < struct cgroup_subsys > {
    enum {
        ID = 496
    };
};
 

template <>
struct type_id < struct pci_bus > {
    enum {
        ID = 497
    };
};
 

template <>
struct type_id < struct pipe_inode_info > {
    enum {
        ID = 498
    };
};
 

template <>
struct type_id < struct acpi_pci_root > {
    enum {
        ID = 499
    };
};
 

template <>
struct type_id < struct ata_timing > {
    enum {
        ID = 500
    };
};
 

template <>
struct type_id < struct ip_options_data > {
    enum {
        ID = 501
    };
};
 

template <>
struct type_id < struct hh_cache > {
    enum {
        ID = 502
    };
};
 

template <>
struct type_id < struct inet_sock > {
    enum {
        ID = 503
    };
};
 

template <>
struct type_id < struct icmpv6_nd_advt > {
    enum {
        ID = 504
    };
};
 

template <>
struct type_id < struct key_type > {
    enum {
        ID = 505
    };
};
 

template <>
struct type_id < struct irq_domain > {
    enum {
        ID = 506
    };
};
 

template <>
struct type_id < struct export_operations > {
    enum {
        ID = 507
    };
};
 

template <>
struct type_id < struct local_apic > {
    enum {
        ID = 508
    };
};
 

template <>
struct type_id < struct tc_tbf_qopt > {
    enum {
        ID = 509
    };
};
 

template <>
struct type_id < struct memcg_cache_params > {
    enum {
        ID = 510
    };
};
 

template <>
struct type_id < struct bvec_merge_data > {
    enum {
        ID = 511
    };
};
 

template <>
struct type_id < struct zone_padding > {
    enum {
        ID = 512
    };
};
 

template <>
struct type_id < struct sched_statistics > {
    enum {
        ID = 513
    };
};
 

template <>
struct type_id < struct user_i387_ia32_struct > {
    enum {
        ID = 514
    };
};
 

template <>
struct type_id < struct inet6_skb_parm > {
    enum {
        ID = 515
    };
};
 

template <>
struct type_id < struct acpi_madt_local_x2apic_nmi > {
    enum {
        ID = 516
    };
};
 

template <>
struct type_id < struct va_alignment > {
    enum {
        ID = 517
    };
};
 

template <>
struct type_id < struct napi_struct > {
    enum {
        ID = 518
    };
};
 

template <>
struct type_id < struct acpi_madt_generic_distributor > {
    enum {
        ID = 519
    };
};
 

template <>
struct type_id < struct static_key > {
    enum {
        ID = 520
    };
};
 

template <>
struct type_id < struct compat_msgbuf > {
    enum {
        ID = 521
    };
};
 

template <>
struct type_id < struct ieee_maxrate > {
    enum {
        ID = 522
    };
};
 

template <>
struct type_id < struct elevator_ops > {
    enum {
        ID = 523
    };
};
 

template <>
struct type_id < struct pgprot > {
    enum {
        ID = 524
    };
};
 

template <>
struct type_id < struct tc_sizespec > {
    enum {
        ID = 525
    };
};
 

template <>
struct type_id < struct elf64_note > {
    enum {
        ID = 526
    };
};
 

template <>
struct type_id < struct IO_APIC_route_entry > {
    enum {
        ID = 527
    };
};
 

template <>
struct type_id < struct pv_lock_ops > {
    enum {
        ID = 528
    };
};
 

template <>
struct type_id < struct dentry_operations > {
    enum {
        ID = 529
    };
};
 

template <>
struct type_id < struct hlist_bl_node > {
    enum {
        ID = 530
    };
};
 

template <>
struct type_id < struct pci_host_bridge > {
    enum {
        ID = 531
    };
};
 

template <>
struct type_id < struct attribute > {
    enum {
        ID = 532
    };
};
 

template <>
struct type_id < struct irq_cfg > {
    enum {
        ID = 533
    };
};
 

template <>
struct type_id < struct paravirt_patch_site > {
    enum {
        ID = 534
    };
};
 

template <>
struct type_id < struct acpi_dmar_device_scope > {
    enum {
        ID = 535
    };
};
 

template <>
struct type_id < struct acpi_madt_local_x2apic > {
    enum {
        ID = 536
    };
};
 

template <>
struct type_id < struct tc_red_qopt > {
    enum {
        ID = 537
    };
};
 

template <>
struct type_id < struct x86_init_paging > {
    enum {
        ID = 538
    };
};
 

template <>
struct type_id < struct ff_rumble_effect > {
    enum {
        ID = 539
    };
};
 

template <>
struct type_id < struct fpu > {
    enum {
        ID = 540
    };
};
 

template <>
struct type_id < struct acpi_ibft_target > {
    enum {
        ID = 541
    };
};
 

template <>
struct type_id < struct setup_data > {
    enum {
        ID = 542
    };
};
 

template <>
struct type_id < struct class_interface > {
    enum {
        ID = 543
    };
};
 

template <>
struct type_id < struct journal_superblock_s > {
    enum {
        ID = 544
    };
};
 

template <>
struct type_id < struct nsproxy > {
    enum {
        ID = 545
    };
};
 

template <>
struct type_id < struct softirq_action > {
    enum {
        ID = 546
    };
};
 

template <>
struct type_id < struct per_cpu_pages > {
    enum {
        ID = 547
    };
};
 

template <>
struct type_id < struct user_regs_struct > {
    enum {
        ID = 548
    };
};
 

template <>
struct type_id < struct acpi_uuid > {
    enum {
        ID = 549
    };
};
 

template <>
struct type_id < struct ifla_vf_vlan > {
    enum {
        ID = 550
    };
};
 

template <>
struct type_id < struct delayed_work > {
    enum {
        ID = 551
    };
};
 

template <>
struct type_id < struct hotplug_slot > {
    enum {
        ID = 552
    };
};
 

template <>
struct type_id < struct css_device_id > {
    enum {
        ID = 553
    };
};
 

template <>
struct type_id < struct acpi_slic_marker > {
    enum {
        ID = 554
    };
};
 

template <>
struct type_id < struct kparam_array > {
    enum {
        ID = 555
    };
};
 

template <>
struct type_id < struct simple_xattr > {
    enum {
        ID = 556
    };
};
 

template <>
struct type_id < struct blkcipher_tfm > {
    enum {
        ID = 557
    };
};
 

template <>
struct type_id < struct mem_cgroup > {
    enum {
        ID = 558
    };
};
 

template <>
struct type_id < struct crypto_cipher > {
    enum {
        ID = 559
    };
};
 

template <>
struct type_id < struct fib6_table > {
    enum {
        ID = 560
    };
};
 

template <>
struct type_id < struct parisc_device_id > {
    enum {
        ID = 561
    };
};
 

template <>
struct type_id < struct boot_params > {
    enum {
        ID = 562
    };
};
 

template <>
struct type_id < struct acpi_madt_nmi_source > {
    enum {
        ID = 563
    };
};
 

template <>
struct type_id < struct ipv4_devconf > {
    enum {
        ID = 564
    };
};
 

template <>
struct type_id < struct xt_table > {
    enum {
        ID = 565
    };
};
 

template <>
struct type_id < struct in6_ifreq > {
    enum {
        ID = 566
    };
};
 

template <>
struct type_id < struct acpi_handle_list > {
    enum {
        ID = 567
    };
};
 

template <>
struct type_id < struct prefix_cacheinfo > {
    enum {
        ID = 568
    };
};
 

template <>
struct type_id < struct ata_bmdma_prd > {
    enum {
        ID = 569
    };
};
 

template <>
struct type_id < struct acpi_resource_source > {
    enum {
        ID = 570
    };
};
 

template <>
struct type_id < struct sys_desc_table > {
    enum {
        ID = 571
    };
};
 

template <>
struct type_id < struct tc_cbq_wrropt > {
    enum {
        ID = 572
    };
};
 

template <>
struct type_id < struct inet6_timewait_sock > {
    enum {
        ID = 573
    };
};
 

template <>
struct type_id < struct cpu_vfs_cap_data > {
    enum {
        ID = 574
    };
};
 

template <>
struct type_id < struct hash_desc > {
    enum {
        ID = 575
    };
};
 

template <>
struct type_id < struct quota_module_name > {
    enum {
        ID = 576
    };
};
 

template <>
struct type_id < struct acpi_table_fadt > {
    enum {
        ID = 577
    };
};
 

template <>
struct type_id < struct ipv6_pinfo > {
    enum {
        ID = 578
    };
};
 

template <>
struct type_id < struct fasync_struct > {
    enum {
        ID = 579
    };
};
 

template <>
struct type_id < struct icmpv6_nd_ra > {
    enum {
        ID = 580
    };
};
 

template <>
struct type_id < struct tcp_request_sock_ops > {
    enum {
        ID = 581
    };
};
 

template <>
struct type_id < struct nf_sockopt_ops > {
    enum {
        ID = 582
    };
};
 

template <>
struct type_id < struct gnet_stats_queue > {
    enum {
        ID = 583
    };
};
 

template <>
struct type_id < struct flow_cache_object > {
    enum {
        ID = 584
    };
};
 

template <>
struct type_id < struct ts_ops > {
    enum {
        ID = 585
    };
};
 

template <>
struct type_id < struct dcb_app > {
    enum {
        ID = 586
    };
};
 

template <>
struct type_id < struct ifla_port_vsi > {
    enum {
        ID = 587
    };
};
 

template <>
struct type_id < struct pnp_fixup > {
    enum {
        ID = 588
    };
};
 

template <>
struct type_id < struct netdev_fcoe_hbainfo > {
    enum {
        ID = 589
    };
};
 

template <>
struct type_id < struct cdrom_read_audio > {
    enum {
        ID = 590
    };
};
 

template <>
struct type_id < struct pv_init_ops > {
    enum {
        ID = 591
    };
};
 

template <>
struct type_id < struct cdrom_msf > {
    enum {
        ID = 592
    };
};
 

template <>
struct type_id < struct prefixmsg > {
    enum {
        ID = 593
    };
};
 

template <>
struct type_id < struct scsi_cmnd > {
    enum {
        ID = 594
    };
};
 

template <>
struct type_id < struct ip_ct_tcp_state > {
    enum {
        ID = 595
    };
};
 

template <>
struct type_id < struct acpi_srat_x2apic_cpu_affinity > {
    enum {
        ID = 596
    };
};
 

template <>
struct type_id < struct ndt_stats > {
    enum {
        ID = 597
    };
};
 

template <>
struct type_id < struct inet_bind_bucket > {
    enum {
        ID = 598
    };
};
 

template <>
struct type_id < struct acpi_device_info > {
    enum {
        ID = 599
    };
};
 

template <>
struct type_id < struct mrw_feature_desc > {
    enum {
        ID = 600
    };
};
 

template <>
struct type_id < struct sched_class > {
    enum {
        ID = 601
    };
};
 

template <>
struct type_id < struct platform_device_id > {
    enum {
        ID = 602
    };
};
 

template <>
struct type_id < struct rtnl_link_stats64 > {
    enum {
        ID = 603
    };
};
 

template <>
struct type_id < struct rta_mfc_stats > {
    enum {
        ID = 604
    };
};
 

template <>
struct type_id < struct linux_binprm > {
    enum {
        ID = 605
    };
};
 

template <>
struct type_id < struct bug_entry > {
    enum {
        ID = 606
    };
};
 

template <>
struct type_id < struct cpu_itimer > {
    enum {
        ID = 607
    };
};
 

template <>
struct type_id < struct acpi_device_status > {
    enum {
        ID = 608
    };
};
 

template <>
struct type_id < struct ethtool_eeprom > {
    enum {
        ID = 609
    };
};
 

template <>
struct type_id < struct preempt_notifier > {
    enum {
        ID = 610
    };
};
 

template <>
struct type_id < struct flowidn > {
    enum {
        ID = 611
    };
};
 

template <>
struct type_id < struct ipv6_opt_hdr > {
    enum {
        ID = 612
    };
};
 

template <>
struct type_id < struct acpi_pmtt_domain > {
    enum {
        ID = 613
    };
};
 

template <>
struct type_id < struct acpi_hest_ia_machine_check > {
    enum {
        ID = 614
    };
};
 

template <>
struct type_id < struct elf32_rela > {
    enum {
        ID = 615
    };
};
 

template <>
struct type_id < struct sg_table > {
    enum {
        ID = 616
    };
};
 

template <>
struct type_id < struct mode_page_header > {
    enum {
        ID = 617
    };
};
 

template <>
struct type_id < struct qtree_mem_dqinfo > {
    enum {
        ID = 618
    };
};
 

template <>
struct type_id < struct acpi_mcfg_allocation > {
    enum {
        ID = 619
    };
};
 

template <>
struct type_id < struct ipack_device_id > {
    enum {
        ID = 620
    };
};
 

template <>
struct type_id < struct elf64_rela > {
    enum {
        ID = 621
    };
};
 

template <>
struct type_id < struct blkcipher_alg > {
    enum {
        ID = 622
    };
};
 

template <>
struct type_id < struct xfrm_algo > {
    enum {
        ID = 623
    };
};
 

template <>
struct type_id < struct statfs > {
    enum {
        ID = 624
    };
};
 

template <>
struct type_id < struct kioctx > {
    enum {
        ID = 625
    };
};
 

template <>
struct type_id < struct tcp_request_sock > {
    enum {
        ID = 626
    };
};
 

template <>
struct type_id < struct xfrm_replay_state > {
    enum {
        ID = 627
    };
};
 

template <>
struct type_id < struct acpi_table_header > {
    enum {
        ID = 628
    };
};
 

template <>
struct type_id < struct sched_param > {
    enum {
        ID = 629
    };
};
 

template <>
struct type_id < struct crypto_attr_u32 > {
    enum {
        ID = 630
    };
};
 

template <>
struct type_id < struct poll_table_page > {
    enum {
        ID = 631
    };
};
 

template <>
struct type_id < struct ethtool_rxnfc > {
    enum {
        ID = 632
    };
};
 

template <>
struct type_id < struct writeback_control > {
    enum {
        ID = 633
    };
};
 

template <>
struct type_id < struct group_filter > {
    enum {
        ID = 634
    };
};
 

template <>
struct type_id < struct acpi_madt_local_apic_override > {
    enum {
        ID = 635
    };
};
 

template <>
struct type_id < struct lock_manager > {
    enum {
        ID = 636
    };
};
 

template <>
struct type_id < struct journal_s > {
    enum {
        ID = 637
    };
};
 

template <>
struct type_id < struct acpi_pcct_shared_memory > {
    enum {
        ID = 638
    };
};
 

template <>
struct type_id < struct phy_driver > {
    enum {
        ID = 639
    };
};
 

template <>
struct type_id < struct acpi_asf_header > {
    enum {
        ID = 640
    };
};
 

template <>
struct type_id < struct slab > {
    enum {
        ID = 641
    };
};
 

template <>
struct type_id < struct compress_tfm > {
    enum {
        ID = 642
    };
};
 

template <>
struct type_id < struct tcp6_request_sock > {
    enum {
        ID = 643
    };
};
 

template <>
struct type_id < struct acpi_resource_spi_serialbus > {
    enum {
        ID = 644
    };
};
 

template <>
struct type_id < struct acpi_device > {
    enum {
        ID = 645
    };
};
 

template <>
struct type_id < struct disk_part_tbl > {
    enum {
        ID = 646
    };
};
 

template <>
struct type_id < struct kmem_cache_order_objects > {
    enum {
        ID = 647
    };
};
 

template <>
struct type_id < struct rtattr > {
    enum {
        ID = 648
    };
};
 

template <>
struct type_id < struct ff_device > {
    enum {
        ID = 649
    };
};
 

template <>
struct type_id < struct dev_pm_qos > {
    enum {
        ID = 650
    };
};
 

template <>
struct type_id < struct nlmsghdr > {
    enum {
        ID = 651
    };
};
 

template <>
struct type_id < struct scsi_target > {
    enum {
        ID = 652
    };
};
 

template <>
struct type_id < struct ff_constant_effect > {
    enum {
        ID = 653
    };
};
 

template <>
struct type_id < struct crypto_type > {
    enum {
        ID = 654
    };
};
 

template <>
struct type_id < struct class_container > {
    enum {
        ID = 655
    };
};
 

template <>
struct type_id < struct posix_acl_entry > {
    enum {
        ID = 656
    };
};
 

template <>
struct type_id < struct cg_proto > {
    enum {
        ID = 657
    };
};
 

template <>
struct type_id < struct ifla_vf_mac > {
    enum {
        ID = 658
    };
};
 

template <>
struct type_id < struct acpi_resource_address64 > {
    enum {
        ID = 659
    };
};
 

template <>
struct type_id < struct x86_init_timers > {
    enum {
        ID = 660
    };
};
 

template <>
struct type_id < struct acpi_device_perf > {
    enum {
        ID = 661
    };
};
 

template <>
struct type_id < struct kobject > {
    enum {
        ID = 662
    };
};
 

template <>
struct type_id < struct sched_group_power > {
    enum {
        ID = 663
    };
};
 

template <>
struct type_id < struct flowi_common > {
    enum {
        ID = 664
    };
};
 

template <>
struct type_id < struct buffer_head > {
    enum {
        ID = 665
    };
};
 

template <>
struct type_id < struct ethtool_gstrings > {
    enum {
        ID = 666
    };
};
 

template <>
struct type_id < struct cftype > {
    enum {
        ID = 667
    };
};
 

template <>
struct type_id < struct arch_shared_info > {
    enum {
        ID = 668
    };
};
 

template <>
struct type_id < struct swap_list_t > {
    enum {
        ID = 669
    };
};
 

template <>
struct type_id < struct pcpu_tstats > {
    enum {
        ID = 670
    };
};
 

template <>
struct type_id < struct kcore_list > {
    enum {
        ID = 671
    };
};
 

template <>
struct type_id < struct tpacket_hdr_v1 > {
    enum {
        ID = 672
    };
};
 

template <>
struct type_id < struct symsearch > {
    enum {
        ID = 673
    };
};
 

template <>
struct type_id < struct tpacket_auxdata > {
    enum {
        ID = 674
    };
};
 

template <>
struct type_id < struct dyn_arch_ftrace > {
    enum {
        ID = 675
    };
};
 

template <>
struct type_id < struct siginfo > {
    enum {
        ID = 676
    };
};
 

template <>
struct type_id < struct acpi_table_einj > {
    enum {
        ID = 677
    };
};
 

template <>
struct type_id < struct tty_struct > {
    enum {
        ID = 678
    };
};
 

template <>
struct type_id < struct acpi_ibft_control > {
    enum {
        ID = 679
    };
};
 

template <>
struct type_id < struct nf_queue_entry > {
    enum {
        ID = 680
    };
};
 

template <>
struct type_id < struct seccomp > {
    enum {
        ID = 681
    };
};
 

template <>
struct type_id < struct user_xsave_hdr > {
    enum {
        ID = 682
    };
};
 

template <>
struct type_id < struct cdrom_msf0 > {
    enum {
        ID = 683
    };
};
 

template <>
struct type_id < struct crypto_alg > {
    enum {
        ID = 684
    };
};
 

template <>
struct type_id < struct acpi_madt_io_sapic > {
    enum {
        ID = 685
    };
};
 

template <>
struct type_id < struct acpi_mpst_power_state > {
    enum {
        ID = 686
    };
};
 

template <>
struct type_id < struct resource > {
    enum {
        ID = 687
    };
};
 

template <>
struct type_id < struct css_id > {
    enum {
        ID = 688
    };
};
 

template <>
struct type_id < struct crypto_rng > {
    enum {
        ID = 689
    };
};
 

template <>
struct type_id < struct __sysctl_args > {
    enum {
        ID = 690
    };
};
 

template <>
struct type_id < struct gendisk > {
    enum {
        ID = 691
    };
};
 

template <>
struct type_id < struct ip_mreqn > {
    enum {
        ID = 692
    };
};
 

template <>
struct type_id < struct in_device > {
    enum {
        ID = 693
    };
};
 

template <>
struct type_id < struct __large_struct > {
    enum {
        ID = 694
    };
};
 

template <>
struct type_id < struct xfrmu_spdinfo > {
    enum {
        ID = 695
    };
};
 

template <>
struct type_id < struct dev_pm_info > {
    enum {
        ID = 696
    };
};
 

template <>
struct type_id < struct security_mnt_opts > {
    enum {
        ID = 697
    };
};
 

template <>
struct type_id < struct backing_dev_info > {
    enum {
        ID = 698
    };
};
 

template <>
struct type_id < struct compat_if_settings > {
    enum {
        ID = 699
    };
};
 

template <>
struct type_id < struct acpi_device_ops > {
    enum {
        ID = 700
    };
};
 

template <>
struct type_id < struct itimerval > {
    enum {
        ID = 701
    };
};
 

template <>
struct type_id < struct mm_rss_stat > {
    enum {
        ID = 702
    };
};
 

template <>
struct type_id < struct pnp_id > {
    enum {
        ID = 703
    };
};
 

template <>
struct type_id < struct crypto_hash > {
    enum {
        ID = 704
    };
};
 

template <>
struct type_id < struct acpi_table_waet > {
    enum {
        ID = 705
    };
};
 

template <>
struct type_id < struct net_device_stats > {
    enum {
        ID = 706
    };
};
 

template <>
struct type_id < struct timecounter > {
    enum {
        ID = 707
    };
};
 

template <>
struct type_id < struct inet_cork_full > {
    enum {
        ID = 708
    };
};
 

template <>
struct type_id < struct sembuf > {
    enum {
        ID = 709
    };
};
 

template <>
struct type_id < struct iommu_ops > {
    enum {
        ID = 710
    };
};
 

template <>
struct type_id < struct sock_fprog > {
    enum {
        ID = 711
    };
};
 

template <>
struct type_id < struct acpi_dbg2_device > {
    enum {
        ID = 712
    };
};
 

template <>
struct type_id < struct driver_private > {
    enum {
        ID = 713
    };
};
 

template <>
struct type_id < struct compat_itimerspec > {
    enum {
        ID = 714
    };
};
 

template <>
struct type_id < struct compat_ethtool_rxnfc > {
    enum {
        ID = 715
    };
};
 

template <>
struct type_id < struct module_ref > {
    enum {
        ID = 716
    };
};
 

template <>
struct type_id < struct x86_init_oem > {
    enum {
        ID = 717
    };
};
 

template <>
struct type_id < struct task_rss_stat > {
    enum {
        ID = 718
    };
};
 

template <>
struct type_id < struct acpi_pnp_device_id > {
    enum {
        ID = 719
    };
};
 

template <>
struct type_id < struct rng_tfm > {
    enum {
        ID = 720
    };
};
 

template <>
struct type_id < struct nf_ct_event_notifier > {
    enum {
        ID = 721
    };
};
 

template <>
struct type_id < struct netlink_callback > {
    enum {
        ID = 722
    };
};
 

template <>
struct type_id < struct ifla_vlan_flags > {
    enum {
        ID = 723
    };
};
 

template <>
struct type_id < struct acpi_system_info > {
    enum {
        ID = 724
    };
};
 

template <>
struct type_id < struct bus_attribute > {
    enum {
        ID = 725
    };
};
 

template <>
struct type_id < struct key > {
    enum {
        ID = 726
    };
};
 

template <>
struct type_id < struct acpi_einj_error_type_with_addr > {
    enum {
        ID = 727
    };
};
 

template <>
struct type_id < struct pci_bus_region > {
    enum {
        ID = 728
    };
};
 

template <>
struct type_id < struct tc_sfq_xstats > {
    enum {
        ID = 729
    };
};
 

template <>
struct type_id < struct hash_alg_common > {
    enum {
        ID = 730
    };
};
 

template <>
struct type_id < struct free_area > {
    enum {
        ID = 731
    };
};
 

template <>
struct type_id < struct srcu_notifier_head > {
    enum {
        ID = 732
    };
};
 

template <>
struct type_id < struct tracepoint_iter > {
    enum {
        ID = 733
    };
};
 

template <>
struct type_id < struct ts_config > {
    enum {
        ID = 734
    };
};
 

template <>
struct type_id < struct address_space_operations > {
    enum {
        ID = 735
    };
};
 

template <>
struct type_id < struct acpi_rasf_shared_memory > {
    enum {
        ID = 736
    };
};
 

template <>
struct type_id < struct acpi_ibft_nic > {
    enum {
        ID = 737
    };
};
 

template <>
struct type_id < struct xfrm_user_report > {
    enum {
        ID = 738
    };
};
 

template <>
struct type_id < struct cputime > {
    enum {
        ID = 739
    };
};
 

template <>
struct type_id < struct acpi_generic_address > {
    enum {
        ID = 740
    };
};
 

template <>
struct type_id < struct acpi_resource_common_serialbus > {
    enum {
        ID = 741
    };
};
 

template <>
struct type_id < struct phy_fixup > {
    enum {
        ID = 742
    };
};
 

template <>
struct type_id < struct block_device > {
    enum {
        ID = 743
    };
};
 

template <>
struct type_id < struct acpi_osc_context > {
    enum {
        ID = 744
    };
};
 

template <>
struct type_id < struct acpi_device_id > {
    enum {
        ID = 745
    };
};
 

template <>
struct type_id < struct __kernel_sockaddr_storage > {
    enum {
        ID = 746
    };
};
 

template <>
struct type_id < struct dvd_lu_send_asf > {
    enum {
        ID = 747
    };
};
 

template <>
struct type_id < struct acpi_table_spcr > {
    enum {
        ID = 748
    };
};
 

template <>
struct type_id < struct scatterlist > {
    enum {
        ID = 749
    };
};
 

template <>
struct type_id < struct module_sect_attrs > {
    enum {
        ID = 750
    };
};
 

template <>
struct type_id < struct acpi_sleep_functions > {
    enum {
        ID = 751
    };
};
 

template <>
struct type_id < struct signal_struct > {
    enum {
        ID = 752
    };
};
 

template <>
struct type_id < struct proto > {
    enum {
        ID = 753
    };
};
 

template <>
struct type_id < struct compat_ustat > {
    enum {
        ID = 754
    };
};
 

template <>
struct type_id < struct smp_ops > {
    enum {
        ID = 755
    };
};
 

template <>
struct type_id < struct tcp_repair_opt > {
    enum {
        ID = 756
    };
};
 

template <>
struct type_id < struct apm_bios_info > {
    enum {
        ID = 757
    };
};
 

template <>
struct type_id < struct IR_IO_APIC_route_entry > {
    enum {
        ID = 758
    };
};
 

template <>
struct type_id < struct match_token > {
    enum {
        ID = 759
    };
};
 

template <>
struct type_id < struct acpi_mem_space_context > {
    enum {
        ID = 760
    };
};
 

template <>
struct type_id < struct real_mode_header > {
    enum {
        ID = 761
    };
};
 

template <>
struct type_id < struct io_context > {
    enum {
        ID = 762
    };
};
 

template <>
struct type_id < struct tc_rsvp_pinfo > {
    enum {
        ID = 763
    };
};
 

template <>
struct type_id < struct llist_node > {
    enum {
        ID = 764
    };
};
 

template <>
struct type_id < struct dma_slave_config > {
    enum {
        ID = 765
    };
};
 

template <>
struct type_id < struct ata_acpi_drive > {
    enum {
        ID = 766
    };
};
 

template <>
struct type_id < struct aead_tfm > {
    enum {
        ID = 767
    };
};
 

template <>
struct type_id < struct tc_choke_qopt > {
    enum {
        ID = 768
    };
};
 

template <>
struct type_id < struct in6_pktinfo > {
    enum {
        ID = 769
    };
};
 

template <>
struct type_id < struct listen_sock > {
    enum {
        ID = 770
    };
};
 

template <>
struct type_id < struct acpi_einj_vendor > {
    enum {
        ID = 771
    };
};
 

template <>
struct type_id < struct quotactl_ops > {
    enum {
        ID = 772
    };
};
 

template <>
struct type_id < struct core_thread > {
    enum {
        ID = 773
    };
};
 

template <>
struct type_id < struct dquot > {
    enum {
        ID = 774
    };
};
 

template <>
struct type_id < struct zonelist > {
    enum {
        ID = 775
    };
};
 

template <>
struct type_id < struct pcie_link_state > {
    enum {
        ID = 776
    };
};
 

template <>
struct type_id < struct kmem_cachep > {
    enum {
        ID = 777
    };
};
 

template <>
struct type_id < struct module_param_attrs > {
    enum {
        ID = 778
    };
};
 

template <>
struct type_id < struct elv_fs_entry > {
    enum {
        ID = 779
    };
};
 

template <>
struct type_id < struct x86_init_resources > {
    enum {
        ID = 780
    };
};
 

template <>
struct type_id < struct netns_core > {
    enum {
        ID = 781
    };
};
 

template <>
struct type_id < struct user_ymmh_regs > {
    enum {
        ID = 782
    };
};
 

template <>
struct type_id < struct compat_itimerval > {
    enum {
        ID = 783
    };
};
 

template <>
struct type_id < struct netpoll_info > {
    enum {
        ID = 784
    };
};
 

template <>
struct type_id < struct ahash_request > {
    enum {
        ID = 785
    };
};
 

template <>
struct type_id < struct ata_port_stats > {
    enum {
        ID = 786
    };
};
 

template <>
struct type_id < struct tpacket_stats_v3 > {
    enum {
        ID = 787
    };
};
 

template <>
struct type_id < struct fs_quota_stat > {
    enum {
        ID = 788
    };
};
 

template <>
struct type_id < struct pnp_card_device_id > {
    enum {
        ID = 789
    };
};
 

template <>
struct type_id < struct in6_flowlabel_req > {
    enum {
        ID = 790
    };
};
 

template <>
struct type_id < struct acpi_bus_type > {
    enum {
        ID = 791
    };
};
 

template <>
struct type_id < struct crypto_comp > {
    enum {
        ID = 792
    };
};
 

template <>
struct type_id < struct compat_dirent > {
    enum {
        ID = 793
    };
};
 

template <>
struct type_id < struct acpi_ivrs_memory > {
    enum {
        ID = 794
    };
};
 

template <>
struct type_id < struct ethtool_drvinfo > {
    enum {
        ID = 795
    };
};
 

template <>
struct type_id < struct compat_statfs > {
    enum {
        ID = 796
    };
};
 

template <>
struct type_id < struct dma_device > {
    enum {
        ID = 797
    };
};
 

template <>
struct type_id < struct hid_device_id > {
    enum {
        ID = 798
    };
};
 

template <>
struct type_id < struct latency_record > {
    enum {
        ID = 799
    };
};
 

template <>
struct type_id < struct res_counter > {
    enum {
        ID = 800
    };
};
 

template <>
struct type_id < struct rt_rq > {
    enum {
        ID = 801
    };
};
 

template <>
struct type_id < struct elf32_hdr > {
    enum {
        ID = 802
    };
};
 

template <>
struct type_id < struct proto_ops > {
    enum {
        ID = 803
    };
};
 

template <>
struct type_id < struct ipc_perm > {
    enum {
        ID = 804
    };
};
 

template <>
struct type_id < struct dsa_switch_tree > {
    enum {
        ID = 805
    };
};
 

template <>
struct type_id < struct cdrom_mcn > {
    enum {
        ID = 806
    };
};
 

template <>
struct type_id < struct trampoline_header > {
    enum {
        ID = 807
    };
};
 

template <>
struct type_id < struct ablkcipher_request > {
    enum {
        ID = 808
    };
};
 

template <>
struct type_id < struct ablkcipher_alg > {
    enum {
        ID = 809
    };
};
 

template <>
struct type_id < struct __key_reference_with_attributes > {
    enum {
        ID = 810
    };
};
 

template <>
struct type_id < struct vm_event_state > {
    enum {
        ID = 811
    };
};
 

template <>
struct type_id < struct dcb_app_type > {
    enum {
        ID = 812
    };
};
 

template <>
struct type_id < struct acpi_resource_dma > {
    enum {
        ID = 813
    };
};
 

template <>
struct type_id < struct linux_binfmt > {
    enum {
        ID = 814
    };
};
 

template <>
struct type_id < struct xfrm_user_expire > {
    enum {
        ID = 815
    };
};
 

template <>
struct type_id < struct qdisc_walker > {
    enum {
        ID = 816
    };
};
 

template <>
struct type_id < struct xfrm_policy_hash > {
    enum {
        ID = 817
    };
};
 

template <>
struct type_id < struct dmi_system_id > {
    enum {
        ID = 818
    };
};
 

template <>
struct type_id < struct xfrm_usersa_id > {
    enum {
        ID = 819
    };
};
 

template <>
struct type_id < struct tc_mqprio_qopt > {
    enum {
        ID = 820
    };
};
 

template <>
struct type_id < struct dma_interleaved_template > {
    enum {
        ID = 821
    };
};
 

template <>
struct type_id < struct ff_condition_effect > {
    enum {
        ID = 822
    };
};
 

template <>
struct type_id < struct dsa_platform_data > {
    enum {
        ID = 823
    };
};
 

template <>
struct type_id < struct load_weight > {
    enum {
        ID = 824
    };
};
 

template <>
struct type_id < struct compat_utimbuf > {
    enum {
        ID = 825
    };
};
 

template <>
struct type_id < struct pm_qos_flags_request > {
    enum {
        ID = 826
    };
};
 

template <>
struct type_id < struct xfrm_selector > {
    enum {
        ID = 827
    };
};
 

template <>
struct type_id < struct tc_cbq_ovl > {
    enum {
        ID = 828
    };
};
 

template <>
struct type_id < struct xfrm_user_mapping > {
    enum {
        ID = 829
    };
};
 

template <>
struct type_id < struct netns_mib > {
    enum {
        ID = 830
    };
};
 

template <>
struct type_id < struct serio_device_id > {
    enum {
        ID = 831
    };
};
 

template <>
struct type_id < struct rusage > {
    enum {
        ID = 832
    };
};
 

template <>
struct type_id < struct rlimit > {
    enum {
        ID = 833
    };
};
 

template <>
struct type_id < struct compat_stat > {
    enum {
        ID = 834
    };
};
 

template <>
struct type_id < struct hlist_nulls_node > {
    enum {
        ID = 835
    };
};
 

template <>
struct type_id < struct llist_head > {
    enum {
        ID = 836
    };
};
 

template <>
struct type_id < struct ata_acpi_gtm > {
    enum {
        ID = 837
    };
};
 

template <>
struct type_id < struct iocb > {
    enum {
        ID = 838
    };
};
 

template <>
struct type_id < struct rtnl_link_ifmap > {
    enum {
        ID = 839
    };
};
 

template <>
struct type_id < struct seminfo > {
    enum {
        ID = 840
    };
};
 

template <>
struct type_id < struct apic > {
    enum {
        ID = 841
    };
};
 

template <>
struct type_id < struct crypto_blkcipher > {
    enum {
        ID = 842
    };
};
 

template <>
struct type_id < struct acpi_table_tcpa > {
    enum {
        ID = 843
    };
};
 

template <>
struct type_id < struct msg_msg > {
    enum {
        ID = 844
    };
};
 

template <>
struct type_id < struct compat_ipc64_perm > {
    enum {
        ID = 845
    };
};
 

template <>
struct type_id < struct rps_dev_flow > {
    enum {
        ID = 846
    };
};
 

template <>
struct type_id < struct file > {
    enum {
        ID = 847
    };
};
 

template <>
struct type_id < struct jbd2_journal_revoke_tail > {
    enum {
        ID = 848
    };
};
 

template <>
struct type_id < struct flock > {
    enum {
        ID = 849
    };
};
 

template <>
struct type_id < struct acpi_fpdt_s3pt_ptr > {
    enum {
        ID = 850
    };
};
 

template <>
struct type_id < struct ethtool_cmd > {
    enum {
        ID = 851
    };
};
 

template <>
struct type_id < struct ahash_alg > {
    enum {
        ID = 852
    };
};
 

template <>
struct type_id < struct request_sock_queue > {
    enum {
        ID = 853
    };
};
 

template <>
struct type_id < struct acpi_driver > {
    enum {
        ID = 854
    };
};
 

template <>
struct type_id < struct acpi_device_pnp > {
    enum {
        ID = 855
    };
};
 

template <>
struct type_id < struct disk_stats > {
    enum {
        ID = 856
    };
};
 

template <>
struct type_id < struct proc_inode > {
    enum {
        ID = 857
    };
};
 

template <>
struct type_id < struct rta_cacheinfo > {
    enum {
        ID = 858
    };
};
 

template <>
struct type_id < struct __wait_queue_head > {
    enum {
        ID = 859
    };
};
 

template <>
struct type_id < struct mii_bus > {
    enum {
        ID = 860
    };
};
 

template <>
struct type_id < struct dvd_layer > {
    enum {
        ID = 861
    };
};
 

template <>
struct type_id < struct ptr_heap > {
    enum {
        ID = 862
    };
};
 

template <>
struct type_id < struct acpi_wdat_entry > {
    enum {
        ID = 863
    };
};
 

template <>
struct type_id < struct irq_chip_regs > {
    enum {
        ID = 864
    };
};
 

template <>
struct type_id < struct tcp_info > {
    enum {
        ID = 865
    };
};
 

template <>
struct type_id < struct acpi_object_list > {
    enum {
        ID = 866
    };
};
 

template <>
struct type_id < struct dma_async_tx_descriptor > {
    enum {
        ID = 867
    };
};
 

template <>
struct type_id < struct ata_queued_cmd > {
    enum {
        ID = 868
    };
};
 

template <>
struct type_id < struct gnet_stats_basic > {
    enum {
        ID = 869
    };
};
 

template <>
struct type_id < struct pci_fixup > {
    enum {
        ID = 870
    };
};
 

template <>
struct type_id < struct tm > {
    enum {
        ID = 871
    };
};
 

template <>
struct type_id < struct jbd2_buffer_trigger_type > {
    enum {
        ID = 872
    };
};
 

template <>
struct type_id < struct cee_pfc > {
    enum {
        ID = 873
    };
};
 

template <>
struct type_id < struct iret_context > {
    enum {
        ID = 874
    };
};
 

template <>
struct type_id < struct acpi_hest_generic_status > {
    enum {
        ID = 875
    };
};
 

template <>
struct type_id < struct tcp_congestion_ops > {
    enum {
        ID = 876
    };
};
 

template <>
struct type_id < struct tcf_proto > {
    enum {
        ID = 877
    };
};
 

template <>
struct type_id < struct skb_shared_info > {
    enum {
        ID = 878
    };
};
 

template <>
struct type_id < struct nf_conn > {
    enum {
        ID = 879
    };
};
 

template <>
struct type_id < struct workqueue_struct > {
    enum {
        ID = 880
    };
};
 

template <>
struct type_id < struct jbd2_journal_revoke_header_s > {
    enum {
        ID = 881
    };
};
 

template <>
struct type_id < struct acpi_memory_list > {
    enum {
        ID = 882
    };
};
 

template <>
struct type_id < struct edid_info > {
    enum {
        ID = 883
    };
};
 

template <>
struct type_id < struct netlink_notify > {
    enum {
        ID = 884
    };
};
 

template <>
struct type_id < struct inet_timewait_sock > {
    enum {
        ID = 885
    };
};
 

template <>
struct type_id < struct xps_dev_maps > {
    enum {
        ID = 886
    };
};
 

template <>
struct type_id < struct shash_alg > {
    enum {
        ID = 887
    };
};
 

template <>
struct type_id < struct ifla_cacheinfo > {
    enum {
        ID = 888
    };
};
 

template <>
struct type_id < struct epoll_event > {
    enum {
        ID = 889
    };
};
 

template <>
struct type_id < struct hrtimer_sleeper > {
    enum {
        ID = 890
    };
};
 

template <>
struct type_id < struct acpi_dock_ops > {
    enum {
        ID = 891
    };
};
 

template <>
struct type_id < struct gate_struct64 > {
    enum {
        ID = 892
    };
};
 

template <>
struct type_id < struct crypto_ablkcipher > {
    enum {
        ID = 893
    };
};
 

template <>
struct type_id < struct pci_ats > {
    enum {
        ID = 894
    };
};
 

template <>
struct type_id < struct acpi_table_pmtt > {
    enum {
        ID = 895
    };
};
 

template <>
struct type_id < struct tcp6_timewait_sock > {
    enum {
        ID = 896
    };
};
 

template <>
struct type_id < struct netns_unix > {
    enum {
        ID = 897
    };
};
 

template <>
struct type_id < struct sk_buff > {
    enum {
        ID = 898
    };
};
 

template <>
struct type_id < struct ethtool_test > {
    enum {
        ID = 899
    };
};
 

template <>
struct type_id < struct kernel_param_ops > {
    enum {
        ID = 900
    };
};
 

template <>
struct type_id < struct zone > {
    enum {
        ID = 901
    };
};
 

template <>
struct type_id < struct ethtool_value > {
    enum {
        ID = 902
    };
};
 

template <>
struct type_id < struct acpi_table_cpep > {
    enum {
        ID = 903
    };
};
 

template <>
struct type_id < struct _ddebug > {
    enum {
        ID = 904
    };
};
 

template <>
struct type_id < struct acpi_resource_irq > {
    enum {
        ID = 905
    };
};
 

template <>
struct type_id < struct radix_tree_iter > {
    enum {
        ID = 906
    };
};
 

template <>
struct type_id < struct ifconf > {
    enum {
        ID = 907
    };
};
 

template <>
struct type_id < struct sem_queue > {
    enum {
        ID = 908
    };
};
 

template <>
struct type_id < struct inet_cork > {
    enum {
        ID = 909
    };
};
 

template <>
struct type_id < struct spi_device_id > {
    enum {
        ID = 910
    };
};
 

template <>
struct type_id < struct crypto_shash > {
    enum {
        ID = 911
    };
};
 

template <>
struct type_id < struct dvd_lu_send_challenge > {
    enum {
        ID = 912
    };
};
 

template <>
struct type_id < struct acpi_srat_mem_affinity > {
    enum {
        ID = 913
    };
};
 

template <>
struct type_id < struct kstat > {
    enum {
        ID = 914
    };
};
 

template <>
struct type_id < struct rtgenmsg > {
    enum {
        ID = 915
    };
};
 

template <>
struct type_id < struct nfs4_lock_state > {
    enum {
        ID = 916
    };
};
 

template <>
struct type_id < struct inet_request_sock > {
    enum {
        ID = 917
    };
};
 

template <>
struct type_id < struct ethtool_coalesce > {
    enum {
        ID = 918
    };
};
 

template <>
struct type_id < struct start_info > {
    enum {
        ID = 919
    };
};
 

template <>
struct type_id < struct ethtool_rx_ntuple > {
    enum {
        ID = 920
    };
};
 

template <>
struct type_id < struct klist_iter > {
    enum {
        ID = 921
    };
};
 

template <>
struct type_id < struct pacct_struct > {
    enum {
        ID = 922
    };
};
 

template <>
struct type_id < struct vlan_ethhdr > {
    enum {
        ID = 923
    };
};
 

template <>
struct type_id < struct cdrom_tocentry > {
    enum {
        ID = 924
    };
};
 

template <>
struct type_id < struct blk_queue_tag > {
    enum {
        ID = 925
    };
};
 

template <>
struct type_id < struct pcpu_lstats > {
    enum {
        ID = 926
    };
};
 

template <>
struct type_id < struct acpi_memory_attribute > {
    enum {
        ID = 927
    };
};
 

template <>
struct type_id < struct compat_mq_attr > {
    enum {
        ID = 928
    };
};
 

template <>
struct type_id < struct aead_request > {
    enum {
        ID = 929
    };
};
 

template <>
struct type_id < struct ftrace_ret_stack > {
    enum {
        ID = 930
    };
};
 

template <>
struct type_id < struct arch_uprobe_task > {
    enum {
        ID = 931
    };
};
 

template <>
struct type_id < struct xfrm_lifetime_cur > {
    enum {
        ID = 932
    };
};
 

template <>
struct type_id < struct sysfs_dirent > {
    enum {
        ID = 933
    };
};
 

template <>
struct type_id < struct acpi_pmtt_physical_component > {
    enum {
        ID = 934
    };
};
 

template <>
struct type_id < struct acpi_resource_fixed_io > {
    enum {
        ID = 935
    };
};
 

template <>
struct type_id < struct dcbnl_rtnl_ops > {
    enum {
        ID = 936
    };
};
 

template <>
struct type_id < struct xfrmu_sadhinfo > {
    enum {
        ID = 937
    };
};
 

template <>
struct type_id < struct inet_timewait_death_row > {
    enum {
        ID = 938
    };
};
 

template <>
struct type_id < struct task_group > {
    enum {
        ID = 939
    };
};
 

template <>
struct type_id < struct tpacket2_hdr > {
    enum {
        ID = 940
    };
};
 

template <>
struct type_id < struct blk_integrity_exchg > {
    enum {
        ID = 941
    };
};
 

template <>
struct type_id < struct rcu_batch > {
    enum {
        ID = 942
    };
};
 

template <>
struct type_id < struct acpi_mpst_channel > {
    enum {
        ID = 943
    };
};
 

template <>
struct type_id < struct input_device_id > {
    enum {
        ID = 944
    };
};
 

template <>
struct type_id < struct acpi_cpep_polling > {
    enum {
        ID = 945
    };
};
 

template <>
struct type_id < struct wait_bit_queue > {
    enum {
        ID = 946
    };
};
 

template <>
struct type_id < struct msr_regs_info > {
    enum {
        ID = 947
    };
};
 

template <>
struct type_id < struct icmpv6_mib_device > {
    enum {
        ID = 948
    };
};
 

template <>
struct type_id < struct mpc_lintsrc > {
    enum {
        ID = 949
    };
};
 

template <>
struct type_id < struct acpi_madt_interrupt_override > {
    enum {
        ID = 950
    };
};
 

template <>
struct type_id < struct tc_choke_xstats > {
    enum {
        ID = 951
    };
};
 

template <>
struct type_id < struct acpi_asf_alert_data > {
    enum {
        ID = 952
    };
};
 

template <>
struct type_id < struct mr_table > {
    enum {
        ID = 953
    };
};
 

template <>
struct type_id < struct acpi_asf_rmcp > {
    enum {
        ID = 954
    };
};
 

template <>
struct type_id < struct skb_seq_state > {
    enum {
        ID = 955
    };
};
 

template <>
struct type_id < struct tc_htb_glob > {
    enum {
        ID = 956
    };
};
 

template <>
struct type_id < struct acpi_pci_driver > {
    enum {
        ID = 957
    };
};
 

template <>
struct type_id < struct dentry > {
    enum {
        ID = 958
    };
};
 

template <>
struct type_id < struct mmu_gather > {
    enum {
        ID = 959
    };
};
 

template <>
struct type_id < struct tcmsg > {
    enum {
        ID = 960
    };
};
 

template <>
struct type_id < struct acpi_dmar_atsr > {
    enum {
        ID = 961
    };
};
 

template <>
struct type_id < struct clock_event_device > {
    enum {
        ID = 962
    };
};
 

template <>
struct type_id < struct mii_if_info > {
    enum {
        ID = 963
    };
};
 

template <>
struct type_id < struct vmcore > {
    enum {
        ID = 964
    };
};
 

template <>
struct type_id < struct msr_info > {
    enum {
        ID = 965
    };
};
 

template <>
struct type_id < struct ifla_vlan_qos_mapping > {
    enum {
        ID = 966
    };
};
 

template <>
struct type_id < struct mpc_cpu > {
    enum {
        ID = 967
    };
};
 

template <>
struct type_id < struct bio_vec > {
    enum {
        ID = 968
    };
};
 

template <>
struct type_id < struct sem_undo > {
    enum {
        ID = 969
    };
};
 

template <>
struct type_id < struct shash_desc > {
    enum {
        ID = 970
    };
};
 

template <>
struct type_id < struct acpi_bus_event > {
    enum {
        ID = 971
    };
};
 

template <>
struct type_id < struct static_key_deferred > {
    enum {
        ID = 972
    };
};
 

template <>
struct type_id < struct subsys_dev_iter > {
    enum {
        ID = 973
    };
};
 

template <>
struct type_id < struct zonelist_cache > {
    enum {
        ID = 974
    };
};
 

template <>
struct type_id < struct dsa_switch_driver > {
    enum {
        ID = 975
    };
};
 

template <>
struct type_id < struct ebt_table > {
    enum {
        ID = 976
    };
};
 

template <>
struct type_id < struct tcp_md5sig_key > {
    enum {
        ID = 977
    };
};
 

template <>
struct type_id < struct irq_desc > {
    enum {
        ID = 978
    };
};
 

template <>
struct type_id < struct hlist_nulls_head > {
    enum {
        ID = 979
    };
};
 

template <>
struct type_id < struct netns_packet > {
    enum {
        ID = 980
    };
};
 

template <>
struct type_id < struct tcp6_sock > {
    enum {
        ID = 981
    };
};
 

template <>
struct type_id < struct netlink_kernel_cfg > {
    enum {
        ID = 982
    };
};
 

template <>
struct type_id < struct raw_hashinfo > {
    enum {
        ID = 983
    };
};
 

template <>
struct type_id < struct plist_node > {
    enum {
        ID = 984
    };
};
 

template <>
struct type_id < struct srcu_struct > {
    enum {
        ID = 985
    };
};
 

template <>
struct type_id < struct rps_map > {
    enum {
        ID = 986
    };
};
 

template <>
struct type_id < struct acpi_madt_io_apic > {
    enum {
        ID = 987
    };
};
 

template <>
struct type_id < struct module_version_attribute > {
    enum {
        ID = 988
    };
};
 

template <>
struct type_id < struct scsi_transport_template > {
    enum {
        ID = 989
    };
};
 

template <>
struct type_id < struct prop_descriptor > {
    enum {
        ID = 990
    };
};
 

template <>
struct type_id < struct device_type > {
    enum {
        ID = 991
    };
};
 

template <>
struct type_id < struct acpi_eject_event > {
    enum {
        ID = 992
    };
};
 

template <>
struct type_id < struct hrtimer_clock_base > {
    enum {
        ID = 993
    };
};
 

template <>
struct type_id < struct tc_htb_opt > {
    enum {
        ID = 994
    };
};
 

template <>
struct type_id < struct percpu_rw_semaphore > {
    enum {
        ID = 995
    };
};
 

template <>
struct type_id < struct tasklet_struct > {
    enum {
        ID = 996
    };
};
 

template <>
struct type_id < struct acpi_table_msct > {
    enum {
        ID = 997
    };
};
 

template <>
struct type_id < struct blk_trace > {
    enum {
        ID = 998
    };
};
 

template <>
struct type_id < struct iw_public_data > {
    enum {
        ID = 999
    };
};
 

template <>
struct type_id < struct pcmcia_device_id > {
    enum {
        ID = 1000
    };
};
 

template <>
struct type_id < struct acpi_mpst_data_hdr > {
    enum {
        ID = 1001
    };
};
 

template <>
struct type_id < struct prop_global > {
    enum {
        ID = 1002
    };
};
 

template <>
struct type_id < struct acpi_table_asf > {
    enum {
        ID = 1003
    };
};
 

template <>
struct type_id < struct acpi_mpst_power_data > {
    enum {
        ID = 1004
    };
};
 

template <>
struct type_id < struct acpi_table_csrt > {
    enum {
        ID = 1005
    };
};
 

template <>
struct type_id < struct dvd_lu_send_title_key > {
    enum {
        ID = 1006
    };
};
 

template <>
struct type_id < struct usb_device_id > {
    enum {
        ID = 1007
    };
};
 

template <>
struct type_id < struct sockaddr_pkt > {
    enum {
        ID = 1008
    };
};
 

template <>
struct type_id < struct super_block > {
    enum {
        ID = 1009
    };
};
 

template <>
struct type_id < struct inet6_dev > {
    enum {
        ID = 1010
    };
};
 

template <>
struct type_id < struct sockaddr_in6 > {
    enum {
        ID = 1011
    };
};
 

template <>
struct type_id < struct rta_session > {
    enum {
        ID = 1012
    };
};
 

template <>
struct type_id < struct dvd_bca > {
    enum {
        ID = 1013
    };
};
 

template <>
struct type_id < struct acpi_table_slit > {
    enum {
        ID = 1014
    };
};
 

template <>
struct type_id < struct transaction_s > {
    enum {
        ID = 1015
    };
};
 

template <>
struct type_id < struct sem_array > {
    enum {
        ID = 1016
    };
};
 

template <>
struct type_id < struct ata_ering > {
    enum {
        ID = 1017
    };
};
 

template <>
struct type_id < struct pci_slot > {
    enum {
        ID = 1018
    };
};
 

template <>
struct type_id < struct acpi_table_slic > {
    enum {
        ID = 1019
    };
};
 

template <>
struct type_id < struct acpi_madt_interrupt_source > {
    enum {
        ID = 1020
    };
};
 

template <>
struct type_id < struct cdrom_ti > {
    enum {
        ID = 1021
    };
};
 

template <>
struct type_id < struct softnet_data > {
    enum {
        ID = 1022
    };
};
 

template <>
struct type_id < struct inodes_stat_t > {
    enum {
        ID = 1023
    };
};
 

template <>
struct type_id < struct transaction_chp_stats_s > {
    enum {
        ID = 1024
    };
};
 

template <>
struct type_id < struct acpi_device_power_flags > {
    enum {
        ID = 1025
    };
};
 

template <>
struct type_id < struct rtnl_af_ops > {
    enum {
        ID = 1026
    };
};
 

template <>
struct type_id < struct semid64_ds > {
    enum {
        ID = 1027
    };
};
 

template <>
struct type_id < struct ethtool_ops > {
    enum {
        ID = 1028
    };
};
 

template <>
struct type_id < struct dquot_operations > {
    enum {
        ID = 1029
    };
};
 

template <>
struct type_id < struct pv_time_ops > {
    enum {
        ID = 1030
    };
};
 

template <>
struct type_id < struct group_req > {
    enum {
        ID = 1031
    };
};
 

template <>
struct type_id < struct user_i387_struct > {
    enum {
        ID = 1032
    };
};
 

template <>
struct type_id < struct iommu_group > {
    enum {
        ID = 1033
    };
};
 

template <>
struct type_id < struct device_dma_parameters > {
    enum {
        ID = 1034
    };
};
 

template <>
struct type_id < struct Scsi_Host > {
    enum {
        ID = 1035
    };
};
 

template <>
struct type_id < struct dvd_physical > {
    enum {
        ID = 1036
    };
};
 

template <>
struct type_id < struct acpi_mpst_component > {
    enum {
        ID = 1037
    };
};
 

template <>
struct type_id < struct sigqueue > {
    enum {
        ID = 1038
    };
};
 

template <>
struct type_id < struct inode_operations > {
    enum {
        ID = 1039
    };
};
 

template <>
struct type_id < struct irq_2_iommu > {
    enum {
        ID = 1040
    };
};
 

template <>
struct type_id < struct fprop_global > {
    enum {
        ID = 1041
    };
};
 

template <>
struct type_id < struct acpi_table_boot > {
    enum {
        ID = 1042
    };
};
 

template <>
struct type_id < struct itimerspec > {
    enum {
        ID = 1043
    };
};
 

template <>
struct type_id < struct bio_set > {
    enum {
        ID = 1044
    };
};
 

template <>
struct type_id < struct kthread_worker > {
    enum {
        ID = 1045
    };
};
 

template <>
struct type_id < struct kref > {
    enum {
        ID = 1046
    };
};
 

template <>
struct type_id < struct _fpx_sw_bytes > {
    enum {
        ID = 1047
    };
};
 

template <>
struct type_id < struct net_device > {
    enum {
        ID = 1048
    };
};
 

template <>
struct type_id < struct dvd_send_key > {
    enum {
        ID = 1049
    };
};
 

template <>
struct type_id < struct timeval > {
    enum {
        ID = 1050
    };
};
 

template <>
struct type_id < struct __user_cap_data_struct > {
    enum {
        ID = 1051
    };
};
 

template <>
struct type_id < struct multicall_entry > {
    enum {
        ID = 1052
    };
};
 

template <>
struct type_id < struct cdrom_mechstat_header > {
    enum {
        ID = 1053
    };
};
 

template <>
struct type_id < struct dn_dev > {
    enum {
        ID = 1054
    };
};
 

template <>
struct type_id < struct blocking_notifier_head > {
    enum {
        ID = 1055
    };
};
 

template <>
struct type_id < struct acpi_resource_vendor_typed > {
    enum {
        ID = 1056
    };
};
 

template <>
struct type_id < struct pci_driver > {
    enum {
        ID = 1057
    };
};
 

template <>
struct type_id < struct xfrm_lifetime_cfg > {
    enum {
        ID = 1058
    };
};
 

template <>
struct type_id < struct rb_root > {
    enum {
        ID = 1059
    };
};
 

template <>
struct type_id < struct unixware_vtoc > {
    enum {
        ID = 1060
    };
};
 

template <>
struct type_id < struct text_poke_param > {
    enum {
        ID = 1061
    };
};
 

template <>
struct type_id < struct key_owner > {
    enum {
        ID = 1062
    };
};
 

template <>
struct type_id < struct acpi_table_pcct > {
    enum {
        ID = 1063
    };
};
 

template <>
struct type_id < struct file_operations > {
    enum {
        ID = 1064
    };
};
 

template <>
struct type_id < struct acpi_signal_fatal_info > {
    enum {
        ID = 1065
    };
};
 

template <>
struct type_id < struct acpi_ivrs_device8c > {
    enum {
        ID = 1066
    };
};
 

template <>
struct type_id < struct pci_sysdata > {
    enum {
        ID = 1067
    };
};
 

template <>
struct type_id < struct acpi_ivrs_device8a > {
    enum {
        ID = 1068
    };
};
 

template <>
struct type_id < struct wakeup_source > {
    enum {
        ID = 1069
    };
};
 

template <>
struct type_id < struct arch_uprobe > {
    enum {
        ID = 1070
    };
};
 

template <>
struct type_id < struct x86_init_mpparse > {
    enum {
        ID = 1071
    };
};
 

template <>
struct type_id < struct vm_unmapped_area_info > {
    enum {
        ID = 1072
    };
};
 

template <>
struct type_id < struct user_xstateregs > {
    enum {
        ID = 1073
    };
};
 

template <>
struct type_id < struct completion > {
    enum {
        ID = 1074
    };
};
 

template <>
struct type_id < struct ifla_vf_spoofchk > {
    enum {
        ID = 1075
    };
};
 

template <>
struct type_id < struct tc_qfq_stats > {
    enum {
        ID = 1076
    };
};
 

template <>
struct type_id < struct xfrm_user_polexpire > {
    enum {
        ID = 1077
    };
};
 

template <>
struct type_id < struct qdisc_rate_table > {
    enum {
        ID = 1078
    };
};
 

template <>
struct type_id < struct acpi_dmar_rhsa > {
    enum {
        ID = 1079
    };
};
 

template <>
struct type_id < struct ethtool_get_features_block > {
    enum {
        ID = 1080
    };
};
 

template <>
struct type_id < struct u64_stats_sync > {
    enum {
        ID = 1081
    };
};
 

template <>
struct type_id < struct tcp_cookie_transactions > {
    enum {
        ID = 1082
    };
};
 

template <>
struct type_id < struct obs_kernel_param > {
    enum {
        ID = 1083
    };
};
 

template <>
struct type_id < struct irq_chip_type > {
    enum {
        ID = 1084
    };
};
 

template <>
struct type_id < struct idr_layer > {
    enum {
        ID = 1085
    };
};
 

template <>
struct type_id < struct acpi_resource_io > {
    enum {
        ID = 1086
    };
};
 

template <>
struct type_id < struct irqaction > {
    enum {
        ID = 1087
    };
};
 

template <>
struct type_id < struct subsys_private > {
    enum {
        ID = 1088
    };
};
 

template <>
struct type_id < struct timerqueue_head > {
    enum {
        ID = 1089
    };
};
 

template <>
struct type_id < struct xfrm_aevent_id > {
    enum {
        ID = 1090
    };
};
 

template <>
struct type_id < struct pm_domain_data > {
    enum {
        ID = 1091
    };
};
 

template <>
struct type_id < struct seqcount > {
    enum {
        ID = 1092
    };
};
 

template <>
struct type_id < struct pid_link > {
    enum {
        ID = 1093
    };
};
 

template <>
struct type_id < struct input_handler > {
    enum {
        ID = 1094
    };
};
 

template <>
struct type_id < struct neigh_ops > {
    enum {
        ID = 1095
    };
};
 

template <>
struct type_id < struct semid_ds > {
    enum {
        ID = 1096
    };
};
 

template <>
struct type_id < struct acpi_hest_ia_corrected > {
    enum {
        ID = 1097
    };
};
 

template <>
struct type_id < struct rtnl_link_stats > {
    enum {
        ID = 1098
    };
};
 

template <>
struct type_id < struct tpacket_hdr_variant1 > {
    enum {
        ID = 1099
    };
};
 

template <>
struct type_id < struct net_device_ops > {
    enum {
        ID = 1100
    };
};
 

template <>
struct type_id < struct edd_device_params > {
    enum {
        ID = 1101
    };
};
 

template <>
struct type_id < struct scsi_ioctl_command > {
    enum {
        ID = 1102
    };
};
 

template <>
struct type_id < struct kiocb > {
    enum {
        ID = 1103
    };
};
 

template <>
struct type_id < struct ethtool_rx_ntuple_flow_spec > {
    enum {
        ID = 1104
    };
};
 

template <>
struct type_id < struct vm_struct > {
    enum {
        ID = 1105
    };
};
 

template <>
struct type_id < struct sem > {
    enum {
        ID = 1106
    };
};
 

template <>
struct type_id < struct miscdevice > {
    enum {
        ID = 1107
    };
};
 

template <>
struct type_id < struct irq_pin_list > {
    enum {
        ID = 1108
    };
};
 

template <>
struct type_id < struct pv_irq_ops > {
    enum {
        ID = 1109
    };
};
 

template <>
struct type_id < struct ip_options_rcu > {
    enum {
        ID = 1110
    };
};
 

template <>
struct type_id < struct map_segment > {
    enum {
        ID = 1111
    };
};
 

template <>
struct type_id < struct irq_affinity_notify > {
    enum {
        ID = 1112
    };
};
 

template <>
struct type_id < struct mutex > {
    enum {
        ID = 1113
    };
};
 

template <>
struct type_id < struct sigaltstack > {
    enum {
        ID = 1114
    };
};
 

template <>
struct type_id < struct ata_link > {
    enum {
        ID = 1115
    };
};
 

template <>
struct type_id < struct ethtool_dump > {
    enum {
        ID = 1116
    };
};
 

template <>
struct type_id < struct ethtool_eee > {
    enum {
        ID = 1117
    };
};
 

template <>
struct type_id < struct tcp_fastopen_cookie > {
    enum {
        ID = 1118
    };
};
 

template <>
struct type_id < struct iw_handler_def > {
    enum {
        ID = 1119
    };
};
 

template <>
struct type_id < struct acpi_resource_vendor > {
    enum {
        ID = 1120
    };
};
 

template <>
struct type_id < struct cdrom_device_info > {
    enum {
        ID = 1121
    };
};
 

template <>
struct type_id < struct hash_tfm > {
    enum {
        ID = 1122
    };
};
 

template <>
struct type_id < struct task_struct > {
    enum {
        ID = 1123
    };
};
 

template <>
struct type_id < struct cleancache_ops > {
    enum {
        ID = 1124
    };
};
 

template <>
struct type_id < struct vcpu_guest_context > {
    enum {
        ID = 1125
    };
};
 

template <>
struct type_id < struct ap_device_id > {
    enum {
        ID = 1126
    };
};
 

template <>
struct type_id < struct lock_manager_operations > {
    enum {
        ID = 1127
    };
};
 

template <>
struct type_id < struct snmp_mib > {
    enum {
        ID = 1128
    };
};
 

template <>
struct type_id < struct thread_info > {
    enum {
        ID = 1129
    };
};
 

template <>
struct type_id < struct module_attribute > {
    enum {
        ID = 1130
    };
};
 

template <>
struct type_id < struct ctl_table_poll > {
    enum {
        ID = 1131
    };
};
 

template <>
struct type_id < struct tcf_t > {
    enum {
        ID = 1132
    };
};
 

template <>
struct type_id < struct poll_table_entry > {
    enum {
        ID = 1133
    };
};
 

template <>
struct type_id < struct linux_mib > {
    enum {
        ID = 1134
    };
};
 

template <>
struct type_id < struct ctl_table > {
    enum {
        ID = 1135
    };
};
 

template <>
struct type_id < struct ipv6_ac_socklist > {
    enum {
        ID = 1136
    };
};
 

template <>
struct type_id < struct vm86plus_info_struct > {
    enum {
        ID = 1137
    };
};
 

template <>
struct type_id < struct ip_beet_phdr > {
    enum {
        ID = 1138
    };
};
 

template <>
struct type_id < struct mem_cgroup_reclaim_cookie > {
    enum {
        ID = 1139
    };
};
 

template <>
struct type_id < struct perf_event > {
    enum {
        ID = 1140
    };
};
 

template <>
struct type_id < struct pm_message > {
    enum {
        ID = 1141
    };
};
 

template <>
struct type_id < struct seq_net_private > {
    enum {
        ID = 1142
    };
};
 

template <>
struct type_id < struct acpi_table_ecdt > {
    enum {
        ID = 1143
    };
};
 

template <>
struct type_id < struct physid_mask > {
    enum {
        ID = 1144
    };
};
 

template <>
struct type_id < struct nameidata > {
    enum {
        ID = 1145
    };
};
 

template <>
struct type_id < struct preempt_ops > {
    enum {
        ID = 1146
    };
};
 

template <>
struct type_id < struct tc_netem_corrupt > {
    enum {
        ID = 1147
    };
};
 

template <>
struct type_id < struct sg_io_v4 > {
    enum {
        ID = 1148
    };
};
 

template <>
struct type_id < struct disk_events > {
    enum {
        ID = 1149
    };
};
 

template <>
struct type_id < struct pci_dev > {
    enum {
        ID = 1150
    };
};
 

template <>
struct type_id < struct jbd2_journal_handle > {
    enum {
        ID = 1151
    };
};
 

template <>
struct type_id < struct virtio_device_id > {
    enum {
        ID = 1152
    };
};
 

template <>
struct type_id < struct acpi_device_physical_node > {
    enum {
        ID = 1153
    };
};
 

template <>
struct type_id < struct debug_obj_descr > {
    enum {
        ID = 1154
    };
};
 

template <>
struct type_id < struct seccomp_filter > {
    enum {
        ID = 1155
    };
};
 

template <>
struct type_id < struct uprobes_state > {
    enum {
        ID = 1156
    };
};
 

template <>
struct type_id < struct va_format > {
    enum {
        ID = 1157
    };
};
 

template <>
struct type_id < struct udp_sock > {
    enum {
        ID = 1158
    };
};
 

template <>
struct type_id < struct nl_info > {
    enum {
        ID = 1159
    };
};
 

template <>
struct type_id < struct ata_port_info > {
    enum {
        ID = 1160
    };
};
 

template <>
struct type_id < struct pm_qos_constraints > {
    enum {
        ID = 1161
    };
};
 

template <>
struct type_id < struct acpi_mpst_shared > {
    enum {
        ID = 1162
    };
};
 

template <>
struct type_id < struct acpi_pci_routing_table > {
    enum {
        ID = 1163
    };
};
 

template <>
struct type_id < struct cyclecounter > {
    enum {
        ID = 1164
    };
};
 

template <>
struct type_id < struct irq_routing_table > {
    enum {
        ID = 1165
    };
};
 

template <>
struct type_id < struct flowi > {
    enum {
        ID = 1166
    };
};
 

template <>
struct type_id < struct user > {
    enum {
        ID = 1167
    };
};
 

template <>
struct type_id < struct module_use > {
    enum {
        ID = 1168
    };
};
 

template <>
struct type_id < struct block_device_operations > {
    enum {
        ID = 1169
    };
};
 

template <>
struct type_id < struct crypto_tfm > {
    enum {
        ID = 1170
    };
};
 

template <>
struct type_id < struct blk_plug > {
    enum {
        ID = 1171
    };
};
 

template <>
struct type_id < struct solaris_x86_vtoc > {
    enum {
        ID = 1172
    };
};
 

template <>
struct type_id < struct memory_block > {
    enum {
        ID = 1173
    };
};
 

template <>
struct type_id < struct wait_bit_key > {
    enum {
        ID = 1174
    };
};
 

template <>
struct type_id < struct pvclock_vsyscall_time_info > {
    enum {
        ID = 1175
    };
};
 

template <>
struct type_id < struct acpi_table_srat > {
    enum {
        ID = 1176
    };
};
 

template <>
struct type_id < struct firmware > {
    enum {
        ID = 1177
    };
};
 

template <>
struct type_id < struct blk_plug_cb > {
    enum {
        ID = 1178
    };
};
 

template <>
struct type_id < struct acpi_table_spmi > {
    enum {
        ID = 1179
    };
};
 

template <>
struct type_id < struct tc_netem_gemodel > {
    enum {
        ID = 1180
    };
};
 

template <>
struct type_id < struct event_header > {
    enum {
        ID = 1181
    };
};
 

template <>
struct type_id < struct mmsghdr > {
    enum {
        ID = 1182
    };
};
 

template <>
struct type_id < struct jbd2_revoke_table_s > {
    enum {
        ID = 1183
    };
};
 

template <>
struct type_id < struct acpi_table_bert > {
    enum {
        ID = 1184
    };
};
 

template <>
struct type_id < struct compat_sysctl_args > {
    enum {
        ID = 1185
    };
};
 

template <>
struct type_id < struct bio > {
    enum {
        ID = 1186
    };
};
 

template <>
struct type_id < struct tcp_sack_block > {
    enum {
        ID = 1187
    };
};
 

template <>
struct type_id < struct ratelimit_state > {
    enum {
        ID = 1188
    };
};
 

template <>
struct type_id < struct compat_robust_list > {
    enum {
        ID = 1189
    };
};
 

template <>
struct type_id < struct aperfmperf > {
    enum {
        ID = 1190
    };
};
 

template <>
struct type_id < struct user32_fxsr_struct > {
    enum {
        ID = 1191
    };
};
 

template <>
struct type_id < struct xfrm_user_kmaddress > {
    enum {
        ID = 1192
    };
};
 

template <>
struct type_id < struct debug_obj > {
    enum {
        ID = 1193
    };
};
 

template <>
struct type_id < struct netns_xt > {
    enum {
        ID = 1194
    };
};
 

template <>
struct type_id < struct dst_ops > {
    enum {
        ID = 1195
    };
};
 

template <>
struct type_id < struct ff_envelope > {
    enum {
        ID = 1196
    };
};
 

template <>
struct type_id < struct mempool_s > {
    enum {
        ID = 1197
    };
};
 

template <>
struct type_id < struct tc_netem_corr > {
    enum {
        ID = 1198
    };
};
 

template <>
struct type_id < struct input_absinfo > {
    enum {
        ID = 1199
    };
};
 

template <>
struct type_id < struct elf32_note > {
    enum {
        ID = 1200
    };
};
 

template <>
struct type_id < struct tc_drr_stats > {
    enum {
        ID = 1201
    };
};
 

template <>
struct type_id < struct x86_init_iommu > {
    enum {
        ID = 1202
    };
};
 

template <>
struct type_id < struct kobj_ns_type_operations > {
    enum {
        ID = 1203
    };
};
 

template <>
struct type_id < struct ifa_cacheinfo > {
    enum {
        ID = 1204
    };
};
 

template <>
struct type_id < struct tcf_result > {
    enum {
        ID = 1205
    };
};
 

template <>
struct type_id < struct acpi_hest_aer_common > {
    enum {
        ID = 1206
    };
};
 

template <>
struct type_id < struct nduseroptmsg > {
    enum {
        ID = 1207
    };
};
 

template <>
struct type_id < struct rlimit64 > {
    enum {
        ID = 1208
    };
};
 

template <>
struct type_id < struct audit_names > {
    enum {
        ID = 1209
    };
};
 

template <>
struct type_id < struct kparam_string > {
    enum {
        ID = 1210
    };
};
 

template <>
struct type_id < struct xfrm_user_migrate > {
    enum {
        ID = 1211
    };
};
 

template <>
struct type_id < struct io_apic_irq_attr > {
    enum {
        ID = 1212
    };
};
 

template <>
struct type_id < struct tracepoint_func > {
    enum {
        ID = 1213
    };
};
 

template <>
struct type_id < struct rnd_state > {
    enum {
        ID = 1214
    };
};
 

template <>
struct type_id < struct cgroup_scanner > {
    enum {
        ID = 1215
    };
};
 

template <>
struct type_id < struct timer_list > {
    enum {
        ID = 1216
    };
};
 

template <>
struct type_id < struct fib_rules_ops > {
    enum {
        ID = 1217
    };
};
 

template <>
struct type_id < struct acpi_table_s3pt > {
    enum {
        ID = 1218
    };
};
 

template <>
struct type_id < struct Qdisc_ops > {
    enum {
        ID = 1219
    };
};
 

template <>
struct type_id < struct input_id > {
    enum {
        ID = 1220
    };
};
 

template <>
struct type_id < struct zone_reclaim_stat > {
    enum {
        ID = 1221
    };
};
 

template <>
struct type_id < struct pcpu_alloc_info > {
    enum {
        ID = 1222
    };
};
 

template <>
struct type_id < struct compat_msqid64_ds > {
    enum {
        ID = 1223
    };
};
 

template <>
struct type_id < struct compat_sel_arg_struct > {
    enum {
        ID = 1224
    };
};
 

template <>
struct type_id < struct idr > {
    enum {
        ID = 1225
    };
};
 

template <>
struct type_id < struct ifla_vf_tx_rate > {
    enum {
        ID = 1226
    };
};
 

template <>
struct type_id < struct range > {
    enum {
        ID = 1227
    };
};
 

template <>
struct type_id < struct dma_chan > {
    enum {
        ID = 1228
    };
};
 

template <>
struct type_id < struct hlist_bl_head > {
    enum {
        ID = 1229
    };
};
 

template <>
struct type_id < struct mpc_ioapic > {
    enum {
        ID = 1230
    };
};
 

template <>
struct type_id < struct ida > {
    enum {
        ID = 1231
    };
};
 

template <>
struct type_id < struct throtl_data > {
    enum {
        ID = 1232
    };
};
 

template <>
struct type_id < struct ethtool_rx_flow_spec > {
    enum {
        ID = 1233
    };
};
 

template <>
struct type_id < struct klist_node > {
    enum {
        ID = 1234
    };
};
 

template <>
struct type_id < struct bsg_class_device > {
    enum {
        ID = 1235
    };
};
 

template <>
struct type_id < struct msr > {
    enum {
        ID = 1236
    };
};
 

template <>
struct type_id < struct vm86_regs > {
    enum {
        ID = 1237
    };
};
 

template <>
struct type_id < struct acpi_srat_cpu_affinity > {
    enum {
        ID = 1238
    };
};
 

template <>
struct type_id < struct acpi_resource_fixed_memory32 > {
    enum {
        ID = 1239
    };
};
 

template <>
struct type_id < struct nf_udp_net > {
    enum {
        ID = 1240
    };
};
 

template <>
struct type_id < struct acpi_table_gtdt > {
    enum {
        ID = 1241
    };
};
 

template <>
struct type_id < struct sock > {
    enum {
        ID = 1242
    };
};
 

template <>
struct type_id < struct acpi_erst_info > {
    enum {
        ID = 1243
    };
};
 

template <>
struct type_id < struct tc_cbq_lssopt > {
    enum {
        ID = 1244
    };
};
 

template <>
struct type_id < struct cpu_user_regs > {
    enum {
        ID = 1245
    };
};
 

template <>
struct type_id < struct mpc_intsrc > {
    enum {
        ID = 1246
    };
};
 

template <>
struct type_id < struct compat_ifconf > {
    enum {
        ID = 1247
    };
};
 

template <>
struct type_id < struct execute_work > {
    enum {
        ID = 1248
    };
};
 

template <>
struct type_id < struct compat_flock64 > {
    enum {
        ID = 1249
    };
};
 

template <>
struct type_id < struct i387_fsave_struct > {
    enum {
        ID = 1250
    };
};
 

template <>
struct type_id < struct dqstats > {
    enum {
        ID = 1251
    };
};
 

template <>
struct type_id < struct task_io_accounting > {
    enum {
        ID = 1252
    };
};
 

template <>
struct type_id < struct acpi_buffer > {
    enum {
        ID = 1253
    };
};
 

template <>
struct type_id < struct kthread_work > {
    enum {
        ID = 1254
    };
};
 

template <>
struct type_id < struct dma_page_list > {
    enum {
        ID = 1255
    };
};
 

template <>
struct type_id < struct dev_pm_qos_request > {
    enum {
        ID = 1256
    };
};
 

template <>
struct type_id < struct flowi4 > {
    enum {
        ID = 1257
    };
};
 

template <>
struct type_id < struct flowi6 > {
    enum {
        ID = 1258
    };
};
 

template <>
struct type_id < struct nlm_lockowner > {
    enum {
        ID = 1259
    };
};
 

template <>
struct type_id < struct tcp_md5sig > {
    enum {
        ID = 1260
    };
};
 

template <>
struct type_id < struct pcpu_group_info > {
    enum {
        ID = 1261
    };
};
 

template <>
struct type_id < struct ftrace_event_call > {
    enum {
        ID = 1262
    };
};
 

template <>
struct type_id < struct acpi_device_wakeup_flags > {
    enum {
        ID = 1263
    };
};
 

template <>
struct type_id < struct mm_struct > {
    enum {
        ID = 1264
    };
};
 

template <>
struct type_id < struct blk_integrity > {
    enum {
        ID = 1265
    };
};
 

template <>
struct type_id < struct fiemap > {
    enum {
        ID = 1266
    };
};
 

template <>
struct type_id < struct tc_cbq_xstats > {
    enum {
        ID = 1267
    };
};
 

template <>
struct type_id < struct aio_ring > {
    enum {
        ID = 1268
    };
};
 

template <>
struct type_id < struct x86_msi_ops > {
    enum {
        ID = 1269
    };
};
 

template <>
struct type_id < struct client_extension > {
    enum {
        ID = 1270
    };
};
 

template <>
struct type_id < struct raw6_sock > {
    enum {
        ID = 1271
    };
};
 

template <>
struct type_id < struct blockgroup_lock > {
    enum {
        ID = 1272
    };
};
 

template <>
struct type_id < struct _xsave_hdr > {
    enum {
        ID = 1273
    };
};
 

template <>
struct type_id < struct per_cpu_pageset > {
    enum {
        ID = 1274
    };
};
 

template <>
struct type_id < struct compat_shmid64_ds > {
    enum {
        ID = 1275
    };
};
 

template <>
struct type_id < struct files_struct > {
    enum {
        ID = 1276
    };
};
 

template <>
struct type_id < struct acpi_ivrs_hardware > {
    enum {
        ID = 1277
    };
};
 

template <>
struct type_id < struct apm_info > {
    enum {
        ID = 1278
    };
};
 

template <>
struct type_id < struct ip_auth_hdr > {
    enum {
        ID = 1279
    };
};
 

template <>
struct type_id < struct pid_namespace > {
    enum {
        ID = 1280
    };
};
 

template <>
struct type_id < struct acpi_pld_info > {
    enum {
        ID = 1281
    };
};
 

template <>
struct type_id < struct xfrm_usersa_flush > {
    enum {
        ID = 1282
    };
};
 

template <>
struct type_id < struct compat_ifmap > {
    enum {
        ID = 1283
    };
};
 

template <>
struct type_id < struct iattr > {
    enum {
        ID = 1284
    };
};
 

template <>
struct type_id < struct cdrom_read > {
    enum {
        ID = 1285
    };
};
 

template <>
struct type_id < struct header_ops > {
    enum {
        ID = 1286
    };
};
 

template <>
struct type_id < struct edd > {
    enum {
        ID = 1287
    };
};
 

template <>
struct type_id < struct tc_u32_mark > {
    enum {
        ID = 1288
    };
};
 

template <>
struct type_id < struct cftype_set > {
    enum {
        ID = 1289
    };
};
 

template <>
struct type_id < struct class_compat > {
    enum {
        ID = 1290
    };
};
 

template <>
struct type_id < struct __una_u64 > {
    enum {
        ID = 1291
    };
};
 

template <>
struct type_id < struct irq_data > {
    enum {
        ID = 1292
    };
};
 

template <>
struct type_id < struct pci_bus_resource > {
    enum {
        ID = 1293
    };
};
 

template <>
struct type_id < struct kmem_cache > {
    enum {
        ID = 1294
    };
};
 

template <>
struct type_id < struct ata_eh_context > {
    enum {
        ID = 1295
    };
};
 

template <>
struct type_id < struct alt_instr > {
    enum {
        ID = 1296
    };
};
 

template <>
struct type_id < struct acpi_resource_address > {
    enum {
        ID = 1297
    };
};
 

template <>
struct type_id < struct ist_info > {
    enum {
        ID = 1298
    };
};
 

template <>
struct type_id < struct dma_attrs > {
    enum {
        ID = 1299
    };
};
 

template <>
struct type_id < struct module_notes_attrs > {
    enum {
        ID = 1300
    };
};
 

template <>
struct type_id < struct mmu_notifier_mm > {
    enum {
        ID = 1301
    };
};
 

template <>
struct type_id < struct ip_conntrack_stat > {
    enum {
        ID = 1302
    };
};
 

template <>
struct type_id < struct acpi_device_power_state > {
    enum {
        ID = 1303
    };
};
 

template <>
struct type_id < struct zorro_device_id > {
    enum {
        ID = 1304
    };
};
 

template <>
struct type_id < struct acpi_ivrs_device8b > {
    enum {
        ID = 1305
    };
};
 

template <>
struct type_id < struct bio_integrity_payload > {
    enum {
        ID = 1306
    };
};
 

template <>
struct type_id < struct cgroup > {
    enum {
        ID = 1307
    };
};
 

template <>
struct type_id < struct input_keymap_entry > {
    enum {
        ID = 1308
    };
};
 

template <>
struct type_id < struct ieee_ets > {
    enum {
        ID = 1309
    };
};
 

template <>
struct type_id < struct kobj_type > {
    enum {
        ID = 1310
    };
};
 

template <>
struct type_id < struct acpi_table_hest > {
    enum {
        ID = 1311
    };
};
 

template <>
struct type_id < struct pnp_driver > {
    enum {
        ID = 1312
    };
};
 

template <>
struct type_id < struct hlist_head > {
    enum {
        ID = 1313
    };
};
 

template <>
struct type_id < struct packet_offload > {
    enum {
        ID = 1314
    };
};
 

template <>
struct type_id < struct cgroup_iter > {
    enum {
        ID = 1315
    };
};
 

template <>
struct type_id < struct timewait_sock_ops > {
    enum {
        ID = 1316
    };
};
 

template <>
struct type_id < struct tcamsg > {
    enum {
        ID = 1317
    };
};
 

template <>
struct type_id < struct zoneref > {
    enum {
        ID = 1318
    };
};
 

template <>
struct type_id < struct poll_table_struct > {
    enum {
        ID = 1319
    };
};
 

template <>
struct type_id < struct ethtool_usrip4_spec > {
    enum {
        ID = 1320
    };
};
 

template <>
struct type_id < struct tc_sfb_qopt > {
    enum {
        ID = 1321
    };
};
 

template <>
struct type_id < struct mmu_update > {
    enum {
        ID = 1322
    };
};
 

template <>
struct type_id < struct ipc_namespace > {
    enum {
        ID = 1323
    };
};
 

template <>
struct type_id < struct acpi_s3pt_suspend > {
    enum {
        ID = 1324
    };
};
 

template <>
struct type_id < struct fprop_local_percpu > {
    enum {
        ID = 1325
    };
};
 

template <>
struct type_id < struct dma_pool > {
    enum {
        ID = 1326
    };
};
 

template <>
struct type_id < struct in6_addr > {
    enum {
        ID = 1327
    };
};
 

template <>
struct type_id < struct eisa_device_id > {
    enum {
        ID = 1328
    };
};
 

template <>
struct type_id < struct file_handle > {
    enum {
        ID = 1329
    };
};
 

template <>
struct type_id < struct cdrom_volctrl > {
    enum {
        ID = 1330
    };
};
 

template <>
struct type_id < struct tasklet_hrtimer > {
    enum {
        ID = 1331
    };
};
 

template <>
struct type_id < struct bio_pair > {
    enum {
        ID = 1332
    };
};
 

template <>
struct type_id < struct ctl_table_set > {
    enum {
        ID = 1333
    };
};
 

template <>
struct type_id < struct user_struct > {
    enum {
        ID = 1334
    };
};
 

template <>
struct type_id < struct rt2_hdr > {
    enum {
        ID = 1335
    };
};
 

template <>
struct type_id < struct rt_mutex > {
    enum {
        ID = 1336
    };
};
 

template <>
struct type_id < struct pdev_archdata > {
    enum {
        ID = 1337
    };
};
 

template <>
struct type_id < struct tc_ratespec > {
    enum {
        ID = 1338
    };
};
 

template <>
struct type_id < struct scsi_lun > {
    enum {
        ID = 1339
    };
};
 

template <>
struct type_id < struct dsa_chip_data > {
    enum {
        ID = 1340
    };
};
 

template <>
struct type_id < struct acpi_asf_address > {
    enum {
        ID = 1341
    };
};
 

template <>
struct type_id < struct elf64_shdr > {
    enum {
        ID = 1342
    };
};
 

template <>
struct type_id < struct mtd_info > {
    enum {
        ID = 1343
    };
};
 

template <>
struct type_id < struct sb_writers > {
    enum {
        ID = 1344
    };
};
 

template <>
struct type_id < struct nda_cacheinfo > {
    enum {
        ID = 1345
    };
};
 

template <>
struct type_id < struct acpi_ibft_header > {
    enum {
        ID = 1346
    };
};
 

template <>
struct type_id < struct statfs64 > {
    enum {
        ID = 1347
    };
};
 

template <>
struct type_id < struct ata_port_operations > {
    enum {
        ID = 1348
    };
};
 

template <>
struct type_id < struct class_dev_iter > {
    enum {
        ID = 1349
    };
};
 

template <>
struct type_id < struct linger > {
    enum {
        ID = 1350
    };
};
 

template <>
struct type_id < struct dn_route > {
    enum {
        ID = 1351
    };
};
 

template <>
struct type_id < struct page_frag > {
    enum {
        ID = 1352
    };
};
 

template <>
struct type_id < struct f_owner_ex > {
    enum {
        ID = 1353
    };
};
 

template <>
struct type_id < struct qdisc_watchdog > {
    enum {
        ID = 1354
    };
};
 

template <>
struct type_id < struct _ymmh_state > {
    enum {
        ID = 1355
    };
};
 

template <>
struct type_id < struct ata_port > {
    enum {
        ID = 1356
    };
};
 

template <>
struct type_id < struct acpi_device_flags > {
    enum {
        ID = 1357
    };
};
 

template <>
struct type_id < struct class_attribute > {
    enum {
        ID = 1358
    };
};
 

template <>
struct type_id < struct fib_table > {
    enum {
        ID = 1359
    };
};
 

template <>
struct type_id < struct ipv6_devconf > {
    enum {
        ID = 1360
    };
};
 

template <>
struct type_id < struct acpi_table_erst > {
    enum {
        ID = 1361
    };
};
 

template <>
struct type_id < struct cpumask > {
    enum {
        ID = 1362
    };
};
 

template <>
struct type_id < struct i387_fxsave_struct > {
    enum {
        ID = 1363
    };
};
 

template <>
struct type_id < struct ieee1394_device_id > {
    enum {
        ID = 1364
    };
};
 

template <>
struct type_id < struct isapnp_device_id > {
    enum {
        ID = 1365
    };
};
 

template <>
struct type_id < struct hd_struct > {
    enum {
        ID = 1366
    };
};
 

template <>
struct type_id < struct compat_siginfo > {
    enum {
        ID = 1367
    };
};
 

template <>
struct type_id < struct iov_iter > {
    enum {
        ID = 1368
    };
};
 

template <>
struct type_id < struct class_ > {
    enum {
        ID = 1369
    };
};
 

template <>
struct type_id < struct tc_cbq_fopt > {
    enum {
        ID = 1370
    };
};
 

template <>
struct type_id < struct aead_alg > {
    enum {
        ID = 1371
    };
};
 

template <>
struct type_id < struct posix_acl > {
    enum {
        ID = 1372
    };
};
 

template <>
struct type_id < struct sock_common > {
    enum {
        ID = 1373
    };
};
 

template <>
struct type_id < struct ndmsg > {
    enum {
        ID = 1374
    };
};
 

template <>
struct type_id < struct compat_kexec_segment > {
    enum {
        ID = 1375
    };
};
 

template <>
struct type_id < struct ip_mreq > {
    enum {
        ID = 1376
    };
};
 

template <>
struct type_id < struct crypto_aead > {
    enum {
        ID = 1377
    };
};
 

template <>
struct type_id < struct acpi_vendor_uuid > {
    enum {
        ID = 1378
    };
};
 

template <>
struct type_id < struct acpi_madt_generic_interrupt > {
    enum {
        ID = 1379
    };
};
 

template <>
struct type_id < struct swap_info_struct > {
    enum {
        ID = 1380
    };
};
 

template <>
struct type_id < struct raw_spinlock > {
    enum {
        ID = 1381
    };
};
 

template <>
struct type_id < struct xattr_handler > {
    enum {
        ID = 1382
    };
};
 

template <>
struct type_id < struct acpi_subtable_header > {
    enum {
        ID = 1383
    };
};
 

template <>
struct type_id < struct eventfd_ctx > {
    enum {
        ID = 1384
    };
};
 

template <>
struct type_id < struct xfrm_encap_tmpl > {
    enum {
        ID = 1385
    };
};
 

template <>
struct type_id < struct xfrm_algo_auth > {
    enum {
        ID = 1386
    };
};
 

template <>
struct type_id < struct biovec_slab > {
    enum {
        ID = 1387
    };
};
 

template <>
struct type_id < struct wireless_dev > {
    enum {
        ID = 1388
    };
};
 

template <>
struct type_id < struct netlink_skb_parms > {
    enum {
        ID = 1389
    };
};
 

template <>
struct type_id < struct nf_hook_ops > {
    enum {
        ID = 1390
    };
};
 

template <>
struct type_id < struct kern_ipc_perm > {
    enum {
        ID = 1391
    };
};
 

template <>
struct type_id < struct xfrm_mark > {
    enum {
        ID = 1392
    };
};
 

template <>
struct type_id < struct ccs_modesel_head > {
    enum {
        ID = 1393
    };
};
 

template <>
struct type_id < struct uts_namespace > {
    enum {
        ID = 1394
    };
};
 

template <>
struct type_id < struct acpi_madt_local_apic_nmi > {
    enum {
        ID = 1395
    };
};
 

template <>
struct type_id < struct tcp_mib > {
    enum {
        ID = 1396
    };
};
 

template <>
struct type_id < struct acpi_dmar_hardware_unit > {
    enum {
        ID = 1397
    };
};
 

template <>
struct type_id < struct spinlock > {
    enum {
        ID = 1398
    };
};
 

template <>
struct type_id < struct ff_periodic_effect > {
    enum {
        ID = 1399
    };
};
 

template <>
struct type_id < struct acpi_table_wddt > {
    enum {
        ID = 1400
    };
};
 

template <>
struct type_id < struct acpi_slic_key > {
    enum {
        ID = 1401
    };
};
 

template <>
struct type_id < struct tc_service_curve > {
    enum {
        ID = 1402
    };
};
 

template <>
struct type_id < struct acpi_fpdt_header > {
    enum {
        ID = 1403
    };
};
 

template <>
struct type_id < struct acpi_io_attribute > {
    enum {
        ID = 1404
    };
};
 

template <>
struct type_id < struct xfrm_userpolicy_type > {
    enum {
        ID = 1405
    };
};
 

template <>
struct type_id < struct ifla_vxlan_port_range > {
    enum {
        ID = 1406
    };
};
 

template <>
struct type_id < struct compat_statfs64 > {
    enum {
        ID = 1407
    };
};
 

template <>
struct type_id < struct nf_ip_net > {
    enum {
        ID = 1408
    };
};
 

template <>
struct type_id < struct acpi_asf_alert > {
    enum {
        ID = 1409
    };
};
 

template <>
struct type_id < struct pm_subsys_data > {
    enum {
        ID = 1410
    };
};
 

template <>
struct type_id < struct dvd_manufact > {
    enum {
        ID = 1411
    };
};
 

template <>
struct type_id < struct unixware_slice > {
    enum {
        ID = 1412
    };
};
 

template <>
struct type_id < struct sched_info > {
    enum {
        ID = 1413
    };
};
 

template <>
struct type_id < struct netdev_boot_setup > {
    enum {
        ID = 1414
    };
};
 

template <>
struct type_id < struct proc_dir_entry > {
    enum {
        ID = 1415
    };
};
 

template <>
struct type_id < struct elf64_sym > {
    enum {
        ID = 1416
    };
};
 

template <>
struct type_id < struct file_lock > {
    enum {
        ID = 1417
    };
};
 

template <>
struct type_id < struct xsave_hdr_struct > {
    enum {
        ID = 1418
    };
};
 

template <>
struct type_id < struct tcp_timewait_sock > {
    enum {
        ID = 1419
    };
};
 

template <>
struct type_id < struct rps_dev_flow_table > {
    enum {
        ID = 1420
    };
};
 

template <>
struct type_id < struct pnp_card > {
    enum {
        ID = 1421
    };
};
 

template <>
struct type_id < struct msgbuf > {
    enum {
        ID = 1422
    };
};
 

template <>
struct type_id < struct sockaddr_ll > {
    enum {
        ID = 1423
    };
};
 

template <>
struct type_id < struct sk_buff_head > {
    enum {
        ID = 1424
    };
};
 

template <>
struct type_id < struct xfrm_userpolicy_info > {
    enum {
        ID = 1425
    };
};
 

template <>
struct type_id < struct xfrm_user_sec_ctx > {
    enum {
        ID = 1426
    };
};
 

template <>
struct type_id < struct acpi_csrt_descriptor > {
    enum {
        ID = 1427
    };
};
 

template <>
struct type_id < struct timex > {
    enum {
        ID = 1428
    };
};
 

template <>
struct type_id < struct acpi_dmar_pci_path > {
    enum {
        ID = 1429
    };
};
 

template <>
struct type_id < struct hv_vmbus_device_id > {
    enum {
        ID = 1430
    };
};
 

template <>
struct type_id < struct device_driver > {
    enum {
        ID = 1431
    };
};
 

template <>
struct type_id < struct file_ra_state > {
    enum {
        ID = 1432
    };
};
 

template <>
struct type_id < struct iphdr > {
    enum {
        ID = 1433
    };
};
 

template <>
struct type_id < struct fs_struct > {
    enum {
        ID = 1434
    };
};
 

template <>
struct type_id < struct bdi_writeback > {
    enum {
        ID = 1435
    };
};
 

template <>
struct type_id < struct x86_cpu_id > {
    enum {
        ID = 1436
    };
};
 

template <>
struct type_id < struct dma_pinned_list > {
    enum {
        ID = 1437
    };
};
 

template <>
struct type_id < struct acpi_table_dbgp > {
    enum {
        ID = 1438
    };
};
 

template <>
struct type_id < struct ethtool_perm_addr > {
    enum {
        ID = 1439
    };
};
 

template <>
struct type_id < struct cipher_desc > {
    enum {
        ID = 1440
    };
};
 

template <>
struct type_id < struct netns_ipv4 > {
    enum {
        ID = 1441
    };
};
 

template <>
struct type_id < struct partition_meta_info > {
    enum {
        ID = 1442
    };
};
 

template <>
struct type_id < struct shrink_control > {
    enum {
        ID = 1443
    };
};
 

template <>
struct type_id < struct ieee_pfc > {
    enum {
        ID = 1444
    };
};
 

template <>
struct type_id < struct vfs_cap_data > {
    enum {
        ID = 1445
    };
};
 

template <>
struct type_id < struct of_device_id > {
    enum {
        ID = 1446
    };
};
 

template <>
struct type_id < struct dma_coherent_mem > {
    enum {
        ID = 1447
    };
};
 

template <>
struct type_id < struct i387_soft_struct > {
    enum {
        ID = 1448
    };
};
 

template <>
struct type_id < struct rng_alg > {
    enum {
        ID = 1449
    };
};
 

template <>
struct type_id < struct acpi_table_dbg2 > {
    enum {
        ID = 1450
    };
};
 

template <>
struct type_id < struct netlink_dump_control > {
    enum {
        ID = 1451
    };
};
 

template <>
struct type_id < struct netns_ipvs > {
    enum {
        ID = 1452
    };
};
 

template <>
struct type_id < struct pci_saved_state > {
    enum {
        ID = 1453
    };
};
 

template <>
struct type_id < struct qdisc_size_table > {
    enum {
        ID = 1454
    };
};
 

template <>
struct type_id < struct sec_path > {
    enum {
        ID = 1455
    };
};
 

template <>
struct type_id < struct acpi_resource_fixed_dma > {
    enum {
        ID = 1456
    };
};
 

template <>
struct type_id < struct x86_io_apic_ops > {
    enum {
        ID = 1457
    };
};
 

template <>
struct type_id < struct xattr > {
    enum {
        ID = 1458
    };
};
 

template <>
struct type_id < struct acpi_asf_control_data > {
    enum {
        ID = 1459
    };
};
 

template <>
struct type_id < struct hd_geometry > {
    enum {
        ID = 1460
    };
};
 

template <>
struct type_id < struct acpi_s3pt_resume > {
    enum {
        ID = 1461
    };
};
 

template <>
struct type_id < struct acpi_table_rasf > {
    enum {
        ID = 1462
    };
};
 

template <>
struct type_id < struct compat_flock > {
    enum {
        ID = 1463
    };
};
 

template <>
struct type_id < struct xsave_struct > {
    enum {
        ID = 1464
    };
};
 

template <>
struct type_id < struct acpi_resource_memory24 > {
    enum {
        ID = 1465
    };
};
 

template <>
struct type_id < struct acpi_mpst_power_node > {
    enum {
        ID = 1466
    };
};
 

template <>
struct type_id < struct cleancache_filekey > {
    enum {
        ID = 1467
    };
};
 

template <>
struct type_id < struct packet_type > {
    enum {
        ID = 1468
    };
};
 

template <>
struct type_id < struct device > {
    enum {
        ID = 1469
    };
};
 

template <>
struct type_id < struct tp_module > {
    enum {
        ID = 1470
    };
};
 

template <>
struct type_id < struct vcpu_info > {
    enum {
        ID = 1471
    };
};
 

template <>
struct type_id < struct tc_sfb_xstats > {
    enum {
        ID = 1472
    };
};
 

template <>
struct type_id < struct anon_vma > {
    enum {
        ID = 1473
    };
};
 

template <>
struct type_id < struct pci_device_id > {
    enum {
        ID = 1474
    };
};
 

template <>
struct type_id < struct dst_entry > {
    enum {
        ID = 1475
    };
};
 

template <>
struct type_id < struct pci_sriov > {
    enum {
        ID = 1476
    };
};
 

template <>
struct type_id < struct request > {
    enum {
        ID = 1477
    };
};
 

template <>
struct type_id < struct ssb_device_id > {
    enum {
        ID = 1478
    };
};
 

template <>
struct type_id < struct compat_linux_dirent > {
    enum {
        ID = 1479
    };
};
 

template <>
struct type_id < struct subprocess_info > {
    enum {
        ID = 1480
    };
};
 

template <>
struct type_id < struct vio_device_id > {
    enum {
        ID = 1481
    };
};
 

template <>
struct type_id < struct mdio_device_id > {
    enum {
        ID = 1482
    };
};
 

template <>
struct type_id < struct gnet_stats_rate_est > {
    enum {
        ID = 1483
    };
};
 

template <>
struct type_id < struct input_value > {
    enum {
        ID = 1484
    };
};
 

template <>
struct type_id < struct tc_gred_qopt > {
    enum {
        ID = 1485
    };
};
 

template <>
struct type_id < struct ata_device > {
    enum {
        ID = 1486
    };
};
 

template <>
struct type_id < struct shared_info > {
    enum {
        ID = 1487
    };
};
 

template <>
struct type_id < struct rtnexthop > {
    enum {
        ID = 1488
    };
};
 

template <>
struct type_id < struct platform_device > {
    enum {
        ID = 1489
    };
};
 

template <>
struct type_id < struct rps_sock_flow_table > {
    enum {
        ID = 1490
    };
};
 

template <>
struct type_id < struct vm86plus_struct > {
    enum {
        ID = 1491
    };
};
 

template <>
struct type_id < struct x86_init_ops > {
    enum {
        ID = 1492
    };
};
 

template <>
struct type_id < struct super_operations > {
    enum {
        ID = 1493
    };
};
 

template <>
struct type_id < struct acpi_bus_ops > {
    enum {
        ID = 1494
    };
};
 

template <>
struct type_id < struct _fpstate > {
    enum {
        ID = 1495
    };
};
 

template <>
struct type_id < struct request_values > {
    enum {
        ID = 1496
    };
};
 

template <>
struct type_id < struct rcu_node > {
    enum {
        ID = 1497
    };
};
 

template <>
struct type_id < struct cgroup_taskset > {
    enum {
        ID = 1498
    };
};
 

template <>
struct type_id < struct pneigh_entry > {
    enum {
        ID = 1499
    };
};
 

template <>
struct type_id < struct user_desc > {
    enum {
        ID = 1500
    };
};
 

template <>
struct type_id < struct ipc64_perm > {
    enum {
        ID = 1501
    };
};
 

template <>
struct type_id < struct node_active_region > {
    enum {
        ID = 1502
    };
};
 

template <>
struct type_id < struct cdrom_blk > {
    enum {
        ID = 1503
    };
};
 

template <>
struct type_id < struct request_sense > {
    enum {
        ID = 1504
    };
};
 

template <>
struct type_id < struct mnt_namespace > {
    enum {
        ID = 1505
    };
};
 

template <>
struct type_id < struct acpi_pmtt_controller > {
    enum {
        ID = 1506
    };
};
 

template <>
struct type_id < struct ethhdr > {
    enum {
        ID = 1507
    };
};
 

template <>
struct type_id < struct percpu_counter > {
    enum {
        ID = 1508
    };
};
 

template <>
struct type_id < struct scsi_varlen_cdb_hdr > {
    enum {
        ID = 1509
    };
};
 

template <>
struct type_id < struct rt0_hdr > {
    enum {
        ID = 1510
    };
};
 

template <>
struct type_id < struct udp_table > {
    enum {
        ID = 1511
    };
};
 

template <>
struct type_id < struct module_kobject > {
    enum {
        ID = 1512
    };
};
 

template <>
struct type_id < struct module > {
    enum {
        ID = 1513
    };
};
 

template <>
struct type_id < struct Qdisc_class_hash > {
    enum {
        ID = 1514
    };
};
 

template <>
struct type_id < struct ctl_table_header > {
    enum {
        ID = 1515
    };
};
 

template <>
struct type_id < struct linux_dirent64 > {
    enum {
        ID = 1516
    };
};
 

template <>
struct type_id < struct netns_sysctl_ipv6 > {
    enum {
        ID = 1517
    };
};
 

template <>
struct type_id < struct device_private > {
    enum {
        ID = 1518
    };
};
 

template <>
struct type_id < struct zap_details > {
    enum {
        ID = 1519
    };
};
 

template <>
struct type_id < struct compat_timespec > {
    enum {
        ID = 1520
    };
};
 

template <>
struct type_id < struct inet_connection_sock > {
    enum {
        ID = 1521
    };
};
 

template <>
struct type_id < struct ip6_mtuinfo > {
    enum {
        ID = 1522
    };
};
 

template <>
struct type_id < struct mpc_oemtable > {
    enum {
        ID = 1523
    };
};
 

template <>
struct type_id < struct acpi_table_wdrt > {
    enum {
        ID = 1524
    };
};
 

template <>
struct type_id < struct acpi_table_sbst > {
    enum {
        ID = 1525
    };
};
 

template <>
struct type_id < struct Qdisc_class_common > {
    enum {
        ID = 1526
    };
};
 

template <>
struct type_id < struct x86_cpuinit_ops > {
    enum {
        ID = 1527
    };
};
 

template <>
struct type_id < struct acpi_table_rsdt > {
    enum {
        ID = 1528
    };
};
 

template <>
struct type_id < struct acpi_table_rsdp > {
    enum {
        ID = 1529
    };
};
 

template <>
struct type_id < struct blkcg_gq > {
    enum {
        ID = 1530
    };
};
 

template <>
struct type_id < struct task_delay_info > {
    enum {
        ID = 1531
    };
};
 

template <>
struct type_id < struct ethtool_channels > {
    enum {
        ID = 1532
    };
};
 

template <>
struct type_id < struct xps_map > {
    enum {
        ID = 1533
    };
};
 

template <>
struct type_id < struct compat_robust_list_head > {
    enum {
        ID = 1534
    };
};
 

template <>
struct type_id < struct tmem_op > {
    enum {
        ID = 1535
    };
};
 

template <>
struct type_id < struct reclaim_state > {
    enum {
        ID = 1536
    };
};
 

template <>
struct type_id < struct mpc_table > {
    enum {
        ID = 1537
    };
};
 

template <>
struct type_id < struct sigaction > {
    enum {
        ID = 1538
    };
};
 

template <>
struct type_id < struct if_dqblk > {
    enum {
        ID = 1539
    };
};
 

template <>
struct type_id < struct dma_chan_dev > {
    enum {
        ID = 1540
    };
};
 

template <>
struct type_id < struct ndt_config > {
    enum {
        ID = 1541
    };
};
 

template <>
struct type_id < struct ata_taskfile > {
    enum {
        ID = 1542
    };
};
 

template <>
struct type_id < struct compat_rusage > {
    enum {
        ID = 1543
    };
};
 

template <>
struct type_id < struct cgroupstats > {
    enum {
        ID = 1544
    };
};
 

template <>
struct type_id < struct garp_port > {
    enum {
        ID = 1545
    };
};
 

template <>
struct type_id < struct inet_hashinfo > {
    enum {
        ID = 1546
    };
};
 

template <>
struct type_id < struct cfs_rq > {
    enum {
        ID = 1547
    };
};
 

template <>
struct type_id < struct acpi_hest_generic > {
    enum {
        ID = 1548
    };
};
 

template <>
struct type_id < struct ethtool_tcpip4_spec > {
    enum {
        ID = 1549
    };
};
 

template <>
struct type_id < struct mempolicy > {
    enum {
        ID = 1550
    };
};
 

template <>
struct type_id < struct cdrom_tochdr > {
    enum {
        ID = 1551
    };
};
 

template <>
struct type_id < struct tpacket_req > {
    enum {
        ID = 1552
    };
};
 

template <>
struct type_id < struct xfrm_user_acquire > {
    enum {
        ID = 1553
    };
};
 

template <>
struct type_id < struct thread_group_cputimer > {
    enum {
        ID = 1554
    };
};
 

template <>
struct type_id < struct acpi_grt_info > {
    enum {
        ID = 1555
    };
};
 

template <>
struct type_id < struct quota_format_ops > {
    enum {
        ID = 1556
    };
};
 

template <>
struct type_id < struct qtree_fmt_operations > {
    enum {
        ID = 1557
    };
};
 

template <>
struct type_id < struct kobj_attribute > {
    enum {
        ID = 1558
    };
};
 

template <>
struct type_id < struct semaphore > {
    enum {
        ID = 1559
    };
};
 

template <>
struct type_id < struct acpi_gtm_info > {
    enum {
        ID = 1560
    };
};
 

template <>
struct type_id < struct pci_vpd > {
    enum {
        ID = 1561
    };
};
 

template <>
struct type_id < struct compat_semid64_ds > {
    enum {
        ID = 1562
    };
};
 

template <>
struct type_id < struct pv_mmu_ops > {
    enum {
        ID = 1563
    };
};
 

template <>
struct type_id < struct neighbour > {
    enum {
        ID = 1564
    };
};
 

template <>
struct type_id < struct pollfd > {
    enum {
        ID = 1565
    };
};
 

template <>
struct type_id < struct mem_section > {
    enum {
        ID = 1566
    };
};
 

template <>
struct type_id < struct olpc_ofw_header > {
    enum {
        ID = 1567
    };
};
 

template <>
struct type_id < struct bsd_partition > {
    enum {
        ID = 1568
    };
};
 

template <>
struct type_id < struct ethtool_sfeatures > {
    enum {
        ID = 1569
    };
};
 

template <>
struct type_id < struct dma_tx_state > {
    enum {
        ID = 1570
    };
};
 

template <>
struct type_id < struct compat_sock_fprog > {
    enum {
        ID = 1571
    };
};
 

template <>
struct type_id < struct tcf_proto_ops > {
    enum {
        ID = 1572
    };
};
 

template <>
struct type_id < struct xfrm_policy > {
    enum {
        ID = 1573
    };
};
 

template <>
struct type_id < struct pci_error_handlers > {
    enum {
        ID = 1574
    };
};
 

template <>
struct type_id < struct pci_dynids > {
    enum {
        ID = 1575
    };
};
 

template <>
struct type_id < struct ipv6_mreq > {
    enum {
        ID = 1576
    };
};
 

template <>
struct type_id < struct nf_ct_tcp_flags > {
    enum {
        ID = 1577
    };
};
 

template <>
struct type_id < struct ifinfomsg > {
    enum {
        ID = 1578
    };
};
 

template <>
struct type_id < struct dma_chan_percpu > {
    enum {
        ID = 1579
    };
};
 

template <>
struct type_id < struct prop_local_percpu > {
    enum {
        ID = 1580
    };
};
 

template <>
struct type_id < struct neighbour_cb > {
    enum {
        ID = 1581
    };
};
 

template <>
struct type_id < struct nfs4_lock_info > {
    enum {
        ID = 1582
    };
};
 

template <>
struct type_id < struct acpi_pci_id > {
    enum {
        ID = 1583
    };
};
 

template <>
struct type_id < struct mii_ioctl_data > {
    enum {
        ID = 1584
    };
};
 

template <>
struct type_id < struct netns_sctp > {
    enum {
        ID = 1585
    };
};
 

template <>
struct type_id < struct jbd2_journal_block_tail > {
    enum {
        ID = 1586
    };
};
 

template <>
struct type_id < struct notifier_block > {
    enum {
        ID = 1587
    };
};
 

template <>
struct type_id < struct scm_creds > {
    enum {
        ID = 1588
    };
};
 

template <>
struct type_id < struct uprobe_consumer > {
    enum {
        ID = 1589
    };
};
 

template <>
struct type_id < struct kstatfs > {
    enum {
        ID = 1590
    };
};
 

template <>
struct type_id < struct file_lock_operations > {
    enum {
        ID = 1591
    };
};
 

template <>
struct type_id < struct __user_cap_header_struct > {
    enum {
        ID = 1592
    };
};
 

template <>
struct type_id < struct acpi_resource_memory32 > {
    enum {
        ID = 1593
    };
};
 

template <>
struct type_id < struct tc_police > {
    enum {
        ID = 1594
    };
};
 

template <>
struct type_id < struct fstrim_range > {
    enum {
        ID = 1595
    };
};
 

template <>
struct type_id < struct files_stat_struct > {
    enum {
        ID = 1596
    };
};
 

template <>
struct type_id < struct ifmap > {
    enum {
        ID = 1597
    };
};
 

template <>
struct type_id < struct udphdr > {
    enum {
        ID = 1598
    };
};
 

template <>
struct type_id < struct queue_limits > {
    enum {
        ID = 1599
    };
};
 

template <>
struct type_id < struct acpi_dev_node > {
    enum {
        ID = 1600
    };
};
 

template <>
struct type_id < struct acpi_table_fpdt > {
    enum {
        ID = 1601
    };
};
 

template <>
struct type_id < struct kmem_cache_cpu > {
    enum {
        ID = 1602
    };
};
 

template <>
struct type_id < struct dql > {
    enum {
        ID = 1603
    };
};
 

template <>
struct type_id < struct xfrm_sec_ctx > {
    enum {
        ID = 1604
    };
};
 

template <>
struct type_id < struct ccw_device_id > {
    enum {
        ID = 1605
    };
};
 

template <>
struct type_id < struct bio_list > {
    enum {
        ID = 1606
    };
};
 

template <>
struct type_id < struct ipv6_params > {
    enum {
        ID = 1607
    };
};
 

template <>
struct type_id < struct fs_qfilestat > {
    enum {
        ID = 1608
    };
};
 

template <>
struct type_id < struct rtable > {
    enum {
        ID = 1609
    };
};
 

template <>
struct type_id < struct netns_dccp > {
    enum {
        ID = 1610
    };
};
 

template <>
struct type_id < struct dsa_switch > {
    enum {
        ID = 1611
    };
};
 

template <>
struct type_id < struct page > {
    enum {
        ID = 1612
    };
};
 

template <>
struct type_id < struct sched_avg > {
    enum {
        ID = 1613
    };
};
 

template <>
struct type_id < struct ndtmsg > {
    enum {
        ID = 1614
    };
};
 

template <>
struct type_id < struct list_head > {
    enum {
        ID = 1615
    };
};
 

template <>
struct type_id < struct ipv6_rt_hdr > {
    enum {
        ID = 1616
    };
};
 

template <>
struct type_id < struct pnp_protocol > {
    enum {
        ID = 1617
    };
};
 

template <>
struct type_id < struct elevator_queue > {
    enum {
        ID = 1618
    };
};
 

template <>
struct type_id < struct acpi_ivrs_device4 > {
    enum {
        ID = 1619
    };
};
 

template <>
struct type_id < struct feature_header > {
    enum {
        ID = 1620
    };
};
 

template <>
struct type_id < struct acpi_asf_remote > {
    enum {
        ID = 1621
    };
};
 

template <>
struct type_id < struct tms > {
    enum {
        ID = 1622
    };
};
 

template <>
struct type_id < struct audit_context > {
    enum {
        ID = 1623
    };
};
 

template <>
struct type_id < struct radix_tree_node > {
    enum {
        ID = 1624
    };
};
 

template <>
struct type_id < struct sysv_sem > {
    enum {
        ID = 1625
    };
};
 

template <>
struct type_id < struct __una_u16 > {
    enum {
        ID = 1626
    };
};
 

template <>
struct type_id < struct Qdisc > {
    enum {
        ID = 1627
    };
};
 

template <>
struct type_id < struct pnp_card_link > {
    enum {
        ID = 1628
    };
};
 

template <>
struct type_id < struct acpi_predefined_names > {
    enum {
        ID = 1629
    };
};
 

template <>
struct type_id < struct dvd_lu_send_rpcstate > {
    enum {
        ID = 1630
    };
};
 

template <>
struct type_id < struct robust_list_head > {
    enum {
        ID = 1631
    };
};
 

template <>
struct type_id < struct sysinfo > {
    enum {
        ID = 1632
    };
};
 

template <>
struct type_id < struct tc_gred_sopt > {
    enum {
        ID = 1633
    };
};
 

template <>
struct type_id < struct socket > {
    enum {
        ID = 1634
    };
};
 

template <>
struct type_id < struct ip_comp_hdr > {
    enum {
        ID = 1635
    };
};
 

template <>
struct type_id < struct io_cq > {
    enum {
        ID = 1636
    };
};
 

template <>
struct type_id < struct pci_bits > {
    enum {
        ID = 1637
    };
};
 

template <>
struct type_id < struct selinux_audit_rule > {
    enum {
        ID = 1638
    };
};
 

template <>
struct type_id < struct compat_mmsghdr > {
    enum {
        ID = 1639
    };
};
 

template <>
struct type_id < struct vfsmount > {
    enum {
        ID = 1640
    };
};
 

template <>
struct type_id < struct timerqueue_node > {
    enum {
        ID = 1641
    };
};
 

template <>
struct type_id < struct acpi_table_desc > {
    enum {
        ID = 1642
    };
};
 

template <>
struct type_id < struct kernel_vm86_struct > {
    enum {
        ID = 1643
    };
};
 

template <>
struct type_id < struct seccomp_data > {
    enum {
        ID = 1644
    };
};
 

template <>
struct type_id < struct acpi_table_wdat > {
    enum {
        ID = 1645
    };
};
 

template <>
struct type_id < struct acpi_resource_generic_register > {
    enum {
        ID = 1646
    };
};
 

template <>
struct type_id < struct ctl_node > {
    enum {
        ID = 1647
    };
};
 

template <>
struct type_id < struct netdev_tc_txq > {
    enum {
        ID = 1648
    };
};
 

template <>
struct type_id < struct acpi_erst_entry > {
    enum {
        ID = 1649
    };
};
 

template <>
struct type_id < struct neigh_table > {
    enum {
        ID = 1650
    };
};
 

template <>
struct type_id < struct tick_sched > {
    enum {
        ID = 1651
    };
};
 

template <>
struct type_id < struct sockaddr_nl > {
    enum {
        ID = 1652
    };
};
 

template <>
struct type_id < struct paravirt_patch_template > {
    enum {
        ID = 1653
    };
};
 

template <>
struct type_id < struct dvd_disckey > {
    enum {
        ID = 1654
    };
};
 

template <>
struct type_id < struct dentry_stat_t > {
    enum {
        ID = 1655
    };
};
 

template <>
struct type_id < struct tcf_walker > {
    enum {
        ID = 1656
    };
};
 

template <>
struct type_id < struct call_single_data > {
    enum {
        ID = 1657
    };
};
 

template <>
struct type_id < struct dvd_host_send_rpcstate > {
    enum {
        ID = 1658
    };
};
 

template <>
struct type_id < struct pci_cap_saved_state > {
    enum {
        ID = 1659
    };
};
 

template <>
struct type_id < struct key_user > {
    enum {
        ID = 1660
    };
};
 

template <>
struct type_id < struct ts_state > {
    enum {
        ID = 1661
    };
};
 

template <>
struct type_id < struct driver_attribute > {
    enum {
        ID = 1662
    };
};
 

template <>
struct type_id < struct file_system_type > {
    enum {
        ID = 1663
    };
};
 

template <>
struct type_id < struct tcp_fastopen_request > {
    enum {
        ID = 1664
    };
};
 

template <>
struct type_id < struct amba_id > {
    enum {
        ID = 1665
    };
};
 

template <>
struct type_id < struct aio_ring_info > {
    enum {
        ID = 1666
    };
};
 

template <>
struct type_id < struct sockaddr > {
    enum {
        ID = 1667
    };
};
 

template <>
struct type_id < struct pid > {
    enum {
        ID = 1668
    };
};
 

template <>
struct type_id < struct swap_extent > {
    enum {
        ID = 1669
    };
};
 

template <>
struct type_id < struct tcpm_hash_bucket > {
    enum {
        ID = 1670
    };
};
 

template <>
struct type_id < struct sched_domain_attr > {
    enum {
        ID = 1671
    };
};
 

template <>
struct type_id < struct ata_ering_entry > {
    enum {
        ID = 1672
    };
};
 

template <>
struct type_id < struct dmi_strmatch > {
    enum {
        ID = 1673
    };
};
 

template <>
struct type_id < struct device_node > {
    enum {
        ID = 1674
    };
};
 

template <>
struct type_id < struct input_mt > {
    enum {
        ID = 1675
    };
};
 

template <>
struct type_id < struct __old_kernel_stat > {
    enum {
        ID = 1676
    };
};
 

template <>
struct type_id < struct dvd_lu_send_agid > {
    enum {
        ID = 1677
    };
};
 

template <>
struct type_id < struct netdev_queue > {
    enum {
        ID = 1678
    };
};
 

template <>
struct type_id < struct tss_struct > {
    enum {
        ID = 1679
    };
};
 

template <>
struct type_id < struct stat > {
    enum {
        ID = 1680
    };
};
 

template <>
struct type_id < struct shrinker > {
    enum {
        ID = 1681
    };
};
 

template <>
struct type_id < struct ipv6_txoptions > {
    enum {
        ID = 1682
    };
};
 

template <>
struct type_id < struct acpi_fpdt_boot > {
    enum {
        ID = 1683
    };
};
 

template <>
struct type_id < struct commit_header > {
    enum {
        ID = 1684
    };
};
 

template <>
struct type_id < struct dev_pm_domain > {
    enum {
        ID = 1685
    };
};
 

template <>
struct type_id < struct acpi_madt_local_sapic > {
    enum {
        ID = 1686
    };
};
 

template <>
struct type_id < struct cgroup_subsys_state > {
    enum {
        ID = 1687
    };
};
 

template <>
struct type_id < struct seq_file > {
    enum {
        ID = 1688
    };
};
 

template <>
struct type_id < struct acpi_pcct_subspace > {
    enum {
        ID = 1689
    };
};
 

template <>
struct type_id < struct acpi_hest_aer > {
    enum {
        ID = 1690
    };
};
 

template <>
struct type_id < struct tc_netem_qopt > {
    enum {
        ID = 1691
    };
};
 

template <>
struct type_id < struct ethtool_flash > {
    enum {
        ID = 1692
    };
};
 

template <>
struct type_id < struct edd_info > {
    enum {
        ID = 1693
    };
};
 

template <>
struct type_id < struct tcp_sack_block_wire > {
    enum {
        ID = 1694
    };
};
 

