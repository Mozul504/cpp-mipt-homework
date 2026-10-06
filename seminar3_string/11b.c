#include <stdio.h>
#include <stddef.h>

void safe_strcpy(char dst[], size_t size, const char src[])
{
    size_t i = 0;

    while (i < size - 1 && src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}
