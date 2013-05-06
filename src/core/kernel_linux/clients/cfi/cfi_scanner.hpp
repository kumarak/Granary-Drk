/*
 * cfi_scanner.hpp
 *
 *  Created on: 2013-02-08
 *      Author: akshayk
 */

#ifndef CFI_SCANNER_HPP_
#define CFI_SCANNER_HPP_

#define KERNEL_ADDRESS_OFFSET       0xffff000000000000
#define KERNEL_MEMORY_START         0xffff880000000000
#define KERNEL_MEMORY_HOLE_START    0xffffc80000000000
#define KERNEL_MEMORY_HOLE_END      0xffffc8ffffffffff
#define USER_ADDRESS_OFFSET         0x00007fffffffffff


/// used to more easily define scan function in terms of a type and a function body
/// that operates on the 'arg' variable

#define SCAN \
    FORCE_INLINE static void scan(struct hashtable_t *htable, ArgT__ &arg, const int depth__)



#define TYPE_SCAN_WRAPPER(type_name, body) \
    template <> \
    class scan_function<type_name> { \
    public: \
        enum { \
            NUM = 1, \
            IS_DEFINED = 1 \
        }; \
        typedef identity_type<type_name>::type ArgT__; \
        static unsigned id_;\
        struct scan_impl body ; \
    };

// Scan an l-value that is a function pointer
#define SCAN_FUNCTION(lval) \
        address_scanner_function(lval); \


//#define SCAN_PTR SCAN_FUNC

#define SCAN_HEAD   \
        FORCE_INLINE static void scan_head(ArgT__ &arg)

// recursively Scan

#define SCAN_RECURSIVE(lval)  \
            if(depth__ <= MAX_DEPTH_SCANNER)    {   \
                scan_recursive<scan_function, DECLTYPE(lval)>(htable, lval, depth__+1);\
            }

#define SCAN_RECURSIVE_PTR(lval)  \
        if(!is_alias_address((uint64_t)lval)) {  \
                if(NULL != (uint64_t*)&(*lval)) {   \
                    if(depth__ <= MAX_DEPTH_SCANNER)    {   \
                        scan_recursive<scan_function, DECLTYPE(*(lval))>(htable, *(lval), depth__+1);   \
                    }\
                }   \
        } else {    \
            cfi_collect_watcpoint((void*)0, (void*)lval);   \
        }

#define MAX_DEPTH_SCANNER 5

#define SCANNER(type_name) \
        scan_function<type_name>::scan_impl::scan(htable, arg, MAX_DEPTH_SCANNER)

#define SCAN_HEAD_FUNC(type_name) \
        scan_function<type_name>::scan_impl::scan_head

/// Scan an argument based on its type

template<typename T>
class type_id_impl {
public:
    static unsigned get(void) throw() {
        static unsigned id_(0);
        return id_++;
    }
};

template<typename T, typename Category=void>
class type_class {
public:
    static unsigned get_id(void) throw () {
        static type_class id_(type_id_impl<Category>::get());
        return id_;
    }

    static unsigned get_size(void) throw () {
        unsigned size_ = sizeof(T);
        return size_;
    }
};




template <typename T>
class scan_function {
public:
	enum {
		NUM = 0,
		IS_DEFINED = 1
	};

	struct scan_impl {
	    FORCE_INLINE static void scan_head(T &) { }
		FORCE_INLINE static void scan(struct hashtable_t *htable, T & , const int depth__) { }
	};
};

template <>
class scan_function<void *> {
public:
	enum {
		NUM = 0,
		IS_DEFINED = 1
	};
	static unsigned id_;
	struct scan_impl{
	    FORCE_INLINE static void scan_head(void*) { }
		FORCE_INLINE static void scan(struct hashtable_t *htable, void*, const int depth__) { }
	};
};


/// type reduction for recursive wrappers
template <template<typename> class Scan, typename Arg>
class recursive_scanner_base {
public:
    enum {
        NUM = Scan<Arg>::NUM
    };

    inline static void pre_scan(struct hashtable_t* htable, Arg &arg, const int depth__) {
        Scan<Arg>::scan_impl::scan(htable, arg, depth__);
    }
};

