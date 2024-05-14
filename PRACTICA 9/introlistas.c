#include <stdio.h>

typedef struct node{
    int head;
    struct node * tail;
}

typedef struct node * TList;

int isEmpty(TList l){
    return l == NULL;
}

int belongs(const TList list, int n){
    if(list == NULL)
        return 0;
    if(list->head > n)
        return 0;
    return (list->head == n) || belongs(list->tail, n);
}

void freeList(TList list){
    if(list != NULL)
        freeList(list->tail);
    free(list);
}

int size(const TList list){
    if(list == NULL)
        return 0;
    return 1 + size(list->tail);
}