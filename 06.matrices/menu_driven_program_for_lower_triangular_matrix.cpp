// Menu Driven Program For Lower Triangular Matrix
#include <stdio.h>

struct Matrix
{
    int *A;
    int n;
};

int main()
{

    struct Matrix m;
    printf("Enter Dimension: ");
    scanf("%d", &m.n);

    int option;

    m.A = new int[(m.n * m.n + 1) / 2];

    do
    {
        printf("\nMenu:\n1.Create\n2.Set\n3.Get\n4.Display\n5.Exit\n\n");
        printf("Choose Your Option Number: ");
        scanf("%d", &option);
        printf("\n");

        switch (option)
        {
        case 1:
            for (int i = 1; i <= m.n; i++)
            {
                for (int j = 1; j <= m.n; j++)
                {
                    if (i >= j)
                    {
                        printf("Enter element of A[%d][%d]= ", i, j);
                        scanf("%d", &m.A[i * (i - 1) / 2 + (j - 1)]);
                    }
                }
            }
            break;

        case 2:
            int i, j, x;
            printf("Enter the row number of Element: ");
            scanf("%d", &i);
            printf("Enter the column number of Element: ");
            scanf("%d", &j);
            if (i >= j)
            {
                printf("Enter the Element to replace original: ");
                scanf("%d", &x);
                m.A[i * (i - 1) / 2 + (j - 1)] = x;
            }
            else
                printf("This is a lower triangular matrix, so element in this place always be zero\n");

            break;
        case 3:
        {
            int i, j;
            printf("Enter the row number of Element: ");
            scanf("%d", &i);
            printf("Enter the column number of Element: ");
            scanf("%d", &j);

            if (i >= j)
                printf("Element is: %d\n", m.A[i * (i - 1) / 2 + (j - 1)]);

            else if (i > m.n || j > m.n)
                printf("Invalid Input ! \n");

            else
                printf("Element is: %d\n", 0);
        }
        break;
        case 4:
        {
            int i, j;

            for (i = 1; i <= m.n; i++)
            {
                for (j = 1; j <= m.n; j++)
                {
                    if (i >= j)
                        printf("%d ", m.A[i * (i - 1) / 2 + (j - 1)]);

                    else
                        printf("0 ");
                }
                printf("\n");
            }
        }
        break;
        case 5:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid Option! Please try again.\n");
        }

    } while (option != 5);

    return 0;
}
