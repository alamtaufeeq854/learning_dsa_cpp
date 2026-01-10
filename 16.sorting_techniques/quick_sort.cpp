// Quick Sort

#include <stdio.h>

void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do
        {
            i++;

        } while (A[i] <= pivot);

        do
        {
            j--;

        } while (A[j] > pivot);

        if (i < j)
            swap(&A[i], &A[j]);

    } while (i < j);

    swap(&A[l], &A[j]);

    return j;
}

void quickSort(int A[], int l, int h)
{

    int j;

    if (l < h)
    {
        j = partition(A, l, h);

        quickSort(A, l, j);
        quickSort(A, j + 1, h);
    }
}

int main()
{
    int A[] = {21, 39, 7, 2, 16, 19, 24, 51, 10, 3, __INT32_MAX__}, n = 11, i;

    quickSort(A, 0, 10);

    for (int i = 0; i < 10; i++)
        printf("%d ", A[i]);

    printf("\n");

    return 0;
}