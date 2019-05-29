/*
 *  buffercounter header
 *  Function prototypes, data, and constants for synchronized buffercounter module
 *
 *  University of Washington, Tacoma
 *  TCSS 422 - Operating Systems
 *  Spring 2019
 */

// SYNCHRONIZED COUNTER

#include <sys/types.h>

// buffercounter structures
typedef struct __counter_t {
    int value;
    pthread_mutex_t  lock;
} counter_t;

typedef struct __counters_t {
    counter_t * prod;
    counter_t * cons;
} counters_t;

// buffercounter methods
void init_cnt(counter_t *c);
void increment_cnt(counter_t *c);
void decrement_cnt(counter_t *c);
int get_cnt(counter_t *c);
