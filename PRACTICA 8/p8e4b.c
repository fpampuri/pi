// Sé que es optimizable poniendo las cosas en una sola funcion (es decir que analice ambas manos en la misma funcion y etc)
// pero me daba bastante paja volver a armar todo.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "random.h"
#include "getnum.h"
#define NAIPES 52
#define CANT_PALOS 4
#define CANT_CONFIGURACIONES 4
#define CANT_VALORES 13
#define CARTAS_POR_MANO 5
#define NUEVA_MANO 10

typedef enum{NADA=1, PAR,PIERNA,POKER} tipoConfig;
typedef enum{DIAMANTE=0, CORAZON, PICA, TREBOL} tipoPalo;
typedef struct {
    int valor;
    tipoPalo palo;
} tipoCarta;
typedef tipoCarta tipoMazo[NAIPES];

void generarMazo(tipoMazo mazo);
void jugar(tipoMazo mazo);
tipoConfig analizaConfig(tipoMazo mazo, int * mano, int * figura);
void imprimirMano(int mano, tipoMazo mazo, tipoConfig resUser, tipoConfig resPC, int ptosUser, int ptosPC);
int userJuega(void);

int main(void){
    randomize();
    tipoMazo mazo;
    generarMazo(mazo);
    jugar(mazo);
    return 0;
}

void jugar(tipoMazo mazo){
    tipoConfig configUser, configPC;
    // Le doy las primeras 5 cartas al User, y las 5 siguientes a la PC.
    // Así sucesivamente hasta que no queden cartas (o el usuario no quiera jugar mas)
    int manoUser=0;
    int manoPC = manoUser + 5;
    int figuraUser, figuraPC;
    int ptosUser = 0, ptosPC = 0;
    do{
    configUser = analizaConfig(mazo, &manoUser, &figuraUser);
    configPC = analizaConfig(mazo, &manoPC, &figuraPC);

    if(configUser > configPC)
        ptosUser++;
    else if (configUser < configPC)
            ptosPC++;
        else if(figuraUser > figuraPC)
            ptosUser++;
            else if(figuraUser < figuraPC)
                ptosPC++;
                    else{
                        ptosPC++;
                        ptosUser++;
                    }

    imprimirMano(manoUser, mazo, configUser, configPC, ptosUser, ptosPC);
    manoUser += CARTAS_POR_MANO;
    manoPC += CARTAS_POR_MANO;
    }
    while(manoPC+CARTAS_POR_MANO < NAIPES && userJuega());
    if( ptosUser == ptosPC)
        printf("EMPATE!\n");
    else
        printf("Ganador: %s\n", ptosPC > ptosUser ? "COMPUTADORA :(" : "VOS!");
    return;
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

tipoConfig analizaConfig(tipoMazo mazo, int * mano, int * figura){
    int i;
    *figura = 1;
    tipoConfig maxConfig = NADA;
    int apariciones[CANT_VALORES]={0};
    for(i=*mano; i<(*mano)+CARTAS_POR_MANO; i++){
        apariciones[mazo[i].valor]++;
    }
    for(i=0; i<CANT_VALORES; i++){
        if(apariciones[i] >= maxConfig){
            maxConfig = apariciones[i];
            *figura = i;
        }
    }
    return maxConfig;
}

void imprimirMano(int mano, tipoMazo mazo, tipoConfig resUser, tipoConfig resPC, int ptosUser, int ptosPC){
    char * palos[CANT_PALOS] = {"Diamante","Corazon","Pica","Trebol"};
    char * configuraciones[CANT_CONFIGURACIONES] = {"NADA","PAR","PIERNA","POKER"};
    printf("TU MANO ES: \t\t\tMANO PC:\n");
    for(int i=mano; i<mano+CARTAS_POR_MANO; i++){
        printf("=> %d de %-8s\t\t=> %d de %s\n", mazo[i].valor, palos[mazo[i].palo], mazo[i+CARTAS_POR_MANO].valor, palos[mazo[i+CARTAS_POR_MANO].palo]);
    }
    printf("RESULTADO: %s\t\t\tRESULTADO: %s\n", configuraciones[resUser-1], configuraciones[resPC-1]);
    printf("PUNTOS = %d\t\t\tPUNTOS = %d", ptosUser, ptosPC);
    putchar('\n');
    return;
}

int userJuega(void){
    printf("\nDesea seguir jugando?\n");
    char decision;
    do{
        decision = getint("Ingrese 1 si SI, 0 si NO: ");
    }
    while(decision != 0 && decision != 1);
    putchar('\n');
    return decision;
}