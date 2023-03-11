# include<stdio.h>


float calculateFloat(float x)
{
    if(x >= 0 && x < 10)
    {
        return x;
    }
    else if (x >= 10 && x < 20)
    {
        return x * x + 1;
    }
    else if (x >= 20 && x < 30)
    {
        return x * x * x + x * x + 1;
    }
}


int calculateInt(int x)
{
    int flag;
    if(x >= 0 && x < 10)
    {
        flag = 1;
    }
    else if (x >= 10 && x < 20)
    {
        flag = 2;
    }
    else if (x >= 20 && x < 30)
    {
        flag = 3;
    }
    switch (flag)
    {
    case 1:
        return x;
        break;
    
    case 2:
        return x * x + 1;
        break;

    case 3:
        return x * x * x + x * x + 1;
        break;

    default:
        break;
    }
}


int main()
{
    int x1, result1;
    float x2, result2;
    printf("Please enter a number(int) in [0,30):\n");
    scanf("%d", &x1);
    if (x1<0 || x1>=30)
    {
        printf("ERROR!The number is out of range");
        return 0;
    }
    result1 = calculateInt(x1);
    printf("if x=%d,y=%d\n", x1, result1);
    printf("Please enter a number(float) in [0,30):\n");
    scanf("%f", &x2);
    if (x2<0 || x2>=30)
    {
        printf("ERROR!The number is out of range");
        return 0;
    }
    result2 = calculateFloat(x2);
    printf("if x=%f,y=%f", x2, result2);
    return 0;
}