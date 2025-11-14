// Sum Of All Elements In Linked List By Recursion
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

int sumByRecursion(struct Node *p)
{

    if (p)
        return p->data + sumByRecursion(p->next);

    else
        return 0;
}

int main()
{

    int A[] = {2, 9, 6, 7, 5, 1, 3, 8};

    create(A, 8);

    printf("\nSum is %d\n ", sumByRecursion(first));

    return 0;
}