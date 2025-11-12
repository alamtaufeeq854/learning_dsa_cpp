// Add Sparse Matrix
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

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;

    int i = 0, j = 0, k = 0;

    if (s1->m != s2->m || s1->n != s2->n)
        return NULL;

    sum = (struct Sparse *)malloc(sizeof(struct Sparse));

    sum->e = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));

    while (i < s1->num && j < s2->num)
    {
        if (s1->e[i].i > s2->e[j].i)
            sum->e[k++] = s2->e[j++];

        else if (s1->e[i].i < s2->e[j].i)
            sum->e[k++] = s1->e[i++];

        else
        {
            if (s1->e[i].j > s2->e[j].j)
                sum->e[k++] = s2->e[j++];

            else if (s1->e[i].j < s2->e[j].j)
                sum->e[k++] = s1->e[i++];

            else
            {
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    for (; i < s1->num; i++)
        sum->e[k++] = s1->e[i];
    for (; j < s2->num; j++)
        sum->e[k++] = s2->e[j];
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
}

int main()
{
    struct Sparse s1, s2, *s3;

    printf("\nCreate First Matrix\n");
    create(&s1);

    printf("\nCreate Second Matrix\n");
    create(&s2);

    s3 = add(&s1, &s2);

    printf("First Matrix\n");
    display(s1);

    printf("Second Matrix\n");
    display(s2);

    printf("Sum Matrix\n");
    display(*s3);

    return 0;
}