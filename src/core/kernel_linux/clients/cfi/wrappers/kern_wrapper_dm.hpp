/*
 * kern_wrapper_dm.hpp
 *
 *  Created on: 2013-04-02
 *      Author: akshayk
 */

#ifndef KERN_WRAPPER_DM_HPP_
#define KERN_WRAPPER_DM_HPP_

extern void destroy_workqueue(struct workqueue_struct *wq);

FUNC_WRAPPER_VOID(destroy_workqueue, (struct workqueue_struct *wq), {
		destroy_workqueue(wq);
})

struct shrinker {
	int (*shrink)(struct shrinker *, struct shrink_control *sc);
	int seeks;      /* seeks to recreate an obj */
	long batch;     /* reclaim batch size, 0 = default */
	/* These are for internal use */
	struct list_head list;
	atomic_long_t nr_in_batch; /* objs pending delete */
};

extern void register_shrinker(struct shrinker *);
extern void unregister_shrinker(struct shrinker *);

FUNC_WRAPPER_VOID(register_shrinker, (struct shrinker *shr), {
		WRAP_FUNC(shr->shrink);
		register_shrinker(shr);
})

FUNC_WRAPPER_VOID(unregister_shrinker, (struct shrinker *shr), {
		WRAP_FUNC(shr->shrink);
		unregister_shrinker(shr);
})


#endif /* KERN_WRAPPER_DM_HPP_ */
