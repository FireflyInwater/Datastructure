//二叉树的特点：
/*
每个节点最多两子树，即不存在degree大于2的节点；
左右树有顺序
满二叉树：所有分支节点都存在左右子树。并且所有叶子节点都在同一层。
完全二叉树：节点从左到右连续编号。且位置同满二叉树的编号对应。
*/

/*二叉树特点：
1、第i层最多2^（i-1）个节点
2、深度为k的二叉树最多2^k - 1 个节点
*/

//顺序存储结构一般只用于完全二叉树

//链式存储二叉树：

#include<iostream>

template<class Type>
class BinaryTree
{
private:
    struct BinaryTreeNode
    {
        Type data;
        BinaryTreeNode * lchild,*rchild;
        BinaryTreeNode(Type val):data(val),lchild(nullptr),rchild(nullptr){};
    };
public:
    BinaryTreeNode *Bitree;//头节点
    // BinaryTree();
    void PreOrderTraverse(BinaryTreeNode *Btree);
    void InOrderTraverse(BinaryTreeNode *Btree);
    void PostOrderTraverse(BinaryTreeNode *Btree);
    void CreateBiTreePre(BinaryTreeNode **Btree);
    BinaryTreeNode*  CreateBiTree(){
            Type val;
            std::cin>>val;
            if(val==0)
                return NULL;
            BinaryTreeNode* new_node = new BinaryTreeNode(val);
            new_node->lchild = CreateBiTree();
            new_node->rchild = CreateBiTree();
            return new_node; 
    };
};

// template<class Type>
// BinaryTree<Type>::BinaryTree(){
//     CreateBiTree(Bitree);
// }
template<class Type>
void BinaryTree<Type>::PreOrderTraverse(BinaryTreeNode * Btree){
    //前序遍历二叉树
    //判断是否为空树
    if(Btree == NULL)
        return;
    //否，则递归遍历
    else{
        std::cout<<"data = "<<Btree->data<<std::endl; //打印节点数据。可更改为其他操作
        PreOrderTraverse(Btree->lchild); //左遍历
        PreOrderTraverse(Btree->rchild); // 右遍历
    }
}

template<class Type>
void BinaryTree<Type>::InOrderTraverse(BinaryTreeNode *Btree ){
    //中序遍历二叉树
    //判断是否为空
    if(Btree == NULL)
        return;
    //否
    else{
       InOrderTraverse(Btree->lchild);
        std::cout<<"data = "<<Btree->data<<std::endl; //打印节点数据。可更改为其他操作
        InOrderTraverse(Btree->rchild);
    }
}

template<class Type>
void BinaryTree<Type>::PostOrderTraverse(BinaryTreeNode * Btree){
    //后序遍历二叉树
    //判断是否为空
    if(Btree == NULL)
        return;
    //否
    else{
        InOrderTraverse(Btree->lchild);
        InOrderTraverse(Btree->rchild);
        std::cout<<"data = "<<Btree->data<<std::endl; //打印节点数据。可更改为其他操作
    }
}

template<class Type>
void BinaryTree<Type>::CreateBiTreePre(BinaryTreeNode **Btree){
    //创建二叉树//前序//
    Type tmp;
    std::cin>>tmp;
    if(tmp==0){
        *Btree = NULL;
        return;
    }
    *Btree = new BinaryTreeNode(tmp);
    CreateBiTreePre(&((*Btree)->lchild));//构造左子树
    CreateBiTreePre(&((*Btree)->rchild)); //构造右子树
    }

struct node
{
    int data;    
};

void test(node **ptr){ //二级指针，实现对指针的指向赋值
    *ptr = new node;
    (*ptr)->data = 100;
}

int main(){
    BinaryTree<int> testBinarytree;
    // testBinarytree.Bitree =  testBinarytree.CreateBiTree();
    testBinarytree.CreateBiTreePre(&testBinarytree.Bitree);
    testBinarytree.PreOrderTraverse(testBinarytree.Bitree);
    // node* testptr;
    // test(&testptr);//传入指针变量的地址
    return 0;
}