// Longest Common Subsequence By Memoization

#include <stdio.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lcs(int i, int j, char A[], char B[], int L[5][3])
{
    if (i < 0 || j < 0)
    {
        L[i][j] = 0;
        return 0;
    }

    if (L[i][j] != INT_MIN)
        return L[i][j];

    if (A[i] == B[j])
        L[i][j] = 1 + lcs(i - 1, j - 1, A, B, L);

    else
        L[i][j] = MAX(lcs(i - 1, j, A, B, L), lcs(i, j - 1, A, B, L));

    return L[i][j];
}

int main()
{
    char A[] = {'a', 'b', 'c', 'd', 'e'};
    char B[] = {'a', 'c', 'e'};
    int L[5][3];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 3; j++)
            L[i][j] = INT_MIN;

    printf("Longest Common Subsequence Is: %d", lcs(4, 2, A, B, L));

    return 0;
}