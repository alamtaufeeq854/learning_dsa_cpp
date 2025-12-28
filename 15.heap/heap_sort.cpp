// Heap Sort
#include <stdio.h>

void insert(int A[], int n)
{
    int temp, i = n;
    temp = A[n];

    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }

    A[i] = temp;
}

int deleted(int A[], int n)
{
    int x, temp, val, i, j;

    x = A[n];
    val = A[1];
    A[1] = A[n];
    A[n] = val;

    i = 1;
    j = 2 * i;

    while (j <= n - 1)
    {
        if (j < n - 1 && A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    return val;
}

int main()
{
    int H[] = {0, 2, 5, 8, 6, 4, 7, 1};

    int i;

    for (i = 2; i <= 7; i++)
        insert(H, i);

    printf("Elements in Heap: ");
    for (i = 1; i <= 7; i++)
        printf("%d ", H[i]);

    printf("\n");

    for (i = 7; i > 1; i--)
    {
        deleted(H, i);
    }

    for (i = 1; i <= 7; i++)
        printf("Element Deleted: %d \n", H[i]);
    printf("\n");

    return 0;
}