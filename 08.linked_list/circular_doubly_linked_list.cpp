// Circular Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;

} *Head = NULL, *last = NULL;

void create(int *A, int n)
{
    struct Node *t;

    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->prev = Head;
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));

        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        Head->prev = t;
        last = t;
    }
}

int length(struct Node *p)
{
    int len = 0;

    do
    {
        len++;
        p = p->next;
    } while (p != Head);

    return len;
}

void display(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != Head);
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
        t->prev = last;
        t->next = Head;

        if (p)
        {
            last->next = t;
            Head->prev = t;
        }

        Head = t;
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

int deleteElement(struct Node *p, int index)
{
    int x, i;

    if (index < 1 || index > length(p))
        return -1;

    if (index == 1)
    {
        x = Head->data;

        if (Head == last)
        {
            free(Head);
            Head = last = NULL;
        }

        else
        {
            last->next = Head->next;
            Head->next->prev = last;
            struct Node *t = Head;
            Head = Head->next;
            free(t);
        }
    }

    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;

        x = p->data;

        p->next->prev = p->prev;
        p->prev->next = p->next;

        free(p);
    }
    return x;
}

int main()
{
    int A[6] = {2, 9, 6, 7, 5, 1};

    create(A, 6);
    display(Head);

    printf("\nDeleted Element: %d\n", deleteElement(Head, 4));

    display(Head);

    return 0;
}