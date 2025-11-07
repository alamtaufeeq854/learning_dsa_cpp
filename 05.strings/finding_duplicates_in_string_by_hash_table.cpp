// Finding Duplicates In String By Hash Table
#include <stdio.h>

int main()
{
    char s[] = "finding";
    char H[26] = {0};

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != '0')
        {
            H[s[i] - 97]++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            printf(" %c Repeats %d times\n", i + 'a', H[i]);
        }
    }
    return 0;
}
