// Sum Of All Elements In Linked List
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

int sum(struct Node *p)
{
    int sum = 0;

    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int main()
{

    int A[] = {2, 9, 6, 7, 5, 1, 4, 3, 8};

    create(A, 9);

    printf("\nSum is %d\n ", sum(first));

    return 0;
}