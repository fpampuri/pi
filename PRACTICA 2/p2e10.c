#include <stdio.h>
#include "getnum.h"

int main() {
    int seg;
    printf("Escriba una cantidad de segundos\n");
    seg = getint("");
    printf("%d segundos equivalen a:\n%.2f horas\n%.2f minutos\n", seg, seg/3600.0, seg/60.0);
    return 0;
}