// Polynomial Representation
#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Polynomial
{
    int n;
    struct Term *poly;
};

void create(struct Polynomial *p)
{
    printf("Enter Number Of Non-Zeroes Terms: ");
    scanf("%d", &p->n);

    p->poly = (struct Term *)malloc(p->n * sizeof(struct Term));

    for (int i = 0; i < p->n; i++)
    {
        printf("Enter Exponent of X: ");
        scanf("%d", &p->poly[i].exp);

        printf("Enter coefficient of X^%d: ", p->poly[i].exp);
        scanf("%d", &p->poly[i].coeff);
    }
    printf("\n");
}

void display(struct Polynomial p)
{
    for (int i = 0; i < p.n; i++)
    {
        printf("%dX^%d+", p.poly[i].coeff, p.poly[i].exp);
    }
    printf("\n\n");
}

int main()
{
    struct Polynomial p;

    create(&p);

    display(p);

    return 0;
}
