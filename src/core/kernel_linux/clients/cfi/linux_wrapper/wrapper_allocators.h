/*
 * wrapper_allocators.h
 *
 *  Created on: 2013-04-16
 *      Author: akshayk
 */

#ifndef WRAPPER_ALLOCATORS_H_
#define WRAPPER_ALLOCATORS_H_

#define FUNCTION_WRAPPER FUNC_WRAPPER
#define P(x)

#define WATCHPOINT_NUMBER 20
static volatile uint64_t watchpoint_counter = 0;

#define CAN_WRAP___kmalloc 1
#if defined(CAN_WRAP___kmalloc) && CAN_WRAP___kmalloc
#define WRAPPER_FOR___kmalloc 1
FUNCTION_WRAPPER(__kmalloc, (size_t size, gfp_t flags), {
    function_t *wrap_func;
    uint i = 0;
    wrap_func = wrapped_functions[i];
    for(wrap_func; wrap_func != NULL; wrap_func = wrapped_functions[++i]){
         if(wrap_func->start == (void*)__kmalloc){
              P(kern_printk("__kmalloc : %llx, wrap_start : %llx", __kmalloc, wrap_func->start);)
              __kmalloc = (decltype(__kmalloc))(wrap_func->replace_func);
              break;
          }
    }
    void *watchpoint_addr = __kmalloc(size, flags);
   // uint64_t counter((uint64_t)__sync_fetch_and_add(&(watchpoint_counter), 0x1));
//    if((counter < WATCHPOINT_NUMBER) /*&& (counter != 11)*/) {
#ifdef ACTIVATE_WATCHPOINT
        ADD_WATCHPOINT(watchpoint_addr, size);
        watchpoint_descriptor *meta_info = NULL;
        meta_info = WATCHPOINT_META(watchpoint_addr);
        if(NULL != meta_info) {
            uint64_t newval = 0x0ULL;
            uint64_t oldval = 0x0ULL;
            do {
                oldval = meta_info->state;
                newval = meta_info->state | WP_MEMORY_ALLOCATED;
            }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
        }
        cfi_handler_alloc(target_module, watchpoint_addr, size, NULL);
        P(kern_printk("__kmalloc wrapper  : %lx, %lx\n", watchpoint_addr, size);)
        cfi_dump_stack();
#endif
  //  }
        cfi_dump_stack();
    return watchpoint_addr;
})
#endif

FUNC_WRAPPER_VOID(kfree, ( void* addr), {
    P(kern_printk("kfree wrapper : %lx\n", addr);)
    function_t *wrap_func;
    uint i = 0;
    wrap_func = wrapped_functions[i];
    for(wrap_func; wrap_func != NULL; wrap_func = wrapped_functions[++i]){
        if(wrap_func->start == (void*)kfree){
            P(kern_printk("kfree : %llx, wrap_start : %llx", kfree, wrap_func->start);)
            kfree = (decltype(kfree))(wrap_func->replace_func);
            break;
        }
    }
    /*check if this is watchpoint*/

#ifdef ACTIVATE_WATCHPOINT
    cfi_handler_free(target_module, addr, NULL);
    watchpoint_descriptor *meta_info = NULL;
    meta_info = WATCHPOINT_META(addr);
    if(NULL != meta_info) {
        uint64_t newval = 0x0ULL;
        uint64_t oldval = 0x0ULL;
        do {
            oldval = meta_info->state;
            newval = (meta_info->state & (~WP_MEMORY_ALLOCATED)/*| WP_MEMORY_FREED*/);
        }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
        //meta_info->state &= ~WP_MEMORY_ALLOCATED;
        //meta_info->state |= WP_MEMORY_FREED;
    }

    REMOVE_WATCHPOINT(addr);
#endif
    return kfree(addr);
})

// TODO: handle _krealloc correctly
FUNC_WRAPPER(__krealloc, (const void* ptr, size_t size, gfp_t flags), {
    kern_printk("__krealloc wrapper\n");
    //REMOVE_WATCHPOINT(ptr);
    void *watch_ptr = __krealloc(ptr, size, flags);
    return watch_ptr;
})

