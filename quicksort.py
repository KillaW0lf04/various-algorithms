
def quicksort(nlist, start=0, end=-1):

    # If default values passed
    if end == -1:
        end = len(nlist) - 1

    # Termination Criteria
    if start >= end:
        return

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
