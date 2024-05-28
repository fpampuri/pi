#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "5_imaginarios.h"

typedef struct imagCDT{
    double real;
    double imag;
} imaginario;

imagADT nuevoIm(double real, double imag){
    imagADT z = malloc(sizeof(imaginario));
    z->real = real;
    z->imag = imag;
    return z;
}

double parteReal(imagADT z){
    return z->real;
}

double parteImag(imagADT z){
    return z->imag;
}

imagADT suma(imagADT z, imagADT w){
    imagADT p = malloc(sizeof(imaginario));
    p->real = z->real + w->real;
    p->imag = z->imag + w->imag;
    return p;
}

imagADT resta(imagADT z, imagADT w){
    imagADT p = malloc(sizeof(imaginario));
    p->real = z->real - w->real;
    p->imag = z->imag - w->imag;
    return p;
}

imagADT mult(imagADT z, imagADT w){
    imagADT p = malloc(sizeof(imaginario));
    p->real = (z->real * w->real) + (z->imag * w->imag)*(-1);
    p->imag = (z->real * w->imag) + (z->imag * w->real);
    return p; 
}

void liberaIm(imagADT z){
    free(z);
}

imagADT conjugado(imagADT z){
    imagADT p = malloc(sizeof(imaginario));
    p->real = z->real;
    p->imag = z->imag*(-1);
    return p;
}

double norma(imagADT z){
    return sqrt(z->real*z->real + z->imag*z->imag);
}

int main() {
    // Crear dos números complejos
    imagADT c1 = nuevoIm(2.0, 3.0);
    imagADT c2 = nuevoIm(4.0, 5.0);

    // Obtener y mostrar la parte real e imaginaria de c1
    printf("Parte real de c1: %f\n", parteReal(c1));
    printf("Parte imaginaria de c1: %f\n", parteImag(c1));

    // Sumar c1 y c2
    imagADT result = suma(c1, c2);

    // Mostrar el resultado de la suma
    printf("Resultado de la suma: %f + %fi\n", parteReal(result), parteImag(result));

    // Multiplicar c1 y c2
    imagADT result2 = mult(c1, c2);

    // Mostrar el resultado de la suma
    printf("Resultado de la multiplicacion: %f + %fi\n", parteReal(result2), parteImag(result2));

    printf("Norma de c1 = %f\n", norma(c1));
    return 0;
}