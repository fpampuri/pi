// Escribir la macro ELAPSED que al recibir dos medidas de tiempo en horas y minutos 
// retorne la cantidad de minutos transcurridos. No usar funciones de la biblioteca estándar (((h2)-(h1))*60 + ((m2)-(m1)) )
#include <stdio.h>
#include "getnum.h"

#define ELAPSED(h1,h2,m1,m2) ( ((h1)*60 + (m1) > (h2)*60 + (m2)) ? \
                            (((h1)-(h2))*60 + (m1)-(m2)) : (((h2)-(h1))*60 + (m2)-(m1)) )

int main(){
    int minutos,h1,h2,m1,m2;
    h1=getint("Ingrese la hora 1: ");
    m1=getint("Ingrese los minutos de la hora 1: ");
    h2=getint("Ingrese la hora 2: ");
    m2=getint("Ingrese los minutos de la hora 2: ");
    minutos=ELAPSED(h1,h2,m1,m2);
    printf("La diferencia es de %d minutos.\n", minutos);
    return 0;
}
