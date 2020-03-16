"""
Lab 5 ex 5.

MINIMIZING MAXIMUM LATENESS
"""

f = open('../data.txt')
g = open('../output.txt', 'w')


def sort_by_deadline(activity):
    return activ[1]


n = int(f.readline())
activities = []
for line in f:
    activ = tuple([int(x) for x in line.split()])
    activities.append(activ)

activities.sort(key=sort_by_deadline)

time = 0
plan = []
for activ in activities:
    ora_inc = time
    time += activ[0]
    ora_sf = time
    if time - activ[1] > 0:
        h = time - activ[1]
    else:
        h = 0
    plan.append((ora_inc, ora_sf, activ[1], h))

g.write('Interval\tTermen\tIntarziere\n')
for activ in plan:
    if activ[0] >= 10 or activ[1] >= 10:
        g.write('(' + str(activ[0]) + '-->' + str(activ[1]) + ')\t' + str(activ[2]) + '\t' + str(activ[3]) + '\n')
    else:
        g.write('('+str(activ[0])+'-->'+str(activ[1])+')\t\t'+str(activ[2])+'\t'+str(activ[3])+'\n')

"""
Data input example:

6
3 6
2 8
1 9
4 9
3 14
2 15
"""
