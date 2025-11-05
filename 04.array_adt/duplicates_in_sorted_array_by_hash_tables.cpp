// Finding Duplicates In Sorted Array By Hash Tables
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

int min(struct Array arr)
{
    int min = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

void findDuplicates(struct Array arr)
{
    int high = max(arr);
    int low = min(arr);

    int *h = (int *)calloc(high + 1, sizeof(int));

    for (int i = 0; i < arr.length; i++)
    {
        h[arr.A[i]]++;
    }

    for (int i = low; i <= high; i++)
    {
        if (h[i] > 1)
        {
            printf("%d appears %d times\n", i, h[i]);
        }
    }
    free(h);
}

int main()
{
    struct Array arr = {{5, 5, 6, 7, 8, 9, 9, 9, 10, 11, 12, 12}, 15, 12};

    findDuplicates(arr);

    return 0;
}