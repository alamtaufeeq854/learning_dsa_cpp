// Reverse Of String Second Method
#include <stdio.h>

int main()
{
    char s1[] = "Python";
    char s2[15];

    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
        ;
    i = i - 1;

    for (j = 0; i >= 0; i--, j++)
    {
        s2[j] = s1[i];
    }
    s2[j] = '\0';

    printf("Reverse Of String %s is: %s\n", s1, s2);

    return 0;
}