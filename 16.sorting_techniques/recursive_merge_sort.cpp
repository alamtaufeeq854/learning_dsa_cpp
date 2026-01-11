// Recursive Merge Sort

#include <stdio.h>

void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];

        else
            B[k++] = A[j++];
    }

    for (; i <= mid; i++)
        B[k++] = A[i];

    for (; j <= h; j++)
        B[k++] = A[j];

    for (i = l; i <= h; i++)
        A[i] = B[i];
}

void mergeSort(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;

        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

int main()
{
    int A[] = {21, 39, 7, 4, 17, 19, 24, 51, 10, 3}, n = 10, i;

    mergeSort(A, 0, n - 1);

    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);

    printf("\n");

    return 0;
}