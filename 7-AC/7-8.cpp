#include <bits/stdc++.h>
using namespace std;
#define ll long long
int heap[1005];
int currentSize=0;
int maxSize;
void SiftDown(int index){
     int cur = index;
     int son = 2*index+1;
     int tmp = heap[index];
     while(son < currentSize){
       if(son<currentSize-1 && heap[son] > heap[son+1])
            son++;
       if(tmp > heap[son]){
         heap[cur] = heap[son];
         cur = son;
         son = 2* cur + 1;
       }else
       break;
     }
     heap[cur] = tmp;
}
void HeapInit(int a[],int n){
   currentSize = n;
   for(int i=0;i<n;i++)
        heap[i] = a[i];
   for(int i= (currentSize-2)/2; i>=0; i--){
        SiftDown(i);
   }
}
void HeapInsert(int value){
     if(currentSize >= maxSize) return;
     currentSize++;
     int index = currentSize-1;
     while(index>0){
        if(heap[(index-1)/2] <= value)break;
        heap[index] = heap[(index-1)/2];
        index = (index-1)/2;
     }
     heap[index] = value;
}
int HeapDelete(){
     if(currentSize==0) return -1;
     int maxValue = heap[0];
     heap[0] = heap[currentSize-1];
     currentSize--;
     SiftDown(0);
     return maxValue;
}
int a[1005];
int main()
{   
    int n,m;
    cin>>n>>m;
    maxSize = n;
    while(m--){
        int x,y;
        cin>>x;
        if(x == -1){
            HeapDelete();
        }else{
            cin>>y;
            HeapInsert(y);
        }
        for(int i=0;i<currentSize;i++){
            if(i != 0)cout<<" ";
            cout<<heap[i];
        }cout<<endl;
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)cin>>a[i];
    currentSize = 0;
    HeapInit( a , k);
    for(int i=0;i<k;i++){
        if(i != 0)cout<<" ";
        cout<<heap[i];
    }cout<<endl;
    return 0;
}