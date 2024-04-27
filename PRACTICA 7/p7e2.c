#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "getnum.h"
#include <math.h>
#include <ctype.h>

#define FALSE 0
#define TRUE !FALSE
int main(void){
    int base_orig;
    int base_dest;
    int datoIncorrecto = FALSE;
    puts("Ingrese las bases en formato < BASE_INICIAL > BASE_FINAL");
    do
    {
        printf("\nIngrese bases en formato < n >m: ");
        datoIncorrecto = scanf("< %d > %d", &base_orig, &base_dest);
        if (datoIncorrecto == 2 && (base_orig < 2 || base_orig > 10 || base_dest < 2 || base_dest > 10))
            datoIncorrecto = 0;
        while (getchar()!='\n');
    } while (datoIncorrecto != 2);
    int num_leido = getint("Ingrese un numero de base %d a convertir: ", base_orig);
    int decimal=0;
    // Para convertirlo a la base deseada primero lo convierto a decimal y despues lo convierto a la base deseada
    int i;
    for( i=0; num_leido != 0; i++){
        decimal += pow(5,i)*(num_leido%10);
        num_leido /= 10;
    }

    // Una vez convertido a decimal, hay que pasarlo a binario
    int convertido=0;
    for(i=0; decimal != 0 ;i++){
        convertido = (convertido*10)+(decimal%base_dest);
        decimal /= base_dest;
    }

    int num_final=0;
    for(i=0; convertido != 0; i++){
        num_final = num_final*10 + convertido%10;
        convertido /= 10;
    }

    printf("El numero convertido es: %d\n", num_final);
}