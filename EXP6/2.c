#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int PID;
    int score;
    struct node *next;
} Node, *PNode;

PNode Init(int n) // 尾插法
{
    PNode head, p1, p2;
    head = (PNode)malloc(sizeof(Node));
    head->next = NULL;
    p1 = head;
    for (int i = 0; i < n; i++)
    {
        p2 = (PNode)malloc(sizeof(Node));
        p2->next = NULL;
        scanf("%d %d", &p2->PID, &p2->score);
        if (p2->score <0 || p2->score > 100)
        {
            printf("成绩不合法\n");
            return NULL;
        }
        p1->next = p2;
        p1 = p2;
    }
    return head;
}

void Print(PNode head)
{
    PNode temp = head->next;
    while (temp)
    {
        printf("%d %d\n", temp->PID, temp->score);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

PNode Sort(PNode head) // 冒泡排序
{
    int count = 0;
    PNode temp = head->next;
    PNode last = head; // 指向上一个结点
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    for (int i = count - 1; i > 0; --i)
    {
        last = head;
        temp = head->next;
        for (int j = 0; j < i; j++, last = last->next)
        {
            if (temp->PID > temp->next->PID)
            {
                last->next = temp->next;
                temp->next = temp->next->next;
                last->next->next = temp;
            }
            else
            {
                temp = temp->next; // 若未发生交换，则正常继续遍历
            }
        }
    }

    // for (int i = count - 1; i > 0; --i)
    // {
    //     temp = head->next;
    //     for (int j = 0; j < i; j++, temp = temp->next)
    //     {
    //         if (temp->PID > temp->next->PID)
    //         {
    //             Swap(&temp->PID, &temp->next->PID);
    //             Swap(&temp->score, &temp->next->score);
    //         }
    //     }
    // }
    return head;
}

int correct(PNode head1, PNode head2, int m, int n)
{
    PNode temp1 = head1->next, temp2 = head2->next;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (temp1->PID == temp2->PID)
            {
                return 0;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
        temp2 = head2->next;
    }
    return 1;
}

PNode Merge(PNode head1, PNode head2, int m, int n)
{
    int flag;
    flag = correct(head1, head2, m, n);
    if (!flag)
    {
        printf("学号重复！\n");
        return NULL;
    }
    PNode temp = head1->next;
    while (temp->next) // 找到链表结尾
    {
        temp = temp->next;
    }
    temp->next = head2->next;
    head1 = Sort(head1);
    return head1;
}

int main()
{
    int m, n;
    PNode head1, head2, head;
    printf("请输入第一个链表元素的个数：\n");
    scanf("%d", &m);
    printf("请依次输入学号和成绩：\n");
    head1 = Init(m);
    if (!head1)
    {
        return 0;
    }
    printf("请输入第二个链表元素的个数：\n");
    scanf("%d", &n);
    printf("请依次输入学号和成绩：\n");
    head2 = Init(n);
    if (!head2)
    {
        return 0;
    }
    // Print(head1);
    // Print(head2);
    head = Merge(head1, head2, m, n);
    if (!head)
    {
        return 0;
    }
    printf("结果：\n");
    Print(head);
    return 0;
}