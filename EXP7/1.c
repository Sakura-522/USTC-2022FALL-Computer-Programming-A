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