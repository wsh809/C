#include <stdio.h>
/*
替换指定数组arr1中的最大元素。要求指定整数为数组arr2中的第一个元素arr2[0]。
*/

//将数组上最大的项替换为 value 的值
void replaceMax(int arr[],int value)
{
    int max = arr[0];
    int index = 0;
    int i;
    for(i=1;i<5;i++)			  //确定数组中最大数的 index 
    {
        if(arr[i]>max)
        {
            max = arr[i];          //将数组中较大的数赋值给max
            index = i;  //记录当前索引
        }                
    }  
    arr[index] = value;      //将value的值赋给数组中最大的数
}

int main()
{
    int arr1[] = {10,41,3,12,22};
    int arr2[] = {1,2,3,4,5};
    int i;
    replaceMax(arr1, arr2[0]); //将数组arr1和数组arr2的第一个元素传入函数中
    for(i=0;i<5;i++)
    {
        printf("%d ",arr1[i]);                
    }
    return 0;    
}