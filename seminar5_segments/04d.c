#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_test_strings() {
    char** arr = (char**)malloc(4 * sizeof(char*)); 
    arr[0] = (char*)malloc(10); strcpy(arr[0], "Banana");
    arr[1] = (char*)malloc(10); strcpy(arr[1], "Apple");
    arr[2] = (char*)malloc(10); strcpy(arr[2], "Cherry");
    arr[3] = NULL;
    return arr;
}

void print_strings(const char** arr) {
    for (int i = 0; arr[i] != NULL; i++) printf("%s\n", arr[i]);
}

size_t* get_sizes(const char** arr) {
    int n = 0; while (arr[n] != NULL) n++;
    size_t* sizes = (size_t*)malloc(n * sizeof(size_t));
    for (int i = 0; i < n; i++) sizes[i] = strlen(arr[i]);
    return sizes;
}

void destroy_strings(char*** p_arr) {
    char** arr = *p_arr;
    for (int i = 0; arr[i] != NULL; i++) free(arr[i]); 
    free(arr); 
    *p_arr = NULL;
}

void sort_strings(char** words) {
    int n = 0; while (words[n] != NULL) n++;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(words[j], words[j+1]) > 0) {
                char* tmp = words[j];
                words[j] = words[j+1];
                words[j+1] = tmp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) return 1;
    
    FILE* f = fopen(argv[1], "r");
    if (!f) return 1;
    
    char** lines = NULL;
    int count = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), f)) {
        lines = (char**)realloc(lines, (count + 2) * sizeof(char*));
        lines[count] = (char*)malloc(strlen(buffer) + 1);
        strcpy(lines[count], buffer);
        count++;
    }
    if (lines) lines[count] = NULL; 
    fclose(f);

    sort_strings(lines);

    FILE* out = fopen(argv[2], "w");
    for (int i = 0; lines[i] != NULL; i++) fprintf(out, "%s", lines[i]);
    fclose(out);

    destroy_strings(&lines);
    return 0;
}
