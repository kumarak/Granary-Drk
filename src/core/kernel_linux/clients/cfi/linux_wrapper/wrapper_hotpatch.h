/*
 * wrapper_hotpatch.h
 *
 *  Created on: 2013-05-22
 *      Author: akshayk
 */

#ifndef WRAPPER_HOTPATCH_H_
#define WRAPPER_HOTPATCH_H_


HOTPATCH_WRAPPER(__kmalloc, (size_t size, gfp_t flags), {
    function_t *wrap_func;
    unsigned int retval = 0;
    enum section_state state;
    uint i = 0;
    wrap_func = wrapped_functions[i];
    for(i = 0; wrap_func != NULL; wrap_func = wrapped_functions[++i]){
         if(wrap_func->start == (void*)__kmalloc){
              P(kern_printk("__kmalloc : %llx, wrap_start : %llx", __kmalloc, wrap_func->start);)
              __kmalloc = (decltype(__kmalloc))(wrap_func->replace_func);
              break;
          }
    }
    void *watchpoint_addr = __kmalloc(size, flags);
#ifdef CONFIG_USING_WATCHPOINT
    state = (enum section_state)get_section_state();
    if(state & KERNEL_WRAPPER_SET){
        retval = cfi_dump_stack();
        kern_printk("ADD_WATCHPOINT with this pointer\n");
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
    }
#endif
    return watchpoint_addr;
})



HOTPATCH_WRAPPER_VOID(kfree, ( void* addr), {
    function_t *wrap_func;
    uint i = 0;
    wrap_func = wrapped_functions[i];
    for(i = 0; wrap_func != NULL; wrap_func = wrapped_functions[++i]){
        if(wrap_func->start == (void*)kfree){
            P(kern_printk("kfree : %llx, wrap_start : %llx", kfree, wrap_func->start);)
            kfree = (decltype(kfree))(wrap_func->replace_func);
            break;
        }
    }
#ifdef CONFIG_USING_WATCHPOINT
        watchpoint_descriptor *meta_info = NULL;
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


//void *__kmalloc_node(size_t size, gfp_t flags, int node);
HOTPATCH_WRAPPER(__kmalloc_node, (size_t size, gfp_t flags, int node), {
    kern_printk("__kmalloc_node wrapper\n");
    return __kmalloc_node(size, flags, node);
})

//void *__kmalloc_track_caller(size_t, gfp_t, unsigned long);
HOTPATCH_WRAPPER(__kmalloc_track_caller, (size_t size, gfp_t flags, unsigned long caller), {
    kern_printk("__kmalloc_track_caller wrapper\n");
    return __kmalloc_track_caller(size, flags, caller);
})

//void *__kmalloc_node_track_caller(size_t, gfp_t, int, unsigned long);
HOTPATCH_WRAPPER(__kmalloc_node_track_caller, (size_t size, gfp_t flags, int node, unsigned long caller), {
    kern_printk("__kmalloc_node_track_caller wrapper\n");
    return __kmalloc_node_track_caller(size, flags, node, caller);
})

//volatile uint64_t watchpoint_counter = 0;

/*  The wrapper for kmem_cache_alloc
 *
 */
HOTPATCH_WRAPPER(kmem_cache_alloc, (struct kmem_cache *s, gfp_t gfpflags), {
    function_t *wrap_func;
    unsigned int retval = 0;
    enum section_state state;
    uint i = 0;
    wrap_func = wrapped_functions[i];
    for(i = 0; wrap_func != NULL; wrap_func = wrapped_functions[++i]){
        if(wrap_func->start == (void*)kmem_cache_alloc){
            P(kern_printk("kmem_cache_alloc : %llx, wrap_start : %llx", kmem_cache_alloc, wrap_func->start);)
            kmem_cache_alloc = (decltype(kmem_cache_alloc))(wrap_func->replace_func);
            break;
        }
    }
    void *watch_ptr = kmem_cache_alloc(s, gfpflags);

#ifdef CONFIG_USING_WATCHPOINT

    state = (enum section_state)get_section_state();
    if(state & KERNEL_WRAPPER_SET){
        //uint64_t counter((uint64_t)__sync_fetch_and_add(&(watchpoint_counter), 0x1));
        //if (counter < 10) {
            retval = cfi_dump_stack();
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
            kern_printk("ADD_WATCHPOINT with this pointer : %llx\n",watch_ptr );
       // }
    }
#endif
    return watch_ptr;
})


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
      //  uint64_t counter((uint64_t)__sync_fetch_and_add(&(watchpoint_counter), 0x1));
      //  if (counter < 10) {
            retval = cfi_dump_stack();
            kern_printk("ADD_WATCHPOINT with this pointer\n");
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
        //}
    }
#endif
    return watch_ptr;
})
//void *kmem_cache_alloc_node(struct kmem_cache *cachep, gfp_t flags, int nodeid)
HOTPATCH_WRAPPER(kmem_cache_alloc_node, (struct kmem_cache *cachep, gfp_t flags, int nodeid), {
    kern_printk("kmem_cache_alloc_node wrapper\n");
    return kmem_cache_alloc_node(cachep, flags, nodeid);
})

