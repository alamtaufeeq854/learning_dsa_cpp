// Binary Search Tree
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void insert(int key)
{
    struct Node *t = root;
    struct Node *p, *r = NULL;

    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while (t != NULL)
    {
        r = t;
        if (key > t->data)
            t = t->rchild;

        else if (key < t->data)
            t = t->lchild;

        else
            return;
    }

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key > r->data)
        r->rchild = p;

    else
        r->lchild = p;
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

struct Node *search(int key)
{
    struct Node *t = root;

    while (t != NULL)
    {
        if (key > t->data)
            t = t->rchild;

        else if (key < t->data)
            t = t->lchild;

        else
            return t;
    }
    return NULL;
}

int main()
{
    insert(4);
    insert(17);
    insert(23);
    insert(10);
    insert(39);
    insert(28);

    printf("\nIn Order: ");
    inorder(root);

    struct Node *temp;

    temp = search(39);

    if (temp != NULL)
        printf("\nElement '%d' is found\n", temp->data);

    else
        printf("\nElement is not found\n");

    return 0;
}
