// Insert In Circular Linked List
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

int insert(struct Node *p, int index, int x)
{
    if (index < 0 || index > length(p))
        return 0;

    struct Node *t;

    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;

        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }

        else
        {
            while (p->next != Head)
                p = p->next;

            p->next = t;
            t->next = Head;
            Head = t;
        }
    }

    else
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;

        for (int i = 0; i < index - 1; i++)
            p = p->next;

        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int A[] = {2, 3, 4, 5, 8};
    create(A, 5);

    insert(Head, 0, 9);
    insert(Head, 3, 7);
    insert(Head, 7, 1);

    display(Head);
    return 0;
}