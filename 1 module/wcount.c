#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wcount(char* s){
    int cnt = 0;
    char *res = strtok(s, " ");
    while (res != NULL){
        cnt ++;
        res = strtok(NULL, " ");
    }
    return cnt;
}
int main(){
    char str[1000];
    gets(str);
    printf("%d\n", wcount(str));
    //free(str);
    return 0;
}