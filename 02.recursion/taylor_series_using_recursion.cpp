// Taylor Series using Recursion
#include <stdio.h>

double e(int x, int n)
{
    double r;

    static double p = 1, f = 1;

    if (n == 0)

        return 1;

    r = e(x, n - 1);
    p = p * x;
    f = f * n;

    return r + p / f;
}

int main()
{
    double result;

    result = e(5, 3);

    printf("%lf\n", result);

    return 0;
}