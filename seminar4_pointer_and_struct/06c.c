int exchange(int* pa, int b)
{
    int old = *pa;
    *pa = b;
    return old;
}
