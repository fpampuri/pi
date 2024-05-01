// Lo mismo que antes, pero hay que escribir una función para liberar la memoria reservada por el ej. anterior
// lo dificil es liberar cada string que reservamos individual.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define LARGO_NOMBRE 15
#define ALUMNOS 10
#define BLOQUE 10

typedef char TAlumnos[][LARGO_NOMBRE];

void libera(char ** alumnos);
char ** aprobados(TAlumnos alumnos, const int promedios[]){
    char ** aprobados = malloc(BLOQUE*sizeof(char *));
    char ** aprobAux;

    if(aprobados == NULL)
        return NULL;

    unsigned int i, cantAprob=0, dimAprob=10;

    for(i=0; alumnos[i][0] != 0; i++){
        if( promedios[i] >= 4){
            if( cantAprob+1 == dimAprob ){ // es +1 porque hay que añadir el string vacio al final
                dimAprob += 10;
                aprobAux = realloc(aprobados, dimAprob*sizeof(char *));

                // si no hay espacio, tengo que liberar todo.
                if(aprobAux == NULL){
                    aprobados[cantAprob]="";    // pongo el string vacio en donde haya llegado para liberar hasta ese string.
                    libera(aprobados);
                    return NULL;
                }
                aprobados = aprobAux;
            }                                                           
            aprobados[cantAprob] = malloc(strlen(alumnos[i]));  

            // si no hay espacio, tengo que liberar todo.
            if( aprobados[cantAprob] == NULL){
                aprobados[cantAprob]="";
                libera(aprobados);
                return NULL;
            }        
            strcpy(aprobados[cantAprob++], alumnos[i]);                
        }
    }
    aprobados[cantAprob]="";
    return aprobados;
}

void libera(char ** alumnos){   // con esta funcion liberamos cada bloquecito reservado adentro del mega-bloque reservado
    for(int i=0; alumnos[i][0] != 0; i++)
        free(alumnos[i]);
    free(alumnos);
}


int main(void){

    TAlumnos alumnos = {"Juan", "Pedro", "Martin", ""};
    int notas[] = {1, 4, 10, 2, 10, 11};
    
    char ** apr = aprobados(alumnos, notas);
    if(apr == NULL){
        puts("No hay suficiente memoria!");
        return 1;
    }
    assert(!strcmp(alumnos[1], apr[0]) && !strcmp(alumnos[2], apr[1]) && !strcmp(alumnos[3], apr[2]));
    
    libera(apr);
    
    puts("OK");
    return 0;
}