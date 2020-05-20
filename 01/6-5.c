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

    printf("\n\n");
    system("pause");
    return 0;
}

LGraph ReadG(){
    //采用邻接表方式存储
    int a, b, i;
    LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
    scanf("%d%d", &Graph -> Nv, &Graph -> Ne);
    for(i = 0; i < Graph -> Nv; i++) {
        PtrToAdjVNode t = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        t -> AdjV = i;
        t -> Next = 0;
        Graph -> G[i].FirstEdge = t;
    }
    for(i = 0; i < Graph -> Ne; i++) {
        scanf("%d%d", &a, &b);
        PtrToAdjVNode p1 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        p1 -> AdjV = b;
        p1 -> Next = Graph -> G[a].FirstEdge;
        Graph -> G[a].FirstEdge = p1;
        PtrToAdjVNode p2 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        p2 -> AdjV = a;
        p2 -> Next = Graph -> G[b].FirstEdge;
        Graph -> G[b].FirstEdge = p2;
    }
    return Graph;
}

/* Your function will be put here */
int CountConnectedComponents(LGraph Graph){
	int Count = 0, Front = 0, Rear = 0;
	Vertex Visit[MaxVertexNum] = { 0 };
	Vertex Queue[MaxVertexNum] = { 0 };
	Vertex V;
	for(int i=0; i<Graph->Nv; i++)
		if (!Visit[i]) {
			Queue[Front] = i;
			Visit[i] = 1;
			while (Front <= Rear) {
				PtrToAdjVNode Ptr = Graph->G[Queue[Front]].FirstEdge;
				for (; Ptr != NULL; Ptr = Ptr->Next)
					if (!Visit[Ptr->AdjV]) {
						Queue[++Rear] = Ptr->AdjV;
						Visit[Ptr->AdjV] = 1;
					}
				Front++;
			}
			Count++;
			Rear=Front;
		}
	return Count;
}

/*
int CountConnectedComponents( LGraph Graph ){
    Vertex QUE[10] = {0};
    PtrToAdjVNode p;
    int visited[MaxVertexNum] = {0};
    int front = 0, rear = 0, i, cnt = 0;
    
    for(i = 0; i < Graph -> Nv; i++){
        if(!visited[i]){
            QUE[rear++] = i;
            visited[i] = 1;
            cnt++;
        }
        while(front != rear){
            p = Graph -> G[QUE[front++]].FirstEdge;
            if(!visited[p -> AdjV]){
                QUE[rear++] = p -> AdjV;
                visited[p -> AdjV] = 1;
            }
            while(p -> Next){
                if(!visited[p -> Next -> AdjV]){
                    QUE[rear++] = p -> Next -> AdjV;
                    visited[p -> Next -> AdjV] = 1;
                }
                p = p -> Next;
            }
        }
        front = rear = 0;
    }

    return cnt;
}
*/
