// N-Queens Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define n 4

int X[n + 1];

bool valid(int k, int l)
{
    for (int i = 1; i < k; i++)
    {
        if (X[i] == l || abs(i - k) == abs(X[i] - l))
            return false;
    }
    return true;
}

void nQueens(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (valid(k, i))
        {
            X[k] = i;

            if (k == n)
            {
                for (int i = 1; i <= n; i++)
                    printf("%d ", X[i]);
                printf("\n");
            }

            else
                nQueens(k + 1);
        }
    }
}

int main()
{
    nQueens(1);
    return 0;
}