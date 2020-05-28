#include <iostream>
using namespace std;

int count = 0;
void hanoi(int n, int a, int b, int c) ;

int main() {
	int n;
	
	cin >> n;
	hanoi(n, 1, 3, 2);
	cout << count;
	return 0;
}
/* 请在这里填写答案 */
void hanoi(int n, int a, int b, int c){
    if(n == 1){
        count++;
        return;
    }
    hanoi(n - 1, a, c, b);
    hanoi(1, a, b, c);
    hanoi(n - 1, c, b, a);
}
