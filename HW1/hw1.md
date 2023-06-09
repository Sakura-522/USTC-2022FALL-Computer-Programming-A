
 # <center>Homework1</center>

 
 **<center>王世炟 PB20151796**</center>
 **<center>2022/09/06**</center>

 [TOC]

 ## 一、进制转换 
 ### 1. 将下列二进制补码数字转换为十进制数字。

$(a)1010$\
$(b)01011010$\
$(c)11111110$\
$(d)0011100111010011$

$(a) -6~~首位为1表示负数，取反加一后为0110，十进制为6，所以原二进制数化为十进制数结果为 -6 $

$(b) 90~~首位为0表示正数，十进制为64+16+8+2=90，所以原二进制数化为十进制数结果为 90 $

$(c) -2~~首位为1表示负数，取反加一后为00000010，十进制为2，所以原二进制数化为十进制数结果为 -2 $

$(d) 14803~~首位为0表示正数，十进制为1+2+16+64+128+256+2048+4096+8192=14803，所以原二进制数化为十进制数结果为 14803 $

 ### 2. 将下列十进制数转换为一个字节（8位）的二进制补码形式

$(a)102$\
$(b)64$\
$(c)33$\
$(d)-128$\
$(e)127$

$(a)102是正数化为二进制后首位为0，102=2+4+32+64，所以8位的二进制补码形式为 01100110$

$(b)64是正数化为二进制后首位为0，64=2^6，所以8位的二进制补码形式为 01000000$

$(c)33是正数化为二进制后首位为0，33=1+2^5，所以8位的二进制补码形式为 00100001$

$(d)注意到-1的补码为11111111，-2的补码为11111110， -3的补码为11111101，以此类推，-127的补码为10000001,那么，为了顺应ALU(算数逻辑单元)的加法操作方式，让码字10000000对应为数值-128$

$(e)127是正数化为二进制后首位为0，127=1+2+4+32+64，所以8位的二进制补码形式为 01111111$

 ## 二、整数编码，浮点数编码 

 ### 3. 下列算式中的数字均使用4位二进制补码 。给出每个算式的十进制结果。并指出哪些发生了溢出。
$(a)1100 + 0011$\
$(b)1100 + 0100$\
$(c)0111 + 0001$\
$(d)1000 -  0001$\
$(e)0111 + 1001$

$(a)$
$$
\begin{array}{r}
1100\\
+0011\\
\hline
1111
\end{array}
$$
$1111化为十进制为-1，没有发生溢出$

$(b)$
$$
\begin{array}{r}
1100\\
+0100\\
\hline
10000
\end{array}
$$
$未发生溢出，最左边溢出位被自然丢弃，剩下0000化为十进制为0，与我们期望的结果0相同，事实上，二者互为补码$

$(c)$
$$
\begin{array}{r}
0111\\
+0001\\
\hline
1000
\end{array}
$$
$1000化为十进制为-8，发生溢出，与原本结果8不同，因为8已经超过4bit表示的范围-8\sim7$

$(d)$
$$
\begin{array}{r}
1000\\
-0001\\
\hline
0111
\end{array}
$$
$0111化为十进制为7，发生溢出，与原本结果-9不同，因为-9已经超过4bit表示的范围-8\sim7$

$(e)$
$$
\begin{array}{r}
0111\\
+1001\\
\hline
10000
\end{array}
$$
$未发生溢出，最左边溢出位被自然丢弃，剩下0000化为十进制为0，与我们期望的结果0相同，事实上，二者互为补码$


 ### 4. 给出下列小数的IEEE单精度浮点数的表示形式。【 选做 】
$(a)-123.75$\
$(b)-55\frac{23}{64}$

$(a)-123.75转化为二进制为-1111011.11，正则化处理后为-1.11101111*2^6,符号位为1，表示负数，指数部分为10000101（十进制为133=127+6）尾数部分省略了小数点左边的1后且精度23位为11101111000000000000000$
$\therefore -123.75的IEEE单精度浮点数表示形式为：$
$$
1~10000101~11101111000000000000000
$$
$十六进制为：$
$$
0xC2F78000
$$

$(b)-55\frac{23}{64}转化为二进制为-110111.010111，正则化处理后为-1.10111010111*2^5,符号位为1，表示负数，指数部分为10000100（十进制为132=127+6）尾数部分省略了小数点左边的1后且精度23位为10111010111000000000000$
$\therefore -55\frac{23}{64}的IEEE单精度浮点数表示形式为：$
$$
1~10000100~10111010111000000000000\\
$$
$十六进制为：$
$$
0xC25D7000
$$
