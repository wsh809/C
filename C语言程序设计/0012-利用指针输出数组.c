/*定义指针（比如整形）
    int *a;
    其中，*在定义变量的时候叫做指针说明符，表示我们定义的是一个指针变量
          在使用的时候叫间接访问符（在程序中会说明）
    a 是变量名，与普通变量不同的是，指针变量中的内容是地址，这个地址指向另外一个变量
    而int 说明指针变量a 所指向的另外一个变量是整形变量

    赋值
    给指针变量赋值要赋地址，例如数组名，&变量名，或另外一个指针变量
*/

//没有用指针的情况  change函数
#include <stdio.h>

void change(int a, int b);
int a,b;

int main()
{
    scanf("%d,%d",&a,&b);
    change(a,b);
    printf("a = %d, b = %d",a,b);
    return 0;
}

void change(int m, int n)
{
    int temp;
    temp = m;
    m = n;
    n= temp;
    printf("m= %d, n = %d",m,n);
}