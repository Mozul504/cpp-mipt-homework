#include <stdio.h>

int main(void)
{
    char c;
    scanf("%c", &c);

    int code = (int)c;

    if ((code >= 65 && code <= 90) || (code >= 97 && code <= 122))
        printf("Letter\n");
    else if (code >= 48 && code <= 57)
        printf("Digit\n");
    else
        printf("Other\n");

    return 0;
}
