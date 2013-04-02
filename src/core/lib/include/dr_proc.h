/* **********************************************************
 * Copyright (c) 2002-2009 VMware, Inc.  All rights reserved.
 * **********************************************************/

/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * 
 * * Neither the name of VMware, Inc. nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without
 *   specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL VMWARE, INC. OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

#ifndef _DR_PROC_H_
#define _DR_PROC_H_ 1

/****************************************************************************
 * PROCESSOR-SPECIFIC UTILITY ROUTINES AND CONSTANTS
 */
/**
 * @file dr_proc.h
 * @brief Utility routines for identifying features of the processor.
 */

/* TODO(peter): The linux kernel has pages with 4K, 2MB, and 1GB. This size
 * isn't universal.
 */
/* page size is 4K on all DR-supported platforms */
#ifndef PAGE_SIZE
# define PAGE_SIZE (4*1024) /**< Size of a page of memory. */
#else
# if PAGE_SIZE != 4096
#  error bag page size
# endif
#endif


/**< Convenience macro to align to the start of a page of memory. */
#define PAGE_START(x) (((ptr_uint_t)(x)) & ~((PAGE_SIZE)-1))

/** Constants returned by proc_get_vendor(). */
enum {
    VENDOR_INTEL,   /**< proc_get_vendor() processor identification: Intel */
    VENDOR_AMD,     /**< proc_get_vendor() processor identification: AMD */
    VENDOR_UNKNOWN, /**< proc_get_vendor() processor identification: unknown */
};

/* Family and Model
 *   Intel 486                 Family 4
 *   Intel Pentium             Family 5
 *   Intel Pentium Pro         Family 6, Model 0 and 1 
 *   Intel Pentium 2           Family 6, Model 3, 5, and 6
 *   Intel Celeron             Family 6, Model 5 and 6
 *   Intel Pentium 3           Family 6, Model 7, 8, 10, 11
 *   Intel Pentium 4           Family 15, Extended 0
 *   Intel Itanium             Family 7
 *   Intel Itanium 2           Family 15, Extended 1 and 2
 *   Intel Pentium M           Family 6, Model 9 and 13
 *   Intel Core                Family 6, Model 14
 *   Intel Core 2              Family 6, Model 15
 */

/* Remember that we add extended family to family as Intel suggests */
#define FAMILY_ITANIUM_2_DC 17 /**< proc_get_family() processor family: Itanium 2 DC */
#define FAMILY_ITANIUM_2    16 /**< proc_get_family() processor family: Itanium 2 */
#define FAMILY_K8L          16 /**< proc_get_family() processor family: AMD K8L */
#define FAMILY_K8           15 /**< proc_get_family() processor family: AMD K8 */
#define FAMILY_PENTIUM_4    15 /**< proc_get_family() processor family: Pentium 4 */
#define FAMILY_ITANIUM       7 /**< proc_get_family() processor family: Itanium */
/* Pentium Pro, Pentium II, Pentium III, Athlon, Pentium M, Core, Core 2 */
#define FAMILY_CORE_2        6 /**< proc_get_family() processor family: Core 2 */
#define FAMILY_CORE          6 /**< proc_get_family() processor family: Core */
#define FAMILY_PENTIUM_M     6 /**< proc_get_family() processor family: Pentium M */
#define FAMILY_PENTIUM_3     6 /**< proc_get_family() processor family: Pentium 3 */
#define FAMILY_PENTIUM_2     6 /**< proc_get_family() processor family: Pentium 2 */
#define FAMILY_PENTIUM_PRO   6 /**< proc_get_family() processor family: Pentium Pro */
#define FAMILY_ATHLON        6 /**< proc_get_family() processor family: Athlon */
/* Pentium (586) */
#define FAMILY_PENTIUM       5 /**< proc_get_family() processor family: Pentium */
#define FAMILY_K6            5 /**< proc_get_family() processor family: K6 */
#define FAMILY_K5            5 /**< proc_get_family() processor family: K5 */
/* 486 */
#define FAMILY_486           4 /**< proc_get_family() processor family: 486 */

