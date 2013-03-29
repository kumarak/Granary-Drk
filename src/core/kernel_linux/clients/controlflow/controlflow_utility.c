#include "controlflow_module.h"
#include "globals.h"

static int g_debug = 0;
void check_code_origin_validity(void *addr, void *ret)
{
	app_pc instr_addr = (app_pc)addr;
	if(!is_executable_address(instr_addr) )
	{
		g_debug++;
		if(g_debug < 10)
		{
			printk("code origin policy violated\n");
		}
	} else if(is_executable_area_writable(instr_addr))
	{
		g_debug++;
		if(g_debug < 10)
		{
			printk("code origin policy violated writable\n");
		}
	}
}
