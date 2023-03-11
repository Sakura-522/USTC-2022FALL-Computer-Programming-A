# include <stdio.h>

double fabs(double a, double b)
{
    double result = b - a;
    if (result < 0 )
    {
        result = -result;
    }
    return result;
}

int main()
{
    double a, b, result;
    printf("Please enter two numbers:\n");
    scanf("%lf %lf", &a, &b);
    result = fabs(a, b);
    printf("The result is %lf\n", result);
    printf("The result is %lf\n", a>b?a-b:b-a);
    return 0;
}