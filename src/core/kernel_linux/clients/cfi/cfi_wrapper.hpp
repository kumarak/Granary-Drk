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

#include <stdarg.h>

extern "C" {

    #include "cfi_defines.h"
    #include "wrappers/includes.h"
}


#define MODULE_START_ADDR   0xffffffffa0000000
#define MODULE_END_ADDR     0xffffffffc0000000
#define MODULE_SHADOW_END   0xffffffffe0000000
#define MODULE_SHADOW_END_EXTENDED   0xffffffffff000000
#define MODULE_SHADOW_START MODULE_END_ADDR
#define MODULE_SHADOW_OFFSET 0x20000000

#define ADD_TO_HASH(key, value)\
            hashmap_put(kernel_pointer_hash, (void*)key, (void*)value);


#define ENABLE_TAINT_TRACKING 0
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

/* Taken from Documentation/x86/x86_64/mm.txt */
template <typename T>
bool is_kernel_virtual_address_space(T addr) {
    return (((unsigned long) addr) > 0x00007fffffffffff );
}



/// tag types for pre/post wrappers; used to dispatch on the correct recursive call
/// by means of function overloading.
class pre_tag { };
class post_tag { };
class return_tag { };



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
    FORCE_INLINE static void wrap(ArgT__ &arg, uint64_t func_addr, const int depth__, tag_type tag__)

#define wrap_func_ptr(tag_type, can_track) \
    constexpr static int track_wrapper(tag_type) { return can_track; } \
    FORCE_INLINE static void wrap(ArgT__ *arg, uint64_t func_addr, const int depth__, tag_type tag__)

/// if one defines manual pre/post wrappers, and those types are tracked; then
/// the tracking will be auto-performed
#define pre wrap_func(pre_tag,1)
#define post wrap_func(post_tag,1)
#define wrap_return wrap_func(return_tag,1)

#define wrap_pre wrap_func_ptr(pre_tag,1)

/// if one doesn't define pre/post, then tracking isn't defined
#define no_pre wrap_func(pre_tag,0) { (void) depth__; (void) tag__; }
#define no_post wrap_func(post_tag,0) { (void) depth__; (void) tag__; }
#define no_return wrap_func(return_tag,0) { (void) depth__; (void) tag__; }

#define no_wrap_pre wrap_func_ptr(pre_tag,0) { (void) depth__; (void) tag__; }
#define no_wrap_post wrap_func_ptr(post_tag,0) { (void) depth__; (void) tag__; }



#define TYPE_WRAPPER(type_name, body) \
    template <> \
    class wrap_type<type_name> { \
    public: \
        enum { \
            NUM = 1, \
            WRAP_CHOICE = 0, \
            IS_DEFINED = 1 \
        }; \
        typedef identity_type<type_name>::type ArgT__; \
        struct impl body ; \
    };

#define MODULE_TYPE_WRAPPER(type_name, body) \
    template <> \
    class module_wrap_type<type_name> { \
    public: \
        enum { \
            NUM = 1, \
            WRAP_CHOICE = 1, \
            IS_DEFINED = 1 \
        }; \
        typedef identity_type<type_name>::type ArgT__; \
        struct impl body ; \
    };


#define FUNC_WRAPPER(func_name, args, body) \
    template <typename R, typename... Args> \
    class cfi_wrapper_impl<KERN_ADDR_ ## func_name, R, Args...> { \
    public: \
        static R wrapper args { \
            constexpr int WRAP_CHOICE = 0; \
            typedef R (orig_func_type)(Args...); \
            orig_func_type *func_name = ((orig_func_type *) KERN_ADDR_ ## func_name); \
            uint64_t func_addr = (uint64_t)func_name; \
            (void) func_name; \
            pre_tag tag__; \
            const int depth__ = 0; \
            (void) tag__; \
            (void) depth__; \
            (void) WRAP_CHOICE; \
            body \
        } \
    };

#define FUNC_WRAPPER_VOID(func_name, args, body) \
    template <typename... Args> \
    class cfi_wrapper_impl<KERN_ADDR_ ## func_name, void, Args...> { \
    public: \
        static void wrapper args { \
            constexpr int WRAP_CHOICE = 0; \
            typedef void (orig_func_type)(Args...); \
            orig_func_type *func_name = ((orig_func_type *) KERN_ADDR_ ## func_name); \
            uint64_t func_addr = (uint64_t)func_name; \
            (void) func_name; \
            pre_tag tag__; \
            const int depth__ = 0; \
            (void) tag__; \
            (void) depth__; \
            (void) WRAP_CHOICE; \
            body \
        } \
    };

// wrap an l-value that is a function pointer
#define WRAP_FUNC(lval) \
    if(lval != 0) {  \
        lval = to_shadow_address(lval); \
    }




// recursively wrap
#define MAX_WRAP_DEPTH 2
#define WRAP_RECURSIVE(lval) \
		if(depth__ < MAX_WRAP_DEPTH) { \
			wrap_recursive<choose_wrapper<WRAP_CHOICE>::wrap, DECLTYPE(lval)>(lval, func_addr, depth__ + (1 - IS_TRACKED_VALUE(lval)), tag__); \
    }

