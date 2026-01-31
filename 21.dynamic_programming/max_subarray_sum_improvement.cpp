// Max Subarray Sum Improvement

#include <stdio.h>
#include <limits.h>

int maxSub(int A[], int n)
{
    int start, end;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += A[j];

            if (sum > maxSum)
            {
                maxSum = sum;
                start = i;
                end = j;
            }
        }
    }
    printf("Maximum Sum of Subarray starts From index %d and ends on index %d\n", start, end);
    return maxSum;
}

int main()
{
    int D[] = {2, -5, -6, 4, 3, -9, -2, -3, 5, 7, 8, -2};

    printf("Maximum Sum of Subarray will be of: %d", maxSub(D, 12));

    return 0;
}