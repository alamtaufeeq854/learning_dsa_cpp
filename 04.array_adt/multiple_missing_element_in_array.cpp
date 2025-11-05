// Finding Multiple Missing Element In a Array
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
            while (difference < arr.A[i] - i)
            {
                printf("Missing element: %d\n", difference + i);
                difference++;
            }
        }
    }
}

int main()
{
    struct Array arr = {{6, 7, 8, 9, 11, 15, 16, 17, 18, 19, 20}, 15, 11};

    findMissing(arr);

    return 0;
}