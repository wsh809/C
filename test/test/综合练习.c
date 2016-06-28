#include <stdio.h>
int i;
int j;
int sum = 0;
float avr;
int max;
int min;
int score[]={67,98,75,63,82,79,81,91,66,84};

int sum_points()
{
    for(i=0;i<10;i++)
    {
        sum += score[i];
    }
    printf("总分为：%d\n\r",sum);
    return 0;
}

int max_points()
{
    max = score[0];
    printf("最高分为：%d\n\r",max);
    return 0;

}

int min_points()
{
    min = score[9];
    printf("最低分为：%d\n\r",min);
    return 0;

}

int avr_points()
{
    avr = sum/10;
    printf("平均分为：%f\n\r",avr);
    return 0;
}

int ord_points()
{
    for(i=1;i<9;i++)
    {
        for(j=9;j>=i;j--)
        {
            if(score[j]>score[j-1])
            {
                int tmp;
                tmp = score[j];
                score[j] = score[j-1];
                score[j-1] = tmp;
            }
        }
    }
    printf("成绩由高到低排序:");
    for(i=0;i<10;i++)
    {
        printf("%d ",score[i]);
    }
    printf("\n\r");
    return 0;
}

int main()
{
    sum_points();
    avr_points();
    ord_points();
    max_points();
    min_points();
    
    return 0;
}

