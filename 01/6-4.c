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
    // 采用邻接表方式存储
    Graph G = (Graph)malloc(sizeof(Graph));
    int i;
    Vertex s, e;
    scanf("%d%d", &(G -> NumOfVertices), &(G -> NumOfEdges));
    PtrToVNode* arr[G -> NumOfVertices];
    for(i = 0; i < G -> NumOfVertices; i++){
        arr[i] = 0;
    }
    G -> Array = arr;
    for(i = 0; i < G -> NumOfEdges; i++){
        scanf("%d%d", &s, &e);
        PtrToVNode v = (PtrToVNode)malloc(sizeof(PtrToVNode));
        v -> Vert = e;
        v -> Next = 0;
        if(G -> Array[s]){
            PtrToVNode vn = G -> Array[s];
            while(vn -> Next){
                vn = vn -> Next;
            }
            vn -> Next = v;
        }else{
            G -> Array[s] = v;
        }
    }
    return G;
}
/* Your function will be put here */
void StronglyConnectedComponents(Graph G, void (*visit)(Vertex V)){
    PtrToVNode * v = G -> Array;
    Vertex s = v -> Vert;
    visit(s);
    while(vn -> Next != NULL || vn -> Next -> Vert != s){
        vn = vn -> Next;
        visit(vn -> Vert);
    }
    printf("\n");
}
