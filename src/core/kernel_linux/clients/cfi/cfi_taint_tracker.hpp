#ifndef CFI_TAINT_TRACKER_HPP_
#define CFI_TAINT_TRACKER_HPP_

#include <stdint.h>
#include <string.h>
#include <stddef.h>

#include "cfi_region_allocator.hpp"

#define U8(x) static_cast<uint8_t>(x)

#ifndef FORCE_INLINE
#   define FORCE_INLINE __attribute__((always_inline))
#endif

#define CHECK(x)

/// forward declaration
void MurmurHash3_x86_32(const void *key, int len, uint32_t seed, void *out);

/// defines some tain meta information about a type
template <typename T>
struct taint_meta_info {
    enum {
        IS_TRACKED = 0,
        IS_STRUCT_TRACKED = 0,
    };
};

template <typename T>
struct taint_meta_info<const T> : public taint_meta_info<T> { };

/// extend the size of something to have enough space for a 32 bit hash
#define TAINT_SIZE_EXTENSION(rvalue) (4 + (4 - ((rvalue) % 4)))
#define TAINT_EXTEND_SIZE(lvalue) lvalue += TAINT_SIZE_EXTENSION(lvalue)

#if ENABLE_TAINT_TRACKING

/// designate a function pointer field of a type to be the taint meta pointer
#   define SET_TAINT_TRACKER(type, func_ptr_field_name) \
        template <> \
        struct taint_meta_info<type> { \
        public: \
            enum { \
                OFFSET = OFFSETOF(type, func_ptr_field_name), \
                IS_TRACKED = 1, \
                IS_STRUCT_TRACKED = 0, \
            }; \
        }

/// designate that a type is taint-tracked using structure extension
#   define ADD_TAINT_TRACKER(type) \
        template <> \
        struct taint_meta_info<type> { \
        public: \
            enum { \
                OFFSET = sizeof(type) + TAINT_SIZE_EXTENSION(sizeof(type)) - 4U, \
                IS_TRACKED = 1, \
                IS_STRUCT_TRACKED = 1, \
            }; \
        }

#else
#   define SET_TAINT_TRACKER(type, func_ptr_field_name)
#   define ADD_TAINT_TRACKER(type)
#endif

/// simple interface to using function-tracked taineted data. Everything in body
/// is executed iff the data is tainted.
#define WITH_FUNC_TAINTED_DATA(rvalue, body) {\
    taint_tracked_data *tracker__(0); \
    typedef tracked_type<DECLTYPE(rvalue)> tracked_type__; \
    typedef typename tracked_type__::type tracked_base_type__; \
    typedef taint_meta_info<tracked_base_type__> tracked_type_meta__; \
    tracked_base_type__ *tracked_data__(tracked_type__::to_pointer(rvalue)); \
    bool tracker_is_new__(true); \
    bool tracker_is_dirty__(false); \
    if(taint_tracked_data::is_tracked(tracked_data__)) { \
        tracker_is_new__ = false; \
        tracker__ = taint_tracked_data::get_tracker(tracked_data__); \
        tracker_is_dirty__ = tracker__->is_dirty(); \
    } \
    if(tracker_is_new__ || tracker_is_dirty__) { \
        if(tracker_is_dirty__) { \
            tracker__->untrack<tracked_base_type__>(); \
        } \
        body \
        if(tracker_is_new__) { \
            taint_tracked_data::track(tracked_data__); \
        } else { \
            tracker__->update<tracked_base_type__>(); \
        } \
    }}

//#define IS_FIRST_TAINTING tracker_is_new__

/// simple interface to using structure-extneded taint tracking of data.
#define WITH_STRUCT_TAINTED_DATA(rvalue, body) {\
    typedef tracked_type<DECLTYPE(rvalue)> tracked_type__; \
    typedef typename tracked_type__::type tracked_base_type__; \
    typedef taint_meta_info<tracked_base_type__> tracked_type_meta__; \
    tracked_base_type__ *tracked_data__(tracked_type__::to_pointer(rvalue)); \
    uint32_t *taint_hash__ = (uint32_t *) &(((uint8_t *) tracked_data__)[tracked_type_meta__::OFFSET]); \
    uint32_t taint_new_hash__(0U); \
    MurmurHash3_x86_32(tracked_data__, sizeof(tracked_base_type__), taint_tracked_data::seed, &(taint_new_hash__)); \
    if(*taint_hash__ != taint_new_hash__) { \
        body \
    } \
    MurmurHash3_x86_32(tracked_data__, sizeof(tracked_base_type__), taint_tracked_data::seed, taint_hash__); \
    }

template <typename T>
class bad_tracking_pointer {
public:
	static void halt(T *) {
		do_halt(0);
	}
	__attribute__((noinline)) static void do_halt(T *) {
		__asm__ __volatile__ (
		"	mov $0, %rax;"
		"	call *%rax;"
		"	div %rax, %rax;"
		"	hlt;");
	}
};

