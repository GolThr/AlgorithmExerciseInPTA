#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
//选择排序和冒泡排序最后一个测试点均超时，采用希尔排序实现
//参考：
//希尔排序的原理解析(https://baijiahao.baidu.com/s?id=1644158198885715432&wfr=spider&for=pc)
//6-11 求自定类型元素序列的中位数(https://blog.csdn.net/qq_40604313/article/details/81276492)
void ShellSort(ElementType A[], int N){
    int i, j, k;
    ElementType t;
    for(k = N / 2; k > 0; k /= 2){
        for(i = k; i < N; i++){
            for(j = i - k; j >= 0 && A[j] > A[j + k]; j -= k){
                t = A[j];
                A[j] = A[j + k];
                A[j + k] = t;
            }
        }
    }
}

ElementType Median( ElementType A[], int N ){
    int i, j, min, l = 0, h = N - 1;
    ElementType t;
    ShellSort(A, N);
    return A[N / 2];
}
