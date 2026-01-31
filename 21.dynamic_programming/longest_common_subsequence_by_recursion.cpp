// Longest Common Subsequence By Recursion

#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lcs(int i, int j, char A[], char B[])
{
    if (i == -1 || j == -1)
        return 0;

    if (A[i] == B[j])
        return 1 + lcs(i - 1, j - 1, A, B);

    else
        return MAX(lcs(i - 1, j, A, B), lcs(i, j - 1, A, B));
}

int main()
{
    char A[] = {'a', 'b', 'c', 'd', 'e'};
    char B[] = {'a', 'c', 'e'};

    printf("Longest Common Subsequence Is: %d", lcs(4, 2, A, B));

    return 0;
}