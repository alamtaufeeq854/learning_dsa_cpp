// AVL Trees
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
} *root = NULL;

int nodeHeight(struct Node *p)
{
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int balanceFactor(struct Node *p)
{
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

struct Node *LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if (root == p)
        root = pl;

    return pl;
}

struct Node *LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);

    if (root == p)
        root = plr;

    return plr;
}

struct Node *RRRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);

    if (root == p)
        root = pr;

    return pr;
}

struct Node *RLRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;

    prl->lchild = p;
    prl->rchild = pr;

    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);
    prl->height = nodeHeight(prl);

    if (root == p)
        root = prl;

    return prl;
}

struct Node *insertNode(struct Node *p, int key)
{
    if (p == NULL)
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
        p->lchild = insertNode(p->lchild, key);
    else if (key > p->data)
        p->rchild = insertNode(p->rchild, key);

    p->height = nodeHeight(p);

    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return LLRotation(p);

    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return LRRotation(p);

    if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
        return RRRotation(p);

    if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return RLRotation(p);

    return p;
}

void display(struct Node *p)
{
    if (p)
    {
        display(p->lchild);
        printf("%d ", p->data);
        display(p->rchild);
    }
}

int main()
{
    root = insertNode(root, 50);
    insertNode(root, 10);
    insertNode(root, 20);

    display(root);

    return 0;
}
