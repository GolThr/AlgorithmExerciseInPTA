#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, i;
    cin >> n;
    char a[n + 1];

    for(i = 0; i < n; i++){
        a[i] = i + 1 + '0';
    }
    a[n] = '\0';
    do{
        cout << a << endl;
    }while(next_permutation(a, a + n));

    return 0;
}