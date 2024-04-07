#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "getnum.h"

#define LEER_DENOM(denom) {do { denom = getint(""); \
                                if (denom == 0) \
                                puts("El denominador debe ser distinto de cero\n");} \
                            while ( denom == 0);}
int menu(void);

int simpFrac(int num, int den);

int sumarFrac(int num1, int num2, int den1, int den2);

int mcd(int x, int y);

int main(){
    int num1, num2, den1, den2;
    int opcion;
    do {
        opcion = menu();
        switch(opcion) {
            case 1: num1 = getint("Ingrese el numerador: "); // Pido numerador y denominador para realizar la simplificacion
                    puts("Ingrese el denominador: ");
                    LEER_DENOM(den1)
                    simpFrac(num1, den1);
                    break;
            case 2: num1 = getint("Ingrese el numerador uno: ");
                    puts("Ingrese el denominador uno: ");
                    LEER_DENOM(den1)
                    num2 = getint("Ingrese el numerador dos: ");
                    puts("Ingrese el denominador dos: ");
                    LEER_DENOM(den2)
                    sumarFrac(num1,num2,den1,den2);
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

int simpFrac(int num1, int den1) {
    int naux, daux, divcomun;
    naux = num1;
    daux = den1;
    divcomun = mcd(num1,den1);
    num1 /= divcomun;
    den1 /= divcomun;

    printf("%d/%d simplificada es %s%d", naux, daux, (num1*den1>0) ? "" : "-", abs(num1));
    if ( abs(den1) != 1) 
        printf("/%d\n",abs(den1));
    printf("\n\n");
    return 0;
}

int sumarFrac(int num1, int num2, int den1, int den2){
    int denComun = den1*den2;
    int numTot = (num1*(denComun/den1)) + (num2*(denComun/den2));
    simpFrac(numTot, denComun);
    return 0;
}