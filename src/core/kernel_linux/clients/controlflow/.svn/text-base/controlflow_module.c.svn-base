#include <linux/module.h>
//#include "globals.h"
#include "dr_api.h"
#include "dr_kernel_utils.h"
#include "dr_ir_instr.h"
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/kallsyms.h>
#include "controlflow_module.h"
//#include <unistd.h>
#include "hashtable_client.h"

#define main_log_file "/home/akshayk/drk/src/core/mainlog.txt"
   
struct file *logfile;


MODULE_LICENSE("Dual BSD/GPL");

hashtable_t gtable;

hashtable_t return_hash;

int g_debug = 0;
bool update_hash = 0;

#define TESTALL(mask, var) (((mask) & (var)) == (mask))
#define TESTANY(mask, var) (((mask) & (var)) != 0)

static bool eflags_opt;

typedef struct {
    bool (*include)(instr_t *instr);
    const char *name;
} instr_counter_t;

static bool
always_include(instr_t *instr)
{
    return true;
}

void
update_hashtable(void);

instr_counter_t instr_counters[] = {
    {always_include, "total"},
    {instr_is_stringop, "stringop"},
    {instr_is_stringop_loop, "stringop_loop"},
};

#define NUM_INSTR_COUNTERS (sizeof(instr_counters) / sizeof(instr_counters[0]))

typedef struct {
    uint64 dynamic_count[NUM_INSTR_COUNTERS];
    uint64 static_count[NUM_INSTR_COUNTERS];
    uint64 eflags_saved;
    uint64 eflags_dead;
} instr_count_tls_t;

/* For easy access from stat reporting and error reporting code. They can't use
 * dr_get_current_drcontext b/c they run in the kernel context. */
DEFINE_PER_CPU(instr_count_tls_t*, instr_count_tls);

static instr_count_tls_t*
get_instr_count_tls(void)
{
    return __get_cpu_var(instr_count_tls);
}

static void
set_instr_count_tls(instr_count_tls_t* tls)
{
    /* GIANT HACK! Use Linux's per_cpu variable for instrcount TLS because DR
     * only provides TLS for a single client
     * (dcontext->client_data->user_field). We'd like to use instrcount with
     * other clients.
     */
    __get_cpu_var(instr_count_tls) = tls;
}

static void
thread_init_event(void *drcontext)
{
    instr_count_tls_t *tls = dr_thread_alloc(drcontext,
                                             sizeof(instr_count_tls_t));
    memset(tls, 0, sizeof(instr_count_tls_t));
    set_instr_count_tls(tls);
}

static void
thread_exit_event(void *drcontext)
{
    dr_thread_free(drcontext, get_instr_count_tls(), sizeof(instr_count_tls_t));
    set_instr_count_tls(NULL);
}

static void 
at_direct_call(app_pc instr_addr, app_pc target_addr)
{
    int *ret_hash = NULL;
    uint32 low;
    uint32 high;
    //printk(KERN_EMERG "Target address is not present in the hash table (direct call)\n");
    ret_hash = hashtable_lookup(&gtable, &target_addr);
    if(ret_hash == NULL)
    {
	low = (uint64)target_addr & 0xffffffff;
	high = ((uint64)target_addr >> 32 ) & 0xffffffff;
	printk(KERN_EMERG "Target address is not present in the hash table (direct call) %x%x\n",low,high);
	//printk(KERN_INFO "Error look this\n");    
    }
}

static void 
at_indirect_call(app_pc instr_addr, app_pc target_addr)
{
    int *ret_hash = NULL;
    uint32 low;
    uint32 high;
    ret_hash = hashtable_lookup(&gtable, &target_addr);
    //printk(KERN_EMERG "Target address is not present in the hash table (indirect call)\n");
    if(ret_hash == NULL)
    {
	low = (uint64)target_addr & 0xffffffff;
	high = ((uint64)target_addr >> 32 ) & 0xffffffff;
	printk(KERN_EMERG "Target address is not present in the hash table (indirect call) %x%x\n",low,high);
	//printk(KERN_INFO "Error look this\n"); 
    }
}

static void 
at_return(app_pc instr_addr, app_pc target_addr)
{
	//printk("return call : %x\n",target_addr);
}

static void 
at_ubr(app_pc instr_addr, app_pc target_addr)
{
	//printk("unconditional direct branch : %x\n", target_addr);
	return;
}

static void 
at_cbr(app_pc instr_addr, app_pc target_addr)
{
	//printk("conditional direct branch : %x\n", target_addr);
	return;
}

