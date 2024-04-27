#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
#include "getnum.h"
#include "random.h"

#define X 3
#define FALSE 0
#define TRUE !FALSE
/* 
La computadora construye un conjunto aleatorio de X dígitos distintos (para X usar una constante simbólica). 
Sólo se usan los dígitos del 1 al 9

Se le  pide ingresar al usuario el nivel en que quiere jugar. Según esto se trabajará con una tolerancia de hasta N pasos, 
dentro de los cuales si no logra ganar el juego se termina automáticamente. 
El jugador entra un conjunto de X dígitos distintos por teclado. 

Si el número propuesto por el jugador coincide con el que generó la máquina o la cantidad de chances excedió el número tope N , 
el juego finaliza; sino el programa debe informarle cuántos dígitos están BIEN (son correctos y están en su lugar) 
y cuántos son REGULARES (son correctos pero están fuera de lugar) y se vuelve a ejecutar el paso anterior. 

Así se va guiando al jugador hasta que adivine el número.
*/

void generarAleatorio(int numero[]);
int elegirNivel(void);
void leerNumero(int usr_num[]);
int coincideNumero(int * usr_num, int * num, int *bien, int *reg);
int cantidadBien(int * usr_num, int * num);
int cantidadRegular(int * usr_num, int * num);

int main(void){
    int num[X];
    int usr_num[X];
    int nivel;
    int intentos=0;
    int coincide = FALSE;
    int ok_dig, rg_dig;
    generarAleatorio(num);
    puts("--------- MASTERMIND -----------");
    nivel = elegirNivel();
    while(intentos < nivel && !coincide){
        leerNumero(usr_num);
        coincide = coincideNumero(usr_num, num, &ok_dig, &rg_dig);
        if( !coincide ){
            printf("%d BIEN, %d REGULARES\n", ok_dig, rg_dig);
            intentos++;
        }
    }

    if(coincide)
        printf("FELICITACIONES, era el numero correcto!\n");
    else
        printf("HAS PERDIDO. Agotaste todos los intentos.\n");
    return 0;
}

void generarAleatorio(int numero[]){
    unsigned char valores[9] = {1,2,3,4,5,6,7,8,9};
    unsigned char random;
    int digits = 9;
    for(int i=0; i<X; i++){
        random = randInt(0, digits - 1);
        numero[i] = valores[random];
        valores[random]=valores[--digits];
    }
}

int elegirNivel(void){
    int nivel;
    do{
        printf("Elija el nivel (Entre 1 y 10)\n");
        scanf("%d", &nivel);
        while( getchar() != '\n');
    }
    while( nivel<1 || nivel>10 );
    return nivel;
}

void leerNumero(int usr_num[]){
    int n, i, j, digito;
    int numValido = TRUE;
    printf("RECUERDA: El numero a adivinar es de %d digitos!\n", X);
    do{
        n = getint("Ingrese un numero entero sin digitos repetidos: ");
        for(i=X-1; i>=0 && numValido; i--){
            digito = n % 10; 
            if( digito == 0)
                numValido = FALSE;
            else
                for(j=X-1; j>i; j--){
                    if( usr_num[j] == digito)
                        numValido = FALSE;
                }
            if(numValido) 
                usr_num[i] = digito;
            n /= 10;
        }
    }
    while( !numValido || n != 0);
}

// DEVUELVE 1 SI COINCIDE, 0 SI NO
int coincideNumero(int * usr_num, int * num, int *bien, int *reg){
    int coincide = FALSE;
    if( (*bien = cantidadBien(usr_num, num)) == X)
        coincide = TRUE;
    else
        *reg = cantidadRegular(usr_num, num);
    return coincide;
}

int cantidadBien(int * usr_num, int * num){
    int bien=0;
    for(int i=0; i<X; i++){
        if(usr_num[i] == num[i])
            bien++;
    }
    return bien;
}

int cantidadRegular(int * usr_num, int * num){
    int reg=0;
    int j;
    for(int i=0; i<X; i++)
        for(j=0; j<X; j++)
            if(i != j)
                reg += (usr_num[i] == num[j]);
    return reg;
    
}
