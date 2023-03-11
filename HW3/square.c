# include<stdio.h>

int main()
{
    int x, y;
    printf("Please enter the coordinate:\n");
    scanf("%d %d", &x, &y);
    if (x <= 2 && x >= -2 && y <= 2 && y >= -2)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}