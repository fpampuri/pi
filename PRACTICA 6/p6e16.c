/* La función debe retornar 1 si la matriz es "ascendente", -1 si es "descendente" y 0 si no es ascendente ni descendente. 
Se dice que una matriz es ascendente si recorriendola en forma ordenada por filas cada elemento es mayor o igual al anterior, 
En forma análoga se define una matriz descendente.
El recorrido comienza por el elemento [0][0], continúa con el [0][1] y luego de terminar la primera fila 
hace lo mismo con la segunda fila, tercer fila, etc. */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FALSE 0
#define TRUE !FALSE
#define FILS 5
#define COLS 5
#define SIGUE ((esAscendente || esDescendente))
int ordenMatriz(const int m[FILS][COLS]);

int ordenMatriz(const int m[FILS][COLS]){
    int i,j, aux, esAscendente, esDescendente;
    esAscendente=TRUE;
    esDescendente=TRUE;   
    aux=m[0][0];
    //comparo cada pos. con la anterior(aux) porq es mas sencillo que compararlo con la siguiente
    //deja de comparar si deja de crecer o decrecer.
    i=0;
    while(i<FILS && SIGUE){
        for(j=0;j<COLS && SIGUE;j++){
            if(aux < m[i][j] && SIGUE)
                esDescendente=FALSE;

            if(aux > m[i][j] && SIGUE)
                esAscendente=FALSE;
            aux=m[i][j];
        }
        i++;
    }

    if(esAscendente)
        return 1;
    if(esDescendente)
        return -1;
    return 0;
}
