#include <stdio.h>

int main()
{
    int a[20] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int b[10] = {1, 43, 72, 23, 9, 87, 54, 3, 55, 0};
    int temp, i, j;
    for (i = 10; i < 20; i++)
    {
        a[i] = b[i - 10];
    }
    
    for (i = 0; i < 20; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
    for (i = 0; i < 20; i++)
    {
        printf("%d\n", a[i]);
    }
    
    return 0;
}