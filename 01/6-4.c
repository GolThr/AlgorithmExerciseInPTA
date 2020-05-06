#include <stdio.h>
#include <stdlib.h>

#define MaxVertices 10  /* maximum number of vertices */
typedef int Vertex;     /* vertices are numbered from 0 to MaxVertices-1 */
typedef struct VNode *PtrToVNode;
struct VNode {
    Vertex Vert;
    PtrToVNode Next;
};
typedef struct GNode *Graph;
struct GNode {
    int NumOfVertices;
    int NumOfEdges;
    PtrToVNode *Array;
};

Graph ReadG(); /* details omitted */

void PrintV( Vertex V )
{
   printf("%d ", V);
}

void StronglyConnectedComponents( Graph G, void (*visit)(Vertex V) );

int main()
{
    Graph G = ReadG();
    StronglyConnectedComponents( G, PrintV );
    return 0;
}

Graph ReadG(){
    //采用邻接表方式存储
    int a, b, i;
    Graph G = (Graph)malloc(sizeof(Graph));
    scanf("%d%d", &G -> NumOfVertices, &G -> NumOfEdges);
    G -> Array = (PtrToVNode*)malloc(sizeof(PtrToVNode) * G -> NumOfVertices);
    for(i = 0; i < G -> NumOfVertices; i++) {
        G -> Array[i] = 0;
    }
    for(i = 0; i < G -> NumOfEdges; i++) {
        scanf("%d%d", &a, &b);
        PtrToVNode p = (PtrToVNode)malloc(sizeof(PtrToVNode));
        p -> Vert = b;
        p -> Next = G -> Array[a];
        G -> Array[a] = p;
    }
    return G;
}
/* Your function will be put here */
void StronglyConnectedComponents(Graph G, void (*visit)(Vertex V)){
    int vertn = G -> NumOfVertices;
    int reached[vertn][vertn];
    int visited[vertn];
    int i, j, k;
    
    for(i = 0; i < vertn; i++){
        visited[i] = 0;
        for(j = 0; j < vertn; j++){
            reached[i][j] = 0;
        }
    }

    //邻接矩阵
    for(i = 0; i < vertn; i++){
        PtrToVNode vnode = G -> Array[i];
        if(vnode){
            reached[i][vnode -> Vert] = 1;
            while(vnode -> Next){
                vnode = vnode -> Next;
                reached[i][vnode -> Vert] = 1;
            }
        }
    }

    //可达矩阵
    for(k = 0; k < vertn; k++){ //对每个中间节点
        for(i = 0; i < vertn; i++){
            for(j = 0; j < vertn; j++){
                if(reached[i][k] && reached[k][j]){
                    reached[i][j] = 1;
                }
            }
        }
    }

    for(i = 0; i < vertn; i++){
        if(!visited[i]){
            visit(i);
            visited[i] = 1;
            for(j = 0; j < vertn; j++){
                if(!visited[j] && reached[i][j] && reached[j][i]){
                    visit(j);
                    visited[j] = 1;
                }
            }
            printf("\n");
        }
    }
}
