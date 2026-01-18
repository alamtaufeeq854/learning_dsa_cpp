// Breadth First Search

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
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

int dequeue()
{
    int x = -1;
    struct Node *t;

    if (front != NULL)
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
        if (front == NULL)
            rear = NULL;
    }
    return x;
}

int isEmpty()
{
    return front == NULL;
}

void BFS(int G[][7], int start, int n)
{
    int visited[7] = {0};
    int i = start, j;

    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();
        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

int main()
{
    int G[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    BFS(G, 4, 7);
    return 0;
}
