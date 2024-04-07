// Realizar un programa que copie el input al output
// reemplazando cada cadena de espacios por un solo espacio.

#include <stdio.h>
#define TRUE 1
#define FALSE !TRUE

int main(void){
    int c, antEsp=FALSE;
    while ( (c=getchar()) != EOF )
    {
        if ( !(c == ' '  && antEsp) )   // Siempre y cuando se cumpla que c no sea un espacio y el anterior tambien lo haya sido, imprime c.
        putchar(c);
        antEsp = c == ' ' ? TRUE : FALSE; // flag que indica si el caracter anterior fue un espacio
    }
    return 0;
}
