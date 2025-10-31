// Array ADT of desired size
#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void display(struct Array arr)
{
    printf("\nElements of Array: ");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

int main()
{
    struct Array arr;
    printf("Enter Size of an Array: ");
    scanf("%d", &arr.size);

    arr.A = (int *)malloc(arr.size * sizeof(int));

    int n;
    printf("\nEnter number of numbers: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\n%d. Enter number: ", i + 1);
        scanf("%d", &arr.A[i]);
    }

    arr.length = n;

    display(arr);

    return 0;
}
