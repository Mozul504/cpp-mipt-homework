#include <stdio.h>
#include <string.h>

int is_palindrome(const char *s)
{
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right)
    {
        if (s[left] != s[right])
            return 0;  
        left++;
        right--;
    }

    return 1;           
}

int main(void)
{
    char s[1000];
    scanf("%s", s);

    if (is_palindrome(s))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
