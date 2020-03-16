"""
Lab. 5 ex. 7 / C9 Pb7

FRACTIONAL KNAPSACK PROBLEM
"""

f = open('../data.txt')


def sort_(x):
    return x[0] / x[1]


def simplify(a, b):
    for i in range(2, a):
        while a % i == 0 and b % i == 0:
            a //= i; b //= i
    return str(a) + '/' + str(b)


n = int(f.readline())
objects = []
for i in range(3):
    o = tuple([int(x) for x in f.readline().split()])
    objects.append(o)
G = int(f.readline())

objects.sort(key=sort_, reverse=True)

knapsack = []
i = 0
G1 = G
while objects[i][1] <= G1:
    knapsack.append(objects[i])
    G1 -= objects[i][1]
    i += 1
knapsack.append((objects[i], simplify(G1, objects[i][1])))

# printing the results:
print('weigth:')
print(str(G) + ' = ', end='')
for o in knapsack[:-1]:
    print(str(o[1]) + ' + ', end='')
print('(' + knapsack[-1][1] + ')*' + str(knapsack[-1][0][1]) + '\n')

print('value:')
val = 0
for o in knapsack[:-1]:
    val += o[0]
    print(str(knapsack[0]) + ' + ', end='')
val += knapsack[-1][0][0] * int(knapsack[-1][1][0]) / int(knapsack[-1][1][2])
print('(' + knapsack[-1][1] + ')*' + str(knapsack[-1][0][0]) + ' = ' + str(val))

"""
Data input example:

3
120 30
60 10
100 20
50
"""
