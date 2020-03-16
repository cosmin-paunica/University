"""
C13 ex. III 1 (desi rezolvarea e diferita)

COIN CHANGE PROBLEM
"""

coins = [1, 5, 6, 8]
n = len(coins)
s = 11

T = [[] for j in range(s+1)]

# T[j] = smallest set of coins for paying sum j

for j in range(1, s+1):
    x = T[j-1].copy()
    x.append(coins[0])
    T[j] = x
for i in range(1, n):
    for j in range(s+1):
        if j >= coins[i]:
            x = [coins[i]]*(j // coins[i])
            x.extend(T[j % coins[i]])
            if len(x) < len(T[j]):  # verific daca, adaugand moneda j, obtin o solutie mai buna
                T[j] = x
ans = T[s]

print(ans)

# se poate vizualiza solutia mai bine daca T este tablou bidimensional, in care fiecare linie i contine listele optime
# construite avand doar monedele 0, 1, ... , i; rezolvarea este similara
