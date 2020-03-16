"""
S5 ex. 1

PROBLEMA CUIELOR

FIX ALL THE GIVEN PLANKS WITH A MINIMUM NUMBER OF NAILS
"""

planks = [(4, 6), (8, 10), (0, 3), (1, 2), (5, 8)]

planks.sort()

nails = []
last_nail_position = -1
for s in planks:
    if s[0] > last_nail_position:
        nails.append(s[1])
        last_nail_position = s[1]
    elif s[1] < last_nail_position:
        nails.pop()
        nails.append(s[1])
        last_nail_position = s[1]

print(nails)
