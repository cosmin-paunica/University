"""
C11 Pb3
"""


def weighted_median(v):
    if len(v) == 1:
        return v[0]
    if len(v) == 2:
        if v[0][1] > v[1][1]:
            return v[0]
        return v[1]
    e = list(v[0])
    v_st, v_dr = [], []
    sum_st, sum_dr = 0, 0
    for x in v[1:]:
        if x[0] < e[0]:
            v_st.append(x)
            sum_st += x[1]
        else:
            v_dr.append(x)
            sum_dr += x[1]
    if sum_st < 0.5 and sum_dr <= 0.5:
        return e
    if sum_dr > 0.5:
        e[1] += sum_st
        v_dr.append(tuple(e))
        return weighted_median(v_dr)
    e[1] += sum_dr
    v_st.append(tuple(e))
    return weighted_median(v_st)


v = [(5, 0.12), (20, 0.3), (16, 0.1), (6, 0.08), (3, 0.1), (15, 0.1), (12, 0.2)]
print(weighted_median(v))
