#include<iostream>

template<class Type>
class Tree{
    struct TreeNode
    {
        Type data;
        int parent; //双亲表示法 //静态链表（数组）
        // TreeNode(Type val,int parentIndex):data(val),parent(parentIndex){};
    };
    int max_tree_size;
    TreeNode* nodes;
    int root_index,node_num;//根节点位置和目前的节点数目
    
    public:
        Tree(int maxval){
            nodes = new TreeNode[maxval];
            nodes[0].parent = -1;
            node_num = 1;
        };
        void addNode(Type val,int index,int parentIndex);
};

template<class Type>
void Tree<Type>::addNode(Type val,int index,int parentIndex){
    if(node_num==1){
        nodes[1].data = val;
        nodes[1].parent = 0;}
    else{
        nodes[index].data = val;
        nodes[index].parent = parentIndex;
        }
}

int main(){
    Tree<int> TestTree(5);
    TestTree.addNode(1,1,0);
    TestTree.addNode(2,2,0);
    return 0;
}