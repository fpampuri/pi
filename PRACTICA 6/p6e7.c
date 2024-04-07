/*Hacer una función que reciba dos parámetros de entrada representando arreglos de números enteros positivos,
 ordenados en forma ascendente y sin elementos repetidos. El último elemento de cada arreglo es -1.
  La función debe devolver en un tercer parámetro de salida un arreglo ordenado con la unión de los dos primeros,
   también terminado en -1.     EJERCICIOS 7 Y 8
   */
  
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "getnum.h"

#define FALSE 0
#define TRUE !FALSE
#define VFINAL -1


enum { IGUAL=0, MENOR, MAYOR};

int compara( int a, int b );
void unionvec(int v1[], int v2[], int resultado[]);

int main(){
    int i;
    int veca[] = { 1, 2, 5, 5, 5, 6, 7, 8, 9, -1};
    int vecb[] = { 4, 5, 5, 6, 7, 9, 9, 10, 11, 11, -1};
    int res[15];
    unionvec(veca, vecb, res);
    int dimRes=sizeof(res)/sizeof(res[0]);
    for ( i = 0; i < dimRes ; i++)
        printf("%d ", res[i]);
    puts("\n");
    return 0;
}
void unionvec(int v1[], int v2[], int resultado[]){   
    int i=0, j=0, k=0;     
    while (!( v1[i] == VFINAL && v2[j] == VFINAL )) {
        while ( v1[i] == v1[i+1] )
            i++;
        while (v2[j] == v2[j+1])
            j++;
        switch( compara(v1[i],v2[j]) ){
            case IGUAL: resultado[k] = v1[i];
                        i++; j++;
                        break;
            case MAYOR: resultado[k] = v2[j];
                        j++;
                        break;
            case MENOR: resultado[k] = v1[i];
                        i++;
                        break;
        }
        k++;
    }
    resultado[k] = VFINAL;
}

int compara( int a, int b ){
    if (a == b)
        return IGUAL;
    if (a == VFINAL)
        return MAYOR;
    if (b == VFINAL)
        return MENOR;
    if (a > b)
        return MAYOR;
    return MENOR;
}