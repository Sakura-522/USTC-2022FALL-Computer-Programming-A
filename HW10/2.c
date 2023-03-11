#include <stdio.h>
#include <stdlib.h>

struct student
{
    int stunum;           //学号
    char name[20];        //姓名
    float examscore;      //考试成绩
    float labscore;       //实验成绩
    float totalmark;      //总评成绩
    struct student *next; //下一个结点
};

struct student *Sort(struct student *head) // 冒泡排序
{
    int count = 0;
    struct student *temp = head->next;
    struct student *last = head; // 指向上一个结点
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
            if (temp->totalmark > temp->next->totalmark)
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
    return head;
}

struct student *create(int n)
{
    struct student *head, *p1, *p2;
    head = (struct student *)malloc(sizeof(struct student));
    head->next = NULL;
    p1 = head;
    for (int i = 0; i < n; i++)
    {
        p2 = (struct student *)malloc(sizeof(struct student));
        p2->next = NULL;
        scanf("%d %s %f %f", &p2->stunum, p2->name, &p2->examscore, &p2->labscore);
        p2->totalmark = 0.6 * p2->examscore + 0.4 * p2->labscore;
        p1->next = p2;
        p1 = p2;
    }
    head = Sort(head);
    return head;
}

struct student *delete(struct student *head, int stunum)
{
    struct student *temp = head->next, *last = head;
    int flag = 0; // 判断是否找到要删除的结点
    while (temp)
    {
        if (temp->stunum == stunum)
        {
            last->next = temp->next;
            free(temp); // 释放内存
            temp = last->next;
            flag = 1;
            continue; // 若删除成功那么temp与last均不必更新
        }
        last = last->next;
        temp = temp->next;
    }
    if (!flag)
    {
        printf("未找到要删除的学号！\n");
    }
    
    return head;
}

struct student *insert(struct student *head)
{
    struct student *p1;
    printf("请输入待插入的学生信息：\n");
    p1 = (struct student *)malloc(sizeof(struct student));
    scanf("%d %s %f %f", &p1->stunum, p1->name, &p1->examscore, &p1->labscore);
    p1->totalmark = 0.6 * p1->examscore + 0.4 * p1->labscore;
    p1->next = head->next;
    head->next = p1;
    head = Sort(head); // 维护有序性质
    printf("插入成功：\n");
    return head;
}

void Print(struct student *head)
{
    struct student *temp;
    temp = head->next;
    while (temp)
    {
        printf("%d %s %f\n", temp->stunum, temp->name, temp->totalmark);
        temp = temp->next;
    }
    return;
}

int main()
{
    struct student *head;
    int stunum = 11111;
    freopen("score.txt", "r", stdin);
    printf("创建链表：\n");
    head = create(10);
    Print(head);
    printf("插入结点：\n");
    head = insert(head);
    Print(head);
    printf("删除结点，学号为 %d ：\n",stunum);
    head = delete(head, stunum);
    Print(head);
    printf("删除结点，学号为 111 (不存在)：\n");
    head = delete(head, 111);
    Print(head);
    return 0;
}