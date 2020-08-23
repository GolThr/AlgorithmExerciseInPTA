#include <iostream>
using namespace std;

#define MaxInt 32767
#define MVNum 100 
typedef char VerTexType;
typedef int ArcType;

int *D=new int[MVNum];
bool *S=new bool[MVNum];
int *Path=new int[MVNum];

typedef struct{ 
	VerTexType vexs[MVNum]; 
	ArcType arcs[MVNum][MVNum]; 
	int vexnum,arcnum;
}AMGraph;

void CreateUDN(AMGraph &G);//实现细节隐藏
void ShortestPath_DIJ(AMGraph G, int v0);

void DisplayPath(AMGraph G , int begin ,int temp ){
	if(Path[temp] != -1){
		DisplayPath(G , begin ,Path[temp]);
		cout << G.vexs[Path[temp]] << "->";
	}
}

int main()
{
	AMGraph G; 
	int i , j ,num_start , num_destination;
	VerTexType start , destination;
	CreateUDN(G);
	cin >> start >> destination;
	num_start = LocateVex(G , start);
	num_destination = LocateVex(G , destination);
	ShortestPath_DIJ(G , num_start);
	DisplayPath(G , num_start , num_destination);
	cout << G.vexs[num_destination]<<endl;
	return 0;
}
/* 请在这里填写答案 */
void ShortestPath_DIJ(AMGraph G, int v0){
    int i, j, min;
    for(i = 0; i < G.vexnum; i++){
        S[i] = 0;
        D[i] = MaxInt;
        Path[i] = -1;       // !!! 不要忘了初始化路径为-1 !!!
    }
    D[v0] = 0;
    min = v0;
    while(min != -1){
        S[min] = 1;
        for(j = 0; j < G.vexnum; j++){
            if(G.arcs[min][j] + D[min] < D[j]){
                D[j] = G.arcs[min][j] + D[min];
                Path[j] = min;
            }
        }
        for(i = 0, min = -1; i < G.vexnum; i++){
            if(i != v0 && !S[i]){
                min = i;
                break;
            }
        }
        for(i = 0; i < G.vexnum; i++){
            if(i != v0 && D[i] < D[min] && !S[i]){
                min = i;
            }
        }
    }
}
