// Finding Pair Of Elements with sum K By Hash Table
#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

int max(struct Array arr)
{
    int max = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

void sum(struct Array arr, int k)
{
    int high = max(arr);
    int *h = (int *)calloc(high + 1, sizeof(int));

    for (int i = 0; i < arr.length; i++)
    {
        if (h[k - arr.A[i]] != 0 && h[k - arr.A[i]] > 0)
        {
            printf("%d + %d = %d\n", k - arr.A[i], arr.A[i], k);
        }
        h[arr.A[i]]++;
    }
    free(h);
}

int main()
{
    struct Array arr = {{5, 2, 4, 8, 9, 3, 1, 4, 7, 4, 5, 6}, 15, 12};

    sum(arr, 10);

    return 0;
}