#include <stdint.h>
#include "cfi_wrapper.h"
#include "cfi_kernel_addresses.h" // generated file
#include "symbols/symbol_get_addr.h"

/// get access to printk, directly from an address from System.map
typedef int (printf_type)(const char *, ...);
//typedef int (vsnprintf_type)(const char *, size_t, const char *, va_list);
typedef int (sys_getpid)(void);
typedef int (sys_gettid)(void);

static printf_type *kern_printk = (printf_type *) KERN_ADDR_printk;

/// include the taint tracker
#include "cfi_taint_tracker.hpp"

#ifndef NOTHING
#   define NOTHING__
#   define NOTHING_ NOTHING__
#   define NOTHING NOTHING_
#endif

extern "C" {
    extern void dr_app_start(void);
    extern void dr_app_stop(void);
    extern void cfi_thread_slot_module_enrty(void);
    extern void cfi_return_to_kernel(void *ptr);
}

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


/// wrap an argument based on its type
#define MAKE_BASE_WRAPPER(class_name)  \
    template <typename T> \
    class class_name { \
    public: \
        enum { \
            NUM = 0, \
            IS_DEFINED = 0 \
        }; \
        struct impl { \
            constexpr static int track_wrapper(pre_tag) { return 0; } \
            constexpr static int track_wrapper(post_tag) { return 0; } \
            constexpr static int track_wrapper(return_tag) { return 0; } \
            FORCE_INLINE static void wrap(T &, uint64_t, int, pre_tag) { } \
            FORCE_INLINE static void wrap(T &, uint64_t, int, post_tag) { } \
            FORCE_INLINE static void wrap(T &, uint64_t, int, return_tag) { } \
        }; \
    }; \
    \
    template <> \
    class class_name<void *> { \
    public: \
        enum { \
            NUM = 0, \
            IS_DEFINED = 1 \
        }; \
        struct impl { \
            constexpr static int track_wrapper(pre_tag) { return 0; } \
            constexpr static int track_wrapper(post_tag) { return 0; } \
            constexpr static int track_wrapper(return_tag) { return 0; } \
            FORCE_INLINE static void wrap(void *, uint64_t, int, pre_tag) { } \
            FORCE_INLINE static void wrap(void *, uint64_t, int, post_tag) { } \
            FORCE_INLINE static void wrap(void *, uint64_t, int, return_tag) { } \
        }; \
    };


template <int>
struct choose_wrapper;

MAKE_BASE_WRAPPER(wrap_type)
MAKE_BASE_WRAPPER(module_wrap_type)

template <>
struct choose_wrapper<0> {
public:
    template <typename Arg>
    struct wrap : public wrap_type<Arg> { };
};

template <>
struct choose_wrapper<1> {
public:
    template <typename Arg>
    struct wrap : public module_wrap_type<Arg> { };
};

/// implementation of wrappers; performs automatic taint tracking if the type
/// is appropriately tracked
template <template<typename> class Wrap, typename Arg, typename Tag, const int IS_TRACKED>
class tracked_recursive_wrapper;

// case 0: untracked, or shouldn't be tracked
template <template<typename> class Wrap, typename Arg, typename Tag>
class tracked_recursive_wrapper<Wrap, Arg, Tag, 0> {
public:
    FORCE_INLINE static void wrap(Arg &arg, uint64_t func_addr, const int depth__) {
        Wrap<Arg>::impl::wrap(arg, func_addr, depth__, static_tag<Tag>::tag);
    }
};

// case 1: tracked using function pointers
template <template<typename> class Wrap, typename Arg, typename Tag>
class tracked_recursive_wrapper<Wrap, Arg, Tag, 1> {
public:
    FORCE_INLINE static void wrap(Arg &arg, uint64_t func_addr, const int depth__) {
        WITH_FUNC_TAINTED_DATA(arg, {
            Wrap<Arg>::impl::wrap(arg, func_addr, depth__, static_tag<Tag>::tag);
        });
    }
};

// case 2: tracked using structure extension
template <template<typename> class Wrap, typename Arg, typename Tag>
class tracked_recursive_wrapper<Wrap, Arg, Tag, 2> {
public:
    FORCE_INLINE static void wrap(Arg &arg, uint64_t func_addr, const int depth__) {
        WITH_STRUCT_TAINTED_DATA(arg, {
            Wrap<Arg>::impl::wrap(arg, func_addr, depth__, static_tag<Tag>::tag);
        });
    }
};

/// type reduction for recursive wrappers
template <template<typename> class Wrap, typename Arg>
class recursive_wrapper_base {
public:
    enum {
        NUM = Wrap<Arg>::NUM
    };

