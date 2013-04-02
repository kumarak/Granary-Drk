/*
 * cfi_debug_log.c
 *
 *  Created on: 2012-11-02
 *      Author: akshayk
 */

#include "cfi_module.h"
#include "cfi_debug_log.h"
//#include "segment_descriptor.h"

#include <linux/fs.h>
#include <asm/segment.h>
//#include <asm/uaccess.h>


#define SEGMENT_SELECTOR_ACCESSOR(selector_reg) \
static inline unsigned short \
get_##selector_reg(void) \
{\
    unsigned short result; \
    asm volatile("movw %%" #selector_reg ", %0" : "=m" (result)); \
    return result; \
}

//SEGMENT_SELECTOR_ACCESSOR(cs)
//SEGMENT_SELECTOR_ACCESSOR(ds)
//SEGMENT_SELECTOR_ACCESSOR(es)
//SEGMENT_SELECTOR_ACCESSOR(fs)
//SEGMENT_SELECTOR_ACCESSOR(gs)
//SEGMENT_SELECTOR_ACCESSOR(ss)

static unsigned short get_ds_new(void){
    unsigned short result;
    asm volatile("movw %%" "ds" ", %0" : "=m" (result));
    return result;
}


struct file*
cfi_file_open(const char *path, unsigned int flags, unsigned int rights){
    struct file *filp = NULL;
    mm_segment_t oldfs;
    int err = 0;

    oldfs = get_fs();
    set_fs(get_ds());
    filp = filp_open(path, flags, rights);
    set_fs(oldfs);

    if(IS_ERR(filp)){
        err = PTR_ERR(filp);
        return NULL;
    }
    return filp;
}

void
cfi_file_close(struct file *file){
    filp_close(file, NULL);
}

void
cfi_file_read(struct file* file, unsigned long long offset, unsigned char* data, unsigned int size)
{
    mm_segment_t oldfs;
    int ret;

    oldfs = get_fs();
    set_fs(get_ds());

    ret = vfs_read(file, data, size, &offset);

    set_fs(oldfs);
    return ret;
}

int
cfi_file_write(struct file *file,  const char *fmt, va_list ap){
    size_t size;
    char logbuf[MAX_LOG_LENGTH];
    mm_segment_t oldfs;
    int ret;

    if (file == INVALID_FILE)
        return 0;

    size = vsnprintf(logbuf, BUFFER_SIZE_ELEMENTS(logbuf), fmt, ap);

    oldfs = get_fs();
    set_fs(get_ds());

    dr_printf("%s", logbuf);
    //ret = vfs_write(file, logbuf, size, &file->f_pos);

    set_fs(oldfs);
    return ret;
}


void
cfi_fprintf(struct file* f, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    cfi_file_write(f, fmt, ap);
    va_end(ap);
}



noinline void cfi_debug_break_1(void *addr)
{
	(void)addr;
}

noinline void cfi_debug_break_2(void *addr)
{
	(void)addr;
}
