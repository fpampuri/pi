/* 	Escribir una función recursiva productoEsc que reciba tres parámetros de entrada
 representando dos vectores de números reales de igual tamaño y su dimensión.
  La función debe regresar en su nombre el producto escalar de los vectores recibidos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double productoEsc(const double v1[], const double v2[], int dim){
    double suma = 0;
    if(dim == 0)
        return 0;
    suma = (*v1) * (*v2);
    return suma + productoEsc(v1+1, v2+1, --dim);
}
