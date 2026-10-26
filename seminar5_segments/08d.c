#include <stdio.h>

int sum(int x, int y)    { return x + y; }
int diff(int x, int y)   { return x - y; }
int mult(int x, int y)   { return x * y; }
int sqdiff(int x, int y) { return x * x - y * y; }
int lin(int x, int y)    { return 5 * x - y; }

typedef int (*FuncPtr)(int, int);
FuncPtr array[5] = {sum, diff, mult, sqdiff, lin};

void print_func_name(FuncPtr p) {
    if (p == sum) printf("sum\n");
    else if (p == diff) printf("diff\n");
    else if (p == mult) printf("mult\n");
    else if (p == sqdiff) printf("sqdiff\n");
    else if (p == lin) printf("lin\n");
}

void sort_funcs(FuncPtr* a, size_t n, int x, int y) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (a[j](x, y) > a[j + 1](x, y)) {
                FuncPtr tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

int main() {
    print_func_name(array[0]); 
    sort_funcs(array, 5, 2, 2);
    return 0;
}
