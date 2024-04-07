#include <stdio.h>
#include "getnum.h"


#define MAXIMO2(num1, num2, max) max=((num1) > (num2) ? (num1) : (num2))
#define MAXIMO3(num1, num2, num3, max) (max=((MAXIMO2(num1,num2,max)) > (num3) ? max : (num3)))

int main(void){
    int max;
    int x = getint("Ingrese un numero 1: ");
    int y = getint("Ingrese un numero 2: ");
    int z = getint("Ingrese un numero 3: ");
    MAXIMO3(x,y,z,max);
    printf("El maximo es %d\n", max);
    return 0;
}