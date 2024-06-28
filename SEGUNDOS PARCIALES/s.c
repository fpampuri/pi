#include "s.h"
#include <assert.h>
#define BLOCK 5
typedef struct node{
  elemType elem;
  struct node * tail;
} TNode;
typedef TNode * TList;
 
typedef struct dataCDT{
  TList list;
  size_t count;
  compare cmp;
} dataCDT;
 
// Recibe como parametro una funcion que sirve para comparar elementos.
dataADT newData(compare cmp){
  dataADT data = malloc(sizeof(dataCDT));
  data->list = NULL;
  data->count = 0;
  data->cmp = cmp;
  return data;
}
 
static TList addRec(TList list, elemType elem, compare cmp, int * ok){
  int c;
  if(list == NULL || (c = cmp(list->elem, elem)) > 0){
    TList aux = malloc(sizeof(TNode));
    aux->elem = elem;
    aux->tail = list;
    *ok = 1;
    return aux;
  }
  if(c < 0)
    list->tail = addRec(list->tail, elem, cmp, ok);
  return list;  
}
int addElement(dataADT data, elemType elem){
  int ok = 0;
  data->list = addRec(data->list, elem, data->cmp, &ok);
  if(ok)
    data->count++;
  return ok;
}
 
static TList deleteRec(TList list, elemType elem, compare cmp, int * ok){
   char c;
  if(list == NULL || (c = cmp(list->elem, elem)) > 0)
    return list;
  if(c < 0){
    list->tail = deleteRec(list->tail, elem, cmp, ok);
    return list;
  }
  else{
    TList aux = list->tail;
    free(list);
    *ok = 1;
    return aux;
  }
}
 
int deleteElement(dataADT data, elemType elem){
  int ok = 0;
  data->list = deleteRec(data->list, elem, data->cmp, &ok);
  if(ok)
    data->count--;
  return ok;
}

size_t countElement(const dataADT data){
    return data->count;
}
 
elemType * elems(const dataADT data, int (*filter)(elemType), size_t * dim){
  elemType * elems = NULL;
  *dim = 0;
  TList aux = data->list;
  while(aux != NULL){
    if(filter(aux->elem)){
      if(*dim % BLOCK == 0)  // Agrego memoria si hiciera falta
        elems = realloc(elems, (*dim + BLOCK)*sizeof(elemType));
      elems[*dim] = aux->elem; 
      (*dim)++;
    }
    aux = aux->tail;
  }
  elems = realloc(elems, (*dim)*sizeof(elemType));
  return elems;
}

int even(int n) {
return n % 2 == 0;
}
int main(void) {
dataADT data = newData(even); // Almacenaremos enteros ordenados en forma ascendente
assert(addElement(data, 10) == 1);
assert(addElement(data, 10) == 0);
assert(addElement(data, 1) == 1);
assert(addElement(data, 100) == 1);
assert(addElement(data, 5) == 1);
assert(addElement(data, 15) == 1);
assert(addElement(data, 20) == 1);
assert(countElement(data) == 6);
size_t dim;
int * v = elems(data, even, &dim);
assert(dim == 3);
assert(v[0] == 10 && v[1] == 20 && v[2] == 100);
free(v);
assert(countElement(data) == 6);
assert(deleteElement(data, 20) == 1);
assert(countElement(data) == 5);
assert(deleteElement(data, 20) == 0);
v = elems(data, even, &dim);
assert(dim == 2);
assert(v[0] == 10 && v[1] == 100);
free(v);
return 0;
}