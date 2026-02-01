// Rat in a Maze Problem

#include <stdio.h>

#define N 7

int sol[2][N * N];
int path = 0;

int M[N][N] = {
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 0, 1},
    {0, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 0},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1}};

void rim(int i, int j)
{
    if (i == N - 1 && j == N - 1)
    {
        sol[0][path] = i;
        sol[1][path] = j;

        for (int k = 0; k <= path; k++)
            printf("(%d,%d) ", sol[0][k], sol[1][k]);

        printf("\n\n\n");
        return;
    }

    M[i][j] = 0;
    sol[0][path] = i;
    sol[1][path] = j;
    path++;

    if (j + 1 < N && M[i][j + 1] == 1)
        rim(i, j + 1);

    if (i + 1 < N && M[i + 1][j] == 1)
        rim(i + 1, j);

    if (j - 1 >= 0 && M[i][j - 1] == 1)
        rim(i, j - 1);

    if (i - 1 >= 0 && M[i - 1][j] == 1)
        rim(i - 1, j);

    M[i][j] = 1;
    path--;
}

int main()
{
    rim(0, 0);
    return 0;
}
