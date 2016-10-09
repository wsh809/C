#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <time.h>
#define MAX 4
int row=0,col=0;//元素下标
int loop=0;//排数
int i = 0, j = 0;//下标
int map[MAX][MAX] = {0};

/*初始化数组*/
void init()
{
    memset(map,0,sizeof(map));
}

/*在某一个空的位置创建随机数*/
void CreateRandNumber()
{
    int flag =0,pos=0;
    srand(time(0));
    int x =0 ,y = 0;
    int r[MAX*MAX];
    int c[MAX*MAX];
    int k = 0;
    /*判断哪些位置可空*/
    for(row=0;row<MAX;row++)
    {
        for(col=0;col<MAX;col++)
        {
            if(map[row][col]==0)
            {
                r[k]=row;
                c[k]=col;
                k++;

            }
        }
    }
    if(k==0)
    {
        printf("游戏结束\n");
        exit(0);
    }
    printf("\n");
    pos = rand()%k;
    x = r[pos];
    y = c[pos];
    map[x][y] = (rand()%2+1)*2;
    printf("产生随机数map[%d][%d]=%d\n",x,y,map[x][y]);
    /*从空的位置中产生一个随机数2或者4*/
}

/*显示游戏盘*/
void show_map()
{
    CreateRandNumber();
    for(row=0;row<4;row++)
    {
        for(loop=0;loop<4;loop++)
        {
            printf("----+");
        }
        printf("\n");
        for(col=0;col<4;col++)
        {
            if(map[row][col]==0)
            {
                printf("    |");
            }
            else
            {
                 printf("%-4d|",map[row][col]);
            }
        }
        printf("\n");
    }
    for(loop=0;loop<4;loop++)
    {
        printf("----+");
    }
    printf("\n");
}
/*向左移动*/
void toward_left()
{
    printf("正在向左移动\n");
    for(loop=0;loop<4;loop++)
    {
        //移动数字
        for(i=1;i<=3;i++)
        {
            for(j=i;j>0;j--)
            {
                if(map[loop][j-1]==0)
                {
                    map[loop][j-1]=map[loop][j];
                    map[loop][j]=0;
                }
            }
        }
        //合并相同数字
        for(i=1;i<=3;i++)
        {
            if((map[loop][i]==map[loop][i-1]) && (map[loop][i-1]!=0))
            {
                map[loop][i-1]=2*map[loop][i-1];
                map[loop][i]=0;
            }
        }
    }
}
/*向上移动*/
void toward_up()
{
    printf("正在向上移动\n");
    for(loop=0;loop<4;loop++)
    {
        //移动数字
        for(i=1;i<=3;i++)
        {
            for(j=i;j>0;j--)
            {
                if(map[j-1][loop]==0)
                {
                    map[j-1][loop]=map[j][loop];
                    map[j][loop]=0;
                }
            }
        }
        //合并相同数字
        for(i=1;i<=3;i++)
        {
            if((map[i-1][loop]==map[i][loop]) && (map[i-1][loop]!=0))
            {
                map[i-1][loop]*=2;
                map[i][loop]=0;
            }
        }
    }

}
/*向下移动*/
void toward_down()
{
    printf("正在向下移动\n");
    for(loop=0;loop<4;loop++)
    {
        //移动数字
        for(i=3;i>0;i--)
        {
            for(j=i;j<=3;j++)
            {
                if(map[j][loop]==0)
                {
                    map[j][loop]=map[j-1][loop];
                    map[j-1][loop]=0;
                }
            }
        }
        //合并相同数字
        for(i=3;i>0;i--)
        {
            if((map[i][loop]==map[i-1][loop]) && (map[i][loop]!=0))
            {
                map[i][loop]*=2;
                map[i-1][loop]=0;
            }
        }
    }

}
/*向右移动*/
void toward_right()
{
    printf("正在向右移动\n");
    for(loop=0;loop<4;loop++)//四排
    {
        //移动数字
        i = 2;
        while(i>=0)
        {
            for(j=i;j<3;j++)
            {
                if(map[loop][j+1]==0)
                {
                    map[loop][j+1]=map[loop][j];
                    map[loop][j]=0;
                }
            }
            i--;
        }
        //合并相同数字
        for(i=2;i>=0;i--)
        {
            if((map[loop][i+1]==map[loop][i]) && (map[loop][i+1]!=0))
            {
                map[loop][i+1]=2*map[loop][i+1];
                map[loop][i]=0;
            }
        }
    }

}
/*开始游戏*/
void play()
{
    show_map();
    char direction = ' ';
    while(1)
    {
        printf("h代表向左，j代表向向上，k代表向下，l代表向右:\n");
        printf("输入方向：");
        scanf("%c",&direction);
        scanf("%*[^\n]");
        scanf("%*c");
        switch(direction)
        {
            case 'h':toward_left(); show_map();break;
            case 'j':toward_up(); show_map();break;
            case 'k':toward_down(); show_map();break;
            case 'l':toward_right(); show_map();break;
            default:break;
        }
    }
}
int main()
{
    init();
    play();
    return 0;
}