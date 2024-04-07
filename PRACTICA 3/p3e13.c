// DIBUJAR UN CUADRADO DE LADO VARIABLE CON DOS CICLOS
#include <stdio.h>
#include "getnum.h"

int main() {
    int i,j, lado = getint("Ingrese el valor del lado del cuadrado: ");
   for (j = 0; j < lado; j++) {
        for( i = 0; i < lado; i++)
        putchar('*');
        putchar('\n');
    }
    return 0;
}