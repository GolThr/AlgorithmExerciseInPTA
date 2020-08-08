#include<iostream>
using namespace std;
int main(){
	int n,c;
	cin>>n>>c;
	int w[105];
	int v[105];
	int dp[105][1005]={};
	for(int i=1;cin>>w[i]>>v[i];i++);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=w[i])
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
		}
	}
	cout<<dp[n][c];
} 
