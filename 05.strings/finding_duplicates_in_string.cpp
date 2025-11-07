// Finding Duplicates In String
#include <stdio.h>

int main()
{
    char s[] = "Finding";

    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        int count = 1;

        if (s[i] != '0')
        {
            for (int j = i + 1; s[j] != '\0'; j++)
            {
                if (s[i] == s[j])
                {
                    s[j] = '0';
                    count++;
                }
            }
            if (count > 1)
                printf(" %c Repeats %d times\n", s[i], count);
        }
    }
    return 0;
}