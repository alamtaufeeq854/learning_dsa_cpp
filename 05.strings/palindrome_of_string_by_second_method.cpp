// Palindrome of String by Second Method
#include <stdio.h>

int main()
{
    char s[] = "madam";

    int i;

    for (i = 0; s[i] != '\0'; i++)
        ;
    i = i - 1;

    for (int j = 0; i > j; i--, j++)
    {
        if (s[i] != s[j])
        {
            printf("NOt a Palindrome\n");
            return 0;
        }
    }

    printf("Palindrome\n");

    return 0;
}