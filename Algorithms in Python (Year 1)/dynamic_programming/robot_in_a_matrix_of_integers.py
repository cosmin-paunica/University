"""
C13 ex. II 1

A robot can start in any position on the top row of a matrix of integers and moves one step down or to the right.
What path will give him a maximum sum of visited positions?
"""


m = 5
n = 6
M = [
    [    11, -10,  30,   -7, -9, -4],
    [-10000,   3,   6,   15, -2,  3],
    [    50,  -4,   9,   -8,  1,  1],
    [     2,   1,   7,   -2, -6, -5],
    [     9,   2, -10,   20, -5,  2]
]

# completing auxiliary matrix (of partial sums)
# T[i][j] = maxumum obtainable sum up until M[i][j]

T = [[0 for j in range(n)] for i in range(m)]
sum_max = M[0][0]
i_max, j_max = 0, 0

for j in range(n):
    T[0][j] = M[0][j]
    if T[0][j] > sum_max:
        sum_max = T[0][j]
        j_max = j
for i in range(1, m):
    T[i][0] = M[i][0] + T[i-1][0]
    if T[i][0] > sum_max:
        sum_max = T[i][0]
        i_max = i
for i in range(1, m):
    for j in range(1, n):
        T[i][j] = M[i][j] + max(T[i-1][j], T[i][j-1])
        if T[i][j] > sum_max:
            sum_max = T[i][j]
            i_max, j_max = i, j

# traversing the auxiliary matrix in reverse, starting from the position with maximum sum

i, j = i_max, j_max
S = [(M[i][j], (i, j))]
while i > 0 and j > 0:
    if T[i-1][j] > T[i][j-1]:
        i -= 1
    else:
        j -= 1
    S.append((M[i][j], (i, j)))

while i > 0:
    i -= 1
    S.append((M[i][0], (i, 0)))

# if we reached row 0, we go left searching for elements which give bigger sums, because the robot can start anywhere

partial_sum_on_line_0 = 0
k = j - 1
while k >= 0:
    partial_sum_on_line_0 += M[0][k]
    if partial_sum_on_line_0 > 0:
        for l in range(j-1, k-1, -1):
            S.append((M[0][l], (0, l)))
            sum_max += M[0][l]
        j = k
        partial_sum_on_line_0 = 0
    k -= 1

S.reverse()

print(S)
print(sum_max)