/// templates for removing pointers / references
template <typename T>
struct tracked_type {
public:
    typedef T type;
    FORCE_INLINE static T *to_pointer(T &val) throw() {
        return &val;
    }
};

template <typename T>
struct tracked_type<T &> {
public:
    typedef typename tracked_type<T>::type type;
    FORCE_INLINE static T *to_pointer(T &val) throw() {
        return tracked_type<T>::to_pointer(val);
    }
};

template <typename T>
struct tracked_type<T *> {
public:
    typedef typename tracked_type<T>::type type;
    FORCE_INLINE static T *to_pointer(T *val) throw() {
        return tracked_type<T>::to_pointer(*val);
    }
};

/// forward declaration
struct taint_tracked_data;

template <typename T>
void check_tracker_pointer(const void *);

/// taint tracker struct. stores code and metadata about a structure being
/// tracked. takes up 20 bytes of memory, so not so bad ;-)
///
/// the designated function pointer of a taint-tracked structure can be
/// cast to a taint_tracker *, and then operated on like any C++ class
/// for maximum convenience.
struct taint_tracked_data {
public:

    enum {
        OP_JMP_NEAR_OFF32 = 0xE9,
        JMP_ADRR_LEN = 5 // 5 bytes to encode a jmp to a fixed address
    };

    /// seed for the hash
    static uint32_t seed;

    /// allocates new taint trackers
    static atomic_region_allocator<taint_tracked_data> allocator;

    /// just enough space to store a JMP operation
    uint8_t gencode[JMP_ADRR_LEN] __attribute__ ((aligned (8)));

    /// can we re-use this tracker?; eventually, we might want to create a
    /// kernel thread of our own that periodically scans the taint tracker
    /// shadow for "garbage". That is, suppose a tracked struct has its
    /// designated function pointer changed by the module. The next time
    /// we wrap that struct, we will allocate a new gencode for it, and
    /// it's previous one will be garbage. We can verify that it's
    /// garbage by using the tracked_struct_size and tracked_struct to
    /// re-inspect the struct and see if it's being tracked by another
    /// gencode thing, then mark this tracker as free and add it to a
    /// free list for future re-allocation.
    //bool is_free;
    bool is_free;

    /// needed for garbage collection; also helps fill up the empty space
    uint16_t tracked_struct_size;

    /// pointer back to the structure being tracked by the taint tracker.
    /// this is needed both for garbage collection, as well as de-allocation
    /// when trying to confirm that a de-allocator is indeed de-allocating
    /// a tracked structure.
    void *tracked_struct;

    /// murmurhash2, 32 bit hash of the structure being tracked
    uint32_t hash;

    /// atomic allocator needs to be able to construct this type of object
    friend class atomic_region_allocator<taint_tracked_data>;

public:

    /// notify the tracker to invalidate everything, i.e. change the seed
    static void invalidate(void) throw() {
        ++seed;
    }

    /// returns true iff the designated function pointer of some struct
    /// is currently tracked.
    template <typename T>
    FORCE_INLINE static bool is_tracked(T *struct_to_test) throw() {
        if(((uint64_t) struct_to_test) < 4096) {
            return false;
        }
        return is_tracked(get_tracker(struct_to_test));
    }

    /// check if a pointer is tracked
    FORCE_INLINE static bool is_tracked(taint_tracked_data *tracker) throw() {
    	CHECK( check_tracker_pointer<void>((const void *) tracker); )
    	if(allocator.is_allocated(tracker)) { // it's in the "right" place
            return !(tracker->is_free); // it is potentially tracked
        }
        return false;
    }

    FORCE_INLINE static bool is_tracked(const taint_tracked_data *tracker) throw() {
    	CHECK( check_tracker_pointer<void>((const void *)tracker); )
    	if(allocator.is_allocated(tracker)) { // it's in the "right" place
            return !(tracker->is_free); // it is potentially tracked
        }
        return false;
    }

    /// check if a structure has been dirtied; we don't update the hash here
    /// as the structure needs to be re-wrapped after being dirtied
    bool is_dirty(void) const throw() {
        uint32_t curr_hash(0);
        CHECK( check_tracker_pointer<void>((const void *) this); )
        MurmurHash3_x86_32(tracked_struct, tracked_struct_size, seed, &(curr_hash));
        return hash != curr_hash;
    }

    /// update the tracking hash
    template <typename T>
    void update(void) throw() {
    	CHECK( check_tracker_pointer<T>((const void *) this); )

        typedef taint_meta_info<T> meta_info;
        char *data((char *) tracked_struct);

        // a pointer to the structure's function pointer field, cast
        // as a pointer to a taint_tracked_data pointer
        taint_tracked_data **designated_ptr((taint_tracked_data **) &(data[meta_info::OFFSET]));

        // don't want a tracked function to be propagated
        if(is_tracked(*designated_ptr)) {
            *designated_ptr = (*designated_ptr)->get_target();
        }

        // initialize its gencode
        emit_jmp(
			&(gencode[0]),
			(void *) *designated_ptr,
			(void *) bad_tracking_pointer<T>::halt
        );
        *designated_ptr = (taint_tracked_data *) &(gencode[0]);
        MurmurHash3_x86_32(tracked_struct, tracked_struct_size, seed, &(hash));
    }

