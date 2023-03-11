#include <stdio.h>
#include <math.h>

int main()
{
    double x, change;
    double m[11] = {100, 50, 20, 10, 5, 1, 0.5, 0.1, 0.05, 0.02, 0.01};
    int num[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // 用于存储钱的张数
    char ch0[] = "100元";
    char ch1[] = "50元";
    char ch2[] = "20元";
    char ch3[] = "10元";
    char ch4[] = "5元";
    char ch5[] = "1元";
    char ch6[] = "5角";
    char ch7[] = "1角";
    char ch8[] = "5分";
    char ch9[] = "2分";
    char ch10[] = "1分";
    char *arr[] = {ch0, ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8, ch9, ch10};
    scanf("%lf", &x);
    if (x < 0)
    {
        printf("ERROR!OUT OF RANGE!");
        return 0;
    }
    if (x > 100)
    {
        printf("买不起。");
        return 0;
    }
    if (x == 100)
    {
        printf("不用找零");
        return 0;
    }
    
    change = 100 - x + 0.0000001;
    //printf("%lf", change - 0.05 - 0.02 - 0.02 - 0.01 + 0.0000001);
    
    for (int i = 0; i < 11; i++)
    {
        while (change >= m[i])
        {
            num[i]++;
            change -= m[i];
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (num[i] != 0)
        {
            printf("%d 个 %s的\n", num[i], arr[i]);
        }
    }
    
    return 0;
}