// Intersection Of Sorted Array
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

struct Array *arrayIntersection(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    int i = 0, j = 0, k = 0;

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            i++;
        }

        else if (arr1->A[i] > arr2->A[j])
        {
            j++;
        }

        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

int main()
{
    struct Array arr1 = {{13, 20, 54, 76, 99}, 20, 5};
    struct Array arr2 = {{13, 19, 20, 28, 76}, 20, 5};

    struct Array *arr3 = arrayIntersection(&arr1, &arr2);

    display(*arr3);

    return 0;
}
