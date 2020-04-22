#include<stdio.h>
#include<stdlib.h>
typedef  int  KeyType;
typedef  struct {                      
  KeyType *elem; /*elem[0]һ�����ڱ��򻺳���*/                       
  int Length;      
}SqList;
void  CreatSqList(SqList *L);/*�������н������ɲ���ʵ�֣�ϸ�ڲ���*/ 
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
   printf("\n\n");
   system("pause");
  return 0;
}
void  CreatSqList(SqList *L){/*�������н������ɲ���ʵ�֣�ϸ�ڲ���*/ 
  int n, i;
  scanf("%d", &n);
  L -> Length = n;
  L -> elem = (int *)malloc(sizeof(int)*(n + 1));
  for(i = 1; i <= n; i++){
    scanf("%d", &(L -> elem[i]));
  }
}
/*��Ĵ��뽫��Ƕ������ */
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
