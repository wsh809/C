#include <stdio.h>

int isprime(int n)
{
    int i;
    for(i=2;i<=n/2;i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main()
{
    int i,num;
    printf("请输入一个偶数：");
    do
    {
        scanf("%d",&num);
        if(num%2==0)
            break;
        printf("输入错误，请重新输入一个偶数：");
    }while(num%2);
    for(i=2;i<=num/2;i++)
        if(isprime(i)&&isprime(num-i))
            printf("%d = %d + %d\r\n", num,i,num-i);
            return 0;
}