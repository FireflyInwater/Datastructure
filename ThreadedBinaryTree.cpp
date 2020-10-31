/*
线索二叉树。主要是每个节点中加入了前驱后继标志位；
*/

template<class Type>
class ThreadedBinaryTree{
    struct ThreadedBinaryTreeNode
    {
        Type data; //数据域
        ThreadedBinaryTreeNode * leftptr;
        bool leftflag; //当flag为0时，leftptr指向的是child node。flag=1则是指向前驱
        ThreadedBinaryTreeNode * rightptr;
        bool rightflag; //rightflag=1，righptr指向后继
        ThreadedBinaryTreeNode(Type val):data(val),leftptr(nullptr),leftflag(true),rightptr(nullptr),rightflag(true){};
    };
    ThreadedBinaryTreeNode* root;
    ThreadedBinaryTreeNode* pre;
    public:
        ThreadedBinaryTree();
        void InCreateTBTree(ThreadedBinaryTreeNode **head);// 中序创建
        void InThreading(ThreadedBinaryTreeNode* p);//中序遍历线索化
        void InOrderTraverse(ThreadedBinaryTreeNode * p);//中序遍历
};


template<class Type>
ThreadedBinaryTree<Type>::ThreadedBinaryTree(){
    InCreateTBTree(&root);
}

template<class Type>
void ThreadedBinaryTree<Type>::InCreateTBTree(ThreadedBinaryTreeNode ** head){
    Type cin_tmp;
    std::cout<<"please input the data"<<std::endl;
    std::cin>>cin_tmp;
    if(cin_tmp == 0){
        *head = NULL;
        return;}
    else{
        InCreateTBTree(&((*head)->leftptr));
        *head = new ThreadedBinaryTreeNode(cin_tmp);
        InCreateTBTree(&(*(head)->rightptr));
    }
}

template<class Type>
void ThreadedBinaryTree<Type>::InThreading(ThreadedBinaryTreeNode* p){
    if(p){
        InThreading(p->leftptr);
        //线索化
        if(!p->leftptr){
            p->leftflag = false;
            p->leftptr = pre;
        }
        if(!pre->rightptr){
            pre->rightflag = false;
            pre->rightptr = p;
        }
        pre = p;
        InThreading(p->rightptr);
    }
}