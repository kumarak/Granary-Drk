#!/usr/bin/python

import re, struct, sys
import os, fnmatch
import pickle


printk_addr = "0"
sys_getpid = "0"
sys_gettid = "0"

def find_files(directory, pattern):
    for root, dirs, files in os.walk(directory):
        for basename in files:
            if fnmatch.fnmatch(basename, pattern):
                filename = os.path.join(root, basename)
                yield filename

def kern_addr_to_int(addr):
    """Convert a 64-bit hexadecimal address to a 32-bit number representing only the low order
    32 bits."""
    assert ('f' * 8) == addr[:8]
    return int(addr[8:], 16)

def get_exported_funcs(exported_syms_file_name, file_name):
    """Given the name of file that is a copy of System.map, return a dictionary mapping the
    low 32-bits of the kernel addresses to their function names."""
    
    global printk_addr
    global sys_getpid
    global sys_gettid
    
    func_pattern = re.compile(r"^(f+[a-f0-9]+) (t|T) ([a-zA-Z0-9_]+)$")
    addr_to_name = { }
    exported = set()
    
    try:
        with open(exported_syms_file_name, "rb") as f:
            exported = pickle.load(f)
    except IOError:
        print "WARNING: cfi/symbols/exported_syms might not exist. Make sure to run (with sudo) cfi/symbols/make_module.sh"
        
    try:
        with open(file_name, "r") as f:
            for line in f:
                m = func_pattern.search(line)
                if not m:
                    continue
                addr, name = m.group(1), m.group(3)
                if "printk" == name:
                    assert "0" == printk_addr
                    printk_addr = addr
		
                if "sys_getpid" == name:
                    sys_getpid = addr

                if "sys_gettid" == name:
                    sys_gettid = addr
                    
                elif len(exported) and name not in exported:
                    continue
                addr_to_name[kern_addr_to_int(addr)] = (addr, name)
    except IOError:
        pass
    return addr_to_name

def hash(d, addr):
    """Hash a 32-bit address."""
    if d == 0: 
        d = 0x01000193

    # Use the FNV algorithm from http://isthe.com/chongo/tech/comp/fnv/ 
    for c in (struct.pack('I', addr)):
        d = ( (d * 0x01000193) ^ ord(c) ) & 0xffffffff

    return d

# Computes a minimal perfect hash table using the given python dictionary. It
# returns a tuple (G, V). G and V are both arrays. G contains the uintermediate
# table of values needed to compute the index of the value in V. V contains the
# values of the dictionary.
#
# Created by Steve Hanov
def min_perf_hash( dict ):
    size = len(dict)

    # Step 1: Place all of the keys uinto buckets
    buckets = [ [] for i in range(size) ]
    G = [0] * size
    values = [None] * size
    
    for key in dict.keys():
        buckets[hash(0, key) % size].append( key )

    # Step 2: Sort the buckets and process the ones with the most items first.
    buckets.sort( key=len, reverse=True )        
    for b in xrange( size ):
        bucket = buckets[b]
        if len(bucket) <= 1: break
        
        d = 1
        item = 0
        slots = []

        # Repeatedly try different values of d until we find a hash function
        # that places all items in the bucket uinto free slots
        while item < len(bucket):
            slot = hash( d, bucket[item] ) % size
            if values[slot] != None or slot in slots:
                d += 1
                item = 0
                slots = []
            else:
                slots.append( slot )
                item += 1

        G[hash(0, bucket[0]) % size] = d
        for i in range(len(bucket)):
            values[slots[i]] = dict[bucket[i]]

        #if ( b % 1000 ) == 0:
        #    pruint "bucket %d    r" % (b),
        #    sys.stdout.flush()

    # Only buckets with 1 item remain. Process them more quickly by directly
    # placing them uinto a free slot. Use a negative value of d to indicate
    # this.
    freelist = []
    for i in xrange(size): 
        if values[i] == None: freelist.append( i )

    for b in xrange( b, size ):
        bucket = buckets[b]
        if len(bucket) == 0: break
        slot = freelist.pop()
        # We subtract one to ensure it's negative even if the zeroeth slot was
        # used.
        G[hash(0, bucket[0]) % size] = -slot-1 
        values[slot] = dict[bucket[0]]

    return (G, values)

def get_white_list(white_list_file):
    """Get the set of all functions that we have wrappers for. This might more accurately be
    named a black list. Oh well."""
    ls = set()
    try:
        with open(white_list_file) as f:
            for func_name in f:
                ls.add(func_name.strip())
    except IOError:
        pass

    return ls

