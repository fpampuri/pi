#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pampulib.h"

#define ESTRELLA 1
#define ROWS 20
#define COLS 80


void generarCielo(int cielo[][COLS], int rows, int cols){
    int i,j;
    for( i=0 ; i<rows ; i++){
        for( j=0 ; j<cols ; j++)
            cielo[i][j]=randInt(0,5);
    }
}
void hayEstrella(int rows, int cols, const int cielo[][COLS], int grafico[][COLS]){
    
    int i, j, k, t, suma;

    for( i=1 ; i < rows - 1 ; i++){
        for( j=1 ; j < cols-1 ; j++){
            
            for( k=-1 ; k<=1 ; k++){
                for( t=-1 ; t<=1 ; t++){
                    suma += cielo[i+k][j+t];
                }
            }
            if (suma/9 > 10)
                grafico[i][j]=ESTRELLA;
        }
    }
}

void representacion(int rows, int cols, int grafico[][COLS]){
    int i,j;
    for( i=0 ; i < rows ; i++){
        for( j=0 ; j < cols ; j++){
            if (grafico[i][j] == ESTRELLA)
                printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}

int main(){
    int sky[ROWS][COLS];
    int grafico[ROWS][COLS];
    int rows = 10, cols = 10;
    generarCielo(sky, rows, cols);
    hayEstrella(rows, cols, sky, grafico);
    representacion(rows, cols, grafico);
    return 0;
}

