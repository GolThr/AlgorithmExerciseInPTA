#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int i, j, k, p, l, t, n, min;
    cin >> n;
    int a[n], b[n];

    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    for(i = 0; i < n; i++){
        cin >> b[i];
    }
    
    for(i = 1; i < n; i++){
        if(b[i] < b[i - 1]){
            break;
        }
    }
    for(j = i; i < n; i++){
        if(a[i] != b[i]){
            break;
        }
    }
    if(i >= n){
        cout << "Insertion Sort" << endl;
        for(i = 0; i < j; i++){
            if(b[i] > b[j]){
                t = b[j];
                for(k = j - 1; k >= i; k--){
                    b[k + 1] = b[k];
                }
                b[i] = t;
            }
        }
        cout << b[0];
        for(i = 1; i < n; i++){
            cout << " " << b[i];
        }
    }else{
        cout << "Merge Sort" << endl;
        for(i = j, t = 1; i < n - 1; i++){
            if(b[i] < b[i +1]){
                t++;
            }else{
                break;
            }
        }
        l = j < t ? j : t;
        for(i = 0; (i + l * 2) <= n; i += l * 2){
            sort(b + i, b + i + l * 2);
        }
        if(i < n){
            sort(b + i, b + n);
        }
        cout << b[0];
        for(i = 1; i < n; i++){
            cout << " " << b[i];
        }
    }

    return 0;
}