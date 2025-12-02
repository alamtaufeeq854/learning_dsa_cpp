// Circular Queue
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size + 1;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue Is Full");

    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;

    if (q->front == q->rear)
        printf("Queue Is Empty");

    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }

    return x;
}

void display(struct Queue q)
{
    if (q.front == q.rear)
        printf("Queue Is Empty");

    else
    {
        int i = q.front + 1;

        do
        {
            printf("%d ", q.Q[i]);
            i = (i + 1) % q.size;

        } while (i != (q.rear + 1) % q.size);

        printf("\n");
    }
}

int main()
{
    struct Queue q;

    create(&q, 6);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);

    display(q);

    printf("Deleted Element: %d\n", dequeue(&q));

    display(q);

    return 0;
}