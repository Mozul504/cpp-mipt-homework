#include <stdio.h>

#define MAX_LEN 200

int main(void)
{
    char s[MAX_LEN];
    scanf("%s", s);

    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++)
        sum += s[i] - '0';

    printf("%d\n", sum);
    return 0;
}
