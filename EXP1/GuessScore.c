# include <stdio.h>

int main()
{
    int n = 5, guess, counter = 1;
    printf("下面进行猜分数游戏，分数值为0~10间的整数，共有三次猜测机会。\n");
    while (counter <= 3)
    {
    printf("请输入猜测的值:\n");
    scanf("%d", &guess);
    printf("第%d次猜测结果:\n", counter);
    if (guess == n)
    {
        printf("猜对了！");
        return 0;
    }
    else if (guess < n)
    {
        if (counter == 3)
        {
            printf("猜小了(剩余机会：%d)\n", 3 - counter);
            break;
        }
        printf("猜小了，再来一次(剩余机会：%d)\n", 3 - counter);
    }
    else if (guess > n)
    {
        if (counter == 3)
        {
            printf("猜大了(剩余机会：%d)\n", 3 - counter);
            break;
        }
        printf("猜大了，再来一次(剩余机会：%d)\n", 3 - counter);
    }
    counter++;
    }
    printf("对不起，您的猜测机会已用光，实际的分数值为：%d", n);
    return 0;
}