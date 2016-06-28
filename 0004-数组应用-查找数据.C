#include <stdio.h>
int getIndex(int arr[5],int value)
{
    int i;
    int index;
    for(i=0;i<5;i++)
    {
       /* 请完善数组查询功能 */
       if(arr[i] == value)
       {
           return i;
       }
    }
    return -1;
}

int main()
{
    int arr[5]={3,12,9,8,6};
    int value;
	 printf("请输入要查询的值:");
	 scanf("%d", &value);
    int index = getIndex(arr , value);      //这里应该传什么参数呢？
    if(index!=-1)
    {
        printf("%d在数组中存在，下标为：%d\n",value,index);             
    }
    else
    {
        printf("%d在数组中不存在。\n",value);    
    }
    return 0;    
}