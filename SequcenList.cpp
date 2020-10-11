#include<iostream>
using namespace std;
#define defaultSize 10
//Sequence list: Dynamic array

template <class Type>
class SeqList{
    Type* data; //Array
    int MaxSize;
    int last; //index of the last element;;没有元素就为-1
    public:
        SeqList(int MaxSize = defaultSize);
        ~SeqList(){delete [] data;} //析构函数
        int Length() const {return last+1;} //const成员函数;不可以修改对象的数据
        int Find(Type &x)const; //任何不会修改数据成员的函数都应该声明为const类型
        int IsIn(Type &x);
        int Insert(Type &x,int i);
        int Remove(Type &x);
        int Next(Type &x);
        int Prior(Type &x);
        int IsEmpty(){return last==-1;}
        int IsFull(){return last == MaxSize;}
        Type Get(int i){ //返回index = i的元素
            return i<0||i>last?NULL:data[i];
        }
};

template<class Type>
SeqList<Type>::SeqList(int sz){
    if(sz>0){//参数合法性检查
        MaxSize = sz;
        last = -1;//初始无数据
        data = new Type[MaxSize];
        if(data==NULL){
            MaxSize = 0;
            last = -1;
            return;
        }
    }
}

template<class Type>
int SeqList<Type>::Find(Type &x) const{
    int i = 0;// 查找x是否在表中，如果在，返回其位置index
    while (i<=last&&data[i]!=x)
        i++;
    if(i>last) return -1; //failure
    else
    {
        return i;//success
    }
}

template<class Type>
int SeqList<Type>::Insert(Type &x,int i){
    //参数合法性判断
    if(i<0||i>last+1|| last== MaxSize-1)
        return 0;
    for(int j = last ;j >= i;j--){
        data[j+1] = data[j]
    }
    last++;
    // last++
/*      for(int j = last ;j > i;j--){
        data[j] = data[j-1]
    } */
    data[i] = x;
    return 1; //success
}

template<class Type>
int SeqList<Type>::Remove(Type &x){
    int i = Find(x);
    if(i>=0){
        last--;
        for(int j = i;i<=last;i++){
            data[j]=data[j+1]
        }
        return 1;
    }
    return 0;
}



/*
特点：
数据元素的逻辑关系很明确；
可随机存取元素；
插入、删除操作要通过移动元素实现，效率低；
元素较少时，存储空间利用率低；
*/

//application A n B
template<class Type>
int Union(SeqList<Type> &LA,SeqList<Type>LB){
    int len_LA = LA.Length(); 
    int len_LB = LB.Length();
    for(int i = 0;i<len_LB;i++){
        int k = LA.Find(LB.data[i]) //判断B中元素是否在A中
        if(k==-1){ //不在
            LA.Insert(LB.data[i],len_LA);
            len_LA++;
        }
    }
    return 1;
}