/*
 * kernel_types.hpp
 *
 *  Created on: 2013-03-31
 *      Author: akshayk
 */

#ifndef KERNEL_TYPES_HPP_
#define KERNEL_TYPES_HPP_

typedef __signed__ 	char 	__s8 ;
typedef unsigned 	char 	__u8 ;
typedef __signed__ 	short 	__s16 ;
typedef unsigned short 	__u16 ;
typedef __signed__ int 	__s32 ;
typedef unsigned int 	__u32 ;
typedef __signed__ long long __s64 ;
typedef unsigned long long __u64 ;
typedef signed char s8 ;
typedef unsigned char u8 ;
typedef signed short s16 ;
typedef unsigned short u16 ;
typedef signed int s32 ;
typedef unsigned int u32 ;
typedef signed long long s64 ;
typedef unsigned long long u64 ;
typedef unsigned long uintptr_t ;
typedef unsigned char u_char ;
typedef unsigned short u_short ;
typedef unsigned int u_int ;
typedef unsigned long u_long ;
typedef unsigned char unchar ;
typedef unsigned short ushort ;
typedef unsigned int uint ;
typedef unsigned long ulong ;
typedef unsigned long sector_t ;
typedef unsigned long blkcnt_t ;
typedef unsigned gfp_t ;
typedef unsigned fmode_t ;
typedef unsigned long __kernel_size_t ;
typedef unsigned gfp_t ;
typedef __kernel_size_t size_t ;
typedef unsigned char u8 ;
typedef void ( * __kernel_sighandler_t ) ( int ) ;
typedef struct { int val [ 2 ] ; } __kernel_fsid_t ;
typedef unsigned short umode_t ;
typedef int __kernel_key_t ;
typedef int __kernel_mqd_t ;
typedef unsigned long __kernel_ino_t ;
typedef unsigned int __kernel_mode_t ;
typedef unsigned long __kernel_nlink_t ;
typedef long __kernel_off_t ;
typedef int __kernel_pid_t ;
typedef int __kernel_ipc_pid_t ;
typedef unsigned int __kernel_uid_t ;
typedef unsigned int __kernel_gid_t ;
typedef unsigned long __kernel_size_t ;
typedef long __kernel_ssize_t ;
typedef long __kernel_ptrdiff_t ;
typedef long __kernel_time_t ;
typedef long __kernel_suseconds_t ;
typedef long __kernel_clock_t ;
typedef int __kernel_timer_t ;
typedef int __kernel_clockid_t ;
typedef int __kernel_daddr_t ;
typedef char * __kernel_caddr_t ;
typedef unsigned short __kernel_uid16_t ;
typedef unsigned short __kernel_gid16_t ;
typedef long long __kernel_loff_t ;
typedef unsigned short __kernel_old_uid_t ;
typedef unsigned short __kernel_old_gid_t ;
typedef unsigned long __kernel_old_dev_t ;
typedef __kernel_uid_t __kernel_uid32_t ;
typedef __kernel_gid_t __kernel_gid32_t ;
typedef __u32 __kernel_dev_t ;
typedef __kernel_ino_t ino_t ;
typedef __kernel_mode_t mode_t ;
typedef __kernel_nlink_t nlink_t ;
typedef __kernel_off_t off_t ;
typedef __kernel_pid_t pid_t ;
typedef __kernel_daddr_t daddr_t ;
typedef __kernel_key_t key_t ;
typedef __kernel_suseconds_t suseconds_t ;
typedef __kernel_timer_t timer_t ;
typedef __kernel_clockid_t clockid_t ;
typedef __kernel_mqd_t mqd_t ;
typedef __kernel_uid16_t uid16_t ;
typedef __kernel_gid16_t gid16_t ;
typedef __kernel_old_uid_t old_uid_t ;
typedef __kernel_old_gid_t old_gid_t ;
typedef __kernel_loff_t loff_t ;
typedef __kernel_size_t size_t ;
typedef __kernel_ssize_t ssize_t ;
typedef __kernel_ptrdiff_t ptrdiff_t ;
typedef __kernel_time_t time_t ;
typedef __kernel_clock_t clock_t ;
typedef __kernel_caddr_t caddr_t ;
typedef __u8 u_int8_t ;
typedef __s8 int8_t ;
typedef __u16 u_int16_t ;
typedef __s16 int16_t ;
typedef __u32 u_int32_t ;
typedef __s32 int32_t ;
typedef __u8 uint8_t ;
typedef __u16 uint16_t ;
typedef __u32 uint32_t ;
//typedef __u64 uint64_t ;
typedef __u64 u_int64_t ;
//typedef __s64 int64_t ;
typedef u64 dma_addr_t ;
typedef __u16 __le16 ;
typedef __u16 __be16 ;
typedef __u32 __le32 ;
typedef __u32 __be32 ;
typedef __u64 __le64 ;
typedef __u64 __be64 ;
typedef __u16 __sum16 ;
typedef __u32 __wsum ;
typedef u64 phys_addr_t ;
typedef struct { int counter ; } atomic_t ;
typedef struct { long counter ; } atomic64_t ;
typedef __kernel_uid32_t qid_t;
typedef long long qsize_t;


/*--mapped_device--*/
typedef enum { STATUSTYPE_INFO , STATUSTYPE_TABLE } status_type_t ;


struct lock_class_key { } ;
struct list_head { struct list_head * next , * prev ; } ;
struct hlist_head { struct hlist_node * first ; } ;
struct hlist_node { struct hlist_node * next , * * pprev ; } ;

typedef int ( * initxattrs ) ( struct inode * inode , const struct xattr * xattr_array , void * fs_data ) ;
typedef int ( * dm_ctr_fn ) ( struct dm_target * target , unsigned int argc , char * * argv ) ;
typedef void ( * dm_dtr_fn ) ( struct dm_target * ti ) ;
typedef int ( * dm_map_fn ) ( struct dm_target * ti , struct bio * bio , union map_info * map_context ) ;
typedef int ( * dm_map_request_fn ) ( struct dm_target * ti , struct request * clone , union map_info * map_context ) ;
typedef int ( * dm_request_endio_fn ) ( struct dm_target * ti , struct request * clone , int error , union map_info * map_context ) ;
typedef void ( * dm_flush_fn ) ( struct dm_target * ti ) ;
typedef void ( * dm_presuspend_fn ) ( struct dm_target * ti ) ;
typedef void ( * dm_resume_fn ) ( struct dm_target * ti ) ;
typedef int ( * dm_status_fn ) ( struct dm_target * ti , status_type_t status_type , char * result , unsigned int maxlen ) ;
typedef int ( * dm_message_fn ) ( struct dm_target * ti , unsigned argc , char * * argv ) ;
typedef int ( * dm_ioctl_fn ) ( struct dm_target * ti , unsigned int cmd , unsigned long arg ) ;
typedef int ( * dm_busy_fn ) ( struct dm_target * ti ) ;
typedef int ( * dm_merge_fn ) ( struct dm_target * ti , struct bvec_merge_data * bvm , struct bio_vec * biovec , int max_size ) ;
typedef int ( * iterate_devices_callout_fn ) ( struct dm_target * ti , struct dm_dev * dev , sector_t start , sector_t len , void * data ) ;
typedef int ( * dm_iterate_devices_fn ) ( struct dm_target * ti , iterate_devices_callout_fn fn , void * data ) ;
typedef void ( * dm_io_hints_fn ) ( struct dm_target * ti , struct queue_limits * limits ) ;
typedef int ( * dm_endio_fn ) ( struct dm_target * ti , struct bio * bio , int error , union map_info * map_context ) ;
typedef int ( * dm_preresume_fn ) ( struct dm_target * ti ) ;
typedef void ( * dm_postsuspend_fn ) ( struct dm_target * ti ) ;

struct target_type {
	uint64_t features ;
	const char * name ;
	struct module * module ;
	unsigned version [ 3 ] ;
	dm_ctr_fn ctr ;
	dm_dtr_fn dtr ;
	dm_map_fn map ;
	dm_map_request_fn map_rq ; dm_endio_fn end_io ; dm_request_endio_fn rq_end_io ;
	dm_flush_fn flush ; dm_presuspend_fn presuspend ; dm_postsuspend_fn postsuspend ; dm_preresume_fn preresume ;
	dm_resume_fn resume ; dm_status_fn status ; dm_message_fn message ; dm_ioctl_fn ioctl ; dm_merge_fn merge ; dm_busy_fn busy ;
	dm_iterate_devices_fn iterate_devices ; dm_io_hints_fn io_hints ;
	struct list_head list ; } ;




