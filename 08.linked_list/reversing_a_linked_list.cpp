// Reversing a Linked List
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

int count(struct Node *p)
{
    int l = 0;

    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

void reverse(struct Node *p)
{
    int *A, i = 0;

    A = (int *)malloc(count(p) * sizeof(int));
    while (p != NULL)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }

    p = first;
    i--;

    while (p != NULL)
    {
        p->data = A[i--];
        p = p->next;
    }
}

int main()
{

    int A[6] = {2, 12, 16, 19, 25, 31};

    create(A, 6);

    display(first);

    reverse(first);

    printf("\n");
    display(first);

    return 0;
}