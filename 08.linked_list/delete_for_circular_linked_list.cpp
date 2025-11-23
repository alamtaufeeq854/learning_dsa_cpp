// Delete For Circular Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *Head;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *h)
{
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        display(h->next);
    }
    flag = 0;
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

int deleteElement(struct Node *p, int index)
{
    struct Node *q;
    int x;

    if (index < 1 || index > length(p))
        return -1;

    if (index == 1)
    {
        while (p->next != Head)
            p = p->next;

        if (p == Head)
        {
            x = p->data;
            free(p);
            Head = NULL;
        }

        else
        {
            p->next = Head->next;
            x = Head->data;
            free(Head);
            Head = p->next;
        }
    }

    else
    {
        for (int i = 0; i < index - 2; i++)
            p = p->next;

        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[] = {2, 3, 4, 5, 8};
    create(A, 5);
    deleteElement(Head, 3);
    display(Head);
    return 0;
}