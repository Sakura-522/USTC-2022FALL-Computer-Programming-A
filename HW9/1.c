#include <stdio.h>
#include <stdlib.h>

double Inner(double *a, double *b, int n)
{
    double inner = 0;
    for (int i = 0; i < n; i++)
    {
        inner += *(a + i) * *(b + i);
    }
    return inner;
}

int main()
{
    int n;
    double *a, *b;
    double inner;
    scanf("%d", &n);
    a = (double *)malloc(n * sizeof(double));
    b = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &*(a + i));
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &*(b + i));
    }
    inner = Inner(a, b, n);
    printf("%lf", inner);
}