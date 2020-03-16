"""
N QUEEN PROBLEM
"""


def print_board(M):
    for row in M:
        for x in row:
            print(x, end='  ')
        print()


def check(row, col):
    for i in range(row):
        if Board[i][col] == 1:
            return False
    i, j = row-1, col-1
    while i >= 0 and j >= 0:
        if Board[i][j] == 1:
            return False
        i -= 1; j -= 1
    i, j = row-1, col+1
    while i >= 0 and j < n:
        if Board[i][j] == 1:
            return False
        i -= 1; j += 1
    return True


def place_queen(row=0):
    global done
    if row == n:
        done = True
        print_board(Board)
        print()
    if not done:
        for col in range(n):
            if check(row, col):
                Board[row][col] = 1
                place_queen(row+1)
                Board[row][col] = 0


n = 5
Board = [[0 for i in range(n)] for i in range(n)]

done = False
place_queen()
if not done:
    print("Nu exista solutie")

# To show all solutions, delete everything that contains the 'done' variable.
