"""
CLOSEST PAIR OF POINTS
"""

from math import sqrt

f = open('../data.txt')


def sort_horizontal(x):
    return x[0]


def sort_vertical(x):
    return x[1]


def dist(x, y):
    return sqrt((y[0]-x[0])**2 + (y[1]-x[1])**2)


def min_dist(X, Y):
    if len(X) == 2:
        return dist(X[0], X[1])
    if len(X) == 3:
        return min(dist(X[0], X[1]), dist(X[0], X[2]), dist(X[1], X[2]))

    e = X[len(X)//2]
    X_st = X[:len(X)//2]
    X_dr = X[len(X)//2:]
    Y_st, Y_dr = [], []
    for p in Y:
        if p[0] < e[0]:
            Y_st.append(p)
        else:
            Y_dr.append(p)
    d1 = min_dist(X_st, Y_st)
    d2 = min_dist(X_dr, Y_dr)
    d = min(d1, d2)

    Y_strip = []
    for p in Y:
        if e[0]-d <= p[0] <= e[0]+d:
            Y_strip.append(p)
    for i in range(len(Y_strip)):
        for j in range(i+1, min(i+8, len(Y_strip))):
            if dist(Y_strip[i], Y_strip[j]) < d:
                d = dist(Y_strip[i], Y_strip[j])

    return d


points = []
for line in f:
    points.append(tuple([int(x) for x in line.split()]))

X = points.copy()
X.sort(key=sort_horizontal)
Y = points.copy()
Y.sort(key=sort_vertical)
d = min_dist(X, Y)

print(d)
