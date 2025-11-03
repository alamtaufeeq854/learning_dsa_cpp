// Rearrangement of an array
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

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void rearrange(struct Array *arr)
{
    int i = 0, j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;

        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

int main()
{
    struct Array arr = {{-15, 17, 8, -56, -87, 53, 29, -32, 43}, 20, 9};
    display(arr);
    printf("\n");
    rearrange(&arr);
    display(arr);
    return 0;
}
