#include <iostream>
using namespace std;

#define MVNum 100 
typedef char VerTexType;

typedef struct ArcNode{
    int adjvex;          
    struct ArcNode *nextarc;
}ArcNode; 

typedef struct VNode{ 
    VerTexType data; 
    ArcNode *firstarc; 
}VNode, AdjList[MVNum];

typedef struct{ 
    AdjList vertices; //邻接表
	AdjList converse_vertices;//逆邻接表
    int vexnum, arcnum; 
}ALGraph;

int CreateUDG(ALGraph &G);//创建图，实现细节隐藏
void FindInDegree(ALGraph G,int indegree[]);
int TopologicalSort(ALGraph G , int topo[]); 

int main(){
	ALGraph G;
	CreateUDG(G);
	int *topo = new int [G.vexnum];
	if(TopologicalSort(G , topo)){
		for(int j = 0 ; j < G.vexnum; j++){
			if(j != G.vexnum - 1)
				cout << G.vertices[topo[j]].data << ",";
			else
				cout << G.vertices[topo[j]].data ;
		}
	}
	else
		cout << "Ring in net";
	return 0;
}

int CreateUDG(ALGraph &G){
    int i, j, k;
    char a, b;
    cin >> G.vexnum >> G.arcnum;
    for(i = 0; i < G.vexnum; i++){
        cin >> a;
        G.vertices[i].data = a;
        G.vertices[i].firstarc = NULL;
        G.converse_vertices[i].data = a;
        G.converse_vertices[i].firstarc = NULL;
    }
    for(j = 0; j < G.arcnum; j++){
        cin >> a >> b;
        for(i = 0; i < G.vexnum; i++){
            if(G.vertices[i].data == a){
                ArcNode * p = new ArcNode;
                for(k = 0; k < G.vexnum; k++){
                    if(G.vertices[k].data == b){
                        break;
                    }
                }
                p -> adjvex = k;
                p -> nextarc = G.vertices[i].firstarc;
                G.vertices[i].firstarc = p;
            }
        }
        for(i = 0; i < G.vexnum; i++){
            if(G.converse_vertices[i].data == b){
                ArcNode * p = new ArcNode;
                for(k = 0; k < G.vexnum; k++){
                    if(G.vertices[k].data == a){
                        break;
                    }
                }
                p -> adjvex = k;
                p -> nextarc = G.converse_vertices[i].firstarc;
                G.converse_vertices[i].firstarc = p;
            }
        }
    }
}

/* 请在这里填写答案 */
void FindInDegree(ALGraph G,int indegree[]){
    int i, j;
    ArcNode * p;
    for(i = 0; i < G.vexnum; i++){
        p = G.converse_vertices[i].firstarc;
        indegree[i] = 0;
        while(p){
            indegree[i]++;
            p = p -> nextarc;
        }
    }
}

int TopologicalSort(ALGraph G , int topo[]){
	int * indegree = new int [G.vexnum];
    FindInDegree(G, indegree);
    int stack[1000] = {0};
    int i, j, top = 0, p = 0;
    ArcNode * t;
    for(i = 0; i < G.vexnum; i++){
        if(indegree[i] == 0){
            stack[top++] = i;
        }
    }
    while(top != 0){
        t = G.vertices[stack[--top]].firstarc;
        topo[p++] = stack[top];
        while(t){
            indegree[t -> adjvex]--;
            if(indegree[t -> adjvex] == 0){
                stack[top++] = t -> adjvex;
            }
            t = t -> nextarc;
        }
    }
}
