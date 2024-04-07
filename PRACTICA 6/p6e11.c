/* 	Escribir una función que ordene las filas de una matriz de cualquier tamaño, 
según el valor de una determinada columna. La función recibirá como parámetros la matriz, 
la cantidad de filas, la cantidad de columnas y el número de columna a tomar como clave de ordenación, 
teniendo en cuenta que la primera columna es la columna 1 (uno).
Para ordenar se puede usar el bubble sort ( https://www.geeksforgeeks.org/bubble-sort/ ) o selection sort (https://www.geeksforgeeks.org/selection-sort/ )
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FALSE 0
#define TRUE !FALSE
#define MAXCOL 10
void swap(int v1[], int v2[], int dim);
void ordenar(int cols, int rows, int matriz[][cols], int n_col);

int checkVector(const int v1[], const int v2[], int dim) {
  for(int i=0; i < dim; i++)
    if ( v1[i] != v2[i])
      return 0;
  return 1;
}

int main(void) {
  int m[][MAXCOL] = { {1, 2, 3, 4, 5},
            {6, 2, 8, 9, 10},
            {3, 5, 8, 2, 1},
            {8, 7, 3, 6, 7}};

  int m2[][MAXCOL] = { {1, 2, 3, 4, 5},
            {6, 2, 8, 9, 10},
            {3, 5, 8, 2, 1},
            {8, 7, 3, 6, 7}};
  
  // La matriz no cambia 
  ordenar(5, 4, m, 2);

  for(int i=0; i < 4; i++)
    assert(checkVector(m[i], m2[i], 5));

  ordenar(5, 4, m, 1);
  assert(checkVector(m[0], m2[0], 5));
  assert(checkVector(m[1], m2[2], 5));
  assert(checkVector(m[2], m2[1], 5));
  assert(checkVector(m[3], m2[3], 5));
  
  ordenar(5, 4, m, 3);
  assert(checkVector(m[0], m2[0], 5) || checkVector(m[0], m2[3], 5));
  assert(checkVector(m[1], m2[0], 5) || checkVector(m[1], m2[3], 5));
  assert(checkVector(m[2], m2[1], 5) || checkVector(m[2], m2[2], 5));
  assert(checkVector(m[3], m2[1], 5) || checkVector(m[3], m2[2], 5));

  printf("OK!\n");
  return 0;
}

void swap(int v1[], int v2[], int dim){
    int i;
    for(i=0; i < dim; i++){
        int aux = v1[i];
        v1[i]=v2[i];
        v2[i]=aux;
    }
}

void ordenar(int cols, int rows, int matriz[][cols], int n_col){
    int i=0, swapped;
    while(i<rows-1){
        swapped=FALSE;
        if (matriz[i][n_col-1] > matriz[i+1][n_col-1]){ // si el valor en la columna inferior es mayor, entonces hay q "swapear" las filas.
            swap(matriz[i],matriz[i+1], cols);
            swapped=TRUE;
            }
        if( swapped && i>0 )
            i--;
        else i++;
        }
    return;
    }