struct file_system_type {
	const char * name ;
	int fs_flags ;
	struct dentry * ( * mount ) ( struct file_system_type * , int , const char * , void * ) ;
	void ( * kill_sb ) ( struct super_block * ) ;
	struct module * owner ;
	struct file_system_type * next ;
	struct list_head fs_supers ;
	struct lock_class_key s_lock_key ;
	struct lock_class_key s_umount_key ;
	struct lock_class_key s_vfs_rename_key ;
	struct lock_class_key i_lock_key ;
	struct lock_class_key i_mutex_key ;
	struct lock_class_key i_mutex_dir_key ;
};

struct kmem_cache_order_objects { unsigned long x ; } ;
struct kref { atomic_t refcount ; } ;
struct kobject { const char * name ; struct list_head entry ; struct kobject * parent ; struct kset * kset ; struct kobj_type * ktype ; struct sysfs_dirent * sd ; struct kref kref ; unsigned int state_initialized : 1 ; unsigned int state_in_sysfs : 1 ; unsigned int state_add_uevent_sent : 1 ; unsigned int state_remove_uevent_sent : 1 ; unsigned int uevent_suppress : 1 ; } ;

struct kmem_cache {
	struct kmem_cache_cpu * cpu_slab ; unsigned long flags ;
	unsigned long min_partial ; int size ; int objsize ; int offset ; int cpu_partial ;
	struct kmem_cache_order_objects oo ; struct kmem_cache_order_objects max ;
	struct kmem_cache_order_objects min ; gfp_t allocflags ; int refcount ;
	void ( * ctor ) ( void * ) ; int inuse ; int align ; int reserved ; const char * name ;
	struct list_head list ; struct kobject kobj ; int remote_node_defrag_ratio ;
	struct kmem_cache_node * node [ ( 1 << 6 ) ] ; } ;


extern int register_filesystem ( struct file_system_type * ) ;
extern int unregister_filesystem ( struct file_system_type * ) ;
extern int dm_register_target ( struct target_type * tt ) ;



extern void * __kmalloc ( size_t size , gfp_t flags );
extern void* kfree ( void* x );


fmode_t dm_table_get_mode(struct dm_table *t);
void dm_unregister_target(struct target_type *t);
extern int core_kernel_text ( unsigned long addr ) ;
extern int core_kernel_data ( unsigned long addr ) ;
extern int __kernel_text_address ( unsigned long addr ) ;
extern int kernel_text_address ( unsigned long addr ) ;
extern int func_ptr_is_kernel_text ( void * ptr ) ;

extern void posix_acl_init ( struct posix_acl * , int ) ;
extern struct posix_acl * posix_acl_alloc ( int , gfp_t ) ;
extern int posix_acl_valid ( const struct posix_acl * ) ;
extern int posix_acl_permission ( struct inode * , const struct posix_acl * , int ) ;
extern struct posix_acl * posix_acl_from_mode ( umode_t , gfp_t ) ;
extern int posix_acl_equiv_mode ( const struct posix_acl * , umode_t * ) ;
extern int posix_acl_create ( struct posix_acl * * , gfp_t , umode_t * ) ;
extern int posix_acl_chmod ( struct posix_acl * * , gfp_t , umode_t ) ;
extern struct posix_acl * get_posix_acl ( struct inode * , int ) ;
extern int set_posix_acl ( struct inode * , int , struct posix_acl * ) ;
extern struct posix_acl *posix_acl_from_xattr(const void *value, size_t size);
extern int posix_acl_to_xattr(const struct posix_acl *acl, void *buffer, size_t size);

extern int current_umask(void);

int security_inode_init_security ( struct inode * inode , struct inode * dir ,
		const struct qstr * qstr , initxattrs initxattrs , void * fs_data ) ;


typedef int (get_block_t)(struct inode *inode, sector_t iblock,
		struct buffer_head *bh_result, int create);
typedef void (dio_iodone_t)(struct kiocb *iocb, loff_t offset,
		ssize_t bytes, void *private_data, int ret,
		bool is_async);
typedef void (dio_submit_t)(int rw, struct bio *bio, struct inode *inode,
                             loff_t file_offset);
typedef int ( * filldir_t ) ( void * , const char * , int , loff_t , u64 , unsigned ) ;

extern int generic_file_open ( struct inode * inode , struct file * filp ) ;
extern int nonseekable_open ( struct inode * inode , struct file * filp ) ;
void dio_end_io ( struct bio * bio , int error ) ;
void inode_dio_wait ( struct inode * inode ) ;
void inode_dio_done ( struct inode * inode ) ;
ssize_t __blockdev_direct_IO ( int rw , struct kiocb * iocb , struct inode * inode ,
		struct block_device * bdev , const struct iovec * iov , loff_t offset , unsigned long nr_segs , get_block_t get_block , dio_iodone_t end_io , dio_submit_t submit_io , int flags ) ;
extern int vfs_readlink ( struct dentry * , char * , int , const char * ) ;
extern int vfs_follow_link ( struct nameidata * , const char * ) ;
extern int page_readlink ( struct dentry * , char * , int ) ;
extern void * page_follow_link_light ( struct dentry * , struct nameidata * ) ;
extern void page_put_link ( struct dentry * , struct nameidata * , void * ) ;
extern int __page_symlink ( struct inode * inode , const char * symname , int len , int nofs ) ;
extern int page_symlink ( struct inode * inode , const char * symname , int len ) ;
extern int generic_readlink ( struct dentry * , char * , int ) ;
extern void generic_fillattr ( struct inode * , struct kstat * ) ;
extern int vfs_getattr ( struct vfsmount * , struct dentry * , struct kstat * ) ;
void __inode_add_bytes ( struct inode * inode , loff_t bytes ) ;
void inode_add_bytes ( struct inode * inode , loff_t bytes ) ;
void inode_sub_bytes ( struct inode * inode , loff_t bytes ) ;
loff_t inode_get_bytes ( struct inode * inode ) ;
void inode_set_bytes ( struct inode * inode , loff_t bytes ) ;
extern int vfs_readdir ( struct file * , filldir_t , void * ) ;
extern int vfs_stat ( const char * , struct kstat * ) ;
extern int vfs_lstat ( const char * , struct kstat * ) ;
extern int vfs_fstat ( unsigned int , struct kstat * ) ;
extern int vfs_fstatat ( int , const char * , struct kstat * , int ) ;
extern int do_vfs_ioctl ( struct file * filp , unsigned int fd , unsigned int cmd , unsigned long arg ) ;
extern int __generic_block_fiemap ( struct inode * inode , struct fiemap_extent_info * fieinfo , loff_t start , loff_t len , get_block_t * get_block ) ;
extern int generic_block_fiemap ( struct inode * inode , struct fiemap_extent_info * fieinfo , u64 start , u64 len , get_block_t * get_block ) ;
extern void get_filesystem ( struct file_system_type * fs ) ;
extern void put_filesystem ( struct file_system_type * fs ) ;
extern struct file_system_type * get_fs_type ( const char * name ) ;
extern struct super_block * get_super ( struct block_device * ) ;
extern struct super_block * get_active_super ( struct block_device * bdev ) ;


extern void 	blk_put_queue ( struct request_queue * ) ;
extern void 	blk_start_plug ( struct blk_plug * ) ;
extern void 	blk_finish_plug ( struct blk_plug * ) ;
extern void 	blk_flush_plug_list ( struct blk_plug * , bool ) ;
extern int 		blk_queue_start_tag ( struct request_queue * , struct request * ) ;
extern struct request * blk_queue_find_tag ( struct request_queue * , int ) ;
extern void 	blk_queue_end_tag ( struct request_queue * , struct request * ) ;
extern int 		blk_queue_init_tags ( struct request_queue * , int , struct blk_queue_tag * ) ;
extern void 	blk_queue_free_tags ( struct request_queue * ) ;
extern int 		blk_queue_resize_tags ( struct request_queue * , int ) ;
extern void 	blk_queue_invalidate_tags ( struct request_queue * ) ;
extern struct blk_queue_tag * blk_init_tags ( int ) ;
extern void 	blk_free_tags ( struct blk_queue_tag * ) ;
extern bool 	blk_integrity_is_initialized ( struct gendisk * ) ;
extern int 		blk_integrity_register ( struct gendisk * , struct blk_integrity * ) ;
extern void 	blk_integrity_unregister ( struct gendisk * ) ;
extern int 		blk_integrity_compare ( struct gendisk * , struct gendisk * ) ;
extern int 		blk_rq_map_integrity_sg ( struct request_queue * , struct bio * , struct scatterlist * ) ;
extern int 		blk_rq_count_integrity_sg ( struct request_queue * , struct bio * ) ;
extern int 		blk_integrity_merge_rq ( struct request_queue * , struct request * , struct request * ) ;
extern int 		blk_integrity_merge_bio ( struct request_queue * , struct request * , struct bio * ) ;


