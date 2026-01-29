// Matrix Chain Multiplication Using Memoization

#include <stdio.h>
#include <limits.h>

int m(int i, int j, int D[], int M[5][5])
{
    if (i == j)
    {
        M[i][j] = 0;
        return 0;
    }

    if (M[i][j] != -1)
        return M[i][j];

    M[i][j] = INT_MAX;

    int cost = 0;

    for (int k = i; k < j; k++)
    {
        M[i][k] = m(i, k, D, M);
        M[k + 1][j] = m(k + 1, j, D, M);
        cost = M[i][k] + M[k + 1][j] + (D[i - 1] * D[k] * D[j]);

        if (cost < M[i][j])
            M[i][j] = cost;
    }
    return M[i][j];
}

int main()
{
    int D[] = {2, 5, 6, 4, 3};
    int M[5][5];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            M[i][j] = -1;

    printf("Minimum Multiplication Required is: %d", m(1, 4, D, M));

    return 0;
}