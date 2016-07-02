/*输出不及格同学的成绩*/
#include<stdio.h> 
void  search(float (*p)[4],int  n)          
{ int  i,j,flag; 
  for(j=0;j <n;j++) 
  { flag=0;                                         /*设置标志，用来标识不及格的同学*/ 
    for(i=0;i<4;i++) 
       if(*(*(p+j)+i)<60)                           /*查找不及格的分数*/
          flag=1;                                    
       if(flag==1) 
         { printf("No.%d fails，his scores are:\n",j+1);
           for(i=0;i<4;i++) 
           printf("%5.1f", (*(*(p+j)+i)) );
           printf("\n");  }
        }
}
int main()
{  float score[3][4]={{65,57,70,60},{68,87,90,81},{50,99,100,98}};
   search(score,3);                                /*二维数组名做函数实参*/
return 0; 
}


/*输出三个学生四门课平均分*/
#include<stdio.h>
int main()
   {  void average(float *p,int n);
      void search(float (*p)[4],int n);
      int k; 
      float score[3][4] ={{65,67,70,60},{80,87,90,81},{90,99,100,98}};
      scanf("%d",&k);                       /*输出第k个同学的成绩*/
      average(*score,12);                   /*用二维数组第0行的首地址做实参调用函数*/ 
      search(score,k);                      /*用二维数组名做实参调用函数*/
      return 0;         
}
/*求全部分数的平均分*/
void  average(float *p,int n)               /*指向变量的指针做函数形参*/ 
{  float *p_end; 
   float  sum=0,aver;     
   p_end=p+n-1;                       
   for(;p<=p_end;p++)    
      sum=sum+(*p);   
   aver=sum/n;
   printf("average=%5.2f\n",aver);
} 
/*输出指定学生的成绩*/
void search(float(*p)[4],int n )             /*行指针做函数形参*/
{int  i;
    printf("the score of No.%d are：",n); 
    for(i=0;i<4;i++)
    printf("%7.2f",*(*(p+n)+i));             /*在第n行移动指针，输出该同学的全部成绩*/
}