#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
    if (n == 0)
        return 1;
    int factorial = 1;
    for (int i = 0; i < n; i++)
    {
        factorial *= (i + 1);
    }
    return factorial;
}

int *coef(int n)
{
    if (n < 0)
    {
        return NULL;
    }
    int *p;
    p = (int *)malloc((n + 1) * sizeof(int));
    for (int k = 0; k <= n; k++)
    {
        p[k] = fact(n) / (fact(k) * fact(n - k));
    }
    return p;
}

int main()
{
    int n = 0, *p;
    p=coef(n);
    for (int i = 0; i <= n; i++)
    {
        printf("%7d", p[i]);
    }
    return 0;
}