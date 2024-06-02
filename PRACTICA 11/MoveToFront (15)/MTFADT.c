#include "MTFADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct node{
    elemType elem;
    struct node * tail;
} TNode;
typedef TNode * TList;

typedef struct moveToFrontCDT{
    TList first;
    TList iterator;
    size_t count;
    comp cmp;
} moveToFrontCDT;

moveToFrontADT newMoveToFront(comp cmp){
    moveToFrontADT aux = calloc(1, sizeof(moveToFrontCDT));
    aux->cmp = cmp;
    return aux;
}

unsigned int size(moveToFrontADT moveToFront){
    return moveToFront->count;
}

/* Inserta un elemento si no está. Lo inserta al final.
** Retorna 1 si lo agregó, 0 si no.
*/

static TList addRec(TList l, elemType elem, comp cmp, int * flag){
    if(l == NULL){
        TList aux = malloc(sizeof(TNode));
        aux->elem = elem;
        aux->tail = NULL;
        *flag = 1;
        return aux;
    }
    if(cmp(l->elem, elem) == 0)
        return l;
    l->tail = addRec(l->tail, elem, cmp, flag);
    return l;
}
unsigned int add(moveToFrontADT moveToFront, elemType elem){
    int found = 0;
    moveToFront->first = addRec(moveToFront->first, elem, moveToFront->cmp, &found);
    moveToFront->count += found;
    return found;
}

/* Retorna una copia del elemento. Si no existe retorna NULL.
** Para saber si el elemento está, usa la función compare. 
** Si el elemento estaba lo ubica al principio.
*/
TList findNode(TList list, elemType elem, comp cmp, TList * found){
    if(list == NULL){
        *found = NULL;
        return list;
    }
    
    if(cmp(list->elem, elem) == 0){
        *found = list;
        return list->tail;
    }
    list->tail = findNode(list->tail, elem, cmp, found);
    return list;
}
elemType * get(moveToFrontADT moveToFront, elemType elem){
    TList found;
    moveToFront->first = findNode(moveToFront->first, elem, moveToFront->cmp, &found);

    if(found != NULL){
        found->tail = moveToFront->first;
        moveToFront->first = found;
        elemType * resp = malloc(sizeof(elemType));
        *resp = found->elem;
        return resp;
    }
    else return NULL;
}

static void freeRec(TList l){
    if(l == NULL)
        return;
    freeRec(l->tail);
    free(l);
}
void freeMoveToFront(moveToFrontADT m){
    freeRec(m->first);
    free(m);
}

/* Se ubica al principio del conjunto, para poder iterar sobre el mismo */
void toBegin(moveToFrontADT moveToFront){
    moveToFront->iterator = moveToFront->first;
}

/* Retorna 1 si hay un elemento siguiente en el iterador, 0 si no */
int hasNext(moveToFrontADT moveToFront){
    return moveToFront->iterator != NULL;
}

/* Retorna el siguiente elemento. Si no hay siguiente elemento, aborta */
elemType next(moveToFrontADT moveToFront){
    if(!hasNext(moveToFront)){
        fprintf(stderr, "No hay siguiente elemento");
        exit(1);
    }
    elemType aux = moveToFront->iterator->elem;
    moveToFront->iterator = moveToFront->iterator->tail;
    return aux;
}



static int compareStruct (elemType e1, elemType e2) {
   	return e1.code - e2.code;
}


int 
main(void) {
   	moveToFrontADT p = newMoveToFront(compareStruct);
    
    elemType aux = {1, "uno"};
    assert(add(p, aux)==1);
    strcpy(aux.name, "dos");
    assert(add(p, aux)==0);
    aux.code = 2;
    assert(add(p, aux)==1);
    aux.code = 3;
    strcpy(aux.name, "tres");
    assert(add(p, aux)==1);
    aux.code = 4;
    strcpy(aux.name, "cuatro");
    assert(add(p, aux)==1);
    toBegin(p);
    
    while (hasNext(p)) {
       aux = next(p);
       printf("%d %s ", aux.code, aux.name);
    }
    putchar('\n'); 
    
    aux.code = 5;
    elemType * q = get(p, aux);	
    assert(q==NULL);
    
    aux.code = 3;
    q = get(p, aux);
    printf("%d %s\n", q->code, q->name);    
    assert(q->code==3);
    assert(strcmp(q->name, "tres")==0);
    free(q);
    
    // Volvemos a pedir el 3, que ahora debe estar al principio
    aux.code = 3;
    q = get(p, aux);
    printf("%d %s\n", q->code, q->name);    
    assert(q->code==3);
    assert(strcmp(q->name, "tres")==0);
    free(q);
    
    toBegin(p);
    printf("Debe imprimir 3 tres 1 uno 2 dos 4 cuatro\n");
    int vec[] = {3, 1, 2, 4};
    int i=0;
    while (hasNext(p)) {
       aux = next(p);
       printf("%d %s ", aux.code, aux.name);
       assert(aux.code == vec[i++]);
    }
    putchar('\n');

    aux.code = 5;
    strcpy(aux.name, "cinco");
    assert(add(p, aux)==1);
    q = get(p, aux);
    assert(q->code==5);
    assert(strcmp(q->name, "cinco")==0);
    free(q);
    toBegin(p);
    assert(next(p).code == 5);
    assert(next(p).code == 3);
    
    freeMoveToFront(p);
    puts("OK primera parte!"); 
	
	// Insertamos miles de elementos
	int dim=50000;
	p = newMoveToFront(compareStruct);
	for(int i=1; i <= dim; i++) {
		elemType aux = {i, "foo"};
		assert(add(p, aux));
	}
	assert(size(p)==dim);
	aux.code = dim + 1;
    q = get(p, aux);	
    assert(q==NULL);	
	
	aux.code = dim - 10;
	q = get(p, aux);
	assert(q!=NULL);
	assert(q->code == dim-10);
	free(q);
	toBegin(p);
    assert(next(p).code == dim-10);
    assert(next(p).code == 1);
	
	freeMoveToFront(p);
    puts("OK segunda parte!"); 
	return 0;
}