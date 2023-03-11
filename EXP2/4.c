# include<stdio.h>
# include<math.h>

int main()
{
    int n = 1;
    double temp, result;
    temp = 1;
    while (fabs(temp) > 1e-6)
    {
        n++;
        result += temp;
        temp = pow(-1, n - 1) / (2 * n - 1);
    }
    printf("PI = %lf", 4 * result);
    return 0;
}