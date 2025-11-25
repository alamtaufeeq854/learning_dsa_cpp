#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL, *poly2 = NULL, *sumpoly = NULL;

void create()
{
    struct Node *t, *last;
    int num, i, m;

    printf("Enter number of terms: ");
    scanf("%d", &num);

    m = num - 1;

    for (i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter Coefficient of X^%d: ", m);
        scanf("%d", &t->coeff);
        t->exp = m--;
        t->next = NULL;

        if (poly == NULL)
        {
            poly = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void create2()
{
    struct Node *t, *last;
    int num, i, m;

    printf("Enter number of terms: ");
    scanf("%d", &num);

    m = num - 1;

    for (i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter Coefficient of X^%d: ", m);
        scanf("%d", &t->coeff);
        t->exp = m--;
        t->next = NULL;

        if (poly2 == NULL)
        {
            poly2 = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void display(struct Node *p)
{
    while (p)
    {
        printf("%dX^%d+", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

long eval(struct Node *p, int x)
{
    long val = 0;

    while (p)
    {
        val += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return val;
}

void add(struct Node *p, struct Node *q)
{
    struct Node *t, *last = NULL;
    sumpoly = NULL;

    while (p && q)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->next = NULL;

        if (p->exp == q->exp)
        {
            t->coeff = p->coeff + q->coeff;
            t->exp = p->exp;
            p = p->next;
            q = q->next;
        }
        else if (p->exp > q->exp)
        {
            t->coeff = p->coeff;
            t->exp = p->exp;
            p = p->next;
        }
        else
        {
            t->coeff = q->coeff;
            t->exp = q->exp;
            q = q->next;
        }

        if (sumpoly == NULL)
            sumpoly = last = t;
        else
        {
            last->next = t;
            last = t;
        }
    }

    while (p)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->coeff = p->coeff;
        t->exp = p->exp;
        t->next = NULL;

        last->next = t;
        last = t;
        p = p->next;
    }

    while (q)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->coeff = q->coeff;
        t->exp = q->exp;
        t->next = NULL;

        last->next = t;
        last = t;
        q = q->next;
    }
}

int main()
{
    printf("\nFor First Polynomial\n");
    create();

    printf("\nFor Second Polynomial\n");
    create2();

    add(poly, poly2);

    display(sumpoly);
    printf("\n");

    printf("Value is: %ld", eval(poly, 3));

    return 0;
}