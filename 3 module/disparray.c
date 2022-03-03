#include <stdio.h>
#include <stdlib.h>
typedef struct List list;
struct List{
    int k;
    int v;
    list* next;
};

list* initList(int k, int v);
int listEmpty(list* t);
list* listSearch(list* t,int k);
void insertBeforeStart(list* t, int y,int x);
void initHash(int n, list **t);
list* Searching(list** t, int k, int n);

int main() {
    int i,n,m,firstdigit,seconddigit;
    char cmd[20];

    scanf("%d\n%d", &n, &m);

    list *ex[m],*buf;
    initHash(m,ex);

    for (i=0;i<n;i++){
        scanf("%s", cmd);

        if (cmd[1]=='T'){
            scanf("%d", &firstdigit);
            buf = Searching(ex,firstdigit,m);
            if (buf==NULL)
                printf("0\n");
            else
                printf("%d\n",(*buf).v);
        }
        else if (cmd[1]=='S'){
            scanf("%d %d", &firstdigit, &seconddigit);
            if ((buf = Searching(ex,firstdigit,m))!=NULL)
                (*buf).v=seconddigit;
            else
                insertBeforeStart(ex[abs(firstdigit)%m], firstdigit,seconddigit);
        }
    }
    for(i=0;i<m;i++){
        list* b;
        b=ex[i];
        while (b!=NULL){
            ex[i] = (*ex[i]).next;
            free(b);
            b = ex[i];
        }
    }
}

list* initList(int k, int v){
    list* elem = malloc(sizeof(list));
    (*elem).k=k;
    (*elem).v=v;
    (*elem).next=NULL;
}

int listEmpty(list* t){
    if ((*t).next==NULL)
        return 1;
    else
        return 0;
}

list* listSearch(list* t,int k){
    list* x =(*t).next;
    while (x!=NULL && (*x).k!=k){
        x=(*x).next;
    }
    return x;
}

void insertBeforeStart(list* t, int y,int x){
    list* elem = malloc(sizeof(list));
    (*elem).k=y;
    (*elem).v=x;
    (*elem).next=(*t).next;
    (*t).next=elem;
}

void initHash(int n, list **t){
    int i;
    for (i=0;i<n;i++)
    {
        t[i] = initList(0, 0);
    }
}

list* Searching(list** t, int k, int n){
    list* result;
    result = listSearch(t[abs(k)%n],k);

    return result;
}