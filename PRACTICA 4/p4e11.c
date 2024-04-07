// 	Escribir una función que reciba tres parámetros de entrada de tipo entero 
// y que devuelva en su nombre el mayor de ellos. (En 2 líneas)
#include <stdio.h>
#include "getnum.h"

int
maximo(int num1, int num2, int num3) {
   int max1;
    return ((max1 = (num1>num2 ? num1 : num2)) > num3 ? max1 : num3);
}

int main(void){
    int x = getint("Ingrese un numero: ");
    int y = getint("Ingrese un numero: ");
    int z = getint("Ingrese un numero: ");

    printf("%d\n", maximo(x,y,z));
    return 0;
}