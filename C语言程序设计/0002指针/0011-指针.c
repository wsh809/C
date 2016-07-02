/*！！！！指针就是地址！！！！
    定义指针（比如整形）
    int *a;
    其中，*在定义变量的时候叫做指针说明符，表示我们定义的是一个指针变量
          在使用的时候叫间接访问符（在程序中会说明）
    a 是变量名，与普通变量不同的是，指针变量中的内容是地址，这个地址指向另外一个变量
    而int 说明指针变量a 所指向的另外一个变量是整形变量

    赋值
    给指针变量赋值要赋地址，例如数组名，&变量名，或另外一个指针变量
*/

//没有用指针的情况  change函数内形参的值并不能传递回main函数中，因为a,b的值并不会发生改变
#include <stdio.h>
int main()
{
    void change(int a, int b);
    int a,b;
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
    printf("m= %d, n = %d\n\r",m,n);
}
//*************************我是愉快的分隔线***************************


#include <stdio.h>
int main()
{
    void change(int *p1, int *p2);
    int a,b;
    int *p1,*p2;    //这里的*为指针定义符
    scanf("%d,%d",&a,&b);
    p1 = &a;        //&为取地值符，本句意为将a的地址赋给p1
    p2 = &b;
    change(p1,p2);
    printf("a = %d, b = %d",a,b);
    return 0;
}

void change(int *p_1, int *p_2)
{
    int temp;           //p_1 p_1是change函数的形参，实参p1 p2的值传给p_1和p_2，意味着p1和p_1现在指向同一个变量，即a
    temp = *p_1;        //p2和p_2指向同一个变量，b
    *p_1 = *p_2;        //交换p_1和p_2所指变量的值，即a b的值
    *p_2 = temp;        //函数结束虽然形参p_1和p_1消失，但是a b的值已经交换所以保留下来
    printf("m= %d, n = %d\n\r",*p1,*p2);        //这里的*为间接访问符，意为访问p1内所存地址指向的变量的值
}