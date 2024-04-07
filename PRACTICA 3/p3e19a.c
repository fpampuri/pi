// CUENTA LA CANTIDAD DE DIGITOS "CINCO" EN UN NUMERO INGRESADO

#include <stdio.h>
#include "getnum.h"

int main(void)
{
    int num, cantCincos = 0;
    num=getint("Ingrese un numero ");
    while ( num != 0) {
    cantCincos += ((num % 10) == 5);
    num /= 10;
    }
    printf("La cantidad de digitos CINCO en el numero ingresado es de %d\n",cantCincos);
    return 0;
}