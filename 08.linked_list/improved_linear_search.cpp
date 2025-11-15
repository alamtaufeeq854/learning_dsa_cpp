// Improved Linear Search In Linked List
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

struct Node *linearSearch(struct Node *p, int key)
{
    struct Node *q = NULL;

    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;

            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

int main()
{

    struct Node *temp;

    int A[6] = {2, 9, 6, 7, 5, 1};

    create(A, 6);

    temp = linearSearch(first, 7);

    if (temp)
        printf("Element '%d' is found\n", temp->data);

    else
        printf("Element not found\n");

    return 0;
}