// arrayUnion Of Sorted Array
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

struct Array *arrayUnion(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    int i = 0, j = 0, k = 0;

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }

        else if (arr1->A[i] > arr2->A[j])
        {
            arr3->A[k++] = arr2->A[j++];
        }

        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    for (; i < arr1->length;)
        arr3->A[k++] = arr1->A[i++];

    for (; j < arr2->length;)
        arr3->A[k++] = arr2->A[j++];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

int main()
{
    struct Array arr1 = {{13, 20, 54, 76, 99}, 20, 5};
    struct Array arr2 = {{13, 19, 20, 28, 76}, 20, 5};

    struct Array *arr3 = arrayUnion(&arr1, &arr2);

    display(*arr3);

    return 0;
}
