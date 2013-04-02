#include <linux/module.h>
#include "dr_api.h"
MODULE_LICENSE("Dual BSD/GPL");

static int 
detector_notifier_call(struct notifier_block *nb,
	unsigned long mod_state, void *vmod)
{
//	int i =0;
	struct module* mod = (struct module *)vmod;

	if(mod_state == MODULE_STATE_LIVE)
	{
		printk("module is loaded now\n");
		printk("module info : %lu\t%lu\t%lu\t%lu", (unsigned long)mod->module_init, (unsigned long)mod->module_core, (unsigned long)mod->init_size, (unsigned long)mod->core_size);
	}
	return 0;
}

struct notifier_block detector_nb = {
	.notifier_call = detector_notifier_call,
	.next = NULL,
	.priority = -1, 
};



static dr_emit_flags_t
bb_event(void *drcontext, void *tag, instrlist_t *bb, bool for_trace,
         bool translating) {
    return DR_EMIT_DEFAULT;    
}

void
drinit(client_id_t id)
{
    printk("drinit null %d\n", id);
    dr_register_bb_event(bb_event);
    register_module_notifier(&detector_nb);
}
