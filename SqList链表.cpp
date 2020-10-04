//线性表的链式存储方式：链表
//链表的基本单元： Node=数据+指针
//这里指的是单链表

#include<iostream>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType; // 这里将数据类型定为int

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

//把 struct Node * 定义成了类型 LinkList。这个类型是一个结构体的指针
typedef struct Node *LinkList; /*定义链表*/

/*每一个Node节点是以指针表示的*/

Status CreateListHead(LinkList *L,int n){
    //头插法创建整表；新节点始终放在前面;
    
    LinkList p;
    *L = new Node; //头结点
    (*L)->next = NULL; 

    for(int i=0;i<n;i++)
    {
        p  = new Node;
        p->data = rand()%100 + 1; //每一个节点的数据
        p->next = (*L)->next;
        (*L)->next = p;
    }
    return OK;
}

Status CreateListTail(LinkList *L,int n){
    //尾插法；按节点生成顺序将每个新的节点放在表尾
    LinkList p,t; //t是指向最后一个节点的指针
    *L = new Node;
    t = *L;
    for(int i=0;i<n;i++){
        p = new Node;
        p->data = rand()%100 + 1;
        p->next = NULL;
        t->next = p;
        t = p;
    }
    return OK;
}


Status GetElem(LinkList L,int i, ElemType *e){
    int j = 1;
    LinkList p; //声明一个Node指针
    p = L->next; //让p指向链表的第一个节点
    while(p&&j<i){
        p = p->next; //工作-指针后移
        j++;
    }
    if(!p || j > i) //若p为空，说明i个元素不存在
        return ERROR;
    *e = p->data;
    return OK;
}

Status ListInsert(LinkList *L,int i,ElemType e){
    LinkList p,s;
    p = *L;
    int j = 1;
    while (p&&j<i) 
    {
       p =  p->next;
       j++;
    }
    if(!p || j>i) return ERROR;
    s = new Node; // 分配新的内存
    s->data = e;
    s->next = p->next; // 插入操作
    p->next = s;
    return OK;
}

Status ListDelete(LinkList *L, int i,ElemType *e){
    LinkList p,q;
    p = *L;
    int j = 1;
    while(p&&j<i){
        p = p->next;
        j++;
    }
    if(!p||j>i) return ERROR;
    q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q); //释放内存
    return OK;   
}

Status ClearList(LinkList *L)
{
    LinkList p,q;
    p = (*L)->next; //指向表头
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}


int main(){
    LinkList L1;
    CreateListTail(&L1,10);
    for(LinkList p = L1;p->next!=NULL;p++){
        std::cout<<p->data<<std::endl;
    }
    return 0;   
}