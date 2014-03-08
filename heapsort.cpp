#include "heapsort.h"

#define LEFT(i) (i+1) << 1 - 1
#define RIGHT(i) (i+1) << 1

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

// Performs a heap sort on the given interger array
void heapsort(int *buffer, int size) {
    for(int i=0; i<size; i++)
        buildMaxHeap(&buffer[i], size - i);
}
