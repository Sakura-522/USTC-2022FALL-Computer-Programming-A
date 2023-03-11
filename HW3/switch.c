# include <stdio.h>

int main()
{
    int score,flag;
    printf("Please enter the score(0~100):\n");
    scanf("%d", &score);
    if (score > 100 || score < 0)
    {
        printf("ERROR!  The score is out of range!\nPlease enter the right score.");
        return 0;
    }
    else
    {
        if (score >= 95 && score <= 100)
        {
            flag = 1;
        }
        else if (score >= 90 && score < 95)
        {
            flag = 2;
        }
        else if (score >= 85 && score < 90)
        {
            flag = 3;
        }
        else if (score >= 82 && score < 85)
        {
            flag = 4;
        }
        else if (score >= 78 && score < 82)
        {
            flag = 5;
        }
        else if (score >= 75 && score < 78)
        {
            flag = 6;
        }
        else if (score >= 72 && score < 75)
        {
            flag = 7;
        }
        else if (score >= 68 && score < 72)
        {
            flag = 8;
        }
        else if (score >= 65 && score < 68)
        {
            flag = 9;
        }
        else if (score == 64)
        {
            flag = 10;
        }
        else if (score >= 61 && score < 64)
        {
            flag = 11;
        }
        else if (score == 60)
        {
            flag = 12;
        }
        else
        {
            flag = 13;
        }
    }
    
    switch (flag)
    {
    case 1:
        printf("百分制=%d，五分制=A+，GPA=4.3", score);
        break;
    
    case 2:
        printf("百分制=%d，五分制=A，GPA=4.0", score);
        break;

    case 3:
        printf("百分制=%d，五分制=A-，GPA=3.7", score);
        break;

    case 4:
        printf("百分制=%d，五分制=B+，GPA=3.3", score);
        break;

    case 5:
        printf("百分制=%d，五分制=B，GPA=3.0", score);
        break;

    case 6:
        printf("百分制=%d，五分制=B-，GPA=2.7", score);
        break;

    case 7:
        printf("百分制=%d，五分制=C+，GPA=2.3", score);
        break;

    case 8:
        printf("百分制=%d，五分制=C，GPA=2.0", score);
        break;

    case 9:
        printf("百分制=%d，五分制=C-，GPA=1.7", score);
        break;

    case 10:
        printf("百分制=%d，五分制=D+，GPA=1.5", score);
        break;

    case 11:
        printf("百分制=%d，五分制=D，GPA=1.3", score);
        break;

    case 12:
        printf("百分制=%d，五分制=D-，GPA=1.0", score);
        break;

    default:
        printf("百分制=%d，五分制=F，GPA=0", score);
        break;
    }

    return 0;
}