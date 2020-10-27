 #include<iostream>
 using namespace std;

template<class Type>
class DoubleLinkedNode{ //双向链表的节点类定义
    friend class DoubleLinkedList<Type>;//友元类，使得链表对象可以访问。
    public:
    //构造函数
        DoubleLinkedNode(Type value,DoubleLinkedNode<Type> *leftP = NULL,DoubleLinkedNode<Type>*rightP = NULL):data(value),leftPtr(leftP),rightPtr(rightP){}
    private:
        Type data;
        DoubleLinkedNode<Type> *leftPtr,*rightPtr;
};


template<class Type>
class DoubleLinkedList
{
    private:
        DoubleLinkedNode<Type> *Head,*CurrentPtr;//头指针和目前的移动指针
    public:
        DoubleLinkedList(Type Value);
        ~DoubleLinkedList(); //析构函数
        int addNode(Type value);//在最后加一个节点
};

template<class Type>
DoubleLinkedList<Type>::DoubleLinkedList(Type Value){
    //初始化链表
    Head = new DoubleLinkedNode<Type>(Value); //头结点值可任意
    Head->leftPtr = Head;
    Head->rightPtr = Head;
    CurrentPtr = NULL;//Current 指针只指向有意义的节点.
}

template<class Type>
int DoubleLinkedList<Type>::addNode(Type value){
    DoubleLinkedNode<Type>* NewNode = new DoubleLinkedNode<Type>(value);
    if(NewNode==NULL){
        cerr<<"内存分配失败"<<endl;
        return 0;
    }
    if(CurrentPtr==NULL){//说明目前没有实际节点,newnode为首个实际节点
    NewNode->leftPtr = NewNode;
    NewNode->rightPtr = NewNode;
    Head->rightPtr = NewNode;
    CurrentPtr = NewNode;
    }

}
