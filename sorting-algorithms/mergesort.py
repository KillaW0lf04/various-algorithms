from math import floor


# This is a really hackish mergesort
def mergesort(nlist):

    if len(nlist) <= 1:
        return nlist

    mid = floor(len(nlist)/2)
    a = mergesort(nlist[:mid])
    b = mergesort(nlist[mid:])

    result = []

    # Merge operation
    while len(a) > 0 and len(b) > 0:
        if a[0] > b[0]:
            result.append(a[0])
            a = a[1:]
        else:
            result.append(b[0])
            b = b[1:]

    result.extend(a)
    result.extend(b)
    return result


if __name__ == '__main__':

    import random
    n = 10
    nlist = random.sample(range(n), n)

    nlist = mergesort(nlist)

    print(nlist)