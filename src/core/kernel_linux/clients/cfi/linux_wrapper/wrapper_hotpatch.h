/*
 * wrapper_hotpatch.h
 *
 *  Created on: 2013-05-22
 *      Author: akshayk
 */

#ifndef WRAPPER_HOTPATCH_H_
#define WRAPPER_HOTPATCH_H_

//#undef CONFIG_USING_WATCHPOINT


HOTPATCH_WRAPPER(__kmalloc, (size_t size, gfp_t flags), {
        unsigned int retval = 0;
        enum section_state state;
        if(slub_allocator.__kmalloc != NULL){
            __kmalloc = (decltype(__kmalloc))(slub_allocator.__kmalloc);
        }
        void *watchpoint_addr = __kmalloc(size, flags);

#ifdef CONFIG_USING_WATCHPOINT
        state = (enum section_state)get_section_state();
        if(state & KERNEL_WRAPPER_SET){
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

            retval = cfi_dump_stack();
            P(kern_printk("ADD_WATCHPOINT with this pointer : %llx\n", watchpoint_addr);)
        }
#endif
        return watchpoint_addr;
})



HOTPATCH_WRAPPER_VOID(kfree, ( void* addr), {
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
                newval = (meta_info->state & (~WP_MEMORY_ALLOCATED));
            }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
        }

        REMOVE_WATCHPOINT(addr);
#endif
        kfree(addr);
})

// TODO: handle _krealloc correctly
HOTPATCH_WRAPPER(__krealloc, (const void* ptr, size_t size, gfp_t flags), {
    kern_printk("__krealloc wrapper\n");
    //REMOVE_WATCHPOINT(ptr);
    void *watch_ptr = __krealloc(ptr, size, flags);
    return watch_ptr;
})

//TODO: handle krealloc
HOTPATCH_WRAPPER(krealloc, (const void* ptr, size_t size, gfp_t flags), {
    kern_printk("krealloc wrapper\n");
    //REMOVE_WATCHPOINT(ptr);
    void *watch_ptr = krealloc(ptr, size, flags);
    return watch_ptr;
})


HOTPATCH_WRAPPER(__kmalloc_node, (size_t size, gfp_t flags, int node), {
        P(kern_printk("__kmalloc_node wrapper\n");)
        if(slub_allocator.__kmalloc_node != NULL){
            __kmalloc_node = (decltype(__kmalloc_node))(slub_allocator.__kmalloc_node);
        }
        return __kmalloc_node(size, flags, node);
})

//void *__kmalloc_track_caller(size_t, gfp_t, unsigned long);
HOTPATCH_WRAPPER(__kmalloc_track_caller, (size_t size, gfp_t flags, unsigned long caller), {
        P(kern_printk("__kmalloc_track_caller wrapper\n");)
        if(slub_allocator.__kmalloc_track_caller != NULL){
            __kmalloc_track_caller = (decltype(__kmalloc_track_caller))(slub_allocator.__kmalloc_track_caller);
        }
        return __kmalloc_track_caller(size, flags, caller);
})

//void *__kmalloc_node_track_caller(size_t, gfp_t, int, unsigned long);
HOTPATCH_WRAPPER(__kmalloc_node_track_caller, (size_t size, gfp_t flags, int node, unsigned long caller), {
        P(kern_printk("__kmalloc_node_track_caller wrapper\n");)
        if(slub_allocator.__kmalloc_node_track_caller != NULL){
            __kmalloc_node_track_caller = (decltype(__kmalloc_node_track_caller))(slub_allocator.__kmalloc_node_track_caller);
        }
        return __kmalloc_node_track_caller(size, flags, node, caller);
})

//volatile uint64_t watchpoint_counter = 0;

/*  The wrapper for kmem_cache_alloc
 *
 */
