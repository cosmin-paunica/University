"""
C13 ex. II 1

A robot starts in the top-left position of a matrix of positive numbers and can move one step down or to the right.
What path will give him a maximum sum of visited positions?
"""


m = 5
n = 6
M = [
    [5, 10,  2,  7,  9, 4],
    [1,  3,  6, 15,  2, 3],
    [50, 4,  9,  8,  1, 1],
    [2,  1,  7,  2,  6, 5],
    [9,  2, 10, 20, 15, 2]
]

# completing auxiliary matrix (of partial sums)
# T[i][j] = maxumum obtainable sum up until M[i][j]

T = []
for i in range(m):
    T.append([0]*n)

T[0][0] = M[0][0]
for i in range(1, m):
    T[i][0] = M[i][0] + T[i-1][0]
for j in range(1, n):
    T[0][j] = M[0][j] + T[0][j-1]
for i in range(1, m):
    for j in range(1, n):
        T[i][j] = M[i][j] + max(T[i-1][j], T[i][j-1])

# traversing the auxiliary matrix in reverse

ans = [(M[m-1][n-1], m-1, n-1)]
i, j = m-1, n-1
while i != 0 and j != 0:
    if T[i-1][j] > T[i][j-1]:
        ans.append((M[i-1][j], i-1, j))
        i -= 1
    else:
        ans.append((M[i][j-1], i, j-1))
        j -= 1
while i > 0:
    ans.append((M[i-1][0], i-1, 0))
    i -= 1
while j > 0:
    ans.append((M[0][j-1], 0, j-1))
    j -= 1

ans.reverse()
print(ans)
