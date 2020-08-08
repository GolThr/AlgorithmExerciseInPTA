#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn = 105;
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
int main()
{
    int x1,x2,y1,y2;
    cin>>x1>>y1;
    for(int i=1;i<=x1;i++){
        for(int j=1;j<=y1;j++){
            cin>>a[i][j];
        }
    }
    cin>>x2>>y2;
    for(int i=1;i<=x2;i++){
        for(int j=1;j<=y2;j++){
            cin>>b[i][j];
        }
    }
    if(y1 != x2){
        printf("Error: %d != %d",y1,x2);
        return 0;
    }
    
    for(int i=1;i<=x1;i++){
        
        for(int j=1;j<=y2;j++){
            int cnt = 0;
            for(int k=1;k<=y1;k++){
                cnt += (a[i][k]*b[k][j]);
            }
            c[i][j] = cnt;
        }
    }
    printf("%d %d\n",x1,y2);
    for(int i=1;i<=x1;i++){
        for(int j=1;j<=y2;j++){
            if(j != 1)
                printf(" ");
            printf("%d",c[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}