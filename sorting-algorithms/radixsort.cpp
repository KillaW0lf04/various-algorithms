#include "radixsort.h"

#include <list>

/*
 * Performs a Radix sort in ascending order on an array of integers
 * Time Complexity: O(n * d)
 * Memory: O(n)  (In-place)
 * Stable
 * */

void radixsort(int *buffer, int length, int max) {
    int index;
    int value;

    std::list<int> buckets[10];

    int m = 10;  // Value by which to mod
    int n = 1;   // Value by which to divide

    while (max > 0) {
        for (int i=0; i < length; i++) {
            value = buffer[i];

            index = (value % m) / n;
            buckets[index].push_back(value);
        }

        // Replace values from buckets
        index = 0;
        for (int i=0; i<10; i++) {
            while (!buckets[i].empty()) {
                buffer[index++] = buckets[i].front();
                buckets[i].pop_front();
            }
        }

        // update parameters for next iteration
        m *= 10;
        n *= 10;
        max /= 10;
    }
}
