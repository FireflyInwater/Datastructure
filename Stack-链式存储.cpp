#include<iostream>

template<class Type>
class Stack_List{
    private:
        struct StacklistNode //节点
        {
            Type data;
            StacklistNode* nextptr;
             StacklistNode(int val):data(val), nextptr(nullptr){} //参数初始化列表
        };
        StacklistNode* top; //栈顶
        int count;
    public:
        Stack_List();
        ~Stack_List();
        int push(Type elem);
        Type pop();
};

template<class Type>
Stack_List<Type>::Stack_List(){
    top = NULL; //空栈
    count = 0;
}


template<class Type>
Stack_List<Type>::~Stack_List(){
     std::cout<<"clear the stack..."<<std::endl;
    while (top)
    {
        pop();/* code */
    }
    
     std::cout<<"clear done!"<<std::endl;
}

template<class Type>
int Stack_List<Type>::push(Type elem){
    StacklistNode* new_node = new StacklistNode(elem);
    if(!top){
        top = new_node;
    }
    else
    {
        new_node->nextptr = top;
        top = new_node;
    }
    count++;
    return 1 ;
}

template<class Type>
Type Stack_List<Type>::pop(){
    if(top == NULL){
        std::cout<<"empty!"<<std::endl;
    }
    Type returnElem = top->data;
    StacklistNode * tmp = top;
    top = top->nextptr;
    count--;
    delete tmp;
    return returnElem;
}

int main(){
    Stack_List<int> stack_list_test;
    stack_list_test.push(1);
    stack_list_test.push(2);
    stack_list_test.push(3);
    stack_list_test.push(4);
    std::cout<<stack_list_test.pop()<<std::endl;
    std::cout<<stack_list_test.pop()<<std::endl;
    return 0 ;
}