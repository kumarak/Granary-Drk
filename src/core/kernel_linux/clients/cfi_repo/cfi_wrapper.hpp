/*
 * cfi_wrapper.hpp
 *
 *  Created on: 2012-04-12
 *      Author: pag
 *     Version: $Id$
 */

#ifndef DRK_CFI_WRAPPER_HPP_
#define DRK_CFI_WRAPPER_HPP_

#define D(x)

#define MODULE_START_ADDR   0xffffffffa0000000
#define MODULE_END_ADDR     0xffffffffc0000000
#define MODULE_SHADOW_END   0xffffffffe0000000
#define MODULE_SHADOW_END_EXTENDED   0xffffffffff000000
#define MODULE_SHADOW_START MODULE_END_ADDR
#define MODULE_SHADOW_OFFSET 0x20000000

#define ENABLE_TAINT_TRACKING 0
#define CFI_SEQUENTIALIZE_MODULE 1

#if defined(__GNUC__) && ((__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 2)))
#   define FORCE_INLINE __attribute__((always_inline))
#else
#   define FORCE_INLINE inline
#endif

#if defined(__GNUC__) && !defined(__clang__)
#   define DECLTYPE decltype
#   define OFFSETOF __builtin_offsetof
#else
#   define DECLTYPE decltype
#   define OFFSETOF offsetof
#endif

/// tag types for pre/post wrappers; used to dispatch on the correct recursive call
/// by means of function overloading.
class pre_tag { };
class post_tag { };

template <typename T>
class static_tag {
public:
    static const T tag;
};

template <typename T>
const T static_tag<T>::tag;

/// dummy for returning the same type; guarantees typdef syntax correctness
template <typename T>
class identity_type {
public:
    typedef T type;
};

/// used to more easily define wrappers in terms of a type and a function body
/// that operates on the 'arg' variable
#define wrap_func(tag_type, can_track) \
    constexpr static int track_wrapper(tag_type) { return can_track; } \
    FORCE_INLINE static void wrap(ArgT__ &arg, const int depth__, tag_type tag__)

/// if one defines manual pre/post wrappers, and those types are tracked; then
/// the tracking will be auto-performed
#define pre wrap_func(pre_tag,1)
#define post wrap_func(post_tag,1)

/// if one doesn't define pre/post, then tracking isn't defined
#define no_pre wrap_func(pre_tag,0) { (void) depth__; (void) tag__; }
#define no_post wrap_func(post_tag,0) { (void) depth__; (void) tag__; }

#define TYPE_WRAPPER(type_name, body) \
    template <> \
    class wrap_type<type_name> { \
    public: \
        enum { \
            NUM = 1 \
        }; \
        typedef identity_type<type_name>::type ArgT__; \
        struct impl body ; \
    };

#define FUNC_WRAPPER(func_name, args, body) \
    template <typename R, typename... Args> \
    class cfi_wrapper_impl<KERN_ADDR_ ## func_name, R, Args...> { \
    public: \
        static R wrapper args { \
            typedef R (orig_func_type)(Args...); \
            orig_func_type *func_name = ((orig_func_type *) KERN_ADDR_ ## func_name); \
            pre_tag tag__; \
            const int depth__ = 0; \
            (void) tag__; \
            (void) depth__; \
            body \
        } \
    };

// wrap an l-value that is a function pointer
#define WRAP_FUNC(lval) \
    if(lval != 0) {  \
        D( kern_printk("wrap_function : %lx\n", lval); )  \
        lval = to_shadow_address(lval); \
    }

// recursively wrap
#define MAX_WRAP_DEPTH 2
#define WRAP_RECURSIVE(lval) \
    if(depth__ < MAX_WRAP_DEPTH) { \
        wrap_recursive(lval, depth__ + (1 - IS_TRACKED_VALUE(lval)), tag__); \
    }

#include <stdint.h>
#include <string.h>
//#include <cstdarg>
#include "cfi_wrapper.h"
#include "cfi_kernel_addresses.h" // generated file
#include "symbols/symbol_get_addr.h"

/// include the taint tracker
#include "cfi_taint_tracker.hpp"

#ifndef NOTHING
#   define NOTHING__
#   define NOTHING_ NOTHING__
#   define NOTHING NOTHING_
#endif

#if ENABLE_TAINT_TRACKING
#   define IS_TRACKED_TYPE(tpl_prefix, T) \
        (taint_meta_info<tpl_prefix tracked_type<T>::type>::IS_TRACKED)

