// Maximum Element In Linked List By Recursion
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

int maxRecursive(struct Node *p)
{
    if (p == NULL)
        return INT_MIN;

    int x = maxRecursive(p->next);

    return (p->data > x) ? p->data : x;
}

int main()
{
    int A[6] = {2, 9, 6, 7, 5, 1};

    create(A, 6);

    printf("\nMaximum element is: %d\n\n", maxRecursive(first));

    return 0;
}