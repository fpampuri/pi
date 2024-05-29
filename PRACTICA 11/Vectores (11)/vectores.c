#include "vectores.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef struct element{
    elemType elem;
    char occupied;
} TElem;

struct vectorCDT{
    TElem * vec;
    size_t dim;
    size_t used;
    fnCmp cmp;
};

vectorADT newVector(fnCmp cmp){
    vectorADT aux = calloc(1, sizeof(struct vectorCDT));
    aux->cmp = cmp;
    return aux;
}

/* Libera todos los recursos reservados por el TAD */
void freeVector(vectorADT v){
    if(v->vec != NULL){
        free(v->vec);
    }
    free(v);
}

/* Almacena los elementos de elems a partir de la posición index, 
** donde elems es un vector de dim elementos.
** En caso de ser necesario agranda el vector.
** El resto de los elementos del vector no se modifican y permanecen 
** en la misma posición.
** Si se recibe NULL o no se pudo insertar retorna cero.
** Si alguna posición está ocupada, la deja como estaba.
** Retorna cuántos elementos pudo almacenar.
** Ejemplo:
**   Si v tiene ocupadas las posiciones 1,3 y 6
**   Se invoca con index=2, dim=5
**   El vector actual quedará con los mismos elementos en las 
**   posiciones 1, 3 y 6
**   Pero además v[2]=elems[0], v[4]=elems[2], v[5]=elems[3]
**   y la función retorna 3
*/
int put(vectorADT v, elemType * elems, size_t dim, size_t index){
    if(dim == 0 || elems == NULL)
        return 0;
    if(index + dim > v->dim){
        v->vec = realloc(v->vec,(index+dim)*sizeof(TElem));
        v->dim = index + dim;
    }
    int aux = 0, count = 0;
    for(int i=index; i < index+dim; i++){
        if(!v->vec[i].occupied){
            v->vec[i].elem = elems[aux];
            v->vec[i].occupied = 1;
            v->used++;
            count++;
        }
        aux++;
    }
    return count;   
}

int getIdx(vectorADT v, elemType elem){
    int i;
    for(i=0; i<v->dim; i++){
        if(v->vec[i].occupied && !v->cmp(v->vec[i].elem, elem))
            return i;
    }
    return -1;
}

/* Elimina el elemento en la posición index. Si index está fuera del vector no hace nada */
void deleteElement(vectorADT v, size_t index){
    if(index < v->dim && v->vec[index].occupied){
        v->vec[index].occupied = 0;
        v->used--;
    }
}

/* Retorna cuántos elementos hay insertados en el vector */
int elementCount(vectorADT v){
    return v->used;
}






int compInt (elemType source, elemType target) {
    return source - target;
}

int main(void) {
    
    vectorADT v = newVector(compInt);
    elemType elems[] = {1, 2, 10, 20, 100, -2, 4};
    elemType elems2[]= {1, 3, 4, 10, 22, 33};

    assert( getIdx(v, elems[2]) == -1);
    
    assert( put(v, elems, 7, 3) == 7);    // v queda {vacio, vacio, vacio, 1, 2, 10, 20, 100, -2, 4}
    assert(elementCount(v)==7);
    assert( getIdx(v, 1) == 3);
    assert( getIdx(v, 2) == 4);
    assert( getIdx(v, 10) == 5);
    assert( getIdx(v, 22) == -1);
    assert( put(v, elems2, 6, 0) == 3);   // v queda {1, 3, 4, 1, 2, 10, 20, 100, -2, 4}
    assert( getIdx(v, 22) == -1);
    assert( getIdx(v, 1) == 0);
    assert( getIdx(v, 3) == 1);
    assert(elementCount(v)==10);
    assert( put(v, elems2, 6, 0) == 0);   // v queda igual
    assert( getIdx(v, 1) == 0);
    assert(elementCount(v)==10);
    deleteElement(v, 100);
    assert(elementCount(v)==10);
    deleteElement(v, 0);
    assert( getIdx(v, 1) == 3);
    assert(elementCount(v)==9);
    // Volvemos a borrar el 0, no deberia decrementar la cantidad
    deleteElement(v, 0);
    assert(elementCount(v)==9);
    assert( getIdx(v, 1) == 3);
    
    assert( put(v, elems2 + 5, 1, 12) == 1);   // v queda {vacio, 3, 4, 1, 2, 10, 20, 100, -2, 4. vacio, vacio, 33}
    assert(elementCount(v)==10);
    assert( getIdx(v, 33) == 12);
    assert( getIdx(v, 0) == -1);

    freeVector(v);
    
    puts("OK!");

    return 0;
}