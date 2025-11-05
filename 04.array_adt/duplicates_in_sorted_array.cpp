// Finding Duplicates In Sorted Array
#include <stdio.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void findDuplicates(struct Array arr)
{
    int lastDuplicate = 0;
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] == arr.A[i + 1] && arr.A[i] != lastDuplicate)
        {
            printf("%d is Duplicate value\n", arr.A[i]);
            lastDuplicate = arr.A[i];
        }
    }
}

void count(struct Array arr)
{
    int i, j;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] == arr.A[i + 1])
        {
            j = i;

            while (arr.A[j] == arr.A[i])
            {
                j++;
            }
            printf("%d appears %d times\n", arr.A[i], j - i);
            i = j - 1;
        }
    }
}

int main()
{
    struct Array arr = {{5, 5, 6, 7, 8, 9, 9, 9, 10, 11, 12, 12}, 15, 12};

    findDuplicates(arr);

    count(arr);

    return 0;
}