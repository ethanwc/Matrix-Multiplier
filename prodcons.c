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
#include <stdlib.h>
#include <unistd.h>
#include "counter.h"
#include "matrix.h"
#include "pcmatrix.h"
#include "prodcons.h"


// Define Locks and Condition variables here
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Producer consumer data structures
counter_t *buffercounter;
counters_t *synchronizedcounter;

// Bounded buffer bigmatrix
Matrix * bigmatrix[MAX];


// Define the stuff used
void setup() {
    counter_t *prod, *cons;
    prod = (counter_t *) malloc(sizeof(counter_t));
    cons = (counter_t *) malloc(sizeof(counter_t));
    buffercounter = (counter_t *) malloc(sizeof(counter_t));
    synchronizedcounter = (counters_t *) malloc(sizeof(counters_t));
    synchronizedcounter->prod = prod;
    synchronizedcounter->cons = cons;
    init_cnt(prod);
    init_cnt(cons);
    init_cnt(buffercounter);

}

// Bounded buffer put() get()
int put(Matrix * value)
{
    int fill_ptr;
    fill_ptr = get_cnt(synchronizedcounter->prod) % MAX;
    bigmatrix[fill_ptr] = value;
    increment_cnt(synchronizedcounter->prod);
    increment_cnt(buffercounter);
    return 0;
}

Matrix * get() {
    int use_ptr = get_cnt(synchronizedcounter->cons) % MAX;
    Matrix *res = bigmatrix[use_ptr];
    increment_cnt(synchronizedcounter->cons);
    decrement_cnt(buffercounter);
    return res;
}


// Matrix PRODUCER worker thread
void *prod_worker(void *arg) {
    int i;
    ProdConsStats *stats = arg;

    for (i = 0; i < LOOPS; i++) {
        Matrix *value = GenMatrixRandom();

        pthread_mutex_lock(&mutex);

        //wait while buffer size >= max
        while (get_cnt(buffercounter) == MAX) pthread_cond_wait(&cond, &mutex);

        put(value);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    stats->matrixtotal = get_cnt(synchronizedcounter->prod);
    return NULL;
}

// Matrix CONSUMER worker thread
void *cons_worker(void *arg)
{
    int use_ptr, ccount, pcount;
    ProdConsStats *stats = arg;
    Matrix *res;

    //loop while consumer is less than loop count
    while (get_cnt(synchronizedcounter->cons) < LOOPS) {
        pthread_mutex_lock(&mutex);

        //wait for first matrix
        while (get_cnt(buffercounter) == 0) pthread_cond_wait(&cond, &mutex);

        Matrix *m1 = get();

        //wait for second matrix and check cond again
        while (get_cnt(buffercounter) == 0 && get_cnt(synchronizedcounter->cons) < LOOPS) pthread_cond_wait(&cond, &mutex);

        //signal completion
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);


        use_ptr = get_cnt(synchronizedcounter->cons) % MAX;
        res = MatrixMultiply(m1, bigmatrix[use_ptr]);
        pcount = get_cnt(synchronizedcounter->prod);
        ccount = get_cnt(synchronizedcounter->cons);

        //make sure producer counter is greater than consumer count and matrix multiplied
        if (res != NULL && (pcount - ccount > 0)) {

            pthread_mutex_lock(&mutex);
            Matrix *m2 = get();
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&mutex);
            stats->sumtotal += SumMatrix(res);
            stats->multtotal++;

            //display stuff
            DisplayMatrix(m1, stdout);
            printf("    X\n");
            DisplayMatrix(m2, stdout);
            printf("    =\n");
            DisplayMatrix(res, stdout);
            printf("\n");
            printf("------------------------\n");
            FreeMatrix(m2);
            FreeMatrix(res);

        }
        FreeMatrix(m1);
    }
    return NULL;
}