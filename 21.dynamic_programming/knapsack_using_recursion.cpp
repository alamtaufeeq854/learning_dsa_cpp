// Knapsack Using Recursion

#include <stdio.h>

int knapsack(int Elements, int capacity, int P[], int W[])
{
    if (Elements == 0 || capacity == 0)
        return 0;

    if (W[Elements - 1] <= capacity)
    {
        int no = knapsack(Elements - 1, capacity, P, W);
        int yes = knapsack(Elements - 1, capacity - W[Elements - 1], P, W) + (P[Elements - 1]);

        return no > yes ? no : yes;
    }

    else
    {
        return knapsack(Elements - 1, capacity, P, W);
    }
}

int main()
{
    int P[] = {17, 23, 4, 10, 6, 12, 8, 3, 2, 11, 7};
    int W[] = {7, 2, 5, 4, 6, 1, 9, 2, 8, 5, 4};

    printf("Max Profit = %d\n", knapsack(11, 15, P, W));

    return 0;
}