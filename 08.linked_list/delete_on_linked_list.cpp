// Delete On Linked List
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

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int deleteElement(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1;

    if (index < 1 || index > count(p))
        return -1;

    if (index == 1)
    {
        q = first;
        first = first->next;
        x = q->data;
        free(q);

        return x;
    }

    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;

        free(p);

        return x;
    }
}
int main()
{

    int A[6] = {2, 9, 6, 7, 5, 1};

    create(A, 6);

    display(first);

    deleteElement(first, 3);

    printf("\n");
    display(first);

    return 0;
}