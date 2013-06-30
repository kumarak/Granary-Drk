/*
 * wrapper_allocators.h
 *
 *  Created on: 2013-04-16
 *      Author: akshayk
 */

#ifndef WRAPPER_ALLOCATORS_H_
#define WRAPPER_ALLOCATORS_H_

extern "C" {
    void debug___kmalloc(void *ptr, size_t size){
        printk("%s\n", __FUNCTION__);
    }

    void debug_kmem_cache_alloc(void *ptr, size_t size){
        printk("%s\n", __FUNCTION__);
    }

    void debug_kmem_cache_alloc_trace(void *ptr, size_t size){
        printk("%s\n", __FUNCTION__);
    }
}

#define FUNCTION_WRAPPER FUNC_WRAPPER
#define P(x)

#define WATCHPOINT_NUMBER 20
static volatile uint64_t watchpoint_counter = 0;

#define CAN_WRAP___kmalloc 1
#if defined(CAN_WRAP___kmalloc) && CAN_WRAP___kmalloc
#define WRAPPER_FOR___kmalloc 1
FUNCTION_WRAPPER(__kmalloc, (size_t size, gfp_t flags), {
        unsigned int retval = 0;
        enum section_state state;
        if(slub_allocator.__kmalloc != NULL){
            __kmalloc = (decltype(__kmalloc))(slub_allocator.__kmalloc);
        }
        void *watchpoint_addr = __kmalloc(size, flags);

#ifdef CONFIG_USING_WATCHPOINT
        ADD_WATCHPOINT(watchpoint_addr, size);
        descriptor *meta_info = NULL;
        meta_info = WATCHPOINT_META(watchpoint_addr);
        if(NULL != meta_info) {
            uint64_t newval = 0x0ULL;
            uint64_t oldval = 0x0ULL;
            do {
                oldval = meta_info->state;
                newval = meta_info->state | WP_MEMORY_ALLOCATED;
            }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
        }
        P(kern_printk("__kmalloc wrapper  : %lx, %lx\n", watchpoint_addr, size);)
        cfi_dump_stack();
#endif
        return watchpoint_addr;
})
#endif

FUNC_WRAPPER_VOID(kfree, ( void* addr), {
        if(slub_allocator.kfree != NULL){
            kfree = (decltype(kfree))(slub_allocator.kfree);
        }

        handle_free_object(addr);
#ifdef CONFIG_USING_WATCHPOINT
        descriptor *meta_info = NULL;
        meta_info = WATCHPOINT_META(addr);
        if(NULL != meta_info) {
            uint64_t newval = 0x0ULL;
            uint64_t oldval = 0x0ULL;
            do {
                oldval = meta_info->state;
                newval = (meta_info->state & (~WP_MEMORY_ALLOCATED)/*| WP_MEMORY_FREED*/);
            }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
        }

        REMOVE_WATCHPOINT(addr);
#endif
        kfree(addr);
})

// TODO: handle _krealloc correctly
FUNC_WRAPPER(__krealloc, (const void* ptr, size_t size, gfp_t flags), {
    P(kern_printk("__krealloc wrapper\n");)
    //REMOVE_WATCHPOINT(ptr);
    void *watch_ptr = __krealloc(ptr, size, flags);
    return watch_ptr;
})

//TODO: handle krealloc
FUNC_WRAPPER(krealloc, (const void* ptr, size_t size, gfp_t flags), {
    kern_printk("krealloc wrapper\n");
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
        unsigned int retval = 0;
        enum section_state state;
        if(slub_allocator.kmem_cache_alloc != NULL){
            kmem_cache_alloc = (decltype(kmem_cache_alloc))(slub_allocator.kmem_cache_alloc);
        }
        void *watch_ptr = kmem_cache_alloc(s, gfpflags);

#ifdef CONFIG_USING_WATCHPOINT
        ADD_WATCHPOINT(watch_ptr, s->size);
        if(s->ctor != NULL)
            s->ctor(watch_ptr);

        descriptor *meta_info = NULL;
        meta_info = WATCHPOINT_META(watch_ptr);
        if(NULL != meta_info) {
            uint64_t newval = 0x0ULL;
            uint64_t oldval = 0x0ULL;
            meta_info->state = meta_info->state | WP_MEMORY_ALLOCATED;
        }
        P(kern_printk("kmem_cache_alloc wrapper : %lx  : %lx\n", (uint64_t)watch_ptr, s->size);)
        cfi_dump_stack();
#endif
      //  debug_kmem_cache_alloc(watch_ptr, s->size);
        return watch_ptr;
})

#if 0

FUNC_WRAPPER(kmem_cache_alloc_trace, (struct kmem_cache *s, gfp_t gfpflags, size_t size), {
        function_t *wrap_func;
        unsigned int retval = 0;
        uint i = 0;
        wrap_func = wrapped_functions[i];
        for(i = 0; wrap_func != NULL; wrap_func = wrapped_functions[++i]){
            if(wrap_func->start == (void*)kmem_cache_alloc_trace){
                P(kern_printk("kmem_cache_alloc_trace : %llx, wrap_start : %llx", kmem_cache_alloc_trace, wrap_func->start);)
                kmem_cache_alloc_trace = (decltype(kmem_cache_alloc_trace))(wrap_func->replace_func);
                break;
             }
        }
        void *watch_ptr = kmem_cache_alloc_trace(s, gfpflags, size);
#ifdef CONFIG_USING_WATCHPOINT
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
#endif
      //  debug_kmem_cache_alloc_trace(watch_ptr, size);
        return watch_ptr;
})
#endif

