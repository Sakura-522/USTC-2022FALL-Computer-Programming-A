#include <stdio.h>
#include <windows.h>

int main()
{
    FILE *fp;
    fp = fopen("music.txt", "r");
    int a, b;
    for (int i = 0; i < 25; i++)
    {
        fscanf(fp, "%d %d", &a, &b);
        // Beep((unsigned int)a, (unsigned int)b);
        printf("Beep(%d,%d);\nSleep(64);\n", a, b);
    }
    fclose(fp);
    return 0;
}
