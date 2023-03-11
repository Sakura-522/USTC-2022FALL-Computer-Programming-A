#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int ArrLength = 0;
int PerLinePrintNum = 0;
int ElePrintWid = 0;
char CharElePrintWid[10];

struct ConfigVal
{
    int ArrLength, PerLinePrintNum, ElePrintWid;
};

void PrintArr(int *a, int n) //打印数组
{
    char type[20] = "%";
    char type1[10] = "d";
    //将type变成 %ElePrintWid d
    strcat(type, CharElePrintWid);
    strcat(type, type1);
    for (int i = 0; i < n; i++)
    {
        printf(type, a[i]);
        if ((i + 1) % PerLinePrintNum == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    return;
}

void FillArray(int a[], int n, int flag, int x, int y) //生成数组的样本数据
{
    switch (flag)
    {
    case 1: //用指定范围的随机数填充数组
        srand((unsigned)time(NULL));
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % (y - x + 1) + x;
        }
        break;

    case 2: //键盘输入
        printf("请输入%d个整数:\n", n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        break;

    case 3: //整个数组填同一个值
        for (int i = 0; i < n; i++)
        {
            a[i] = x;
        }
        break;

    case 4: //用等差序列填充数组
        for (int i = 0; i < n; i++)
        {
            a[i] = x + i * y;
        }
        break;
    default:
        break;
    }
    printf("已生成数组的样本数据\n");
    return;
}

void Config(struct ConfigVal cv) //配置系统参数：数组元素个数、一行打印元素个数、每个元素的打印宽度等
{
    ArrLength = cv.ArrLength;
    PerLinePrintNum = cv.PerLinePrintNum;
    ElePrintWid = cv.ElePrintWid;
    sprintf(CharElePrintWid, "%d", cv.ElePrintWid);
    printf("已配置系统参数");
    return;
}

void Delete(int a[], int n, int id) //删除指定下标的元素
{
    for (int i = id; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    ArrLength--;
    printf("已删除下标为%d的元素\n", id);
    return;
}

void DeleteVal(int a[], int n, int val) //删除指定值的元素
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == val)
        {
            count++;
            for (int j = i; j < n - 1; j++)
            {
                a[j] = a[j + 1];
            }
            i = -1;
            n--;
        }
    }
    ArrLength -= count;
    printf("已删除值为%d的元素,共%d个\n", val, count);
    return;
}

void DeleteRange(int a[], int n, int s, int t) //删除s..t下标区间的元素
{
    for (int i = s; i <= n && i + (t - s) + 1 < n; i++)
    {
        a[i] = a[i + t - s + 1];
    }
    ArrLength -= t - s + 1;
    printf("已删除下标从%d到%d的元素\n", s, t);
    return;
}

void Insert(int a[], int n, int pos, int val) //在数组中pos下标处插入新元素
{
    for (int i = n - 1; i >= pos; --i)
    {
        a[i + 1] = a[i];
    }
    a[pos] = val;
    ArrLength += 1;
    printf("已插入元素\n");
    return;
}

int isAsc(int a[], int n) //判断数组是否升序排列
{
    if (n == 0)
    {
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int isDesc(int a[], int n) //判断数组是否降序排列
{
    if (n == 0)
    {
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int OrderInsert(int a[], int n, int val) //在有序数组中插入新元素保持有序性
{
    int i;
    if (isAsc(a, n))
    {
        for (i = 0; i < n; i++)
        {
            if (a[i] >= val)
            {
                break;
            }
        }
        for (int j = n - 1; j >= i; j--)
        {
            a[j + 1] = a[j];
        }
        a[i] = val;
    }
    else if (isDesc(a, n))
    {
        for (i = 0; i < n; i++)
        {
            if (a[i] <= val)
            {
                break;
            }
        }
        for (int j = n - 1; j >= i; j--)
        {
            a[j + 1] = a[j];
        }
        a[i] = val;
    }
    else
    {
        return 0;
    }
    ArrLength += 1;
    printf("已插入元素\n");
    return 1;
}

int Max(int a[], int n) //返回数组最大值的下标
{
    int max = a[0];
    int max_pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            max_pos = i;
        }
    }
    return max_pos;
}

int Min(int a[], int n) //返回数组最小值的下标
{
    int min = a[0];
    int min_pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            min_pos = i;
        }
    }
    return min_pos;
}

float Average(int a[], int n) //计算数组的平均值
{
    float sum = 0;
    float average;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    average = sum / n;
    return average;
}

float Var(int a[], int n) //计算数组的方差
{
    float sum = 0;
    float average, var;
    average = Average(a, n);
    for (int i = 0; i < n; i++)
    {
        sum += (a[i] - average) * (a[i] - average);
    }
    var = sum / n;
    return var;
}

int Search(int a[], int n, int val) //普通查找
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == val)
        {
            return i;
        }
    }
    return -1;
}

int BiSearch(int a[], int n, int val) //二分查找
{
    int left = 0, right = n - 1, mid;
    if (isAsc(a, n))
    {
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (a[mid] > val)
            {
                right = mid - 1;
            }
            else if (a[mid] < val)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
    else if (isDesc(a, n))
    {
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (a[mid] < val)
            {
                right = mid - 1;
            }
            else if (a[mid] > val)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
    else
    {
        return -2;
    }
}

int isEqual(int a[], int n) //判断数组是否全相等
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != a[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

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

int Partition(int a[], int p, int r) //快速排序的partition步骤
{
    int x, i;

    x = a[r];
    i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (a[j] <= x)
        {
            i += 1;
            Swap(&a[i], &a[j]);
        }
    }
    Swap(&a[i + 1], &a[r]);
    return i + 1;
}

void QuickSort(int a[], int p, int r) //快速排序
{
    int q;
    if (p < r)
    {
        q = Partition(a, p, r); //用q分割为两个子问题
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
    return;
}

void Reverse(int a[], int n) //逆置数组
{
    for (int i = 0; i < n / 2; i++)
    {
        Swap(&a[i], &a[n - 1 - i]);
    }
    return;
}

int LeftRotate(int a[], int n, int m) //左旋m位，即向左循环移位m次，左端移出进入右端。例如 int b[10]={0,1,2,3,4,5,6,7,8,9}; 调用 LeftRotate(b,10,4)之后，b的元素为{4，5，6，7，8，9，0，1，2，3}
{
    int temp, i, j;
    for (i = 0; i < m; i++)
    {
        temp = a[0];
        for (j = 1; j < n; j++)
        {
            a[j - 1] = a[j];
        }
        a[j - 1] = temp;
    }
    return 0;
}

int RightRotate(int a[], int n, int m) //右旋m位
{
    int temp, i, j;
    for (i = 0; i < m; i++)
    {
        temp = a[n - 1];
        for (j = n - 1; j > 0; j--)
        {
            a[j] = a[j - 1];
        }
        a[0] = temp;
    }
    return 0;
}

void menu() //一级菜单
{
    printf("欢迎使用数组运算器\n");
    printf(
        "--------------------------------------------------\n"
        "序号|  功能\n"
        "0  |  退出\n"
        "1  |  配置系统参数\n"
        "2  |  生成样本数据\n"
        "3  |  显示数组\n"
        "4  |  删除\n"
        "5  |  插入\n"
        "6  |  统计\n"
        "7  |  查找\n"
        "8  |  判断\n"
        "9  |  排列数组元素\n"
        "--------------------------------------------------\n");
    printf("请输入功能序号:\n");
    return;
}
