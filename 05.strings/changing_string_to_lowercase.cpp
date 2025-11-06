// Changing String To Lowercase
#include <stdio.h>

int main()
{
    char s[] = "WELCOME";

    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        s[i] += 32;
    }

    printf("Updated String is: %s\n", s);

    return 0;
}