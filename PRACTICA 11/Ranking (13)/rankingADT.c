#include "rankingADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define BLOCK 5

/* typedef struct element{
    elemType elem;
    size_t calls;
} element;
 */
typedef struct rankingCDT{
    elemType * ranking;
    size_t sizeR;
    compare cmp;
} rankingCDT;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

rankingADT newRanking(elemType elems[], size_t dim, compare cmp){
    rankingADT r = calloc(1, sizeof(rankingCDT));
    r->cmp = cmp;
    if(dim > 0){
        r->sizeR = dim;
        r->ranking = calloc(dim, sizeof(elemType));
        for(int i=0; i<dim; i++){
            r->ranking[i] = elems[i];
        }
    }
    return r;
}


static void upRanking(elemType * vec, int idx){
    elemType aux = vec[idx-1];
    vec[idx-1] = vec[idx];
    vec[idx] = aux;
}
void addRanking(rankingADT r, elemType elem){
    int i=0;
    for(i; i < r->sizeR; i++){
        if(r->cmp(r->ranking[i], elem)== 0){
            if(i != 0)
                upRanking(r->ranking, i);
            return;
        }
    }
    // el elemento no estaba en el ranking
    if(r->sizeR % BLOCK == 0)
        r->ranking = realloc(r->ranking, (r->sizeR + BLOCK)*sizeof(elemType));
    r->ranking[i] = elem;
    r->sizeR++;
}


size_t size(const rankingADT r){
    return r->sizeR;
}

int getByRanking(rankingADT r, size_t n, elemType * elem){
    if(n > r->sizeR || n <= 0)
        return 0;
    *elem = r->ranking[n-1];
    if(n > 1)
        upRanking(r->ranking, n-1);
    return 1;
}


elemType * getTopRanking(const rankingADT r, size_t * top){
    size_t greatest = *top < r->sizeR ? *top : r->sizeR;
    *top = greatest;
    if( greatest > 0){
        elemType * resp = malloc(greatest*sizeof(elemType));
        for(int i = 0; i < greatest; i++){
            resp[i] = r->ranking[i];
        }
        return resp;
    }
    return NULL;
}


int contains(rankingADT r, elemType elem){
    int i;
    for(i=0; i < r->sizeR; i++){
        if(r->cmp(r->ranking[i], elem) == 0){
            if(i>0)
                upRanking(r->ranking, i);
            return 1;
        }
    }
    return 0;
}


void downByRanking(rankingADT r, size_t n){
    if(n > 0 && n < r->sizeR){
        upRanking(r->ranking, n);
    }
    return;
}

void freeRanking(rankingADT r){
    free(r->ranking);
    free(r);
}


int position(const rankingADT r, elemType elem){
    int i;
    for(i=0; i < r->sizeR; i++){
        if(r->cmp(r->ranking[i], elem) == 0)
            return i+1;
    }
    return 0;
}