#include <stdio.h>
#include <malloc.h>

void swap(void *a, void *b, size_t width) {
    char buf;
    for(int i = 0; i < width; i++){
        buf = ((char*)a)[i];
        ((char*)a)[i] = ((char*)b)[i];
        ((char*)b)[i] = buf;
    }
}

void Heapify(int (*compare)(const void *a, const void *b), void *base, int i, unsigned long nel, size_t width){
    while (1){
        int l = 2*i + 1;
        int r = l + 1;
        int j = i;
        if (l < nel && (compare((unsigned char *)base + i * width , (unsigned char *)base + l * width) < 0))
            i = l;
        if (r < nel && (compare((unsigned char *)base + i * width, (unsigned char *)base + r * width) < 0))
            i = r;
        if (i == j)
            break;
        swap((unsigned char *)base + j * width, (unsigned char *)base + i * width, width);
    }
}

void BuildHeap(int (*compare)(const void *a, const void *b), unsigned long nel, void *base, size_t width) {
    for (int i = (int)nel / 2 - 1; i >= 0; i--)
        Heapify(compare, base, i, nel, width);
}

void hsort(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b)){
    BuildHeap(compare, nel, base, width);
    for (int i = nel - 1; i > 0; i--){
        swap(base, (unsigned char *)base + i * width, width);
        Heapify(compare, base, 0, i, width);
    }
}

int count_a(const char *str){
    int res = 0;
    for(int i = 0; str[i]; i++){
        if (str[i] == 'a')
            res++;
    }
    return res;
}

int compare(const void *a, const void *b){
    int s1_count = count_a(a);
    int s2_count = count_a(b);
    return s1_count - s2_count;
}

int main(){
    int n;
    scanf("%d ", &n);
    char arr[n][1000];
    for(int i = 0; i < n; i++)
        fgets(arr[i], 1000*sizeof(char), stdin);
    hsort(arr, n, 1000, compare);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    return 0;
}
