#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *concat(char **s, int n) {
    int size = 0, id = 0;
    for (int i = 0; i < n; ++i)
        size += strlen(&s[i][0]);
    char *str = malloc(size + 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; s[i][j] != '\0'; ++j)
            str[id++] = s[i][j];
    str[id] = '\0';
    return str;
}

char *cpy(char *s, int ln) {
    char *str = malloc(ln + 1);
    for (int i = 0; i <= ln; i++) str[i] = s[i];
    return str;
}

int main() {
    int n;
    scanf("%d", &n);

    char *res[1005 * 1005 / 10 + 5], str[1005];

    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        res[i] = cpy(str, strlen(str));
    }

    char *memres = concat(res, n);
    printf("%s", memres);
    free(memres);
    for (int i = 0; i < n; i++) free(res[i]);

    return 0;
}