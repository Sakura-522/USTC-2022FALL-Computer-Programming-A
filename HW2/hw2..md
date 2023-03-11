# <center>Homework2</center>


**<center>王世炟 PB20151796**</center>
**<center>2022/09/14</center>**

## 1.编辑一个helloworld.c程序，如下:

```
#include <stdio.h>
int main()
{
printf(“Hello World!\n”);
return(0);
}
```

**编译，结果信息截图贴在这里：**

![](img/gcc.jpg)

在终端输入编译命令，可观察到生成了`helloworld.exe`文件

![](img/helloworld.jpg)

**运行 ，结果信息截图贴在这里：**

![](img/exe.jpg)

## 2.修改上面的helloworld.c， 使它能够输出下面样式的字符串:

```
*
***
*****
*******
*****
***
*
```

**把修改后的程序源码拷贝到这里：**

这里提供两种方法:
```
#include <stdio.h>
int main()
{
    printf("*\n***\n*****\n*******\n*****\n***\n*\n");
    printf(
    "*\n"
    "***\n"
    "*****\n"
    "*******\n"
    "*****\n"
    "***\n"
    "*\n"
    );
    return (0);
}
```

**运行，结果截图贴在这里：**

![](img/star.jpg)


## 3.下面的程序可以输入两个不相等的整数，并输出其中较大的值。

```
#include <stdio.h>
int main()
{
  int a,b;
  scanf(“%d” &a);
  scanf(“%d” &b);
  if (a>=b) 
     printf(“the bigger is %d\n”, a);
  else
     printf(“the bigger is %d\n”, b); 
}
```

改写这个程序，输入三个整数，输出较大的值。

**将改写后的源码复制到下面：**

```
#include <stdio.h>
int main()
{
  int a,b,c,t;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  t = a;
  if (b>=t)
      t = b;
  if (c>=t)
      t = c;
  printf("the biggest is %d\n",t); 
}
```

**运行结果截图：**

![](img/result.jpg)

## 4.下面的公式表示温度单位的转换，从华氏度f转换到摄氏度c：

$$c=\frac{5}{9}\times(f-32)$$

编程序实现：输入华氏度值，转换成摄氏度值并输出。

**程序源码：**

```
#include <stdio.h>
int main()
{
  double f, c;
  printf("please enter the Fahrenheit degree:\n"); 
  scanf("%lf", &f);
  c = 5 / 9.0 * (f - 32);
  printf("the Celsius degree is %f\n",c); 
}
```

**运行结果截图：**

![](img/transform.jpg)