/* We do not enumerate all models; just relevant ones needed to distinguish
 * major processors in the same family.
 */
#define MODEL_PENTIUM_M_1MB  9 /**< proc_get_model() processor model: Pentium M 1MB L2 */
#define MODEL_PENTIUM_M     13 /**< proc_get_model() processor model: Pentium M 2MB L2 */
#define MODEL_CORE          14 /**< proc_get_model() processor model: Core */
#define MODEL_CORE_2        15 /**< proc_get_model() processor model: Core 2 */

/**
 * Struct to hold all 4 32-bit feature values returned by cpuid.
 * Used by proc_get_all_feature_bits().
 */
typedef struct {
    uint flags_edx;             /**< feature flags stored in edx */
    uint flags_ecx;             /**< feature flags stored in ecx */
    uint ext_flags_edx;         /**< extended feature flags stored in edx */
    uint ext_flags_ecx;         /**< extended feature flags stored in ecx */
} features_t;

/**
 * Feature bits returned by cpuid.  Pass one of these values to proc_has_feature() to
 * determine whether the underlying processor has the feature.
 */
typedef enum {
    /* features returned in edx */
    FEATURE_FPU =       0,              /**< Floating-point unit on chip */
    FEATURE_VME =       1,              /**< Virtual Mode Extension */
    FEATURE_DE =        2,              /**< Debugging Extension */
    FEATURE_PSE =       3,              /**< Page Size Extension */
    FEATURE_TSC =       4,              /**< Time-Stamp Counter */
    FEATURE_MSR =       5,              /**< Model Specific Registers */
    FEATURE_PAE =       6,              /**< Physical Address Extension */
    FEATURE_MCE =       7,              /**< Machine Check Exception */
    FEATURE_CX8 =       8,              /**< CMPXCHG8 Instruction Supported */
    FEATURE_APIC =      9,              /**< On-chip APIC Hardware Supported */
    FEATURE_SEP =       11,             /**< Fast System Call */
    FEATURE_MTRR =      12,             /**< Memory Type Range Registers */
    FEATURE_PGE =       13,             /**< Page Global Enable */
    FEATURE_MCA =       14,             /**< Machine Check Architecture */
    FEATURE_CMOV =      15,             /**< Conditional Move Instruction */
    FEATURE_PAT =       16,             /**< Page Attribute Table */
    FEATURE_PSE_36 =    17,             /**< 36-bit Page Size Extension */
    FEATURE_PSN =       18,             /**< Processor serial # present & enabled */
    FEATURE_CLFSH =     19,             /**< CLFLUSH Instruction supported */
    FEATURE_DS =        21,             /**< Debug Store */
    FEATURE_ACPI =      22,             /**< Thermal monitor & SCC supported */
    FEATURE_MMX =       23,             /**< MMX technology supported */
    FEATURE_FXSR =      24,             /**< Fast FP save and restore */
    FEATURE_SSE =       25,             /**< SSE Extensions supported */
    FEATURE_SSE2 =      26,             /**< SSE2 Extensions supported */
    FEATURE_SS =        27,             /**< Self-snoop */
    FEATURE_HTT =       28,             /**< Hyper-threading Technology */
    FEATURE_TM =        29,             /**< Thermal Monitor supported */
    FEATURE_IA64 =      30,             /**< IA64 Capabilities */
    FEATURE_PBE =       31,             /**< Pending Break Enable */
    /* features returned in ecx */
    FEATURE_SSE3 =      0 + 32,         /**< SSE3 Extensions supported */
    FEATURE_MONITOR =   3 + 32,         /**< MONITOR/MWAIT instructions supported */
    FEATURE_DS_CPL =    4 + 32,         /**< CPL Qualified Debug Store */
    FEATURE_VMX =       5 + 32,         /**< Virtual Machine Extensions */
    FEATURE_EST =       7 + 32,         /**< Enhanced Speedstep Technology */
    FEATURE_TM2 =       8 + 32,         /**< Thermal Monitor 2 */
    FEATURE_SSSE3 =     9 + 32,         /**< SSSE3 Extensions supported */
    FEATURE_CID =       10 + 32,        /**< Context ID */ 
    FEATURE_CX16 =      13 + 32,        /**< CMPXCHG16B instruction supported */
    FEATURE_xPTR =      14 + 32,        /**< Send Task Priority Messages */
    /* extended features returned in edx */
    FEATURE_SYSCALL =   11 + 64,        /**< SYSCALL/SYSRET instructions supported */
    FEATURE_XD_Bit =    20 + 64,        /**< Execution Disable bit */
    FEATURE_EM64T =     29 + 64,        /**< Extended Memory 64 Technology */
    /* extended features returned in ecx */
    FEATURE_LAHF =      0 + 96          /**< LAHF/SAHF available in 64-bit mode */
} feature_bit_t;

