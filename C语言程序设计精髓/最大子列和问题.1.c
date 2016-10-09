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
    if(Sum > 0)
        printf("%d",Sum);
    else
        printf("0");
    return 0;
}

int MaxSubSum(int a[], int n)
{
    int NowSum, MaxSum;
    int i;
    int Start,End;
    NowSum = MaxSum = 0;
    Start = 0;
    End = n;
    for(i=0;i<n;i++)
    {
        NowSum += a[i];
        if(NowSum > MaxSum)
        {
            MaxSum = NowSum;
            End = i;
        }
        else if(NowSum < 0)
        {
             NowSum = 0;
            Start = i+1;
        }       
    }
    return MaxSum;
}