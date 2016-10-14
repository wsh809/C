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
    List head;
    List p;
    p = (List)malloc(sizeof(List));
    p->Next = NULL;
    head = p;
    
    int m,n;
    List L1, L2, L;
    printf("数列1的数字个数为：");
    scanf("%d",&m);
    printf("请按从小到大的顺序输入%d个数字：",m);
    L1 = Read(head,m);
    
    printf("数列2的数字个数为：");
    scanf("%d",&n);
    printf("请按从小到大的顺序输入%d个数字：",n);
    L2 = Read(head,n);
    
    L = Merge(L1, L2);
    // Print(L);
    Print(L1);
    Print(L2);
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
    while(p != NULL)
    {
        printf("%d",p->Data);
        p = p->Next;
    }
}
/* 你的代码将被嵌在这里 */

List Merge(List L1, List L2)
{
    List p = L1;
    List q1 = L2;
    List q2 = L2->Next;
    List r = p;
    while(r != NULL)
    {
        p = r;
        //若L1节点中的数小于 L2节点中的数，则将L1链接在L2该结点之前
        if(p->Data < q1->Data)
        {
            r = r->Next;
            p->Next = q1;
            L2 = p;
        }
        else if(p->Data < q2->Data)
        {
            r = r->Next;
            q1->Next = p;
            p->Next = q2;
            q1 = q1->Next;
            q2 = q2->Next;
        }
        else if(q1 != NULL)
        {
            q1 = q1->Next;
            q2 = q2->Next;
        }
        else
        {
            q1->Next = p;
            return L2;
        }
    }
    return L2;
}
