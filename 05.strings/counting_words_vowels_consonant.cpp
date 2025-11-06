// Counting Number of Words,Vowels & Consonant
#include <stdio.h>

int main()
{
    char s[] = "How are you";

    int consonants = 0, vowels = 0, words = 1;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            vowels++;

        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            consonants++;

        if (s[i + 1] != ' ' && s[i] == ' ')
            words++;
    }

    printf("Number of Words: %d\n", words);
    printf("Number of Vowels: %d\n", vowels);
    printf("Number of Consonants: %d\n", consonants);

    return 0;
}