#include<iostream>
using namespace std;

template<class Type> class CircularLinkedList
{
private:
    CircListNode<Type> * first,*current,*last;
public:
    CircularLinkedList(Type value);
    ~CircularLinkedList();
    int Length() const;
    Boolean IsEmpty(){
        return first->next == first;
    }
    Type getData() const;
    CircListNode<Type>* Find(Type value){;
    void Firster() (current = first;)
    void Insert(const Type &value); //current 指向当前节点位置
};

template <class Type>
 class CircListNode{
     friend class CircularLinkedList<Type>;
     public:
     CircListNode(Type d = 0,CircListNode<Type>*next = NULL):data(d),next(next){} // 构造函数
     private:
        Type data;
        CircListNode<Type> *next;
};

template<class Type>
CircListNode<Type>* CircularLinkedList<Type>::Find(Type value){
//在链表中从头搜说其数据为value的节点
CircListNode<Type>* p = first->next;
while (p!=first&&p->data!=value)//再次指到头部或者找到时退出
{
    p = p->next;
};
return (p!=first)?p:NULL; //判定是上述的哪一种
}
