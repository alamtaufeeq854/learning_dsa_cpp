// Quadratic Probing

#include <stdio.h>

int hash(int key)
{
    return key % 10;
}

int probe(int H[], int key)
{
    int index = hash(key);
    int i = 0;

    while (H[(index + i * i) % 10] != 0)
        i++;

    return (index + i * i) % 10;
}

void insert(int H[], int key)
{
    int index = hash(key);

    if (H[index] != 0)
        index = probe(H, key);

    H[index] = key;
}

int search(int H[], int key)
{

    int index = hash(key);

    int i = 0;

    while (H[(index + i * i) % 10] != key)
        i++;

    return (index + i * i) % 10;
}

int main()
{

    int HT[10] = {0};

    int A[] = {17, 4, 23, 39, 10};
    int n = 5;

    for (int i = 0; i < n; i++)
        insert(HT, A[i]);

    printf("\nKey found at index: %d\n", search(HT, 17));

    return 0;
}