#include <stdio.h>

int main() {
    long long s[10][10];
    int n, m, minstol[10],maxstr[10];
    scanf("%d%d", &n, &m);
    for (int i = 0; i<n; i++){
        maxstr[i] = -1000000;
    }
    for (int i = 0; i<m; i++){
        minstol[i] = 1000000;
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            scanf("%lld", &s[i][j]);
            if (s[i][j]<minstol[j]){
                minstol[j]=s[i][j];
            }
            if (s[i][j]>maxstr[i]){
                maxstr[i]=s[i][j];
            }
        }
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            if (maxstr[i]==minstol[j]){
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    printf("none");
    return 0;
}
