#include "bagADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define BLOCK 5

struct value{
    elemType elem;
    size_t amount;
};

typedef struct bagCDT{
    struct value * vec;
    size_t cantElem;
    size_t memRes;
    cmp fnCmp;
} bag;


bagADT newBag(cmp fnCmp){
    bagADT aux = calloc(1, sizeof(bag));
    aux->fnCmp = fnCmp;
    return aux;
}

static int isEmptyBag(bagADT bag){
    return bag->cantElem == 0;
}

unsigned int add(bagADT bag, elemType elem){
        for(int i=0; i<bag->cantElem; i++){
            if(bag->fnCmp((bag->vec[i]).elem, elem) == 0){
                return ++((bag->vec[i]).amount);
            }
        }
        if(bag->cantElem == bag->memRes){
            bag->memRes += BLOCK;
            bag->vec = realloc(bag->vec, bag->memRes*sizeof(struct value));
        }
        bag->vec[bag->cantElem++].elem = elem;
        return ++(bag->vec[bag->cantElem]).amount; 
}

unsigned int count(const bagADT bag, elemType elem){
    for(int i=0; i<bag->cantElem; i++){
        if(bag->fnCmp((bag->vec[i]).elem, elem) == 0){
            return (bag->vec[i]).amount;
        }
    }
    return 0;
}

unsigned int size(const bagADT bag){
    return bag->cantElem;
}

unsigned int deleteFromBag(bagADT bag, elemType elem){
    int i;
    for(i=0; i<bag->cantElem; i++){
        if(bag->fnCmp(bag->vec[i].elem, elem)){
            // si solo hay una aparicion, libero y borro del vector
            if(bag->vec[i].amount == 1){
                bag->vec[i] = bag->vec[--bag->cantElem];
                return 0;
            }
            return ((bag->vec[i]).amount)--;
        }
    }
    return 0;
}

elemType mostPopular(bagADT bag){
    if(bag->cantElem == 0)
        exit(1);
    elemType mostPopular;
    int aux = 0;
    for(int i=0; i<bag->cantElem; i++){
        if(bag->vec[i].amount > aux){
            aux = bag->vec[i].amount;
            mostPopular = bag->vec[i].elem;
        }
    }
    return mostPopular;
}