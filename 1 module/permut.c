#include <stdio.h>
void comp(long long *a, long long *b){
    long long check[8];
    for (int i = 0; i<8;i++){
        check[i]=0;
    }
    for (int i = 0; i<8;i++){
        int flag = 0;
        for (int j = 0; j<8;j++){
            if (a[i]==b[j] && check[j]!=1){
                check[j]=1;
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            printf("No");
            return;
        }
    }
    printf("Yes");
    return;
}

int main() {
    long long a[8], b[8];
    for (int i = 0; i<8;i++){
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i<8;i++){
        scanf("%lld", &b[i]);
    }
    comp(a,b);
}
