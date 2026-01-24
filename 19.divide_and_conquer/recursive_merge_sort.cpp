// Recursive Merge Sort

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

        else
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

void recursive_Merge_Sort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        recursive_Merge_Sort(A, low, mid);
        recursive_Merge_Sort(A, mid + 1, high);
        mergeSort(A, low, mid, high);
    }
}

int main()
{
    int A[] = {4, 52, 12, 33, 49, 66, 45, 72, 29, 35, 47, 8, 65, 99, 19, 63};

    recursive_Merge_Sort(A, 0, 15);

    for (int i = 0; i < (sizeof(A) / sizeof(A[0])); i++)
        printf(" %d", A[i]);

    return 0;
}