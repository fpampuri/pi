#include <stdio.h> 
#include <stdlib.h>
#include "getnum.h"
#include "random.h"
#include <time.h>
#include <string.h>
#include <ctype.h>

#define FALSE 0
#define TRUE 1
#define MAX_STRIKES 5
#define CANT_PALABRAS 5
#define MAX_LARGO_PALABRA 13

void rellenarPalabra(char * palabra, char * ahorcado);
void imprimirAhorcado(char * ahorcado);
int jugar(char * palabra, char * ahorcado, int * strikes);
int esPalabraCorrecta(char * guess, char * palabra);
int isInWord(char letra, const char * palabra, char * ahorcado);
int esPalabra(char * s);

int main(void){
    randomize();
    int strikes = 0;
    char * palabra;
    char * palabras[CANT_PALABRAS] = {"PUTO","PALABRA","ENCICLOPEDIA","PRACTICA","BOTELLA"};
    palabra = palabras[randInt(0,CANT_PALABRAS-1)];
    char ahorcado[MAX_LARGO_PALABRA];
    int adivina = FALSE;    

    puts("-------- AHORCADO ---------");
    rellenarPalabra(palabra, ahorcado);

    while( strikes < MAX_STRIKES && !adivina ){
        imprimirAhorcado(ahorcado);
        adivina = jugar(palabra, ahorcado, &strikes);
    }
    
    if( adivina )
        printf("FELICITACIONES, GANASTE!\nLa palabra era %s\n",palabra);
    else
        printf("PERDISTE! Se te acabaron los errores y fuiste ahorcado =(\n");
    return 0;
}

void rellenarPalabra(char * palabra, char * ahorcado){
    int i;

    for(i=0; palabra[i]; i++)
        ahorcado[i]='_';
    ahorcado[i]=0;
}

void imprimirAhorcado(char * ahorcado){
    for(int i=0; ahorcado[i]; i++)
        printf("%c ",ahorcado[i]);
    putchar('\n');
}

int jugar(char * palabra, char * ahorcado, int * strikes){
    char guess[MAX_LARGO_PALABRA];
    int largo_guess;
    int adivina = FALSE;
    do{
        pRIN("STRIKES: %d/%d\tIngrese una letra o intente adivinar la palabra: ", *strikes, MAX_STRIKES);
        scanf("%s", guess);
    }
    while( !esPalabra(guess));
    largo_guess = strlen(guess);
    if(largo_guess > 1) // Si el largo del string ingresado es mayor a 1, es una palabra. Hay que chequear si es correcta
        adivina = esPalabraCorrecta(guess, palabra);
    else if ( !isInWord(guess[0], palabra, ahorcado))
        (*strikes)++;
    return adivina;
}

int esPalabraCorrecta(char * guess, char * palabra){
    int sonIguales = TRUE;
    if(strlen(guess) != strlen(palabra))
        sonIguales = FALSE;
    for(int i=0; palabra[i] && sonIguales; i++){
        if(toupper(guess[i]) != palabra[i])
            sonIguales = FALSE;
    }
    return sonIguales;
}

int isInWord(char letra, const char * palabra, char * ahorcado){
    int isLetter = FALSE;
    letra = toupper(letra);
    for(int i=0; palabra[i]; i++){
        if( palabra[i] == letra){
            isLetter = TRUE;
            ahorcado[i] = letra;        // cambio el '_' por la letra hallada.
        }
    }
    return isLetter;
}

int esPalabra(char * s){
    char flag = TRUE;
    for(int i=0; s[i] && flag; i++){
        if(!isalpha(s[i]))
            flag = FALSE;
    }
    return flag;
}