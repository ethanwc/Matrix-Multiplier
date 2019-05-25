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
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
// Producer consumer data structures

//init_cnt(buffercounter);
// Bounded buffer bigmatrix defined in prodcons.h
//Matrix* buffer[MAX] = malloc(sizeof(Matrix) * MAX);

//int fill_ptr = 0;
//int use_ptr = 0;
//int count = 0;

//test


// Bounded buffer put() get()
int put(Matrix * value) {

//    fill_ptr should be current spot in array(syncrhonized counter)

    int fill_ptr = get_cnt(synchronizedcounter->prod) % MAX;
    buffer[fill_ptr] = value;
    increment_cnt(buffercounter);
    increment_cnt(synchronizedcounter->prod);

    return 0;
}

Matrix* get() {
    //printf("here3\n");

    int use_ptr = get_cnt(synchronizedcounter->cons) % MAX;
    Matrix *M = buffer[use_ptr];
    decrement_cnt(buffercounter);
    increment_cnt(synchronizedcounter->cons);
    return M;
}

// Matrix PRODUCER worker thread
void *prod_worker(void *arg) {
    //printf("produced\n");

    //int i;
//    for (i = 0; i < LOOPS; i++) {
        Matrix *M = GenMatrixRandom();
        pthread_mutex_lock(&mutex);
        while(buffercounter->value == MAX)
            pthread_cond_wait(&cond, &mutex);
        put(M);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
//        todo: update stats here
//    }

  return NULL;
}

// Matrix CONSUMER worker thread
void *cons_worker(void *arg) {
    //printf("consumed\n");
    while (get_cnt(synchronizedcounter->cons) < LOOPS) {
        pthread_mutex_lock(&mutex);
       
        //wait for a value to be added to buffer
        while(get_cnt(buffercounter) == 0) {
            //printf("stuck here1\n");
            pthread_cond_wait(&cond, &mutex);
        }
        Matrix *M1 = get();

        //wait for second value to be added to buffer
        while(get_cnt(buffercounter) == 0) {
            //printf("stuck here2\n");
            pthread_cond_wait(&cond, &mutex);
        }

        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);

        pthread_mutex_lock(&mutex);
        Matrix *M2 = get();
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);


        Matrix *Multiply = MatrixMultiply(M1, M2);


        if ((get_cnt(synchronizedcounter->prod) - get_cnt(synchronizedcounter->cons)) > 0
            && (Multiply != NULL)) {
                printf("works\n");
            DisplayMatrix(M1, stdout);
            printf("    X\n");
            DisplayMatrix(M2, stdout);
            printf("    =\n");
            DisplayMatrix(Multiply, stdout);
            printf("\n");

            
        } else {
            printf("not working\n");
        }
        FreeMatrix(M1);
        FreeMatrix(M2);
        FreeMatrix(Multiply);
    }

    printf("Consumed worked\n");

//    todo: update stats again
  return NULL;
}
