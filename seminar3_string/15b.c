#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 4096   

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Error: Wrong number of arguments!\n");
        printf("Usage: %s <input_file> <output_file> <lines>\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    if (in == NULL)
    {
        printf("Error: File %s does not exist!\n", argv[1]);
        return 1;
    }

    int start = 0;     
    int end   = 0;      
    int is_range = 0;   
    int pos = 0;        

    if (sscanf(argv[3], "%d:%d%n", &start, &end, &pos) == 2
        && argv[3][pos] == '\0')
    {
        is_range = 1;
    }
    else if (sscanf(argv[3], "%d%n", &start, &pos) == 1
             && argv[3][pos] == '\0')
    {
        is_range = 0;
        end = start + 1;   
    }
    else
    {
        printf("Error: Wrong lines format!\n");
        fclose(in);
        return 1;
    }

    if (start <= 0 || end <= start)
    {
        printf("Error: Wrong lines format!\n");
        fclose(in);
        return 1;
    }

    FILE *out = fopen(argv[2], "w");
    if (out == NULL)
    {
        printf("Error: cannot open '%s'\n", argv[2]);
        fclose(in);
        return 1;
    }

    char line[MAX_LINE];    
    int line_no = 0;       

    
    while (fgets(line, MAX_LINE, in) != NULL)
    {
        line_no++;   

        if (line_no >= start && line_no < end)
        {
            fputs(line, out);
        }

        if (line_no >= end)
            break;
    }

    fclose(in);
    fclose(out);

    return 0;
}
