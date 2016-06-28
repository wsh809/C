#include <stdio.h>
#include <string.h>
int main()
{
    char s1[100]="";
    char s2[]="我爱你,";
    char s3[]="张瑜轩";
    /*在以下补全代码*/
    strcpy(s1, s2);
    strcat(s1, s3);
    
    printf("%s\n",s1);
    return 0;    
}