#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "random.h"
#define NAIPES 52
#define CANT_PALOS 4
#define CANT_CONFIGURACIONES 4
#define CANT_VALORES 13
typedef enum{NADA=1, PAR,PIERNA,POKER} tipoConfig;
typedef enum{DIAMANTE=0, CORAZON, PICA, TREBOL} tipoPalo;
typedef struct {
    int valor;
    tipoPalo palo;
} tipoCarta;
typedef tipoCarta tipoMazo[NAIPES];
void generarMazo(tipoMazo mazo);
tipoConfig config(tipoMazo mazo);
void imprimirMano(tipoMazo mazo, tipoConfig res);

int main(void){
    randomize();
    tipoMazo baraja;
    tipoConfig res;
    generarMazo(baraja);
    res = config(baraja);
    imprimirMano(baraja, res);
}

void generarMazo(tipoMazo mazo){
    int i, random, cartas = NAIPES;
    tipoMazo mazoAux;
    // Lleno el mazo auxiliar en orden, (1 Diamante, 1 Corazon, 1 Pica, 1 Trebol ; 2 Diamante, 2 Corazon, ...)
    for(i=0; i<NAIPES; i++){
        mazoAux[i].valor = i/4 + 1;
        mazoAux[i].palo = i%4;
    }

    // Mezclo el mazo
    for(i=0; i<NAIPES; i++){
        random = randInt(0,cartas - 1);
        mazo[i] = mazoAux[random];
        mazoAux[random] = mazoAux[--cartas];
    }
    return;
}

tipoConfig config(tipoMazo mazo){
    int i;
    tipoConfig maxConfig = NADA;
    int apariciones[CANT_VALORES]={0};
    for(i=0; i<5; i++){
        apariciones[mazo[i].valor]++;
    }
    for(i=0; i<CANT_VALORES; i++){
        if(apariciones[i] > maxConfig)
            maxConfig = apariciones[i];
    }
    return maxConfig;
}

void imprimirMano(tipoMazo mazo, tipoConfig resultado){
    char * palos[CANT_PALOS] = {"Diamante","Corazon","Pica","Trebol"};
    char * configuraciones[CANT_CONFIGURACIONES] = {"NADA","PAR","PIERNA","POKER"};
    printf("TU MANO ES: \n");
    for(int i=0; i<5; i++){
        printf("=> %d de %s\n", mazo[i].valor, palos[mazo[i].palo]);
    }
    printf("Y tienes %s!\n", configuraciones[resultado-1]);
    return;
}