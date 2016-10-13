#include <time.h>
#include <stdio.h>

void Print1N();
void Print2N();

int main()
{
    int N;
    printf("请输入一个数字:");
    scanf("%d", &N);
    clock_t start1, finish1, start2, finish2;
    
    start1 = clock();

    Print1N(N);
    
    finish1 =clock();
    
    start2 = clock();
    
    Print2N(N);
    
    finish2 =clock();
    
    printf("%f s\n\r",(double)CLOCKS_PER_SEC);
    printf("循环开始时间：%f s\n\r",(double)(start1)/ CLOCKS_PER_SEC);
    printf("循环结束时间：%f s\n\r",(double)(finish1)/ CLOCKS_PER_SEC);
    printf("循环用时：%f s\n\r",(double)(finish1-start1)/ CLOCKS_PER_SEC);

    printf("递归开始时间：%f s\n\r",(double)(start2)/ CLOCKS_PER_SEC);
    printf("递归结束时间：%f s\n\r",(double)(finish2)/ CLOCKS_PER_SEC);
    printf("递归用时：%f s\n\r",(double)(finish2-start2)/ CLOCKS_PER_SEC);

    return 0;
}

//用循环实现
void Print1N(int N)
{
    int i;
    for(i=1;i<=N;i++)
    {
        printf("%d\n", i);
    }
    return;
}

//用递归实现
void Print2N(int N)
{
    if(N)
    {
        Print2N(N-1);
        printf("%d\n", N);
    }
    return;
}
