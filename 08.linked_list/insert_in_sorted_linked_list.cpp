// Insert In Sorted Linked List
#include <stdio.h>
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

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void insertSorted(struct Node *p, int x)
{
    struct Node *q = NULL, *t;

    t = (struct Node *)malloc(sizeof(struct Node));

    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
        return;
    }

    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        if (p == first)
        {
            t->next = first;
            first = t;
        }

        else
        {
            t->next = p;
            q->next = t;
        }
    }
}

int main()
{

    int A[] = {3, 5, 7, 8, 10, 12};

    create(A, 6);

    display(first);

    insertSorted(first, 2);
    insertSorted(first, 13);
    insertSorted(first, 9);

    printf("\n\n");
    display(first);

    return 0;
}