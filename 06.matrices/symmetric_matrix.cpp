// Symmetric Matrix
#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void set(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
        m->A[i * (i - 1) / 2 + (j - 1)] = x;
}

int get(struct Matrix m, int i, int j)
{
    if (i >= j)
        return m.A[i * (i - 1) / 2 + (j - 1)];
    else
        return m.A[j * (j - 1) / 2 + (i - 1)];
}

void display(struct Matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i >= j)
                printf("%d ", m.A[i * (i - 1) / 2 + (j - 1)]);
            else
                printf("%d ", m.A[j * (j - 1) / 2 + (i - 1)]);
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    printf("Enter dimension of symmetric matrix: ");
    scanf("%d", &m.n);

    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    int x;
    printf("Enter elements for lower-triangular part:\n");
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &x);
            set(&m, i, j, x);
        }
    }

    printf("\nSymmetric Matrix:\n");
    display(m);

    free(m.A);

    return 0;
}
