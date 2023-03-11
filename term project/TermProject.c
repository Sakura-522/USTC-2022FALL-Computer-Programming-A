/*
2022秋计算机程序设计课程实验
数组运算器
王世炟 PB20151796
2022/10/09 begin
2022/10/12 end
*/
#include "functions.h"

int main()
{
    int flag, flag2, flag4, flag5, flag6, flag7, flag8, flag9, flag9_plus;
    int x, y;
    int a[500];
    float value;
    while (1)
    {
    //start:
        menu();
        scanf("%d", &flag);
        if (flag == 0)
        {
            break;
        }

        switch (flag)
        {
        case 1: //配置系统参数
            printf("请输入系统参数：数组元素个数 一行打印元素个数 每个元素的打印宽度:\n");
            struct ConfigVal cv;
            scanf("%d %d %d", &cv.ArrLength, &cv.PerLinePrintNum, &cv.ElePrintWid);
            if (cv.ArrLength < 0 || cv.ElePrintWid < 0 || cv.PerLinePrintNum < 0)
            {
                printf("三个参数均不可小于0\n");
                system("pause");
                //goto start;
                continue;
            }

            Config(cv);
            printf("数组元素个数为%d\n一行打印元素个数为%d\n每个元素的打印宽度为%d\n", ArrLength, PerLinePrintNum, ElePrintWid);
            system("pause");
            // system("cls");//用于清屏（可选）
            break;

        case 2: //生成样本数据
            while (1)
            {
                printf("--------------------------------------------------\n");
                printf("-------------------生成样本数据--------------------\n");
                printf(
                    "--------------------------------------------------\n"
                    "序号|  功能\n"
                    "0  |  返回上一级菜单\n"
                    "1  |  用指定范围的随机数填充数组\n"
                    "2  |  键盘输入\n"
                    "3  |  整个数组填同一个值\n"
                    "4  |  用等差序列填充数组\n"
                    "--------------------------------------------------\n");
                printf("请输入功能序号:\n");
                scanf("%d", &flag2);
                if (flag2 == 0)
                {
                    break;
                }

                switch (flag2)
                {
                case 1: //用指定范围的随机数填充数组
                    printf("请输入指定的范围:\n");
                    scanf("%d %d", &x, &y);
                    if (x > y)
                    {
                        printf("请确保第一个数不大于第二个数\n");
                        system("pause");
                        break;
                    }

                    FillArray(a, ArrLength, 1, x, y);
                    system("pause");
                    break;

                case 2: //键盘输入
                    FillArray(a, ArrLength, 2, 0, 0);
                    system("pause");
                    break;

                case 3: //整个数组填同一个值
                    printf("请输入指定的值:\n");
                    scanf("%d", &x);
                    FillArray(a, ArrLength, 3, x, 0);
                    system("pause");
                    break;

                case 4: //用等差序列填充数组
                    printf("请输入序列的起始值和公差:\n");
                    scanf("%d %d", &x, &y);
                    FillArray(a, ArrLength, 4, x, y);
                    system("pause");
                    break;
                default:
                    printf("ERROR! WRONG NUMBER!\n");
                    system("pause");
                    break;
                }
            }
            break;

        case 3: //显示数组
            PrintArr(a, ArrLength);
            system("pause");
            break;

        case 4: //删除
            while (1)
            {
                printf("--------------------------------------------------\n");
                printf("-----------------------删除------------------------\n");
                printf(
                    "--------------------------------------------------\n"
                    "序号|  功能\n"
                    "0  |  返回上一级菜单\n"
                    "1  |  删除指定下标的元素\n"
                    "2  |  删除指定值的元素\n"
                    "3  |  删除按指定下标区间的一组元素\n"
                    "--------------------------------------------------\n");
                printf("请输入功能序号:\n");
                scanf("%d", &flag4);
                if (flag4 == 0)
                {
                    break;
                }

                switch (flag4)
                {
                case 1: //删除指定下标的元素
                    printf("请输入指定的下标:\n");
                    scanf("%d", &x);
                    if (x < 0 || x >= ArrLength)
                    {
                        printf("下标超出范围\n");
                        system("pause");
                        break;
                    }

                    Delete(a, ArrLength, x);
                    system("pause");
                    break;

                case 2: //删除指定值的元素
                    printf("请输入指定的值:\n");
                    scanf("%d", &x);
                    DeleteVal(a, ArrLength, x);
                    system("pause");
                    break;

                case 3: //删除按指定下标区间的一组元素
                    printf("请输入指定的下标区间:\n");
                    scanf("%d %d", &x, &y);
                    if (x > y)
                    {
                        printf("请确保第一个数不大于第二个数\n");
                        system("pause");
                        break;
                    }
                    if (x < 0 || y >= ArrLength)
                    {
                        printf("请确保两个数在数组下标范围内\n");
                        system("pause");
                        break;
                    }
                    DeleteRange(a, ArrLength, x, y);
                    system("pause");
                    break;

                default:
                    printf("ERROR! WRONG NUMBER!\n");
                    system("pause");
                    break;
                }
            }
            break;

        case 5: //插入
            while (1)
            {
                printf("--------------------------------------------------\n");
                printf("----------------------插入------------------------\n");
                printf(
                    "--------------------------------------------------\n"
                    "序号|  功能\n"
                    "0  |  返回上一级菜单\n"
                    "1  |  按指定下标位置插入新元素\n"
                    "2  |  在有序数组中插入新元素\n"
                    "--------------------------------------------------\n");
                printf("请输入功能序号:\n");
                scanf("%d", &flag5);
                if (flag5 == 0)
                {
                    break;
                }

                switch (flag5)
                {
                case 1: //按指定下标位置插入新元素
                    printf("请输入指定的下标和待插入的值:\n");
                    scanf("%d %d", &x, &y);
                    if (x < 0 || x >= ArrLength)
                    {
                        printf("下标超出范围\n");
                        system("pause");
                        break;
                    }
                    Insert(a, ArrLength, x, y);
                    system("pause");
                    break;

                case 2: //在有序数组中插入新元素
                    printf("请输入待插入的值:\n");
                    scanf("%d", &x);
                    y = OrderInsert(a, ArrLength, x);
                    if (!y)
                    {
                        printf("不是有序数组:\n");
                    }
                    system("pause");
                    break;

                default:
                    printf("ERROR! WRONG NUMBER!\n");
                    system("pause");
                    break;
                }
            }
            break;

        case 6: //统计
            while (1)
            {
                printf("--------------------------------------------------\n");
                printf("----------------------统计------------------------\n");
                printf(
                    "--------------------------------------------------\n"
                    "序号|  功能\n"
                    "0  |  返回上一级菜单\n"
                    "1  |  求最大值\n"
                    "2  |  求最小值\n"
                    "3  |  求平均值\n"
                    "4  |  求方差和均方差\n"
                    "--------------------------------------------------\n");
                printf("请输入功能序号:\n");
                scanf("%d", &flag6);
                if (flag6 == 0)
                {
                    break;
                }

                switch (flag6)
                {
                case 1: //求最大值
                    x = Max(a, ArrLength);
                    printf("数组最大值为： %d \n", a[x]);
                    system("pause");
                    break;

                case 2: //求最小值
                    x = Min(a, ArrLength);
                    printf("数组最小值为： %d \n", a[x]);
                    system("pause");
                    break;

                case 3: //求平均值
                    value = Average(a, ArrLength);
                    printf("数组平均值为： %f \n", value);
                    system("pause");
                    break;

                case 4: //求方差和均方差
                    value = Var(a, ArrLength);
                    printf("数组方差为： %f ，均方差为： %lf \n", value, sqrt((double)value));
                    system("pause");
                    break;

                default:
                    printf("ERROR! WRONG NUMBER!\n");
                    system("pause");
                    break;
                }
            }
            break;

        case 7: //查找
            while (1)
            {
                printf("--------------------------------------------------\n");
                printf("-----------------------查找------------------------\n");
                printf(
                    "--------------------------------------------------\n"
                    "序号|  功能\n"
                    "0  |  返回上一级菜单\n"
                    "1  |  普通查找\n"
                    "2  |  二分查找\n"
                    "--------------------------------------------------\n");
                printf("请输入功能序号:\n");
                scanf("%d", &flag7);
                if (flag7 == 0)
                {
                    break;
                }

                switch (flag7)
                {
                case 1: //普通查找
                    printf("请输入要查找的值:\n");
                    scanf("%d", &x);
                    y = Search(a, ArrLength, x);
                    if (y != -1)
                    {
                        printf("要找的值 %d 的下标为： %d \n", x, y);
                    }
                    else
                    {
                        printf("数组中找不到此值！\n");
                    }
                    system("pause");
                    break;

                case 2: //二分查找
                    printf("请输入要查找的值:\n");
                    scanf("%d", &x);
                    y = BiSearch(a, ArrLength, x);
                    if (y == -2)
                    {
                        printf("数组无序，无法进行二分查找\n建议使用普通查找或先排序再查找\n");
                    }
                    else if (y != -1)
                    {
                        printf("要找的值 %d 的下标为： %d \n", x, y);
                    }
                    else
                    {
                        printf("数组中找不到此值！\n");
                    }
                    system("pause");
                    break;

                default:
                    printf("ERROR! WRONG NUMBER!\n");
                    system("pause");
                    break;
                }
            }
            break;

        case 8: //判断
            while (1)
            {
                printf("--------------------------------------------------\n");
                printf("-----------------------判断------------------------\n");
                printf(
                    "--------------------------------------------------\n"
                    "序号|  功能\n"
                    "0  |  返回上一级菜单\n"
                    "1  |  是否升序排列\n"
                    "2  |  是否降序排列\n"
                    "3  |  是否全部相等\n"
                    "--------------------------------------------------\n");
                printf("请输入功能序号:\n");
                scanf("%d", &flag8);
                if (flag8 == 0)
                {
                    break;
                }

                switch (flag8)
                {
                case 1: //是否升序排列
                    if (isAsc(a, ArrLength))
                    {
                        printf("数组是升序排列\n");
                    }
                    else
                    {
                        printf("数组不是升序排列\n");
                    }
                    system("pause");
                    break;

                case 2: //是否降序排列
                    if (isDesc(a, ArrLength))
                    {
                        printf("数组是降序排列\n");
                    }
                    else
                    {
                        printf("数组不是降序排列\n");
                    }
                    system("pause");
                    break;

                case 3: //是否全部相等
                    if (isEqual(a, ArrLength))
                    {
                        printf("数组全部相等\n");
                    }
                    else
                    {
                        printf("数组不是全部相等\n");
                    }
                    system("pause");
                    break;

                default:
                    printf("ERROR! WRONG NUMBER!\n");
                    system("pause");
                    break;
                }
            }
            break;

        case 9: //排列数组元素
            while (1)
            {
                printf("--------------------------------------------------\n");
                printf("--------------------排列数组元素---------------------\n");
                printf(
                    "--------------------------------------------------\n"
                    "序号|  功能\n"
                    "0  |  返回上一级菜单\n"
                    "1  |  四种排序算法\n"
                    "2  |  逆置数组\n"
                    "3  |  左旋数组 (循环左移：如将\"abcdef\"进行左旋2位变为\"cdefab\")\n"
                    "4  |  右旋数组 (循环右移)\n"
                    "--------------------------------------------------\n");
                printf("请输入功能序号:\n");
                scanf("%d", &flag9);
                if (flag9 == 0)
                {
                    break;
                }

                switch (flag9)
                {
                case 1: //四种排序算法
                    while (1)
                    {
                        printf("--------------------------------------------------\n");
                        printf("--------------------四种排序算法---------------------\n");
                        printf(
                            "--------------------------------------------------\n"
                            "序号|  功能\n"
                            "0  |  返回上一级菜单\n"
                            "1  |  冒泡法\n"
                            "2  |  选择法\n"
                            "3  |  插入法\n"
                            "4  |  快速排序\n"
                            "--------------------------------------------------\n");
                        printf("请输入功能序号:\n");
                        scanf("%d", &flag9_plus);
                        if (flag9_plus == 0)
                        {
                            break;
                        }
                        switch (flag9_plus)
                        {
                        case 1: //冒泡法
                            printf("排序前数组：\n");
                            PrintArr(a, ArrLength);
                            BubbleSort(a, ArrLength);
                            printf("排序后数组：\n");
                            PrintArr(a, ArrLength);
                            system("pause");
                            break;

                        case 2: //选择法
                            printf("排序前数组：\n");
                            PrintArr(a, ArrLength);
                            SelectSort(a, ArrLength);
                            printf("排序后数组：\n");
                            PrintArr(a, ArrLength);
                            system("pause");
                            break;

                        case 3: //插入法
                            printf("排序前数组：\n");
                            PrintArr(a, ArrLength);
                            InsertSort(a, ArrLength);
                            printf("排序后数组：\n");
                            PrintArr(a, ArrLength);
                            system("pause");
                            break;

                        case 4: //快速排序
                            printf("排序前数组：\n");
                            PrintArr(a, ArrLength);
                            QuickSort(a, 0, ArrLength - 1);
                            printf("排序后数组：\n");
                            PrintArr(a, ArrLength);
                            system("pause");
                            break;

                        default:
                            break;
                        }
                    }

                    break;

                case 2: //逆置数组
                    printf("逆置前数组：\n");
                    PrintArr(a, ArrLength);
                    Reverse(a, ArrLength);
                    printf("逆置后数组：\n");
                    PrintArr(a, ArrLength);
                    system("pause");
                    break;

                case 3: //左旋数组
                    printf("请输入左旋位数：\n");
                    scanf("%d", &x);
                    if (x < 0)
                    {
                        printf("左旋位数不能小于0！\n");
                        system("pause");
                        break;
                    }
                    printf("左旋前数组：\n");
                    PrintArr(a, ArrLength);
                    LeftRotate(a, ArrLength, x);
                    printf("左旋后数组：\n");
                    PrintArr(a, ArrLength);
                    system("pause");
                    break;

                case 4: //右旋数组
                    printf("请输入右旋位数：\n");
                    scanf("%d", &x);
                    if (x < 0)
                    {
                        printf("右旋位数不能小于0！\n");
                        system("pause");
                        break;
                    }
                    printf("右旋前数组：\n");
                    PrintArr(a, ArrLength);
                    RightRotate(a, ArrLength, x);
                    printf("右旋后数组：\n");
                    PrintArr(a, ArrLength);
                    system("pause");
                    break;

                default:
                    printf("ERROR! WRONG NUMBER!\n");
                    system("pause");
                    break;
                }
            }
            break;

        default:
            printf("ERROR! WRONG NUMBER!\n");
            system("pause");
            break;
        }
    }

    return 0;
}