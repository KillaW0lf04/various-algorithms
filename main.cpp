#include <iostream>

#include <stdlib.h>
#include <time.h>

#include "heapsort.h"

#define BUFFERSIZE 100

int main(int argc, char *argv[]) {
    int buffer[BUFFERSIZE];

    srand(time(NULL));

    // Generate an array of random integers
    for( int i=0; i<BUFFERSIZE; i++)
        buffer[i] = rand() % BUFFERSIZE;

    heapsort(buffer, BUFFERSIZE);

    std::cout << "Sorted list" << std::endl;

    for( int i=0; i<BUFFERSIZE; i++)
        std::cout << buffer[i] << ", ";

    std::cout << std::endl;
}
