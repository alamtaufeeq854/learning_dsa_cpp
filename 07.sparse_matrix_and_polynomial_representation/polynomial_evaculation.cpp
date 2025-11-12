// Polynomial Evaculation
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

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

int value(struct Polynomial p, int x = 1)
{
    int sum = 0;
    for (int i = 0; i < p.n; i++)
    {
        sum += p.poly[i].coeff * pow(x, p.poly[i].exp);
    }
    return sum;
}

int main()
{
    struct Polynomial p;

    create(&p);

    display(p);

    printf("Value of Polynomial At X=2 is: %d\n", value(p, 2));

    return 0;
}
