#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "heapsort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "insertionsort.h"
#include "bubblesort.h"
#include "radixsort.h"

#define BUFFERSIZE 20000
#define NO_SORT_ALGS 6
#define MAX_VALUE 1000

void quicksort_h(int *buffer, int length) {
    quicksort(buffer, 0, length - 1);
}

void radixsort_h(int *buffer, int length) {
    radixsort(buffer, length, MAX_VALUE);
}

void mergesort_h(int *buffer, int length) {
    int work[BUFFERSIZE];
    mergesort(buffer, work, length);
}

int main() {
    clock_t t0, runtime;
    void (*sort[NO_SORT_ALGS])(int *, int) = {
            quicksort_h,
            radixsort_h,
            mergesort_h,
            heapsort,
            bubblesort,
            insertionsort,
    };

    int buffer[BUFFERSIZE];

    for (int i=0; i < NO_SORT_ALGS; i++) {
        srand(time(NULL));

        // Generate an array of random integers
        for( int j=0; j<BUFFERSIZE; j++)
            buffer[j] = rand() % MAX_VALUE;

        t0 = clock();
        (*sort[i])(buffer, BUFFERSIZE);
        runtime = clock() - t0;

        printf("Sort Runtime = %f seconds\n", ((float) runtime) / CLOCKS_PER_SEC);
    }

    printf("Finished\n");
}
