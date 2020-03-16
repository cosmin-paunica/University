"""
S6 ex 2.

Complete a matrix by the following rule, then find the position of an element in the matrix.

|III | I|
|-------|
|II | IV|
"""


def afisare_matrice(M):
    for row in M:
        print(row)


def completare(sus, st, jos, dr):
    global counter
    if dr-st == 2:
        A[sus][st+1] = counter
        A[sus+1][st] = counter+1
        A[sus][st] = counter+2
        A[sus+1][st+1] = counter+3
        counter += 4
    else:
        completare(sus, dr-(dr-st)//2, (jos-sus)//2, dr)
        completare(jos-(jos-sus)//2, st, jos, dr-(dr-st)//2)
        completare(sus, st, jos-(jos-sus)//2, dr-(dr-st)//2)
        completare(jos-(jos-sus)//2, dr-(dr-st)//2, jos, dr)


def cautare(x, m, M, sus, st, jos, dr):
    if m == M:
        return sus, st
    d = m-1     # d este folosit pentru a normaliza patratul curent la cel care contine elemente incepand de la 1
    x -= d; m -= d; M -= d
    if m <= x <= M//4:
        return cautare(x + d, m + d, M//4 + d, sus, dr-(dr-st)//2, jos-(jos-sus)//2, dr)
    if M//4+1 <= x <= M//2:
        return cautare(x + d, M//4+1 + d, M//2 + d, jos-(jos-sus)//2, st, jos, dr-(dr-st)//2)
    if M//2+1 <= x <= M//4*3:
        return cautare(x + d, M//2+1 + d, M//4*3 + d, sus, st, jos-(jos-sus)//2, dr-(dr-st)//2)
    return cautare(x + d, M//4*3+1 + d, M + d, jos-(jos-sus)//2, dr-(dr-st)//2, jos, dr)


n = 8
A = [[0 for j in range(n)] for i in range(n)]

counter = 1
completare(0, 0, n, n)
afisare_matrice(A)

x = 63
print(cautare(x, 1, n*n, 0, 0, n, n))
