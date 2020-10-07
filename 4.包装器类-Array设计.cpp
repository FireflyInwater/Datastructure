#include<iostream>
#include<stdlib.h>
#define DefaultSize 10

// 包装类容器Array

template<class Type>
class Array{
    private:
        Type *elements; //数组存储
        int ArraySize; //current size
        void getArray(){
            elements = new Type[ArraySize];
            if(elements ==NULL){ //查看内存是否分配成功//只要需要申请内存就要进行内存检查
                ArraySize = 0;
                std::cerr<<"Memory Allocation Error"<<std::endl;
                return;
            }
        }; //dynamic allocate memory for array
    public:
        Array(int Size = DefaultSize);
        Array(const Array<Type> &x); //复制构造函数；深复制
        ~Array(){delete [] elements;} //析构函数
        Array<Type>& operator=(const Array<Type>&A); //copy array 函数返回值为引用：可以避免内存的再分配。提高效率
        Type& operator[](int i); //get the ith element
        Type* operator*() const{ //* operator
            return elements;
        }
        int Length() const {return ArraySize;} //get the length
        void ReSize(int sz); //resize the array；
};

template<class Type>
Array<Type>::Array(int sz){
    if(sz<=0){
        ArraySize = 0;
        std::cerr<<"非法数组大小"<<std::endl;
        return;
    }
    ArraySize = sz;
    getArray();
}

template<class Type>
Array<Type>::Array(const Array<Type>&x){
    //copy constructor
    int n = ArraySize = x.ArraySize;  //获取对象x的数组大小
    elements = new Type[n]; //申请内存
    if(elements == NULL){
        ArraySize = 0;
        std::cerr<<"内存分配失败"<<std::endl;
        return;
    }
    Type* sourcePoint = x.elements;
    Type* destintPoint = elements;
    while (n--)
    {
        *destintPoint = *sourcePoint; //复制
        destintPoint++;//指针移向下个存储单元
        sourcePoint++;
    }
}

template<class Type>
Type& Array<Type>::operator[](int i){
    //获取下标为i的元素
    //数组运算符重载；防止越界；c++没有越界检查？？
    if(i<0||i>ArraySize-1){
        std::cerr<<"下标越界"<<std::endl;
      //  return NULL;//这里其实应该抛出异常
    }
    return elements[i];
}

template<class Type>
void Array<Type>::ReSize(int sz){
    if(sz>=0;sz!=ArraySize){
        Type* newarray = new Type[sz];
        if(newarray==NULL){
        std::cerr<<"内存分配失败"<<std::endl;
        return;           
        }
    int n = (sz<=ArraySize)?sz:ArraySize;
    Type* srcptr = elements;
    Type* destptr = newarray;
    while(n--) *destptr++ = *srcptr++;jiancha
    delete [] elements; //清除原有内存
    elements = newarray; //注意：原有指针还在。
    ArraySize = sz;
    }
}

int main(){
    Array<int> a;
    std::cout<<a[1]<<std::endl;
    return 0;
}


//总结：分配内存必定要内存检查
//总结：涉及到下标必定要想到越界检查