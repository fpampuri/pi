#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define LARGO_NOMBRE 15
#define ALUMNOS 10
#define BLOQUE 10

typedef char TAlumnos[][LARGO_NOMBRE];

char ** aprobados(TAlumnos alumnos, const int promedios[]){
    char ** aprobados = malloc(BLOQUE*sizeof(char *)), aprobAux;

    if(aprobados == NULL)
        return NULL;

    unsigned int i, cantAprob=0, dimAprob=10;

    for(i=0; alumnos[i][0] != 0; i++){
        if( promedios[i] >= 4){
            if( cantAprob+1 == dimAprob ){ // es +1 porque hay que añadir el string vacio al final
                dimAprob += 10;
                aprobados = realloc(aprobados, dimAprob*sizeof(char *));
                //aprobados = aprobAux;
            }
            aprobados[cantAprob] = malloc(strlen(alumnos[i]));
            strcpy(aprobados[cantAprob++], alumnos[i]);
        }
    }
    aprobados[cantAprob]="";
    return aprobados;
}
