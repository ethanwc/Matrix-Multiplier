/*
 *  prodcons module
 *  Producer Consumer module
 *
 *  Implements routines for the producer consumer module based on
 *  chapter 30, section 2 of Operating Systems: Three Easy Pieces
 *
 *  University of Washington, Tacoma
 *  TCSS 422 - Operating Systems
 *  Spring 2019
 */

// Include only libraries for this module
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "counter.h"
#include "matrix.h"
#include "pcmatrix.h"
#include "prodcons.h"


// Define Locks and Condition variables here

// Producer consumer data structures

// Bounded buffer bigmatrix defined in prodcons.h
//Matrix ** bigmatrix;


//Matrix* buffer[MAX];
int fill_ptr = 0;
int use_ptr = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

//int count = 0;

//cond_t empty, full;
//mutex_t mutex;
int put(Matrix * value) {
   bigmatrix[(counters->prod)->value] = value;
   increment_cnt(counters->prod);

   //(counters->prod)->value = ((counters->prod)->value + 1) % MAX;
   return (counters->prod)->value;
}

Matrix* get() {
    use_ptr = get_cot(mutex);
    int tmp = bigmatrix[use_ptr];
    use_ptr = (use_ptr + 1) % MAX;
    decrement_cnt(counters->cons);
    //count--;
    return tmp;
}


// Matrix PRODUCER worker thread
void *prod_worker(void *arg)
{
   int i;
   for (i = 0; i < LOOPS; i ++) {
      Matrix matrix = GenMatrixRandom();
      pthread_mutex_lock(&(counters->prod)->lock);
      while((counters->prod)->value == MAX){
         //Pthread_cond_wait(&empty, &counter->lock);
      }
      put(matrix);
      //Pthread_cond_signal(&full);
      pthread_mutex_unlock(&(counters->prod)->lock);
   }
   return NULL;
}

// Matrix CONSUMER worker thread
void *cons_worker(void *arg)
{
  
  return NULL;
}
