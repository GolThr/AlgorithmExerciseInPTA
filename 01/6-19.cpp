#include <iostream>
using namespace std;

float Knapsack(int n,float c,float v[],float w[],float x[]);

int main() {
	int n;
	float c;

	cin >> n >> c;
	float w[n+1];
	float v[n+1];
	float x[n+1];
	for (int i = 1; i <= n; i ++) {
		cin >> v[i] >> w[i];
	}

	float value = Knapsack(n, c, v, w, x);

	cout << value << endl;
	for(int i = 1; i <= n; i++)
		cout << x[i] << " ";
	return 0;
}
/* 请在这里填写答案 */
float Knapsack(int n,float c,float v[],float w[],float x[]){
    int i, j;
	float sum = 0.0;
	for(i = 1; i <= n; i++){
		x[i] = 0;
	}
	for(i = 1; i <= n && c != 0; i++){
		if(c >= w[i]){
			sum += v[i];
            x[i] = 1;
			c -= w[i];
		}else{
			sum += c * (v[i] / w[i]);
            x[i] = c / w[i];
			c = 0;
		}
	}
	return sum;
}
