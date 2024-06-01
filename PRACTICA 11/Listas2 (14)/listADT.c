#include "listADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define BLOCK 5

typedef struct node{
    elemType elem;
    struct node * tail;
} TNode;
typedef TNode * TList;

typedef struct listCDT{
    TList firstIn;
    TList lastIn;
    TList firstAsc;
    TList iteradorIn;
    TList iteradorAsc;
    compare cmp;
} listCDT;

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

listADT newList(compare cmp){
    listADT aux = calloc(1, sizeof(listCDT));
    aux->cmp = cmp;
    return aux;
}

static TList addAsc(TList listAsc, elemType elem, compare cmp, int * ok){
    int c;
    if(listAsc == NULL || (c = cmp(listAsc->elem, elem)) > 0){
        TList aux = malloc(sizeof(TNode));
        aux->elem = elem;
        aux->tail = listAsc;
        *ok = 1;
        return aux;
    }
    if(c < 0)
        listAsc->tail = addAsc(listAsc->tail, elem, cmp, ok);
    return listAsc;
}

void add(listADT list, elemType elem){
    int ok = 0;
    list->firstAsc = addAsc(list->firstAsc, elem, list->cmp, &ok);
    if(ok){
        TList aux = calloc(1, sizeof(TNode));
        aux->elem = elem;
        if(list->firstIn == NULL)
            list->firstIn = aux;
        else list->lastIn->tail = aux;
        list->lastIn = aux;
    }
}

// Iterador de la lista que va en orden de inserción
void toBegin(listADT list){
    list->iteradorIn = list->firstIn;
}
int hasNext(listADT list){
    return list->iteradorIn != NULL;
}
elemType next(listADT list){
    if(!hasNext(list)){
        exit(1);
    }
    elemType aux = list->iteradorIn->elem;
    list->iteradorIn = list->iteradorIn->tail;
    return aux;
}

// Iterador de la lista que va en orden ascendente
void toBeginAsc(listADT list){
    list->iteradorAsc = list->firstAsc;
}
int hasNextAsc(listADT list){
    return list->iteradorAsc != NULL;
}
elemType nextAsc(listADT list){
    if(!hasNextAsc(list)){
        exit(1);
    }
    elemType aux = list->iteradorAsc->elem;
    list->iteradorAsc = list->iteradorAsc->tail;
    return aux;
}


void freeListRec(TList list){
    if(list == NULL)
        return;
    freeListRec(list->tail);
    free(list);
}
void freeList(listADT list){
    freeListRec(list->firstIn);
    freeListRec(list->firstAsc);
    free(list);
}


static int comp (elemType e1, elemType e2) {
    return e1-e2;
}

int
main(void) {
   listADT c = newList(comp); // una lista, en este caso de int
   toBegin(c);
   assert(!hasNext(c));
   assert(!hasNextAsc(c));
   add(c, 3);   add(c, 1);   add(c, 5);   add(c, 2);
   toBegin(c);         // iterador por orden de insercià¸£à¸“n
   int n = next(c);    // n = 3
   assert(n==3);
   n = next(c);        // n = 1
   assert(n==1);
  
   toBeginAsc(c);      // iterador por orden ascendente

   assert(hasNext(c));
   assert(hasNextAsc(c));

   n = nextAsc(c);     // n = 1
   assert(n==1);

   n = next(c);        // n = 5
   assert(n==5);

   n = next(c);        // n = 2
   assert(n==2);
   assert(!hasNext(c)); 

   n = nextAsc(c);     // n = 2
   assert(n==2);

   n = nextAsc(c);     // n = 3
   assert(n==3);

   n = nextAsc(c);     // n = 5
   assert(n==5);

   assert(! hasNextAsc(c));

   freeList(c);

   puts("OK!");

   return 0;
}