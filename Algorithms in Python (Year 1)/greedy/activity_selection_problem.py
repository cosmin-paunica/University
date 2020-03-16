"""
Lab. 5 ex. 2 / C8 Pb3

ACTIVITY SELECTION PROBLEM
"""


f = open('../data.txt')


def time(hour_and_minute):
    return 60*int(hour_and_minute[:2]) + int(hour_and_minute[3:])


def sort_timp_sf(activity):
    return time(activity[1])


activities = []
for line in f:
    if line[-1] == '\n':
        line = line[:-1]
    begin_time = line.split('-')[0]
    end_time = line.split('-')[1].split(' ')[0]
    name = line.split(' ', 1)[1]
    a = (begin_time, end_time, name)
    activities.append(a)

activities.sort(key=sort_timp_sf)

plan = [activities[0]]
i = 0
for spect in activities[1:]:
    if time(spect[0]) >= time(plan[i][0]):
        plan.append(spect)
        i += 1

for spect in plan:
    print(spect[0] + '-' + spect[1] + ' ' + spect[2])

"""
Set date intrare:

10:00-11:20 Scufita Rosie
09:30-12:10 Punguta cu doi bani
08:20-09:50 Vrajitorul din Oz
11:30-14:00 Capra cu trei iezi
12:10-13:10 Micul Print
14:00-16:00 Povestea porcului
15:00-15:30 Frumoasa din padurea adormita
"""