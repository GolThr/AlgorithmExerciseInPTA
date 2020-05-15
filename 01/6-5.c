#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG(); /* details omitted */

int CountConnectedComponents( LGraph Graph );

int main()
{
    LGraph G = ReadG();
    printf("%d\n", CountConnectedComponents(G));

    return 0;
}

LGraph ReadG(){
    //采用邻接表方式存储
    int a, b, i;
    LGraph G = (LGraph)malloc(sizeof(LGraph));
    scanf("%d%d", &G -> Nv, &G -> Ne);
    for(i = 0; i < G -> Nv; i++) {
        G -> G[i].FirstEdge = 0;
    }
    for(i = 0; i < G -> Ne; i++) {
        scanf("%d%d", &a, &b);
        PtrToAdjVNode p = (PtrToAdjVNode)malloc(sizeof(PtrToAdjVNode));
        p -> AdjV = b;
        p -> Next = G -> G[a].FirstEdge;
        G -> G[a].FirstEdge = p;
    }
    return G;
}

/* Your function will be put here */
int CountConnectedComponents( LGraph Graph ){
    int i, j, k, cnt = 0;
    int vn = Graph -> Nv;
    int reached[vn][vn];
    int visited[vn];

    for(i = 0; i < vn; i++){
        visited[i] = 0;
        for(j = 0; j < vn; j++){
            reached[i][j] = 0;
        }
    }

    //邻接矩阵
    for(i = 0; i < vn; i++){
        PtrToAdjVNode ptr = Graph -> G[i].FirstEdge;
        if(!ptr){
            reached[i][ptr -> AdjV] = 1;
            reached[ptr -> AdjV][i] = 1;
            while(!ptr -> Next){
                ptr = ptr -> Next;
                reached[i][ptr -> AdjV] = 1;
                reached[ptr -> AdjV][i] = 1;
            }
        }
    }

    for(i = 0; i < vn; i++){
        for(j = 0; j < vn; j++){
            printf("%d ", reached[i][j]);
        }
        printf("\n");
    }

    //可达矩阵
    for(k = 0; k < vn; k++){ //对每个中间节点
        for(i = 0; i < vn; i++){
            for(j = 0; j < vn; j++){
                if(reached[i][k] && reached[k][j]){
                    reached[i][j] = 1;
                }
            }
        }
    }

    for(i = 0; i < vn; i++){
        if(!visited[i]){
            visited[i] = 1;
            for(j = 0; j < vn; j++){
                if(!visited[j] && reached[i][j] && reached[j][i]){
                    visited[j] = 1;
                }
            }
            cnt++;
        }
    }
    printf("%d", cnt);
}
