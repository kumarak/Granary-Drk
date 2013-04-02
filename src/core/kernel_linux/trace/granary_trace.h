/*
 * granary_trace.h
 *
 *  Created on: 2013-02-06
 *      Author: akshayk
 */

#ifndef GRANARY_TRACE_H_
#define GRANARY_TRACE_H_

#include <linux/module.h>

struct granary_symbolic_pair{
    int key;
    const char* value;
};

typedef int (*granary_trace_pp_function)(char* dest, size_t size, const void* data);

void
granary_trace_pp_unregister(void);

void
granary_trace(granary_trace_pp_function pp,
                        const void* data, size_t size);

void*
granary_trace_lock(granary_trace_pp_function pp, size_t size, void** data);

void
granary_trace_unlock_commit(void* id);

int
granary_tracer_init(void);

void
granary_tracer_exit(void);


static inline const char* granary_resolve_symbolic(int key,
    struct granary_symbolic_pair* pairs, int n)
{
    static char buffer[10];
    int i;
    for(i = 0; i < n; i++)
        if(key == pairs[i].key) return pairs[i].value;

    snprintf(buffer, sizeof(buffer), "%d", key);
    return buffer;
}

#define granary_print_symbolic(key, ...) \
    ({struct granary_symbolic_pair pairs[] = {__VA_ARGS__}; \
    granary_resolve_symbolic(key, pairs, ARRAY_SIZE(pairs));})



void granary_trace_marker_target(struct module* target_module,
                        struct module* payload_module, bool is_begin);

#endif /* GRANARY_TRACE_H_ */
