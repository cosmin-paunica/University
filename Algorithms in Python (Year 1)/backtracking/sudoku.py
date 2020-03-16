"""
SUDOKU

exercitiul nr. 125 din revista mea de Sudoku
"""

def print_board(M):
    print('|---------+---------+---------|')
    for i in range(len(M)):
        for j in range(len(M)):
            if j == 0:
                print('|', end=' ')
            print(M[i][j], end=' ')
            if j == 8:
                print(end='|')
            elif (j+1)%3 == 0:
                print(end='|')
            print(end=' ')

        print()
        if (i+1)%3 == 0:
            print('|---------+---------+---------|')


def check(k, row, col):
    for i in range(9):
        if Board[i][col] == k:
            return False
    for j in range(9):
        if Board[row][j] == k:
            return False
    for i in range(row//3*3, row//3*3+3):
        for j in range(col//3*3, col//3*3+3):
            if Board[i][j] == k:
                return False
    return True


def sudoku(i=0, j=0):
    if i == 9:
        print_board(Board)
    else:
        if Board[i][j] == 0:
            for k in range(1, 10):
                if check(k, i, j):
                    Board[i][j] = k
                    if j == 8:
                        sudoku(i+1, 0)
                    else:
                        sudoku(i, j+1)
                    Board[i][j] = 0
        elif j == 8:
            sudoku(i+1, 0)
        else:
            sudoku(i, j+1)


Board = [[0, 0, 8, 0, 0, 0, 9, 0, 0],
         [0, 6, 0, 1, 3, 9, 0, 7, 0],
         [1, 0, 0, 0, 0, 0, 0, 0, 5],
         [0, 9, 0, 2, 0, 6, 0, 8, 0],
         [0, 5, 0, 0, 0, 0, 0, 4, 0],
         [0, 4, 0, 7, 0, 3, 0, 9, 0],
         [7, 0, 0, 0, 0, 0, 0, 0, 9],
         [0, 1, 0, 9, 7, 5, 0, 3, 0],
         [0, 0, 3, 0, 0, 0, 4, 0, 0]]

sudoku()
