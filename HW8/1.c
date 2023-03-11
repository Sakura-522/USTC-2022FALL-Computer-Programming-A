#include <stdio.h>

int main()
{
    char c[200];
    gets(c);
    int end[200];
    int len[200] = {0}, maxlen = 0;
    int i = 0, j = 0;
    int cnt;
    while (*(c + i))
    {
        if (!((*(c + i) >= 'a' && *(c + i) <= 'z') || (*(c + i) >= 'A' && *(c + i) <= 'Z')))
        {
            if (*(len + j) > maxlen)
            {
                maxlen = *(len + j);
            }
            *(end + j) = i;
            j++;
        }
        else
        {
            *(len + j) += 1;
        }
        i++;
    }
    *(end + j) = i;
    cnt = j;
    i = 0;
    for (i = 0; i <= cnt; i++)
    {
        if (*(len + i) == maxlen)
        {
            for (j = *(end + i) - maxlen; j < *(end + i); j++)
            {
                printf("%c", *(c + j));
            }
            printf("\n");
        }
    }
    return 1;
}
