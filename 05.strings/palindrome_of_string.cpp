// Palindrome Of String
#include <stdio.h>

int main()
{
    char s1[] = "madam";
    char s2[20];

    int i, j, k;

    for (i = 0; s1[i] != '\0'; i++)
        ;
    i = i - 1;

    for (j = 0; i >= 0; i--, j++)
    {
        s2[j] = s1[i];
    }
    s2[j] = '\0';

    for (k = 0; s1[k] != '\0'; k++)
    {
        if (s1[k] != s2[k])
        {
            printf("NOt a Palindrome\n");
            return 0;
        }
    }

    printf("Palindrome\n");

    return 0;
}