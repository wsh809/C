#include<stdio.h>
#define STNUM   5
struct stuinf
{   int stid;           /* 学生学号 */
    int score;          /* 学生成绩 */
}stu [ STNUM ];          /* stu: 结构数组 */
struct  stuinf *p[STNUM];

void main ( )
{
    struct stuinf  *ptemp, *p[STNUM]; int i,j,sum=0;
    for ( i=0; i<=STNUM-1; i++ )
    {
        scanf ("%d%d", &stu[i].stid,&stu[i].score);
        p[i]=&stu[i];
        sum += stu[i].score;
    }
    
    for ( i =0; i <= STNUM-2; i++ )
    {
        for ( j = i; j <= STNUM-1; j++ )
            if ( p[i]->score < p[j]->score )
                {  ptemp = p[i];  p[i]=p[j];  p[j]=ptemp; }
    }
    
    for (i=0; i<=STNUM-1; i++)
        printf("%d,%d\n", (*p[i]).stid, p[i]->score);
    printf ("average score = %d\n", sum/STNUM);
}