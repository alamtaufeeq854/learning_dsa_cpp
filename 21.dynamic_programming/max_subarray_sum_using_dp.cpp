// Max Subarray Sum Using DP

#include <stdio.h>

int dpSum(int A[], int n)
{
    int S[n];

    S[0] = A[0];

    for (int i = 1; i < n; i++)
    {
        if (S[i - 1] < 0)
            S[i] = A[i];

        else
            S[i] = S[i - 1] + A[i];
    }

    int maxSum = S[0];

    for (int i = 1; i < n; i++)
    {
        if (S[i] > maxSum)
            maxSum = S[i];
    }

    return maxSum;
}

int main()
{
    int D[] = {2, -5, -6, 4, 3, -9, -2, -3, 5, 7, 8, -2};

    printf("Maximum Sum Of Subarray will be: %d", dpSum(D, 12));

    return 0;
}