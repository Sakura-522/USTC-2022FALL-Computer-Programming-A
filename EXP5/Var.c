#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double Average(double a[], int n) //计算数组的平均值
{
    double sum = 0;
    double average;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    average = sum / n;
    return average;
}

double Var(double a[], int n) //计算数组的方差
{
    double sum = 0;
    double average, var;
    average = Average(a, n);
    for (int i = 0; i < n; i++)
    {
        sum += (a[i] - average) * (a[i] - average);
    }
    var = sum / n;
    return var;
}

int main(int argc, char *argv[])
{
    double var;
    double *a = (double *)malloc((argc - 1) * sizeof(double));
    for (int i = 0; i < argc - 1; i++)
    {
        a[i] = atof(argv[i + 1]);
    }
    var = Var(a, argc - 1);
    printf("Var is %lf", var);
    return 0;
}