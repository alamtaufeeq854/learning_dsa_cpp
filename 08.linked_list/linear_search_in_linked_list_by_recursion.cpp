// Linear Search In Linked List By Recursion
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

struct Node *linearSearchRecursion(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;

    else if (p->data == key)
        return p;

    return linearSearchRecursion(p->next, key);
}

int main()
{
    struct Node *temp;

    int A[6] = {2, 9, 6, 7, 5, 1};

    create(A, 6);

    temp = linearSearchRecursion(first, 7);

    if (temp)
        printf("Element '%d' is found\n", temp->data);

    else
        printf("Element not found\n");

    return 0;
}