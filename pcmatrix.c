/*
 *  pcmatrix module
 *  Primary module providing control flow for the pcMatrix program
 *
 *  Producer consumer bounded buffer program to produce random matrices in parallel
 *  and consume them while searching for valid pairs for matrix multiplication.
 *  Matrix multiplication requires the first matrix column count equal the
 *  second matrix row count.
 *
 *  A matrix is consumed from the bounded buffer.  Then matrices are consumed
 *  from the bounded buffer, one at a time, until an eligible matrix for multiplication
 *  is found.
 *
 *  Totals are tracked using the ProdConsStats Struct for:
 *  - the total number of matrices multiplied (multtotal from consumer threads)
 *  - the total number of matrices produced (matrixtotal from producer threads)
 *  - the total number of matrices consumed (matrixtotal from consumer threads)
 *  - the sum of all elements of all matrices produced and consumed (sumtotal from producer and consumer threads)
 *
 *  Correct programs will produce and consume the same number of matrices, and
 *  report the same sum for all matrix elements produced and consumed.
 *
 *  Each thread produces a total sum of the value of
 *  randomly generated elements.  Producer sum and consumer sum must match.
 *
 *  University of Washington, Tacoma
 *  TCSS 422 - Operating Systems
 *  Spring 2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include <time.h>
#include "matrix.h"
#include "counter.h"
#include "prodcons.h"
#include "pcmatrix.h"

int main (int argc, char * argv[]) {
    int numw = NUMWORK;
    int i;

    // Array of thread IDs
    pthread_t *tid;
    // Struct to track the work
    ProdConsStats *stats;

    //setup the conters
    setup();

    printf("%d Matricies of %dx%d being produced.\n", LOOPS, ROW, COL);
    printf("Buffer size: %d\n", MAX);
    printf("Prod and con threads: %d\n",numw);
    printf("\n");

    // Allocates enough space for both producers and consumers
    tid = (pthread_t*)malloc(sizeof(pthread_t) * (numw * 2));
    stats = (ProdConsStats *) malloc(sizeof(ProdConsStats));

    // initialize the stats to zero
    stats->sumtotal = 0;
    stats->multtotal = 0;
    stats->matrixtotal = 0;

    // create producers/consumers
    for (i = 0; i < numw; i+=2) {
        pthread_create(&tid[i], NULL, prod_worker, stats);
        pthread_create(&tid[i + 1], NULL, cons_worker, stats);

    }
    // Joins producers/consumers
    for (i = 0; i < numw; i+=2) {
        pthread_join(tid[i], NULL);
        pthread_join(tid[i + 1], NULL);
    }

    // consume ProdConsStats from producer and consumer threads
    printf("Sum of Matrix elements --> Produced=%d = Consumed=%d\n", stats->sumtotal, stats->sumtotal);
    printf("Matrices produced=%d consumed=%d multiplied=%d\n", stats->matrixtotal, stats->matrixtotal, stats->multtotal);

    return 0;
}
