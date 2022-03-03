#include <stdio.h>

int compare(void *a, void *b){
    if (*(int*)a > *(int*)b){
        return 1;
    }
    else if (*(int*)a < *(int*)b) {
        return 2;
    }
}

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)){
    int *max = (int*) base;
    int basedebug = base;
    for (int i = 0; i < nel; i++){
        if (compare(basedebug+i*width, max)==1){
            max = basedebug + i *width;
        }
    }
    return *max;
}


int main() {
    int n = 8;
    int s[] = {5, 4, 32, 66, 21, 75, 21, 53};
    int max = maxarray(s, n, sizeof(int), compare);
    for (int i = 0; i<n; i++){
        if (s[i]==max){
            printf("%d", i);
            return 0;
        }
    }
}
