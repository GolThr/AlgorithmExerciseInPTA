#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int n, int* L, int X ){
    int s = 1, e = n, p = (e + s) / 2;
    while(s < e && e - s != 1){
        if(X < L[p]){
            e = p;
            p = (e + s) / 2;
        }else if(X > L[p]){
            s = p;
            p = (e + s) / 2;
        }else{
            return p;
        }
    }
    return 0;
}

int main(){
    int n = 3;
    int a[] = {0, 26, 78, 233};
    int x = 31;
    int r = BinarySearch(n, a, x);

    printf("%d\n", r);

    printf("\n\n");
    system("pause");
}