// Longest Common Subsequence By Tabulation

#include <stdio.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lcs(int m, int n, char A[], char B[])
{
    int L[m + 1][n + 1];

    for (int i = 0; i <= n; i++)
        L[0][i] = 0;

    for (int i = 0; i <= m; i++)
        L[i][0] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (A[i - 1] == B[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = MAX(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

int main()
{
    char A[] = {'a', 'b', 'c', 'd', 'e'};
    char B[] = {'a', 'c', 'e'};

    printf("Longest Common Subsequence Is: %d", lcs(5, 3, A, B));

    return 0;
}