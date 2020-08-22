#include <iostream>
using namespace std;

int main(){
    int ra, ca, rb, cb, i, j, k;
    cin >> ra >> ca;
    int a[ra][ca];
    for(i = 0; i < ra; i++){
        for(j = 0; j < ca; j++){
            cin >> a[i][j];
        }
    }
    cin >> rb >> cb;
    int b[rb][cb], c[ra][cb];
    for(i = 0; i < rb; i++){
        for(j = 0; j < cb; j++){
            cin >> b[i][j];
        }
    }
    if(ca != rb){
        cout << "Error: " << ca << " != "<< rb;
    }else{
        for(i = 0; i < ra; i++){
            for(j = 0; j < cb; j++){
                c[i][j] = 0;
            }
        }
        for(i = 0; i < ra; i++){
            for(j = 0; j < cb; j++){
                for(k = 0; k < ca; k++){
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        cout << ra << " " << cb << endl;
        for(i = 0; i < ra; i++){
            for(j = 0; j < cb; j++){
                if(j != 0){
                    cout << " ";
                }
                cout << c[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}