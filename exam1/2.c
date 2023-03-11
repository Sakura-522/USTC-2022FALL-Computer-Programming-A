#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *p, temp;
    FILE *fp;
    fp = fopen("1.txt", "r");
    fscanf(fp, "%d", &n);
    p = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &p[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > i; --j)
        {
            if (p[j] < p[j - 1])
            {
                temp = p[j];
                p[j] = p[j - 1];
                p[j - 1] = temp;
            }
            
        }
    }
    if (n%2==0)
    {
        printf("%f", (float)(p[(n - 1) / 2] + p[(n - 1) / 2 + 1]) / 2);
        return 0;
    }
    printf("%d", p[(n - 1) / 2]);
    return 0;
}