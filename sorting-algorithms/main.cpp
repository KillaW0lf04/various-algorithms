#include <iostream>

#include <stdlib.h>
#include <time.h>

#include "heapsort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "insertionsort.h"
#include "bubblesort.h"

#define BUFFERSIZE 100

int main() {
    int buffer[BUFFERSIZE];
    int work[BUFFERSIZE];

    srand(time(NULL));

    // Generate an array of random integers
    for( int i=0; i<BUFFERSIZE; i++)
        buffer[i] = rand() % BUFFERSIZE;

    //heapsort(buffer, BUFFERSIZE);
    //quicksort(buffer, 0, BUFFERSIZE - 1);
    //mergesort(buffer, work, BUFFERSIZE);
    //insertionsort(buffer, BUFFERSIZE);
    bubblesort(buffer, BUFFERSIZE);

    std::cout << "Sorted list" << std::endl;

    for( int i=0; i<BUFFERSIZE; i++)
        std::cout << buffer[i] << ", ";

    std::cout << std::endl;
}
