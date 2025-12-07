// Level Order Traversals
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

struct Stack
{
    int size;
    int top;
    struct Node **s;
};

void create(struct Stack *st, int stackSize)
{
    st->size = stackSize;
    st->top = -1;
    st->s = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow\n");

    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;
    if (st->top == -1)
        printf("Stack Underflow\n");

    else
        x = st->s[st->top--];

    return x;
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;

    else
        return 0;
}

void create(struct Queue *q, int size)
{
    q->size = size + 1;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue Is Full");

    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;

    if (q->front == q->rear)
        printf("Queue Is Empty");

    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }

    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}

struct Node *root = NULL;

void treeCreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of '%d': ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of '%d': ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct
                                             Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void iterativePreorder(Node *p)
{
    struct Stack st;
    create(&st, 100);

    while (p != NULL || !isEmpty(st))
    {
        if (p)
        {
            printf("%d ", p->data);
            push(&st, p);
            p = p->lchild;
        }

        else
        {
            p = pop(&st);
            p = p->rchild;
        }
    }
}

void iterativeInorder(Node *p)
{
    struct Stack st;
    create(&st, 100);

    while (p != NULL || !isEmpty(st))
    {
        if (p)
        {
            push(&st, p);
            p = p->lchild;
        }

        else
        {
            p = pop(&st);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void levelOrder(struct Node *root)
{
    struct Queue q;
    create(&q, 100);

    printf("%d ", root->data);
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        root = dequeue(&q);
        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if (root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

int main()
{
    treeCreate();
    printf("\nLevel Order ");
    levelOrder(root);

    return 0;
}
