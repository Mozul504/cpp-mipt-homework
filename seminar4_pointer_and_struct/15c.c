#include <stdio.h>

struct node
{
    int value;
    struct node* ptr;
};
typedef struct node Node;

int main(void)
{
    Node n1 = {10, NULL};
    Node n2 = {20, NULL};
    Node n3 = {30, NULL};

    n1.ptr = &n2;
    n2.ptr = &n3;
    n3.ptr = &n1;

    Node* p = &n1;
    while (1)
    {
        printf("%d\n", p->value);
        p = p->ptr;
    }

    return 0;
}
