// Find Maximum & Minimum Element In a Array In Single Scan
#include <stdio.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void findMaxMin(struct Array arr)
{
    int max = arr.A[0], min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];

        else if (arr.A[i] < min)
            min = arr.A[i];
    }
    printf("Maximum is: %d\nMinimum is: %d\n", max, min);
}

int main()
{
    struct Array arr = {{58, 52, 53, 64, 25, 75, 26, 47, 68, 28, 19, 39}, 15, 12};

    findMaxMin(arr);

    return 0;
}