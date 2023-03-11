#include <stdio.h>

int main()
{
    int n;
    printf("Please enter a odd number :\n");
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        printf("ERROR! The number is an even number.");
        return 0;
    }
    for (int i = 0; i < n / 2 + 1; i++)
    {
        for (int j = 0;j < n / 2 - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        for (int j = 0;j < n / 2 - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}