#include <stdio.h>

int stepnum = 0;

void Move(char getdisk, char putdisk)
{
    printf("%c---->%c\n",getdisk,putdisk);
    stepnum++;
}

void hanoi(int n, char start, char mid, char target)
{
    if(n==1)
        Move(start,target);
    else
    {
        hanoi(n-1,start,target,mid);
        Move(start,target);
        hanoi(n-1,mid,start,target);
    }
}

int main()
{
    int num;
    printf("请输入盘子的个数:");
    scanf("%d",&num);
    printf("移动盘子的过程为：\n\r");
    hanoi(num,'S','M','T');
    printf("移动的总步数为： %d", stepnum);
}