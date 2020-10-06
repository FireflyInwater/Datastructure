#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;

void buuleSort(int *a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return;
}

int Fib(int N){//斐波那契数列
    if(N<=1)
        return 1;
    else
    {
        return(Fib(N-1)+Fib(N-2));
    }   
}


int main(){
    int *data; //存放数据
    int test[5]={1,5,10,15,50};
    int scale[10] = {1000,5000,10000,15000,20000};  //数据规模
    clock_t start,end; //根据cpu得到的时钟；

    for(int i =0;i<5;i++){
        data = new int[scale[i]];
        for(int j = 0;j<scale[i];j++)
            data[j] = int(random());
            start = clock();
            buuleSort(data,scale[i]);
            end = clock();
            cout<<scale[i]<<" "<<end-start<<endl;
            delete [] data;
    }

    for(int i=0;i<5;i++){
        start = clock();
        end = clock();
        cout<<Fib(test[i])<<" "<<end-start<<endl;
    }
    return 0;
}