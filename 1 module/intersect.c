#include <stdio.h>
#include <math.h>
 
int main() {
 
    int n, k;
 
    scanf("%d", &n);
 
    char B[33]= "000000000000000000000000000000000";
    char A[33]= "000000000000000000000000000000000";
 
    for (int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        A[a] = 1;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        int a ;
        scanf("%d", &a);
        B[a] = 1;
    }
 
    for (int u = 0; u < 32; u++){
        if ((A[u] == B[u]) && (A[u] == 1)){
            printf("%d", u);
            printf("%s", "\n");
        }
    }
    return 0;
}