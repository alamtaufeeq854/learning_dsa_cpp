// Middle Node Of Linked List
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
    int mid;
    if (length(p) > 1)
    {
        if (length(p) % 2 != 0)
        {
            mid = (length(p) + 1) / 2;

            for (int i = 0; i < mid - 1; i++)
                p = p->next;

            printf("Middle Element is: %d\n", p->data);
        }

        else
        {
            mid = length(p) / 2;

            for (int i = 0; i < mid - 1; i++)
                p = p->next;

            printf("Middle Element is: %d\n", p->data);
            p = p->next;
            printf("Middle Element is: %d\n", p->data);
        }
    }
    else if (length(p) == 1)
        printf("Middle Element is: %d\n", p->data);

    else
        return 0;
}
int main()
{

    int A[7] = {2, 9, 6, 7, 5, 1, 8};

    create(A, 7);

    display(first);

    middle(first);
    return 0;
}