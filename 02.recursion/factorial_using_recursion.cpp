// Factorial using Recursion
#include <stdio.h>

int factorial(int n)
{
    if (n == 0)

        return 1;

    return factorial(n - 1) * n;
}

int main()
{
    int result;

    result = factorial(5);

    printf("%d\n", result);

    return 0;
}