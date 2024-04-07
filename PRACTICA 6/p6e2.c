#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "getnum.h"

#define NUM(f) f[0]
#define DEN(f) f[1]
#define LEER_DENOM(denom) {do { denom = getint(""); \
                                if (denom == 0) \
                                puts("El denominador debe ser distinto de cero\n");} \
                            while ( denom == 0);}
int menu(void);

void simpFrac2(int frac[2]);

void sumarFrac(int fraccion[2], int fraccion2[2], int suma[2]);

int mcd(int x, int y);

int main(){
    int opcion;
    do {
        int fraccion[2];
        int fraccion2[2];
        int suma[2];
        opcion = menu();
        switch(opcion) {
            case 1: NUM(fraccion) = getint("Ingrese el numerador: "); // Pido numerador y denominador para realizar la simplificacion
                    puts("Ingrese el denominador: ");
                    LEER_DENOM(DEN(fraccion))
                    simpFrac2(fraccion);
                    printf("La fraccion simplificada resulta %d/%d\n", NUM(fraccion), DEN(fraccion));
                    break;
            case 2: NUM(fraccion) = getint("Ingrese el numerador uno: ");
                    puts("Ingrese el denominador uno: ");
                    LEER_DENOM(DEN(fraccion))
                    NUM(fraccion2) = getint("Ingrese el numerador dos: ");
                    puts("Ingrese el denominador dos: ");
                    LEER_DENOM(DEN(fraccion2))
                    sumarFrac(fraccion, fraccion2, suma);
                    printf("La suma es %d/%d\n",NUM(suma), DEN(suma));
                    break;
            case 3: break;
            default: puts("\nIngrese una opcion valida"); break;
        }
    }
    while ( opcion != 3 );
    return 0;
}

int menu(){
    puts("1) Simplificar una fraccion");
    puts("2) Sumar dos fracciones");
    puts("3) Terminar el programa");
    int decision = getint("\nElija una opcion: ");
    return decision;
}

int mcd(int x, int y) {
    int auxi;
    auxi = x;
    while (auxi != 0)
    {
        x = y;
        y = auxi;
        auxi = x % y ;
    }
    return y;
}


void sumarFrac(int fraccion[2], int fraccion2[2], int suma[2]){
    int denComun = DEN(fraccion)*DEN(fraccion2);
    DEN(suma) = denComun;
    NUM(suma) = (NUM(fraccion)*(denComun/DEN(fraccion))) + (NUM(fraccion2)*(denComun/DEN(fraccion)));
    simpFrac2(suma);
}

void simpFrac2(int frac[2]) {
    int divcomun;
    divcomun = mcd(NUM(frac), DEN(frac));
    NUM(frac) /= divcomun;
    DEN(frac) /= divcomun;
}