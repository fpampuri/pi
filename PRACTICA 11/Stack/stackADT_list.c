#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
#include "stackADT.h"

#define FALSE 0
#define TRUE !FALSE
#define BLOQUE 5
struct node{
    elemType head;
    struct node * tail;
};

struct stackCDT{
    struct node * list;
    int elemCount;
    fnEquals fn;
};

stackADT newStack(fnEquals func){
    stackADT stack = calloc(1, sizeof(struct stackCDT));
    stack->fn = func;
    return stack;
}

void freeStack(stackADT stack){
    freeListRec(stack->list);
    free(stack);
}

static void freeListRec(struct node * list){
    if(list == NULL)
        return;
    freeListRec(list->tail);
    free(list);
}

int isEmpty(const stackADT stack){
    return stack->list == NULL;
}

void push(stackADT stack, elemType elem){
    struct node * aux = malloc(sizeof(struct node));
    aux->head = elem;
    aux->tail = stack->list;
    stack->list = aux;
    (stack->elemCount)++;
}

elemType pop(stackADT stack){
    if(isEmpty(stack))
        exit(1);
    elemType ans = stack->list->head;
    struct node * aux = stack->list;
    stack->list = aux->tail;
    free(aux);
    (stack->elemCount)--;
    return ans;
}

int sizeStack(const stackADT stack){
    return stack->elemCount;
}

int belongs(const stackADT stack, elemType elem){
    return belongsRec(stack->list, elem, stack->fn);
}
static int belongsRec(struct node * list, elemType elem, fnEquals fn){
    if(list == NULL)
        return FALSE;
    return fn(list->head, elem) || belongsRec(list->tail, elem, fn);
}

int belongs(const stackADT stack, elemType elem){
    struct node * aux = stack->list;
    while(aux != NULL){
        if(stack->fn(aux->head, elem))
            return 1;
        aux = aux->tail;
    }
    return 0;
}
