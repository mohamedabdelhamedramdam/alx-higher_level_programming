#!/usr/bin/python3

import sys

def is_safe(board, row, col):
    # Check if there is a queen in the same column
    for i in range(row):
        if board[i] == col or \
           board[i] - i == col - row or \
           board[i] + i == col + row:
            return False
    return True

def solve_nqueens(n):
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    def print_solution(board):
        for row in board:
            print([i, row[i]] for i in range(n))
        print()

    def solve(row, board):
        if row == n:
            print_solution(board)
            return
        for col in range(n):
            if is_safe(board, row, col):
                board.append(col)
                solve(row + 1, board)
                board.pop()

    solve(0, [])

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)

try:
    n = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    sys.exit(1)

solve_nqueens(n)
