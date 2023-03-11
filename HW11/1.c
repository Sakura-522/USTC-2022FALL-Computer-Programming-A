#include <stdio.h>

int main()
{
    int n = 0, i = -1;
    char str[10000];
    FILE *fp, *fp1;
    printf("please enter n:\n");
    scanf("%d", &n);
    while (n >= 26)
    {
        n -= 26;
    }
    while (n < 0)
    {
        n += 26;
    }

    fp = fopen("secret.txt", "r");
    do
    {
        i++;
        str[i] = fgetc(fp);
    } while (str[i] != EOF);
    str[i] = '\0';
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = 'a' + (str[i] - 'a' + n) % 26;
        }
        else if (str[i] >= 'A' && str[i] <= 'z')
        {
            str[i] = 'A' + (str[i] - 'A' + n) % 26;
        }
        else
            continue;
    }
    fp1 = fopen("secret.txt", "w");
    fputs(str, (FILE *)fp1);
    fclose(fp1);
    return 0;
}