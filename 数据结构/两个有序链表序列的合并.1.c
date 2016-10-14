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
    int m,n;
    List L1, L2,L;
    printf("数列1的数字个数为：");
    scanf("%d",&m);
    printf("请按从小到大的顺序输入%d个数字：",m);
    L1 = Read(m);
    
    printf("数列2的数字个数为：");
    scanf("%d",&n);
    printf("请按从小到大的顺序输入%d个数字：",n);
    L2 = Read(n);
    
    Print(L1);
    printf("\r");
    Print(L2);
    printf("\r");
    L = Merge(L1, L2);
    Print(L);
    return 0;
}

List Read(int i)
{
    List head = (List)malloc(sizeof(List));
    head->Next = NULL;
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
    return head->Next;
}

void Print(List head)
{
    List p;
    p = head;
    while(p != NULL)
    {
        printf("%d ",p->Data);
        p = p->Next;
    }
}
/* 你的代码将被嵌在这里 */

List Merge(List L1, List L2)
{
    List head = (List)malloc(sizeof(List));
    head->Next = NULL;
    List p = head;
    while(L1 != NULL && L2!= NULL)
    {
        if(L1->Data < L2->Data)
        {
            p->Next = L1;
            L1 = L1->Next;
        }
        else
        {
            p->Next = L2;
            L2 = L2->Next;
        }
        p = p->Next;
    }
    if(L1 != NULL)
    {
        p->Next = L1;
    }
    if(L2 != NULL)
    {
        p->Next = L2;
    }
    return head->Next;
}
