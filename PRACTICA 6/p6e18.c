/* Nota 2: Todas las filas tienen sus elementos ordenados de manera no descendente (cada elemento es menor o igual al siguiente)
La función debe retornar:
    1: si la primera matriz es amiga de la segunda
    2: si la segunda matriz es amiga de la primera
    0: en cualquier otro caso
Si ambas son amigas, la función puede retornar 1 ó 2.
*/

// POR ALGUN MOTIVO QUE DESCONOZCO, FALLA EN EL ASSERT DE LA LINEA 35.
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FALSE 0
#define TRUE !FALSE

#define COLS 4

enum {MENOR=-1, IGUAL, MAYOR};

int sonAmigas(const int m1[][COLS], int fils1, const int m2[][COLS], int fils2);
int esAmiga(const int m1[][COLS], int fils1, const int m2[][COLS], int fils2);
int esFilaAmiga(const int f1[], const int f2[]);
int compara(int a, int b);

int 
main(void)
{
  int m1[][COLS] = {{0,1,2,3}, {4,4,5,6}, {7,8,8,9}};
  int m2[][COLS] = {{0,1,2,3}, {-3,7,8,9}, {-1,3,4,7}, {4,5,6,8}};
  int m3[][COLS] = {{2,3,3,7}};
  assert(sonAmigas(m1,3,m2,4)==1);
  assert(sonAmigas(m1,1,m2,4)==1);
  assert(sonAmigas(m1,2,m2,4)==1);
  assert(sonAmigas(m1,2,m2,2)==0);
  assert(sonAmigas(m2,4,m1,3)==2);
  assert(sonAmigas(m1,3,m3,1)==0);
  assert(sonAmigas(m3,1,m1,3)==0);
  int res = sonAmigas(m1,3,m1,3);
  assert(res==1 || res==2);
  
  printf("OK !\n");

  return 0;
}

/* Creo la funcion auxiliar "esAmiga" para ver si una matriz m1 es amiga de una matriz m2 para no 
   escribir dos veces el mismo codigo largo, analogamente, creo la funcion "esFilaAmiga" */

/* Una matriz es amiga de otra si todas las filas de la primera matriz 
   son amigas de alguna fila de la segunda matriz

   Una fila es amiga de otra si todos los elementos de una fila están incluidos en otra.*/

int compara(int a, int b){
    if(a==b)
        return IGUAL;
    if(a>b)
        return MAYOR;
    return MENOR;
}

int esFilaAmiga(const int f1[], const int f2[]){
    int filas_amigas, i,j;
    filas_amigas = TRUE;
    i=0; j=0;
    while( (i < COLS && j < COLS) && filas_amigas ){
        if( (i == 0) || (f1[i] != f1[i-1]) ){   // Si es igual al num. anterior, no hace falta q lo analice
            switch( compara(f1[i], f2[j]) )
            {
                case MENOR: filas_amigas = FALSE; break;
                case MAYOR: j++; break;
                case IGUAL: i++; j++; break;
            }
        }
        i++;
    }
    return filas_amigas;
}


// la función "esAmiga" va a retornar 1 y si una matriz m1 es amiga de una matriz m2, y 0 en caso contrario.
int esAmiga(const int m1[][COLS], int fils1, const int m2[][COLS], int fils2){
    int i,j, existeFilaAmiga;
    existeFilaAmiga = TRUE;
    for(i=0; i < fils1 && existeFilaAmiga ; i++){
        existeFilaAmiga = FALSE;

        for(j=0; j<fils2 && !existeFilaAmiga; j++){
            existeFilaAmiga = esFilaAmiga(m1[i], m2[j]);
        }
    }
    return existeFilaAmiga;
}

int sonAmigas(const int m1[][COLS], int fils1, const int m2[][COLS], int fils2){
    if (esAmiga(m1, fils1, m2, fils2))
        return 1;
    if (esAmiga(m2, fils2, m1, fils1))
        return 2;
    return 0;
}