#include <stdio.h>

int age(int n)
{
    if(n==1)
        return 10;
    else
        return 2 + age(n-1);
}

int main()
{
    int num;
    printf("请输入小朋友的编号：");
    scanf("%d",&num);
    printf("第%d个小朋友的年龄为：%d岁",num,age(num));
    return 0;
}