/*
 * cfi_debug_log.h
 *
 *  Created on: 2012-11-02
 *      Author: akshayk
 */

#ifndef CFI_DEBUG_LOG_H_
#define CFI_DEBUG_LOG_H_

//#include "globals_shared.h"

typedef unsigned int uint;

#define MAX_LOG_LENGTH 1024
#define BUFFER_SIZE_BYTES(buf)      sizeof(buf)
#define BUFFER_SIZE_ELEMENTS(buf)   (BUFFER_SIZE_BYTES(buf) / sizeof(buf[0]))

static char fname[64] = "/home/akshayk/logfile.txt";


struct file*
cfi_file_open(const char *path, unsigned int flags, unsigned int rights);

/*
struct file*
cfi_file_open(char *fname, uint mode_flags);
*/
void
cfi_fprintf(struct file* f, const char *fmt, ...);



/*#define CFI_LOG_FILE "cfi_debug.log"

FILE *fp_log;

#define CFI_DEBUG_OPEN	\
		fp_log = fopen(CFI_LOG_FILE, "a");

#define CFI_DEBUG_LOG(log_data)	\
		fprintf(fp_log, "[CFI_DEBUG] %s", log_data);

#define CFI_DEBUG_CLOSE	\
	fclose(fp_log);

*/

void cfi_debug_break_1(void *addr);

void cfi_debug_break_2(void *addr);

#endif /* CFI_DEBUG_LOG_H_ */
