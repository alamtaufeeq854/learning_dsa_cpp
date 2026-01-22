// Iterative Merge Sort

#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;

    int *B = (int *)malloc((h + 1) * sizeof(int));

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];

        else if (A[i] > A[j])
            B[k++] = A[j++];
    }
    for (; i <= mid;)
        B[k++] = A[i++];

    for (; j <= h;)
        B[k++] = A[j++];

    for (i = l; i <= h; i++)
        A[i] = B[i];

    free(B);
}

void mergeSort(int A[], int n)
{
    int lastSize = 0;
    for (int size = 1; size <= n / 2; size *= 2)
    {
        lastSize = size;

        for (int low = 0, high = 2 * size - 1; high <= n - 1; low = high + 1, high = low + 2 * size - 1)
        {
            merge(A, low, (low + high) / 2, high);
        }
    }

    if (2 * lastSize < n)
        merge(A, 0, 2 * lastSize - 1, n - 1);
}

int main()
{
    int A[] = {4, 23, 12, 63, 49, 56, 55, 72, 29, 5, 35, 47, 8, 65, 99, 77};

    mergeSort(A, (sizeof(A) / sizeof(A[0])));

    for (int i = 0; i < (sizeof(A) / sizeof(A[0])); i++)
        printf(" %d", A[i]);

    return 0;
}
