// Kadanes Max Subarray Sum

#include <stdio.h>

int kadanes(int A[], int n)
{
    int prevSum = A[0];
    int maxSum = A[0];

    int start = 0, end = 0, subStart = 0;

    for (int i = 1; i < n; i++)
    {
        if (prevSum < 0)
        {
            prevSum = A[i];
            subStart = i;
        }

        else
            prevSum += A[i];

        if (prevSum > maxSum)
        {
            maxSum = prevSum;
            start = subStart;
            end = i;
        }
    }
    printf("Maximum Sum of Subarray starts From index %d and ends on index %d\n", start, end);
    return maxSum;
}

int main()
{
    int D[] = {2, -5, -6, 4, 3, -9, -2, -3, 5, 7, 8, -2};

    printf("Maximum Sum Of Subarray will be: %d", kadanes(D, 12));

    return 0;
}