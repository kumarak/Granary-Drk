/*
 * dcontent_extend.h
 *
 *  Created on: 2012-05-02
 *      Author: pag
 *     Version: $Id$
 */



#ifndef DR_EXTENSION
#   define DR_EXTENSION(name) (offsetof(struct dr_client_extensions, name))
#endif

#ifndef E
#   define E(x)
#   define DRK_EXTENSION_ALWAYS_INCLUDE 0
#else
#   define DRK_EXTENSION_ALWAYS_INCLUDE 1
#endif



#if DRK_EXTENSION_ALWAYS_INCLUDE
#   ifdef DRK_EXTENSION_DEFS
#       undef DRK_EXTENSION_DEFS
#   endif
#endif

#ifndef DRK_EXTENSION_DEFS
#define DRK_EXTENSION_DEFS


struct dr_client_extensions {

    /**
     * CFI client extensions to the dcontext_t.
     */
    struct cfi_client_extension {

        /* stack of raw module addresses for returns from module-to-kernel calls
         * and interrupts within modules. */
    	void *return_address_stack[8];
        unsigned return_stack_size;

        /* kernel address for call/return exits */
        union {
            //uint32_t stack_hash;

            void *exit_address;
        };

        /* interrupt handlers */
        void (*iret_handler)(void);

        /* pending interrupt stack frame */
        interrupt_stack_frame_t pending;
    } cfi;
} E(client);

#if !DRK_EXTENSION_ALWAYS_INCLUDE
#   undef E
#endif

#endif /* DRK_EXTENSION_DEFS */

