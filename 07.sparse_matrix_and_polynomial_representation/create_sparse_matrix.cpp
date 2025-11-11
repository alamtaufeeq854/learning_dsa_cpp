// Create Sparse Matrix
#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *e;
};

void create(struct Sparse *s)
{
    printf("Enter number of rows: ");
    scanf("%d", &s->m);

    printf("Enter number of column: ");
    scanf("%d", &s->n);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &s->num);

    s->e = (struct Element *)malloc(s->num * sizeof(struct Element));

    for (int i = 0; i < s->num; i++)
    {
        printf("Enter Row Number: ");
        scanf("%d", &s->e[i].i);

        printf("Enter column Number: ");
        scanf("%d", &s->e[i].j);

        if (s->m >= s->e[i].i && s->n >= s->e[i].j)
        {
            printf("Enter Element for Array[%d][%d]: ", s->e[i].i, s->e[i].j);
            scanf("%d", &s->e[i].x);
        }

        else
            printf("Invalid Row or Column Number !\n");
    }
}

void display(struct Sparse s)
{
    int i, j, k = 0;

    for (i = 1; i <= s.m; i++)
    {
        for (j = 1; j <= s.n; j++)
        {
            if (s.e[k].i == i && s.e[k].j == j)
                printf("%d ", s.e[k++].x);

            else
                printf("0 ");
        }
        printf("\n");
    }
    printf("\n\n");
}

int main()
{
    struct Sparse s1;

    create(&s1);

    display(s1);

    return 0;
}