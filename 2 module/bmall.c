#include <stdio.h>
#include <string.h>
 
int main(int argc, char *argv[]){
    if(argc<3){
        return -1;
    }
    char *T = argv[2];
    char *S = argv[1];

    int sizeS = strlen(S);
    int sizeT = strlen(T);
 
    int wc[1024];

    int i;
    for (i = 0; i < 1024; i++){
        wc[i] = -1;
    }
    
    for (i = 0; i < sizeS; i++){
        wc[(int)S[i]] = i;
    }

    int found = 0;
    int shift = 0; 
    while (shift <= (sizeT - sizeS)){
        int j = sizeS - 1;
 
        while (j >= 0 && S[j] == T[shift + j]){
            j--;
        }
        if (j < 0){
            found++;
            printf("%d\n", shift);
            shift += (shift + sizeS < sizeT) ? sizeS - wc[T[shift + sizeS]] : 1;
        }
        else{
            if(1 > j - wc[T[shift + j]]){
                shift += 1;
            }
            else{
                shift += j - wc[T[shift + j]];
            }
        }
    }
    return 0;
}