#include <stdio.h>

int main()
{
    int n, k;
    printf("请输入n值(n>=2)：\n");
    scanf("%d", &n);
    if (n<2)
    {
        printf("n的值不能小于2");
        return 0;
    }
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%-3d", k);
            k++;
        }
        
        printf("\n");
    }
    */
    for (int i = n; i >= 1; i--)
    {
        k = i * (i + 1) / 2;
        for (int j = i - 1; j >= 0; j--)
        {
            printf("%-3d", k - j);
        }
        
        printf("\n");
    }
    return 0;
}