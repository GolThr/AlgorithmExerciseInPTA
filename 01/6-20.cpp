#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int weight;
    int parent;
    int lchild;
    int rchild;
} HTNode, *HuffmanTree;
typedef char ** HuffmanCode;

void SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2);
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n);

int main() {
    HuffmanTree ht;
    HuffmanCode hc;

    int n;
    scanf("%d", &n);
	
    int *w = (int *) malloc (n * sizeof(int));
    for(int i = 0; i < n; ++ i)
        scanf("%d", &w[i]);

    HuffmanCoding(ht, hc, w, n);
	
    for (int i = 1; i <= 2 * n - 1; ++ i) {
        printf("%d %d %d %d\n", 
        ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
    }

    for (int i = 1; i <= n; ++ i)
        printf("%s\n", hc[i]);

    free(w);
    free(ht);
    for (int i = 1; i <= n; ++ i)
        free(hc[i]);
	
    return 0;
}
/* 你的代码将被嵌在这里 */
void reverse(char * CH){
	int n = strlen(CH);
	int i;
	char temp;
	for(i = 0; i < n / 2; i++){
		temp = CH[i];
		CH[i] = CH[n - i - 1];
		CH[n - i - 1] = temp;
	}
}

void SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2){
    int i, mina = 0, minb = 0, minwa = 1000, minwb = 1000;
    for(i = 1; i < upbound; i++){
        if(HT[i].weight < minwa){
            if(HT[i].parent == 0){
                minb = mina;
                minwb = minwa;
                mina = i;
                minwa = HT[i].weight;
            }
        }else if(HT[i].weight < minwb){
            if(HT[i].parent == 0){
                minb = i;
                minwb = HT[i].weight;
            }
        }
    }
    // 无需判断大小！！
    s1 = mina;
    s2 = minb;
}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n){
    HT = (HuffmanTree)malloc(sizeof(HTNode) * (2 * n));
    HC = (char **)malloc(sizeof(char *) * (n + 1));
    int i, j, s1, s2;
    for(int i=1;i<=n;i++){
    	HC[i] = (char *)malloc(sizeof(char) * (n + 1));
		memset(HC[i], 0, sizeof(char) * (n + 1));
	}
    for(i = 0; i < 2 * n; i++){
        HT[i].weight = 0;
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for(i = 0; i < n; i++){
        HT[i + 1].weight = w[i];
    }
    for(i = 0; i < n - 1; i++){
        SelectTwoMin(n + i + 1, HT, s1, s2);
        HT[n + i + 1].weight = HT[s1].weight + HT[s2].weight;
        HT[n + i + 1].lchild = s1;
        HT[n + i + 1].rchild = s2;
        HT[s1].parent = n + i + 1;
        HT[s2].parent = n + i + 1;
    }
    //Coding
	for(i = 1; i <= n; i++){
        int c = i;
        int parent = HT[c].parent;
        while(parent != 0){
            if(HT[parent].lchild == c){
                strncat(HC[i], "0", 1);
            }else{
            	strncat(HC[i], "1", 1);
			}
	        c = parent;
	        parent = HT[parent].parent;
	    }
	    reverse(HC[i]);
    }
}
