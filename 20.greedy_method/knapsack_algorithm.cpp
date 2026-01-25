// Fractional Knapsack Algorithm

#include <stdio.h>

void sortByRatio(double A[2][11], int n)
{
    double ratio1, ratio2;
    double tempP, tempW;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            ratio1 = A[0][j] / A[1][j];
            ratio2 = A[0][j + 1] / A[1][j + 1];

            if (ratio1 < ratio2) // decreasing order
            {
                tempP = A[0][j];
                tempW = A[1][j];

                A[0][j] = A[0][j + 1];
                A[1][j] = A[1][j + 1];

                A[0][j + 1] = tempP;
                A[1][j + 1] = tempW;
            }
        }
    }
}

double knapsack(double object[2][11], int arraySize, int capacity)
{
    sortByRatio(object, arraySize);

    double profit = 0;

    for (int i = 0; i < arraySize; i++)
    {
        if (object[1][i] <= capacity)
        {
            profit += object[0][i];
            capacity -= object[1][i];
        }

        else
        {
            profit += capacity * object[0][i] / object[1][i];
            break;
        }
    }
    return profit;
}

int main()
{
    int P[] = {17, 23, 4, 10, 6, 12, 8, 3, 2, 11, 7};
    int W[] = {7, 2, 5, 4, 6, 1, 9, 2, 8, 5, 4};
    double A[2][11];

    for (int i = 0; i < 11; i++)
    {
        A[0][i] = P[i];
        A[1][i] = W[i];
    }

    printf("Max Profit = %.2f\n", knapsack(A, 11, 15));
    return 0;
}