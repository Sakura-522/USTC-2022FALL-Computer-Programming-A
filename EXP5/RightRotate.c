#include <stdio.h>
#include <string.h>

void RightRotate0(char *a, int n, int m) //右旋m位
{
    char temp;
    int i, j;
    for (i = 0; i < m; i++)
    {
        temp = *(a + n - 1);
        for (j = n - 1; j > 0; j--)
        {
            *(a + j) = *(a + j - 1);
        }
        *a = temp;
    }
    return;
}

void RightRotate1(char *a, int n, int m)
{
    char str[50];
    for (int i = 0; i < n; i++)
    {
        *(str + (i + m) % strlen(a)) = *(a + i);
    }
    for (int i = 0; i < n; i++)
    {
        *(a + i) = *(str + i);
    }
    return;
}

int main()
{
    int i, n;
    char str0[500], str[51];
    str[50] = '\0';
    gets(str0);
    for (i = 0; i < 50 && str0[i] != '\0'; i++)
    {
        str[i] = str0[i];
    }
    printf("请输入右旋位数:\n");
    scanf("%d", &n);
    n = n % strlen(str);
    RightRotate1(str, strlen(str), n);
    printf("%s\n", str);
    return 0;
}