typedef u32 __ticketpair_t ;
typedef u16 __ticket_t ;
typedef struct { unsigned long fds_bits [ ( 1024 / ( 8 * sizeof ( unsigned long ) ) ) ] ; } __kernel_fd_set ;

typedef struct arch_spinlock { union { __ticketpair_t head_tail ; struct { __ticket_t head , tail ; } tickets ; } ; } arch_spinlock_t ;
typedef struct raw_spinlock { arch_spinlock_t raw_lock ; } raw_spinlock_t ;
typedef struct spinlock { union { struct raw_spinlock rlock ; } ; } spinlock_t ;
struct timespec { __kernel_time_t tv_sec ; long tv_nsec ; } ;
struct timeval { __kernel_time_t tv_sec ; __kernel_suseconds_t tv_usec ; } ;
typedef __kernel_fd_set fd_set ;
typedef __kernel_dev_t dev_t ;
typedef __kernel_uid32_t uid_t ;
typedef __kernel_gid32_t gid_t ;
struct mutex { atomic_t count ; spinlock_t wait_lock ; struct list_head wait_list ; struct task_struct * owner ; } ;
struct rcu_head { struct rcu_head * next ; void ( * func ) ( struct rcu_head * head ) ; } ;
struct prio_tree_root { struct prio_tree_node * prio_tree_node ; unsigned short index_bits ; unsigned short raw ; } ;
struct radix_tree_root { unsigned int height ; gfp_t gfp_mask ; struct radix_tree_node * rnode ; } ;
struct address_space { struct inode * host ; struct radix_tree_root page_tree ;
spinlock_t tree_lock ; unsigned int i_mmap_writable ; struct prio_tree_root i_mmap ;
struct list_head i_mmap_nonlinear ; struct mutex i_mmap_mutex ; unsigned long nrpages ; unsigned long writeback_index ; const struct address_space_operations * a_ops ; unsigned long flags ; struct backing_dev_info * backing_dev_info ; spinlock_t private_lock ; struct list_head private_list ; struct address_space * assoc_mapping ; } __attribute__ ( ( aligned ( sizeof ( long ) ) ) ) ;

struct inode { umode_t i_mode ; unsigned short i_opflags ; uid_t i_uid ; gid_t i_gid ;
unsigned int i_flags ; struct posix_acl * i_acl ; struct posix_acl * i_default_acl ;
const struct inode_operations * i_op ; struct super_block * i_sb ; struct address_space * i_mapping ;
void * i_security ; unsigned long i_ino ; union { const unsigned int i_nlink ; unsigned int __i_nlink ; } ;
dev_t i_rdev ;
struct timespec i_atime ;
struct timespec i_mtime ;
struct timespec i_ctime ;
spinlock_t i_lock ; unsigned short i_bytes ; blkcnt_t i_blocks ; loff_t i_size ; unsigned long i_state ;
struct mutex i_mutex ; unsigned long dirtied_when ; struct hlist_node i_hash ; struct list_head i_wb_list ; struct list_head i_lru ;
struct list_head i_sb_list ; union { struct list_head i_dentry ; struct rcu_head i_rcu ; } ;
atomic_t i_count ; unsigned int i_blkbits ; u64 i_version ; atomic_t i_dio_count ;
atomic_t i_writecount ; const struct file_operations * i_fop ;
struct file_lock * i_flock ; struct address_space i_data ; struct dquot * i_dquot [ 2 ] ;
struct list_head i_devices ;
union { struct pipe_inode_info * i_pipe ; struct block_device * i_bdev ; struct cdev * i_cdev ; } ;
__u32 i_generation ; __u32 i_fsnotify_mask ; struct hlist_head i_fsnotify_marks ; void * i_private ; } ;

struct kmem_cache * kmem_cache_create ( const char * , size_t , size_t , unsigned long , void ( * ) ( void * ) ) ;
void kmem_cache_destroy ( struct kmem_cache * ) ;
int kmem_cache_shrink ( struct kmem_cache * ) ;
void kmem_cache_free ( struct kmem_cache * , void * ) ;
unsigned int kmem_cache_size ( struct kmem_cache * ) ;


struct buffer_head * __find_get_block ( struct block_device * bdev , sector_t block , unsigned size ) ;
struct buffer_head * __getblk ( struct block_device * bdev , sector_t block , unsigned size ) ;
void __brelse ( struct buffer_head * ) ;
void __bforget ( struct buffer_head * ) ;
void __breadahead ( struct block_device * , sector_t block , unsigned int size ) ;
struct buffer_head * __bread ( struct block_device * , sector_t block , unsigned size ) ;

extern void get_random_bytes ( void * buf , int nbytes ) ;
extern void get_random_bytes_arch ( void * buf , int nbytes ) ;


extern void _raw_spin_lock ( raw_spinlock_t * lock ) ;
extern int _cond_resched ( void ) ;
extern int __cond_resched_lock ( spinlock_t * lock ) ;
extern int __cond_resched_softirq ( void ) ;
void io_schedule ( void ) ;
long io_schedule_timeout ( long timeout ) ;

extern void inode_sb_list_add ( struct inode * inode ) ;
extern void submit_bio ( int , struct bio * ) ;

typedef atomic64_t atomic_long_t ;
typedef union { s32 lock ; s32 write ; } arch_rwlock_t ;
struct __wait_queue_head { spinlock_t lock ; struct list_head task_list ; } ;
typedef struct __wait_queue_head wait_queue_head_t ;

extern void __wake_up ( wait_queue_head_t * q , unsigned int mode , int nr , void * key ) ;
void __wake_up_locked_key ( wait_queue_head_t * q , unsigned int mode , void * key ) ;
void __wake_up_sync_key ( wait_queue_head_t * q , unsigned int mode , int nr , void * key ) ;
void __wake_up_locked ( wait_queue_head_t * q , unsigned int mode ) ;
void __wake_up_sync ( wait_queue_head_t * q , unsigned int mode , int nr ) ;
void __wake_up_bit ( wait_queue_head_t * , void * , int ) ;
int __wait_on_bit ( wait_queue_head_t * , struct wait_bit_queue * , int ( * ) ( void * ) , unsigned ) ;
int __wait_on_bit_lock ( wait_queue_head_t * , struct wait_bit_queue * , int ( * ) ( void * ) , unsigned ) ;
void wake_up_bit ( void * , int ) ;
int out_of_line_wait_on_bit ( void * , int , int ( * ) ( void * ) , unsigned ) ;
int out_of_line_wait_on_bit_lock ( void * , int , int ( * ) ( void * ) , unsigned ) ;

extern bool flush_work ( struct work_struct * work ) ;
extern bool flush_work_sync ( struct work_struct * work ) ;
extern bool cancel_work_sync ( struct work_struct * work ) ;
extern bool flush_delayed_work ( struct delayed_work * dwork ) ;
extern bool flush_delayed_work_sync ( struct delayed_work * work ) ;
extern bool cancel_delayed_work_sync ( struct delayed_work * dwork ) ;

typedef struct { unsigned long bits [ ( ( ( ( 1 << 6 ) ) + ( 8 * sizeof ( long ) ) - 1 ) / ( 8 * sizeof ( long ) ) ) ] ; } nodemask_t ;
extern unsigned long __phys_addr ( unsigned long ) ;

struct workqueue_struct { struct cpu_workqueue_struct * cpu_wq ; struct list_head list ; const char * name ; int singlethread ; int freezeable ; int rt ; } ;

