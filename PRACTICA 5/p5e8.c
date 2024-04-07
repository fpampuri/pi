/* La función floor puede ser utilizada para redondear un número a una cantidad específica de lugares decimales. 
Por ejemplo,  floor( x * 100 + .5 ) / 100  redondea x a la posición de los centésimos.

a) Escribir una función redondeo que reciba dos parámetros de entrada correspondientes al número a redondear 
y la cantidad de cifras decimales que se desean, y que devuelva en su nombre el número redondeado (en no más de 5 líneas). */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "getnum.h"

double redondeo(double num, int cifras) {
    int i, factor=1;
    for (i=0 ; i < cifras ; i++) {
        factor *= 10;
    }
    return ( floor ( (num * factor) + 0.5 ) / factor );
}

int menu() {
    puts("1) Redondear al entero mas cercano");
    puts("2) Redondear a la décima mas cercana");
    puts("3) Redondear a la centésima mas cercana");
    puts("4) Redondear a la milesima mas cercana");
    int opcion = getint("\nElija una opción: ");
    return opcion;
}

int main() {
    double resp, numero = getfloat("Ingrese un numero: ");
    do {
    switch(menu()) {
        case 1: resp=redondeo(numero,0); break;
        case 2: resp=redondeo(numero,1); break;
        case 3: resp=redondeo(numero,2); break;
        case 4: resp=redondeo(numero,3); break;
        default:
            resp = 0;
            puts("\nElija una opcion valida");
    }
    }
    while ( resp == 0);
    printf("%.3f\n",resp);
    return 0;
}