//void kmem_cache_free(struct kmem_cache *, void *);
HOTPATCH_WRAPPER_VOID(kmem_cache_free, (struct kmem_cache *s, void *ptr), {
    P(kern_printk("kmem_cache_free wrapper : %lx\n", ptr);)
    function_t *wrap_func;
    uint i = 0;
    wrap_func = wrapped_functions[i];
    for( i = 0; wrap_func != NULL; wrap_func = wrapped_functions[++i]){
        if(wrap_func->start == (void*)kmem_cache_free){
            P(kern_printk("kmem_cache_free : %llx, wrap_start : %llx", kmem_cache_free, wrap_func->start);)
            kmem_cache_free = (decltype(kmem_cache_free))(wrap_func->replace_func);
            break;
        }
    }
#ifdef CONFIG_USING_WATCHPOINT
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
    void* addr= (void*)__get_free_pages(gfp_mask, order);
    P(kern_printk("__get_free_pages wrapper : %lx\n", addr);)
    return (unsigned long)addr;
})

//void __free_pages(struct page *page, unsigned int order)
HOTPATCH_WRAPPER_VOID(__free_pages, (struct page *page, unsigned int order), {
    P(kern_printk("__free_pages wrapper\n");)
    __free_pages(page, order);
})



HOTPATCH_WRAPPER(__alloc_percpu, (size_t size, size_t align), {
        function_t *wrap_func;
        uint i = 0;
        unsigned int retval = 0;
        enum section_state state;
        wrap_func = wrapped_functions[i];
        for(i = 0; wrap_func != NULL; wrap_func = wrapped_functions[++i]){
            if(wrap_func->start == (void*)__alloc_percpu){
                P(kern_printk("__alloc_percpu : %llx, wrap_start : %llx", __alloc_percpu, wrap_func->start);)
                __alloc_percpu = (decltype(__alloc_percpu))(wrap_func->replace_func);
                break;
            }
        }
        void *addr = __alloc_percpu(size, align);
#ifdef CONFIG_USING_WATCHPOINT
        state = (enum section_state)get_section_state();
        if(state & KERNEL_WRAPPER_SET){
            retval = cfi_dump_stack();
            ADD_WATCHPOINT(addr, size);
            watchpoint_descriptor *meta_info = NULL;
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
        return addr;
})


HOTPATCH_WRAPPER_VOID(free_percpu, ( void* __pdata), {
        function_t *wrap_func;
        uint i = 0;
        wrap_func = wrapped_functions[i];

        for(i = 0; wrap_func != NULL; wrap_func = wrapped_functions[++i]){
            if(wrap_func->start == (void*)free_percpu){
                P(kern_printk("free_percpu : %llx, wrap_start : %llx", free_percpu, wrap_func->start);)
                free_percpu = (decltype(free_percpu))(wrap_func->replace_func);
                break;
            }
        }
#ifdef CONFIG_USING_WATCHPOINT
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
        free_percpu(__pdata);

})

#endif /* WRAPPER_HOTPATCH_H_ */
