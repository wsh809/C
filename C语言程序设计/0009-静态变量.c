/*静态变量*/
#include<stdio.h>
int main( )
 {  
    int i ;  
    void f(int);
    for( i=1;i<=3;i++)
    f( i ); 
    return 0; 
 }
void f(int j)
{  
    static int a=100;   
    auto  int k=1; 
    ++k;  
    printf("%d+%d+%d=%d\n", a, k, j, a+k+j);
    a+=10;       
}