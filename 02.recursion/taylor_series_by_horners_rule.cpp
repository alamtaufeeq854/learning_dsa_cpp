// Taylor Series By Horner's Rule using Recursion
#include <stdio.h>

double e(int x, int n)
{
    static double s = 1;

    if (n == 0)

        return s;

    s = 1 + ((double)x / n) * s;

    return e(x, n - 1);
}

int main()
{
    double result;

    result = e(5, 3);

    printf("%lf\n", result);

    return 0;
}
