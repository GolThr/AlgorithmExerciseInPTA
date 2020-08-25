#include <iostream>
using namespace std;

int main(){
    int n, c, i, j, t;
    cin >> n >> c;
    int w[n + 1], v[n + 1];
    int dp[n + 1][c + 1];

    for(i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    //init
    for(i = 0; i <= c; i++){
        dp[0][i] = 0;
    }
    for(i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    //construct
    for(i = 1; i <= n; i++){
        for(j = 1; j <= c; j++){
            if(w[i] > j){
                dp[i][j] = dp[i - 1][j];
            }else{
                t = dp[i - 1][j - w[i]] + v[i];
                dp[i][j] = dp[i - 1][j] > t ? dp[i - 1][j] : t;
            }
        }
    }
    cout << dp[n][c];

    return 0;
}