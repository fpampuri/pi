#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int head;
    struct node * tail;
} TNode;
typedef TNode * TList;

/*Escribir una función recursiva deleteAll que reciba únicamente dos listas de enteros ordenados
 en forma ascendente (sin repetidos) 
y elimine de la primera lista los elementos que pertenezcan a la segunda lista.
*/
TList deleteAll(TList l1, TList l2){
    if(l1 == NULL || l2 == NULL || l2->head > l1->head)
        return l1;
    if(l1->head < l2->head){
        l1->tail = deleteAll(l1->tail, l2);
        return l1;
    }
    else if(l1->head > l2->head){
        l1 = deleteAll(l1, l2->tail);
        return l1;
    }
    else{
        TList aux = l1->tail;
        free(l1);
        aux = deleteAll(aux, l2->tail);
        return aux;
    }
}