HOTPATCH_WRAPPER(kmem_cache_alloc, (struct kmem_cache *s, gfp_t gfpflags), {
        unsigned int retval = 0;
        enum section_state state;
        if(slub_allocator.kmem_cache_alloc != NULL){
            kmem_cache_alloc = (decltype(kmem_cache_alloc))(slub_allocator.kmem_cache_alloc);
        }
        void *watch_ptr = kmem_cache_alloc(s, gfpflags);

#ifdef CONFIG_USING_WATCHPOINT

        state = (enum section_state)get_section_state();
        if(state & KERNEL_WRAPPER_SET){
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
            retval = cfi_dump_stack();
            P(kern_printk("ADD_WATCHPOINT with this pointer : %llx\n", watch_ptr);)
        }
#endif
        return watch_ptr;
})

#if 0

HOTPATCH_WRAPPER(kmem_cache_alloc_trace, (struct kmem_cache *s, gfp_t gfpflags, size_t size), {
    function_t *wrap_func;
    unsigned int retval = 0;
    enum section_state state;
    uint i = 0;
    wrap_func = wrapped_functions[i];
    for( i = 0; wrap_func != NULL; wrap_func = wrapped_functions[++i]){
        if(wrap_func->start == (void*)kmem_cache_alloc_trace){
                P(kern_printk("kmem_cache_alloc_trace : %llx, wrap_start : %llx", kmem_cache_alloc_trace, wrap_func->start);)
                kmem_cache_alloc_trace = (decltype(kmem_cache_alloc_trace))(wrap_func->replace_func);
                break;
              }
        }
    void *watch_ptr = kmem_cache_alloc_trace(s, gfpflags, size);
#ifdef CONFIG_USING_WATCHPOINT
    state = (enum section_state)get_section_state();
    if(state & KERNEL_WRAPPER_SET){
            kern_printk("ADD_WATCHPOINT with this pointer\n");
            ADD_WATCHPOINT(watch_ptr, s->size);
            if(s->ctor != NULL)
                s->ctor(watch_ptr);

            watchpoint_descriptor *meta_info = NULL;
            meta_info = WATCHPOINT_META(watch_ptr);
            if(NULL != meta_info) {
                uint64_t newval = 0x0ULL;
                uint64_t oldval = 0x0ULL;
                meta_info->state = meta_info->state | WP_MEMORY_ALLOCATED;
#if 0
                do {
                    oldval = meta_info->state;
                    newval = meta_info->state | WP_MEMORY_ALLOCATED;
                }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
#endif
            }
        //}
    }
#endif
    return watch_ptr;
})
#endif

//void *kmem_cache_alloc_node(struct kmem_cache *cachep, gfp_t flags, int nodeid)
HOTPATCH_WRAPPER(kmem_cache_alloc_node, (struct kmem_cache *cachep, gfp_t flags, int nodeid), {
        P(kern_printk("kmem_cache_alloc_node wrapper\n");)
        if(slub_allocator.kmem_cache_alloc_node != NULL){
            kmem_cache_alloc_node = (decltype(kmem_cache_alloc_node))(slub_allocator.kmem_cache_alloc_node);
        }
        return kmem_cache_alloc_node(cachep, flags, nodeid);
})

//void kmem_cache_free(struct kmem_cache *, void *);
HOTPATCH_WRAPPER_VOID(kmem_cache_free, (struct kmem_cache *s, void *ptr), {
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
            newval = (meta_info->state & (~WP_MEMORY_ALLOCATED));
            do {
                oldval = meta_info->state;
            }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
        }
        REMOVE_WATCHPOINT(ptr);
#endif
        kmem_cache_free(s, ptr);

})

//struct kmem_cache *kmem_cache_create(const char *, size_t, size_t,
//                         unsigned long,
//                         void (*)(void *));

HOTPATCH_WRAPPER(kmem_cache_create, (const char *name , size_t size, size_t align, unsigned long flags,  void(*ctor)(void*) ), {
    kern_printk("kmem_cache_create wrapper\n");
    return kmem_cache_create(name, size, align, flags, ctor);
})

//int kmem_cache_shrink(struct kmem_cache *s)
HOTPATCH_WRAPPER_VOID(kmem_cache_shrink, (struct kmem_cache *s), {
    kern_printk("kmem_cache_shrink wrapper\n");
    return kmem_cache_shrink(s);
})

