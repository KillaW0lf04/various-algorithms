#include "bubblesort.h"

/*
 * Performs a bubble sort in descending order on an array of integers
 * Time Complexity: O(n^2)
 * Memory: O(1)  (In-place)
 * Stable
 * */

#include <algorithm>

void bubblesort(int *buffer, int length) {

    int i = 0;
    bool flag;

    do {
        flag = false;
        i++;

        for (int j=0; j < length - i; j++) {
            if (buffer[j] < buffer[j + 1]) {
                flag = true;
                std::swap(buffer[j], buffer[j + 1]);
            }
        }
    } while( flag && i < length);
}
