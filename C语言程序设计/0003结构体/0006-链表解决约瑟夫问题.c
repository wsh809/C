#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
}
typedef struct node NODE; 

void josef(int m, int n)

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
    for(i=0; i<15; i++)
    {
        for(k=1; k<9; k++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        printf("%d ", q->num);
        free(q);
    }
}

