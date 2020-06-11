#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode *PtrToAVLNode;
struct AVLNode{
    int Data;
    PtrToAVLNode Left;
    PtrToAVLNode Right;
    int Height;
};
typedef PtrToAVLNode AVLTree;

AVLTree Insert ( int Key, AVLTree T );
void PostOrderPrint( AVLTree T ); /* details omitted */
void InOrderPrint( AVLTree T );   /* details omitted */

int main()
{
    int N, Key, i;
    AVLTree T = NULL;

    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &Key);
        T = Insert( Key, T );
    }
    PostOrderPrint( T );
    InOrderPrint( T );

    return 0;
}

void PostOrderPrint( AVLTree T ){
    if(!T){
        return;
    }else{
        PostOrderPrint(T -> Left);
        PostOrderPrint(T -> Right);
        printf("%d ", T -> Data);
    }
}

void InOrderPrint( AVLTree T ){
    if(!T){
        return;
    }else{
        InOrderPrint(T -> Left);
        printf("%d ", T -> Data);
        InOrderPrint(T -> Right);
    }
}

/* Your function will be put here */
int getMax(int a, int b){
    return a > b ? a : b;
}

int getHeight(AVLTree T){
    if(!T) return 0;
    return T -> Height;
}

AVLTree RR_rotation(AVLTree A){
    AVLTree B = A -> Left;
    A -> Left = B -> Right;
    B -> Right = A;
    A -> Height = getMax(getHeight(A -> Left), getHeight(A -> Right)) + 1;
    B -> Height = getMax(getHeight(B -> Left), getHeight(B -> Right)) + 1;
    return B;
}

AVLTree LL_rotation(AVLTree A){
    AVLTree B = A -> Right;
    A -> Right = B -> Left;
    B -> Left = A;
    A -> Height = getMax(getHeight(A -> Left), getHeight(A -> Right)) + 1;
    B -> Height = getMax(getHeight(B -> Left), getHeight(B -> Right)) + 1;
    return B;
}

AVLTree RL_rotation(AVLTree A){
    A -> Right = RR_rotation(A -> Right);
    A = LL_rotation(A);
    return A;
}

AVLTree LR_rotation(AVLTree A){
    A -> Left = LL_rotation(A -> Left);
    A = RR_rotation(A);
    return A;
}

AVLTree Insert ( int Key, AVLTree T ){
    if(!T){
        PtrToAVLNode node = (PtrToAVLNode)malloc(sizeof(struct AVLNode));
        node -> Data = Key;
        node -> Left = NULL;
        node -> Right = NULL;
        node -> Height = 1;
        return node;
    }
    if(Key < T -> Data){
        T -> Left = Insert(Key, T -> Left);
        if(getHeight(T -> Left) - getHeight(T -> Right) >= 2){
            if(Key < T -> Left -> Data){
                T = RR_rotation(T);
            }else{
                T = LR_rotation(T);
            }
        }
    }else{
        T -> Right = Insert(Key, T -> Right);
        if(getHeight(T -> Right) - getHeight(T -> Left) >= 2){
            if(Key > T -> Right -> Data){
                T = LL_rotation(T);
            }else{
                T = RL_rotation(T);
            }
        }
    }
    T -> Height = getMax(getHeight(T -> Left), getHeight(T -> Right)) + 1;
    return T;
}
