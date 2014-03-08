#include <algorithm>

void quicksort(int *buffer, int start, int end) {
    if( start < end) {
        int mid = buffer[end];

        int divider = start;
        for(int i=start; i < end; i++) {
            if(buffer[i] <= mid)
            {
                std::swap(buffer[i], buffer[divider]);
                divider += 1;
            }
        }

        std::swap(buffer[divider], buffer[end]);

        // Recursively sort for the rest
        quicksort(buffer, start, divider - 1);
        quicksort(buffer, divider + 1, end);
    }
}
