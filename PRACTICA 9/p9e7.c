/* */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int busquedaBinaria(const int datos[], int dim, int n){
    if(dim == 0)
        return 0;

    // chequeo que el numero este dentro del rango de busqueda
    if( *datos > n || n > datos[dim-1])
        return 0;
    

    return (datos[0] == n || datos[dim-1] == n) || busquedaBinaria(datos + 1, dim - 2, n);
}
