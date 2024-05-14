/* Escribir una función recursiva bienFormado que reciba como único argumento
 un string con el formato mencionado y retorne 0 (cero) si está bien formado,
y distinto de cero si no.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#define TRUE 0
#define FALSE !TRUE

int bienFormado(char * s){
    if(*s == '\0')
        return TRUE;
    if(isalpha(*s))
        return 1 + bienFormado(s+1);
 
// Si no es letra, entonces es dígito en el formato mencionado
    int res = bienFormado(s+1);
    if(res == 0)
        return -(*s - '0');
    else
        return 1;
}
