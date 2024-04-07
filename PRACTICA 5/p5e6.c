/* Ejercicio 6
    Escribir un programa que ofrezca las siguientes opciones para accionar sobre un caracter leído desde la entrada estándar.
Utilizar distintas funciones (con no más de 4 líneas) para cada una de las opciones y una función para el menú de opciones:

    Convertir de mayúscula a minúscula. 
    Convertir de minúscula a mayúscula. 
    Imprimir el carácter siguiente. 
    Imprimir la siguiente letra en forma circular (si la letra es 'z', debe imprimir 'a') */

#include <stdio.h>
#include <ctype.h>
#include "getnum.h"

#define DELTA ('a' - 'A')
#define DELTA2 ('z' - 'a')
int menu() {
    printf("Opciones:\n\n");
    puts("1) Convertir de mayuscula a minuscula");
    puts("2) Convertir de minuscula a mayuscula");
    puts("3) Imprimir el caracter siguiente");
    puts("4) Imprimir la siguiente letra en forma circular");
    int opcion;
    opcion = getint("Elija una opcion de la lista: ");
    return opcion;
}

int amayus ( int letra ){
    if ( islower(letra) )
        letra = letra - DELTA;
    return letra;
}

int aminus ( int letra ){
    if ( isupper(letra) )
        letra = letra + DELTA;
    return letra;
}

int sig ( int car ){
    return car=car+1;
}

int sigletra ( int letra ){
    if (isalpha(letra)) {
        if ( letra != 'z' && letra != 'Z' )
            letra=letra+1;
        else letra = letra - DELTA2;
    }
    return letra;
}

int main()
{
    int c, decision, resp;
    do {
    puts("Ingrese un caracter: ");
    c = getchar();
    decision = menu();

    switch (decision)
    {
        case 1: resp = aminus(c);
                break;
        case 2: resp = amayus(c);
                break;
        case 3: resp = sig(c);
                break;
        case 4: resp = sigletra(c);
                break;
        default: 
            resp = 0;
            printf("Ingrese un numero valido\n");
    }
    printf("%c\n",resp);
    }
    while( c != EOF);
    return 0;
}
