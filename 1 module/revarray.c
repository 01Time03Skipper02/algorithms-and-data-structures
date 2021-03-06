#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revarray(void *base, unsigned long nel, unsigned long width) {
    for (unsigned long i = 0; i * 2 < nel; i++) {
        unsigned long j = nel - i - 1;
        void* buff = malloc(width);
        memmove(buff, ((char*)base + i * width), width);
        memmove(((char*)base + i * width), ((char*)base + j * width), width);
        memmove(((char*)base + j * width), buff, width);
        free(buff);
    }
}
int main(int argc, char **argv){
    int array[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    revarray(array, 5, sizeof(int));
    for (int i = 0; i < 5; i++){
        printf("%d ", array[i]);
    }
    return 0;
}
