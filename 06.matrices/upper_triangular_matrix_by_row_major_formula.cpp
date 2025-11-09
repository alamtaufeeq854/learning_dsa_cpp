// Upper Triangular Matrix By Row Major Formula
#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void set(struct Matrix *m, int i, int j, int x)
{
    if (i <= j)
        m->A[(i - 1) * m->n - (i - 2) * (i - 1) / 2 + j - i] = x;
}

int get(struct Matrix m, int i, int j)
{
    if (i <= j)
        return m.A[m.n * (i - 1) - (i - 2) * (i - 1) / 2 + j - i];

    else
        return 0;
}

void display(struct Matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i <= j)
                printf("%d ", m.A[m.n * (i - 1) - (i - 2) * (i - 1) / 2 + j - i]);

            else
                printf("0 ");
        }
        printf("\n");
    }

    printf("\n\n");
}

int main()
{
    struct Matrix m;
    printf("Enter Dimension: ");
    scanf("%d", &m.n);

    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    int x;

    printf("Enter elements row-wise (only upper-triangular part):\n");
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = i; j <= m.n; j++)
        {
            scanf("%d", &x);
            set(&m, i, j, x);
        }
    }

    printf("\n\n");
    display(m);

    free(m.A);

    return 0;
}
