// Double Hashing

#include <stdio.h>

int hash(int key)
{
    return key % 10;
}

int probe(int H[], int key)
{
    int index = hash(key);
    int i = 0;

    while (H[(index + i * (7 - key % 7)) % 10] != 0)
        i++;

    return (index + i * (7 - key % 7)) % 10;
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

    while (H[(index + i * (7 - key % 7)) % 10] != key)
        i++;

    return (index + i * (7 - key % 7)) % 10;
}

int main()
{

    int HT[10] = {0};

    int A[] = {174, 417, 423, 349, 107};
    int n = 5;

    for (int i = 0; i < n; i++)
        insert(HT, A[i]);

    printf("\nKey found at index: %d\n", search(HT, 107));

    return 0;
}