    inline static void pre_wrap(Arg &arg, uint64_t func_addr, const int depth__) {
        enum {
            CAN_TRACK_WRAPPER = !!Wrap<Arg>::impl::track_wrapper(pre_tag()),
            IS_TRACKED = !!IS_TRACKED_TYPE(typename, Arg),
            IS_STRUCT_TRACKED = !!IS_STRUCT_TRACKED_TYPE(typename, Arg),
            TRACK_TYPE = CAN_TRACK_WRAPPER ? (IS_TRACKED + IS_STRUCT_TRACKED) : 0,
        };
        tracked_recursive_wrapper<Wrap, Arg, pre_tag, TRACK_TYPE>::wrap(arg, func_addr, depth__);
    }
    inline static void post_wrap(Arg &arg, uint64_t func_addr, const int depth__) {
        enum {
            CAN_TRACK_WRAPPER = !!Wrap<Arg>::impl::track_wrapper(post_tag()),
            IS_TRACKED = !!IS_TRACKED_TYPE(typename, Arg),
            IS_STRUCT_TRACKED = !!IS_STRUCT_TRACKED_TYPE(typename, Arg),
            TRACK_TYPE = CAN_TRACK_WRAPPER ? (IS_TRACKED + IS_STRUCT_TRACKED) : 0,
        };
        tracked_recursive_wrapper<Wrap, Arg, post_tag, TRACK_TYPE>::wrap(arg, func_addr, depth__);
    }
    inline static void return_wrap(Arg &arg, uint64_t func_addr, const int depth__) {
        enum {
            CAN_TRACK_WRAPPER = !!Wrap<Arg>::impl::track_wrapper(return_tag()),
            IS_TRACKED = !!IS_TRACKED_TYPE(typename, Arg),
            IS_STRUCT_TRACKED = !!IS_STRUCT_TRACKED_TYPE(typename, Arg),
            TRACK_TYPE = CAN_TRACK_WRAPPER ? (IS_TRACKED + IS_STRUCT_TRACKED) : 0,
        };
        //tracked_recursive_wrapper<Wrap, Arg, return_tag, TRACK_TYPE>::wrap(arg, depth__);
    }
};

/// type reduction for recursive wrappers
template <template<typename> class Wrap, typename Arg>
class recursive_wrapper : public recursive_wrapper_base<Wrap, Arg> { };

template <template<typename> class Wrap, typename Arg>
class recursive_wrapper<Wrap, const Arg> {
public:

    enum {
        NUM = Wrap<Arg>::NUM
    };

    inline static void pre_wrap(const Arg &arg, uint64_t func_addr, const int depth__) {
        recursive_wrapper<Wrap, Arg>::pre_wrap(const_cast<Arg &>(arg), func_addr, depth__);
    }
    inline static void post_wrap(const Arg &arg, uint64_t func_addr, const int depth__) {
        recursive_wrapper<Wrap, Arg>::post_wrap(const_cast<Arg &>(arg), func_addr, depth__);
    }
    inline static void return_wrap(const Arg &arg, uint64_t func_addr, const int depth__) {
        kern_printk("return wrapper\n");
        recursive_wrapper<Wrap, Arg>::return_wrap(const_cast<Arg &>(arg), func_addr, depth__);
    }
};

#if 0
template <template<typename> class Wrap, typename Arg>
class recursive_wrapper<Wrap, Arg> {
public:

    enum {
        NUM = 0
    };

    inline static void pre_wrap(const Arg &arg, const int depth__) {
        recursive_wrapper<Wrap, Arg>::pre_wrap(const_cast<Arg &>(arg), depth__);
    }
    inline static void post_wrap(const Arg &arg, const int depth__) {
        recursive_wrapper<Wrap, Arg>::post_wrap(const_cast<Arg &>(arg), depth__);
    }
    inline static void return_wrap(const Arg &arg, const int depth__) {
        kern_printk("return wrapper8\n");
        recursive_wrapper<Wrap, Arg>::return_wrap(const_cast<Arg &>(arg), depth__);
    }
};
#endif
template <template<typename> class Wrap, typename Arg>
class recursive_wrapper<Wrap, Arg *> {
public:

    enum {
        NUM = Wrap<Arg *>::IS_DEFINED
        	? 1
			: recursive_wrapper<Wrap, Arg>::NUM
    };

    inline static void pre_wrap(Arg *&arg, uint64_t func_addr, const int depth__) {
        if(((Arg *) 4095) < arg) {
        	if(Wrap<Arg *>::IS_DEFINED) {
        		recursive_wrapper_base<Wrap, Arg *>::pre_wrap(arg, func_addr, depth__);
        	} else {
        		recursive_wrapper<Wrap, Arg>::pre_wrap(*arg, func_addr, depth__);
        	}
        }
    }
    inline static void post_wrap(Arg *&arg, uint64_t func_addr, const int depth__) {
        if(((Arg *) 4095) < arg) {
        	if(Wrap<Arg *>::IS_DEFINED) {
				recursive_wrapper_base<Wrap, Arg *>::post_wrap(arg, func_addr, depth__);
			} else {
				recursive_wrapper<Wrap, Arg>::post_wrap(*arg, func_addr, depth__);
			}
        }
    }
    inline static void return_wrap(Arg *&arg, uint64_t func_addr, const int depth__) {
        kern_printk("return wrapper1\n");
        if(((Arg *) 4095) < arg) {
            if(Wrap<Arg *>::IS_DEFINED) {
                recursive_wrapper_base<Wrap, Arg *>::return_wrap(arg, func_addr, depth__);
            } else {
                recursive_wrapper<Wrap, Arg>::return_wrap(*arg, func_addr, depth__);
            }
        }
    }
};

