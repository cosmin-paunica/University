"""
C11 Pb2

MEDIAN OF TWO SORTED ARRAYS OF DIFFERENT SIZES
"""


def median(v):
    if len(v) % 2 == 1:
        return v[len(v)//2]
    return (v[len(v)//2-1] + v[len(v)//2]) / 2


def merge(v, w):
    a = []
    i, j = 0, 0
    while i < len(v) and j < len(w):
        if v[i] < w[j]:
            a.append(v[i])
            i += 1
        else:
            a.append(w[j])
            j += 1
    while i < len(v):
        a.append(v[i])
        i += 1
    while j < len(w):
        a.append(w[j])
        j += 1
    return a


def extended_middle(v):
    if len(v) % 2 == 1:
        return v[len(v)//2-1 : len(v)//2+2]
    return v[len(v)//2-2 : len(v)//2+2]


def med_of_arrays(v, w):
    print(v)
    print(w)
    print()
    if len(v) <= 2:
        return median(merge(v, extended_middle(w)))
    if median(v) < median(w):
        return med_of_arrays(v[len(v)//2 :], w[: len(w) - len(v)//2])
    return med_of_arrays(v[: len(v)//2 + len(v) % 2], w[len(v)//2 :])


v = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21]
w = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34]

print(med_of_arrays(v, w))
