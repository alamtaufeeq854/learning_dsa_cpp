// Check If Linked List Is Sorted
#include <stdio.h>
#include <limits.h>
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

int isSorted(struct Node *p)
{
    int x = INT_MIN;

    while (p != NULL)
    {
        if (p->data < x)
            return false;

        x = p->data;
        p = p->next;
    }

    return true;
}

int main()
{

    int A[6] = {2, 9, 16, 17, 25, 31};

    create(A, 6);

    display(first);

    if (isSorted(first))
        printf(" is Sorted\n");

    else
        printf(" is not Sorted\n");

    return 0;
}