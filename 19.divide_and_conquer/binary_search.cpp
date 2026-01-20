// Binary Search Using Divide And Conquer

#include <stdio.h>

int binarySearch(int A[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (A[mid] == key)
        return mid;

    else if (key < A[mid])
        return binarySearch(A, low, mid - 1, key);

    else
        return binarySearch(A, mid + 1, high, key);
}

int main()
{
    int A[] = {4, 12, 36, 59, 66, 72, 79, 89, 92, 95, 99};

    int index = binarySearch(A, 0, 10, 72);

    if (index != -1)
        printf("Element is found at index %d", index);

    return 0;
}