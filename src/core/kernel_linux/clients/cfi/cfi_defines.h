/*
 * cfi_defines.h
 *
 *  Created on: 2013-02-01
 *      Author: akshayk
 */

#ifndef CFI_DEFINES_H_
#define CFI_DEFINES_H_

//#define CFI_NO_WATCHPOINT

//#define CLIENT_BUFFER_OVERFLOW
#define CLIENT_MEMORY_LEAK

enum {
	CFI_ALIAS_ADDRESS_NOT_ENABLED               = 0x8000000000000000ULL,
    CFI_ALIAS_ADDRESS_ENABLED                   = ~CFI_ALIAS_ADDRESS_NOT_ENABLED, // high-order bit not set

    CFI_ALIAS_ADDRESS_INDEX_MASK                = 0xffff000000000000ULL,
    CFI_ALIAS_ADDRESS_INDEX_OFFSET              = (12 * 4),
    CFI_ALIAS_ADDRESS_DISPLACEMENT_MASK         = 0x0000ffffffffffffULL
};

enum {
    CFI_ALLOC_WHITE_LIST,
    CFI_ALLOC_GREY_LIST,
    CFI_LOST_REFERENCE,
    CFI_COLLECT_LIST
};

#define DISPLAY_STRING(msg) dr_printf("%s\n", msg);
#define NULL_TERMINATE(buf) buf[(sizeof(buf)/sizeof(buf[0])) - 1] = '\0'




#endif /* CFI_DEFINES_H_ */
