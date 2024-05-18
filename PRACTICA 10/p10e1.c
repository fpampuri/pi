/*Escribir una función recursiva sumAll que reciba 
una lista de enteros y retorne la suma de sus elementos*/

/*Escribir una función recursiva odds que reciba una lista de enteros
 y retorne 1 si todos sus elementos son impares, y cero si no.*/

#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"
#include <assert.h>



int sumAll(TList l){
    if(l == NULL)
        return 0;
    return l->elem + sumAll(l->tail);
}

int odds1(const TList l){
    if(l == NULL)
        return 1;
    return l->elem % 2 && odds1(l->tail);
}

int odds2(const TList l){
    if(l == NULL)
        return 0;
    return l->elem % 2 && odds1(l->tail);
}

