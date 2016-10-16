
#include <stdio.h>

int MaxSubSum(int a[], int n);
int main()
{
    int k,i;
    scanf("%d",&k);
    int a[k];
    for(i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
    }
    MaxSubSum(a, k);
    return 0;
}

/*借鉴了网上的算法，之前只定义了Start和End的值，现在多定义了两个临时值。
    当前子列和小于等于零时
    将其置为零，并将临时起始位和结束位置为其下一位
    
    当前子列和大于零时
    将后一子项加进来

    如果当前子列和大于最大子列和 或者 结束位位置未改变且当前子列和为零
    则令新最大子列和的值为当前子列和
    并将起始位和结束位更新为临时起始位和结束位的值
*/
#include <stdio.h>

int MaxSubSum(int a[], int n);
int main()
{
    int k,i;
    scanf("%d",&k);
    int a[k];
    for(i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
    }
    MaxSubSum(a, k);
    return 0;
}

int MaxSubSum(int a[], int n)
{
    int NowSum = 0;
    int MaxSum = 0;
    int Start = 0;
    int End = n-1;
    int TStart = 0;
    int TEnd = 0;
    int i;
    for(i=0;i<n;i++)
    {
        if(NowSum < 0)
        {
            NowSum = 0;
            NowSum += a[i];
            TStart = i;
            TEnd = i;
        }
        else
        {
            NowSum += a[i];
            TEnd = i;
        }
        if(NowSum > MaxSum ||(End == n-1 && NowSum == 0))
        {
            MaxSum = NowSum;
            Start = TStart;
            End = TEnd;
        }
    }
    printf("%d %d %d", MaxSum, a[Start], a[End]);
    return 0;
}