#   define IS_STRUCT_TRACKED_TYPE(tpl_prefix, T) \
        (taint_meta_info<tpl_prefix tracked_type<T>::type>::IS_STRUCT_TRACKED)

#   define IS_TRACKED_VALUE(rvalue) \
        IS_TRACKED_TYPE(NOTHING, DECLTYPE(rvalue))
#else
#   define IS_TRACKED_TYPE(tpl_prefix, T) 0
#   define IS_STRUCT_TRACKED_TYPE(tpl_prefix, T) 0
#   define IS_TRACKED_VALUE(rvalue) 0
#endif

/// get access to printk, directly from an address from System.map
typedef int (printf_type)(const char *, ...);
typedef int (vsnprintf_type)(const char *, size_t, const char *, va_list);
typedef int (sys_getpid)(void);
typedef int (sys_gettid)(void);

static printf_type *kern_printk = (printf_type *) KERN_ADDR_printk;
static vsnprintf_type *kern_vsnprintf = (vsnprintf_type *) KERN_ADDR_vsnprintf;
//static sys_getpid *getpid = (sys_getpid *)SYS_GETPID;
//static sys_gettid *gettid = (sys_gettid *)SYS_GETTID;

/// wrap an argument based on its type
template <typename T>
class wrap_type {
public:
    enum {
        NUM = 0
    };
    struct impl {
        constexpr static int track_wrapper(pre_tag) { return 0; }
        constexpr static int track_wrapper(post_tag) { return 0; }
        FORCE_INLINE static void wrap(T &, int, pre_tag) { }
        FORCE_INLINE static void wrap(T &, int, post_tag) { }
    };
};

template <>
class wrap_type<void *> {
public:
    enum {
        NUM = 0
    };
    struct impl {
        constexpr static int track_wrapper(pre_tag) { return 0; }
        constexpr static int track_wrapper(post_tag) { return 0; }
        FORCE_INLINE static void wrap(void *, int, pre_tag) { }
        FORCE_INLINE static void wrap(void *, int, post_tag) { }
    };
};

/// convert an arbitrary function type into one that is in the shadow module
/// iff the original is in the shadow
template <typename R, typename... Args>
FORCE_INLINE R (*to_shadow_address(R (*func_ptr)(Args...)))(Args...) {
    typedef R (func_type)(Args...);

    uint64_t addr((uint64_t) func_ptr);

    // the address is already in the shadow
    if(MODULE_SHADOW_START <= addr && addr < MODULE_SHADOW_END) {
        (void) addr;

    // convert module address to shadow address
    } else if(MODULE_START_ADDR <= addr && addr < MODULE_END_ADDR) {
        addr += MODULE_SHADOW_OFFSET; 

        // initialize the 'call' instruction in the shadow if not present
        char *shadow_code((char *) addr);
        extern char SHADOW_CALL[];
        extern const unsigned long SHADOW_CALL_SIZE;

        memcpy(shadow_code, SHADOW_CALL, SHADOW_CALL_SIZE);

        D( kern_printk("initializing shadow module entrypoint %lx\n", addr); )

    // no value, don't care
    } else if(0 == addr) {
        (void) addr;

    // kernel address
    } else {
        //if(0 == cfi_get_kernel_wrapper((cfi_type_erased_func_ptr) addr)) {
        // TODO: check me; kernel function is not exported!
        //}
    }

    return (func_type *) addr;
}

/// implementation of wrappers; performs automatic taint tracking if the type
/// is appropriately tracked
template <typename Arg, typename Tag, const int IS_TRACKED>
class tracked_recursive_wrapper;

// case 0: untracked, or shouldn't be tracked
template <typename Arg, typename Tag>
class tracked_recursive_wrapper<Arg, Tag, 0> {
public:
    FORCE_INLINE static void wrap(Arg &arg, const int depth__) {
        wrap_type<Arg>::impl::wrap(arg, depth__, static_tag<Tag>::tag);
    }
};

// case 1: tracked using function pointers
template <typename Arg, typename Tag>
class tracked_recursive_wrapper<Arg, Tag, 1> {
public:
    FORCE_INLINE static void wrap(Arg &arg, const int depth__) {
        WITH_FUNC_TAINTED_DATA(arg, {
            wrap_type<Arg>::impl::wrap(arg, depth__, static_tag<Tag>::tag);
        });
    }
};

