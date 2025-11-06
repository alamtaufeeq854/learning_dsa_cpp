// Toggle the cases of Alphabets
#include <stdio.h>

int main()
{
    char s[] = "WeLcOme";

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;

        else if (s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
    }

    printf("Updated String is: %s\n", s);

    return 0;
}