static dr_emit_flags_t
basic_block_event(void *drcontext, void *tag, instrlist_t *bb, bool for_trace, bool translating) 
{   
    instr_t *instr,*next_instr,*tgt, *last_instr;
    app_pc instr_address;
    opnd_t op;
    uint32 high, low;
    bool ret;
    char* name;
    ptr_uint_t addr;
    int *ret_hash = NULL;
    app_pc address_opnd = NULL;
    //printk(KERN_INFO "Error look this\n");

    if(translating == false)
    {

    	for(instr= instrlist_first(bb); instr != NULL; instr = next_instr)
    	{
		next_instr = instr_get_next(instr);

		if(!instr_opcode_valid(last_instr))
            	 	continue;

    		if(instr_is_cti(instr) && instr_num_srcs(instr))
   		{
			op = instr_get_target(instr);

			if(instr_is_call_direct(instr))
			{
				address_opnd = opnd_get_pc(op);
				ret_hash = hashtable_lookup(&gtable, &address_opnd);
				if(ret_hash == NULL)
				{
					//printk("direct address call is not present");
				}
			}else if(instr_is_call_indirect(instr))
			{
				if(opnd_is_near_pc(op))
				{
					dr_insert_call_instrumentation(drcontext, bb, instr, (app_pc)at_indirect_call);
				}
				else if(instr_is_mbr(instr)){
					dr_insert_mbr_instrumentation(drcontext, bb, instr, (app_pc)at_indirect_call, SPILL_SLOT_1);
				}
			
			}
   		}
	}
	
    }


    return DR_EMIT_DEFAULT;
}

static dr_emit_flags_t
trace_event(void *drcontext, void *tag, instrlist_t *bb, bool translating) {

    instr_t *instr,*next_instr,*tgt, *last_instr;
    app_pc instr_address;
    opnd_t op;
    uint32 high, low;
    bool ret;
    char* name;
    ptr_uint_t addr;
    int *ret_hash = NULL;
    app_pc address_opnd = NULL;

    if(translating == false)
    {

    	for(instr= instrlist_first(bb); instr != NULL; instr = next_instr)
    	{
		next_instr = instr_get_next(instr);

		if(!instr_opcode_valid(last_instr))
            	 	continue;

    		if(instr_is_cti(instr) && instr_num_srcs(instr))
   		{
			op = instr_get_target(instr);

			if(instr_is_call_direct(instr))
			{
				address_opnd = opnd_get_pc(op);
				ret_hash = hashtable_lookup(&gtable, &address_opnd);
				if(ret_hash == NULL)
				{
					//printk("direct address call is not present");
				}
				
			}else if(instr_is_call_indirect(instr))
			{
				if(opnd_is_near_pc(op))
				{
					dr_insert_call_instrumentation(drcontext, bb, instr, (app_pc)at_indirect_call);
				}
				else{
					dr_insert_mbr_instrumentation(drcontext, bb, instr, (app_pc)at_indirect_call, SPILL_SLOT_1);
				}
			
			}
   		}
	}
	
    }


  /*  instr_t *instr,*next_instr;
    app_pc instr_address;
    opnd_t op;
    bool ret;
    app_pc addr;
    for(instr= instrlist_first(bb); instr != NULL; instr = next_instr)
    {
	next_instr = instr_get_next(instr);
	instr_address = instr_get_app_pc(instr);
	
        if(!instr_opcode_valid(instr))
             continue;
	
	if(instr_is_cti(instr))
	{
	     	op = instr_get_target(instr);
	     	if(instr_is_ubr(instr)){
			if(opnd_is_near_pc(op))
			{
				dr_insert_ubr_instrumentation(drcontext, bb, instr, (app_pc)at_ubr);
			}
		}else if(instr_is_cbr(instr)){
			if(opnd_is_near_pc(op))
			{
				dr_insert_cbr_instrumentation(drcontext, bb, instr, (app_pc)at_cbr);
			}
		}else if(instr_is_call_direct(instr)){
			if(opnd_is_near_pc(op))
			{
				dr_insert_call_instrumentation(drcontext, bb, instr, (app_pc)at_direct_call);
			}
		} else if(instr_is_call_indirect(instr) && instr_is_mbr(instr)){
			if(opnd_is_near_pc(op)){
				dr_insert_mbr_instrumentation(drcontext, bb, instr, (app_pc)at_indirect_call, SPILL_SLOT_1);
			}
		}else if(instr_is_return(instr) && instr_is_mbr(instr)){
			if(opnd_is_near_pc(op)){
				dr_insert_mbr_instrumentation(drcontext, bb, instr, (app_pc)at_return, SPILL_SLOT_1);
			}
		}
	}
    }
*/
    return DR_EMIT_DEFAULT;
}

