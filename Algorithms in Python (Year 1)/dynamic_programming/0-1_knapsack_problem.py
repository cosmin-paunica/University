"""
C14 ex. 3 (desi in curs problema e rezolvata diferit)

0/1 KNAPSACK PROBLEM
"""


class Object:
    def __init__(self, v, g):
        self.v = v  # valoare
        self.g = g  # greutate


objects = [Object(3, 8), Object(2, 12), Object(1, 6), Object(7, 10), Object(4, 6), Object(9, 16), Object(10, 10), Object(21, 14), Object(12, 12)]
n = len(objects)
G = 50

T = [[0 for j in range(G+1)] for i in range(n)]

for j in range(objects[0].g, G+1):
    T[0][j] = objects[0].v
for i in range(1, n):
    for j in range(1, G+1):
        if j < objects[i].g:
            T[i][j] = T[i-1][j]
        else:
            T[i][j] = max(T[i-1][j], objects[i].v + T[i-1][j-objects[i].g])
ans = T[n-1][G]

print(ans)
