//链表的创建步骤
//stdlib.h 
//动态分配函数  void *malloc*(int size)
//释放内存函数  void free(void *p)

#include <stdlib.h>
#include <stdio.h>
struct node
{
    char name[20];
    char adress[20];
    char phone[15];
    struct node *link;      //每一个类型为node的结构体都含有一个指向相同类型结构体的指针
}
typedef struct node NODE    //简化定义结构体命令

void main()
{
    NODE *head;                 //说明头指针head
    //添加头节点
    NODE *p;                    //移动指针
    p = (NODE *)malloc(sizeof(NODE));
    p->link = NULL;
    head = p;
    //创建一个空链表，此时head->link是NULL，创建新的数据节点后，head->link 指向第一个数据节点

    //创建新的数据节点
    void creat(NODE *head, int n);
    creat(NODE *head, 2);       //添加2个数据节点

    //输出数据节点的数据
    void output(NODE *head);
    output(NODE *head);

}

//新建n个数据节点
void creat(NODE *head, int n)
{
    //创建一个指向类型为node的结构体的指针
    printf("请输入%d个新名字：",&n);
    NODE *p;
    for(;n>0;n--)
        p = (NODE *)malloc(sizeof(NODE));
        gets(p->name);          //读取数据
        p->link = head->link;   //新数据节点的尾部与head->link指向的节点头部连在一起
        head->link = p;         //将head->link与新数据节点的头部连在一起，完成新建节点
}

//在第i个节点后插入一个数据节点
void insert(NODE *head, NODE *q, int i)
{
    printf("请输入想插入的名字：");
    //创建一个指向类型为node的结构体的指针
    NODE *p; 
    int n = 0;

    //定位
    for(p = head; (n<i && p->link) != NULL; i++)
        p = p->link;

    //链接想要插入的节点
    q->link = p->link;
    p->link = q;
}

//输出所有数据节点中的数据
void output(NODE *head)
{
    //创建一个指向类型为node的结构体的指针
    NODE *p;
    p = head->link;             //p指向第一个数据节点
    while(p!=NULL)
        puts(p->name);          //输出节点中存储的名字
        p = p->link;            //将p->link赋值给p,则p指向下一个数据节点
}

//删除第i个节点
void delete(NODE *head, int i)
{
    for(p = head; (n<i-1 && p->link) != NULL; i++)      //定位到要删除的节点前面一个节点
        p = p->link;
    if((i>0 && p->link) != NULL)
        q = p->link;
        q->link = p->link;
        free(p);
}


