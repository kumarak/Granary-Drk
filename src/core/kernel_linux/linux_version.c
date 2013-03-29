/*
 * linux_version.c
 *
 *  Created on: 2012-11-08
 *      Author: akshayk
 */


#include <stdio.h>
#include <sys/utsname.h>

#include "linux_version.h"

int get_linux_version()
{
	struct utsname uts;
	int major;
	int minor;
	int teeny;
	int n;

	if(uname(&uts))
		return 0;

	n = sscanf(uts.release, "%d.%d.%d", &major, &minor, &teeny);

	if(n < 1 || n > 3)
		return 0;

	return KERNEL_VERSION(major, minor, teeny);

}

