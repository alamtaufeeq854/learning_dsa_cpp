// Insert In A Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;

} *first = NULL;

void create(int *A, int n)
{
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));

        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

int length(struct Node *p)
{
    int len = 0;

    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (index < 0 || index > length(p))
        return;

    if (index == 0)
    {
        t->data = x;
        t->prev = NULL;
        t->next = first;
        if (p)
            first->prev = t;
        first = t;
    }

    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;

        t->data = x;
        t->prev = p;

        t->next = p->next;

        if (t->next)
            p->next->prev = t;
        p->next = t;
    }
}

int main()
{

    int A[6] = {2, 9, 6, 7, 5, 1};

    create(A, 6);

    insert(first, 4, 8);

    display(first);

    return 0;
}