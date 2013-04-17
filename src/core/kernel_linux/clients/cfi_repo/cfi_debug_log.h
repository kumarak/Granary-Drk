/*
 * cfi_debug_log.h
 *
 *  Created on: 2012-11-02
 *      Author: akshayk
 */

#ifndef CFI_DEBUG_LOG_H_
#define CFI_DEBUG_LOG_H_

#define CFI_LOG_FILE "cfi_debug.log"

FILE *fp_log;

#define CFI_DEBUG_OPEN	\
		fp_log = fopen(CFI_LOG_FILE, "a");

#define CFI_DEBUG_LOG(log_data)	\
		fprintf(fp_log, "[CFI_DEBUG] %s", log_data);

#define CFI_DEBUG_CLOSE	\
	fclose(fp_log);



#endif /* CFI_DEBUG_LOG_H_ */
