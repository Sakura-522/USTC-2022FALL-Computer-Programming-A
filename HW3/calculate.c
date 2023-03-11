# include<stdio.h>

int main()
{
    int a=2, b=3, c=4;
    float x=3.5, y=4.8;
    printf("%f\n", 3.5+1/2+56%10);
    a--;
    printf("%f\n", a++ * 1 / 3);
    printf("%f\n", x + a % 3 * (int)(x + y) % 2 / 4);
    printf("%f\n", (float)(a+b)/2+(int)x%(int)y);
    printf("%d\n", b > c && b == c);
    printf("%d\n", !(a > b) && !c || 1);
    printf("%d\n", !(x = a) && (y = b) && 0);
    printf("%d\n", !(a + b) + c - 1 && b + c / 2);
    printf("%d\n", 1 && 30 % 10 >= 0 && 30 % 10 <= 3);
    printf("%d\n", a += a + b);
    a = 2;
    printf("%d\n", a *= b % c);
    a = 2;
    printf("%d\n", a /= c - a);
    a = 2;
    printf("%d\n", a += a -= a *= a);
    a = 2;
    printf("%f\n", a = (a = ++b, a + 5, a / 5));
    a = 2;
    printf("%d\n", (a >= b >= 2) ? 1 : 0);
    return 0;
}
