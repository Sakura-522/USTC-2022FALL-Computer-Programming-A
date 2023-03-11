#include <stdio.h>
#include <stdlib.h>

#define swap(A, B, TYPE) \
    {                    \
        TYPE temp;       \
        temp = A;        \
        A = B;           \
        B = temp;        \
    }

typedef struct PolyNode
{
    float a;               //系数
    int e;                 //指数
    struct PolyNode *next; //指向下一个结点
} PNode, *PtrPNode;

void BubbleSort(float *a, int *e, int n) //冒泡排序
{
    for (int i = n - 1; i > 0; --i)
    {
        for (int j = 0; j < i; j++)
        {
            if (e[j] < e[j + 1])
            {
                swap(e[j], e[j + 1], int);
                swap(a[j], a[j + 1], float);
            }
        }
    }
    return;
}

PtrPNode Init(int n) // 尾插法
{
    PtrPNode head, p1, p2;
    float *a;
    int *e;
    a = (float *)malloc(n * sizeof(float));
    e = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%f %d", &a[i], &e[i]);
    }
    BubbleSort(a, e, n);
    head = (PtrPNode)malloc(sizeof(PNode));
    head->next = NULL;
    p1 = head;
    for (int i = 0; i < n; i++)
    {
        p2 = (PtrPNode)malloc(sizeof(PNode));
        p2->next = NULL;
        p2->a = a[i];
        p2->e = e[i];
        // scanf("%f %d", &p2->a, &p2->e);
        p1->next = p2;
        p1 = p2;
    }
    return head;
}

void Print(PtrPNode head)
{
    PtrPNode temp = head->next, last = head;
    int flag = 0;
    while (temp) // temp 为 NULL 即到达链表末尾
    {
        if (temp->a > 0)
        {
            printf("+%fX^%d", temp->a, temp->e);
            flag = 1;
        }
        else if (temp->a == 0)
        {
            last->next = temp->next;
            free(temp);
            temp = last->next;
            continue;
        }
        else
        {
            printf("%fX^%d", temp->a, temp->e);
            flag = 1;
        }
        temp = temp->next;
        last = last->next;
    }
    if (!flag)
    {
        printf("%d", 0);
    }

    printf("\n");
    return;
}

PtrPNode Sum(PtrPNode head1, PtrPNode head2)
{
    PtrPNode temp1 = head1->next, temp2 = head2->next; // 用于遍历两个链表
    PtrPNode L, head, temp;                            // 用于存储求和后的结果
    head = (PtrPNode)malloc(sizeof(PNode));
    head->next = NULL;
    L = head;
    while (temp1 && temp2) // 两个链表均未结束
    {
        if (temp1->e > temp2->e)
        {
            temp = (PtrPNode)malloc(sizeof(PNode));
            temp->next = NULL;
            temp->a = temp1->a;
            temp->e = temp1->e;
            L->next = temp;
            L = temp;
            temp1 = temp1->next;
        }
        else if (temp1->e < temp2->e)
        {
            temp = (PtrPNode)malloc(sizeof(PNode));
            temp->next = NULL;
            temp->a = temp2->a;
            temp->e = temp2->e;
            L->next = temp;
            L = temp;
            temp2 = temp2->next;
        }
        else // 两项指数相等，那么系数相加
        {
            temp = (PtrPNode)malloc(sizeof(PNode));
            temp->next = NULL;
            temp->a = temp1->a + temp2->a;
            temp->e = temp1->e;
            L->next = temp;
            L = temp;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    if (temp1) // 链表1未结束，将剩余部分复制到L后
    {
        L->next = temp1;
    }
    if (temp2) // 链表2未结束，将剩余部分复制到L后
    {
        L->next = temp2;
    }
    return head;
}

int main()
{
    int n;
    PtrPNode head1, head2, head;
    printf("请输入第一个多项式的非零项的个数：\n");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("非零项的个数需要为正数！");
        return 0;
    }
    printf("请依次输入系数和指数：\n");
    head1 = Init(n);
    printf("请输入第二个多项式的非零项的个数：\n");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("非零项的个数需要为正数！");
        return 0;
    }
    printf("请依次输入系数和指数：\n");
    head2 = Init(n);
    Print(head1);
    Print(head2);
    head = Sum(head1, head2);
    printf("求和结果为：\n");
    Print(head);
    return 0;
}