//TODO: handle krealloc
FUNC_WRAPPER(krealloc, (const void* ptr, size_t size, gfp_t flags), {
    kern_printk("krealloc wrapper\n");
    //REMOVE_WATCHPOINT(ptr);
    void *watch_ptr = krealloc(ptr, size, flags);
    return watch_ptr;
})


//void *__kmalloc_node(size_t size, gfp_t flags, int node);
FUNC_WRAPPER(__kmalloc_node, (size_t size, gfp_t flags, int node), {
    kern_printk("__kmalloc_node wrapper\n");
    return __kmalloc_node(size, flags, node);
})

//void *__kmalloc_track_caller(size_t, gfp_t, unsigned long);
FUNC_WRAPPER(__kmalloc_track_caller, (size_t size, gfp_t flags, unsigned long caller), {
    kern_printk("__kmalloc_track_caller wrapper\n");
    return __kmalloc_track_caller(size, flags, caller);
})

//void *__kmalloc_node_track_caller(size_t, gfp_t, int, unsigned long);
FUNC_WRAPPER(__kmalloc_node_track_caller, (size_t size, gfp_t flags, int node, unsigned long caller), {
    kern_printk("__kmalloc_node_track_caller wrapper\n");
    return __kmalloc_node_track_caller(size, flags, node, caller);
})

/*  The wrapper for kmem_cache_alloc
 *
 */
FUNC_WRAPPER(kmem_cache_alloc, (struct kmem_cache *s, gfp_t gfpflags), {
    void *watch_ptr = kmem_cache_alloc(s, gfpflags);
    uint64_t counter((uint64_t)__sync_fetch_and_add(&(watchpoint_counter), 0x1));
    //if((counter < WATCHPOINT_NUMBER) /*&& (counter != 11)*/) {
#ifdef ACTIVATE_WATCHPOINT
    ADD_WATCHPOINT(watch_ptr, s->size);
    if(s->ctor != NULL)
        s->ctor(watch_ptr);

    watchpoint_descriptor *meta_info = NULL;
    meta_info = WATCHPOINT_META(watch_ptr);
    if(NULL != meta_info) {
        uint64_t newval = 0x0ULL;
        uint64_t oldval = 0x0ULL;
        do {
            oldval = meta_info->state;
            newval = meta_info->state | WP_MEMORY_ALLOCATED;
        }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
    }
    cfi_handler_alloc(target_module, watch_ptr, s->size, NULL);
    P(kern_printk("kmem_cache_alloc wrapper : %lx  : %lx\n", (uint64_t)watch_ptr, s->size);)
    cfi_dump_stack();
#endif
   // }
    return watch_ptr;
})


FUNC_WRAPPER(kmem_cache_alloc_trace, (struct kmem_cache *s, gfp_t gfpflags, size_t size), {
    void *watch_ptr = kmem_cache_alloc_trace(s, gfpflags, size);
#ifdef ACTIVATE_WATCHPOINT
    ADD_WATCHPOINT(watch_ptr, size);
    if(s->ctor != NULL)
        s->ctor(watch_ptr);

    watchpoint_descriptor *meta_info = NULL;
    meta_info = WATCHPOINT_META(watch_ptr);
    if(NULL != meta_info) {
        uint64_t newval = 0x0ULL;
        uint64_t oldval = 0x0ULL;
        do {
            oldval = meta_info->state;
            newval = meta_info->state | WP_MEMORY_ALLOCATED;
        }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
    }

    cfi_handler_alloc(target_module, watch_ptr, size, NULL);
    P(kern_printk("kmem_cache_alloc_trace wrapper : %lx  : %lx\n", (uint64_t)watch_ptr, size);)
    cfi_dump_stack();
#endif
    return watch_ptr;
})
//void *kmem_cache_alloc_node(struct kmem_cache *cachep, gfp_t flags, int nodeid)
FUNC_WRAPPER(kmem_cache_alloc_node, (struct kmem_cache *cachep, gfp_t flags, int nodeid), {
    kern_printk("kmem_cache_alloc_node wrapper\n");
    return kmem_cache_alloc_node(cachep, flags, nodeid);
})

