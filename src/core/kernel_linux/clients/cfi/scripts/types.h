typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned int __uint32_t;
typedef unsigned int uint32_t;
typedef uint32_t __u32;
typedef __u32 __wsum;
typedef unsigned char u8;
typedef unsigned long long u64;
typedef unsigned gfp_t;
typedef long unsigned int size_t;
typedef long int __ssize_t ;
typedef __ssize_t ssize_t ;
typedef long int __off64_t ;
typedef __off64_t __loff_t ;
typedef __loff_t loff_t ;
enum dma_data_direction {
DMA_BIDIRECTIONAL = 0 , DMA_TO_DEVICE = 1 , DMA_FROM_DEVICE = 2 , DMA_NONE = 3 , };
typedef enum {
PHY_INTERFACE_MODE_MII , PHY_INTERFACE_MODE_GMII , PHY_INTERFACE_MODE_SGMII , PHY_INTERFACE_MODE_TBI , PHY_INTERFACE_MODE_RMII , PHY_INTERFACE_MODE_RGMII , PHY_INTERFACE_MODE_RGMII_ID , PHY_INTERFACE_MODE_RGMII_RXID , PHY_INTERFACE_MODE_RGMII_TXID , PHY_INTERFACE_MODE_RTBI }
phy_interface_t;

