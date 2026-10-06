#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <word> <count>\n", argv[0]);
        return 1;
    }

    char *word = argv[1];
    int n = atoi(argv[2]);

    for (int i = 0; i < n; i++)
    {
        printf("%s", word);
        if (i < n - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}
