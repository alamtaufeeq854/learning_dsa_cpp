// Validating a String
#include <stdio.h>

int valid(char name[])
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!((name[i] >= 'A' && name[i] <= 'Z') ||
              (name[i] >= 'a' && name[i] <= 'z') ||
              (name[i] >= '0' && name[i] <= '9') ||
              (name[i] == ' ')))
        {
            printf("%s Is Invalid String\n", name);
            return -1;
        }
    }
    printf("%s Is Valid String\n", name);
    return 0;
}

int main()
{
    char s1[] = "Anil123";
    char s2[] = "john?456";

    valid(s1);
    valid(s2);

    return 0;
}