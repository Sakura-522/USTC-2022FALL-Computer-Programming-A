#include <stdio.h>

struct student
{
    int stunum;      //学号
    char name[20];   //姓名
    float examscore; //考试成绩
    float labscore;  //实验成绩
    float totalmark; //总评成绩
};

void Sort(struct student *parray[], int n)
{
    int i, j;
    struct student *temp;
    for (i = 0; i < n; i++)
    {
        temp = parray[i];
        for (j = i - 1; j >= 0 && parray[j]->totalmark > temp->totalmark; j--)
        {
            parray[j + 1] = parray[j];
        }
        parray[j + 1] = temp;
    }
    return;
}

int main()
{
    struct student student[10];
    struct student *parray[10];
    freopen("score.txt", "r", stdin);
    for (int i = 0; i < 10; i++)
    {
        scanf("%d %s %f %f", &student[i].stunum, student[i].name, &student[i].examscore, &student[i].labscore);
        student[i].totalmark = 0.6 * student[i].examscore + 0.4 * student[i].labscore;
        // printf("%d %s %f %f %f\n", student[i].stunum, student[i].name, student[i].examscore, student[i].labscore, student[i].totalmark);
        parray[i] = student + i;
    }
    Sort(parray, 10);
    for (int i = 0; i < 10; i++)
    {
        // printf("%d %s %f %f %f\n", parray[i]->stunum, parray[i]->name, parray[i]->examscore, parray[i]->labscore, parray[i]->totalmark);
        printf("%d %s %f\n", parray[i]->stunum, parray[i]->name, parray[i]->totalmark);
    }
    return 0;
}