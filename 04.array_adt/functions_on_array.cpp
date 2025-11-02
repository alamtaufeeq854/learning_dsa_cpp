// Functions On Array
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

int get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
}

void set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
}

int max(struct Array arr)
{
    int max = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int min(struct Array arr)
{
    int min = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int sum(struct Array arr)
{
    int sum = 0;

    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

float avg(struct Array arr)
{
    return (float)sum(arr) / arr.length;
}

int main()
{
    struct Array arr = {{5, 6, 9, 2, 3}, 20, 5};

    printf("%d\n", get(arr, 3));

    printf("%d\n", max(arr));

    printf("%d\n", min(arr));

    printf("%d\n", sum(arr));

    printf("%f\n", avg(arr));

    set(&arr, 2, 27);

    display(arr);

    return 0;
}