extern void destroy_workqueue ( struct workqueue_struct * wq ) ;
extern int queue_work ( struct workqueue_struct * wq , struct work_struct * work ) ;
extern int queue_work_on ( int cpu , struct workqueue_struct * wq , struct work_struct * work ) ;
extern int queue_delayed_work ( struct workqueue_struct * wq , struct delayed_work * work , unsigned long delay ) ;
extern int queue_delayed_work_on ( int cpu , struct workqueue_struct * wq , struct delayed_work * work , unsigned long delay ) ;

struct page * __alloc_pages_nodemask ( gfp_t gfp_mask , unsigned int order , struct zonelist * zonelist , nodemask_t * nodemask ) ;
extern struct page * alloc_pages_current ( gfp_t gfp_mask , unsigned order ) ;
extern struct page * alloc_pages_vma ( gfp_t gfp_mask , int order , struct vm_area_struct * vma , unsigned long addr , int node ) ;
extern unsigned long __get_free_pages ( gfp_t gfp_mask , unsigned int order ) ;
extern unsigned long get_zeroed_page ( gfp_t gfp_mask ) ;
void * alloc_pages_exact ( size_t size , gfp_t gfp_mask ) ;
void free_pages_exact ( void * virt , size_t size ) ;
void * alloc_pages_exact_nid ( int nid , size_t size , gfp_t gfp_mask ) ;
extern void __free_pages ( struct page * page , unsigned int order ) ;
extern void free_pages ( unsigned long addr , unsigned int order ) ;
extern void free_hot_cold_page ( struct page * page , int cold ) ;
void page_alloc_init ( void ) ;

typedef unsigned long pgprotval_t ;
typedef struct pgprot { pgprotval_t pgprot ; } pgprot_t ;

extern void * vmalloc ( unsigned long size ) ;
extern void * vzalloc ( unsigned long size ) ;
extern void * __vmalloc ( unsigned long size , gfp_t gfp_mask , pgprot_t prot ) ;
extern void * __vmalloc_node_range ( unsigned long size , unsigned long align , unsigned long start , unsigned long end , gfp_t gfp_mask , pgprot_t prot , int node , void * caller ) ;
extern void vfree ( const void * addr ) ;

typedef struct __wait_queue wait_queue_t ;
typedef int ( * wait_queue_func_t ) ( wait_queue_t * wait , unsigned mode , int flags , void * key ) ;
struct __wait_queue { unsigned int flags ; void * private_ ; wait_queue_func_t func ; struct list_head task_list ; } ;


int default_wake_function ( wait_queue_t * wait , unsigned mode , int flags , void * key ) ;
extern void __init_waitqueue_head ( wait_queue_head_t * q , struct lock_class_key * ) ;
extern void add_wait_queue ( wait_queue_head_t * q , wait_queue_t * wait ) ;
extern void remove_wait_queue ( wait_queue_head_t * q , wait_queue_t * wait ) ;


extern struct workqueue_struct * __alloc_workqueue_key ( const char * name , unsigned int flags , int max_active , struct lock_class_key * key , const char * lock_name ) ;
void init_timer_key ( struct timer_list * timer , const char * name , struct lock_class_key * key ) ;


extern struct bio * bio_alloc ( gfp_t , unsigned int ) ;
extern struct bio * bio_kmalloc ( gfp_t , unsigned int ) ;
extern struct bio * bio_alloc_bioset ( gfp_t , int , struct bio_set * ) ;
extern void bio_put ( struct bio * ) ;
extern void bio_free ( struct bio * , struct bio_set * ) ;
extern void bio_endio ( struct bio * , int ) ;
extern int bio_phys_segments ( struct request_queue * , struct bio * ) ;
extern void __bio_clone ( struct bio * , struct bio * ) ;
extern struct bio * bio_clone ( struct bio * , gfp_t ) ;
extern void bio_init ( struct bio * ) ;
extern int bio_add_page ( struct bio * , struct page * , unsigned int , unsigned int ) ;


/**************************************************************************
 *  mb_cache
 *  **************************************************************************/

struct mb_cache_entry {
	struct list_head                e_lru_list;
	struct mb_cache                 *e_cache;
	unsigned short                  e_used;
	unsigned short                  e_queued;
	struct block_device             *e_bdev;
	sector_t                        e_block;
	struct list_head                e_block_list;
	struct {
		struct list_head        o_list;
		unsigned int            o_key;
	} e_index;
};

struct mb_cache {
	struct list_head                c_cache_list;
	const char                      *c_name;
	atomic_t                        c_entry_count;
	int                             c_max_entries;
	int                             c_bucket_bits;
	struct kmem_cache               *c_entry_cache;
	struct list_head                *c_block_hash;
	struct list_head                *c_index_hash;
};

/* Functions on caches */

struct mb_cache *mb_cache_create(const char *, int);
void mb_cache_shrink(struct block_device *);
void mb_cache_destroy(struct mb_cache *);

/* Functions on cache entries */

struct mb_cache_entry *mb_cache_entry_alloc(struct mb_cache *, gfp_t);
int mb_cache_entry_insert(struct mb_cache_entry *, struct block_device *,
		sector_t, unsigned int);
void mb_cache_entry_release(struct mb_cache_entry *);
void mb_cache_entry_free(struct mb_cache_entry *);
struct mb_cache_entry *mb_cache_entry_get(struct mb_cache *,
		struct block_device *,
		sector_t);
struct mb_cache_entry *mb_cache_entry_find_first(struct mb_cache *cache,
		struct block_device *,
		unsigned int);
struct mb_cache_entry *mb_cache_entry_find_next(struct mb_cache_entry *,
		struct block_device *,
		unsigned int);

extern int sb_set_blocksize ( struct super_block * , int ) ;
extern int sb_min_blocksize ( struct super_block * , int ) ;



extern struct vfsmount * mntget ( struct vfsmount * mnt ) ;
extern int mnt_want_write ( struct vfsmount * mnt ) ;
extern int mnt_want_write_file ( struct file * file ) ;
extern int mnt_clone_write ( struct vfsmount * mnt ) ;
extern void mnt_drop_write ( struct vfsmount * mnt ) ;
extern void mntput ( struct vfsmount * mnt ) ;
extern void mnt_pin ( struct vfsmount * mnt ) ;
extern void mnt_unpin ( struct vfsmount * mnt ) ;
extern int __mnt_is_readonly ( struct vfsmount * mnt ) ;

extern struct dentry * mount_ns ( struct file_system_type * fs_type , int flags , void * data , int ( * fill_super ) ( struct super_block * , void * , int ) ) ;
extern struct dentry * mount_bdev ( struct file_system_type * fs_type , int flags , const char * dev_name , void * data , int ( * fill_super ) ( struct super_block * , void * , int ) ) ;
extern struct dentry * mount_single ( struct file_system_type * fs_type , int flags , void * data , int ( * fill_super ) ( struct super_block * , void * , int ) ) ;
extern struct dentry * mount_nodev ( struct file_system_type * fs_type , int flags , void * data , int ( * fill_super ) ( struct super_block * , void * , int ) ) ;
extern struct dentry * mount_subtree ( struct vfsmount * mnt , const char * path ) ;


struct dquot_operations {
	int ( * write_dquot ) ( struct dquot * ) ;
	struct dquot * ( * alloc_dquot ) ( struct super_block * , int ) ;
	void ( * destroy_dquot ) ( struct dquot * ) ;
	int ( * acquire_dquot ) ( struct dquot * ) ;
	int ( * release_dquot ) ( struct dquot * ) ;
	int ( * mark_dirty ) ( struct dquot * ) ;
	int ( * write_info ) ( struct super_block * , int ) ;
	qsize_t * ( * get_reserved_space ) ( struct inode * ) ;
};

struct dquot *dquot_alloc(struct super_block *sb, int type);
void dquot_destroy(struct dquot *dquot);
int dquot_alloc_inode(const struct inode *inode);
int dquot_resume(struct super_block *sb, int type);
int dquot_commit(struct dquot *dquot);
int dquot_acquire(struct dquot *dquot);
int dquot_release(struct dquot *dquot);
int dquot_commit_info(struct super_block *sb, int type);
int dquot_mark_dquot_dirty(struct dquot *dquot);
int dquot_file_open(struct inode *inode, struct file *file);
int dquot_enable(struct inode *inode, int type, int format_id,
		unsigned int flags);
int dquot_quota_on(struct super_block *sb, int type, int format_id,
		struct path *path);
int dquot_quota_on_mount(struct super_block *sb, char *qf_name,
		int format_id, int type);