void add_hashtable(char * key)
{
     uint64 data = 0;
     int i = 0;
     int chr = 0;
     uint32 low, high;
     void *payload = dr_global_alloc(sizeof(int));
     for (i = 0; i< 16; i++)
     {
        chr = key[i];
	switch(chr)
	{
		case '0': case '1': case '2': case '3':
		case '4': case '5': case '6': case '7':
		case '8': case '9':
		        data =(data<<4)+(chr - '0');
			break;

		case 'a':		data =(data<<4)+10;
					break;

		case 'b': 		data =(data<<4)+11;
					break;

		case 'c':		data =(data<<4)+12;
					break;

		case 'd': 		data =(data<<4)+13;
					break;

		case 'e':		data =(data<<4)+14;
					break;

		case 'f': 		data =(data<<4)+15;
					break;
	}
     }
   //  low = data & 0xffffffff;
  //   high = (data >> 32 ) & 0xffffffff;
     //printk("%x%x : %d",high,low, payload);
     hashtable_add(&gtable, &data, payload);
}

void
update_hashtable(void)
{
    struct file *f;
    char *buf = dr_global_alloc(4096);
    char *char_key = dr_global_alloc(20);
    char *buf_temp, *buf_temp1;
    char *dynamo_find, mii_find;
    uint64 key =0;
    mm_segment_t fs;
    int i;
    int readret=0;
    char *ret = NULL;
    int count=0, len=0;

    f = filp_open("/proc/kallsyms", O_RDONLY, 0);
    if(f == NULL)
        printk(KERN_ALERT "filp_open error!!.\n");
    else{
        do{
                fs = get_fs();
                set_fs(get_ds());
                readret = f->f_op->read(f, buf, 4096, &f->f_pos);
		set_fs(fs);
		len = strcspn(buf,"\n");
		count = count+len+1;	
		buf_temp1 = buf;	
		buf_temp = strchr(buf, '\n');			
		while(buf_temp != NULL)
		{
			buf_temp1[len]= '\0';
			dynamo_find = strstr(buf_temp1, "dynamoro");
			//mii_find = strstr(buf_temp1, "mii");
			if((dynamo_find != NULL))
			{
				printk("found : %s",buf_temp1);
			}
			strncpy(char_key, buf_temp1, 16);
			char_key[17] = '\0';
			printk("%s\n",char_key);
			add_hashtable(char_key);
			buf_temp1 = buf_temp+1;
			len = strcspn(buf_temp1,"\n");			
			buf_temp = strchr(buf_temp+1, '\n');
			if(buf_temp != NULL)
			{
				count = count + len + 1;
			}
		}
		
               	f->f_pos = count;
        }while((readret > 0));
    }

    filp_close(f,NULL);
    dr_global_free(buf, 4096);
    dr_global_free(char_key, 20);
}

void
drinit(client_id_t id)
{

    //char *buf_endp;

    printk("drinit control flow %d\n", id);

    hashtable_init(&gtable, 8, HASH_INTPTR, false);
    update_hashtable();
    dr_register_thread_init_event(thread_init_event);
    dr_register_thread_exit_event(thread_exit_event);
    dr_register_bb_event(basic_block_event);
    dr_register_trace_event(trace_event);
//    dr_register_end_trace_event(end_trace_event);
}

static dr_stats_t stats;

static int __init
controlflow_init(void)
{
    if (dr_stats_init(&stats)) {
        return -ENOMEM;
    }
   // logfile = filp_open(main_log_file, O_WRONLY, 0);

#define ALLOC_STAT(name, fn) do {\
    if (dr_cpu_stat_alloc(&stats, #name, fn, THIS_MODULE)) {\
        goto failed;\
    } } while (0)
//    ALLOC_STAT(dynamic, show_cpu_dynamic_instr_count);
//    ALLOC_STAT(static, show_cpu_static_instr_count);
 //   ALLOC_STAT(stats, show_cpu_instr_count_stats);
#undef ALLOC_STAT
    return 0;
failed:
    dr_stats_free(&stats);
    return -ENOMEM;
}

static void __exit
controlflow_exit(void)
{
    dr_stats_free(&stats);
}

module_init(controlflow_init);
module_exit(controlflow_exit);

