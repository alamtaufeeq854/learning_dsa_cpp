// Minimum Element In Linked List

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

} *first = NULL;

void create(int *A, int n)
{
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));

    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int minimum(struct Node *p)
{
    int min = INT_MAX;

    while (p != NULL)
    {
        if (p->data < min)
            min = p->data;

        p = p->next;
    }
    return min;
}

int main()
{
    int A[6] = {21, 9, 6, 7, 5, 11};

    create(A, 6);

    printf("\nMinimum element is: %d\n\n", minimum(first));

    return 0;
}
