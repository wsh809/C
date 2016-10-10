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
    int NowSum, MaxSum;
    int i;
    int flag = 0;
    int Start,End;
    NowSum = MaxSum = 0;
    Start = 0;
    End = n-1;
    for(i=0;i<n;i++)
    {
        NowSum += a[i];
        if(NowSum > MaxSum)
        {
            MaxSum = NowSum;
            End = i;
            if(flag > 0)
            {
                Start = flag;
                flag = 0;
            }
        }
        else if(NowSum <= 0)
        {
            NowSum = 0;
            flag = i+1;
            if(a[i]==0)
                {
                    Start = i;
                    End = i;
                }
        }
    }
    printf("%d %d %d", MaxSum, a[Start], a[End]);
    return MaxSum;
}