#include <stdio.h>
#include <stdlib.h>
int *s;

int compare(unsigned long i, unsigned long j){
    if (s[i]<s[j]){
        return -1;
    }
    if (s[i]==s[j]){
        return 0;
    }
    return 1;
}

void swap(unsigned long i, unsigned long j){
    int buf = s[i];
    s[i]=s[j];
    s[j]=buf;
}

void shellsort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j)){
    int fib1 = 1, fib2 = 1, cnt = 0;
    for (;fib2<nel; cnt++){
        int buf = fib2;
        fib2 = fib1 + fib2;
        fib1 = buf;
    }
    fib1=1, fib2=1;
    int *fibs = malloc(cnt * sizeof(int));
    for (int i = 0; fib2<nel; i++){
        int buf = fib2;
        fib2 = fib1 + fib2;
        fib1 = buf;
        fibs[i]=fib1;
    }
    for(int i = cnt-1; i>=0; i--){
        int d = fibs[i];
        for (int j = 0; j<nel; j++){
            for (int k = j-d; k>=0 && compare(k,k+d)==1;k-=d){
                swap(k, k+d);
            }
        }
    }
    free(fibs);
}

int main(int argc, char **argv){
    int n;
    scanf("%d", &n);
    s = (int*)malloc(n * sizeof(int));
    for (int i = 0; i<n; i++){
        scanf("%d", &s[i]);
    }
    shellsort(n,compare,swap);
    for (int i = 0; i<n ; i++){
            printf("%d ", s[i]);
    }
    free(s);
    return 0;
}
