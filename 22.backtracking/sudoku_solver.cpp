// Sudoku Solver

#include <stdio.h>
#include <stdbool.h>

#define N 9

int S[N][N] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}};

void printSudoku()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", S[i][j]);
        printf("\n");
    }
}

bool isValid(int r, int c, int val)
{
    for (int i = 0; i < N; i++)
    {
        if (S[r][i] == val)
            return false;
        if (S[i][c] == val)
            return false;
    }

    int blockRow = r - r % 3;
    int blockCol = c - c % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (S[blockRow + i][blockCol + j] == val)
                return false;

    return true;
}

bool solveSudoku(int r, int c)
{
    if (r == N)
        return true;

    if (c == N)
        return solveSudoku(r + 1, 0);

    if (S[r][c] != 0)
        return solveSudoku(r, c + 1);

    for (int val = 1; val <= 9; val++)
    {
        if (isValid(r, c, val))
        {
            S[r][c] = val;

            if (solveSudoku(r, c + 1))
                return true;

            S[r][c] = 0;
        }
    }
    return false;
}

int main()
{
    if (solveSudoku(0, 0))
        printSudoku();
    else
        printf("No solution exists\n");

    return 0;
}
