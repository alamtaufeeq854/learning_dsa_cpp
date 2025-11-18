// Concatenate Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

} *first = NULL, *second = NULL, *third = NULL;

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

void create2(int *A, int n)
{
    struct Node *t, *last;

    second = (struct Node *)malloc(sizeof(struct Node));

    second->data = A[0];
    second->next = NULL;
    last = second;

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

void concate(struct Node *p, struct Node *q)
{
    third = p;

    while (p->next != NULL)
        p = p->next;

    p->next = q;
}

int main()
{

    int A[6] = {2, 9, 6, 7, 5, 1};
    create(A, 6);
    printf("\n");
    display(first);

    int B[6] = {32, 29, 96, 47, 75, 21};
    create2(B, 6);
    printf("\n");
    display(second);

    concate(first, second);
    printf("\n");
    display(third);

    return 0;
}