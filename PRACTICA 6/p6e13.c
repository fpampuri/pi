#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define DIMMAX 4
int suma(int i, int j, int dim, int m1[dim][dim], int m2[dim][dim]);
void prod(int dim, int m1[dim][dim], int m2[dim][dim], int res[dim][dim]);

int main(void) {

  int m1[DIMMAX][DIMMAX] = {
      { 1, 2, 3, 4},
      {11,12,13,14},
      {21,22,23,24},
      {31,32,33,34},
      };

  int m2[DIMMAX][DIMMAX] = {
      { 2, 1, 3, 4},
      { 3, 4, 5, 2},
      { 2, 5,10,11},
      {21,12,13,14},
      };

  int ceros[DIMMAX][DIMMAX] ={{0}};

  int m3[DIMMAX][DIMMAX];

  prod(DIMMAX, m1, ceros, m3);

  for(int i=0; i < DIMMAX; i++) {
    for(int j=0; j < DIMMAX; j++)
      assert(m3[i][j]==0);
  }

  // Ahora ceros para a ser I
  for(int i=0; i < DIMMAX; i++) {
    ceros[i][i] = 1;
  }
  prod(DIMMAX, m1, ceros, m3);
  for(int i=0; i < DIMMAX; i++) {
    for(int j=0; j < DIMMAX; j++)
      assert(m3[i][j]==m1[i][j]);
  }

  int res[][DIMMAX] = {
    {98,72,95,97},
    {378,292,405,407},
    {658,512,715,717},
    {938,732,1025,1027}
  };

  prod(DIMMAX, m1, m2, m3);
  for(int i=0; i < DIMMAX; i++) {
    for(int j=0; j < DIMMAX; j++)
      assert(m3[i][j]==res[i][j]);
  }

  int res3[][3] = {
    {14,24,43},
    {84,124,223},
    {154,224,403}
  };
  
  int m4[3][3] = {
      { 1, 2, 3},
      {11,12,13},
      {21,22,23}
      };

  int m5[3][3] = {
      { 2, 1, 3},
      { 3, 4, 5},
      { 2, 5,10}
      };

 int m6[3][3];
  
  prod(3, m4, m5, m6);
  for(int i=0; i < 3; i++) {
    for(int j=0; j < 3; j++) {
      assert(m6[i][j]==res3[i][j]);
	}
  }

  puts("OK!");
}




int suma(int i, int j, int dim, int m1[dim][dim], int m2[dim][dim]){
    int suma = 0, k;
    for(k=0;k<dim;k++)
        suma+= (m1[i][k]*m2[k][j]);
    return suma;
}

void prod(int dim, int m1[dim][dim], int m2[dim][dim], int res[dim][dim]){
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++)
            res[i][j]=suma(i,j,dim,m1,m2);
    }
    return;
}