#include<iostream>

#define MAXSIZE 20 /*存储空间一定*/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType; // 这里将数据类型定为int

typedef struct{
    ElemType data[MAXSIZE];//数组存储数据
    int length; //线性表当前长度
}SqList;


Status InitList(SqList *L){
    //
    L->length = 0;
    return OK;
}

//   GetElem(L,i,*e):将L表中第i个位置元素值返回给e
Status Get_Elem(SqList L,int i,ElemType *e){
    if(L.length ==0 || L.length < i|| i<1)
        return ERROR;
    *e = L.data[i-1];
     return OK;
}

//在线性表L的i处插入e；
Status ListInsert(SqList *L,int  i ,ElemType e){
    // 插入位置不合理，抛出异常
    if(i<1||i>L->length+1)
        return ERROR;
    if(L->length>=MAXSIZE){
        std::cout<<"Sqlist is full"<<std::endl;
        return ERROR;
    }
    else
    {
        for(int j = L->length;j > i;j--){
            L->data[j] = L->data[j-1];
        }
        L->data[i] = e;
    }
    L->length += 1;
    return OK;
}

//删除L中第i个元素返回给e
Status  ListDelete(SqList *L,int i,ElemType *e){
    //判断要删除的位置是否合理
    if(i<1||i>L->length) //要删除的位置不正确
        return ERROR;
    if(L->length==0) //表是空表
        return ERROR; 
    //移动数据
    *e = L->data[i]; //返回值
    for(int k = i;k<L->length;k++){
        L->data[k] = L->data[k+1];
    }
    L->length -= 1;
    return OK;
}

Status printList(SqList L){
    if(L.length==0) return  ERROR;
    for(int i=0;i<L.length;i++){
        std::cout<<L.data[i]<<std::endl;
    }
    return OK;
}

int main(){
    SqList L;
    InitList(&L);
    return 0;
}