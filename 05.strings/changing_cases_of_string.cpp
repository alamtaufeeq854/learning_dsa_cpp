// Changing Cases Of String

#include <stdio.h>

int main()
{
    char s[] = "WeL5cOmE";

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 90)
            s[i] += 32;

        else if (s[i] >= 97 && s[i] <= 'z')
            s[i] -= 32;
    }

    printf("Updated String is: %s\n", s);

    return 0;
}
