// 2D Array Partially In Stack And Heap
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *A[3];

    A[0] = (int *)malloc(4 * sizeof(int));
    A[1] = (int *)malloc(4 * sizeof(int));
    A[2] = (int *)malloc(4 * sizeof(int));

    // Array of garbage values
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // Free heap memory
    for (int i = 0; i < 3; i++)
        free(A[i]);

    return 0;
}