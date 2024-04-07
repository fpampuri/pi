//DIBUJAR UN CUADRADO DE LADO VARIABLE
#include <stdio.h>
#include "getnum.h"

int main() {
    int i, sq, lado = getint("Ingrese el valor del lado del cuadrado: ");
    sq = lado*lado;
    for (i=1; i<=sq; i++) {
        printf("%s", i%lado == 0 ? "*\n" : "*");
    }
    return 0;
}