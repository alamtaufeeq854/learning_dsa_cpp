// Power using Recursion
#include <stdio.h>

int power1(int m, int n)
{
    if (n == 0)

        return 1;

    return power1(m, n - 1) * m;
}

int power2(int m, int n) // Better and Faster Algorithm
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
        return power2(m * m, n / 2);

    else
        return m * power2(m * m, (n - 1) / 2);
}

int main()
{
    int result1, result2;

    result1 = power1(2, 9);

    printf("By using power1 function: %d\n", result1);

    result2 = power2(2, 9);

    printf("By using power2 function: %d\n", result2);

    return 0;
}