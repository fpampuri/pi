#include <stdio.h>
#include <math.h>
#include "getnum.h"

#define EPSILON 0.0000001
// 1 + x + x2 / 2! + x3 / 3! + ....... 

double epowx(double x)
{
    double factorial=1;
    double valor, anterior, potX;
    int termino=1;
    if ( x < 0 )
        return -1;
    potX = x;
    valor = 1;
    anterior = 0;
    while ((valor - anterior) > EPSILON)
    {
        anterior = valor;
        valor += potX / factorial;
        potX *= x;
        termino++;
        factorial *= termino;
    }
    return valor;
}

int main() {
    double x = getint("Ingrese un numero: ");
    double aprox = epowx(x);
    double real = exp(x);
    printf("aproximacion: %.6f, real: %.6f", aprox, real);
    return 0;
}