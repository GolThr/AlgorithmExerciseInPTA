#include <stdio.h>
#include <stdlib.h>
struct Heap{
    int *data;
    int capacity;
    int size;
};
struct Heap* initHeap(int capacity){   // initialise the heap
    struct Heap* h;
    h = (struct Heap*)malloc(sizeof(struct Heap));
    if(!h) return NULL;
    h->data = (int*)malloc(sizeof(int)*capacity+1);
    if(h->data == NULL){
        free(h);
        return NULL;
    }
    h->capacity = capacity;
    h->size = 0;
    return h;
};
void printHeap(struct Heap* h){  // print heap elements
    /* details omitted 函数实现细节省略 */
    for(int i = 1; i <= h -> size; i++){
        printf("%d, ", h -> data[i]);
    }
    printf("\n");
}
int insertIntoHeap(struct Heap* h, int x);
int deleteMin(struct Heap* h, int* pElement);
int main(){
    struct Heap *h;
    int n;
    scanf("%d", &n);   // input the capacity of heap
    h = initHeap(n);
    int op, x;
    scanf("%d", &op);
    while(op){    // op： -1 means delete,    1 means insert,     0 means terminate
        if(op == 1){
            scanf("%d", &x);
            printf("Insertion %s. ", insertIntoHeap(h, x) ? "succeeded" : "failed" );
            printHeap(h);
        }
        else{
            if (deleteMin(h, &x) ) printf("%d deleted. ", x);
            else printf("Deletion failed. ");
            printHeap(h);
        }
        scanf("%d", &op);
    }
    return 0;
}

/* Your code will be put here */
int insertIntoHeap(struct Heap* h, int x){
    int i, t;
    if(h -> size >= h -> capacity) return 0;
    h -> data[++h -> size] = x;
    for(i = h -> size; i > 0; i /= 2){
        if(i / 2 > 0 && h -> data[i] < h -> data[i / 2]){
            t = h -> data[i];
            h -> data[i] = h -> data[i / 2];
            h -> data[i / 2] = t;
        }
    }
    return 1;
}

int deleteMin(struct Heap* h, int* pElement){
    int i, j, t;
    if(h -> size == 0) return 0;
    *pElement = h -> data[1];
    h -> data[1] = h -> data[h -> size];
    h -> size--;
    for(i = 1; i <= h -> size / 2; i++){
        j = 2 * i;
        if(j + 1 <= h -> size && h -> data[j + 1] < h -> data[j]) j = j + 1;
        if(h -> data[j] < h -> data[i]){
            t = h -> data[j];
            h -> data[j] = h -> data[i];
            h -> data[i] = t;
        }
    }
    return 1;
}