int dquot_quota_off(struct super_block *sb, int type);
int dquot_quota_sync(struct super_block *sb, int type, int wait);
int dquot_get_dqinfo(struct super_block *sb, int type, struct if_dqinfo *ii);
int dquot_set_dqinfo(struct super_block *sb, int type, struct if_dqinfo *ii);
int dquot_get_dqblk(struct super_block *sb, int type, qid_t id,
		struct fs_disk_quota *di);
int dquot_set_dqblk(struct super_block *sb, int type, qid_t id,
		struct fs_disk_quota *di);


typedef unsigned char BOOLEAN ;
typedef unsigned char UINT8 ;
typedef unsigned short UINT16 ;
typedef unsigned long long UINT64 ;
typedef long long INT64 ;
typedef unsigned int UINT32 ;
typedef int INT32 ;
typedef char * acpi_string ;
typedef void * acpi_handle ;
typedef char acpi_bus_id [ 8 ] ;
typedef unsigned long acpi_bus_address ;
typedef char acpi_device_name [ 40 ] ;
typedef char acpi_device_class [ 20 ] ;
typedef void * acpi_handle ;
typedef char * acpi_string ;
typedef u64 acpi_physical_address ;
typedef s64 acpi_native_int ;
typedef u64 acpi_size ;
typedef u64 acpi_io_address ;
typedef u64 acpi_physical_address ;
typedef u32 acpi_status ;
typedef u32 acpi_name ;
typedef u8 acpi_owner_id ;
typedef u64 acpi_integer ;
typedef u32 acpi_object_type ;
typedef u32 acpi_event_type ;
typedef u32 acpi_event_status ;
typedef u8 acpi_adr_space_type ;
struct acpi_object_list { u32 count ; union acpi_object * pointer ; } ;
struct acpi_predefined_names { char * name ; u8 type ; char * val ; } ;
struct acpi_system_info { u32 acpi_ca_version ; u32 flags ; u32 timer_resolution ; u32 reserved1 ; u32 reserved2 ; u32 debug_level ; u32 debug_layer ; } ;
typedef void ( * acpi_osd_exec_callback ) ( void * context ) ;
struct acpica_device_id { u32 length ; char * string ; } ;
struct acpi_pci_id { u16 segment ; u16 bus ; u16 device ; u16 function ; } ;
struct acpi_memory_list { char * list_name ; void * list_head ; u16 object_size ; u16 max_depth ; u16 current_depth ; u16 link_offset ; } ;
struct acpi_table_header { char signature [ 4 ] ; u32 length ; u8 revision ; u8 checksum ; char oem_id [ 6 ] ; char oem_table_id [ 8 ] ; u32 oem_revision ; char asl_compiler_id [ 4 ] ; u32 asl_compiler_revision ; } ;
struct acpi_generic_address { u8 space_id ; u8 bit_width ; u8 bit_offset ; u8 access_width ; u64 address ; } ;
struct acpi_table_rsdp { char signature [ 8 ] ; u8 checksum ; char oem_id [ 6 ] ; u8 revision ; u32 rsdt_physical_address ; u32 length ; u64 xsdt_physical_address ; u8 extended_checksum ; u8 reserved [ 3 ] ; } ;
struct acpi_table_facs { char signature [ 4 ] ; u32 length ; u32 hardware_signature ; u32 firmware_waking_vector ; u32 global_lock ; u32 flags ; u64 xfirmware_waking_vector ; u8 version ; u8 reserved [ 3 ] ; u32 ospm_flags ; u8 reserved1 [ 24 ] ; } ;
union acpi_name_union { u32 integer ; char ascii [ 4 ] ; } ;
struct acpi_subtable_header { u8 type ; u8 length ; } ;
struct acpi_bert_region { u32 block_status ; u32 raw_data_offset ; u32 raw_data_length ; u32 data_length ; u32 error_severity ; } ;
struct acpi_einj_trigger { u32 header_size ; u32 revision ; u32 table_size ; u32 entry_count ; } ;
struct acpi_erst_info { u16 signature ; u8 data [ 48 ] ; } ;
struct acpi_hest_header { u16 type ; u16 source_id ; } ;
struct acpi_hest_ia_error_bank { u8 bank_number ; u8 clear_status_on_init ; u8 status_format ; u8 reserved ; u32 control_register ; u64 control_data ; u32 status_register ; u32 address_register ; u32 misc_register ; } ;
struct acpi_hest_aer_common { u16 reserved1 ; u8 flags ; u8 enabled ; u32 records_to_preallocate ; u32 max_sections_per_record ; u32 bus ; u16 device ; u16 function ; u16 device_control ; u16 reserved2 ; u32 uncorrectable_mask ; u32 uncorrectable_severity ; u32 correctable_mask ; u32 advanced_capabilities ; } ;
struct acpi_hest_notify { u8 type ; u8 length ; u16 config_write_enable ; u32 poll_interval ; u32 vector ; u32 polling_threshold_value ; u32 polling_threshold_window ; u32 error_threshold_value ; u32 error_threshold_window ; } ;
struct acpi_hest_generic_status { u32 block_status ; u32 raw_data_offset ; u32 raw_data_length ; u32 data_length ; u32 error_severity ; } ;
struct acpi_hest_generic_data { u8 section_type [ 16 ] ; u32 error_severity ; u16 revision ; u8 validation_bits ; u8 flags ; u32 error_data_length ; u8 fru_id [ 16 ] ; u8 fru_text [ 20 ] ; } ;
struct acpi_msct_proximity { u8 revision ; u8 length ; u32 range_start ; u32 range_end ; u32 processor_capacity ; u64 memory_capacity ; } ;
struct acpi_asf_header { u8 type ; u8 reserved ; u16 length ; } ;
struct acpi_asf_alert_data { u8 address ; u8 command ; u8 mask ; u8 value ; u8 sensor_type ; u8 type ; u8 offset ; u8 source_type ; u8 severity ; u8 sensor_number ; u8 entity ; u8 instance ; } ;
struct acpi_asf_control_data { u8 function ; u8 address ; u8 command ; u8 value ; } ;
struct acpi_dmar_header { u16 type ; u16 length ; } ;
struct acpi_dmar_device_scope { u8 entry_type ; u8 length ; u16 reserved ; u8 enumeration_id ; u8 bus ; } ;
struct acpi_dmar_pci_path { u8 dev ; u8 fn ; } ;
struct acpi_ibft_header { u8 type ; u8 version ; u16 length ; u8 index ; u8 flags ; } ;
struct acpi_ivrs_header { u8 type ; u8 flags ; u16 length ; u16 device_id ; } ;
struct acpi_ivrs_de_header { u8 type ; u16 id ; u8 data_setting ; } ;
struct acpi_mcfg_allocation { u64 address ; u16 pci_segment ; u8 start_bus_number ; u8 end_bus_number ; u32 reserved ; } ;
struct acpi_slic_header { u32 type ; u32 length ; } ;
typedef u16 acpi_rs_length ;
typedef u32 acpi_rsdesc_size ;
struct acpi_uuid { u8 data [ 16 ] ; } ;
struct acpi_vendor_uuid { u8 subtype ; u8 data [ 16 ] ; } ;
struct acpi_resource_irq { u8 descriptor_length ; u8 triggering ; u8 polarity ; u8 sharable ; u8 interrupt_count ; u8 interrupts [ 1 ] ; } ;
struct acpi_resource_dma { u8 type ; u8 bus_master ; u8 transfer ; u8 channel_count ; u8 channels [ 1 ] ; } ;
struct acpi_resource_start_dependent { u8 descriptor_length ; u8 compatibility_priority ; u8 performance_robustness ; } ;
struct acpi_resource_io { u8 io_decode ; u8 alignment ; u8 address_length ; u16 minimum ; u16 maximum ; } ;
struct acpi_resource_fixed_io { u16 address ; u8 address_length ; } ;
struct acpi_resource_vendor { u16 byte_length ; u8 byte_data [ 1 ] ; } ;
struct acpi_resource_vendor_typed { u16 byte_length ; u8 uuid_subtype ; u8 uuid [ 16 ] ; u8 byte_data [ 1 ] ; } ;
struct acpi_resource_end_tag { u8 checksum ; } ;
struct acpi_resource_memory24 { u8 write_protect ; u16 minimum ; u16 maximum ; u16 alignment ; u16 address_length ; } ;
struct acpi_resource_memory32 { u8 write_protect ; u32 minimum ; u32 maximum ; u32 alignment ; u32 address_length ; } ;
struct acpi_resource_fixed_memory32 { u8 write_protect ; u32 address ; u32 address_length ; } ;
struct acpi_memory_attribute { u8 write_protect ; u8 caching ; u8 range_type ; u8 translation ; } ;
struct acpi_io_attribute { u8 range_type ; u8 translation ; u8 translation_type ; u8 reserved1 ; } ;
struct acpi_resource_source { u8 index ; u16 string_length ; char * string_ptr ; } ;
struct acpi_resource_generic_register { u8 space_id ; u8 bit_width ; u8 bit_offset ; u8 access_size ; u64 address ; } ;
struct acpi_pci_routing_table { u32 length ; u32 pin ; u64 address ; u32 source_index ; char source [ 4 ] ; } ;
struct acpi_signal_fatal_info { u32 type ; u32 code ; u32 argument ; } ;
struct acpi_handle_list { u32 count ; acpi_handle handles [ 10 ] ; } ;
typedef int ( * acpi_op_add ) ( struct acpi_device * device ) ;
typedef int ( * acpi_op_remove ) ( struct acpi_device * device , int type ) ;
typedef int ( * acpi_op_start ) ( struct acpi_device * device ) ;
typedef int ( * acpi_op_resume ) ( struct acpi_device * device ) ;
typedef int ( * acpi_op_bind ) ( struct acpi_device * device ) ;
typedef int ( * acpi_op_unbind ) ( struct acpi_device * device ) ;
struct acpi_device_status { u32 present : 1 ; u32 enabled : 1 ; u32 show_in_ui : 1 ; u32 functional : 1 ; u32 battery_present : 1 ; u32 reserved : 27 ; } ;
struct acpi_device_flags { u32 dynamic_status : 1 ; u32 bus_address : 1 ; u32 removable : 1 ; u32 ejectable : 1 ; u32 lockable : 1 ; u32 suprise_removal_ok : 1 ; u32 power_manageable : 1 ; u32 performance_manageable : 1 ; u32 reserved : 24 ; } ;
struct acpi_device_pnp { acpi_bus_id bus_id ; acpi_bus_address bus_address ; char * unique_id ; struct list_head ids ; acpi_device_name device_name ; acpi_device_class device_class ; } ;
struct acpi_device_power_flags { u32 explicit_get : 1 ; u32 power_resources : 1 ; u32 inrush_current : 1 ; u32 power_removed : 1 ; u32 reserved : 28 ; } ;
struct acpi_device_perf_flags { u8 reserved : 8 ; } ;
struct acpi_device_wakeup_flags { u8 valid : 1 ; u8 run_wake : 1 ; u8 notifier_present : 1 ; } ;
struct acpi_bus_event { struct list_head node ; acpi_device_class device_class ; acpi_bus_id bus_id ; u32 type ; u32 data ; } ;
typedef int ( * acpi_table_handler ) ( struct acpi_table_header * table ) ;
typedef int ( * acpi_table_entry_handler ) ( struct acpi_subtable_header * header , const unsigned long end ) ;
struct acpi_buffer { acpi_size length ; void * pointer ; } ;
typedef u32 ( * acpi_osd_handler ) ( void * context ) ;
typedef void ( * ACPI_GBL_EVENT_HANDLER ) ( u32 event_type , acpi_handle device , u32 event_number , void * context ) ;
typedef u32 ( * acpi_event_handler ) ( void * context ) ;
typedef u32 ( * acpi_gpe_handler ) ( acpi_handle gpe_device , u32 gpe_number , void * context ) ;
typedef void ( * acpi_notify_handler ) ( acpi_handle device , u32 value , void * context ) ;
typedef void ( * acpi_object_handler ) ( acpi_handle object , void * data ) ;
typedef u32 ( * acpi_interface_handler ) ( acpi_string interface_name , u32 supported ) ;
struct acpica_device_id_list { u32 count ; u32 list_size ; struct acpica_device_id ids [ 1 ] ; } ;
struct acpi_mem_space_context { u32 length ; acpi_physical_address address ; acpi_physical_address mapped_physical_address ; u8 * mapped_logical_address ; acpi_size mapped_length ; } ;
struct acpi_table_rsdt { struct acpi_table_header header ; u32 table_offset_entry [ 1 ] ; } ;
struct acpi_table_xsdt { struct acpi_table_header header ; u64 table_offset_entry [ 1 ] ; } ;
struct acpi_table_fadt { struct acpi_table_header header ; u32 facs ; u32 dsdt ; u8 model ; u8 preferred_profile ; u16 sci_interrupt ; u32 smi_command ; u8 acpi_enable ; u8 acpi_disable ; u8 S4bios_request ; u8 pstate_control ; u32 pm1a_event_block ; u32 pm1b_event_block ; u32 pm1a_control_block ; u32 pm1b_control_block ; u32 pm2_control_block ; u32 pm_timer_block ; u32 gpe0_block ; u32 gpe1_block ; u8 pm1_event_length ; u8 pm1_control_length ; u8 pm2_control_length ; u8 pm_timer_length ; u8 gpe0_block_length ; u8 gpe1_block_length ; u8 gpe1_base ; u8 cst_control ; u16 C2latency ; u16 C3latency ; u16 flush_size ; u16 flush_stride ; u8 duty_offset ; u8 duty_width ; u8 day_alarm ; u8 month_alarm ; u8 century ; u16 boot_flags ; u8 reserved ; u32 flags ; struct acpi_generic_address reset_register ; u8 reset_value ; u8 reserved4 [ 3 ] ; u64 Xfacs ; u64 Xdsdt ; struct acpi_generic_address xpm1a_event_block ; struct acpi_generic_address xpm1b_event_block ; struct acpi_generic_address xpm1a_control_block ; struct acpi_generic_address xpm1b_control_block ; struct acpi_generic_address xpm2_control_block ; struct acpi_generic_address xpm_timer_block ; struct acpi_generic_address xgpe0_block ; struct acpi_generic_address xgpe1_block ; } ;
struct acpi_table_desc { acpi_physical_address address ; struct acpi_table_header * pointer ; u32 length ; union acpi_name_union signature ; acpi_owner_id owner_id ; u8 flags ; } ;
struct acpi_whea_header { u8 action ; u8 instruction ; u8 flags ; u8 reserved ; struct acpi_generic_address register_region ; u64 value ; u64 mask ; } ;
struct acpi_table_bert { struct acpi_table_header header ; u32 region_length ; u64 address ; } ;
struct acpi_table_cpep { struct acpi_table_header header ; u64 reserved ; } ;
struct acpi_cpep_polling { struct acpi_subtable_header header ; u8 id ; u8 eid ; u32 interval ; } ;
struct acpi_table_ecdt { struct acpi_table_header header ; struct acpi_generic_address control ; struct acpi_generic_address data ; u32 uid ; u8 gpe ; u8 id [ 1 ] ; } ;
struct acpi_table_einj { struct acpi_table_header header ; u32 header_length ; u8 flags ; u8 reserved [ 3 ] ; u32 entries ; } ;
struct acpi_table_erst { struct acpi_table_header header ; u32 header_length ; u32 reserved ; u32 entries ; } ;
struct acpi_table_hest { struct acpi_table_header header ; u32 error_source_count ; } ;
struct acpi_hest_ia_machine_check { struct acpi_hest_header header ; u16 reserved1 ; u8 flags ; u8 enabled ; u32 records_to_preallocate ; u32 max_sections_per_record ; u64 global_capability_data ; u64 global_control_data ; u8 num_hardware_banks ; u8 reserved3 [ 7 ] ; } ;
struct acpi_hest_ia_corrected { struct acpi_hest_header header ; u16 reserved1 ; u8 flags ; u8 enabled ; u32 records_to_preallocate ; u32 max_sections_per_record ; struct acpi_hest_notify notify ; u8 num_hardware_banks ; u8 reserved2 [ 3 ] ; } ;
struct acpi_hest_ia_nmi { struct acpi_hest_header header ; u32 reserved ; u32 records_to_preallocate ; u32 max_sections_per_record ; u32 max_raw_data_length ; } ;
struct acpi_hest_aer_root { struct acpi_hest_header header ; struct acpi_hest_aer_common aer ; u32 root_error_command ; } ;
struct acpi_hest_aer { struct acpi_hest_header header ; struct acpi_hest_aer_common aer ; } ;
struct acpi_hest_aer_bridge { struct acpi_hest_header header ; struct acpi_hest_aer_common aer ; u32 uncorrectable_mask2 ; u32 uncorrectable_severity2 ; u32 advanced_capabilities2 ; } ;
struct acpi_hest_generic { struct acpi_hest_header header ; u16 related_source_id ; u8 reserved ; u8 enabled ; u32 records_to_preallocate ; u32 max_sections_per_record ; u32 max_raw_data_length ; struct acpi_generic_address error_status_address ; struct acpi_hest_notify notify ; u32 error_block_length ; } ;
struct acpi_table_madt { struct acpi_table_header header ; u32 address ; u32 flags ; } ;
struct acpi_madt_local_apic { struct acpi_subtable_header header ; u8 processor_id ; u8 id ; u32 lapic_flags ; } ;
struct acpi_madt_io_apic { struct acpi_subtable_header header ; u8 id ; u8 reserved ; u32 address ; u32 global_irq_base ; } ;
struct acpi_madt_interrupt_override { struct acpi_subtable_header header ; u8 bus ; u8 source_irq ; u32 global_irq ; u16 inti_flags ; } ;
struct acpi_madt_nmi_source { struct acpi_subtable_header header ; u16 inti_flags ; u32 global_irq ; } ;
struct acpi_madt_local_apic_nmi { struct acpi_subtable_header header ; u8 processor_id ; u16 inti_flags ; u8 lint ; } ;
struct acpi_madt_local_apic_override { struct acpi_subtable_header header ; u16 reserved ; u64 address ; } ;
struct acpi_madt_io_sapic { struct acpi_subtable_header header ; u8 id ; u8 reserved ; u32 global_irq_base ; u64 address ; } ;
struct acpi_madt_local_sapic { struct acpi_subtable_header header ; u8 processor_id ; u8 id ; u8 eid ; u8 reserved [ 3 ] ; u32 lapic_flags ; u32 uid ; char uid_string [ 1 ] ; } ;
struct acpi_madt_interrupt_source { struct acpi_subtable_header header ; u16 inti_flags ; u8 type ; u8 id ; u8 eid ; u8 io_sapic_vector ; u32 global_irq ; u32 flags ; } ;
struct acpi_madt_local_x2apic { struct acpi_subtable_header header ; u16 reserved ; u32 local_apic_id ; u32 lapic_flags ; u32 uid ; } ;
struct acpi_madt_local_x2apic_nmi { struct acpi_subtable_header header ; u16 inti_flags ; u32 uid ; u8 lint ; u8 reserved [ 3 ] ; } ;
struct acpi_table_msct { struct acpi_table_header header ; u32 proximity_offset ; u32 max_proximity_domains ; u32 max_clock_domains ; u64 max_address ; } ;
struct acpi_table_sbst { struct acpi_table_header header ; u32 warning_level ; u32 low_level ; u32 critical_level ; } ;
struct acpi_table_slit { struct acpi_table_header header ; u64 locality_count ; u8 entry [ 1 ] ; } ;
struct acpi_table_srat { struct acpi_table_header header ; u32 table_revision ; u64 reserved ; } ;
struct acpi_srat_cpu_affinity { struct acpi_subtable_header header ; u8 proximity_domain_lo ; u8 apic_id ; u32 flags ; u8 local_sapic_eid ; u8 proximity_domain_hi [ 3 ] ; u32 reserved ; } ;
struct acpi_srat_mem_affinity { struct acpi_subtable_header header ; u32 proximity_domain ; u16 reserved ; u64 base_address ; u64 length ; u32 reserved1 ; u32 flags ; u64 reserved2 ; } ;
struct acpi_srat_x2apic_cpu_affinity { struct acpi_subtable_header header ; u16 reserved ; u32 proximity_domain ; u32 apic_id ; u32 flags ; u32 clock_domain ; u32 reserved2 ; } ;
struct acpi_table_asf { struct acpi_table_header header ; } ;
struct acpi_asf_info { struct acpi_asf_header header ; u8 min_reset_value ; u8 min_poll_interval ; u16 system_id ; u32 mfg_id ; u8 flags ; u8 reserved2 [ 3 ] ; } ;
struct acpi_asf_alert { struct acpi_asf_header header ; u8 assert_mask ; u8 deassert_mask ; u8 alerts ; u8 data_length ; } ;
struct acpi_asf_remote { struct acpi_asf_header header ; u8 controls ; u8 data_length ; u16 reserved2 ; } ;
struct acpi_asf_rmcp { struct acpi_asf_header header ; u8 capabilities [ 7 ] ; u8 completion_code ; u32 enterprise_id ; u8 command ; u16 parameter ; u16 boot_options ; u16 oem_parameters ; } ;
struct acpi_asf_address { struct acpi_asf_header header ; u8 eprom_address ; u8 devices ; } ;
struct acpi_table_boot { struct acpi_table_header header ; u8 cmos_index ; u8 reserved [ 3 ] ; } ;
struct acpi_table_dbgp { struct acpi_table_header header ; u8 type ; u8 reserved [ 3 ] ; struct acpi_generic_address debug_port ; } ;
struct acpi_table_dmar { struct acpi_table_header header ; u8 width ; u8 flags ; u8 reserved [ 10 ] ; } ;
struct acpi_dmar_hardware_unit { struct acpi_dmar_header header ; u8 flags ; u8 reserved ; u16 segment ; u64 address ; } ;
struct acpi_dmar_reserved_memory { struct acpi_dmar_header header ; u16 reserved ; u16 segment ; u64 base_address ; u64 end_address ; } ;
struct acpi_dmar_atsr { struct acpi_dmar_header header ; u8 flags ; u8 reserved ; u16 segment ; } ;
struct acpi_dmar_rhsa { struct acpi_dmar_header header ; u32 reserved ; u64 base_address ; u32 proximity_domain ; } ;
struct acpi_table_hpet { struct acpi_table_header header ; u32 id ; struct acpi_generic_address address ; u8 sequence ; u16 minimum_tick ; u8 flags ; } ;
struct acpi_table_ibft { struct acpi_table_header header ; u8 reserved [ 12 ] ; } ;
struct acpi_ibft_control { struct acpi_ibft_header header ; u16 extensions ; u16 initiator_offset ; u16 nic0_offset ; u16 target0_offset ; u16 nic1_offset ; u16 target1_offset ; } ;
struct acpi_ibft_initiator { struct acpi_ibft_header header ; u8 sns_server [ 16 ] ; u8 slp_server [ 16 ] ; u8 primary_server [ 16 ] ; u8 secondary_server [ 16 ] ; u16 name_length ; u16 name_offset ; } ;
struct acpi_ibft_nic { struct acpi_ibft_header header ; u8 ip_address [ 16 ] ; u8 subnet_mask_prefix ; u8 origin ; u8 gateway [ 16 ] ; u8 primary_dns [ 16 ] ; u8 secondary_dns [ 16 ] ; u8 dhcp [ 16 ] ; u16 vlan ; u8 mac_address [ 6 ] ; u16 pci_address ; u16 name_length ; u16 name_offset ; } ;
struct acpi_ibft_target { struct acpi_ibft_header header ; u8 target_ip_address [ 16 ] ; u16 target_ip_socket ; u8 target_boot_lun [ 8 ] ; u8 chap_type ; u8 nic_association ; u16 target_name_length ; u16 target_name_offset ; u16 chap_name_length ; u16 chap_name_offset ; u16 chap_secret_length ; u16 chap_secret_offset ; u16 reverse_chap_name_length ; u16 reverse_chap_name_offset ; u16 reverse_chap_secret_length ; u16 reverse_chap_secret_offset ; } ;
struct acpi_table_ivrs { struct acpi_table_header header ; u32 info ; u64 reserved ; } ;
struct acpi_ivrs_hardware { struct acpi_ivrs_header header ; u16 capability_offset ; u64 base_address ; u16 pci_segment_group ; u16 info ; u32 reserved ; } ;
struct acpi_ivrs_device4 { struct acpi_ivrs_de_header header ; } ;
struct acpi_ivrs_device8a { struct acpi_ivrs_de_header header ; u8 reserved1 ; u16 used_id ; u8 reserved2 ; } ;
struct acpi_ivrs_device8b { struct acpi_ivrs_de_header header ; u32 extended_data ; } ;
struct acpi_ivrs_device8c { struct acpi_ivrs_de_header header ; u8 handle ; u16 used_id ; u8 variety ; } ;
struct acpi_ivrs_memory { struct acpi_ivrs_header header ; u16 aux_data ; u64 reserved ; u64 start_address ; u64 memory_length ; } ;
struct acpi_table_mcfg { struct acpi_table_header header ; u8 reserved [ 8 ] ; } ;
struct acpi_table_mchi { struct acpi_table_header header ; u8 interface_type ; u8 protocol ; u64 protocol_data ; u8 interrupt_type ; u8 gpe ; u8 pci_device_flag ; u32 global_interrupt ; struct acpi_generic_address control_register ; u8 pci_segment ; u8 pci_bus ; u8 pci_device ; u8 pci_function ; } ;
struct acpi_table_slic { struct acpi_table_header header ; } ;
struct acpi_slic_key { struct acpi_slic_header header ; u8 key_type ; u8 version ; u16 reserved ; u32 algorithm ; char magic [ 4 ] ; u32 bit_length ; u32 exponent ; u8 modulus [ 128 ] ; } ;
struct acpi_slic_marker { struct acpi_slic_header header ; u32 version ; char oem_id [ 6 ] ; char oem_table_id [ 8 ] ; char windows_flag [ 8 ] ; u32 slic_version ; u8 reserved [ 16 ] ; u8 signature [ 128 ] ; } ;
struct acpi_table_spcr { struct acpi_table_header header ; u8 interface_type ; u8 reserved [ 3 ] ; struct acpi_generic_address serial_port ; u8 interrupt_type ; u8 pc_interrupt ; u32 interrupt ; u8 baud_rate ; u8 parity ; u8 stop_bits ; u8 flow_control ; u8 terminal_type ; u8 reserved1 ; u16 pci_device_id ; u16 pci_vendor_id ; u8 pci_bus ; u8 pci_device ; u8 pci_function ; u32 pci_flags ; u8 pci_segment ; u32 reserved2 ; } ;
struct acpi_table_spmi { struct acpi_table_header header ; u8 interface_type ; u8 reserved ; u16 spec_revision ; u8 interrupt_type ; u8 gpe_number ; u8 reserved1 ; u8 pci_device_flag ; u32 interrupt ; struct acpi_generic_address ipmi_register ; u8 pci_segment ; u8 pci_bus ; u8 pci_device ; u8 pci_function ; u8 reserved2 ; } ;
struct acpi_table_tcpa { struct acpi_table_header header ; u16 reserved ; u32 max_log_length ; u64 log_address ; } ;
struct acpi_table_uefi { struct acpi_table_header header ; u8 identifier [ 16 ] ; u16 data_offset ; } ;
struct acpi_table_waet { struct acpi_table_header header ; u32 flags ; } ;
struct acpi_table_wdat { struct acpi_table_header header ; u32 header_length ; u16 pci_segment ; u8 pci_bus ; u8 pci_device ; u8 pci_function ; u8 reserved [ 3 ] ; u32 timer_period ; u32 max_count ; u32 min_count ; u8 flags ; u8 reserved2 [ 3 ] ; u32 entries ; } ;
struct acpi_wdat_entry { u8 action ; u8 instruction ; u16 reserved ; struct acpi_generic_address register_region ; u32 value ; u32 mask ; } ;
struct acpi_table_wddt { struct acpi_table_header header ; u16 spec_version ; u16 table_version ; u16 pci_vendor_id ; struct acpi_generic_address address ; u16 max_count ; u16 min_count ; u16 period ; u16 status ; u16 capability ; } ;
struct acpi_table_wdrt { struct acpi_table_header header ; struct acpi_generic_address control_register ; struct acpi_generic_address count_register ; u16 pci_device_id ; u16 pci_vendor_id ; u8 pci_bus ; u8 pci_device ; u8 pci_function ; u8 pci_segment ; u16 max_count ; u8 units ; } ;
union acpi_resource_attribute { struct acpi_memory_attribute mem ; struct acpi_io_attribute io ; u8 type_specific ; } ;
struct acpi_resource_extended_irq { u8 producer_consumer ; u8 triggering ; u8 polarity ; u8 sharable ; u8 interrupt_count ; struct acpi_resource_source resource_source ; u32 interrupts [ 1 ] ; } ;
typedef void ( * acpi_op_notify ) ( struct acpi_device * device , u32 event ) ;
struct acpi_bus_ops { u32 acpi_op_add : 1 ; u32 acpi_op_start : 1 ; } ;
struct acpi_device_power_state { struct { u8 valid : 1 ; u8 explicit_set : 1 ; u8 reserved : 6 ; } flags ; int power ; int latency ; struct acpi_handle_list resources ; } ;
struct acpi_device_perf_state { struct { u8 valid : 1 ; u8 reserved : 7 ; } flags ; u8 power ; u8 performance ; int latency ; } ;
struct acpi_device_perf { int state ; struct acpi_device_perf_flags flags ; int state_count ; struct acpi_device_perf_state * states ; } ;
struct acpi_device_wakeup { acpi_handle gpe_device ; u64 gpe_number ; u64 sleep_state ; struct acpi_handle_list resources ; struct acpi_device_wakeup_flags flags ; int prepare_count ; } ;
struct acpi_bus_type { struct list_head list ; struct bus_type * bus ; int ( * find_device ) ( struct device * , acpi_handle * ) ; int ( * find_bridge ) ( struct device * , acpi_handle * ) ; } ;
struct acpi_pci_driver { struct acpi_pci_driver * next ; int ( * add ) ( acpi_handle handle ) ; void ( * remove ) ( acpi_handle handle ) ; } ;



