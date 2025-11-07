// Diagonal Matrix
#include <stdio.h>

struct Matrix
{
    int A[10];
    int n;
};

void set(struct Matrix *m, int i, int j, int x)
{
    if (i == j)
        m->A[i - 1] = x;
}

void get(struct Matrix m, int i, int j)
{
    if (i == j)
        printf("Element is: %d\n", m.A[i - 1]);
    else
        printf("Element is: %d\n", 0);
}

void display(struct Matrix m)
{
    int i, j;

    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i == j)
                printf("%d ", m.A[i]);

            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    m.n = 5;

    set(&m, 1, 1, 9);
    set(&m, 2, 2, 7);
    set(&m, 3, 3, 1);
    set(&m, 4, 4, 5);
    set(&m, 5, 5, 2);

    get(m, 5, 5);
    get(m, 4, 3);

    display(m);

    return 0;
}