// Permutation Problem

#include <stdio.h>
#include <stdbool.h>

#define n 3

char result[n + 1];
bool sel[n] = {false, false, false};
char str[] = "ABC";

void permutation(int k)
{
    if (k == n)
    {
        result[k] = '\0';
        printf("%s\n", result);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (sel[i] == false)
        {
            result[k] = str[i];
            sel[i] = true;

            permutation(k + 1);

            sel[i] = false;
        }
    }
}

int main()
{
    permutation(0);
    return 0;
}
