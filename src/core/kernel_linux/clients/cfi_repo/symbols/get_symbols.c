/*
 * get_symbols.c
 *
 *  Created on: 2012-04-25
 *      Author: pag
 *     Version: $Id$
 */


#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>

#include "symbol_get_addr.h"

#ifdef symbol_get
#   undef symbol_get
#endif

#define SUCCESS 0

MODULE_LICENSE("GPL");

#define DEVICE_NAME "get_symbols"
#define DEVICE_FILE_NAME "get_symbols"
#define GET_SYMBOLS_MINOR 0

typedef void *(symbol_get_func)(const char *);

/// fake symbol getter iff one of the symbol_get or symbol_get_gpl don't exist
static void *fake_symbol_get(const char *ignored) {
    (void) ignored;
    return NULL;
}

/// return a function for looking up symbols given an (possibly zero) address
/// of a kernel function that should be able to look up the symbols
static symbol_get_func *symbol_getter(unsigned long long addr) {
    if(0 == addr) {
        return &fake_symbol_get;
    } else {
        return (symbol_get_func *) addr;
    }
}

/// all function names from System.map
static const char *all_symbol_names[] = {
#   include "all_symbols.inc"
};

enum {
    NUM_NAMES = sizeof(all_symbol_names) / sizeof(*all_symbol_names)
};

/// those function names from System.map that are exported
static const char *exported_symbol_names[NUM_NAMES];
static unsigned curr_symbol = 0;
static unsigned device_is_open = 0;

/*
 * This is called whenever a process attempts to open the device file
 */
static int device_open(struct inode *inode, struct file *file) {
    if (device_is_open) {
        return -EBUSY;
    }

    curr_symbol = 0;
    device_is_open = 1;
    return generic_file_open(inode, file);
}

static int device_release(struct inode *inode, struct file *file) {
    device_is_open = 0;
    curr_symbol = 0;
    return SUCCESS;
}

/*
 * This function is called whenever a process which has already opened the
 * device file attempts to read from it.
 */
static ssize_t device_read(
    struct file *file,
    char __user *buffer,
    size_t length,
    loff_t *offset
) {
    const char *sym;
    int num_read = 0;

    for(; curr_symbol < NUM_NAMES; ++curr_symbol) {
        if(NULL != exported_symbol_names[curr_symbol]) {
            break;
        }
    }
    if(curr_symbol >= NUM_NAMES) {
        return 0;
    }

    // write each character of the symbol to the user; semi-implicitly assumes
    // the buffer length is long enough
    sym = exported_symbol_names[curr_symbol++];
    for(; length && *sym; --length, ++sym, ++buffer, ++num_read) {
        put_user(*sym, buffer);
    }

    // to separate symbols; makes it nice for Python to read one symbol as
    // one line
    if(length--) {
        put_user('\n', buffer++);
        ++num_read;
    }

    return num_read;
}


struct file_operations file_ops = {
    .read = device_read,
    .open = device_open,
    .release = device_release,  /* a.k.a. close */
};

static struct miscdevice misc_dev = {
    .minor          = GET_SYMBOLS_MINOR,
    .name           = DEVICE_NAME,
    .fops           = &file_ops,
};

/// initialize the module
int init_module(void) {
    unsigned i = 0;
    unsigned num_exported_syms = 0;
    const char *sym;
    int ret;

    // lookup kernel symbols not using the typical function but by using the
    // address of the function derived from the System.map
    symbol_get_func *symbol_get = symbol_getter(SYMBOL_GET_ADDR);
    symbol_get_func *symbol_get_gpl = symbol_getter(SYMBOL_GET_GPL_ADDR);

    for(; i < NUM_NAMES; ++i) {
        sym = all_symbol_names[i];
        if(NULL == symbol_get(sym) && NULL == symbol_get_gpl(sym)) {
            exported_symbol_names[i] = NULL;
        } else {
            exported_symbol_names[i] = sym;
            ++num_exported_syms;
        }
    }
    printk(KERN_INFO
        "get_symbols: found %u / %u exported symbols.\n",
        num_exported_syms, NUM_NAMES
    );

    ret = misc_register(&misc_dev);
    if(ret) {
        printk(KERN_ERR "Unable to register get_symbols misc device.\n");
        return ret;
    }

    return 0;
}

/// cleanup the module
void cleanup_module(void) {
    misc_deregister(&misc_dev);
}

