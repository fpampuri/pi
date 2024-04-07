#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "getnum.h"
#include <time.h>

#define FALSE 0
#define TRUE !FALSE

void desordenar(int v[], int dim){
    srand(time(NULL));
    int i,aux, random;
    for( i = 0 ; i < dim ; i++) {
        random = (rand() % dim) + 1;
        aux = v[i];
        v[i] = v[dim-random];
        v[dim-random] = aux;
    }
    return;
}

int main(void){
    int vector[] = {1,2,3,4,5,6,7,8,9,10};
    int dim = sizeof(vector)/sizeof(vector[0]);
    for (int i = 0; i < dim ; i++) {
        printf("%d ",vector[i]);
    }
    printf("\n");
    desordenar(vector, dim);
    for (int i = 0; i < dim ; i++) {
        printf("%d ",vector[i]);
    }
    printf("\n");
    return 0;
}