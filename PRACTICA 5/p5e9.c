/* Escribir un programa (en no más de 15 líneas) para encontrar raíces de funciones en un intervalo dado. 
Se deberá recorrer el intervalo a incrementos de 0.001,
evaluando la función en cada paso y escribiendo por salida estándar los puntos que son raíces. 
Los extremos del intervalo serán de tipo real y su valor estará dado por constantes del programa. 

Tener en cuenta no sólo el caso en el que el resultado de evaluar la función sea cero, 
sino también aquellos puntos en los cuales la función cambia de signo. (EJERCICIO 9)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "getnum.h"

#define INCREMENTO 0.001
#define EPSILON 0.0001

double funcion(double x);

int main(){
    double eval, anterior = 0, izq = -100, der = 100;

    for( ; izq <= der ; izq += INCREMENTO ) {
        eval = funcion(izq);
        if (fabs(eval) < EPSILON || (anterior*eval) < 0)
            printf("Raiz en %g\n",izq);
        anterior = eval;
    }

    return 0;
}


double funcion(double x) {
    return sqrt(x) + exp(x);
}
