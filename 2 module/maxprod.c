#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
void getFractionMultiply(int* numerators, int* denominators, int nel);
 
int main() {
    int N;
    scanf("%d", &N);
    int i = 0;
    int fraction_numerators[N];
    int fraction_denominators[N];
    for(i; i < N; i++) {
        scanf("%d", &fraction_numerators[i]);
        scanf("/");
        scanf("%d", &fraction_denominators[i]);
 
    }
    getFractionMultiply(fraction_numerators, fraction_denominators, N);
}

void getFractionMultiply(int* numerators, int* denominators, int nel){
    int i, j, k;
    float answer = 1, denom_answer = 1;
    float final, maxi = INT_MIN, current;
 
    int left = 0, right = 0;
    for(i = 0; i < nel; i++){
        for(j = i; j < nel; j++) {
            current = 1;
            for (k = i; k <= j; k++) {
                current *= numerators[k];
                current /= denominators[k];
 
            }
            if (maxi < current) {
                maxi = current;
                left = i;
                right = j;
            }
        }
    }
    printf("%d %d", left , right);
}