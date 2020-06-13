#include <iostream>
#include <cstdlib>

using namespace std;

void LCSLength(int m, int n, char *x, char *y, int  **c, int **b);
void LCS(int i ,int j, char *x, int **b);

int main() {
	int m, n;
	cin >> m >> n;
	char x[m+1], y[n+1];
	for (int i = 1; i <= m; i ++)
		cin >> x[i];
	for (int j = 1; j <= n; j ++)
		cin >> y[j];

	int **c = new int *[m+1];
	int **b = new int *[m+1];
	for (int i = 0; i <= m; i ++) {
		c[i] =  new int [n+1]{0};
		b[i] =  new int [n+1]{0};
	}
	LCSLength(m, n, x, y, c, b);
	LCS(m,n, x, b);
    system("pause");
	return 0;
}

void LCSLength(int m, int n, char *x, char *y, int  **c, int **b) {
	int i, j;
	for (i = 1; i <= m ; i ++ )
		c[i][0] = 0;
	for ( i = 1; i <= n ; i ++ )
		c[0][i] = 0;
	for ( i = 1; i <= m; i ++ )
		for(int j = 1; j <= n; j ++) {
			if(x[i] == y[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			} else if(c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;
			} else {
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;
			}
		}
}

/* 请在这里填写答案 */
void LCS(int i ,int j, char *x, int **b){
    char v[i + j];
	int top = 0;
	while(b[i][j] != 0){
		if(b[i][j] == 2){			// from left
			i--;
		}else if(b[i][j] == 3){		// from right
			j--;
		}else if(b[i][j] == 1){		// from upper left
			v[top++] = x[i];
			i--; j--;
		}
	}
	while(top != 0){
		cout << v[--top] << " ";
	}
}
