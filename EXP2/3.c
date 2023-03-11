# include<stdio.h>

int main()
{
    char a;
    printf("请输入字符(以0结束)：\n");
    while (1)
    {
        a = getchar();
        if (a == '0')
        {
            break;
        }
        if (a>=65 && a<=90)
        {
            printf("'%c' 已经是大写字母\n", a);
        }
        else if (a>=97 && a<=122)
        {
            printf("%c\n", a-32);
        }
        else
        {
            printf("'%c' 不是字母\n", a);
        }
    }
    return 0;
}