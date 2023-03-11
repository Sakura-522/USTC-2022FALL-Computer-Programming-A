#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b) //交换两个数
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void BubbleSort(int a[], int n) //冒泡排序
{
    for (int i = n - 1; i > 0; --i)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                Swap(&a[j], &a[j + 1]);
            }
        }
    }
    return;
}

void SelectSort(int a[], int n) //选择排序
{
    int flag;
    for (int i = 0; i < n; i++)
    {
        flag = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[flag])
            {
                flag = j;
            }
        }
        Swap(&a[i], &a[flag]);
    }
    return;
}

void InsertSort(int a[], int n) //插入排序
{
    int temp, i, j;
    for (i = 0; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
    return;
}

float OrderSearch(int data[], int key[])
{
    printf("顺序查找:\n");
    int cmp[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float cmp1 = 0, cmp2 = 0;
    int cnt = 0, j;
    for (int i = 0; i < 10; i++)
    {
        for (j = 0; j < 500; j++)
        {
            cmp[i] += 1;
            if (key[i] == data[j])
            {
                break;
            }
        }
        if (j == 500)
        {
            cmp2 = cmp2 + cmp[i];
            cnt += 1;
            printf("key[%d]=%d不存在,比较次数：%d\n", i, key[i], cmp[i]);
        }
        else
        {
            cmp1 = cmp1 + cmp[i];
            printf("key[%d]=%d存在,比较次数：%d\n", i, key[i], cmp[i]);
        }
    }
    cmp1 = cmp1 / (10 - cnt);
    return cmp1;
}

void Sort(int data[])
{
    int flag;
    printf("请输入要选择的排序方法：\n");
    printf("1.冒泡法\n"
           "2.选择法\n"
           "3.插入法\n");
    scanf("%d", &flag);
    switch (flag)
    {
    case 1:
        BubbleSort(data, 500);
        break;

    case 2:
        SelectSort(data, 500);
        break;

    case 3:
        InsertSort(data, 500);
        break;

    default:
        printf("wrong number!");
        return;
        break;
    }
    printf("排序成功！\n");
    return;
}

float BinarySearch(int data[], int key[])
{
    int left, right, mid, find;
    int cmpB[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float cmp1 = 0, cmp2 = 0;
    int cnt = 0;
    printf("二分查找:\n");
    for (int i = 0; i < 10; i++)
    {
        find = 0;
        left = 0;
        right = 499;
        while (left <= right)
        {
            cmpB[i]++;
            mid = (left + right) / 2;
            if (data[mid] > key[i])
            {
                right = mid - 1;
            }
            else if (data[mid] < key[i])
            {
                left = mid + 1;
            }
            else
            {
                find = 1;
                cmp1 += cmpB[i];
                cnt++;
                printf("key[%d]=%d存在,比较次数：%d\n", i, key[i], cmpB[i]);
                break;
            }
        }
        if (!find)
        {
            cmp2 += cmpB[i];
            printf("key[%d]=%d不存在,比较次数：%d\n", i, key[i], cmpB[i]);
        }
    }
    cmp1 = cmp1 / (10 - cnt);
    return cmp1;
}

int main()
{
    float order, binary;
    int data[500];
    int key[10] = {9, 53, 368, 1064, 1753, 1, 271, 799, 1968, 1997};
    srand(1);
    for (int i = 0; i < 500; i++)
    {
        data[i] = rand() % 2000;
    }
    order = OrderSearch(data, key);
    printf("顺序查找当key值存在时，查找一个key值平均进行了%.2f次比较\n\n", order);
    Sort(data);
    for (int i = 0; i < 500; i++)
    {
        printf("%d  ", data[i]);
    }
    
    binary = BinarySearch(data, key);
    printf("二分查找当key值存在时，查找一个key值平均进行了%.2f次比较\n\n", binary);
    return 0;
}