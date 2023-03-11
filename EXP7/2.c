#include <math.h>
#include <stdio.h>

#define PI 3.1415926

FILE *fp;

void table(double (*f)(double), double first, double last, double incr)
{
    int num = (int)(last - first) / incr;
    double x;
    for (int i = 0; i < num; i++)
    {
        x = first + i * incr;
        fprintf(fp, "%11.6lf %11.6lf\n", x, f(x));
    }
    return;
}

int main()
{
    double first = 0, last = PI, incr = PI / 3;
    // scanf("%lf %lf %lf", &first, &last, &incr);
    fp = fopen("三角函数表.txt", "w");
    fprintf(fp, "   Trigonometric table");
    fprintf(fp, "\n      x         sin(x)\n   --------------------\n");
    table(sin, first, last, incr);
    fprintf(fp, "\n      x         cos(x)\n   --------------------\n");
    table(cos, first, last, incr);
    fprintf(fp, "\n      x         tan(x)\n   --------------------\n");
    table(tan, first, last, incr);
    return 0;
}