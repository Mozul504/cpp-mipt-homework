#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char* a, const char* b) {
    char* res = (char*)malloc((strlen(a) + strlen(b) + 1) * sizeof(char));
    strcpy(res, a);
    strcat(res, b);
    return res;
}

int main() {
    char* str = concat("Hello, ", "World!");
    printf("%s\n", str);
    free(str);
    return 0;
}
