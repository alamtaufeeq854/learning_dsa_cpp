// Nested Recursion
#include <stdio.h>

int fun(int n)
{
    if (n > 100)

        return (n - 10);

    return fun(fun(n + 11));
}

int main()
{
    int result;

    result = fun(99);

    printf("%d\n", result);

    return 0;
}