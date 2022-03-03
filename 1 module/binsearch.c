#include <stdio.h>
#define less -1
#define notless 1

int s[10] = {2, 3, 6, 7, 9, 15, 25, 37, 58, 89}, com=25;

int compare(unsigned long i){
    if (s[i]<com){
        return less;
    }
    else if (s[i]>com){
        return notless;
    }
    return 0;
}

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)){
    int leftind = -1, rightind = nel-1, middleind;
    while (rightind-leftind>1){
        middleind = (rightind+leftind)/2;
        if (compare(middleind)!=less){
            rightind = middleind;
        }
        else
            leftind = middleind;
    }
    if (compare(rightind)==0){
        return rightind;
    }
    return nel;

}


int main(){
    printf("%ld", binsearch(10, compare));
}

