#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"
#include <assert.h>

typedef struct nodeBrief {
		int elem;
		int count;
		struct nodeBrief * tail;
	} TNodeBrief;

typedef struct nodeBrief * TListBrief; 

TListBrief comprimeList(TList l){
    if(l == NULL)
        return NULL;
    
    TListBrief newList = comprimeList(l->tail); 

    if(newList == NULL || l->elem < newList->elem){
        TListBrief aux = malloc(sizeof(TNodeBrief));
        aux->elem = l->elem;
        aux->count = 1; // Inicializo la cuenta en 1, dsp veo si sumo
        aux->tail = newList;
        return aux;
    }
    // Si no entró en el if anterior, es porque l-<elem == newList->elem ==> Tengo q sumar
    newList->count++;
    return newList;
}

// Auxiliar para que pase el test con sanitizer
void freeListBrief(TListBrief lb) {
   if ( lb == NULL)
     return;
   freeListBrief(lb->tail);
   free(lb);
}

int main(void) {

  int v[] = {1,1,2,3,3,3,3,3,10,100,100,998};
  TList list = fromArray(v, sizeof(v)/sizeof(v[0]));
  TListBrief bf = comprimeList(list);

  TListBrief aux = bf;
  assert(aux->elem ==1 && aux->count == 2);

  aux = aux->tail;
  assert(aux->elem ==2 && aux->count == 1);

  aux = aux->tail;
  assert(aux->elem ==3 && aux->count == 5);

  aux = aux->tail;
  assert(aux->elem ==10 && aux->count == 1);

  aux = aux->tail;
  assert(aux->elem ==100 && aux->count == 2);

  aux = aux->tail;
  assert(aux->elem ==998 && aux->count == 1);

  aux = aux->tail;
  assert(aux == NULL);

  freeList(list);
  freeListBrief(bf);
  
  printf ("OK!\n");
  return 0;
}