// case 2: tracked using structure extension
template <typename Arg, typename Tag>
class tracked_recursive_wrapper<Arg, Tag, 2> {
public:
    FORCE_INLINE static void wrap(Arg &arg, const int depth__) {
        WITH_STRUCT_TAINTED_DATA(arg, {
            wrap_type<Arg>::impl::wrap(arg, depth__, static_tag<Tag>::tag);
        });
    }
};

/// type reduction for recursive wrappers
template <typename Arg>
class recursive_wrapper {
public:
    enum {
        NUM = wrap_type<Arg>::NUM
    };

    FORCE_INLINE static void pre_wrap(Arg &arg, const int depth__) {
        enum {
            CAN_TRACK_WRAPPER = !!wrap_type<Arg>::impl::track_wrapper(pre_tag()),
            IS_TRACKED = !!IS_TRACKED_TYPE(typename, Arg),
            IS_STRUCT_TRACKED = !!IS_STRUCT_TRACKED_TYPE(typename, Arg),
            TRACK_TYPE = CAN_TRACK_WRAPPER ? (IS_TRACKED + IS_STRUCT_TRACKED) : 0,
        };
        tracked_recursive_wrapper<Arg, pre_tag, TRACK_TYPE>::wrap(arg, depth__);
    }
    FORCE_INLINE static void post_wrap(Arg &arg, const int depth__) {
        enum {
            CAN_TRACK_WRAPPER = !!wrap_type<Arg>::impl::track_wrapper(post_tag()),
            IS_TRACKED = !!IS_TRACKED_TYPE(typename, Arg),
            IS_STRUCT_TRACKED = !!IS_STRUCT_TRACKED_TYPE(typename, Arg),
            TRACK_TYPE = CAN_TRACK_WRAPPER ? (IS_TRACKED + IS_STRUCT_TRACKED) : 0,
        };
        tracked_recursive_wrapper<Arg, post_tag, TRACK_TYPE>::wrap(arg, depth__);
    }
};

template <typename Arg>
class recursive_wrapper<const Arg> {
public:

    enum {
        NUM = wrap_type<Arg>::NUM
    };

    FORCE_INLINE static void pre_wrap(const Arg &arg, const int depth__) {
        recursive_wrapper<Arg>::pre_wrap(const_cast<Arg &>(arg), depth__);
    }
    FORCE_INLINE static void post_wrap(const Arg &arg, const int depth__) {
        recursive_wrapper<Arg>::post_wrap(const_cast<Arg &>(arg), depth__);
    }
};

template <typename Arg>
class recursive_wrapper<Arg *> {
public:

    enum {
        NUM = recursive_wrapper<Arg>::NUM
    };

    FORCE_INLINE static void pre_wrap(Arg *&arg, const int depth__) {
        if(((Arg *) 4095) < arg) {
            recursive_wrapper<Arg>::pre_wrap(*arg, depth__);
        }
    }
    FORCE_INLINE static void post_wrap(Arg *&arg, const int depth__) {
        if(((Arg *) 4095) < arg) {
            recursive_wrapper<Arg>::post_wrap(*arg, depth__);
        }
    }
};

template <typename Arg>
class recursive_wrapper<Arg **> {
public:

    enum {
        NUM = recursive_wrapper<Arg *>::NUM
    };

    FORCE_INLINE static void pre_wrap(Arg **&arg, const int depth__) {
        if(((Arg **) 4095) < arg) {
            recursive_wrapper<Arg *>::pre_wrap(*arg, depth__);
        }
    }
    FORCE_INLINE static void post_wrap(Arg **&arg, const int depth__) {
        if(((Arg **) 4095) < arg) {
            recursive_wrapper<Arg *>::post_wrap(*arg, depth__);
        }
    }
};

template <typename Ret, typename... Args>
class recursive_wrapper<Ret (*)(Args...)> {
public:

    typedef Ret (Arg)(Args...);

    enum {
        NUM = wrap_type<Arg *>::NUM
    };

    FORCE_INLINE static void pre_wrap(Arg *&arg, const int depth__) {
        if(((Arg *) 4095) < arg) {
            pre_tag tag;
            wrap_type<Arg *>::impl::wrap(arg, depth__, tag);
        }
    }
    FORCE_INLINE static void post_wrap(Arg *&arg, const int depth__) {
        if(((Arg *) 4095) < arg) {
            post_tag tag;
            wrap_type<Arg *>::impl::wrap(arg, depth__, tag);
        }
    }
};

template <>
class recursive_wrapper<void *> {
public:
    enum {
        NUM = 0
    };

