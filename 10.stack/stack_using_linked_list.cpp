// Stack Using Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

int push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
    {
        printf("Stack Overflow");
        return -1;
    }

    else
    {
        t->data = x;
        t->next = top;
        top = t;
        return 1;
    }
}

int pop()
{
    int x = -1;

    if (top == NULL)
    {
        printf("Stack Is Empty");
        return x;
    }

    else
    {
        struct Node *t;

        x = top->data;
        t = top;
        top = top->next;
        free(t);
    }

    return x;
}

void display()
{
    if (top == NULL)
        printf("Stack Is Empty");

    else
    {
        struct Node *t;
        t = top;

        while (t)
        {
            printf("%d ", t->data);
            t = t->next;
        }
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    printf("\nElement Deleted: ");
    printf("%d \n", pop());

    display();

    return 0;
}