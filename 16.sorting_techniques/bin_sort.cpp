// Bin Sort

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

void binSort(int A[], int n)
{
    int i, j, max;
    struct Node **bins;

    max = findMax(A, n);
    bins = (struct Node **)malloc(sizeof(struct Node *) * (max + 1));

    for (i = 0; i <= max; i++)
        bins[i] = NULL;

    for (i = 0; i < n; i++)
        binInsert(&bins[A[i]], A[i]);

    i = 0;
    j = 0;

    while (i <= max)
    {
        while (bins[i] != NULL)
            A[j++] = binDelete(&bins[i]);
        i++;
    }

    free(bins);
}

int main()
{
    int A[] = {11, 2, 17, 12, 17, 39, 39, 5, 10, 4};
    int n = 10;

    binSort(A, n);

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
