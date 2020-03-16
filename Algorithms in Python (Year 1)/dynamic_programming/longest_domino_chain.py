"""
Lab. 7, ex. 1

LONGEST DOMINO CHAIN
"""

v = [(1, 6), (1, 5), (5, 3), (5, 2), (4, 6), (2, 4), (2, 3)]
n = len(v)

# T[i]: length of longest subchain obtained until position i
# chains[i] longest subchain obtained until position i

T = [1]*n
chains = [[i] for i in range(n)]
for i in range(n):
    for j in range(i):
        if v[i][0] == v[j][1] and T[i] < T[j] + 1:
            T[i] = T[j] + 1
            x = chains[j].copy()
            x.append(i)
            chains[i] = x

l = max(T)
i = T.index(l)

no_of_possible_longest_chains = 0
ans = None
for s in chains:
    if len(s) == l:
        if ans is None:
            ans = [v[i] for i in s]
        no_of_possible_longest_chains += 1

print(ans)
print(no_of_possible_longest_chains)
