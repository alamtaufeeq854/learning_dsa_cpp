// Reverse For Doubly Linked List
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

void reverse(struct Node *p)
{
    struct Node *temp;

    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
            first = p;
    }
}

int main()
{

    int A[6] = {2, 9, 6, 7, 5, 1};

    create(A, 6);

    reverse(first);

    display(first);

    return 0;
}