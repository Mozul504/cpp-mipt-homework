#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int main(void)
{
    char s1[MAX_LEN];
    char s2[MAX_LEN];

    scanf("%s", s1);
    scanf("%s", s2);

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int max_len = (len1 > len2) ? len1 : len2;

    for (int i = 0; i < max_len; i++)
    {
        if (i < len1)
            printf("%c", s1[i]);
        if (i < len2)
            printf("%c", s2[i]);
    }

    printf("\n");
    return 0;
}
