/*函数的递归调用，即函数直接或间接地调用了它本身
*/
#include <stdio.h>

float fact(int n)
{
    if(n==1||n==0)
        return 1;
    else
        return n * fact(n-1);;
}

int main()
{
    int num;
    printf("请输入一个大于等于零的数：");
    do
    {
        scanf("%d",&num);
        if(num>=0)
           break;
           printf("输入错误，请重新输入一个大于等于零的数：");
           }while(num<0);
           printf("%f的阶乘为 ", fact(num));
           return 0;
           }