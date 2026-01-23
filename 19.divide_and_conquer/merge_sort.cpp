// Merge Sort

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int A[], int l, int mid, int h)
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

int main()
{
    int A[] = {4, 12, 33, 49, 66, 72, 29, 35, 47, 65, 99};

    mergeSort(A, 0, 5, 10);

    for (int i = 0; i < (sizeof(A) / sizeof(A[0])); i++)
        printf(" %d", A[i]);

    return 0;
}