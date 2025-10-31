// Array ADT of fixed size
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

int main()
{
    struct Array arr = {{5, 6, 9, 2, 3}, 20, 5};
    display(arr);

    return 0;
}
