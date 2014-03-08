void quicksort(int *buffer, int start, int end) {
    if( start < end) {
        int mid = buffer[end];
        int dummy;

        int divider = start;
        for(int i=start; i < end; i++) {
            if(buffer[i] <= mid)
            {
                // Swap
                dummy = buffer[divider];
                buffer[divider] = buffer[i];
                buffer[i] = dummy;

                divider += 1;
            }
        }

        dummy = buffer[end];
        buffer[end] = buffer[divider];
        buffer[divider] = dummy;

        // Recursively sort for the rest
        quicksort(buffer, start, divider - 1);
        quicksort(buffer, divider + 1, end);
    }
}
