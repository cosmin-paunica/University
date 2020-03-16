"""
C13 ex I 1

LONGEST INCREASING SUBSEQUEC
"""


n = 11
v = [5, 9, 2, 4, 7, 6, 7, 15, 10, 11, 9]

# T[i] = longest increasing subsequence from 0 to i
# W[i] = where we came from when we built the longest subsequence from 0 to i
T = [1]*n
W = [-1]*n
for i in range(n):
    for j in range(i):
        if v[i] > v[j] and T[i] < T[j] + 1:
            T[i] = T[j] + 1
            W[i] = j

# merg inapoi prin v dupa cum dicteaza W
i = T.index(max(T))
subsequence = [v[i]]
while W[i] != -1:
    i = W[i]
    subsequence.append(v[i])
subsequence.reverse()

print(subsequence)
