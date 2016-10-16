/*
 题目：本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。
 
 函数接口定义：
 
 List Merge( List L1, List L2 );
 其中List结构定义如下：
 
 typedef struct Node *PtrToNode;
 struct Node {
 ElementType Data; // 存储结点数据
 PtrToNode   Next; // 指向下一个结点的指针
 };
 typedef PtrToNode List; // 定义单链表类型
 L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；函数Merge要将L1和L2合并为一个非递减的整数序列。应直接使用原序列中的结点，返回归并后的链表头指针。
 
 裁判测试程序样例：
 
 #include <stdio.h>
 #include <stdlib.h>
 
 typedef int ElementType;
 typedef struct Node *PtrToNode;
 struct Node {
 ElementType Data;
 PtrToNode   Next;
 };
 typedef PtrToNode List;
 
 List Read(); // 细节在此不表
 void Print( List L ); // 细节在此不表；空链表将输出NULL
 
 List Merge( List L1, List L2 );
 
 int main()
 {
 List L1, L2, L;
 L1 = Read();
 L2 = Read();
 L = Merge(L1, L2);
 Print(L);
 Print(L1);
 Print(L2);
 return 0;
 }
 
 // 你的代码将被嵌在这里
 输入样例：
 
 3
 1 3 5
 5
 2 4 6 8 10
 输出样例：
 
 1 2 3 4 5 6 8 10
 NULL
 NULL
 */

/*
 总结：
 刚开始对头指针和头节点的概念还不是很清楚，参考别的程序，有的程序链表是带头节点的，有的程序是不带的，所以出现了各种各样的错误
 考虑的时候还可以 考虑到了只有一个链表处理完毕的情况
 */
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
    
    List L1,L2,L;
    
    
    int m,n;
    printf("数列1的数字个数为：\n");
    scanf("%d",&m);
    printf("请按从小到大的顺序输入%d个数字：\n",m);
    L1 = Read(m);
    
    printf("数列2的数字个数为：\n");
    scanf("%d",&n);
    printf("请按从小到大的顺序输入%d个数字：\n",n);
    L2 = Read(n);
    
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);

    
    return 0;
}

List Read(int i)
{
    List  head = (List)malloc(sizeof(List));
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
    putchar('\n');
}
/* 你的代码将被嵌在这里 */

List Merge(List L1, List L2)
{
    List L3 = (List)malloc(sizeof(List));
    List p1,p2,p3;
    p3 = L3;
    L3->Next = NULL;
    p1 = L1->Next;
    p2 = L2->Next;
    while(p1 != NULL && p2!= NULL)
    {
        if(p1->Data < p2->Data)
        {
            p3->Next = p1;
            p1 = p1->Next;
            p3 = p3->Next;
        }
        else
        {
            p3->Next = p2;
            p2 = p2->Next;
            p3 = p3->Next;
        }
        p3->Next = NULL;
        
    }
    if(p1 != NULL)
    {
        p3->Next = p1;
    }
    if(p2 != NULL)
    {
        p3->Next = p2;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return L3;
}