template <template<typename> class Wrap, typename Arg>
class recursive_wrapper<Wrap, Arg **> {
public:

    enum {
        NUM = recursive_wrapper<Wrap, Arg *>::NUM
    };

    inline static void pre_wrap(Arg **&arg, uint64_t func_addr, const int depth__) {
        if(((Arg **) 4095) < arg) {
            recursive_wrapper<Wrap, Arg *>::pre_wrap(*arg, func_addr, depth__);
        }
    }
    inline static void post_wrap(Arg **&arg, uint64_t func_addr, const int depth__) {
        if(((Arg **) 4095) < arg) {
            recursive_wrapper<Wrap, Arg *>::post_wrap(*arg, func_addr, depth__);
        }
    }
    inline static void return_wrap(Arg **&arg, uint64_t func_addr, const int depth__) {
        kern_printk("return wrapper2\n");
        if(((Arg **) 4095) < arg) {
            recursive_wrapper<Wrap, Arg *>::return_wrap(*arg, func_addr, depth__);
        }
    }
};

template <template<typename> class Wrap, typename Ret, typename... Args>
class recursive_wrapper<Wrap, Ret (*)(Args...)> {
public:

    typedef Ret (Arg)(Args...);

    enum {
        NUM = Wrap<Arg *>::NUM
    };

    inline static void pre_wrap(Arg *&arg, uint64_t func_addr, const int depth__) {
        if(((Arg *) 4095) < arg) {
            pre_tag tag;
            Wrap<Arg *>::impl::wrap(arg, func_addr, depth__, tag);
        }
    }
    inline static void post_wrap(Arg *&arg, uint64_t func_addr, const int depth__) {
        if(((Arg *) 4095) < arg) {
            post_tag tag;
            Wrap<Arg *>::impl::wrap(arg, func_addr, depth__, tag);
        }
    }
    inline static void return_wrap(Arg *&arg, uint64_t func_addr, const int depth__) {
        kern_printk("return wrapper3\n");
        if(((Arg *) 4095) < arg) {
            return_tag tag;
            Wrap<Arg *>::impl::wrap(arg, func_addr, depth__, tag);
        }
    }
};

template <template<typename> class Wrap, typename Arg>
class recursive_wrapper<Wrap, Arg &> : public recursive_wrapper<Wrap, Arg> { };

#if 1
template <template<typename> class Wrap>
class recursive_wrapper<Wrap, void *> {
public:
    enum {
        NUM = 0
    };

    FORCE_INLINE static void pre_wrap(void *, uint64_t, int) { }
    FORCE_INLINE static void post_wrap(void *, uint64_t, int) { }
    FORCE_INLINE static void return_wrap(void *, uint64_t, int) {
        kern_printk("return wrapper5\n");
    }
};

template <template<typename> class Wrap>
class recursive_wrapper<Wrap, int> {
public:
    enum {
        NUM = 0
    };

    FORCE_INLINE static void pre_wrap(int, uint64_t, int) { }
    FORCE_INLINE static void post_wrap(int, uint64_t, int) { }
    FORCE_INLINE static void return_wrap(int, uint64_t, int) {
        kern_printk("return wrapper19\n");
    }
};

template <template<typename> class Wrap>
class recursive_wrapper<Wrap, const void *> {
public:
    enum {
        NUM = 0
    };

    FORCE_INLINE static void pre_wrap(const void *, uint64_t, int) { }
    FORCE_INLINE static void post_wrap(const void *, uint64_t, int) { }
    FORCE_INLINE static void return_wrap(const void *, uint64_t, int) {
        kern_printk("return wrapper6\n");
    }
};
#endif
/// recursively wrap some argument; benefits from type deduction
/// uses the type tag (passed through recursive_wrapper) and define
/// in the pre/post macros to dispatch to the correct wrapper. e.g. when
/// WRAP_RECURSIVE is used in post { ... }, the post wrappers are called.
template <template<typename> class Wrap, typename Arg>
void wrap_recursive(Arg &arg, uint64_t func_addr, const int depth__, pre_tag) {
    recursive_wrapper<Wrap, Arg>::pre_wrap(arg, func_addr, depth__);
}
template <template<typename> class Wrap, typename Arg>
void wrap_recursive(Arg &arg, uint64_t func_addr, const int depth__, post_tag) {
    recursive_wrapper<Wrap, Arg>::post_wrap(arg, func_addr, depth__);
}

/// base cases for wrapping arguments
template <template<typename> class Wrap >
FORCE_INLINE void arg_pre_wrapper(int, uint64_t) {
	D(kern_printk("%s\n", __FUNCTION__));
}

template <template<typename> class Wrap >
FORCE_INLINE void arg_post_wrapper(int, uint64_t) {
	D(kern_printk("%s\n", __FUNCTION__));
}
/*
template <template<typename> class Wrap >
FORCE_INLINE void arg_return_wrapper(int) {
    D(kern_printk("%s\n", __FUNCTION__));
}
*/
/// unroll and wrap arguments by type
template <template<typename> class Wrap, typename Arg, typename... Rest>
inline void arg_pre_wrapper(const int depth__, uint64_t func_addr, Arg &arg, Rest&... rest) {
    recursive_wrapper<Wrap, Arg>::pre_wrap(arg, func_addr, depth__);
    arg_pre_wrapper<Wrap, Rest...>(depth__, func_addr, rest...);
}

