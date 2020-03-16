"""
Lab 6 II 3.

MAP COLOURING PROBLEM

Print all the possible ways in which you can colour a given map, so that two adjacent regions are differently-coloured.
"""

f = open('../data.txt')


def create_adjacency():
    for line in f:
        i, j = int(line[0]), int(line[2])
        M[i][j], M[j][i] = 1, 1


def check(k, color):
    for j in range(1, k):
        if M[k][j] == 1 and s[j] == color:
            return False
    return True


def bkt(k=1):
    if k == n+1:
        print(s[1:])
        return
    for color in range(1, 5):
        if check(k, color):
            s[k] = color
            if k <= n:
                bkt(k+1)


n = int(f.readline())
M = []
for i in range(n+1):
    M.append([0]*(n+1))
create_adjacency()
s = [0]*(n+1)
bkt()

"""
input data example:

6
1 2
3 1
4 1
1 5
2 3
5 2
4 3
5 4
6 1
3 6
4 6
"""