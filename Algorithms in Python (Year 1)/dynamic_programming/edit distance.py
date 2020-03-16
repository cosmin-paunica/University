"""
L7 ex. 3

EDIT DISTANCE
"""

s1 = "carte"
s2 = "antet"
n = len(s1)
m = len(s2)

T = [[0 for j in range(n+1)] for i in range(m+1)]
B = [[0 for j in range(n+1)] for i in range(m+1)]

# T[i][j] = minimum number of operations necessary in order to get from s1[:j] to s2[:j]
# B[i][j] = what operation we did

for j in range(n+1):
    T[0][j] = j
for i in range(m+1):
    T[i][0] = i
for i in range(1, m+1):
    for j in range(1, n+1):
        if s1[j-1] == s2[i-1]:
            T[i][j] = T[i-1][j-1]
            B[i][j] = 'n'
        else:
            T[i][j] = min(T[i][j-1], T[i-1][j-1], T[i-1][j]) + 1
            if T[i][j-1] == min(T[i][j-1], T[i-1][j-1], T[i-1][j]):
                B[i][j] = 'd'   # delete
            elif T[i-1][j-1] == min(T[i][j-1], T[i-1][j-1], T[i-1][j]):
                B[i][j] = 'r'   # replace
            else:
                B[i][j] = 'i'   # insert

i, j = m, n
op = []
while i > 0 and j > 0:
    if B[i][j] == 'r':
        op.append('replace ' + s1[j-1] + ' with ' + s2[i-1])
        i -= 1; j -= 1
    elif B[i][j] == 'i':
        op.append('insert ' + s2[i-1])
        i -= 1
    elif B[i][j] == 'd':
        op.append('delete ' + s1[j-1])
        j -= 1
    else:
        i -= 1; j -= 1
while i > 0:
    op.append('insert ' + s2[i-1])
    i -= 1
while j > 0:
    op.append('delete ' + s1[j-1])
    j -= 1

op.reverse()
print(op)
