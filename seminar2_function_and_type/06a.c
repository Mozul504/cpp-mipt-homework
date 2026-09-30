int trib(int n)
{
    if (n == 0 || n == 1)
        return 0;
    if (n == 2)
        return 1;

    int t0 = 0; 
    int t1 = 0;  
    int t2 = 1;  
    for (int i = 3; i <= n; i++)
    {
        int t3 = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = t3;
    }

    return t2;
}
