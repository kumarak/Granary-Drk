/*
 * os_log.c
 *
 *  Created on: 2013-01-17
 *      Author: akshayk
 */


#include <linux/fs.h>
#if 0
#include "os_shared.h"



file_t
os_open(const char *fname, int os_open_flags)
{
#if 0
    struct file *f;
    //f = filp_open(fname, os_open_flags);
    return f;
    //return INVALID_FILE;
#else
    /* TODO(peter): Test this. */
    char buffer[HYPERCALL_MAX_SIZE];
    hypercall_open_t *hypercall = (hypercall_open_t*) &buffer[0];
    size_t size;
    file_t file;
    if (os_open_flags & OS_OPEN_READ) {
        ASSERT_NOT_PORTED(false);
    }
    /* strlen does not include the '\0' byte, however the hypercall->fname
     * placeholder gives us 1 byte of storage. */
    size = sizeof(*hypercall) + strlen(fname);
    hypercall->hypercall.size = size;
    hypercall->hypercall.type = HYPERCALL_OPEN;
   // hypercall->fd = next_open_fd();
    strcpy(&hypercall->fname, fname);
    if (!hypercall_send(&hypercall->hypercall)) {
        file = INVALID_FILE;
    } else {
        file = hypercall->fd;
    }
    return file;
#endif
}
#endif
