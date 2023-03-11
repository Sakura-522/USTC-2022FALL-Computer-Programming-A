#include <stdio.h>
#include <stdlib.h>

struct SListNode
{
    int data;
    struct SListNode *next;
};

struct SListNode *creatList(int *a)
{
    struct SListNode *head, *p1, *p2;
    head = (struct SListNode *)malloc(sizeof(struct SListNode));
    head->next = NULL;
    p1 = head;
    for (int i = 0; i < 11; i++)
    {
        p2 = (struct SListNode *)malloc(sizeof(struct SListNode));
        p2->data = a[i];
        p2->next = NULL;
        p1->next = p2;
        p1 = p2;
    }
    p1 = head->next;
    while (p1)
    {
        printf("%3d", p1->data);
        p1 = p1->next;
    }
    printf("\n");
    return head;
}

struct SListNode *reverse(struct SListNode *head)
{
    struct SListNode *p, *q = head->next, *rev;
    rev = (struct SListNode *)malloc(sizeof(struct SListNode));
    rev->next = NULL;
    while (q)
    {
        p = (struct SListNode *)malloc(sizeof(struct SListNode));
        p->data = q->data;
        p->next = rev->next;
        rev->next = p;
        q = q->next;
    }
    p = rev->next;
    while (p)
    {
        printf("%3d", p->data);
        p = p->next;
    }
    printf("\n");
    return rev;
}

struct SListNode *findmidnode(struct SListNode *head)
{
    struct SListNode *fast = head, *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    printf("%d", slow->data);
    return slow;
}

int main()
{
    int a[11] = {8, 94, 15, 10, 45, 6, 21, 38, 19, 82, 70};
    struct SListNode *s_raw, *s_reverse, *mid;
    s_raw = creatList(a);
    s_reverse = reverse(s_raw);
    mid = findmidnode(s_reverse);
    return 0;
}