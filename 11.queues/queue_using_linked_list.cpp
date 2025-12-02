// Node Using Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(struct Node *q, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("Queue Is Full");

    else
    {
        t->data = x;
        t->next = NULL;

        if (front == NULL)
            front = rear = t;

        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue(struct Node *q)
{
    int x = -1;

    if (front == NULL)
        printf("Queue Is Empty");

    else
    {
        struct Node *t;
        t = (struct Node *)malloc(sizeof(struct Node));

        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }

    return x;
}

void display(struct Node q)
{
    if (front == NULL)
        printf("Queue Is Empty");

    else
    {

        struct Node *t;
        t = (struct Node *)malloc(sizeof(struct Node));
        t = front;

        while (t)
        {
            printf("%d ", t->data);
            t = t->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Node q;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(q);

    printf("Deleted Element: %d\n", dequeue(&q));

    display(q);

    return 0;
}