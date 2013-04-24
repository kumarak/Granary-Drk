/*
 * linux_wrapper.c
 *
 *  Created on: 2013-04-24
 *      Author: akshayk
 */


#include <linux/kernel.h>
#include <asm/spinlock.h>
#include <linux/atomic.h>
#include "linux_wrapper.h"


int cfi__ticket_spin_is_locked(arch_spinlock_t *lock){
    struct __raw_tickets tmp = ACCESS_ONCE(lock->tickets);

    return tmp.tail != tmp.head;
}
