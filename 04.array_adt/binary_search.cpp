// Binary Search
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

int binarySearch(struct Array arr, int key)
{
    int low = 0, mid, high = arr.length - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr.A[mid] == key)
        {
            printf("Element found at index: %d\n", mid);
            return mid;
        }
        else if (arr.A[mid] > key)
            high = mid - 1;

        else
            low = mid + 1;
    }
    printf("Element not found!\n");
    return -1;
}

int main()
{
    struct Array arr = {{1, 5, 8, 9, 10, 17, 23, 39}, 20, 8};
    binarySearch(arr, 9);
    display(arr);

    return 0;
}
