#include<iostream>
#define MAXVEX 100  //最大顶点数，由用户决定
#define INFINITY 65535 // 用65535表示无穷

template<class VertexType,class EdgeType>
class MGraph{
    VertexType vexs[MAXVEX]; //顶点表
    EdgeType arc[MAXVEX][MAXVEX]; //邻接矩阵，可看作边表
    int numVertexes,numEdges; //图中当前的顶点数和边数 
    public:
        void CreateMGraph(MGraph &G);
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

int main(){
    MGraph<int,int> testMgraph;
    testMgraph.CreateMGraph(testMgraph);
    return 0;
}