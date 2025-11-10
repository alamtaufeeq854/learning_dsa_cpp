// Tridiagonal Matrix
#include <stdio.h>
#include <stdlib.h>

struct TridiagonalMatrix
{
    int *A;
    int n;
};

void set(struct TridiagonalMatrix *m, int i, int j, int x)
{
    if (i - j == 1)
    {
        m->A[i - 2] = x;
    }

    else if (i - j == 0)
    {
        m->A[m->n - 1 + i - 1] = x;
    }

    else if (i - j == -1)
    {
        m->A[2 * m->n - 1 + i - 1] = x;
    }
}

int get(struct TridiagonalMatrix m, int i, int j)
{
    if (i - j == 1)
    {
        return m.A[i - 2];
    }

    else if (i - j == 0)
    {
        return m.A[m.n - 1 + i - 1];
    }

    else if (i - j == -1)
    {
        return m.A[2 * m.n - 1 + i - 1];
    }

    else
        return 0;
}

void display(struct TridiagonalMatrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i - j == 1)
                printf("%d ", m.A[i - 2]);

            else if (i - j == 0)
                printf("%d ", m.A[m.n - 1 + i - 1]);

            else if (i - j == -1)
                printf("%d ", m.A[2 * m.n - 1 + i - 1]);

            else
                printf("0 ");
        }

        printf("\n");
    }
    printf("\n\n");
}

int main()
{
    struct TridiagonalMatrix m;

    printf("Enter Dimension: ");
    scanf("%d", &m.n);

    m.A = (int *)malloc((3 * m.n - 2) * sizeof(int));

    int k = 1;

    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            set(&m, i, j, k);
            if (k > 8)
                k = 1;
            k++;
        }
    }

    if (m.n > 2)
        get(m, m.n - 1, m.n - 2);

    display(m);

    free(m.A);
    return 0;
}