#include <stdio.h>

long long s[1000000];

long long firstSum(long long *s, long long sum, long k){
    for (int i = 0; i<k ; i++){
        sum += s[i];
    }
    return sum;
}

long long maxsum(long long *s, long a, long k){
    long long sum = 0, max=0;
    max = firstSum(s, sum, k);
    sum = max;
    for (int i = 1; i<=a-k ; i++){
        sum -= s[i-1];
        sum += s[i+k-1];
        if (sum>max){
            max=sum;
        }
    }
    return max;
}
int main() {
    long a, k;
    scanf("%ld", &a);
    for (int i = 0; i<a ; i++){
        scanf("%lld", &s[i]);
    }
    scanf("%ld", &k);
    printf("%lld", maxsum(s,a,k));
}
