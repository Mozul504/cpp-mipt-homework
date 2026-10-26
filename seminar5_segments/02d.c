#include <stdio.h>
#include <stdlib.h>

float* get_geometric_progression(float a, float r, int n) {
    float* arr = (float*)malloc(n * sizeof(float));
    arr[0] = a;
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i-1] * r;
    }
    return arr; 
}

int main() {
    float* prog = get_geometric_progression(3.0f, 3.0f, 10);
    for (int i = 0; i < 10; i++) printf("%.0f ", prog[i]);
    free(prog); 
    return 0;
}
