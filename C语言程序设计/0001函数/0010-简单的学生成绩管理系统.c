
/*简单的学习成绩管理*/
#include<stdio.h>
#include<string.h>
#define N 5
float score[N][N]={{85,90,89,78},
    {87,65,89,87},
    {65,87,67,65},
    {93,99,76,89},
    {84,78,67,88}};                       /*定义外部数组存储学习成绩*/
char name[N][10]={"wang","zhang","li","liu","zhao"};    /*定义外部数组存储学生姓名*/
float aver=0;                           /*定义外部变量存储一个学生的平均分*/
int flag = 1;
int main()
{
    int a;
    char name1[10];
    void query(char name1[]);                              /*函数的说明*/
    void average();                                        /*函数的说明*/
    void browse();                                         /*函数的说明*/
    
    printf("***************************\n");
    printf("   学习成绩管理系统   \n");
    printf("***************************\n");
    printf("1:通过姓名查询成绩\n");
    printf("2:计算平均分\n");
    printf("3:浏览\n");
    printf("0:退出\n");
    printf("请输入选项n:0--3\n");
    
    do {
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                do
                {
                    getchar();printf("\n请输入学生姓名:");
                    gets(name1);
                    query(name1);
                }while(flag);
                break;
            case 2:printf("\n已经完成平均分计算!");
                average();  break;
            case 3:printf("\n所有同学成绩:\n");
                browse();   break;
            default: printf("输入错误，请重新输入\n");
        }
    }while(a!=0);
    
    return 0;
}

void query(char name1[])                    /*按姓名查询学生成绩*/
{
    int i,j;
    for(i=0;i<=N-1;i++)
        if(strcmp(name1,name[i])==0)
        {
            printf("%10s:",name1);
            for(j=0;j<N-1;j++)
                printf("%5.0f",score[i][j] );
            flag = 0;
        }
    if(flag==1)
        printf("输入有错，请重新输入正确的学生姓名！");
}

void average()                            /*计算每个学生的平均分*/
{ int i,j;
    float sum;
    for(i=0;i<N;i++)
    {  for(sum=0,j=0;j<N-1;j++)
        sum=sum+score[i][j];
        aver=sum/(N-1);
        score[i][N-1]=aver;
    }
}
void browse( )                            /*浏览所有学生的成绩*/
{int i,j;
    for(i=0;i<N;i++)
    { printf("%10s:",name[i]);
        for(j=0;j<N-1;j++)
            printf("%5.0f",score[i][j]);
        printf("%8.2f",score[i][N-1] );
        printf("\n");
    }
}