// Polynomial Addition
#include <stdio.h>
#include <stdlib.h>

struct Poly
{
    int coeff;
    int exp;
};

struct Polynomial
{
    int n;
    struct Poly *poly;
};

void create(struct Polynomial *p)
{
    printf("Enter Number Of Non-Zeroes Terms: ");
    scanf("%d", &p->n);

    p->poly = (struct Poly *)malloc(p->n * sizeof(struct Poly));

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

struct Polynomial *add(struct Polynomial *p1, struct Polynomial *p2)
{
    int i = 0, j = 0, k = 0;

    struct Polynomial *sum;

    sum = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    sum->poly = (struct Poly *)malloc((p1->n + p2->n) * sizeof(struct Poly));

    while (i < p1->n && j < p2->n)
    {
        if (p1->poly[i].exp > p2->poly[j].exp)
            sum->poly[k++] = p1->poly[i++];

        else if (p1->poly[i].exp < p2->poly[j].exp)
            sum->poly[k++] = p2->poly[j++];

        else
        {
            sum->poly[k].exp = p1->poly[i].exp;
            sum->poly[k++].coeff = p1->poly[i++].coeff + p2->poly[j++].coeff;
        }
    }

    for (; i < p1->n; i++)
        sum->poly[k++] = p1->poly[i];
    for (; j < p2->n; j++)
        sum->poly[k++] = p2->poly[j];

    sum->n = k;

    return sum;
}

int main()
{
    struct Polynomial p1, p2, *p3;

    create(&p1);
    display(p1);

    create(&p2);
    display(p2);

    p3 = add(&p1, &p2);

    display(*p3);

    return 0;
}
