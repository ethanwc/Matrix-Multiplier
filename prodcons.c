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


Matrix* buffer[MAX];
int fill_ptr = 0;
int use_ptr = 0;
int count = 0;

int put(Matrix * value) {
    buffer[fill_ptr] = value;
    fill_ptr = (fill_ptr + 1) % MAX;
    count++;
}

Matrix* get() {
    int tmp = buffer[use_ptr];
    use_ptr = (use_ptr + 1) % MAX;
    count--;
    return tmp;
}


// Matrix PRODUCER worker thread
void *prod_worker(void *arg)
{
  return NULL;
}

// Matrix CONSUMER worker thread
void *cons_worker(void *arg)
{
  return NULL;
}
