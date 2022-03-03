#include <stdio.h>
void refact(long long s[], long long sres[], long long n){
    for (int i=0; i<=n; i++){
        sres[i]=s[i]*(n-i);
    }
}

int main(int argc, char **argv){
    long long n, x, s[10000];
    scanf("%lld", &n);
    scanf("%lld", &x);
    for (int i = 0; i<=n; i++){
        scanf("%lld", &s[i]);
    }
    long long res = s[n];
    int i = 1;
    long long resx = x;
    while (i!=n){
        res += resx*s[n-i];
        if (i==n-1){
            resx *= x*s[0];
        }
        else resx *= x;
        i++;
    }
    printf("%lld\n", res+resx);
    long long refs[10000];
    refact(s,refs,n);
    long long proiz = refs[0];
    for (int i = 0 ; i<n-1 ; i++){
        proiz *=x;
        proiz +=refs[i+1];
    }
    printf("%lld\n", proiz);
    return 0;
}