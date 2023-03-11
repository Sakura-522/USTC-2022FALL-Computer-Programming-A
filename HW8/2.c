#include <stdio.h>

// int temp[100][100];
void Swap(int *a, int *b) //交换两个数
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void BubbleSort(int *a, int n) //冒泡排序
{
    for (int i = n - 1; i > 0; --i)
    {
        for (int j = 0; j < i; j++)
        {
            if (*(a + j) > *(a + j + 1))
            {
                Swap(a + j, a + j + 1);
            }
        }
    }
    return;
}
/*
void min4Corner(int *address, int n)
{
    int k = 4;
    BubbleSort(address, n * n);
    **temp = *address;
    *(*(temp) + n - 1) = *(address + 1);
    *(*(temp + n - 1)) = *(address + 2);
    *(*(temp + n - 1) + n - 1) = *(address + 3);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (((i == 0) && (j == 0)) || ((i == 0) && (j == n - 1)) || ((i == n - 1) && (j == 0)) || ((i == n - 1) && (j == n - 1)))
            {
                continue;
                ;
            }
            else
            {
                *(*(temp + i) + j) = *(address + k);
                k++;
            }
        }
    }
}
*/

void min4Corner(int *address, int n)
{
    int temp[10000];
    int j = 4;
    BubbleSort(address, n * n);
    *temp = *address;
    *(temp + n - 1) = *(address + 1);
    *(temp + n * (n - 1)) = *(address + 2);
    *(temp + n * n - 1) = *(address + 3);

    for (int i = 0; i < n * n; i++)
    {
        if ((i != 0) && (i != n - 1) && (i != n * (n - 1)) && (i != n * n - 1))
        {
            *(temp + i) = *(address + j);
            j++;
        }
    }
    for (int i = 0; i < n * n; i++)
    {
        *(address + i) = *(temp + i);
    }
    return;
}

int main()
{
    int address[10000];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n * n; i++)
    {
        scanf("%d", address + i);
    }
    min4Corner(address, n);
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d", *(*(temp + i) + j));
        }
        printf("\n");
    }
    */

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d", *(address + i * n + j));
        }
        printf("\n");
    }

    return 0;
}