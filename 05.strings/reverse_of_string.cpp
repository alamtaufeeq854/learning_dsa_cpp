// Reverse of String
#include <stdio.h>

int main()
{
    char s[] = "Python";

    int i;

    for (i = 0; s[i] != '\0'; i++)
        ;
    i = i - 1;

    for (int j = 0; i > j; i--, j++)
    {
        char temp;
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    printf("Reverse Of String is %s\n", s);

    return 0;
}