//void kmem_cache_free(struct kmem_cache *, void *);
FUNC_WRAPPER_VOID(kmem_cache_free, (struct kmem_cache *s, void *ptr), {
    kern_printk("kmem_cache_free wrapper : %lx\n", ptr);
#ifdef ACTIVATE_WATCHPOINT
    watchpoint_descriptor *meta_info = NULL;
    meta_info = WATCHPOINT_META(ptr);
    if(NULL != meta_info) {
        uint64_t newval = 0x0ULL;
        uint64_t oldval = 0x0ULL;
        do {
            oldval = meta_info->state;
            newval = (meta_info->state & (~WP_MEMORY_ALLOCATED)/*| WP_MEMORY_FREED*/);
        }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
    }

    cfi_handler_free(target_module, ptr, NULL);
    REMOVE_WATCHPOINT(ptr);
#endif
    return kmem_cache_free(s, ptr);

})

//struct kmem_cache *kmem_cache_create(const char *, size_t, size_t,
//                         unsigned long,
//                         void (*)(void *));

FUNC_WRAPPER(kmem_cache_create, (const char *name , size_t size, size_t align, unsigned long flags,  void(*ctor)(void*) ), {
    kern_printk("kmem_cache_create wrapper\n");
    WRAP_FUNC(ctor);
    return kmem_cache_create(name, size, align, flags, ctor);
})

//int kmem_cache_shrink(struct kmem_cache *s)
FUNC_WRAPPER_VOID(kmem_cache_shrink, (struct kmem_cache *s), {
    kern_printk("kmem_cache_shrink wrapper\n");
    return kmem_cache_shrink(s);
})

//void kmem_cache_destroy(struct kmem_cache *);
FUNC_WRAPPER_VOID(kmem_cache_destroy, (struct kmem_cache *s), {
    kern_printk("kmem_cache_destroy wrapper\n");
    return kmem_cache_destroy(s);
})


//void *vmalloc(unsigned long size)
FUNC_WRAPPER(vmalloc, (unsigned long size), {
    kern_printk("vmalloc wrapper\n");
    void *ptr = vmalloc(size);
    //ADD_WATCHPOINT(ptr);
    return ptr;
})

//extern void vfree ( void * addr ) ;
FUNC_WRAPPER_VOID(vfree, ( void * addr ), {
    kern_printk("vfree wrapper\n");
    //REMOVE_WATCHPOINT(addr);
    vfree(addr);
})

//void *vmalloc_node(unsigned long size, int node)
FUNC_WRAPPER(vmalloc_node, (unsigned long size, int node), {
    kern_printk("vmalloc_node wrapper\n");
    void *ptr = vmalloc_node(size, node);

    return ptr;
})


FUNC_WRAPPER(posix_acl_alloc, (int count, gfp_t flags), {
    struct posix_acl *ret = posix_acl_alloc(count, flags);
    //ADD_WATCHPOINT(ret);
    kern_printk("posix_acl_alloc wrapper %lx\n", ret);
    return ret;
})

#ifndef PAGE_SIZE
#define PAGE_SIZE 4096
#endif

//extern unsigned long __get_free_pages(gfp_t gfp_mask, unsigned int order);
FUNC_WRAPPER(__get_free_pages, (gfp_t gfp_mask, unsigned int order), {
    void* addr= (void*)__get_free_pages(gfp_mask, order);
    //ADD_WATCHPOINT(addr);
    //granary_lc_handle_alloc(target_module, addr, order*PAGE_SIZE, NULL);
    kern_printk("__get_free_pages wrapper : %lx\n", addr);
    return (unsigned long)addr;
})

