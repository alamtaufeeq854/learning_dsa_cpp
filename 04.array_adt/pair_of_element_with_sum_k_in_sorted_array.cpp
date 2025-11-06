// Pair Of Elements with sum K In Sorted Array
#include <stdio.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void sum(struct Array arr, int k)
{
    int i = 0, j = arr.length - 1;
    while (i < j)
    {
        if (arr.A[i] + arr.A[j] > k)
            j--;

        else if (arr.A[i] + arr.A[j] < k)
            i++;

        else
        {
            printf("%d + %d = %d\n", arr.A[i], arr.A[j], k);
            i++;
            j--;
        }
    }
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 5, 6, 7, 8, 8, 9, 9}, 15, 12};

    sum(arr, 10);

    return 0;
}