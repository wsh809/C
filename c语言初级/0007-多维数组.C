#include <stdio.h>
int main()
{
    //使用第一种方式初始化方式声明并初始化二维数组arr1
    int arr1[2][2] = {{10,20}, {30,40}};
    //使用第二种方式初始化方式声明并初始化二维数组arr2
    int arr2[2][2];
    arr2[0][0]= 11, arr2[0][1] = 22, arr2[1][0] = 33,arr2[1][1] = 44;
    int i;
    int j;
	 printf("arr1=");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        printf(" %d", arr1[i][j]);
    }
	printf("\n\r");
	printf("arr2=");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        printf(" %d", arr2[i][j]);
    }
    
    return 0;    
}