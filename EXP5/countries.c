#include <stdio.h>
#include <string.h>

void InsertSort1(char *order[], int n)
{
    char *temp;
    int i, j;
    for (i = 0; i < n; i++)
    {
        temp = order[i];
        for (j = i - 1; j >= 0 && (int)strlen(order[j]) > (int)strlen(temp); j--)
        {
            order[j + 1] = order[j];
        }
        order[j + 1] = temp;
    }
    return;
}

void InsertSort2(char *order[], int n)
{
    char *temp;
    int i, j;
    for (i = 0; i < n; i++)
    {
        temp = order[i];
        for (j = i - 1; j >= 0 && (strcmp(order[j], temp) == 1); j--)
        {
            order[j + 1] = order[j];
        }
        order[j + 1] = temp;
    }
    return;
}

int main()
{
    char countries[10][40] = {"Saint Vincent and the Grenadines",
                              "El Salvador",
                              "Papua New Guinea",
                              "Niue",
                              "Norfolk Island",
                              "United Arab Emirates",
                              "United Kingdom",
                              "United States",
                              "Slovenia",
                              "Solomon Islands"};
    char *order1[10], *order2[10];
    for (int i = 0; i < 10; i++)
    {
        order1[i] = countries[i];
        order2[i] = countries[i];
    }
    InsertSort1(order1, 10);
    InsertSort2(order2, 10);
    printf("按串长排序:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", order1[i]);
    }
    printf("按ASCII码排序:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", order2[i]);
    }
    return 0;
}