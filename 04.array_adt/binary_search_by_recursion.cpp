// Binary Search By Recursion
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

int recursionBinarySearch(int A[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;

        if (A[mid] == key)
        {
            printf("Element found at index: %d\n", mid);
            return mid;
        }
        else if (A[mid] > key)
            return recursionBinarySearch(A, low, mid - 1, key);

        else
            return recursionBinarySearch(A, mid + 1, high, key);
    }
    printf("Element not found!\n");
    return -1;
}

int main()
{
    struct Array arr = {{1, 5, 8, 9, 10, 17, 23, 39}, 20, 8};
    recursionBinarySearch(arr.A, 0, arr.length - 1, 9);
    display(arr);

    return 0;
}
