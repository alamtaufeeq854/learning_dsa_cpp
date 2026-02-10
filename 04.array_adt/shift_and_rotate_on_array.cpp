// Shift And Rotate On Array

#include <stdio.h>

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

void leftShift(struct Array *arr)
{
    int i = 0;

    while (i < arr->length - 1)
    {
        arr->A[i] = arr->A[i + 1];
        i++;
    }

    arr->A[i] = 0;
}

void rightShift(struct Array *arr)
{
    int i = arr->length - 1;

    while (i > 0)
    {
        arr->A[i] = arr->A[i - 1];
        i--;
    }

    arr->A[i] = 0;
}

void leftRotate(struct Array *arr)
{
    int i = 0;
    int x = arr->A[i];

    while (i < arr->length - 1)
    {
        arr->A[i] = arr->A[i + 1];
        i++;
    }

    arr->A[i] = x;
}

void rightRotate(struct Array *arr)
{
    int i = arr->length - 1;

    int x = arr->A[i];

    while (i > 0)
    {
        arr->A[i] = arr->A[i - 1];
        i--;
    }

    arr->A[i] = x;
}

int main()
{
    struct Array arr = {{5, 2, 4, 8, 9, 3, 1, 4, 7, 4, 5, 6}, 15, 12};
    printf("\nOriginal Array Is: ");
    display(arr);

    printf("\nLeft Rotate On Array: ");
    leftRotate(&arr);
    display(arr);

    printf("\nRight Rotate On Array: ");
    rightRotate(&arr);
    display(arr);

    printf("\nLeft Shift On Array: ");
    leftShift(&arr);
    display(arr);

    printf("\nRight Shift On Array: ");
    rightShift(&arr);
    display(arr);

    return 0;
}