/*
 *  prodcons module
 *  Producer Consumer module
 *
 *  Implements routines for the producer consumer module based on
 *  chapter 30, section 2 of Operating Systems: Three Easy Pieces
 *
 *  University of Washington, Tacoma
 *  TCSS 422 - Operating Systems
 *  Fall 2016
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
pthread_cond_t empty = PTHREAD_COND_INITIALIZER, fill = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Producer consumer data structures
Matrix * bigmatrix[MAX];

//Synchronized counter for the total # of
// producer/consumer
counters_t *synCounter;

//General sync counter;
counter_t *counter;

// Define the stuff used
void setup() {
    counter_t *prod, *cons; //Producer and consumer counter
    prod = (counter_t *) malloc(sizeof(counter_t));
    cons = (counter_t *) malloc(sizeof(counter_t));
    counter = (counter_t *) malloc(sizeof(counter_t));
    synCounter = (counters_t *) malloc(sizeof(counters_t));
    init_cnt(prod);
    init_cnt(cons);
    init_cnt(counter);
    synCounter->prod = prod;
    synCounter->cons = cons;
}

// Bounded buffer put() get()
int put(Matrix * value)
{
    int fill_ptr;
    fill_ptr = get_cnt(synCounter->prod) % MAX;
    bigmatrix[fill_ptr] = value;
    increment_cnt(synCounter->prod);
    increment_cnt(counter);
    return 0;
}

Matrix * get()
{
    int use_ptr;
    use_ptr = get_cnt(synCounter->cons) % MAX;
    Matrix *returnM = bigmatrix[use_ptr];
    increment_cnt(synCounter->cons);
    decrement_cnt(counter);

    return returnM;
}


// Matrix PRODUCER worker thread
void *prod_worker(void *arg)
{
    int i;
    ProdConsStats *stats = arg;

    for (i = 0; i < LOOPS; i++) {
//    Matrix *value = GenMatrixBySize(5, 5);
        Matrix *value = GenMatrixRandom();

        // If the buffer is full producer waits
        pthread_mutex_lock(&mutex);
        while (get_cnt(counter) == MAX) {
            pthread_cond_wait(&empty, &mutex);
        }
        put(value);
        pthread_cond_signal(&fill);
        pthread_mutex_unlock(&mutex);
    }
    stats->matrixtotal = get_cnt(synCounter->prod);
    return NULL;
}

// Matrix CONSUMER worker thread
void *cons_worker(void *arg)
{
    int use_ptr;
    ProdConsStats *stats = arg;
    Matrix *product;

    // while loop goes until LOOP number of matrix has been consumed
    while (get_cnt(synCounter->cons) < LOOPS) {
        pthread_mutex_lock(&mutex);

        // Wait if buffer is empty
        while (get_cnt(counter) == 0)
            pthread_cond_wait(&fill, &mutex);
        Matrix *matrix1 = get();

        // Waits if buffer is empty again
        while (get_cnt(counter) == 0 && get_cnt(synCounter->cons) < LOOPS)
            pthread_cond_wait(&fill, &mutex);
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);

        // Before getting the second matrix to multiply, checks to see if the next matrix in the buffer
        // can be multiplied with the current matrix. If yes, get() the second matrix. If no, consume the
        // first matrix and move on.
        use_ptr = get_cnt(synCounter->cons) % MAX;
        if ((get_cnt(synCounter->prod) - get_cnt(synCounter->cons)) > 0
            && (product = MatrixMultiply(matrix1, bigmatrix[use_ptr])) != NULL) {

            pthread_mutex_lock(&mutex);
            Matrix *matrix2 = get();
            pthread_cond_signal(&empty);
            pthread_mutex_unlock(&mutex);
            stats->multtotal++;
            stats->sumtotal += SumMatrix(product);

            DisplayMatrix(matrix1, stdout);
            printf("    X\n");
            DisplayMatrix(matrix2, stdout);
            printf("    =\n");
            DisplayMatrix(product, stdout);
            printf("\n");
            printf("----------------------------\n");
            FreeMatrix(matrix2);
            FreeMatrix(product);

        }
        // If the multiplication was not viable only need to free the first matrix
        FreeMatrix(matrix1);
    }
    return NULL;
}

