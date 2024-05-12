/* Escribir una función recursiva que reciba como parámetros de entrada
 un vector de enteros y su dimensión, y que devuelva en su nombre la suma de todos sus elementos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sumaVec(const int *v, int dim){
    int suma = 0;
    if(dim == 0)
        return 0;
    suma += *v;
    return suma + sumaVec(v+1, --dim);
}
