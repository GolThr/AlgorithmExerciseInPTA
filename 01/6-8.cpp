#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;	//元素的数据类型

typedef struct LNode {
	ElemType data;		//结点的数据域
	struct LNode *next;	//指向后继结点
} LinkNode;		 	//单链表结点类型

//尾插法建立单链表,细节不表
void CreateListR(LinkNode *&L, ElemType a[], int n);

//输出线性表,细节不表
void DispList(LinkNode *L);

//单链表插入排序：元素递增排序
void insertion_sort(LinkNode *&L);

int main() 
{
	int n;

	scanf("%d", &n);
	ElemType a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	LinkNode *A;
	CreateListR(A, a, n);

	insertion_sort(A);
	printf("排序后的单链表: ");
	DispList(A);

	return 0;
}

void CreateListR(LinkNode *&L, ElemType a[], int n){
	int i, j;
	L = new LinkNode;
	L -> next = NULL;
	for(i = 0; i < n; i++){
		LinkNode * p = new LinkNode;
		p -> data = a[i];
		p -> next = L -> next;
		L -> next = p;
	}
}

void DispList(LinkNode *L){
    LinkNode * p = L -> next;
	while(p){
		printf(" %d", p -> data);
		p = p -> next;
	}
}

/* 请在下面填写答案 */
void insertion_sort(LinkNode *&L){
	LinkNode * s = L -> next;
	LinkNode * i = s -> next;
	LinkNode * t, * pre;
	while(i){
		for(pre = L, t = L -> next; t != i; pre = pre -> next, t = t -> next){
			if(i -> data < t -> data){
				pre -> next = i;
				s -> next = i -> next;
				i -> next = t;
				break;
			}
		}
		if(t == i){
			s = i;
		}
		i = s -> next;
	}
}

/*精简版，但运行超时
void insertion_sort(LinkNode *&L){
	LinkNode * s = L -> next;
	LinkNode * i = s -> next;
	LinkNode * t;
	while(i){
		for(t = L; t -> next != i; t = t -> next){
			if(i -> data < t -> next -> data){
				s -> next = i -> next;
				i -> next = t -> next;
				t -> next = i;
				break;
			}
		}
		if(t -> next == i){
			s = i;
		}
		i = s -> next;
	}
}
*/
