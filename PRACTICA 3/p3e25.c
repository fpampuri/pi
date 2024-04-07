// Escriba un programa que lea de entrada estándar un número entero positivo 
// y calcule la cantidad de bits en ‘1’ que contiene.

#include <stdio.h>
#include "getnum.h"

int main(void)
{
    int num, cantUnos=0;
    while ( (num = getint("Ingrese un entero positivo: ")) < 0 ) // me aseguro que igresen un entero positivo
        puts("Debe ingresar un numero entero positivo");
    
    while ( num != 0 ) {
        cantUnos += (num % 2);
        num /= 2;
    }
    printf("La cantidad de unos en la representacion binaria es %d\n", cantUnos);
    return 0;
}