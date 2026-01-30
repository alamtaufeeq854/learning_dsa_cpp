// Matrix Chain Multiplication Using Tabulation

#include <stdio.h>
#include <limits.h>

int mcm(int D[], int n, int M[5][5])
{
    int cost;

    for (int i = 1; i <= n; i++)
        M[i][i] = 0;

    for (int diff = 1; diff < n; diff++)
    {
        for (int i = 1; i <= n - diff; i++)
        {
            int j = i + diff;
            M[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                cost = M[i][k] + M[k + 1][j] + (D[i - 1] * D[k] * D[j]);

                if (cost < M[i][j])
                    M[i][j] = cost;
            }
        }
    }

    return M[1][n];
}

int main()
{
    int D[] = {2, 5, 6, 4, 3};
    int M[5][5];

    printf("Minimum Multiplication Required is: %d", mcm(D, 4, M));

    return 0;
}