//void *kmem_cache_alloc_node(struct kmem_cache *cachep, gfp_t flags, int nodeid)
FUNC_WRAPPER(kmem_cache_alloc_node, (struct kmem_cache *cachep, gfp_t flags, int nodeid), {
        P(kern_printk("kmem_cache_alloc_node wrapper\n");)
        if(slub_allocator.kmem_cache_alloc_node != NULL){
            kmem_cache_alloc_node = (decltype(kmem_cache_alloc_node))(slub_allocator.kmem_cache_alloc_node);
        }
        return kmem_cache_alloc_node(cachep, flags, nodeid);
})

//void kmem_cache_free(struct kmem_cache *, void *);
FUNC_WRAPPER_VOID(kmem_cache_free, (struct kmem_cache *s, void *ptr), {
        P(kern_printk("kmem_cache_free wrapper : %lx\n", ptr);)
        if(slub_allocator.kmem_cache_free != NULL){
            kmem_cache_free = (decltype(kmem_cache_free))(slub_allocator.kmem_cache_free);
        }
        handle_free_object(ptr);

#ifdef CONFIG_USING_WATCHPOINT
        descriptor *meta_info = NULL;
        meta_info = WATCHPOINT_META(ptr);
        if(NULL != meta_info) {
            uint64_t newval = 0x0ULL;
            uint64_t oldval = 0x0ULL;
            do {
                oldval = meta_info->state;
                newval = (meta_info->state & (~WP_MEMORY_ALLOCATED)/*| WP_MEMORY_FREED*/);
            }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
        }

        REMOVE_WATCHPOINT(ptr);
#endif
        kmem_cache_free(s, ptr);

})

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
#ifdef CONFIG_USING_WATCHPOINT
        ADD_WATCHPOINT(ptr, size);
        descriptor *meta_info = NULL;
        meta_info = WATCHPOINT_META(ptr);
        if(NULL != meta_info) {
            uint64_t newval = 0x0ULL;
            uint64_t oldval = 0x0ULL;
            do {
                oldval = meta_info->state;
                newval = meta_info->state | WP_MEMORY_ALLOCATED;
            }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
        }
#endif
    return ptr;
})

//extern void vfree ( void * addr ) ;
FUNC_WRAPPER_VOID(vfree, ( void * ptr), {
        kern_printk("vfree wrapper\n");
#ifdef CONFIG_USING_WATCHPOINT
        descriptor *meta_info = NULL;
        meta_info = WATCHPOINT_META(ptr);
        if(NULL != meta_info) {
            uint64_t newval = 0x0ULL;
            uint64_t oldval = 0x0ULL;
            do {
                oldval = meta_info->state;
                newval = (meta_info->state & (~WP_MEMORY_ALLOCATED)/*| WP_MEMORY_FREED*/);
            }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
        }

        REMOVE_WATCHPOINT(ptr);
#endif
        vfree(ptr);
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
        if(slub_allocator.__get_free_pages != NULL){
            __get_free_pages = (decltype(__get_free_pages))(slub_allocator.__get_free_pages);
        }
        void* addr= (void*)__get_free_pages(gfp_mask, order);
#ifdef CONFIG_USING_WATCHPOINT
        ADD_WATCHPOINT(addr, PAGE_SIZE<<order);
        descriptor *meta_info = NULL;
        meta_info = WATCHPOINT_META(addr);
        if(NULL != meta_info) {
            uint64_t newval = 0x0ULL;
            uint64_t oldval = 0x0ULL;
            do {
                oldval = meta_info->state;
                newval = meta_info->state | WP_MEMORY_ALLOCATED;
            }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
        }
        cfi_dump_stack();
#endif
        P(kern_printk("__get_free_pages wrapper : %lx\n", addr);)
        return (unsigned long)addr;
})

//void __free_pages(struct page *page, unsigned int order)
FUNC_WRAPPER_VOID(__free_pages, (struct page *page, unsigned int order), {
    P(kern_printk("__free_pages wrapper\n");)
    __free_pages(page, order);
})


FUNCTION_WRAPPER(__alloc_percpu, (size_t size, size_t align), {
        unsigned int retval = 0;
        enum section_state state;
        if(slub_allocator.__alloc_percpu != NULL){
            __alloc_percpu = (decltype(__alloc_percpu))(slub_allocator.__alloc_percpu);
        }
        void *addr = __alloc_percpu(size, align);

        handle_alloc_percpu(addr, size);
#ifdef CONFIG_USING_WATCHPOINT
        ADD_WATCHPOINT(addr, size);
        descriptor *meta_info = NULL;
        meta_info = WATCHPOINT_META(addr);
        if(NULL != meta_info) {
            uint64_t newval = 0x0ULL;
            uint64_t oldval = 0x0ULL;
            do {
                oldval = meta_info->state;
                newval = meta_info->state | WP_MEMORY_ALLOCATED;
            }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
        }
        P(kern_printk("__kmalloc wrapper  : %lx, %lx\n", watchpoint_addr, size);)
#endif
        return addr;
})

FUNC_WRAPPER_VOID(free_percpu, ( void* __pdata), {
        if(slub_allocator.free_percpu != NULL){
            free_percpu = (decltype(free_percpu))(slub_allocator.free_percpu);
        }

        handle_free_percpu(__pdata);

#ifdef CONFIG_USING_WATCHPOINT
        descriptor *meta_info = NULL;
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
        return free_percpu(__pdata);
})


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
    return destroy_workqueue(wq);
})

FUNC_WRAPPER(mb_cache_create, (const char *name, int bucket_bits), {
    struct mb_cache *ret = mb_cache_create(name, bucket_bits);
    return ret;
})

#endif /* KERNEL_ALLOCATORS_H_ */