//void kmem_cache_destroy(struct kmem_cache *);
HOTPATCH_WRAPPER_VOID(kmem_cache_destroy, (struct kmem_cache *s), {
    kern_printk("kmem_cache_destroy wrapper\n");
    return kmem_cache_destroy(s);
})


//void *vmalloc(unsigned long size)
HOTPATCH_WRAPPER(vmalloc, (unsigned long size), {
    kern_printk("vmalloc wrapper\n");
    void *ptr = vmalloc(size);
    //ADD_WATCHPOINT(ptr);
    return ptr;
})

//extern void vfree ( void * addr ) ;
HOTPATCH_WRAPPER_VOID(vfree, ( void * addr ), {
    kern_printk("vfree wrapper\n");
    //REMOVE_WATCHPOINT(addr);
    vfree(addr);
})

//void *vmalloc_node(unsigned long size, int node)
HOTPATCH_WRAPPER(vmalloc_node, (unsigned long size, int node), {
    kern_printk("vmalloc_node wrapper\n");
    void *ptr = vmalloc_node(size, node);

    return ptr;
})


HOTPATCH_WRAPPER(posix_acl_alloc, (int count, gfp_t flags), {
    struct posix_acl *ret = posix_acl_alloc(count, flags);
    kern_printk("posix_acl_alloc wrapper %lx\n", ret);
    return ret;
})

#ifndef PAGE_SIZE
#define PAGE_SIZE 4096
#endif

//extern unsigned long __get_free_pages(gfp_t gfp_mask, unsigned int order);
HOTPATCH_WRAPPER(__get_free_pages, (gfp_t gfp_mask, unsigned int order), {
        if(slub_allocator.__get_free_pages != NULL){
            __get_free_pages = (decltype(__get_free_pages))(slub_allocator.__get_free_pages);
        }
        void* addr= (void*)__get_free_pages(gfp_mask, order);
        P(kern_printk("__get_free_pages wrapper : %lx\n", addr);)
        return (unsigned long)addr;
})

//void __free_pages(struct page *page, unsigned int order)
HOTPATCH_WRAPPER_VOID(__free_pages, (struct page *page, unsigned int order), {
        if(slub_allocator.__free_pages != NULL){
            __free_pages = (decltype(__free_pages))(slub_allocator.__free_pages);
        }
        P(kern_printk("__free_pages wrapper\n");)
        __free_pages(page, order);
})



HOTPATCH_WRAPPER(__alloc_percpu, (size_t size, size_t align), {
        unsigned int retval = 0;
        enum section_state state;
        if(slub_allocator.__alloc_percpu != NULL){
            __alloc_percpu = (decltype(__alloc_percpu))(slub_allocator.__alloc_percpu);
        }
        void *addr = __alloc_percpu(size, align);
#ifdef CONFIG_USING_WATCHPOINT
        state = (enum section_state)get_section_state();
        if(state & KERNEL_WRAPPER_SET){
            handle_alloc_percpu(addr, size);
         //   retval = cfi_dump_stack();
            ADD_PERCPU_WATCHPOINT(addr, size);
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
        }
#endif
        kern_printk("__alloc_percpu wrapper  : %lx, %lx\n", addr, size);
        return addr;
})


HOTPATCH_WRAPPER_VOID(free_percpu, ( void* __pdata), {
        if(slub_allocator.free_percpu != NULL){
            free_percpu = (decltype(free_percpu))(slub_allocator.free_percpu);
        }
#ifdef CONFIG_USING_WATCHPOINT
        handle_free_percpu(__pdata);
        descriptor *meta_info = NULL;
        meta_info = WATCHPOINT_META(__pdata);
        if(NULL != meta_info) {
            uint64_t newval = 0x0ULL;
            uint64_t oldval = 0x0ULL;
            do {
                oldval = meta_info->state;
                newval = (meta_info->state & (~WP_MEMORY_ALLOCATED));
            }while(!__sync_bool_compare_and_swap(&(meta_info->state), oldval, newval));
        }

        REMOVE_PERCPU_WATCHPOINT(__pdata);
#endif
        free_percpu(__pdata);

})

#endif /* WRAPPER_HOTPATCH_H_ */
