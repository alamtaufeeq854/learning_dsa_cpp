// Insert at Last In Linked List
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

void lastInsert(struct Node *p, int x)
{
    struct Node *t, *last;

    last = (struct Node *)malloc(sizeof(struct Node));
    t = (struct Node *)malloc(sizeof(struct Node));

    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;

    else
    {
        last = p;
        while (last->next)
            last = last->next;

        last->next = t;
        last = t;
    }
}

int main()
{

    int A[6] = {2, 9, 6, 7, 5, 1};

    create(A, 6);

    display(first);

    lastInsert(first, 4);

    printf("\n");
    display(first);

    return 0;
}