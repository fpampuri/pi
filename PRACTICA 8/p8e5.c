/* La partícula hace un paso aleatorio en una de las cuatro direcciones dada por
        x = x - 1
        x = x + 1
        y = y - 1
        y = y + 1
La caminata termina cuando se sale fuera del círculo ( x2 + y2>= r2 ). */
#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include <math.h>

#define RAD_MAX 10

typedef struct {
    int x;
    int y;
} punto;


void imprimirTabla(punto p);
int recorrerCirc(punto pto, int  r);
int estaEnCirc(punto pto, int  r);

int main(){
    randomize();
    punto p;
    imprimirTabla(p);
    return 0;
}

void imprimirTabla(punto p){
    int tiempo;
    printf("%-8s\t%-8s\t%s\n", "Radio", "Tiempo", "R/T");
    for(int r = 1; r < RAD_MAX; r++){
        tiempo = recorrerCirc(p, r);
        printf("%-8d\t%-8d\t%.2f\n", r, tiempo, (double)r/tiempo);
    }
}

int recorrerCirc(punto pto, int r){
    pto.x = 0; pto.y = 0;
    int i, tiempo = 0;
    while(estaEnCirc(pto, r)){
        i = randInt(1,4);
        switch(i){
            case 1: pto.x++; break;
            case 2: pto.x--; break;
            case 3: pto.y++; break;
            case 4: pto.y--; break;
        }
        tiempo++;
    }
    return tiempo;
}

int estaEnCirc(punto pto, int  r){
    return ((pow(pto.x, 2) + pow(pto.y,2)) < pow(r,2)); 
}