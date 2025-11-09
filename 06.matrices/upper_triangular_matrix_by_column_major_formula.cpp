// Upper Triangular Matrix By column Major Formula
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
        m->A[(j * (j - 1)) / 2 + (i - 1)] = x;
}

int get(struct Matrix m, int i, int j)
{
    if (i <= j)
        return m.A[(j * (j - 1)) / 2 + (i - 1)];
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
                printf("%d ", m.A[(j * (j - 1)) / 2 + (i - 1)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    printf("Enter Dimension: ");
    scanf("%d", &m.n);

    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    int x;

    printf("Enter elements column-wise (only upper-triangular part):\n");
    for (int j = 1; j <= m.n; j++)
    {
        for (int i = 1; i <= j; i++)
        {
            scanf("%d", &x);
            set(&m, i, j, x);
        }
    }

    printf("\nUpper Triangular Matrix:\n");
    display(m);

    free(m.A);

    return 0;
}
