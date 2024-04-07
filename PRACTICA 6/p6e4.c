/*Escribir una función que reciba un vector desordenado de números enteros y su dimensión,
 y construya otro vector eliminando los valores repetidos. 
La función deberá retornar en su nombre la dimensión del nuevo vector 
(La función solicitada  no debe superar las 10 líneas).
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "getnum.h"

#define FALSE 0
#define TRUE !FALSE
int noRepeat(const int vec[], int dim, int vecNuevo[])
{
    int dimNueva=0;
    for ( int i=0 ; i < dim ; i++) {
        int rep = FALSE;
        for ( int j=0 ; j < dimNueva && rep == FALSE; j++ ){
            if (vec[i] == vecNuevo[j]) 
                rep = TRUE;
        }
        if ( !rep ) {
            vecNuevo[dimNueva] = vec[i];
            dimNueva++;
        }
    }
    return dimNueva;
}

    int main(void) {
  int v[] = { 3, 5, 1, 3, -3, 3, 5, 1};
  int res[20];
  int dimRes;

  dimRes = noRepeat(v, 0, res);
  assert(dimRes==0);

  dimRes = noRepeat(v, 1, res);
  assert(dimRes==1);
  assert(res[0]==3);

  dimRes = noRepeat(v, 2, res);
  assert(dimRes==2);
  assert(res[0]==3);
  assert(res[1]==5);

  dimRes = noRepeat(v, 4, res);
  assert(dimRes==3);
  assert(res[0]==3);
  assert(res[1]==5);
  assert(res[2]==1);


  dimRes = noRepeat(v, 8, res);
  assert(dimRes==4);
  assert(res[0]==3);
  assert(res[1]==5);
  assert(res[2]==1);
  assert(res[3]==-3);

  for (int i=0; i < 8; i++)
     v[i] =10;
  dimRes = noRepeat(v, 8, res);
  assert(dimRes==1);
  assert(res[0]==10);

  for (int i=0; i < 8; i++)
     v[i] =i;
  dimRes = noRepeat(v, 8, res);
  assert(dimRes==8);
  for (int i=0; i < 8; i++)
    assert(res[i]==i);

  puts("OK!");
  return 0;
}
