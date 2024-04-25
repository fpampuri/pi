#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#define VOCALES 5
#define ERROR 0
#define EXITO 1
#define FALSE 0
#define TRUE !FALSE

int elimVocales(char * s, int mat[][VOCALES], int n);
int esVocal(char c);    // esVocal devuelve 0 si no es vocal, 1 si es A, 2 si es E, 3 I, 4 O, 5 U

int main(void) {
  int m[6][VOCALES];
  char s[] = "las buenas ideas escasean, si";

  assert(elimVocales(s, m, 6)==EXITO);
  assert(strcmp(s, "ls bns ds scsn, s")==0);
  assert(m[0][0] == 1);
  assert(m[1][0] == 8);
  assert(m[2][0] == 14);
  assert(m[3][0] == 20);
  assert(m[4][0] == 23);
  assert(m[5][0] == -1);
  
  assert(m[0][1] == 6);
  assert(m[1][1] == 13);
  assert(m[2][1] == 17);
  assert(m[3][1] == 22);
  assert(m[4][1] == -1);

  assert(m[0][2] == 11);
  assert(m[1][2] == 28);
  assert(m[2][2] == -1);

  assert(m[0][3] == -1);

  assert(m[0][4] == 5);
  assert(m[1][4] == -1);

  strcpy(s, "las buenas ideas escasean, si");
  assert(elimVocales(s, m, 1)==ERROR);
  assert(strcmp(s, "las buenas ideas escasean, si")==0);
  assert(m[0][0]==-1);
  assert(m[0][1]==-1);
  assert(m[0][2]==-1);
  assert(m[0][3]==-1);
  assert(m[0][4]==-1);

  assert(elimVocales(s, m, 5)==ERROR);
  assert(strcmp(s, "ls bns ds scsan, s")==0);
  assert(m[0][0] == 1);
  assert(m[1][0] == 8);
  assert(m[2][0] == 14);
  assert(m[3][0] == 20);
  assert(m[4][0] == -1);
  
  assert(m[0][1] == 6);
  assert(m[1][1] == 13);
  assert(m[2][1] == 17);
  assert(m[3][1] == 22);
  assert(m[4][1] == -1);

  assert(m[0][2] == 11);
  assert(m[1][2] == 28);
  assert(m[2][2] == -1);

  assert(m[0][3] == -1);

  assert(m[0][4] == 5);
  assert(m[1][4] == -1);

  printf("OK!\n");
  return 0;
}

int elimVocales(char * s, int mat[][VOCALES], int n){
    int i, letra, dimNueva=0, index;
    int cantVoc[VOCALES]={0};
    int hayEspacio=EXITO;
    int imprimo;
    for(i=0; s[i] ; i++){
        letra = esVocal(s[i]);
        if( letra ){
            index = cantVoc[letra-1];
            if(index < (n-1)){
                mat[index][letra-1]=i;
                cantVoc[letra-1]++;
                imprimo=FALSE;
            }
            else{
                imprimo=TRUE;
                hayEspacio = ERROR;
            }
        }
        if( !letra || imprimo )
        s[dimNueva++]=s[i];
    }

    for(int j=0;j<VOCALES;j++) // coloco el -1 al final de cada columna
        mat[cantVoc[j]][j] = -1;
    s[dimNueva]=0;
    return hayEspacio;
}

int esVocal(char c){
    c=toupper(c);
    const char * voc = "AEIOU";
    char * pos = strchr(voc, c);
    if( pos == NULL )
        return 0;
    else 
        return (pos - voc + 1);
}