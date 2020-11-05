#include<queue> //用自带的库实现队列
#define MAXVEX 100  //最大顶点数，由用户决定
#define INFINITY 65535 // 用65535表示无穷
typedef bool Boolean;

template<class VertexType,class EdgeType>
class MGraph{
    VertexType vexs[MAXVEX]; //顶点表
    EdgeType arc[MAXVEX][MAXVEX]; //邻接矩阵，可看作边表
    int numVertexes,numEdges; //图中当前的顶点数和边数 
    Boolean visited[MAXVEX];
    public:
        void CreateMGraph(MGraph &G);
        void DFSTraverse(MGraph G);
        void DFS(MGraph G,int i);
        void BFSTraverse(MGraph G);//邻接矩阵的广度遍历算法
};

template<class VertexType,class EdgeType>
void MGraph<VertexType,EdgeType>::CreateMGraph(MGraph &G){
    int i,j,k,w;
    std::cout<<"输入顶点数和边数："<<std::endl;
    std::cin>>G.numVertexes;
    std::cin>>G.numEdges;
     std::cout<<"输入顶点表："<<std::endl;
    for(i = 0;i<G.numVertexes;i++){//建立顶点表 //一维数组
        std::cin>>G.vexs[i];
    }
    for ( i = 0; i < G.numVertexes; i++)
        for (j = 0; j < G.numVertexes; j++)
        {
            G.arc[i][j] = INFINITY; //邻接矩阵初始化
        }
    for (k = 0; k < G.numEdges; k++)//建立邻接矩阵
    {
        std::cout<<"输入边（vi，vj）上的下标i、下标j和权w:"<<std::endl;
        std::cin>>i;
        std::cin>>j;
        std::cin>>w;
        G.arc[i][j] = w;
        G.arc[j][i] = G.arc[i][j];//无向图，对称
    }
}

template<class VertexType,class EdgeType>
void MGraph<VertexType,EdgeType>::BFSTraverse(MGraph G){
    int i,j;
    std::queue<int> Q;
    for (i = 0; i <G.numVertexes; i++)
    {
        visited[i] = false; //初始化访问标志位
    }
    for(i = 0;i<G.numVertexes;i++){
        if(!visited[i]){
            visited[i] = true;
            std::cout<<G.vexs[i]<<std::endl;
            Q.push(i);//入队列
            while (!Q.empty())
            {
                Q.pop();//出队列
                for (j = 0; j < G.numVertexes; j++)
                {
                    if(G.arc[i][j]==1&&!visited[j]){
                        visited[j] = true;
                        std::cout<<G.vexs[j]<<std::endl;
                        Q.push(j);
                    }
                }
            }
        }
    }
}
