#include <stdio.h>

void encrypt(char *str, int k)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = 'A' + (str[i] - 'A' + k) % 26;
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = 'a' + (str[i] - 'a' + k) % 26;
        
    }
}
