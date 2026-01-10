// Insertion Sort

#include <stdio.h>
#include <stdlib.h>

void insertion(int A[], int n)
{
    int i, j, x;

    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];

        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = x;
    }
}

int main()
{
    int A[] = {21, 39, 7, 2, 16, 19, 24, 51, 10, 3}, n = 10, i;

    insertion(A, n);

    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);

    printf("\n");

    return 0;
}