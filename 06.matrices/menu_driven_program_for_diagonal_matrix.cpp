// Menu Driven Program For Diagonal Matrix
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

    m.A = new int[m.n];

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
                printf("Enter element of A[%d][%d]= ", i, i);
                scanf("%d", &m.A[i - 1]);
            }
            break;

        case 2:
            int i, j, x;
            printf("Enter the row number of Element: ");
            scanf("%d", &i);
            printf("Enter the column number of Element: ");
            scanf("%d", &j);
            if (i == j)
            {
                printf("Enter the Element to replace original: ");
                scanf("%d", &x);
                m.A[i - 1] = x;
            }
            else
                printf("This is a Diagonal Element, so this place always be zero\n");

            break;
        case 3:
        {
            int i, j;
            printf("Enter the row number of Element: ");
            scanf("%d", &i);
            printf("Enter the column number of Element: ");
            scanf("%d", &j);

            if (i == j)
                printf("Element is: %d\n", m.A[i - 1]);

            else if (i > m.n || j > m.n)
                printf("Invalid Input ! \n");

            else
                printf("Element is: %d\n", 0);
        }
        break;
        case 4:
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
