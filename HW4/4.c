#include <stdio.h>

int main()
{
    int pri[500] = {0};
    int c = 1, j = 0;
    pri[0] = 2;
    for (int i = 1; (2 * i + 1) <= 500; i++)
    {
        for (j = 0; j < c; j++)
        {
            if ((2 * i + 1) % pri[j] == 0)
            {
                break;
            }
        }
        if (j == c)
        {
            c += 1;
            pri[c - 1] = 2 * i + 1;
        }
    }
    if (c < 10)
    {
        printf("没有10个素数");
    }
    else
    {
        int sum = 0;
        for (int n = c - 10; n < c - 1; n++)
        {
            printf("%d+", pri[n]);
            sum = sum + pri[n];
        }
        sum = sum + pri[c - 1];
        printf("%d = %d", pri[c - 1], sum);
    }
    return 0;
}