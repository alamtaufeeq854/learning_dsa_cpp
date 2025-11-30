// Sparse Matrix Using Linked List
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int col;
    int val;
    struct node *next;
};

int main()
{
    int nz, i, m, n, c, v, j;

    printf("enter no. of rows.\n");
    scanf("%d", &m);

    printf("enter no. of columns.\n");
    scanf("%d", &n);

    struct node *A[m], *last;

    for (i = 0; i < m; i++)
    {
        A[i] = NULL;
        printf("Enter non zero elements in %d row.\n", i + 1);
        scanf("%d", &nz);

        for (j = 0; j < nz; j++)
        {
            if (A[i] == NULL)
            {
                A[i] = (struct node *)malloc(sizeof(struct node));
                last = A[i];
            }
            else
            {
                last->next = (struct node *)malloc(sizeof(struct node));
                last = last->next;
            }

            printf("enter column and value.\n");
            scanf("%d%d", &c, &v);
            last->col = c;
            last->val = v;
            last->next = NULL;
        }
    }

    printf("\nSparse Matrix Representation:\n");
    for (i = 0; i < m; i++)
    {
        last = A[i];

        for (j = 0; j < n; j++)
        {
            if (last != NULL && last->col == j)
            {
                printf("%d ", last->val);
                last = last->next;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

    return 0;
}
