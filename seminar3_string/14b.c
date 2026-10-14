#include <stdio.h>   
#include <stdlib.h>  
char caesar(char c, int k)
{
    if (c >= 'A' && c <= 'Z')
        return 'A' + (c - 'A' + k) % 26;
    if (c >= 'a' && c <= 'z')
        return 'a' + (c - 'a' + k) % 26;
    return c;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <input> <output> <key>\n", argv[0]);
        return 1;
    }
    FILE *in = fopen(argv[1], "r");
    if (in == NULL)
    {
        printf("Error: cannot open '%s'\n", argv[1]);
        return 1;
    }
    FILE *out = fopen(argv[2], "w");
    if (out == NULL)
    {
        printf("Error: cannot open '%s'\n", argv[2]);
        fclose(in);
        return 1;
    }
    int k = atoi(argv[3]);

    while ((c = fgetc(in)) != EOF)
        fputc(caesar(c, k), out);
    fclose(in);
    fclose(out);

    return 0;
}