/**
 * L1 and L2 cache sizes, used by proc_get_L1_icache_size(),
 * proc_get_L1_dcache_size(), proc_get_L2_cache_size(), and
 * proc_get_cache_size_str().
 */
typedef enum {
    CACHE_SIZE_8_KB,    /**< L1 or L2 cache size of 8 KB. */
    CACHE_SIZE_16_KB,   /**< L1 or L2 cache size of 16 KB. */
    CACHE_SIZE_32_KB,   /**< L1 or L2 cache size of 32 KB. */
    CACHE_SIZE_64_KB,   /**< L1 or L2 cache size of 64 KB. */
    CACHE_SIZE_128_KB,  /**< L1 or L2 cache size of 128 KB. */
    CACHE_SIZE_256_KB,  /**< L1 or L2 cache size of 256 KB. */
    CACHE_SIZE_512_KB,  /**< L1 or L2 cache size of 512 KB. */
    CACHE_SIZE_1_MB,    /**< L1 or L2 cache size of 1 MB. */
    CACHE_SIZE_2_MB,    /**< L1 or L2 cache size of 2 MB. */
    CACHE_SIZE_UNKNOWN  /**< Unknown L1 or L2 cache size. */
} cache_size_t;



/** Returns the cache line size in bytes of the processor. */
size_t
proc_get_cache_line_size(void);

/** Returns true only if \p addr is cache-line-aligned. */
bool 
proc_is_cache_aligned(void *addr);

/** Returns n >= \p sz such that n is a multiple of the cache line size. */
ptr_uint_t
proc_bump_to_end_of_cache_line(ptr_uint_t sz);

/** Returns n <= \p addr such that n is a multiple of the page size. */
void *
proc_get_containing_page(void *addr);

/** Returns one of the VENDOR_ constants. */
uint
proc_get_vendor(void);

/** 
 * Returns the processor family as given by the cpuid instruction,
 * adjusted by the extended family as described in the Intel documentation.
 * The FAMILY_ constants identify important family values.
 */
uint
proc_get_family(void);

/** Returns the processor type as given by the cpuid instruction. */
uint
proc_get_type(void);

/** 
 * Returns the processor model as given by the cpuid instruction,
 * adjusted by the extended model as described in the Intel documentation.
 * The MODEL_ constants identify important model values.
 */
uint
proc_get_model(void);

/** Returns the processor stepping ID. */
uint
proc_get_stepping(void);

/** Tests if processor has selected feature. */
bool
proc_has_feature(feature_bit_t feature);

/**
 * Returns all 4 32-bit feature values.  Use proc_has_feature to test
 * for specific features.
 */
features_t *
proc_get_all_feature_bits(void);

/** Returns the processor brand string as given by the cpuid instruction. */
char*
proc_get_brand_string(void);

/** Returns the size of the L1 instruction cache. */
cache_size_t
proc_get_L1_icache_size(void);

/** Returns the size of the L1 data cache. */
cache_size_t
proc_get_L1_dcache_size(void);

/** Returns the size of the L2 cache. */
cache_size_t
proc_get_L2_cache_size(void);

/** Converts a cache_size_t type to a string. */
const char*
proc_get_cache_size_str(cache_size_t size);

/**
 * Returns the size in bytes needed for a buffer for saving the floating point state.
 */
size_t
proc_fpstate_save_size(void);

