/* Dado un arreglo lineal de números reales, cuyo indicador de fin de elementos es cero, 
escribir una función para obtener la mayor diferencia entre dos elementos consecutivos. (En no más de 5 líneas).
 Tener en cuenta que los números pueden ser negativos.
 En caso de que el vector tenga un solo elemento deberá retornar como diferencia el valor cero
*/

#include <stdio.h>
#include <stdlib.h>
#include "getnum.h"
#include <math.h>

double dif(int dim, double vec[dim]); 
int main(){
    double vector[] = {1.0, 5.1, 6.4, 6.5, 56.4, 150.9, 0};
    int size = sizeof(vector)/sizeof(vector[0]);
    double diferencia = dif(size, vector);
    printf("La diferencia mayor es %lf\n", diferencia);
    return 0;
}

double dif(int dim, double vec[dim]){
    double dif, difMayor=0;
    if ( dim == 1)
        return 0;
    for ( int i=0 ; vec[i+1] != 0 && i < dim ; i++ ){
        dif = fabs(vec[i]-vec[i+1]);
        if ( dif > difMayor )
            difMayor = dif;
    }
    return difMayor;
}