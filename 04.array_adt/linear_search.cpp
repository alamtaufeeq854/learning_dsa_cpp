// Linear Search
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

int linearSearch(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)
        {
            printf("Element found at index: %d\n", i);
            return i;
        }
    }
    printf("Element not found!\n");
    return -1;
}

int main()
{
    struct Array arr = {{5, 6, 9, 2, 3}, 20, 5};
    linearSearch(arr, 9);
    display(arr);

    return 0;
}