extern void __mutex_init ( struct mutex * lock , const char * name , struct lock_class_key * key ) ;
extern void mutex_lock ( struct mutex * lock ) ;
extern int mutex_lock_interruptible ( struct mutex * lock ) ;
extern int mutex_lock_killable ( struct mutex * lock ) ;
extern int mutex_trylock ( struct mutex * lock ) ;
extern void mutex_unlock ( struct mutex * lock ) ;


struct dm_bufio_client;
struct dm_buffer;
int dm_get_device(struct dm_target *ti, const char *path, fmode_t mode,
                                                  struct dm_dev **result);
void dm_put_device(struct dm_target *ti, struct dm_dev *d);
extern void dm_bufio_mark_buffer_dirty(struct dm_buffer *b);
extern struct dm_bufio_client *
dm_bufio_client_create(struct block_device *bdev, unsigned block_size,
		unsigned reserved_buffers, unsigned aux_size,
		void (*alloc_callback)(struct dm_buffer *),
		void (*write_callback)(struct dm_buffer *));
extern void dm_bufio_client_destroy(struct dm_bufio_client *c);
extern void *dm_bufio_read(struct dm_bufio_client *c, sector_t block,
                     struct dm_buffer **bp);

extern void *dm_bufio_get(struct dm_bufio_client *c, sector_t block,
                    struct dm_buffer **bp);
