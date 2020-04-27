#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

List ReadInput(){ /* 裁判实现，细节不表。元素从下标1开始存储 */
    int n, i;
    scanf("%d", &n);
    List l = (List)malloc(sizeof(List));
    for(i = 1; i <= n; i++){
        scanf("%d", &(l -> Data[i]));
    }
    l -> Last = n;
    return l;
}
/* 你的代码将被嵌在这里 */
Position BinarySearch( List L, ElementType X ){
    int s = 1, e = L -> Last, p = (e + s) / 2;
    while(s < e && e - s != 1){
        if(X < L -> Data[p]){
            e = p;
            p = (e + s) / 2;
        }else if(X > L -> Data[p]){
            s = p;
            p = (e + s) / 2;
        }else{
            return p;
        }
    }
    if(X == L -> Data[s]){
        return s;
    }else if(X == L -> Data[e]){
        return e;
    }
    return NotFound;    // 测试点1和6
}
