// Taylor Series Using Iterative
#include <stdio.h>

double e(int x, int n)
{
    double sum = 1;

    double numerator = 1, denominator = 1;

    for (int i = 1; i <= n; i++)
    {
        numerator = numerator * x;
        denominator = denominator * i;

        sum += numerator / denominator;
    }

    return sum;
}

int main()
{
    double result;

    result = e(5, 3);

    printf("%lf\n", result);

    return 0;
}