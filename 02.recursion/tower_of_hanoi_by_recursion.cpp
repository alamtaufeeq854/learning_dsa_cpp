// Tower Of Hanoi By Recursion
#include <stdio.h>

void towerOfHanoi(int n, int a, int b, int c)
{
    if (n > 0)
    {
        towerOfHanoi(n - 1, a, c, b);

        printf("(%d,%d)\n", a, c);

        towerOfHanoi(n - 1, b, a, c);
    }
}

int main()
{
    towerOfHanoi(3, 1, 2, 3);

    return 0;
}