    /// remove tracking pointer so that other stuff doesn't observe weird values
    template <typename T>
    void untrack(void) throw() {
        typedef taint_meta_info<typename tracked_type<T>::type> meta_info;
        CHECK( check_tracker_pointer<T>((const void *) this); )
        uint8_t *data((uint8_t *) tracked_struct);
        *((taint_tracked_data **) &(data[meta_info::OFFSET])) = get_target();
    }

    template <typename T>
    FORCE_INLINE static taint_tracked_data *&get_tracker(T *struct_to_track) throw() {
        typedef taint_meta_info<T> meta_info;
        taint_tracked_data *&tracker(*((taint_tracked_data **) &(((char *) struct_to_track)[meta_info::OFFSET])));
        CHECK( check_tracker_pointer<T>((const void *) tracker); )
        return tracker;
    }

    /// initialize a structure to be taint tracked. We assume that all functions
    /// have been wrapped (i.e. turned to shadow addresses if they were raw
    /// module addresses).
    ///
    /// the first argument is a pointer to the structure to be wrapped. this
    ///     structure must contain a function pointer.
    ///
    /// the second argument is a pointer to the function pointer that is the
    ///     designated tracking function pointer of the structure. if the structure
    ///     has multiple tracking pointers, then choose one and only one. be
    ///     consistent!
    template <typename T>
    static taint_tracked_data *track(T *struct_to_init) throw() {
        typedef taint_meta_info<T> meta_info;

        taint_tracked_data *tracker = allocator.allocate();

        CHECK( check_tracker_pointer<T>((const void *) tracker); )

        // replace the function pointer with a pointer to the gencode,
        // initialize the rest of the tracker, then hash the structure
        // with the gencode pointer
        tracker->is_free = false;
        tracker->tracked_struct_size = (uint16_t) sizeof(T);
        tracker->tracked_struct = struct_to_init;
        tracker->update<T>();

        return (taint_tracked_data *) tracker->gencode;
    }

    /// get the untracked version of a pointer (the target of the JMP), still
    /// left as the tracked type for simplicity
    taint_tracked_data *get_target(void) const throw() {
    	CHECK( check_tracker_pointer<void>((const void *) this); )
        uint64_t offset(gencode[4]);
        offset = (offset << 8) | gencode[3];
        offset = (offset << 8) | gencode[2];
        offset = (offset << 8) | gencode[1];
        offset += ((uint64_t) gencode) + 5ULL;
        return (taint_tracked_data *) offset;
    }

private:

    /// patch a block of code to jump to a specific address.
    static void emit_jmp(uint8_t *begin, void *func, void *bad_target) throw() {
    	if(!func) {
    		func = bad_target;
    	}
        const ptrdiff_t offset(((ptrdiff_t) func) - (((ptrdiff_t) begin) + 5));

        const uint8_t CALL_FUNC_OP[] = {
            OP_JMP_NEAR_OFF32,
            U8((offset >>  0) & 0xFF),
            U8((offset >>  8) & 0xFF),
            U8((offset >> 16) & 0xFF),
            U8((offset >> 24) & 0xFF)
        };

        memcpy(begin, CALL_FUNC_OP, sizeof CALL_FUNC_OP);
    }

} __attribute__((packed));

atomic_region_allocator<taint_tracked_data> taint_tracked_data::allocator(
    (void *) MODULE_SHADOW_END,
    (void *) MODULE_SHADOW_END_EXTENDED
);

/// check a tracking pointer for sanity
template <typename T>
void check_tracker_pointer(const void *ptr) {
	const uint64_t ptr_val = (uint64_t) ptr;
	if(ptr_val < 4096 || (0 != (ptr_val % sizeof(taint_tracked_data)))) {
		typedef int (printf_type)(const char *, ...);
		printf_type *kern_printk = (printf_type *) KERN_ADDR_printk;
		kern_printk("INSANE POINTER %llx\n\n\n\n\n\n", ptr_val);
		bad_tracking_pointer<T>::halt(0);
	}
}

/// initialize the static data
uint32_t taint_tracked_data::seed = 0xdeadbeef;


extern "C" {
    void *cfi_get_untracked_address(void *addr_) {
        const taint_tracked_data *tracker = (taint_tracked_data *) addr_;
        if(taint_tracked_data::is_tracked(tracker)) {
            return (void *) tracker->get_target();
        } else {
            return addr_;
        }
    }
}

#include "murmurhash.h"

#endif
