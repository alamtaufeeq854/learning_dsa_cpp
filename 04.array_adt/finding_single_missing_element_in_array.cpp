// Finding Single Missing Element In a Array
#include <stdio.h>

struct Array
{
    int A[15];
    int size;
    int length;
};

int findMissing(struct Array arr)
{
    int lower = arr.A[0];
    int difference = lower - 0;

    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] - i != difference)
        {
            printf("Element '%d' is missing at index %d\n", i + difference, i);
            return i;
        }
    }
}

int main()
{
    struct Array arr = {{6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17}, 15, 11};

    findMissing(arr);

    return 0;
}