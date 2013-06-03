/*
 * slubx.h
 *
 *  Created on: 2013-05-17
 *      Author: akshayk
 */

#define WRAP_FUNCTION_NORET(name, nargs, ...)\
    WRAP_FUNCTION(name, reg_t, nargs, __VA_ARGS__)

    WRAP_FUNCTION_NORET(kfree, 1, const void *)
    WRAP_FUNCTION(__kmalloc, void *, 2, size_t, gfp_t)
    WRAP_FUNCTION_NORET(free_percpu, 1, void *)
    WRAP_FUNCTION(__alloc_percpu, void *, 2, size_t, size_t)
    WRAP_FUNCTION(kmem_cache_alloc, void *, 2, struct kmem_cache*, gfp_t)
  //  WRAP_FUNCTION(kmem_cache_alloc_trace, void *, 3, struct kmem_cache*, gfp_t, size_t)
    WRAP_FUNCTION_NORET(kmem_cache_free, 2, struct kmem_cache *, void *)
    //extern void * kmem_cache_alloc_trace ( struct kmem_cache * s , gfp_t gfpflags , size_t size ) ;
    /*WRAP_FUNCTION(__kmalloc_node, void *, 3, size_t, gfp_t, int)
    WRAP_FUNCTION(__kmalloc_track_caller, void *, 3, size_t, gfp_t, unsigned long)
    WRAP_FUNCTION(__kmalloc_node_track_caller, void *, 4, size_t, gfp_t, int, unsigned long)
    *///WRAP_FUNCTION(kmem_cache_alloc, void *, 2, struct kmem_cache*, gfp_t)
    /*WRAP_FUNCTION(kmem_cache_alloc_node, void *, 3, struct kmem_cache *, gfp_t, int)
    *///WRAP_FUNCTION_NORET(kmem_cache_free, 2, struct kmem_cache *, void *)
    /*WRAP_FUNCTION(new_slab, struct page *, 3, struct kmem_cache *, gfp_t, int)
    WRAP_FUNCTION_NORET(__free_slab, 2, struct kmem_cache *, struct page *)
    *//*SLUB_FUNCTION_NORET(schedule, 0)
  */  /* Include these so the stack traces work properly. */
    /*WRAP_FUNCTION(kmem_cache_create, struct kmem_cache *, 5, const char *, size_t, size_t, unsigned long, void (*)(void *))
    WRAP_FUNCTION(kmem_cache_shrink, int, 1, struct kmem_cache *)
    WRAP_FUNCTION_NORET(kmem_cache_destroy, 1, struct kmem_cache *)
    WRAP_FUNCTION(ksize, size_t, 1, const void *)
    *//* These ones are important because of interprocessor interrupts. On the
     * CPUs that receive the IPIs these functions aren't called by public slab
     * functions. Instead, they're called by smp_call_function. */
     /* TODO(peter): A proper solution would be to detect when a CPU inside of a
      * slab function is issuing an IPI. Doing this would set in_slab on all of
      * the other CPUs.
      */
    /*WRAP_FUNCTION_NORET(flush_cpu_slab, 1, void *)
    WRAP_FUNCTION_NORET(deactivate_slab, 2, struct kmem_cache *, struct kmem_cache_cpu*)
*/
    /* These functions we need to wrap to suppress false positives with
     * check_defined. */
    //WARP_FUNCTION(skb_clone, struct sk_buff *, 2, struct sk_buff *, gfp_t)

    /* Functions wrapped for stack checking. */
  //  WRAP_FUNCTION_NORET(free_task, 1, struct task_struct *)
    /* copy_process has a bunch of arguments, but we don't care about them. */
    //SLUB_FUNCTION(copy_process, struct task_struct *, 0)


