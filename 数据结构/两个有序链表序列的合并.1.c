//裁判测试程序样例：
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    int Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List head1 = (List)malloc(sizeof(List));
    head1->Next = NULL;
    List head2 = (List)malloc(sizeof(List));
    head2->Next = NULL;
    List head3 = (List)malloc(sizeof(List));
    head3->Next = NULL;
    List L1,L2,L;
    
    
    int m,n;
    printf("数列1的数字个数为：");
    scanf("%d",&m);
    printf("请按从小到大的顺序输入%d个数字：",m);
    L1 = Read(head1,m);
    
    printf("数列2的数字个数为：");
    scanf("%d",&n);
    printf("请按从小到大的顺序输入%d个数字：",n);
    L2 = Read(head2,n);
    
    L = Merge(L1, L2);
    Print(L);
    printf("\r");
    Print(L1);
    printf("\r");
    Print(L2);
    printf("\r");
   
    return 0;
}

List Read(List head, int i)
{
    
    List p;
    List q;
    q = head;
    for(;i>0;i--)
    {
        p = (List)malloc(sizeof(List));
        scanf("%d",&p->Data);
        q->Next = p;
        p->Next = NULL;
        q = p;
    }
    return head;
}

void Print(List head)
{
    List p;
    p = head->Next;
    if(p == NULL)
        printf("NULL ");
    while(p != NULL)
    {
        printf("%d ",p->Data);
        p = p->Next;
    }
}
/* 你的代码将被嵌在这里 */

List Merge(List L1, List L2)
{
    List L3 = (List)malloc(sizeof(List));
    List p1,p2,p3,add;
    p3 = L3;
    L3->Next = NULL;
    p1 = L1->Next;
    p2 = L2->Next;
    while(p1 != NULL && p2!= NULL)
    {
        if(p1->Data < p2->Data)
        {
            add = p1;
            p1 = p1->Next;
        }
        else
        {
            add = p2;
            p2 = p2->Next;
        }
        p3->Next = add;
        add->Next = NULL;
        p3 = add;
    }
    if(p1 != NULL)
    {
        p3->Next = p1;
    }
    if(p2 != NULL)
    {
        p2->Next = p2;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return L3;
}
