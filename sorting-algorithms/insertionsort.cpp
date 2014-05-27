#include "insertionsort.h"

/*
 * Performs an insertion sort in descending order on an array of integers
 * Time Complexity: O(n^2)
 * Memory: O(1) (In-place)
 * Stable
 * */

#include <algorithm>

void insertionsort(int *buffer, int length) {
    for (int i = 1; i < length; i++) {
        int count = i;
        while(i > 0 && buffer[count] > buffer[count -1])
        {
            std::swap(buffer[count], buffer[count - 1]);
            count--;
        }
    }
}
