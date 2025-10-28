// Fibonacci Series By Using Iterative
#include <stdio.h>

int fibonacci(int n)
{
    int sum = 0, t0 = 0, t1 = 1;

    if (n <= 1)
        return n;

    for (int i = 2; i <= n; i++)
    {
        sum = (t0 + t1);
        t0 = t1;
        t1 = sum;
    }

    return sum;
}

int main()
{
    int result;

    result = fibonacci(7);

    printf("%d\n", result);

    return 0;
}