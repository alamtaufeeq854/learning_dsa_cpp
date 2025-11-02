// Reverse Array
#include <stdio.h>
#include <stdlib.h>

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

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(struct Array *arr)
{
    int *B, i, j;
    B = (int *)malloc(arr->length * sizeof(int));

    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }

    for (i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void reverse2(struct Array *arr)
{
    int i, j;

    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

int main()
{
    struct Array arr = {{5, 6, 9, 2, 3}, 20, 5};
    display(arr);
    printf("\n");
    reverse(&arr);
    display(arr);
    printf("\n");
    reverse2(&arr);
    display(arr);

    return 0;
}
