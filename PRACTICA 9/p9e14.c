#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// FUNCIONA PORQUE SOLO CONTIENE PARENTESIS! SINO NO FUNCIONARIA
int apareados(char * s){
    int aux;
    if(*s == 0)
        return 0;

    aux = apareados(s+1);
    if(aux > 0)
        return aux;
    return aux + (*s == '(' ? 1 : -1);
}

