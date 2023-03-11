#include <stdio.h>

int wordcounter(char str[])
{
    int i = 0;
    int cnt = 0, word = 0;
    while (str[i] != '\0')
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
        {
            word = 0;
        }
        else if (word == 0)
        {
            word = 1;
            cnt += 1;
        }
        i++;
    }
    return cnt;
}

int main()
{
    int result;
    char str[100];
    gets(str);
    result = wordcounter(str);
    printf("the result is %d", result);
    return 0;
}