#include<stdio.h>
int x=500;                     /*外部变量定义与初始化*/
void f1()
{
    x+=100;
    printf("x=%d\n",x);
}
void f2()
{
    int x=10;                       /*局部变量定义与初始化*/
    printf("x=%d\n",x);
}
int  main()
{
    int x=300;                       /*局部变量定义与初始化*/
    f1();
    f2();
    printf("x=%d\n",x);
    return 0;
}