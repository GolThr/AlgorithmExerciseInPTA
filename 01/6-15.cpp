#include <iostream>
#define MAXSIZE 1000
using namespace std;

typedef struct
{
 int key;
 char *otherinfo;
}ElemType;

typedef struct
{
 ElemType *r;
 int  length;
}SqList;
							
void Create_Sq(SqList &L)
{
 int i,n;
 cin>>n;	//输入的值不大于 MAXSIZE
 for(i=1;i<=n;i++)
 {
  cin>>L.r[i].key;
  L.length++;
 }
}
void show(SqList L)
{
 int i;
 for(i=1;i<=L.length;i++)
  if(i==1) 
   cout<<L.r[i].key;
  else
   cout<<" "<<L.r[i].key;
}

void HeapAdjust(SqList &L,int s,int m);//筛选法调整堆
void CreatHeap(SqList &L); //把无序序列L.r[1..n]建成大根堆
void HeapSort(SqList &L);//对顺序表L进行堆排序

int main()
{
 SqList L;
 L.r=new ElemType[MAXSIZE+1];
 L.length=0;
 Create_Sq(L);
 HeapSort(L);
 show(L);
 return 0;
}
/* 请在这里填写答案 */
void HeapAdjust(SqList &L,int s,int m){
    int n = m - s + 1;
    int i = 1, j;
    ElemType k;
    bool isHeap = false;
    k = L.r[i];
    while(!isHeap && 2 * i < n){
        j = 2 * i;
        if(j + 1 <= n && L.r[j].key < L.r[j + 1].key) j = j + 1;
        if(k.key < L.r[j].key){
            L.r[i] = L.r[j];
            i = j;
        }else{
            isHeap = true;
        }
    }
    L.r[i] = k;
}

void CreatHeap(SqList &L){
    int i, j, t;
    ElemType k;
    bool isHeap;
    for(t = L.length / 2; t > 0; t--){
        i = t;
        isHeap = false;
        k = L.r[i];
        while(!isHeap && 2 * i <= L.length){
            j = 2 * i;
            if(j + 1 <= L.length && L.r[j].key < L.r[j + 1].key) j = j + 1;
            if(k.key < L.r[j].key){
                L.r[i] = L.r[j];
                i = j;
            }else{
                isHeap = true;
            }
        }
        L.r[i] = k;
    }
    
}

void HeapSort(SqList &L){
    CreatHeap(L);
    int n = L.length;
    ElemType t;
    while(n !=  2){
        t = L.r[1];
        L.r[1] = L.r[n];
        L.r[n] = t;
        HeapAdjust(L, 1, --n);
    }
}
