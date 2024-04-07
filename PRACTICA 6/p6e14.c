/*Escribir la función contiene que reciba dos vectores de enteros y la dimensión de cada uno y retorne:
    1 si todos los elementos del primer vector están en el segundo
    2 si todos los elementos del segundo vector están en el primero
    0 en caso contrario
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define FALSE 0
#define TRUE !FALSE
int contiene(int v1[], int dim1, int v2[], int dim2);
int encuentra(int v1[], int v2[], int dim1, int dim2);

int main(void) {

  int v1[] = {1,6,5,3,2};
  int v2[] = {1,2};
  assert(contiene(v1, 5, v2, 2)==2);
  assert(contiene(v2, 2, v1, 5)==1);
  assert(contiene(v1, 1, v2, 2)==1);
  assert(contiene(v1, 0, v2, 2)==1);
  assert(contiene(v1, 5, v2, 0)==2);
  
  int v3[] = {1,2,3,4,5,6};
  assert(contiene(v1, 5, v3, 6)==1);

  int cnt = contiene(v1, 0, v3, 0);
  assert(cnt ==1 || cnt==2);

  int v4[] = { 10, 20, 30, 1, 2};
  assert(contiene(v2, 2, v4, 4)==0);
  assert(contiene(v2, 2, v4, 5)==1);
  assert(contiene(v4, 5, v2, 2)==2);

  int v5[] = {1,1,1,1,1,2,1,2};
  int v6[] = {1,2,3};
  assert(contiene(v5, 8, v6, 3)==1);
  assert(contiene(v6, 3, v5, 8 )==2);

  printf("OK!\n");
  return 0;
}


int encuentra(int v1[], int v2[], int dim1, int dim2){
    int i, j, encontrado;
    encontrado=TRUE;
    i=0;
        while( i < dim1 && encontrado ){
            encontrado = FALSE;
            for(j=0;j<dim2 && !encontrado ;j++){
                if(v1[i]==v2[j])
                    encontrado = TRUE;
            }
            i++;
        }
        return encontrado;
}
int contiene(int v1[], int dim1, int v2[], int dim2){
    if ( encuentra(v1, v2, dim1, dim2) == TRUE )
        return 1;
    if ( encuentra(v2, v1, dim2, dim1) == TRUE )
        return 2;
    else return 0;
}