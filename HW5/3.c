#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int soldiers[n];
    int death[n];
    for (int j = 0; j < n; j++)
    {
        soldiers[j] = 1;
    }
    int temp = 0;
    int cnt = 0;
    int i = 0;
    printf("前%d个被杀死人的顺序是: ", n - 1);
    while (cnt < n)
    {
        if (i == (n))
            i = 0;
        if (soldiers[i] == 1)
        {
            temp++;
            if (temp == m)
            {
                temp = 0;
                soldiers[i] = 0;
                death[cnt] = i + 1;
                cnt++;
            }
        }
        i++;
    }
    for ( i = 0; i < n - 1; i++)
    {
        printf("%d ", death[i]);
    }
    printf(",最后留下来的是：%d", death[n - 1]);
}
