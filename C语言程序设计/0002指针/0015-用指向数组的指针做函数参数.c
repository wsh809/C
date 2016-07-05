
#include  <stdio.h>
#include  <string.h>
void  fun ( char *w,  int  m )
{  char  s, *p1 , *p2 ;
    p1=w;   p2=w+m-1;
    while(p1<p2)
    {   s=*p1++;   *p1=*p2-- ; *p2=s;    }
}
int main( )
{  char    a[ ]="1234567";
    fun ( a , (int) strlen(a) );
    puts(a);
    return 0;
}

//
#include<stdio.h>
int max(int *p)                       /*定义一个函数，求1最大值*/      
{  int i,t=*p;
   for(i=1;i<10;i++)
    if(*(p+i)>t ) 
     t=*(p+i);
  return t;  
}
int main()
{int i,m,a[10];       
 int (*pf)(int a[]);                  /*定义一个函数型指针*/                             
 for(i=0;i<10;i++)
 scanf("%d",&a[i]); 
 pf=&max;                            /*为函数型指针初始化*/
 m=(*pf)(a);                         /*用指针调用函数*/     
 printf("max=%d\n",m);
 return 0;
}
