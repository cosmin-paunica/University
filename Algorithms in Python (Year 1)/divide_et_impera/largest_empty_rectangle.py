"""
Lab 5 ex 2. / C11 Pb4
"""

f = open('../data.txt')


def divide(down_left, top_right):
    global A_max, coord_max
    ok = True
    for c in holes:
        if down_left[0] < c[0] < top_right[0] and down_left[1] < c[1] < top_right[1]:
            ok = False
            divide(down_left, (c[0], top_right[1]))
            divide((c[0], down_left[1]), top_right)
            divide(down_left, (top_right[0], c[1]))
            divide((down_left[0], c[0]), top_right)
    if ok and A_max < (top_right[0] - down_left[0]) * (top_right[1] - down_left[1]):
        A_max = (top_right[0] - down_left[0]) * (top_right[1] - down_left[1])
        coord_max = (down_left, top_right)


down_left = tuple([int(x) for x in f.readline().split()])
top_right = tuple([int(x) for x in f.readline().split()])
holes = []
for line in f:
    holes.append(tuple([int(x) for x in line.split()]))

A_max = 0
coord_max = ((0, 0), (0, 0))
divide(down_left, top_right)

print(A_max, coord_max)

"""
Data input example:

2 1     (down-left corner of the area)
8 5     (top-right corner of the area)
3 2
4 4
5 3
7 4
"""