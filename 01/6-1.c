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
  return 0;
}
/*��Ĵ��뽫��Ƕ������ */

