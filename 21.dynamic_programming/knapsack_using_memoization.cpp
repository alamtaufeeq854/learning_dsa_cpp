// Knapsack Using Memoization

#include <stdio.h>

int knapsack(int Elements, int capacity, int P[], int W[], int Table[12][16])
{
    if (Elements == 0 || capacity == 0)
    {
        Table[Elements][capacity] = 0;
        return 0;
    }

    if (Table[Elements][capacity] != -1)
        return Table[Elements][capacity];

    if (W[Elements - 1] <= capacity)
    {
        int no = knapsack(Elements - 1, capacity, P, W, Table);
        int yes = knapsack(Elements - 1, capacity - W[Elements - 1], P, W, Table) + (P[Elements - 1]);

        Table[Elements][capacity] = no > yes ? no : yes;
    }

    else
    {
        Table[Elements][capacity] = knapsack(Elements - 1, capacity, P, W, Table);
    }
    return Table[Elements][capacity];
}

int main()
{
    int P[] = {17, 23, 4, 10, 6, 12, 8, 3, 2, 11, 7};
    int W[] = {7, 2, 5, 4, 6, 1, 9, 2, 8, 5, 4};

    int Table[12][16];

    for (int i = 0; i <= 11; i++)
        for (int j = 0; j <= 15; j++)
            Table[i][j] = -1;

    printf("Max Profit = %d\n", knapsack(11, 15, P, W, Table));

    return 0;
}