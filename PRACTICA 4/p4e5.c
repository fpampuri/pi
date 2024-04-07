//	Escribir una macro MAXIMO2 que recibiendo tres parámetros, asigne al tercer parámetro el mayor
//de los dos primeros. Utilizarla en un programa para verificar su correcto funcionamiento. (En no más de 5 líneas)

#include <stdio.h>
#include "getnum.h"


#define MAXIMO2(num1, num2, max) int max=((num1) > (num2) ? num1 : num2)

int main(void){
    int x = getint("Ingrese un numero 1: "), y = getint("Ingrese un numero 2: ");
    MAXIMO2(x,y,rta);
    printf("El maximo es %d\n", rta);
    return 0;
}