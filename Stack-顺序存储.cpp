#include<iostream>

template <class Type>
class Stack{
    private:
        Type *data; //顺序存储结构。利用数组实现。
        int Maxsize;
        int top; //栈顶
    public:
        Stack(int max){
            Maxsize = max;
            data = new Type [Maxsize]; //分配内存
            if(data==NULL){
                std::cerr<<"内存分配失败"<<std::endl;
            }
            top =  -1;
        }
        ~Stack();
        int push(Type elem); //入栈
        Type pop(); //出栈
};

template<class Type>
Stack<Type>::~Stack(){
    std::cout<<"clear the stack..."<<std::endl;
    while (top!=-1)
    {
        pop();
    }
    std::cout<<"clear done!"<<std::endl;
}

template<class Type>
int Stack<Type>::push(Type elem){
    //判断栈是否已满
    if(top<Maxsize-1){
    //将元素压入栈内
        top++;
        data[top] = elem;
        return 1;
    }
    std::cout<<"超出最大容量"<<std::endl;
    return 0;
}

template<class Type>
Type Stack<Type>::pop(){
    //判断是否为空栈
    if(top!=-1){
        Type tmp = data[top];
        top--;
        return tmp;
    }
    std::cout<<"empty!"<<std::endl; 
}

int main(){
    Stack<int> stack_test(1);
    stack_test.push(1);
    stack_test.push(2);
    stack_test.push(3);
    stack_test.push(4);
    stack_test.push(5);
    stack_test.push(6);
    stack_test.push(7);
    stack_test.push(8);
    stack_test.push(9);
    stack_test.push(10);
    stack_test.push(11);
    for(int i = 0;i<10;i++){
        std::cout<<stack_test.pop()<<std::endl;
    }
    
    return 0;
    }