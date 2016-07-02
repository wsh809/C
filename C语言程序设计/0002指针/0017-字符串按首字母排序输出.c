/*将字符串按首字母排序输出*/
#include<stdio.h>
#include<string.h>
int main(  )
{  int i,j;
    static char *str[4]={"Program","Fortran","C" ,"Basic"};
    char *temp;                          /*定义指针 *temp，作为临时变量交换两个字符串*/
    for(i=0;i<4;i++)
        for(j=i+1;j<4;j++)
            if ( strcmp(str[i],str[j])>0 )
            {   temp=str[j] ;
                str[j]=str[i];
                str[i]=temp;
            }
    for(i=0; i<4; i++)
        printf("%s\n",str[i] );
    return 0;  
}