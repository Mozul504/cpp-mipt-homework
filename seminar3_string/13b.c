#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error: Wrong number of arguments!\n");
        return 1;
    }

    int a, b;
    char op;
    char extra;

    if (sscanf(argv[1], "%d %c %d %c", &a, &op, &b, &extra) != 3)
    {
        printf("Error: Wrong format!\n");
        return 1;
    }

    if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%')
    {
        printf("Error: Invalid operator!\n");
        return 1;
    }

    if (op == '/' || op == '%')
    {
        if (b == 0)
        {
            printf("Error: Division by zero!\n");
            return 1;
        }
    }

    switch (op)
    {
        case '+': printf("%d\n", a + b); break;
        case '-': printf("%d\n", a - b); break;
        case '*': printf("%d\n", a * b); break;
        case '/': printf("%d\n", a / b); break;
        case '%': printf("%d\n", a % b); break;
    }

    return 0;
}
