#include<stdio.h>
#include<stdlib.h>
typedef  int  KeyType;
typedef  struct {                      
  KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/                       
  int Length;      
}SqList;
void  CreatSqList(SqList *L);/*待排序列建立，由裁判实现，细节不表*/ 
void  SelectSort(SqList L);
int main()
{
  SqList L;
  int i;
  CreatSqList(&L);
  SelectSort(L);
  for(i=1;i<=L.Length;i++)
   {		
     printf("%d ",L.elem[i]);
   }
  return 0;
}
void  CreatSqList(SqList *L){/*待排序列建立，由裁判实现，细节不表*/ 
  int n, i;
  scanf("%d", &n);
  L -> Length = n;
  L -> elem = (int *)malloc(sizeof(int)*(n + 1));
  for(i = 1; i <= n; i++){
    scanf("%d", &(L -> elem[i]));
  }
}
/*你的代码将被嵌在这里 */
void  SelectSort(SqList L){
  int i, j, min;
  KeyType t;
  for(i = 1; i <= L.Length; i++){
    for(j = i + 1, min = i; j <= L.Length; j++){
      if(L.elem[j] < L.elem[min]){
        min = j;
      }
    }
    if(min != i){
      t = L.elem[i];
      L.elem[i] = L.elem[min];
      L.elem[min] = t;
    }
  }
}
