from math import floor
from copy import copy


def max_heapify(nlist, index):
    # LEFT = parent * 2 + 1
    # RIGHT = parent * 2
    # BUT we are using zero index
    left = (index+1) * 2 - 1
    right = (index+1) * 2

    largest = index

    if left < len(nlist) and nlist[left] > nlist[largest]:
        largest = left

    if right < len(nlist) and nlist[right] > nlist[largest]:
        largest = right

    if largest != index:
        nlist[largest], nlist[index] = nlist[index], nlist[largest]
        max_heapify(nlist, largest)


# heap property is that parent must always be larger than children
# Always remember that heap arrays are always 1 indexed
def build_max_heap(nlist):

    # Because 1 element nodes are guaranteed to satisfy the heap
    # property we can simply start from size/2 - 1 (ie the first left node)
    for i in reversed(range(floor(len(nlist)/2))):
        max_heapify(nlist, i)


# Not the most efficient way to perform a merge sort
# because we are creating so many arrays per iteration
# Ideally you would pass boundary markers start and end
# and perform a heap sort within the specified region alone
def heapsort(nlist):

    result = []
    current = copy(nlist)

    for i in range(len(nlist)):

        build_max_heap(current)
        result.append(current[0])

        current = current[1:]

    return result


if __name__ == '__main__':

    import random
    n = 10
    a = random.sample(range(n), n)

    a = heapsort(a)

    print(a)
