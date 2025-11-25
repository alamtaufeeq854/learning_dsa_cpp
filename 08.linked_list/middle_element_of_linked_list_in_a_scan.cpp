// Middle Node Of Linked List In A Scan
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
    printf("\n");
}

int length(struct Node *p)
{
    int l = 0;

    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

int middle(struct Node *p)
{
    struct Node *q;
    int mid = length(p);
    p = q = first;

    while (q)
    {
        q = q->next;
        if (q)
            q = q->next;
        if (q)
            p = p->next;
    }
    if (mid == 1)
        printf("Middle Element is: %d\n", p->data);

    else if (mid % 2 != 0)
        printf("Middle Element is: %d\n", p->data);

    else
    {
        printf("Middle Element is: %d\n", p->data);
        p = p->next;
        printf("Middle Element is: %d\n", p->data);
    }
}
int main()
{

    int A[8] = {2, 9, 6, 7, 5, 1, 8, 4};

    create(A, 8);

    display(first);

    middle(first);
    return 0;
}