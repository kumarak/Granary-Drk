/*
 * drk_memtracer.c
 *
 *  Created on: 2012-11-10
 *      Author: akshayk
 */

#include <linux/module.h>
#include "dr_api.h"
#include "drk_memtracer.h"

MODULE_LICENSE("Dual BSD/GPL");

static void
instrument_mem_write(void *drcontext, instrlist_t *ilist, instr_t *where,
               int pos, bool write)
{
	instr_t *instr, *call, *restore;
	opnd_t ref, opnd1, opnd2;
}

static dr_emit_flags_t
basic_block_event(void *drcontext, void *tag, instrlist_t *bb, bool for_trace, bool translating)
{
	instr_t *instr;
	int i;
//	printk("%s\n", __FUNCTION__);
/*	for(instr = instrlist_first(bb); instr != NULL; instr = instr_get_next(instr))
	{
		if(instr_get_app_pc(instr) == NULL)
			continue;

		if(instr_writes_memory(instr))
		{
			for(i = 0; i < instr_num_dsts(instr); i++)
			{
				if(opnd_is_memory_reference(instr_get_dst(instr, i))) {
					instrument_mem_write(drcontext, bb, instr, i, true);
				}
			}
		}
	}
*/
	return DR_EMIT_DEFAULT;
}


static void
thread_init_event(void *drcontext)
{
	printk("%s\n", __FUNCTION__);
    char logname[MAXIMUM_PATH];
    char *dirsep;
    int len;
}

static void
thread_exit_event(void *drcontext)
{
	printk("%s\n", __FUNCTION__);
}


void
drinit(client_id_t id)
{
    printk("drinit memtracer %d\n", id);

   // dr_register_thread_init_event(thread_init_event);
   // dr_register_thread_exit_event(thread_exit_event);
    dr_register_bb_event(basic_block_event);

}

static int __init
memtracer_init(void)
{
    return 0;
}

static void __exit
memtracer_exit(void)
{

}


module_init(memtracer_init);
module_exit(memtracer_exit);
