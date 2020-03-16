"""
C14, ex. 2

OPTIMAL STRAREGY FOR A GAME
"""

v = [3, 7, 1, 9, 4, 5, 2, 8, 8, 4, 2, 3]
n = len(v)

T = [[0 for i in range(n)] for i in range(n)]

# T[i][j] = pereche formata din rezultatele pe care le pot obtine jucatorii daca tabla ar fi formata doar din
# elementele de la pozitia i pana la pozitia j

for i in range(n):
    T[i][i] = (v[i], 0)
for i in range(n-1):
    T[i][i+1] = (max(v[i], v[i+1]), min(v[i], v[i+1]))
for len in range(2, n):
    for i in range(n - len):
        if v[i] + T[i+1][i+len][1] > v[i+len] + T[i][i+len-1][1]:
            suma_P1 = v[i] + T[i+1][i+len][1]
            suma_P2 = T[i+1][i+len][0]
        else:
            suma_P1 = v[i+len] + T[i][i+len-1][1]
            suma_P2 = T[i][i+len-1][0]
        T[i][i+len] = (suma_P1, suma_P2)
ans = T[0][n-1]

print(ans)      # maximum win of player 1 and resulting win of player 2

