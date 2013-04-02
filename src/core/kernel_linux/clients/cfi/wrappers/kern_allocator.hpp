/*
 * kern_allocator.hpp
 *
 *  Created on: 2013-04-01
 *      Author: akshayk
 */

#ifndef KERN_ALLOCATOR_HPP_
#define KERN_ALLOCATOR_HPP_


FUNC_WRAPPER(__kmalloc, (size_t size, gfp_t flags), {
    unsigned int value;
    int i = 0;
    void *watch_ptr = __kmalloc(size, flags);
    uint64_t base = (uint64_t)watch_ptr;
    uint64_t limit = base + size;
#ifdef CFI_NO_WATCHPOINT
    ADD_WATCHPOINT(watch_ptr, size);
    struct alisa_meta *meta_info = (struct alisa_meta*)WATCHPOINT_META(watch_ptr);
    REMOVE_WATCHPOINT(watch_ptr);
    while(base < limit){
    	hashmap_put(module_watchpoint_map, (void*)base, (void*)meta_info);
    	base = base+8;//++;
    }
#else
    ADD_WATCHPOINT(watch_ptr, size);
#endif
    granary_lc_handle_alloc(target_module, watch_ptr, size, NULL);
    kern_printk("__kmalloc wrapper  : %lx, %lx\n", watch_ptr, size);
    return watch_ptr;
})

FUNC_WRAPPER(kfree, ( void* addr), {
	kern_printk("kfree wrapper : %lx\n", addr);
	int i = 0;
	void *base = addr;
	struct alias_meta *meta_info = NULL;
	granary_lc_handle_free(target_module, addr, NULL);
#ifdef CFI_NO_WATCHPOINT
    if(hashmap_get(module_watchpoint_map, (void*)base, (void**)&meta_info)){
    	if(meta_info != NULL){
    		while((unsigned long)base >= (unsigned long)meta_info->limit){
    			hashmap_delete(module_watchpoint_map, (void*)base);
    			base = base+1;//++;
    		}
    	}
    }
#else
    REMOVE_WATCHPOINT(addr);
#endif
    return kfree(addr);
})

//void * __must_check __krealloc(const void *, size_t, gfp_t);
FUNC_WRAPPER(__krealloc, (const void* ptr, size_t size, gfp_t flags), {
    kern_printk("__krealloc wrapper\n");
    void *watch_ptr = __krealloc(ptr, size, flags);
    //granary_lc_handle_alloc(target_module, watch_ptr, size, NULL);
    return watch_ptr;
})

//void * __must_check krealloc(const void *, size_t, gfp_t);
FUNC_WRAPPER(krealloc, (const void* ptr, size_t size, gfp_t flags), {
    kern_printk("krealloc wrapper\n");
    void *watch_ptr = krealloc(ptr, size, flags);
    //granary_lc_handle_alloc(target_module, watch_ptr, size, NULL);
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
    uint64_t base = (uint64_t)watch_ptr;
    uint64_t limit = base + s->size;
    unsigned int i = 0;
#ifdef CFI_NO_WATCHPOINT
    ADD_WATCHPOINT(watch_ptr, s->size);
    struct alisa_meta *meta_info = (struct alisa_meta*)WATCHPOINT_META(watch_ptr);
    REMOVE_WATCHPOINT(watch_ptr);
    while(base < limit){
    	hashmap_put(module_watchpoint_map, (void*)base, (void*)meta_info);
    	base = base+8;
    }
#else
    ADD_WATCHPOINT(watch_ptr, s->size);
    if(s->ctor != NULL)
        s->ctor(watch_ptr);
#endif
    granary_lc_handle_alloc(target_module, watch_ptr, s->size, NULL);
    kern_printk("kmem_cache_alloc wrapper : %lx  : %lx\n", (uint64_t)watch_ptr, s->size);
    return watch_ptr;
})


FUNC_WRAPPER(kmem_cache_alloc_trace, (struct kmem_cache *s, gfp_t gfpflags, size_t size), {
    void *watch_ptr = kmem_cache_alloc_trace(s, gfpflags, size);
    uint64_t base = (uint64_t)watch_ptr;
    uint64_t limit = base + s->size;
    unsigned int i = 0;
#ifdef CFI_NO_WATCHPOINT
    ADD_WATCHPOINT(watch_ptr, s->size);
    struct alisa_meta *meta_info = (struct alisa_meta*)WATCHPOINT_META(watch_ptr);
    REMOVE_WATCHPOINT(watch_ptr);
    while(base < limit){
    	hashmap_put(module_watchpoint_map, (void*)base, (void*)meta_info);
    	base = base+8;
    }
#else
    ADD_WATCHPOINT(watch_ptr, s->size);
    if(s->ctor != NULL)
        s->ctor(watch_ptr);
#endif
    granary_lc_handle_alloc(target_module, watch_ptr, s->size, NULL);
    kern_printk("kmem_cache_alloc wrapper : %lx  : %lx\n", (uint64_t)watch_ptr, s->size);
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
    void *base = ptr;
    struct alias_meta *meta_info = NULL;
    granary_lc_handle_free(target_module, ptr, NULL);
#ifdef CFI_NO_WATCHPOINT
    if(hashmap_get(module_watchpoint_map, (void*)base, (void**)&meta_info)){
    	if(meta_info != NULL){
    		while((unsigned long)base >= (unsigned long)meta_info->limit){
    			hashmap_delete(module_watchpoint_map, (void*)base);
    			base = base+1;
    		}
    	}
    }
    //hashmap_delete(module_watchpoint_map, (void*)ptr);
#else
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
    ADD_WATCHPOINT(ptr);
    return ptr;
})

//extern void vfree ( void * addr ) ;
FUNC_WRAPPER_VOID(vfree, ( void * addr ), {
    kern_printk("vfree wrapper\n");
    REMOVE_WATCHPOINT(addr);
    vfree(addr);
})

//void *vmalloc_node(unsigned long size, int node)
FUNC_WRAPPER(vmalloc_node, (unsigned long size, int node), {
    kern_printk("vmalloc_node wrapper\n");
    void *ptr = vmalloc_node(size, node);
   // if (ptr != NULL)
           // granary_lc_handle_alloc(target_module, ptr, size, NULL);

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
    ADD_WATCHPOINT(addr);
    granary_lc_handle_alloc(target_module, addr, order*PAGE_SIZE, NULL);
    kern_printk("__get_free_pages wrapper : %lx\n", addr);
    return (unsigned long)addr;
})

//void __free_pages(struct page *page, unsigned int order)
FUNC_WRAPPER_VOID(__free_pages, (struct page *page, unsigned int order), {
    kern_printk("__free_pages wrapper\n");
    REMOVE_WATCHPOINT(page);
    granary_lc_handle_free(target_module, page, NULL);
    __free_pages(page, order);
})


#endif /* KERN_ALLOCATOR_HPP_ */
