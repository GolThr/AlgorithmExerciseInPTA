#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    int *a = new int[N];
    int *b = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
 
    int index;
    for (index = 1; b[index] >= b[index - 1]; index++);
    int count = index;//已经排好序的元素的个数
    while (count < N && a[count] == b[count]) {
        count++;//没有排序的个数
    }
 
    if (count == N) {//如果count和元素个数相等的话   插排
        cout << "Insertion Sort\n";
        sort(b, b + index + 1);
        cout << b[0];
        for (int i = 1; i < N; i++) {
            cout << " " << b[i];
        }
    }
    else {//堆排序
        cout << "Heap Sort\n";
        sort(a, a + N);//把A排序
        for (index = N - 1; index > 0 && b[index] == a[index]; index--);//从末尾数相同元素的个数
        //for (index = N - 1; index > 0 && b[index] > b[index - 1]; index--);
        pop_heap(b, b + index + 1);
        cout << b[0];
        for (int i = 1; i < N; i++) {
            cout << " " << b[i];
        }
    }
}
