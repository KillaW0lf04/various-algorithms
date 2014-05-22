#include <algorithm>

/* buffer is the array to sort
 * start specifies the first index in the subarray
 * end specifies the last index in the subarray
 * */
void quicksort(int *buffer, int start, int end) {
    // Termination Criteria
    if (start >= end)
        return;

    // Use a random index as the midpoint to prevent O(n^2) worst case
    std::swap(buffer[start + rand() % (end-start)], buffer[end]);
    int x = buffer[end];

    // Specifies the current midpoint of the partition
    int midpoint = start;

    for (int i = start; i < end; i++) {
        if (buffer[i] <= x) {
            std::swap(buffer[i], buffer[midpoint]);

            // move the midpoint up once
            midpoint += 1;
        }
    }

    // Swap x with the midpoint
    std::swap(buffer[end], buffer[midpoint]);

    // Sort the subarrays, do not include the midpoint
    quicksort(buffer, start, midpoint - 1);
    quicksort(buffer, midpoint + 1, end);
}