template <template<typename> class Wrap, typename Arg, typename... Rest>
inline void arg_post_wrapper(const int depth__, uint64_t func_addr, Arg &arg, Rest&... rest) {
    recursive_wrapper<Wrap, Arg>::post_wrap(arg, func_addr, depth__);
    arg_post_wrapper<Wrap, Rest...>(depth__, func_addr, rest...);
}

template <template<typename> class Wrap, typename Arg>
inline void arg_return_wrapper(const int depth__, Arg arg){
    recursive_wrapper<Wrap, Arg>::return_wrap(arg, depth__);
}

/// count how many arguments are being wrapped
template <template<typename> class Wrap, typename ...Args>
class count_wrappers;

template <template<typename> class Wrap, typename First, typename ...Rest>
class count_wrappers<Wrap, First, Rest...> {
public:
    enum {
        NUM = recursive_wrapper<Wrap, First>::NUM + count_wrappers<Wrap, Rest...>::NUM,
        HAS_ANY = NUM > 0
    };
};

template <template<typename> class Wrap>
class count_wrappers<Wrap> {
public:
    enum {
        NUM = 0,
        HAS_ANY = false
    };
};

extern "C" {
    extern uint64_t get_return_address(void);
    extern void set_return_address(uint64_t);
    extern void set_section_state(enum section_state state);
    extern void unset_section_state(enum section_state state);
}

/// implementation of the wrapper for function returning a value
template <const uint64_t addr, typename R, typename... Args>
class cfi_wrapper_impl {
public:
    static R wrapper(Args... args) {
        typedef R (orig_func_type)(Args...);
        D( kern_printk("in wrapper for %lx; wrapping %lu args\n", (uint64_t) addr, sizeof...(Args)); )
        const int depth__ = 0;
        enum section_state state;
        state = (enum section_state)get_section_state();
        if(!(state & KERNEL_WRAPPER_SET)){
            if(count_wrappers<wrap_type, Args...>::HAS_ANY) {
                arg_pre_wrapper<wrap_type, Args...>(depth__,addr, args...);
            }
        }
        //native_box<R> ret_val(addr, args...);
        set_section_state(KERNEL_WRAPPER_SET);
        R ret(((orig_func_type *) addr)(args...));
        unset_section_state(KERNEL_WRAPPER_SET);
        if(count_wrappers<wrap_type, Args...>::HAS_ANY) {
            arg_post_wrapper<wrap_type, Args...>(depth__,addr, args...);
        }

       // arg_return_wrapper<wrap_type, R>(depth__, ret);

        return ret;
    }
};
template <const uint64_t addr, typename... Args>
class cfi_wrapper_impl<addr, void, Args...> {
public:
	typedef void R;
    static R wrapper(Args... args) {
        typedef R (orig_func_type)(Args...);
        D( kern_printk("in wrapper for %lx; wrapping %lu args\n", (uint64_t) addr, sizeof...(Args)); )
        const int depth__ = 0;
        enum section_state state;
        state = (enum section_state)get_section_state();
        if(!(state & KERNEL_WRAPPER_SET)){
            if(count_wrappers<wrap_type, Args...>::HAS_ANY) {
                arg_pre_wrapper<wrap_type, Args...>(depth__,addr, args...);
            }
        }
        set_section_state(KERNEL_WRAPPER_SET);
        ((orig_func_type *) addr)(args...);
        unset_section_state(KERNEL_WRAPPER_SET);
        if(count_wrappers<wrap_type, Args...>::HAS_ANY) {
            arg_post_wrapper<wrap_type, Args...>(depth__,addr, args...);
        }
    }
};




#ifdef MODULE_ENTRY_DISABLE
        typedef R (orig_func_type)(Args...);
        D( kern_printk("in dynamic wrapper for %lx; wrapping %lu args\n", (uint64_t) addr, sizeof...(Args)); )
        const int depth__ = 0;
        if(count_wrappers<wrap_type, Args...>::HAS_ANY) {
            arg_pre_wrapper<wrap_type, Args...>(depth__, args...);
        }

        asm(
                "mov 0x8(%%rbp), %0;"
                "sub $0x20000005, %0;"    // convert shadow addr to module addr
        		"mov %0, 0x8(%%rbp);"
        		"pop %0;"
        		"mov %%rbp, %%rsp;"
        		"pop %%rbp;"
        		"jmp dr_app_start;"
        		: "=r"(addr)
        );

        return 0;
