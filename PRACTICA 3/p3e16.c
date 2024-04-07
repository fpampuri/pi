// PASAJE DE DECIMAL A BINARIO
#include <stdio.h>
#include "getnum.h"

int main(){
    int decimal, binario=0, binarioInvertido=0;
    decimal = getint("Ingrese un numero decimal: ");
    while ( decimal != 0) {
        binario = binario*10 + (decimal%2);
        decimal /= 2;
    }
    printf("%d\n",binario);
    while ( binario != 0 ) {
        binarioInvertido = binarioInvertido*10 + (binario%10);
        binario /= 10;
    }
    printf("El binario del numero ingresado es %d\n",binarioInvertido);
    return 0;
}