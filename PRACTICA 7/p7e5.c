/* 	Sean Nombre y Curso dos arreglos que contienen el nombre y el curso( ‘G’ o ‘H’) de cada uno de los alumnos de una materia. 
Escribir una función que reciba dichos arreglos como parámetros de entrada 
y retorne en parámetros de salida otros dos arreglos CursoG y CursoH con el nombre de los alumnos separados por curso. 
El string vacío en el nombre indica fin del arreglo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define LARGO_NOMBRE 25
#define MAX_ALUMNOS 40
typedef char TNombres[MAX_ALUMNOS][LARGO_NOMBRE];
typedef char TCurso[];

/* OBS: Va a haber tantos nombres como elementos en curso.
    Manera 1: Ir iterando sobre ambos vectores hasta llegar al final de ambos. Por cada nombre, veo su curso y dependiendo
             de cual sea su curso, lo meto en CursoG o CursoH con strcpy. */

/* PROBLEMA: Cuanto espacio reservo en cada vector!!? 
    SOLUCION 1: Recorrer una sola vez el vector de cursos, contar los elementos totales y cuantos hay en G.
                Hacer la cuenta y obtener cuantos hay en H. Reservar lo necesario en c/u. */
void separa(TNombres nombre, TCurso curso, TNombres cursoG, TNombres cursoH);

int main(void){

    TNombres alumnos={"Juan", "Pedro", "Martin", ""}, cursoG, cursoH;
    TCurso curso={'H', 'G', 'H', 0};
    separa(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[1]));
    assert(!strcmp(cursoH[0], alumnos[0]));
    assert(!strcmp(cursoH[1], alumnos[2]));
    assert(!strcmp(cursoG[1], alumnos[3]) && !strcmp(cursoH[2], alumnos[3]));   // Terminan con "" 

    alumnos[0][0] = '/0'; curso[0]=0;  // Depende del tipo de alumnos, esta linea puede ser: "alumnos[0][0]=0; curso[0]=0;"
    separa(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[0]) && !strcmp(cursoH[0], alumnos[0]));

    puts("OK!");
    return 0;
}

void separa(TNombres nombre, TCurso curso, TNombres cursoG, TNombres cursoH){
    int i, g=0, h=0;
    for(i=0; nombre[i][0] != 0 ; i++){
        if(curso[i] == 'G')
            strcpy(cursoG[g++], nombre[i]);
        else
            strcpy(cursoH[h++], nombre[i]);
    }
    cursoG[g][0]=0;
    cursoH[h][0]=0;
}
