/* Escribir una función que reciba como parámetro de entrada un string y 
retorne 1 si el mismo es palíndromo y 0 en caso contrario.
 Resolver el problema en forma recursiva*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
int esCapicuaRec(char * s, int len);

int esCapicua(char * s){
    return esCapicuaRec(s, strlen(s));
}

int esCapicuaRec(char * s, int len){
    if(len == 0 || len == 1)
        return 1;
    return (s[0] == s[len-1]) && esCapicuaRec(s + 1, len - 2);
}