/**
 * Saves the floating point state into the 16-byte-aligned buffer \p buf,
 * which must be 512 bytes for processors with the FXSR feature, and
 * 108 bytes for those without (where this routine does not support
 * 16-bit operand sizing).  \note proc_fpstate_save_size() can be used
 * to determine the particular size needed.
 * 
 * DR does NOT save the application's floating-point, MMX, or SSE state
 * on context switches!  Thus if a client performs any floating-point 
 * operations in its main routines called by DR, the client must save 
 * and restore the floating-point/MMX/SSE state.
 * If the client needs to do so inside the code cache the client should implement
 * that itself.
 * Returns number of bytes written.
 */
size_t
proc_save_fpstate(byte *buf);

/**
 * Restores the floating point state from the 16-byte-aligned buffer
 * \p buf, which must be 512 bytes for processors with the FXSR feature,
 * and 108 bytes for those without (where this routine does not
 * support 16-bit operand sizing).  \note proc_fpstate_save_size() can
 * be used to determine the particular size needed.
 */
void 
proc_restore_fpstate(byte *buf);


/**
 * Inserts into \p ilist prior to \p where meta-instruction(s) to save the
 * floating point state into the 16-byte-aligned buffer referred to by
 * \p buf, which must be 512 bytes for processors with the FXSR
 * feature, and 108 bytes for those without (where this routine does
 * not support 16-bit operand sizing).  \p buf should have size of
 * OPSZ_512; this routine will automatically adjust it to OPSZ_108 if
 * necessary.  \note proc_fpstate_save_size() can be used to determine
 * the particular size needed.
 */
void
dr_insert_save_fpstate(void *drcontext, instrlist_t *ilist, instr_t *where,
                       opnd_t buf);

/**
 * Inserts into \p ilist prior to \p where meta-instruction(s) to restore the
 * floating point state from the 16-byte-aligned buffer referred to by
 * buf, which must be 512 bytes for processors with the FXSR feature,
 * and 108 bytes for those without (where this routine does not
 * support 16-bit operand sizing).  \p buf should have size of
 * OPSZ_512; this routine will automatically adjust it to OPSZ_108 if
 * necessary.  \note proc_fpstate_save_size() can be used to determine
 * the particular size needed.
 */
void
dr_insert_restore_fpstate(void *drcontext, instrlist_t *ilist, instr_t *where,
                          opnd_t buf);

bool
dr_is_emulating_interrupt_return(void *drcontext);

void
dr_register_module_exit(void (*func)(void *), enum module_exit_kind flag);

/**
 * Returns a pointer to a client extension of the dcontext.
 */
//void *
//dr_get_client_extension()


void *
dr_get_client_return_address(void);

void *
dr_get_client_return_address_from_thread(void);

void
dr_get_mcontext_snapshot(void *addr);

void
dr_set_client_return_address_from_thread(void *addr);

void *
dr_get_client_extension_temp(size_t offset);

void
dr_register_return_path_address(void *addr);

void
dr_register_hotpatch_callback(void *addr);

/**
 * Returns a pointer to a client extension of the thread.
 */
void *
dr_get_client_extension(void);

/**
 * Returns the machine stack pointer.
 */
void *
dr_get_stack_pointer(void *drcontext);

void*
dr_get_stack_pointer_value(void *drcontex);

void
dr_set_stack_pointer_value(void *dcontext, void *addr);

void
dr_fix_mcontext(void *drcontext);

reg_t
dr_get_gp_xflag(void *dcontext);

/**
 * Returns a pointer to a client extension of the dcontext, given the dcontext
 * of this thread.
 */
void *
dr_get_client_extension_from_context(void *drcontext, size_t offset);

/**
 * Redirect execution to some address.
 */
void
dr_redirect_execution_native(void *drcontext, void *to_address);

/**
 * Return the address of the next basic block.
 */
void *
dr_next_address(void *drcontext);

/**
 * Register a callback to initialize a client extension.
 */
void
dr_init_client_extension(void (*init)(void *), unsigned long long offset);


#endif /* _DR_PROC_H_ */
