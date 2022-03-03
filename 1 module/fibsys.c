#include <stdio.h>
void printing(unsigned long max, unsigned long x, unsigned long fib1, unsigned long fib2){
    for(; max > 0; max--){
        if(fib1 <= x){
            printf("1");
            x -= fib1;
        }
        else printf("0");
        unsigned long c = fib2;
        fib2 = fib1 - fib2;
        fib1 = c;
    }
}

int main(int argc, char **argv){
    unsigned long max = 1, x = 0, fib1 = 1, fib2 = 1;
    scanf("%lu", &x);
    if(x == 0){
        printf("0");
        return 0;
    }

    while(fib1 < x) {
        max++;
        unsigned long c = fib1;
        fib1 += fib2;
        fib2 = c;
    }
    if(fib1 > x){
        max--;
        unsigned long c = fib2;
        fib2 = fib1 - fib2;
        fib1 = c;
    }
    printing(max, x, fib1, fib2);
}