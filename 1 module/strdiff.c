#include <stdio.h>
#include <stdlib.h>

int strdiff(char *a, char *b);

int main(int argc, char **argv){
    char *s1 = malloc(1000 * sizeof(char));
    char *s2 = malloc(1000 * sizeof(char));
    fgets(s1, 1000 * sizeof(char), stdin);
    fgets(s2, 1000 * sizeof(char), stdin);

    printf("%d\n", strdiff(s1, s2));
    free(s1);
    free(s2);
    return 0;
}

int strdiff(char *s1, char *s2){
    int i = 0;
    while (s1[i] || s2[i]) {
        if (s1[i] != s2[i]) {
            for(int j = 0; j<8; j++)
                if ((s1[i] & (1 << j)) != (s2[i] & (1 << j)))
                    return (i * 8 + j);
        }
        if(!s1[i] || !s2[i])
            break;
        i++;
    }
    return -1;
}

