#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int m, n, p, i, j, k;
    cin >> m >> n >> p;
    double cnt;
    double a[m][n], b[n][p], c[m][p], sigma[m][p], grad_sc[m][p], T[m+n+p][m+n+p];

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < p; j++){
            cin >> b[i][j];
        }
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < p; j++){
            c[i][j] = 0;
        }
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < p; j++){
            for(k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < p; j++){
            sigma[i][j] = 1 / (1 + exp(-c[i][j]));
        }
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < p; j++){
            printf("%.2f ", sigma[i][j]);
        }
        cout << endl;
    }
    cout << endl;

    //求sigma对C的梯度: grad sigma(C)
    //令sigma(C)为f(x)，sigma对C的梯度即求f对x在每个值处的导数值，即求sigma对C在C[i][j]处的导数值。求导配项化简后可得f'(x)=f(x)-[f(x)]^2=f(x)(1-f(x))即sigma[i][j]=sigma[i][j]*(1-sigma[i][j])
    for(i = 0; i < m; i++){
        for(j = 0; j < p; j++){
            grad_sc[i][j] = sigma[i][j] * ((double)1 - sigma[i][j]);
            printf("%.2f ", grad_sc[i][j]);
        }
        cout << endl;
    }
    cout << endl;
    //求sigma对A(或B)的梯度: grad sigma(C)
    //令sigma(C)为f(t)，其中t=ab，sigma对A(或B)的梯度即求f对a(或b)在每个值处的偏导值，即求sigma对a(或b)在a[i][j](或b[i][j])处的导数值。即f'(x)={f(x)-[f(x)]^2}*b，矩阵要先求b的转置T。(或f'(x)=a*{f(x)-[f(x)]^2})
    for(i = 0; i < n; i++){
        for(j = 0; j < p; j++){
            T[j][i] = b[i][j];
        }
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            for(k = 0, cnt = 0; k < p; k++){
                cnt += grad_sc[i][k] * T[k][j];
            }
            printf("%.2f ", cnt);
        }
        cout << endl;
    }
    cout << endl;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            T[j][i] = a[i][j];
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < p; j++){
            for(k = 0, cnt = 0; k < m; k++){
                cnt += T[i][k] * grad_sc[k][j];
            }
            printf("%.2f ", cnt);
        }
        cout << endl;
    }
    //没有空行！！！

    return 0;
}