// Chaining

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void sortedInsert(struct Node **H, int x)
{
    struct Node *t, *q = NULL, *p = *H;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
        *H = t;

    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

struct Node *search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

int hash(int key)
{
    return key % 10;
}

void insert(struct Node *H[], int key)
{
    int index = hash(key);
    sortedInsert(&H[index], key);
}

int main()
{
    int A[] = {11, 2, 17, 21, 17, 7, 92, 39, 39, 5, 10, 4};
    int n = 12;

    struct Node *HT[10];
    struct Node *temp;

    int i;

    for (i = 0; i < 10; i++)
        HT[i] = NULL;

    for (i = 0; i < n; i++)
        insert(HT, A[i]);

    temp = search(HT[hash(4)], 4);

    if (temp)
        printf("%d ", temp->data);

    return 0;
}