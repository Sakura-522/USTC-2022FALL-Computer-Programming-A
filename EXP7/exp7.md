@import "D:\USR\vue.css"

<style>
img{
    width: 100%;
    padding-left: 15%;
    padding-right: 15%;
}
</style>

# <center>程序设计上机实验</center>

**<center>《文件》</center>**

**<center>王世炟 PB20151796</center>**
**<center>2022/12/01</center>**

<hr>


## 1、

>比较两个文本文件是否相同。【实验要点：文件，命令行参数】  
【说明：】从头到尾逐个字符比较两个文件 `a.txt` 和 `b.txt`，如果发现不同，则
报告出现第一个不同字在文件中的字节位置。若相同则输出“相同”。  
要求程序支持命令行参数，命令行格式如下例：`myfilecomp.exe a.txt b.txt`


**源程序：**

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    char *file1, *file2;
    char ch1, ch2;
    int i = 0;
    FILE *fp1, *fp2;
    file1 = argv[1];
    file2 = argv[2];
    if (((fp1 = fopen(file1, "r")) == NULL) || ((fp2 = fopen(file2, "r")) == NULL))
    {
        printf("can not open the file\n");
        return 0;
    }
    do
    {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);
        if (ch1 != ch2)
        {
            printf("不相同，第一个不同字在文件中的字节位置为: %d bytes\n", ftell(fp1));
            return 0;
        }
        
        i++;
    } while ((!feof(fp1)) && (!feof(fp2)));
    printf("相同");
    fclose(fp1);
    fclose(fp2);
    return 0;
}
```

**运行结果截图：**

@import "1.jpg"

**a.txt:**

@import "a.txt"

**b.txt:**

@import "b.txt"

**实验记录：（实验过程中出现的错误及其修改调试记录，可截图。）**

读文件操作，用`ftell()`函数返回文件指针位置的字节数。

## 2、 

>用函数指针实现生成三角函数表（sin,cos,tan），并存入文件以便查阅。  
说明：$\cos$ 函数、$\sin$ 函数和 $\tan$ 函数都已经在`<math.h>`中定义. 编写一个函数 `void table(double (*f)(double), double first, double last, double incr);`  
三个参数分别为三角函数指针，自变量起始值，自变量终止值，增量。在主函数中调用该函数， 并将求出的三角函数表以整洁的格式存入一个文本文件。

**源程序：**

```c
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
    scanf("%lf %lf %lf", &first, &last, &incr);
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
```

**运行结果截图：**

@import "三角函数表.txt"


**实验记录：（实验过程中出现的错误及其修改调试记录，可截图。）**

文件的写操作，函数指针。