#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};
typedef struct node NODE;

void josef(int m, int n);
void exchange(int a[]);

void main()
{
    int m,n;
    printf("请输入总人数：");
    scanf("%d",&m);
    printf("请输入第几个人受到惩罚：");
    scanf("%d",&n);
    josef(m,n);
}

void josef(int m, int n)
{
    int i, k;
    int a[m/2];
    NODE *head, *p, *q;
    head = (NODE *)malloc(sizeof(NODE));
    head->num = -1;
    
    //生成循环链表
    head->next = NULL;
    for(i = 30; i>0; i--)
    {
        p = (NODE *)malloc(sizeof(NODE));
        p->num = i;
        p->next = head->next;
        head->next = p;
    }
    printf("the original circle is: ");
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = head->next;
    for(i=0; i<m/2; i++)
    {
        for(k=1; k<n; k++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        a[i] = q->num;
        free(q);
    }
    exchange(a);
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

