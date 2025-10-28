// Fibonacci Series By Using Memoization
#include <stdio.h>

int F[20]; // Global Array

int fibonacci(int n)
{

    if (n <= 1)
    {

        F[n] = n;

        return n;
    }

    if (F[n - 2] == -1)
    {
        F[n - 2] = fibonacci(n - 2);
    }

    if (F[n - 1] == -1)
    {
        F[n - 1] = fibonacci(n - 1);
    }

    F[n] = F[n - 2] + F[n - 1];

    return F[n];
}

int main()
{
    for (int i = 0; i < 20; i++)
    {
        F[i] = -1;
    }

    int result;

    result = fibonacci(10);

    printf("%d\n", result);

    return 0;
}