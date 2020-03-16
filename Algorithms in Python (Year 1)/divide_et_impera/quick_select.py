"""
S6 ex 3. --> si alte solutii in caiet

Sa se gaseasca al k-lea minim dintr-un vector de numere distincte.
"""

def quick_select(v, k):
    piv = v[0]
    st, dr = [], []
    for x in v[1:]:
        if x < piv:
            st.append(x)
        else:
            dr.append(x)
    if len(st) == k-1:
        return piv
    if len(st) > k-1:
        return quick_select(st, k)
    return quick_select(dr, k-len(st)-1)


L = [3, 5, 6, 1, 9, 7, 4, 2, 8]
k = 5
min_k = quick_select(L, k)
print(min_k)
