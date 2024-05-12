// Escribir una funcion recursiva que reciba como parametros
// dos numeros enteros y devuelva el MCD utilizando Euclides
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int mcd(int a, int b);
int esNulo(const int v[], int dim);
int cuentaVocales(char * s);
int isVowel(char c);

int main(){
  /*   int a = 15, b = 20;
    printf("MCD: %d\n", mcd(b,a));
    int v1[100] = {0};
    int v2[10] = {0,0,0,0,0,0,0,0,0,0};
    printf("%s nulo.\n", esNulo(v1, 100) ? "SI" : "NO");
    printf("%s nulo.\n", esNulo(v2, 10) ? "SI" : "NO"); */
    char * s = "Vocales ae1c";
    printf("CANTIDAD DE VOCALES: %d\n", cuentaVocales(s));
    return 0;
}
int mcd(int a, int b){
    if(b == 0)
        return a;
    else
        return mcd(b, a%b);
}

int esNulo(const int v[], int dim){
    if( dim == 0)
        return 1;

    if(v[dim-1] != 0)
        return 0;
    else return esNulo(v, dim-1);
}

int cuentaVocales(char * s){
    if(*s == '\0')
        return 0;
    return isVowel(*s) + cuentaVocales(s + 1);
}

int isVowel(char c){
    c = toupper(c);
    if( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return 1;
    return 0;
}