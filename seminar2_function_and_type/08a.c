#include <stdio.h>

void reverse(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int a1[] = {10, 20, 30, 40, 50};
    int a2[] = {60, 20, 80, 10};

    reverse(a1, 5);
    print_array(a1, 5);   // 50 40 30 20 10

    reverse(a2, 4);
    print_array(a2, 4);   // 10 80 20 60

    return 0;
}
