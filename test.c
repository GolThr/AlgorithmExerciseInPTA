#include <stdio.h>
#include <stdlib.h>

int main(){
    int *n = (int *)malloc(sizeof(int)*3);
    n[0] = 3;
    n[1] = 2;
    n[2] = 4;
    n[3] = 5;
    for(int i = 0; i <= 3; i++){
        printf("%d ", n[i]);
    }
    system("pause");
}