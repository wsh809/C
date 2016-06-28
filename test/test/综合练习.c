#include <stdio.h>
#include <stdlib.h>
#define N 10

int cmp(const void *a,const void *b)        //若return *(int*)a - *(int*)b 则从小到大排序
{
    return *(int*)b - *(int*)a;
}

int Sum(int score[]){
    int s = 0,i;
    for(i = 0 ; i < N ; i++)
        s += score[i];
    return s;
}

int Max(int score[]){
    return score[0];
}

int Min(int score[]){
    return score[N-1];
}

double Avg(int s){
    return (s + 0.0) / N;
}

int main()
{
    int score[N]={67,98,75,63,82,79,81,91,66,84};
    int i,sum;
    sum = Sum(score);
    qsort(score,N,sizeof(int),cmp);//sort it
    //四个参数分别为 要进行排序数组的首地址，参加排序的元素个数，每个元素所占字节，和比较函数
    
    printf("Total score : %d\n",sum);
    printf("Max score : %d\n",Max(score));
    printf("Min Score : %d\n",Min(score));
    printf("Average score : %f\n",Avg(sum));
    printf("\n成绩排序:\n");
    for(i = 0 ; i < N ; i++)
    {
        printf("Rank %d's score : %d\n",i+1,score[i]);
    }
    return 0;
}