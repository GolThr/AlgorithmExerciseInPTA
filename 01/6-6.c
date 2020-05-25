#include <stdio.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10  /* 最大顶点数设为10 */
#define INFINITY 65535   /* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;      /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;  /* 边的权值设为整型 */

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;  /* 顶点数 */
    int Ne;  /* 边数   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */
bool Visited[MaxVertexNum]; /* 顶点的访问标记 */

MGraph CreateGraph(); /* 创建图并且将Visited初始化为false；裁判实现，细节不表 */

void Visit( Vertex V )
{
    printf(" %d", V);
}

void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) );

int main()
{
    MGraph G;
    Vertex V;

    G = CreateGraph();
    scanf("%d", &V);
    printf("DFS from %d:", V);
    DFS(G, V, Visit);

    return 0;
}

MGraph CreateGraph(){
    int i, j;
    for(i = 0; i < MaxVertexNum; i++){
        Visited[i] = false;
    }
    MGraph G = (MGraph)malloc(sizeof(struct GNode));
    for(i = 0; i < MaxVertexNum; i++){
        for(j = 0; j < MaxVertexNum; j++){
            G -> G[i][j] = 0;
        }
    }
    G -> Nv = 7;
    G -> Ne = 9;
    G -> G[0][2] = 1; G -> G[0][3] = 1; G -> G[0][4] = 1;
    G -> G[1][3] = 1; G -> G[1][5] = 1; G -> G[2][0] = 1;
    G -> G[2][3] = 1; G -> G[2][5] = 1; G -> G[3][0] = 1;
    G -> G[3][1] = 1; G -> G[3][2] = 1; G -> G[4][0] = 1;
    G -> G[4][5] = 1; G -> G[5][1] = 1; G -> G[5][2] = 1;
    G -> G[5][4] = 1; G -> G[5][6] = 1; G -> G[6][5] = 1;

    return G;
}
/* 你的代码将被嵌在这里 */
//1. 递归方法
void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) ){
    int i;
    Visited[V] = true;
    Visit(V);
    for(i = 0; i < Graph -> Nv; i++){
        if(Graph -> G[V][i] == 1 && !Visited[i]){   //注意加上判断==1，否则PTA过不了
            DFS(Graph, i, Visit);
        }
    }
}

//2. 非递归方法
/*
void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) ){
    int i, j, top = -1;
    Vertex stack[100000] = {0};
    Vertex t;
    
    stack[++top] = V;
    Visited[V] = true;
    Visit(V);
    while(top != -1){
        t = stack[top];
        for(i = 0; i < Graph -> Nv; i++){
            if(Graph -> G[t][i] == 1 && !Visited[i]){   //注意加上判断==1，否则PTA过不了
                stack[++top] = i;
                Visited[i] = true;
                Visit(i);
                break;
            }
        }
        if(i >= Graph -> Nv){
            top--;
        }
    }
}
*/