extern void *dm_bufio_new(struct dm_bufio_client *c, sector_t block,
                    struct dm_buffer **bp);

extern void dm_bufio_release(struct dm_buffer *b);

extern void dm_bufio_mark_buffer_dirty(struct dm_buffer *b);
extern void dm_bufio_write_dirty_buffers_async(struct dm_bufio_client *c);
extern int dm_bufio_write_dirty_buffers(struct dm_bufio_client *c);
extern int dm_bufio_issue_flush(struct dm_bufio_client *c);
extern void dm_bufio_release_move(struct dm_buffer *b, sector_t new_block);
extern unsigned dm_bufio_get_block_size(struct dm_bufio_client *c);
extern sector_t dm_bufio_get_device_size(struct dm_bufio_client *c);
extern sector_t dm_bufio_get_block_number(struct dm_buffer *b);
extern void *dm_bufio_get_block_data(struct dm_buffer *b);
extern void *dm_bufio_get_aux_data(struct dm_buffer *b);
extern struct dm_bufio_client *dm_bufio_get_client(struct dm_buffer *b);

struct dm_io_client *dm_io_client_create(void);
void dm_io_client_destroy(struct dm_io_client *client);


int dm_io(struct dm_io_request *io_req, unsigned num_regions,
           struct dm_io_region *region, unsigned long *sync_error_bits);

extern void *kmem_cache_alloc_trace(struct kmem_cache *s, gfp_t gfpflags, size_t size);
#endif /* KERNEL_TYPES_HPP_ */
