""""
C14 ex. 1

LONGEST COMMON SUBSTRING OF TWO SEQUENCES OF NUMBERS
"""

n = 9
m = 9
v = [5, 2, 7, 9, 4, 3, 12, 10, 4]
w = [5, 9, 2, 7, 10, 14, 3, 10, 9]

# T[i][j] = length of longest common subsequence up until v[i] and w[j]

T = [[0 for j in range(m+1)] for i in range(n+1)]
v.insert(0, 0)  # pt a indexa de la 1
w.insert(0, 0)

for i in range(1, n+1):
    for j in range(1, m+1):
        t1 = T[i-1][j]
        t2 = T[i][j-1]
        t3 = T[i-1][j-1] + (v[i] == w[j])
        T[i][j] = max(t1, t2, t3)

print(T[n][m])
