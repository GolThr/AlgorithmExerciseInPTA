#include <iostream>
#include <stdlib.h>
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
        for(; j < n; j += 2){
            for(k = 1, t = 1; k < n; k++){
                if(b[k] >= b[k - 1]){
                    t++;
                }else{
                    if(t != j){
                        break;
                    }
                    t = 1;
                }
            }
            if(k >= n){
                break;
            }
        }
        k = 0;
        l = k + 2 * j;
        while(l <= n){
            for(i = k; i < l; i++){
                for(p = i + 1, min = i; p < l; p++){
                    if(b[p] < b[min]){
                        min = p;
                    }
                }
                t = b[min];
                b[min] = b[i];
                b[i] = t;
            }
            k += l;
            l = k + 2 * j;
        }
        if(k < n){
            for(i = k; i < n; i++){
                for(p = i + 1, min = i; p < n; p++){
                    if(b[p] < b[min]){
                        min = p;
                    }
                }
                t = b[min];
                b[min] = b[i];
                b[i] = t;
            }
        }
        cout << b[0];
        for(i = 1; i < n; i++){
            cout << " " << b[i];
        }
    }

    system("pause");
    return 0;
}