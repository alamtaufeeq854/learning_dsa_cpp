// Linear Search By Move To Head
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

int linearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            printf("Element found at index: %d\n", i);
            if (i > 0)
                swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    printf("Element not found!\n");
    return -1;
}

int main()
{
    struct Array arr = {{5, 6, 9, 2, 3}, 20, 5};
    linearSearch(&arr, 9);
    display(arr);

    return 0;
}
