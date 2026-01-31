// Max Subarray Sum

#include <stdio.h>
#include <limits.h>

int maxSub(int A[], int n)
{
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;

            for (int k = i; k <= j; k++)
            {
                sum += A[k];
            }
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    return maxSum;
}

int main()
{
    int D[] = {2, -5, -6, 4, 3, -9, -2, -3, 5, 7, 8, -2};

    printf("Maximum Sum Of Subarray will be: %d", maxSub(D, 12));

    return 0;
}