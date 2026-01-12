// Shell Sort

#include <stdio.h>
#include <stdlib.h>

void shellSort(int A[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;

            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }

            A[j + gap] = temp;
        }
    }
}

int main()
{
    int A[] = {10, 39, 17, 4, 23, 19, 24, 51, 9, 3}, n = 10, i;

    shellSort(A, n);

    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);

    printf("\n");

    return 0;
}