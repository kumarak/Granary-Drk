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
    FORCE_INLINE static void scan(struct hashtable_t *htable, ArgT__ &arg)



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
#define SCAN_FUNC(lval) \
    if(!IS_WATCHPOINT(lval)) {  \
            is_watchpoint_address(lval); \
    }


//#define SCAN_PTR SCAN_FUNC

#define SCAN_HEAD   \
        FORCE_INLINE static void scan_head(ArgT__ &arg)

// recursively Scan

#define SCAN_RECURSIVE(lval)  \
        if(!IS_WATCHPOINT(lval)){	\
            scan_recursive<scan_function, DECLTYPE(lval)>(htable, lval); \
        }

#if 0
        void *value; \
        if(!hashmap_get(htable, (void*)(&lval), (void**)&value)){   \
			scan_recursive<scan_function, DECLTYPE(lval)>(htable, lval); \
        }
#endif

#define SCAN_RECURSIVE_PTR(lval)  \
			if(!IS_WATCHPOINT(lval)){	\
				scan_recursive<scan_function, DECLTYPE(lval)>(htable, lval); \
			}
#if 0
        if(lval != NULL) {  \
            void *value; \
            if(!hashmap_get(htable, (void*)(lval), (void**)&value)){   \
                scan_recursive<scan_function, DECLTYPE(lval)>(htable, lval); \
            }   \
        }
#endif
#define SCAN_FUNCTION(type_name) \
        scan_function<type_name>::scan_impl::scan

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
		FORCE_INLINE static void scan(struct hashtable_t *htable, T &) { }
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
		FORCE_INLINE static void scan(struct hashtable_t *htable, void*) { }
	};
};


/// type reduction for recursive wrappers
template <template<typename> class Scan, typename Arg>
class recursive_scanner_base {
public:
    enum {
        NUM = Scan<Arg>::NUM
    };
//Scan<Arg>::scan_impl::scan(arg, depth__, static_tag<Tag>::tag);
    inline static void pre_scan(struct hashtable_t* htable, Arg &arg) {
        Scan<Arg>::scan_impl::scan(htable, arg);
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

    inline static void pre_scan(struct hashtable_t* htable, const Arg &arg) {
        recursive_scanner<Scan, Arg>::pre_scan(htable, const_cast<Arg &>(arg));
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

    inline static void pre_scan(struct hashtable_t* htable, Arg *&arg) {
        if(((Arg *) 4095) < arg) {
        	if(Scan<Arg *>::IS_DEFINED) {
        		recursive_scanner_base<Scan, Arg *>::pre_scan(htable, arg);
        	} else {
        		recursive_scanner<Scan, Arg>::pre_scan(htable, *arg);
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

    inline static void pre_scan(struct hashtable_t* htable, Arg **&arg) {
        if(((Arg **) 4095) < arg) {
            recursive_scanner<Scan, Arg *>::pre_scan(htable, *arg);
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

    inline static void pre_scan(struct hashtable_t* htable, Arg *&arg) {
        if(((Arg *) 4095) < arg) {
            pre_tag tag;
            Scan<Arg *>::scan_impl::scan(htable, arg);
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

    FORCE_INLINE static void pre_scan(struct hashtable_t* htable, void *) { }
};

template <template<typename> class Scan>
class recursive_scanner<Scan, const void *> {
public:
    enum {
        NUM = 0
    };

    FORCE_INLINE static void pre_scan(struct hashtable_t* htable, const void *) { }
};

template <template<typename> class Scan, typename Arg>
void scan_recursive(struct hashtable_t* htable, Arg &arg) {
    recursive_scanner<Scan, Arg>::pre_scan(htable, arg);
}


template <template<typename> class Scan>
void arg_pre_scanner(int) {
    kern_printk("%s\n", __FUNCTION__);
}

template <typename T>
bool is_watchpoint_address(T* func_ptr) {
    uint64_t addr((uint64_t) func_ptr);
    if((!(addr & CFI_ALIAS_ADDRESS_NOT_ENABLED)) && ((addr | CFI_ALIAS_ADDRESS_INDEX_MASK ) != addr)){
    	return true;
    }

    return false;
#if 0
    void *value;
    if(hashmap_get(module_watchpoint_map, (void*)addr, (void**)&value)){
        return true;
    }
    return false;
#endif
}

template <typename T>
bool is_watchpoint_address(T func_ptr) {
    //return IS_WATCHPOINT(func_ptr);
#if 0
    uint64_t addr((uint64_t) func_ptr);
    if((!(addr & CFI_ALIAS_ADDRESS_NOT_ENABLED)) && ((addr | CFI_ALIAS_ADDRESS_INDEX_MASK ) != addr)){
    	return true;
    }

    return false;
#endif
    return true;
#if 0
    void *value;
    if(hashmap_get(module_watchpoint_map, (void*)addr, (void**)&value)){
        return true;
    }
    return false;
#endif
}
/*
template <typename T>
bool is_watchpoint_address(T func_ptr) {
    uint64_t addr((uint64_t) func_ptr);
    void *value;
    if(hashmap_get(module_watchpoint_map, (void*)addr, (void**)&value)){
        return true;
    }
    return false;
}
*/

#endif /* CFI_SCANNER_HPP_ */
