"""
Lab 6 II 1.

Break a natural number into a sum of distinct natural numbers.
"""


def check(s):
    for i in range(len(s)-1):
        if s[i] > s[i+1]:
            return False
    if sum(s) != n:
        return False
    return True


def bkt():
    if check(s):
        print(s)
    for i in range(1, n+1):
        if i not in s:
            s.append(i)
            if sum(s) <= n:
                bkt()
            s.pop()


n = 8
s = []
bkt()
