#include <iostream>
#include <cstdlib>
using namespace std;

#define MAXINT 62767
#define MAXNUM 100

struct Graph{
    int vexnum, arcnum;
    int arcs[MAXNUM][MAXNUM];
};

int path[MAXNUM];

void Dijkstra(Graph * G, int start){
    int weight[G -> vexnum];
    bool visited[G -> vexnum];
    int i, j, min;
    for(i = 0; i < G -> vexnum; i++){
        visited[i] = 0;
        if(i != start){
            weight[i] = MAXINT;
        }
    }
    weight[start] = 0;
    min = start;
    while(min != -1){
        visited[min] = 1;
        cout << min << " ";
        for(j = 0; j < G -> vexnum; j++){
            if(G -> arcs[min][j] + weight[min] < weight[j]){
                weight[j] = G -> arcs[min][j] + weight[min];
                path[j] = min;
            }
        }
        for(i = 0, min = -1; i < G -> vexnum; i++){
            if(i != start && !visited[i]){
                min = i;
                break;
            }
        }
        for(i = 0; i < G -> vexnum; i++){
            if(i != start && weight[i] < weight[min] && !visited[i]){
                min = i;
            }
        }
    }
    cout << endl;
    for(i = 0; i < G -> vexnum; i++){
        cout << weight[i] << " ";
    }
    cout << endl;
    for(i = 0; i < G -> vexnum; i++){
        cout << path[i] << " ";
    }
}

int main(){
    Graph * G = new Graph;
    cin >> G -> vexnum >> G -> arcnum;
    int i, j, a, b, w, start;

    for(i = 0; i < G -> vexnum; i++){
        for(j = 0; j < G -> vexnum; j++){
            G -> arcs[i][j] = MAXINT;
        }
    }
    for(i = 0; i < G -> arcnum; i++){
        cin >> a >> b >> w;
        G -> arcs[a][b] = w;
    }
    cin >> start;
    Dijkstra(G, start);

    system("pause");
    return 0;
}