//void __free_pages(struct page *page, unsigned int order)
FUNC_WRAPPER_VOID(__free_pages, (struct page *page, unsigned int order), {
    kern_printk("__free_pages wrapper\n");
    //REMOVE_WATCHPOINT(page);
    //granary_lc_handle_free(target_module, page, NULL);
    __free_pages(page, order);
})

//extern void *__alloc_percpu(size_t size, size_t align);
FUNCTION_WRAPPER(__alloc_percpu, (size_t size, size_t align), {
    void *watchpoint_addr = __alloc_percpu(size, align);
#ifdef ACTIVATE_WATCHPOINT
        ADD_WATCHPOINT(watchpoint_addr, size);
        watchpoint_descriptor *meta_info = NULL;
        meta_info = WATCHPOINT_META(watchpoint_addr);
        if(NULL != meta_info) {
            uint64_t newval = 0x0ULL;
            uint64_t oldval = 0x0ULL;
            do {
                oldval = meta_info->state;
                newval = meta_info->state | WP_MEMORY_ALLOCATED;
            }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
        }
        cfi_handler_alloc(target_module, watchpoint_addr, size, NULL);
        P(kern_printk("__kmalloc wrapper  : %lx, %lx\n", watchpoint_addr, size);)
        cfi_dump_stack();
#endif
    return watchpoint_addr;
})

//extern void free_percpu(void *__pdata);
FUNC_WRAPPER_VOID(free_percpu, ( void* __pdata), {
    kern_printk("free_percpu wrapper : %lx\n", __pdata);
    /*check if this is watchpoint*/
#ifdef ACTIVATE_WATCHPOINT
    cfi_handler_free(target_module, __pdata, NULL);
    watchpoint_descriptor *meta_info = NULL;
    meta_info = WATCHPOINT_META(__pdata);
    if(NULL != meta_info) {
        uint64_t newval = 0x0ULL;
        uint64_t oldval = 0x0ULL;
        do {
            oldval = meta_info->state;
            newval = (meta_info->state & (~WP_MEMORY_ALLOCATED)/*| WP_MEMORY_FREED*/);
        }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
    }

    REMOVE_WATCHPOINT(__pdata);
#endif
    return kfree(__pdata);
})

/*extern struct workqueue_struct * __alloc_workqueue_key ( const char * fmt , unsigned int flags , int max_active , struct lock_class_key * key , const char * lock_name , const char namefmt [ ] );
extern void destroy_workqueue ( struct workqueue_struct * wq ) ;*/

FUNC_WRAPPER(__alloc_workqueue_key, (
        const char * fmt ,
        unsigned int flags ,
        int max_active ,
        struct lock_class_key * key ,
        const char * lock_name ,
        ...
    ), {
    va_list args__;
    va_start(args__, lock_name);
    size_t namelen = vsnprintf(NULL, 0, fmt, args__) + 1;

    kern_printk("namelen : %lx\n", namelen);

    char name_buf[namelen];
    vsnprintf(&(name_buf[0]), namelen, fmt, args__);
    kern_printk("namebuf : %s\n", name_buf);
    struct workqueue_struct *ret = __alloc_workqueue_key(fmt, flags, max_active, key, name_buf);
    va_end(args__);
    return ret;
})

FUNC_WRAPPER_VOID(destroy_workqueue,  ( struct workqueue_struct * wq ), {
    kern_printk("destroy_workqueue wrapper : %lx\n", wq);
#if 0
    /*check if this is watchpoint*/
    cfi_handler_free(target_module, wq, NULL);

    watchpoint_descriptor *meta_info = NULL;
    meta_info = WATCHPOINT_META(wq);
    if(NULL != meta_info) {
        uint64_t newval = 0x0ULL;
        uint64_t oldval = 0x0ULL;
        do {
            oldval = meta_info->state;
            newval = (meta_info->state & (~WP_MEMORY_ALLOCATED)/*| WP_MEMORY_FREED*/);
        }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
    }

    REMOVE_WATCHPOINT(wq);
#endif
    return destroy_workqueue(wq);
})

#endif /* KERNEL_ALLOCATORS_H_ */
