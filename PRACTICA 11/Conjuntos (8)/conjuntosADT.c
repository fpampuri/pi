
#include "conjuntosADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define BLOQUE 5

typedef struct conjuntoCDT{
    elemType * vec;
    int cantElem;
    int elemReservados;
    cmp compare;
} conjunto;

conjuntoADT nuevoConjunto(cmp fnCompare){
    conjuntoADT conjunto = calloc(1, sizeof(conjunto));
    conjunto->compare = fnCompare;
    return conjunto;
}

// C1 U {elem}
int agregarElem(conjuntoADT c1, elemType elem){
    if(setContains(c1, elem))
        return 0;
    if(c1->cantElem  == c1->elemReservados){
        c1->elemReservados += BLOQUE;
        c1->vec = realloc(c1->vec,c1->elemReservados*sizeof(struct conjuntoCDT));
    }
        c1->vec[c1->cantElem++] = elem;
        return 1;
}

// C1 - {elem}
void borrarElem(conjuntoADT c1, elemType elem){
    int i, aux = 1;
    for(i=0; i<c1->cantElem && aux; i++){
        if(c1->compare(c1->vec[i], elem) == 0){
            c1->vec[i] = c1->vec[c1->cantElem--];
            aux = 0;
        }
    }
}

// C1 U C2
conjuntoADT unionConj(conjuntoADT c1, conjuntoADT c2){
    conjuntoADT aux = nuevoConjunto(c1->compare);
    int i, c;
    for(i=0; i<c1->cantElem; i++){
        c = agregarElem(aux, c1->vec[i]);
    }
    for(i=0; i<c2->cantElem; i++){
        c = agregarElem(aux, c2->vec[i]);
    }
    return aux;
}

// C1 ∩ C2
conjuntoADT interseccionConj(conjuntoADT c1, conjuntoADT c2){
    conjuntoADT aux = nuevoConjunto(c1->compare);
    int i, j, c;
    char flag;
    for(i=0; i<c1->cantElem; i++){
        if(setContains(c2, c1->vec[i])){
            c = agregarElem(aux, c1->vec[i]);
        }
    }
    return aux;
}

// C1 - C2
conjuntoADT restaConj(conjuntoADT c1, conjuntoADT c2){
    conjuntoADT aux = nuevoConjunto(c1->compare);
    int i, j, c;
    for(i=0; i<c1->cantElem; i++){
        if(!setContains(c2, c1->vec[i]))
            c = agregarElem(aux, c1->vec[i]);
    }
    return aux;
}

void liberarConjunto(conjuntoADT c1){
    free(c1->vec);
    free(c1);
}

int sizeConjunto(conjuntoADT c1){
    return c1->cantElem;
}

int isEmptyConj(conjuntoADT c1){
    return c1->cantElem == 0;
}

int setContains(conjuntoADT c1, elemType elem){
    for(int i=0; i<c1->cantElem; i++){
        if(c1->compare(c1->vec[i], elem) == 0)
            return 1;
    }
    return 0;
}