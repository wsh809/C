
#include  <stdio.h>

int main()
{
    int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int (*p)[4], i, j;
    p = a;
    scanf("%d,%d", &i, &j);
    printf("a[%d][%d] = %d", i, j, *(*(p+i)+j));
}

/*用指针数组访问二维数组*/
#include<stdio.h>
int main()
{ static int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
  int *pa[3]={a[0],a[1],a[2]};
  int i,j;
  for(i=0;i<3;i++)
  for(j=0;j<4;j++)
     printf("%d,%d,%d\n",a[i][j],*(pa[i]+j),*(*(a+i)+j)); 
     printf("\n");
  return 0;
}

