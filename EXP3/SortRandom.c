#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap(int *a, int *b) //交换两个数
{
    int temp = *a;
    *a = *b;
    *b = temp;
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

int main()
{
    int rand_num[32];
    srand((unsigned)time(NULL));
    printf("生成的随机数组");
    for (int i = 0; i < 32; i++)
    {
        rand_num[i] = rand() % (1000 - 100 + 1) + 100;
        printf("%d ", rand_num[i]);
    }
    printf("\n");
    QuickSort(rand_num, 0, 31);
    printf("排序后的数组");
    for (int i = 0; i < 32; i++)
    {
        printf("%d ", rand_num[i]);
    }
    return 0;
}