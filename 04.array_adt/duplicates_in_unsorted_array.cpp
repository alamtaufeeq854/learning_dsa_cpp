// Finding Duplicates In Unsorted Array
#include <stdio.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void findDuplicates(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        int count = 1;

        if (arr.A[i] != -1)
        {
            for (int j = i + 1; j < arr.length; j++)
            {
                if (arr.A[i] == arr.A[j])
                {
                    arr.A[j] = -1;
                    count++;
                }
            }
            if (count > 1)
                printf("%d appears %d times\n", arr.A[i], count);
        }
    }
}

int main()
{
    struct Array arr = {{5, 95, 16, 11, 8, 5, 95, 95, 10, 11, 16, 12}, 15, 12};

    findDuplicates(arr);

    return 0;
}