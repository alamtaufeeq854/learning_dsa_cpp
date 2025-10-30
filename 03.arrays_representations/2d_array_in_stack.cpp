// 2D Array In Stack
#include <stdio.h>

int main()
{
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {3, 6, 7, 9}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}