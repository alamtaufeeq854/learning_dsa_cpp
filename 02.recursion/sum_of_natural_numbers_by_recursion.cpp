// Sum Of 'N' Natural Numbers Using Recursion
#include <stdio.h>

int sum(int n)
{
    if (n == 0)

        return 0;

    return sum(n - 1) + n;
}

int main()
{
    int result;

    result = sum(5);

    printf("%d\n", result);

    return 0;
}