// Selection Sort

#include <stdio.h>

void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int A[], int n)
{
    int i, j, k;

    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
                k = j;
        }

        swap(&A[i], &A[k]);
    }
}

int main()
{
    int A[] = {73, 59, 79, 24, 1, 19, 43, 51, 10, 3}, n = 10;

    selectionSort(A, n);

    for (int i = 0; i < 10; i++)
        printf("%d ", A[i]);

    printf("\n");

    return 0;
}
