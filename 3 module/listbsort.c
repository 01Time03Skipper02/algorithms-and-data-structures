#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem
{
    struct Elem *next;
    char *word;
};

struct Elem *bsort(struct Elem *list);
struct Elem *add_elem(struct Elem *list, struct Elem *new_elem);

int main(){
    struct Elem *list;
	list = NULL;
    char *buffer = (char *) calloc(1000 + 1, 1);
    char c;
	//Считывание строки
    while ((c = getchar()) != '\n'){
        if (c != ' '){
            ungetc(c, stdin);
            scanf("%s", buffer);
            int len = strlen(buffer);
            struct Elem *new_elem = (struct Elem *) malloc(sizeof(struct Elem));
            new_elem->word = (char *) calloc(len + 1, 1);
            new_elem->next = NULL;
            new_elem->word = strcpy(new_elem->word, buffer);
            list = add_elem(list, new_elem);
        }
    }

    list = bsort(list);
    struct Elem *currentPrint = list;
	//Печатаем строку уже после сортировки
    while (currentPrint != NULL){
        printf("%s%c", currentPrint->word, (currentPrint->next) ? ' ' : '\n');
        currentPrint = currentPrint->next;
    }
    struct Elem *currentFree = list, *prev = NULL;
	//Чистим память :-)
    while (currentFree){
        free(currentFree->word);
        prev = currentFree;
        currentFree = currentFree->next;
        free(prev);
    }
	free(buffer);
    return (0);
}

struct Elem *bsort(struct Elem *list){
    struct Elem *current, *prev;
    int sorted;
    do{
        current = list;
        prev = NULL;
        sorted = 1;
        while (current->next != NULL){
            if (strlen(current->next->word) < strlen(current->word)){
                struct Elem *next = current->next;
                if (current == list) list = current->next;
                else prev->next = next;
                current->next = next->next;
                next->next = current;
                prev = next;
                sorted = 0;
                continue;
            }
            prev = current;
            current = current->next;
        }
    } while (!sorted);
    return (list);
}

struct Elem *add_elem(struct Elem *list, struct Elem *new_elem){
    struct Elem *current = list, *prev = NULL;
    while (current != NULL){
        prev = current;
        current = current->next;
    }
    if (prev == NULL) list = new_elem;
    else prev->next = new_elem;
    new_elem->next = NULL;
    return (list);
}