
#include <stdio.h>

int main()
{
    int a[]={1,2,3,4,5};
    int *p1=a;
    int i;
    for(i=0;i<=4;i++)
        printf("%d  %d  %d\n\r", a[0+i],*(p1+i),*(a+i));
        //数组名就是数组的首地址，其实就相当于一个指针
}

