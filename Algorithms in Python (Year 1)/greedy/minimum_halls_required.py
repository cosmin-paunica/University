"""
Lab 5 ex 6. / S5 ex 2.

MINIMUM HALLS REQUIRED FOR CLASS SCHEDULING
"""

from heapq import heappush, heappop

f = open('../data.txt')


def time(ora_minut):
    return 60*int(ora_minut[:2]) + int(ora_minut[3:])


def sort_by_begin_time(spect):
    return time(spect[0])


classes = []
for line in f:
    if line[-1] == '\n':
        line = line[:-1]
    begin_time = line.split('-')[0]
    end_time = line.split('-')[1].split(' ')[0]
    name = line.split(' ', 1)[1]
    c = (begin_time, end_time, name)
    classes.append(c)

classes.sort(key=sort_by_begin_time)

halls = [[classes[0]]]
Q = [(time(classes[0][1]), 0)]
k = 0   # numerotam salile de la 0
for c in classes[1:]:
    h, s = Q[0][0], Q[0][1]     # h = ora de eliberare cea mai devreme; s = indicele salii cu aceasta ora
    if time(c[0]) < Q[0][0]:
        halls.append([c])
        k += 1
        heappush(Q, (time(c[1]), k))
    else:
        halls[s].append(c)
        heappop(Q)
        heappush(Q, (time(c[1]), s))

print(len(halls))
for sala in halls:
    print(sala)

"""
Data input example:

15:00-16:30 j
11:00-12:30 d
09:00-10:30 a
13:00-14:30 f
14:00-16:30 h
11:00-14:00 e
15:00-16:30 i
09:00-12:30 b
13:00-14:30 g
09:00-10:30 c
"""
