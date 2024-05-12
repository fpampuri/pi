#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

void piramide(int * latas, int * altura){
    int latas_por_nivel = pow(*altura + 1, 2);
    if(*latas < latas_por_nivel)
        return;
    *latas -= latas_por_nivel;
    *altura += 1;
    piramide(latas, altura);
    return;
    }
