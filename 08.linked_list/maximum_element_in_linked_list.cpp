// Maximum Element In Linked List
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

int maximum(struct Node *p)
{
    int max = INT_MIN;

    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;

        p = p->next;
    }
    return max;
}

int main()
{
    int A[6] = {2, 9, 6, 7, 5, 1};

    create(A, 6);

    printf("\nMaximum element is: %d\n\n", maximum(first));

    return 0;
}