// CUENTA LA CANTIDAD DE DIGITOS "CINCO" EN UN NUMERO DECIMAL INGRESADO
// SEPARANDO POR PARTE ENTERA Y PARTE DECIMAL

#include <stdio.h>
#include "getnum.h"
#define EPSILON 0.0001

int main(void)
{
    double num = getdouble("Ingrese un numero real: ");
    int partEnt, cantEntera = 0, cantDecimal = 0;
    num = (num > 0 ? num : (-1)*num);         // toma el valor absoluto del numero para facilitar las operaciones
    partEnt = num;
    while ( partEnt != 0) {
        cantEntera += (partEnt%10) == 5;       // el compilador castea el numero a entero automaticamnte
        partEnt = partEnt / 10;                  // con el fin de realizar la operación modulo,
    }
    num -= (int)num;
    printf("%.20f\n",num);
    while ( num > EPSILON ) {
        num *= 10;
        cantDecimal += (int)num == 5;
        num -= (int)num;
    }
    printf("Hay %d cincos en la parte entera y %d en la parte decimal\n",cantEntera,cantDecimal);
    return 0;
}