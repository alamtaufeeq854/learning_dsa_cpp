// Insert for Linked List
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

int count(struct Node *p)
{
    int l = 0;

    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
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
    if (index < 0 || index > count(p))
        return;

    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }

    else if (index > 0)
    {
        p = first;

        for (int i = 0; i < index - 1; i++)
            p = p->next;

        t->next = p->next;
        p->next = t;
    }
}

int main()
{

    int A[6] = {2, 9, 6};

    create(A, 3);

    display(first);

    printf("\n");

    insert(first, 2, 7);

    display(first);

    return 0;
}