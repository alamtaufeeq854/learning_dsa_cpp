// Fibonacci Series By Using Recursion
#include <stdio.h>

int fibonacci(int n)
{

    if (n <= 1)
        return n;

    return fibonacci(n - 2) + fibonacci(n - 1);
}

int main()
{
    int result;

    result = fibonacci(10);

    printf("%d\n", result);

    return 0;
}