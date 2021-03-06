#include <stdio.h>
int main()
{
    double arr[]={1.78, 1.77, 1.82, 1.79, 1.85, 1.75, 1.86, 1.77, 1.81, 1.80};
    int i,j;
    printf("\n************排队前*************\n");
    for(i=0;i<10;i++)
    {
        if(i != 9)   
            printf("%.2f, ", arr[i]);  //%.2f表示小数点后精确到两位
        else
            printf("%.2f", arr[i]);    //%.2f表示小数点后精确到两位
    }
    for(i=8; i>=0; i--)
    {
        for(j=0;j<=i;j++)
        {
            if(arr[j]>arr[j+1])      //当前面的数比后面的数大时
            {
                double temp;      //定义临时变量temp
                temp = arr[j];    //将前面的数赋值给temp
                arr[j] = arr[j+1];//前后之数颠倒位置
                arr[j+1] = temp;    //将较大的数放在后面    
            }                 
        }                
    }
    printf("\n************排队后*************\n");
    for(i=0;i<10;i++)
    {
        if(i != 9)   
            printf("%.2f, ", arr[i]);  //%.2f表示小数点后精确到两位     
        else
            printf("%.2f", arr[i]);    //%.2f表示小数点后精确到两位
    }
    return 0;    
}

void exchange(int a[])
{
    int i,k,m;
    m = sizeof(a[0]);
    for(i=m-2; i>=0; i--)
    {
        for(k=0;k<=i;k++)
        {
            if(a[k]>a[k+1])      //当前面的数比后面的数大时
            {
                int temp;      //定义临时变量temp
                temp = a[k];    //将前面的数赋值给temp
                a[k] = a[k+1];//前后之数颠倒位置
                a[k+1] = temp;    //将较大的数放在后面
            }
        }
    }
    for(i=0;i<m;i++)
    {
        printf("%d ", a[i]);
    }
}