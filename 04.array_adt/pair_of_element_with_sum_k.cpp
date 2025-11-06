// Finding Pair Of Elements with sum K
#include <stdio.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void sum(struct Array arr, int k)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        for (int j = i + 1; j < arr.length; j++)
        {
            if (arr.A[i] + arr.A[j] == k)
            {
                printf("%d + %d = %d\n", arr.A[i], arr.A[j], k);
            }
        }
    }
}

int main()
{
    struct Array arr = {{5, 2, 4, 8, 9, 0, 1, 4, 7, 4, 5, 6}, 15, 12};

    sum(arr, 10);

    return 0;
}