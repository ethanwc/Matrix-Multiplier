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

    printf("here0\n");
    buffer = (Matrix **) malloc(sizeof(Matrix *) * BOUNDED_BUFFER_SIZE);

//    time_t t;
    int numw = LOOPS;
//    int i;
    // Array of thread IDs
    pthread_t *tid;
    // Struct to track the work
    ProdConsStats *stats;
    printf("here1\n");

    buffercounter = malloc(sizeof(counter_t));
    synchronizedcounter = malloc(sizeof(counters_t));

    synchronizedcounter->prod = malloc(sizeof(counter_t));
    synchronizedcounter->cons = malloc(sizeof(counter_t));


    init_cnt(buffercounter);
    printf("here1.1\n");

    init_cnt(synchronizedcounter->cons);
    printf("here1.2\n");

    init_cnt(synchronizedcounter->prod);

    printf("here1.5\n");

    tid = (pthread_t*)malloc(sizeof(pthread_t) * (numw * 2));
    stats = (ProdConsStats *) malloc(sizeof(ProdConsStats));


    int i;
    for (i = 0; i < numw; i+=2) {
        pthread_create(&tid[i], NULL, prod_worker, stats);
//    for (j = 0; j < 100; j++) printf("");
        pthread_create(&tid[i + 1], NULL, cons_worker, stats);

    }
    // Joins producers/consumers
    for (i = 0; i < numw; i+=2) {
        pthread_join(tid[i], NULL);
        pthread_join(tid[i + 1], NULL);
    }


//    stats->sumtotal = 0;
//
//
//    pthread_create(&tid[0], NULL, prod_worker, stats);
////    for (j = 0; j < 100; j++) printf("");
//    pthread_create(&tid[1], NULL, cons_worker, stats);
//
//
//    pthread_create(&tid[2], NULL, prod_worker, stats);
////    for (j = 0; j < 100; j++) printf("");
//    pthread_create(&tid[3], NULL, cons_worker, stats);
//
//
//    pthread_join(tid[0], NULL);
//    pthread_join(tid[1], NULL);

}

//int main (int argc, char * argv[])
//{
//  // Process command line arguments
//  int numw = NUMWORK;
//  if (argc==1)
//  {
//    BOUNDED_BUFFER_SIZE=MAX;
//    NUMBER_OF_MATRICES=LOOPS;
//    MATRIX_MODE=DEFAULT_MATRIX_MODE;
//    printf("USING DEFAULTS: worker_threads=%d bounded_buffer_size=%d matricies=%d matrix_mode=%d\n",numw,BOUNDED_BUFFER_SIZE,NUMBER_OF_MATRICES,MATRIX_MODE);
//  }
//  else
//  {
//    if (argc==2)
//    {
//      numw=atoi(argv[1]);
//      BOUNDED_BUFFER_SIZE=MAX;
//      NUMBER_OF_MATRICES=LOOPS;
//      MATRIX_MODE=DEFAULT_MATRIX_MODE;
//    }
//    if (argc==3)
//    {
//      numw=atoi(argv[1]);
//      BOUNDED_BUFFER_SIZE=atoi(argv[2]);
//      NUMBER_OF_MATRICES=LOOPS;
//      MATRIX_MODE=DEFAULT_MATRIX_MODE;
//    }
//    if (argc==4)
//    {
//      numw=atoi(argv[1]);
//      BOUNDED_BUFFER_SIZE=atoi(argv[2]);
//      NUMBER_OF_MATRICES=atoi(argv[3]);
//      MATRIX_MODE=DEFAULT_MATRIX_MODE;
//    }
//    if (argc==5)
//    {
//      numw=atoi(argv[1]);
//      BOUNDED_BUFFER_SIZE=atoi(argv[2]);
//      NUMBER_OF_MATRICES=atoi(argv[3]);
//      MATRIX_MODE=atoi(argv[4]);
//    }
//    printf("USING: worker_threads=%d bounded_buffer_size=%d matricies=%d matrix_mode=%d\n",numw,BOUNDED_BUFFER_SIZE,NUMBER_OF_MATRICES,MATRIX_MODE);
//  }
//  bigmatrix = (Matrix **) malloc(sizeof(Matrix *) * BOUNDED_BUFFER_SIZE);
//
//  time_t t;
//  // Seed the random number generator with the system time
//  srand((unsigned) time(&t));
//
//  //
//  // Demonstration code to show the use of matrix routines
//  //
//  // DELETE THIS CODE ON ASSIGNMENT 2 SUBMISSION
//  // ----------------------------------------------------------
//  printf("MATRIX MULTIPLICATION DEMO:\n\n");
//  Matrix *m1, *m2, *m3;
//  for (int i=0;i<NUMBER_OF_MATRICES;i++)
//  {
//    m1 = GenMatrixRandom();
//    m2 = GenMatrixRandom();
//    m3 = MatrixMultiply(m1, m2);
//    if (m3 != NULL)
//    {
//      DisplayMatrix(m1,stdout);
//      printf("    X\n");
//      DisplayMatrix(m2,stdout);
//      printf("    =\n");
//      DisplayMatrix(m3,stdout);
//      printf("\n");
//      FreeMatrix(m3);
//      FreeMatrix(m2);
//      FreeMatrix(m1);
//      m1=NULL;
//      m2=NULL;
//      m3=NULL;
//    }
//  }
////  return 0;
////   ----------------------------------------------------------
//
//  printf("Producing %d matrices in mode %d.\n",NUMBER_OF_MATRICES,MATRIX_MODE);
//  printf("Using a shared buffer of size=%d\n", BOUNDED_BUFFER_SIZE);
//  printf("With %d producer and consumer thread(s).\n",numw);
//  printf("\n");
//
//  pthread_t pr;
//  pthread_t co;
//
//  int prs = 0;
//  int cos = 0;
//  int prodtot = 0;
//  int constot = 0;
//  int consmul = 0;
//
//  // consume ProdConsStats from producer and consumer threads
//  // add up total matrix stats in prs, cos, prodtot, constot, consmul
//
//  printf("Sum of Matrix elements --> Produced=%d = Consumed=%d\n",prs,cos);
//  printf("Matrices produced=%d consumed=%d multiplied=%d\n",prodtot,constot,consmul);
//
//  return 0;
//}
