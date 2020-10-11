//STL 中提供的线性结构容器：
//vector；deque；string

/*vector */
//线性表的线性容器，模板类，提供了强大的操作
//#include<vector>


/*
查找：无序数据元素存储到顺序结构，
顺序查找O（n）
折半查找
hash
*/

/*
//折半查找算法
**递归：递归深度过大时会造成栈溢出。
**非递归：一般采用循环方式解决
*/


#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>&num ,int target){ //顺序查找，vector
    int i = 0;
    while(i<num.size()){
        if(num[i] == target){
            return i;
            break;
        }
        i++;
    }
    return -1;
}
int binarySearch(vector<int> &nums,int target){ //折半查找，nums为顺序序列,返回位置索引
    int start = 0;
    int end = nums.size() - 1;
    while (start<=end)    /*循环查找，直到左右两个边界重合*/
    {
        int mid = (int)(start + end) / 2;
        //cout<<mid<<endl;
        if(target == nums[mid]){
            return mid; 
        }
        else if (target>nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }        
    }
    return -1;
}

int binartSearchA(vector<int> &nums,int target){//查找第一个
    int start = 0;
    int end = int (nums.size()) - 1;
    while (start + 1< end) //为什么？
    {
        int mid = start  + (end - start) / 2; //防止整数溢出的技巧
        if(nums[mid] == target){
            end = mid; //如果找到了target,则继续对start~mid段数据进行二分查找
        }
        else if(nums[mid] < target){
            start = mid;
        }
        else // if(nums[mid] > target)
        {
            end = mid;
        }
    }
    if(nums[start]==target) return start;
    if(nums[end]==target) return end;
    return -1;
}

int main(){
    vector<int> array;
    vector<int>::iterator it;
    array.push_back(3); //将变量插到vector的最后；
    array.push_back(4);
    array.push_back(5);
    array.push_back(8);
    array.push_back(8);
    array.push_back(8);
    array.push_back(8);
    array.push_back(10);
    array.push_back(13);
    array.push_back(15);

/*     for(int i = 0;i<array.size();i++){ //array.size()返回vector的大小
        cout<<array[i]<<endl;
    }
    cout<<endl;
    for(it = array.begin();it!=array.end();it++){
        cout<<*it<<endl;
    } */
    cout<<search(array,8)<<endl;
    cout<<search(array,88)<<endl;
    cout<<binarySearch(array,8)<<endl;
    cout<<binarySearch(array,88)<<endl;
    return 0;

}