def do_write_wrappers(G, V, s, white_list_file):
    """Output the code the wraps the functions and contains the static hash table."""
    global printk_addr

    s.write("""
#include <stdint.h>
extern \"C\" {
#    include "wrappers/kernel_types.h"
}
#include "cfi_wrapper.hpp"
#include "cfi_wrapper.h"
void *__gxx_personality_v0; // for C-compatibility, even though runtime support for CXX exceptions is turned off

""")
    
    # write out the lookup table helper
    s.write("static const int32_t G[] = {\n    ")
    i = 0
    for g in G:
        if 20 == i:
            s.write("\n    ")
            i = 0
        s.write("%d, " % g)
        i += 1

    s.write("\n};\n\n")

    # write out the template instantiations to wrap the kernel functions
    s.write("#define CFI_WRAP(a, f) {(cfi_type_erased_func_ptr) a, cfi_wrapper<a>(f), #f}\n")
    s.write("#define CFI_PASS(a, f) {(cfi_type_erased_func_ptr) a, (cfi_type_erased_func_ptr) a, #f}\n")
    s.write("typedef struct cfi_wrapper_info {cfi_type_erased_func_ptr original, wrapper; const char *name; } cfi_wrapper_info;");
    s.write("static cfi_wrapper_info V[] = {\n");
    funcs_to_wrap = get_white_list(white_list_file)
    for func_addr, func_name in V:
        if func_name in funcs_to_wrap:
            s.write("    CFI_WRAP(0x%s, %s),\n" % (func_addr, func_name))
        else:
            s.write("    CFI_PASS(0x%s, %s),\n" % (func_addr, func_name))
    s.write("};\n\n")

    # write out the hash function to get a kernel function wrapper
    s.write("""
static uint32_t hash_addr(uint32_t d, uint32_t addr) {
    if(0 == d) { 
        d = 0x01000193;
    }

    // Use the a slightly modified FNV algorithm from
    // http://isthe.com/chongo/tech/comp/fnv/ 

    d = ( (d * 0x01000193) ^ (addr & 0xFF)) & 0xffffffff;
    addr >>= 8;
    d = ( (d * 0x01000193) ^ (addr & 0xFF)) & 0xffffffff;
    addr >>= 8;
    d = ( (d * 0x01000193) ^ (addr & 0xFF)) & 0xffffffff;
    addr >>= 8;
    d = ( (d * 0x01000193) ^ (addr & 0xFF)) & 0xffffffff;

    return d;

    (void) __gxx_personality_v0;
}
    """)

    s.write("""
enum {
    NUM_EXPORTED_FUNCS = %d
};
extern "C" {
#include <string.h>
    cfi_type_erased_func_ptr cfi_to_shadow_address(cfi_type_erased_func_ptr addr) {
        return to_shadow_address(addr);
    }

    cfi_type_erased_func_ptr cfi_get_kernel_wrapper(cfi_type_erased_func_ptr addr) {
	return addr;
        typedef int (printf_type)(const char *, ...);
        typedef int (sys_getpid)(void);
        printf_type *kern_printk = (printf_type *) 0x%s;
        sys_getpid *kern_getpid = (sys_getpid *) 0x%s;
        sys_getpid *kern_gettid = (sys_getpid *) 0x%s;

        uint64_t addr_as_i64 = (uint64_t) addr;
        uint32_t low_bits = (uint32_t) addr_as_i64;
        int32_t d = G[hash_addr(0, low_bits) %% NUM_EXPORTED_FUNCS];
        cfi_type_erased_func_ptr ret;
        cfi_wrapper_info *w;
        
        //kern_printk("addr_as_i64=%%lu low_bits=%%u d=%%d ", addr_as_i64, low_bits, d);
        //(void) kern_printk;
        
        if(d < 0) {
            d = -d - 1;
        } else {
            d = hash_addr(d, low_bits) %% NUM_EXPORTED_FUNCS;
        }
        
        w = &(V[d]);
        
        if(w->original == addr) {
            //if(w[1] == w[0]) {
            //    kern_printk("calling unwrapped function %%lx\\n", addr_as_i64);
            //}
            //kern_printk("call : pid ('%%d') tid ( '%%d')'%%s'\\n", kern_getpid(), kern_gettid(), w->name);
            ret = w->wrapper;
        } else {
            //kern_printk("calling unexported function %%lx\\n", addr_as_i64);
            //ret = (cfi_type_erased_func_ptr) 0;
            ret = addr;
        }

        (void) kern_getpid;
        (void) kern_gettid;
        (void) kern_printk;
        
        //memcpy(&addr_as_i64, (void *) &ret, 8);
        //kern_printk("d=%%d ret=%%lu\\n", d, addr_as_i64);

        return ret;
    }
}
    """ % (len(V), printk_addr, sys_getpid, sys_gettid))

def write_wrappers(exported_syms_file_name, map_file_name, white_list_file_name, out_source, out_addrs):
    G, V = min_perf_hash(get_exported_funcs(exported_syms_file_name, map_file_name))
    
    with open(out_source, "w") as s:
        do_write_wrappers(G, V, s, white_list_file_name)

    with open(out_addrs, "w") as s:
        for func_addr, func_name in V:
            s.write("#define KERN_ADDR_%s 0x%sULL\n" % (func_name, func_addr))

if "__main__" == __name__ and 1 < len(sys.argv):
    print "not working"
    write_wrappers(
        os.path.join(sys.argv[1], "symbols/exported_syms"),
        os.path.join(sys.argv[1], "wrappers/map.txt"), 
        os.path.join(sys.argv[1], "wrappers/white_list.txt"), 
        os.path.join(sys.argv[1], "cfi_wrapper.cc"),
        os.path.join(sys.argv[1], "cfi_kernel_addresses.h")
    )
