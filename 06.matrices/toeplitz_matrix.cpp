// Toeplitz Matrix
#include <stdio.h>
#include <stdlib.h>

struct ToeplitzMatrix
{
    int *A;
    int n;
};

int get(struct ToeplitzMatrix m, int i, int j)
{
    if (j >= i)
        return m.A[j - 1];
    else
        return m.A[m.n + i - j - 1];
}

void display(struct ToeplitzMatrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (j >= i)
                printf("%d ", m.A[j - 1]);
            else
                printf("%d ", m.A[m.n + i - j - 1]);
        }

        printf("\n");
    }
    printf("\n\n");
}

int main()
{
    struct ToeplitzMatrix m;

    printf("Enter Dimension: ");
    scanf("%d", &m.n);

    m.A = (int *)malloc((2 * m.n - 1) * sizeof(int));

    for (int i = 0; i < m.n; i++)
    {
        printf("Enter a Element through column wise: ");
        scanf("%d", &m.A[i]);
    }

    printf("\n");

    for (int i = m.n; i < 2 * m.n - 1; i++)
    {
        printf("Enter a Element through row wise: ");
        scanf("%d", &m.A[i]);
    }

    printf("\n\nToeplitz Matrix: \n");
    display(m);

    free(m.A);
    return 0;
}