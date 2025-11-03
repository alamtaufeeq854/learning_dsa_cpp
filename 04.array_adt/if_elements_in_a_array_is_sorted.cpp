// If Element in a Array is Sorted
#include <stdio.h>
#include <stdbool.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

int isSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            printf("FALSE ");
            return false;
        }
    }
    printf("TRUE ");
    return true;
}

int main()
{
    struct Array arr = {{15, 17, 29, 32, 43}, 20, 5};
    display(arr);
    printf("\n");
    isSorted(arr);
    return 0;
}