typedef struct {
volatile int counter ;
}atomic_t;
typedef struct {
volatile long counter ;
}atomic64_t;
typedef struct raw_spinlock {
unsigned int slock ;
}raw_spinlock_t;
typedef struct {
raw_spinlock_t raw_lock ;
}spinlock_t;
struct netdev_hw_addr_list {
struct list_head list ;
int count ;
};
struct net_device_stats {
unsigned long rx_packets ;
unsigned long tx_packets ;
unsigned long rx_bytes ;
unsigned long tx_bytes ;
unsigned long rx_errors ;
unsigned long tx_errors ;
unsigned long rx_dropped ;
unsigned long tx_dropped ;
unsigned long multicast ;
unsigned long collisions ;
unsigned long rx_length_errors ;
unsigned long rx_over_errors ;
unsigned long rx_crc_errors ;
unsigned long rx_frame_errors ;
unsigned long rx_fifo_errors ;
unsigned long rx_missed_errors ;
unsigned long tx_aborted_errors ;
unsigned long tx_carrier_errors ;
unsigned long tx_fifo_errors ;
unsigned long tx_heartbeat_errors ;
unsigned long tx_window_errors ;
unsigned long rx_compressed ;
unsigned long tx_compressed ;
}
;
typedef struct pm_message {
int event ;
}
pm_message_t;
struct hlist_node {
struct hlist_node * next , **pprev ;
};
struct page;
struct firmware {
size_t size;
const u8 * data;
struct page **pages ;
};
struct semaphore {
spinlock_t lock ;
unsigned int count ;
struct list_head wait_list ;
};
struct sysfs_dirent;
struct kref {
atomic_t refcount;
};
struct kobj_type;
struct kset;
struct __wait_queue_head {
spinlock_t lock ;
struct list_head task_list ;
}
;
typedef struct __wait_queue_head wait_queue_head_t ;
enum dpm_state {
DPM_INVALID , DPM_ON , DPM_PREPARING , DPM_RESUMING , DPM_SUSPENDING , DPM_OFF , DPM_OFF_IRQ , }
;
enum rpm_status {
RPM_ACTIVE = 0 , RPM_RESUMING , RPM_SUSPENDED , RPM_SUSPENDING , }
;
enum rpm_request {
RPM_REQ_NONE = 0 , RPM_REQ_IDLE , RPM_REQ_SUSPEND , RPM_REQ_RESUME , }
;
struct timer_list {
struct list_head entry ;
unsigned long expires ;
void ( * function ) ( unsigned long ) ;
unsigned long data ;
struct tvec_base * base ;
void * start_site ;
char start_comm [ 16 ] ;
int start_pid ;
}
;
struct pci_dynids {
spinlock_t lock ;
struct list_head list ;
}
;
typedef unsigned int pci_ers_result_t ;
typedef atomic64_t atomic_long_t;
typedef void ( *work_func_t ) ( struct work_struct *work );
struct work_struct {
atomic_long_t data;
struct list_head entry;
work_func_t func;
};
struct dev_pm_info {
pm_message_t power_state ;
unsigned int can_wakeup:1;
unsigned int should_wakeup:1;
enum dpm_state status;
struct list_head entry;
struct timer_list suspend_timer;
unsigned long timer_expires;
struct work_struct work;
wait_queue_head_t wait_queue;
spinlock_t lock;
atomic_t usage_count;
atomic_t child_count;
unsigned int disable_depth:3;
unsigned int ignore_children:1;
unsigned int idle_notification:1;
unsigned int request_pending:1;
unsigned int deferred_resume:1;
enum rpm_request request;
enum rpm_status runtime_status;
int runtime_error;
};
struct kobject {
const char * name;
struct list_head entry;
struct kobject * parent;
struct kset * kset;
struct kobj_type * ktype;
struct sysfs_dirent * sd;
struct kref kref;
unsigned int state_initialized:1;
unsigned int state_in_sysfs:1;
unsigned int state_add_uevent_sent:1;
unsigned int state_remove_uevent_sent:1;
unsigned int uevent_suppress:1;
};
struct dev_archdata {
void * acpi_handle ;
struct dma_map_ops * dma_ops ;
};
typedef unsigned long int __dev_t;
typedef __dev_t dev_t ;
struct klist_node {
void * n_klist ;
struct list_head n_node ;
struct kref n_ref ;
};
struct class1;
struct device {
struct device * parent ;
struct device_private * p ;
struct kobject kobj;
const char * init_name;
struct device_type * type;
struct semaphore sem;
struct bus_type * bus;
struct device_driver * driver;
void * platform_data;
struct dev_pm_info power;
int numa_node ;
u64 * dma_mask ;
u64 coherent_dma_mask ;
struct device_dma_parameters * dma_parms ;
struct list_head dma_pools ;
struct dma_coherent_mem * dma_mem ;
struct dev_archdata archdata ;
dev_t devt ;
spinlock_t devres_lock ;
struct list_head devres_head ;
struct klist_node knode_class ;
struct class1 *class1;
const struct attribute_group * * groups ;
void ( * release ) ( struct device * dev ) ;
};
struct bus_type;
struct module;
struct pci_device_id;
struct pci_dev;
struct netdev_tx_t;
struct sk_buff;
typedef int u16;
struct scatterlist;
struct vlan_group;
struct neigh_parms;
struct ifmap;
struct ifreq;
struct iw_handler_def;
struct iw_public_data;
struct header_ops;
struct netdev_hw_addr_list;
struct dev_addr_list;
struct wireless_dev;
struct netdev_hw_addr_list;
struct netdev_queue;
struct Qdisc;
struct list_head;
struct hlist_node;
struct net_device;
struct netpoll_info;
struct net;
struct net_bridge_port;
struct macvlan_port;
struct garp_port;
struct attribute_group;
struct rtnl_link_ops;
struct dcbnl_rtnl_ops;
typedef struct {
volatile unsigned int slock;
}
arch_spinlock_t;
enum ethtool_phys_id_state {
ETHTOOL_ID_INACTIVE, ETHTOOL_ID_ACTIVE, ETHTOOL_ID_ON, ETHTOOL_ID_OFF };
struct netdev_queue {
struct net_device * dev ;
struct Qdisc * qdisc ;
unsigned long state ;
struct Qdisc * qdisc_sleeping ;
spinlock_t _xmit_lock __attribute__ ( ( __aligned__ ( ( 1 << ( 6 ) ) ) ) ) ;
int xmit_lock_owner ;
unsigned long trans_start ;
unsigned long tx_bytes ;
unsigned long tx_packets ;
unsigned long tx_dropped ;
}
__attribute__ ( ( __aligned__ ( ( 1 << ( 6 ) ) ) ) ) ;
enum netdev_tx {
NETDEV_TX_OK = 0 , NETDEV_TX_BUSY , NETDEV_TX_LOCKED = - 1 , }
;
