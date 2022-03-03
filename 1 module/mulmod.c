#include <stdio.h>
unsigned long long mulmod(unsigned long long a, unsigned long long m, unsigned long long s[], unsigned long long k){
    unsigned long long res = a * s[k-1];
    for (int i = 0; i <= k-2; i++){
        res = (res%m) * 2;
        res = (res%m) + (a % m) * (s[k-i-2] % m);
    }
    return res%m;
}

int main() {
    unsigned long long a, b, m;
    scanf("%lld%lld%lld", &a, &b, &m);
    unsigned long long x = b, s[300], k=0;
    while(x>0){
        s[k] = x%2;
        x /= 2;
        k++;
    }
    unsigned long long res = mulmod(a,m,s,k);
    printf("%lld\n", res);
}