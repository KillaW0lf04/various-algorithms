
def quicksort(nlist, start=0, end=-1):

    # If default values passed
    if end == -1:
        end = len(nlist) - 1

    # Termination Criteria
    if start >= end:
        return

    # NOTE: Choosing a random pivot is theoretically better as it
    # prevents worst case O(n^2) time complexity from occurring in
    # cases where the last element is also the largest element (Which
    # is the case in already sorted lists for example)
    # TODO!

    # Choose the last item as the mid value
    mid_value = nlist[end]
    mid = start

    for index in range(start, end):

        if nlist[index] < mid_value:
            nlist[mid], nlist[index] = nlist[index], nlist[mid]
            mid += 1

    # Swap the mid-value with the current mid pointer
    nlist[mid], nlist[end] = nlist[end], nlist[mid]

    # Recursively sort the sublists
    quicksort(nlist, start, mid - 1)
    quicksort(nlist, mid + 1, end)


if __name__ == '__main__':

    import random
    size = 3000
    a = random.sample(range(0, size), size)
    quicksort(a)

    print(a)
