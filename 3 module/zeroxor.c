#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <math.h>    
#define distanceTable 6
#define x 143
#define y 7
#define HashPos1 table[Hash(PrefixXOR)* distanceTable]
#define HashPos2 table[j * distanceTable + k]

//Выполнял при помощи хэш-таблицы, изменяя данные таблицы, перебирая ключи

unsigned int Hash(int key){
    long res = 1;
    for(int i = 32; i >= 0; i--) {
        res *= 551; //простое число!
        if (key & (1 << i)){
            res += x;
        }
        else{
            res += y;
        }
        res %= 106349; //простое число большее, чем n в условии задачи!
    }
    return (res % 106349);
}

struct Pair{
    int key;
    unsigned int value;
};

int main() {
    int n;
    int a;
    scanf("%d", &n);
    struct Pair **table = malloc(sizeof(struct Pair*) * 106349 * distanceTable);
    memset(table, 0, sizeof(struct Pair*) * 106349 * distanceTable);
    int PrefixXOR = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        PrefixXOR ^= a;
        if (HashPos1 == NULL){
            HashPos1 = malloc(sizeof(struct Pair));
            if(PrefixXOR){
                HashPos1->value = 0;
            }
            else{
                HashPos1->value = 1;
            }
            HashPos1->key = PrefixXOR;
        }
        else if (HashPos1->key == PrefixXOR){
            HashPos1->value++;
        }
        else{
            unsigned int j = Hash(PrefixXOR);
            int k = 1;
            for(; HashPos2 != NULL; k++){
                if (HashPos2->key == PrefixXOR) break;
            };
            if(HashPos2 == NULL){
                HashPos2 = malloc(sizeof(struct Pair));
                HashPos2->key = PrefixXOR;
                if (PrefixXOR){
                    HashPos2->value = 0;
                }
                else{
                    HashPos2->value = 1;
                }
            } else {
                HashPos2->value++;
            }
        }
    }
    unsigned int res = 0;
    for (int i = 0; i < 106349 * distanceTable; i++){
        struct Pair *elem = table[i];
        if (elem == NULL) continue;
        unsigned int val = elem->value;
        res += val * (val + 1) / 2;
        free(elem);
    }
    free(table);
    printf("%u\n", res);
}