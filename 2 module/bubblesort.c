#include <stdio.h>
#include <stdlib.h>
int *s;
int compare(unsigned long i, unsigned long j){
    if (s[i] < s[j]){
        return -1;
    }
    else if (s[i] == s[j]) return 0;
    return 1;
}
void swap(unsigned long i, unsigned long j){
    unsigned long buf = s[i];
    s[i]=s[j];
    s[j]=buf;
}
void bubblesort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j)){
    int leftind=0 , rightind = nel-1, c;
    do{
        c=0;
        for (int i = leftind; i<rightind; i++){
            if (compare(i, i + 1)==1){
                swap(i, i + 1);
                c=i;
            }
        }
        for (int j=rightind; j>leftind; j--){
            if (compare(j, j - 1)==-1){
                swap(j, j - 1);
                c=j;
            }
        }
    } while (c>0);
}
int main(int argc, char **argv){
    int n;
    scanf("%d", &n);
    s = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }
    bubblesort(n, compare, swap);
    for (int i = 0; i < n; i++){
        printf("%d ", s[i]);
    }
    free(s);
}
