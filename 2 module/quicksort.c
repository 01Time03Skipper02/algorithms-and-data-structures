#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int *arr, int begin, int end) {
    for(int i = end; i > begin; i--) {
    int mxid = i;
    for(int j = i - 1; j >= begin; j--)
        if(arr[j] > arr[mxid])mxid = j;
    swap(arr + i, arr + mxid);
    }
}

int putting(int *arr, int begin, int end) {
    for(int j = begin; j < end; j++)
    if(arr[j] < arr[end])
        swap(arr + begin++, arr + j);
    swap(arr + begin, arr + end);
    return begin;
}

void quicksort(int *arr, int begin, int end, int m) {
    if(end - begin <= m) selectionSort(arr, begin, end);
    else{
        while(begin < end){
        int newbeggin = putting(arr, begin, end);
        if(newbeggin - begin < end - newbeggin) quicksort(arr, begin, newbeggin - 1, m), begin = newbeggin + 1;
        else quicksort(arr, newbeggin + 1, end, m), end = newbeggin - 1;
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int *arr = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) scanf("%d", arr + i);

    quicksort(arr, 0, n - 1, m);

    for(int i = 0; i < n; i++) printf("%d ", arr[i]);

    free(arr); 
    return 0;
}