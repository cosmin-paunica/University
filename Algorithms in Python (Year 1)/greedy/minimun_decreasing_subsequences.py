"""
S5 ex. 3

Break a sequence of numbers into a minimun number of strictly decreasing subesquences.
"""


def binary_search(v, x, st=0, dr=None):
    if dr is None:
        dr = len(v)
    if dr-st == 1:
        return st
    m = (st + dr) // 2
    if v[m-1] <= x < v[m]:
        return m
    if v[m] <= x:
        return binary_search(v, x, m+1, dr)
    return binary_search(v, x, st, m)


seq = [10, 15, 9, 6, 7, 14, 3, 8, 10, 2, 7, 3, 9]

subseqs = [[seq[0]]]
B = [seq[0]]    # vector ce contine ultimul numar din fiecare subsir (mereu este sortat crescator)
for x in seq[1:]:
    if x >= B[-1]:
        subseqs.append([x])
        B.append(x)
    else:
        i = binary_search(B, x)
        subseqs[i].append(x)
        B[i] = x

for s in subseqs:
    print(s)
