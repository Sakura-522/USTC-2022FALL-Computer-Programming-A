#include <stdio.h>
#include <stdlib.h>

int main()
{
    //freopen("score50.txt", "r", stdin);
    int ss[50][4];
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &ss[i][j]);
        }
    }
    //fclose(stdin);
    float s[50];
    for (int i = 0; i < 50; i++)
    {
        s[i] = (ss[i][1] + ss[i][2] + ss[i][3]) / 3.0;
    }
    //QuickSort
    int temp;
    for (int i = 0; i < 50 - 1; i++)
    {
        for (int j = 0; j < 50 - i - 1; j++)
        {
            if (s[j] < s[j + 1])
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    //BinarySearch
    int low = 0, high = 49, mid = (low + high) / 2;
    int p;
    while (1)
    {
        if (s[mid] == 85)
        {
            if (s[mid + 1] == 85)
            {
                mid = mid + 1;
            }
            else
            {
                p = mid;
                break;
            }
        }
        else if (s[mid] < 85)
        {
            if (s[mid - 1] >= 85)
            {
                p = mid - 1;
                break;
            }
            else
            {
                high = mid;
                mid = (low + mid) / 2;
            }
        }
        else
        {
            low = mid;
            mid = (mid + high) / 2;
        }
    }
    //输出
    printf("平均分85分及以上共有：%d人\n", p + 1);
    printf("所有人平均成绩从高到低为：\n");
    for (int i = 0; i < 50; i++)
    {
        printf("%f\n", s[i]);
    }
    return 0;
}
