#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"
#include <assert.h>

TList listUnion(TList l1, TList l2){
    if(l1 == NULL && l2 == NULL)
        return NULL;
    
    TList aux = malloc(sizeof(TNode));
    if(l2 == NULL || (l1 != NULL && l1->elem < l2->elem)){
        aux->elem = l1->elem;
        aux->tail = listUnion(l1->tail, l2);
        return aux;
    }
    if(l1 == NULL || l1->elem > l2->elem){
        aux->elem = l2->elem;
        aux->tail = listUnion(l1, l2->tail);
        return aux;
    }
    else{
        aux->elem = l2->elem;
        aux->tail = listUnion(l1->tail, l2->tail);
        return aux;
    }
}


int main(void) {

  int v[] = {1, 4, 5, 6, 7, 8};
  int w[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int x[] = {2, 3, 9};

  TList l1 = fromArray(v, 6);
  TList l2 = fromArray(w, 9);
  TList l3 = listUnion(l1, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, l1);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, NULL);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(NULL, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);
  freeList(l1);
  freeList(l2);
  
  l1 = fromArray(v, 6);
  l2 = fromArray(x, 3);
  l3 = listUnion(l1, l2);
  freeList(l1);
  freeList(l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);


  printf ("OK!\n");
  return 0;
}