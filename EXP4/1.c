#include <stdio.h>

#define swap(A, B, TYPE) \
    {                    \
        TYPE temp;       \
        temp = A;        \
        A = B;           \
        B = temp;        \
    }

void macro_test(void)
{
    printf("Line is %d\n", __LINE__);
    printf("Filename is %s \nThe function is %s\n", __FILE__, __func__);
    #ifdef _WIN32
    printf("WIN32 is defined as %d\n", _WIN32);
    #endif
    #ifdef _WIN64
    printf("WIN64 is defined as %d\n", _WIN64);
    #endif
    #ifdef __CYGWIN__
    printf("CYGWIN is defined as %d\n", __CYGWIN__);
    #endif
    #ifdef __MINGW32__
    printf("MINGW32 is defined as %d\n", __MINGW32__);
    #endif
}

int main()
{
    int a = 1, b = 2;
    float x = 1.1, y = 2.2;
    char m = 't', n = 'f';
    swap(a, b, int);
    swap(x, y, float);
    swap(m, n, char);
    printf("%d, %d\n", a, b);
    printf("%f, %f\n", x, y);
    printf("%c, %c\n", m, n);
    macro_test();
    return 0;
}