// Finding Multiple Missing Element In a Array By Hash Table
#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[15];
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

void findMissing(struct Array arr)
{
    int lower = min(arr);
    int high = max(arr);

    int *arr2 = (int *)calloc(high + 1, sizeof(int));

    for (int i = 0; i < arr.length; i++)
    {
        arr2[arr.A[i]]++;
    }

    for (int i = lower; i <= high; i++)
    {
        if (arr2[i] == 0)
        {
            printf("Missing element: %d\n", i);
        }
    }
}

int main()
{
    struct Array arr = {{6, 7, 8, 9, 11, 15, 16, 17, 18, 19, 20}, 15, 11};

    findMissing(arr);

    return 0;
}