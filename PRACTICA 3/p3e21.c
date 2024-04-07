#include <stdio.h>
#include "getnum.h"

int main(void) {
    int original, numero, inverso = 0;
    numero = getint("Ingrese un numero entero: ");
    original = numero;
    while (numero != 0) {
        inverso = inverso*10 + (numero%10);
        numero /= 10;
    }
        printf("El numero %d%ses capicua.\n", original, original == inverso ? " " : " no ");
    return 0;
}