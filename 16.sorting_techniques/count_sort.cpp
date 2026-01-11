// Count Sort

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int findMax(int A[], int n)
{
    int max = INT_MIN;
    int i;

    for (i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void countSort(int A[], int n)
{
    int i, j, max, *C;

    max = findMax(A, n);

    C = (int *)malloc(sizeof(int) * (max + 1));

    for (i = 0; i <= max; i++)
        C[i] = 0;

    for (i = 0; i < n; i++)
        C[A[i]]++;

    i = 0, j = 0;

    while (i <= max)
    {
        if (C[i] > 0)
        {
            A[j++] = i;
            C[i]--;
        }

        else
            i++;
    }

    free(C);
}

int main()
{
    int A[] = {11, 2, 17, 12, 17, 39, 39, 5, 10, 4}, n = 10, i;

    countSort(A, n);

    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);

    printf("\n");

    return 0;
}