    FORCE_INLINE static void pre_wrap(void *, int) { }
    FORCE_INLINE static void post_wrap(void *, int) { }
};

template <typename Arg>
class recursive_wrapper<Arg &> : public recursive_wrapper<Arg> { };

/// recursively wrap some argument; benefits from type deduction
/// uses the type tag (passed through recursive_wrapper) and define
/// in the pre/post macros to dispatch to the correct wrapper. e.g. when
/// WRAP_RECURSIVE is used in post { ... }, the post wrappers are called.
template <typename Arg>
void wrap_recursive(Arg &arg, const int depth__, pre_tag) {
    recursive_wrapper<Arg>::pre_wrap(arg, depth__);
}
template <typename Arg>
void wrap_recursive(Arg &arg, const int depth__, post_tag) {
    recursive_wrapper<Arg>::post_wrap(arg, depth__);
}

/// base cases for wrapping arguments
FORCE_INLINE void arg_pre_wrapper(int) { }
FORCE_INLINE void arg_post_wrapper(int) { }

/// unroll and wrap arguments by type
template <typename Arg, typename... Rest>
FORCE_INLINE void arg_pre_wrapper(const int depth__, Arg &arg, Rest&... rest) {
    recursive_wrapper<Arg>::pre_wrap(arg, depth__);
    arg_pre_wrapper(depth__, rest...);
}

template <typename Arg, typename... Rest>
FORCE_INLINE void arg_post_wrapper(const int depth__, Arg &arg, Rest&... rest) {
    recursive_wrapper<Arg>::post_wrap(arg, depth__);
    arg_post_wrapper(depth__, rest...);
}

/// count how many arguments are being wrapped
template <typename ...Args>
class count_wrappers;

template <typename First, typename ...Rest>
class count_wrappers<First, Rest...> {
public:
    enum {
        NUM = recursive_wrapper<First>::NUM + count_wrappers<Rest...>::NUM,
        HAS_ANY = NUM > 0
    };
};

template <>
class count_wrappers<> {
public:
    enum {
        NUM = 0,
        HAS_ANY = false
    };
};

/// box for holding a return value; needed so that we can avoid a partial
/// specialization of cfi_wrapper_impl on a void return address, which would
/// introduce an ambiguous lookup for any function wrappers with a void
/// return type.
template <typename T>
class box {
private:
    T val;
public:

    template <typename... Args>
    FORCE_INLINE box(uint64_t func_address, Args&&... args) throw()
        : val(((T (*)(Args...)) func_address)(args...))
    { }

    FORCE_INLINE T unbox(void) throw() {
        return val;
    }
};

template <>
class box<void> {
public:

    template <typename... Args>
    FORCE_INLINE box(uint64_t func_address, Args&&... args) throw() {
        ((void (*)(Args...)) func_address)(args...);
    }

    FORCE_INLINE void unbox(void) throw() {
        return;
    }
};

/// implementation of the wrapper for function returning a value
template <const uint64_t addr, typename R, typename... Args>
class cfi_wrapper_impl {
public:
    static R wrapper(Args... args) {
        typedef R (orig_func_type)(Args...);
        D( kern_printk("in wrapper for %lx; wrapping %lu args\n", (uint64_t) addr, sizeof...(Args)); )
        const int depth__ = 0;
        if(count_wrappers<Args...>::HAS_ANY) {
            arg_pre_wrapper(depth__, args...);
        }
        box<R> ret_val(addr, args...);
        if(count_wrappers<Args...>::HAS_ANY) {
            arg_post_wrapper(depth__, args...);
        }
        return ret_val.unbox();
    }
};

/// include shadow aliasing machinery
//#include "cfi_alias.hpp"

/// include dynamic wrapper machinery
//#include "cfi_dynamic_wrapper.hpp"

/// include all wrappers; must be after the above template definitions
/// so that partial specializations of cfi_wrapper_imple for FUNC_WRAPPERs
/// take control for specific functions.
#include "wrappers/wrappers.hpp"

/// C++ constexpr wrapper; we are given the absolute address of the function,
/// hence why we only care about its address and its types
template <const uint64_t addr, typename R, typename... Args>
cfi_type_erased_func_ptr cfi_wrapper(R (*)(Args...)) {
    return (cfi_type_erased_func_ptr) cfi_wrapper_impl<addr, R, Args...>::wrapper;
}

#undef D
#undef pre
#undef post

#endif /* DRK_CFI_WRAPPER_HPP_ */
