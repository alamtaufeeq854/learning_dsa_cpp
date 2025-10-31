// Deleting From Array
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

int del(struct Array *arr, int index)
{
    if (index >= 0 && index < arr->length)
    {
        int x = arr->A[index];

        for (int i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;

        return x;
    }
    return 0;
}

int main()
{
    struct Array arr = {{5, 6, 9, 2, 3}, 20, 5};
    display(arr);
    printf("\n");
    del(&arr, 2);

    display(arr);

    return 0;
}
