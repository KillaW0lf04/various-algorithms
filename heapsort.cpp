#include <iostream>
#include <stdlib.h>
#include <time.h>

#define LEFT(i) (i+1)*2 - 1
#define RIGHT(i) (i+1)*2

using namespace std;

// Assuming left and right satisfy the heap property
void maxHeapify(int *buffer, int size, int index) {
    int left = LEFT(index);
    int right = RIGHT(index);

    int largest = index;

    if(left < size && buffer[left] > buffer[largest])
        largest = left;
    if(right < size && buffer[right] > buffer[largest])
        largest = right;

    if(largest != index)
    {
        int dummy = buffer[index];
        buffer[index] = buffer[largest];
        buffer[largest] = dummy;

        // Ensure the Heap Property is satisfied
        maxHeapify(buffer, size, largest);
    }
}

// Builds a max heap from an array of integers
void buildMaxHeap(int *buffer, int size) {
    // elements from size/2 onwards are 1 element heaps
    // which automatically satisfy the heap property
    for(int i=size/2 - 1; i>=0; i--)
        maxHeapify(buffer, size, i);
}

void heapSort(int *buffer, int size) {
    for(int i=0; i<size; i++)
        buildMaxHeap(&buffer[i], size - i);
}

#define BUFFERSIZE 100

// Need to use a 1-index based array for this to work

int main()
{
    // Array to be sorted
    int buffer[BUFFERSIZE];

    srand(time(NULL));

    // Generate an array of random integers
    for( int i=0; i<BUFFERSIZE; i++)
        buffer[i] = rand() % BUFFERSIZE;

    heapSort(buffer, BUFFERSIZE);

    cout << "Sorted list" << endl;

    for( int i=0; i<BUFFERSIZE; i++)
        cout << buffer[i] << ", ";

    cout << endl;
}

