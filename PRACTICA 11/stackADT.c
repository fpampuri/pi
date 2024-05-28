#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
#include "stackADT.h"

#define BLOQUE 5

struct stackCDT{
    elemType * vec;
    int dim; // elementos en la pila
    int size; // elementos reservados
    fnEquals fn;
};

stackADT newStack(fnEquals func){
    stackADT stack = calloc(1, sizeof(struct stackCDT));
    stack->fn = func;
    return stack;
}

void freeStack(stackADT stack){
    free(stack->vec);
    free(stack);
    return;
}

int isEmpty(const stackADT stack){
    return stack->dim == 0;
}

void push(stackADT stack, elemType elem){
    if(stack->dim == stack->size){
        stack->vec = realloc(stack->vec, (stack->size+BLOQUE)*sizeof(int));
        stack->size += BLOQUE;
    }
    stack->vec[(stack->dim)++] = elem;
    return;
}

elemType pop(stackADT stack){
    if(stack->dim == 0){
        fprintf(stderr, "No hay elementos para popear");
        exit(1);   
    }
    return stack->vec[--stack->dim];
}

int sizeStack(const stackADT stack){
    return stack->dim;
}

int belongs(const stackADT stack, elemType elem){
    for(int i=0; i < stack->dim; i++){
        if(stack->fn(stack->vec[i], elem))
            return 1;
    }
    return 0;
}

