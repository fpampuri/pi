#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "random.h"
#define NAIPES 52

typedef struct {
    char par;
    char pierna;
    char poker;
} opciones;
void generarMazo(int mazo[]);
int config(int mazo[]);

int main(void){
    int baraja[NAIPES];
    int res;
    generarMazo(baraja);
    res=config(baraja);
}

void generarMazo(int mazo[]){

}

int config(int mazo[]){

}