#if 0
    	uint64_t addr(0);
        typedef R (orig_func_type)(Args...);
 /*       asm (
        		"mov 0x8(%%rbp), %0;"
        		"sub $0x20000005, %0;"
        		"lea"
        		:"=r"(addr)
        		);*/
         D( kern_printk("in dynamic wrapper for %lx; wrapping %lu args\n", (uint64_t) addr, sizeof...(Args)); )
         const int depth__ = 0;
         if(count_wrappers<wrap_type, Args...>::HAS_ANY) {
             arg_pre_wrapper<wrap_type, Args...>(depth__, args...);
         }

         asm(
                 "push %rbx;"
                 "mov 0x8(%rbp), %rbx;"
                 "sub $0x20000005, %rbx;"    // convert shadow addr to module addr
        		 "mov %rbx, 0x8(%rbp);"
        		 "pop %rbx;"
        		 "mov %rbp, %rsp;"
        		 "pop %rbp;"
        		 "jmp dr_app_start;"
         );

         return (R)0;
#else
#endif
#endif



/// include shadow aliasing machinery
//#include "cfi_alias.hpp"
#include "descriptor_table.hpp"
#include "aliases/aliases.hpp"
#include "cfi_scanner.hpp"

/// implementation of the wrapper for function returning a value
template <typename R, typename... Args>
class cfi_dynamic_wrapper_impl {
public:
    static R wrapper(Args... args) {


        uint64_t addr;

#if 1
        const int depth__ = 0;

        __asm__ volatile(
			"mov %%r10, %0;"
			: "=m"(addr)
		);

        typedef R (orig_func_type)(Args...);

        if(count_wrappers<module_wrap_type, Args...>::HAS_ANY) {
            D(kern_printk("in dynamic wrapper for %lx; wrapping %lu args\n", (uint64_t) addr,  sizeof...(Args)));
            arg_pre_wrapper<module_wrap_type, Args...>(depth__,addr, args...);
        }
     //   cfi_print_symbol_name((void*)addr);
        cfi_thread_slot_module_enrty();
#else
        __asm__ volatile(
            "mov %%rbp, %%rsp;"
            "pop %%rbp;"
            "push %%r10;"
            "jmp dr_app_start;"
            : "=m"(addr)
        );
#endif
        dr_app_start();
        R ret(((orig_func_type *) addr)(args...));
        /* implicit dr_app_stop(); */
/*
        if(is_kernel_virtual_address_space(ret)){
            if(!is_alias_address((uint64_t)ret)){
                kern_printk( "adding return object for type scanning\n");
               // ADD_TO_HASH(ret, SCAN_HEAD_FUNC(DECLTYPE(*ret)));
            }else {
                cfi_return_to_kernel((void*)ret);
            }
        }
*/
        if(count_wrappers<module_wrap_type, Args...>::HAS_ANY) {
            arg_post_wrapper<module_wrap_type, Args...>(depth__, addr, args...);
        }
        /*

        if(count_wrappers<module_wrap_type, R>::HAS_ANY) {
            arg_return_wrapper<module_wrap_type, R>(depth__, ret);
        }
*/
        return ret;
    }
};

/// implementation of the wrapper for function returning a value
template <typename... Args>
class cfi_dynamic_wrapper_impl<void, Args...> {
public:
	typedef void R;
    static R wrapper(Args... args) {
    	uint64_t addr;
#if 1
        const int depth__ = 0;

        __asm__ volatile(
			"mov %%r10, %0;"
        	: "=m"(addr)
	    );

        typedef R (orig_func_type)(Args...);

        //break_on_dynamic_module_wrapper();
        if(count_wrappers<module_wrap_type, Args...>::HAS_ANY) {
        	D(kern_printk("in dynamic wrapper for %lx; wrapping %lu args\n", (uint64_t) addr, sizeof...(Args)));
            arg_pre_wrapper<module_wrap_type, Args...>(depth__,addr, args...);
        }
        cfi_thread_slot_module_enrty();
#else
        __asm__ volatile(
            "mov %%rbp, %%rsp;"
            "pop %%rbp;"
            "push %%r10;"
            "jmp dr_app_start;"
            : "=m"(addr)
        );
#endif

        dr_app_start();
        ((orig_func_type *) addr)(args...);
        /* implicit dr_app_stop(); */

        if(count_wrappers<module_wrap_type, Args...>::HAS_ANY) {
            arg_post_wrapper<module_wrap_type, Args...>(depth__, addr, args...);
        }
    }
};

template <typename R, typename... Args>
struct cfi_dynamic_wrapper_ret_impl {
	static void wrapper(Args... args) throw() {
		//uint64_t addr(get_return_address() - 0x20000005);
		uint64_t slot_address(get_return_address() + 0x3);
		uint64_t addr = (uint64_t)(*(uint64_t*)slot_address);

		__asm__ volatile (
			"mov %0, %%r10;"
			"movq $%c1, 0x8(%%rbp);"
			:
			: "m"(addr), "i"(cfi_dynamic_wrapper_impl<R, Args...>::wrapper)
		    : "r10"
		);
		return;
	}
};


