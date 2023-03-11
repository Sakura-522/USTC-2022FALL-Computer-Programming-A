#include <math.h>
#include <stdio.h>

int main()
{
    double x, y, z, p, s;
    printf("请输入三条边长：\n");
    scanf("%lf %lf %lf", &x, &y, &z);
    if (x < 0 || y < 0 || z < 0)
    {
        printf("边长不能小于0");
        return 0;
    }

    if (x + y > z && y + z > x && z + x > y)
    {
        if (x == y && y == z)
        {
            printf("边长为%lf,%lf,%lf是一个等边三角形", x, y, z);
        }
        else if (x == y || y == z || z == x)
        {
            printf("边长为%lf,%lf,%lf是一个等腰三角形", x, y, z);
        }
        else if (x * x + y * y == z * z || x * x + z * z == y * y || y * y + z * z == x * x)
        {
            printf("边长为%lf,%lf,%lf是一个直角三角形", x, y, z);
        }
        else
        {
            printf("边长为%lf,%lf,%lf是一个普通三角形", x, y, z);
        }
        p = (x + y + z) / 2;
        s = sqrt(p * (p - x) * (p - y) * (p - z));
        printf(",其面积为%lf\n", s);
    }
    else
    {
        printf("ERROR");
    }
}