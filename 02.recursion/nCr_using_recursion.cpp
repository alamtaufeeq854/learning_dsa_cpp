// nCr using Recursion
#include <stdio.h>

int factorial(int n)
{
    if (n == 0)

        return 1;

    return factorial(n - 1) * n;
}

int nCr(int n, int r)
{
    int numerator = factorial(n);
    int denominator = factorial(r) * factorial(n - r);

    return numerator / denominator;
}

int main()
{
    printf("%d\n", nCr(8, 5));

    return 0;
}