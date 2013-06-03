
import re

def get_func_symbol_names(host_file_name, client_file_name):
    """Given the name of file that is a copy of System.map, return a dictionary mapping the
    low 32-bits of the kernel addresses to their function names."""
    
    func_pattern = re.compile(r"^(f+[a-f0-9]+) (t|T) ([a-zA-Z0-9_]+)$")
    names = set()
    get_symbol_addr = "0"
    get_symbol_gpl_addr = "0"
    vmalloc_area_addr = "0"
    vmalloc_node_range_addr = "0"
    printk_addr = "0"
    module_alloc_addr = "0"
    __kernel_text_address = "0"
	
    try:
        with open(host_file_name, "r") as hf:
            with open(client_file_name, "r") as cf:

                # go get some non-exported addresses on the host machine
                # this is needed because the host/client aren't necessarily
                # the same, and so the addresses of various functions will
                # differ
                for line in hf:
                    m = func_pattern.search(line)
                    if not m:
                        continue

                    func_name = m.group(3).strip(" \r\n\t")
                    
                    if "__symbol_get" == func_name:
                        get_symbol_addr = m.group(1)
                    
                    if "__symbol_get_gpl" == func_name:
                        get_symbol_gpl_addr = m.group(1)

                # go get the non-exported stuff on the client machine
                for line in cf:
                    m = func_pattern.search(line)
                    if not m:
                        continue

                    func_name = m.group(3).strip(" \r\n\t")
                    names.add(func_name)
                    
                    if "__vmalloc_area" == func_name:
                        vmalloc_area_addr = m.group(1)

		    if "__vmalloc_node_range" == func_name:
			vmalloc_node_range_addr = m.group(1)
                    
                    if "printk" == func_name:
                        printk_addr = m.group(1)

                    if "module_alloc_update_bounds" == func_name:
                        module_alloc_addr = m.group(1)

		    if "__kernel_text_address" == func_name:
			__kernel_text_address = m.group(1)
                    
    except IOError:
        pass
    return get_symbol_addr, get_symbol_gpl_addr, vmalloc_area_addr, vmalloc_node_range_addr, printk_addr, module_alloc_addr, __kernel_text_address, names

if __name__ == "__main__":
    addr, gpl_addr, vmalloc_addr, vmalloc_node_range_addr, printk_addr, module_alloc_addr, __kernel_text_address, syms = get_func_symbol_names("host_map.txt", "client_map.txt")
    with open("all_symbols.inc", "w") as f:
        for sym_name in syms:
            f.write("\"%s\",\n" % sym_name)
    with open("symbol_get_addr.h", "w") as f:
        f.write("""
/* hard-coded address of symbol getting functions */
enum {
    SYMBOL_GET_ADDR = 0x%sULL,
    SYMBOL_GET_GPL_ADDR = 0x%sULL,
    VMALLOC_AREA_ADDR = 0x%sULL,
    VMALLOC_NODE_RANGE = 0x%sULL,
    PRINTK_ADDR = 0x%sULL,
    MODULE_ALLOC = 0x%sULL,
    __KERNEL_TEXT_ADDRESS = 0x%sULL
};

""" % (addr, gpl_addr, vmalloc_addr, vmalloc_node_range_addr, printk_addr, module_alloc_addr, __kernel_text_address))
