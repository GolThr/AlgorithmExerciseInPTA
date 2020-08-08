#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn = 105;
double a[maxn][maxn],b[maxn][maxn],c[maxn][maxn],d[maxn][maxn];
double a1[maxn][maxn],b1[maxn][maxn];
int main()
{
    int n,m,p;
    cin>>m>>n>>p;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++){
            cin>>b[i][j];
        }
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=p;j++){
            double cnt = 0;
            for(int k=1;k<=n;k++){
                cnt += (a[i][k]*b[k][j]);
            }
            c[i][j] = cnt;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=p;j++){
            //if(j != 1)
            //    printf(" ");
            d[i][j] = (double)1/((double)1 + double(1/exp(c[i][j])));
            printf("%.2lf ",d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=p;j++){
            //if(j != 1)
            //   printf(" ");
            d[i][j] = d[i][j]*((double)1-d[i][j]);
            printf("%.2lf ",d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++){
            b1[j][i] = b[i][j];
        }
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            double cnt = 0;
            for(int k=1;k<=p;k++){
                //printf("%.2lf %.2lf\n",d[i][k],b1[k][j]);
                cnt += (d[i][k] * b1[k][j]);
            }
            //if(j != 1)
            //    printf(" ");
            printf("%.2lf ",cnt);
        }
        printf("\n");
    }
    printf("\n");
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            a1[j][i] = a[i][j];
        }
    }
	for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++){
            double cnt = 0;
            for(int k=1;k<=m;k++){
                //printf("%.2lf %.2lf\n",d[i][k],b1[k][j]);
                cnt += (a1[i][k] * d[k][j]);
            }
            //if(j != 1)
            //    printf(" ");
            printf("%.2lf ",cnt);
        }
        printf("\n");
    }
	return 0;
}
