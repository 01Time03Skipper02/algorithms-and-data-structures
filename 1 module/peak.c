#include <stdio.h>
#include <stdlib.h>

long long s[10] = {21, 521, 2, 21, 21, 5, 86, 42, 88, 90};

int less (unsigned long i, unsigned long j){
    if (s[i]<s[j]){
        return 1;
    }
    return 0;
}

unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)){
    if (nel==0){
            return 0;
        }
    for (unsigned long i = 0; i<nel ; i++){
        if ((i == 0 || (i > 0 && !less(i, i - 1))) && (i == nel - 1 || (i < nel - 1 && !less(i, i + 1)))){
            return i;
        }
    }
}

int main(int argc, char **argv){
    unsigned long res = peak(10, less);
    printf("%ld\n", res);
}