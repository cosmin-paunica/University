"""
Lab. 5 ex. 4 / C8 Pb2

FIND A WAY TO PAY A GIVEN SUM WITH COINS WITH VALUES FROM A GIVEN SET SO THAT THEIR NUMBER IS MINIMUM

b[i] divids b[j] for each 0 <= i < j <= n-2
"""

f = open('../data.txt')

bancnote = f.readline().split()
for i in range(len(bancnote)):
    bancnote[i] = int(bancnote[i])
s = int(f.readline())

bancnote.sort(reverse=True)

i = 0
plata = []
nr = 0
while s > 0:
    while bancnote[i] <= s:
        s -= bancnote[i]
        nr += 1
    if nr != 0:
        plata.append((bancnote[i], nr))
        nr = 0
    i += 1

s = ''
for x in plata:
    s += str(x[0]) + '*' + str(x[1]) + ' + '
s = s[:-3]

print(s)

"""
Set date intrare:

1 5 10 50 100 200 500
173
"""