/// type reduction for recursive wrappers
template <template<typename> class Scan, typename Arg>
class recursive_scanner : public recursive_scanner_base<Scan, Arg> { };

template <template<typename> class Scan, typename Arg>
class recursive_scanner<Scan, const Arg> {
public:

    enum {
        NUM = Scan<Arg>::NUM
    };

    inline static void pre_scan(struct hashtable_t* htable, const Arg &arg, const int depth__) {
        recursive_scanner<Scan, Arg>::pre_scan(htable, const_cast<Arg &>(arg), depth__);
    }
};

template <template<typename> class Scan, typename Arg>
class recursive_scanner<Scan, Arg *> {
public:

    enum {
        NUM = Scan<Arg *>::IS_DEFINED
        	? 1
			: recursive_scanner<Scan, Arg>::NUM
    };

    inline static void pre_scan(struct hashtable_t* htable, Arg *&arg, const int depth__) {
        if(((Arg *) 4095) < arg) {
        	if(Scan<Arg *>::IS_DEFINED) {
        		recursive_scanner_base<Scan, Arg *>::pre_scan(htable, arg, depth__);
        	} else {
        		recursive_scanner<Scan, Arg>::pre_scan(htable, *arg, depth__);
        	}
        }
    }
};

template <template<typename> class Scan, typename Arg>
class recursive_scanner<Scan, Arg **> {
public:

    enum {
        NUM = recursive_scanner<Scan, Arg *>::NUM
    };

    inline static void pre_scan(struct hashtable_t* htable, Arg **&arg, const int depth__) {
        if(((Arg **) 4095) < arg) {
            recursive_scanner<Scan, Arg *>::pre_scan(htable, *arg, depth__);
        }
    }
};

template <template<typename> class Scan, typename Ret, typename... Args>
class recursive_scanner<Scan, Ret (*)(Args...)> {
public:

    typedef Ret (Arg)(Args...);

    enum {
        NUM = Scan<Arg *>::NUM
    };

    inline static void pre_scan(struct hashtable_t* htable, Arg *&arg, const int depth__) {
        if(((Arg *) 4095) < arg) {
            pre_tag tag;
            Scan<Arg *>::scan_impl::scan(htable, arg, depth__);
        }
    }
};

template <template<typename> class Scan, typename Arg>
class recursive_scanner<Scan, Arg &> : public recursive_scanner<Scan, Arg> { };

template <template<typename> class Scan>
class recursive_scanner<Scan, void *> {
public:
    enum {
        NUM = 0
    };

    FORCE_INLINE static void pre_scan(struct hashtable_t* htable, void *, const int) { }
};

template <template<typename> class Scan>
class recursive_scanner<Scan, const void *> {
public:
    enum {
        NUM = 0
    };

    FORCE_INLINE static void pre_scan(struct hashtable_t* htable, const void *, const int) { }
};

template <template<typename> class Scan, typename Arg>
void scan_recursive(struct hashtable_t* htable, Arg &arg, const int depth__) {
    recursive_scanner<Scan, Arg>::pre_scan(htable, arg, depth__);
}



template <template<typename> class Scan>
void arg_pre_scanner(int) {
    kern_printk("%s\n", __FUNCTION__);
}

template <typename T>
bool address_scanner_function(T* func_ptr) {
    //kern_printk("address scanner function one\n");
    uint64_t value = (uint64_t)(func_ptr);
    if(is_alias_address(value)) {
        cfi_collect_watcpoint((void*)0, (void*)value);
    }
    return true;
}

template <typename T>
bool address_scanner_function(T addr) {
    //kern_printk("address scanner function two\n");
    unsigned int size = type_class<T>::get_size();
    unsigned int i = 0;
    uint64_t *ptr = (uint64_t*)&addr;
    uint64_t value = (uint64_t)(*ptr);
    while(i <= size){
        if(is_alias_address(value)) {
            cfi_collect_watcpoint(ptr, (void*)value);
        }
        ptr++;
        i += 8;
    }
}

#endif /* CFI_SCANNER_HPP_ */
