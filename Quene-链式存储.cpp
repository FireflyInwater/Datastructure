#include<iostream>


template<class Type>
class Queue_List{
    private:
        struct Qnode
        {
            Type data;
            Qnode* next;
            Qnode(Type val):data(val),next(nullptr){};
        };
        Qnode* front,*rear;        
        int length;
    public:
        Queue_List();
//        ~Queue_List();
        int enQueue(Type elem);//进队列
        Type deQueue();//出队列
};


template<class Type>
Queue_List<Type>::Queue_List(){
    //初始化队列。带头结点。空队列时front和rear都指向头结点；
    Qnode* head = new Qnode(0);
    front = head;
    rear = head;
    length = 0;
}

template<class Type>
int Queue_List<Type>::enQueue(Type elem){
    Qnode * newQnode = new Qnode(elem);
    rear->next = newQnode;
    rear = newQnode;
    length++;
    return 1;
}

template<class Type>
Type Queue_List<Type>::deQueue(){
    //判断是否是空队列
    if(front == rear)
        std::cout<<"empty!"<<std::endl;
    else
    {
        Qnode* tmp = front->next;
        front->next = tmp->next;
        Type returnElem = tmp->data;
        if(rear == tmp)//如果删除的是最后一个节点,队列尾巴重新指向队列头。
            rear = front; 
        delete tmp; 
        length--;
        return returnElem;
    }
}


int main(){
    Queue_List<int> Qlist;
    Qlist.enQueue(1);
    Qlist.enQueue(2);
    Qlist.enQueue(3);
    std::cout<<Qlist.deQueue()<<std::endl;
    std::cout<<Qlist.deQueue()<<std::endl;
    std::cout<<Qlist.deQueue()<<std::endl;
    return 0;
}