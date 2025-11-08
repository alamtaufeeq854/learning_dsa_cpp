// Comparing Strings
#include <stdio.h>

int main()
{
    char s1[] = "Painter";
    char s2[] = "paintInG";

    int i, j;

    for (i = 0, j = 0; s1[i] != '\0' && s2[j] != '\0'; i++, j++)
    {
        s1[i] = (s1[i] >= 'A' && s1[i] <= 'Z') ? s1[i] + 32 : s1[i];
        s2[j] = (s2[j] >= 'A' && s2[j] <= 'Z') ? s2[j] + 32 : s2[j];

        if (s1[i] != s2[j])
            break;
    }

    if (s1[i] == s2[j])
        printf("Equal \n");

    else if (s1[i] > s2[j])
    {
        printf("string '%s' Appears first\n", s2);
    }

    else
    {
        printf("string '%s' Appears first\n", s1);
    }

    return 0;
}