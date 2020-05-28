#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 20  /* 最大顶点数设为20 */
struct Graph{
    int v;  // amount of vertices
    int Adj[MaxVertexNum][MaxVertexNum]; /* Adj Matrix */
};
int visited[MaxVertexNum]; /* 顶点的访问标记 */
struct Graph* CreateGraph(){
    int v;
    scanf("%d",&v);
    struct Graph* g;
    g = malloc(sizeof(struct Graph));
    if(!g) return NULL;
    g->v = v;
    for(int i=0; i<v; i++){
        visited[i] = 0;
        for(int j=0; j<v; j++)
            scanf("%d",&(g->Adj[i][j]));
    }
    return g;
}
int hasPath(struct Graph *g, int v, int w);
int main(){
    struct Graph* g;
    g = CreateGraph();
    int v,w;
    scanf("%d%d", &v, &w);
    printf("%s\n", hasPath(g,v,w) ? "Yes" : "No");
    return 0;
}

/* Your code will be put here */
int hasPath(struct Graph *g, int v, int w){
    int que[1000];
    int front = 0, rear = 0, cnt = 1;
    int i, t;
    que[rear++] = v;
    visited[v] = 1;
    while(front != rear){
        t = que[front++];
        for(i = 0; i < g -> v; i++){
            if(g -> Adj[t][i] == 1 && visited[i] == 0){
                que[rear++] = i;
                visited[i] = 1;
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    if(v != w){
        if(visited[w] == 1){
            printf("%d\n", cnt);
            return 1;
        }else{
            for(i = 0; i < MaxVertexNum; i++) visited[i] = 0;
            front = 0, rear = 0, cnt = 1;
            que[rear++] = w;
            visited[w] = 1;
            while(front != rear){
                t = que[front++];
                for(i = 0; i < g -> v; i++){
                    if(g -> Adj[t][i] == 1 && visited[i] == 0){
                        que[rear++] = i;
                        visited[i] = 1;
                        cnt++;
                    }
                }
            }
            printf("%d\n", cnt);
            return 0;
        }
    }else{
        printf("%d\n", cnt);
        return 1;
    }
}
