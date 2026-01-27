// Matrix Chain Multiplication Using Recursion

#include <stdio.h>
#include <limits.h>

int m(int i, int j, int D[])
{
    if (i == j)
        return 0;

    int cost, minimumCost = INT_MAX;

    for (int k = i; k < j; k++)
    {
        cost = m(i, k, D) + m(k + 1, j, D) + (D[i - 1] * D[k] * D[j]);

        if (cost < minimumCost)
            minimumCost = cost;
    }
    return minimumCost;
}

int main()
{
    int D[] = {2, 5, 6, 4, 3};

    printf("Minimum Multiplication Required is: %d", m(1, 4, D));

    return 0;
}