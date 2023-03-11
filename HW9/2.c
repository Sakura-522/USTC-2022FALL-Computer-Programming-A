#include <stdio.h>
#include <math.h>

#define N 10000

double Integral(double a, double b, double (*fun)(double))
{
    double sum = 0, x = a;
    double h = (b - a) / N;
    for (int i = 0; i < N; i++)
    {
        sum += h * (*fun)(x);
        x += h;
    }
    return sum;
}

int main()
{
    double (*p)(double, double, double (*fun)(double)) = Integral;
    printf("sin x 在[0,1]上的积分值为：%lf\n", (*p)(0, 1, sin));
    printf("cos x 在[-1,1]上的积分值为：%lf\n", (*p)(-1, 1, cos));
    printf("exp x 在[0,2]上的积分值为：%lf\n", (*p)(0, 2, exp));
    return 0;
}