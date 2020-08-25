#include <iostream>
#include <cstdlib>
using namespace std;

struct MoonCake{
    double n;
    double v;
    double per;
};

int main(){
    int n, d, i, j;
    double cnt = 0;
    cin >> n >> d;
    MoonCake cake[n], t;

    for(i = 0; i < n; i++){
        cin >> cake[i].n;
    }
    for(i = 0; i < n; i++){
        cin >> cake[i].v;
    }
    for(i = 0; i < n; i++){
        cake[i].per = cake[i].v / cake[i].n;
    }
    for(i = 0; i < n - 1; i++){
        for(j = n - 1; j > 0; j--){
            if(cake[j].per > cake[j - 1].per){
                t = cake[j];
                cake[j] = cake[j - 1];
                cake[j - 1] = t;
            }
        }
    }
    for(i = 0; d != 0 && i < n; i++){
        if(cake[i].n <= d){
            d -= cake[i].n;
            cnt += cake[i].v;
        }else{
            cnt += d * cake[i].per;
            d = 0;
        }
    }
    printf("%.2f", cnt);

    system("pause");
    return 0;
}