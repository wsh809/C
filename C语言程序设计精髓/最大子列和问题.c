#include <stdio.h>

int MaxSubSum(int a[], int n);
int main()
{
    int k,i,Sum;
    scanf("%d",&k);
    int a[k];
    for(i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
    }
    Sum = MaxSubSum(a, k);
    printf("%d",Sum);
    return 0;
}
//在线算法，复杂度O(N)
int MaxSubSum(int a[], int n)
{
    int NowSum, MaxSum;
    int i;
    NowSum = MaxSum = 0;
    for(i=0;i<n;i++)
    {
        NowSum += a[i];
        if(NowSum > MaxSum)
            MaxSum = NowSum;
        else if(NowSum < 0)
            NowSum = 0;
    }
    return MaxSum;
}