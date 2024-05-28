#include <stdio.h>
#include <stdlib.h>
#include "getnum.h"
#include "math.h"

#define FUNCION(x) ((x)*(x)-20)
#define EPSILON 0.00001
#define CONST 100000
#define BLOQUE 5
#define FALSE 0
#define TRUE !FALSE

typedef struct{
    double izq, der;
} intervalo;

typedef struct{
    intervalo * arr;
    int dim;
} tipoCeros;

// DECLARACIONES DE FUNCIONES //
tipoCeros encuentraCeros(intervalo it);
int guardarParticion(tipoCeros * resultados, intervalo it, int cantParticiones);
void imprimirResultados(tipoCeros resultados);

int main(){
    intervalo it;
    it.izq = getfloat("Ingrese el valor izquierdo del intervalo: ");
    do
        it.der = getfloat("Ingrese el valor derecho del intervalo: ");
    while(it.der <= it.izq);

    tipoCeros result = encuentraCeros(it);
    imprimirResultados(result);
    free(result.arr);

}

tipoCeros encuentraCeros(intervalo it){
    double i;
    int cantParticiones = 0;
    intervalo intAux;
    tipoCeros resultados;
    resultados.dim = 0;
    int ceroSigno, ceroEps;
    char hayEspacio = TRUE, esRaiz;
    double f, fant;

    double salto;
    salto = (it.der - it.izq) / CONST;
    if( salto == 0)
        salto = 0.00001;

    i = it.izq;
    while(i <= it.der && hayEspacio){
        fant = f = FUNCION(i);  // iguala fant a f, y despues f lo cambia a FUNCION(i);
        ceroSigno = FALSE; 
        ceroEps = FALSE;

        if( f * fant < 0)
            ceroSigno = TRUE;

        else {if ( fabs(f) < EPSILON )
            ceroEps = TRUE;
                else esRaiz = FALSE;
        }
        
        if(ceroSigno || ceroEps){
            if(!esRaiz)
                intAux.izq = i-salto;
            // CASO 1: Cero por diferencia de signos
            if(ceroSigno){
                intAux.der = i;
            }
            else{
                intAux.der = i+salto;
            }
            if(!esRaiz){
                if(guardarParticion(&resultados, intAux, cantParticiones))
                    cantParticiones++;
                else
                    hayEspacio = FALSE;
            }
        }
        i += salto;
    }
    resultados.arr = realloc(resultados.arr, cantParticiones*sizeof(intervalo));
    return resultados;
}

// guardarParticion retorna 0 si no pudo guardar, y 1 si pudo guardar.
int guardarParticion(tipoCeros * resultados, intervalo it, int cantParticiones){
    if( !cantParticiones )
        resultados->arr = NULL;

    intervalo * aux;
    if( cantParticiones % BLOQUE == 0){
        aux = realloc(resultados->arr, (cantParticiones+BLOQUE)*sizeof(intervalo));

        if(!aux){
            free(resultados->arr);
            resultados->dim = -1; // Seteo dim en -1 para indicar que no hubo espacio suficiente.
            return 0;
        }
        else resultados->arr = aux;
    }
    resultados->arr[cantParticiones] = it;
    resultados->dim++;
    return 1;
}

void imprimirResultados(tipoCeros resultados){
    if( resultados.dim != -1){
        printf("DIMENSIÓN: %d\n", resultados.dim);
        for(int i=0; i<resultados.dim; i++){
            printf("P%d: [%.4f, %.4f]\n", i, (resultados.arr[i]).izq, (resultados.arr[i]).der );
        }
    }
    else printf("No hubo espacio suficiente en memoria.\n");
    return;
}
