// to check loop in Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

} *first = NULL, *last = NULL;

void create(int *A, int n)
{
    struct Node *t;

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

int isLoop(struct Node *f)
{
    struct Node *p, *q;

    p = q = f;

    do
    {
        p = p->next;
        q = q->next;

        q = q ? q->next : q;
    } while (p && q && p != q);

    if (p == q)
        return 1;

    else
        return 0;
}

int main()
{

    int A[6] = {2, 9, 6, 7, 5, 1};

    create(A, 6);
    display(first);

    struct Node *t1, *t2;

    t1 = first;
    t2 = last;
    t2->next = t1;

    if (isLoop(first))
        printf("\nIt is a Loop");

    else
        printf("\nIt is not a Loop");

    return 0;
}