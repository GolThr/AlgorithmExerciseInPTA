#include <iostream>
#include <cstdlib>
using namespace std;

void show(int heap[], int n){
    for(int i = 1; i <= n; i++){
        if(i != 1){
            cout << " ";
        }
        cout << heap[i];
    }
    cout << endl;
}

void adjust(int heap[], int i, int n){
    int min, t = heap[i];
    bool isHeap = false;
    while(2 * i <= n && !isHeap){
        if(2 * i <= n){
            min = 2 * i;
        }
        if(2 * i + 1 <= n && heap[2 * i] > heap[2 * i + 1]){
            min++;
        }
        if(heap[min] < t){
            heap[i] = heap[min];
            i = min;
            isHeap = false;
        }else{
            isHeap = true;
        }
    }
    heap[i] = t;
    show(heap, n);
}

void construct(int heap[], int n){
    for(int i = n / 2; i > 0; i--){
        adjust(heap, i, n);
    }
}

void insert(int heap[], int n, int x){
    int t;
    heap[n] = x;
    for(int i = n; i > 1; i /= 2){
        if(heap[i] < heap[i / 2]){
            t = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = t;
        }
    }
}

void del(int heap[], int n){
    heap[1] = heap[n];
    adjust(heap, 1, n);
}

int main(){
    int n, i;
    cin >> n;
    int heap[n + 1], cnt = n;

    for(i = 1; i <= n; i++){
        cin >> heap[i];
    }
    construct(heap, n);
    show(heap, n);
    cout << endl << "sort..." << endl;
    for(i = 1; i <= n; i++){
        cout << heap[1] << endl;
        del(heap, cnt--);
        show(heap, n);
    }

    system("pause");
    return 0;
}