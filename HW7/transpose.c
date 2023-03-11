#include <stdio.h>

void transpose(int matrix[][5])
{
    int t;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
        }
    }
    return;
}

int main()
{
    int matrix[5][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    printf("转置前：\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    transpose(matrix);
    printf("转置后：\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}