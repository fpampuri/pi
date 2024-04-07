//	Escribir una función que reciba dos parámetros de entrada de tipo entero
// y devuelva en su nombre un número aleatorio entre ambos números. (En una línea)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define EPSILON 0.0001

int randomizer(int top, int bot) {
    return bot + rand()%(top-bot+1);
}

double potencia(double base, int exponente)
{
    int signo, i;
    double contador = base;
    if (fabs(base) < EPSILON && exponente <= 0 ) // me elimino el "0/0" y el "0^0"
        return -1;
    if (exponente == 0) //si el exponente es 0, devuelvo 1 automaticamente
        return 1;
    signo = exponente > 0; //utilizo el flag signo para ver si el exp es positivo o negativo
    exponente = abs(exponente);
    for ( i=1 ; i<exponente ; i++ )
        contador *= base; // multiplico tantas veces como el exponente indique
    return ( signo ? contador : (1.0/contador) ); 
}
