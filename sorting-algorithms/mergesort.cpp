#include "mergesort.h"

/*
 * Performs a merge sort in descending order on an array of integers
 * Time Complexity: O(nlogn)
 * Memory: O(n)
 * Stable sort
 * */

#include <string.h>

// buffer is the array to sort
// work is a work array to use for the merge sort
// length is the length of the buffer and work array
// Note that mergesort is NOT an in-place sort because of the need
// for extra memory to function
// merge sort can also be performed using a top-down or bottom-up approach
void mergesort(int *buffer, int *work, int length) {
    if (length == 1)
        return;

    // mid-point
    int mid = length / 2;
    mergesort(buffer, work, mid);
    mergesort(&(buffer[mid]), &(work[mid]), length - mid);

    int ptr1 = 0;    // pointer for the first subarray
    int ptr2 = mid;  // pointer for the second subarray
    int index = 0;       // pointer for the work array

    do {
        if (buffer[ptr1] < buffer[ptr2]) {
            work[index++] = buffer[ptr1++];
        } else {
            work[index++] = buffer[ptr2++];
        }
    } while (index < length && ptr2 < length && ptr1 < mid);

    // Finish any leftover points
    while (ptr1 < mid)
        work[index++] = buffer[ptr1++];

    while (ptr2 < length)
        work[index++] = buffer[ptr2++];

    // Copy the array back to the original buffer
    memcpy(buffer, work, sizeof(int) * length);
}
