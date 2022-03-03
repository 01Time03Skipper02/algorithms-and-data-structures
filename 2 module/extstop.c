#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int BMSubst(char *s,char *t,int n)
{
    int **g,i,j;
    int len = strlen(s),len1= strlen(t);
    int lenbuf=len;
    g = (int**)malloc((len) * sizeof(int*));
    for (i = 0; i < len; i++)
        g[i]=(int *)malloc(n * sizeof(int));
    for (j = 0; j < len; j++)
        for (i = 0; i < n; i++)
            g[j][i]=0;

        int i1, j1;
        int leng = strlen(s);
        for (j1 = 0; j1 < leng; j++){
            for (i1 = 0; i1 < n; i1++){
                g[j1][i1] = leng - j1;
            }
        }
        len--;

        while (len < len1){
            i = lenbuf - 1;
            while (t[len] == s[i])
        {
                if (i == 0)
            {
                    for (j = 0; j < lenbuf; j++)
                        free(g[j]);
                    free(g);
                    return len;
            }
            i--;
            len--;
        }
        len += g[i][t[len] - 'a'];
    }
    for (j = 0; j < lenbuf; j++)
          free(g[j]);
    free(g);
    return len1;
}

int main(int argc, char **argv){
    int x;
    x = BMSubst(argv[1], argv[2], 10);
    printf("%d\n", x);
    return 0;
}