// Radix Sort

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};

int findMax(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
        if (A[i] > max)
            max = A[i];
    return max;
}

void binInsert(struct Node **bin, int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*bin == NULL)
        *bin = t;
    else
    {
        struct Node *p = *bin;
        while (p->next)
            p = p->next;
        p->next = t;
    }
}

int binDelete(struct Node **bin)
{
    struct Node *p = *bin;
    int x = p->data;
    *bin = p->next;
    free(p);
    return x;
}

void radixSort(int A[], int n)
{
    int i, j, k, pass, max;
    struct Node *bins[10];

    max = findMax(A, n);

    for (pass = 1; max / pass > 0; pass *= 10)
    {
        for (i = 0; i < 10; i++)
            bins[i] = NULL;

        for (i = 0; i < n; i++)
        {
            k = (A[i] / pass) % 10;
            binInsert(&bins[k], A[i]);
        }

        i = 0;
        j = 0;

        while (i < 10)
        {
            while (bins[i] != NULL)
                A[j++] = binDelete(&bins[i]);
            i++;
        }
    }
}

int main()
{
    int A[] = {174, 234, 394, 2339, 417, 389, 39, 5, 10, 4};
    int n = 10;

    radixSort(A, n);

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
