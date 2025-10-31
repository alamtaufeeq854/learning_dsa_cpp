// Inserting in an array
#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

void append(struct Array *arr, int x)
{
    arr->A[arr->length++] = x;
}

void insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;

        arr->length++;
    }
}
int main()
{
    struct Array arr = {{5, 6, 9, 2, 3}, 20, 5};

    append(&arr, 39);

    insert(&arr, 3, 17);

    display(arr);

    return 0;
}
