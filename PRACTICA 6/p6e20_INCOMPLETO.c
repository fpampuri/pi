/* Escribir una función que compruebe si una solución dada a un Sudoku es correcta sabiendo que:

    -   Un tablero sudoku se compone de una matriz de 9 filas por 9 columnas. 
        A su vez el tablero se subdivide en 9 subcuadrados de 9 casillas cada uno (3x3) NO SUPERPUESTOS 
        (un número en una posición NO puede pertenecer a dos subcuadrados). 

    -   Se debe verificar que todas las casillas contienen un número comprendido entre el 1 y el 9. 
        Si alguna casilla contiene un número menor a 1 o mayor a 9, es incorrecta la matriz.

    -   Por fila, no hay valores repetidos
    -   Por columna, no hay valores repetidos
    -   Por subcuadrado, no hay valores repetidos */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TAMANO 9
#define DIM_SUBMATRIZ 3

// Asumo que el input es una matriz de 9x9
int sudokuValido(const int sudoku[][TAMANO]);
int filaCumple(const int v[]);
int colCumple(const int m[][TAMANO], int col);
int matCumple(int m[][TAMANO], int fil, int col);

int sudokuValido(int sudoku[][TAMANO]){
    int i,j;
    
    // Valido que todo elemento este en el rango deseado
    for(i=0; i<TAMANO; i++)
        for(j=0; j<TAMANO; j++)
            if(sudoku[i][j] < 1 || sudoku[i][j] > 9)
                return 0;
    
    // Chequeo que no haya ningun elemento repetido en ninguna fila.
    for(i=0; i<TAMANO; i++)
        if ( ! filaCumple(sudoku[i]) )
            return 0;

    // Chequeo que no haya ningun elemento repetido en ninguna columna.
    for(j=0; j<TAMANO; j++)
        if( ! colCumple(sudoku, j) )
            return 0;

    for(i=0; i<=6; i += 3)
        for(j=0; j<=6; j += 3)
            if ( ! matCumple(sudoku, i, j)) 
                return 0;
    
    /* Si no retornó, es porque todas las filas, columnas y submatrices cumplen, 
       entonces es una solucion valida. */
    return 1;
}

// la funcion filaCumple() devuelve 1 si no hay repetidos y 0 si los hay.
int filaCumple(const int v[]){
    int i,j;
    for(i=0; i<TAMANO; i++)
        for(j=i+1; j<TAMANO; j++)
            if(v[i] == v[j])
                return 0;
    return 1;
}

// la funcion colCumple() devuelve 1 si no hay repetidos y 0 si los hay.
int colCumple(const int m[][TAMANO], int col){
    int i,k;
    for(i=0; i<TAMANO; i++)
        for(k=i+1; k<TAMANO; k++)
            if(m[i][col] == m[k][col])
                return 0;
    return 1;
}

// la funcion matCumple() devuelve 1 si no hay repetidos y 0 si los hay.
int matCumple(int m[][TAMANO], int fil, int col){
    int i,j, aux;
    int fil_max = fil+2;
    int col_max = col+2;
    for(i=fil; i<=(fil+3); i++){
        for(j=col; j<=(col+3); j++){
            chequearSucesivos(m, i, j, fil_max, col_max);
        }
    }
}

int chequearSucesivos(int m[][TAMANO], int fil, int col, int fil_max, int col_max){
    int i,j, aux;
    aux = m[fil][col];
    for(i=fil; i<=fil_max; i++){
        for(j=col; j<=col_max; j++){
            if(aux == m[i][j])
        }
    }
}