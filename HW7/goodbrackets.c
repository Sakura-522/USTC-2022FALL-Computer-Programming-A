#include <stdio.h>

int goodbrackets( char str[])
{
    int i = 0, count = 0;
    while (str[i] != '\0')
    {
        if (str[i]=='(')
        {
            count++;
        }
        else if (str[i] == ')')
        {
            count--;
        }
        if (count < 0)
        {
            return 0;
        }
        i++;
    }
    if (count == 0)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int flag;
    char str[50];
    gets(str);
    flag = goodbrackets(str);
    if (flag)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}