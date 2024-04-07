/* Escribir una función armaFilas que recibe una matriz de enteros de N filas y M columnas, y un vector de dimensión N.
La función debe armar los números que se forman con cada fila y guardarlos en el vector.
Si hubiera números negativos o de más de una cifra en una fila, no se completa el armado de ese número, pero se sigue con la próxima fila.
La función retorna en su nombre la dimensión final del vector de números. */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FALSE 0
#define TRUE !FALSE

#define N 4
#define M 5

int armaFilas(int m[][M], int v[]){
    int i, j, numero, cumple, dimV;
    dimV=0;
    i=0;
    while(i<N){
        numero=0;
        cumple=TRUE;

        for(j=0; j<M && cumple ;j++){
            if(m[i][j] < 0 || m[i][j] > 9)
                cumple = FALSE;
            else {
                numero *= 10;
                numero += m[i][j];
            }
        }
        if(cumple)
            v[dimV++] = numero;
        i++;
    }
    return dimV;
}
