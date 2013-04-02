struct net_device_ops {
    int (*ndo_init ) ( struct net_device * dev ) ;
    void (*ndo_uninit ) ( struct net_device * dev ) ;
    int (*ndo_open ) ( struct net_device * dev ) ;
    int (*ndo_stop ) ( struct net_device * dev ) ;
    netdev_tx_t (*ndo_start_xmit ) ( struct sk_buff * skb , struct net_device * dev ) ;
    u16 (*ndo_select_queue ) ( struct net_device * dev , struct sk_buff * skb ) ;
    void (*ndo_change_rx_flags ) ( struct net_device * dev , int flags ) ;
    void (*ndo_set_rx_mode ) ( struct net_device * dev ) ;
    void (*ndo_set_multicast_list ) ( struct net_device * dev ) ;
    int (*ndo_set_mac_address ) ( struct net_device * dev , void * addr ) ;
    int (*ndo_validate_addr ) ( struct net_device * dev ) ;
    int (*ndo_do_ioctl ) ( struct net_device * dev , struct ifreq * ifr , int cmd );
    int (*ndo_set_config ) ( struct net_device * dev , struct ifmap * map );
    int (*ndo_change_mtu ) ( struct net_device * dev , int new_mtu );
    int (*ndo_neigh_setup ) ( struct net_device * dev , struct neigh_parms * );
    void (*ndo_tx_timeout ) ( struct net_device * dev );
    struct net_device_stats * ( * ndo_get_stats ) ( struct net_device * dev );
    void (*ndo_vlan_rx_register ) ( struct net_device * dev , struct vlan_group * grp );
    void (*ndo_vlan_rx_add_vid ) ( struct net_device * dev , unsigned short vid );
    void (*ndo_vlan_rx_kill_vid ) ( struct net_device * dev , unsigned short vid );
    void (*ndo_poll_controller ) ( struct net_device * dev );
    int (*ndo_fcoe_enable ) ( struct net_device * dev );
    int (*ndo_fcoe_disable ) ( struct net_device * dev );
    int (*ndo_fcoe_ddp_setup ) ( struct net_device * dev , u16 xid , struct scatterlist * sgl , unsigned int sgc );
    int (*ndo_fcoe_ddp_done ) ( struct net_device * dev , u16 xid );
};

