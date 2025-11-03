// Inserted Element In Sorted Position
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

void insert(struct Array *arr, int x)
{
    if (arr->length == arr->size)
    {
        return;
    }

    int i = arr->length - 1;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int main()
{
    struct Array arr = {{15, 17, 29, 32, 43}, 20, 5};
    display(arr);
    printf("\n");
    insert(&arr, 30);
    display(arr);
    return 0;
}