/// convert an arbitrary function type into one that is in the shadow module
/// iff the original is in the shadow
template <typename R, typename... Args>
R (*to_shadow_address(R (*func_ptr)(Args...)))(Args...) {
    typedef R (func_type)(Args...);

    uint64_t addr((uint64_t) func_ptr);
#if 1

    if(MODULE_START_ADDR <= addr && addr < MODULE_END_ADDR) {

        if(!shadow_allocator::is_shadow_allocate((void*)addr)) {
            void *value = NULL;
            hashmap_get(dynamic_wrapper_table, (void*)addr, &value);

            if((value == NULL)){
                int ret = 0;
                D(kern_printk("inside allocator wrapping address : %llx\n", addr);)

                uint64_t wrapper_addr = (uint64_t) cfi_dynamic_wrapper_ret_impl<R, Args...>::wrapper;

                shadow_region *region = shadow_allocator::allocate();

                if(NULL == region) {
                    granary_fault();
                    return (func_type *)addr;
                }

                uint64_t *shadow_address((uint64_t*)&(region->instr));

                int64_t shadow_ptr = (int64_t)shadow_address;
                int64_t offset_val = (wrapper_addr - (shadow_ptr + 5));

                unsigned char instruction[] = {
                        0xe8, 0x00, 0x00, 0x00, 0x00,
                        /*      0x68, 0x00, 0x00, 0x00, 0x00, */
                        0xc3 // ret
                };

                instruction[1] = ((offset_val >> 0)     & 0xff);
                instruction[2] = ((offset_val >> 8)     & 0xff);
                instruction[3] = ((offset_val >> 16)    & 0xff);
                instruction[4] = ((offset_val >> 24)    & 0xff);

                memcpy((void*)shadow_address, instruction, 6);

                region->slot = addr;

#if 0
                /*
                unsigned long hotpatch_instruction[] = {
                        0xe8, 0x00, 0x00, 0x00, 0x00,
                       */ /*      0x68, 0x00, 0x00, 0x00, 0x00, */
                       /* 0xc3 // ret
                };

                hotpatch_instruction[1] = ((offset_val >> 0)     & 0xff);
                hotpatch_instruction[2] = ((offset_val >> 8)     & 0xff);
                hotpatch_instruction[3] = ((offset_val >> 16)    & 0xff);
                hotpatch_instruction[4] = ((offset_val >> 24)    & 0xff);

                hotpatch_instr = (volatile uint64_t){(hotpatch_instruction[0])
                                                + (hotpatch_instruction[1] << 8)
                                                + (hotpatch_instruction[2] << 16)
                                                + (hotpatch_instruction[3] << 24)
                                                + (hotpatch_instruction[4] << 32)
                                                + (hotpatch_instruction[5] << 40)};


                memcpy(shadow_address);
                if(shadow_address > (uint64_t*)4095){
                    oldval = *(shadow_address);
                    newval = hotpatch_instr;

                    do {
                        newval = hotpatch_instr;
                    }while(!__sync_bool_compare_and_swap(shadow_address, oldval, newval));
                }

                if(shadow_slot > (uint64_t*)4095){
                    oldval = *(shadow_slot);
                    newval = addr;

                    do {
                        newval = addr;
                    }while(!__sync_bool_compare_and_swap(shadow_slot, oldval, newval));
                }*/
#endif
                ret = hashmap_put(dynamic_wrapper_table, (void*)addr, (void*)region);
                D(kern_printk(" inside allocator actual address : %llx\t wrapper address : %llx\n", addr, shadow_address);)
                addr = (uint64_t)shadow_address;
            } else {
                D(kern_printk("actual address : %llx\t wrapper address : %llx\n", addr, value);)

                addr = (uint64_t)&(((shadow_region*)value)->instr);
            }
        }

    }
#else
    // the address is already in the shadow
    if(MODULE_SHADOW_START <= addr && addr < MODULE_SHADOW_END) {
        (void) addr;

    // convert module address to shadow address
    } else if(MODULE_START_ADDR <= addr && addr < MODULE_END_ADDR) {
        volatile uint64_t oldval = 0x0ULL;
        volatile uint64_t newval = 0x0ULL;
        volatile uint64_t hotpatch_instr = 0x0ULL;


        addr += MODULE_SHADOW_OFFSET;
        uint64_t wrapper_addr = (uint64_t) cfi_dynamic_wrapper_ret_impl<R, Args...>::wrapper;
     //   uint64_t wrapper_addr = (uint64_t) cfi_enter_module_from_shadow;
        // initialize the 'call' instruction in the shadow if not present
        char *shadow_code((char *) addr);
        volatile uint64_t *shadow_address((uint64_t*)addr);


        int64_t shadow_ptr = (int64_t)shadow_address;
        int64_t offset_val = (wrapper_addr - (shadow_ptr + 5));
#if 0
        unsigned char shadow_instruction[] = {
			0xe8, 0x00, 0x00, 0x00, 0x00,

	/*		0x68, 0x00, 0x00, 0x00, 0x00, */
			0xc3 // ret
        };

        shadow_instruction[1] = ((offset_val >> 0)     & 0xff);
        shadow_instruction[2] = ((offset_val >> 8)     & 0xff);
        shadow_instruction[3] = ((offset_val >> 16)    & 0xff);
        shadow_instruction[4] = ((offset_val >> 24)    & 0xff);

        memcpy(shadow_code, shadow_instruction, 6);
#endif
        unsigned long hotpatch_instruction[] = {
            0xe8, 0x00, 0x00, 0x00, 0x00,

    /*      0x68, 0x00, 0x00, 0x00, 0x00, */
            0xc3 // ret
        };

        hotpatch_instruction[1] = ((offset_val >> 0)     & 0xff);
        hotpatch_instruction[2] = ((offset_val >> 8)     & 0xff);
        hotpatch_instruction[3] = ((offset_val >> 16)    & 0xff);
        hotpatch_instruction[4] = ((offset_val >> 24)    & 0xff);

        {


            hotpatch_instr = (volatile uint64_t){(hotpatch_instruction[0])
                                        + (hotpatch_instruction[1] << 8)
                                        + (hotpatch_instruction[2] << 16)
                                        + (hotpatch_instruction[3] << 24)
                                        + (hotpatch_instruction[4] << 32)
                                        + (hotpatch_instruction[5] << 40)};

            /*this condition is not required but shadow_address is sometime taking garbage value
             * TODO: a more appropriate fix is required for this; don't know what is the reason*/
          //  region->instr = hotpatch_instr;
          //  region->slot = (uint64_t)addr;

            if(shadow_address > (uint64_t*)4095){
                oldval = *(shadow_address);
                newval = hotpatch_instr;
                __sync_bool_compare_and_swap(shadow_address, oldval, newval);
/*
                do {
                    newval = hotpatch_instr;
                }while(!__sync_bool_compare_and_swap(shadow_address, oldval, newval));*/
            }
           // kern_printk("shadow region instr : %llx, slot : %llx\n", region->instr, region->slot);
        }


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
#endif
    return (func_type *) addr;


}


//////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////

extern "C" {
#ifndef INCLUDED_KERNEL_TYPES_H_
#define INCLUDED_KERNEL_TYPES_H_
#   include "linux_wrapper/kernel_types.h"
#endif
}




/// include dynamic wrapper machinery
//#include "cfi_dynamic_wrapper.hpp"

/// include all wrappers; must be after the above template definitions
/// so that partial specializations of cfi_wrapper_impl for FUNC_WRAPPERs
/// take control for specific functions.
#include "linux_wrapper/wrappers.h"

/// C++ constexpr wrapper; we are given the absolute address of the function,
/// hence why we only care about its address and its types
template <const uint64_t addr, typename R, typename... Args>
constexpr cfi_type_erased_func_ptr cfi_wrapper(R (*)(Args...)) {
    return (cfi_type_erased_func_ptr) cfi_wrapper_impl<addr, R, Args...>::wrapper;
}

/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////


#define HOTPATCH_WRAPPER(func_name, args, body) \
    template <typename R, typename... Args> \
    class cfi_hotpatch_impl<KERN_ADDR_ ## func_name, R, Args...> { \
    public: \
        static R wrapper args { \
            constexpr int WRAP_CHOICE = 0; \
            typedef R (orig_func_type)(Args...); \
            orig_func_type *func_name = ((orig_func_type *) KERN_ADDR_ ## func_name); \
            uint64_t func_addr = (uint64_t)func_name; \
            (void) func_name; \
            pre_tag tag__; \
            const int depth__ = 0; \
            (void) tag__; \
            (void) depth__; \
            (void) WRAP_CHOICE; \
            body \
        } \
    };

#define HOTPATCH_WRAPPER_VOID(func_name, args, body) \
    template <typename... Args> \
    class cfi_hotpatch_impl<KERN_ADDR_ ## func_name, void, Args...> { \
    public: \
        static void wrapper args { \
            constexpr int WRAP_CHOICE = 0; \
            typedef void (orig_func_type)(Args...); \
            orig_func_type *func_name = ((orig_func_type *) KERN_ADDR_ ## func_name); \
            uint64_t func_addr = (uint64_t)func_name; \
            (void) func_name; \
            pre_tag tag__; \
            const int depth__ = 0; \
            (void) tag__; \
            (void) depth__; \
            (void) WRAP_CHOICE; \
            body \
        } \
    };


/// implementation of the wrapper for function returning a value
template <const uint64_t addr, typename R, typename... Args>
class cfi_hotpatch_impl {
public:
    static R wrapper(Args... args) {
        typedef R (orig_func_type)(Args...);
        D( kern_printk("in wrapper for %lx; wrapping %lu args\n", (uint64_t) addr, sizeof...(Args)); )

        R ret(((orig_func_type *) addr)(args...));

        return ret;
    }
};
template <const uint64_t addr, typename... Args>
class cfi_hotpatch_impl<addr, void, Args...> {
public:
    typedef void R;
    static R wrapper(Args... args) {
        typedef R (orig_func_type)(Args...);
        D( kern_printk("in wrapper for %lx; wrapping %lu args\n", (uint64_t) addr, sizeof...(Args)); )
        ((orig_func_type *) addr)(args...);
    }
};

#include "linux_wrapper/wrapper_hotpatch.h"

template <const uint64_t addr, typename R, typename... Args>
constexpr cfi_type_erased_func_ptr cfi_hotpatch(R (*)(Args...)) {
    return (cfi_type_erased_func_ptr) cfi_hotpatch_impl<addr, R, Args...>::wrapper;
}

#undef D
#undef pre
#undef post

#endif /* DRK_CFI_WRAPPER_HPP_ */
